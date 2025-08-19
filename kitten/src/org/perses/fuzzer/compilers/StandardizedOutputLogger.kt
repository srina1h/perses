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

import java.io.File
import java.security.MessageDigest
import java.time.LocalDateTime
import java.time.format.DateTimeFormatter

/**
 * Provides standardized logging for differential testing outputs in a table format.
 * Each test case gets a unique ID (hash) and outputs are formatted with line numbers
 * for easy comparison and discrepancy detection.
 */
class StandardizedOutputLogger {
  
  /**
   * Represents a standardized output entry with line-by-line formatting
   */
  data class StandardizedOutput(
    val testId: String,
    val timestamp: String,
    val inputFile: String,
    val engineName: String,
    val exitCode: Int,
    val executionTimeMs: Long,
    val status: ExecutionStatus,
    val stdoutLines: List<String>,
    val stderrLines: List<String>,
    val crashSignature: String? = null,
    val errorType: String? = null
  ) {
    enum class ExecutionStatus {
      SUCCESS,
      ERROR,
      CRASH,
      HANG,
      TIMEOUT
    }
  }
  
  /**
   * Generates a unique test ID based on input file content and timestamp
   */
  fun generateTestId(inputFile: File, timestamp: String = LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME)): String {
    val content = inputFile.readText()
    val hash = MessageDigest.getInstance("SHA-256").digest((content + timestamp).toByteArray())
    return hash.take(8).joinToString("") { "%02x".format(it) }
  }
  
  /**
   * Converts raw engine output to standardized format
   */
  fun standardizeOutput(
    testId: String,
    inputFile: File,
    engineName: String,
    result: DifferentialTestResult.EngineResult,
    executionTimeMs: Long = 0L
  ): StandardizedOutput {
    
    val status = when {
      result.exitCode == 0 -> StandardizedOutput.ExecutionStatus.SUCCESS
      result.exitCode == 124 -> StandardizedOutput.ExecutionStatus.TIMEOUT
      result.stderr.contains("timeout", ignoreCase = true) -> StandardizedOutput.ExecutionStatus.TIMEOUT
      result.stderr.contains("crash", ignoreCase = true) || result.stderr.contains("segmentation fault", ignoreCase = true) -> StandardizedOutput.ExecutionStatus.CRASH
      result.stderr.isNotEmpty() -> StandardizedOutput.ExecutionStatus.ERROR
      else -> StandardizedOutput.ExecutionStatus.ERROR
    }
    
    val errorType = if (status == StandardizedOutput.ExecutionStatus.ERROR) {
      extractErrorType(result.stderr)
    } else null
    
    val crashSignature = if (status == StandardizedOutput.ExecutionStatus.CRASH) {
      extractCrashSignature(result.stderr)
    } else null
    
    return StandardizedOutput(
      testId = testId,
      timestamp = LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME),
      inputFile = inputFile.name,
      engineName = engineName,
      exitCode = result.exitCode,
      executionTimeMs = executionTimeMs,
      status = status,
      stdoutLines = result.stdout.split("\n").filter { it.isNotBlank() },
      stderrLines = result.stderr.split("\n").filter { it.isNotBlank() },
      crashSignature = crashSignature,
      errorType = errorType
    )
  }
  
  /**
   * Formats standardized output as a table with line numbers
   */
  fun formatAsTable(outputs: List<StandardizedOutput>): String {
    if (outputs.isEmpty()) return "No outputs to format"
    
    val testId = outputs.first().testId
    val inputFile = outputs.first().inputFile
    
    return buildString {
      appendLine("=== STANDARDIZED DIFFERENTIAL TEST OUTPUT ===")
      appendLine("Test ID: $testId")
      appendLine("Input File: $inputFile")
      appendLine("Timestamp: ${outputs.first().timestamp}")
      appendLine("Number of Engines: ${outputs.size}")
      appendLine()
      
      // Summary table
      appendLine("=== EXECUTION SUMMARY ===")
      appendLine("Engine Name | Exit Code | Status | Execution Time (ms) | Error Type")
      appendLine("------------|-----------|--------|-------------------|-----------")
      outputs.forEach { output ->
        appendLine("${output.engineName.padEnd(12)} | ${output.exitCode.toString().padEnd(9)} | ${output.status.name.padEnd(6)} | ${output.executionTimeMs.toString().padEnd(17)} | ${output.errorType ?: "N/A"}")
      }
      appendLine()
      
      // Detailed output comparison
      appendLine("=== DETAILED OUTPUT COMPARISON ===")
      
      // Find maximum number of lines across all outputs
      val maxStdoutLines = outputs.maxOfOrNull { it.stdoutLines.size } ?: 0
      val maxStderrLines = outputs.maxOfOrNull { it.stderrLines.size } ?: 0
      
      // STDOUT comparison
      if (maxStdoutLines > 0) {
        appendLine("--- STDOUT COMPARISON ---")
        appendLine("Line | ${outputs.joinToString(" | ") { it.engineName.padEnd(12) }}")
        appendLine("-----|${outputs.joinToString("|") { "-".repeat(14) }}")
        
        for (lineNum in 0 until maxStdoutLines) {
          val lineNumber = (lineNum + 1).toString().padEnd(4)
          val lineOutputs = outputs.map { output ->
            if (lineNum < output.stdoutLines.size) {
              output.stdoutLines[lineNum].take(12).padEnd(12)
            } else {
              "".padEnd(12)
            }
          }
          appendLine("$lineNumber | ${lineOutputs.joinToString(" | ")}")
        }
        appendLine()
      }
      
      // STDERR comparison
      if (maxStderrLines > 0) {
        appendLine("--- STDERR COMPARISON ---")
        appendLine("Line | ${outputs.joinToString(" | ") { it.engineName.padEnd(12) }}")
        appendLine("-----|${outputs.joinToString("|") { "-".repeat(14) }}")
        
        for (lineNum in 0 until maxStderrLines) {
          val lineNumber = (lineNum + 1).toString().padEnd(4)
          val lineOutputs = outputs.map { output ->
            if (lineNum < output.stderrLines.size) {
              output.stderrLines[lineNum].take(12).padEnd(12)
            } else {
              "".padEnd(12)
            }
          }
          appendLine("$lineNumber | ${lineOutputs.joinToString(" | ")}")
        }
        appendLine()
      }
      
      // Crash signatures if any
      val crashOutputs = outputs.filter { it.crashSignature != null }
      if (crashOutputs.isNotEmpty()) {
        appendLine("--- CRASH SIGNATURES ---")
        crashOutputs.forEach { output ->
          appendLine("${output.engineName}: ${output.crashSignature}")
        }
        appendLine()
      }
      
      // Discrepancy detection
      appendLine("=== DISCREPANCY ANALYSIS ===")
      val discrepancies = detectDiscrepancies(outputs)
      if (discrepancies.isEmpty()) {
        appendLine("No discrepancies detected - all engines produced consistent results")
      } else {
        discrepancies.forEachIndexed { index, discrepancy ->
          appendLine("Discrepancy ${index + 1}: ${discrepancy}")
        }
      }
    }
  }
  
  /**
   * Detects discrepancies between standardized outputs
   */
  private fun detectDiscrepancies(outputs: List<StandardizedOutput>): List<String> {
    val discrepancies = mutableListOf<String>()
    
    if (outputs.size < 2) return discrepancies
    
    // Check for status discrepancies
    val statuses = outputs.map { it.status }.toSet()
    if (statuses.size > 1) {
      discrepancies.add("Status mismatch: ${statuses.joinToString(" vs ")}")
    }
    
    // Check for exit code discrepancies
    val exitCodes = outputs.map { it.exitCode }.toSet()
    if (exitCodes.size > 1) {
      discrepancies.add("Exit code mismatch: ${exitCodes.joinToString(" vs ")}")
    }
    
    // Check for stdout discrepancies
    val stdoutSets = outputs.map { it.stdoutLines.toSet() }
    if (stdoutSets.toSet().size > 1) {
      discrepancies.add("STDOUT content mismatch between engines")
    }
    
    // Check for stderr discrepancies
    val stderrSets = outputs.map { it.stderrLines.toSet() }
    if (stderrSets.toSet().size > 1) {
      discrepancies.add("STDERR content mismatch between engines")
    }
    
    // Check for error type discrepancies
    val errorTypes = outputs.map { it.errorType }.filterNotNull().toSet()
    if (errorTypes.size > 1) {
      discrepancies.add("Error type mismatch: ${errorTypes.joinToString(" vs ")}")
    }
    
    return discrepancies
  }
  
  /**
   * Extracts error type from stderr output
   */
  private fun extractErrorType(stderr: String): String? {
    val errorPatterns = mapOf(
      "TypeError" to "TypeError",
      "ReferenceError" to "ReferenceError", 
      "SyntaxError" to "SyntaxError",
      "RangeError" to "RangeError",
      "URIError" to "URIError",
      "EvalError" to "EvalError"
    )
    
    for ((pattern, errorType) in errorPatterns) {
      if (stderr.contains(pattern, ignoreCase = true)) {
        return errorType
      }
    }
    
    return if (stderr.isNotBlank()) "RuntimeError" else null
  }
  
  /**
   * Extracts crash signature from stderr output
   */
  private fun extractCrashSignature(stderr: String): String? {
    val crashPatterns = listOf(
      "segmentation fault",
      "crash",
      "abort",
      "fatal error",
      "assertion failed"
    )
    
    for (pattern in crashPatterns) {
      if (stderr.contains(pattern, ignoreCase = true)) {
        return pattern
      }
    }
    
    return null
  }
  
  /**
   * Saves standardized output to a file
   */
  fun saveToFile(outputs: List<StandardizedOutput>, outputFile: File) {
    val formattedOutput = formatAsTable(outputs)
    outputFile.writeText(formattedOutput)
  }
  
  /**
   * Creates a compact CSV format for easy parsing
   */
  fun formatAsCSV(outputs: List<StandardizedOutput>): String {
    return buildString {
      // Header
      appendLine("test_id,timestamp,input_file,engine_name,exit_code,execution_time_ms,status,stdout_lines,stderr_lines,crash_signature,error_type")
      
      // Data rows
      outputs.forEach { output ->
        appendLine("${output.testId}," +
          "${output.timestamp}," +
          "${output.inputFile}," +
          "${output.engineName}," +
          "${output.exitCode}," +
          "${output.executionTimeMs}," +
          "${output.status}," +
          "\"${output.stdoutLines.joinToString("\\n")}\"," +
          "\"${output.stderrLines.joinToString("\\n")}\"," +
          "${output.crashSignature ?: ""}," +
          "${output.errorType ?: ""}")
      }
    }
  }
  
  /**
   * Creates a map-based comparison structure for quick discrepancy detection.
   * This provides O(1) lookup time for comparing outputs across engines.
   */
  fun createComparisonMap(outputs: List<StandardizedOutput>): ComparisonMap {
    val engineNames = outputs.map { it.engineName }
    val testId = outputs.firstOrNull()?.testId ?: "unknown"
    
    // Create maps for each comparison dimension
    val statusMap = outputs.associate { it.engineName to it.status }
    val exitCodeMap = outputs.associate { it.engineName to it.exitCode }
    val executionTimeMap = outputs.associate { it.engineName to it.executionTimeMs }
    val errorTypeMap = outputs.associate { it.engineName to it.errorType }
    val crashSignatureMap = outputs.associate { it.engineName to it.crashSignature }
    
    // Create stdout and stderr maps with line-by-line indexing
    val stdoutMap = createLineIndexedMap(outputs) { it.stdoutLines }
    val stderrMap = createLineIndexedMap(outputs) { it.stderrLines }
    
    // Create content-based maps for quick set operations
    val stdoutContentMap = outputs.associate { it.engineName to it.stdoutLines.toSet() }
    val stderrContentMap = outputs.associate { it.engineName to it.stderrLines.toSet() }
    
    return ComparisonMap(
      testId = testId,
      engineNames = engineNames,
      statusMap = statusMap,
      exitCodeMap = exitCodeMap,
      executionTimeMap = executionTimeMap,
      errorTypeMap = errorTypeMap,
      crashSignatureMap = crashSignatureMap,
      stdoutMap = stdoutMap,
      stderrMap = stderrMap,
      stdoutContentMap = stdoutContentMap,
      stderrContentMap = stderrContentMap
    )
  }
  
  /**
   * Creates a line-indexed map for quick line-by-line comparison.
   * Returns a map where keys are line numbers and values are maps of engine names to line content.
   */
  private fun createLineIndexedMap(
    outputs: List<StandardizedOutput>,
    lineExtractor: (StandardizedOutput) -> List<String>
  ): Map<Int, Map<String, String>> {
    val lineMap = mutableMapOf<Int, MutableMap<String, String>>()
    
    outputs.forEach { output ->
      val lines = lineExtractor(output)
      lines.forEachIndexed { index, line ->
        val lineNumber = index + 1
        lineMap.getOrPut(lineNumber) { mutableMapOf() }[output.engineName] = line
      }
    }
    
    return lineMap
  }
  
  /**
   * Performs quick discrepancy detection using map-based comparison.
   * Returns a list of discrepancies with O(1) lookup performance.
   */
  fun detectDiscrepanciesQuick(comparisonMap: ComparisonMap): List<QuickDiscrepancy> {
    val discrepancies = mutableListOf<QuickDiscrepancy>()
    
    // Check status discrepancies
    val statuses = comparisonMap.statusMap.values.toSet()
    if (statuses.size > 1) {
      discrepancies.add(QuickDiscrepancy(
        type = DiscrepancyType.STATUS_MISMATCH,
        description = "Different execution statuses: ${statuses.joinToString(" vs ")}",
        engines = comparisonMap.engineNames,
        values = statuses.map { it.name },
        details = comparisonMap.statusMap
      ))
    }
    
    // Check exit code discrepancies
    val exitCodes = comparisonMap.exitCodeMap.values.toSet()
    if (exitCodes.size > 1) {
      discrepancies.add(QuickDiscrepancy(
        type = DiscrepancyType.EXIT_CODE_MISMATCH,
        description = "Different exit codes: ${exitCodes.joinToString(" vs ")}",
        engines = comparisonMap.engineNames,
        values = exitCodes.map { it.toString() },
        details = comparisonMap.exitCodeMap
      ))
    }
    
    // Check stdout content discrepancies using set operations
    val stdoutSets = comparisonMap.stdoutContentMap.values.toSet()
    if (stdoutSets.size > 1) {
      discrepancies.add(QuickDiscrepancy(
        type = DiscrepancyType.STDOUT_CONTENT_MISMATCH,
        description = "Different stdout content between engines",
        engines = comparisonMap.engineNames,
        values = stdoutSets.map { it.joinToString("; ") },
        details = comparisonMap.stdoutContentMap
      ))
    }
    
    // Check stderr content discrepancies using set operations
    val stderrSets = comparisonMap.stderrContentMap.values.toSet()
    if (stderrSets.size > 1) {
      discrepancies.add(QuickDiscrepancy(
        type = DiscrepancyType.STDERR_CONTENT_MISMATCH,
        description = "Different stderr content between engines",
        engines = comparisonMap.engineNames,
        values = stderrSets.map { it.joinToString("; ") },
        details = comparisonMap.stderrContentMap
      ))
    }
    
    // Check error type discrepancies
    val errorTypes = comparisonMap.errorTypeMap.values.filterNotNull().toSet()
    if (errorTypes.size > 1) {
      discrepancies.add(QuickDiscrepancy(
        type = DiscrepancyType.ERROR_TYPE_MISMATCH,
        description = "Different error types: ${errorTypes.joinToString(" vs ")}",
        engines = comparisonMap.engineNames,
        values = errorTypes.toList(),
        details = comparisonMap.errorTypeMap
      ))
    }
    
    // Check crash signature discrepancies
    val crashSignatures = comparisonMap.crashSignatureMap.values.filterNotNull().toSet()
    if (crashSignatures.size > 1) {
      discrepancies.add(QuickDiscrepancy(
        type = DiscrepancyType.CRASH_SIGNATURE_MISMATCH,
        description = "Different crash signatures: ${crashSignatures.joinToString(" vs ")}",
        engines = comparisonMap.engineNames,
        values = crashSignatures.toList(),
        details = comparisonMap.crashSignatureMap
      ))
    }
    
    return discrepancies
  }
  
  /**
   * Finds specific line differences between engines using the map-based approach.
   * Returns line-by-line discrepancies for quick identification.
   */
  fun findLineDifferences(comparisonMap: ComparisonMap): List<LineDifference> {
    val lineDifferences = mutableListOf<LineDifference>()
    
    // Check stdout line differences
    comparisonMap.stdoutMap.forEach { (lineNumber, engineLines) ->
      val uniqueLines = engineLines.values.toSet()
      if (uniqueLines.size > 1) {
        lineDifferences.add(LineDifference(
          streamType = StreamType.STDOUT,
          lineNumber = lineNumber,
          engineLines = engineLines,
          uniqueContent = uniqueLines
        ))
      }
    }
    
    // Check stderr line differences
    comparisonMap.stderrMap.forEach { (lineNumber, engineLines) ->
      val uniqueLines = engineLines.values.toSet()
      if (uniqueLines.size > 1) {
        lineDifferences.add(LineDifference(
          streamType = StreamType.STDERR,
          lineNumber = lineNumber,
          engineLines = engineLines,
          uniqueContent = uniqueLines
        ))
      }
    }
    
    return lineDifferences
  }
  
  /**
   * Compares two specific engines using the map-based approach.
   * Returns detailed differences between the two engines.
   */
  fun compareEngines(
    comparisonMap: ComparisonMap,
    engine1: String,
    engine2: String
  ): EngineComparison {
    val status1 = comparisonMap.statusMap[engine1]
    val status2 = comparisonMap.statusMap[engine2]
    
    val exitCode1 = comparisonMap.exitCodeMap[engine1]
    val exitCode2 = comparisonMap.exitCodeMap[engine2]
    
    val stdout1 = comparisonMap.stdoutContentMap[engine1] ?: emptySet()
    val stdout2 = comparisonMap.stdoutContentMap[engine2] ?: emptySet()
    
    val stderr1 = comparisonMap.stderrContentMap[engine1] ?: emptySet()
    val stderr2 = comparisonMap.stderrContentMap[engine2] ?: emptySet()
    
    return EngineComparison(
      engine1 = engine1,
      engine2 = engine2,
      statusMatch = status1 == status2,
      exitCodeMatch = exitCode1 == exitCode2,
      stdoutMatch = stdout1 == stdout2,
      stderrMatch = stderr1 == stderr2,
      statusDifference = if (status1 != status2) "${status1} vs ${status2}" else null,
      exitCodeDifference = if (exitCode1 != exitCode2) "${exitCode1} vs ${exitCode2}" else null,
      stdoutDifference = if (stdout1 != stdout2) {
        val onlyIn1 = stdout1 - stdout2
        val onlyIn2 = stdout2 - stdout1
        "Only in $engine1: ${onlyIn1.joinToString(", ")} | Only in $engine2: ${onlyIn2.joinToString(", ")}"
      } else null,
      stderrDifference = if (stderr1 != stderr2) {
        val onlyIn1 = stderr1 - stderr2
        val onlyIn2 = stderr2 - stderr1
        "Only in $engine1: ${onlyIn1.joinToString(", ")} | Only in $engine2: ${onlyIn2.joinToString(", ")}"
      } else null
    )
  }
  
  /**
   * Data class representing a map-based comparison structure for quick lookups
   */
  data class ComparisonMap(
    val testId: String,
    val engineNames: List<String>,
    val statusMap: Map<String, ExecutionStatus>,
    val exitCodeMap: Map<String, Int>,
    val executionTimeMap: Map<String, Long>,
    val errorTypeMap: Map<String, String?>,
    val crashSignatureMap: Map<String, String?>,
    val stdoutMap: Map<Int, Map<String, String>>,
    val stderrMap: Map<Int, Map<String, String>>,
    val stdoutContentMap: Map<String, Set<String>>,
    val stderrContentMap: Map<String, Set<String>>
  )
  
  /**
   * Data class representing a quick discrepancy detected using map-based comparison
   */
  data class QuickDiscrepancy(
    val type: DiscrepancyType,
    val description: String,
    val engines: List<String>,
    val values: List<String>,
    val details: Map<String, Any>
  )
  
  /**
   * Data class representing a line-by-line difference
   */
  data class LineDifference(
    val streamType: StreamType,
    val lineNumber: Int,
    val engineLines: Map<String, String>,
    val uniqueContent: Set<String>
  )
  
  /**
   * Data class representing a comparison between two specific engines
   */
  data class EngineComparison(
    val engine1: String,
    val engine2: String,
    val statusMatch: Boolean,
    val exitCodeMatch: Boolean,
    val stdoutMatch: Boolean,
    val stderrMatch: Boolean,
    val statusDifference: String?,
    val exitCodeDifference: String?,
    val stdoutDifference: String?,
    val stderrDifference: String?
  )
  
  enum class DiscrepancyType {
    STATUS_MISMATCH,
    EXIT_CODE_MISMATCH,
    STDOUT_CONTENT_MISMATCH,
    STDERR_CONTENT_MISMATCH,
    ERROR_TYPE_MISMATCH,
    CRASH_SIGNATURE_MISMATCH
  }
  
  enum class StreamType {
    STDOUT,
    STDERR
  }
}
