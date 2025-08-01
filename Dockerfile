# Use Ubuntu 22.04 as base image
FROM ubuntu:22.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
ENV PATH=$JAVA_HOME/bin:/root/bin:$PATH

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
    && rm -rf /var/lib/apt/lists/*

# Install Bazel 7.4.1 (specific version required by the project)
RUN BAZEL_VERSION=7.4.1 \
    && curl -fsSL https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/bazel-${BAZEL_VERSION}-installer-linux-x86_64.sh -o bazel-installer.sh \
    && chmod +x bazel-installer.sh \
    && ./bazel-installer.sh --user \
    && rm bazel-installer.sh \
    && ln -sf $HOME/bin/bazel /usr/local/bin/bazel \
    && bazel --version

# Install JSVU (JavaScript Version Updater)
RUN npm install -g jsvu

# Install JavaScript engines via JSVU (install all together)
RUN jsvu --os=linux64 --engines=graaljs,hermes,v8 \
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
# Create necessary directoriesß
RUN mkdir -p kitten/temp_testing_campaigns/differential_finding_folder_javascript \
    && mkdir -p kitten/temp_testing_campaigns/differential_processing_folder_javascript \
    && mkdir -p kitten/temp_testing_campaigns/differential_duplicate_folder_javascript \
    && mkdir -p kitten/reported_bugs/javascript

# Build the project
RUN bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar

# Create a script to update the configuration with correct paths
RUN cat > /workspace/update-config.sh << 'EOF'
#!/bin/bash
# Update the differential testing config with correct paths
cd /workspace
echo "Current directory: $(pwd)"
echo "Checking if config file exists:"
if [ -f "kitten/scripts/javascript/all-compilers-config.yaml" ]; then
    echo "Config file found!"
    echo "Updating configuration paths..."
    sed -i 's|/Users/srinath/.jsvu/bin/v8|/usr/local/bin/js-engines/v8|g' kitten/scripts/javascript/all-compilers-config.yaml
    sed -i 's|/Users/srinath/.jsvu/bin/hermes|/usr/local/bin/js-engines/hermes|g' kitten/scripts/javascript/all-compilers-config.yaml
    sed -i 's|/Users/srinath/.jsvu/bin/graaljs|/usr/local/bin/js-engines/graaljs|g' kitten/scripts/javascript/all-compilers-config.yaml
    echo "Configuration update completed."
else
    echo "ERROR: Config file not found!"
    echo "Available files in kitten/scripts/javascript/:"
    ls -la kitten/scripts/javascript/ || echo "Directory not found!"
    exit 1
fi
EOF

RUN chmod +x /workspace/update-config.sh

# Create the main entry script with SLURM support
RUN cat > /workspace/start-differential-testing.sh << 'EOF'
#!/bin/bash
set -e

echo "Starting differential testing setup..."

# Update configuration paths
./update-config.sh

# Verify JavaScript engines are available
echo "Verifying JavaScript engines..."

# Debug: Show what we're about to do
echo "DEBUG: About to check and create symlinks..."
echo "DEBUG: HOME=$HOME"
echo "DEBUG: Checking if V8 exists at $HOME/.jsvu/engines/v8/v8"

# Ensure engines are available (they should be copied during build)
echo "Checking if engines are available..."
mkdir -p /usr/local/bin/js-engines
echo "Available engines:"
ls -la /usr/local/bin/js-engines/ || echo "No engines found"

# Try to copy engines if they're not already copied
echo "Checking for engines in ~/.jsvu/bin/..."
if [ -f "$HOME/.jsvu/bin/v8" ] && [ ! -f "/usr/local/bin/js-engines/v8" ]; then
    echo "Copying V8 from ~/.jsvu/bin/v8..."
    cp $HOME/.jsvu/bin/v8 /usr/local/bin/js-engines/v8
fi
if [ -f "$HOME/.jsvu/bin/hermes" ] && [ ! -f "/usr/local/bin/js-engines/hermes" ]; then
    echo "Copying Hermes from ~/.jsvu/bin/hermes..."
    cp $HOME/.jsvu/bin/hermes /usr/local/bin/js-engines/hermes
fi
if [ -d "$HOME/.jsvu/engines/graaljs" ]; then
    echo "Copying GraalJS directory from ~/.jsvu/engines/graaljs/..."
    cp -r $HOME/.jsvu/engines/graaljs/ /usr/local/bin/js-engines/graaljs/
    echo "Creating symlink to GraalJS binary..."
    ln -sf /usr/local/bin/js-engines/graaljs/graaljs-24.2.2-linux-amd64 /usr/local/bin/js-engines/graaljs
elif [ -f "$HOME/.jsvu/bin/graaljs" ]; then
    echo "Copying GraalJS binary from ~/.jsvu/bin/graaljs..."
    cp $HOME/.jsvu/bin/graaljs /usr/local/bin/js-engines/graaljs
fi

# Also check ~/.jsvu/engines/ directory as fallback
echo "Checking for engines in ~/.jsvu/engines/..."
if [ -d "$HOME/.jsvu/engines/v8" ] && [ ! -d "/usr/local/bin/js-engines/v8" ]; then
    echo "Copying V8 directory from ~/.jsvu/engines/v8/..."
    cp -r $HOME/.jsvu/engines/v8/ /usr/local/bin/js-engines/v8/
fi
if [ -f "$HOME/.jsvu/engines/hermes/hermes" ] && [ ! -f "/usr/local/bin/js-engines/hermes" ]; then
    echo "Copying Hermes from ~/.jsvu/engines/hermes/hermes..."
    cp $HOME/.jsvu/engines/hermes/hermes /usr/local/bin/js-engines/hermes
fi
if [ -f "$HOME/.jsvu/engines/graaljs/graaljs" ] && [ ! -f "/usr/local/bin/js-engines/graaljs" ]; then
    echo "Copying GraalJS from ~/.jsvu/engines/graaljs/graaljs..."
    cp $HOME/.jsvu/engines/graaljs/graaljs /usr/local/bin/js-engines/graaljs
fi

echo "Final engine status:"
ls -la /usr/local/bin/js-engines/ || echo "No engines found"

echo "Checking symlinks:"
ls -la /usr/local/bin/js-engines/
echo "Checking original files:"
ls -la $HOME/.jsvu/engines/
echo "Testing engines:"
echo "DEBUG: About to test V8..."
if [ -f "/usr/local/bin/js-engines/v8/v8" ]; then
    echo "DEBUG: V8 exists, testing..."
    echo "console.log('V8 test successful');" | /usr/local/bin/js-engines/v8/v8
else
    echo "ERROR: V8 not found!"
    echo "Checking if V8 exists in original location:"
    ls -la $HOME/.jsvu/engines/v8/v8 || echo "V8 not found in original location"
    echo "DEBUG: Skipping V8 test since engine doesn't exist"
fi
if [ -f "/usr/local/bin/js-engines/hermes" ]; then
    echo "DEBUG: About to test Hermes..."
    /usr/local/bin/js-engines/hermes --version
else
    echo "ERROR: Hermes not found!"
    echo "Checking if Hermes exists in original location:"
    ls -la $HOME/.jsvu/bin/hermes || echo "Hermes not found in original location"
fi
if [ -f "/usr/local/bin/js-engines/graaljs" ]; then
    echo "DEBUG: About to test GraalJS..."
    echo "console.log('GraalJS test successful');" | /usr/local/bin/js-engines/graaljs
else
    echo "ERROR: GraalJS not found!"
    echo "Checking if GraalJS exists in original location:"
    ls -la $HOME/.jsvu/engines/graaljs/ || echo "GraalJS not found in original location"
fi

# Determine number of threads based on SLURM environment or system cores
if [[ -n "${SLURM_CPUS_PER_TASK:-}" ]]; then
    THREADS="${SLURM_CPUS_PER_TASK}"
    echo "Using SLURM_CPUS_PER_TASK: ${THREADS} threads"
elif [[ -n "${SLURM_JOB_CPUS_PER_NODE:-}" ]]; then
    THREADS="${SLURM_JOB_CPUS_PER_NODE}"
    echo "Using SLURM_JOB_CPUS_PER_NODE: ${THREADS} threads"
elif [[ -n "${SLURM_NTASKS:-}" ]]; then
    THREADS="${SLURM_NTASKS}"
    echo "Using SLURM_NTASKS: ${THREADS} threads"
else
    THREADS=$(nproc)
    echo "Using system cores: ${THREADS} threads"
fi

# Determine memory allocation based on SLURM environment
if [[ -n "${SLURM_MEM_PER_NODE:-}" ]]; then
    # Convert SLURM memory (in MB) to GB for JVM
    MEM_GB=$((SLURM_MEM_PER_NODE / 1024))
    # Reserve 2GB for system, use rest for JVM
    JVM_HEAP=$((MEM_GB - 2))
    echo "SLURM memory: ${SLURM_MEM_PER_NODE}MB, JVM heap: ${JVM_HEAP}G"
else
    JVM_HEAP=16
    echo "Using default JVM heap: ${JVM_HEAP}G"
fi

echo "Starting differential testing with ${THREADS} threads and ${JVM_HEAP}G heap..."
cd /workspace

# Create a temporary script with the correct thread count
cat > /workspace/run-differential-testing-temp.sh << 'INNER_EOF'
#!/bin/bash
set -e

echo "Starting differential testing with multiple JavaScript engines..."
echo "Engines: V8, Hermes, GraalJS"
echo "Threads: THREADS_PLACEHOLDER"
echo "JVM Heap: JVM_HEAP_PLACEHOLDER"
echo "Differential findings will be saved to: kitten/temp_testing_campaigns/differential_finding_folder_javascript"

java -XmxJVM_HEAP_PLACEHOLDER -Xms4G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \
  --threads THREADS_PLACEHOLDER \
  --verbosity "FINE" \
  --finding-folder "kitten/temp_testing_campaigns/differential_finding_folder_javascript"

echo "Differential testing completed!"
echo "Check kitten/temp_testing_campaigns/differential_finding_folder_javascript for differential findings."
INNER_EOF

# Replace placeholders with actual values
sed -i "s/THREADS_PLACEHOLDER/${THREADS}/g" /workspace/run-differential-testing-temp.sh
sed -i "s/JVM_HEAP_PLACEHOLDER/${JVM_HEAP}G/g" /workspace/run-differential-testing-temp.sh

chmod +x /workspace/run-differential-testing-temp.sh
./run-differential-testing-temp.sh
EOF

RUN chmod +x /workspace/start-differential-testing.sh

# Set the default command
CMD ["/workspace/start-differential-testing.sh"] 