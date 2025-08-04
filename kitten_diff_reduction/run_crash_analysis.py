#!/usr/bin/env python3
"""
Simple Crash Analysis Script

This script analyzes only crash findings using fast pattern matching.
No semantic analysis or heavy processing involved.
"""

import sys
import os
from pathlib import Path
from crash_analyzer import analyze_crash_folders


def main():
    """Run crash analysis on the specified directory."""
    if len(sys.argv) < 2:
        print("Usage: python run_crash_analysis.py <input_directory>")
        print("Example: python run_crash_analysis.py ../results/differential_findings_javascript")
        sys.exit(1)
    
    input_dir = sys.argv[1]
    
    if not os.path.exists(input_dir):
        print(f"Error: Directory '{input_dir}' does not exist")
        sys.exit(1)
    
    print(f"Starting crash analysis on: {input_dir}")
    print("=" * 60)
    
    try:
        # Run crash analysis
        crash_groups = analyze_crash_folders(input_dir)
        
        print("\n" + "=" * 60)
        print("CRASH ANALYSIS COMPLETE")
        print("=" * 60)
        
        # Save results to a simple text file
        output_file = "crash_analysis_results.txt"
        with open(output_file, 'w') as f:
            f.write("CRASH ANALYSIS RESULTS\n")
            f.write("=" * 50 + "\n\n")
            
            f.write(f"Total crash groups: {len(crash_groups)}\n")
            f.write(f"Total crashes analyzed: {sum(g.count for g in crash_groups)}\n\n")
            
            f.write("TOP CRASH GROUPS:\n")
            f.write("-" * 30 + "\n")
            
            for i, group in enumerate(crash_groups[:20]):  # Top 20
                f.write(f"{i+1}. {group.crash_type} ({group.count} crashes)\n")
                f.write(f"   Pattern: {group.signature.error_pattern}\n")
                f.write(f"   Representative: {group.representative.finding_path.name}\n")
                f.write(f"   Exit code: {group.signature.exit_code}\n")
                f.write(f"   Engines: {group.signature.engine_combination}\n\n")
        
        print(f"Results saved to: {output_file}")
        
    except Exception as e:
        print(f"Error during analysis: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main() 