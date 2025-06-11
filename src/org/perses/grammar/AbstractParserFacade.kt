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

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import com.google.common.io.ByteStreams
import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.DefaultErrorStrategy
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.TokenStream
import org.antlr.v4.runtime.atn.LexerATNSimulator
import org.antlr.v4.runtime.atn.ParserATNSimulator
import org.antlr.v4.runtime.atn.PredictionContextCache
import org.antlr.v4.runtime.atn.PredictionMode
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.antlr.GrammarHierarchy.Companion.createFromAntlrGrammar
import org.perses.antlr.MetaTokenInfoDB
import org.perses.antlr.ParseTreeWithParser
import org.perses.antlr.ast.PersesAstBuilder.Companion.loadGrammarFromString
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.antlr.toTokenType
import org.perses.program.LanguageKind
import org.perses.util.Util
import org.perses.util.ktFine
import org.perses.util.transformToImmutableList
import java.io.IOException
import java.io.Reader
import java.io.StringReader
import java.io.UncheckedIOException
import java.lang.reflect.Constructor
import java.lang.reflect.InvocationTargetException
import java.lang.reflect.Method
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.absolute
import kotlin.io.path.readText

/** The base class for the parser facade  */
abstract class AbstractParserFacade protected constructor(
  val language: LanguageKind,
  val antlrGrammar: AbstractAntlrGrammar,
  identifierTokenTypes: ImmutableIntArray,
  val lexerClass: Class<out Lexer>,
  val parserClass: Class<out Parser>,
) {

  val ruleHierarchy = createFromAntlrGrammar(antlrGrammar)

  val identifierTokenTypes =
    identifierTokenTypes.toArray().asSequence().transformToImmutableList { it.toTokenType() }

  val metaTokenInfoDb: MetaTokenInfoDB
    get() = lexerAtnWrapper.metaTokenInfoDB

  val lexerAtnWrapper: LexerAtnWrapper<out Lexer> by lazy {
    LexerAtnWrapper(lexerClass)
  }

  init {
    require(identifierTokenTypes.toArray().distinct().size == identifierTokenTypes.length()) {
      "The identifier token types have duplicate elements: $identifierTokenTypes"
    }
  }

  fun parseFile(file: Path): ParseTreeWithParser {
    Files.newBufferedReader(file, StandardCharsets.UTF_8).use {
      return parseReader(fileName = file.toString(), reader = it, startRuleName = null)
    }
  }

  fun tokenizeFile(
    file: Path,
  ): ImmutableList<Token> {
    return tokenizeString(content = file.readText(), fileName = file.absolute().toString())
  }

  fun transformLiteralIntoSingleToken(literal: String): Token {
    val lexer = createLexerWithoutCache(CharStreams.fromString(literal))
    val result = lexer.nextToken()
    val next = lexer.nextToken()
    check(next.type == Token.EOF) {
      """|literal = $literal
         |result = ${result.text}, ${result.type}, $result
         |next = ${next.text}, ${next.type}, $next
      """.trimMargin()
    }
    return result
  }

  fun parseString(
    string: String,
    filename: String = DEFAULT_FILE_NAME,
    startRuleName: String? = null,
  ): ParseTreeWithParser {
    val reader = StringReader(string)
    return parseReader(filename, reader, startRuleName)
  }

  fun isSourceCodeParsable(sourceCode: String): Boolean {
    return try {
      parseString(sourceCode)
      true
    } catch (e: Exception) {
      logger.ktFine {
        """
          The input source is not parsable.
          
          $e
        """.trimIndent()
      }
      false
    }
  }

  fun tokenizeString(content: String, fileName: String = DEFAULT_FILE_NAME): ImmutableList<Token> {
    val lexer: Lexer = createLexerWithoutCache(CharStreams.fromString(content, fileName))
    val builder = ImmutableList.builder<Token>()
    var token: Token = lexer.nextToken()
    while (token.type != Token.EOF) {
      if (token.channel == Token.DEFAULT_CHANNEL) {
        builder.add(token)
      }
      token = lexer.nextToken()
    }
    return builder.build().also { tokens ->
      Util.lazyAssert(test = {
        if (tokens.isEmpty()) {
          return@lazyAssert true
        }
        val distinctChannels = tokens.map { it.channel }.distinct()
        distinctChannels.size == 1 && distinctChannels.single() == Token.DEFAULT_CHANNEL
      }) {
        tokens.joinToString(separator = "\n")
      }
    }
  }
  private val lexerConstructor: Constructor<out Lexer> =
    lexerClass.getDeclaredConstructor(CharStream::class.java)
  private val parserConstructor: Constructor<out Parser> =
    parserClass.getDeclaredConstructor(TokenStream::class.java)
  private val startRuleParsingMethod: Method =
    parserClass.getDeclaredMethod(antlrGrammar.startRuleName)

  protected fun startParsingWithSpecificRule(
    parser: Parser,
    parserRuleName: String,
  ): ParseTree {
    val method = parser::class.java.getDeclaredMethod(parserRuleName)
    return parseWithMethod(parser, method)
  }

  private fun parseWithMethod(parser: Parser, method: Method): ParseTree {
    try {
      return method.invoke(parser) as ParseTree
    } catch (e: InvocationTargetException) {
      val targetException = e.targetException
      // Need to throw the target exception.
      if (targetException is AntlrFailureException) {
        throw AntlrFailureException(
          cause = targetException,
          file = targetException.file,
          details = targetException.details + """\nThis is a rethrown exception to track the current stack trace.
              |Method = $method
          """.trimMargin(),
        )
      }
      throw RuntimeException(e.targetException)
    }
  }

  private fun parseReader(
    fileName: String,
    reader: Reader,
    startRuleName: String?,
  ): ParseTreeWithParser {
    val parsingMethod = if (startRuleName == null) {
      startRuleParsingMethod
    } else {
      parserClass.getDeclaredMethod(startRuleName)
    }
    return Companion.parseReader(
      fileName,
      reader,
      lexerCreator = ::createLexerWithoutCache,
      parserCreator = ::createParserWithoutCache,
      parseFunction = { parser ->
        parseWithMethod(parser, parsingMethod)
      },
    )
  }

  @Suppress("UNCHECKED_CAST")
  private fun createLexer(inputStream: CharStream): Lexer {
    return lexerConstructor.newInstance(inputStream)
  }

  private fun createLexerWithoutCache(inputStream: CharStream): Lexer {
    val lexer = createLexer(inputStream)
    disableGlobalCachingIfInstructed(lexer)
    return lexer
  }

  @Suppress("UNCHECKED_CAST")
  private fun createParser(tokens: TokenStream): Parser {
    return parserConstructor.newInstance(tokens) as Parser
  }

  private fun createParserWithoutCache(tokens: TokenStream): Parser {
    val parser = createParser(tokens)
    disableGlobalCachingIfInstructed(parser)
    return parser
  }

  companion object {
    @JvmStatic
    fun readAntlrGrammarContent(
      antlrGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): String {
      Util.openResourceAsStream(antlrGrammarFileName, classUnderSamePkg).use { stream ->
        return String(ByteStreams.toByteArray(stream), StandardCharsets.UTF_8)
      }
    }

    @JvmStatic
    protected fun createSeparateAntlrGrammar(
      startRuleName: String,
      antlrParserGrammarFileName: String,
      antlrLexerGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): AbstractAntlrGrammar.SeparateAntlrGrammar {
      return try {
        val persesGrammar = loadGrammarFromString(
          readAntlrGrammarContent(antlrParserGrammarFileName, classUnderSamePkg),
        )
        val lexerGrammar = loadGrammarFromString(
          readAntlrGrammarContent(antlrLexerGrammarFileName, classUnderSamePkg),
        )
        AbstractAntlrGrammar.SeparateAntlrGrammar(startRuleName, persesGrammar, lexerGrammar)
      } catch (e: IOException) {
        throw UncheckedIOException(e)
      }
    }

    @JvmStatic
    protected fun createCombinedAntlrGrammar(
      startRuleName: String,
      antlrGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): AbstractAntlrGrammar.CombinedAntlrGrammar {
      return try {
        val content = readAntlrGrammarContent(antlrGrammarFileName, classUnderSamePkg)
        val persesGrammar = loadGrammarFromString(content)
        AbstractAntlrGrammar.CombinedAntlrGrammar(startRuleName, persesGrammar)
      } catch (e: IOException) {
        throw UncheckedIOException(e)
      }
    }

    private val logger = FluentLogger.forEnclosingClass()

    const val DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY = true

    @JvmStatic
    inline fun<L : Lexer, P : Parser> parseReader(
      fileName: String,
      reader: Reader,
      lexerCreator: (CharStream) -> L,
      parserCreator: (CommonTokenStream) -> P,
      parseFunction: (P) -> ParseTree,
    ): ParseTreeWithParser {
      val listener = FailOnErrorAntlrErrorListener(fileName)
      val lexer = lexerCreator.invoke(CharStreams.fromReader(reader))
      lexer.removeErrorListeners()
      lexer.addErrorListener(listener)
      val tokenStream = CommonTokenStream(lexer)
      val parser = parserCreator.invoke(tokenStream)
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        parser.interpreter = ParserATNSimulator(
          parser,
          parser.atn,
          parser.interpreter.decisionToDFA,
          PredictionContextCache(),
        )
      }
      parser.removeErrorListeners()
      parser.errorHandler = DefaultErrorStrategy()
      parser.addErrorListener(listener)
      val tree = parseFunction.invoke(parser)
      lexer.interpreter.clearDFA()
      lexer.interpreter.reset()
      parser.interpreter.clearDFA()
      parser.interpreter.reset()
      // TODO(cnsun): need to mark whether the entire input is parsed.
      return ParseTreeWithParser(tree, parser, lexer)
    }

    @JvmStatic
    fun <LEXER : Lexer> disableGlobalCachingIfInstructed(lexer: LEXER): LEXER {
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        lexer.interpreter = LexerATNSimulator(
          lexer,
          lexer.atn,
          lexer.interpreter.decisionToDFA,
          PredictionContextCache(),
        )
      }
      return lexer
    }

    @JvmStatic
    fun <PARSER : Parser> disableGlobalCachingIfInstructed(parser: PARSER): PARSER {
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        // The following code is from.
        // https://github.com/antlr/antlr4/issues/499#issuecomment-38159752
        parser.interpreter = ParserATNSimulator(
          parser,
          parser.atn,
          parser.interpreter.decisionToDFA,
          PredictionContextCache(),
        )
        parser.interpreter.predictionMode = PredictionMode.LL
      }
      return parser
    }

    private val DEFAULT_FILE_NAME = "<in memory>"
  }
}
