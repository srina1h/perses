#!/usr/bin/env python3
"""
Differential Findings Analysis Script

This script analyzes differential findings by loading standardized CSV files
from finding folders and generating statistics about the differences between
JavaScript engines.
"""

import os
import pandas as pd
import glob
from pathlib import Path
from collections import defaultdict, Counter
import json
import argparse
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import KMeans
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np


class DifferentialFindingsAnalyzer:
    def __init__(self, findings_dir):
        """
        Initialize the analyzer with the directory containing finding folders.
        
        Args:
            findings_dir: Path to the directory containing differential finding folders
        """
        self.findings_dir = Path(findings_dir)
        self.csv_files = []
        self.all_data = []
        self.stats = {}
        
    def discover_csv_files(self):
        """
        Discover all standardized_output.csv files in the findings directory.
        
        Returns:
            List of paths to CSV files
        """
        pattern = str(self.findings_dir / "differential_finding_*" / "standardized_output.csv")
        self.csv_files = [Path(f) for f in glob.glob(pattern)]
        print(f"Found {len(self.csv_files)} CSV files")
        return self.csv_files
    
    def load_csv_data(self, csv_path):
        """
        Load and parse a single CSV file.
        
        Args:
            csv_path: Path to the CSV file
            
        Returns:
            DataFrame with the CSV data
        """
        try:
            # Try with different CSV parsing options to handle malformed files
            df = pd.read_csv(csv_path, quoting=3, escapechar='\\', on_bad_lines='skip')
            # Add metadata about the finding
            df['finding_folder'] = csv_path.parent.name
            df['csv_file'] = str(csv_path)
            return df
        except Exception as e:
            try:
                # Fallback: try with different quoting
                df = pd.read_csv(csv_path, quoting=1, on_bad_lines='skip')
                df['finding_folder'] = csv_path.parent.name
                df['csv_file'] = str(csv_path)
                return df
            except Exception as e2:
                print(f"Error loading {csv_path}: {e2}")
                return pd.DataFrame()
    
    def load_all_data(self):
        """
        Load all CSV files and combine them into a single DataFrame.
        
        Returns:
            Combined DataFrame with all findings data
        """
        if not self.csv_files:
            self.discover_csv_files()
        
        all_dfs = []
        for csv_file in self.csv_files:
            df = self.load_csv_data(csv_file)
            if not df.empty:
                all_dfs.append(df)
        
        if all_dfs:
            self.all_data = pd.concat(all_dfs, ignore_index=True)
            print(f"Loaded {len(self.all_data)} total records from {len(all_dfs)} CSV files")
        else:
            self.all_data = pd.DataFrame()
            print("No data loaded")
        
        return self.all_data
    
    def generate_basic_stats(self):
        """
        Generate basic statistics about the findings.
        
        Returns:
            Dictionary with basic statistics
        """
        if self.all_data.empty:
            return {}
        
        # Clean data and handle mixed types - focus on main engines
        main_engines = ['V8', 'SpiderMonkey', 'JavaScriptCore', 'GraalJS']
        engine_names = self.all_data['engine_name'].dropna().unique()
        engine_names = [str(x).strip() for x in engine_names if pd.notna(x)]
        
        # Filter to only main engines
        valid_engines = [eng for eng in engine_names if eng in main_engines]
        
        stats = {
            'total_findings': len(self.all_data['test_id'].unique()),
            'total_records': len(self.all_data),
            'engines': sorted(valid_engines),
            'status_counts': self.all_data['status'].value_counts().to_dict(),
            'exit_code_counts': self.all_data['exit_code'].value_counts().to_dict(),
            'error_type_counts': self.all_data['error_type'].value_counts().to_dict(),
            'findings_per_folder': self.all_data['finding_folder'].value_counts().to_dict()
        }
        
        # Engine-specific stats
        engine_stats = {}
        for engine in stats['engines']:
            engine_data = self.all_data[self.all_data['engine_name'].astype(str).str.strip() == engine]
            engine_stats[engine] = {
                'total_runs': len(engine_data),
                'success_count': len(engine_data[engine_data['status'] == 'SUCCESS']),
                'error_count': len(engine_data[engine_data['status'] == 'ERROR']),
                'exit_codes': engine_data['exit_code'].value_counts().to_dict(),
                'error_types': engine_data['error_type'].value_counts().to_dict()
            }
        stats['engine_stats'] = engine_stats
        
        self.stats = stats
        return stats
    
    def find_differential_behavior(self):
        """
        Find cases where engines behave differently for the same test.
        
        Returns:
            Dictionary with differential behavior analysis
        """
        if self.all_data.empty:
            return {}
        
        differential_cases = []
        
        # Group by test_id to find differences
        for test_id, group in self.all_data.groupby('test_id'):
            # Filter to only main engines
            main_engines = ['V8', 'SpiderMonkey', 'JavaScriptCore', 'GraalJS']
            engine_names = group['engine_name'].astype(str).str.strip()
            valid_engines = engine_names[engine_names.isin(main_engines)]
            
            if len(valid_engines.unique()) > 1:  # Multiple engines tested
                # Check if there are differences in status, exit_code, or stdout
                statuses = group['status'].unique()
                exit_codes = group['exit_code'].unique()
                stdout_values = group['stdout_lines'].unique()
                
                if len(statuses) > 1 or len(exit_codes) > 1 or len(stdout_values) > 1:
                    differential_cases.append({
                        'test_id': test_id,
                        'finding_folder': group['finding_folder'].iloc[0],
                        'engines': valid_engines.tolist(),
                        'statuses': statuses.tolist(),
                        'exit_codes': exit_codes.tolist(),
                        'stdout_different': len(stdout_values) > 1,
                        'details': group[['engine_name', 'status', 'exit_code', 'stdout_lines', 'stderr_lines']].to_dict('records')
                    })
        
        differential_stats = {
            'total_differential_cases': len(differential_cases),
            'cases_by_status_diff': Counter([len(case['statuses']) for case in differential_cases]),
            'cases_by_exit_code_diff': Counter([len(case['exit_codes']) for case in differential_cases]),
            'cases_with_stdout_diff': len([c for c in differential_cases if c['stdout_different']]),
            'differential_cases': differential_cases
        }
        
        return differential_stats
    
    def analyze_crash_signatures(self):
        """
        Analyze crash signatures and error patterns.
        
        Returns:
            Dictionary with crash signature analysis
        """
        if self.all_data.empty:
            return {}
        
        # Filter for error cases
        error_data = self.all_data[self.all_data['status'] == 'ERROR']
        
        crash_analysis = {
            'total_errors': len(error_data),
            'error_types': error_data['error_type'].value_counts().to_dict(),
            'crash_signatures': error_data['crash_signature'].value_counts().to_dict(),
            'engines_with_errors': error_data['engine_name'].value_counts().to_dict()
        }
        
        return crash_analysis
    
    def analyze_exit_code_patterns(self):
        """
        Group findings by exit code patterns across the 4 engines.
        
        Returns:
            Dictionary with exit code pattern analysis
        """
        if self.all_data.empty:
            return {}
        
        # Group by test_id to get exit codes for each engine
        exit_code_patterns = {}
        
        for test_id, group in self.all_data.groupby('test_id'):
            # Filter to only main engines
            main_engines = ['V8', 'SpiderMonkey', 'JavaScriptCore', 'GraalJS']
            engine_names = group['engine_name'].astype(str).str.strip()
            valid_engines = engine_names[engine_names.isin(main_engines)]
            
            if len(valid_engines.unique()) == 4:  # All 4 engines present
                # Create a pattern of exit codes
                pattern = []
                for engine in sorted(main_engines):
                    engine_data = group[group['engine_name'].astype(str).str.strip() == engine]
                    if len(engine_data) > 0:
                        exit_code = engine_data['exit_code'].iloc[0]
                        pattern.append(str(exit_code))
                    else:
                        pattern.append('N/A')
                
                # Create pattern string (e.g., "0,0,0,0" or "1,0,0,0")
                pattern_str = ','.join(pattern)
                
                if pattern_str not in exit_code_patterns:
                    exit_code_patterns[pattern_str] = []
                
                exit_code_patterns[pattern_str].append({
                    'test_id': test_id,
                    'finding_folder': group['finding_folder'].iloc[0],
                    'engines': sorted(main_engines),
                    'exit_codes': pattern
                })
        
        # Count patterns
        pattern_counts = {pattern: len(cases) for pattern, cases in exit_code_patterns.items()}
        
        return {
            'total_patterns': len(exit_code_patterns),
            'pattern_counts': pattern_counts,
            'exit_code_patterns': exit_code_patterns
        }
    
    def cluster_findings_by_tfidf(self, pattern_cases, max_features=1000, n_clusters=None):
        """
        Cluster findings within a pattern using TF-IDF and K-means.
        
        Args:
            pattern_cases: List of cases for a specific exit code pattern
            max_features: Maximum number of features for TF-IDF
            n_clusters: Number of clusters (auto-determined if None)
            
        Returns:
            Dictionary with clustering results
        """
        if len(pattern_cases) < 2:
            return {'n_clusters': 1, 'clusters': [pattern_cases]}
        
        # Extract text content for clustering
        texts = []
        for case in pattern_cases:
            # Combine relevant text fields
            text_parts = []
            
            # Get the finding folder name (often contains useful info)
            text_parts.append(case['finding_folder'])
            
            # Get test_id
            text_parts.append(str(case['test_id']))
            
            # Get the actual data for this test
            test_data = self.all_data[self.all_data['test_id'] == case['test_id']]
            if not test_data.empty:
                # Add stdout and stderr content
                for _, row in test_data.iterrows():
                    if pd.notna(row['stdout_lines']) and row['stdout_lines']:
                        text_parts.append(str(row['stdout_lines']))
                    if pd.notna(row['stderr_lines']) and row['stderr_lines']:
                        text_parts.append(str(row['stderr_lines']))
                    if pd.notna(row['error_type']) and row['error_type']:
                        text_parts.append(str(row['error_type']))
            
            texts.append(' '.join(text_parts))
        
        # Create TF-IDF vectors
        try:
            vectorizer = TfidfVectorizer(
                max_features=max_features,
                stop_words='english',
                ngram_range=(1, 2),
                min_df=1,
                max_df=0.95
            )
            tfidf_matrix = vectorizer.fit_transform(texts)
            
            # Determine number of clusters if not specified
            if n_clusters is None:
                n_clusters = min(5, max(1, len(pattern_cases) // 10))
                n_clusters = max(1, min(n_clusters, len(pattern_cases)))
            
            # Perform clustering
            if n_clusters > 1:
                kmeans = KMeans(n_clusters=n_clusters, random_state=42, n_init=10)
                cluster_labels = kmeans.fit_predict(tfidf_matrix)
            else:
                cluster_labels = [0] * len(pattern_cases)
            
            # Group cases by cluster
            clusters = defaultdict(list)
            for i, label in enumerate(cluster_labels):
                clusters[label].append(pattern_cases[i])
            
            return {
                'n_clusters': len(clusters),
                'clusters': list(clusters.values()),
                'cluster_sizes': [len(cluster) for cluster in clusters.values()]
            }
            
        except Exception as e:
            print(f"Error in TF-IDF clustering: {e}")
            return {'n_clusters': 1, 'clusters': [pattern_cases]}
    
    def analyze_pattern_clusters(self):
        """
        Analyze clustering within each exit code pattern.
        
        Returns:
            Dictionary with clustering analysis for each pattern
        """
        exit_patterns = self.analyze_exit_code_patterns()
        if not exit_patterns:
            return {}
        
        pattern_clusters = {}
        total_clusters = 0
        
        for pattern, cases in exit_patterns['exit_code_patterns'].items():
            if len(cases) >= 2:  # Only cluster if we have multiple cases
                clustering_result = self.cluster_findings_by_tfidf(cases)
                pattern_clusters[pattern] = clustering_result
                total_clusters += clustering_result['n_clusters']
            else:
                pattern_clusters[pattern] = {'n_clusters': 1, 'clusters': [cases]}
                total_clusters += 1
        
        return {
            'total_patterns': len(pattern_clusters),
            'total_clusters': total_clusters,
            'pattern_clusters': pattern_clusters
        }
    
    def create_folder_structure(self, output_dir="organized_findings"):
        """
        Create a folder structure organized by exit code patterns and clusters.
        
        Args:
            output_dir: Directory to create the organized structure
        """
        if self.all_data.empty:
            print("No data loaded. Please load data first.")
            return
        
        # Get clustering analysis
        pattern_clusters = self.analyze_pattern_clusters()
        if not pattern_clusters:
            print("No clustering results available.")
            return
        
        # Create output directory
        output_path = Path(output_dir)
        output_path.mkdir(exist_ok=True)
        
        # Create summary file
        summary_file = output_path / "summary.txt"
        with open(summary_file, 'w') as f:
            f.write("ORGANIZED FINDINGS SUMMARY\n")
            f.write("=" * 50 + "\n\n")
            f.write(f"Total patterns: {pattern_clusters['total_patterns']}\n")
            f.write(f"Total clusters: {pattern_clusters['total_clusters']}\n\n")
        
        total_files_created = 0
        
        # Process each pattern
        for pattern, cluster_info in pattern_clusters['pattern_clusters'].items():
            # Create pattern directory
            pattern_dir = output_path / f"pattern_{pattern.replace(',', '_')}"
            pattern_dir.mkdir(exist_ok=True)
            
            # Create pattern summary
            pattern_summary = pattern_dir / "pattern_summary.txt"
            with open(pattern_summary, 'w') as f:
                f.write(f"EXIT CODE PATTERN: {pattern}\n")
                f.write(f"Engines: V8, SpiderMonkey, JavaScriptCore, GraalJS\n")
                total_cases = sum(cluster_info.get('cluster_sizes', [len(cluster) for cluster in cluster_info['clusters']]))
                f.write(f"Total cases: {total_cases}\n")
                f.write(f"Number of clusters: {cluster_info['n_clusters']}\n")
                cluster_sizes = cluster_info.get('cluster_sizes', [len(cluster) for cluster in cluster_info['clusters']])
                f.write(f"Cluster sizes: {cluster_sizes}\n\n")
            
            # Process each cluster
            for cluster_idx, cluster_cases in enumerate(cluster_info['clusters']):
                cluster_dir = pattern_dir / f"cluster_{cluster_idx + 1:02d}"
                cluster_dir.mkdir(exist_ok=True)
                
                # Create cluster summary
                cluster_summary = cluster_dir / "cluster_summary.txt"
                with open(cluster_summary, 'w') as f:
                    f.write(f"CLUSTER {cluster_idx + 1}\n")
                    f.write(f"Size: {len(cluster_cases)} cases\n")
                    f.write(f"Pattern: {pattern}\n\n")
                    f.write("CASES:\n")
                    f.write("-" * 20 + "\n")
                
                # Process each case in the cluster
                for case_idx, case in enumerate(cluster_cases):
                    case_dir = cluster_dir / f"case_{case_idx + 1:03d}"
                    case_dir.mkdir(exist_ok=True)
                    
                    # Get the actual data for this test
                    test_data = self.all_data[self.all_data['test_id'] == case['test_id']]
                    
                    # Create case summary
                    case_summary = case_dir / "case_summary.txt"
                    with open(case_summary, 'w') as f:
                        f.write(f"TEST ID: {case['test_id']}\n")
                        f.write(f"FINDING FOLDER: {case['finding_folder']}\n")
                        f.write(f"EXIT CODE PATTERN: {pattern}\n")
                        f.write(f"CLUSTER: {cluster_idx + 1}\n\n")
                        
                        # Add engine-specific information
                        f.write("ENGINE RESULTS:\n")
                        f.write("-" * 20 + "\n")
                        for _, row in test_data.iterrows():
                            engine = row['engine_name']
                            exit_code = row['exit_code']
                            status = row['status']
                            f.write(f"{engine}: exit_code={exit_code}, status={status}\n")
                            
                            if pd.notna(row['error_type']) and row['error_type']:
                                f.write(f"  Error type: {row['error_type']}\n")
                    
                    # Save stdout and stderr for each engine
                    for _, row in test_data.iterrows():
                        engine = row['engine_name']
                        # Sanitize engine name for filesystem
                        safe_engine_name = "".join(c for c in engine.lower() if c.isalnum() or c in ('-', '_'))
                        engine_dir = case_dir / safe_engine_name
                        engine_dir.mkdir(exist_ok=True)
                        
                        # Save stdout
                        if pd.notna(row['stdout_lines']) and row['stdout_lines']:
                            stdout_file = engine_dir / "stdout.txt"
                            with open(stdout_file, 'w') as f:
                                f.write(str(row['stdout_lines']))
                        
                        # Save stderr
                        if pd.notna(row['stderr_lines']) and row['stderr_lines']:
                            stderr_file = engine_dir / "stderr.txt"
                            with open(stderr_file, 'w') as f:
                                f.write(str(row['stderr_lines']))
                        
                                            # Save error info
                        if pd.notna(row['error_type']) and row['error_type']:
                            error_file = engine_dir / "error.txt"
                            with open(error_file, 'w') as f:
                                f.write(f"Error type: {row['error_type']}\n")
                                if pd.notna(row['crash_signature']) and row['crash_signature']:
                                    f.write(f"Crash signature: {row['crash_signature']}\n")
                    
                    # Copy original finding folder contents
                    original_finding_folder = Path("../results_9_21/differential_finding_folder_javascript") / case['finding_folder']
                    if original_finding_folder.exists():
                        finding_data_dir = case_dir / "finding_data"
                        finding_data_dir.mkdir(exist_ok=True)
                        
                        # Copy all files from the original finding folder
                        for item in original_finding_folder.iterdir():
                            if item.is_file():
                                import shutil
                                shutil.copy2(item, finding_data_dir / item.name)
                            elif item.is_dir():
                                import shutil
                                shutil.copytree(item, finding_data_dir / item.name, dirs_exist_ok=True)
                        
                        # Create a summary of the finding data
                        finding_summary = finding_data_dir / "finding_summary.txt"
                        with open(finding_summary, 'w') as f:
                            f.write(f"ORIGINAL FINDING FOLDER: {case['finding_folder']}\n")
                            f.write(f"TEST ID: {case['test_id']}\n")
                            f.write(f"EXIT CODE PATTERN: {pattern}\n")
                            f.write(f"CLUSTER: {cluster_idx + 1}\n\n")
                            
                            f.write("FILES IN ORIGINAL FOLDER:\n")
                            f.write("-" * 30 + "\n")
                            for item in finding_data_dir.iterdir():
                                if item.is_file() and item.name != "finding_summary.txt":
                                    f.write(f"  {item.name}\n")
                                elif item.is_dir():
                                    f.write(f"  {item.name}/ (directory)\n")
                    
                    # Update cluster summary
                    with open(cluster_summary, 'a') as f:
                        f.write(f"  Case {case_idx + 1}: {case['test_id']} ({case['finding_folder']})\n")
                    
                    total_files_created += 1
        
        print(f"\n📁 FOLDER STRUCTURE CREATED:")
        print(f"   Output directory: {output_dir}")
        print(f"   Total patterns: {pattern_clusters['total_patterns']}")
        print(f"   Total clusters: {pattern_clusters['total_clusters']}")
        print(f"   Total cases organized: {total_files_created}")
        print(f"   Summary file: {summary_file}")
        
        return output_dir
    
    def print_summary(self, quiet=False):
        """Print a summary of the analysis."""
        if not self.stats:
            self.generate_basic_stats()
        
        if not quiet:
            print("\n" + "="*60)
            print("DIFFERENTIAL FINDINGS ANALYSIS SUMMARY")
            print("="*60)
        
        print(f"\n📊 BASIC STATISTICS:")
        print(f"   Total findings: {self.stats.get('total_findings', 0)}")
        print(f"   Total records: {self.stats.get('total_records', 0)}")
        print(f"   Engines tested: {', '.join(self.stats.get('engines', []))}")
        
        print(f"\n📈 STATUS DISTRIBUTION:")
        for status, count in self.stats.get('status_counts', {}).items():
            print(f"   {status}: {count}")
        
        if not quiet:
            print(f"\n🔧 ENGINE-SPECIFIC STATS:")
            for engine, stats in self.stats.get('engine_stats', {}).items():
                print(f"   {engine}:")
                print(f"     Total runs: {stats['total_runs']}")
                print(f"     Success: {stats['success_count']}")
                print(f"     Errors: {stats['error_count']}")
                if stats['error_types']:
                    print(f"     Error types: {stats['error_types']}")
        else:
            print(f"\n🔧 ENGINE SUMMARY:")
            for engine, stats in self.stats.get('engine_stats', {}).items():
                success_rate = (stats['success_count'] / stats['total_runs'] * 100) if stats['total_runs'] > 0 else 0
                print(f"   {engine}: {stats['success_count']}/{stats['total_runs']} ({success_rate:.1f}% success)")
        
        # Differential behavior analysis
        differential_stats = self.find_differential_behavior()
        if differential_stats:
            print(f"\n🔍 DIFFERENTIAL BEHAVIOR:")
            print(f"   Total differential cases: {differential_stats['total_differential_cases']}")
            print(f"   Cases with stdout differences: {differential_stats['cases_with_stdout_diff']}")
        
        # Crash analysis
        crash_analysis = self.analyze_crash_signatures()
        if crash_analysis:
            print(f"\n💥 CRASH ANALYSIS:")
            print(f"   Total errors: {crash_analysis['total_errors']}")
            if crash_analysis['error_types']:
                print(f"   Error types: {crash_analysis['error_types']}")
            if not quiet and crash_analysis['engines_with_errors']:
                print(f"   Engines with errors: {crash_analysis['engines_with_errors']}")
        
        # Exit code pattern analysis
        exit_patterns = self.analyze_exit_code_patterns()
        if exit_patterns:
            print(f"\n🔢 EXIT CODE PATTERNS:")
            print(f"   Total unique patterns: {exit_patterns['total_patterns']}")
            
            # Show top patterns
            pattern_counts = exit_patterns['pattern_counts']
            sorted_patterns = sorted(pattern_counts.items(), key=lambda x: x[1], reverse=True)
            
            print(f"   Top 10 patterns (V8,SpiderMonkey,JavaScriptCore,GraalJS):")
            for pattern, count in sorted_patterns[:10]:
                print(f"     {pattern}: {count} cases")
            
            if not quiet and len(sorted_patterns) > 10:
                print(f"     ... and {len(sorted_patterns) - 10} more patterns")
        
        # Pattern clustering analysis
        pattern_clusters = self.analyze_pattern_clusters()
        if pattern_clusters:
            print(f"\n🔍 PATTERN CLUSTERING ANALYSIS:")
            print(f"   Total patterns: {pattern_clusters['total_patterns']}")
            print(f"   Total clusters: {pattern_clusters['total_clusters']}")
            
            # Show clustering results for top patterns
            print(f"   Clustering results for top patterns:")
            for pattern, count in sorted_patterns[:5]:
                if pattern in pattern_clusters['pattern_clusters']:
                    cluster_info = pattern_clusters['pattern_clusters'][pattern]
                    print(f"     {pattern}: {cluster_info['n_clusters']} clusters")
                    if cluster_info['n_clusters'] > 1:
                        cluster_sizes = cluster_info['cluster_sizes']
                        print(f"       Cluster sizes: {cluster_sizes}")
    
    def save_detailed_report(self, output_file="differential_analysis_report.json"):
        """
        Save a detailed report to JSON file.
        
        Args:
            output_file: Path to save the detailed report
        """
        if not self.stats:
            self.generate_basic_stats()
        
        detailed_report = {
            'basic_stats': self.stats,
            'differential_behavior': self.find_differential_behavior(),
            'crash_analysis': self.analyze_crash_signatures(),
            'exit_code_patterns': self.analyze_exit_code_patterns(),
            'metadata': {
                'total_csv_files': len(self.csv_files),
                'analysis_timestamp': pd.Timestamp.now().isoformat()
            }
        }
        
        with open(output_file, 'w') as f:
            json.dump(detailed_report, f, indent=2, default=str)
        
        print(f"\n📄 Detailed report saved to: {output_file}")


def main():
    parser = argparse.ArgumentParser(description='Analyze differential findings from JavaScript engines')
    parser.add_argument('--findings-dir', 
                       default='8_29/differential_finding_folder_javascript',
                       help='Directory containing differential finding folders')
    parser.add_argument('--output', 
                       default='differential_analysis_report.json',
                       help='Output file for detailed report')
    parser.add_argument('--no-summary', 
                       action='store_true',
                       help='Skip printing summary to console')
    parser.add_argument('--quiet', 
                       action='store_true',
                       help='Show only key statistics (less verbose)')
    
    args = parser.parse_args()
    
    # Initialize analyzer
    analyzer = DifferentialFindingsAnalyzer(args.findings_dir)
    
    # Load data
    print(f"Loading data from: {args.findings_dir}")
    analyzer.load_all_data()
    
    if analyzer.all_data.empty:
        print("No data found. Please check the findings directory path.")
        return
    
    # Generate and print summary
    if not args.no_summary:
        analyzer.print_summary(quiet=args.quiet)
    
    # Save detailed report
    analyzer.save_detailed_report(args.output)


if __name__ == "__main__":
    main()
