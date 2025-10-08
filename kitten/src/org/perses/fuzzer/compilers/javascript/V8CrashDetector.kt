package org.perses.fuzzer.compilers.javascript

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.ICompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor
import org.perses.util.shell.CmdOutput

class V8CrashDetector : AbstractCompilerCrashDetector() {
    
    // Override to add stricter filtering: require stderr output for crashes
    fun detectCrash(stderr: List<String>, exitCodeForCrash: Int): ICompilerCrashDetector.AbstractResult {
        require(exitCodeForCrash > 0) {
            "The exit code should be non-zero."
        }
        
        // If stderr is completely empty, this is likely not a real crash
        // V8 always produces some output when it crashes
        val hasStderr = stderr.any { it.isNotBlank() }
        if (!hasStderr) {
            return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
        }
        
        // Use parent class logic but with our strict signature detection
        val rawSignature = detectCrashSignatureFromStderr(stderr)
        val isCommonCrashExitCode = CommonCrashExitCodes.isCrashExitCode(exitCodeForCrash)
        
        // Only accept as crash if we found a crash signature
        // Don't accept crashes based on exit code alone - too many false positives
        if (rawSignature.isEmpty()) {
            return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
        }
        
        return ICompilerCrashDetector.AbstractResult.CrashResult.create(
            javaClass,
            exitCodeForCrash,
            rawSignature,
        )
    }
    
    override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
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
        
        return result.asSequence().filter { it.isNotBlank() }.map { it.trim() }.toList()
    }

    companion object {
        const val KEYWORD_FATAL_ERROR = "FATAL"
    }
} 