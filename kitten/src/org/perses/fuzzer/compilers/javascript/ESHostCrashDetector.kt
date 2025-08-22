package org.perses.fuzzer.compilers.javascript

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor

class ESHostCrashDetector : AbstractCompilerCrashDetector() {
    override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
        val result = ArrayList<String>()
        val sanitizerCrashDetector = SanitizerCrashSignatureExtractor()
        stderr.asSequence()
            .filter {
                it.isNotBlank() && it.contains(KEYWORD_FATAL_ERROR, ignoreCase = true)
            }
            .forEach {
                result.add(it)
            }
        result.addAll(sanitizerCrashDetector.extractCrashSignatureFromStderr(stderr))
        return result.asSequence().filter { it.isNotBlank() }.map { it.trim() }.toList()
    }

    /**
     * Override timeout detection to be more aggressive for ESHost.
     * ESHost is wrapped by timeout command, so exit code 137 (SIGKILL) 
     * should always be treated as timeout, not as OOM crash.
     */
    override fun isTimeoutExitCode(exitCode: Int, stderr: List<String>): Boolean {
        // For ESHost, always treat exit code 137 as timeout (from timeout -s 9 -k 1 command)
        if (exitCode == 137) {
            return true
        }
        
        // Also check for standard timeout exit code 124
        if (exitCode == 124) {
            return true
        }
        
        // For other exit codes, use the standard timeout detection logic
        return super.isTimeoutExitCode(exitCode, stderr)
    }

    companion object {
        const val KEYWORD_FATAL_ERROR = "FATAL"
    }
}
