package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "instrumentation",
    srcs = glob([
        "*.kt",
        "probes/*.kt",
    ]),
    deps = [
        "//:flogger",
        "//:guava",
        "//:jackson",
        "//src/org/perses/grammar/javascript:parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
    ],
) 