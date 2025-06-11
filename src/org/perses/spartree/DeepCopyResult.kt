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

import com.google.common.collect.BiMap

class DeepCopyResult<ValueT, NodeT>(
  val result: ValueT,
  @PublishedApi
  internal val orig2copyMapping: BiMap<NodeT, NodeT>,
) {

  inline fun <NewValueT> transform(transformer: (ValueT) -> NewValueT) =
    DeepCopyResult(transformer(result), orig2copyMapping)

  fun getCopyNode(origNode: NodeT): NodeT? {
    return orig2copyMapping[origNode]
  }

  fun getOrigNode(copyNode: NodeT): NodeT? {
    return orig2copyMapping.inverse()[copyNode]
  }
}
