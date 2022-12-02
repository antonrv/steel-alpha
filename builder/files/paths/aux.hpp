#ifndef FILES_STATE_AUX_HPP
#define FILES_STATE_AUX_HPP


#include "files/paths/decl.hpp"

namespace bld::state {

template <key_path Path>
void remove_path_in_string(std::string& refStr) {

  auto erasePathStr = state::paths<Path>::get_path();
 
  for (auto iPos = refStr.find(erasePathStr); iPos != std::string::npos; iPos = refStr.find(erasePathStr)) {
    refStr.erase( iPos, erasePathStr.size() );
  }
}

bool is_valid_path(const std::string& pathFlag);

} // namespace bld::state

#endif // FILES_STATE_AUX_HPP
