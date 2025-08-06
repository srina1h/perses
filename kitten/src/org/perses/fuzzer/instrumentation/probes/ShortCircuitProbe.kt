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
 * Probe for detecting incorrect evaluation of logical operators (&&, ||, ??).
 * This probe helps detect differences in short-circuit evaluation behavior
 * across JavaScript engines.
 */
class ShortCircuitProbe(
  private val leftOperand: String,
  private val rightOperand: String,
  private val operator: String,
  private val variableName: String? = null,
  sourceLocation: SourceLocation? = null
) : AbstractProbe(InstrumentationConfig.ProbeType.SHORT_CIRCUIT, sourceLocation) {
  
  override fun generateProbeCode(): String {
    val varName = variableName ?: "short_circuit_probe_${hashCode()}"
    val probes = mutableListOf<String>()
    
    // Create wrapper functions to capture evaluation order
    probes.add("""
      let __left_evaluated = false;
      let __right_evaluated = false;
      let __left_value = null;
      let __right_value = null;
      
      function __getLeft() {
        __left_evaluated = true;
        __left_value = $leftOperand;
        return __left_value;
      }
      
      function __getRight() {
        __right_evaluated = true;
        __right_value = $rightOperand;
        return __right_value;
      }
    """.trimIndent())
    
    // Perform the logical operation with monitoring
    val logicalExpression = when (operator) {
      "&&" -> "__getLeft() && __getRight()"
      "||" -> "__getLeft() || __getRight()"
      "??" -> "__getLeft() ?? __getRight()"
      else -> throw IllegalArgumentException("Unsupported logical operator: $operator")
    }
    
    probes.add("let $varName = $logicalExpression;")
    
    // Capture evaluation information
    probes.add(generateProbeCall("SHORT_CIRCUIT_EVAL", 
      "\"$varName\"", 
      "\"$operator\"",
      "__left_evaluated.toString()",
      "__right_evaluated.toString()",
      "JSON.stringify(__left_value)",
      "JSON.stringify(__right_value)",
      "JSON.stringify($varName)"
    ))
    
    return probes.joinToString("\n")
  }
  
  override fun shouldApplyTo(node: AbstractSparTreeNode): Boolean {
    val nodeText = getNodeText(node)
    
    // Check for logical operators
    val hasLogicalOp = nodeText.contains(" && ") || nodeText.contains(" || ") || nodeText.contains(" ?? ")
    
    // Check for complex expressions that might benefit from short-circuit probing
    val hasComplexExpr = nodeText.contains("(") && nodeText.contains(")") && hasLogicalOp
    
    return hasLogicalOp && (hasComplexExpr || nodeText.contains("="))
  }
  
  private fun getNodeText(node: AbstractSparTreeNode): String {
    return when (node) {
      is LexerRuleSparTreeNode -> node.token.text
      is ParserRuleSparTreeNode -> node.tokenListCostlyComputed.joinToString("")
      else -> ""
    }
  }
  
  override fun getPriority(): Int = 20 // High priority for logical operations
  
  /**
   * Get the target expression for this probe.
   */
  fun getTargetExpression(): String = "$leftOperand $operator $rightOperand"
  
  companion object {
    /**
     * Create a short-circuit probe for a logical AND operation.
     */
    fun forLogicalAnd(leftOperand: String, rightOperand: String, variableName: String? = null, sourceLocation: SourceLocation? = null): ShortCircuitProbe {
      return ShortCircuitProbe(leftOperand, rightOperand, "&&", variableName, sourceLocation)
    }
    
    /**
     * Create a short-circuit probe for a logical OR operation.
     */
    fun forLogicalOr(leftOperand: String, rightOperand: String, variableName: String? = null, sourceLocation: SourceLocation? = null): ShortCircuitProbe {
      return ShortCircuitProbe(leftOperand, rightOperand, "||", variableName, sourceLocation)
    }
    
    /**
     * Create a short-circuit probe for a nullish coalescing operation.
     */
    fun forNullishCoalescing(leftOperand: String, rightOperand: String, variableName: String? = null, sourceLocation: SourceLocation? = null): ShortCircuitProbe {
      return ShortCircuitProbe(leftOperand, rightOperand, "??", variableName, sourceLocation)
    }
    
    /**
     * Parse a logical expression and create appropriate probes.
     */
    fun fromExpression(expression: String, variableName: String? = null, sourceLocation: SourceLocation? = null): List<ShortCircuitProbe> {
      val probes = mutableListOf<ShortCircuitProbe>()
      
      // Simple regex-based parsing for common patterns
      val andPattern = Regex("(\\w+)\\s*&&\\s*(\\w+)")
      val orPattern = Regex("(\\w+)\\s*\\|\\|\\s*(\\w+)")
      val nullishPattern = Regex("(\\w+)\\s*\\?\\?\\s*(\\w+)")
      
      andPattern.find(expression)?.let { match ->
        probes.add(forLogicalAnd(match.groupValues[1], match.groupValues[2], variableName, sourceLocation))
      }
      
      orPattern.find(expression)?.let { match ->
        probes.add(forLogicalOr(match.groupValues[1], match.groupValues[2], variableName, sourceLocation))
      }
      
      nullishPattern.find(expression)?.let { match ->
        probes.add(forNullishCoalescing(match.groupValues[1], match.groupValues[2], variableName, sourceLocation))
      }
      
      return probes
    }
  }
} 