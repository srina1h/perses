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
package org.perses.reduction.scheduler

import com.fasterxml.jackson.annotation.JsonIgnore
import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerAnnotation.ReductionResultSizeTrend.BEST_RESULT_SIZE_INCREASE
import org.perses.reduction.ReducerContext
import org.perses.reduction.StatsOfFilesBeingReduced
import org.perses.spartree.SparTree
import org.perses.util.Util

// TODO(cnsun): needs testing.
class ReducerScheduler(
  private val reducerContext: ReducerContext,
  private val reducerExecutionPlan: ReducerExecutionPlan,
  private val computeStatistics: () -> StatsOfFilesBeingReduced,
  reducerRunner: (AbstractTokenReducer) -> SparTree?,
) {

  private val schedulerEvents = SchedulerEventHistory()

  /**
   * @return the minimal spartree if the minimal spartree is smaller than the current best spartree
   *          that is being reduced.
   */
  fun runAndGetGlobalMinimalSparTreeIfDifferentFromCurrentBest(): SparTree? {
    // Always run the main reducers first, continuously if fixpoint is enabled.
    executePlan(reducerExecutionPlan.steps)

    val minSparTree = schedulerEvents.findTreeWithMinimalProgramSizeFromHistory()
    val currentBestSparTree = schedulerEvents.findCurrentBestSparTreeFromHistory()
    return if (minSparTree !== currentBestSparTree) {
      // Need to update the spartree.
      minSparTree
    } else {
      null
    }
  }

  private data class PlanExecutionBeforeAndAfterStats(
    val before: StatsSnapshotEvent,
    val after: StatsSnapshotEvent,
  )

  private fun executePlan(
    planElement: ReducerExecutionPlan.AbstractExecutionPlanStep,
  ): PlanExecutionBeforeAndAfterStats {
    return when (planElement) {
      is ReducerExecutionPlan.FixpointLoopStep -> {
        executeFixpointLoop(planElement)
      }

      is ReducerExecutionPlan.UnconditionalSequentialSteps -> {
        executeUnconditionalSequence(planElement)
      }

      is ReducerExecutionPlan.AtomicReducerStep -> {
        executeAtomicReducer(planElement)
      }

      is ReducerExecutionPlan.IfProgressedThenStep -> {
        executeIfReducedThenStep(planElement)
      }
    }
  }

  private fun executeFixpointLoop(
    fixpointLoop: ReducerExecutionPlan.FixpointLoopStep,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    var countOfNonDeletions = 0

    while (true) {
      val result = executePlan(fixpointLoop.body)
      when (computeFixpointDecision(result.before, result.after)) {
        FixpointDecision.CONTINUE_SMALLER_RESULT -> {
          countOfNonDeletions = 0
          continue
        }

        FixpointDecision.CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER -> {
          ++countOfNonDeletions
          check(fixpointLoop.continueCondition is ReducerExecutionPlan.ContinueOnChange) {
            fixpointLoop
          }
          if (countOfNonDeletions >= fixpointLoop.continueCondition.maxCountOfAllowedChanges) {
            break
          }
        }

        else -> break
      }
    }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  private fun executeUnconditionalSequence(
    sequence: ReducerExecutionPlan.UnconditionalSequentialSteps,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    sequence.reducers.forEach { executePlan(it) }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  private fun executeAtomicReducer(
    atomicReducer: ReducerExecutionPlan.AtomicReducerStep,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    atomicReducer.actionBefore.invoke()
    atomicReducer.reducer.create(reducerContext).forEach { callReducer(it) }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  private fun executeIfReducedThenStep(
    step: ReducerExecutionPlan.IfProgressedThenStep,
  ): PlanExecutionBeforeAndAfterStats {
    val before = recordStatsSnapshotIfNotYet()
    val conditionResult = computeFixpointDecision(executePlan(step.condition))
    if (conditionResult.continueFixpoint) {
      executePlan(step.then)
    }
    val after = recordStatsSnapshotIfNotYet()
    return PlanExecutionBeforeAndAfterStats(before = before, after = after)
  }

  fun readSchedulerEvents() = schedulerEvents.asList()

  private fun recordStatsSnapshotIfNotYet(): StatsSnapshotEvent {
    if (schedulerEvents.isLastEvent { it == null || it !is StatsSnapshotEvent }) {
      val currentStats = computeStatistics()
      val (numberOfNonDeletionIterations, fileContentChangedWrtPrevious) =
        schedulerEvents.lastStatsSnapshotEvent().let { lastStats ->
          if (lastStats == null) {
            check(schedulerEvents.lastEvent() == null) { "This event should be the first." }
            Pair(0, false)
          } else {
            val beforeStats = lastStats.stats
            when {
              beforeStats.tokenCount > currentStats.tokenCount -> Pair(0, true)
              beforeStats.fileContents == currentStats.fileContents -> {
                Pair(lastStats.numberOfNonDeletionIterations, false)
              }

              else -> {
                check(beforeStats.fileContents != currentStats.fileContents) {
                  "The file contents should be different: $beforeStats, $currentStats"
                }
                Pair(lastStats.numberOfNonDeletionIterations + 1, true)
              }
            }
          }
        }
      schedulerEvents.add(
        StatsSnapshotEvent(
          stats = currentStats,
          numberOfNonDeletionIterations = numberOfNonDeletionIterations,
          fileContentChangedWrtPrevious = fileContentChangedWrtPrevious,
        ),
      )
    }
    val last = schedulerEvents.lastEvent()
    check(last is StatsSnapshotEvent) { "The last element is $last" }
    Util.lazyAssert({ schedulerEvents.checkSchedulerEventsIntegrity() }) { schedulerEvents }
    return last
  }

  private val callReducer: (AbstractTokenReducer) -> Unit = { reducer: AbstractTokenReducer ->
    val treeAfterReduction = reducerRunner(reducer)
    val reducerEvent = ReducerCallEvent(reducer.reducerAnnotation, treeAfterReduction)
    schedulerEvents.add(reducerEvent)
    recordStatsSnapshotIfNotYet()
  }

  private fun computeFixpointDecision(
    statsBeforeAndAfter: PlanExecutionBeforeAndAfterStats,
  ): FixpointDecision {
    return computeFixpointDecision(
      before = statsBeforeAndAfter.before,
      after = statsBeforeAndAfter.after,
    )
  }

  private fun computeFixpointDecision(
    before: StatsSnapshotEvent,
    after: StatsSnapshotEvent,
  ): FixpointDecision {
    /*
      Every time the tokenCount is not reduced but the program is modified
      numOfNonDeletionTransformationAttempt will increment by 1. When the token
      number is not decreasing and the attempt times reach the pre-configured
      limit, the reduction process will be terminated. Every time the token
      number is reduced, numOfNonDeletionTransformationAttempt will be reset.
     */
    return if (before.stats.fileContents == after.stats.fileContents) {
      FixpointDecision.STOP_NO_CHANGE_IN_RESULT
    } else if (before.stats.tokenCount > after.stats.tokenCount ||
      before.stats.characterCount > after.stats.characterCount
    ) {
      FixpointDecision.CONTINUE_SMALLER_RESULT
    } else {
      FixpointDecision.CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER
    }
  }

  private enum class FixpointDecision(
    val continueFixpoint: Boolean,
    val reason: String,
  ) {
    STOP_NO_CHANGE_IN_RESULT(
      continueFixpoint = false,
      reason = "No change in the program.",
    ),
    CONTINUE_SMALLER_RESULT(
      continueFixpoint = true,
      reason = "The source file is smaller.",
    ),
    CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER(
      continueFixpoint = true,
      reason = "The program is changed, but its size remains the same.",
    ),
  }

  sealed class SchedulerEvent {
    final override fun hashCode(): Int {
      return super.hashCode()
    }

    final override fun equals(other: Any?): Boolean {
      return super.equals(other)
    }
  }

  data class ReducerCallEvent(
    val reducer: ReducerAnnotation,
    @JsonIgnore val treeAfterReduction: SparTree?,
  ) : SchedulerEvent() {
    override fun toString(): String {
      return MoreObjects.toStringHelper(this).add(
        "reducer",
        reducer,
      ).toString()
    }
  }

  data class StatsSnapshotEvent(
    val stats: StatsOfFilesBeingReduced,
    val numberOfNonDeletionIterations: Int,
    val fileContentChangedWrtPrevious: Boolean,
  ) : SchedulerEvent()

  class SchedulerEventHistory {

    private val history = mutableListOf<SchedulerEvent>()

    fun isLastEvent(predicate: (SchedulerEvent?) -> Boolean): Boolean {
      val last = history.lastOrNull()
      return predicate(last)
    }

    /**
     * TODO(cnsun): need to be unit-tested.
     */
    fun findTreeWithMinimalProgramSizeFromHistory(): SparTree? {
      val programCandidates = history.map { event ->
        if (event !is ReducerCallEvent) {
          return@map null
        }
        val program = event.treeAfterReduction ?: return@map null
        program
      }.filterNotNull()
      if (programCandidates.isEmpty()) {
        return null
      }
      val minTokenCount = programCandidates.minBy { it.tokenCount }.tokenCount
      val minProgramCandidates = programCandidates
        .filter { it.tokenCount == minTokenCount }
        .asReversed()
      return minProgramCandidates.minByOrNull { it.totalCharacterCount }
    }

    fun findCurrentBestSparTreeFromHistory(): SparTree? {
      val event = history
        .asReversed()
        .firstOrNull { it is ReducerCallEvent && it.treeAfterReduction != null } ?: return null
      return (event as ReducerCallEvent).treeAfterReduction
    }

    fun add(event: SchedulerEvent): SchedulerEvent {
      require(!history.contains(event)) { "The event $event is already in the history." }
      val last = history.lastOrNull()
      if (last == null) {
        require(event is StatsSnapshotEvent) { "The first event must be a stats event." }
      } else {
        require(last::class.java != event::class.java) {
          "$history, $event"
        }
        if (last is ReducerCallEvent) {
          require(event is StatsSnapshotEvent)
          val eventBeforeLast = history[history.size - 2]
          check(eventBeforeLast is StatsSnapshotEvent)
          if (last.reducer.reductionResultSizeTrend != BEST_RESULT_SIZE_INCREASE) {
            check(eventBeforeLast.stats.tokenCount >= event.stats.tokenCount) {
              "The reducer cannot increase the token count, but the token count increases."
            }
          }
        }
      }
      history.add(event)
      return event
    }

    fun findAllReducerEventsBetween(
      startStats: StatsSnapshotEvent,
      endStats: StatsSnapshotEvent,
    ): ImmutableList<ReducerCallEvent> {
      require(startStats !== endStats)
      val startIndex = history.indexOf(startStats)
      require(startIndex >= 0) {
        "$startIndex, $startStats, $history"
      }
      Util.lazyAssert({ history.lastIndexOf(startStats) == startIndex }) {
        "$startIndex, $history, ${history.lastIndexOf(startStats)}"
      }
      val endIndex = history.lastIndexOf(endStats)
      require(endIndex >= 0)
      Util.lazyAssert({ history.indexOf(endStats) == endIndex }) {
        "$endIndex, $history, ${history.indexOf(endStats)}"
      }
      require(startIndex < endIndex) { "$startIndex, $endIndex" }
      val builder = ImmutableList.builder<ReducerCallEvent>()
      for (i in startIndex + 1 until endIndex) {
        val event = history[i]
        if (event is ReducerCallEvent) {
          builder.add(event)
        }
      }
      return builder.build()
    }

    fun lastStatsSnapshotEvent(): StatsSnapshotEvent? {
      return history.lastOrNull { it is StatsSnapshotEvent } as StatsSnapshotEvent?
    }

    fun lastEvent() = history.lastOrNull()

    fun asList(): List<SchedulerEvent> = history

    fun checkSchedulerEventsIntegrity(): Boolean {
      if (history.isEmpty()) {
        return true
      }
      if (history.toHashSet().size != history.size) {
        return false
      }
      return history.first() is StatsSnapshotEvent && history.zipWithNext().none { (prev, curr) ->
        prev::class.java == curr::class.java
      }
    }
  }
}
