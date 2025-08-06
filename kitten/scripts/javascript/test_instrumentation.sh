#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ ! -e "WORKSPACE" ]]; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"

echo "Testing JavaScript instrumentation in Docker environment..."

# Create a test JavaScript file
readonly TEST_FILE="${SCRIPT_DIR}/test_instrumentation.js"
cat > "${TEST_FILE}" << 'EOF'
// Test file for instrumentation
let x = 0.1 + 0.2;
let y = {a: 1, b: "test"};
let z = true && false;
console.log(x, y, z);
EOF

echo "Original test file:"
cat "${TEST_FILE}"
echo ""

# Build the project
echo "Building kitten with instrumentation support..."
bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar || exit 1

# Create a simple test program to verify instrumentation
readonly TEST_CLASS="TestInstrumentation"
readonly TEST_JAVA="${SCRIPT_DIR}/TestInstrumentation.java"

cat > "${TEST_JAVA}" << 'EOF'
import org.perses.fuzzer.instrumentation.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class TestInstrumentation {
    public static void main(String[] args) throws Exception {
        // Read the test file
        String sourceCode = new String(Files.readAllBytes(Paths.get("kitten/scripts/javascript/test_instrumentation.js")));
        
        // Create instrumentation config
        InstrumentationConfig config = InstrumentationConfig.Companion.defaultConfig();
        
        // Create instrumenter
        JavaScriptInstrumenter instrumenter = new JavaScriptInstrumenter(config);
        
        // Instrument the code
        String instrumentedCode = instrumenter.instrument(sourceCode);
        
        // Print the instrumented code
        System.out.println("=== INSTRUMENTED CODE ===");
        System.out.println(instrumentedCode);
        
        // Print statistics
        JavaScriptInstrumenter.InstrumentationStats stats = instrumenter.getInstrumentationStats();
        System.out.println("\n=== INSTRUMENTATION STATS ===");
        System.out.println("Enabled: " + stats.getEnabled());
        System.out.println("Probe types: " + stats.getProbeTypes());
        System.out.println("Max probes per program: " + stats.getMaxProbesPerProgram());
        
        System.out.println("\nInstrumentation test completed successfully!");
    }
}
EOF

# Compile and run the test
echo "Compiling and running instrumentation test..."
javac -cp "bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar" "${TEST_JAVA}"
java -cp ".:bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar" "${TEST_CLASS}"

# Clean up
rm -f "${TEST_FILE}" "${TEST_JAVA}" "${TEST_CLASS}.class"

echo "Instrumentation test completed!" 