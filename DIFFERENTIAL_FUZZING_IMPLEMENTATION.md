# Differential Fuzzing Implementation in Kitten

## Overview

I have successfully implemented differential fuzzing in kitten, which allows running the same inputs on multiple JavaScript engines and detecting discrepancies in their behavior. This implementation integrates seamlessly with the existing kitten fuzzing workflow while adding powerful differential testing capabilities.

## Key Components Added

### 1. Core Differential Testing Classes

#### `DifferentialTestResult.kt`
- **Location**: `kitten/src/org/perses/fuzzer/compilers/DifferentialTestResult.kt`
- **Purpose**: Data class that represents the results of differential testing
- **Features**:
  - Stores results from multiple engines
  - Tracks discrepancies between engines
  - Supports different types of discrepancies (exit codes, stdout, stderr, crashes)

#### `DifferentialTester.kt`
- **Location**: `kitten/src/org/perses/fuzzer/compilers/DifferentialTester.kt`
- **Purpose**: Main class that orchestrates differential testing
- **Features**:
  - Runs the same input on multiple engines
  - Compares outputs and detects discrepancies
  - Supports engine name detection from commands
  - Comprehensive discrepancy detection logic

#### `DifferentialFindingFolder.kt`
- **Location**: `kitten/src/org/perses/fuzzer/DifferentialFindingFolder.kt`
- **Purpose**: Manages storage of differential findings
- **Features**:
  - Creates organized folder structure for findings
  - Saves input files, seed files, and engine outputs
  - Generates detailed reports and summaries

### 2. Integration with Existing Fuzzer

#### Modified `FuzzerDriver.kt`
- **Changes**:
  - Added `DifferentialTester` instance
  - Modified `testWithFuzzer` method to use differential testing
  - Added `testDifferentially` method
  - Maintains backward compatibility with traditional crash detection

#### Updated Build Configuration
- **Files Modified**:
  - `kitten/src/org/perses/fuzzer/BUILD`
  - `kitten/src/org/perses/fuzzer/compilers/BUILD`
- **Changes**: Added new source files to build targets

### 3. Configuration and Scripts

#### `differential-testing-config.yaml`
- **Location**: `kitten/scripts/javascript/differential-testing-config.yaml`
- **Purpose**: Configuration for differential testing with multiple JavaScript engines
- **Engines Supported**:
  - V8
  - Hermes
  - GraalJS
  - JavaScriptCore (JSC)

#### `launch_differential_testing.sh`
- **Location**: `kitten/scripts/javascript/launch_differential_testing.sh`
- **Purpose**: Main script to launch differential testing
- **Features**:
  - Sets up differential testing folders
  - Configures multiple engines
  - Provides clear output and logging

#### `test_differential.sh`
- **Location**: `kitten/scripts/javascript/test_differential.sh`
- **Purpose**: Test script for verifying differential testing functionality
- **Features**:
  - Quick test with limited iterations
  - Lower resource requirements
  - Suitable for development and testing

## Types of Discrepancies Detected

1. **Exit Code Mismatch**: Different engines return different exit codes
2. **STDOUT Mismatch**: Different engines produce different standard output
3. **STDERR Mismatch**: Different engines produce different error messages
4. **Crash vs No Crash**: One engine crashes while another doesn't
5. **Different Crash Signatures**: Both engines crash but with different error signatures

## Output Structure

Differential findings are saved in organized folders with the following structure:

```
differential_finding_YYYYMMDD_HHMMSS_<timestamp>/
├── input.js                    # The input that caused the discrepancy
├── seed.js                     # The original seed file
├── differential_results.txt    # Detailed discrepancy analysis
├── summary.txt                 # High-level summary
└── engine_<name>/              # Per-engine outputs
    ├── command.txt             # Command executed
    ├── exit_code.txt           # Exit code
    ├── stdout.txt              # Standard output
    └── stderr.txt              # Standard error
```

## Usage Examples

### Quick Start
```bash
# Run differential testing with all configured engines
./kitten/scripts/javascript/launch_differential_testing.sh
```

### Test the Implementation
```bash
# Run a quick test to verify functionality
./kitten/scripts/javascript/test_differential.sh
```

### Custom Configuration
1. Modify `differential-testing-config.yaml` to add/remove engines
2. Update engine paths if needed
3. Add new crash detectors for custom engines

## Integration Benefits

### Seamless Integration
- **Backward Compatibility**: Traditional crash detection still works
- **Existing Workflow**: Integrates with current fuzzing pipeline
- **Coverage Collection**: Maintains existing coverage tracking
- **Mutation Logic**: Uses existing mutation operators

### Enhanced Bug Detection
- **Cross-Engine Validation**: Finds bugs that affect only some engines
- **Specification Violations**: Detects when engines don't follow the same spec
- **Implementation Differences**: Uncovers subtle behavioral differences
- **Regression Detection**: Can detect when one engine regresses

## Performance Considerations

- **Multi-Engine Overhead**: Each input is tested on multiple engines
- **Resource Usage**: Higher memory and CPU requirements
- **Scalability**: Can be tuned by reducing threads or engine count
- **Timeout Management**: Each engine has its own timeout

## Future Enhancements

1. **More Engine Support**: Add support for additional JavaScript engines
2. **Custom Discrepancy Types**: Allow users to define custom comparison logic
3. **Statistical Analysis**: Add statistical significance testing for discrepancies
4. **Automated Reporting**: Generate automated reports and summaries
5. **Integration with CI/CD**: Add differential testing to continuous integration

## Testing and Validation

The implementation includes:
- **Build Verification**: All new code compiles successfully
- **Integration Testing**: Works with existing kitten infrastructure
- **Test Scripts**: Ready-to-use test scripts for validation
- **Documentation**: Comprehensive documentation and examples

## Conclusion

This differential fuzzing implementation significantly enhances kitten's bug detection capabilities by comparing behavior across multiple JavaScript engines. It maintains full backward compatibility while adding powerful new testing capabilities that can uncover subtle bugs and implementation differences that would be missed by single-engine testing.

The implementation is production-ready and can be immediately used to find bugs in JavaScript engines through differential testing. 