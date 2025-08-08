# Seed Validation on All Engines

This document describes the seed validation feature that ensures only seeds that work on all configured engines are included in the fuzzing pool.

## Overview

During differential fuzzing, it's important that the initial seed pool only contains seeds that work correctly on all engines. Seeds that fail on one or more engines can lead to false positives and reduce the effectiveness of differential testing.

## Problem

Previously, the fuzzer would include any seed that could be parsed successfully, even if it failed to run on some engines. This meant that:

1. Seeds that crashed on some engines were still included in the pool
2. Seeds that returned non-zero exit codes on some engines were still included
3. This could lead to false differential findings during mutation

## Solution

The new seed validation feature (`--validate-seeds-on-all-engines`) validates each seed against all configured engines before adding it to the fuzzing pool. A seed is only included if:

1. It can be parsed successfully
2. It runs successfully on all engines (exit code 0)
3. It doesn't crash on any engine

## Usage

### Enable Seed Validation

To enable seed validation, add the `--validate-seeds-on-all-engines true` flag to your fuzzer command:

```bash
java -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \
  --threads 4 \
  --validate-seeds-on-all-engines true \
  --finding-folder "kitten/temp_testing_campaigns/differential_finding_folder_javascript"
```

### Disable Seed Validation (Default)

By default, seed validation is disabled. You can explicitly disable it by omitting the flag or setting it to false:

```bash
java -jar bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar \
  --testing-config "kitten/scripts/javascript/all-compilers-config.yaml" \
  --threads 4 \
  --finding-folder "kitten/temp_testing_campaigns/differential_finding_folder_javascript"
```

## Implementation Details

### Validation Process

1. **Parsing Check**: First, the seed is parsed to ensure it's syntactically valid
2. **Engine Execution**: The seed is executed on all configured engines
3. **Exit Code Check**: All engines must return exit code 0
4. **Crash Detection**: All engines must not crash during execution
5. **Pool Addition**: Only if all checks pass, the seed is added to the fuzzing pool

### Logging

The validation process provides detailed logging:

- `FINE` level: Shows validation progress for each seed
- `WARNING` level: Reports the total number of seeds that failed validation
- `INFO` level: Shows the final count of validated seeds

### Performance Impact

Seed validation adds overhead to the initial seed processing phase, but provides significant benefits:

- **Reduced false positives**: Fewer differential findings from seeds that don't work on all engines
- **Better mutation base**: Mutations are generated from seeds that are known to work
- **Cleaner results**: Differential findings are more likely to be real bugs

## Testing

You can test the seed validation feature using the provided test script:

```bash
./kitten/scripts/javascript/test_seed_validation.sh
```

This script creates test seeds with different characteristics and compares the results with and without validation enabled.

## Configuration

The seed validation feature works with any engine configuration. It automatically detects the engines from your testing configuration and validates against all of them.

## Troubleshooting

### Seeds Being Filtered Out

If you notice that many seeds are being filtered out, check:

1. **Engine paths**: Ensure all engines are correctly configured and accessible
2. **Engine compatibility**: Some seeds may not be compatible with all engines
3. **Timeout settings**: Very slow seeds might timeout during validation

### Performance Issues

If seed validation is too slow:

1. **Reduce seed pool size**: Use `--seed-limit` to process fewer seeds
2. **Increase verbosity**: Use `--verbosity FINE` to see which seeds are being validated
3. **Check engine performance**: Ensure engines are running efficiently

## Integration with Docker

The Docker setup automatically enables seed validation for differential fuzzing. This ensures that the containerized environment only uses seeds that work on all configured engines.
