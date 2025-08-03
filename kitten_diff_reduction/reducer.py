"""
Reduction Engine for JavaScript Differential Testing Results

This module minimizes test cases while preserving bugs using delta debugging
techniques and creates minimal reproducing examples.
"""

import subprocess
import tempfile
import os
from pathlib import Path
from typing import List, Dict, Optional, Tuple, Callable
from dataclasses import dataclass
from finding_parser import DifferentialFinding, EngineOutput
from error_classifier import ClassifiedError


@dataclass
class ReductionResult:
    """Result of a reduction operation."""
    original_size: int
    reduced_size: int
    reduction_ratio: float
    reduced_code: str
    preserved_bug: bool
    reduction_steps: int
    error_messages: List[str] = None


class DeltaDebugger:
    """Delta debugging implementation for JavaScript code reduction."""
    
    def __init__(self, engines: List[str] = None):
        self.engines = engines or ["graaljs", "hermes", "v8"]
        self.test_function = None
    
    def reduce(self, finding: DifferentialFinding, 
              test_function: Callable[[str], bool]) -> ReductionResult:
        """Reduce a JavaScript program while preserving the bug."""
        self.test_function = test_function
        original_code = finding.input_js
        original_size = len(original_code)
        
        # Start with the original code
        current_code = original_code
        reduction_steps = 0
        
        # Apply different reduction strategies
        strategies = [
            self._remove_comments_and_whitespace,
            self._remove_unused_variables,
            self._remove_unused_functions,
            self._simplify_expressions,
            self._delta_debugging
        ]
        
        for strategy in strategies:
            if not self.test_function(current_code):
                break  # Bug is no longer preserved
                
            reduced_code = strategy(current_code)
            if reduced_code != current_code:
                current_code = reduced_code
                reduction_steps += 1
        
        reduced_size = len(current_code)
        reduction_ratio = (original_size - reduced_size) / original_size
        
        return ReductionResult(
            original_size=original_size,
            reduced_size=reduced_size,
            reduction_ratio=reduction_ratio,
            reduced_code=current_code,
            preserved_bug=self.test_function(current_code),
            reduction_steps=reduction_steps
        )
    
    def _remove_comments_and_whitespace(self, code: str) -> str:
        """Remove comments and unnecessary whitespace."""
        lines = code.split('\n')
        cleaned_lines = []
        
        for line in lines:
            # Remove comments
            if '//' in line:
                line = line.split('//')[0]
            
            # Remove trailing whitespace
            line = line.rstrip()
            
            # Keep non-empty lines
            if line.strip():
                cleaned_lines.append(line)
        
        return '\n'.join(cleaned_lines)
    
    def _remove_unused_variables(self, code: str) -> str:
        """Remove unused variable declarations."""
        # This is a simplified implementation
        # In practice, you'd need a proper JavaScript parser
        lines = code.split('\n')
        used_vars = set()
        var_declarations = []
        
        # Find variable declarations
        for i, line in enumerate(lines):
            if any(keyword in line for keyword in ['var ', 'let ', 'const ']):
                var_declarations.append((i, line))
        
        # Find variable usage
        for line in lines:
            for var_decl in var_declarations:
                var_name = self._extract_var_name(var_decl[1])
                if var_name and var_name in line and line != var_decl[1]:
                    used_vars.add(var_name)
        
        # Remove unused declarations
        result_lines = []
        for i, line in enumerate(lines):
            if any(keyword in line for keyword in ['var ', 'let ', 'const ']):
                var_name = self._extract_var_name(line)
                if var_name not in used_vars:
                    continue  # Skip unused variable
            result_lines.append(line)
        
        return '\n'.join(result_lines)
    
    def _extract_var_name(self, declaration: str) -> Optional[str]:
        """Extract variable name from declaration."""
        import re
        match = re.search(r'(?:var|let|const)\s+(\w+)', declaration)
        return match.group(1) if match else None
    
    def _remove_unused_functions(self, code: str) -> str:
        """Remove unused function declarations."""
        # Simplified implementation
        # In practice, you'd need proper JavaScript parsing
        return code  # Placeholder
    
    def _simplify_expressions(self, code: str) -> str:
        """Simplify complex expressions."""
        # Simplified implementation
        return code  # Placeholder
    
    def _delta_debugging(self, code: str) -> str:
        """Apply delta debugging algorithm."""
        if len(code) < 10:
            return code
        
        # Split code into chunks
        chunks = self._split_into_chunks(code)
        
        # Try removing chunks one by one
        for i in range(len(chunks)):
            test_code = ''.join(chunks[:i] + chunks[i+1:])
            if self.test_function(test_code):
                return test_code
        
        # Try removing chunks in pairs
        for i in range(0, len(chunks), 2):
            if i + 1 < len(chunks):
                test_code = ''.join(chunks[:i] + chunks[i+2:])
                if self.test_function(test_code):
                    return test_code
        
        return code
    
    def _split_into_chunks(self, code: str) -> List[str]:
        """Split code into logical chunks."""
        # Split by statements (semicolons and braces)
        import re
        chunks = re.split(r'([;{}])', code)
        return [chunk for chunk in chunks if chunk.strip()]


