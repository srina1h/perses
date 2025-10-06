#!/usr/bin/env bash
set -euo pipefail

# Generate a unique list of function names in a binary that map to allowlisted source files.
# Requires: nm, addr2line
# Usage: D8_BIN=/path/to/d8 ALLOWLIST=/workspace/allowlist.txt ./gen_uprobe_functions.sh > /workspace/uprobe_functions.txt

: "${D8_BIN:?Set D8_BIN to the binary to analyze (e.g., /workspace/v8/out/Default/d8)}"
: "${ALLOWLIST:?Set ALLOWLIST to the file with src/ paths to include}"

if ! command -v nm >/dev/null || ! command -v addr2line >/dev/null; then
  echo "nm/addr2line required" >&2
  exit 1
fi

# Read allowlist into a grep-able regex (prefix match per line)
mapfile -t al < "${ALLOWLIST}"
if [ ${#al[@]} -eq 0 ]; then
  exit 0
fi
tmp_re="$(printf '|%s' "${al[@]}")"
tmp_re="${tmp_re:1}"

# Collect symbols with addresses and demangled names
# Then map each address to source file via addr2line, filter by allowlist prefix, and print function names
nm -an --demangle "${D8_BIN}" 2>/dev/null | awk '/ T /{print $1" "substr($0,index($0,$4))}' | \
  while read -r addr func; do
    src=$(addr2line -e "${D8_BIN}" -f -C -p "0x${addr}" 2>/dev/null | tail -n1 | awk -F' at ' '{print $2}')
    if [ -n "${src}" ] && echo "${src}" | grep -E "${tmp_re}" >/dev/null 2>&1; then
      echo "${func}"
    fi
  done | sort -u


