"""
Error Classifier for JavaScript Differential Testing Results

This module categorizes errors by type and severity, groups similar error patterns,
and identifies unique vs. duplicate issues.
"""

import re
from typing import Dict, List, Set, Tuple, Optional
from dataclasses import dataclass
from enum import Enum
from difflib import SequenceMatcher
from finding_parser import DifferentialFinding, EngineOutput, DiscrepancyType


class ErrorSeverity(Enum):
    """Severity levels for errors."""
    CRITICAL = "critical"
    HIGH = "high"
    MEDIUM = "medium"
    LOW = "low"
    INFO = "info"


class ErrorCategory(Enum):
    """Categories of JavaScript errors."""
    # Differential errors
    SYNTAX_ERROR = "syntax_error"
    RUNTIME_ERROR = "runtime_error"
    TYPE_ERROR = "type_error"
    REFERENCE_ERROR = "reference_error"
    RANGE_ERROR = "range_error"
    URI_ERROR = "uri_error"
    EVAL_ERROR = "eval_error"
    TIMEOUT_ERROR = "timeout_error"
    MEMORY_ERROR = "memory_error"
    
    # Crash errors
    SEGMENTATION_FAULT = "segmentation_fault"
    ASSERTION_FAILURE = "assertion_failure"
    FATAL_ERROR = "fatal_error"
    ABORT_ERROR = "abort_error"
    CORE_DUMP = "core_dump"
    
    UNKNOWN_ERROR = "unknown_error"


@dataclass
class ErrorSignature:
    """Represents a unique error signature for deduplication."""
    category: ErrorCategory
    severity: ErrorSeverity
    error_pattern: str
    engine_combination: Tuple[str, ...]
    exit_code_pattern: Tuple[int, ...]
    normalized_message: str


@dataclass
class ClassifiedError:
    """Represents a classified error with metadata."""
    finding: DifferentialFinding
    signature: ErrorSignature
    confidence: float
    related_findings: List[str] = None


