#!/usr/bin/env python3
"""
Test script to verify comprehensive seed validation.
This script tests the new validation logic that ensures:
1. All engines exit with code 0 (clean exit)
2. No engine crashes
3. All engines produce identical stdout output
"""

import subprocess
import sys
import os
import tempfile
import json
from pathlib import Path

def run_engine_test(engine_cmd, test_file):
    """Run a test file on a specific engine and return the result."""
    try:
        # Run the engine with the test file
        result = subprocess.run(
            [engine_cmd, test_file],
            capture_output=True,
            text=True,
            timeout=10
        )
        return {
            'exit_code': result.returncode,
            'stdout': result.stdout.strip(),
            'stderr': result.stderr.strip(),
            'success': result.returncode == 0
        }
    except subprocess.TimeoutExpired:
        return {
            'exit_code': -1,
            'stdout': '',
            'stderr': 'Timeout',
            'success': False
        }
    except Exception as e:
        return {
            'exit_code': -1,
            'stdout': '',
            'stderr': str(e),
            'success': False
        }

def normalize_stdout(output):
    """Normalize stdout output for comparison."""
    if not output:
        return ""
    
    # Trim and collapse whitespace
    normalized = output.strip()
    normalized = normalized.replace('\r\n', '\n').replace('\r', '\n')
    import re
    normalized = re.sub(r'\s+', ' ', normalized)
    
    return normalized

def validate_seed_comprehensively(test_file, engines):
    """
    Comprehensive seed validation that ensures:
    1. All engines exit with code 0 (clean exit)
    2. No engine crashes
    3. All engines produce identical stdout output
    """
    print(f"Validating seed: {test_file}")
    print(f"Testing on engines: {engines}")
    
    results = {}
    
    # Step 1: Run the seed on all engines
    for engine in engines:
        print(f"  Testing on {engine}...")
        result = run_engine_test(engine, test_file)
        results[engine] = result
        print(f"    Exit code: {result['exit_code']}")
        print(f"    Stdout: '{result['stdout'][:100]}...'")
        print(f"    Stderr: '{result['stderr'][:100]}...'")
    
    # Step 2: Check if all engines succeeded (exit code 0)
    for engine, result in results.items():
        if result['exit_code'] != 0:
            print(f"  ❌ FAIL: Engine {engine} failed with exit code {result['exit_code']}")
            return False
    
    # Step 3: Check that all engines produce the same stdout output
    if len(results) > 1:
        first_stdout = normalize_stdout(results[list(results.keys())[0]]['stdout'])
        for engine, result in results.items():
            normalized_stdout = normalize_stdout(result['stdout'])
            if normalized_stdout != first_stdout:
                print(f"  ❌ FAIL: Engine {engine} produces different stdout")
                print(f"    Expected: '{first_stdout}'")
                print(f"    Got: '{normalized_stdout}'")
                return False
    
    print(f"  ✅ PASS: Seed passed comprehensive validation")
    return True

def main():
    # Define test engines (adjust paths as needed)
    engines = [
        "v8",
        "graaljs", 
        "jsc"
    ]
    
    # Test files
    test_files = [
        "test_seeds/valid_seed.js",
        "test_seeds/invalid_seed.js"
    ]
    
    print("=== Comprehensive Seed Validation Test ===\n")
    
    for test_file in test_files:
        if os.path.exists(test_file):
            print(f"\n--- Testing {test_file} ---")
            success = validate_seed_comprehensively(test_file, engines)
            print(f"Result: {'PASS' if success else 'FAIL'}")
        else:
            print(f"\n--- Skipping {test_file} (file not found) ---")
    
    print("\n=== Test Complete ===")

if __name__ == "__main__":
    main()
