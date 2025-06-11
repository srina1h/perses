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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.CommandOptions
import org.perses.antlr.ParseTreeUtil
import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.AbstractListInputMinimizerListener
import org.perses.listminimizer.ListInputMinimizerProgressListener
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractActionSetProfiler.ActionSetProfiler
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.cache.AbstractQueryCacheProfiler
import org.perses.reduction.cache.EnumQueryCachingControl
import org.perses.reduction.cache.NullQueryCache
import org.perses.reduction.cache.PassLevelCache
import org.perses.reduction.cache.PassLevelCache.PassLevelCacheResult
import org.perses.reduction.cache.QueryCacheConfiguration
import org.perses.reduction.cache.QueryCacheFactory
import org.perses.reduction.cache.QueryCacheMemoryProfiler
import org.perses.reduction.cache.QueryCacheTimeCsvProfiler
import org.perses.reduction.cache.QueryCacheTimeProfiler
import org.perses.reduction.cache.QueryCacheType
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.SanityCheckEvent
import org.perses.reduction.event.TestScriptExecutorServiceStatisticsSnapshot
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.reduction.reducer.SparTreeRootReplacementReducer
import org.perses.reduction.reducer.TreeSlicer
import org.perses.reduction.reducer.lpr.LLMBasedDataTypeEliminationReducer
import org.perses.reduction.reducer.lpr.LLMBasedDataTypeSimplificationReducer
import org.perses.reduction.reducer.lpr.LLMBasedFunctionInliningReducer
import org.perses.reduction.reducer.lpr.LLMBasedLoopUnrollingReducer
import org.perses.reduction.reducer.lpr.LLMBasedVariableEliminationReducer
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import org.perses.reduction.reducer.token.LineBasedConcurrentTokenSlicer
import org.perses.reduction.reducer.trec.TokenCanonicalizer
import org.perses.reduction.reducer.vulcan.IdentifierReplacementReducer
import org.perses.reduction.reducer.vulcan.SubTreeReplacementReducer
import org.perses.reduction.reducer.vulcan.pattern.LocalExhaustivePatternReducer
import org.perses.reduction.scheduler.ReducerExecutionPlan
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractExecutionPlanStep
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractExecutionPlanStep.Companion.concatenate
import org.perses.reduction.scheduler.ReducerExecutionPlan.AtomicReducerStep
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.fixpoint
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.ifProgressed
import org.perses.reduction.scheduler.ReducerExecutionPlan.ContinueOnChange
import org.perses.reduction.scheduler.ReducerScheduler
import org.perses.spartree.AbstractNodeActionSetCache
import org.perses.spartree.AbstractSparTreeEditListener
import org.perses.spartree.AbstractTreeNode
import org.perses.spartree.NodeActionSetCache
import org.perses.spartree.NullNodeActionSetCache
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.Serialization
import org.perses.util.TimeSpan
import org.perses.util.TimeUtil
import org.perses.util.Util
import org.perses.util.ktFine
import org.perses.util.ktInfo
import org.perses.util.ktSevere
import org.perses.util.ktWarning
import org.perses.util.shell.Shells
import org.perses.util.transformToImmutableList
import java.lang.ref.WeakReference

