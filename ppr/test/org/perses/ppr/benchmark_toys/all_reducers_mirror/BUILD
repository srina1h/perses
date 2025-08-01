load("//benchmark:benchmark.bzl", "sanity_test")
load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")

PPR_REDUCER_BIN = "//ppr/src/org/perses/ppr:main"

sanity_test(
    name = "sanity_test",
    source_files = [
        "seed.c",
        "variant.c",
    ],
    test_script = "r.sh",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_all_reducers_mirror",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_progress.txt",
    golden_reduced_seed_file = "golden_reduced_seed.c",
    golden_reduced_variant_file = "golden_reduced_variant.c",
    log_file = "reduction_golden_test.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "true",
        "--min-commonality": "true",
        "--enable-mirror": "true",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
        "--append-to-progress-dump-file": "true",
    },
    perses_bin = PPR_REDUCER_BIN,
    progress_dump_file = "progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

sh_test(
    name = "check_fixpoint_iterations_are_printed",
    srcs = ["ppr_reduction_log_test.sh"],
    args = [
        "$(location reduction_golden_test.log)",
    ],
    data = ["reduction_golden_test.log"],
)
