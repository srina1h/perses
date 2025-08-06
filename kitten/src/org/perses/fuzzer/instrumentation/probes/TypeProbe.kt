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
 * Probe for capturing deep type and structure information about JavaScript values.
 * This probe helps detect differences in how engines handle type coercion,
 * object properties, and prototype chains.
 */
class TypeProbe(
  private val targetExpression: String,
  private val variableName: String? = null,
  sourceLocation: SourceLocation? = null
) : AbstractProbe(InstrumentationConfig.ProbeType.TYPE, sourceLocation) {
  
  override fun generateProbeCode(): String {
    val varName = variableName ?: "type_probe_${hashCode()}"
    val probes = mutableListOf<String>()
    
    // Basic type information
    probes.add(generateTypeCapture(varName, targetExpression))
    
    // Constructor information
    probes.add(generateProbeCall("CONSTRUCTOR", "\"$varName\"", "$targetExpression.constructor"))
    
    // Prototype chain information
    probes.add(generateProbeCall("PROTOTYPE_CHAIN", "\"$varName\"", targetExpression))
    
    // Object property enumeration
    if (targetExpression.contains(".") || targetExpression.matches(Regex("[a-zA-Z_$][a-zA-Z0-9_$]*"))) {
      probes.add(generateProbeCall("ENUMERATE_PROPERTIES", "\"$varName\"", targetExpression))
    }
    
    // Array-specific information
    probes.add(generateProbeCall("ARRAY_INFO", "\"$varName\"", targetExpression))
    
    // Function-specific information
    probes.add(generateProbeCall("FUNCTION_INFO", "\"$varName\"", targetExpression))
    
    return probes.joinToString("\n")
  }
  
  override fun shouldApplyTo(node: AbstractSparTreeNode): Boolean {
    // Apply to variable declarations, assignments, and expressions
    val nodeText = getNodeText(node)
    
    // Only apply if the node contains the target expression and is meaningful
    return nodeText.contains(targetExpression) && 
           (nodeText.contains("=") || nodeText.contains("let") || nodeText.contains("const") || nodeText.contains("var")) &&
           nodeText.length > 5 // Skip very short expressions
  }
  
  private fun getNodeText(node: AbstractSparTreeNode): String {
    return when (node) {
      is LexerRuleSparTreeNode -> node.token.text
      is ParserRuleSparTreeNode -> node.tokenListCostlyComputed.joinToString("")
      else -> ""
    }
  }
  
  override fun getPriority(): Int = 10
  
  /**
   * Get the target expression for this probe.
   */
  fun getTargetExpression(): String = targetExpression
  
  companion object {
    /**
     * Create a type probe for a variable declaration.
     */
    fun forVariableDeclaration(variableName: String, sourceLocation: SourceLocation? = null): TypeProbe {
      return TypeProbe(variableName, variableName, sourceLocation)
    }
    
    /**
     * Create a type probe for an expression.
     */
    fun forExpression(expression: String, sourceLocation: SourceLocation? = null): TypeProbe {
      return TypeProbe(expression, null, sourceLocation)
    }
  }
} 