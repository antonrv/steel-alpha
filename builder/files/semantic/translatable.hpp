#ifndef STEEL_COMPILER_ELEMENT_TRANSLATABLE_FILE_HPP
#define STEEL_COMPILER_ELEMENT_TRANSLATABLE_FILE_HPP

#include "files/felement/base.hpp"

namespace bld {

// Something that can be transformed to a scanable_file
class translatable_file : public base_felement {
private:
public:
  translatable_file(const state::filename& fn) : base_felement(fn) {}
  translatable_file(const state::filename& fn, std::filesystem::file_time_type ftt) : base_felement(fn, ftt) {}

};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_TRANSLATABLE_FILE_HPP
