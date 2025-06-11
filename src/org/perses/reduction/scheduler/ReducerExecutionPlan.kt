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

import com.google.common.collect.ImmutableList
import org.perses.reduction.ReducerAnnotation
import org.perses.util.toImmutableList

class ReducerExecutionPlan(
  val steps: AbstractExecutionPlanStep,
) {

  sealed class AbstractExecutionPlanStep {

    abstract fun toDefinition(): ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef

    companion object {
      fun concatenate(
        steps: List<AbstractExecutionPlanStep>,
      ): AbstractExecutionPlanStep {
        return when (steps.size) {
          0 -> error("Execution plan must have at least one step")
          1 -> steps.single()
          else -> UnconditionalSequentialSteps(reducers = steps.toImmutableList())
        }
      }

      fun concatenate(vararg steps: AbstractExecutionPlanStep?): AbstractExecutionPlanStep {
        return concatenate(steps.filterNotNull())
      }
    }
  }

  class FixpointLoopStep(
    val body: AbstractExecutionPlanStep,
    val continueCondition: AbstractConditionCondition,
  ) : AbstractExecutionPlanStep() {

    override fun toDefinition(): ExecutionPlanYamlDefinition.FixpointLoopStepDef {
      return ExecutionPlanYamlDefinition.FixpointLoopStepDef(
        body = body.toDefinition(),
        condition = when (continueCondition) {
          is ContinueOnSmallSize -> "smaller"
          is ContinueOnChange -> continueCondition.maxCountOfAllowedChanges.toString()
        },
      )
    }
  }

  sealed class AbstractConditionCondition

  /**
   * Intentionally not using object but a regular class for YAML serialization.
   */
  class ContinueOnSmallSize : AbstractConditionCondition() {
    companion object {
      val INSTANCE = ContinueOnSmallSize()
    }
  }

  class ContinueOnChange(val maxCountOfAllowedChanges: Int) : AbstractConditionCondition()

  class UnconditionalSequentialSteps(
    val reducers: ImmutableList<AbstractExecutionPlanStep>,
  ) : AbstractExecutionPlanStep() {

    init {
      require(reducers.size > 1) { reducers }
    }

    override fun toDefinition(): ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef {
      return ExecutionPlanYamlDefinition.SequenceDef(
        reducers = reducers.map { it.toDefinition() },
      )
    }
  }

  class AtomicReducerStep(
    val reducer: ReducerAnnotation,
    val actionBefore: () -> Unit,
  ) : AbstractExecutionPlanStep() {
    override fun toDefinition(): ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef {
      return ExecutionPlanYamlDefinition.AtomicReducerStepDef(
        reducer = reducer.shortName,
      )
    }
  }

  class IfProgressedThenStep(
    val condition: AbstractExecutionPlanStep,
    val then: AbstractExecutionPlanStep,
  ) : AbstractExecutionPlanStep() {
    override fun toDefinition(): ExecutionPlanYamlDefinition.IfProgressedThenStepDef {
      return ExecutionPlanYamlDefinition.IfProgressedThenStepDef(
        condition = condition.toDefinition(),
        then = then.toDefinition(),
      )
    }
  }

  companion object {

    fun fixpoint(
      continueCondition: AbstractConditionCondition = ContinueOnSmallSize.INSTANCE,
      body: () -> AbstractExecutionPlanStep,
    ): FixpointLoopStep {
      return FixpointLoopStep(body = body(), continueCondition = continueCondition)
    }

    fun ifProgressed(
      condition: AbstractExecutionPlanStep,
      then: () -> AbstractExecutionPlanStep,
    ): IfProgressedThenStep {
      return IfProgressedThenStep(
        condition = condition,
        then = then(),
      )
    }

    fun ifProgressed(
      condition: ReducerAnnotation,
      then: () -> AbstractExecutionPlanStep,
    ): IfProgressedThenStep {
      return ifProgressed(atomic(condition), then)
    }

    fun atomic(
      reducer: ReducerAnnotation,
      actionBefore: () -> Unit = {},
    ): AtomicReducerStep {
      return AtomicReducerStep(reducer, actionBefore)
    }
  }
}
