#!/usr/bin/env bash
timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=2 -Z mir-opt-level=2 -Z new-llvm-pass-manager=no -Z unsound-mir-opts=no -Z polonius=no -Z polymorphize=no mutant.rs
