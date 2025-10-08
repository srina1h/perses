#!/usr/bin/env bash
set -euo pipefail

# Run kitten with V8 for crash detection

WORKDIR="${WORKDIR:-/workspace}"
V8_DIR="${WORKDIR}/v8"
D8_BIN="${D8_BIN:-${V8_DIR}/out/instrumented/d8}"
THREADS="${THREADS:-$(nproc 2>/dev/null || sysctl -n hw.ncpu)}"
JVM_HEAP="${JVM_HEAP:-8}"

# Disable core dumps to save disk space
ulimit -c 0
echo "[runner] Core dumps disabled (ulimit -c 0)"

if [ ! -x "${D8_BIN}" ]; then
  echo "[runner] ERROR: d8 not found at ${D8_BIN}" >&2
  exit 1
fi

echo "[runner] Using d8: ${D8_BIN}"
echo "[runner] Threads: ${THREADS}, Heap: ${JVM_HEAP}G"

# Create runtime config
KIT_CFG_DIR="${WORKDIR}/kitten_runtime"
KIT_CFG_FILE="${KIT_CFG_DIR}/v8-instrumented.yaml"
SEEDS_DIR="${KIT_CFG_DIR}/seeds"
mkdir -p "${KIT_CFG_DIR}" "${SEEDS_DIR}"

cat >"${KIT_CFG_FILE}" <<EOF
language: "JAVASCRIPT"
seedFolders:
  - path: "${SEEDS_DIR}"
    fileExtentions: [".js"]
programsUnderTest:
  - command: "${D8_BIN}"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--version"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.V8CrashDetector"
EOF

# Copy prepared seeds
echo "[runner] Checking for seeds in /workspace/seeds..."
if [ -d "/workspace/seeds" ]; then
  seed_count=$(find "/workspace/seeds" -type f -name '*.js' 2>/dev/null | wc -l)
  echo "[runner] Found ${seed_count} .js files in /workspace/seeds"
  
  if [ "$seed_count" -gt 0 ]; then
    echo "[runner] Copying prepared seeds to ${SEEDS_DIR}..."
    cp -r /workspace/seeds/* "${SEEDS_DIR}/" || true
    copied_count=$(find "${SEEDS_DIR}" -type f -name '*.js' 2>/dev/null | wc -l)
    echo "[runner] Copied ${copied_count} seed files"
  else
    echo "[runner] No .js files found in /workspace/seeds, creating minimal seed..."
    echo 'print("hello");' >"${SEEDS_DIR}/seed.js"
  fi
else
  echo "[runner] /workspace/seeds directory not found, creating minimal seed..."
  echo 'print("hello");' >"${SEEDS_DIR}/seed.js"
fi

final_seed_count=$(find "${SEEDS_DIR}" -type f -name '*.js' 2>/dev/null | wc -l)
echo "[runner] Final seed count in ${SEEDS_DIR}: ${final_seed_count}"

# Create startup report in findings folder
FINDINGS_DIR="${WORKDIR}/kitten/findings_v8"
mkdir -p "${FINDINGS_DIR}"
REPORT_FILE="${FINDINGS_DIR}/fuzzing_startup_report.txt"

cat >"${REPORT_FILE}" <<REPORT_EOF
================================================================================
V8 Fuzzing Session Report
================================================================================
Started: $(date)
Hostname: $(hostname)
================================================================================

CONFIGURATION:
- D8 Binary: ${D8_BIN}
- D8 Version: $(${D8_BIN} --version 2>&1 | head -1 || echo "unknown")
- Fuzzing Threads: ${THREADS}
- JVM Heap: ${JVM_HEAP}G
- Core Dumps: Disabled (ulimit -c 0)

SEEDS:
- Initial Seeds Found: ${final_seed_count}
- Seeds Location: ${SEEDS_DIR}

CRASH DETECTION:
- Detector: V8CrashDetector
- Detects: FATAL errors, Check failed, UNREACHABLE, Assertions, Signals, Sanitizer crashes
- Filters: Timeouts (124, 143, 137), Normal errors (exit 1 without crash signature)

RESULTS:
- Findings Folder: ${FINDINGS_DIR}
- Report File: ${REPORT_FILE}

================================================================================
Fuzzing started at: $(date)
================================================================================
REPORT_EOF

echo "[runner] Startup report saved to ${REPORT_FILE}"
cat "${REPORT_FILE}"

# Run kitten (using only standard flags)
exec java -Xmx${JVM_HEAP}G -Xms1G -XX:+UseG1GC \
  -jar "${WORKDIR}/bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar" \
  --testing-config "${KIT_CFG_FILE}" \
  --threads "${THREADS}" \
  --verbosity "FINE" \
  --timeout 0 \
  --finding-folder "${WORKDIR}/kitten/findings_v8" \
  --language-model N_DEPTH_TREE_MODEL \
  --generator GUIDED_GENERATOR \
  --enable-replace-with-generated-node

