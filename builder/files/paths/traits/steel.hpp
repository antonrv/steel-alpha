#ifndef STEEL_COMPILER_STATE_DIR_TRAITS_STEEL_HPP
#define STEEL_COMPILER_STATE_DIR_TRAITS_STEEL_HPP



namespace bld {

template <key_path KP> struct dir_traits;

template <> struct dir_traits<key_path::steel_root> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "-steel";

  static constexpr key_path root = key_path::undefined;
};

template <> struct dir_traits<key_path::steel_runtime> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "-steel-runtime";

  static constexpr key_path root = key_path::steel_root;
  static constexpr const char * relative = "runtime/";
};

template <> struct dir_traits<key_path::steel_runtime_modules_ctxt> {
  static constexpr path_require value = path_require::none; // exist DEPRECATED
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "ctxt/";
};

// template <> struct dir_traits<key_path::steel_runtime_modules_data> {
//   static constexpr path_require value = path_require::exist;
//   static constexpr bool single = true;
//   static constexpr bool editable = false;
//   static constexpr const char * option = "";
// 
//   static constexpr key_path root = key_path::steel_runtime;
//   static constexpr const char * relative = "data/";
// };

template <> struct dir_traits<key_path::steel_runtime_modules_dep> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "dep/";
};

template <> struct dir_traits<key_path::steel_runtime_modules_instrument> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "instrument/";
};

template <> struct dir_traits<key_path::steel_runtime_modules_policy> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "policy/";
};

template <> struct dir_traits<key_path::steel_runtime_modules_safe> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "safe/";
};

template <> struct dir_traits<key_path::steel_runtime_modules_task> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "task/";
};

template <> struct dir_traits<key_path::steel_runtime_modules_util> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "util/";
};

template <> struct dir_traits<key_path::steel_runtime_modules_work> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "work/";
};

template <> struct dir_traits<key_path::steel_runtime_include> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "include/";
};

template <> struct dir_traits<key_path::steel_runtime_instrument> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "instrument/";
};

template <> struct dir_traits<key_path::steel_runtime_test> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::steel_runtime;
  static constexpr const char * relative = "test/";
};

template <> struct dir_traits<key_path::steel_runtime_test_case> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = "UNDEFINED";

  static constexpr key_path root = key_path::undefined;
  static constexpr const char * relative = "";
};

template <> struct dir_traits<key_path::steel_builder> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "-steel-builder";

  static constexpr key_path root = key_path::steel_root;
  static constexpr const char * relative = "builder/";
};

template <> struct dir_traits<key_path::steel_builder_test> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "-steel-builder-test";

  static constexpr key_path root = key_path::steel_builder;
  static constexpr const char * relative = "test/";
};

template <> struct dir_traits<key_path::steel_builder_test_suite> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = ""; // not meant to be set in cli

  static constexpr key_path root = key_path::steel_builder_test;
  static constexpr const char * relative = "UNDEFINED";
};

template <> struct dir_traits<key_path::steel_builder_test_suite_ref> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = ""; // not meant to be set in cli

  static constexpr key_path root = key_path::steel_builder_test_suite;
  static constexpr const char * relative = "TEST_REF/";
};

template <> struct dir_traits<key_path::steel_builder_test_suite_ref_inspect> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = ""; // not meant to be set in cli

  static constexpr key_path root = key_path::steel_builder_test_suite_ref;
  static constexpr const char * relative = "inspect/";
};

template <> struct dir_traits<key_path::steel_builder_test_suite_ref_translate> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = ""; // not meant to be set in cli

  static constexpr key_path root = key_path::steel_builder_test_suite_ref;
  static constexpr const char * relative = "translate/";
};

template <> struct dir_traits<key_path::steel_builder_test_suite_ref_autogen> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = true;
  static constexpr const char * option = ""; // not meant to be set in cli

  static constexpr key_path root = key_path::steel_builder_test_suite_ref;
  static constexpr const char * relative = "generate/";
};

} // namespace bld

#endif // STEEL_COMPILER_STATE_DIR_TRAITS_STEEL_HPP
