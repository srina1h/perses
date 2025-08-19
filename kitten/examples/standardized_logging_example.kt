/*
 * Example demonstrating the standardized logging system for differential testing
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
    
    // Format and display the results
    println("\n=== STANDARDIZED OUTPUT EXAMPLE ===")
    val formattedOutput = logger.formatAsTable(standardizedOutputs)
    println(formattedOutput)
    
    // Save to files
    val outputDir = File("example_output")
    outputDir.mkdirs()
    
    val tableFile = File(outputDir, "example_standardized_output.txt")
    val csvFile = File(outputDir, "example_standardized_output.csv")
    
    logger.saveToFile(standardizedOutputs, tableFile)
    csvFile.writeText(logger.formatAsCSV(standardizedOutputs))
    
    println("\nFiles saved to:")
    println("  Table format: ${tableFile.absolutePath}")
    println("  CSV format: ${csvFile.absolutePath}")
}

private fun createSampleTestFile(): File {
    val testCode = """
        // Sample JavaScript test case that produces different outputs
        const x = undefined;
        try {
            console.log("Hello World");
            console.log(x.property); // This will cause different errors
        } catch (e) {
            console.error(e.message);
        }
    """.trimIndent()
    
    val testFile = File("sample_test.js")
    testFile.writeText(testCode)
    return testFile
}

private fun createSampleEngineResults(testFile: File): Map<String, DifferentialTestResult.EngineResult> {
    // Simulate different engine behaviors
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
                            org.perses.util.shell.Output("Hello World\nundefined"),
                            org.perses.util.shell.Output("")
                        )
                    )
                }
            },
            cmdOutput = org.perses.util.shell.CmdOutput(
                org.perses.util.shell.ExitCode(0),
                org.perses.util.shell.Output("Hello World\nundefined"),
                org.perses.util.shell.Output("")
            ),
            cmd = "v8 sample_test.js",
            exitCode = 0,
            stdout = "Hello World\nundefined",
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
                            org.perses.util.shell.Output("TypeError: Cannot read property 'property' of undefined")
                        )
                    )
                }
            },
            cmdOutput = org.perses.util.shell.CmdOutput(
                org.perses.util.shell.ExitCode(1),
                org.perses.util.shell.Output("Hello World"),
                org.perses.util.shell.Output("TypeError: Cannot read property 'property' of undefined")
            ),
            cmd = "graaljs sample_test.js",
            exitCode = 1,
            stdout = "Hello World",
            stderr = "TypeError: Cannot read property 'property' of undefined"
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
                            org.perses.util.shell.Output("Hello World\nundefined"),
                            org.perses.util.shell.Output("")
                        )
                    )
                }
            },
            cmdOutput = org.perses.util.shell.CmdOutput(
                org.perses.util.shell.ExitCode(0),
                org.perses.util.shell.Output("Hello World\nundefined"),
                org.perses.util.shell.Output("")
            ),
            cmd = "jsc sample_test.js",
            exitCode = 0,
            stdout = "Hello World\nundefined",
            stderr = ""
        )
    )
}
