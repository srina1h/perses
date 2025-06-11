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

import com.fasterxml.jackson.annotation.JsonSubTypes
import com.fasterxml.jackson.annotation.JsonTypeInfo
import com.fasterxml.jackson.core.type.TypeReference
import com.fasterxml.jackson.dataformat.yaml.YAMLGenerator
import org.perses.util.Serialization

class ExecutionPlanYamlDefinition {

  @JsonTypeInfo(
    use = JsonTypeInfo.Id.NAME,
    include = JsonTypeInfo.As.PROPERTY,
    property = "type",
  )
  @JsonSubTypes(
    JsonSubTypes.Type(value = FixpointLoopStepDef::class, name = "fixpoint"),
    JsonSubTypes.Type(value = SequenceDef::class, name = "sequence"),
    JsonSubTypes.Type(value = AtomicReducerStepDef::class, name = "atomic"),
    JsonSubTypes.Type(value = IfProgressedThenStepDef::class, name = "if"),
  )
  sealed class AbstractExecutionPlanStepDef {

    fun toYamlString(): String {
      return Serialization.toYamlString(
        value = this,
        yamlFactoryCustomizer = { factory ->
          factory.enable(YAMLGenerator.Feature.USE_NATIVE_TYPE_ID)
            .enable(YAMLGenerator.Feature.MINIMIZE_QUOTES)
        },
      )
    }

    companion object {
      fun fromYamlString(yaml: String): AbstractExecutionPlanStepDef {
        return Serialization.fromYamlString(
          yaml,
          typeReference = object : TypeReference<AbstractExecutionPlanStepDef>() {},
        )
      }
    }
  }

  class FixpointLoopStepDef(
    val body: AbstractExecutionPlanStepDef,
    val condition: String,
  ) : AbstractExecutionPlanStepDef()

  class SequenceDef(
    val reducers: List<AbstractExecutionPlanStepDef>,
  ) : AbstractExecutionPlanStepDef()

  class AtomicReducerStepDef(
    val reducer: String,
  ) : AbstractExecutionPlanStepDef()

  class IfProgressedThenStepDef(
    val condition: AbstractExecutionPlanStepDef,
    val then: AbstractExecutionPlanStepDef,
  ) : AbstractExecutionPlanStepDef()
}
