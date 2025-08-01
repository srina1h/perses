#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

echo "=== Simple Differential Testing Test ==="

# Create a simple test directory
mkdir -p kitten/scripts/javascript/simple_test_seeds
echo "console.log('Hello World');" > kitten/scripts/javascript/simple_test_seeds/simple.js

# Create a simple config
cat > kitten/scripts/javascript/simple_test_config.yaml << EOF
language: "JAVASCRIPT"
seedFolders:
  - path: "kitten/scripts/javascript/simple_test_seeds"
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
mkdir -p kitten/temp_simple_test

echo "Running simple test for 10 seconds..."

# Run a very short test
timeout 10s java -Xmx2G -Xms512M -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config kitten/scripts/javascript/simple_test_config.yaml \
  --threads 1 \
  --verbosity "INFO" \
  --finding-folder kitten/temp_simple_test \
  --timeout 10 \
  --max-seed-pool-size 1 || true

echo "Test completed. Checking results..."

# Check what was created
if [[ -d "kitten/temp_simple_test" ]]; then
    echo "✅ Output directory exists"
    ls -la kitten/temp_simple_test/
    
    if [[ -d "kitten/temp_simple_test/differential_finding_"* ]]; then
        echo "✅ Differential findings found!"
        ls -la kitten/temp_simple_test/differential_finding_*/
    else
        echo "❌ No differential findings found"
    fi
else
    echo "❌ Output directory does not exist"
fi 