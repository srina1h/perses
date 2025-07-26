#!/bin/bash

# Generate JavaScript compiler configuration with correct JSVU path
# This script automatically detects the JSVU installation and generates the config

set -e

# Default JSVU path
JSVU_PATH="${HOME}/.jsvu/bin"

# Check if JSVU is installed
if [ ! -d "$JSVU_PATH" ]; then
    echo "Error: JSVU not found at $JSVU_PATH"
    echo "Please install JSVU first: npm install -g jsvu"
    exit 1
fi

# Check if required engines are available
if [ ! -f "$JSVU_PATH/v8" ]; then
    echo "Warning: V8 not found at $JSVU_PATH/v8"
    echo "You can install it with: jsvu --engines=v8"
fi

if [ ! -f "$JSVU_PATH/hermes" ]; then
    echo "Warning: Hermes not found at $JSVU_PATH/hermes"
    echo "You can install it with: jsvu --engines=hermes"
fi

# Generate the configuration file
cat > "all-compilers-config.yaml" << EOF
language: "JAVASCRIPT"
seedFolders:
  - path: "seeds"
    fileExtentions: [".js"]

programsUnderTest:
  # - command: "jerry-trunk-asan_ubsan"
  #   flagsToTest:
  #     - flags: []
  #   versionFlags:
  #     flags: ["--version"]
  #   crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.JerryScriptCrashDetector"
  
  - command: "$JSVU_PATH/v8"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--version"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.V8CrashDetector"
  
  - command: "$JSVU_PATH/hermes"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["--version"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.javascript.HermesCrashDetector"
EOF

echo "Configuration file generated successfully!"
echo "JSVU path: $JSVU_PATH"
echo "Configuration file: all-compilers-config.yaml" 