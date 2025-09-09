#!/usr/bin/env python3
"""
Exit Code Pattern Analysis

This script analyzes and displays exit code patterns across the 4 JavaScript engines.
"""

import sys
import os
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from reduce import DifferentialFindingsAnalyzer

def main():
    # Initialize analyzer
    analyzer = DifferentialFindingsAnalyzer('8_29/differential_finding_folder_javascript')
    
    # Load data
    print("Loading data...")
    analyzer.load_all_data()
    
    if analyzer.all_data.empty:
        print("No data found.")
        return
    
    # Analyze exit code patterns
    print("\n🔢 EXIT CODE PATTERN ANALYSIS")
    print("=" * 50)
    
    exit_patterns = analyzer.analyze_exit_code_patterns()
    
    if not exit_patterns:
        print("No exit code patterns found.")
        return
    
    print(f"\n📊 OVERVIEW:")
    print(f"   Total unique patterns: {exit_patterns['total_patterns']}")
    
    # Show all patterns sorted by frequency
    pattern_counts = exit_patterns['pattern_counts']
    sorted_patterns = sorted(pattern_counts.items(), key=lambda x: x[1], reverse=True)
    
    print(f"\n🎯 ALL PATTERNS (V8,SpiderMonkey,JavaScriptCore,GraalJS):")
    print(f"   {'Pattern':<15} {'Count':<8} {'Percentage':<12}")
    print(f"   {'-'*15} {'-'*8} {'-'*12}")
    
    total_cases = sum(pattern_counts.values())
    
    for pattern, count in sorted_patterns:
        percentage = (count / total_cases * 100) if total_cases > 0 else 0
        print(f"   {pattern:<15} {count:<8} {percentage:>6.1f}%")
    
    print(f"\n💡 SUMMARY:")
    print(f"   Total cases analyzed: {total_cases}")
    print(f"   Most common pattern: {sorted_patterns[0][0]} ({sorted_patterns[0][1]} cases)")
    print(f"   Least common pattern: {sorted_patterns[-1][0]} ({sorted_patterns[-1][1]} cases)")

if __name__ == "__main__":
    main()
