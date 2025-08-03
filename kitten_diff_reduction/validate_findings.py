#!/usr/bin/env python3
"""
Utility script to validate and fix problematic differential finding folders.

This script helps identify and fix issues with finding folder structure
and missing or corrupted files.
"""

import os
import sys
from pathlib import Path
from typing import List, Dict, Tuple


def validate_finding_folder(finding_path: Path) -> Dict:
    """Validate a single finding folder and return issues found."""
    issues = {
        "missing_files": [],
        "empty_files": [],
        "invalid_exit_codes": [],
        "structure_issues": []
    }
    
    if not finding_path.exists():
        issues["structure_issues"].append("Finding folder does not exist")
        return issues
    
    if not finding_path.is_dir():
        issues["structure_issues"].append("Path is not a directory")
        return issues
    
    # Check required files
    required_files = ["input.js"]
    for file_name in required_files:
        file_path = finding_path / file_name
        if not file_path.exists():
            issues["missing_files"].append(file_name)
        elif file_path.stat().st_size == 0:
            issues["empty_files"].append(file_name)
    
    # Check engine directories
    engines = ["engine_graaljs", "engine_hermes", "engine_v8"]
    engine_issues = []
    
    for engine in engines:
        engine_path = finding_path / engine
        if engine_path.exists():
            # Check engine files
            engine_files = ["command.txt", "exit_code.txt", "stdout.txt", "stderr.txt"]
            for file_name in engine_files:
                file_path = engine_path / file_name
                if not file_path.exists():
                    engine_issues.append(f"{engine}/{file_name} missing")
                elif file_name == "exit_code.txt":
                    # Check exit code validity
                    try:
                        with open(file_path, 'r') as f:
                            content = f.read().strip()
                            if content == "":
                                issues["empty_files"].append(f"{engine}/{file_name}")
                            else:
                                int(content)  # Try to convert to int
                    except (ValueError, FileNotFoundError):
                        issues["invalid_exit_codes"].append(f"{engine}/{file_name}")
                elif file_path.stat().st_size == 0:
                    issues["empty_files"].append(f"{engine}/{file_name}")
    
    if engine_issues:
        issues["structure_issues"].extend(engine_issues)
    
    return issues


def fix_finding_folder(finding_path: Path, issues: Dict) -> bool:
    """Attempt to fix issues in a finding folder."""
    fixed = False
    
    # Fix empty exit codes
    for invalid_exit_code in issues["invalid_exit_codes"]:
        file_path = finding_path / invalid_exit_code
        try:
            with open(file_path, 'r') as f:
                content = f.read().strip()
            
            # Try to fix common issues
            if content == "":
                # Empty file - set to -1 (unknown error)
                with open(file_path, 'w') as f:
                    f.write("-1")
                fixed = True
                print(f"  Fixed empty exit code in {invalid_exit_code}")
            elif not content.isdigit():
                # Non-numeric content - set to -1
                with open(file_path, 'w') as f:
                    f.write("-1")
                fixed = True
                print(f"  Fixed invalid exit code in {invalid_exit_code}")
        except Exception as e:
            print(f"  Could not fix {invalid_exit_code}: {e}")
    
    return fixed


def validate_all_findings(base_path: str) -> Tuple[List[Path], List[Tuple[Path, Dict]]]:
    """Validate all findings in a directory."""
    base_path = Path(base_path)
    valid_findings = []
    problematic_findings = []
    
    if not base_path.exists():
        print(f"Error: Base path does not exist: {base_path}")
        return valid_findings, problematic_findings
    
    print(f"Validating findings in: {base_path}")
    
    for item in base_path.iterdir():
        if item.is_dir() and (item / "input.js").exists():
            issues = validate_finding_folder(item)
            
            if any(issues.values()):
                problematic_findings.append((item, issues))
            else:
                valid_findings.append(item)
    
    return valid_findings, problematic_findings


def main():
    """Main validation function."""
    if len(sys.argv) < 2:
        print("Usage: python validate_findings.py <findings_directory> [--fix]")
        print("Example: python validate_findings.py results/differential_findings_javascript --fix")
        sys.exit(1)
    
    base_path = sys.argv[1]
    should_fix = "--fix" in sys.argv
    
    valid_findings, problematic_findings = validate_all_findings(base_path)
    
    print(f"\nValidation Results:")
    print(f"  Valid findings: {len(valid_findings)}")
    print(f"  Problematic findings: {len(problematic_findings)}")
    
    if problematic_findings:
        print(f"\nProblematic findings:")
        for finding_path, issues in problematic_findings[:10]:  # Show first 10
            print(f"\n  {finding_path.name}:")
            
            for issue_type, issue_list in issues.items():
                if issue_list:
                    print(f"    {issue_type}: {issue_list}")
            
            if should_fix:
                print(f"    Attempting to fix...")
                if fix_finding_folder(finding_path, issues):
                    print(f"    Fixed some issues")
                else:
                    print(f"    Could not fix issues")
        
        if len(problematic_findings) > 10:
            print(f"  ... and {len(problematic_findings) - 10} more problematic findings")
    
    if should_fix and problematic_findings:
        print(f"\nRe-validating after fixes...")
        valid_findings_after, problematic_findings_after = validate_all_findings(base_path)
        print(f"  Valid findings after fix: {len(valid_findings_after)}")
        print(f"  Problematic findings after fix: {len(problematic_findings_after)}")
    
    if valid_findings:
        print(f"\nReady to process {len(valid_findings)} valid findings")
    else:
        print(f"\nNo valid findings found. Please check the directory structure.")


if __name__ == "__main__":
    main() 