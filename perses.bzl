load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_library",
)

def copy(name, src, dest):
    native.genrule(
        name = name,
        outs = [
            dest,
        ],
        srcs = [
            src,
        ],
        cmd = "cp $< $@",
    )

def kt_binary_for_genrule(
        name,
        srcs,
        main_class,
        deps,
        data = None,
        jvm_flags = None,
        args = None):
    lib_name = "kt_aux_lib_" + name
    if not data:
        data = []
    kt_jvm_library(
        name = lib_name,
        srcs = srcs,
        deps = deps,
        data = data,
    )
    if not jvm_flags:
        jvm_flags = []
    if not args:
        args = []
    native.java_binary(
        name = name,
        main_class = main_class,
        runtime_deps = [
            lib_name,
        ],
        jvm_flags = jvm_flags,
        args = args,
    )

DEFAULT_PERSES_BIN = "//src/org/perses:perses"
DEFAULT_MAIN_REDUCTION_ALGORITHM = "perses_node_priority_with_dfs_delta"

def reduce(
        name,
        reduction_algorithm,
        source_file,
        test_script,
        output_dir = None,
        names_of_other_files_in_output_dir = None,
        enable_query_caching = None,
        enable_edit_caching = None,
        statistics_file = None,
        progress_dump_file = None,
        thread_count = None,
        verbosity = None,
        log_file = None,
        call_formatter = None,
        query_cache_type = None,
        other_flags = None,
        extra_output_files = None,
        delta_debugger_profile = None,
        perses_bin = DEFAULT_PERSES_BIN,
        cmd_deps = None,
        deps = None):
    if "/" in source_file:
        fail("The source file should be in the current folder.")
    if "/" in test_script:
        fail("The test script should be in the current folder.")
    if output_dir == None and names_of_other_files_in_output_dir != None:
        fail("output_dir cannot be None if names_of_other_files_in_output_dir is not None.")

    thread_count = thread_count or 1  # for determinism
    stdout_file = "%s.stdout.txt" % name

    args = [
        "$(location %s)" % perses_bin,
        "--test-script $(location %s)" % test_script,
        "--input-file $(location %s)" % source_file,
        "--alg %s" % reduction_algorithm,
        "--threads %s" % thread_count,
        "--fixpoint true",
    ]
    outs = []
    if enable_query_caching != None:
        args.append("--query-caching %s" % ("true" if enable_query_caching else "false"))
    if enable_edit_caching != None:
        args.append("--edit-caching %s" % ("true" if enable_edit_caching else "false"))
    if call_formatter != None:
        args.append("--call-formatter %s" % ("true" if call_formatter else "false"))
    if query_cache_type:
        args.append("--query-cache-type %s" % query_cache_type)
    if progress_dump_file:
        args.append("--progress-dump-file $(location %s)" % progress_dump_file)
        outs.append(progress_dump_file)
    if statistics_file:
        args.append("--stat-dump-file $(location %s)" % statistics_file)
        outs.append(statistics_file)
    if delta_debugger_profile:
        args.append("--profile-delta-debugger $(location %s)" % delta_debugger_profile)
        outs.append(delta_debugger_profile)

    if output_dir != None:
        main_result_file = "%s/%s" % (output_dir, source_file)
        args.append("--output-dir $$(dirname $(location %s))" % main_result_file)
        outs.append(main_result_file)
        if names_of_other_files_in_output_dir:
            for file_name in names_of_other_files_in_output_dir:
                outs.append("%s/%s" % (output_dir, file_name))

    if verbosity:
        args.append("--verbosity %s" % verbosity)

    if other_flags:
        for (key, value) in other_flags.items():
            args.append(key)
            args.append(value)
    if extra_output_files:
        outs += extra_output_files

    if log_file:
        args.append("&>")
        args.append("$(location %s)" % log_file)
        outs.append(log_file)
    else:
        args.append("&>")
        args.append("$(location %s)" % stdout_file)
        outs.append(stdout_file)

    srcs = [source_file, test_script]

    if cmd_deps:  # The flags --deps
        srcs.append(cmd_deps)
        args.append("--deps $(location %s)" % cmd_deps)
    if deps:  # This is the general deps which do not require to be specified in --deps
        srcs += deps
    native.genrule(
        name = name,
        outs = outs,
        srcs = srcs,
        tools = [perses_bin],
        cmd = " ".join(args),
    )
