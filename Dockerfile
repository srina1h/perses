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
RUN jsvu --os=linux64 --engines=graaljs,hermes,v8

# Find and copy JS engines to a standard location
RUN mkdir -p /usr/local/bin/js-engines \
    && echo "Copying JS engines..." \
    # Find the 'v8' executable inside its directory and copy it
    && cp $(find ~/.jsvu/engines/v8 -type f -name v8) /usr/local/bin/js-engines/v8 \
    # Find the 'hermes' executable
    && cp $(find ~/.jsvu/engines/hermes -type f -name hermes) /usr/local/bin/js-engines/hermes \
    # Use the direct symlink for GraalJS
    && cp ~/.jsvu/bin/graaljs /usr/local/bin/js-engines/graaljs \
    && echo "Verifying copied engines:" \
    && ls -la /usr/local/bin/js-engines/

# Clone the perses repository
WORKDIR /workspace
RUN git clone https://github.com/srina1h/perses.git .
RUN git checkout diff

# Prepare seeds by running the prepare_seeds.sh script
RUN chmod +x prepare_seeds.sh && ./prepare_seeds.sh

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
echo "Updating configuration paths..."
sed -i 's|/Users/srinath/.jsvu/bin/v8|/usr/local/bin/js-engines/v8|g' kitten/scripts/javascript/all-compilers-config.yaml
sed -i 's|/Users/srinath/.jsvu/bin/hermes|/usr/local/bin/js-engines/hermes|g' kitten/scripts/javascript/all-compilers-config.yaml
sed -i 's|/Users/srinath/.jsvu/bin/graaljs|/usr/local/bin/js-engines/graaljs|g' kitten/scripts/javascript/all-compilers-config.yaml
echo "Configuration update completed."
EOF

RUN chmod +x /workspace/update-config.sh

# Create the main entry script with SLURM support
RUN cat > /workspace/start-differential-testing.sh << 'EOF'
#!/bin/bash
set -e

echo "Starting differential testing setup..."

# Update configuration paths
/workspace/update-config.sh

# Verify engines (which were copied during the Docker build)
echo "Verifying JavaScript engines are executable:"
ls -la /usr/local/bin/js-engines/
/usr/local/bin/js-engines/v8 --version
/usr/local/bin/js-engines/hermes --version
/usr/local/bin/js-engines/graaljs --version

# Determine number of threads
if [[ -n "${SLURM_CPUS_PER_TASK:-}" ]]; then
    THREADS="${SLURM_CPUS_PER_TASK}"
elif [[ -n "${SLURM_JOB_CPUS_PER_NODE:-}" ]]; then
    THREADS="${SLURM_JOB_CPUS_PER_NODE}"
else
    THREADS=$(nproc)
fi
echo "Using ${THREADS} threads"

# Determine memory allocation
if [[ -n "${SLURM_MEM_PER_NODE:-}" ]]; then
    MEM_GB=$((SLURM_MEM_PER_NODE / 1024))
    JVM_HEAP=$((MEM_GB > 2 ? MEM_GB - 2 : 1)) # Ensure at least 1G
else
    JVM_HEAP=16
fi
echo "Using JVM heap: ${JVM_HEAP}G"

echo "Starting differential testing..."
cd /workspace

java -Xmx${JVM_HEAP}G -Xms4G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \
  --threads "${THREADS}" \
  --verbosity "FINE" \
  --finding-folder "kitten/temp_testing_campaigns/differential_finding_folder_javascript"

echo "Differential testing completed!"
EOF

RUN chmod +x /workspace/start-differential-testing.sh

# Set the default command
CMD ["/workspace/start-differential-testing.sh"]