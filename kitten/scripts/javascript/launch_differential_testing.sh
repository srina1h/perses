#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ ! -e "WORKSPACE" ]]; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
source "${SCRIPT_DIR}/configuration.sh" || exit 1

# Create differential testing specific folders
readonly DIFFERENTIAL_FINDING_FOLDER="${CAMPAIGN_ROOT_DIR}/differential_finding_folder_javascript"
readonly DIFFERENTIAL_PROCESSING_FOLDER="${CAMPAIGN_ROOT_DIR}/differential_processing_folder_javascript"
readonly DIFFERENTIAL_DUPLICATE_FOLDER="${CAMPAIGN_ROOT_DIR}/differential_duplicate_folder_javascript"

mkdir -p "${DIFFERENTIAL_FINDING_FOLDER}"
mkdir -p "${DIFFERENTIAL_PROCESSING_FOLDER}"
mkdir -p "${DIFFERENTIAL_DUPLICATE_FOLDER}"

echo "Building kitten with differential testing support..."
bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar || exit 1

echo "Starting differential testing with multiple JavaScript engines..."
echo "Engines: V8, Hermes, GraalJS, JavaScriptCore"
echo "Differential findings will be saved to: ${DIFFERENTIAL_FINDING_FOLDER}"

java -Xmx210G -Xms30G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "${SCRIPT_DIR}/differential-testing-config.yaml" \
  --threads 5 \
  --verbosity "FINE" \
  --finding-folder "${DIFFERENTIAL_FINDING_FOLDER}"

echo "Differential testing completed!"
echo "Check ${DIFFERENTIAL_FINDING_FOLDER} for differential findings." 