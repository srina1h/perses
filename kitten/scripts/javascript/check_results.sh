#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

echo "=== Checking Differential Testing Results ==="

# Check if the main directory exists
if [[ -d "kitten/temp_testing_campaigns" ]]; then
    echo "✅ Main campaigns directory exists"
    ls -la kitten/temp_testing_campaigns/
else
    echo "❌ Main campaigns directory does not exist"
fi

# Check for test differential folder
if [[ -d "kitten/temp_testing_campaigns/test_differential_finding_folder" ]]; then
    echo "✅ Test differential finding folder exists"
    echo "Number of findings: $(ls kitten/temp_testing_campaigns/test_differential_finding_folder/ | wc -l)"
    echo "First few findings:"
    ls kitten/temp_testing_campaigns/test_differential_finding_folder/ | head -5
else
    echo "❌ Test differential finding folder does not exist"
fi

# Check for main differential folder
if [[ -d "kitten/temp_testing_campaigns/differential_finding_folder_javascript" ]]; then
    echo "✅ Main differential finding folder exists"
    echo "Number of findings: $(ls kitten/temp_testing_campaigns/differential_finding_folder_javascript/ | wc -l)"
    echo "First few findings:"
    ls kitten/temp_testing_campaigns/differential_finding_folder_javascript/ | head -5
else
    echo "❌ Main differential finding folder does not exist"
fi

# Check for any differential findings anywhere
echo "=== Searching for any differential findings ==="
find . -name "differential_finding_*" 2>/dev/null | head -10

echo "=== Checking file permissions ==="
ls -la kitten/temp_testing_campaigns/ 2>/dev/null || echo "Cannot access campaigns directory" 