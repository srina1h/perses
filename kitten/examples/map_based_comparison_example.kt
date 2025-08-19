/*
 * Example demonstrating the map-based comparison approach for quick discrepancy detection
 */

import org.perses.fuzzer.compilers.StandardizedOutputLogger
import org.perses.fuzzer.compilers.DifferentialTestResult
import java.io.File

fun main() {
    // Create a sample test case
    val testFile = createSampleTestFile()
    
    // Create the standardized output logger
    val logger = StandardizedOutputLogger()
    
    // Generate a test ID
    val testId = logger.generateTestId(testFile)
    println("Generated test ID: $testId")
    
    // Create sample engine results (simulating different engine outputs)
    val sampleResults = createSampleEngineResults(testFile)
    
    // Convert to standardized outputs
    val standardizedOutputs = sampleResults.map { (engineName, result) ->
        logger.standardizeOutput(
            testId = testId,
            inputFile = testFile,
            engineName = engineName,
            result = result
        )
    }
    
    println("\n=== MAP-BASED COMPARISON EXAMPLE ===")
    
    // Create comparison map for quick lookups
    val comparisonMap = logger.createComparisonMap(standardizedOutputs)
    println("Created comparison map with ${comparisonMap.engineNames.size} engines")
    
    // Perform quick discrepancy detection
    val quickDiscrepancies = logger.detectDiscrepanciesQuick(comparisonMap)
    println("Quick discrepancy detection found ${quickDiscrepancies.size} discrepancies:")
    
    quickDiscrepancies.forEach { discrepancy ->
        println("  - ${discrepancy.type}: ${discrepancy.description}")
        println("    Engines: ${discrepancy.engines.joinToString(", ")}")
        println("    Values: ${discrepancy.values.joinToString(" vs ")}")
    }
    
    // Find line-by-line differences
    val lineDifferences = logger.findLineDifferences(comparisonMap)
    println("\nLine-by-line differences found: ${lineDifferences.size}")
    
    lineDifferences.forEach { diff ->
        println("  - Line ${diff.lineNumber} (${diff.streamType}):")
        diff.engineLines.forEach { (engine, content) ->
            println("    $engine: '$content'")
        }
    }
    
    // Compare specific engines
    if (comparisonMap.engineNames.size >= 2) {
        val engine1 = comparisonMap.engineNames[0]
        val engine2 = comparisonMap.engineNames[1]
        
        println("\n=== COMPARISON: $engine1 vs $engine2 ===")
        val comparison = logger.compareEngines(comparisonMap, engine1, engine2)
        
        println("Status match: ${comparison.statusMatch}")
        println("Exit code match: ${comparison.exitCodeMatch}")
        println("STDOUT match: ${comparison.stdoutMatch}")
        println("STDERR match: ${comparison.stderrMatch}")
        
        if (comparison.statusDifference != null) {
            println("Status difference: ${comparison.statusDifference}")
        }
        if (comparison.exitCodeDifference != null) {
            println("Exit code difference: ${comparison.exitCodeDifference}")
        }
        if (comparison.stdoutDifference != null) {
            println("STDOUT difference: ${comparison.stdoutDifference}")
        }
        if (comparison.stderrDifference != null) {
            println("STDERR difference: ${comparison.stderrDifference}")
        }
    }
    
    // Demonstrate map structure
    println("\n=== COMPARISON MAP STRUCTURE ===")
    println("Status Map: ${comparisonMap.statusMap}")
    println("Exit Code Map: ${comparisonMap.exitCodeMap}")
    println("STDOUT Content Map: ${comparisonMap.stdoutContentMap}")
    println("STDERR Content Map: ${comparisonMap.stderrContentMap}")
    
    // Show line-indexed maps
    println("\nSTDOUT Line Map:")
    comparisonMap.stdoutMap.forEach { (lineNumber, engineLines) ->
        println("  Line $lineNumber: $engineLines")
    }
    
    println("\nSTDERR Line Map:")
    comparisonMap.stderrMap.forEach { (lineNumber, engineLines) ->
        println("  Line $lineNumber: $engineLines")
    }
    
    // Performance comparison
    println("\n=== PERFORMANCE COMPARISON ===")
    
    // Traditional approach (simulated)
    val traditionalStart = System.currentTimeMillis()
    repeat(1000) {
        // Simulate traditional line-by-line comparison
        standardizedOutputs.forEach { output ->
            output.stdoutLines.forEach { line ->
                // Simulate comparison work
                line.length
            }
        }
    }
    val traditionalTime = System.currentTimeMillis() - traditionalStart
    
    // Map-based approach
    val mapBasedStart = System.currentTimeMillis()
    repeat(1000) {
        // Use map-based comparison
        comparisonMap.stdoutMap.forEach { (_, engineLines) ->
            engineLines.values.toSet().size
        }
    }
    val mapBasedTime = System.currentTimeMillis() - mapBasedStart
    
    println("Traditional approach: ${traditionalTime}ms")
    println("Map-based approach: ${mapBasedTime}ms")
    println("Speedup: ${traditionalTime.toDouble() / mapBasedTime.toDouble():.2f}x")
}

