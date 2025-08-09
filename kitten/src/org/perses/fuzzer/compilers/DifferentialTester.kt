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

/**
 * Performs differential testing by running the same input on multiple engines
 * and comparing their outputs to detect discrepancies.
 */
class DifferentialTester(
  private val facades: List<AbstractCompilerConfigurationFacade>
) {
  private enum class Status { SUCCESS, ERROR, CRASH, HANG }
  private data class Outcome(val status: Status, val errorKind: String? = null)
  
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
    
    logger.atFine().log("Seed %s passed on all engines", seedFile)
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
  
  private fun getEngineName(action: ICompilationAction): String {
    // Try to extract a meaningful name from the command
    val cmd = action.constructCompileCmd(File("dummy"))
    return when {
      cmd.contains("v8") -> "V8"
      cmd.contains("hermes") -> "Hermes"
      cmd.contains("graaljs") -> "GraalJS"
      cmd.contains("jsc") -> "JavaScriptCore"
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

    fun normalizeStdout(out: String): String {
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