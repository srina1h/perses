#!/usr/bin/env python3
"""
Analyze Standardized Differential Testing Outputs

This script helps analyze the standardized outputs from differential testing
to quickly identify discrepancies between JavaScript engines.
"""

import argparse
import csv
import os
import sys
from pathlib import Path
from typing import Dict, List, Set, Tuple
from collections import defaultdict


class StandardizedOutputAnalyzer:
    """Analyzes standardized differential testing outputs."""
    
    def __init__(self, output_dir: str):
        self.output_dir = Path(output_dir)
        self.csv_files = list(self.output_dir.glob("**/*.csv"))
        self.table_files = list(self.output_dir.glob("**/*standardized_output_table.txt"))
        
    def find_discrepancies(self) -> List[Dict]:
        """Find all discrepancies across all test files."""
        discrepancies = []
        
        for csv_file in self.csv_files:
            test_discrepancies = self._analyze_csv_file(csv_file)
            discrepancies.extend(test_discrepancies)
            
        return discrepancies
    
    def _analyze_csv_file(self, csv_file: Path) -> List[Dict]:
        """Analyze a single CSV file for discrepancies."""
        discrepancies = []
        
        try:
            with open(csv_file, 'r', encoding='utf-8') as f:
                reader = csv.DictReader(f)
                rows = list(reader)
                
            if len(rows) < 2:
                return discrepancies
                
            # Group by test_id
            test_groups = defaultdict(list)
            for row in rows:
                test_groups[row['test_id']].append(row)
            
            for test_id, test_rows in test_groups.items():
                test_discrepancies = self._analyze_test_group(test_id, test_rows, csv_file)
                discrepancies.extend(test_discrepancies)
                
        except Exception as e:
            print(f"Error analyzing {csv_file}: {e}")
            
        return discrepancies
    
    def _analyze_test_group(self, test_id: str, rows: List[Dict], source_file: Path) -> List[Dict]:
        """Analyze a group of rows for the same test ID."""
        discrepancies = []
        
        # Check for status discrepancies
        statuses = set(row['status'] for row in rows)
        if len(statuses) > 1:
            discrepancies.append({
                'test_id': test_id,
                'type': 'status_mismatch',
                'description': f"Different execution statuses: {', '.join(statuses)}",
                'engines': [row['engine_name'] for row in rows],
                'values': list(statuses),
                'source_file': str(source_file)
            })
        
        # Check for exit code discrepancies
        exit_codes = set(int(row['exit_code']) for row in rows)
        if len(exit_codes) > 1:
            discrepancies.append({
                'test_id': test_id,
                'type': 'exit_code_mismatch',
                'description': f"Different exit codes: {', '.join(map(str, exit_codes))}",
                'engines': [row['engine_name'] for row in rows],
                'values': list(map(str, exit_codes)),
                'source_file': str(source_file)
            })
        
        # Check for stdout discrepancies
        stdout_sets = [set(row['stdout_lines'].split('\\n')) for row in rows if row['stdout_lines']]
        if len(stdout_sets) > 1 and len(set(tuple(sorted(s)) for s in stdout_sets)) > 1:
            discrepancies.append({
                'test_id': test_id,
                'type': 'stdout_mismatch',
                'description': "Different stdout content between engines",
                'engines': [row['engine_name'] for row in rows],
                'values': [row['stdout_lines'] for row in rows],
                'source_file': str(source_file)
            })
        
        # Check for stderr discrepancies
        stderr_sets = [set(row['stderr_lines'].split('\\n')) for row in rows if row['stderr_lines']]
        if len(stderr_sets) > 1 and len(set(tuple(sorted(s)) for s in stderr_sets)) > 1:
            discrepancies.append({
                'test_id': test_id,
                'type': 'stderr_mismatch',
                'description': "Different stderr content between engines",
                'engines': [row['engine_name'] for row in rows],
                'values': [row['stderr_lines'] for row in rows],
                'source_file': str(source_file)
            })
        
        # Check for error type discrepancies
        error_types = [row['error_type'] for row in rows if row['error_type']]
        if len(set(error_types)) > 1:
            discrepancies.append({
                'test_id': test_id,
                'type': 'error_type_mismatch',
                'description': f"Different error types: {', '.join(set(error_types))}",
                'engines': [row['engine_name'] for row in rows],
                'values': error_types,
                'source_file': str(source_file)
            })
        
        return discrepancies
    
    def print_summary(self):
        """Print a summary of all findings."""
        discrepancies = self.find_discrepancies()
        
        print("=== STANDARDIZED OUTPUT ANALYSIS SUMMARY ===")
        print(f"Output directory: {self.output_dir}")
        print(f"CSV files found: {len(self.csv_files)}")
        print(f"Table files found: {len(self.table_files)}")
        print(f"Total discrepancies found: {len(discrepancies)}")
        print()
        
        if discrepancies:
            print("=== DISCREPANCIES BY TYPE ===")
            type_counts = defaultdict(int)
            for d in discrepancies:
                type_counts[d['type']] += 1
            
            for discrepancy_type, count in sorted(type_counts.items()):
                print(f"{discrepancy_type}: {count}")
            print()
            
            print("=== DETAILED DISCREPANCIES ===")
            for i, discrepancy in enumerate(discrepancies, 1):
                print(f"Discrepancy {i}:")
                print(f"  Test ID: {discrepancy['test_id']}")
                print(f"  Type: {discrepancy['type']}")
                print(f"  Description: {discrepancy['description']}")
                print(f"  Engines: {', '.join(discrepancy['engines'])}")
                print(f"  Source: {discrepancy['source_file']}")
                print()
        else:
            print("✓ No discrepancies found - all engines produced consistent results")
    
    def export_discrepancies(self, output_file: str):
        """Export discrepancies to a CSV file."""
        discrepancies = self.find_discrepancies()
        
        with open(output_file, 'w', newline='', encoding='utf-8') as f:
            writer = csv.DictWriter(f, fieldnames=[
                'test_id', 'type', 'description', 'engines', 'values', 'source_file'
            ])
            writer.writeheader()
            writer.writerows(discrepancies)
        
        print(f"Exported {len(discrepancies)} discrepancies to {output_file}")
    
    def find_specific_discrepancy(self, discrepancy_type: str) -> List[Dict]:
        """Find discrepancies of a specific type."""
        all_discrepancies = self.find_discrepancies()
        return [d for d in all_discrepancies if d['type'] == discrepancy_type]
    
    def compare_engines(self, engine1: str, engine2: str) -> List[Dict]:
        """Compare outputs between two specific engines."""
        discrepancies = self.find_discrepancies()
        return [d for d in discrepancies if engine1 in d['engines'] and engine2 in d['engines']]


