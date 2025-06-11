#!/usr/bin/env bash
set -o nounset
set -o pipefail
set -o xtrace

readonly OUTPUT="temp_compilation_output.tmp.txt"
readonly CRASH_EXIT_CODE=1

timeout -s 9 30 slang-trunk mutant.sv &> "${OUTPUT}"

[[ "$?" == "${CRASH_EXIT_CODE}" ]] || exit 1

if ! grep --quiet --fixed-strings "AddressSanitizer:DEADLYSIGNAL" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ERROR: AddressSanitizer: stack-overflow on address" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "SUMMARY: AddressSanitizer: stack-overflow" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "slang-nightly/source/binding/Expression.cpp" "${OUTPUT}"; then
  exit 1
fi

exit 0
