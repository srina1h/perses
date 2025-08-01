#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

echo "=== Debug Differential Testing ==="

# Create a very simple test
mkdir -p debug_test_seeds
echo "console.log('test');" > debug_test_seeds/test.js

# Create debug config
cat > debug_config.yaml << EOF
language: "JAVASCRIPT"
seedFolders:
  - path: "debug_test_seeds"
    fileExtentions: [".js"]

programsUnderTest:
  - command: "/Users/srinath/.jsvu/bin/v8"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--help"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.V8CrashDetector"
  
  - command: "/Users/srinath/.jsvu/bin/hermes"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--version"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.HermesCrashDetector"
EOF

# Create output directory
mkdir -p debug_output

echo "Running debug test..."

# Run with explicit output
java -Xmx1G -Xms256M -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config debug_config.yaml \
  --threads 1 \
  --verbosity "FINE" \
  --finding-folder debug_output \
  --timeout 30 \
  --max-seed-pool-size 1

echo "Debug test completed."
echo "Current directory: $(pwd)"
echo "Debug output contents:"
ls -la debug_output/ 2>/dev/null || echo "No debug output directory found"

# Check for any differential findings
find . -name "differential_finding_*" 2>/dev/null | head -5 