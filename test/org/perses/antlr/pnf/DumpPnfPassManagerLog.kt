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
package org.perses.antlr.pnf

import com.beust.jcommander.Parameter
import org.perses.antlr.GrammarTestingUtility.loadGrammarFromString
import org.perses.grammar.AbstractParserFacade.Companion.readAntlrGrammarContent
import org.perses.grammar.c.CParserFacade
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import java.io.Closeable
import java.io.PrintStream
import java.nio.charset.StandardCharsets

class DumpPnfPassManagerLog(cmd: Options) : AbstractMain<DumpPnfPassManagerLog.Options>(
  cmd,
) {

  override fun internalRun() {
    val output = cmd.file!!
    val antlrGrammarContent = readAntlrGrammarContent("OrigC.g4", CParserFacade::class.java)
    val parserGrammar = loadGrammarFromString(antlrGrammarContent)
    val manager = PnfPassManager()
    PassListener(output).use { listener ->
      manager.process(
        GrammarPair(parserGrammar, lexerGrammar = null),
        "compilationUnit",
        listener,
      )
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor = CommandLineProcessor<Options>(
        cmdCreator = { Options() },
        programName = DumpPnfPassManagerLog::class.qualifiedName!!,
        args = args,
      )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      DumpPnfPassManagerLog(processor.cmd).run()
    }
  }

  class Options : AbstractCommandOptions() {
    @Parameter(description = "Output file")
    var file: String? = null

    override fun validateExtra() {
      require(file != null)
    }
  }

  private class PassListener(file: String) : PnfPassManager.Listener(), Closeable {

    private val stream = PrintStream(file, StandardCharsets.UTF_8.name())

    override fun close() {
      stream.close()
    }

    override fun start(grammar: GrammarPair, startRuleName: String) {
      stream.println(grammar.parserGrammar!!.sourceCode.trim { it <= ' ' })
    }

    override fun afterPass(grammar: GrammarPair, passClass: Class<*>, iteration: Int) {
      print(passClass, iteration)
      stream.println(grammar.parserGrammar!!.sourceCode.trim { it <= ' ' })
    }

    private fun print(passClass: Class<*>, iteration: Int) {
      stream.printf("Iteration %d, pass=%s", iteration, passClass)
    }
  }
}
