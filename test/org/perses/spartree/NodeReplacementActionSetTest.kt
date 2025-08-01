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

import com.google.common.truth.Truth.assertThat
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createSparTreeFromFile
import org.perses.spartree.NodeReplacementActionSet.Companion.createByReplacingSingleNode
import java.nio.file.Paths
import java.util.stream.Collectors

@RunWith(JUnit4::class)
class NodeReplacementActionSetTest {
  private var tree = createSparTreeFromFile(Paths.get("test_data/parentheses/t.c"))
  private var node5 = tree.getNodeByTreeScanForId(5)!!
  private var node10 = tree.getNodeByTreeScanForId(10)!!
  private var node46 = tree.getNodeByTreeScanForId(46)!!
  private var node72 = tree.getNodeByTreeScanForId(72)!!
  private lateinit var actionSet: NodeReplacementActionSet
  private lateinit var actionSet2: NodeReplacementActionSet

  @Before
  fun setup() {
    run {
      val builder = NodeReplacementActionSet.Builder("test 1")
      builder.replaceNode(node5, node10)
      builder.replaceNode(node46, node72)
      actionSet = builder.build()
      assertThat(actionSet.actionsDescription).isEqualTo("test 1")
    }
    run {
      val builder = NodeReplacementActionSet.Builder("test 2")
      builder.replaceNode(node5, node10)
      builder.replaceNode(node46, node72)
      actionSet2 = builder.build()
      assertThat(actionSet2.actionsDescription).isEqualTo("test 2")
    }
  }

  @Test
  fun testContainsNodeAsTarget() {
    assertThat(actionSet.containsNodeAsTarget(node5)).isTrue()
    assertThat(actionSet.containsNodeAsTarget(node46)).isTrue()
    assertThat(actionSet.containsNodeAsTarget(node10)).isFalse()
    assertThat(actionSet.containsNodeAsTarget(node72)).isFalse()
  }

  @Test
  fun testActionsAreSortedAndDistinct() {
    assertThat(
      actionSet.actions.stream()
        .map(NodeReplacementAction::targetNode)
        .collect(Collectors.toList()),
    )
      .containsExactly(node5, node46)
      .inOrder()
    assertThat(
      actionSet2.actions.stream()
        .map(NodeReplacementAction::targetNode)
        .collect(Collectors.toList()),
    )
      .containsExactly(node5, node46)
      .inOrder()
  }

  @Test
  fun testActionSetEqualsAndHashcode() {
    assertThat(actionSet.actions).hasSize(2)
    assertThat(actionSet.actions[0]).isEqualTo(actionSet2.actions[0])
    assertThat(actionSet.actions[1]).isEqualTo(actionSet2.actions[1])
    assertThat(actionSet.equals(actionSet2)).isTrue()
    assertThat(actionSet.hashCode()).isEqualTo(actionSet2.hashCode())
    val set = HashSet<NodeReplacementActionSet?>()
    set.add(actionSet)
    assertThat(set).containsExactly(actionSet2)
  }

  @Test
  fun testActionSetNotEqual() {
    val other = createByReplacingSingleNode(node72, node5, "test desc")
    assertThat(actionSet).isNotEqualTo(other)
    assertThat(actionSet.hashCode()).isNotEqualTo(other.hashCode())
    assertThat(other.actionsDescription).isEqualTo("test desc")
  }
}
