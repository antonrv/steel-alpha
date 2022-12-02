#include "source/token/piece.hpp"


namespace bld::src::pc {

///////////////// BASE


piece::piece() :
m_parent(nullptr)
{}

// Copy constructor does not copy the parent ptr, but leaves it as nullptr. WHY??? XXX
piece::piece(const piece& pc) :
m_parent(pc.m_parent)
{}


piece::~piece() {}

void piece::set_parent(cpiece_t pc) {
  m_parent = pc;
}

cpiece_t piece::get_parent() const {
  return m_parent;
}

std::string piece::get_kind_str() const {
  return util::enum_convert<kind>::to_string_rt(this->get_kind());
}



} // namespace bld::src::pc

