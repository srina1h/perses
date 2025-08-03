#!/usr/bin/env python3
"""
Main entry point for JavaScript Differential Testing Error Reduction Framework

This script provides a command-line interface to process, classify, deduplicate,
and reduce differential testing findings.
"""

import argparse
import json
import sys
from pathlib import Path
from typing import List, Dict, Tuple
from tqdm import tqdm

from finding_parser import parse_multiple_findings, parse_findings_by_type, DifferentialFinding, FindingType
from error_classifier import ErrorClassifier, ClassifiedError
from reducer import DifferentialReducer, ReductionResult
from semantic_enhancement import SemanticErrorAnalyzer, EnhancedErrorClassifier, SemanticReducer


def main():
    """Main entry point."""
    parser = argparse.ArgumentParser(
        description="JavaScript Differential Testing Error Reduction Framework"
    )
    
    parser.add_argument(
        "--input-dir",
        type=str,
        required=True,
        help="Directory containing differential findings"
    )
    
    parser.add_argument(
        "--output-dir",
        type=str,
        default="reduced_findings",
        help="Output directory for reduced findings (default: reduced_findings)"
    )
    
    parser.add_argument(
        "--finding-path",
        type=str,
        help="Process a specific finding folder"
    )
    
    parser.add_argument(
        "--report-only",
        action="store_true",
        help="Generate report only, skip reduction"
    )
    
    parser.add_argument(
        "--similarity-threshold",
        type=float,
        default=0.8,
        help="Similarity threshold for error grouping (default: 0.8)"
    )
    
    parser.add_argument(
        "--engines",
        type=str,
        nargs="+",
        default=["graaljs", "hermes", "v8"],
        help="JavaScript engines to consider (default: graaljs hermes v8)"
    )
    
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="Enable verbose output"
    )
    
    parser.add_argument(
        "--semantic",
        action="store_true",
        help="Enable semantic similarity analysis and clustering"
    )
    
    parser.add_argument(
        "--semantic-threshold",
        type=float,
        default=0.8,
        help="Semantic similarity threshold for clustering (default: 0.8)"
    )
    
    parser.add_argument(
        "--cluster-eps",
        type=float,
        default=0.3,
        help="DBSCAN epsilon parameter for clustering (default: 0.3)"
    )
    
    parser.add_argument(
        "--max-findings",
        type=int,
        default=None,
        help="Maximum number of findings to process (for large datasets)"
    )
    
    parser.add_argument(
        "--sample-size",
        type=int,
        default=None,
        help="Sample size for semantic analysis (for large datasets)"
    )
    
    parser.add_argument(
        "--skip-semantic",
        action="store_true",
        help="Skip semantic analysis for faster processing"
    )
    
    args = parser.parse_args()
    
    try:
        if args.finding_path:
            # Process a single finding
            process_single_finding(args)
        else:
            # Process multiple findings
            process_multiple_findings(args)
            
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)


def process_single_finding(args):
    """Process a single finding."""
    print(f"Processing finding: {args.finding_path}")
    
    # Parse the finding
    from finding_parser import parse_finding_folder
    finding = parse_finding_folder(args.finding_path)
    
    # Classify the error
    if args.semantic:
        print("Using semantic-enhanced classification...")
        classifier = EnhancedErrorClassifier()
        classified_error = classifier.classify_with_semantic_similarity([finding])[0]
    else:
        classifier = ErrorClassifier()
        classified_error = classifier.classify_finding(finding)
    
    print(f"Error Category: {classified_error.signature.category.value}")
    print(f"Error Severity: {classified_error.signature.severity.value}")
    print(f"Confidence: {classified_error.confidence:.2f}")
    
    if args.semantic and hasattr(classified_error, 'semantic_metadata'):
        print(f"Semantic Cluster ID: {classified_error.semantic_metadata.get('cluster_id', 'N/A')}")
        print(f"Semantic Confidence: {classified_error.semantic_metadata.get('semantic_confidence', 0):.2f}")
    
    if not args.report_only:
        # Reduce the finding
        reducer = DifferentialReducer(args.engines)
        result = reducer.reduce_finding(finding, args.output_dir)
        
        print(f"Reduction Results:")
        print(f"  Original size: {result.original_size}")
        print(f"  Reduced size: {result.reduced_size}")
        print(f"  Reduction ratio: {result.reduction_ratio:.2%}")
        print(f"  Bug preserved: {result.preserved_bug}")
        print(f"  Reduction steps: {result.reduction_steps}")


