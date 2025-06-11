#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in decompose, at wide-int.h" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "check_nul_terminated_array(tree_node*, tree_node*, tree_node*)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "check_access(tree_node*, tree_node*, tree_node*, tree_node*, tree_node*, access_mode, access_data const*)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "check_read_access" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin_memcmp" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin(tree_node*, rtx_def*, rtx_def*, machine_mode, int)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_expr_real_1(tree_node*, rtx_def*, machine_mode, expand_modifier, rtx_def**, bool)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "store_expr(tree_node*, rtx_def*, int, bool, bool)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_assignment(tree_node*, tree_node*, bool)" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_call_stmt" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_gimple_stmt_1" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_gimple_stmt" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_gimple_basic_block" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}"; then
  exit 1
fi
exit 0
