load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "JavaParserFacadeTest",
    srcs = ["JavaParserFacadeTest.kt"],
    test_class = "org.perses.grammar.java.JavaParserFacadeTest",
    deps = [
        "//:truth",
        "//src/org/perses/grammar/java:orig_parser_facade_java8",
        "//src/org/perses/grammar/java:parser_facade_java8",
    ],
)
