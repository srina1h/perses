#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 jerry-trunk-asan_ubsan mutant.js &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "/jerryscript/jerry-core/vm/vm.c:3731:77: runtime error: left shift of negative value -1" "${OUTPUT}"; then
  exit 1
fi
exit 0