def process_multiple_findings(args):
    """Process multiple findings."""
    input_dir = Path(args.input_dir)
    output_dir = Path(args.output_dir)
    
    if not input_dir.exists():
        print(f"Error: Input directory does not exist: {input_dir}")
        sys.exit(1)
    
    print(f"Scanning for findings in: {input_dir}")
    
    # Parse findings by type
    findings_by_type = parse_findings_by_type(str(input_dir))
    
    crashes = findings_by_type[FindingType.CRASH]
    differential_findings = findings_by_type[FindingType.DIFFERENTIAL]
    unknown_findings = findings_by_type[FindingType.UNKNOWN]
    
    print(f"Found {len(crashes)} crashes, {len(differential_findings)} differential findings, {len(unknown_findings)} unknown")
    
    # Handle large datasets
    if args.max_findings:
        if len(differential_findings) > args.max_findings:
            print(f"Limiting to {args.max_findings} differential findings (random sample)")
            import random
            random.seed(42)  # For reproducibility
            differential_findings = random.sample(differential_findings, args.max_findings)
    
    if not crashes and not differential_findings:
        print("No valid findings to process")
        return
    
    # Process crashes and differential findings separately
    all_classified_errors = []
    all_error_groups = []
    
    # Process crashes
    if crashes:
        print(f"\nProcessing {len(crashes)} crashes...")
        crash_errors, crash_groups = process_finding_type(crashes, "crashes", args)
        all_classified_errors.extend(crash_errors)
        all_error_groups.extend(crash_groups)
    
    # Process differential findings
    if differential_findings:
        print(f"\nProcessing {len(differential_findings)} differential findings...")
        diff_errors, diff_groups = process_finding_type(differential_findings, "differential findings", args)
        all_classified_errors.extend(diff_errors)
        all_error_groups.extend(diff_groups)
    
    # Process unknown findings if any
    if unknown_findings:
        print(f"\nProcessing {len(unknown_findings)} unknown findings...")
        unknown_errors, unknown_groups = process_finding_type(unknown_findings, "unknown findings", args)
        all_classified_errors.extend(unknown_errors)
        all_error_groups.extend(unknown_groups)
    
    # Generate summary report
    generate_summary_report(all_classified_errors, all_error_groups, output_dir, args.semantic)
    
    if args.report_only:
        print("Report-only mode: skipping reduction")
        return
    
    # Reduce findings
    print("Reducing findings...")
    reducer = DifferentialReducer(args.engines)
    
    # Create output directory
    output_dir.mkdir(parents=True, exist_ok=True)
    
    # Process each error group
    for i, group in enumerate(tqdm(error_groups, desc="Processing error groups")):
        group_dir = output_dir / f"group_{i:03d}"
        group_dir.mkdir(exist_ok=True)
        
        # Save group information
        save_group_info(group, group_dir)
        
        # Save semantic metadata if available
        if args.semantic:
            save_semantic_metadata(group, group_dir)
        
        # Reduce representative finding from each group
        if group:
            representative = select_representative_finding(group)
            try:
                result = reducer.reduce_finding(representative.finding, group_dir)
                save_reduction_result(result, group_dir)
            except Exception as e:
                print(f"Warning: Failed to reduce finding {representative.finding.finding_path}: {e}")
    
    print(f"Processing complete. Results saved to: {output_dir}")


