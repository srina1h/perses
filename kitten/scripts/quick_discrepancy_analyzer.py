#!/usr/bin/env python3
"""
Quick Discrepancy Analyzer for Standardized Differential Testing Outputs

This script implements map-based comparison for O(1) lookup time when detecting
discrepancies between JavaScript engines. It provides much faster analysis than
the traditional line-by-line comparison approach.
"""

import argparse
import csv
import os
import sys
from pathlib import Path
from typing import Dict, List, Set, Tuple, Any
from collections import defaultdict
import time


class QuickDiscrepancyAnalyzer:
    """Implements map-based quick discrepancy detection for standardized outputs."""
    
    def __init__(self, output_dir: str):
        self.output_dir = Path(output_dir)
        self.csv_files = list(self.output_dir.glob("**/*.csv"))
        self.comparison_maps = {}  # Cache for comparison maps
        
    def create_comparison_map(self, csv_file: Path) -> Dict[str, Any]:
        """Creates a comparison map from CSV data for O(1) lookups."""
        comparison_map = {
            'test_id': None,
            'engine_names': [],
            'status_map': {},
            'exit_code_map': {},
            'execution_time_map': {},
            'error_type_map': {},
            'crash_signature_map': {},
            'stdout_map': defaultdict(dict),  # line_number -> {engine -> content}
            'stderr_map': defaultdict(dict),  # line_number -> {engine -> content}
            'stdout_content_map': {},  # engine -> set of lines
            'stderr_content_map': {}   # engine -> set of lines
        }
        
        try:
            with open(csv_file, 'r', encoding='utf-8') as f:
                reader = csv.DictReader(f)
                rows = list(reader)
                
            if not rows:
                return comparison_map
                
            # Group by test_id
            test_groups = defaultdict(list)
            for row in rows:
                test_groups[row['test_id']].append(row)
            
            # Process each test group
            for test_id, test_rows in test_groups.items():
                comparison_map['test_id'] = test_id
                comparison_map['engine_names'] = [row['engine_name'] for row in test_rows]
                
                # Create maps for each comparison dimension
                for row in test_rows:
                    engine_name = row['engine_name']
                    
                    # Basic maps
                    comparison_map['status_map'][engine_name] = row['status']
                    comparison_map['exit_code_map'][engine_name] = int(row['exit_code'])
                    comparison_map['execution_time_map'][engine_name] = int(row['execution_time_ms'])
                    comparison_map['error_type_map'][engine_name] = row['error_type'] if row['error_type'] else None
                    comparison_map['crash_signature_map'][engine_name] = row['crash_signature'] if row['crash_signature'] else None
                    
                    # Content maps
                    stdout_lines = row['stdout_lines'].split('\\n') if row['stdout_lines'] else []
                    stderr_lines = row['stderr_lines'].split('\\n') if row['stderr_lines'] else []
                    
                    comparison_map['stdout_content_map'][engine_name] = set(stdout_lines)
                    comparison_map['stderr_content_map'][engine_name] = set(stderr_lines)
                    
                    # Line-indexed maps
                    for i, line in enumerate(stdout_lines):
                        line_number = i + 1
                        comparison_map['stdout_map'][line_number][engine_name] = line
                    
                    for i, line in enumerate(stderr_lines):
                        line_number = i + 1
                        comparison_map['stderr_map'][line_number][engine_name] = line
                
                break  # Process only the first test group for now
                
        except Exception as e:
            print(f"Error creating comparison map for {csv_file}: {e}")
            
        return comparison_map
    
    def detect_discrepancies_quick(self, comparison_map: Dict[str, Any]) -> List[Dict]:
        """Performs O(1) discrepancy detection using map-based comparison."""
        discrepancies = []
        
        # Check status discrepancies
        statuses = set(comparison_map['status_map'].values())
        if len(statuses) > 1:
            discrepancies.append({
                'type': 'status_mismatch',
                'description': f"Different execution statuses: {' vs '.join(statuses)}",
                'engines': comparison_map['engine_names'],
                'values': list(statuses),
                'details': comparison_map['status_map']
            })
        
        # Check exit code discrepancies
        exit_codes = set(comparison_map['exit_code_map'].values())
        if len(exit_codes) > 1:
            discrepancies.append({
                'type': 'exit_code_mismatch',
                'description': f"Different exit codes: {' vs '.join(map(str, exit_codes))}",
                'engines': comparison_map['engine_names'],
                'values': list(map(str, exit_codes)),
                'details': comparison_map['exit_code_map']
            })
        
        # Check stdout content discrepancies using set operations
        stdout_sets = set(tuple(sorted(s)) for s in comparison_map['stdout_content_map'].values())
        if len(stdout_sets) > 1:
            discrepancies.append({
                'type': 'stdout_content_mismatch',
                'description': "Different stdout content between engines",
                'engines': comparison_map['engine_names'],
                'values': ['; '.join(s) for s in stdout_sets],
                'details': comparison_map['stdout_content_map']
            })
        
        # Check stderr content discrepancies using set operations
        stderr_sets = set(tuple(sorted(s)) for s in comparison_map['stderr_content_map'].values())
        if len(stderr_sets) > 1:
            discrepancies.append({
                'type': 'stderr_content_mismatch',
                'description': "Different stderr content between engines",
                'engines': comparison_map['engine_names'],
                'values': ['; '.join(s) for s in stderr_sets],
                'details': comparison_map['stderr_content_map']
            })
        
        # Check error type discrepancies
        error_types = {v for v in comparison_map['error_type_map'].values() if v is not None}
        if len(error_types) > 1:
            discrepancies.append({
                'type': 'error_type_mismatch',
                'description': f"Different error types: {' vs '.join(error_types)}",
                'engines': comparison_map['engine_names'],
                'values': list(error_types),
                'details': comparison_map['error_type_map']
            })
        
        # Check crash signature discrepancies
        crash_signatures = {v for v in comparison_map['crash_signature_map'].values() if v is not None}
        if len(crash_signatures) > 1:
            discrepancies.append({
                'type': 'crash_signature_mismatch',
                'description': f"Different crash signatures: {' vs '.join(crash_signatures)}",
                'engines': comparison_map['engine_names'],
                'values': list(crash_signatures),
                'details': comparison_map['crash_signature_map']
            })
        
        return discrepancies
    
    def find_line_differences(self, comparison_map: Dict[str, Any]) -> List[Dict]:
        """Finds specific line differences using map-based approach."""
        line_differences = []
        
        # Check stdout line differences
        for line_number, engine_lines in comparison_map['stdout_map'].items():
            unique_lines = set(engine_lines.values())
            if len(unique_lines) > 1:
                line_differences.append({
                    'stream_type': 'stdout',
                    'line_number': line_number,
                    'engine_lines': engine_lines,
                    'unique_content': list(unique_lines)
                })
        
        # Check stderr line differences
        for line_number, engine_lines in comparison_map['stderr_map'].items():
            unique_lines = set(engine_lines.values())
            if len(unique_lines) > 1:
                line_differences.append({
                    'stream_type': 'stderr',
                    'line_number': line_number,
                    'engine_lines': engine_lines,
                    'unique_content': list(unique_lines)
                })
        
        return line_differences
    
    def compare_engines(self, comparison_map: Dict[str, Any], engine1: str, engine2: str) -> Dict:
        """Compares two specific engines using map-based approach."""
        status1 = comparison_map['status_map'].get(engine1)
        status2 = comparison_map['status_map'].get(engine2)
        
        exit_code1 = comparison_map['exit_code_map'].get(engine1)
        exit_code2 = comparison_map['exit_code_map'].get(engine2)
        
        stdout1 = comparison_map['stdout_content_map'].get(engine1, set())
        stdout2 = comparison_map['stdout_content_map'].get(engine2, set())
        
        stderr1 = comparison_map['stderr_content_map'].get(engine1, set())
        stderr2 = comparison_map['stderr_content_map'].get(engine2, set())
        
        return {
            'engine1': engine1,
            'engine2': engine2,
            'status_match': status1 == status2,
            'exit_code_match': exit_code1 == exit_code2,
            'stdout_match': stdout1 == stdout2,
            'stderr_match': stderr1 == stderr2,
            'status_difference': f"{status1} vs {status2}" if status1 != status2 else None,
            'exit_code_difference': f"{exit_code1} vs {exit_code2}" if exit_code1 != exit_code2 else None,
            'stdout_difference': self._format_set_difference(stdout1, stdout2, engine1, engine2),
            'stderr_difference': self._format_set_difference(stderr1, stderr2, engine1, engine2)
        }
    
    def _format_set_difference(self, set1: Set, set2: Set, name1: str, name2: str) -> str:
        """Formats set differences for comparison output."""
        if set1 == set2:
            return None
        
        only_in_1 = set1 - set2
        only_in_2 = set2 - set1
        
        parts = []
        if only_in_1:
            parts.append(f"Only in {name1}: {', '.join(only_in_1)}")
        if only_in_2:
            parts.append(f"Only in {name2}: {', '.join(only_in_2)}")
        
        return " | ".join(parts)
    
    def analyze_all_files(self) -> Dict[str, Any]:
        """Analyzes all CSV files using map-based comparison."""
        start_time = time.time()
        all_results = {
            'total_files': len(self.csv_files),
            'total_discrepancies': 0,
            'total_line_differences': 0,
            'files_with_discrepancies': 0,
            'analysis_time': 0,
            'results': []
        }
        
        for csv_file in self.csv_files:
            # Create comparison map
            comparison_map = self.create_comparison_map(csv_file)
            if not comparison_map['test_id']:
                continue
            
            # Detect discrepancies quickly
            discrepancies = self.detect_discrepancies_quick(comparison_map)
            line_differences = self.find_line_differences(comparison_map)
            
            file_result = {
                'file': str(csv_file),
                'test_id': comparison_map['test_id'],
                'engines': comparison_map['engine_names'],
                'discrepancies': discrepancies,
                'line_differences': line_differences,
                'has_discrepancies': len(discrepancies) > 0
            }
            
            all_results['results'].append(file_result)
            all_results['total_discrepancies'] += len(discrepancies)
            all_results['total_line_differences'] += len(line_differences)
            
            if len(discrepancies) > 0:
                all_results['files_with_discrepancies'] += 1
        
        all_results['analysis_time'] = time.time() - start_time
        return all_results
    
    def print_summary(self, results: Dict[str, Any]):
        """Prints a summary of the quick analysis results."""
        print("=== QUICK DISCREPANCY ANALYSIS SUMMARY ===")
        print(f"Output directory: {self.output_dir}")
        print(f"CSV files analyzed: {results['total_files']}")
        print(f"Files with discrepancies: {results['files_with_discrepancies']}")
        print(f"Total discrepancies found: {results['total_discrepancies']}")
        print(f"Total line differences found: {results['total_line_differences']}")
        print(f"Analysis time: {results['analysis_time']:.3f} seconds")
        print()
        
        if results['total_discrepancies'] > 0:
            print("=== DISCREPANCIES BY TYPE ===")
            type_counts = defaultdict(int)
            for result in results['results']:
                for discrepancy in result['discrepancies']:
                    type_counts[discrepancy['type']] += 1
            
            for discrepancy_type, count in sorted(type_counts.items()):
                print(f"{discrepancy_type}: {count}")
            print()
            
            print("=== DETAILED DISCREPANCIES ===")
            for result in results['results']:
                if result['has_discrepancies']:
                    print(f"Test ID: {result['test_id']} ({result['file']})")
                    for discrepancy in result['discrepancies']:
                        print(f"  {discrepancy['type']}: {discrepancy['description']}")
                    print()
        else:
            print("✓ No discrepancies found - all engines produced consistent results")
    
    def export_results(self, results: Dict[str, Any], output_file: str):
        """Exports analysis results to CSV."""
        with open(output_file, 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(['test_id', 'file', 'engines', 'discrepancy_type', 'description', 'values'])
            
            for result in results['results']:
                for discrepancy in result['discrepancies']:
                    writer.writerow([
                        result['test_id'],
                        result['file'],
                        ', '.join(result['engines']),
                        discrepancy['type'],
                        discrepancy['description'],
                        '; '.join(discrepancy['values'])
                    ])
        
        print(f"Exported {results['total_discrepancies']} discrepancies to {output_file}")


def main():
    parser = argparse.ArgumentParser(description="Quick discrepancy analyzer using map-based comparison")
    parser.add_argument("output_dir", help="Directory containing standardized output CSV files")
    parser.add_argument("--export", help="Export results to CSV file")
    parser.add_argument("--compare", nargs=2, metavar=("ENGINE1", "ENGINE2"), 
                       help="Compare two specific engines")
    parser.add_argument("--benchmark", action="store_true", help="Run performance benchmark")
    
    args = parser.parse_args()
    
    if not os.path.exists(args.output_dir):
        print(f"Error: Output directory '{args.output_dir}' does not exist")
        sys.exit(1)
    
    analyzer = QuickDiscrepancyAnalyzer(args.output_dir)
    
    if args.benchmark:
        # Run performance benchmark
        print("Running performance benchmark...")
        start_time = time.time()
        results = analyzer.analyze_all_files()
        end_time = time.time()
        
        print(f"Benchmark results:")
        print(f"  Files processed: {results['total_files']}")
        print(f"  Total time: {end_time - start_time:.3f} seconds")
        print(f"  Average time per file: {(end_time - start_time) / max(1, results['total_files']):.3f} seconds")
        print(f"  Discrepancies found: {results['total_discrepancies']}")
        return
    
    # Run analysis
    results = analyzer.analyze_all_files()
    analyzer.print_summary(results)
    
    if args.export:
        analyzer.export_results(results, args.export)
    
    if args.compare:
        engine1, engine2 = args.compare
        print(f"\n=== COMPARISON: {engine1} vs {engine2} ===")
        
        # Find a file with both engines
        for result in results['results']:
            if engine1 in result['engines'] and engine2 in result['engines']:
                comparison_map = analyzer.create_comparison_map(Path(result['file']))
                comparison = analyzer.compare_engines(comparison_map, engine1, engine2)
                
                print(f"Test ID: {result['test_id']}")
                print(f"Status match: {comparison['status_match']}")
                print(f"Exit code match: {comparison['exit_code_match']}")
                print(f"STDOUT match: {comparison['stdout_match']}")
                print(f"STDERR match: {comparison['stderr_match']}")
                
                if comparison['status_difference']:
                    print(f"Status difference: {comparison['status_difference']}")
                if comparison['exit_code_difference']:
                    print(f"Exit code difference: {comparison['exit_code_difference']}")
                if comparison['stdout_difference']:
                    print(f"STDOUT difference: {comparison['stdout_difference']}")
                if comparison['stderr_difference']:
                    print(f"STDERR difference: {comparison['stderr_difference']}")
                break
        else:
            print(f"No files found with both {engine1} and {engine2}")


if __name__ == "__main__":
    main()
