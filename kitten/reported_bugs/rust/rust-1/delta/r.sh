#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=3 -Z mir-opt-level=3 -Z new-llvm-pass-manager=yes -Z unsound-mir-opts=yes -Z polonius=yes -Z polymorphize=yes mutant.rs &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "434 | let msg_segv = \"clang: error: unable to execute command: Segmentation fault: 11\" ; super :: vxworks_base :: opts ( ) ;" "${OUTPUT}"; then
  exit 1
fi
exit 0
