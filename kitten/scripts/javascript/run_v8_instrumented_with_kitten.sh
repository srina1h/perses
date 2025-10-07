#!/usr/bin/env bash
set -euo pipefail

# Run kitten with manually instrumented V8 for allowlist-based guidance

WORKDIR="${WORKDIR:-/workspace}"
V8_DIR="${WORKDIR}/v8"
D8_BIN="${D8_BIN:-${V8_DIR}/out/instrumented/d8}"
THREADS="${THREADS:-$(nproc 2>/dev/null || sysctl -n hw.ncpu)}"
JVM_HEAP="${JVM_HEAP:-8}"

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

