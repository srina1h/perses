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
package org.perses.fuzzer.instrumentation.probes

import org.perses.fuzzer.instrumentation.InstrumentationConfig
import org.perses.spartree.AbstractSparTreeNode

/**
 * Base interface for all probe types that can be inserted into JavaScript code.
 */
interface Probe {
  
  /**
   * The type of this probe.
   */
  val probeType: InstrumentationConfig.ProbeType
  
  /**
   * Generate the probe code that will be inserted into the JavaScript program.
   */
  fun generateProbeCode(): String
  
  /**
   * Get a unique identifier for this probe instance.
   */
  fun getProbeId(): String
  
  /**
   * Get the source location information for this probe.
   */
  fun getSourceLocation(): SourceLocation?
  
  /**
   * Check if this probe should be applied to the given AST node.
   */
  fun shouldApplyTo(node: AbstractSparTreeNode): Boolean
  
  /**
   * Get the priority of this probe (higher priority probes are applied first).
   */
  fun getPriority(): Int = 0
}

/**
 * Abstract base class for probes that provides common functionality.
 */
abstract class AbstractProbe(
  override val probeType: InstrumentationConfig.ProbeType,
  private val sourceLocation: SourceLocation? = null,
  private val probeId: String? = null
) : Probe {
  
  override fun getProbeId(): String {
    return probeId ?: "${probeType.name}_${System.currentTimeMillis()}_${hashCode()}"
  }
  
  override fun getSourceLocation(): SourceLocation? = sourceLocation
  
  /**
   * Generate a probe function call with the given arguments.
   */
  protected fun generateProbeCall(functionName: String, vararg arguments: String): String {
    val args = arguments.joinToString(", ")
    return "__PROBE_${functionName}($args);"
  }
  
  /**
   * Generate a probe function call that captures a value.
   */
  protected fun generateValueCapture(variableName: String, expression: String): String {
    return "__PROBE_CAPTURE_VALUE(\"$variableName\", $expression);"
  }
  
  /**
   * Generate a probe function call that captures type information.
   */
  protected fun generateTypeCapture(variableName: String, expression: String): String {
    return "__PROBE_CAPTURE_TYPE(\"$variableName\", $expression);"
  }
}

/**
 * Represents a source location in the original code.
 */
data class SourceLocation(
  val line: Int,
  val column: Int,
  val fileName: String? = null
) {
  override fun toString(): String {
    return fileName?.let { "$it:$line:$column" } ?: "$line:$column"
  }
}

/**
 * Result of applying a probe to an AST node.
 */
data class ProbeApplicationResult(
  val probe: Probe,
  val insertedCode: String,
  val sourceLocation: SourceLocation?,
  val success: Boolean,
  val errorMessage: String? = null
) {
  companion object {
    fun success(probe: Probe, insertedCode: String, sourceLocation: SourceLocation?): ProbeApplicationResult {
      return ProbeApplicationResult(probe, insertedCode, sourceLocation, true)
    }
    
    fun failure(probe: Probe, errorMessage: String): ProbeApplicationResult {
      return ProbeApplicationResult(probe, "", null, false, errorMessage)
    }
  }
} 