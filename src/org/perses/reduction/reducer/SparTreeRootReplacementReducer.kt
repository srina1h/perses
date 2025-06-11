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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode

class SparTreeRootReplacementReducer(
  reducerContext: ReducerContext,
  private val newRootNode: AbstractSparTreeNode,
) : AbstractTokenReducer(META, reducerContext) {

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    val edit = tree.createRootReplacementEdit(
      newRoot = newRootNode,
      actionsDescription = "The current best file is not the minimal one. " +
        "Replace the best file " +
        "with the minimal program we have generated during the reduction process.",
    )
    tree.applyEdit(edit)
  }

  companion object {

    const val NAME = "spartree_root_replacement_reducer"

    @JvmField
    val META = object : ReducerAnnotation(
      shortName = NAME,
      description = "Replace the spartree being reduced with the given spartree",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        error("Cannot call $NAME with its annotation.")
      }
    }
  }
}
