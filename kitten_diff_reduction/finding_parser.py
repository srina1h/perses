"""
Finding Parser for JavaScript Differential Testing Results

This module parses individual finding folders and extracts engine outputs,
metadata, and identifies discrepancy types.
"""

import os
import json
from pathlib import Path
from typing import Dict, List, Optional, NamedTuple
from dataclasses import dataclass
from enum import Enum


class FindingType(Enum):
    """Types of findings in differential testing."""
    CRASH = "crash"
    DIFFERENTIAL = "differential"
    UNKNOWN = "unknown"


class DiscrepancyType(Enum):
    """Types of discrepancies found in differential testing."""
    EXIT_CODE_DIFFERENCE = "exit_code_difference"
    OUTPUT_DIFFERENCE = "output_difference"
    TIMEOUT_DIFFERENCE = "timeout_difference"
    ERROR_DIFFERENCE = "error_difference"
    PERFORMANCE_DIFFERENCE = "performance_difference"
    UNKNOWN = "unknown"


@dataclass
class EngineOutput:
    """Represents the output from a single engine."""
    engine_name: str
    command: str
    exit_code: int
    stdout: str
    stderr: str
    execution_time: Optional[float] = None


@dataclass
class DifferentialFinding:
    """Represents a complete differential finding."""
    finding_path: Path
    finding_type: FindingType
    input_js: str
    seed_js: str
    engine_outputs: Dict[str, EngineOutput]
    discrepancy_type: DiscrepancyType
    summary: str
    differential_results: str
    metadata: Dict


