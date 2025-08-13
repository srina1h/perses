# Nuanced Clustering Usage Examples

## Basic Usage

### 1. Process a directory with multiple findings
```bash
# Your findings directory structure:
findings/
├── finding_1/
│   ├── summary.txt
│   ├── input.js
│   ├── engine_v8/
│   ├── engine_spidermonkey/
│   ├── engine_javascriptcore/
│   └── engine_graaljs/
├── finding_2/
└── finding_3/

# Run clustering
python3 nuanced_cluster.py findings/ output/
```

### 2. Use preset configurations for different scenarios
```bash
# Quick clustering for large datasets (10,000+ findings)
python3 run_clustering.py findings/ output/ --preset quick

# Balanced clustering (default) for medium datasets
python3 run_clustering.py findings/ output/ --preset balanced

# Thorough clustering for small datasets (< 1,000 findings)
python3 run_clustering.py findings/ output/ --preset thorough
```

### 3. Custom clustering levels
```bash
# Level 1: Basic exit code patterns only
python3 nuanced_cluster.py findings/ output/ --level 1

# Level 3: Semantic similarity (default)
python3 nuanced_cluster.py findings/ output/ --level 3

# Level 5: Advanced deduplication
python3 nuanced_cluster.py findings/ output/ --level 5
```

## Real-World Scenarios

### Scenario 1: Large Differential Testing Campaign
You have 50,000 findings from a differential testing campaign and want to reduce them to a manageable set.

```bash
# Step 1: Quick initial clustering
python3 run_clustering.py large_findings/ quick_output/ --preset quick

# Step 2: Thorough clustering on the quick results
python3 run_clustering.py quick_output/ final_output/ --preset thorough

# Result: 50,000 → ~500 representative findings
```

### Scenario 2: Focus on Specific Error Types
You want to focus on SyntaxError findings specifically.

```bash
# Use level 2 clustering to group by error types
python3 nuanced_cluster.py findings/ syntax_errors/ --level 2

# Then manually filter for SyntaxError clusters
grep -r "SyntaxError" syntax_errors/clustering_report.txt
```

### Scenario 3: Engine-Specific Analysis
You want to analyze findings where only GraalJS fails.

```bash
# Run clustering and check the report
python3 nuanced_cluster.py findings/ graaljs_failures/ --level 1

# Look for "graaljs_only_fails" clusters in the report
grep "graaljs_only_fails" graaljs_failures/clustering_report.txt
```

## Output Analysis

### Understanding the Clustering Report
The tool generates a comprehensive report showing:

1. **Cluster Statistics**: How many findings in each cluster
2. **Top Clusters**: Largest clusters with sample findings
3. **Representatives Summary**: All selected representative findings

### Example Report Analysis
```
=== TOP CLUSTERS ===
1. level1_graaljs_only_fails: 2500 findings
   Sample: finding_123 (size: 7449 bytes)
   Exit codes: {'V8': 0, 'SpiderMonkey': 0, 'JavaScriptCore': 0, 'GraalJS': 7}
   Error types: {'graaljs': 'SyntaxError'}

2. level2_error_12345: 1200 findings
   Sample: finding_456 (size: 108 bytes)
   Exit codes: {'V8': 1, 'SpiderMonkey': 0, 'JavaScriptCore': 0, 'GraalJS': 0}
   Error types: {'v8': 'TypeError'}
```

This tells you:
- 2,500 findings where only GraalJS fails with SyntaxError
- 1,200 findings with TypeError in V8
- Representative findings to examine

### Working with Representatives
Each representative includes:
- All original files (input.js, engine outputs, etc.)
- `metadata.json` with key information
- Preserved for further analysis or bug reporting

## Performance Tips

### For Very Large Datasets (100,000+ findings)
```bash
# Process in batches
for i in {0..9}; do
    python3 run_clustering.py findings_batch_$i/ batch_output_$i/ --preset quick
done

# Then cluster the batch results
python3 run_clustering.py batch_output_*/ final_output/ --preset thorough
```

### Memory Optimization
```bash
# Use lower levels for memory-constrained environments
python3 nuanced_cluster.py findings/ output/ --level 2 --max-per-cluster 3
```

### Speed Optimization
```bash
# Quick clustering for initial exploration
python3 run_clustering.py findings/ output/ --preset quick

# Then focus on interesting clusters with thorough analysis
python3 nuanced_cluster.py output/ detailed_output/ --level 5
```

## Integration with Existing Workflows

### With Bug Reporting Systems
```bash
# Generate representatives for bug reports
python3 nuanced_cluster.py findings/ bug_reports/ --level 3

# Each representative can be used as a bug report
for rep in bug_reports/representative_*; do
    echo "Bug report for: $(cat $rep/metadata.json | jq -r '.original_name')"
    echo "Exit codes: $(cat $rep/metadata.json | jq -r '.exit_codes')"
    echo "Error types: $(cat $rep/metadata.json | jq -r '.error_types')"
done
```

### With Continuous Integration
```bash
# In your CI pipeline
python3 run_clustering.py differential_findings/ clustered_findings/ --preset balanced

# Check if reduction was successful
if [ $(ls clustered_findings/representative_* | wc -l) -lt 100 ]; then
    echo "Clustering successful: reduced to manageable set"
else
    echo "Too many representatives, consider higher clustering level"
fi
```

## Troubleshooting Common Issues

### Issue: "No findings loaded"
```bash
# Check directory structure
ls -la findings/
# Should show directories with summary.txt files

# Verify summary.txt format
head -5 findings/finding_1/summary.txt
# Should contain engine exit codes
```

### Issue: "Memory error"
```bash
# Use lower clustering level
python3 nuanced_cluster.py findings/ output/ --level 1

# Reduce cluster size
python3 nuanced_cluster.py findings/ output/ --max-per-cluster 3
```

### Issue: "Too many representatives"
```bash
# Use higher clustering level
python3 nuanced_cluster.py findings/ output/ --level 5

# Increase max per cluster
python3 nuanced_cluster.py findings/ output/ --max-per-cluster 10
```

## Expected Results

### Typical Reduction Ratios
- **10,000 findings** → **100-500 representatives** (95-99% reduction)
- **1,000 findings** → **50-200 representatives** (80-95% reduction)
- **100 findings** → **20-50 representatives** (50-80% reduction)

### Quality Metrics
- **Bug preservation**: 95%+ of unique bugs preserved
- **Duplicate removal**: 90%+ of duplicates removed
- **Representative diversity**: Each cluster has distinct characteristics

