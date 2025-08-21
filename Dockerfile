# Use Ubuntu 22.04 as base image
FROM ubuntu:22.04

# Set build argument for seed mode
ARG SEED_MODE=normal

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

# Configure Git for Bazel workspace status (needed for build)
RUN git config --global user.name "Docker Build" \
    && git config --global user.email "docker@build.local"

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

# Install eshost and JSVU globally
RUN npm install -g eshost-cli jsvu

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

# Configure eshost hosts using JSVU-installed binaries (only add if present)
RUN set -eux; \
    mkdir -p /root/.eshost; \
    if [ "$SEED_MODE" = "test262" ]; then \
        echo "Configuring eshost for test262 mode"; \
        if [ -x /root/.jsvu/bin/graaljs ]; then eshost --add 'GJS' graaljs /root/.jsvu/bin/graaljs; fi; \
        if [ -x /root/.jsvu/bin/javascriptcore ]; then eshost --add 'JSC' jsc /root/.jsvu/bin/javascriptcore; fi; \
        if [ -x /root/.jsvu/bin/spidermonkey ]; then eshost --add 'SM' jsshell /root/.jsvu/bin/spidermonkey; fi; \
        if [ -x /root/.jsvu/bin/v8 ]; then eshost --add 'V8' d8 /root/.jsvu/bin/v8; fi; \
    elif [ "$SEED_MODE" = "normal" ]; then \
        echo "Configuring eshost for normal mode with fuzzing harnesses"; \
        if [ -x /root/.jsvu/bin/graaljs ]; then eshost --add 'GJS' graaljs /root/.jsvu/bin/graaljs -h /workspace/fuzzing_harness/graal.js; fi; \
        if [ -x /root/.jsvu/bin/javascriptcore ]; then eshost --add 'JSC' jsc /root/.jsvu/bin/javascriptcore -h /workspace/fuzzing_harness/jsc.js; fi; \
        if [ -x /root/.jsvu/bin/spidermonkey ]; then eshost --add 'SM' jsshell /root/.jsvu/bin/spidermonkey -h /workspace/fuzzing_harness/sm.js; fi; \
        if [ -x /root/.jsvu/bin/v8 ]; then eshost --add 'V8' d8 /root/.jsvu/bin/v8 -h /workspace/fuzzing_harness/v8.js; fi; \
    else \
        echo "Invalid SEED_MODE: $SEED_MODE. Must be 'normal' or 'test262'"; \
        exit 1; \
    fi; \
    eshost --list || true

ARG CACHE_BUST

# Copy the current repository into the image
WORKDIR /workspace
RUN echo "Cloning repository with cache buster: $CACHE_BUST"
RUN git clone https://github.com/srina1h/perses.git .
RUN git checkout diff_eshost

# Prepare seeds based on SEED_MODE
RUN if [ "$SEED_MODE" = "test262" ]; then \
        echo "Preparing test262 seeds"; \
        chmod +x prepare_test262_seeds.sh && ./prepare_test262_seeds.sh; \
    elif [ "$SEED_MODE" = "normal" ]; then \
        echo "Preparing normal regression seeds"; \
        chmod +x prepare_seeds.sh && ./prepare_seeds.sh; \
    fi

# Create necessary directories for differential testing with instrumentation
RUN mkdir -p kitten/temp_testing_campaigns/differential_finding_folder_javascript \
    && mkdir -p kitten/temp_testing_campaigns/differential_processing_folder_javascript \
    && mkdir -p kitten/temp_testing_campaigns/differential_duplicate_folder_javascript \
    && mkdir -p kitten/reported_bugs/javascript \
    && mkdir -p kitten/scripts/javascript/seeds

# Build the project with instrumentation support
RUN bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar

# Minimal start script using eshost-driven config
RUN echo '#!/bin/bash' > /workspace/start.sh && \
    echo 'set -euo pipefail' >> /workspace/start.sh && \
    echo 'THREADS=${THREADS:-$(nproc)}' >> /workspace/start.sh && \
    echo 'JVM_HEAP=${JVM_HEAP:-8}' >> /workspace/start.sh && \
    echo 'echo "Threads: ${THREADS}, JVM heap: ${JVM_HEAP}G"' >> /workspace/start.sh && \
    echo 'exec java -Xmx${JVM_HEAP}G -Xms1G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \' >> /workspace/start.sh && \
    echo '  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \' >> /workspace/start.sh && \
    echo '  --threads ${THREADS} \' >> /workspace/start.sh && \
    echo '  --verbosity "FINE" \' >> /workspace/start.sh && \
    echo '  --timeout 1000000000 \' >> /workspace/start.sh && \
    echo '  --finding-folder "kitten/temp_testing_campaigns/differential_finding_folder_javascript"' >> /workspace/start.sh && \
    chmod +x /workspace/start.sh

# Default command
CMD ["/workspace/start.sh"]