#!/usr/bin/env python3
"""
Explore Findings Script

This script explores the types of files available in the finding data folders
to help understand what data is available for analysis.
"""

import os
from pathlib import Path
from collections import defaultdict, Counter

def main():
    organized_dir = Path("organized_findings")
    
    if not organized_dir.exists():
        print("Organized findings directory not found. Run organize_findings.py first.")
        return
    
    print("🔍 EXPLORING FINDING DATA FILES")
    print("=" * 50)
    
    # Find all finding_data directories
    finding_data_dirs = list(organized_dir.rglob("finding_data"))
    
    if not finding_data_dirs:
        print("No finding_data directories found.")
        return
    
    print(f"Found {len(finding_data_dirs)} finding_data directories")
    
    # Collect all file types
    file_types = Counter()
    file_names = Counter()
    total_files = 0
    
    for finding_dir in finding_data_dirs:
        for item in finding_dir.iterdir():
            if item.is_file():
                total_files += 1
                file_types[item.suffix] += 1
                file_names[item.name] += 1
    
    print(f"\n📊 FILE STATISTICS:")
    print(f"   Total files: {total_files}")
    print(f"   Unique file types: {len(file_types)}")
    print(f"   Unique file names: {len(file_names)}")
    
    print(f"\n📁 FILE TYPES:")
    print("-" * 20)
    for ext, count in file_types.most_common():
        print(f"  {ext or '(no extension)'}: {count} files")
    
    print(f"\n📄 COMMON FILE NAMES:")
    print("-" * 25)
    for name, count in file_names.most_common(10):
        print(f"  {name}: {count} occurrences")
    
    # Show sample of what's in a finding_data directory
    print(f"\n🔍 SAMPLE FINDING_DATA CONTENTS:")
    print("-" * 35)
    sample_dir = finding_data_dirs[0]
    print(f"Sample directory: {sample_dir}")
    print("Files:")
    for item in sample_dir.iterdir():
        if item.is_file():
            size = item.stat().st_size
            print(f"  {item.name} ({size} bytes)")
        elif item.is_dir():
            print(f"  {item.name}/ (directory)")
    
    print(f"\n💡 ANALYSIS TIPS:")
    print(f"   - input.js: Contains the test case that caused the differential behavior")
    print(f"   - seed.js: Original file that was mutated to create the test")
    print(f"   - standardized_output.csv: Engine outputs in CSV format")
    print(f"   - standardized_output_table.txt: Engine outputs in table format")
    print(f"   - finding_summary.txt: Summary of the finding context")

if __name__ == "__main__":
    main()
