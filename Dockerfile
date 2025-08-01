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

# Install JavaScript engines via JSVU
RUN jsvu --os=linux64 --engines=v8,hermes,graaljs,jsc

# Create symlinks for the engines in a standard location
RUN mkdir -p /usr/local/bin/js-engines \
    && ln -sf ~/.jsvu/v8 /usr/local/bin/js-engines/v8 \
    && ln -sf ~/.jsvu/hermes /usr/local/bin/js-engines/hermes \
    && ln -sf ~/.jsvu/graaljs /usr/local/bin/js-engines/graaljs \
    && ln -sf ~/.jsvu/jsc /usr/local/bin/js-engines/jsc

# Clone the perses repository
WORKDIR /workspace
RUN git clone https://github.com/srina1h/perses.git .

# Create necessary directories
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
if [ -f "kitten/scripts/javascript/differential-testing-config.yaml" ]; then
    echo "Config file found!"
    echo "Updating configuration paths..."
    sed -i 's|/Users/srinath/.jsvu/bin/v8|/usr/local/bin/js-engines/v8|g' kitten/scripts/javascript/differential-testing-config.yaml
    sed -i 's|/Users/srinath/.jsvu/bin/hermes|/usr/local/bin/js-engines/hermes|g' kitten/scripts/javascript/differential-testing-config.yaml
    sed -i 's|/Users/srinath/.jsvu/bin/graaljs|/usr/local/bin/js-engines/graaljs|g' kitten/scripts/javascript/differential-testing-config.yaml
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
/usr/local/bin/js-engines/v8 --version
/usr/local/bin/js-engines/hermes --version
/usr/local/bin/js-engines/graaljs --version
/usr/local/bin/js-engines/jsc --version

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

echo "Building kitten with differential testing support..."
bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar || exit 1

echo "Starting differential testing with multiple JavaScript engines..."
echo "Engines: V8, Hermes, GraalJS, JavaScriptCore"
echo "Threads: THREADS_PLACEHOLDER"
echo "JVM Heap: JVM_HEAP_PLACEHOLDER"
echo "Differential findings will be saved to: kitten/temp_testing_campaigns/differential_finding_folder_javascript"

java -XmxJVM_HEAP_PLACEHOLDER -Xms4G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "kitten/scripts/javascript/differential-testing-config.yaml" \
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