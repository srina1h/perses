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

import com.google.common.flogger.FluentLogger
import org.perses.fuzzer.instrumentation.probes.*
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import java.util.*

/**
 * Main instrumenter for JavaScript code that applies AST-based probes
 * for differential fuzzing.
 */
class JavaScriptInstrumenter(
  private val config: InstrumentationConfig
) {
  
  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
  
  private val astParser = JavaScriptASTParser()
  private val probeGenerator = ProbeGenerator(config)
  
  /**
   * Instrument JavaScript source code with probes.
   */
  fun instrument(sourceCode: String): String {
    if (!config.enabled) {
      logger.atFine().log("Instrumentation disabled, returning original code")
      return sourceCode
    }
    
    try {
      // Parse the source code into an AST
      val sparTree = astParser.parse(sourceCode)
      
      // Generate probes for the AST
      val probes = probeGenerator.generateProbes(sparTree)
      
      if (probes.isEmpty()) {
        logger.atFine().log("No probes generated, returning original code")
        return sourceCode
      }
      
      // Apply probes to generate instrumented code
      val instrumentedCode = applyProbes(sourceCode, probes)
      
      logger.atInfo().log("Successfully instrumented code with %d probes", probes.size)
      
      return instrumentedCode
      
    } catch (e: Exception) {
      logger.atWarning().withCause(e).log("Failed to instrument code, returning original")
      return sourceCode
    }
  }
  
  /**
   * Apply probes to the source code to generate instrumented code.
   */
  private fun applyProbes(sourceCode: String, probes: List<Probe>): String {
    val probeCode = probes.joinToString("\n") { it.generateProbeCode() }
    
    // Add probe runtime functions at the beginning
    val runtimeFunctions = generateRuntimeFunctions()
    
    // Combine original code with probe code, adding "use strict"; at the top
    return """
      "use strict";
      
      $runtimeFunctions
      
      // Original code
      $sourceCode
      
      // Probe code
      $probeCode
      
      // Output summary
      __PROBE_SUMMARY();
    """.trimIndent()
  }
  
  /**
   * Generate runtime functions that will be called by the probes.
   */
  private fun generateRuntimeFunctions(): String {
    return """
      // Structured output for differential testing
      let __PROBE_OUTPUT = [];
      
      // Polyfill for console.log and JSON.stringify for maximum compatibility across engines
      if (typeof console === 'undefined') {
        console = {};
      }
      if (typeof console.log !== 'function') {
        // Hermes and some shells: fallback to print if available, else no-op
        if (typeof print === 'function') {
          console.log = print;
        } else {
          console.log = function() {};
        }
      }
      if (typeof JSON === 'undefined') {
        JSON = {};
      }
      if (typeof JSON.stringify !== 'function') {
        JSON.stringify = function(obj) {
          try {
            return String(obj);
          } catch (e) {
            return '[unserializable]';
          }
        };
      }
      
      // Probe runtime functions
      function __PROBE_CAPTURE_VALUE(name, value) {
        const output = {
          type: "value_capture",
          name: name,
          value: value
        };
        __PROBE_OUTPUT.push(output);
        console.log(JSON.stringify(output));
      }
      
      function __PROBE_CAPTURE_TYPE(name, value) {
        const output = {
          type: "type_capture",
          name: name,
          value: value,
          typeOf: typeof value,
          constructor: value?.constructor?.name
        };
        __PROBE_OUTPUT.push(output);
        console.log(JSON.stringify(output));
      }
      
      function __PROBE_CONSTRUCTOR(name, constructor) {
        const output = {
          type: "constructor",
          name: name,
          constructor: constructor?.name
        };
        __PROBE_OUTPUT.push(output);
        console.log(JSON.stringify(output));
      }
      
      function __PROBE_PROTOTYPE_CHAIN(name, value) {
        const chain = [];
        let current = value;
        while (current && current !== Object.prototype) {
          chain.push(current.constructor?.name || 'Object');
          current = Object.getPrototypeOf(current);
        }
        const output = {
          type: "prototype_chain",
          name: name,
          chain: chain
        };
        __PROBE_OUTPUT.push(output);
        console.log(JSON.stringify(output));
      }
      
      function __PROBE_ENUMERATE_PROPERTIES(name, value) {
        if (typeof value === 'object' && value !== null) {
          const properties = Object.getOwnPropertyNames(value);
          const symbols = Object.getOwnPropertySymbols(value);
          const output = {
            type: "properties",
            name: name,
            properties: properties,
            symbols: symbols.map(s => s.toString())
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_ARRAY_INFO(name, value) {
        if (Array.isArray(value)) {
          const output = {
            type: "array_info",
            name: name,
            length: value.length,
            isArray: Array.isArray(value)
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_FUNCTION_INFO(name, value) {
        if (typeof value === 'function') {
          const output = {
            type: "function_info",
            name: name,
            functionName: value.name,
            length: value.length,
            toString: value.toString().substring(0, 100)
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_FLOAT_BINARY(name, value) {
        if (typeof value === 'number') {
          const buffer = new ArrayBuffer(8);
          const view = new DataView(buffer);
          view.setFloat64(0, value);
          const binary = Array.from(new Uint8Array(buffer))
            .map(b => b.toString(2).padStart(8, '0'))
            .join('');
          const output = {
            type: "float_binary",
            name: name,
            value: value,
            binary: binary
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_FLOAT_PRECISION(name, value) {
        if (typeof value === 'number') {
          const output = {
            type: "float_precision",
            name: name,
            value: value,
            toString: value.toString(),
            toFixed: value.toFixed(20),
            toExponential: value.toExponential()
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_FLOAT_COMPONENTS(name, value) {
        if (typeof value === 'number') {
          const buffer = new ArrayBuffer(8);
          const view = new DataView(buffer);
          view.setFloat64(0, value);
          const uint64 = view.getBigUint64(0);
          const sign = (uint64 >> 63n) & 1n;
          const exponent = (uint64 >> 52n) & 0x7FFn;
          const mantissa = uint64 & 0xFFFFFFFFFFFFFn;
          const output = {
            type: "float_components",
            name: name,
            value: value,
            sign: Number(sign),
            exponent: Number(exponent),
            mantissa: Number(mantissa)
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_FLOAT_SPECIAL_VALUES(name, value) {
        if (typeof value === 'number') {
          const output = {
            type: "float_special",
            name: name,
            value: value,
            isNaN: isNaN(value),
            isFinite: isFinite(value),
            isInteger: Number.isInteger(value)
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_FLOAT_ROUNDING(name, value) {
        if (typeof value === 'number') {
          const output = {
            type: "float_rounding",
            name: name,
            value: value,
            floor: Math.floor(value),
            ceil: Math.ceil(value),
            round: Math.round(value)
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_FLOAT_STRING_REPR(name, value) {
        if (typeof value === 'number') {
          const output = {
            type: "float_string",
            name: name,
            value: value,
            toString: value.toString(),
            toFixed: value.toFixed(),
            toExponential: value.toExponential(),
            toPrecision: value.toPrecision()
          };
          __PROBE_OUTPUT.push(output);
          console.log(JSON.stringify(output));
        }
      }
      
      function __PROBE_SHORT_CIRCUIT_EVAL(name, operator, leftEvaluated, rightEvaluated, leftValue, rightValue, result) {
        const output = {
          type: "short_circuit",
          name: name,
          operator: operator,
          leftEvaluated: leftEvaluated === 'true',
          rightEvaluated: rightEvaluated === 'true',
          leftValue: JSON.parse(leftValue),
          rightValue: JSON.parse(rightValue),
          result: JSON.parse(result)
        };
        __PROBE_OUTPUT.push(output);
        console.log(JSON.stringify(output));
      }
      
      // Output summary at the end
      function __PROBE_SUMMARY() {
        console.log(JSON.stringify({
          type: "summary",
          probeCount: __PROBE_OUTPUT.length,
          probes: __PROBE_OUTPUT
        }));
      }
    """.trimIndent()
  }
  
  /**
   * Get instrumentation statistics.
   */
  fun getInstrumentationStats(): InstrumentationStats {
    return InstrumentationStats(
      enabled = config.enabled,
      probeTypes = config.probeTypes.getEnabledProbes(),
      maxProbesPerProgram = config.maxProbesPerProgram
    )
  }
  
  /**
   * Statistics about the instrumentation process.
   */
  data class InstrumentationStats(
    val enabled: Boolean,
    val probeTypes: Set<InstrumentationConfig.ProbeType>,
    val maxProbesPerProgram: Int
  )
} 