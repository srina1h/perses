#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

git clean -d --interactive -x \
  --exclude ".ijwb" \
  --exclude "bazel-bin" \
  --exclude "bazel-out" \
  --exclude "bazel-testlogs" \
  --exclude "bazel-perses-private"
