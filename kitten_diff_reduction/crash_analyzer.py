"""
Lightweight Crash Analyzer for JavaScript Differential Testing

This module provides fast, memory-efficient analysis of crash findings
without the overhead of semantic analysis.
"""

import os
import re
from pathlib import Path
from typing import List, Dict, Tuple, Set
from dataclasses import dataclass
from collections import defaultdict
import hashlib
from finding_parser import DifferentialFinding, FindingType


@dataclass
class CrashSignature:
    """Represents a crash signature for grouping similar crashes."""
    crash_type: str
    error_pattern: str
    exit_code: int
    engine_combination: str
    hash: str
    
    def __str__(self):
        return f"{self.crash_type}:{self.error_pattern[:50]}..."


@dataclass
class CrashGroup:
    """Represents a group of similar crashes."""
    signature: CrashSignature
    findings: List[DifferentialFinding]
    representative: DifferentialFinding
    
    @property
    def count(self) -> int:
        return len(self.findings)
    
    @property
    def crash_type(self) -> str:
        return self.signature.crash_type


class CrashAnalyzer:
    """Fast crash analyzer using simple pattern matching and hashing."""
    
    def __init__(self):
        """Initialize the crash analyzer."""
        self.crash_patterns = {
            'SEGMENTATION_FAULT': [
                r'segmentation fault',
                r'segfault',
                r'SIGSEGV',
                r'access violation'
            ],
            'ASSERTION_FAILURE': [
                r'assertion failed',
                r'assert.*failed',
                r'ASSERT.*FAILED'
            ],
            'FATAL_ERROR': [
                r'fatal error',
                r'FATAL.*ERROR',
                r'critical error'
            ],
            'ABORT_ERROR': [
                r'abort',
                r'ABORT',
                r'terminate called'
            ],
            'CORE_DUMP': [
                r'core dumped',
                r'core dump',
                r'stack trace'
            ],
            'MEMORY_ERROR': [
                r'out of memory',
                r'memory allocation failed',
                r'heap overflow'
            ],
            'TIMEOUT_ERROR': [
                r'timeout',
                r'execution timeout',
                r'killed by signal'
            ]
        }
    
    def analyze_crashes(self, findings: List[DifferentialFinding]) -> List[CrashGroup]:
        """Analyze and group crash findings."""
        print(f"Analyzing {len(findings)} crashes...")
        
        # Extract crash signatures
        print("  Extracting crash signatures...")
        signatures = []
        for i, finding in enumerate(findings):
            if i % 1000 == 0 and i > 0:
                print(f"    Processed {i}/{len(findings)} findings...")
            
            signature = self._extract_crash_signature(finding)
            if signature:
                signatures.append((signature, finding))
        
        print(f"  Extracted {len(signatures)} valid crash signatures")
        
        # Group by signature
        print("  Grouping by signature...")
        groups = self._group_by_signature(signatures)
        print(f"  Created {len(groups)} initial groups")
        
        # Select representatives
        print("  Selecting representatives...")
        crash_groups = []
        for i, (signature, findings_list) in enumerate(groups.items()):
            if i % 50 == 0 and i > 0:
                print(f"    Processed {i}/{len(groups)} groups...")
            
            representative = self._select_representative(findings_list)
            group = CrashGroup(
                signature=signature,
                findings=findings_list,
                representative=representative
            )
            crash_groups.append(group)
        
        # Sort by frequency
        print("  Sorting groups by frequency...")
        crash_groups.sort(key=lambda g: g.count, reverse=True)
        
        print(f"  Created {len(crash_groups)} final crash groups")
        return crash_groups
    
    def _extract_crash_signature(self, finding: DifferentialFinding) -> CrashSignature:
        """Extract a crash signature from a finding."""
        # Get all error text
        error_text = ""
        exit_codes = []
        engines = []
        
        for engine_name, output in finding.engine_outputs.items():
            engines.append(engine_name)
            if output.exit_code is not None:
                exit_codes.append(output.exit_code)
            
            if output.stderr:
                error_text += output.stderr + "\n"
            if output.stdout:
                error_text += output.stdout + "\n"
        
        # Determine crash type
        crash_type = self._classify_crash_type(error_text)
        
        # Extract error pattern (first significant error line)
        error_pattern = self._extract_error_pattern(error_text)
        
        # Get exit code pattern
        exit_code = self._get_exit_code_pattern(exit_codes)
        
        # Create engine combination
        engine_combination = "+".join(sorted(engines))
        
        # Create hash for uniqueness
        hash_input = f"{crash_type}:{error_pattern}:{exit_code}:{engine_combination}"
        signature_hash = hashlib.md5(hash_input.encode()).hexdigest()[:8]
        
        return CrashSignature(
            crash_type=crash_type,
            error_pattern=error_pattern,
            exit_code=exit_code,
            engine_combination=engine_combination,
            hash=signature_hash
        )
    
    def _classify_crash_type(self, error_text: str) -> str:
        """Classify the type of crash based on error text."""
        error_text_lower = error_text.lower()
        
        for crash_type, patterns in self.crash_patterns.items():
            for pattern in patterns:
                if re.search(pattern, error_text_lower, re.IGNORECASE):
                    return crash_type
        
        # Default classification
        if "error" in error_text_lower:
            return "RUNTIME_ERROR"
        elif "exception" in error_text_lower:
            return "EXCEPTION"
        else:
            return "UNKNOWN_CRASH"
    
    def _extract_error_pattern(self, error_text: str) -> str:
        """Extract the most significant error pattern."""
        lines = error_text.split('\n')
        
        for line in lines:
            line = line.strip()
            if not line:
                continue
            
            # Look for error indicators
            if any(keyword in line.lower() for keyword in 
                   ['error', 'exception', 'fatal', 'abort', 'segmentation', 'assert']):
                # Clean up the line
                cleaned = re.sub(r'\s+', ' ', line)
                return cleaned[:100]  # Limit length
        
        # Fallback: return first non-empty line
        for line in lines:
            if line.strip():
                return line.strip()[:100]
        
        return "NO_ERROR_PATTERN"
    
    def _get_exit_code_pattern(self, exit_codes: List[int]) -> int:
        """Get a representative exit code pattern."""
        if not exit_codes:
            return -1
        
        # Return the most common exit code, or -1 if all are different
        from collections import Counter
        counter = Counter(exit_codes)
        most_common = counter.most_common(1)[0]
        
        if most_common[1] > 1:  # If there's a common pattern
            return most_common[0]
        else:
            return -1  # No clear pattern
    
    def _group_by_signature(self, signatures: List[Tuple[CrashSignature, DifferentialFinding]]) -> Dict[CrashSignature, List[DifferentialFinding]]:
        """Group findings by their crash signature."""
        groups = defaultdict(list)
        
        for signature, finding in signatures:
            # Create a key based on crash type and error pattern
            key = (signature.crash_type, signature.error_pattern[:50])
            groups[key].append(finding)
        
        # Convert to CrashSignature keys
        result = {}
        for (crash_type, error_pattern), findings_list in groups.items():
            # Use the first signature as the representative
            signature = signatures[0][0]
            result[signature] = findings_list
        
        return result
    
    def _select_representative(self, findings: List[DifferentialFinding]) -> DifferentialFinding:
        """Select a representative finding from the group."""
        # Prefer findings with more detailed error information
        best_finding = findings[0]
        max_error_length = 0
        
        for finding in findings:
            error_length = sum(len(output.stderr or "") + len(output.stdout or "") 
                             for output in finding.engine_outputs.values())
            
            if error_length > max_error_length:
                max_error_length = error_length
                best_finding = finding
        
        return best_finding
    
    def generate_crash_summary(self, groups: List[CrashGroup]) -> Dict:
        """Generate a summary of crash analysis."""
        summary = {
            'total_crashes': sum(g.count for g in groups),
            'unique_crash_types': len(set(g.crash_type for g in groups)),
            'crash_groups': len(groups),
            'reduction_ratio': 1 - (len(groups) / sum(g.count for g in groups)),
            'crash_types': defaultdict(int),
            'top_groups': []
        }
        
        # Count by crash type
        for group in groups:
            summary['crash_types'][group.crash_type] += group.count
        
        # Top groups
        summary['top_groups'] = [
            {
                'crash_type': g.crash_type,
                'count': g.count,
                'error_pattern': g.signature.error_pattern[:100],
                'representative_path': str(g.representative.finding_path)
            }
            for g in groups[:10]  # Top 10
        ]
        
        return summary


