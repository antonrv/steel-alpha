#ifndef STEEL_COMPILER_ELEMENT_MODIFIABLE_FILE_HPP
#define STEEL_COMPILER_ELEMENT_MODIFIABLE_FILE_HPP

#include "files/semantic/scanable.hpp"

#include <fstream>

namespace bld {

// Something in which readable content can be dumped
class modifiable_file : public scanable_file {
public:
  modifiable_file(const state::filename& fn) : scanable_file(fn) {}
  modifiable_file(const state::filename& fn, std::filesystem::file_time_type ftt) : scanable_file(fn, ftt) {}

  void dump_content(const std::string& filecontent) {
    {
      std::ofstream ofs(this->get_identifier(), std::ofstream::out | std::ofstream::trunc);
      ofs << filecontent;
    }
    return this->update_modification_time();
  }

//  virtual void set_yield(base_felement * yPtr) = 0;
};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_MODIFIABLE_FILE_HPP