def generate_summary_report(classified_errors: List[ClassifiedError], 
                          error_groups: List[List[ClassifiedError]], 
                          output_dir: Path, use_semantic: bool = False):
    """Generate a summary report of the findings."""
    report = {
        "total_findings": len(classified_errors),
        "unique_error_groups": len(error_groups),
        "error_categories": {},
        "error_severities": {},
        "engine_combinations": {},
        "reduction_potential": {},
        "analysis_method": "semantic_enhanced" if use_semantic else "pattern_based",
        "findings_by_type": {
            "crashes": 0,
            "differential_findings": 0,
            "unknown": 0
        }
    }
    
    # Count by category
    for error in classified_errors:
        category = error.signature.category.value
        report["error_categories"][category] = report["error_categories"].get(category, 0) + 1
    
    # Count by severity
    for error in classified_errors:
        severity = error.signature.severity.value
        report["error_severities"][severity] = report["error_severities"].get(severity, 0) + 1
    
    # Count by engine combination
    for error in classified_errors:
        engines = "_".join(error.signature.engine_combination)
        report["engine_combinations"][engines] = report["engine_combinations"].get(engines, 0) + 1
    
    # Count by finding type
    for error in classified_errors:
        finding_type = error.finding.finding_type.value
        if finding_type == "crash":
            report["findings_by_type"]["crashes"] += 1
        elif finding_type == "differential":
            report["findings_by_type"]["differential_findings"] += 1
        else:
            report["findings_by_type"]["unknown"] += 1
    
    # Estimate reduction potential
    total_size = sum(len(error.finding.input_js) for error in classified_errors)
    report["reduction_potential"]["total_input_size"] = total_size
    report["reduction_potential"]["average_input_size"] = total_size / len(classified_errors) if classified_errors else 0
    
    # Save report
    output_dir.mkdir(parents=True, exist_ok=True)
    report_file = output_dir / "summary_report.json"
    
    with open(report_file, 'w') as f:
        json.dump(report, f, indent=2)
    
    # Print summary
    print("\n=== SUMMARY REPORT ===")
    print(f"Analysis method: {report['analysis_method']}")
    print(f"Total findings: {report['total_findings']}")
    print(f"Unique error groups: {report['unique_error_groups']}")
    print(f"Average input size: {report['reduction_potential']['average_input_size']:.0f} characters")
    
    print(f"\nFindings by type:")
    print(f"  Crashes: {report['findings_by_type']['crashes']}")
    print(f"  Differential findings: {report['findings_by_type']['differential_findings']}")
    print(f"  Unknown: {report['findings_by_type']['unknown']}")
    
    print("\nError categories:")
    for category, count in sorted(report["error_categories"].items()):
        print(f"  {category}: {count}")
    
    print("\nError severities:")
    for severity, count in sorted(report["error_severities"].items()):
        print(f"  {severity}: {count}")
    
    print(f"\nDetailed report saved to: {report_file}")


def select_representative_finding(group: List[ClassifiedError]) -> ClassifiedError:
    """Select a representative finding from a group."""
    # Select the finding with the highest confidence
    return max(group, key=lambda x: x.confidence)


def save_group_info(group: List[ClassifiedError], group_dir: Path):
    """Save information about an error group."""
    if not group:
        return
    
    representative = group[0]
    
    group_info = {
        "size": len(group),
        "category": representative.signature.category.value,
        "severity": representative.signature.severity.value,
        "engine_combination": list(representative.signature.engine_combination),
        "error_pattern": representative.signature.error_pattern,
        "normalized_message": representative.signature.normalized_message,
        "findings": [
            {
                "path": str(error.finding.finding_path),
                "confidence": error.confidence,
                "input_size": len(error.finding.input_js)
            }
            for error in group
        ]
    }
    
    with open(group_dir / "group_info.json", 'w') as f:
        json.dump(group_info, f, indent=2)


