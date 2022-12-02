#ifndef STEEL_COMPILER_ELEMENT_INSPECTABLE_FILE_HPP
#define STEEL_COMPILER_ELEMENT_INSPECTABLE_FILE_HPP

#include "files/felement/base.hpp"

namespace bld {

// Something that can be transformed to a scanable_file
class inspectable_file : public base_felement {
private:

public:
  inspectable_file(const state::filename& fn) : base_felement(fn) {}
  inspectable_file(const state::filename& fn, std::filesystem::file_time_type ftt) : base_felement(fn, ftt) {}


//  virtual void set_yield(base_felement * yPtr) = 0;
};


} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_INSPECTABLE_FILE_HPP
