#!/usr/bin/env bash

set -o pipefail
set -o nounset

if [[ "$@" == *"--version"* ]]; then
  echo "rustc mock 1"
  exit 0
fi

cat 1>&2 <<- EOF
thread 'rustc' panicked at 'cannot use the \`#[rustc_if_this_changed]\` or \`#[rustc_then_this_would_need]\` annotations without supplying \`-Z query-dep-graph\`', compiler/rustc_incremental/src/assert_dep_graph.rs:77:13
stack backtrace:
   0: rust_begin_unwind
             at /rustc/7f7a1cbfd3b55daee191247770627afab09eece2/library/std/src/panicking.rs:483
   1: std::panicking::begin_panic_fmt
             at /rustc/7f7a1cbfd3b55daee191247770627afab09eece2/library/std/src/panicking.rs:437
   2: rustc_middle::dep_graph::<impl rustc_query_system::dep_graph::DepKind for rustc_middle::dep_graph::dep_node::DepKind>::with_deps
   3: rustc_incremental::assert_dep_graph::assert_dep_graph
   4: rustc_session::utils::<impl rustc_session::session::Session>::time
   5: rustc_codegen_ssa::base::finalize_tcx
   6: rustc_codegen_ssa::base::codegen_crate
   7: <rustc_codegen_llvm::LlvmCodegenBackend as rustc_codegen_ssa::traits::backend::CodegenBackend>::codegen_crate
   8: rustc_interface::passes::QueryContext::enter
   9: rustc_interface::queries::Queries::ongoing_codegen
  10: rustc_interface::queries::<impl rustc_interface::interface::Compiler>::enter
  11: rustc_span::with_source_map
  12: rustc_interface::interface::create_compiler_and_run
  13: scoped_tls::ScopedKey<T>::set
note: Some details are omitted, run with \`RUST_BACKTRACE=full\` for a verbose backtrace.

error: internal compiler error: unexpected panic

note: the compiler unexpectedly panicked. this is a bug.

note: we would appreciate a bug report: https://github.com/rust-lang/rust/issues/new?labels=C-bug%2C+I-ICE%2C+T-compiler&template=ice.md

note: rustc 1.48.0-nightly (7f7a1cbfd 2020-09-27) running on x86_64-unknown-linux-gnu

note: compiler flags: --crate-type staticlib

query stack during panic:
end of query stack
EOF

exit 1
