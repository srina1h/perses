#!/usr/bin/env python3
"""
Nuanced Differential Testing Findings Clusterer

This script provides multiple levels of clustering sophistication:
Level 1: Basic exit code patterns
Level 2: Error type clustering  
Level 3: Semantic similarity clustering
Level 4: Code pattern analysis
Level 5: Advanced deduplication

Usage: python nuanced_cluster.py <findings_dir> <output_dir> [--level 1-5]
"""

import os
import json
import re
import hashlib
import argparse
from pathlib import Path
from collections import defaultdict, Counter
from typing import Dict, List, Tuple, Set
import shutil

class NuancedClusterer:
    def __init__(self, findings_dir: str, output_dir: str):
        self.findings_dir = Path(findings_dir)
        self.output_dir = Path(output_dir)
        self.findings = []
        self.clusters = defaultdict(list)
        
    def load_findings(self):
        """Load all findings from the directory structure"""
        print(f"Loading findings from {self.findings_dir}...")
        
        # Check if this is a single finding directory or contains multiple findings
        summary_file = self.findings_dir / "summary.txt"
        if summary_file.exists():
            # This is a single finding directory
            finding = self._parse_finding(self.findings_dir)
            if finding:
                self.findings.append(finding)
        else:
            # This contains multiple finding directories
            for finding_dir in self.findings_dir.iterdir():
                if not finding_dir.is_dir():
                    continue
                    
                summary_file = finding_dir / "summary.txt"
                if not summary_file.exists():
                    continue
                    
                finding = self._parse_finding(finding_dir)
                if finding:
                    self.findings.append(finding)
                
        print(f"Loaded {len(self.findings)} findings")
        
    def _parse_finding(self, finding_dir: Path) -> Dict:
        """Parse a single finding directory"""
        finding = {
            'path': finding_dir,
            'name': finding_dir.name,
            'exit_codes': {},
            'error_types': {},
            'error_messages': {},
            'input_size': 0,
            'input_hash': '',
            'code_features': {}
        }
        
        # Parse summary.txt
        summary_file = finding_dir / "summary.txt"
        if summary_file.exists():
            with open(summary_file) as f:
                content = f.read()
                finding['summary'] = content
                
                # Extract exit codes
                exit_code_pattern = r'(\w+): exit_code=(\d+)'
                for engine, code in re.findall(exit_code_pattern, content):
                    finding['exit_codes'][engine] = int(code)
        
        # Parse engine outputs
        for engine in ['v8', 'spidermonkey', 'javascriptcore', 'graaljs']:
            engine_dir = finding_dir / f"engine_{engine}"
            stderr_file = engine_dir / "stderr.txt"
            
            if stderr_file.exists():
                with open(stderr_file) as f:
                    stderr_content = f.read().strip()
                    if stderr_content:
                        finding['error_types'][engine] = self._extract_error_type(stderr_content)
                        finding['error_messages'][engine] = stderr_content
        
        # Get input file info
        input_file = finding_dir / "input.js"
        if input_file.exists():
            finding['input_size'] = input_file.stat().st_size
            with open(input_file) as f:
                input_content = f.read()
                finding['input_hash'] = hashlib.md5(input_content.encode()).hexdigest()[:8]
                finding['code_features'] = self._extract_code_features(input_content)
                
        return finding
    
    def _extract_error_type(self, stderr_content: str) -> str:
        """Extract the primary error type from stderr"""
        error_patterns = [
            (r'SyntaxError', 'SyntaxError'),
            (r'ReferenceError', 'ReferenceError'),
            (r'TypeError', 'TypeError'),
            (r'RangeError', 'RangeError'),
            (r'URIError', 'URIError'),
            (r'EvalError', 'EvalError'),
            (r'InternalError', 'InternalError'),
            (r'OutOfMemoryError', 'OutOfMemoryError'),
            (r'StackOverflowError', 'StackOverflowError'),
            (r'TimeoutError', 'TimeoutError'),
        ]
        
        for pattern, error_type in error_patterns:
            if re.search(pattern, stderr_content):
                return error_type
                
        return 'UnknownError'
    
    def _extract_code_features(self, code_content: str) -> Dict:
        """Extract code features for analysis"""
        features = {
            'length': len(code_content),
            'lines': len(code_content.split('\n')),
            'functions': len(re.findall(r'function\s+\w+', code_content)),
            'arrows': len(re.findall(r'=>', code_content)),
            'classes': len(re.findall(r'class\s+\w+', code_content)),
            'bigint_usage': len(re.findall(r'\d+n', code_content)),
            'template_literals': len(re.findall(r'`[^`]*`', code_content)),
            'regex_literals': len(re.findall(r'/[^/]*/[gimuy]*', code_content)),
        }
        return features
    
    def level1_basic_clustering(self):
        """Level 1: Basic exit code pattern clustering"""
        print("Level 1: Basic exit code clustering...")
        
        for finding in self.findings:
            exit_codes = finding['exit_codes']
            if len(exit_codes) != 4:
                continue
                
            # Create pattern key
            pattern = tuple(exit_codes.get(engine, -1) for engine in 
                          ['v8', 'spidermonkey', 'javascriptcore', 'graaljs'])
            
            # Categorize pattern
            category = self._categorize_exit_pattern(pattern)
            self.clusters[f"level1_{category}"].append(finding)
    
    def _categorize_exit_pattern(self, pattern: Tuple[int, ...]) -> str:
        """Categorize exit code pattern"""
        v8, sm, jsc, graal = pattern
        
        # All engines pass
        if all(code == 0 for code in pattern):
            return "all_pass"
        
        # All engines fail
        if all(code != 0 for code in pattern):
            return "all_fail"
        
        # Single engine fails
        if sum(1 for code in pattern if code != 0) == 1:
            if v8 != 0:
                return "v8_only_fails"
            elif sm != 0:
                return "spidermonkey_only_fails"
            elif jsc != 0:
                return "javascriptcore_only_fails"
            elif graal != 0:
                return "graaljs_only_fails"
        
        # Multiple engines fail
        return "multiple_engines_fail"
    
    def level2_error_type_clustering(self):
        """Level 2: Error type clustering"""
        print("Level 2: Error type clustering...")
        
        for finding in self.findings:
            error_types = finding['error_types']
            if not error_types:
                continue
                
            # Create error type signature
            error_signature = tuple(sorted(error_types.items()))
            self.clusters[f"level2_error_{hash(error_signature)}"].append(finding)
    
    def level3_semantic_clustering(self):
        """Level 3: Semantic similarity clustering"""
        print("Level 3: Semantic similarity clustering...")
        
        # Group by error message similarity
        error_groups = defaultdict(list)
        
        for finding in self.findings:
            error_messages = finding['error_messages']
            if not error_messages:
                continue
            
            # Create a signature from error messages
            msg_signature = self._create_message_signature(error_messages)
            error_groups[msg_signature].append(finding)
        
        # Create clusters from groups
        for i, (signature, group) in enumerate(error_groups.items()):
            self.clusters[f"level3_semantic_{i}"].extend(group)
    
    def _create_message_signature(self, error_messages: Dict[str, str]) -> str:
        """Create a signature from error messages"""
        # Extract key words from error messages
        all_words = set()
        for msg in error_messages.values():
            words = re.findall(r'\b\w+\b', msg.lower())
            all_words.update(words)
        
        # Sort and create signature
        return hashlib.md5(' '.join(sorted(all_words)).encode()).hexdigest()[:8]
    
    def level4_code_pattern_clustering(self):
        """Level 4: Code pattern clustering"""
        print("Level 4: Code pattern clustering...")
        
        for finding in self.findings:
            features = finding['code_features']
            if not features:
                continue
            
            # Create code pattern signature
            pattern_signature = self._create_code_pattern_signature(features)
            self.clusters[f"level4_code_{pattern_signature}"].append(finding)
    
    def _create_code_pattern_signature(self, features: Dict) -> str:
        """Create a signature from code features"""
        # Normalize features and create signature
        normalized = {
            'size': 'large' if features['length'] > 10000 else 'medium' if features['length'] > 1000 else 'small',
            'complexity': 'high' if features['functions'] > 10 else 'medium' if features['functions'] > 3 else 'low',
            'modern': 'yes' if features['arrows'] > 0 or features['bigint_usage'] > 0 else 'no'
        }
        
        return hashlib.md5(str(normalized).encode()).hexdigest()[:8]
    
    def level5_advanced_deduplication(self):
        """Level 5: Advanced deduplication"""
        print("Level 5: Advanced deduplication...")
        
        # Group by multiple criteria
        for finding in self.findings:
            # Create comprehensive signature
            signature = self._create_comprehensive_signature(finding)
            self.clusters[f"level5_advanced_{signature}"].append(finding)
    
    def _create_comprehensive_signature(self, finding: Dict) -> str:
        """Create a comprehensive signature for advanced clustering"""
        parts = []
        
        # Exit code pattern
        exit_pattern = tuple(finding['exit_codes'].get(engine, -1) for engine in 
                           ['v8', 'spidermonkey', 'javascriptcore', 'graaljs'])
        parts.append(f"exit:{exit_pattern}")
        
        # Error types
        error_types = tuple(sorted(finding['error_types'].items()))
        parts.append(f"errors:{hash(str(error_types))}")
        
        # Code features
        features = finding['code_features']
        if features:
            feature_sig = f"size:{features['length']},funcs:{features['functions']}"
            parts.append(f"code:{hash(feature_sig)}")
        
        return hashlib.md5('|'.join(parts).encode()).hexdigest()[:8]
    
    def select_representatives(self, max_per_cluster: int = 5) -> List[Dict]:
        """Select representative findings from each cluster"""
        print(f"Selecting up to {max_per_cluster} representatives per cluster...")
        
        representatives = []
        
        for cluster_name, cluster_findings in self.clusters.items():
            if not cluster_findings:
                continue
                
            # Sort by input size and take top N
            sorted_findings = sorted(cluster_findings, 
                                   key=lambda f: f['input_size'])
            
            selected = sorted_findings[:max_per_cluster]
            representatives.extend(selected)
            
            print(f"  {cluster_name}: {len(cluster_findings)} findings -> {len(selected)} representatives")
        
        return representatives
    
    def copy_representatives(self, representatives: List[Dict]):
        """Copy representative findings to output directory"""
        print(f"Copying representatives to {self.output_dir}...")
        
        # Clear output directory
        if self.output_dir.exists():
            shutil.rmtree(self.output_dir)
        self.output_dir.mkdir(parents=True)
        
        # Copy each representative
        for i, finding in enumerate(representatives):
            source_path = finding['path']
            dest_path = self.output_dir / f"representative_{i:04d}_{finding['name']}"
            
            shutil.copytree(source_path, dest_path)
            
            # Create metadata file
            metadata = {
                'original_name': finding['name'],
                'exit_codes': finding['exit_codes'],
                'error_types': finding['error_types'],
                'input_size': finding['input_size'],
                'input_hash': finding['input_hash']
            }
            
            with open(dest_path / "metadata.json", "w") as f:
                json.dump(metadata, f, indent=2)
    
    def generate_report(self, representatives: List[Dict]):
        """Generate a comprehensive report"""
        report_file = self.output_dir / "clustering_report.txt"
        
        with open(report_file, "w") as f:
            f.write("=== NUANCED CLUSTERING REPORT ===\n\n")
            f.write(f"Input directory: {self.findings_dir}\n")
            f.write(f"Output directory: {self.output_dir}\n")
            f.write(f"Total findings analyzed: {len(self.findings)}\n")
            f.write(f"Total clusters: {len(self.clusters)}\n")
            f.write(f"Representatives selected: {len(representatives)}\n\n")
            
            # Cluster statistics
            f.write("=== CLUSTER STATISTICS ===\n")
            cluster_sizes = [len(cluster) for cluster in self.clusters.values()]
            if cluster_sizes:
                f.write(f"Average cluster size: {sum(cluster_sizes)/len(cluster_sizes):.1f}\n")
                f.write(f"Largest cluster: {max(cluster_sizes)}\n")
                f.write(f"Smallest cluster: {min(cluster_sizes)}\n")
            else:
                f.write("No clusters found\n")
            f.write("\n")
            
            # Top clusters
            f.write("=== TOP CLUSTERS ===\n")
            sorted_clusters = sorted(self.clusters.items(), 
                                   key=lambda x: len(x[1]), reverse=True)
            
            for i, (cluster_name, cluster_findings) in enumerate(sorted_clusters[:10]):
                f.write(f"{i+1}. {cluster_name}: {len(cluster_findings)} findings\n")
                
                # Show sample
                sample = cluster_findings[0]
                f.write(f"   Sample: {sample['name']} (size: {sample['input_size']} bytes)\n")
                f.write(f"   Exit codes: {sample['exit_codes']}\n")
                f.write(f"   Error types: {sample['error_types']}\n\n")
            
            # Representatives summary
            f.write("=== REPRESENTATIVES SUMMARY ===\n")
            for i, finding in enumerate(representatives):
                f.write(f"{i+1}. {finding['name']}\n")
                f.write(f"   Size: {finding['input_size']} bytes\n")
                f.write(f"   Exit codes: {finding['exit_codes']}\n")
                f.write(f"   Error types: {finding['error_types']}\n\n")
    
    def run_clustering(self, level: int = 3, max_per_cluster: int = 5):
        """Run clustering at specified level"""
        print(f"Running nuanced clustering at level {level}...")
        
        self.load_findings()
        
        # Apply clustering levels
        if level >= 1:
            self.level1_basic_clustering()
        if level >= 2:
            self.level2_error_type_clustering()
        if level >= 3:
            self.level3_semantic_clustering()
        if level >= 4:
            self.level4_code_pattern_clustering()
        if level >= 5:
            self.level5_advanced_deduplication()
        
        # Select representatives
        representatives = self.select_representatives(max_per_cluster)
        
        # Copy to output directory
        self.copy_representatives(representatives)
        
        # Generate report
        self.generate_report(representatives)
        
        print(f"\nClustering complete!")
        print(f"Original findings: {len(self.findings)}")
        print(f"Representative findings: {len(representatives)}")
        print(f"Reduction ratio: {len(representatives)/len(self.findings)*100:.1f}%")
        print(f"Results saved to: {self.output_dir}")

def main():
    parser = argparse.ArgumentParser(description="Nuanced clustering of differential testing findings")
    parser.add_argument("findings_dir", help="Directory containing finding folders")
    parser.add_argument("output_dir", help="Output directory for clustered results")
    parser.add_argument("--level", type=int, default=3, choices=[1,2,3,4,5],
                       help="Clustering level (1=basic, 5=advanced)")
    parser.add_argument("--max-per-cluster", type=int, default=5,
                       help="Maximum representatives per cluster")
    
    args = parser.parse_args()
    
    clusterer = NuancedClusterer(args.findings_dir, args.output_dir)
    clusterer.run_clustering(level=args.level, max_per_cluster=args.max_per_cluster)

if __name__ == "__main__":
    main()
