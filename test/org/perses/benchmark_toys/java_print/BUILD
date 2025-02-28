load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["Hello.java"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_Hello.java.txt",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "Hello.java",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_vulcan_and_auto_query_caching",
    enable_edit_caching = True,
    golden_progress_file = "golden_reduction_progress_with_vulcan_and_auto_query_caching.txt",
    golden_reduced_file = "golden_reduced_Hello_with_vulcan_and_auto_query_caching.java.txt",
    other_flags = {
        "--enable-vulcan": "true",
        "--code-format": "single_token_per_line",
    },
    progress_dump_file = "reduction_progress_with_vulcan_and_auto_query_caching.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "Hello.java",
    test_script = "r.sh",
)
