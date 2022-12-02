#ifndef STEEL_COMPILER_STATE_PATHS_DIR_HPP
#define STEEL_COMPILER_STATE_PATHS_DIR_HPP

#include "files/paths/traits/interface.hpp"

#include <string>
#include <filesystem>
#include <tuple>

namespace bld {


template <path_require PR>
void satisfy(std::string dirStr);


template <key_path KP>
class dir {
private:
  std::string m_name;
public:
  dir(){}

  bool is_set() const {
    return not m_name.empty();
  }

  std::string get() const {
    if (m_name.empty()) {
      if constexpr (KP == key_path::undefined) {
        return "undefined_path";
      } else {
        throw std::runtime_error("Empty path. Set first " + std::string(util::enum_convert<key_path>::to_string<KP>()));
      }
    }
    satisfy<dir_traits<KP>::value>(m_name);
    return m_name;
  }

  void set(std::string s) {
    if (not m_name.empty()) {
      if (s == m_name) {
        return;
      } else {
        if constexpr (not dir_traits<KP>::editable) {
          throw std::runtime_error("Path already set and different on non editable path : " + std::string(util::enum_convert<key_path>::to_string<KP>()) + ". original: " + m_name + ", received: " + s);
        } else {
          // Editable, let it change
        }
      }
    }
    satisfy<dir_traits<KP>::value>(s);
    m_name = s;
  }

  void add(const std::string& s) {
    // static_assert(not dir_traits<KP>::single);
    if constexpr (dir_traits<KP>::single) {
      throw std::runtime_error("Could not add to path : " + std::string(util::enum_convert<key_path>::to_string<KP>()) + ". Unique path allowed");
    }
    satisfy<dir_traits<KP>::value>(s);
    m_name += ";" + s;
  }
};

} // namespace bld

#endif // STEEL_COMPILER_STATE_PATHS_DIR_HPP
