#!/usr/bin/env bash
timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=2 -Z mir-opt-level=3 -Z new-llvm-pass-manager=yes -Z unsound-mir-opts=yes -Z polonius=no -Z polymorphize=no mutant.rs
