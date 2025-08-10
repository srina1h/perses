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
    gnupg \
    ca-certificates \
    libc6-dev \
    libstdc++6 \
    && curl -fsSL https://deb.nodesource.com/setup_18.x | bash - \
    && apt-get install -y nodejs \
    && apt-get clean \
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

# Install JSVU globally
RUN npm install jsvu -g

# Install JavaScript engines via JSVU (use correct architecture)
RUN ARCH=$(uname -m) \
    && if [ "$ARCH" = "x86_64" ]; then \
        jsvu --os=linux64 --engines=all; \
    elif [ "$ARCH" = "aarch64" ]; then \
        jsvu --os=linux64 --engines=graaljs,hermes,spidermonkey,jsc,xs,quickjs \
        && echo "Installing available engines on ARM64 (V8 not available)"; \
    fi

# Add JSVU bin directory to PATH
ENV PATH="/root/.jsvu/bin:$PATH"

# Clone the perses repository
WORKDIR /workspace
RUN git clone https://github.com/srina1h/perses.git .
RUN git checkout diff_instrumented

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
    echo 'if [ -f "kitten/scripts/javascript/all-compilers-config.yaml" ]; then' >> /workspace/update-config.sh && \
    echo '    echo "Updating configuration paths..."' >> /workspace/update-config.sh && \
    echo '    # Update all engine paths to use global commands' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/hermes|hermes|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/graaljs|graaljs|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/v8|v8|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/spidermonkey|spidermonkey|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/jsc|jsc|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/xs|xs|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    sed -i "s|/Users/srinath/.jsvu/bin/quickjs|quickjs|g" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    # Remove V8 configuration on ARM64' >> /workspace/update-config.sh && \
    echo '    if [ "$(uname -m)" = "aarch64" ]; then' >> /workspace/update-config.sh && \
    echo '        echo "Removing V8 configuration on ARM64..."' >> /workspace/update-config.sh && \
    echo '        sed -i "/command: \"v8\"/,/crashDetectorClassName: \"org.perses.fuzzer.compilers.javascript.V8CrashDetector\"/d" kitten/scripts/javascript/all-compilers-config.yaml' >> /workspace/update-config.sh && \
    echo '    fi' >> /workspace/update-config.sh && \
    echo '    echo "Configuration update completed."' >> /workspace/update-config.sh && \
    echo 'else' >> /workspace/update-config.sh && \
    echo '    echo "ERROR: Config file not found!"' >> /workspace/update-config.sh && \
    echo '    exit 1' >> /workspace/update-config.sh && \
    echo 'fi' >> /workspace/update-config.sh

RUN chmod +x /workspace/update-config.sh

# Create the main entry script
RUN echo '#!/bin/bash' > /workspace/start-differential-testing.sh && \
    echo 'set -e' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Starting differential testing setup..."' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Update configuration paths' >> /workspace/start-differential-testing.sh && \
    echo './update-config.sh' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo '# Verify JavaScript engines are available' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Verifying JavaScript engines..."' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking V8:" && which v8 && v8 --version' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking SpiderMonkey:" && which spidermonkey && spidermonkey --version' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking JavaScriptCore:" && which jsc && jsc --version' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking XS:" && which xs && xs -v' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking GraalJS:" && which graaljs && graaljs --version' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking QuickJS:" && which quickjs && quickjs --version' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Checking Hermes:" && which hermes && hermes --version' >> /workspace/start-differential-testing.sh && \
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
    echo 'echo "Starting differential testing with ${THREADS} threads and ${JVM_HEAP}G heap..."' >> /workspace/start-differential-testing.sh && \
    echo 'cd /workspace' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'java -Xmx${JVM_HEAP}G -Xms4G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \' >> /workspace/start-differential-testing.sh && \
    echo '  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \' >> /workspace/start-differential-testing.sh && \
    echo '  --threads ${THREADS} \' >> /workspace/start-differential-testing.sh && \
    echo '  --verbosity "FINE" \' >> /workspace/start-differential-testing.sh && \
    echo '  --timeout 1000000000 \' >> /workspace/start-differential-testing.sh && \
    echo '  --finding-folder "kitten/temp_testing_campaigns/differential_finding_folder_javascript"' >> /workspace/start-differential-testing.sh && \
    echo '' >> /workspace/start-differential-testing.sh && \
    echo 'echo "Differential testing completed!"' >> /workspace/start-differential-testing.sh

RUN chmod +x /workspace/start-differential-testing.sh

# Set the default command
CMD ["/workspace/start-differential-testing.sh"] 