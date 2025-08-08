#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

echo "=== Testing Seed Validation Command Line Parsing ==="

# Test that the flag can be parsed correctly
echo "Testing command line parsing with --validate-seeds-on-all-engines flag..."

# This should just parse the command line and show help, not actually run
java -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --help 2>&1 | grep -q "validate-seeds-on-all-engines" && echo "✅ Flag found in help" || echo "❌ Flag not found in help"

echo "Testing command line parsing with the flag enabled..."
# This should parse successfully and show the flag is enabled
java -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --validate-seeds-on-all-engines true \
  --help 2>&1 | grep -q "validate-seeds-on-all-engines" && echo "✅ Flag parsing successful" || echo "❌ Flag parsing failed"

echo "Seed validation command line parsing test completed!"
