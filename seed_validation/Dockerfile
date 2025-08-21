# Seed Validation-only Dockerfile
# Builds Perses (Kitten) and runs comprehensive seed validation, saving passing seeds.

FROM ubuntu:22.04

ARG SEED_MODE=normal

ENV DEBIAN_FRONTEND=noninteractive \
    PATH=/root/bin:$PATH

# System dependencies
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

# Git identity for Bazel workspace status
RUN git config --global user.name "Docker Build" \
    && git config --global user.email "docker@build.local"

# Bazel
RUN ARCH=$(uname -m) \
    && if [ "$ARCH" = "x86_64" ]; then \
        curl -fsSL https://github.com/bazelbuild/bazel/releases/download/7.4.1/bazel-7.4.1-linux-x86_64 -o /usr/local/bin/bazel; \
    elif [ "$ARCH" = "aarch64" ]; then \
        curl -fsSL https://github.com/bazelbuild/bazel/releases/download/7.4.1/bazel-7.4.1-linux-arm64 -o /usr/local/bin/bazel; \
    fi \
    && chmod +x /usr/local/bin/bazel \
    && bazel --version

# JAVA_HOME
RUN JAVA_HOME=$(update-alternatives --query java | grep 'Value:' | head -1 | awk '{print $2}' | sed 's|/bin/java||') \
    && echo "export JAVA_HOME=$JAVA_HOME" >> /etc/environment \
    && echo "export JAVA_HOME=$JAVA_HOME" >> /root/.bashrc \
    && export JAVA_HOME=$JAVA_HOME

# JS engines and eshost
RUN npm install -g eshost-cli jsvu

RUN ARCH=$(uname -m) \
    && if [ "$ARCH" = "x86_64" ]; then \
        jsvu --os=linux64 --engines=all; \
    elif [ "$ARCH" = "aarch64" ]; then \
        jsvu --os=linux64 --engines=graaljs,hermes,spidermonkey,jsc,xs,quickjs \
        && echo "Installing available engines on ARM64 (V8 not available)"; \
    fi

ENV PATH="/root/.jsvu/bin:$PATH"

# Configure eshost hosts
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

WORKDIR /workspace

# Copy current repo (keeps local modifications)
COPY . /workspace

# Prepare seeds
RUN if [ "$SEED_MODE" = "test262" ]; then \
        echo "Preparing test262 seeds"; \
        chmod +x prepare_test262_seeds.sh && ./prepare_test262_seeds.sh; \
    elif [ "$SEED_MODE" = "normal" ]; then \
        echo "Preparing normal regression seeds"; \
        chmod +x prepare_seeds.sh && ./prepare_seeds.sh; \
    fi

# Build Kitten deploy jar
RUN bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar

# Default output directory for validated seeds
ENV VALIDATED_OUT_DIR=/workspace/validated_seeds

# Start script to run validation-only
RUN echo '#!/bin/bash' > /workspace/start_validation.sh && \
    echo 'set -euo pipefail' >> /workspace/start_validation.sh && \
    echo 'THREADS=${THREADS:-$(nproc)}' >> /workspace/start_validation.sh && \
    echo 'JVM_HEAP=${JVM_HEAP:-8}' >> /workspace/start_validation.sh && \
    echo 'SEED_LIMIT=${SEED_LIMIT:-2147483647}' >> /workspace/start_validation.sh && \
    echo 'VERBOSITY=${VERBOSITY:-INFO}' >> /workspace/start_validation.sh && \
    echo 'mkdir -p "${VALIDATED_OUT_DIR}"' >> /workspace/start_validation.sh && \
    echo 'exec java -Xmx${JVM_HEAP}G -Xms1G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \' >> /workspace/start_validation.sh && \
    echo '  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \' >> /workspace/start_validation.sh && \
    echo '  --threads ${THREADS} \' >> /workspace/start_validation.sh && \
    echo '  --verbosity "${VERBOSITY}" \' >> /workspace/start_validation.sh && \
    echo '  --seed-limit ${SEED_LIMIT} \' >> /workspace/start_validation.sh && \
    echo '  --validate-seeds-only true \' >> /workspace/start_validation.sh && \
    echo '  --validated-seed-output-dir "${VALIDATED_OUT_DIR}"' >> /workspace/start_validation.sh && \
    chmod +x /workspace/start_validation.sh

CMD ["/workspace/start_validation.sh"]