class DifferentialReducer:
    """Main reducer for differential testing findings."""
    
    def __init__(self, engines: List[str] = None):
        self.engines = engines or ["graaljs", "hermes", "v8"]
        self.delta_debugger = DeltaDebugger(engines)
    
    def reduce_finding(self, finding: DifferentialFinding, 
                      output_dir: Path = None) -> ReductionResult:
        """Reduce a single finding."""
        # Create test function that checks if the bug is preserved
        test_function = self._create_test_function(finding)
        
        # Apply reduction
        result = self.delta_debugger.reduce(finding, test_function)
        
        # Save reduced code if output directory is provided
        if output_dir and result.reduced_code != finding.input_js:
            self._save_reduced_code(finding, result, output_dir)
        
        return result
    
    def reduce_findings(self, findings: List[DifferentialFinding], 
                       output_dir: Path = None) -> List[ReductionResult]:
        """Reduce multiple findings."""
        results = []
        
        for finding in findings:
            try:
                result = self.reduce_finding(finding, output_dir)
                results.append(result)
            except Exception as e:
                print(f"Warning: Failed to reduce finding {finding.finding_path}: {e}")
        
        return results
    
    def _create_test_function(self, finding: DifferentialFinding) -> Callable[[str], bool]:
        """Create a test function that checks if the bug is preserved."""
        def test_function(code: str) -> bool:
            try:
                # Create a temporary file with the test code
                with tempfile.NamedTemporaryFile(mode='w', suffix='.js', delete=False) as f:
                    f.write(code)
                    temp_file = f.name
                
                # Test with each engine
                results = {}
                for engine in self.engines:
                    engine_name = f"engine_{engine}"
                    if engine_name in finding.engine_outputs:
                        original_output = finding.engine_outputs[engine_name]
                        current_output = self._run_engine(engine, temp_file)
                        
                        # Check if the discrepancy is preserved
                        if self._discrepancy_preserved(original_output, current_output, finding):
                            results[engine] = current_output
                
                # Clean up
                os.unlink(temp_file)
                
                # Return True if the bug is preserved
                return len(results) > 0
                
            except Exception as e:
                print(f"Error in test function: {e}")
                return False
        
        return test_function
    
    def _run_engine(self, engine: str, file_path: str) -> EngineOutput:
        """Run a JavaScript engine on a file."""
        try:
            if engine == "graaljs":
                cmd = ["graaljs", file_path]
            elif engine == "hermes":
                cmd = ["hermes", file_path]
            elif engine == "v8":
                cmd = ["node", file_path]
            else:
                raise ValueError(f"Unknown engine: {engine}")
            
            result = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=30  # 30 second timeout
            )
            
            return EngineOutput(
                engine_name=f"engine_{engine}",
                command=" ".join(cmd),
                exit_code=result.returncode,
                stdout=result.stdout,
                stderr=result.stderr
            )
            
        except subprocess.TimeoutExpired:
            return EngineOutput(
                engine_name=f"engine_{engine}",
                command=" ".join(cmd),
                exit_code=-1,
                stdout="",
                stderr="timeout"
            )
        except Exception as e:
            return EngineOutput(
                engine_name=f"engine_{engine}",
                command=" ".join(cmd),
                exit_code=-1,
                stdout="",
                stderr=str(e)
            )
    
    def _discrepancy_preserved(self, original: EngineOutput, current: EngineOutput, 
                             finding: DifferentialFinding) -> bool:
        """Check if the discrepancy is preserved between original and current outputs."""
        # Check if exit codes match
        if original.exit_code != current.exit_code:
            return True
        
        # Check if stdout differs
        if original.stdout.strip() != current.stdout.strip():
            return True
        
        # Check if stderr differs
        if original.stderr.strip() != current.stderr.strip():
            return True
        
        return False
    
    def _save_reduced_code(self, finding: DifferentialFinding, result: ReductionResult, 
                          output_dir: Path):
        """Save the reduced code to a file."""
        output_dir = Path(output_dir)
        output_dir.mkdir(parents=True, exist_ok=True)
        
        # Create a filename based on the original finding
        finding_name = finding.finding_path.name
        reduced_file = output_dir / f"{finding_name}_reduced.js"
        
        with open(reduced_file, 'w') as f:
            f.write(result.reduced_code)
        
        # Save reduction metadata
        metadata_file = output_dir / f"{finding_name}_reduction_metadata.json"
        import json
        metadata = {
            "original_size": result.original_size,
            "reduced_size": result.reduced_size,
            "reduction_ratio": result.reduction_ratio,
            "preserved_bug": result.preserved_bug,
            "reduction_steps": result.reduction_steps
        }
        
        with open(metadata_file, 'w') as f:
            json.dump(metadata, f, indent=2)


def create_test_function_for_finding(finding: DifferentialFinding) -> Callable[[str], bool]:
    """Create a test function for a specific finding."""
    reducer = DifferentialReducer()
    return reducer._create_test_function(finding) 