def save_reduction_result(result: ReductionResult, group_dir: Path):
    """Save reduction result information."""
    result_info = {
        "original_size": result.original_size,
        "reduced_size": result.reduced_size,
        "reduction_ratio": result.reduction_ratio,
        "preserved_bug": result.preserved_bug,
        "reduction_steps": result.reduction_steps
    }
    
    with open(group_dir / "reduction_result.json", 'w') as f:
        json.dump(result_info, f, indent=2)


def save_semantic_metadata(group: List[ClassifiedError], group_dir: Path):
    """Save semantic analysis metadata for a group."""
    if not group:
        return
    
    semantic_metadata = {
        "group_size": len(group),
        "semantic_confidence_scores": [],
        "cluster_information": {}
    }
    
    for error in group:
        if hasattr(error, 'semantic_metadata'):
            semantic_metadata["semantic_confidence_scores"].append(
                error.semantic_metadata.get('semantic_confidence', 0)
            )
            semantic_metadata["cluster_information"] = {
                "cluster_id": error.semantic_metadata.get('cluster_id', -1)
            }
    
    if semantic_metadata["semantic_confidence_scores"]:
        semantic_metadata["average_semantic_confidence"] = sum(
            semantic_metadata["semantic_confidence_scores"]
        ) / len(semantic_metadata["semantic_confidence_scores"])
    
    with open(group_dir / "semantic_metadata.json", 'w') as f:
        json.dump(semantic_metadata, f, indent=2)


def process_finding_type(findings: List[DifferentialFinding], finding_type_name: str, args) -> Tuple[List[ClassifiedError], List[List[ClassifiedError]]]:
    """Process a specific type of findings (crashes or differential findings)."""
    print(f"Classifying {finding_type_name}...")
    
    # Handle large datasets for semantic analysis
    if args.semantic and args.sample_size and len(findings) > args.sample_size:
        print(f"Sampling {args.sample_size} findings for semantic analysis (from {len(findings)})")
        import random
        random.seed(42)  # For reproducibility
        sampled_findings = random.sample(findings, args.sample_size)
    else:
        sampled_findings = findings
    
    if args.semantic and not args.skip_semantic:
        print(f"Using semantic-enhanced classification for {finding_type_name}...")
        print(f"  Processing {len(sampled_findings)} findings...")
        
        classifier = EnhancedErrorClassifier()
        classified_errors = classifier.classify_with_semantic_similarity(sampled_findings)
        
        print(f"  Performing semantic clustering...")
        # Use semantic clustering
        semantic_analyzer = SemanticErrorAnalyzer()
        semantic_clusters = semantic_analyzer.cluster_findings_semantically(
            sampled_findings, eps=args.cluster_eps
        )
        
        print(f"  Converting clusters to error groups...")
        # Convert semantic clusters to error groups
        error_groups = []
        for cluster in semantic_clusters:
            if cluster:  # Skip empty clusters
                group = [classified_errors[i] for i in cluster]
                error_groups.append(group)
        
        print(f"Semantic clustering found {len(error_groups)} groups for {finding_type_name}")
        
        print(f"  Computing semantic reduction...")
        # Also perform semantic reduction
        semantic_reducer = SemanticReducer()
        semantic_result = semantic_reducer.reduce_with_semantic_grouping(
            sampled_findings, args.semantic_threshold
        )
        print(f"Semantic reduction ratio for {finding_type_name}: {semantic_result['reduction_ratio']:.2%}")
        
    else:
        # Use pattern-based classification for all findings
        print(f"Using pattern-based classification for {finding_type_name}...")
        classifier = ErrorClassifier()
        classified_errors = classifier.classify_findings(findings)
        
        # Group similar errors
        print(f"Grouping similar {finding_type_name}...")
        error_groups = classifier.group_similar_errors(
            classified_errors, 
            args.similarity_threshold
        )
        print(f"Found {len(error_groups)} groups for {finding_type_name}")
    
    return classified_errors, error_groups


if __name__ == "__main__":
    main() 