#ifndef STEEL_COMPILER_STATE_DIR_TRAITS_CORE_HPP
#define STEEL_COMPILER_STATE_DIR_TRAITS_CORE_HPP



namespace bld {

template <> struct dir_traits<key_path::undefined> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::undefined;
  static constexpr const char * relative = "";
};

template <> struct dir_traits<key_path::pwd> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = true;
  static constexpr bool editable = false;
  static constexpr const char * option = "";

  static constexpr key_path root = key_path::undefined;
  static constexpr const char * relative = "";
};

template <> struct dir_traits<key_path::user_include> {
  static constexpr path_require value = path_require::exist;
  static constexpr bool single = false;
  static constexpr bool editable = false;
  static constexpr const char * option = "-include";

  static constexpr key_path root = key_path::undefined;
  static constexpr const char * relative = "";
};

} // namespace bld

#endif // STEEL_COMPILER_STATE_DIR_TRAITS_CORE_HPP