abstract class AbstractProgramReductionDriver(
  globalContext: GlobalContext,
  protected val cmd: CommandOptions,
  ioManager: TokenReductionIOManager,
  private var tree: SparTreeWithParsability,
  val configuration: ReductionConfiguration,
  val listenerManager: AsyncReductionListenerManager,
) : AbstractReductionDriver<TokenizedProgram, LanguageKind, TokenReductionIOManager>(
  globalContext,
  ioManager,
  cmd.reductionControlFlags.getNumOfThreads(),
  cmd.reductionControlFlags.testScriptExecutionTimeoutInSeconds,
  cmd.reductionControlFlags.testScriptExecutionKeepWaitingAfterTimeout,
) {

  private fun createQueryCacheProfiler() =
    if (cmd.profilingFlags.profileQueryCacheTimeCSV != null) {
      QueryCacheTimeCsvProfiler(
        globalContext.fileStreamPool.rentStream(
          cmd.profilingFlags.profileQueryCacheTimeCSV!!,
          description = QueryCacheTimeCsvProfiler::class.qualifiedName,
        ),
      )
    } else if (cmd.profilingFlags.profileQueryCacheTime != null) {
      QueryCacheTimeProfiler(
        globalContext.fileStreamPool.rentStream(
          cmd.profilingFlags.profileQueryCacheTime!!,
          description = QueryCacheTimeProfiler::class.qualifiedName,
        ),
      )
    } else if (cmd.profilingFlags.profileQueryCacheMemory != null) {
      QueryCacheMemoryProfiler(
        globalContext.fileStreamPool.rentStream(
          cmd.profilingFlags.profileQueryCacheMemory!!,
          description = QueryCacheMemoryProfiler::class.qualifiedName,
        ),
      )
    } else {
      AbstractQueryCacheProfiler.NULL_PROFILER
    }

  private val queryCache =
    if (configuration.enableTestScriptExecutionCaching) {
      QueryCacheFactory.createQueryCache(
        computeQueryCacheType(cmd.cacheControlFlags.cacheType, ioManager.getDefaultProgramFormat()),
        tree.programSnapshot,
        registerToClose(createQueryCacheProfiler()),
        QueryCacheConfiguration(
          cmd.cacheControlFlags.queryCacheRefreshThresholdAsFraction(),
          enableLightweightRefreshing = cmd.cacheControlFlags.enableLightweightRefreshing,
        ),
      )
    } else {
      NullQueryCache()
    }

  val nodeActionSetCache =
    if (cmd.cacheControlFlags.nodeActionSetCaching) {
      NodeActionSetCache()
    } else {
      NullNodeActionSetCache()
    }
  private val actionSetProfiler =
    if (cmd.profilingFlags.actionSetProfiler == null) {
      AbstractActionSetProfiler.NULL_PROFILER
    } else {
      ActionSetProfiler(cmd.profilingFlags.actionSetProfiler!!)
    }

  override fun getInitialProgram(): TokenizedProgram {
    return tree.programSnapshot
  }

  override fun reduce() {
    printStartTime()
    val parsableTree = tree.getParsableTreeOrFail()
    val reductionStartEvent = createReductionStartEvent(parsableTree)
    listenerManager.onReductionStart(reductionStartEvent)
    try {
      logCacheSettings()
      ioManager.backupAllMutableFiles()
      sanityCheckAndLogAndMayThrow()
      ioManager.updateBestResult(parsableTree.programSnapshot)
      val sparTreeEditListeners = createSparTreeEditListeners(
        ioManager,
        queryCache,
        listenerManager,
        nodeActionSetCache,
      )
      parsableTree.registerSparTreeEditListeners(sparTreeEditListeners)
      val tokenizedProgramFactory = parsableTree.tokenizedProgramFactory
      val persesTokenFactory = tokenizedProgramFactory.tokenFactory
      logger.ktInfo {
        "The number of lexemes in the token factory is is ${persesTokenFactory.numOfLexemes()}"
      }

      val actionBeforeNonFirstRunOfMainReducers = {
        updateTreeBeforeIteration(reductionStartEvent) { tree ->
          val sparTree = tree.getTreeRegardlessOfParsability()
          check(
            sparTree.tokenizedProgramFactory
              === tokenizedProgramFactory,
          ) { "The tokenized program factory should be unchanged during a reduction process." }
          check(
            sparTree.tokenizedProgramFactory.tokenFactory ===
              tokenizedProgramFactory.tokenFactory,
          ) { "The perses token factory should be unchanged during a reduction process." }
          check(sparTree.hasTheSameEditListeners(sparTreeEditListeners))
        }
      }
      val reducerExecutionPlan = createReducerExecutionPlan(
        atomicMainReducerStep = AtomicReducerStep(
          reducer = createMainReducerCreator(),
          actionBefore = actionBeforeNonFirstRunOfMainReducers,
        ),
      )
      listenerManager.onAdHocMessageEvent(
        reductionStartEvent.createAdHocMessageEvent(
          programSize = tree.programSnapshot.tokenCount,
        ) {
          buildString {
            append("The reducer execution plan is listed below.\n")
            append(reducerExecutionPlan.steps.toDefinition().toYamlString()).append('\n')
          }
        },
      )
      internalReduce(
        reductionStartEvent = reductionStartEvent,
        reducerExecutionPlan = reducerExecutionPlan,
      )
    } finally {
      // Just to make sure the onReductionEnd() can be called even in case of exceptions.
      val finalTokenCount = tree.updateTokenCountAndGet()
      val reductionEndEvent = reductionStartEvent.createEndEvent(
        programSize = finalTokenCount,
        testScriptStatistics = executorService.statistics.createSnapshot(),
      )
      listenerManager.onReductionEnd(reductionEndEvent)
    }
    callCreduceIfEnabled()
    formatBestFileIfEnabled()
  }

  private var sanityCheckResult: SanityCheckEvent? = null

  private fun sanityCheckAndLogAndMayThrow() {
    val result = cachedSanityCheckResult
    listenerManager.onSanityCheck(
      SanityCheckEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = getInitialProgram().tokenCount,
        sanityCheckResult = result,
      ),
    )
    if (result is IReductionDriver.FailingSanityCheckResult) {
      throw result.exception
    }
  }

  private fun logCacheSettings() {
    logger.ktInfo {
      val queryCacheStatus = boolToString(configuration.enableTestScriptExecutionCaching)
      val editCacheStatus = boolToString(cmd.cacheControlFlags.nodeActionSetCaching)
      val queryCacheType = cmd.cacheControlFlags.cacheType.name.lowercase()
      "Cache setting: query-caching=$queryCacheStatus, " +
        "edit-caching=$editCacheStatus, query-cache=$queryCacheType"
    }
  }

  private fun createReductionStartEvent(parsableTree: SparTree) = ReductionStartEvent(
    System.currentTimeMillis(),
    WeakReference(parsableTree),
    parsableTree.tokenCount,
    commandLineOptions = Serialization.toYamlString(
      cmd,
      objectMapperCustomizer = Serialization::customizeObjectMapperByUsingBasenameForPath,
    ),
    extraData = "Parser Facade: ${configuration.parserFacade::class}",
  )

  private fun createReducerExecutionPlan(
    atomicMainReducerStep: AtomicReducerStep,
  ): ReducerExecutionPlan {
    val mainReducerSteps = if (configuration.fixpointReductionForMainReducer) {
      fixpoint { atomicMainReducerStep }
    } else {
      atomicMainReducerStep
    }
    val coarseGritReducers = createExecutionPlanForCoarseGritReducers(
      atomicMainReducerStep = atomicMainReducerStep,
      reducerAnnotations = listOfNotNull(
        LineBasedConcurrentTokenSlicer.CompositeReducerAnnotation.takeIf { lineSlicerEnabled },
        TreeSlicer.META.takeIf { cmd.algorithmControlFlags.enableTreeSlicer },
        ConcurrentTokenSlicer.CompositeReducerAnnotation.takeIf {
          cmd.algorithmControlFlags.enableTokenSlicer
        },
        /* t-rec does not further reduce tokens after vulcan, so run trec right after main */
        TokenCanonicalizer.META.takeIf { cmd.trecFlags.enableTrec },
      ).plus(
        cmd.experimentFlags.onDemandCoarseGritReducerAnnotationClasses.map {
          ReducerFactory.getReductionAlgorithm(it.name)
        },
      ),
    )

    val mediumGritReducers =
      createExecutionPlanForLanguageSpecificTransformativeReducers(
        atomicMainReducerStep = atomicMainReducerStep,
        reducerAnnotations = listOfNotNull(
          LLMBasedFunctionInliningReducer.META.takeIf { cmd.lprFlags.enableLPR },
          LLMBasedLoopUnrollingReducer.META.takeIf { cmd.lprFlags.enableLPR },
          LLMBasedDataTypeEliminationReducer.META.takeIf { cmd.lprFlags.enableLPR },
          LLMBasedDataTypeSimplificationReducer.META.takeIf { cmd.lprFlags.enableLPR },
          LLMBasedVariableEliminationReducer.META.takeIf { cmd.lprFlags.enableLPR },
        ).plus(
          cmd.experimentFlags.onDemandMediumGritReducerAnnotationClasses.map {
            ReducerFactory.getReductionAlgorithm(it.name)
          },
        ),
        overallFixpoint = configuration.lprConfig.lprFixpoint,
      )
    val fineGritReducers =
      createExecutionPlanForFineGritReducers(
        atomicMainReducerStep = atomicMainReducerStep,
        reducerAnnotations = listOfNotNull(
          LocalExhaustivePatternReducer.META.takeIf { cmd.vulcanFlags.enableVulcan },
          IdentifierReplacementReducer.META.takeIf { cmd.vulcanFlags.enableVulcan },
          SubTreeReplacementReducer.META.takeIf { cmd.vulcanFlags.enableVulcan },
        ).plus(
          cmd.experimentFlags.onDemandFineGritReducerAnnotationClasses.map {
            ReducerFactory.getReductionAlgorithm(it.name)
          },
        ),
        overallFixpoint = configuration.vulcanConfig.vulcanFixpoint,
      )

    return ReducerExecutionPlan(
      steps = concatenate(
        mainReducerSteps,
        coarseGritReducers,
        mediumGritReducers,
        fineGritReducers,
      ),
    )
  }

  private fun createExecutionPlanForCoarseGritReducers(
    atomicMainReducerStep: AtomicReducerStep,
    reducerAnnotations: List<ReducerAnnotation>,
  ): AbstractExecutionPlanStep? {
    val reducers: ImmutableList<AbstractExecutionPlanStep> = reducerAnnotations
      .transformToImmutableList { reducer ->
        fixpoint {
          ifProgressed(reducer) {
            fixpoint { atomicMainReducerStep }
          }
        }
      }
    return when (reducers.size) {
      0 -> null
      1 -> reducers.single()
      else -> ReducerExecutionPlan.UnconditionalSequentialSteps(reducers)
    }
  }

  private fun createExecutionPlanForLanguageSpecificTransformativeReducers(
    atomicMainReducerStep: AtomicReducerStep,
    reducerAnnotations: List<ReducerAnnotation>,
    overallFixpoint: Boolean,
  ): AbstractExecutionPlanStep? {
    if (reducerAnnotations.isEmpty()) {
      return null
    }
    val reducers = reducerAnnotations.map {
      ifProgressed(it) {
        atomicMainReducerStep
      }
    }
    val concatenated = concatenate(reducers)
    return if (overallFixpoint) {
      fixpoint(ContinueOnChange(configuration.vulcanConfig.nonDeletionIterationLimit)) {
        concatenated
      }
    } else {
      concatenated
    }
  }

  private fun createExecutionPlanForFineGritReducers(
    atomicMainReducerStep: AtomicReducerStep,
    reducerAnnotations: List<ReducerAnnotation>,
    overallFixpoint: Boolean,
  ): AbstractExecutionPlanStep? {
    if (reducerAnnotations.isEmpty()) {
      return null
    }
    val reducers = reducerAnnotations.map {
      fixpoint(ContinueOnChange(configuration.vulcanConfig.nonDeletionIterationLimit)) {
        ifProgressed(it) { atomicMainReducerStep }
      }
    }
    val concatenated = concatenate(reducers)
    return if (overallFixpoint) {
      fixpoint { concatenated }
    } else {
      concatenated
    }
  }

  private fun internalReduce(
    reductionStartEvent: ReductionStartEvent,
    reducerExecutionPlan: ReducerExecutionPlan,
  ) {
    val reducerScheduler = ReducerScheduler(
      reducerContext = reducerContext,
      reducerExecutionPlan = reducerExecutionPlan,
      computeStatistics = this::computeStatistics,
      reducerRunner = { callReducer(reductionStartEvent, it) },
    )
    val minimalSparTree = reducerScheduler
      .runAndGetGlobalMinimalSparTreeIfDifferentFromCurrentBest()
    listenerManager.onAdHocMessageEvent(
      reductionStartEvent.createAdHocMessageEvent(
        programSize = minimalSparTree?.tokenCount ?: tree.programSnapshot.tokenCount,
        messageComputer = {
          val events = reducerScheduler.readSchedulerEvents()
          buildString {
            append("The history of the reducer invocation.\n")
            events.withIndex().forEach { event ->
              append("[${event.index}]: ${event.value::class.simpleName}\n")
              append(Serialization.toYamlString(event.value))
              append("\n")
            }
          }
        },
      ),
    )
    if (minimalSparTree == null) {
      return
    }
    callReducer(
      reductionStartEvent,
      SparTreeRootReplacementReducer(
        reducerContext,
        minimalSparTree.detachRootFromTree(),
      ),
    )
  }

  private fun computeStatistics(): StatsOfFilesBeingReduced {
    return StatsOfFilesBeingReduced(
      tree.updateTokenCountAndGet(),
      characterCount = tree.programSnapshot.totalCharacterCount,
      ioManager.readAndTrimAllBestFiles().transformToImmutableList {
        StatsOfFilesBeingReduced.FileNameAndContentDigestPair(
          it.fileName,
          Util.SHA512HashCode.createFromString(it.computeFileContent()),
        )
      },
    )
  }

  private inline fun updateTreeBeforeIteration(
    reductionStartEvent: ReductionStartEvent,
    treeAssertion: (SparTreeWithParsability) -> Unit,
  ) {
    val message = StringBuilder()
    if (cmd.algorithmControlFlags.rebuildParseTreeEachIteration) {
      message.append("Rebuilding spar-tree: ")
      // Rebuilding is necessary, to hop over different production rules.
      val oldSparTree = tree.getTreeRegardlessOfParsability()
      if (!oldSparTree.dirty) {
        message.append("The spartree is not dirty, and thus the rebuilding is skipped.")
      } else {
        tree = reparseAndCreateSparTree(tree, configuration.parserFacade, ioManager)
        if (oldSparTree != tree.getTreeRegardlessOfParsability()) {
          // TODO: this branch needs testing. We currently have no test which can trigger this branch.
          tree.getTreeRegardlessOfParsability().copyListenersFrom(oldSparTree)
        }
        message.append("The spartree is rebuilt.")
      }
      listenerManager.onAdHocMessageEvent(
        reductionStartEvent.createAdHocMessageEvent(
          programSize = tree.getTreeRegardlessOfParsability().tokenCount,
        ) { message.append("\n") },
      )
    }
    treeAssertion(tree)
  }

  private fun simplifySparTree() {
    SparTreeSimplifier.simplify(tree.getTreeRegardlessOfParsability())
  }

  private fun callCreduceIfEnabled() {
    if (!cmd.outputRefiningFlags.callCReduce) {
      return
    }
    val program = tree.programSnapshot
    val origTokenCount = program.tokenCount
    logger.ktInfo {
      "Calling C-Reduce to further refine the result. #tokens=$origTokenCount"
    }
    val creduceCmd = cmd.outputRefiningFlags.creduceCmd
    val reductionFolder = executorService.createReductionFolder(
      prefix = "creduce_at_the_end",
      suffix = TimeUtil.formatDateForFileName(System.currentTimeMillis()),
    )
    ioManager.createOutputManager(program)
      .write(reductionFolder)
    val cmdOutput = Shells.singleton.run(
      constructFullCreduceCommand(creduceCmd, reductionFolder),
      reductionFolder.folder,
      captureOutput = false,
      environment = Shells.CURRENT_ENV,
    )
    if (cmdOutput.exitCode.isNonZero()) {
      val tempDir = copyFilesToTempDir(reductionFolder.folder)
      logger.ktSevere {
        "C-Reduce failed to reduce the file. All files are copied to $tempDir"
      }
      return
    }
    try {
      /* TODO: we need to put the syntax checking into the reduction script, so that
       *       the result generated by c-reduce is still syntactical valid.
       */
      tree = ioManager.visitMainSourceFileIn(reductionFolder) {
        createSparTree(it, configuration.parserFacade)
      }
    } catch (e: java.lang.Exception) {
      logger.ktSevere { "The file produced by C-Reduce cannot be parsed: $e" }
      return
    }
    ioManager.updateBestResult(tree.programSnapshot)
    val tokenCount = tree.programSnapshot.tokenCount
    logger.ktInfo {
      "C-Reduce reduced the file from $origTokenCount to $tokenCount tokens"
    }
  }

  private fun constructFullCreduceCommand(
    creduceCmd: String,
    reductionFolder: ReductionFolder,
  ) = buildString {
    append(creduceCmd)
    append(' ')
    append(ioManager.getScriptFileBaseNameIn(reductionFolder))
    append(' ')
    append(ioManager.getSingleSourceFileBaseName(reductionFolder))
  }

  private val lineSlicerEnabled =
    if (!cmd.algorithmControlFlags.enableLineSlicer) {
      false
    } else {
      val programFormat = ioManager.getDefaultProgramFormat()
      if (programFormat == EnumFormatControl.SINGLE_TOKEN_PER_LINE) {
        logger.ktWarning {
          "The program format is $programFormat, " +
            "incompatible with line slicer. Line slicer is disabled."
        }
        false
      } else {
        true
      }
    }

  /**
   * @return a copy of the spartree with the same node ids.
   */
  private fun callReducer(
    reductionStartEvent: ReductionStartEvent,
    reducer: AbstractTokenReducer,
  ): SparTree? {
    val reducerName = reducer.reducerAnnotation.shortName
    if (cmd.cacheControlFlags.enablePassCache && reducer.reducerAnnotation.deterministic &&
      updatePassLevelCache(reducer.reducerAnnotation) == PassLevelCacheResult.EXISTING_ALREADY
    ) {
      logger.ktInfo {
        "[Pass Caching]: The reducer $reducerName is skipped, " +
          "because the input has been reduced the reducer by before and" +
          "the input has not changed."
      }
      return null
    }
    simplifySparTree()
    val preSize = tree.updateTokenCountAndGet()
    logger.ktInfo {
      val time = TimeUtil.formatDateForDisplay(System.currentTimeMillis())
      "$reducerName started at $time. #tokens=$preSize"
    }
    val currentStat = computeStatistics()
    val fixpointIterationStartEvent = reductionStartEvent.nextFixpointIteration(
      programSize = currentStat.tokenCount,

      reducerClass = reducer.reducerAnnotation,
      treeStructureDumper = {
        WeakReference(tree.getTreeRegardlessOfParsability()).get()?.printTreeStructure() ?: ""
      },
      testScriptStatistics = executorService.statistics.createSnapshot(),
    )
    listenerManager.onFixpointIterationStart(fixpointIterationStartEvent)
    reducer.reduce(FixpointReductionState(fixpointIterationStartEvent, tree))
    logger.ktInfo {
      val time = TimeUtil.formatDateForDisplay(System.currentTimeMillis())
      "$reducerName ended at $time. #old=$preSize, #new=${tree.updateTokenCountAndGet()}"
    }
    listenerManager.onFixpointIterationEnd(
      fixpointIterationStartEvent.createEndEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = tree.programSnapshot.tokenCount,
        testScriptStatistics = executorService.statistics.createSnapshot(),
      ),
    )
    return tree.getTreeRegardlessOfParsability()
      .deepCopy(AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy)
      .result
  }

  private val passLevelCache = PassLevelCache()

  private fun updatePassLevelCache(reducerAnnotation: ReducerAnnotation): PassLevelCacheResult {
    return passLevelCache.update(reducerAnnotation) {
      ioManager.outputManagerFactory.createManagerFor(tree.programSnapshot).shA512HashCode
    }
  }

  // TODO: unit-test this function.
  private fun formatBestFileIfEnabled() {
    if (!cmd.outputRefiningFlags.callFormatter) {
      return
    }
    val formatCmd = configuration.parserFacade.language.getDefaultWorkingFormatter()
    if (formatCmd == null) {
      logger.ktSevere {
        "The default formatter is not working. cmd=" +
          configuration.parserFacade.language.getAllDefaultFormatterCommandStrings()
      }
      return
    }

    val formatFolder = executorService.createReductionFolder(
      prefix = "formatter_at_the_end_",
      suffix = TimeUtil.formatDateForFileName(System.currentTimeMillis()),
    )
    ioManager.createOutputManager(tree.programSnapshot)
      .write(formatFolder)
    logger.ktInfo {
      "Formatting the reduction result " +
        "in ${formatFolder.folder} with ${formatCmd.normalizedCommand}"
    }

    val sourceFileNames = ioManager.getAllSourceFileBaseNamesIn(formatFolder)

    for (sourceFileName in sourceFileNames) {
      val cmdOutput = formatCmd.runWith(
        ImmutableList.of(sourceFileName),
        workingDirectory = formatFolder.folder,
      )
      if (cmdOutput.exitCode.isNonZero()) {
        logger.ktSevere {
          "Failed to call formatter ${formatCmd.normalizedCommand} " +
            "on the final result ${formatFolder.folder}."
        }
        logger.ktSevere { "stdout: " + cmdOutput.stderr.combinedLines }
        logger.ktSevere { "stderr: " + cmdOutput.stdout.combinedLines }
        return
      }
    }

    val scriptTestResult = formatFolder.runTestScript()
    if (scriptTestResult.isNotInteresting) {
      logger.ktSevere {
        "The formatted file(s) failed the property test: " +
          "formatter=${formatCmd.normalizedCommand}, program(s)=$formatFolder/$sourceFileNames"
      }
      return
    }
    if (cmd.algorithmControlFlags.rebuildParseTreeEachIteration) {
      try {
        /* TODO: we need to put the syntax checking into the reduction script, so that
         *       the result generated by c-reduce is still syntactical valid.
         */
        tree = ioManager.visitMainSourceFileIn(formatFolder) {
          createSparTree(it, configuration.parserFacade)
        }
      } catch (e: java.lang.Exception) {
        logger.ktSevere {
          "The file produced by the formatter '$formatCmd' cannot be parsed. $e"
        }
        return
      }
      ioManager.updateBestResultInOrigFormat(tree.programSnapshot)
    } else {
      formatFolder.copyTo(ioManager.resultFolder)
    }
  }

  override fun close() {
    // trigger the cache to do some profiling work, before profile is closed.
    queryCache.triggerHeartBeat()
    super.close()
  }

  open fun createMainReducerCreator(): ReducerAnnotation {
    val algorithmMeta = ReducerFactory.getReductionAlgorithm(
      cmd.algorithmControlFlags.reductionAlgorithm.let { algName ->
        algName ?: PersesNodePrioritizedDfsReducer.NAME
      },
    )
    logger.ktInfo {
      "Reduction algorithm is ${algorithmMeta.shortName}"
    }
    return algorithmMeta
  }

  private val reducerContext = ReducerContext(
    ioManager,
    configuration,
    executorService,
    listenerManager,
    queryCache,
    nodeActionSetCache,
    actionSetProfiler,
    sparTreeNodeFactory = tree.getTreeRegardlessOfParsability().sparTreeNodeFactory,
    deltaDebuggerListener = if (cmd.profilingFlags.profileDeltaDebugger == null) {
      AbstractListInputMinimizerListener.NullListInputMinimizerListener
    } else {
      ListInputMinimizerProgressListener(cmd.profilingFlags.profileDeltaDebugger!!)
    },
  )

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    private fun reparseAndCreateSparTree(
      originalTree: SparTreeWithParsability,
      parserFacade: AbstractParserFacade,
      ioManager: TokenReductionIOManager,
    ): SparTreeWithParsability {
      return try {
        val parseTree = parserFacade.parseString(ioManager.readBestMainFile())
        val sparTree = SparTreeBuilder.createSparTree(
          originalTree.getTreeRegardlessOfParsability().sparTreeNodeFactory,
          parseTree,
        )
        SparTreeWithParsability(sparTree, parsable = true)
      } catch (e: Exception) {
        logger.ktWarning { "Fail to re-parse the best program." }
        SparTreeWithParsability(
          originalTree.getTreeRegardlessOfParsability(),
          parsable = false,
        )
      }
    }

    internal fun computeQueryCacheType(
      specifiedQueryType: QueryCacheType,
      defaultProgramFormat: EnumFormatControl,
    ): QueryCacheType {
      val cacheType = if (specifiedQueryType == QueryCacheType.AUTO) {
        if (defaultProgramFormat == EnumFormatControl.SINGLE_TOKEN_PER_LINE) {
          QueryCacheType.COMPACT_QUERY_CACHE
        } else {
          QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE
        }
      } else {
        specifiedQueryType
      }
      require(
        cacheType != QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE ||
          defaultProgramFormat != EnumFormatControl.SINGLE_TOKEN_PER_LINE,
      ) {
        "Cache type ${QueryCacheType.COMPACT_QUERY_CACHE_FORMAT_SENSITIVE} " +
          "is not compatible with the code format ${EnumFormatControl.SINGLE_TOKEN_PER_LINE}"
      }
      return cacheType
    }

    @JvmStatic
    private fun createSparTreeEditListeners(
      ioManager: TokenReductionIOManager,
      queryCache: AbstractQueryCache,
      listenerManager: AsyncReductionListenerManager,
      nodeActionSetCache: AbstractNodeActionSetCache,
    ): ImmutableList<AbstractSparTreeEditListener> {
      val builder = ImmutableList.builder<AbstractSparTreeEditListener>()
      builder.add(
        object : AbstractSparTreeEditListener() {
          override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
            ioManager.updateBestResult(event.program)
            logger.ktFine {
              "An edit is applied to the spar-tree. New #tokens=${event.program.tokenCount}"
            }
          }
        },
      )
      builder.add(
        object : AbstractSparTreeEditListener() {
          override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
            val sizeBefore = queryCache.size()
            queryCache.evictEntriesLargerThan(event.program)
            val sizeAfter = queryCache.size()
            listenerManager.onTestScriptExecutionCacheEntryEviction(sizeBefore, sizeAfter)
          }
        },
      )
      builder.add(
        object : AbstractSparTreeEditListener() {
          override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
            val originalSize = nodeActionSetCache.size
            nodeActionSetCache.clear()
            listenerManager.onNodeActionSetClearance(originalSize)
          }
        },
      )
      return builder.build()
    }

    @JvmStatic
    fun createSparTree(
      fileToReduce: SourceFile,
      parserFacade: AbstractParserFacade,
    ): SparTreeWithParsability {
      val timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis())
      logger.ktInfo { "Tree Building: Start building spar-tree from input file $fileToReduce" }
      val hierarchy = parserFacade.ruleHierarchy
      logger.ktInfo { "Tree Building: Step 1: Antlr parsing." }
      val parseTree = parserFacade.parseString(fileToReduce.textualFileContent)
      // This needs to be enabled, once isInputCompletelyConsumed support the Python grammar.
      // Util.lazyAssert { parseTree.isInputCompletelyConsumed() }
      val tokenizedProgramFactory = createTokenizedProgramFactory(
        parseTree.tree,
        parserFacade.language,
      )
      val sparTreeNodeFactory = SparTreeNodeFactory(
        parserFacade.metaTokenInfoDb,
        tokenizedProgramFactory,
        hierarchy,
      )
      logger.ktInfo { "Tree Building: Step 2: Converting parse tree to spar-tree" }
      val sparTree = SparTreeBuilder.createSparTree(sparTreeNodeFactory, parseTree)
      logger.ktInfo { "Tree Building: Step 3: Simplifying spar-tree" }
      val time = timeSpanBuilder.end(System.currentTimeMillis())
      logger.ktInfo { "Tree Building: Finished in $time" }
      return SparTreeWithParsability(sparTree, parsable = true)
    }

    @JvmStatic
    @VisibleForTesting
    fun createConfiguration(
      cmd: CommandOptions,
      parserFacade: AbstractParserFacade,
      defaultProgramFormat: EnumFormatControl,
    ): ReductionConfiguration {
      return ReductionConfiguration(
        fixpointReductionForMainReducer = cmd.reductionControlFlags.fixpoint,
        enableTestScriptExecutionCaching = computeWhetherToEnableQueryCaching(
          cmd.cacheControlFlags.queryCaching,
          defaultProgramFormat,
          vulcanEnabled = cmd.vulcanFlags.enableVulcan,
        ),
        defaultDeltaDebuggerTypeForKleene =
        cmd.algorithmControlFlags.defaultDeltaDebuggerTypeForKleene,
        numOfReductionThreads = cmd.reductionControlFlags.getNumOfThreads(),
        parserFacade = parserFacade,
        persesNodeReducerConfig = ReductionConfiguration.PersesNodeReducerConfiguration(
          maxEditCountForRegularRuleNode = cmd.algorithmControlFlags.maxEditCountForRegularRuleNode,
          maxBfsDepthForRegularRuleNode = cmd.algorithmControlFlags.maxBfsDepthForRegularRuleNode,
          stopAtFirstCompatibleChildren = cmd
            .algorithmControlFlags.stopAtFirstCompatibleChildForRegularRuleNode,
        ),
        vulcanConfig = ReductionConfiguration.VulcanConfig(
          nonDeletionIterationLimit = cmd.vulcanFlags.nonDeletionIterationLimit,
          windowSizeForLocalExhaustivePatternReduction = cmd.vulcanFlags.windowSize,
          vulcanFixpoint = cmd.vulcanFlags.vulcanFixpoint,
        ),
        lprConfig = ReductionConfiguration.LPRConfig(
          llmClientPath = cmd.lprFlags.llmClientPath,
          lprFixpoint = cmd.lprFlags.lprFixpoint,
        ),
      )
    }

    fun boolToString(value: Boolean) = if (value) "enabled" else "disabled"

    // We should enable SHA512 by default, as it is compatible with every algorithm.
    internal fun computeWhetherToEnableQueryCaching(
      userSpecified: EnumQueryCachingControl,
      programFormatControl: EnumFormatControl,
      vulcanEnabled: Boolean,
    ) = when (userSpecified) {
      EnumQueryCachingControl.TRUE -> true
      EnumQueryCachingControl.FALSE -> false
      EnumQueryCachingControl.AUTO ->
        programFormatControl == EnumFormatControl.SINGLE_TOKEN_PER_LINE &&
          !vulcanEnabled // Vulcan reducers are not compatible with query caching RCC.
    }

    private fun createTokenizedProgramFactory(
      originalTree: ParseTree,
      languageKind: LanguageKind,
    ): TokenizedProgramFactory {
      val tokens = ParseTreeUtil.getTokens(originalTree)
      return TokenizedProgramFactory.createFactory(tokens, languageKind)
    }
  }
}

fun TestScriptExecutorService.Statistics.createSnapshot() =
  TestScriptExecutorServiceStatisticsSnapshot(
    scriptExecutionNumber = this.scriptExecutionNumber,
    externalCacheHitNumber = this.externalCacheHitNumber,
  )
