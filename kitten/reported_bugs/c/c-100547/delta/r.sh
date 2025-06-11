#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: Segmentation fault" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "crash_signal" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_debug_expr" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_debug_locations" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}"; then
  exit 1
fi
exit 0
