# Nuanced Differential Testing Findings Clusterer

A sophisticated clustering tool for reducing thousands of differential testing findings to a manageable set of representative cases.

## Overview

This tool provides **5 levels of clustering sophistication** to handle different needs:

- **Level 1**: Basic exit code patterns (fastest)
- **Level 2**: Error type clustering
- **Level 3**: Semantic similarity clustering (default)
- **Level 4**: Code pattern analysis
- **Level 5**: Advanced deduplication (most thorough)

## Quick Start

### Basic Usage
```bash
# Use default level 3 clustering
python nuanced_cluster.py /path/to/findings /path/to/output

# Use preset configurations
python run_clustering.py /path/to/findings /path/to/output --preset balanced

# Custom level and cluster size
python nuanced_cluster.py /path/to/findings /path/to/output --level 4 --max-per-cluster 10
```

### Preset Configurations
```bash
# Quick clustering (level 2, 3 reps per cluster)
python run_clustering.py findings/ output/ --preset quick

# Balanced clustering (level 3, 5 reps per cluster) - DEFAULT
python run_clustering.py findings/ output/ --preset balanced

# Thorough clustering (level 5, 10 reps per cluster)
python run_clustering.py findings/ output/ --preset thorough
```

## Clustering Levels Explained

### Level 1: Basic Exit Code Patterns
Groups findings by which engines succeed/fail:
- `all_pass`: All engines succeed
- `all_fail`: All engines fail  
- `v8_only_fails`: Only V8 fails
- `spidermonkey_only_fails`: Only SpiderMonkey fails
- `javascriptcore_only_fails`: Only JavaScriptCore fails
- `graaljs_only_fails`: Only GraalJS fails
- `multiple_engines_fail`: Multiple engines fail

**Use when**: You want the fastest clustering with basic categorization.

### Level 2: Error Type Clustering
Groups findings by the types of errors they produce:
- `SyntaxError`, `TypeError`, `ReferenceError`, etc.
- Considers which engines produce which error types

**Use when**: You want to focus on specific error categories.

### Level 3: Semantic Similarity Clustering
Groups findings by similarity of error messages:
- Analyzes error message content
- Groups findings with similar error patterns
- **Default level** - good balance of speed and accuracy

**Use when**: You want to group findings with similar root causes.

### Level 4: Code Pattern Analysis
Groups findings by code characteristics:
- Code size (small/medium/large)
- Complexity (functions, modern features)
- Language features used (arrow functions, BigInt, etc.)

**Use when**: You want to group by code structure patterns.

### Level 5: Advanced Deduplication
Comprehensive clustering using all available information:
- Exit codes + error types + code features
- Most thorough deduplication
- Slowest but most accurate

**Use when**: You need maximum deduplication and have time to wait.

## Input Structure

The tool expects findings in this structure:
```
findings/
├── finding_1/
│   ├── summary.txt
│   ├── input.js
│   ├── seed.js
│   ├── engine_v8/
│   │   ├── stdout.txt
│   │   ├── stderr.txt
│   │   └── exit_code.txt
│   ├── engine_spidermonkey/
│   ├── engine_javascriptcore/
│   └── engine_graaljs/
├── finding_2/
└── ...
```

## Output Structure

The tool creates:
```
output/
├── representative_0001_finding_name/
│   ├── [all original files]
│   └── metadata.json
├── representative_0002_finding_name/
├── ...
└── clustering_report.txt
```

Each representative includes a `metadata.json` with:
- Original finding name
- Exit codes for each engine
- Error types detected
- Input file size and hash

## Example Usage

### Test with your example finding
```bash
# Test with the bigIntGraalJS finding
python nuanced_cluster.py testing_crashes/bigIntGraalJS clustered_output

# Check the results
ls clustered_output/
cat clustered_output/clustering_report.txt
```

### Process large dataset
```bash
# For 10,000 findings, start with quick clustering
python run_clustering.py large_findings/ quick_output/ --preset quick

# Then run thorough clustering on the quick results
python run_clustering.py quick_output/ final_output/ --preset thorough
```

## Performance Guidelines

### For Large Datasets (10,000+ findings)
1. Start with **Level 2** or **Level 3** clustering
2. Use smaller `--max-per-cluster` values (3-5)
3. Process in batches if memory is limited

### For Small Datasets (< 1,000 findings)
1. Use **Level 4** or **Level 5** for thorough analysis
2. Use larger `--max-per-cluster` values (5-10)

### Memory Usage
- Level 1-2: Very low memory usage
- Level 3: Moderate memory usage
- Level 4-5: Higher memory usage (loads all findings into memory)

## Expected Results

### Typical Reduction Ratios
- **Level 1**: 60-80% reduction
- **Level 2**: 70-85% reduction  
- **Level 3**: 80-90% reduction
- **Level 4**: 85-92% reduction
- **Level 5**: 90-95% reduction

### Example Output
```
Running nuanced clustering at level 3...
Loading findings from /path/to/findings...
Loaded 10000 findings
Level 1: Basic exit code clustering...
Level 2: Error type clustering...
Level 3: Semantic similarity clustering...
Selecting up to 5 representatives per cluster...
  level1_graaljs_only_fails: 2500 findings -> 5 representatives
  level2_error_12345: 1200 findings -> 5 representatives
  level3_semantic_0: 800 findings -> 5 representatives
  ...

Clustering complete!
Original findings: 10000
Representative findings: 150
Reduction ratio: 98.5%
Results saved to: /path/to/output
```

## Troubleshooting

### Common Issues

**"No findings loaded"**
- Check that your findings directory contains folders with `summary.txt` files
- Verify the directory structure matches the expected format

**"Memory error"**
- Use a lower clustering level (1-3)
- Reduce `--max-per-cluster` value
- Process in smaller batches

**"Slow performance"**
- Use `--preset quick` for faster processing
- Consider using Level 1-2 for initial exploration

### Getting Help
```bash
# Show all options
python nuanced_cluster.py --help

# Show preset options
python run_clustering.py --help
```

## Advanced Usage

### Custom Clustering Strategy
```python
from nuanced_cluster import NuancedClusterer

# Create custom clusterer
clusterer = NuancedClusterer("findings/", "output/")

# Load findings
clusterer.load_findings()

# Apply only specific levels
clusterer.level1_basic_clustering()
clusterer.level3_semantic_clustering()

# Get representatives
representatives = clusterer.select_representatives(max_per_cluster=3)
```

### Integration with Existing Workflows
The tool is designed to work with existing differential testing frameworks:
- Accepts standard directory structure
- Preserves all original files
- Adds metadata for tracking
- Generates reports for analysis

## Contributing

To extend the clustering capabilities:
1. Add new clustering methods to `NuancedClusterer`
2. Update the `run_clustering()` method to include your level
3. Add appropriate documentation and examples
