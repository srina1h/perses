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
package org.perses.fuzzer.instrumentation

import com.google.common.flogger.FluentLogger
import org.perses.fuzzer.instrumentation.probes.*
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import java.util.*

/**
 * Generates probes for JavaScript AST nodes based on configuration.
 */
class ProbeGenerator(
  private val config: InstrumentationConfig
) {
  
  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
  
  /**
   * Generate probes for the given AST.
   */
  fun generateProbes(sparTree: SparTree): List<Probe> {
    val probes = mutableListOf<Probe>()
    val enabledProbes = config.probeTypes.getEnabledProbes()
    
    if (enabledProbes.isEmpty()) {
      return probes
    }
    
    // Traverse the AST and generate probes
    traverseAndGenerateProbes(sparTree.realRoot, probes, enabledProbes)
    
    // Remove duplicates and sort by priority
    val uniqueProbes = removeDuplicateProbes(probes)
    val sortedProbes = uniqueProbes.sortedByDescending { it.getPriority() }
    val limitedProbes = sortedProbes.take(config.maxProbesPerProgram)
    
    logger.atFine().log("Generated %d unique probes (limited to %d)", uniqueProbes.size, limitedProbes.size)
    
    return limitedProbes
  }
  
  /**
   * Remove duplicate probes based on their content.
   */
  private fun removeDuplicateProbes(probes: List<Probe>): List<Probe> {
    val seen = mutableSetOf<String>()
    val uniqueProbes = mutableListOf<Probe>()
    
    for (probe in probes) {
      val key = when (probe) {
        is TypeProbe -> "type_${probe.getTargetExpression()}"
        is FloatProbe -> "float_${probe.getTargetExpression()}"
        is ShortCircuitProbe -> "short_${probe.getTargetExpression()}"
        else -> probe.getProbeId()
      }
      
      if (!seen.contains(key)) {
        seen.add(key)
        uniqueProbes.add(probe)
      }
    }
    
    return uniqueProbes
  }
  
  /**
   * Traverse the AST and generate probes for relevant nodes.
   */
  private fun traverseAndGenerateProbes(
    node: AbstractSparTreeNode,
    probes: MutableList<Probe>,
    enabledProbes: Set<InstrumentationConfig.ProbeType>
  ) {
    // Only generate probes for meaningful nodes (not every single token)
    if (shouldProbeNode(node)) {
      generateProbesForNode(node, probes, enabledProbes)
    }
    
    // Recursively traverse children
    for (i in 0 until node.childCount) {
      traverseAndGenerateProbes(node.getChild(i), probes, enabledProbes)
    }
  }
  
  /**
   * Determine if a node is worth probing.
   */
  private fun shouldProbeNode(node: AbstractSparTreeNode): Boolean {
    val nodeText = getNodeText(node).trim()
    
    // Skip empty or very short nodes
    if (nodeText.length < 3) return false
    
    // Skip nodes that are just whitespace or punctuation
    if (nodeText.matches(Regex("^[\\s\\p{Punct}]+$"))) return false
    
    // Skip nodes that are just single tokens (like semicolons, braces)
    if (nodeText.matches(Regex("^[;{}()\\[\\]]$"))) return false
    
    // Skip nodes that are too long (likely entire programs or large chunks)
    if (nodeText.length > 100) return false
    
    // Only probe specific, meaningful expressions
    return (nodeText.matches(Regex("^\\s*(let|const|var)\\s+\\w+\\s*=\\s*.+\\s*$")) || // Variable declarations
            nodeText.matches(Regex("^\\s*\\w+\\s*=\\s*.+\\s*$")) || // Simple assignments
            nodeText.matches(Regex("^\\s*\\d+\\.\\d+\\s*$")) || // Single float literals
            nodeText.matches(Regex("^\\s*\\d+\\.\\d+\\s*[+\\-*/]\\s*\\d+\\.\\d+\\s*$")) || // Float arithmetic
            nodeText.matches(Regex("^\\s*\\w+\\s*(&&|\\|\\||\\?\\?)\\s*\\w+\\s*$")) || // Simple logical expressions
            nodeText.matches(Regex("^\\s*\\{[^}]*\\}\\s*$"))) // Simple object literals
  }
  
  /**
   * Generate probes for a specific AST node.
   */
  private fun generateProbesForNode(
    node: AbstractSparTreeNode,
    probes: MutableList<Probe>,
    enabledProbes: Set<InstrumentationConfig.ProbeType>
  ) {
    val nodeText = getNodeText(node).trim()
    val sourceLocation = extractSourceLocation(node)
    
    // Type probing
    if (enabledProbes.contains(InstrumentationConfig.ProbeType.TYPE)) {
      generateTypeProbes(node, nodeText, sourceLocation, probes)
    }
    
    // Float probing
    if (enabledProbes.contains(InstrumentationConfig.ProbeType.FLOAT)) {
      generateFloatProbes(node, nodeText, sourceLocation, probes)
    }
    
    // Short circuit probing
    if (enabledProbes.contains(InstrumentationConfig.ProbeType.SHORT_CIRCUIT)) {
      generateShortCircuitProbes(node, nodeText, sourceLocation, probes)
    }
    
    // Structure probing
    if (enabledProbes.contains(InstrumentationConfig.ProbeType.STRUCTURE)) {
      generateStructureProbes(node, nodeText, sourceLocation, probes)
    }
    
    // Promise probing
    if (enabledProbes.contains(InstrumentationConfig.ProbeType.PROMISE)) {
      generatePromiseProbes(node, nodeText, sourceLocation, probes)
    }
  }
  
  /**
   * Generate type probes for the node.
   */
  @Suppress("UNUSED_PARAMETER")
  private fun generateTypeProbes(
    _node: AbstractSparTreeNode,
    nodeText: String,
    _sourceLocation: SourceLocation?,
    probes: MutableList<Probe>
  ) {
    // Look for variable declarations with meaningful initializers
    val varDeclPattern = Regex("(let|const|var)\\s+([a-zA-Z_$][a-zA-Z0-9_$]*)\\s*=\\s*(.+?)(?:;|$)")
    val match = varDeclPattern.find(nodeText)
    
    if (match != null) {
      val variableName = match.groupValues[2]
      val initializer = match.groupValues[3].trim()
      
      // Only probe if the initializer is meaningful and not just a number
      if (initializer.length > 2 && !initializer.matches(Regex("^\\d+(\\.\\d+)?$"))) {
        probes.add(TypeProbe.forVariableDeclaration(variableName, _sourceLocation))
      }
    }
    
    // Look for simple object literals
    if (nodeText.matches(Regex("^\\s*\\{[^}]*\\}\\s*$"))) {
      val objectContent = nodeText.substringAfter("{").substringBeforeLast("}")
      if (objectContent.trim().isNotEmpty()) {
        probes.add(TypeProbe.forExpression(nodeText.trim(), _sourceLocation))
      }
    }
  }
  
  /**
   * Generate float probes for the node.
   */
  @Suppress("UNUSED_PARAMETER")
  private fun generateFloatProbes(
    _node: AbstractSparTreeNode,
    nodeText: String,
    _sourceLocation: SourceLocation?,
    probes: MutableList<Probe>
  ) {
    // Only probe if this is a simple float literal or simple arithmetic
    if (nodeText.matches(Regex("^\\s*\\d+\\.\\d+\\s*$"))) {
      // Single float literal
      probes.add(FloatProbe.forFloatLiteral(nodeText.trim(), _sourceLocation))
    } else if (nodeText.matches(Regex("^\\s*\\d+\\.\\d+\\s*[+\\-*/]\\s*\\d+\\.\\d+\\s*$"))) {
      // Simple float arithmetic
      probes.add(FloatProbe.forArithmeticExpression(nodeText.trim(), null, _sourceLocation))
    }
  }
  
  /**
   * Generate short circuit probes for the node.
   */
  @Suppress("UNUSED_PARAMETER")
  private fun generateShortCircuitProbes(
    _node: AbstractSparTreeNode,
    nodeText: String,
    _sourceLocation: SourceLocation?,
    probes: MutableList<Probe>
  ) {
    // Look for simple logical expressions with variables
    if (nodeText.matches(Regex("^\\s*\\w+\\s*(&&|\\|\\||\\?\\?)\\s*\\w+\\s*$"))) {
      val shortCircuitProbes = ShortCircuitProbe.fromExpression(nodeText.trim(), null, _sourceLocation)
      probes.addAll(shortCircuitProbes)
    }
  }
  
  /**
   * Generate structure probes for the node.
   */
  @Suppress("UNUSED_PARAMETER")
  private fun generateStructureProbes(
    _node: AbstractSparTreeNode,
    nodeText: String,
    _sourceLocation: SourceLocation?,
    _probes: MutableList<Probe>
  ) {
    // Look for object literals and array literals
    if ((nodeText.contains("{") && nodeText.contains("}")) ||
        (nodeText.contains("[") && nodeText.contains("]"))) {
      
      // This will be handled by the type probe for now
      // In the future, we can add more specific structure probes
    }
  }
  
  /**
   * Generate promise probes for the node.
   */
  @Suppress("UNUSED_PARAMETER")
  private fun generatePromiseProbes(
    _node: AbstractSparTreeNode,
    nodeText: String,
    _sourceLocation: SourceLocation?,
    _probes: MutableList<Probe>
  ) {
    // Look for Promise-related code
    if (nodeText.contains("Promise") || nodeText.contains("async") || nodeText.contains("await")) {
      // For now, we'll use type probes for Promise objects
      // In the future, we can add specific Promise probes
    }
  }
  
  /**
   * Extract source location information from the node.
   */
  @Suppress("UNUSED_PARAMETER")
  private fun extractSourceLocation(_node: AbstractSparTreeNode): SourceLocation? {
    if (!config.includeSourceLocation) {
      return null
    }
    
    // Try to extract line and column information from the node
    // This is a simplified implementation - in practice, you'd need to
    // access the actual token information from the AST
    return try {
      // For now, return a placeholder location
      SourceLocation(1, 1, "instrumented.js")
    } catch (e: Exception) {
      null
    }
  }
  
  /**
   * Get the text content of a node.
   */
  private fun getNodeText(node: AbstractSparTreeNode): String {
    return when (node) {
      is LexerRuleSparTreeNode -> node.token.text
      is ParserRuleSparTreeNode -> node.tokenListCostlyComputed.joinToString("")
      else -> ""
    }
  }
} 