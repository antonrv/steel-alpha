#include "link/base.hpp"
#include "files/interface.hpp"


namespace bld {

linker::linker() {}

template <>
void linker::run_all<code::entry>() {

  auto linkableEntries = state::files<file_kind::compiled>::get_raw<code::entry>();
  for (auto& fElemPtr : linkableEntries) {
    this->run_if_needed<code::entry>( fElemPtr );
  }
}


// // TODO LINKLIB
// template <>
// void linker::run_all<code::library>() {
// 
// }

} // namespace bld
