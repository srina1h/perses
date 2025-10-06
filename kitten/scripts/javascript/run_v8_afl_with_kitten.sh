#!/usr/bin/env bash
set -euo pipefail

# This script wires kitten to generate and mutate JS seeds while executing them
# with an AFL-instrumented d8 binary. Coverage is collected via AFLCoverageCollector.

ROOT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd -P)
WORKDIR="${WORKDIR:-/workspace}"
OUT_DIR="${WORKDIR}/v8/out/afl"
D8_BIN="${D8_BIN:-${OUT_DIR}/d8}"
ALLOWLIST_FILE="${ALLOWLIST_FILE:-}"
AUTO_GEN_ALLOWLIST="${AUTO_GEN_ALLOWLIST:-true}"
THREADS="${THREADS:-$(nproc 2>/dev/null || sysctl -n hw.ncpu)}"
JVM_HEAP="${JVM_HEAP:-8}"

if [ ! -x "${D8_BIN}" ]; then
  echo "d8 not found at ${D8_BIN}. Build it first via build_v8_afl.sh" >&2
  exit 1
fi

if [ -n "${ALLOWLIST_FILE}" ] && [ ! -f "${ALLOWLIST_FILE}" ]; then
  if [ "${AUTO_GEN_ALLOWLIST}" = "true" ]; then
    echo "[runner] ALLOWLIST_FILE missing, attempting to generate from V8 repo" >&2
    GEN_REPO="${WORKDIR}/v8" GEN_SINCE_MONTHS=6 \
      /root/bin/gen_allowlist_from_git.sh > "${ALLOWLIST_FILE}" || true
  fi
fi

# Generate a kitten testing configuration for V8-only crash detection
KIT_CFG_DIR="${WORKDIR}/kitten_runtime"
KIT_CFG_FILE="${KIT_CFG_DIR}/v8-only.yaml"
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

# Prepare seed corpus if empty
if ! find "${SEEDS_DIR}" -type f -name '*.js' | head -1 >/dev/null 2>&1; then
  echo 'print("hello");' >"${SEEDS_DIR}/seed.js"
fi

# Export allowlist for AFL (if provided)
if [ -n "${ALLOWLIST_FILE}" ]; then
  export AFL_LLVM_ALLOWLIST="${ALLOWLIST_FILE}"
fi

# Run kitten with AFL coverage mode
exec java -Xmx${JVM_HEAP}G -Xms1G -XX:+UseG1GC -jar "${WORKDIR}/bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar" \
  --testing-config "${KIT_CFG_FILE}" \
  --threads "${THREADS}" \
  --verbosity "FINE" \
  --timeout 0 \
  --instrumentation-strict-mode false \
  --skip-seed-validation false \
  --finding-folder "${WORKDIR}/kitten/findings_v8" \
  --language-model N_DEPTH_TREE_MODEL \
  --generator GUIDED_GENERATOR \
  --enable-replace-with-generated-node \
  --coverage-interval 15 \
  --afl-coverage-mode true \
  --afl-guidance-strict true


