#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
#set -o xtrace

#expect
# UNPATCHED r
# code to be reduced
# STAT FILE

#do
# run perses on file to be reduced with r, collect stats

if [ $# -gt 1 ]; then
  echo "Running with arguments: $0 $@"
else
  echo "Expect arguments $0 TEST_SCRIPT SEED_FILE VARIANT_FILE [COMPLETE_STAT_FILE]"
  exit 1
fi

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

#command line arguments
readonly TEST_SCRIPT=$1
readonly SEED_FILE=$2
readonly VARIANT_FILE=$3
readonly OUTPUT_DIR=$4
readonly COMPLETE_STAT_FILE=${5:-}
SCRIPT_NAME=$(basename "${TEST_SCRIPT}")
readonly SCRIPT_NAME
SEED_NAME=$(basename "${SEED_FILE}")
readonly SEED_NAME
VARIANT_NAME=$(basename "${VARIANT_FILE}")
readonly VARIANT_NAME
THREADS=1
readonly THREADS

#set up temp file
readonly TMP=$(mktemp -d)
readonly TMP_TEST_SCRIPT="${TMP}/${SCRIPT_NAME}"
readonly TMP_SEED_FILE="${TMP}/${SEED_NAME}"
readonly TMP_VARIANT_FILE="${TMP}/${VARIANT_NAME}"
"${BINARY_DIR}/../patch_oracle.py" "${TEST_SCRIPT}" \
  > "${TMP_TEST_SCRIPT}"
chmod +x "${TMP_TEST_SCRIPT}"
cp "${SEED_FILE}" "${TMP_SEED_FILE}"
cp "${VARIANT_FILE}" "${TMP_VARIANT_FILE}"
readonly REDUCTION_STAT_FILE=$(mktemp)
export REDUCTION_STAT_FILE

#check REDUCTION_STAT_FILE is empty
[[ "0" == "$(wc -l < "${REDUCTION_STAT_FILE}" | sed -e 's/^[ \t]*//')" ]] || exit 1

summarize_results() {
  local -r reduced_seed_file=$1
  local -r reduced_variant_file=$2
  local -r reduced_token_count_seed=$("${BINARY_DIR}/run_token_counter.sh" "${reduced_seed_file}")
  local -r reduced_token_count_variant=$("${BINARY_DIR}/run_token_counter.sh" "${reduced_variant_file}")

  if [ -z "${COMPLETE_STAT_FILE}" ]; then
    echo "${REDUCTION_STAT_FILE} ${TEST_SCRIPT} ${SEED_FILE} ${VARIANT_FILE}" \
      "'$(wc -l < "${REDUCTION_STAT_FILE}" | sed -e 's/^[ \t]*//') query'" \
      "'$((END_TIME - START_TIME)) s' '${RET_CODE} code'" \
      "'seed: ${reduced_token_count_seed} tokens, variant: ${reduced_token_count_variant} tokens'"
  else
    echo "${REDUCTION_STAT_FILE}" >> "${COMPLETE_STAT_FILE}"
    echo "${TEST_SCRIPT}" >> "${COMPLETE_STAT_FILE}"
    echo "${SEED_FILE}" >> "${COMPLETE_STAT_FILE}"
    echo "$(wc -l < "${REDUCTION_STAT_FILE}" | sed -e 's/^[ \t]*//')" \
      >> "${COMPLETE_STAT_FILE}"
    echo "$((END_TIME - START_TIME))" >> "${COMPLETE_STAT_FILE}"
    echo "${reduced_token_count_seed}" >> "${COMPLETE_STAT_FILE}"
    echo "${reduced_token_count_variant}" >> "${COMPLETE_STAT_FILE}"
    echo "${RET_CODE}" >> "${COMPLETE_STAT_FILE}"
  fi

  # mkdir -p $OUTPUT_DIR
  # cp ${reduced_seed_file} $OUTPUT_DIR
  # cp ${reduced_variant_file} $OUTPUT_DIR
  # cp ${TMP_TEST_SCRIPT} $OUTPUT_DIR

  rm -f "${REDUCTION_STAT_FILE}"
  rm -rf "${TMP}"
}

pushd "${TMP}"
readonly START_TIME=$(date +%s)
java ${JVM_FLAGS:=''} -jar "/tmp/binaries/ppr_deploy.jar" ${PERSES_FLAGS:=''} \
  --test-script "${TMP_TEST_SCRIPT}" \
  --input-file "${TMP_SEED_FILE}" \
  --variant-file "${TMP_VARIANT_FILE}" \
  --min-tdiff true \
  --min-ldiff true \
  --min-commonality true \
  --enable-mirror true \
  --output-dir "${OUTPUT_DIR}" \
  --threads "${THREADS}"

readonly RET_CODE="$?"
readonly END_TIME=$(date +%s)

readonly FINAL_SEED_FILE="${OUTPUT_DIR}/${SEED_NAME}"
readonly FINAL_VARIANT_FILE="${OUTPUT_DIR}/${VARIANT_NAME}"

summarize_results "${FINAL_SEED_FILE}" "${FINAL_VARIANT_FILE}"
popd

exit "${RET_CODE}"
