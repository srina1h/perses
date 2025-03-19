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
package org.perses.util.markdown

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.markdown.MarkdownToHTMLConverter.computeStringRepresentation
import org.perses.util.markdown.MarkdownToHTMLConverter.listItemSequence
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.createTempFile
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class MarkdownToHTMLConverterTest {
  private val tempDir = Files.createTempDirectory(this::class.qualifiedName)
  private val resultFile = tempDir.resolve("result.html")
  private val markdownFile = tempDir.resolve("test.md")
  private val htmlResultFile = createTempFile("result", ".html")

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testFindAllBulletList() {
    val document = MarkdownToHTMLConverter.parseMarkdownDocument(
      """
        |+ a b c
        |+ b c d 
        |+ c d e
        |   + e f g 
        |   + f i j
      """.trimMargin(),
    )
    val bulletList = MarkdownToHTMLConverter.findAllBulletLists(document)
    assertThat(bulletList).hasSize(2)
    bulletList.first().listItemSequence().toList().let { list ->
      assertThat(list).hasSize(3)
      assertThat(list.map { it.computeStringRepresentation() }).containsExactly(
        "a b c",
        "b c d",
        "c d e",
      )
    }
    bulletList.last().listItemSequence().toList().let { list ->
      assertThat(list).hasSize(2)
      assertThat(list.map { it.computeStringRepresentation() }).containsExactly(
        "e f g",
        "f i j",
      )
    }
  }

  @Test
  fun testFindAllCodeBlocks() {
    val document = MarkdownToHTMLConverter.parseMarkdownDocument(
      """
        | code below
        | ```bash
        | aaa
        | ```
      """.trimMargin(),
    )
    val codeBlocks = MarkdownToHTMLConverter.findAllFencedCodeBlocks(document)
    assertThat(codeBlocks).hasSize(1)
    assertThat(codeBlocks.single().literal).isEqualTo("aaa\n")
  }

  @Test
  fun testConvertMarkdownToHTML() {
    markdownFile.writeText("# Hello World\nThis is a test markdown file.")
    MarkdownToHTMLConverter.convertMarkdownToHTML(markdownFile, htmlResultFile)
    val htmlContent = htmlResultFile.readText()
    assertThat(htmlContent).contains("<h1>Hello World</h1>")
    assertThat(htmlContent).contains("<p>This is a test markdown file.</p>")
  }

  @Test
  fun testFileNotFound() {
    val fileName = "this_file_does_not_exist"
    val wrongPath = tempDir.resolve(fileName)
    val exception = assertThrows(Throwable::class.java) {
      MarkdownToHTMLConverter.convertMarkdownToHTML(wrongPath, htmlResultFile)
    }
    assertThat(exception.message).contains(fileName)
  }
}
