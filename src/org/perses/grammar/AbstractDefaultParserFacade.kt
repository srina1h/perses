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
package org.perses.grammar

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.program.LanguageKind

/**
 * This is a generic class, so that we can access the exact type of the lexer and parser.
 */
abstract class AbstractDefaultParserFacade<LEXER : Lexer, PARSER : Parser>
protected constructor(
  languageKind: LanguageKind,
  antlrGrammar: AbstractAntlrGrammar,
  lexerClass: Class<LEXER>,
  parserClass: Class<PARSER>,
  identifierTokenTypes: ImmutableIntArray,
) : AbstractParserFacade(
  languageKind,
  antlrGrammar,
  identifierTokenTypes,
  lexerClass,
  parserClass,
)
