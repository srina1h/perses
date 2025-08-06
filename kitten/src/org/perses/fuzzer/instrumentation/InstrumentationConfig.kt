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
package org.perses.fuzzer.instrumentation

import com.google.common.collect.ImmutableSet

/**
 * Configuration for AST-based instrumentation of JavaScript programs
 * for differential fuzzing.
 */
data class InstrumentationConfig(
  val enabled: Boolean = false,
  val probeTypes: ProbeTypes = ProbeTypes(),
  val outputFormat: OutputFormat = OutputFormat.JSON,
  val probePrefix: String = "__PROBE_",
  val includeSourceLocation: Boolean = true,
  val maxProbesPerProgram: Int = 1000,
) {
  
  data class ProbeTypes(
    val typeProbing: Boolean = true,
    val structureProbing: Boolean = true,
    val floatProbing: Boolean = true,
    val promiseProbing: Boolean = true,
    val shortCircuitProbing: Boolean = true,
  ) {
    
    fun getEnabledProbes(): Set<ProbeType> {
      val probes = mutableSetOf<ProbeType>()
      if (typeProbing) probes.add(ProbeType.TYPE)
      if (structureProbing) probes.add(ProbeType.STRUCTURE)
      if (floatProbing) probes.add(ProbeType.FLOAT)
      if (promiseProbing) probes.add(ProbeType.PROMISE)
      if (shortCircuitProbing) probes.add(ProbeType.SHORT_CIRCUIT)
      return ImmutableSet.copyOf(probes)
    }
  }
  
  enum class OutputFormat {
    JSON,
    TEXT,
    COMPACT
  }
  
  enum class ProbeType {
    TYPE,
    STRUCTURE,
    FLOAT,
    PROMISE,
    SHORT_CIRCUIT
  }
  
  companion object {
    fun defaultConfig(): InstrumentationConfig {
      return InstrumentationConfig(
        enabled = true,
        probeTypes = ProbeTypes(),
        outputFormat = OutputFormat.JSON,
        probePrefix = "__PROBE_",
        includeSourceLocation = true,
        maxProbesPerProgram = 20
      )
    }
    
    fun minimalConfig(): InstrumentationConfig {
      return InstrumentationConfig(
        enabled = true,
        probeTypes = ProbeTypes(
          typeProbing = true,
          structureProbing = false,
          floatProbing = true,
          promiseProbing = false,
          shortCircuitProbing = false
        ),
        outputFormat = OutputFormat.JSON,
        probePrefix = "__PROBE_",
        includeSourceLocation = false,
        maxProbesPerProgram = 100
      )
    }
  }
} 