class FindingParser:
    """Parser for differential finding folders."""
    
    def __init__(self, finding_path: Path):
        self.finding_path = Path(finding_path)
        self.engines = ["engine_graaljs", "engine_hermes", "engine_v8"]
    
    def _determine_finding_type(self) -> FindingType:
        """Determine if this is a crash or differential finding based on folder name."""
        folder_name = self.finding_path.name
        
        if folder_name.startswith("crash_"):
            return FindingType.CRASH
        elif folder_name.startswith("differential_finding_"):
            return FindingType.DIFFERENTIAL
        else:
            # Try to infer from content
            if self._has_crash_indicators():
                return FindingType.CRASH
            else:
                return FindingType.DIFFERENTIAL
    
    def _has_crash_indicators(self) -> bool:
        """Check if the finding has indicators of a crash."""
        # Check for crash indicators in stderr
        for engine in self.engines:
            engine_path = self.finding_path / engine
            if engine_path.exists():
                stderr_file = engine_path / "stderr.txt"
                if stderr_file.exists():
                    try:
                        with open(stderr_file, 'r') as f:
                            stderr_content = f.read().lower()
                            crash_indicators = [
                                "segmentation fault",
                                "segfault",
                                "crash",
                                "abort",
                                "core dumped",
                                "fatal error",
                                "assertion failed"
                            ]
                            if any(indicator in stderr_content for indicator in crash_indicators):
                                return True
                    except:
                        pass
        
        return False
    
    def parse(self) -> DifferentialFinding:
        """Parse a complete differential finding folder."""
        if not self.finding_path.exists():
            raise FileNotFoundError(f"Finding path does not exist: {self.finding_path}")
        
        # Determine finding type first
        finding_type = self._determine_finding_type()
        
        # Use different parsing logic for crashes vs differential findings
        if finding_type == FindingType.CRASH:
            return self._parse_crash_folder()
        
        # For differential findings, use the original logic
        # Check if folder is valid before parsing
        if not self._is_folder_valid():
            raise ValueError(f"Finding folder {self.finding_path} has invalid structure or empty files")
        
        # Parse engine outputs
        engine_outputs = {}
        for engine in self.engines:
            engine_path = self.finding_path / engine
            if engine_path.exists():
                try:
                    engine_outputs[engine] = self._parse_engine_output(engine_path, engine)
                except Exception as e:
                    print(f"Warning: Failed to parse engine {engine} in {self.finding_path}: {e}")
                    # Continue with other engines
        
        # Ensure we have at least one engine output
        if not engine_outputs:
            raise ValueError(f"No valid engine outputs found in {self.finding_path}")
        
        # Parse input files (crash folders might not have input.js)
        input_js = self._read_file("input.js") if (self.finding_path / "input.js").exists() else ""
        seed_js = self._read_file("seed.js") if (self.finding_path / "seed.js").exists() else ""
        summary = self._read_file("summary.txt") if (self.finding_path / "summary.txt").exists() else ""
        differential_results = self._read_file("differential_results.txt") if (self.finding_path / "differential_results.txt").exists() else ""
        
        # Determine discrepancy type
        discrepancy_type = self._determine_discrepancy_type(engine_outputs)
        
        # Extract metadata
        metadata = self._extract_metadata(engine_outputs)
        
        return DifferentialFinding(
            finding_path=self.finding_path,
            finding_type=finding_type,
            input_js=input_js,
            seed_js=seed_js,
            engine_outputs=engine_outputs,
            discrepancy_type=discrepancy_type,
            summary=summary,
            differential_results=differential_results,
            metadata=metadata
        )
    

    
    def _parse_engine_output(self, engine_path: Path, engine_name: str) -> EngineOutput:
        """Parse output from a specific engine."""
        command = self._read_file(str(engine_path / "command.txt"))
        
        # Handle empty or invalid exit codes
        exit_code_str = self._read_file(str(engine_path / "exit_code.txt")).strip()
        try:
            exit_code = int(exit_code_str) if exit_code_str else -1
        except ValueError:
            # If exit code is not a valid integer, default to -1
            exit_code = -1
        
        stdout = self._read_file(str(engine_path / "stdout.txt"))
        stderr = self._read_file(str(engine_path / "stderr.txt"))
        
        return EngineOutput(
            engine_name=engine_name,
            command=command,
            exit_code=exit_code,
            stdout=stdout,
            stderr=stderr
        )
    
    def _parse_crash_folder(self) -> DifferentialFinding:
        """Parse a crash folder with the crash-specific structure."""
        # For crash folders, we need to handle the different file structure
        # Read the crash-specific files
        input_js = self._read_file("mutant_22_1754080481155.js") if (self.finding_path / "mutant_22_1754080481155.js").exists() else ""
        seed_js = self._read_file("seed.js") if (self.finding_path / "seed.js").exists() else ""
        summary = self._read_file("crash_signature.txt") if (self.finding_path / "crash_signature.txt").exists() else ""
        differential_results = self._read_file("bug_descriptor.properties") if (self.finding_path / "bug_descriptor.properties").exists() else ""
        
        # Create mock engine outputs from the crash files
        engine_outputs = {}
        
        # Read stdout and stderr from the crash folder
        stdout = self._read_file("stdout.txt") if (self.finding_path / "stdout.txt").exists() else ""
        stderr = self._read_file("stderr.txt") if (self.finding_path / "stderr.txt").exists() else ""
        
        # Create a mock engine output for the crash
        # We'll use a generic engine name since crash folders don't have engine-specific outputs
        engine_outputs["engine_crash"] = EngineOutput(
            engine_name="engine_crash",
            command="crash_reproduction",
            exit_code=-1,  # Crashes typically have non-zero exit codes
            stdout=stdout,
            stderr=stderr
        )
        
        # Determine finding type and discrepancy type
        finding_type = FindingType.CRASH
        discrepancy_type = DiscrepancyType.ERROR_DIFFERENCE  # Crashes are error differences
        
        # Extract metadata
        metadata = {
            "engines_present": ["engine_crash"],
            "total_engines": 1,
            "input_size": len(input_js),
            "seed_size": len(seed_js),
            "is_crash_folder": True
        }
        
        return DifferentialFinding(
            finding_path=self.finding_path,
            finding_type=finding_type,
            input_js=input_js,
            seed_js=seed_js,
            engine_outputs=engine_outputs,
            discrepancy_type=discrepancy_type,
            summary=summary,
            differential_results=differential_results,
            metadata=metadata
        )
    
    def _is_folder_valid(self) -> bool:
        """Check if the finding folder has valid structure and non-empty required files."""
        try:
            # Determine if this is a crash folder
            is_crash = self.finding_path.name.startswith("crash_")
            
            if is_crash:
                # For crash folders, check for crash-specific files
                crash_files = ["mutant_22_1754080481155.js", "seed.js", "crash_signature.txt"]
                valid_crash_files = 0
                for file_name in crash_files:
                    file_path = self.finding_path / file_name
                    if file_path.exists() and file_path.stat().st_size > 0:
                        valid_crash_files += 1
                
                # Require at least one valid crash file
                return valid_crash_files > 0
            else:
                # For differential findings, require input.js
                input_file = self.finding_path / "input.js"
                if not input_file.exists() or input_file.stat().st_size == 0:
                    return False
                
                # Check if at least one engine directory exists and has valid files
                valid_engines = 0
                for engine in self.engines:
                    engine_path = self.finding_path / engine
                    if engine_path.exists():
                        # Check if engine has required files and exit_code.txt is not empty
                        exit_code_file = engine_path / "exit_code.txt"
                        if exit_code_file.exists() and exit_code_file.stat().st_size > 0:
                            valid_engines += 1
                
                # Require at least one valid engine
                return valid_engines > 0
        except Exception:
            # If any error occurs during validation, consider the folder invalid
            return False
    
    def _read_file(self, file_path) -> str:
        """Read a file and return its contents."""
        # Convert string to Path if needed
        if isinstance(file_path, str):
            file_path = Path(file_path)
        
        full_path = self.finding_path / file_path if not file_path.is_absolute() else file_path
        try:
            with open(full_path, 'r', encoding='utf-8') as f:
                return f.read()
        except FileNotFoundError:
            return ""
        except UnicodeDecodeError:
            # Try with different encoding
            with open(full_path, 'r', encoding='latin-1') as f:
                return f.read()
    
    def _determine_discrepancy_type(self, engine_outputs: Dict[str, EngineOutput]) -> DiscrepancyType:
        """Determine the type of discrepancy based on engine outputs."""
        if not engine_outputs:
            return DiscrepancyType.UNKNOWN
        
        # Check for exit code differences
        exit_codes = {name: output.exit_code for name, output in engine_outputs.items()}
        if len(set(exit_codes.values())) > 1:
            return DiscrepancyType.EXIT_CODE_DIFFERENCE
        
        # Check for output differences
        stdouts = {name: output.stdout.strip() for name, output in engine_outputs.items()}
        if len(set(stdouts.values())) > 1:
            return DiscrepancyType.OUTPUT_DIFFERENCE
        
        # Check for error differences
        stderrs = {name: output.stderr.strip() for name, output in engine_outputs.items()}
        if len(set(stderrs.values())) > 1:
            return DiscrepancyType.ERROR_DIFFERENCE
        
        # Check for timeout indicators
        for output in engine_outputs.values():
            if "timeout" in output.stderr.lower() or "timeout" in output.stdout.lower():
                return DiscrepancyType.TIMEOUT_DIFFERENCE
        
        return DiscrepancyType.UNKNOWN
    
    def _extract_metadata(self, engine_outputs: Dict[str, EngineOutput]) -> Dict:
        """Extract metadata from the finding."""
        metadata = {
            "engines_present": list(engine_outputs.keys()),
            "total_engines": len(engine_outputs),
            "input_size": len(self._read_file("input.js")),
            "seed_size": len(self._read_file("seed.js")),
        }
        
        # Add engine-specific metadata
        for engine_name, output in engine_outputs.items():
            metadata[f"{engine_name}_exit_code"] = output.exit_code
            metadata[f"{engine_name}_stdout_size"] = len(output.stdout)
            metadata[f"{engine_name}_stderr_size"] = len(output.stderr)
        
        return metadata