private fun createSampleTestFile(): File {
    val testCode = """
        // Sample JavaScript test case that produces different outputs
        const x = undefined;
        try {
            console.log("Hello World");
            console.log(x.property); // This will cause different errors
            console.log("Additional output");
        } catch (e) {
            console.error(e.message);
            console.error("Error occurred");
        }
    """.trimIndent()
    
    val testFile = File("sample_test_map.js")
    testFile.writeText(testCode)
    return testFile
}

private fun createSampleEngineResults(testFile: File): Map<String, DifferentialTestResult.EngineResult> {
    // Simulate different engine behaviors with more complex outputs
    return mapOf(
        "V8" to DifferentialTestResult.EngineResult(
            engineName = "V8",
            action = object : org.perses.fuzzer.compilers.ICompilationAction {
                override fun constructCompileCmd(inputFile: File): String = "v8 $inputFile"
                override fun compile(inputFile: File): org.perses.fuzzer.compilers.CompilationResult {
                    return org.perses.fuzzer.compilers.CompilationResult(
                        cmd = "v8 $inputFile",
                        cmdOutput = org.perses.util.shell.CmdOutput(
                            org.perses.util.shell.ExitCode(0),
                            org.perses.util.shell.Output("Hello World\nundefined\nAdditional output"),
                            org.perses.util.shell.Output("")
                        )
                    )
                }
            },
            cmdOutput = org.perses.util.shell.CmdOutput(
                org.perses.util.shell.ExitCode(0),
                org.perses.util.shell.Output("Hello World\nundefined\nAdditional output"),
                org.perses.util.shell.Output("")
            ),
            cmd = "v8 sample_test_map.js",
            exitCode = 0,
            stdout = "Hello World\nundefined\nAdditional output",
            stderr = ""
        ),
        
        "GraalJS" to DifferentialTestResult.EngineResult(
            engineName = "GraalJS",
            action = object : org.perses.fuzzer.compilers.ICompilationAction {
                override fun constructCompileCmd(inputFile: File): String = "graaljs $inputFile"
                override fun compile(inputFile: File): org.perses.fuzzer.compilers.CompilationResult {
                    return org.perses.fuzzer.compilers.CompilationResult(
                        cmd = "graaljs $inputFile",
                        cmdOutput = org.perses.util.shell.CmdOutput(
                            org.perses.util.shell.ExitCode(1),
                            org.perses.util.shell.Output("Hello World"),
                            org.perses.util.shell.Output("TypeError: Cannot read property 'property' of undefined\nError occurred")
                        )
                    )
                }
            },
            cmdOutput = org.perses.util.shell.CmdOutput(
                org.perses.util.shell.ExitCode(1),
                org.perses.util.shell.Output("Hello World"),
                org.perses.util.shell.Output("TypeError: Cannot read property 'property' of undefined\nError occurred")
            ),
            cmd = "graaljs sample_test_map.js",
            exitCode = 1,
            stdout = "Hello World",
            stderr = "TypeError: Cannot read property 'property' of undefined\nError occurred"
        ),
        
        "JavaScriptCore" to DifferentialTestResult.EngineResult(
            engineName = "JavaScriptCore",
            action = object : org.perses.fuzzer.compilers.ICompilationAction {
                override fun constructCompileCmd(inputFile: File): String = "jsc $inputFile"
                override fun compile(inputFile: File): org.perses.fuzzer.compilers.CompilationResult {
                    return org.perses.fuzzer.compilers.CompilationResult(
                        cmd = "jsc $inputFile",
                        cmdOutput = org.perses.util.shell.CmdOutput(
                            org.perses.util.shell.ExitCode(0),
                            org.perses.util.shell.Output("Hello World\nundefined\nAdditional output"),
                            org.perses.util.shell.Output("")
                        )
                    )
                }
            },
            cmdOutput = org.perses.util.shell.CmdOutput(
                org.perses.util.shell.ExitCode(0),
                org.perses.util.shell.Output("Hello World\nundefined\nAdditional output"),
                org.perses.util.shell.Output("")
            ),
            cmd = "jsc sample_test_map.js",
            exitCode = 0,
            stdout = "Hello World\nundefined\nAdditional output",
            stderr = ""
        ),
        
        "SpiderMonkey" to DifferentialTestResult.EngineResult(
            engineName = "SpiderMonkey",
            action = object : org.perses.fuzzer.compilers.ICompilationAction {
                override fun constructCompileCmd(inputFile: File): String = "spidermonkey $inputFile"
                override fun compile(inputFile: File): org.perses.fuzzer.compilers.CompilationResult {
                    return org.perses.fuzzer.compilers.CompilationResult(
                        cmd = "spidermonkey $inputFile",
                        cmdOutput = org.perses.util.shell.CmdOutput(
                            org.perses.util.shell.ExitCode(1),
                            org.perses.util.shell.Output("Hello World"),
                            org.perses.util.shell.Output("ReferenceError: x is not defined\nError occurred")
                        )
                    )
                }
            },
            cmdOutput = org.perses.util.shell.CmdOutput(
                org.perses.util.shell.ExitCode(1),
                org.perses.util.shell.Output("Hello World"),
                org.perses.util.shell.Output("ReferenceError: x is not defined\nError occurred")
            ),
            cmd = "spidermonkey sample_test_map.js",
            exitCode = 1,
            stdout = "Hello World",
            stderr = "ReferenceError: x is not defined\nError occurred"
        )
    )
}
