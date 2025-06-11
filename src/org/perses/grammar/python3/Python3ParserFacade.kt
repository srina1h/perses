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
package org.perses.grammar.python3

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonTokenStream
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractDefaultParserFacade
import java.io.StringReader

class Python3ParserFacade : AbstractDefaultParserFacade<Python3Lexer, PnfPython3Parser>(
  LanguagePython3,
  createSeparateAntlrGrammar(
    startRuleName = "file_input",
    antlrParserGrammarFileName = "PnfPython3Parser.g4",
    antlrLexerGrammarFileName = "Python3Lexer.g4",
    Python3ParserFacade::class.java,
  ),
  Python3Lexer::class.java,
  PnfPython3Parser::class.java,
  ImmutableIntArray.of(Python3Lexer.NAME),
) {
  fun parseWithOrigParser(program: String?): ParseTreeWithParser {
    StringReader(program).use { reader ->
      return parseReader(
        "<dummy-file>",
        reader,
        { charStream: CharStream? -> Python3Lexer(charStream) },
        { commonTokenStream: CommonTokenStream? -> PnfPython3Parser(commonTokenStream) },
      ) { obj -> obj.file_input() }
    }
  }
}