def parse_finding_folder(finding_path: str) -> DifferentialFinding:
    """Convenience function to parse a finding folder."""
    parser = FindingParser(Path(finding_path))
    return parser.parse()


def parse_multiple_findings(base_path: str, finding_types: List[FindingType] = None) -> List[DifferentialFinding]:
    """Parse multiple finding folders from a base directory.
    
    Args:
        base_path: Directory containing finding folders
        finding_types: List of finding types to parse. If None, parses all types.
    """
    base_path = Path(base_path)
    findings = []
    skipped_folders = 0
    
    if not base_path.exists():
        return findings
    
    # First, collect all potential folders
    potential_folders = []
    for item in base_path.iterdir():
        if item.is_dir():
            # Check if it's a crash folder or differential finding
            is_crash = item.name.startswith("crash_")
            is_differential = item.name.startswith("differential_finding_")
            
            # Skip if it's neither
            if not is_crash and not is_differential:
                continue
            
            # Filter by finding type if specified
            if finding_types is not None:
                if is_crash and FindingType.CRASH not in finding_types:
                    continue
                if is_differential and FindingType.DIFFERENTIAL not in finding_types:
                    continue
            
            # For differential findings, require input.js
            if is_differential and not (item / "input.js").exists():
                continue
            
            # For crash folders, check for crash-specific files
            if is_crash:
                crash_files = ["mutant_22_1754080481155.js", "seed.js", "crash_signature.txt"]
                has_crash_files = any((item / file_name).exists() for file_name in crash_files)
                if not has_crash_files:
                    continue
            
            potential_folders.append(item)
    
    print(f"Found {len(potential_folders)} potential finding folders to parse")
    
    # Now parse each folder with progress monitoring
    for i, item in enumerate(potential_folders):
        if i % 1000 == 0 and i > 0:
            print(f"  Parsed {i}/{len(potential_folders)} folders...")
        
        try:
            finding = parse_finding_folder(str(item))
            findings.append(finding)
        except Exception as e:
            # Silently skip folders with empty files or invalid structure
            skipped_folders += 1
    
    if skipped_folders > 0:
        print(f"Note: Skipped {skipped_folders} folders with empty files or invalid structure")
    
    return findings


def parse_findings_by_type(base_path: str) -> Dict[FindingType, List[DifferentialFinding]]:
    """Parse findings and separate them by type (crash vs differential)."""
    all_findings = parse_multiple_findings(base_path)
    
    findings_by_type = {
        FindingType.CRASH: [],
        FindingType.DIFFERENTIAL: [],
        FindingType.UNKNOWN: []
    }
    
    for finding in all_findings:
        findings_by_type[finding.finding_type].append(finding)
    
    return findings_by_type 