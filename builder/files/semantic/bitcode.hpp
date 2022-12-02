#ifndef STEEL_COMPILER_ELEMENT_BITCODE_FILE_HPP
#define STEEL_COMPILER_ELEMENT_BITCODE_FILE_HPP


#include "files/felement/base.hpp"


namespace bld {

enum class code : std::size_t;

class bitcode_file : public base_felement {
protected:

  using compilation_flags_t = std::vector<std::string>;

private:

  compilation_flags_t m_inputEffects;
  compilation_flags_t m_outputEffects;

public:

  bitcode_file(const state::filename& fn) : base_felement(fn) {}
  bitcode_file(const state::filename& fn, std::filesystem::file_time_type ftt) : base_felement(fn, ftt) {}

  void reset_in_effects(const compilation_flags_t& inEff) {
    m_inputEffects = inEff;
  }

  bool same_in_effects(const compilation_flags_t& inEff) const {
    return m_inputEffects == inEff;
  }

  const compilation_flags_t& get_out_effects() const {
    return m_outputEffects;
  }

  void reset_out_effects() {
    m_outputEffects = compilation_flags_t();
  }

  template <code CodK>
  void add_out_effect();
};


} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_BITCODE_FILE_HPP
