#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly CLASS="Hello"
readonly FILE="${CLASS}.java"

timeout -s 9 4 javac "${FILE}" || exit 1
readonly OUTPUT="temp.txt"
timeout -s 9 4 java "${CLASS}" > "${OUTPUT}" 2>&1 || exit 1

grep "world" "${OUTPUT}" > /dev/null
