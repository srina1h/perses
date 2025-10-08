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

# Test instrumentation with a simple program
echo "[runner] Testing instrumentation..."
test_output=$(echo 'print("test");' | "${D8_BIN}" - 2>&1 || true)
if echo "$test_output" | grep -q "ALLOWLIST_HIT"; then
  echo "[runner] ✓ Instrumentation detected! Allowlist tracking is active."
else
  echo "[runner] ⚠ Warning: ALLOWLIST_HIT marker not detected in test run"
  echo "[runner]   This may mean no allowlisted files were loaded, or instrumentation failed"
fi

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

# Validate seeds against allowlist
echo "[runner] Validating seeds against allowlist..."
VALIDATION_START=$(date +%s)
seeds_touching_allowlist=0
seeds_tested=0

if [ "${final_seed_count}" -gt 0 ]; then
  for seed_file in "${SEEDS_DIR}"/*.js; do
    [ -f "$seed_file" ] || continue
    seeds_tested=$((seeds_tested + 1))
    
    # Run d8 with the seed and capture stderr
    stderr_output=$("${D8_BIN}" "$seed_file" 2>&1 || true)
    
    # Check if ALLOWLIST_HIT marker is present
    if echo "$stderr_output" | grep -q "ALLOWLIST_HIT"; then
      seeds_touching_allowlist=$((seeds_touching_allowlist + 1))
    fi
    
    # Progress indicator every 10 seeds
    if [ $((seeds_tested % 10)) -eq 0 ]; then
      echo "[runner] Validated ${seeds_tested}/${final_seed_count} seeds..." >&2
    fi
  done
fi

VALIDATION_END=$(date +%s)
VALIDATION_TIME=$((VALIDATION_END - VALIDATION_START))

echo "[runner] Validation complete: ${seeds_touching_allowlist}/${seeds_tested} seeds touch allowlist"

# Create startup report in findings folder
FINDINGS_DIR="${WORKDIR}/kitten/findings_v8"
mkdir -p "${FINDINGS_DIR}"
REPORT_FILE="${FINDINGS_DIR}/fuzzing_startup_report.txt"

# Get allowlist stats if available
ALLOWLIST_FILE="${WORKDIR}/allowlist.txt"
ALLOWLIST_COUNT=0
TOTAL_V8_FILES=0
if [ -f "${ALLOWLIST_FILE}" ]; then
  ALLOWLIST_COUNT=$(wc -l < "${ALLOWLIST_FILE}" | tr -d ' ')
fi
if [ -d "${V8_DIR}" ]; then
  TOTAL_V8_FILES=$(git -C "${V8_DIR}" ls-files "src/*" 2>/dev/null | wc -l | tr -d ' ' || echo "0")
fi

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

RECENTLY MODIFIED FILES (ALLOWLIST):
- Files in allowlist: ${ALLOWLIST_COUNT}
- Total V8 source files: ${TOTAL_V8_FILES}
- Coverage: $(awk "BEGIN {if (${TOTAL_V8_FILES}>0) printf \"%.1f\", (${ALLOWLIST_COUNT}/${TOTAL_V8_FILES}*100); else print \"N/A\"}")%
- Criteria: Last 6 months, commits with 'fix' or 'bug' in message
- Instrumentation: V8 patched to track execution of allowlisted files
- Detection: Looks for 'ALLOWLIST_HIT' marker in stderr

SEED VALIDATION:
- Initial Seeds: ${final_seed_count}
- Seeds Location: ${SEEDS_DIR}
- Validation Time: ${VALIDATION_TIME} seconds
- Seeds Tested: ${seeds_tested}
- Seeds Touching Allowlist: ${seeds_touching_allowlist}
- Proportion: $(awk "BEGIN {if (${seeds_tested}>0) printf \"%.1f\", (${seeds_touching_allowlist}/${seeds_tested}*100); else print \"0.0\"}")%
- Method: Executed each seed with instrumented d8, checked for ALLOWLIST_HIT marker

CRASH DETECTION:
- Detector: V8CrashDetector
- Detects: FATAL errors, Check failed, UNREACHABLE, Assertions, Signals, Sanitizer crashes
- Filters: Timeouts (124, 143, 137), Normal errors (exit 1 without crash signature)
- Requires: Non-empty stderr AND crash signature

FUZZING MODE:
- Mode: Instrumented crash detection  
- V8 Build: Custom build with allowlist execution tracking
- Strategy: Mutate all seeds, detect crashes anywhere in V8
- Tracking: Instrumented V8 will print 'ALLOWLIST_HIT' if allowlisted code runs
- Goal: Find crashes and track which ones touch recently modified code

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

