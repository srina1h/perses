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
import com.google.common.flogger.FluentLogger
import com.google.common.util.concurrent.ListenableFuture
import org.perses.program.TokenizedProgram
import org.perses.reduction.event.AbstractTestScriptExecutionEvent
import org.perses.reduction.event.AbstractTestScriptExecutionEvent.TestScriptExecutionEvent
import org.perses.reduction.event.AdHocMessageEvent
import org.perses.reduction.event.BestProgramUpdateEvent
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.LevelGranularityReductionEndEvent
import org.perses.reduction.event.LevelGranularityReductionStartEvent
import org.perses.reduction.event.LevelReductionEndEvent
import org.perses.reduction.event.LevelReductionStartEvent
import org.perses.reduction.event.NodeEditActionSetCacheClearanceEvent
import org.perses.reduction.event.NodeEditActionSetCacheHitEvent
import org.perses.reduction.event.NodeReductionEndEvent
import org.perses.reduction.event.NodeReductionStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionSkippedEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.SanityCheckEvent
import org.perses.reduction.event.TestScriptExecutionCacheEntryEvictionEvent
import org.perses.reduction.event.TokenSlicingEndEvent
import org.perses.reduction.event.TokenSlicingStartEvent
import org.perses.spartree.AbstractActionSet
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.util.DaemonThreadPool
import org.perses.util.FileNameContentPair
import java.io.Closeable

class AsyncReductionListenerManager(
  private val listeners: ImmutableList<AbstractReductionListener>,
) : Closeable {

  private val executorService = DaemonThreadPool.createSingleThreadPool()

  override fun close() {
    DaemonThreadPool.waitInfinitelyToShutdown(executorService)
    listeners.forEach { it.close() }
  }

  private fun submitEvent(action: (AbstractReductionListener) -> Unit): ListenableFuture<*> {
    return executorService.submit {
      for (listener in listeners) {
        action(listener)
      }
    }
  }

  fun onAdHocMessageEvent(event: AdHocMessageEvent) {
    submitEvent { listener -> listener.onAdHocMessageEvent(event) }
  }

  fun onReductionStart(event: ReductionStartEvent) {
    submitEvent { listener ->
      listener.onReductionStart(event)
    }
  }

  fun onSanityCheck(event: SanityCheckEvent) {
    submitEvent { listener ->
      listener.onSanityCheck(event)
    }
  }

  fun onReductionEnd(endEvent: ReductionEndEvent) {
    submitEvent { listener ->
      listener.onReductionEnd(endEvent)
    }
  }

  fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    val future = submitEvent { listener ->
      listener.onFixpointIterationStart(event)
    }
    // Need to wait for the future to complete, because the event points
    // to the spartree that can be modified by reducers. We need to make sure
    // that the spartree is used before it is changed.
    future.get()
  }

  fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    submitEvent { listener ->
      listener.onFixpointIterationEnd(event)
    }
  }

  fun onBestProgramUpdated(event: BestProgramUpdateEvent) {
    submitEvent { listener ->
      listener.onBestProgramUpdated(event)
    }
  }

  fun onLevelReductionStart(event: LevelReductionStartEvent) {
    submitEvent { listener ->
      listener.onLevelReductionStart(event)
    }
  }

  fun onLevelReductionEnd(event: LevelReductionEndEvent) {
    submitEvent { listener ->
      listener.onLevelReductionEnd(event)
    }
  }

  fun onLevelGranularityReductionStart(event: LevelGranularityReductionStartEvent) {
    submitEvent { listener ->
      listener.onLevelGranularityReductionStart(event)
    }
  }

  fun onLevelGranularityReductionEnd(event: LevelGranularityReductionEndEvent) {
    submitEvent { listener ->
      listener.onLevelGranularityReductionEnd(event)
    }
  }

  fun onSlicingTokensStart(
    event: TokenSlicingStartEvent,
  ) {
    listeners.forEach { it.onSlicingTokensStart(event) }
  }

  fun onSlicingTokensEnd(
    event: TokenSlicingEndEvent,
  ) {
    listeners.forEach { it.onSlicingTokensEnd(event) }
  }

  fun onNodeReductionStart(event: NodeReductionStartEvent) {
    submitEvent { listener ->
      listener.onNodeReductionStart(event)
    }
  }

  fun onNodeReductionEnd(
    event: NodeReductionEndEvent,
  ) {
    submitEvent { listener ->
      listener.onNodeReductionEnd(event)
    }
  }

  fun onTestScriptExecution(
    result: PropertyTestResult,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair<String>>,
  ) {
    val event = TestScriptExecutionEvent(
      System.currentTimeMillis(),
      result,
      program,
      edit,
      outputCreator,
    )
    submitEvent { listener ->
      listener.onTestScriptExecution(event)
    }
  }

  fun onTestScriptExecutionCancelled(
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    millisToCancelTheTask: Int,
    outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair<String>>,
  ) {
    val event = AbstractTestScriptExecutionEvent.TestScriptExecutionCanceledEvent(
      System.currentTimeMillis(),
      millisToCancelTheTask,
      program,
      edit,
      outputCreator,
    )
    submitEvent { listener ->
      listener.onTestScriptExecutionCancelled(event)
    }
  }

  fun onTestResultCacheHit(
    result: PropertyTestResult,
    program: TokenizedProgram,
    edit: AbstractSparTreeEdit<*>,
    outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair<String>>,
  ) {
    val event = AbstractTestScriptExecutionEvent.TestResultCacheHitEvent(
      System.currentTimeMillis(),
      result,
      program,
      edit,
      outputCreator,
    )
    submitEvent { listener ->
      listener.onTestResultCacheHit(event)
    }
  }

  fun onNodeEditActionSetCacheHit(query: AbstractActionSet<*>) {
    val event = NodeEditActionSetCacheHitEvent(
      System.currentTimeMillis(),
      query,
    )
    submitEvent { listener ->
      listener.onNodeEditActionSetCacheHit(event)
    }
  }

  fun onTestScriptExecutionCacheEntryEviction(sizeBefore: Int, sizeAfter: Int) {
    val event = TestScriptExecutionCacheEntryEvictionEvent(
      System.currentTimeMillis(),
      sizeBefore,
      sizeAfter,
    )
    submitEvent { listener ->
      listener.onTestScriptExecutionCacheEntryEviction(event)
    }
  }

  fun onNodeActionSetClearance(cacheSizeBefore: Int) {
    val event = NodeEditActionSetCacheClearanceEvent(
      System.currentTimeMillis(),
      cacheSizeBefore,
    )
    submitEvent { listener ->
      listener.onNodeActionSetCacheClearance(event)
    }
  }

  fun onReductionSkipped(event: ReductionSkippedEvent) {
    submitEvent { listener ->
      listener.onReductionSkipped(event)
    }
  }

  companion object {
    val logger = FluentLogger.forEnclosingClass()
  }
}
