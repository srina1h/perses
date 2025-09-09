#!/usr/bin/env python3
"""
Simple Summary Script for Differential Findings

This script provides a quick summary of the key findings from the differential analysis.
"""

import json
import sys
from pathlib import Path

def load_report(report_file="differential_analysis_report.json"):
    """Load the analysis report."""
    try:
        with open(report_file, 'r') as f:
            return json.load(f)
    except FileNotFoundError:
        print(f"Report file {report_file} not found. Run reduce.py first.")
        return None

def print_summary(report):
    """Print a clean summary of the findings."""
    if not report:
        return
    
    print("🔍 DIFFERENTIAL FINDINGS SUMMARY")
    print("=" * 50)
    
    # Basic stats
    basic = report.get('basic_stats', {})
    print(f"\n📊 OVERVIEW:")
    print(f"   Total findings: {basic.get('total_findings', 0):,}")
    print(f"   Total records: {basic.get('total_records', 0):,}")
    print(f"   Engines tested: {', '.join(basic.get('engines', []))}")
    
    # Engine performance
    print(f"\n🏆 ENGINE PERFORMANCE:")
    engine_stats = basic.get('engine_stats', {})
    for engine, stats in engine_stats.items():
        total = stats['total_runs']
        success = stats['success_count']
        success_rate = (success / total * 100) if total > 0 else 0
        print(f"   {engine:12}: {success:3}/{total:3} ({success_rate:5.1f}% success)")
    
    # Status distribution
    print(f"\n📈 STATUS BREAKDOWN:")
    status_counts = basic.get('status_counts', {})
    success_count = status_counts.get('SUCCESS', 0)
    error_count = status_counts.get('ERROR', 0)
    total_status = sum(status_counts.values())
    if total_status > 0:
        print(f"   SUCCESS: {success_count:,} ({success_count/total_status*100:.1f}%)")
        print(f"   ERROR:   {error_count:,} ({error_count/total_status*100:.1f}%)")
        print(f"   OTHER:   {total_status-success_count-error_count:,} ({(total_status-success_count-error_count)/total_status*100:.1f}%)")
    
    # Differential behavior
    diff_stats = report.get('differential_behavior', {})
    print(f"\n🔍 DIFFERENTIAL BEHAVIOR:")
    print(f"   Total differential cases: {diff_stats.get('total_differential_cases', 0):,}")
    print(f"   Cases with stdout differences: {diff_stats.get('cases_with_stdout_diff', 0):,}")
    
    # Error analysis
    crash_analysis = report.get('crash_analysis', {})
    print(f"\n💥 ERROR ANALYSIS:")
    print(f"   Total errors: {crash_analysis.get('total_errors', 0):,}")
    
    error_types = crash_analysis.get('error_types', {})
    if error_types:
        print(f"   Top error types:")
        sorted_errors = sorted(error_types.items(), key=lambda x: x[1], reverse=True)
        for error_type, count in sorted_errors[:5]:
            print(f"     {error_type}: {count:,}")
    
    # Key insights
    print(f"\n💡 KEY INSIGHTS:")
    
    # Find the most successful and least successful engines
    if engine_stats:
        best_engine = max(engine_stats.items(), key=lambda x: x[1]['success_count']/x[1]['total_runs'])
        worst_engine = min(engine_stats.items(), key=lambda x: x[1]['success_count']/x[1]['total_runs'])
        
        best_rate = (best_engine[1]['success_count'] / best_engine[1]['total_runs'] * 100)
        worst_rate = (worst_engine[1]['success_count'] / worst_engine[1]['total_runs'] * 100)
        
        print(f"   Most successful: {best_engine[0]} ({best_rate:.1f}% success)")
        print(f"   Least successful: {worst_engine[0]} ({worst_rate:.1f}% success)")
        print(f"   Success rate gap: {best_rate - worst_rate:.1f} percentage points")
    
    # Differential behavior insights
    diff_cases = diff_stats.get('total_differential_cases', 0)
    total_findings = basic.get('total_findings', 0)
    if total_findings > 0:
        diff_percentage = (diff_cases / total_findings * 100)
        print(f"   {diff_percentage:.1f}% of findings show differential behavior between engines")

def main():
    report_file = sys.argv[1] if len(sys.argv) > 1 else "differential_analysis_report.json"
    report = load_report(report_file)
    print_summary(report)

if __name__ == "__main__":
    main()
