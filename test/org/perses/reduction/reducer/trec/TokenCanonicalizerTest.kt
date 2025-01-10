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
package org.perses.reduction.reducer.trec

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class TokenCanonicalizerTest {

  @Test
  fun testConversionBetweenIndexAndId0() {
    val index = 0
    val id = TokenCanonicalizer.convertIndexToId(index)
    assertThat(id).isEqualTo("a")
  }

  @Test
  fun testConversionBetweenIndexAndId1() {
    val index = 10
    val id = TokenCanonicalizer.convertIndexToId(index)
    assertThat(id).isEqualTo("k")
  }

  @Test
  fun testConversionBetweenIndexAndId2() {
    val index = 100
    val id = TokenCanonicalizer.convertIndexToId(index)
    assertThat(id).isEqualTo("dw")
  }
}
