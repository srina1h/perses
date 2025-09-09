#!/usr/bin/env python3
"""
Show Organized Structure

This script provides an overview of the organized findings folder structure.
"""

import os
from pathlib import Path

def main():
    organized_dir = Path("organized_findings")
    
    if not organized_dir.exists():
        print("Organized findings directory not found. Run organize_findings.py first.")
        return
    
    print("📁 ORGANIZED FINDINGS STRUCTURE OVERVIEW")
    print("=" * 50)
    
    # Read summary
    summary_file = organized_dir / "summary.txt"
    if summary_file.exists():
        with open(summary_file, 'r') as f:
            print(f.read())
    
    # List all patterns
    pattern_dirs = [d for d in organized_dir.iterdir() if d.is_dir() and d.name.startswith('pattern_')]
    pattern_dirs.sort()
    
    print("📂 PATTERN FOLDERS:")
    print("-" * 30)
    
    total_clusters = 0
    total_cases = 0
    
    for pattern_dir in pattern_dirs:
        pattern_name = pattern_dir.name.replace('pattern_', '').replace('_', ',')
        
        # Read pattern summary
        pattern_summary = pattern_dir / "pattern_summary.txt"
        if pattern_summary.exists():
            with open(pattern_summary, 'r') as f:
                lines = f.readlines()
                total_cases_line = [l for l in lines if 'Total cases:' in l]
                if total_cases_line:
                    cases = int(total_cases_line[0].split(':')[1].strip())
                    total_cases += cases
        
        # Count clusters
        cluster_dirs = [d for d in pattern_dir.iterdir() if d.is_dir() and d.name.startswith('cluster_')]
        n_clusters = len(cluster_dirs)
        total_clusters += n_clusters
        
        print(f"  {pattern_name}: {n_clusters} clusters")
    
    print(f"\n📊 SUMMARY:")
    print(f"   Total patterns: {len(pattern_dirs)}")
    print(f"   Total clusters: {total_clusters}")
    print(f"   Total cases: {total_cases}")
    
    print(f"\n🔍 EXPLORATION TIPS:")
    print(f"   - Each pattern folder contains clusters of similar findings")
    print(f"   - Each cluster contains individual test cases")
    print(f"   - Each case has engine-specific output files (stdout.txt, stderr.txt, error.txt)")
    print(f"   - Summary files are available at each level")
    print(f"   - Start with the largest patterns for most impactful findings")

if __name__ == "__main__":
    main()
