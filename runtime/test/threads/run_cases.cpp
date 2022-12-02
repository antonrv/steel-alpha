
module RunTestCases;

import SteelRT;

import App.Proxy;

import SteelRT.Test;


namespace ctxt {

template <>
void runner::run_case<case_id::initialize_finalize>() {

  std::string instrFn = std::string(argv[0]) + ".log";

  auto [entryCtxtUPtr, activeCtxtTuple] = ctxt::initialize<ctxt::entry_kind::stream, app::enabled_ids, plat::enabled_processors>(instrFn);

  ctxt::terminate( entryCtxtUPtr, activeCtxtTuple );
}

template <>
void runner::verify_case<case_id::initialize_finalize>() {

}

template <>
void runner::run_case<case_id::spawn_1>() { }

template <>
void runner::verify_case<case_id::spawn_1>() { }

template <>
void runner::run_case<case_id::spawn_2>() { }

template <>
void runner::verify_case<case_id::spawn_2>() { }

template <>
void runner::run_case<case_id::spawn_max>() { }

template <>
void runner::verify_case<case_id::spawn_max>() { }


template <>
void runner::run_case<case_id::spawn_1_run_depth_0>() {}

template <>
void runner::verify_case<case_id::spawn_1_run_depth_0>() {}

template <>
void runner::run_case<case_id::spawn_1_run_depth_1>() {}
template <>
void runner::verify_case<case_id::spawn_1_run_depth_1>() {}

template <>
void runner::run_case<case_id::spawn_1_run_depth_2>() {}
template <>
void runner::verify_case<case_id::spawn_1_run_depth_2>() {}

template <>
void runner::run_case<case_id::spawn_1_run_depth_max>() {}
template <>
void runner::verify_case<case_id::spawn_1_run_depth_max>() {}

template <>
void runner::run_case<case_id::spawn_2_run_depth_0>() {}
template <>
void runner::verify_case<case_id::spawn_2_run_depth_0>() {}

template <>
void runner::run_case<case_id::spawn_2_run_depth_1>() {}
template <>
void runner::verify_case<case_id::spawn_2_run_depth_1>() {}

template <>
void runner::run_case<case_id::spawn_2_run_depth_2>() {}
template <>
void runner::verify_case<case_id::spawn_2_run_depth_2>() {}

template <>
void runner::run_case<case_id::spawn_2_run_depth_max>() {}
template <>
void runner::verify_case<case_id::spawn_2_run_depth_max>() {}

template <>
void runner::run_case<case_id::spawn_max_run_depth_0>() {}
template <>
void runner::verify_case<case_id::spawn_max_run_depth_0>() {}

template <>
void runner::run_case<case_id::spawn_max_run_depth_1>() {}
template <>
void runner::verify_case<case_id::spawn_max_run_depth_1>() {}

template <>
void runner::run_case<case_id::spawn_max_run_depth_2>() {}
template <>
void runner::verify_case<case_id::spawn_max_run_depth_2>() {}

template <>
void runner::run_case<case_id::spawn_max_run_depth_max>() {}
template <>
void runner::verify_case<case_id::spawn_max_run_depth_max>() {}


} // namespace ctxt
