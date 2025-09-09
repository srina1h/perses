# Differential Findings Analysis

This directory contains scripts to analyze differential findings from JavaScript engine testing.

## Scripts

### `reduce.py` - Main Analysis Script

The main script that loads and analyzes all differential findings CSV files.

**Usage:**
```bash
python3 reduce.py [options]
```

**Options:**
- `--findings-dir PATH`: Directory containing differential finding folders (default: `8_29/differential_finding_folder_javascript`)
- `--output FILE`: Output file for detailed report (default: `differential_analysis_report.json`)
- `--no-summary`: Skip printing summary to console
- `--quiet`: Show only key statistics (less verbose)

**Examples:**
```bash
# Basic analysis
python3 reduce.py

# Quiet mode for quick overview
python3 reduce.py --quiet

# Custom findings directory
python3 reduce.py --findings-dir /path/to/findings

# Save report to custom location
python3 reduce.py --output my_analysis.json
```

### `summary.py` - Quick Summary Script

A simple script that provides a clean summary of the analysis results.

**Usage:**
```bash
python3 summary.py [report_file]
```

**Examples:**
```bash
# Use default report file
python3 summary.py

# Use custom report file
python3 summary.py my_analysis.json
```

### `exit_patterns.py` - Exit Code Pattern Analysis

Analyzes and displays exit code patterns across the 4 JavaScript engines.

**Usage:**
```bash
python3 exit_patterns.py
```

### `cluster_analysis.py` - TF-IDF Clustering Analysis

Analyzes clustering within each exit code pattern using TF-IDF.

**Usage:**
```bash
python3 cluster_analysis.py
```

### `organize_findings.py` - Create Organized Folder Structure

Creates a folder structure organized by exit code patterns and clusters for further analysis.

**Usage:**
```bash
python3 organize_findings.py
```

### `show_structure.py` - Show Organized Structure Overview

Provides an overview of the organized findings folder structure.

**Usage:**
```bash
python3 show_structure.py
```

### `explore_findings.py` - Explore Finding Data Files

Explores the types of files available in the finding data folders.

**Usage:**
```bash
python3 explore_findings.py
```

## Data Format

The scripts expect CSV files with the following structure:
- `standardized_output.csv` files in each finding folder
- CSV columns: `test_id`, `timestamp`, `input_file`, `engine_name`, `exit_code`, `execution_time_ms`, `status`, `stdout_lines`, `stderr_lines`, `crash_signature`, `error_type`

## Output

### Console Output
- Basic statistics (total findings, records, engines)
- Engine-specific performance metrics
- Status distribution
- Differential behavior analysis
- Error analysis

### JSON Report
The detailed report includes:
- `basic_stats`: Overall statistics and engine performance
- `differential_behavior`: Cases where engines behave differently
- `crash_analysis`: Error patterns and crash signatures
- `metadata`: Analysis timestamp and file counts

## Key Metrics

### Engine Performance
- **Success Rate**: Percentage of successful executions per engine
- **Error Distribution**: Types and frequencies of errors
- **Differential Cases**: Tests where engines produce different results

### Error Analysis
- **ReferenceError**: Most common error type (900 cases)
- **SyntaxError**: Second most common (104 cases)
- **TypeError**: Third most common (27 cases)

### Differential Behavior
- **Total Differential Cases**: 844 out of 1,039 findings (81.2%)
- **Stdout Differences**: 735 cases with different output

## Example Results

From a recent analysis:
- **V8**: 75.3% success rate (most successful)
- **JavaScriptCore**: 72.6% success rate
- **GraalJS**: 38.1% success rate
- **SpiderMonkey**: 26.8% success rate (least successful)

## Requirements

- Python 3.6+
- pandas
- scikit-learn (for TF-IDF clustering)
- pathlib (built-in)
- json (built-in)
- argparse (built-in)

## Troubleshooting

### CSV Parsing Errors
If you encounter CSV parsing errors, the script includes fallback parsing methods. Most malformed files will be skipped automatically.

### Memory Issues
For very large datasets, consider processing in smaller batches or using the `--quiet` flag to reduce memory usage.

### Engine Name Issues
The script filters to focus on the main JavaScript engines: V8, SpiderMonkey, JavaScriptCore, and GraalJS. Other engine names are excluded from the analysis.

## Folder Structure

After running `organize_findings.py`, you'll get a structured folder organization:

```
organized_findings/
├── summary.txt                    # Overall summary
├── pattern_7_0_3_0/              # Exit code pattern folder
│   ├── pattern_summary.txt        # Pattern-specific summary
│   ├── cluster_01/                # Cluster 1 (246 cases)
│   │   ├── cluster_summary.txt    # Cluster summary
│   │   ├── case_001/              # Individual case
│   │   │   ├── case_summary.txt   # Case summary
│   │   │   ├── finding_data/      # Original finding folder contents
│   │   │   │   ├── finding_summary.txt
│   │   │   │   ├── input.js       # The test input that caused the finding
│   │   │   │   ├── seed.js        # Original seed file
│   │   │   │   ├── standardized_output.csv
│   │   │   │   └── standardized_output_table.txt
│   │   │   ├── v8/                # V8 engine output
│   │   │   │   ├── stdout.txt
│   │   │   │   ├── stderr.txt
│   │   │   │   └── error.txt
│   │   │   ├── spidermonkey/      # SpiderMonkey output
│   │   │   ├── javascriptcore/    # JavaScriptCore output
│   │   │   └── graaljs/           # GraalJS output
│   │   └── case_002/              # Next case...
│   └── cluster_02/                # Cluster 2 (59 cases)
└── pattern_0_3_3_0/              # Next pattern...
```

This structure allows you to:
- Focus on specific exit code patterns
- Analyze clusters of similar findings
- Compare engine outputs for individual cases
- Navigate from high-level patterns to specific test cases
- **Access original test inputs** (`input.js`) that caused each finding
- **Examine seed files** (`seed.js`) that were mutated to create the test
- **Review complete finding context** with all original files preserved
