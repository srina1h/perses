#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
source "${SCRIPT_DIR}/../configuration.sh" || exit 1

bazelisk build //kitten/src/org/perses/fuzzer:kitten_deploy.jar || exit 1

java -Xmx32G -Xms16G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "${SCRIPT_DIR}/../clang-guided-generation.yaml" \
  --threads 1 \
  --timeout 86400 \
  --shuffle-seed false \
  --verbosity "INFO" \
  --finding-folder "${FINDING_FOLDER}" \
  --coverage-info "${PWD}/kitten/temp_compilers_source/clang_guided_generation/llvm-build-trunk" \
  --compiler-source "${PWD}/kitten/temp_compilers_source/clang_guided_generation/llvm-project" \
  --coverage-interval 600 \
  --coverage-save "${PWD}/kitten/temp_compilers_source/clang_guided_generation/coverage" \
  --language-model "N_DEPTH_TREE_MODEL" \
  --generator "GUIDED_GENERATOR" \
  --seed-limit 20000
