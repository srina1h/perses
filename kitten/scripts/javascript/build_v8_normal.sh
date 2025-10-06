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
  echo "[build_v8_normal] Cloning depot_tools..."
  git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git "${DEPOT_TOOLS_DIR}"
fi
export PATH="${DEPOT_TOOLS_DIR}:${PATH}"

if [ ! -d "${V8_DIR}" ]; then
  echo "[build_v8_normal] Fetching V8..."
  fetch v8
fi
cd "${V8_DIR}"
echo "[build_v8_normal] Running gclient sync..."
gclient sync

echo "[build_v8_normal] Creating build directory and configuration..."
mkdir -p "${OUT_DIR}"

# Write args.gn directly - skip v8gen.py
cat >"${OUT_DIR}/args.gn" <<EOF
is_debug = false
target_cpu = "x64"
v8_enable_backtrace = true
v8_enable_disassembler = true
v8_enable_object_print = true
v8_enable_verify_heap = true
symbol_level = 1
is_component_build = false
v8_static_library = true
EOF

echo "[build_v8_normal] Generating build files with gn..."
gn gen "${OUT_DIR}"
echo "[build_v8_normal] Building d8 with ninja (${THREADS} threads)..."
"${DEPOT_TOOLS_DIR}/ninja" -C "${OUT_DIR}" -j "${THREADS}" d8

if [ -x "${OUT_DIR}/d8" ]; then
  echo "[build_v8_normal] Built ${OUT_DIR}/d8"
else
  echo "[build_v8_normal] ERROR: d8 missing" >&2
  exit 2
fi


