#!/usr/bin/env bash
set -euo pipefail

# Build uprobe function list from allowlist and run kitten using an eBPF-wrapped d8.

WORKDIR="${WORKDIR:-/workspace}"
V8_OUT="${WORKDIR}/v8/out/afl"
D8_BIN="${D8_BIN:-${V8_OUT}/d8}"
ALLOWLIST_FILE="${ALLOWLIST_FILE:-/workspace/allowlist.txt}"
UPROBE_FUNCS_FILE="${UPROBE_FUNCS_FILE:-/workspace/uprobe_functions.txt}"
THREADS="${THREADS:-$(nproc 2>/dev/null || sysctl -n hw.ncpu)}"
JVM_HEAP="${JVM_HEAP:-8}"

if [ ! -x "${D8_BIN}" ]; then
  echo "d8 not found at ${D8_BIN}" >&2
  exit 1
fi

if [ ! -s "${UPROBE_FUNCS_FILE}" ]; then
  if [ -f "${ALLOWLIST_FILE}" ]; then
    D8_BIN="${D8_BIN}" ALLOWLIST="${ALLOWLIST_FILE}" \
      /root/bin/gen_uprobe_functions.sh > "${UPROBE_FUNCS_FILE}" || true
  fi
fi

KIT_CFG_DIR="${WORKDIR}/kitten_runtime"
KIT_CFG_FILE="${KIT_CFG_DIR}/v8-only-ebpf.yaml"
SEEDS_DIR="${KIT_CFG_DIR}/seeds"
mkdir -p "${KIT_CFG_DIR}" "${SEEDS_DIR}"

cat >"${KIT_CFG_FILE}" <<EOF
language: "JAVASCRIPT"
seedFolders:
  - path: "${SEEDS_DIR}"
    fileExtentions: [".js"]
programsUnderTest:
  - command: "/root/bin/d8_with_bpf.sh"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--version"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.V8CrashDetector"
EOF

# Copy prepared seeds from workspace if available, otherwise create a minimal seed
if [ -d "/workspace/seeds" ] && find "/workspace/seeds" -type f -name '*.js' | head -1 >/dev/null 2>&1; then
  echo "[runner] Copying prepared seeds from /workspace/seeds"
  cp -r /workspace/seeds/* "${SEEDS_DIR}/" || true
elif ! find "${SEEDS_DIR}" -type f -name '*.js' | head -1 >/dev/null 2>&1; then
  echo "[runner] No seeds found, creating minimal seed"
  echo 'print("hello");' >"${SEEDS_DIR}/seed.js"
fi

export D8_BIN
export UPROBE_FUNCS_FILE

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
  --touch-guidance-strict true \
  --filter-seeds-by-touch true


