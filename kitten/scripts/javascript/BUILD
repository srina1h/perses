load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_binary")

kt_jvm_binary(
    name = "simple_instrumentation_test",
    srcs = ["simple_instrumentation_test.kt"],
    main_class = "Simple_instrumentation_testKt",
    deps = [
        "//kitten/src/org/perses/fuzzer/instrumentation",
    ],
) 