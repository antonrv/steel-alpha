#ifndef STEEL_COMPILER_FELEMENT_DEF_HPP
#define STEEL_COMPILER_FELEMENT_DEF_HPP


#include "files/felement/decl.hpp"

namespace bld {

template <file_kind FK, code CodK>
using yield_t = typename felement<FK, CodK>::yield_ptr_type;

template <file_kind FK, code CodK>
felement<FK, CodK>::felement(const state::filename& fn) : super_type(fn) { }


template <file_kind FK, code CodK>
felement<FK, CodK>::felement(const state::filename& fn, std::filesystem::file_time_type ftt) : super_type(fn, ftt) { }

template <file_kind FK, code CodK>
void felement<FK, CodK>::set_yield(yield_t<FK, CodK> yPtr) {
  m_yieldPtr = yPtr;
}

template <file_kind FK, code CodK>
bool felement<FK, CodK>::has_yield() const {
  return m_yieldPtr != nullptr;
}

template <file_kind FK, code CodK>
const yield_t<FK, CodK> felement<FK, CodK>::get_yield() const {
  return m_yieldPtr;
}

template <file_kind FK, code CodK>
yield_t<FK, CodK> felement<FK, CodK>::get_yield() {
  return m_yieldPtr;
}

template <file_kind FK, code CodK>
cfileb_t felement<FK, CodK>::get_poly_yield() const {
  return static_cast<cfileb_t>( this->get_yield() );
}

} // namespace bld

#endif // STEEL_COMPILER_FELEMENT_DEF_HPP
