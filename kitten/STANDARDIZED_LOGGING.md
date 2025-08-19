# Standardized Logging for Differential Testing

This document describes the new standardized logging system for differential testing in Kitten, which provides a consistent, line-by-line format for comparing outputs across multiple JavaScript engines.

## Overview

The standardized logging system addresses the need for efficient comparison of fuzzer outputs by:

1. **Unique Test IDs**: Each test case gets a unique hash-based identifier
2. **Line-by-Line Comparison**: Outputs are formatted in tables with numbered lines
3. **Standardized Status Codes**: Consistent classification of execution results
4. **Multiple Output Formats**: Both human-readable tables and machine-readable CSV
5. **Efficient Discrepancy Detection**: Quick identification of differences between engines

## Key Components

### 1. StandardizedOutputLogger

The main class that handles the standardized logging functionality:

- **Location**: `kitten/src/org/perses/fuzzer/compilers/StandardizedOutputLogger.kt`
- **Purpose**: Converts raw engine outputs into standardized format with line numbers

#### Key Methods:

- `generateTestId(inputFile)`: Creates unique test ID based on file content and timestamp
- `standardizeOutput(testId, inputFile, engineName, result)`: Converts raw output to standardized format
- `formatAsTable(outputs)`: Creates human-readable table with line-by-line comparison
- `formatAsCSV(outputs)`: Creates machine-readable CSV format
- `saveToFile(outputs, outputFile)`: Saves formatted output to file

#### Map-Based Comparison Methods (NEW):

- `createComparisonMap(outputs)`: Creates map-based comparison structure for O(1) lookups
- `detectDiscrepanciesQuick(comparisonMap)`: Performs fast discrepancy detection using maps
- `findLineDifferences(comparisonMap)`: Finds line-by-line differences using map approach
- `compareEngines(comparisonMap, engine1, engine2)`: Compares two specific engines quickly

### 2. Enhanced DifferentialTester

Updated to support standardized logging:

- **New Method**: `testDifferentiallyWithStandardizedLogging(inputFile, outputDirectory)`
- **Returns**: Both traditional `DifferentialTestResult` and standardized outputs
- **Features**: Automatic file generation and logging

### 3. Updated DifferentialFindingFolder

Enhanced to save standardized outputs:

- **New Files**: `standardized_output_table.txt` and `standardized_output.csv`
- **Integration**: Automatically generated for each differential finding

## Output Format

### Table Format Example

```
=== STANDARDIZED DIFFERENTIAL TEST OUTPUT ===
Test ID: a1b2c3d4
Input File: test_case.js
Timestamp: 2025-01-15T14:30:25
Number of Engines: 3

=== EXECUTION SUMMARY ===
Engine Name | Exit Code | Status | Execution Time (ms) | Error Type
------------|-----------|--------|-------------------|-----------
V8          | 0         | SUCCESS| 45                | N/A
GraalJS     | 1         | ERROR  | 67                | TypeError
JavaScriptCore | 0      | SUCCESS| 52                | N/A

=== DETAILED OUTPUT COMPARISON ===
--- STDOUT COMPARISON ---
Line | V8          | GraalJS     | JavaScriptCore
-----|-------------|-------------|---------------
1    | Hello World |             | Hello World
2    | 42          |             | 42

--- STDERR COMPARISON ---
Line | V8          | GraalJS     | JavaScriptCore
-----|-------------|-------------|---------------
1    |             | TypeError:  |             
2    |             | Cannot read |             

=== DISCREPANCY ANALYSIS ===
Discrepancy 1: Status mismatch: SUCCESS vs ERROR
Discrepancy 2: Exit code mismatch: 0 vs 1
Discrepancy 3: STDOUT content mismatch between engines
```

### CSV Format

```csv
test_id,timestamp,input_file,engine_name,exit_code,execution_time_ms,status,stdout_lines,stderr_lines,crash_signature,error_type
a1b2c3d4,2025-01-15T14:30:25,test_case.js,V8,0,45,SUCCESS,"Hello World\n42","",,
a1b2c3d4,2025-01-15T14:30:25,test_case.js,GraalJS,1,67,ERROR,"","TypeError: Cannot read property 'x' of undefined",,TypeError
a1b2c3d4,2025-01-15T14:30:25,test_case.js,JavaScriptCore,0,52,SUCCESS,"Hello World\n42","",,
```

## Execution Status Types

The system classifies execution results into these standardized statuses:

- **SUCCESS**: Exit code 0, no errors
- **ERROR**: Non-zero exit code, stderr present
- **CRASH**: Segmentation fault, crash detected
- **HANG**: Timeout or infinite loop detected
- **TIMEOUT**: Explicit timeout (exit code 124)

## Usage

### In Code

```kotlin
// Use the new standardized logging method
val (differentialResult, standardizedOutputs) = differentialTester.testDifferentiallyWithStandardizedLogging(
    inputFile = testFile,
    outputDirectory = outputDir
)

// Access standardized outputs
standardizedOutputs.forEach { output ->
    println("Engine: ${output.engineName}, Status: ${output.status}")
}
```

