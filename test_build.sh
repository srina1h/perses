#!/bin/bash

echo "Testing build..."
bazel build //kitten/src/org/perses/fuzzer:kitten_deploy.jar

if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    echo "Testing differential fuzzing..."
    ./kitten/scripts/javascript/test_differential.sh
else
    echo "❌ Build failed!"
    exit 1
fi 