# Use Ubuntu 22.04 as base image
FROM ubuntu:22.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV PATH=/root/bin:$PATH

# Install system dependencies
RUN apt-get update && apt-get install -y \
    curl \
    wget \
    git \
    unzip \
    build-essential \
    openjdk-11-jdk \
    python3 \
    python3-pip \
    nodejs \
    npm \
    libc6-dev \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

# Install Bazel using pre-built binary (works on both x86_64 and ARM64)
RUN ARCH=$(uname -m) \
    && if [ "$ARCH" = "x86_64" ]; then \
        curl -fsSL https://github.com/bazelbuild/bazel/releases/download/7.4.1/bazel-7.4.1-linux-x86_64 -o /usr/local/bin/bazel; \
    elif [ "$ARCH" = "aarch64" ]; then \
        curl -fsSL https://github.com/bazelbuild/bazel/releases/download/7.4.1/bazel-7.4.1-linux-arm64 -o /usr/local/bin/bazel; \
    fi \
    && chmod +x /usr/local/bin/bazel \
    && bazel --version

# Set JAVA_HOME to the correct path
RUN JAVA_HOME=$(update-alternatives --query java | grep 'Value:' | head -1 | awk '{print $2}' | sed 's|/bin/java||') \
    && echo "export JAVA_HOME=$JAVA_HOME" >> /etc/environment \
    && echo "export JAVA_HOME=$JAVA_HOME" >> /root/.bashrc \
    && export JAVA_HOME=$JAVA_HOME

# Install JSVU (JavaScript Version Updater)
RUN npm install -g jsvu

# Install JavaScript engines via JSVU (use correct architecture)
RUN ARCH=$(uname -m) \
    && if [ "$ARCH" = "x86_64" ]; then \
        jsvu --os=linux64 --engines=graaljs,hermes,v8; \
    elif [ "$ARCH" = "aarch64" ]; then \
        jsvu --os=linux64 --engines=graaljs,hermes \
        && echo "Skipping V8 on ARM64 - using GraalJS and Hermes only"; \
    fi \
    && echo "Checking what engines were installed:" \
    && ls -la ~/.jsvu/bin/ || echo "No bin directory found"

