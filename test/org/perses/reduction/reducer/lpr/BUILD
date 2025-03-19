load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_test(
    name = "LLMOutputUtilTest",
    srcs = [
        "LLMOutputUtilTest.kt",
    ],
    associates = [
        "//src/org/perses/reduction/reducer/lpr",
    ],
    deps = [
        "//:truth",
        "//test/org/perses:test_util",
    ],
)