def main():
    parser = argparse.ArgumentParser(description="Analyze standardized differential testing outputs")
    parser.add_argument("output_dir", help="Directory containing standardized output files")
    parser.add_argument("--export", help="Export discrepancies to CSV file")
    parser.add_argument("--type", help="Filter by discrepancy type")
    parser.add_argument("--compare", nargs=2, metavar=("ENGINE1", "ENGINE2"), 
                       help="Compare two specific engines")
    
    args = parser.parse_args()
    
    if not os.path.exists(args.output_dir):
        print(f"Error: Output directory '{args.output_dir}' does not exist")
        sys.exit(1)
    
    analyzer = StandardizedOutputAnalyzer(args.output_dir)
    
    if args.type:
        discrepancies = analyzer.find_specific_discrepancy(args.type)
        print(f"=== DISCREPANCIES OF TYPE: {args.type} ===")
        for i, d in enumerate(discrepancies, 1):
            print(f"{i}. {d['description']} (Test: {d['test_id']})")
    
    elif args.compare:
        engine1, engine2 = args.compare
        discrepancies = analyzer.compare_engines(engine1, engine2)
        print(f"=== COMPARISON: {engine1} vs {engine2} ===")
        for i, d in enumerate(discrepancies, 1):
            print(f"{i}. {d['description']} (Test: {d['test_id']})")
    
    else:
        analyzer.print_summary()
    
    if args.export:
        analyzer.export_discrepancies(args.export)


if __name__ == "__main__":
    main()
