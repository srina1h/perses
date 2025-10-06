#!/usr/bin/env bash
set -euo pipefail

# Build V8 d8 with standard toolchain (no AFL), for eBPF uprobes.
# Requirements: depot_tools, clang, ninja

WORKDIR="${WORKDIR:-/workspace}"
DEPOT_TOOLS_DIR="${WORKDIR}/depot_tools"
V8_DIR="${WORKDIR}/v8"
OUT_DIR="${V8_DIR}/out/rel"
: "${THREADS:=8}"

mkdir -p "${WORKDIR}"
cd "${WORKDIR}"

if [ ! -d "${DEPOT_TOOLS_DIR}" ]; then
  git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git "${DEPOT_TOOLS_DIR}"
fi
export PATH="${DEPOT_TOOLS_DIR}:${PATH}"

if [ ! -d "${V8_DIR}" ]; then
  fetch v8
fi
cd "${V8_DIR}"
gclient sync

python3 tools/dev/v8gen.py rel --no-goma

GN_ARGS=(
  "is_official_build=false"
  "is_debug=false"
  "symbol_level=1"
  "use_custom_libcxx=false"
  "v8_monolithic=true"
  "v8_static_library=true"
  "is_clang=true"
  "use_sysroot=false"
)
mkdir -p "${OUT_DIR}"
{
  for a in "${GN_ARGS[@]}"; do echo "$a"; done
} >"${OUT_DIR}/args.gn"

gn gen "${OUT_DIR}"
"${DEPOT_TOOLS_DIR}/ninja" -C "${OUT_DIR}" -j "${THREADS}" d8

if [ -x "${OUT_DIR}/d8" ]; then
  echo "[build_v8_normal] Built ${OUT_DIR}/d8"
else
  echo "[build_v8_normal] ERROR: d8 missing" >&2
  exit 2
fi


