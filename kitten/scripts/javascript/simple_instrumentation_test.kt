import org.perses.fuzzer.instrumentation.*

fun main() {
    println("Testing JavaScript instrumentation...")
    
    // Test source code
    val sourceCode = """
        // Test file for instrumentation
        let x = 0.1 + 0.2;
        let y = {a: 1, b: "test"};
        let z = true && false;
        console.log(x, y, z);
    """.trimIndent()
    
    println("Original code:")
    println(sourceCode)
    println()
    
    // Create instrumentation config
    val config = InstrumentationConfig.defaultConfig()
    
    // Create instrumenter
    val instrumenter = JavaScriptInstrumenter(config)
    
    // Instrument the code
    val instrumentedCode = instrumenter.instrument(sourceCode)
    
    println("=== INSTRUMENTED CODE ===")
    println(instrumentedCode)
    
    // Print statistics
    val stats = instrumenter.getInstrumentationStats()
    println("\n=== INSTRUMENTATION STATS ===")
    println("Enabled: ${stats.enabled}")
    println("Probe types: ${stats.probeTypes}")
    println("Max probes per program: ${stats.maxProbesPerProgram}")
    
    println("\nInstrumentation test completed successfully!")
} 