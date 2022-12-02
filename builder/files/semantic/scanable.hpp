#ifndef STEEL_COMPILER_ELEMENT_SCANABLE_FILE_HPP
#define STEEL_COMPILER_ELEMENT_SCANABLE_FILE_HPP

#include "files/felement/base.hpp"

namespace bld {

// Something that can be transformed to a dependent_file
class scanable_file : public base_felement {
protected:
public:
  scanable_file(const state::filename& fn) : base_felement(fn) {}
  scanable_file(const state::filename& fn, std::filesystem::file_time_type ftt) : base_felement(fn, ftt) {}

//  virtual void set_yield(base_felement * yPtr) = 0;
};


} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_SCANABLE_FILE_HPP
