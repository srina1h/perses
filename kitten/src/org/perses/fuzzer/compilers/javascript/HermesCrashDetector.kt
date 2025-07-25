package org.perses.fuzzer.compilers.javascript

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor

class HermesCrashDetector : AbstractCompilerCrashDetector() {
    override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
        val result = ArrayList<String>()
        val sanitizerCrashDetector = SanitizerCrashSignatureExtractor()
        stderr.asSequence()
            .filter {
                it.isNotBlank() && it.contains(KEYWORD_FATAL_ERROR)
            }
            .forEach {
                result.add(it)
            }
        result.addAll(sanitizerCrashDetector.extractCrashSignatureFromStderr(stderr))
        return result.asSequence().filter { it.isNotBlank() }.map { it.trim() }.toList()
    }

    companion object {
        const val KEYWORD_FATAL_ERROR = "fatal"
    }
} 