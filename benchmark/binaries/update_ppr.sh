#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if ! [ -e "/tmp/binaries/ppr_deploy.jar" ]; then
  pushd "${BINARY_DIR}"
  bazel build //ppr/src/org/perses/ppr:main_deploy.jar
  mkdir -p /tmp/binaries
  ln -s "${BINARY_DIR}/../../bazel-bin/ppr/src/org/perses/ppr/main_deploy.jar" \
    "/tmp/binaries/ppr_deploy.jar"
  chmod a+X "/tmp/binaries/ppr_deploy.jar"
  popd
fi

#echo "Compiled on $(date +%Y%m%d_%H%M%S_%Z)" > perses_version.txt
