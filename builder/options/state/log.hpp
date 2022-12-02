#ifndef OPTIONS_STATE_LOG_DEF_HPP
#define OPTIONS_STATE_LOG_DEF_HPP

#include "options/state/decl.hpp"

#include <iostream>
#include <vector>
#include <set>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << '\n';
  for (auto& elm : vec) {
    os << '\t' << elm << '\n';
  }
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  os << '\n';
  for (auto& elm : st) {
    os << '\t' << elm << '\n';
  }
  return os;
}

namespace bld::state {

template <opt_kind OptKind, typename... Ts>
void log_if( typename otraits<OptKind>::value_type reqVal, Ts&&... printArgs ) {

  if (state::options::is_set<OptKind>() and state::options::get_value<OptKind>() == reqVal) {
    std::cout  << OptKind << " ::: ";
    ((std::cout << printArgs << " "), ...);
    std::cout << '\n';
  } else {
    // Don't print anything
  }
}

template <opt_kind OptKind, typename... Ts>
void log( Ts&&... printArgs ) {

  if constexpr ( std::is_same_v<typename otraits<OptKind>::value_type, bool> ) {

    if (state::options::is_set<OptKind>()) {

      std::cout  << OptKind << " ::: ";
      ((std::cout << printArgs << " "), ...);
      std::cout << '\n';
    }

  } else {
    // eg value_type is a string. Do nothing. log_if must be called directly
  }
}

} // namespace bld::state

#endif // OPTIONS_STATE_LOG_DEF_HPP
