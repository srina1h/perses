package org.perses.fuzzer.compilers.javascript

import org.perses.fuzzer.compilers.AbstractCompilerCrashDetector
import org.perses.fuzzer.compilers.ICompilerCrashDetector
import org.perses.fuzzer.compilers.SanitizerCrashSignatureExtractor
import org.perses.util.shell.CmdOutput

class V8CrashDetector : AbstractCompilerCrashDetector() {
    
    override fun detectCrash(cmdOutput: CmdOutput): ICompilerCrashDetector.AbstractResult {
        // Filter out timeouts and non-crash errors
        val exitCode = cmdOutput.exitCode.intValue
        
        // Exit code 0 = success
        if (exitCode == 0) {
            return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
        }
        
        // Common timeout exit codes - NOT crashes
        if (exitCode == 124 || exitCode == 143 || exitCode == 137) {
            return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
        }
        
        // Exit code 1 is usually just a normal error (syntax error, etc.) - NOT a crash
        // unless there's a FATAL error message
        if (exitCode == 1) {
            val stderr = cmdOutput.stderr.combinedLines
            val hasFatalError = stderr.contains("FATAL", ignoreCase = true) ||
                                stderr.contains("Check failed", ignoreCase = false) ||
                                stderr.contains("UNREACHABLE", ignoreCase = false)
            if (!hasFatalError) {
                return ICompilerCrashDetector.AbstractResult.NonCrashResult(javaClass)
            }
        }
        
        // Use base class logic for actual crashes
        return super.detectCrash(cmdOutput)
    }
    
    override fun detectCrashSignatureFromStderr(stderr: List<String>): List<String> {
        val result = ArrayList<String>()
        val sanitizerCrashDetector = SanitizerCrashSignatureExtractor()
        
        // Look for V8-specific crash indicators
        stderr.asSequence()
            .filter {
                it.isNotBlank() && (
                    it.contains(KEYWORD_FATAL_ERROR, ignoreCase = true) ||
                    it.contains("Check failed", ignoreCase = false) ||
                    it.contains("UNREACHABLE", ignoreCase = false) ||
                    it.contains("Assertion", ignoreCase = false)
                )
            }
            .forEach {
                result.add(it)
            }
        
        // Also check for sanitizer crashes
        result.addAll(sanitizerCrashDetector.extractCrashSignatureFromStderr(stderr))
        
        return result.asSequence().filter { it.isNotBlank() }.map { it.trim() }.toList()
    }

    companion object {
        const val KEYWORD_FATAL_ERROR = "FATAL"
    }
} 