#ifndef STEEL_COMPILER_ELEMENT_TARGET_FILE_HPP
#define STEEL_COMPILER_ELEMENT_TARGET_FILE_HPP


#include "files/semantic/bitcode.hpp"

namespace bld {

// A target file is an input of the link stage, intended to produce a final file - an executable or a library (dyn or static)
class target_file : public bitcode_file {
private:

  compilation_flags_t m_inputEffectsLink;

public:

  target_file(const state::filename& fn) : bitcode_file(fn) {}
  target_file(const state::filename& fn, std::filesystem::file_time_type ftt) : bitcode_file(fn, ftt) {}

  void add_in_effect_link(const std::string& lEff) {
    m_inputEffectsLink.push_back(lEff);
  }
  const compilation_flags_t& get_in_effects_link() const {
    return m_inputEffectsLink;
  }

};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_TARGET_FILE_HPP