### Analysis Scripts

#### Traditional Analysis Script

Use the provided Python analysis script:

```bash
# Analyze all outputs in a directory
python3 kitten/scripts/analyze_standardized_outputs.py /path/to/outputs

# Export discrepancies to CSV
python3 kitten/scripts/analyze_standardized_outputs.py /path/to/outputs --export discrepancies.csv

# Filter by discrepancy type
python3 kitten/scripts/analyze_standardized_outputs.py /path/to/outputs --type status_mismatch

# Compare specific engines
python3 kitten/scripts/analyze_standardized_outputs.py /path/to/outputs --compare V8 GraalJS
```

#### Quick Analysis Script (NEW - Map-Based)

For much faster analysis using map-based comparison:

```bash
# Quick analysis with performance benchmark
python3 kitten/scripts/quick_discrepancy_analyzer.py /path/to/outputs --benchmark

# Quick analysis with export
python3 kitten/scripts/quick_discrepancy_analyzer.py /path/to/outputs --export quick_discrepancies.csv

# Compare specific engines quickly
python3 kitten/scripts/quick_discrepancy_analyzer.py /path/to/outputs --compare V8 GraalJS
```

## Benefits

### 1. Efficient Comparison
- Line-by-line comparison makes discrepancies immediately visible
- Standardized format eliminates parsing inconsistencies
- Quick identification of which engines differ and how

### 2. Map-Based Quick Detection (NEW)
- **O(1) lookup time** for discrepancy detection using hash maps
- **Set-based operations** for fast content comparison
- **Line-indexed maps** for instant line-by-line difference detection
- **Significant performance improvement** over traditional approaches

### 3. Comprehensive Coverage
- Captures all types of discrepancies (status, exit codes, stdout, stderr)
- Includes execution timing and error classification
- Preserves crash signatures and error types

### 4. Machine Readable
- CSV format enables automated analysis
- Consistent structure across all test runs
- Easy integration with data analysis tools

### 5. Human Readable
- Table format provides clear visual comparison
- Line numbers make it easy to reference specific differences
- Summary sections highlight key discrepancies

## File Structure

When a discrepancy is found, the following files are created:

```
differential_finding_YYYYMMDD_HHMMSS_XXXXXXXXXX/
├── input.js                    # Original test case
├── seed.js                     # Seed file used
├── standardized_output_table.txt  # Human-readable comparison table
└── standardized_output.csv    # Machine-readable CSV data
```

**Note**: Standardized output files are only created when discrepancies are detected, keeping the output clean and focused.

## Integration

The standardized logging system is fully integrated with the existing differential testing workflow:

1. **Conditional Generation**: Standardized outputs are created only when discrepancies are found
2. **Backward Compatibility**: Traditional differential testing methods still work
3. **Enhanced Logging**: Additional logging provides test IDs and execution summaries
4. **Analysis Tools**: Python script provides comprehensive analysis capabilities
5. **Clean Output**: Only relevant files are saved, reducing clutter and improving performance

## Map-Based Comparison Architecture

### How It Works

The map-based comparison system creates multiple specialized maps for O(1) lookup performance:

1. **Status Map**: `Map<EngineName, ExecutionStatus>` - Quick status comparison
2. **Exit Code Map**: `Map<EngineName, Int>` - Fast exit code comparison
3. **Content Maps**: `Map<EngineName, Set<String>>` - Set-based content comparison
4. **Line-Indexed Maps**: `Map<LineNumber, Map<EngineName, String>>` - Instant line-by-line comparison

### Performance Benefits

- **Traditional Approach**: O(n²) comparison complexity for n engines
- **Map-Based Approach**: O(1) lookup time for most operations
- **Set Operations**: O(1) average case for content comparison
- **Line-by-Line**: Instant detection of specific line differences

### Example Performance

```kotlin
// Traditional approach (slow)
outputs.forEach { output1 ->
    outputs.forEach { output2 ->
        if (output1.stdoutLines != output2.stdoutLines) {
            // O(n²) complexity
        }
    }
}

// Map-based approach (fast)
val stdoutSets = comparisonMap.stdoutContentMap.values.toSet()
if (stdoutSets.size > 1) {
    // O(1) complexity
}
```

## Future Enhancements

Potential improvements to consider:

1. **Real-time Streaming**: Stream standardized outputs as tests run
2. **Database Integration**: Store standardized outputs in a database for long-term analysis
3. **Web Interface**: Create a web-based viewer for standardized outputs
4. **Statistical Analysis**: Add statistical analysis of discrepancy patterns
5. **Automated Reporting**: Generate automated reports from standardized outputs
6. **Caching**: Implement caching for frequently accessed comparison maps
7. **Parallel Processing**: Use parallel map operations for large datasets
