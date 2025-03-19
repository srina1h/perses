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
package org.perses.reduction.reducer.lpr

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class LLMOutputUtilTest {

  @Test
  fun testExtractListBetweenStarAndNewline1() {
    val input =
      """These are all functions. 
        |* fn1 
        |* fn2 
        |* fn3
      """.trimMargin()
    val list = LLMOutputUtil.extractListBetweenStarAndNewline(input)
    assertThat(list).containsExactly("fn1", "fn2", "fn3").inOrder()
  }

  @Test
  fun testExtractListBetweenStarAndNewline3() {
    val input =
      """
      |These are all functions.
      """.trimMargin()
    val list = LLMOutputUtil.extractListBetweenStarAndNewline(input)
    assertThat(list).hasSize(0)
  }

  @Test
  fun testExtractListBetweenStarAndNewline4() {
    val input =
      """These are all functions.
        |* fn1
        |* fn2
        |* fn3
        |
        |
      """.trimMargin()
    val list = LLMOutputUtil.extractListBetweenStarAndNewline(input)
    assertThat(list).containsExactly("fn1", "fn2", "fn3").inOrder()
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring1() {
    val input =
      """|
      |Here is the program.
      |```
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LLMOutputUtil.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program.trim()).isEqualTo("int main() { return 0; }")
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring2() {
    val input =
      """|
      |Here is the program snippet.
      |```
      |  return 0;
      |```
      |And here is the whole program.
      |```
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LLMOutputUtil.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program).isEqualTo("int main() { return 0; }")
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring3() {
    val input =
      """|
      |Here is the whole program.
      |```c
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LLMOutputUtil.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program).isEqualTo("int main() { return 0; }")
  }

  @Test
  fun testExtractLastFencedCodeBlockFromDocstring4() {
    val input =
      """|
      |Here is the whole program.
      |```python
      |  int main() { return 0; }
      |```
      """.trimMargin()
    val program = LLMOutputUtil.extractLastFencedCodeBlockFromDocstring(input)!!.trim()
    assertThat(program).isEqualTo("int main() { return 0; }")
  }
}
