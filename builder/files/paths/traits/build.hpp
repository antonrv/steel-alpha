#ifndef STEEL_COMPILER_STATE_DIR_TRAITS_BUILD_HPP
#define STEEL_COMPILER_STATE_DIR_TRAITS_BUILD_HPP



namespace bld {

// BUILD_ROOT
template <> struct dir_traits<key_path::build_root> {
  static constexpr path_require value = path_require::create_force;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "-build";

  static constexpr key_path root = key_path::pwd;
  static constexpr const char * relative = "build/";
  //static constexpr key_path root = key_path::undefined;
};
// BUILD_ROOT/STD
template <> struct dir_traits<key_path::build_std> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_root;
  static constexpr const char * relative = "std/";
};
// BUILD_ROOT/RUNTIME
template <> struct dir_traits<key_path::build_runtime> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_root;
  static constexpr const char * relative = "runtime/";
};
// BUILD_ROOT/RUNTIME/AUTOGEN
template <> struct dir_traits<key_path::build_runtime_gen> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime;
  static constexpr const char * relative = "gen/";
};
// BUILD_ROOT/RUNTIME/PRECOMP
template <> struct dir_traits<key_path::build_runtime_precomp> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime;
  static constexpr const char * relative = "precomp/";
};

// BUILD_ROOT/RUNTIME/PRECOMP/ctxt
template <> struct dir_traits<key_path::build_runtime_precomp_ctxt> {
  static constexpr path_require value = path_require::none; // :: DEPRECATED
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "ctxt/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/data
template <> struct dir_traits<key_path::build_runtime_precomp_data> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "data/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/dep
template <> struct dir_traits<key_path::build_runtime_precomp_dep> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "dep/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/instrument
template <> struct dir_traits<key_path::build_runtime_precomp_instrument> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "instrument/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/policy
template <> struct dir_traits<key_path::build_runtime_precomp_policy> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "policy/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/safe
template <> struct dir_traits<key_path::build_runtime_precomp_safe> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "safe/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/task
template <> struct dir_traits<key_path::build_runtime_precomp_task> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "task/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/util
template <> struct dir_traits<key_path::build_runtime_precomp_util> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "util/";
};
// BUILD_ROOT/RUNTIME/PRECOMP/work
template <> struct dir_traits<key_path::build_runtime_precomp_work> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_precomp;
  static constexpr const char * relative = "work/";
};
// BUILD_ROOT/RUNTIME/TEST
template <> struct dir_traits<key_path::build_runtime_test> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime;
  static constexpr const char * relative = "test/";
};

// BUILD_ROOT/RUNTIME/TEST/CASE (to be defined from [-testcase] and [-build] options)
template <> struct dir_traits<key_path::build_runtime_test_case> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_test;
  static constexpr const char * relative = "UNDEFINED";
};

template <> struct dir_traits<key_path::build_runtime_test_case_inspect> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_test_case;
  static constexpr const char * relative = "inspect/";
};

template <> struct dir_traits<key_path::build_runtime_test_case_translate> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_test_case;
  static constexpr const char * relative = "translate/";
};

template <> struct dir_traits<key_path::build_runtime_test_case_autogen> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_test_case;
  static constexpr const char * relative = "generate/";
};

template <> struct dir_traits<key_path::build_runtime_test_case_precomp> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_test_case;
  static constexpr const char * relative = "precomp/";
};

template <> struct dir_traits<key_path::build_runtime_test_case_run> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_runtime_test_case;
  static constexpr const char * relative = "run/";
};


// BUILD_ROOT/BUILDER/TEST
template <> struct dir_traits<key_path::build_builder_test> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_root;
  static constexpr const char * relative = "builder_test/";
};

// BUILD_ROOT/BUILDER/TEST_SUITE_NAME
template <> struct dir_traits<key_path::build_builder_test_suite> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_builder_test;
  static constexpr const char * relative = "UNDEFINED";
};
// BUILD_ROOT/BUILDER/TEST_SUITE_NAME/INSPECT
template <> struct dir_traits<key_path::build_builder_test_suite_inspect> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_builder_test_suite;
  static constexpr const char * relative = "inspect/";
};
// BUILD_ROOT/BUILDER/TEST_SUITE_NAME/TRANSLATE
template <> struct dir_traits<key_path::build_builder_test_suite_translate> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_builder_test_suite;
  static constexpr const char * relative = "translate/";
};
// BUILD_ROOT/BUILDER/TEST_SUITE_NAME/AUTOGEN
template <> struct dir_traits<key_path::build_builder_test_suite_autogen> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_builder_test_suite;
  static constexpr const char * relative = "generate/";
};


// BUILD_ROOT/APP (to be defined from [-app] and [-build] options)
template <> struct dir_traits<key_path::build_app> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_root;
  static constexpr const char * relative = "UNDEFINED";
};

// BUILD_ROOT/APP/INSPECT
template <> struct dir_traits<key_path::build_app_inspect> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_app;
  static constexpr const char * relative = "inspect/";
};

// BUILD_ROOT/APP/TRANSLATE
template <> struct dir_traits<key_path::build_app_translate> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_app;
  static constexpr const char * relative = "translate/";
};

// BUILD_ROOT/APP/[my/app]/AUTOGEN
template <> struct dir_traits<key_path::build_app_autogen> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_app;
  static constexpr const char * relative = "generate/";
};

// BUILD_ROOT/APP/[my/app]/PRECOMP
template <> struct dir_traits<key_path::build_app_precomp> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_app;
  static constexpr const char * relative = "precomp/";
};

// BUILD_ROOT/APP/[my/app]/RUN
template <> struct dir_traits<key_path::build_app_run> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_app;
  static constexpr const char * relative = "run/";
};


// BUILD_ROOT/PLAT (to be defined from [-plat] and [-build] options)
template <> struct dir_traits<key_path::build_plat> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_root;
  static constexpr const char * relative = "UNDEFINED";
};

// BUILD_ROOT/PLAT/[my/plat]/AUTOGEN
template <> struct dir_traits<key_path::build_plat_autogen> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_plat;
  static constexpr const char * relative = "generate/";
};

// BUILD_ROOT/PLAT/[my/plat]/PRECOMP
template <> struct dir_traits<key_path::build_plat_precomp> {
  static constexpr path_require value = path_require::create;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::build_plat;
  static constexpr const char * relative = "precomp/";
};

} // namespace bld

#endif // STEEL_COMPILER_STATE_DIR_TRAITS_BUILD_HPP
