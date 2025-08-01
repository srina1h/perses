#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=1 -C target-cpu=skylake mutant.rs &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: compiler/rustc_mir/src/borrow_check/universal_regions.rs:768:36: cannot convert \`ReEarlyBound(0, 'a)\` to a region vid" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'Box<Any>', compiler/rustc_errors/src/lib.rs:945:9" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}"; then
  exit 1
fi
exit 0
