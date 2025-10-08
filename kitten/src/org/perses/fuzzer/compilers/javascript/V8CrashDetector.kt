package org.perses.fuzzer.compilers.javascript

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor

class V8CrashDetector : AbstractCompilerCrashDetector() {
    
    override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
        // STRICT FILTERING: Only return signatures if stderr is non-empty
        // V8 always produces output when it crashes - if stderr is empty, it's not a crash
        val hasStderr = stderr.any { it.isNotBlank() }
        if (!hasStderr) {
            // Return empty list - base class will treat this as non-crash
            return emptyList()
        }
        
        val result = ArrayList<String>()
        val sanitizerCrashDetector = SanitizerCrashSignatureExtractor()
        
        // Look for V8-specific crash indicators
        // We are VERY strict here to avoid false positives
        stderr.asSequence()
            .filter {
                it.isNotBlank() && (
                    // V8 internal crashes
                    it.contains("# Fatal error", ignoreCase = false) ||
                    it.contains("FATAL ERROR", ignoreCase = false) ||
                    it.contains("Check failed", ignoreCase = false) ||
                    it.contains("UNREACHABLE", ignoreCase = false) ||
                    it.contains("DCHECK", ignoreCase = false) ||
                    // Assertions
                    it.contains("Assertion failed", ignoreCase = false) ||
                    // Signals (segfaults, etc.)
                    it.contains("Received signal", ignoreCase = false) ||
                    it.contains("Illegal instruction", ignoreCase = false) ||
                    // Stack traces indicating crashes
                    it.contains("==== C stack trace", ignoreCase = false) ||
                    it.contains("==== JS stack trace", ignoreCase = false)
                )
            }
            .forEach {
                result.add(it)
            }
        
        // Also check for sanitizer crashes (ASAN, UBSAN, etc.)
        result.addAll(sanitizerCrashDetector.extractCrashSignatureFromStderr(stderr))
        
        // Final check: if we found no signatures, return empty to indicate non-crash
        // This means we won't accept crashes based on exit code alone
        return result.asSequence().filter { it.isNotBlank() }.map { it.trim() }.toList()
    }

    companion object {
        const val KEYWORD_FATAL_ERROR = "FATAL"
    }
} 