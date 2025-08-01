#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: Segmentation fault" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "crash_signal" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "is_gimple_variable" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "is_gimple_id" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "is_gimple_addressable" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "is_gimple_lvalue(tree_node*)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_expr(tree_node**, gimple**, gimple**, bool (*)(tree_node*), int)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_asm_expr" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_stmt(tree_node**, gimple**)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_statement_list" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_bind_expr" "${OUTPUT}"; then
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
