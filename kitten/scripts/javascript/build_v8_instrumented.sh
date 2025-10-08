#!/usr/bin/env bash
set -euo pipefail

# Build V8 with manual allowlist instrumentation
# Much faster and simpler than AFL or eBPF

WORKDIR="${WORKDIR:-/workspace}"
DEPOT_TOOLS_DIR="${WORKDIR}/depot_tools"
V8_DIR="${WORKDIR}/v8"
OUT_DIR="${V8_DIR}/out/instrumented"
ALLOWLIST_FILE="${WORKDIR}/allowlist.txt"
: "${THREADS:=8}"

echo "[build_v8_instrumented] Building V8 with allowlist tracking"
echo "WORKDIR=${WORKDIR}, THREADS=${THREADS}"

mkdir -p "${WORKDIR}"
cd "${WORKDIR}"

# Clone depot_tools if needed
if [ ! -d "${DEPOT_TOOLS_DIR}" ]; then
  echo "[build_v8_instrumented] Cloning depot_tools..."
  git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git "${DEPOT_TOOLS_DIR}"
fi
export PATH="${DEPOT_TOOLS_DIR}:${PATH}"

# Fetch V8 if needed
if [ ! -d "${V8_DIR}" ]; then
  echo "[build_v8_instrumented] Fetching V8..."
  fetch v8
fi

cd "${V8_DIR}"
echo "[build_v8_instrumented] Running gclient sync..."
gclient sync

# Clean any previous build artifacts to ensure fresh build with new patches
if [ -d "${OUT_DIR}" ]; then
  echo "[build_v8_instrumented] Cleaning previous build..."
  rm -rf "${OUT_DIR}"
fi

# Generate allowlist if not exists
if [ ! -f "${ALLOWLIST_FILE}" ]; then
  echo "[build_v8_instrumented] Generating allowlist..."
  chmod +x "${WORKDIR}/kitten/scripts/javascript/gen_allowlist_from_git.sh"
  GEN_REPO="${V8_DIR}" GEN_SINCE_MONTHS=6 \
    "${WORKDIR}/kitten/scripts/javascript/gen_allowlist_from_git.sh" > "${ALLOWLIST_FILE}"
fi

# Patch V8 source files with static initializers (safe approach)
echo "[build_v8_instrumented] Patching V8 source files with allowlist tracking..."
python3 "${WORKDIR}/kitten/scripts/javascript/patch_v8_allowlist.py" \
  "${V8_DIR}" "${ALLOWLIST_FILE}" 2>&1 | tee "${WORKDIR}/patch_v8.log"

echo "[build_v8_instrumented] Patch summary:"
grep -E "\[PATCHED\]|\[SUCCESS\]|\[ERROR\]" "${WORKDIR}/patch_v8.log" | tail -20

# Create build configuration
echo "[build_v8_instrumented] Creating build configuration..."
mkdir -p "${OUT_DIR}"

cat >"${OUT_DIR}/args.gn" <<EOF
is_debug = false
target_cpu = "x64"
symbol_level = 1
is_component_build = false
v8_static_library = true
use_custom_libcxx = false
use_sysroot = false
is_clang = true
treat_warnings_as_errors = false
v8_enable_backtrace = false
v8_enable_disassembler = true
v8_enable_object_print = true
EOF

echo "[build_v8_instrumented] Generating build files..."
gn gen "${OUT_DIR}"

echo "[build_v8_instrumented] Building d8 (${THREADS} threads)..."
"${DEPOT_TOOLS_DIR}/ninja" -C "${OUT_DIR}" -j "${THREADS}" d8

if [ -x "${OUT_DIR}/d8" ]; then
  echo "[build_v8_instrumented] SUCCESS: ${OUT_DIR}/d8"
else
  echo "[build_v8_instrumented] ERROR: d8 not found" >&2
  exit 1
fi

