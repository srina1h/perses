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
gclient sync

# Note: Building V8 with external compilers requires a custom toolchain.
# We configure GN to use system clang and override CC/CXX to AFL wrappers via env for ninja.
# This setup may break across V8 versions; treat as best-effort prototype.

python3 tools/dev/v8gen.py afl --no-goma

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

echo "[build_v8_afl] Writing GN args to ${OUT_DIR}/args.gn"
mkdir -p "${OUT_DIR}"
{
  for a in "${GN_ARGS[@]}"; do echo "$a"; done
} >"${OUT_DIR}/args.gn"

# Export AFL allowlist if provided: one path per line, absolute or repo-relative
if [ -n "${AFL_LLVM_ALLOWLIST:-}" ]; then
  echo "[build_v8_afl] Using AFL_LLVM_ALLOWLIST=${AFL_LLVM_ALLOWLIST}"
fi

export CC=afl-clang-fast
export CXX=afl-clang-fast++
export AFL_USE_ASAN=0
export AFL_DONT_OPTIMIZE=1
export AFL_LLVM_ALLOWLIST="${AFL_LLVM_ALLOWLIST:-}"

echo "[build_v8_afl] Generating build files (gn gen)"
gn gen "${OUT_DIR}"

echo "[build_v8_afl] Building d8 with ninja"
"${DEPOT_TOOLS_DIR}/ninja" -C "${OUT_DIR}" -j "${THREADS}" d8

if [ -x "${OUT_DIR}/d8" ]; then
  echo "[build_v8_afl] Build completed: ${OUT_DIR}/d8"
else
  echo "[build_v8_afl] ERROR: d8 binary not found after build" >&2
  exit 2
fi


