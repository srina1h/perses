#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "llvm::Optional<llvm::APSInt> clang::Expr::getIntegerConstantExpr(const clang::ASTContext&, clang::SourceLocation*, bool) const: Assertion \`!isValueDependent() && \"Expression evaluator can't be called on a dependent expression.\"' failed." "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE submit a bug report to" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}"; then
  exit 1
fi
exit 0
