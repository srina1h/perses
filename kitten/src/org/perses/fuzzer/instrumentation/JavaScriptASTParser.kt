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
import org.perses.grammar.javascript.JavaScriptParserFacade
import org.perses.program.LanguageKind
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.program.TokenizedProgramFactory
import org.perses.antlr.ParseTreeUtil
import java.io.File

/**
 * JavaScript AST parser that integrates with the existing Perses infrastructure
 * to parse JavaScript code for instrumentation.
 */
class JavaScriptASTParser {
  
  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
  
  private val parserFacade = JavaScriptParserFacade()
  
  /**
   * Parse JavaScript source code into a SparTree for instrumentation.
   */
  fun parse(sourceCode: String): SparTree {
    try {
      val parseTreeWithParser = parserFacade.parseString(sourceCode)
      val tokens = ParseTreeUtil.getTokens(parseTreeWithParser.tree)
      val tokenizedProgramFactory = TokenizedProgramFactory.createFactory(
        tokens,
        parserFacade.language,
      )
      val sparTreeNodeFactory = SparTreeNodeFactory(
        parserFacade.metaTokenInfoDb,
        tokenizedProgramFactory,
        parserFacade.ruleHierarchy,
      )
      val sparTree = SparTreeBuilder.createSparTree(sparTreeNodeFactory, parseTreeWithParser)
      
      logger.atFine().log("Successfully parsed JavaScript code into AST with %d nodes", 
                         sparTree.programSnapshot.tokenCount)
      
      return sparTree
    } catch (e: Exception) {
      logger.atWarning().withCause(e).log("Failed to parse JavaScript code")
      throw JavaScriptParseException("Failed to parse JavaScript code", e)
    }
  }
  
  /**
   * Parse JavaScript file into a SparTree for instrumentation.
   */
  fun parseFile(file: File): SparTree {
    val sourceCode = file.readText(Charsets.UTF_8)
    return parse(sourceCode)
  }
  
  /**
   * Check if the given source code can be parsed successfully.
   */
  fun canParse(sourceCode: String): Boolean {
    return try {
      parse(sourceCode)
      true
    } catch (e: Exception) {
      false
    }
  }
  
  /**
   * Get the root node of the parsed AST.
   */
  fun getRootNode(sourceCode: String): AbstractSparTreeNode {
    val sparTree = parse(sourceCode)
    return sparTree.realRoot
  }
  
  /**
   * Custom exception for JavaScript parsing errors.
   */
  class JavaScriptParseException(message: String, cause: Throwable? = null) : 
    RuntimeException(message, cause)
} 