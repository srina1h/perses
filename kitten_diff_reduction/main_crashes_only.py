#!/usr/bin/env python3
"""
Main Script for Crash Analysis Only

This script processes only crash findings using fast pattern matching.
No semantic analysis, no differential findings processing.
"""

import argparse
import sys
import time
from pathlib import Path
from finding_parser import FindingParser, FindingType
from crash_analyzer import CrashAnalyzer


def main():
    """Main function for crash-only analysis."""
    parser = argparse.ArgumentParser(
        description="Analyze crash findings from JavaScript differential testing",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Analyze crashes in a directory
  python main_crashes_only.py --input-dir ../results/differential_findings_javascript
  
  # Analyze with custom output
  python main_crashes_only.py --input-dir ../results/differential_findings_javascript --output-dir crash_results
        """
    )
    
    parser.add_argument(
        '--input-dir',
        required=True,
        help='Directory containing crash findings'
    )
    
    parser.add_argument(
        '--output-dir',
        default='crash_analysis_output',
        help='Output directory for results (default: crash_analysis_output)'
    )
    
    parser.add_argument(
        '--max-crashes',
        type=int,
        help='Maximum number of crashes to process (for testing)'
    )
    
    args = parser.parse_args()
    
    # Validate input directory
    input_path = Path(args.input_dir)
    if not input_path.exists():
        print(f"Error: Input directory '{args.input_dir}' does not exist")
        sys.exit(1)
    
    print(f"Starting crash analysis...")
    print(f"Input directory: {args.input_dir}")
    print(f"Output directory: {args.output_dir}")
    print("=" * 60)
    
    try:
        # Parse findings
        print("Parsing findings...")
        start_time = time.time()
        
        from finding_parser import parse_multiple_findings
        all_findings = parse_multiple_findings(args.input_dir)
        
        parse_time = time.time() - start_time
        print(f"Parsing completed in {parse_time:.2f} seconds")
        print(f"Total findings found: {len(all_findings)}")
        
        # Filter for crashes only
        print("Filtering for crashes...")
        crash_findings = [f for f in all_findings if f.finding_type == FindingType.CRASH]
        print(f"Found {len(crash_findings)} crash findings")
        
        # Limit if requested
        if args.max_crashes and len(crash_findings) > args.max_crashes:
            print(f"Limiting to {args.max_crashes} crashes (random sample)")
            import random
            random.seed(42)
            crash_findings = random.sample(crash_findings, args.max_crashes)
        
        if not crash_findings:
            print("No crash findings found!")
            return
        
        # Analyze crashes
        print(f"Analyzing {len(crash_findings)} crashes...")
        analysis_start = time.time()
        
        analyzer = CrashAnalyzer()
        crash_groups = analyzer.analyze_crashes(crash_findings)
        
        analysis_time = time.time() - analysis_start
        print(f"Crash analysis completed in {analysis_time:.2f} seconds")
        
        # Generate summary
        print("Generating summary...")
        summary_start = time.time()
        summary = analyzer.generate_crash_summary(crash_groups)
        summary_time = time.time() - summary_start
        print(f"Summary generation completed in {summary_time:.2f} seconds")
        
        # Create output directory
        print(f"Creating output directory: {args.output_dir}")
        output_path = Path(args.output_dir)
        output_path.mkdir(exist_ok=True)
        
        # Save detailed results
        print("Saving detailed results...")
        save_start = time.time()
        save_detailed_results(crash_groups, output_path)
        save_time = time.time() - save_start
        print(f"Detailed results saved in {save_time:.2f} seconds")
        
        # Save summary
        print("Saving summary report...")
        summary_save_start = time.time()
        save_summary_report(summary, crash_groups, output_path)
        summary_save_time = time.time() - summary_save_start
        print(f"Summary report saved in {summary_save_time:.2f} seconds")
        
        # Print summary
        print_summary(summary, crash_groups)
        
        total_time = time.time() - start_time
        print(f"\n" + "=" * 60)
        print(f"TOTAL EXECUTION TIME: {total_time:.2f} seconds")
        print(f"Analysis complete! Results saved to: {args.output_dir}")
        print("=" * 60)
        
    except Exception as e:
        print(f"Error during analysis: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


def save_detailed_results(crash_groups, output_path):
    """Save detailed crash analysis results."""
    # Save all groups
    with open(output_path / "crash_groups_detailed.txt", 'w') as f:
        f.write("DETAILED CRASH ANALYSIS\n")
        f.write("=" * 50 + "\n\n")
        
        for i, group in enumerate(crash_groups):
            f.write(f"GROUP {i+1}: {group.crash_type} ({group.count} crashes)\n")
            f.write("-" * 40 + "\n")
            f.write(f"Error Pattern: {group.signature.error_pattern}\n")
            f.write(f"Exit Code: {group.signature.exit_code}\n")
            f.write(f"Engines: {group.signature.engine_combination}\n")
            f.write(f"Hash: {group.signature.hash}\n")
            f.write(f"Representative: {group.representative.finding_path.name}\n\n")
            
            f.write("All findings in this group:\n")
            for j, finding in enumerate(group.findings[:10]):  # Show first 10
                f.write(f"  {j+1}. {finding.finding_path.name}\n")
            if len(group.findings) > 10:
                f.write(f"  ... and {len(group.findings) - 10} more\n")
            f.write("\n" + "=" * 50 + "\n\n")


def save_summary_report(summary, crash_groups, output_path):
    """Save summary report."""
    with open(output_path / "crash_summary.txt", 'w') as f:
        f.write("CRASH ANALYSIS SUMMARY\n")
        f.write("=" * 30 + "\n\n")
        
        f.write(f"Total crashes analyzed: {summary['total_crashes']}\n")
        f.write(f"Unique crash types: {summary['unique_crash_types']}\n")
        f.write(f"Crash groups created: {summary['crash_groups']}\n")
        f.write(f"Reduction ratio: {summary['reduction_ratio']:.2%}\n\n")
        
        f.write("CRASH TYPE BREAKDOWN:\n")
        f.write("-" * 25 + "\n")
        for crash_type, count in summary['crash_types'].items():
            f.write(f"{crash_type}: {count} crashes\n")
        
        f.write(f"\nTOP 10 CRASH GROUPS:\n")
        f.write("-" * 20 + "\n")
        for i, group in enumerate(summary['top_groups'][:10]):
            f.write(f"{i+1}. {group['crash_type']} ({group['count']} crashes)\n")
            f.write(f"   Pattern: {group['error_pattern']}\n")
            f.write(f"   Representative: {group['representative_path']}\n\n")


def print_summary(summary, crash_groups):
    """Print summary to console."""
    print("\n" + "=" * 60)
    print("CRASH ANALYSIS SUMMARY")
    print("=" * 60)
    
    print(f"Total crashes analyzed: {summary['total_crashes']}")
    print(f"Unique crash types: {summary['unique_crash_types']}")
    print(f"Crash groups created: {summary['crash_groups']}")
    print(f"Reduction ratio: {summary['reduction_ratio']:.2%}")
    
    print(f"\nCrash type breakdown:")
    for crash_type, count in summary['crash_types'].items():
        print(f"  {crash_type}: {count} crashes")
    
    print(f"\nTop 5 crash groups:")
    for i, group in enumerate(summary['top_groups'][:5]):
        print(f"  {i+1}. {group['crash_type']} ({group['count']} crashes)")
        print(f"     Pattern: {group['error_pattern']}")


if __name__ == "__main__":
    main() 