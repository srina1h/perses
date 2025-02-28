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
package org.perses.grammar.java

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.AntlrGrammarUtil
import org.perses.grammar.AbstractParserFacade

@RunWith(JUnit4::class)
class JavaParserFacadeTest {

  val pnfFacade: AbstractParserFacade = Java8ParserFacade()

  @Test
  fun testUsingThisAsMethodParameter() {
    val result = pnfFacade.parseString(
      """
      class Test {
        void test(String this) {}
      }
      """,
      filename = "Test.java",
    )
    assertThat(
      AntlrGrammarUtil.convertParseTreeToProgram(result.tree, LanguageJava)
        .tokens.joinToString(separator = " ") { it.text },
    ).contains("this")
  }

  @Test
  fun test() {
    val origFacade: AbstractParserFacade = OrigJava8ParserFacade()

    val origMethods = origFacade.parserClass.declaredMethods
      .map { it.name }
      .sorted()
    val pnfMethods = pnfFacade.parserClass.declaredMethods.toList()
      .map { it.name }
      .sorted()
    assertThat(origMethods).isNotEqualTo(pnfMethods)
  }
}
