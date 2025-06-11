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
package org.perses.spartree

class PlaceholderSparTreeNode internal constructor(
  nodeId: Int,
  private val source: String,
  private val predicateForCompatibility: CompatibilityPredicate,
) : AbstractSparTreeNode(nodeId, antlrRule = null) {

  override var beginToken: LexerRuleSparTreeNode? = null
  override var endToken: LexerRuleSparTreeNode? = null

  override val labelPrefix: String
    get() = "Placeholder: $source"

  override fun internalCopyCurrentNode(computedNewNodeId: Int): AbstractSparTreeNode {
    return PlaceholderSparTreeNode(computedNewNodeId, source, predicateForCompatibility)
  }

  @Deprecated(
    "Should not be called on a placeholder node.",
    ReplaceWith("""error("Cannot call this method on a token node.")"""),
  )
  override fun addChildAtIndex(
    index: Int,
    child: AbstractSparTreeNode,
    payload: AbstractNodePayload,
  ) {
    error("Cannot call this method on a token node.")
  }

  override fun buildTokenIntervalInfoForCurrentNode() {
    // do nothing
  }

  @Deprecated(
    "Should not be called on a placeholder node.",
    ReplaceWith("""error("Cannot call this method on a token node.")"""),
  )
  override fun onChildRemoved(index: Int, child: AbstractSparTreeNode) {
    error("Cannot call this method on a token node.")
  }

  fun canBeReplacedBy(node: AbstractSparTreeNode): Boolean {
    check(node is LexerRuleSparTreeNode || node is ParserRuleSparTreeNode) {
      "PlaceholderNode should not be used for replacing another PlaceholderNode."
    }
    return predicateForCompatibility.isNodeCompatible(node)
  }

  fun interface CompatibilityPredicate {
    /**
     * Test whether the given node is compatible.
     */
    fun isNodeCompatible(node: AbstractSparTreeNode): Boolean
  }
}
