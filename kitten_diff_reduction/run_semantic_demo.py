#!/usr/bin/env python3
"""
Demo script for running semantic-enhanced differential testing error reduction

This script demonstrates how to use the semantic enhancement features
on your differential testing results.
"""

import os
import sys
from pathlib import Path

def main():
    """Run semantic enhancement demo."""
    print("=== JavaScript Differential Testing Semantic Enhancement Demo ===")
    
    # Check if input directory is provided
    if len(sys.argv) < 2:
        print("Usage: python run_semantic_demo.py <input_directory>")
        print("Example: python run_semantic_demo.py results/differential_findings_javascript")
        sys.exit(1)
    
    input_dir = sys.argv[1]
    
    if not Path(input_dir).exists():
        print(f"Error: Input directory does not exist: {input_dir}")
        sys.exit(1)
    
    print(f"Input directory: {input_dir}")
    
    # Step 1: Generate report with pattern-based analysis
    print("\n1. Running pattern-based analysis...")
    os.system(f"python main.py --input-dir {input_dir} --report-only --output-dir pattern_analysis")
    
    # Step 2: Generate report with semantic analysis
    print("\n2. Running semantic-enhanced analysis...")
    os.system(f"python main.py --input-dir {input_dir} --report-only --semantic --output-dir semantic_analysis")
    
    # Step 3: Full processing with semantic enhancement
    print("\n3. Running full semantic-enhanced processing...")
    os.system(f"python main.py --input-dir {input_dir} --semantic --output-dir semantic_reduced_findings")
    
    print("\n=== Demo Complete ===")
    print("Results saved in:")
    print("  - pattern_analysis/: Pattern-based analysis results")
    print("  - semantic_analysis/: Semantic-enhanced analysis results")
    print("  - semantic_reduced_findings/: Full semantic processing results")
    
    # Compare results
    print("\n=== Comparison ===")
    compare_results("pattern_analysis", "semantic_analysis")


def compare_results(pattern_dir: str, semantic_dir: str):
    """Compare pattern-based vs semantic analysis results."""
    import json
    
    pattern_report = Path(pattern_dir) / "summary_report.json"
    semantic_report = Path(semantic_dir) / "summary_report.json"
    
    if pattern_report.exists() and semantic_report.exists():
        with open(pattern_report) as f:
            pattern_data = json.load(f)
        
        with open(semantic_report) as f:
            semantic_data = json.load(f)
        
        print("Pattern-based vs Semantic Analysis Comparison:")
        print(f"  Total findings: {pattern_data['total_findings']} vs {semantic_data['total_findings']}")
        print(f"  Error groups: {pattern_data['unique_error_groups']} vs {semantic_data['unique_error_groups']}")
        
        if 'reduction_ratio' in semantic_data:
            print(f"  Semantic reduction ratio: {semantic_data['reduction_ratio']:.2%}")
        
        # Calculate improvement
        pattern_groups = pattern_data['unique_error_groups']
        semantic_groups = semantic_data['unique_error_groups']
        
        if pattern_groups > 0:
            improvement = (pattern_groups - semantic_groups) / pattern_groups * 100
            print(f"  Grouping improvement: {improvement:.1f}% fewer groups with semantic analysis")


if __name__ == "__main__":
    main() 