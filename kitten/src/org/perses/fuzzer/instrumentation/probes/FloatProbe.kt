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
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.ParserRuleSparTreeNode

/**
 * Probe for capturing IEEE 754 binary representation and precision information
 * for floating-point numbers. This probe helps detect differences in how engines
 * handle floating-point arithmetic and precision.
 */
class FloatProbe(
  private val targetExpression: String,
  private val variableName: String? = null,
  sourceLocation: SourceLocation? = null
) : AbstractProbe(InstrumentationConfig.ProbeType.FLOAT, sourceLocation) {
  
  override fun generateProbeCode(): String {
    val varName = variableName ?: "float_probe_${hashCode()}"
    val probes = mutableListOf<String>()
    
    // Basic floating-point information
    probes.add(generateProbeCall("FLOAT_BINARY", "\"$varName\"", targetExpression))
    
    // Precision information
    probes.add(generateProbeCall("FLOAT_PRECISION", "\"$varName\"", targetExpression))
    
    // IEEE 754 components (sign, exponent, mantissa)
    probes.add(generateProbeCall("FLOAT_COMPONENTS", "\"$varName\"", targetExpression))
    
    // Special values (Infinity, NaN, etc.)
    probes.add(generateProbeCall("FLOAT_SPECIAL_VALUES", "\"$varName\"", targetExpression))
    
    // Rounding behavior
    probes.add(generateProbeCall("FLOAT_ROUNDING", "\"$varName\"", targetExpression))
    
    // String representation
    probes.add(generateProbeCall("FLOAT_STRING_REPR", "\"$varName\"", targetExpression))
    
    return probes.joinToString("\n")
  }
  
  override fun shouldApplyTo(node: AbstractSparTreeNode): Boolean {
    val nodeText = getNodeText(node)
    
    // Skip very short expressions
    if (nodeText.length < 3) return false
    
    // Check for floating-point literals or arithmetic expressions
    val hasFloatLiteral = nodeText.matches(Regex(".*\\b\\d+\\.\\d+\\b.*")) ||
                         nodeText.matches(Regex(".*\\b\\d+e[+-]?\\d+\\b.*")) ||
                         nodeText.matches(Regex(".*\\b\\d+\\.\\d+e[+-]?\\d+\\b.*"))
    
    // Check for arithmetic operations that might involve floating-point
    val hasArithmeticOp = nodeText.contains("+") || nodeText.contains("-") || 
                         nodeText.contains("*") || nodeText.contains("/") ||
                         nodeText.contains("%")
    
    // Check for specific floating-point constants
    val hasFloatConstants = nodeText.contains("Math.PI") || nodeText.contains("Math.E") ||
                           nodeText.contains("Number.MAX_VALUE") || nodeText.contains("Number.MIN_VALUE") ||
                           nodeText.contains("Infinity") || nodeText.contains("NaN")
    
    return hasFloatLiteral || (hasArithmeticOp && hasFloatConstants)
  }
  
  private fun getNodeText(node: AbstractSparTreeNode): String {
    return when (node) {
      is LexerRuleSparTreeNode -> node.token.text
      is ParserRuleSparTreeNode -> node.tokenListCostlyComputed.joinToString("")
      else -> ""
    }
  }
  
  override fun getPriority(): Int = 15 // Higher priority for floating-point operations
  
  /**
   * Get the target expression for this probe.
   */
  fun getTargetExpression(): String = targetExpression
  
  companion object {
    /**
     * Create a float probe for a floating-point literal.
     */
    fun forFloatLiteral(literal: String, sourceLocation: SourceLocation? = null): FloatProbe {
      return FloatProbe(literal, null, sourceLocation)
    }
    
    /**
     * Create a float probe for an arithmetic expression.
     */
    fun forArithmeticExpression(expression: String, variableName: String? = null, sourceLocation: SourceLocation? = null): FloatProbe {
      return FloatProbe(expression, variableName, sourceLocation)
    }
    
    /**
     * Create a float probe for a variable that might contain floating-point values.
     */
    fun forVariable(variableName: String, sourceLocation: SourceLocation? = null): FloatProbe {
      return FloatProbe(variableName, variableName, sourceLocation)
    }
  }
} 