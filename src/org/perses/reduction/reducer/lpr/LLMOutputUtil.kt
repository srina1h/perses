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

import com.google.common.collect.ImmutableList
import org.perses.util.markdown.MarkdownToHTMLConverter
import org.perses.util.markdown.MarkdownToHTMLConverter.computeStringRepresentation
import org.perses.util.markdown.MarkdownToHTMLConverter.listItemSequence

object LLMOutputUtil {

  /**
   * Extracts a list of lines from the end of the given text that start with an asterisk (`*`).
   *
   * This is useful when a LLM is asked to identify a list of items,
   * each prefixed by `*`.
   *
   * For example, in the string:
   *
   * The program contains the following functions:
   * * fn1
   * * fn2
   * * fn3
   *
   * This function will return [fn1, fn2, fn3].
   *
   * @param text the input string potentially containing lines that start with `*`.
   * @return an immutable list of all extracted items.
   */
  fun extractListBetweenStarAndNewline(text: String): ImmutableList<String> {
    val document = MarkdownToHTMLConverter.parseMarkdownDocument(text)
    val lists = MarkdownToHTMLConverter.findAllBulletLists(document)
    if (lists.isEmpty()) return ImmutableList.of()
    val result = ImmutableList.builder<String>()
    val lastBulletList = lists.last()
    lastBulletList.listItemSequence().forEach {
      result.add(it.computeStringRepresentation())
    }
    return result.build()
  }

  /**
   * Extracts the final code block from the given text.
   *
   * Code blocks are expected to be enclosed in triple backticks (```), optionally followed by a
   * language identifier (e.g., ` ```c `). For example, in the string:
   *
   * The whole program is:
   * ```c
   * int main() {}
   * ```
   *
   * This function will return `int main() {}`.
   *
   * This is useful when an LLM's output contain multiple code snippets (e.g., intermediate
   * reasoning steps). The final snippet is typically the complete, final program.
   *
   * @param text the input string that may contain code blocks.
   * @return the extracted final code block content, or an empty string if none was found.
   */
  fun extractLastFencedCodeBlockFromDocstring(text: String): String? {
    /* Matches ``` optionally followed by letters (the language name),
    then any text (including newlines), and ending with another set of ```.
     */
    val document = MarkdownToHTMLConverter.parseMarkdownDocument(text)
    val fencedCodeBlocks = MarkdownToHTMLConverter.findAllFencedCodeBlocks(document)
    if (fencedCodeBlocks.isEmpty()) return null
    return fencedCodeBlocks.last().literal
  }
}
