#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if ! rustfmt --edition 2018 mutant.rs; then
  exit 1
fi
if timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=3 -Z mir-opt-level=3 -Z new-llvm-pass-manager=yes -Z unsound-mir-opts=yes -Z polonius=yes -Z polymorphize=yes mutant.rs &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'index out of bounds: the len is 2 but the index is 2'" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: unexpected panic" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}"; then
  exit 1
fi
exit 0
