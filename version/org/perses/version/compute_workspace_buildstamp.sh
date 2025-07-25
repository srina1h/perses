#!/bin/bash

# This script is used by Bazel to compute workspace status
# It outputs key-value pairs that Bazel uses for build stamping

set -e

# Get the current timestamp
BUILD_TIMESTAMP=$(date -u +"%Y-%m-%d %H:%M:%S UTC")

# Get git information if available
if command -v git >/dev/null 2>&1 && git rev-parse --git-dir >/dev/null 2>&1; then
    GIT_COMMIT=$(git rev-parse HEAD 2>/dev/null || echo "unknown")
    GIT_BRANCH=$(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo "unknown")
    GIT_DIRTY=$(git diff-index --quiet HEAD -- 2>/dev/null && echo "clean" || echo "dirty")
else
    GIT_COMMIT="unknown"
    GIT_BRANCH="unknown"
    GIT_DIRTY="unknown"
fi

# Output the build stamp information
echo "BUILD_TIMESTAMP ${BUILD_TIMESTAMP}"
echo "GIT_COMMIT ${GIT_COMMIT}"
echo "GIT_BRANCH ${GIT_BRANCH}"
echo "GIT_DIRTY ${GIT_DIRTY}"
echo "BUILD_USER $(whoami)"
echo "BUILD_HOST $(hostname)" 