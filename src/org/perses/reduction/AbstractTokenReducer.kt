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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.listminimizer.AbstractListInputMinimizer
import org.perses.listminimizer.AbstractListInputMinimizer.OnBestUpdateHandler
import org.perses.listminimizer.AbstractPropertyTestResultWithPayload
import org.perses.listminimizer.Configuration
import org.perses.listminimizer.IPropertyTester
import org.perses.listminimizer.PropertyTestResultWithPayload
import org.perses.listminimizer.SkipPropertyTestResult
import org.perses.program.LanguageKind
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.EmptyResult
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.ProceedResult
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.reduction.cache.AbstractCacheRetrievalResult
import org.perses.reduction.cache.AbstractProgramEncoding
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeEditListener
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeDeletionTreeEdit
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.AbstractFileContent
import org.perses.util.FileNameContentPair
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import java.util.LinkedList

/** The base class for reducer. Both hdd and perses algorithms extend this class.
 *
 * Note that a token reducer does not mean it works on token sequences. Instead,
 * it means the reducer works on token granularity.
 */
abstract class AbstractTokenReducer protected constructor(
  reducerAnnotation: ReducerAnnotation,
  protected val reducerContext: ReducerContext,
) : AbstractReducer<TokenizedProgram, LanguageKind, TokenReductionIOManager>(
  reducerAnnotation,
  reducerContext.ioManager,
  reducerContext.executorService,
) {

  private var used = false

  val reducerAnnotation: ReducerAnnotation
    get() = nameAndDesc as ReducerAnnotation

  fun reduce(state: FixpointReductionState) {
    check(!used) { "A reducer is not designed to be reused." }
    used = true
    val sparTree = state.sparTree
    lazyAssert {
      SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(
        sparTree.getTreeRegardlessOfParsability().root,
      )
    }
    state.fixpointIterationStartEvent

    val loggingListener = object : AbstractSparTreeEditListener() {
      override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
        reducerContext.listenerManager.onBestProgramUpdated(
          state.fixpointIterationStartEvent.createBestProgramUpdatedEvent(
            currentTimeMillis = System.currentTimeMillis(),
            programSizeBefore = event.programSizeBefore,
            programSizeAfter = event.program.tokenCount(),
          ),
        )
      }
    }
    try {
      sparTree.getTreeRegardlessOfParsability().registerSparTreeEditListener(loggingListener)
      internalReduce(state)
    } finally {
      sparTree.getTreeRegardlessOfParsability().removeSparTreeEditListener(loggingListener)
    }
  }

  protected abstract fun internalReduce(fixpointReductionState: FixpointReductionState)

  protected fun testAllTreeEditsAndReturnTheBest(
    editList: List<AbstractSparTreeEdit<*>>,
  ): TreeEditWithItsResult? {
    if (editList.isEmpty()) {
      return null
    }
    val futureList = asyncApplyEditsInOrderOfProgramSizeFromLeast(editList)
    val best = analyzeResultsAndGetBest(futureList)
    lazyAssert {
      best == null ||
        reducerContext.configuration.parserFacade.isSourceCodeParsable(
          PrinterRegistry.getPrinter(
            ioManager.getDefaultProgramFormat(),
            reducerContext.configuration.parserFacade.lexerAtnWrapper,
          ).print(best.payload!!.edit.program).sourceCode,
        )
    }
    return best?.let { TreeEditWithItsResult(it.payload!!.edit, it.getWithTimeoutWarnings()) }
  }

  private fun isFutureListSortedFromLeastProgramSizeToGreatest(
    futureList: List<TestScriptExecResult<EditTestPayload>>,
  ): Boolean {
    val size = futureList.size
    if (size < 2) {
      return true
    }
    var prevTokenCount = Integer.MIN_VALUE
    futureList.forEach {
      it.payload?.let { current ->
        val curTokenCount = current.program.program.tokenCount()
        if (prevTokenCount > curTokenCount) {
          return false
        }
        prevTokenCount = curTokenCount
      }
    }
    return true
  }

  protected fun analyzeResultsAndGetBest(
    futureList: List<TestScriptExecResult<EditTestPayload>>,
  ): TestScriptExecResult<EditTestPayload>? {
    lazyAssert({ isFutureListSortedFromLeastProgramSizeToGreatest(futureList) }) { futureList }
    var best: TestScriptExecResult<EditTestPayload>? = null
    val iterator = futureList.iterator()
    while (iterator.hasNext()) {
      lazyAssert { best == null }
      val future = iterator.next()
      val testResult = future.getWithTimeoutWarnings()
      future.payload?.let { payload ->
        cacheTestResultIfNotInteresting(payload.program, testResult)
        reducerContext.listenerManager.onTestScriptExecution(
          testResult,
          payload.program.program,
          payload.edit,
          outputCreator = ::computeFileContentListForProgram,
        )
      }
      if (testResult.isInteresting) {
        best = future
        break
      }
    }
    while (iterator.hasNext()) {
      val future = iterator.next()
      lazyAssert { best != null }
      // The best is already found, then it is safe to cancel all the remaining testing tasks, as
      // none of these tasks will beat the current best one. Moreover, the tasks are not useful
      // for future cache testing, as all future programs will be smaller than the programs
      // represented by these tasks.
      val start = System.currentTimeMillis()
      future.cancelWithInterruption()
      val duration = (System.currentTimeMillis() - start).toInt()
      future.payload?.let { payload ->
        reducerContext.listenerManager.onTestScriptExecutionCancelled(
          payload.program.program,
          payload.edit,
          duration,
          outputCreator = ::computeFileContentListForProgram,
        )
      }
    }
    return best
  }

  private fun cacheTestResultIfNotInteresting(
    program: AbstractCacheRetrievalResult.CacheMiss,
    result: PropertyTestResult,
  ) {
    if (result.isNotInteresting) {
      reducerContext.queryCache.cacheProgramAndResult(program, result)
    }
  }

  private fun asyncApplyEditsInOrderOfProgramSizeFromLeast(
    editList: List<AbstractSparTreeEdit<*>>,
  ): List<TestScriptExecResult<EditTestPayload>> {
    val visitedCacheKeys = Util.createConcurrentSet<AbstractProgramEncoding<*>>()
    return editList
      .asSequence()
      .sorted()
      .map { edit ->
        executorService.testProgramAsync(
          ALWAYS_TRUE_PRECHECK,
          IDENTITY_POST_CHECK,
        ) {
          val program = edit.program
          val cachedResult = reducerContext.queryCache.getCachedResult(program)
          if (cachedResult.hasEncoding() &&
            !visitedCacheKeys.add(cachedResult.getEncodingOrFail())
          ) {
            // This program has been added before.
            EmptyResult()
          } else if (cachedResult.isHit()) {
            val testResult = cachedResult.asCacheHit().testResult
            lazyAssert({ !testResult.isInteresting }) { "It should be failure all the time." }
            reducerContext.listenerManager.onTestResultCacheHit(
              testResult,
              program,
              edit,
              outputCreator = ::computeFileContentListForProgram,
            )
            // TODO(cnsun): need to use StopResult here.
            EmptyResult()
          } else {
            // TODO(cnsun): add the TestScriptHistory here.
            val outputManager = ioManager.createOutputManager(program)
            ProceedResult(outputManager, EditTestPayload(edit, cachedResult.asCacheMiss()))
          }
        }
      }.toList()
  }

  protected fun computeFileContentListForProgram(
    program: TokenizedProgram,
  ): ImmutableList<FileNameContentPair<String>> {
    val contentList = ioManager.outputManagerFactory.createManagerFor(program)
      .fileContentList
    val builder = ImmutableList.builderWithExpectedSize<FileNameContentPair<String>>(
      contentList.size + 1,
    )
    contentList.forEach {
      builder.add(
        FileNameContentPair(
          fileName = it.fileName.baseName,
          content = it.content,
        ),
      )
    }
    builder.add(
      FileNameContentPair(
        fileName = "<formatted tokenized program in its original format>",
        content = AbstractFileContent.TextFileContent(
          text = reducerContext.configuration.originalFormatPrinter.print(program).sourceCode,
        ),
      ),
    )
    return builder.build()
  }

  protected fun canBeEpsilon(nodeForTest: AbstractSparTreeNode): Boolean {
    require(nodeForTest.isParserRuleNode() || nodeForTest.isTokenNode())
    var node: AbstractSparTreeNode? = nodeForTest
    while (node != null) {
      check(node.antlrRule != null) { node!! }
      if (node.antlrRule!!.canRuleBeEpsilon()) {
        // If the rule of the current node can be epsilon.
        return true
      }
      val parent = node.parent
      if (parent == null || parent.isSentinelRoot()) {
        // The root node.
        return false
      }
      val payload = node.payload!!
      val antlrRuleForTheChild = payload.expectedAntlrRuleType!!
      if (antlrRuleForTheChild.canRuleBeEpsilon()) {
        // If the EXPECTED rule of the current node can be epsilon.
        return true
      }
      val childCount = parent.childCount
      return if (childCount == 1) {
        // Only the current node, then check whether the parent node rule can be epsilon.
        node = parent
        continue
      } else if (childCount > 1) {
        check(parent is ParserRuleSparTreeNode)
        when (parent.ruleType) {
          RuleType.KLEENE_PLUS, RuleType.KLEENE_STAR -> true
          RuleType.OPTIONAL -> error(
            "Optional should have a single child. " + node.printTreeStructure(),
          )
          else -> false
        }
      } else {
        error("Unreachable. " + node.printTreeStructure())
      }
    }
    return false
  }

  private fun createNodeDeletionActionSetInverse(
    originalInput: ImmutableList<AbstractSparTreeNode>,
    input: ImmutableList<AbstractSparTreeNode>,
  ): NodeDeletionActionSet {
    val actionSetBuilder =
      NodeDeletionActionSet.Builder("delta debugger@${input.size}")
    Util.visitDifference(superList = originalInput, subList = input) {
      lazyAssert { !it.isPermanentlyDeleted }
      actionSetBuilder.deleteNode(it)
    }
    return actionSetBuilder.build()
  }

  fun createPropertyTester(
    actionSetDescriptionPrefix: String,
    tree: SparTree,
  ) = object : IPropertyTester<AbstractSparTreeNode, SparTreeDdminPayload> {

    override fun testProperty(
      configuration: Configuration<AbstractSparTreeNode>,
    ): AbstractPropertyTestResultWithPayload<SparTreeDdminPayload> {
      val actionSet = configuration.deleted.let {
        NodeDeletionActionSet.Builder(
          "${actionSetDescriptionPrefix}dd@${it.size}",
        ).deleteNodes(it).build()
      }
      if (reducerContext.nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
        reducerContext.listenerManager.onNodeEditActionSetCacheHit(actionSet)
        return SkipPropertyTestResult()
      }
      val treeEdit = tree.createNodeDeletionEdit(actionSet)
      val result = testAllTreeEditsAndReturnTheBest(
        listOf(treeEdit),
      ) ?: return SkipPropertyTestResult()
      return PropertyTestResultWithPayload(
        result.testResult,
        SparTreeDdminPayload(
          tree,
          result.edit as NodeDeletionTreeEdit,
        ),
      )
    }
  }

  fun createOnBestUpdateHandler() =
    OnBestUpdateHandler<AbstractSparTreeNode, SparTreeDdminPayload> { _, payload ->
      payload.tree.applyEdit(payload.edit)
    }

  protected fun createDeltaArguments(
    needToTestEmpty: Boolean,
    tree: SparTree,
    actionsDescription: String,
    input: ImmutableList<AbstractSparTreeNode>,
  ): AbstractListInputMinimizer.Arguments<AbstractSparTreeNode, SparTreeDdminPayload> {
    return AbstractListInputMinimizer.Arguments(
      needToTestEmpty = needToTestEmpty,
      input = input,
      propertyTester = createPropertyTester(actionSetDescriptionPrefix = actionsDescription, tree),
      onBestUpdateHandler = createOnBestUpdateHandler(),
      descriptionPrefix = actionsDescription,
      weightProvider = { it.leafTokenCount },
      listener = reducerContext.deltaDebuggerListener,
    )
  }

  companion object {
    private fun removePermanentlyDeletedNodes(partition: LinkedList<AbstractSparTreeNode>) {
      val iter = partition.iterator()
      while (iter.hasNext()) {
        val node = iter.next()
        if (node.isPermanentlyDeleted) {
          iter.remove()
        }
      }
    }
  }
}
