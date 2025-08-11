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
package org.perses.fuzzer

import com.google.common.flogger.FluentLogger
import org.perses.fuzzer.compilers.DifferentialTestResult
import org.perses.fuzzer.compilers.ICompilationAction
import org.perses.program.TokenizedProgram
import java.io.File
import java.text.SimpleDateFormat
import java.util.*

class DifferentialFindingFolder private constructor(
  private val folder: File,
  private val seedProgram: TokenizedProgram,
  private val mutantFile: File,
  private val differentialResult: DifferentialTestResult,
  private val action: ICompilationAction
) : AutoCloseable {

  fun getFolder(): File = folder

  override fun close() {
    // The folder is automatically cleaned up when the JVM exits
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
    private val dateFormat = SimpleDateFormat("yyyyMMdd_HHmmss")

      fun create(
    findingFolder: FindingFolder,
    seedProgram: TokenizedProgram,
    seedFile: File,
    mutantFile: File,
    differentialResult: DifferentialTestResult,
    action: ICompilationAction
  ): DifferentialFindingFolder {
    val timestamp = dateFormat.format(Date())
    val folderName = "differential_finding_${timestamp}_${System.currentTimeMillis()}"
    val folder = File(findingFolder.root, folderName)
    
    // Try to create the folder with retries
    var attempts = 0
    while (!folder.exists() && attempts < 3) {
      if (folder.mkdirs()) {
        break
      }
      attempts++
      Thread.sleep(100) // Wait a bit before retrying
    }
    
    if (!folder.exists()) {
      logger.atWarning().log("Failed to create folder after $attempts attempts: $folder")
      return DifferentialFindingFolder(
        File(findingFolder.root, "failed_creation_${System.currentTimeMillis()}"), 
        seedProgram, mutantFile, differentialResult, action
      )
    }

    // Create the differential finding folder
    val differentialFindingFolder = DifferentialFindingFolder(
      folder, seedProgram, mutantFile, differentialResult, action
    )

    try {
      // Save the input file
      val inputFile = File(folder, "input.${getFileExtension(mutantFile.name)}")
      mutantFile.copyTo(inputFile)

      // Save the seed file
      val seedFileCopy = File(folder, "seed.${getFileExtension(seedFile.name)}")
      seedFile.copyTo(seedFileCopy)

      // Save differential test results
      saveDifferentialResults(folder, differentialResult)

      // Save engine outputs
      saveEngineOutputs(folder, differentialResult)

      // Save summary
      saveSummary(folder, differentialResult)
      
      // Save concise difference summary
      saveDifferenceSummary(folder, differentialResult)
      
      // Save diff view
      saveDiffView(folder, differentialResult)
    } catch (e: Exception) {
      logger.atWarning().withCause(e).log("Failed to save files to folder: $folder")
    }

      logger.atInfo().log("Created differential finding folder: $folder")
      return differentialFindingFolder
    }

    private fun getFileExtension(fileName: String): String {
      val lastDotIndex = fileName.lastIndexOf('.')
      return if (lastDotIndex >= 0) fileName.substring(lastDotIndex + 1) else "txt"
    }

    private fun saveDifferentialResults(folder: File, result: DifferentialTestResult) {
      val resultsFile = File(folder, "differential_results.txt")
      resultsFile.writeText(buildString {
        appendLine("=== DIFFERENTIAL TEST RESULTS ===")
        appendLine("Input file: ${result.inputFile.name}")
        appendLine("Number of engines tested: ${result.engineResults.size}")
        appendLine("Has discrepancies: ${result.hasDiscrepancy}")
        appendLine()
        
        if (result.discrepancies.isNotEmpty()) {
          appendLine("=== DISCREPANCIES FOUND ===")
          result.discrepancies.forEachIndexed { index, discrepancy ->
            appendLine("Discrepancy ${index + 1}:")
            appendLine("  Type: ${discrepancy.type}")
            appendLine("  Description: ${discrepancy.description}")
            appendLine("  Engines: ${discrepancy.engine1} vs ${discrepancy.engine2}")
            appendLine()
            
            // Show engine outputs for this discrepancy
            val engine1Result = result.engineResults[discrepancy.engine1]
            val engine2Result = result.engineResults[discrepancy.engine2]
            
            if (engine1Result != null && engine2Result != null) {
              appendLine("  ${discrepancy.engine1} output:")
              appendLine("    Exit code: ${engine1Result.exitCode}")
              appendLine("    Stdout: ${engine1Result.stdout}")
              if (engine1Result.stderr.isNotEmpty()) {
                appendLine("    Stderr: ${engine1Result.stderr}")
              }
              appendLine()
              
              appendLine("  ${discrepancy.engine2} output:")
              appendLine("    Exit code: ${engine2Result.exitCode}")
              appendLine("    Stdout: ${engine2Result.stdout}")
              if (engine2Result.stderr.isNotEmpty()) {
                appendLine("    Stderr: ${engine2Result.stderr}")
              }
              appendLine()
              
              // Show the specific difference
              appendLine("  DIFFERENCE:")
              when (discrepancy.type) {
                DifferentialTestResult.Discrepancy.DiscrepancyType.SPEC_DIVERGENCE -> {
                  appendLine("    Stdout differs:")
                  appendLine("      ${discrepancy.engine1}: ${discrepancy.value1}")
                  appendLine("      ${discrepancy.engine2}: ${discrepancy.value2}")
                }
                DifferentialTestResult.Discrepancy.DiscrepancyType.SUCCESS_VS_ERROR -> {
                  appendLine("    Execution outcome differs:")
                  appendLine("      ${discrepancy.engine1}: ${discrepancy.value1}")
                  appendLine("      ${discrepancy.engine2}: ${discrepancy.value2}")
                }
                DifferentialTestResult.Discrepancy.DiscrepancyType.DIFFERENT_ERROR_TYPES -> {
                  appendLine("    Error types differ:")
                  appendLine("      ${discrepancy.engine1}: ${discrepancy.value1}")
                  appendLine("      ${discrepancy.engine2}: ${discrepancy.value2}")
                }
                DifferentialTestResult.Discrepancy.DiscrepancyType.CRASH_OR_HANG -> {
                  appendLine("    Crash/Hang behavior differs:")
                  appendLine("      ${discrepancy.engine1}: ${discrepancy.value1}")
                  appendLine("      ${discrepancy.engine2}: ${discrepancy.value2}")
                }
                DifferentialTestResult.Discrepancy.DiscrepancyType.DIFFERENT_CRASH_SIGNATURES -> {
                  appendLine("    Crash signatures differ:")
                  appendLine("      ${discrepancy.engine1}: ${discrepancy.value1}")
                  appendLine("      ${discrepancy.engine2}: ${discrepancy.value2}")
                }
                else -> {
                  appendLine("    Values differ:")
                  appendLine("      ${discrepancy.engine1}: ${discrepancy.value1}")
                  appendLine("      ${discrepancy.engine2}: ${discrepancy.value2}")
                }
              }
            }
            appendLine()
          }
        } else {
          appendLine("No discrepancies found - all engines behaved consistently.")
        }
      })
    }

    private fun saveEngineOutputs(folder: File, result: DifferentialTestResult) {
      result.engineResults.forEach { (engineName, engineResult) ->
        val engineFolder = File(folder, "engine_${engineName.lowercase()}")
        engineFolder.mkdirs()

        // Save command
        File(engineFolder, "command.txt").writeText(engineResult.cmd)

        // Save exit code
        File(engineFolder, "exit_code.txt").writeText(engineResult.exitCode.toString())

        // Save stdout
        File(engineFolder, "stdout.txt").writeText(engineResult.stdout)

        // Save stderr
        File(engineFolder, "stderr.txt").writeText(engineResult.stderr)
      }
    }

    private fun saveSummary(folder: File, result: DifferentialTestResult) {
      val summaryFile = File(folder, "summary.txt")
      summaryFile.writeText(buildString {
        appendLine("=== DIFFERENTIAL TESTING SUMMARY ===")
        appendLine("Timestamp: ${Date()}")
        appendLine("Input file: ${result.inputFile.name}")
        appendLine()
        
        appendLine("Engines tested:")
        result.engineResults.forEach { (engineName, engineResult) ->
          appendLine("  $engineName: exit_code=${engineResult.exitCode}")
        }
        appendLine()
        
        if (result.hasDiscrepancy) {
          appendLine("DISCREPANCIES DETECTED:")
          result.discrepancies.forEach { discrepancy ->
            appendLine("  - ${discrepancy.description}")
          }
        } else {
          appendLine("No discrepancies detected - all engines behaved consistently.")
        }
      })
    }
    
    private fun saveDifferenceSummary(folder: File, result: DifferentialTestResult) {
      val diffFile = File(folder, "differences.txt")
      diffFile.writeText(buildString {
        appendLine("=== QUICK DIFFERENCE SUMMARY ===")
        appendLine("Input: ${result.inputFile.name}")
        appendLine("Engines: ${result.engineResults.keys.joinToString(", ")}")
        appendLine()
        
        if (result.hasDiscrepancy) {
          result.discrepancies.forEachIndexed { index, discrepancy ->
            appendLine("DIFFERENCE ${index + 1}: ${discrepancy.engine1} vs ${discrepancy.engine2}")
            appendLine("Type: ${discrepancy.type}")
            appendLine("Description: ${discrepancy.description}")
            appendLine()
            
            // Show only the differing values
            appendLine("${discrepancy.engine1}: ${discrepancy.value1}")
            appendLine("${discrepancy.engine2}: ${discrepancy.value2}")
            appendLine()
            
            // For SPEC_DIVERGENCE, also show the full outputs for context
            if (discrepancy.type == DifferentialTestResult.Discrepancy.DiscrepancyType.SPEC_DIVERGENCE) {
              val engine1Result = result.engineResults[discrepancy.engine1]
              val engine2Result = result.engineResults[discrepancy.engine2]
              
              if (engine1Result != null && engine2Result != null) {
                appendLine("Full outputs:")
                appendLine("${discrepancy.engine1} stdout: ${engine1Result.stdout}")
                appendLine("${discrepancy.engine2} stdout: ${engine2Result.stdout}")
                appendLine()
              }
            }
          }
        } else {
          appendLine("✓ All engines produced identical results")
        }
      })
    }
    
    private fun saveDiffView(folder: File, result: DifferentialTestResult) {
      val diffViewFile = File(folder, "diff_view.txt")
      diffViewFile.writeText(buildString {
        appendLine("=== DIFF VIEW ===")
        appendLine("Input: ${result.inputFile.name}")
        appendLine()
        
        if (result.hasDiscrepancy) {
          result.discrepancies.forEachIndexed { index, discrepancy ->
            appendLine("--- DIFFERENCE ${index + 1} ---")
            appendLine("${discrepancy.engine1} vs ${discrepancy.engine2}")
            appendLine("Type: ${discrepancy.type}")
            appendLine()
            
            when (discrepancy.type) {
              DifferentialTestResult.Discrepancy.DiscrepancyType.SPEC_DIVERGENCE -> {
                // Show diff-like format for stdout differences
                val engine1Result = result.engineResults[discrepancy.engine1]
                val engine2Result = result.engineResults[discrepancy.engine2]
                
                if (engine1Result != null && engine2Result != null) {
                  appendLine("Exit codes:")
                  appendLine("  ${discrepancy.engine1}: ${engine1Result.exitCode}")
                  appendLine("  ${discrepancy.engine2}: ${engine2Result.exitCode}")
                  appendLine()
                  
                  appendLine("Stdout diff:")
                  appendLine("- ${discrepancy.engine1}: ${discrepancy.value1}")
                  appendLine("+ ${discrepancy.engine2}: ${discrepancy.value2}")
                  appendLine()
                  
                  // Show stderr if present
                  if (engine1Result.stderr.isNotEmpty() || engine2Result.stderr.isNotEmpty()) {
                    appendLine("Stderr:")
                    if (engine1Result.stderr.isNotEmpty()) {
                      appendLine("  ${discrepancy.engine1}: ${engine1Result.stderr}")
                    }
                    if (engine2Result.stderr.isNotEmpty()) {
                      appendLine("  ${discrepancy.engine2}: ${engine2Result.stderr}")
                    }
                    appendLine()
                  }
                }
              }
              DifferentialTestResult.Discrepancy.DiscrepancyType.SUCCESS_VS_ERROR -> {
                appendLine("Execution outcome:")
                appendLine("- ${discrepancy.engine1}: ${discrepancy.value1}")
                appendLine("+ ${discrepancy.engine2}: ${discrepancy.value2}")
                appendLine()
              }
              DifferentialTestResult.Discrepancy.DiscrepancyType.DIFFERENT_ERROR_TYPES -> {
                appendLine("Error types:")
                appendLine("- ${discrepancy.engine1}: ${discrepancy.value1}")
                appendLine("+ ${discrepancy.engine2}: ${discrepancy.value2}")
                appendLine()
              }
              DifferentialTestResult.Discrepancy.DiscrepancyType.CRASH_OR_HANG -> {
                appendLine("Crash/Hang behavior:")
                appendLine("- ${discrepancy.engine1}: ${discrepancy.value1}")
                appendLine("+ ${discrepancy.engine2}: ${discrepancy.value2}")
                appendLine()
              }
              DifferentialTestResult.Discrepancy.DiscrepancyType.DIFFERENT_CRASH_SIGNATURES -> {
                appendLine("Crash signatures:")
                appendLine("- ${discrepancy.engine1}: ${discrepancy.value1}")
                appendLine("+ ${discrepancy.engine2}: ${discrepancy.value2}")
                appendLine()
              }
              else -> {
                appendLine("Values:")
                appendLine("- ${discrepancy.engine1}: ${discrepancy.value1}")
                appendLine("+ ${discrepancy.engine2}: ${discrepancy.value2}")
                appendLine()
              }
            }
          }
        } else {
          appendLine("✓ No differences found")
        }
      })
    }
  }
} 