#!/usr/bin/env bash
set -euo pipefail

# Wrapper to run d8 while bpftrace watches for any uprobe hit on allowlisted functions.
# Prints "EBPF_HIT" to stderr if any allowlisted function was executed.
#
# Env:
#   D8_BIN: path to d8 binary
#   UPROBE_FUNCS_FILE: newline-separated function names to probe
#
# Usage: D8_BIN=/path/to/d8 UPROBE_FUNCS_FILE=/workspace/uprobe_functions.txt d8_with_bpf.sh <d8-args>

: "${D8_BIN:?Set D8_BIN}"
: "${UPROBE_FUNCS_FILE:?Set UPROBE_FUNCS_FILE}"

if ! command -v bpftrace >/dev/null 2>&1; then
  echo "bpftrace not found" >&2
  exec "${D8_BIN}" "$@"
fi

if [ ! -s "${UPROBE_FUNCS_FILE}" ]; then
  # No functions to watch; run normally
  exec "${D8_BIN}" "$@"
fi

tmp_bt=$(mktemp)
hit_file=$(mktemp)
trap 'rm -f "${tmp_bt}" "${hit_file}"' EXIT

{
  echo 'BEGIN { @fired = 0; }'
  while IFS= read -r fn; do
    [ -z "$fn" ] && continue
    # uprobe lines per function
    echo "uprobe:${D8_BIN}:${fn} { if (@fired == 0) { @fired = 1; printf(\"EBPF_HIT\\n\"); } }"
  done < "${UPROBE_FUNCS_FILE}"
} >"${tmp_bt}"

"${D8_BIN}" "$@" &
target_pid=$!

# Start bpftrace attached to pid with our probes; stop when d8 exits
(
  bpftrace -p "${target_pid}" "${tmp_bt}" | head -n 1 >"${hit_file}" || true
) &
bt_pid=$!

wait "${target_pid}" || true
kill "${bt_pid}" 2>/dev/null || true

if grep -q "EBPF_HIT" "${hit_file}" 2>/dev/null; then
  echo "EBPF_HIT" >&2
fi

exit 0


