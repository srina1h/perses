# JavaScript Differential Testing Error Reduction Framework

This framework is designed to reduce and analyze multiple errors found from differential testing campaigns between JavaScript engines (GraalJS, Hermes, V8).

## Overview

The framework processes differential findings with the following structure:
```
├── differential_results.txt
├── engine_graaljs/
│   ├── command.txt
│   ├── exit_code.txt
│   ├── stderr.txt
│   └── stdout.txt
├── engine_hermes/
├── engine_v8/
├── input.js
├── seed.js
└── summary.txt
```

## Components

### 1. Finding Parser (`finding_parser.py`)
- Parses individual finding folders
- Extracts engine outputs and metadata
- Identifies discrepancy types

### 2. Error Classifier (`error_classifier.py`)
- Categorizes errors by type and severity
- Groups similar error patterns
- Identifies unique vs. duplicate issues

### 3. Finding Deduplicator (`deduplicator.py`)
- Groups similar findings together
- Reduces redundant error reports
- Identifies root cause patterns

### 4. Reduction Engine (`reducer.py`)
- Minimizes test cases while preserving bugs
- Applies delta debugging techniques
- Creates minimal reproducing examples

### 5. Report Generator (`reporter.py`)
- Generates summary reports
- Creates categorized error lists
- Provides reduction statistics

## Usage

### Basic Usage
```bash
# Process all findings in a directory (automatically skips invalid folders)
python main.py --input-dir results/differential_findings_javascript --output-dir reduced_findings

# Analyze specific finding
python main.py --finding-path path/to/specific/finding

# Generate summary report
python main.py --report-only --input-dir results/differential_findings_javascript
```

### Semantic Enhancement Usage
```bash
# Process with semantic similarity analysis and clustering
python main.py --input-dir results/differential_findings_javascript --semantic

# Customize semantic analysis parameters
python main.py --input-dir results/differential_findings_javascript --semantic --semantic-threshold 0.9 --cluster-eps 0.2

# Compare pattern-based vs semantic analysis
python main.py --input-dir results/differential_findings_javascript --report-only  # Pattern-based
python main.py --input-dir results/differential_findings_javascript --report-only --semantic  # Semantic-enhanced
```

### Quick Demo
```bash
# Run the demo script to compare both approaches
python run_semantic_demo.py results/differential_findings_javascript
```

## Requirements

- Python 3.8+
- Required packages: see `requirements.txt`

### Optional Semantic Enhancement
For semantic similarity analysis and clustering:
```bash
pip install scikit-learn sentence-transformers numpy
```

The semantic enhancement uses the `all-MiniLM-L6-v2` model for generating embeddings, which will be downloaded automatically on first use. 