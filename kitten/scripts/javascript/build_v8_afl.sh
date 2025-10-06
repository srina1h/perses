#!/usr/bin/env bash
set -euo pipefail

# This script attempts to build V8's d8 with AFL++ instrumentation.
# It uses allowlist-based instrumentation if AFL_LLVM_ALLOWLIST is provided.
# Requirements inside container/host: git, python3, curl, gn, ninja, and afl++ installed.

ROOT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd -P)
WORKDIR="${WORKDIR:-/workspace}"
DEPOT_TOOLS_DIR="${WORKDIR}/depot_tools"
V8_DIR="${WORKDIR}/v8"
OUT_DIR="${V8_DIR}/out/afl"

: "${THREADS:=8}"

echo "[build_v8_afl] WORKDIR=${WORKDIR} THREADS=${THREADS}"

mkdir -p "${WORKDIR}"
cd "${WORKDIR}"

if ! command -v afl-clang-fast >/dev/null 2>&1; then
  echo "AFL++ not found (afl-clang-fast). Please install afl++ before running." >&2
  exit 1
fi

if [ ! -d "${DEPOT_TOOLS_DIR}" ]; then
  git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git "${DEPOT_TOOLS_DIR}"
fi

export PATH="${DEPOT_TOOLS_DIR}:${PATH}"

if [ ! -d "${V8_DIR}" ]; then
  fetch v8
fi

cd "${V8_DIR}"
echo "[build_v8_afl] Running gclient sync..."
gclient sync

echo "[build_v8_afl] Creating AFL build configuration..."
mkdir -p "${OUT_DIR}"

# Get AFL compiler paths
AFL_CLANG=$(which afl-clang-fast)
AFL_CLANGXX=$(which afl-clang-fast++)

# Export AFL environment before build
export AFL_USE_ASAN=0
export AFL_DONT_OPTIMIZE=1
if [ -n "${AFL_LLVM_ALLOWLIST:-}" ] && [ -f "${AFL_LLVM_ALLOWLIST}" ]; then
  echo "[build_v8_afl] Using AFL_LLVM_ALLOWLIST=${AFL_LLVM_ALLOWLIST}"
  export AFL_LLVM_ALLOWLIST="${AFL_LLVM_ALLOWLIST}"
fi

# Write GN args - force V8 to use AFL compilers
cat >"${OUT_DIR}/args.gn" <<EOF
is_debug = false
target_cpu = "x64"
is_clang = true
use_sysroot = false
symbol_level = 1
v8_static_library = true

# Force use of AFL compilers
clang_base_path = "$(dirname $(dirname ${AFL_CLANG}))"
clang_use_chrome_plugins = false
use_custom_libcxx = false
EOF

echo "[build_v8_afl] Generating build files with gn..."
gn gen "${OUT_DIR}"

echo "[build_v8_afl] Building d8 with AFL instrumentation (${THREADS} threads)..."
# Override CC/CXX for ninja
CC="${AFL_CLANG}" CXX="${AFL_CLANGXX}" \
  "${DEPOT_TOOLS_DIR}/ninja" -C "${OUT_DIR}" -j "${THREADS}" d8

if [ -x "${OUT_DIR}/d8" ]; then
  echo "[build_v8_afl] Build completed: ${OUT_DIR}/d8"
else
  echo "[build_v8_afl] ERROR: d8 binary not found after build" >&2
  exit 2
fi