class ErrorClassifier:
    """Classifier for JavaScript differential testing errors."""
    
    def __init__(self):
        self.error_patterns = self._initialize_error_patterns()
        self.severity_weights = self._initialize_severity_weights()
    
    def classify_finding(self, finding: DifferentialFinding) -> ClassifiedError:
        """Classify a single finding."""
        # Extract error patterns from stderr
        error_patterns = self._extract_error_patterns(finding)
        
        # Determine error category
        category = self._determine_error_category(finding, error_patterns)
        
        # Determine severity
        severity = self._determine_severity(finding, category)
        
        # Create error signature
        signature = self._create_error_signature(finding, category, severity, error_patterns)
        
        # Calculate confidence
        confidence = self._calculate_confidence(finding, signature)
        
        return ClassifiedError(
            finding=finding,
            signature=signature,
            confidence=confidence
        )
    
    def classify_findings(self, findings: List[DifferentialFinding]) -> List[ClassifiedError]:
        """Classify multiple findings."""
        classified_errors = []
        for finding in findings:
            try:
                classified_error = self.classify_finding(finding)
                classified_errors.append(classified_error)
            except Exception as e:
                print(f"Warning: Failed to classify finding {finding.finding_path}: {e}")
        
        return classified_errors
    
    def group_similar_errors(self, classified_errors: List[ClassifiedError], 
                           similarity_threshold: float = 0.8) -> List[List[ClassifiedError]]:
        """Group similar errors together."""
        groups = []
        processed = set()
        
        for i, error1 in enumerate(classified_errors):
            if i in processed:
                continue
            
            group = [error1]
            processed.add(i)
            
            for j, error2 in enumerate(classified_errors[i+1:], i+1):
                if j in processed:
                    continue
                
                if self._are_errors_similar(error1, error2, similarity_threshold):
                    group.append(error2)
                    processed.add(j)
            
            groups.append(group)
        
        return groups
    
    def _initialize_error_patterns(self) -> Dict[ErrorCategory, List[str]]:
        """Initialize common JavaScript error patterns."""
        return {
            # Differential error patterns
            ErrorCategory.SYNTAX_ERROR: [
                r"SyntaxError",
                r"Unexpected token",
                r"Missing \w+",
                r"Invalid or unexpected token",
                r"Unexpected end of input"
            ],
            ErrorCategory.TYPE_ERROR: [
                r"TypeError",
                r"Cannot read property",
                r"Cannot set property",
                r"is not a function",
                r"is not iterable"
            ],
            ErrorCategory.REFERENCE_ERROR: [
                r"ReferenceError",
                r"is not defined",
                r"Cannot access",
                r"Undeclared variable"
            ],
            ErrorCategory.RANGE_ERROR: [
                r"RangeError",
                r"Maximum call stack size exceeded",
                r"Invalid array length"
            ],
            ErrorCategory.URI_ERROR: [
                r"URIError",
                r"URI malformed"
            ],
            ErrorCategory.EVAL_ERROR: [
                r"EvalError"
            ],
            ErrorCategory.TIMEOUT_ERROR: [
                r"timeout",
                r"timed out",
                r"execution timeout"
            ],
            ErrorCategory.MEMORY_ERROR: [
                r"out of memory",
                r"memory limit exceeded",
                r"heap out of memory"
            ],
            
            # Crash error patterns
            ErrorCategory.SEGMENTATION_FAULT: [
                r"segmentation fault",
                r"segfault",
                r"signal 11",
                r"signal 6"
            ],
            ErrorCategory.ASSERTION_FAILURE: [
                r"assertion failed",
                r"assertion failure",
                r"ASSERTION FAILED"
            ],
            ErrorCategory.FATAL_ERROR: [
                r"fatal error",
                r"FATAL ERROR",
                r"fatal exception"
            ],
            ErrorCategory.ABORT_ERROR: [
                r"abort",
                r"ABORT",
                r"aborted"
            ],
            ErrorCategory.CORE_DUMP: [
                r"core dumped",
                r"core dump",
                r"dumped core"
            ]
        }
    
    def _initialize_severity_weights(self) -> Dict[ErrorCategory, ErrorSeverity]:
        """Initialize severity weights for different error categories."""
        return {
            # Differential error severities
            ErrorCategory.SYNTAX_ERROR: ErrorSeverity.HIGH,
            ErrorCategory.TYPE_ERROR: ErrorSeverity.MEDIUM,
            ErrorCategory.REFERENCE_ERROR: ErrorSeverity.MEDIUM,
            ErrorCategory.RANGE_ERROR: ErrorSeverity.HIGH,
            ErrorCategory.URI_ERROR: ErrorSeverity.LOW,
            ErrorCategory.EVAL_ERROR: ErrorSeverity.HIGH,
            ErrorCategory.TIMEOUT_ERROR: ErrorSeverity.MEDIUM,
            ErrorCategory.MEMORY_ERROR: ErrorSeverity.CRITICAL,
            
            # Crash error severities (all critical)
            ErrorCategory.SEGMENTATION_FAULT: ErrorSeverity.CRITICAL,
            ErrorCategory.ASSERTION_FAILURE: ErrorSeverity.CRITICAL,
            ErrorCategory.FATAL_ERROR: ErrorSeverity.CRITICAL,
            ErrorCategory.ABORT_ERROR: ErrorSeverity.CRITICAL,
            ErrorCategory.CORE_DUMP: ErrorSeverity.CRITICAL,
            
            ErrorCategory.UNKNOWN_ERROR: ErrorSeverity.LOW
        }
    
    def _extract_error_patterns(self, finding: DifferentialFinding) -> List[str]:
        """Extract error patterns from stderr outputs."""
        patterns = []
        for engine_output in finding.engine_outputs.values():
            if engine_output.stderr:
                # Extract error messages
                lines = engine_output.stderr.split('\n')
                for line in lines:
                    line = line.strip()
                    if line and any(error_pattern in line for error_pattern in 
                                   [r"Error:", r"Exception:", r"SyntaxError", r"TypeError"]):
                        patterns.append(line)
        return patterns
    
    def _determine_error_category(self, finding: DifferentialFinding, 
                                error_patterns: List[str]) -> ErrorCategory:
        """Determine the error category based on patterns and outputs."""
        stderr_text = " ".join([output.stderr for output in finding.engine_outputs.values()])
        stderr_lower = stderr_text.lower()
        
        # Check for specific error categories
        for category, patterns in self.error_patterns.items():
            for pattern in patterns:
                if re.search(pattern, stderr_text, re.IGNORECASE):
                    return category
        
        # Check for exit code patterns
        exit_codes = [output.exit_code for output in finding.engine_outputs.values()]
        if any(code != 0 for code in exit_codes):
            if finding.discrepancy_type == DiscrepancyType.TIMEOUT_DIFFERENCE:
                return ErrorCategory.TIMEOUT_ERROR
            elif "memory" in stderr_lower:
                return ErrorCategory.MEMORY_ERROR
            else:
                return ErrorCategory.RUNTIME_ERROR
        
        return ErrorCategory.UNKNOWN_ERROR
    
    def _determine_severity(self, finding: DifferentialFinding, 
                          category: ErrorCategory) -> ErrorSeverity:
        """Determine the severity of the error."""
        base_severity = self.severity_weights.get(category, ErrorSeverity.LOW)
        
        # Adjust severity based on finding characteristics
        if finding.discrepancy_type == DiscrepancyType.EXIT_CODE_DIFFERENCE:
            # Exit code differences are usually more severe
            if base_severity == ErrorSeverity.LOW:
                return ErrorSeverity.MEDIUM
            elif base_severity == ErrorSeverity.MEDIUM:
                return ErrorSeverity.HIGH
        
        # Check if multiple engines are affected
        if len(finding.engine_outputs) > 2:
            return ErrorSeverity.HIGH
        
        return base_severity
    
    def _create_error_signature(self, finding: DifferentialFinding, 
                              category: ErrorCategory, severity: ErrorSeverity,
                              error_patterns: List[str]) -> ErrorSignature:
        """Create a unique error signature for deduplication."""
        # Normalize error message
        normalized_message = self._normalize_error_message(error_patterns)
        
        # Get engine combination
        engine_combination = tuple(sorted(finding.engine_outputs.keys()))
        
        # Get exit code pattern
        exit_code_pattern = tuple(sorted(
            output.exit_code for output in finding.engine_outputs.values()
        ))
        
        # Create error pattern
        error_pattern = "|".join(error_patterns[:3])  # Take first 3 patterns
        
        return ErrorSignature(
            category=category,
            severity=severity,
            error_pattern=error_pattern,
            engine_combination=engine_combination,
            exit_code_pattern=exit_code_pattern,
            normalized_message=normalized_message
        )
    
    def _normalize_error_message(self, error_patterns: List[str]) -> str:
        """Normalize error message for comparison."""
        if not error_patterns:
            return ""
        
        # Take the first error pattern and normalize it
        message = error_patterns[0]
        
        # Remove line numbers and file paths
        message = re.sub(r'at .*:\d+:\d+', '', message)
        message = re.sub(r'\(.*?\)', '', message)
        
        # Remove extra whitespace
        message = re.sub(r'\s+', ' ', message).strip()
        
        return message
    
    def _calculate_confidence(self, finding: DifferentialFinding, 
                            signature: ErrorSignature) -> float:
        """Calculate confidence in the classification."""
        confidence = 0.5  # Base confidence
        
        # Increase confidence based on clear error patterns
        if signature.error_pattern:
            confidence += 0.2
        
        # Increase confidence for specific error categories
        if signature.category != ErrorCategory.UNKNOWN_ERROR:
            confidence += 0.2
        
        # Increase confidence for clear discrepancy types
        if finding.discrepancy_type != DiscrepancyType.UNKNOWN:
            confidence += 0.1
        
        return min(confidence, 1.0)
    
    def _are_errors_similar(self, error1: ClassifiedError, error2: ClassifiedError,
                          threshold: float) -> bool:
        """Check if two errors are similar enough to be grouped together."""
        # Check if they have the same category and severity
        if (error1.signature.category != error2.signature.category or
            error1.signature.severity != error2.signature.severity):
            return False
        
        # Check if they have the same engine combination
        if error1.signature.engine_combination != error2.signature.engine_combination:
            return False
        
        # Check if they have the same exit code pattern
        if error1.signature.exit_code_pattern != error2.signature.exit_code_pattern:
            return False
        
        # Check message similarity
        similarity = SequenceMatcher(None, 
                                   error1.signature.normalized_message,
                                   error2.signature.normalized_message).ratio()
        
        return similarity >= threshold 