/*
 * Copyright (C) 2018-2025 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.fuzzer.compilers

import com.google.common.flogger.FluentLogger
import java.io.File
import java.time.LocalDateTime
import java.time.format.DateTimeFormatter

/**
 * Performs differential testing by running the same input on multiple engines
 * and comparing their outputs to detect discrepancies.
 */
class DifferentialTester(
  private val facades: List<AbstractCompilerConfigurationFacade>
) {
  private enum class Status { SUCCESS, ERROR, CRASH, HANG }
  private data class Outcome(val status: Status, val errorKind: String? = null)
  
  private val outputLogger = StandardizedOutputLogger()
  
  /**
   * Normalizes stdout output for comparison by trimming whitespace, normalizing line endings,
   * collapsing multiple whitespace characters, and normalizing floating-point numbers.
   */
  private fun normalizeStdout(out: String): String {
    // Trim and collapse whitespace
    var s = out.trim()
    s = s.replace("\r\n", "\n").replace("\r", "\n")
    s = Regex("\\s+").replace(s, " ")

    // Normalize floating-point numbers to fixed precision (6 decimals)
    val floatRegex = Regex("(?<![A-Za-z0-9_])([+-]?(?:\\d+\\.\\d*|\\.\\d+|\\d+)(?:[eE][+-]?\\d+)?)")
    s = floatRegex.replace(s) { m ->
      val token = m.groupValues[1]
      // Try to parse as Double; if fail, keep original
      try {
        val value = token.toDouble()
        // Use String.format to 6 decimal places, strip trailing zeros and dot
        val fixed = String.format(java.util.Locale.ROOT, "%.6f", value)
        fixed.trimEnd('0').trimEnd('.')
      } catch (t: Throwable) {
        token
      }
    }
    return s
  }

  /**
   * Validates that a seed works on all engines without detecting discrepancies.
   * This is used for initial seed filtering to ensure only seeds that work
   * on all engines are included in the fuzzing pool.
   */
  fun validateSeedOnAllEngines(seedFile: File): Boolean {
    logger.atFine().log("Starting validation of seed: %s", seedFile)
    logger.atFine().log("Number of facades: %d", facades.size)
    val engineResults = mutableMapOf<String, DifferentialTestResult.EngineResult>()
    
    // Run the seed on all engines
    for (facade in facades) {
      logger.atFine().log("Processing facade with %d compilation actions", facade.compilationActions.size)
      for (action in facade.compilationActions) {
        val engineName = getEngineName(action)
        val cmd = action.constructCompileCmd(File("dummy"))
        logger.atFine().log("Testing seed on engine: %s (command: %s)", engineName, cmd)
        try {
          val result = action.compile(seedFile)
          
          engineResults[engineName] = DifferentialTestResult.EngineResult(
            engineName = engineName,
            action = action,
            cmdOutput = result.cmdOutput,
            cmd = result.cmd,
            exitCode = result.cmdOutput.exitCode.intValue,
            stdout = result.cmdOutput.stdout.combinedLines,
            stderr = result.cmdOutput.stderr.combinedLines
          )
          logger.atFine().log("Engine %s result: exit code %d, stdout: '%s', stderr: '%s'", 
            engineName, result.cmdOutput.exitCode.intValue, 
            result.cmdOutput.stdout.combinedLines.take(100), 
            result.cmdOutput.stderr.combinedLines.take(100))
        } catch (e: Exception) {
          logger.atWarning().withCause(e).log("Failed to run seed %s on engine %s", seedFile, engineName)
          return false
        }
      }
    }
    
    // Check if all engines succeeded (exit code 0) and didn't crash
    for ((engineName, result) in engineResults) {
      // Check if the engine crashed
      val crashDetector = getCrashDetectorForEngine(engineName)
      val crashResult = crashDetector.detectCrash(result.cmdOutput)
      
      if (crashResult.isCrashDetected()) {
        logger.atFine().log("Seed %s crashed on engine %s", seedFile, engineName)
        return false
      }
      
      // Check if the engine failed (non-zero exit code)
      if (result.exitCode != 0) {
        logger.atFine().log("Seed %s failed on engine %s with exit code %d", seedFile, engineName, result.exitCode)
        return false
      }
    }
    
    // NEW: Check that all engines produce the same stdout output
    if (engineResults.size > 1) {
      val firstStdout = normalizeStdout(engineResults.values.first().stdout)
      for ((engineName, result) in engineResults) {
        val normalizedStdout = normalizeStdout(result.stdout)
        if (normalizedStdout != firstStdout) {
          logger.atFine().log("Seed %s produces different stdout on engine %s: expected '%s', got '%s'", 
            seedFile, engineName, firstStdout, normalizedStdout)
          return false
        }
      }
    }
    
    logger.atFine().log("Seed %s passed comprehensive validation on all engines", seedFile)
    return true
  }

  /**
   * Comprehensive seed validation that ensures:
   * 1. All engines exit with code 0 (clean exit)
   * 2. No engine crashes
   * 3. All engines produce identical stdout output
   * 
   * This method is more thorough than validateSeedOnAllEngines and should be used
   * for initial seed filtering to prevent false positives during fuzzing.
   */
  fun validateSeedComprehensively(seedFile: File): Boolean {
    logger.atFine().log("Starting comprehensive validation of seed: %s", seedFile)
    logger.atFine().log("Number of facades: %d", facades.size)
    val engineResults = mutableMapOf<String, DifferentialTestResult.EngineResult>()
    
    // Run the seed on all engines
    for (facade in facades) {
      logger.atFine().log("Processing facade with %d compilation actions", facade.compilationActions.size)
      for (action in facade.compilationActions) {
        val engineName = getEngineName(action)
        val cmd = action.constructCompileCmd(File("dummy"))
        logger.atFine().log("Testing seed on engine: %s (command: %s)", engineName, cmd)
        try {
          val result = action.compile(seedFile)
          
          engineResults[engineName] = DifferentialTestResult.EngineResult(
            engineName = engineName,
            action = action,
            cmdOutput = result.cmdOutput,
            cmd = result.cmd,
            exitCode = result.cmdOutput.exitCode.intValue,
            stdout = result.cmdOutput.stdout.combinedLines,
            stderr = result.cmdOutput.stderr.combinedLines
          )
          logger.atFine().log("Engine %s result: exit code %d, stdout: '%s', stderr: '%s'", 
            engineName, result.cmdOutput.exitCode.intValue, 
            result.cmdOutput.stdout.combinedLines.take(100), 
            result.cmdOutput.stderr.combinedLines.take(100))
        } catch (e: Exception) {
          logger.atWarning().withCause(e).log("Failed to run seed %s on engine %s", seedFile, engineName)
          return false
        }
      }
    }
    
    // Step 1: Check if all engines succeeded (exit code 0) and didn't crash
    for ((engineName, result) in engineResults) {
      // Check if the engine crashed
      val crashDetector = getCrashDetectorForEngine(engineName)
      val crashResult = crashDetector.detectCrash(result.cmdOutput)
      
      if (crashResult.isCrashDetected()) {
        logger.atFine().log("Seed %s crashed on engine %s", seedFile, engineName)
        return false
      }
      
      // Check if the engine failed (non-zero exit code)
      if (result.exitCode != 0) {
        logger.atFine().log("Seed %s failed on engine %s with exit code %d", seedFile, engineName, result.exitCode)
        return false
      }
    }
    
    // Step 2: Check that all engines produce the same stdout output
    if (engineResults.size > 1) {
      val firstStdout = normalizeStdout(engineResults.values.first().stdout)
      for ((engineName, result) in engineResults) {
        val normalizedStdout = normalizeStdout(result.stdout)
        if (normalizedStdout != firstStdout) {
          logger.atFine().log("Seed %s produces different stdout on engine %s: expected '%s', got '%s'", 
            seedFile, engineName, firstStdout, normalizedStdout)
          return false
        }
      }
    }
    
    logger.atFine().log("Seed %s passed comprehensive validation on all engines", seedFile)
    return true
  }
  
  fun testDifferentially(inputFile: File): DifferentialTestResult {
    val engineResults = mutableMapOf<String, DifferentialTestResult.EngineResult>()
    
    // Run the input on all engines
    for (facade in facades) {
      for (action in facade.compilationActions) {
        val engineName = getEngineName(action)
        val result = action.compile(inputFile)
        
        engineResults[engineName] = DifferentialTestResult.EngineResult(
          engineName = engineName,
          action = action,
          cmdOutput = result.cmdOutput,
          cmd = result.cmd,
          exitCode = result.cmdOutput.exitCode.intValue,
          stdout = result.cmdOutput.stdout.combinedLines,
          stderr = result.cmdOutput.stderr.combinedLines
        )
      }
    }
    
    // Detect discrepancies
    val discrepancies = detectDiscrepancies(engineResults)
    
    return DifferentialTestResult(
      inputFile = inputFile,
      engineResults = engineResults,
      discrepancies = discrepancies
    )
  }
  
  /**
   * Performs differential testing with standardized logging output.
   * This method provides detailed, line-by-line comparison of engine outputs
   * in a table format for easy discrepancy detection.
   */
  fun testDifferentiallyWithStandardizedLogging(
    inputFile: File,
    outputDirectory: File? = null
  ): Pair<DifferentialTestResult, StandardizedOutputLogger.StandardizedOutput> {
    val startTime = System.currentTimeMillis()
    val testId = outputLogger.generateTestId(inputFile)
    val standardizedOutputs = mutableListOf<StandardizedOutputLogger.StandardizedOutput>()
    
    logger.atFine().log("Starting standardized differential testing for test ID: %s", testId)
    
    // Run the input on all engines and collect standardized outputs
    for (facade in facades) {
      for (action in facade.compilationActions) {
        val engineName = getEngineName(action)
        val engineStartTime = System.currentTimeMillis()
        
        try {
          val result = action.compile(inputFile)
          val executionTimeMs = System.currentTimeMillis() - engineStartTime
          
          val standardizedOutput = outputLogger.standardizeOutput(
            testId = testId,
            inputFile = inputFile,
            engineName = engineName,
            result = DifferentialTestResult.EngineResult(
              engineName = engineName,
              action = action,
              cmdOutput = result.cmdOutput,
              cmd = result.cmd,
              exitCode = result.cmdOutput.exitCode.intValue,
              stdout = result.cmdOutput.stdout.combinedLines,
              stderr = result.cmdOutput.stderr.combinedLines
            ),
            executionTimeMs = executionTimeMs
          )
          
          standardizedOutputs.add(standardizedOutput)
          
          logger.atFine().log("Engine %s completed in %d ms with status: %s", 
            engineName, executionTimeMs, standardizedOutput.status)
            
        } catch (e: Exception) {
          logger.atWarning().withCause(e).log("Failed to run test on engine %s", engineName)
          
          // Create a standardized output for the failed execution
          val executionTimeMs = System.currentTimeMillis() - engineStartTime
          val failedOutput = StandardizedOutputLogger.StandardizedOutput(
            testId = testId,
            timestamp = LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME),
            inputFile = inputFile.name,
            engineName = engineName,
            exitCode = -1,
            executionTimeMs = executionTimeMs,
            status = StandardizedOutputLogger.StandardizedOutput.ExecutionStatus.ERROR,
            stdoutLines = emptyList(),
            stderrLines = listOf("Execution failed: ${e.message}"),
            crashSignature = null,
            errorType = "ExecutionError"
          )
          
          standardizedOutputs.add(failedOutput)
        }
      }
    }
    
    // Create the traditional DifferentialTestResult for backward compatibility
    val engineResults = standardizedOutputs.associate { output ->
      output.engineName to DifferentialTestResult.EngineResult(
        engineName = output.engineName,
        action = facades.flatMap { it.compilationActions }.find { getEngineName(it) == output.engineName }!!,
        cmdOutput = org.perses.util.shell.CmdOutput(
          org.perses.util.shell.ExitCode(output.exitCode),
          org.perses.util.shell.Output(output.stdoutLines.joinToString("\n")),
          org.perses.util.shell.Output(output.stderrLines.joinToString("\n"))
        ),
        cmd = "standardized_output",
        exitCode = output.exitCode,
        stdout = output.stdoutLines.joinToString("\n"),
        stderr = output.stderrLines.joinToString("\n")
      )
    }
    
    val discrepancies = detectDiscrepancies(engineResults)
    val differentialResult = DifferentialTestResult(
      inputFile = inputFile,
      engineResults = engineResults,
      discrepancies = discrepancies
    )
    
    // Generate and save standardized output only if there are discrepancies
    if (outputDirectory != null && discrepancies.isNotEmpty()) {
      val outputFile = File(outputDirectory, "standardized_output_${testId}.txt")
      val csvFile = File(outputDirectory, "standardized_output_${testId}.csv")
      
      outputLogger.saveToFile(standardizedOutputs, outputFile)
      csvFile.writeText(outputLogger.formatAsCSV(standardizedOutputs))
      
      logger.atInfo().log("Standardized output saved to: %s and %s", outputFile.absolutePath, csvFile.absolutePath)
    }
    
    // Create comparison map for quick discrepancy detection
    val comparisonMap = outputLogger.createComparisonMap(standardizedOutputs)
    val quickDiscrepancies = outputLogger.detectDiscrepanciesQuick(comparisonMap)
    val lineDifferences = outputLogger.findLineDifferences(comparisonMap)
    
    // Log the formatted table output
    val formattedOutput = outputLogger.formatAsTable(standardizedOutputs)
    logger.atFine().log("Standardized output for test %s:\n%s", testId, formattedOutput)
    
    // Log quick discrepancy detection results
    if (quickDiscrepancies.isNotEmpty()) {
      logger.atInfo().log("Quick discrepancy detection found %d discrepancies for test %s", quickDiscrepancies.size, testId)
      quickDiscrepancies.forEach { discrepancy ->
        logger.atFine().log("Discrepancy: %s - %s", discrepancy.type, discrepancy.description)
      }
    }
    
    if (lineDifferences.isNotEmpty()) {
      logger.atInfo().log("Found %d line-by-line differences for test %s", lineDifferences.size, testId)
      lineDifferences.forEach { diff ->
        logger.atFine().log("Line %d (%s): %s", diff.lineNumber, diff.streamType, diff.uniqueContent)
      }
    }
    
    val totalExecutionTime = System.currentTimeMillis() - startTime
    logger.atInfo().log("Standardized differential testing completed for test %s in %d ms", testId, totalExecutionTime)
    
    return Pair(differentialResult, standardizedOutputs)
  }
  
  private fun getEngineName(action: ICompilationAction): String {
    // Try to extract a meaningful name from the command
    val cmd = action.constructCompileCmd(File("dummy"))
    return when {
      cmd.contains("eshost") -> "ESHost"
      cmd.contains("v8") -> "V8"
      cmd.contains("hermes") -> "Hermes"
      cmd.contains("graaljs") -> "GraalJS"
      cmd.contains("jsc") -> "JavaScriptCore"
      cmd.contains("spidermonkey") -> "SpiderMonkey"
      cmd.contains("jerry") -> "JerryScript"
      else -> cmd.split(" ").firstOrNull()?.let { File(it).name } ?: "Unknown"
    }
  }
  
  private fun getCrashDetectorForEngine(engineName: String): ICompilerCrashDetector {
    // Find the facade that corresponds to this engine
    for (facade in facades) {
      for (action in facade.compilationActions) {
        if (getEngineName(action) == engineName) {
          return facade.crashDetector
        }
      }
    }
    throw IllegalArgumentException("No crash detector found for engine: $engineName")
  }
  
  private fun detectDiscrepancies(
    engineResults: Map<String, DifferentialTestResult.EngineResult>
  ): List<DifferentialTestResult.Discrepancy> {
    val discrepancies = mutableListOf<DifferentialTestResult.Discrepancy>()
    val engines = engineResults.keys.toList()
    
    if (engines.size < 2) {
      return discrepancies
    }
    
    fun isHang(result: DifferentialTestResult.EngineResult): Boolean {
      val stderrLower = result.stderr.lowercase()
      val stdoutLower = result.stdout.lowercase()
      // GNU/coreutils timeout commonly returns 124; also check textual hints
      return result.exitCode == 124 ||
        stderrLower.contains("timeout") || stderrLower.contains("timed out") ||
        stdoutLower.contains("timeout") || stdoutLower.contains("timed out") ||
        stderrLower.contains("execution timeout") || stdoutLower.contains("execution timeout")
    }

    fun detectErrorKind(stderr: String): String {
      // Extract canonical JS error type; ignore the rest of message content
      val canonicalMap = mapOf(
        "typeerror" to "TypeError",
        "referenceerror" to "ReferenceError",
        "syntaxerror" to "SyntaxError",
        "rangeerror" to "RangeError",
        "urierror" to "URIError",
        "evalerror" to "EvalError",
      )
      val regex = Regex("(TypeError|ReferenceError|SyntaxError|RangeError|URIError|EvalError)", RegexOption.IGNORE_CASE)
      val match = regex.find(stderr)
      if (match != null) {
        val key = match.value.lowercase()
        return canonicalMap[key] ?: match.value
      }
      return "RuntimeError"
    }

    fun outcomeOf(engineName: String, result: DifferentialTestResult.EngineResult): Outcome {
      val crashed = getCrashDetectorForEngine(engineName).detectCrash(result.cmdOutput).isCrashDetected()
      if (crashed) return Outcome(Status.CRASH)
      if (isHang(result)) return Outcome(Status.HANG)
      return if (result.exitCode == 0) Outcome(Status.SUCCESS) else Outcome(Status.ERROR, detectErrorKind(result.stderr))
    }



    // Global normalization gates: ignore uninteresting uniform cases
    val allOutcomes: Map<String, Outcome> = engines.associateWith { eng ->
      val res = engineResults[eng]!!
      outcomeOf(eng, res)
    }
    val allSuccess = allOutcomes.values.all { it.status == Status.SUCCESS }
    if (allSuccess) {
      val normalizedStdouts = engines.map { eng -> normalizeStdout(engineResults[eng]!!.stdout) }.toSet()
      if (normalizedStdouts.size == 1) {
        return emptyList()
      }
    }
    val allFail = allOutcomes.values.all { it.status != Status.SUCCESS }
    if (allFail) {
      return emptyList()
    }

    // Compare each pair of engines with simplified, high-signal rules
    for (i in 0 until engines.size - 1) {
      for (j in i + 1 until engines.size) {
        val engine1 = engines[i]
        val engine2 = engines[j]
        val result1 = engineResults[engine1]!!
        val result2 = engineResults[engine2]!!

        val outcome1 = allOutcomes[engine1] ?: outcomeOf(engine1, result1)
        val outcome2 = allOutcomes[engine2] ?: outcomeOf(engine2, result2)

        // 1) Specification divergence: both succeed but produce different outputs
        if (outcome1.status == Status.SUCCESS && outcome2.status == Status.SUCCESS) {
          val out1 = normalizeStdout(result1.stdout)
          val out2 = normalizeStdout(result2.stdout)
          if (out1 != out2) {
            discrepancies.add(
              DifferentialTestResult.Discrepancy(
                type = DifferentialTestResult.Discrepancy.DiscrepancyType.SPEC_DIVERGENCE,
                description = "Different observable outputs for the same input",
                engine1 = engine1,
                engine2 = engine2,
                value1 = out1,
                value2 = out2,
              ),
            )
          }
        }

        // 2) Success vs. Error: one succeeds, the other fails (error/crash/hang)
        if ((outcome1.status == Status.SUCCESS) != (outcome2.status == Status.SUCCESS)) {
          discrepancies.add(
            DifferentialTestResult.Discrepancy(
              type = DifferentialTestResult.Discrepancy.DiscrepancyType.SUCCESS_VS_ERROR,
              description = "One engine succeeded while the other failed",
              engine1 = engine1,
              engine2 = engine2,
              value1 = outcome1.status.name,
              value2 = outcome2.status.name,
            ),
          )
        }

        // 3) Crash or Hang: if exactly one side crashed/hanged, flag it
        val isCrashOrHang1 = outcome1.status == Status.CRASH || outcome1.status == Status.HANG
        val isCrashOrHang2 = outcome2.status == Status.CRASH || outcome2.status == Status.HANG
        if (isCrashOrHang1 != isCrashOrHang2) {
          discrepancies.add(
            DifferentialTestResult.Discrepancy(
              type = DifferentialTestResult.Discrepancy.DiscrepancyType.CRASH_OR_HANG,
              description = "Crash/Hang observed on one engine but not the other",
              engine1 = engine1,
              engine2 = engine2,
              value1 = outcome1.status.name,
              value2 = outcome2.status.name,
            ),
          )
        }

        // 4) Different error types: both error, but kinds differ (TypeError vs ReferenceError, etc.)
        if (outcome1.status == Status.ERROR && outcome2.status == Status.ERROR) {
          val kind1 = outcome1.errorKind ?: "Error"
          val kind2 = outcome2.errorKind ?: "Error"
          if (kind1 != kind2) {
            discrepancies.add(
              DifferentialTestResult.Discrepancy(
                type = DifferentialTestResult.Discrepancy.DiscrepancyType.DIFFERENT_ERROR_TYPES,
                description = "Different JavaScript error types",
                engine1 = engine1,
                engine2 = engine2,
                value1 = kind1,
                value2 = kind2,
              ),
            )
          }
        }

        // 5) If both crashed, optionally record different crash signatures
        if (outcome1.status == Status.CRASH && outcome2.status == Status.CRASH) {
          val signature1 = getCrashDetectorForEngine(engine1).detectCrash(result1.cmdOutput).asCrash().signature.toString()
          val signature2 = getCrashDetectorForEngine(engine2).detectCrash(result2.cmdOutput).asCrash().signature.toString()
          if (signature1 != signature2) {
            discrepancies.add(
              DifferentialTestResult.Discrepancy(
                type = DifferentialTestResult.Discrepancy.DiscrepancyType.DIFFERENT_CRASH_SIGNATURES,
                description = "Different crash signatures",
                engine1 = engine1,
                engine2 = engine2,
                value1 = signature1,
                value2 = signature2,
              ),
            )
          }
        }
      }
    }
    
    return discrepancies
  }
  
  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
} 