# Debug: Check what was installed
RUN echo "Checking JSVU installation:" \
    && ls -la ~/.jsvu/ \
    && echo "Checking bin directory:" \
    && ls -la ~/.jsvu/bin/ \
    && echo "Checking individual engines:" \
    && ls -la ~/.jsvu/bin/* || echo "No engines found"

# Copy engines to a standard location (only copy engines that exist)
RUN mkdir -p /usr/local/bin/js-engines \
    && echo "Copying engines..." \
    && echo "V8 source: ~/.jsvu/bin/v8" \
    && ls -la ~/.jsvu/bin/v8 || echo "V8 source not found" \
    && if [ -f "~/.jsvu/bin/v8" ]; then cp ~/.jsvu/bin/v8 /usr/local/bin/js-engines/v8; fi \
    && echo "Hermes source: ~/.jsvu/bin/hermes" \
    && ls -la ~/.jsvu/bin/hermes 2>/dev/null || echo "Hermes source not found" \
    && if [ -f "~/.jsvu/bin/hermes" ]; then cp ~/.jsvu/bin/hermes /usr/local/bin/js-engines/hermes; fi \
    && echo "GraalJS source: ~/.jsvu/bin/graaljs" \
    && ls -la ~/.jsvu/bin/graaljs 2>/dev/null || echo "GraalJS source not found" \
    && if [ -f "~/.jsvu/bin/graaljs" ]; then cp ~/.jsvu/bin/graaljs /usr/local/bin/js-engines/graaljs; fi \
    && echo "Checking copied engines:" \
    && ls -la /usr/local/bin/js-engines/

# Clone the perses repository
WORKDIR /workspace
RUN git clone https://github.com/srina1h/perses.git .
RUN git checkout diff

# Prepare seeds by running the prepare_seeds.sh script
RUN chmod +x prepare_seeds.sh && ./prepare_seeds.sh

# Create necessary directories for differential testing with instrumentation
RUN mkdir -p kitten/temp_testing_campaigns/differential_finding_folder_javascript \
    && mkdir -p kitten/temp_testing_campaigns/differential_processing_folder_javascript \
    && mkdir -p kitten/temp_testing_campaigns/differential_duplicate_folder_javascript \
    && mkdir -p kitten/reported_bugs/javascript \
    && mkdir -p kitten/scripts/javascript/seeds

# Build the project with instrumentation support
RUN bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar

# Create a script to update the configuration with correct paths
RUN echo '#!/bin/bash' > /workspace/update-config.sh && \
    echo '# Update the differential testing config with correct paths' >> /workspace/update-config.sh && \
    echo 'cd /workspace' >> /workspace/update-config.sh && \
    echo 'echo "Current directory: $(pwd)"' >> /workspace/update-config.sh && \
    echo 'echo "Checking if config file exists:"' >> /workspace/update-config.sh && \
    echo 'if [ -f "kitten/scripts/javascript/all-compilers-config.yaml" ]; then' >> /workspace/update-config.sh && \
    echo '    echo "Config file found!"' >> /workspace/update-config.sh && \
    echo '    echo "Updating configuration paths..."' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/hermes|/usr/local/bin/js-engines/hermes|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/graaljs|/usr/local/bin/js-engines/graaljs|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    # Remove V8 configuration on ARM64' >> /workspace/update-config.sh && \
    echo '    if [ "$(uname -m)" = "aarch64" ]; then' >> /workspace/update-config.sh && \
    echo '        echo "Removing V8 configuration on ARM64..."' >> /workspace/update-config.sh && \
    echo '        sed -i "/command: \"\/usr\/local\/bin\/js-engines\/v8\/v8\"/,/crashDetectorClassName: \"org.perses.fuzzer.compilers.javascript.V8CrashDetector\"/d" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    else' >> /workspace/update-config.sh && \
    echo '        sed -i "s|/Users/srinath/.jsvu/bin/v8|/usr/local/bin/js-engines/v8|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    fi' >> /workspace/update-config.sh && \
    echo '    echo "Configuration update completed."' >> /workspace/update-config.sh && \
    echo 'else' >> /workspace/update-config.sh && \
    echo '    echo "ERROR: Config file not found!"' >> /workspace/update-config.sh && \
    echo '    echo "Available files in kitten/scripts/javascript/:"' >> /workspace/update-config.sh && \
    echo '    ls -la kitten/scripts/javascript/ || echo "Directory not found!"' >> /workspace/update-config.sh && \
    echo '    exit 1' >> /workspace/update-config.sh && \
    echo 'fi' >> /workspace/update-config.sh

RUN chmod +x /workspace/update-config.sh

# Create the main entry script with SLURM support and instrumentation
RUN echo '#!/bin/bash' > /workspace/start-differential-testing.sh && \
    echo 'set -e' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Starting differential testing setup with instrumentation..."' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Update configuration paths' >> /workspace/start-differential-testing.sh && \
    echo './update-config.sh' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Verify JavaScript engines are available' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Verifying JavaScript engines..."' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Debug: Show what we are about to do' >> /workspace/start-differential-testing.sh && \
    echo 'echo "DEBUG: About to check and create symlinks..."' >> /workspace/start-differential-testing.sh && \
    echo 'echo "DEBUG: HOME=$HOME"' >> /workspace/start-differential-testing.sh && \
    echo 'echo "DEBUG: Checking if V8 exists at $HOME/.jsvu/engines/v8/v8"' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Ensure engines are available (they should be copied during build)' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking if engines are available..."' >> /workspace/start-differential-testing.sh && \
    echo 'mkdir -p /usr/local/bin/js-engines' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Available engines:"' >> /workspace/start-differential-testing.sh && \
    echo 'ls -la /usr/local/bin/js-engines/ || echo "No engines found"' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Try to copy engines if they are not already copied' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking for engines in ~/.jsvu/bin/..."' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "$HOME/.jsvu/bin/v8" ] && [ ! -f "/usr/local/bin/js-engines/v8" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying V8 from ~/.jsvu/bin/v8..."' >> /workspace/start-differential-testing.sh && \
    echo '    cp $HOME/.jsvu/bin/v8 /usr/local/bin/js-engines/v8' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "$HOME/.jsvu/bin/hermes" ] && [ ! -f "/usr/local/bin/js-engines/hermes" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying Hermes from ~/.jsvu/bin/hermes..."' >> /workspace/start-differential-testing.sh && \
    echo '    cp $HOME/.jsvu/bin/hermes /usr/local/bin/js-engines/hermes' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -d "$HOME/.jsvu/engines/graaljs" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying GraalJS directory from ~/.jsvu/engines/graaljs/..."' >> /workspace/start-differential-testing.sh && \
    echo '    cp -r $HOME/.jsvu/engines/graaljs/ /usr/local/bin/js-engines/graaljs-temp/' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying GraalJS binary to standard location..."' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Checking what is in graaljs-temp:"' >> /workspace/start-differential-testing.sh && \
    echo '    ls -la /usr/local/bin/js-engines/graaljs-temp/' >> /workspace/start-differential-testing.sh && \
    echo '    if [ -f "/usr/local/bin/js-engines/graaljs-temp/graaljs-24.2.2-linux-amd64/bin/js" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '        echo "Found graaljs-24.2.2-linux-amd64/bin/js, creating wrapper script..."' >> /workspace/start-differential-testing.sh && \
    echo '        echo "#!/bin/bash" > /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '        echo "export GRAALVM_HOME=/usr/local/bin/js-engines/graaljs-temp/graaljs-24.2.2-linux-amd64" >> /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '        echo "export JAVA_HOME=$GRAALVM_HOME" >> /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '        echo "export PATH=$GRAALVM_HOME/bin:$PATH" >> /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '        echo "exec $GRAALVM_HOME/bin/js \"$@\"" >> /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '        chmod +x /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '    elif [ -f "/usr/local/bin/js-engines/graaljs-temp/graaljs-24.2.2-linux-amd64/graaljs" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '        echo "Found graaljs-24.2.2-linux-amd64/graaljs, copying..."' >> /workspace/start-differential-testing.sh && \
    echo '        cp /usr/local/bin/js-engines/graaljs-temp/graaljs-24.2.2-linux-amd64/graaljs /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '    elif [ -f "/usr/local/bin/js-engines/graaljs-temp/graaljs-24.2.2-linux-amd64" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '        echo "Found graaljs-24.2.2-linux-amd64, copying..."' >> /workspace/start-differential-testing.sh && \
    echo '        cp /usr/local/bin/js-engines/graaljs-temp/graaljs-24.2.2-linux-amd64 /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '    elif [ -f "/usr/local/bin/js-engines/graaljs-temp/graaljs" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '        echo "Found graaljs, copying..."' >> /workspace/start-differential-testing.sh && \
    echo '        cp /usr/local/bin/js-engines/graaljs-temp/graaljs /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo '    else' >> /workspace/start-differential-testing.sh && \
    echo '        echo "ERROR: No GraalJS binary found in temp directory!"' >> /workspace/start-differential-testing.sh && \
    echo '        echo "Searching for any graal executable:"' >> /workspace/start-differential-testing.sh && \
    echo '        find /usr/local/bin/js-engines/graaljs-temp/ -type f -executable -name "*graal*" -ls' >> /workspace/start-differential-testing.sh && \
    echo '        echo "Listing contents of graaljs-24.2.2-linux-amd64/bin directory:"' >> /workspace/start-differential-testing.sh && \
    echo '        ls -la /usr/local/bin/js-engines/graaljs-24.2.2-linux-amd64/bin/' >> /workspace/start-differential-testing.sh && \
    echo '    fi' >> /workspace/start-differential-testing.sh && \
    echo 'elif [ -f "$HOME/.jsvu/bin/graaljs" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying GraalJS binary from ~/.jsvu/bin/graaljs..."' >> /workspace/start-differential-testing.sh && \
    echo '    cp $HOME/.jsvu/bin/graaljs /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Also check ~/.jsvu/engines/ directory as fallback' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking for engines in ~/.jsvu/engines/..."' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -d "$HOME/.jsvu/engines/v8" ] && [ ! -d "/usr/local/bin/js-engines/v8" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying V8 directory from ~/.jsvu/engines/v8/..."' >> /workspace/start-differential-testing.sh && \
    echo '    cp -r $HOME/.jsvu/engines/v8/ /usr/local/bin/js-engines/v8/' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "$HOME/.jsvu/engines/hermes/hermes" ] && [ ! -f "/usr/local/bin/js-engines/hermes" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying Hermes from ~/.jsvu/engines/hermes/hermes..."' >> /workspace/start-differential-testing.sh && \
    echo '    cp $HOME/.jsvu/engines/hermes/hermes /usr/local/bin/js-engines/hermes' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "$HOME/.jsvu/engines/graaljs/graaljs" ] && [ ! -f "/usr/local/bin/js-engines/graaljs" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Copying GraalJS from ~/.jsvu/engines/graaljs/graaljs..."' >> /workspace/start-differential-testing.sh && \
    echo '    cp $HOME/.jsvu/engines/graaljs/graaljs /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Final engine status:"' >> /workspace/start-differential-testing.sh && \
    echo 'ls -la /usr/local/bin/js-engines/ || echo "No engines found"' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking symlinks:"' >> /workspace/start-differential-testing.sh && \
    echo 'ls -la /usr/local/bin/js-engines/' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking original files:"' >> /workspace/start-differential-testing.sh && \
    echo 'ls -la $HOME/.jsvu/engines/' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Testing engines:"' >> /workspace/start-differential-testing.sh && \
    echo 'echo "DEBUG: About to test V8..."' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "/usr/local/bin/js-engines/v8/v8" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "DEBUG: V8 exists, testing..."' >> /workspace/start-differential-testing.sh && \
    echo '    echo "console.log(\"V8 test successful\");" | /usr/local/bin/js-engines/v8/v8' >> /workspace/start-differential-testing.sh && \
    echo 'else' >> /workspace/start-differential-testing.sh && \
    echo '    echo "ERROR: V8 not found!"' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Checking if V8 exists in original location:"' >> /workspace/start-differential-testing.sh && \
    echo '    ls -la $HOME/.jsvu/engines/v8/v8 || echo "V8 not found in original location"' >> /workspace/start-differential-testing.sh && \
    echo '    echo "DEBUG: Skipping V8 test since engine does not exist"' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "/usr/local/bin/js-engines/hermes" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "DEBUG: About to test Hermes..."' >> /workspace/start-differential-testing.sh && \
    echo '    /usr/local/bin/js-engines/hermes --version' >> /workspace/start-differential-testing.sh && \
    echo 'else' >> /workspace/start-differential-testing.sh && \
    echo '    echo "ERROR: Hermes not found!"' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Checking if Hermes exists in original location:"' >> /workspace/start-differential-testing.sh && \
    echo '    ls -la $HOME/.jsvu/bin/hermes || echo "Hermes not found in original location"' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "/usr/local/bin/js-engines/graaljs" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "DEBUG: About to test GraalJS..."' >> /workspace/start-differential-testing.sh && \
    echo '    echo "console.log(\"GraalJS test successful\");" | /usr/local/bin/js-engines/graaljs' >> /workspace/start-differential-testing.sh && \
    echo 'else' >> /workspace/start-differential-testing.sh && \
    echo '    echo "ERROR: GraalJS not found!"' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Checking if GraalJS exists in original location:"' >> /workspace/start-differential-testing.sh && \
    echo '    ls -la $HOME/.jsvu/engines/graaljs/ || echo "GraalJS not found in original location"' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Test instrumentation capabilities' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Testing instrumentation capabilities..."' >> /workspace/start-differential-testing.sh && \
    echo 'cd /workspace' >> /workspace/start-differential-testing.sh && \
    echo 'if [ -f "kitten/scripts/javascript/test_instrumentation.sh" ]; then' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Running instrumentation test..."' >> /workspace/start-differential-testing.sh && \
    echo '    chmod +x kitten/scripts/javascript/test_instrumentation.sh' >> /workspace/start-differential-testing.sh && \
    echo '    kitten/scripts/javascript/test_instrumentation.sh || echo "Instrumentation test failed, continuing..."' >> /workspace/start-differential-testing.sh && \
    echo 'else' >> /workspace/start-differential-testing.sh && \
    echo '    echo "No instrumentation test script found, skipping..."' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Determine number of threads based on SLURM environment or system cores' >> /workspace/start-differential-testing.sh && \
    echo 'if [[ -n "${SLURM_CPUS_PER_TASK:-}" ]]; then' >> /workspace/start-differential-testing.sh && \
    echo '    THREADS="${SLURM_CPUS_PER_TASK}"' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Using SLURM_CPUS_PER_TASK: ${THREADS} threads"' >> /workspace/start-differential-testing.sh && \
    echo 'elif [[ -n "${SLURM_JOB_CPUS_PER_NODE:-}" ]]; then' >> /workspace/start-differential-testing.sh && \
    echo '    THREADS="${SLURM_JOB_CPUS_PER_NODE}"' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Using SLURM_JOB_CPUS_PER_NODE: ${THREADS} threads"' >> /workspace/start-differential-testing.sh && \
    echo 'elif [[ -n "${SLURM_NTASKS:-}" ]]; then' >> /workspace/start-differential-testing.sh && \
    echo '    THREADS="${SLURM_NTASKS}"' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Using SLURM_NTASKS: ${THREADS} threads"' >> /workspace/start-differential-testing.sh && \
    echo 'else' >> /workspace/start-differential-testing.sh && \
    echo '    THREADS=$(nproc)' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Using system cores: ${THREADS} threads"' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Determine memory allocation based on SLURM environment' >> /workspace/start-differential-testing.sh && \
    echo 'if [[ -n "${SLURM_MEM_PER_NODE:-}" ]]; then' >> /workspace/start-differential-testing.sh && \
    echo '    # Convert SLURM memory (in MB) to GB for JVM' >> /workspace/start-differential-testing.sh && \
    echo '    MEM_GB=$((SLURM_MEM_PER_NODE / 1024))' >> /workspace/start-differential-testing.sh && \
    echo '    # Reserve 2GB for system, use rest for JVM' >> /workspace/start-differential-testing.sh && \
    echo '    JVM_HEAP=$((MEM_GB - 2))' >> /workspace/start-differential-testing.sh && \
    echo '    echo "SLURM memory: ${SLURM_MEM_PER_NODE}MB, JVM heap: ${JVM_HEAP}G"' >> /workspace/start-differential-testing.sh && \
    echo 'else' >> /workspace/start-differential-testing.sh && \
    echo '    JVM_HEAP=16' >> /workspace/start-differential-testing.sh && \
    echo '    echo "Using default JVM heap: ${JVM_HEAP}G"' >> /workspace/start-differential-testing.sh && \
    echo 'fi' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Starting differential testing with instrumentation using ${THREADS} threads and ${JVM_HEAP}G heap..."' >> /workspace/start-differential-testing.sh && \
    echo 'cd /workspace' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Run the differential testing directly' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Starting differential testing with instrumentation..."' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Engines: Hermes, GraalJS (V8 skipped on ARM64)"' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Threads: ${THREADS}"' >> /workspace/start-differential-testing.sh && \
    echo 'echo "JVM Heap: ${JVM_HEAP}G"' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Differential findings will be saved to: kitten/temp_testing_campaigns/differential_finding_folder_javascript"' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Instrumentation will be applied to JavaScript files for enhanced differential testing"' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'java -Xmx${JVM_HEAP}G -Xms4G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \' >> /workspace/start-differential-testing.sh && \
    echo '  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \' >> /workspace/start-differential-testing.sh && \
    echo '  --threads ${THREADS} \' >> /workspace/start-differential-testing.sh && \
    echo '  --verbosity "FINE" \' >> /workspace/start-differential-testing.sh && \
    echo '  --timeout 1000000000 \' >> /workspace/start-differential-testing.sh && \
    echo '  --validate-seeds-on-all-engines \' >> /workspace/start-differential-testing.sh && \
    echo '  --finding-folder "kitten/temp_testing_campaigns/differential_finding_folder_javascript"' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Differential testing with instrumentation completed!"' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Check kitten/temp_testing_campaigns/differential_finding_folder_javascript for differential findings."' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Instrumented files will have \"instrumented_\" prefix in the findings."' >> /workspace/start-differential-testing.sh

RUN chmod +x /workspace/start-differential-testing.sh

# Set the default command
CMD ["/workspace/start-differential-testing.sh"] 