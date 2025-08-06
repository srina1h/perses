import org.perses.fuzzer.instrumentation.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class TestInstrumentation {
    public static void main(String[] args) throws Exception {
        // Read the test file
        String sourceCode = new String(Files.readAllBytes(Paths.get("kitten/scripts/javascript/test_instrumentation.js")));
        
        // Create instrumentation config
        InstrumentationConfig config = InstrumentationConfig.Companion.defaultConfig();
        
        // Create instrumenter
        JavaScriptInstrumenter instrumenter = new JavaScriptInstrumenter(config);
        
        // Instrument the code
        String instrumentedCode = instrumenter.instrument(sourceCode);
        
        // Print the instrumented code
        System.out.println("=== INSTRUMENTED CODE ===");
        System.out.println(instrumentedCode);
        
        // Print statistics
        JavaScriptInstrumenter.InstrumentationStats stats = instrumenter.getInstrumentationStats();
        System.out.println("\n=== INSTRUMENTATION STATS ===");
        System.out.println("Enabled: " + stats.getEnabled());
        System.out.println("Probe types: " + stats.getProbeTypes());
        System.out.println("Max probes per program: " + stats.getMaxProbesPerProgram());
        
        System.out.println("\nInstrumentation test completed successfully!");
    }
}
