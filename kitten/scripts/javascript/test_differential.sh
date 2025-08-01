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

# Create test-specific folders
readonly TEST_FINDING_FOLDER="${CAMPAIGN_ROOT_DIR}/test_differential_finding_folder"
readonly TEST_PROCESSING_FOLDER="${CAMPAIGN_ROOT_DIR}/test_differential_processing_folder"
readonly TEST_DUPLICATE_FOLDER="${CAMPAIGN_ROOT_DIR}/test_differential_duplicate_folder"

mkdir -p "${TEST_FINDING_FOLDER}"
mkdir -p "${TEST_PROCESSING_FOLDER}"
mkdir -p "${TEST_DUPLICATE_FOLDER}"

echo "Testing differential fuzzing with a small number of iterations..."
echo "This will test the differential testing functionality with the seed files."

# Run with a small number of iterations to test the functionality
java -Xmx4G -Xms1G -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "${SCRIPT_DIR}/differential-testing-config.yaml" \
  --threads 2 \
  --verbosity "INFO" \
  --finding-folder "${TEST_FINDING_FOLDER}" \
  --timeout 60 \
  --max-seed-pool-size 5

echo "Test completed!"
echo "Check ${TEST_FINDING_FOLDER} for any differential findings."
echo "Check ${TEST_PROCESSING_FOLDER} for processing logs." 