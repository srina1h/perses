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

import org.perses.util.shell.CmdOutput
import java.io.File

/**
 * Represents the result of running a program on multiple engines for differential testing.
 */
data class DifferentialTestResult(
  val inputFile: File,
  val engineResults: Map<String, EngineResult>,
  val discrepancies: List<Discrepancy>,
  val hasDiscrepancy: Boolean = discrepancies.isNotEmpty()
) {
  
  data class EngineResult(
    val engineName: String,
    val action: ICompilationAction,
    val cmdOutput: CmdOutput,
    val cmd: String,
    val exitCode: Int,
    val stdout: String,
    val stderr: String
  )
  
  data class Discrepancy(
    val type: DiscrepancyType,
    val description: String,
    val engine1: String,
    val engine2: String,
    val value1: String,
    val value2: String
  ) {
    enum class DiscrepancyType {
      EXIT_CODE_MISMATCH,
      STDOUT_MISMATCH,
      STDERR_MISMATCH,
      CRASH_VS_NO_CRASH,
      DIFFERENT_CRASH_SIGNATURES
    }
  }
  
  fun getEngineNames(): List<String> = engineResults.keys.toList()
  
  fun getResultForEngine(engineName: String): EngineResult? = engineResults[engineName]
  
  fun getExitCodes(): Map<String, Int> = engineResults.mapValues { it.value.exitCode }
  
  fun getStdouts(): Map<String, String> = engineResults.mapValues { it.value.stdout }
  
  fun getStderrs(): Map<String, String> = engineResults.mapValues { it.value.stderr }
} 