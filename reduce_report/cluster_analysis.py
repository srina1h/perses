#!/usr/bin/env python3
"""
TF-IDF Clustering Analysis

This script analyzes clustering within each exit code pattern using TF-IDF.
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
    
    # Analyze clustering
    print("\n🔍 TF-IDF CLUSTERING ANALYSIS")
    print("=" * 50)
    
    pattern_clusters = analyzer.analyze_pattern_clusters()
    
    if not pattern_clusters:
        print("No clustering results found.")
        return
    
    print(f"\n📊 OVERVIEW:")
    print(f"   Total patterns: {pattern_clusters['total_patterns']}")
    print(f"   Total clusters: {pattern_clusters['total_clusters']}")
    
    # Get exit patterns for reference
    exit_patterns = analyzer.analyze_exit_code_patterns()
    pattern_counts = exit_patterns['pattern_counts']
    sorted_patterns = sorted(pattern_counts.items(), key=lambda x: x[1], reverse=True)
    
    print(f"\n🎯 CLUSTERING RESULTS BY PATTERN:")
    print(f"   {'Pattern':<15} {'Cases':<8} {'Clusters':<10} {'Cluster Sizes'}")
    print(f"   {'-'*15} {'-'*8} {'-'*10} {'-'*20}")
    
    total_cases = 0
    total_clusters = 0
    
    for pattern, count in sorted_patterns:
        if pattern in pattern_clusters['pattern_clusters']:
            cluster_info = pattern_clusters['pattern_clusters'][pattern]
            n_clusters = cluster_info['n_clusters']
            
            # Format cluster sizes
            if n_clusters > 1:
                cluster_sizes = cluster_info['cluster_sizes']
                sizes_str = str(cluster_sizes)
            else:
                sizes_str = f"[{count}]"
            
            print(f"   {pattern:<15} {count:<8} {n_clusters:<10} {sizes_str}")
            
            total_cases += count
            total_clusters += n_clusters
    
    print(f"\n💡 SUMMARY:")
    print(f"   Total cases analyzed: {total_cases}")
    print(f"   Total clusters found: {total_clusters}")
    print(f"   Average clusters per pattern: {total_clusters / len(sorted_patterns):.1f}")
    
    # Show patterns with multiple clusters
    print(f"\n🔍 PATTERNS WITH MULTIPLE CLUSTERS:")
    multi_cluster_patterns = []
    for pattern, count in sorted_patterns:
        if pattern in pattern_clusters['pattern_clusters']:
            cluster_info = pattern_clusters['pattern_clusters'][pattern]
            if cluster_info['n_clusters'] > 1:
                multi_cluster_patterns.append((pattern, count, cluster_info))
    
    if multi_cluster_patterns:
        for pattern, count, cluster_info in multi_cluster_patterns[:10]:  # Show top 10
            print(f"   {pattern}: {cluster_info['n_clusters']} clusters")
            print(f"     Cluster sizes: {cluster_info['cluster_sizes']}")
    else:
        print("   No patterns with multiple clusters found.")

if __name__ == "__main__":
    main()
