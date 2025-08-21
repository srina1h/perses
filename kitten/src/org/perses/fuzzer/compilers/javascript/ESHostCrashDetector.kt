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
    override fun detectCrash(stderr: List<String>, exitCodeForCrash: Int): 
        ICompilerCrashDetector.AbstractResult {
        require(exitCodeForCrash > 0) {
            "The exit code should be non-zero."
        }
        
        // For ESHost, treat exit code 137 as timeout (from timeout -s 9 command)
        if (exitCodeForCrash == 137) {
            return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
        }
        
        // Also check for standard timeout exit code 124
        if (exitCodeForCrash == 124) {
            return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
        }
        
        // For other exit codes, use the standard crash detection logic
        val rawSignature = detectCrashSignatureFromStderr(stderr)
        checkRawSignaturesAreInStdErr(rawSignature, stderr)
        val isCommonCrashExitCode = CommonCrashExitCodes.isCrashExitCode(exitCodeForCrash)
        if (rawSignature.isEmpty() && !isCommonCrashExitCode) {
            return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
        } else {
            return ICompilerCrashDetector.AbstractResult.CrashResult.create(
                javaClass,
                exitCodeForCrash,
                rawSignature,
            )
        }
    }

    companion object {
        const val KEYWORD_FATAL_ERROR = "FATAL"
    }
}
