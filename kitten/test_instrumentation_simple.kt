#!/usr/bin/env kotlin

@file:DependsOn("com.google.guava:guava:31.1-jre")
@file:DependsOn("com.google.flogger:flogger:0.7.4")
@file:DependsOn("com.fasterxml.jackson.core:jackson-core:2.15.2")

import org.perses.fuzzer.instrumentation.*
import org.perses.fuzzer.instrumentation.probes.*

fun main() {
    println("Testing improved instrumentation...")
    
    // Test with a simple JavaScript program
    val testCode = """
        let x = 42;
        let y = 3.14;
        let obj = { a: 1, b: 2 };
        let result = x && y;
        let sum = x + y;
    """.trimIndent()
    
    println("Input code:")
    println(testCode)
    println()
    
    // Create configuration
    val config = InstrumentationConfig(
        enabled = true,
        probeTypes = InstrumentationConfig.ProbeTypes(
            typeProbing = true,
            structureProbing = true,
            floatProbing = true,
            promiseProbing = false,
            shortCircuitProbing = true
        ),
        outputFormat = "json",
        probePrefix = "__PROBE_",
        includeSourceLocation = true,
        maxProbesPerProgram = 50
    )
    
    // Create instrumenter
    val instrumenter = JavaScriptInstrumenter(config)
    
    try {
        // Instrument the code
        val result = instrumenter.instrument(testCode)
        
        println("Instrumentation successful!")
        println("Generated ${result.probes.size} probes")
        println()
        
        // Show the instrumented code
        println("Instrumented code:")
        println(result.instrumentedCode)
        println()
        
        // Show probe statistics
        println("Probe statistics:")
        val typeProbes = result.probes.count { it is TypeProbe }
        val floatProbes = result.probes.count { it is FloatProbe }
        val shortCircuitProbes = result.probes.count { it is ShortCircuitProbe }
        
        println("  Type probes: $typeProbes")
        println("  Float probes: $floatProbes")
        println("  Short circuit probes: $shortCircuitProbes")
        println("  Total: ${result.probes.size}")
        
    } catch (e: Exception) {
        println("Error during instrumentation: ${e.message}")
        e.printStackTrace()
    }
} 