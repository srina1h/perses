load("//:perses.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

filegroup(
    name = "delta_3",
    srcs = [
        "r.sh",
        "t.c",
    ],
)

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_3_with_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_3_with_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_cache.c",
    reduction_algorithm = "ddmin",
    source_file = "t.c",
    statistics_file = "stat_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)

reduce(
    name = "reduce_delta_3_wo_caching",
    enable_edit_caching = False,
    enable_query_caching = False,
    log_file = "reduce_delta_3_without_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_without_cache.c",
    reduction_algorithm = "ddmin",
    source_file = "t.c",
    statistics_file = "stat_without_caching_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)

reduce(
    name = "reduce_delta_3_hdd_wo_caching",
    enable_edit_caching = False,
    enable_query_caching = False,
    log_file = "reduce_delta_3_hdd_without_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_hdd_without_cache.c",
    reduction_algorithm = "hdd",
    source_file = "t.c",
    statistics_file = "stat_hdd_without_caching_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)

reduce(
    name = "reduce_delta_3_pristine_hdd_wo_caching",
    enable_edit_caching = False,
    enable_query_caching = False,
    log_file = "reduce_delta_3_pristine_hdd_without_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_pristine_hdd_without_cache.c",
    reduction_algorithm = "pristine_hdd",
    source_file = "t.c",
    statistics_file = "stat_pristine_hdd_without_caching_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)

reduce(
    name = "reduce_delta_3_pristine_hdd_with_caching",
    enable_edit_caching = False,
    enable_query_caching = True,
    log_file = "reduce_delta_3_pristine_hdd_with_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_pristine_hdd_with_cache.c",
    reduction_algorithm = "pristine_hdd",
    source_file = "t.c",
    statistics_file = "stat_pristine_hdd_with_caching_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)

reduce(
    name = "reduce_delta_3_hdd_with_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_3_hdd_with_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_hdd_with_cache.c",
    reduction_algorithm = "hdd",
    source_file = "t.c",
    statistics_file = "stat_hdd_with_caching_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)
