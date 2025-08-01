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
    
    // Compare each pair of engines
    for (i in 0 until engines.size - 1) {
      for (j in i + 1 until engines.size) {
        val engine1 = engines[i]
        val engine2 = engines[j]
        val result1 = engineResults[engine1]!!
        val result2 = engineResults[engine2]!!
        
        // Check exit code discrepancies
        if (result1.exitCode != result2.exitCode) {
          discrepancies.add(
            DifferentialTestResult.Discrepancy(
              type = DifferentialTestResult.Discrepancy.DiscrepancyType.EXIT_CODE_MISMATCH,
              description = "Exit code mismatch between $engine1 and $engine2",
              engine1 = engine1,
              engine2 = engine2,
              value1 = result1.exitCode.toString(),
              value2 = result2.exitCode.toString()
            )
          )
        }
        
        // Check stdout discrepancies (only if both succeeded)
        if (result1.exitCode == 0 && result2.exitCode == 0 && result1.stdout != result2.stdout) {
          discrepancies.add(
            DifferentialTestResult.Discrepancy(
              type = DifferentialTestResult.Discrepancy.DiscrepancyType.STDOUT_MISMATCH,
              description = "STDOUT mismatch between $engine1 and $engine2",
              engine1 = engine1,
              engine2 = engine2,
              value1 = result1.stdout,
              value2 = result2.stdout
            )
          )
        }
        
        // Check stderr discrepancies
        if (result1.stderr != result2.stderr) {
          discrepancies.add(
            DifferentialTestResult.Discrepancy(
              type = DifferentialTestResult.Discrepancy.DiscrepancyType.STDERR_MISMATCH,
              description = "STDERR mismatch between $engine1 and $engine2",
              engine1 = engine1,
              engine2 = engine2,
              value1 = result1.stderr,
              value2 = result2.stderr
            )
          )
        }
        
        // Check crash vs no crash discrepancies
        val crash1 = getCrashDetectorForEngine(engine1).detectCrash(result1.cmdOutput).isCrashDetected()
        val crash2 = getCrashDetectorForEngine(engine2).detectCrash(result2.cmdOutput).isCrashDetected()
        
        if (crash1 != crash2) {
          discrepancies.add(
            DifferentialTestResult.Discrepancy(
              type = DifferentialTestResult.Discrepancy.DiscrepancyType.CRASH_VS_NO_CRASH,
              description = "Crash behavior mismatch: $engine1 ${if (crash1) "crashed" else "didn't crash"}, $engine2 ${if (crash2) "crashed" else "didn't crash"}",
              engine1 = engine1,
              engine2 = engine2,
              value1 = if (crash1) "CRASH" else "NO_CRASH",
              value2 = if (crash2) "CRASH" else "NO_CRASH"
            )
          )
        }
        
        // Check different crash signatures
        if (crash1 && crash2) {
          val signature1 = getCrashDetectorForEngine(engine1).detectCrash(result1.cmdOutput).asCrash().signature.toString()
          val signature2 = getCrashDetectorForEngine(engine2).detectCrash(result2.cmdOutput).asCrash().signature.toString()
          
          if (signature1 != signature2) {
            discrepancies.add(
              DifferentialTestResult.Discrepancy(
                type = DifferentialTestResult.Discrepancy.DiscrepancyType.DIFFERENT_CRASH_SIGNATURES,
                description = "Different crash signatures between $engine1 and $engine2",
                engine1 = engine1,
                engine2 = engine2,
                value1 = signature1,
                value2 = signature2
              )
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