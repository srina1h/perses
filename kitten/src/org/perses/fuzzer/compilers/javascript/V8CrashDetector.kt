package org.perses.fuzzer.compilers.javascript

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor

class V8CrashDetector : AbstractCompilerCrashDetector() {
    
    override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
        val result = ArrayList<String>()
        val sanitizerCrashDetector = SanitizerCrashSignatureExtractor()
        
        // Look for V8-specific crash indicators
        // Note: We intentionally look for specific crash patterns to avoid false positives
        // from normal errors (syntax errors, timeouts, etc.)
        stderr.asSequence()
            .filter {
                it.isNotBlank() && (
                    it.contains(KEYWORD_FATAL_ERROR, ignoreCase = true) ||
                    it.contains("Check failed", ignoreCase = false) ||
                    it.contains("UNREACHABLE", ignoreCase = false) ||
                    it.contains("Assertion", ignoreCase = false) ||
                    it.contains("Received signal", ignoreCase = false)
                )
            }
            .forEach {
                result.add(it)
            }
        
        // Also check for sanitizer crashes (ASAN, UBSAN, etc.)
        result.addAll(sanitizerCrashDetector.extractCrashSignatureFromStderr(stderr))
        
        return result.asSequence().filter { it.isNotBlank() }.map { it.trim() }.toList()
    }

    companion object {
        const val KEYWORD_FATAL_ERROR = "FATAL"
    }
} 