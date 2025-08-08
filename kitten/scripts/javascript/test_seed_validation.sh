#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

echo "=== Testing Seed Validation on All Engines ==="

# Create test seeds directory
mkdir -p kitten/scripts/javascript/seed_validation_test_seeds

# Create a good seed that should work on all engines
echo "console.log('Hello World');" > kitten/scripts/javascript/seed_validation_test_seeds/good.js

# Create a problematic seed that might fail on some engines
echo "console.log('Hello World'); throw new Error('Intentional error');" > kitten/scripts/javascript/seed_validation_test_seeds/problematic.js

# Create a syntax error seed that should fail parsing
echo "console.log('Hello World';" > kitten/scripts/javascript/seed_validation_test_seeds/syntax_error.js

# Create a config that uses the local engine paths
cat > kitten/scripts/javascript/seed_validation_config.yaml << EOF
language: "JAVASCRIPT"
seedFolders:
  - path: "kitten/scripts/javascript/seed_validation_test_seeds"
    fileExtentions: [".js"]

programsUnderTest:
  - command: "/usr/local/bin/js-engines/v8"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--help"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.V8CrashDetector"
  
  - command: "/usr/local/bin/js-engines/hermes"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--version"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.HermesCrashDetector"
  
  - command: "/usr/local/bin/js-engines/graaljs"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--version"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.GraalJSCrashDetector"
EOF

# Create output directory
mkdir -p kitten/temp_seed_validation_test

echo "Running seed validation test..."

echo "Test 1: Without seed validation (should include all seeds)"
java -Xmx2G -Xms512M -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config kitten/scripts/javascript/seed_validation_config.yaml \
  --threads 1 \
  --verbosity "INFO" \
  --finding-folder kitten/temp_seed_validation_test/without_validation \
  --timeout 30 \
  --max-seed-pool-size 10 \
  --fuzzer-mode ONLY_ON_INITIAL_SEED || true

echo "Test 2: With seed validation (should filter out problematic seeds)"
java -Xmx2G -Xms512M -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config kitten/scripts/javascript/seed_validation_config.yaml \
  --threads 1 \
  --verbosity "INFO" \
  --finding-folder kitten/temp_seed_validation_test/with_validation \
  --timeout 30 \
  --max-seed-pool-size 10 \
  --validate-seeds-on-all-engines true \
  --fuzzer-mode ONLY_ON_INITIAL_SEED || true

echo "Test completed. Checking results..."

echo "Results without validation:"
if [[ -d "kitten/temp_seed_validation_test/without_validation" ]]; then
    echo "✅ Output directory exists"
    ls -la kitten/temp_seed_validation_test/without_validation/
else
    echo "❌ Output directory does not exist"
fi

echo "Results with validation:"
if [[ -d "kitten/temp_seed_validation_test/with_validation" ]]; then
    echo "✅ Output directory exists"
    ls -la kitten/temp_seed_validation_test/with_validation/
else
    echo "❌ Output directory does not exist"
fi

echo "Seed validation test completed!"
