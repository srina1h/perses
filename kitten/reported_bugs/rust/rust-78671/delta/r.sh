#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly VERSION="nightly-2020-10-25"
readonly OUTPUT="temp_compilation_output.tmp.txt"

rustup toolchain install "${VERSION}" --force

if ! rustup run "${VERSION}" rustc -Z parse-only mutant.rs; then
  exit 1
fi

if timeout -s 9 30 rustup run "${VERSION}" rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=1 -C target-cpu=skylake mutant.rs &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: compiler/rustc_middle/src/ty/subst.rs" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'Box<Any>'" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}"; then
  exit 1
fi
exit 0
