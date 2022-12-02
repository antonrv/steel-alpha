#include "files/semantic/bitcode.hpp"

#include "files/enum.hpp"

namespace bld {

template <>
void bitcode_file::add_out_effect<code::interface>() {
  m_outputEffects.push_back("-fmodule-file=" + this->get_identifier());
}

template <>
void bitcode_file::add_out_effect<code::implementation>() {
  m_outputEffects.push_back(this->get_identifier());
}

template <>
void bitcode_file::add_out_effect<code::entry>() {
  m_outputEffects.push_back(this->get_identifier());
}

} // namespace bld
