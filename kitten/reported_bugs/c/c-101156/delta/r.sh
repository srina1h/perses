#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: ‘verify_gimple’ failed" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "verify_gimple_in_seq(gimple*)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_body(tree_node*, bool)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_function_tree(tree_node*)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "cgraph_node::analyze()" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "analyze_functions" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::finalize_compilation_unit()" "${OUTPUT}"; then
  exit 1
fi
exit 0
