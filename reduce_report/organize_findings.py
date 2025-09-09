#!/usr/bin/env python3
"""
Organize Findings Script

This script creates a folder structure organized by exit code patterns and clusters
for further analysis of differential findings.
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
    
    # Create folder structure
    print("\n📁 CREATING FOLDER STRUCTURE")
    print("=" * 50)
    
    output_dir = analyzer.create_folder_structure("organized_findings")
    
    if output_dir:
        print(f"\n✅ Organization complete!")
        print(f"   Explore the '{output_dir}' directory for organized findings.")
        print(f"   Each pattern has its own folder with clusters and cases.")
        print(f"   Summary files are included at each level.")

if __name__ == "__main__":
    main()
