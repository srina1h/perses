#!/usr/bin/env python3
"""
Test script for the JavaScript Differential Testing Error Reduction Framework

This script demonstrates how to use the framework with sample data.
"""

import tempfile
import os
from pathlib import Path
from finding_parser import DifferentialFinding, EngineOutput, DiscrepancyType
from error_classifier import ErrorClassifier, ErrorCategory, ErrorSeverity
from reducer import DifferentialReducer


def create_sample_finding():
    """Create a sample differential finding for testing."""
    # Create a temporary directory structure
    with tempfile.TemporaryDirectory() as temp_dir:
        finding_dir = Path(temp_dir) / "sample_finding"
        finding_dir.mkdir()
        
        # Create sample input.js
        input_js = """
// Sample JavaScript code that might cause differential behavior
var x = 1;
var y = "2";
console.log(x + y);  // Different engines might handle this differently
"""
        
        with open(finding_dir / "input.js", 'w') as f:
            f.write(input_js)
        
        # Create sample seed.js
        seed_js = "// Original seed code"
        with open(finding_dir / "seed.js", 'w') as f:
            f.write(seed_js)
        
        # Create engine outputs
        engines = ["engine_graaljs", "engine_hermes", "engine_v8"]
        
        for engine in engines:
            engine_dir = finding_dir / engine
            engine_dir.mkdir()
            
            # Different outputs for different engines
            if engine == "engine_graaljs":
                exit_code = 0
                stdout = "12"
                stderr = ""
            elif engine == "engine_hermes":
                exit_code = 0
                stdout = "3"
                stderr = ""
            else:  # v8
                exit_code = 0
                stdout = "12"
                stderr = ""
            
            with open(engine_dir / "command.txt", 'w') as f:
                f.write(f"{engine} input.js")
            
            with open(engine_dir / "exit_code.txt", 'w') as f:
                f.write(str(exit_code))
            
            with open(engine_dir / "stdout.txt", 'w') as f:
                f.write(stdout)
            
            with open(engine_dir / "stderr.txt", 'w') as f:
                f.write(stderr)
        
        # Create other required files
        with open(finding_dir / "summary.txt", 'w') as f:
            f.write("Sample differential finding")
        
        with open(finding_dir / "differential_results.txt", 'w') as f:
            f.write("Differential behavior detected")
        
        return str(finding_dir)


def test_finding_parser():
    """Test the finding parser."""
    print("Testing Finding Parser...")
    
    # Create a sample finding
    finding_path = create_sample_finding()
    
    # Parse the finding
    from finding_parser import parse_finding_folder
    finding = parse_finding_folder(finding_path)
    
    print(f"Parsed finding: {finding.finding_path}")
    print(f"Discrepancy type: {finding.discrepancy_type}")
    print(f"Number of engines: {len(finding.engine_outputs)}")
    print(f"Input size: {len(finding.input_js)} characters")
    
    return finding


def test_error_classifier(finding):
    """Test the error classifier."""
    print("\nTesting Error Classifier...")
    
    classifier = ErrorClassifier()
    classified_error = classifier.classify_finding(finding)
    
    print(f"Error category: {classified_error.signature.category}")
    print(f"Error severity: {classified_error.signature.severity}")
    print(f"Confidence: {classified_error.confidence:.2f}")
    print(f"Engine combination: {classified_error.signature.engine_combination}")
    print(f"Normalized message: {classified_error.signature.normalized_message}")
    
    return classified_error


def test_reducer(finding):
    """Test the reducer (without actual engine execution)."""
    print("\nTesting Reducer...")
    
    # Create a mock test function that always returns True
    def mock_test_function(code):
        return True
    
    from reducer import DeltaDebugger
    delta_debugger = DeltaDebugger()
    
    # Test basic reduction strategies
    original_code = finding.input_js
    print(f"Original code size: {len(original_code)} characters")
    
    # Test comment removal
    cleaned_code = delta_debugger._remove_comments_and_whitespace(original_code)
    print(f"After comment removal: {len(cleaned_code)} characters")
    
    # Test unused variable removal
    reduced_code = delta_debugger._remove_unused_variables(cleaned_code)
    print(f"After variable removal: {len(reduced_code)} characters")
    
    return reduced_code


def test_multiple_findings():
    """Test processing multiple findings."""
    print("\nTesting Multiple Findings Processing...")
    
    # Create multiple sample findings
    findings = []
    for i in range(3):
        finding_path = create_sample_finding()
        from finding_parser import parse_finding_folder
        finding = parse_finding_folder(finding_path)
        findings.append(finding)
    
    # Classify all findings
    classifier = ErrorClassifier()
    classified_errors = classifier.classify_findings(findings)
    
    print(f"Classified {len(classified_errors)} findings")
    
    # Group similar errors
    error_groups = classifier.group_similar_errors(classified_errors)
    print(f"Found {len(error_groups)} error groups")
    
    for i, group in enumerate(error_groups):
        print(f"Group {i}: {len(group)} findings")
        if group:
            representative = group[0]
            print(f"  Category: {representative.signature.category}")
            print(f"  Severity: {representative.signature.severity}")


def main():
    """Run all tests."""
    print("JavaScript Differential Testing Error Reduction Framework - Test Suite")
    print("=" * 70)
    
    try:
        # Test finding parser
        finding = test_finding_parser()
        
        # Test error classifier
        classified_error = test_error_classifier(finding)
        
        # Test reducer
        reduced_code = test_reducer(finding)
        
        # Test multiple findings
        test_multiple_findings()
        
        print("\n" + "=" * 70)
        print("All tests completed successfully!")
        
    except Exception as e:
        print(f"\nTest failed with error: {e}")
        import traceback
        traceback.print_exc()


if __name__ == "__main__":
    main() 