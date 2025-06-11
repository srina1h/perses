load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//:perses.bzl", "copy")

package(default_visibility = [
    "//visibility:public",
])

copy(
    name = "copy_default_llm_client_script",
    src = "//scripts/llm_scripts:llm_client.py",
    dest = "default_llm_client.py",
)

kt_jvm_library(
    name = "lpr",
    srcs = [
        "AbstractLLMBasedReducer.kt",
        "LLMBasedDataTypeEliminationReducer.kt",
        "LLMBasedDataTypeSimplificationReducer.kt",
        "LLMBasedFunctionInliningReducer.kt",
        "LLMBasedLoopUnrollingReducer.kt",
        "LLMBasedVariableEliminationReducer.kt",
        "LargeLanguageModel.kt",
    ],
    resources = [
        "default_llm_client.py",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reducer_context_interface",
        "//src/org/perses/spartree",
        "//src/org/perses/util:Serialization",
        "//src/org/perses/util/markdown",
    ],
)