def analyze_crash_folders(input_dir: str, output_dir: str = None) -> List[CrashGroup]:
    """Analyze crash folders and return grouped results."""
    from finding_parser import parse_multiple_findings, FindingType
    
    # Parse only crash findings
    print("Parsing crash folders only...")
    findings = parse_multiple_findings(input_dir, finding_types=[FindingType.CRASH])
    
    # Filter for crashes only
    crash_findings = [f for f in findings if f.finding_type == FindingType.CRASH]
    
    print(f"Found {len(crash_findings)} crash findings")
    
    # Analyze crashes
    analyzer = CrashAnalyzer()
    crash_groups = analyzer.analyze_crashes(crash_findings)
    
    # Generate summary
    summary = analyzer.generate_crash_summary(crash_groups)
    
    print(f"\nCrash Analysis Summary:")
    print(f"  Total crashes: {summary['total_crashes']}")
    print(f"  Unique crash types: {summary['unique_crash_types']}")
    print(f"  Crash groups: {summary['crash_groups']}")
    print(f"  Reduction ratio: {summary['reduction_ratio']:.2%}")
    
    print(f"\nCrash types:")
    for crash_type, count in summary['crash_types'].items():
        print(f"  {crash_type}: {count}")
    
    print(f"\nTop crash groups:")
    for i, group in enumerate(summary['top_groups'][:5]):
        print(f"  {i+1}. {group['crash_type']} ({group['count']} crashes)")
        print(f"     Pattern: {group['error_pattern']}")
    
    return crash_groups


if __name__ == "__main__":
    import sys
    
    if len(sys.argv) < 2:
        print("Usage: python crash_analyzer.py <input_directory> [output_directory]")
        sys.exit(1)
    
    input_dir = sys.argv[1]
    output_dir = sys.argv[2] if len(sys.argv) > 2 else None
    
    crash_groups = analyze_crash_folders(input_dir, output_dir) 