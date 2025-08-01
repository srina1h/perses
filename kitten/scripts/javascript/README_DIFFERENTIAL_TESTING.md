# Differential Testing in Kitten

This directory contains the differential testing implementation for kitten, which allows you to run the same inputs on multiple engines and detect discrepancies in their behavior.

## Overview

Differential testing is a powerful technique for finding bugs by comparing the behavior of multiple implementations of the same specification. When different engines produce different outputs for the same input, it often indicates a bug in one or more of the engines.

## Features

- **Multi-engine testing**: Run the same input on multiple JavaScript engines (V8, Hermes, GraalJS, JavaScriptCore)
- **Comprehensive discrepancy detection**: Compare exit codes, stdout, stderr, and crash signatures
- **Structured output**: Save detailed results in organized folders for analysis
- **Backward compatibility**: Traditional crash detection still works alongside differential testing

## Types of Discrepancies Detected

1. **Exit Code Mismatch**: Different engines return different exit codes
2. **STDOUT Mismatch**: Different engines produce different standard output
3. **STDERR Mismatch**: Different engines produce different error messages
4. **Crash vs No Crash**: One engine crashes while another doesn't
5. **Different Crash Signatures**: Both engines crash but with different error signatures

## Usage

### Quick Start

```bash
# Run differential testing with all configured engines
./kitten/scripts/javascript/launch_differential_testing.sh
```

### Configuration

The differential testing configuration is in `differential-testing-config.yaml`. You can modify this file to:

- Add or remove engines
- Change engine paths
- Modify testing flags
- Add new crash detectors

### Output Structure

Differential findings are saved in `kitten/temp_testing_campaigns/differential_finding_folder_javascript/` with the following structure:

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

## Engine Setup

Make sure you have the following JavaScript engines installed via jsvu:

```bash
# Install jsvu if you haven't already
npm install -g jsvu

# Install engines
jsvu --os=mac64 --engines=v8,hermes,graaljs,jsc
```

## Customization

### Adding New Engines

1. Add the engine configuration to `differential-testing-config.yaml`
2. Create a crash detector class in `kitten/src/org/perses/fuzzer/compilers/javascript/`
3. Update the `getEngineName` method in `DifferentialTester.kt` if needed

### Modifying Discrepancy Detection

Edit the `detectDiscrepancies` method in `DifferentialTester.kt` to add new types of comparisons or modify existing ones.

## Integration with Existing Workflow

The differential testing feature integrates seamlessly with kitten's existing fuzzing workflow:

- **Seed Processing**: Initial seeds are tested differentially
- **Mutation Testing**: Each mutant is tested on all engines
- **Crash Detection**: Traditional crash detection still works
- **Coverage Collection**: Coverage information is still collected

## Performance Considerations

- Differential testing runs each input on multiple engines, so it's slower than single-engine testing
- Consider reducing the number of threads if you have limited resources
- The memory usage increases with the number of engines

## Troubleshooting

### Common Issues

1. **Engine not found**: Make sure all engines are installed and paths are correct
2. **Permission denied**: Ensure engine binaries are executable
3. **Timeout issues**: Increase timeout values for slower engines

### Debugging

Enable fine-grained logging by setting verbosity to "FINE":

```bash
--verbosity "FINE"
```

This will show detailed information about each test execution and discrepancy detection.

## Examples

### Example Discrepancy Report

```
=== DIFFERENTIAL TEST RESULTS ===
Input file: mutant_123.js
Number of engines tested: 4
Has discrepancies: true

=== DISCREPANCIES FOUND ===
Discrepancy 1:
  Type: EXIT_CODE_MISMATCH
  Description: Exit code mismatch between V8 and Hermes
  Engine 1 (V8): 0
  Engine 2 (Hermes): 1

Discrepancy 2:
  Type: STDOUT_MISMATCH
  Description: STDOUT mismatch between V8 and GraalJS
  Engine 1 (V8): "Hello World"
  Engine 2 (GraalJS): "Hello, World!"
```

This indicates that V8 and Hermes handle the input differently (one succeeds, one fails), and V8 and GraalJS produce slightly different output even when both succeed. 