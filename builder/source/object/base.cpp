#include "source/object/base.hpp"

#include <sstream>

namespace bld::src {

static const char * SyntheticCharOpen = "_<<";
static const char * SyntheticCharClose = ">>";

// static unsigned SyntheticSourceElementCounter = 0;


sobject_base::~sobject_base() {}

const object_id_t& sobject_base::get_identifier() const {
  return m_identifier;
}



void sobject_base::set_source_filename() {

  auto thisIdentifier = this->get_identifier();

  // Assumed clang format as <fullFilename:1:2, 3:4>

  auto firstBracketPos = thisIdentifier.find('<');
  auto firstColonPos = thisIdentifier.find(':');
  if (firstBracketPos == std::string::npos or firstColonPos == std::string::npos) {
    throw std::logic_error("Could not get_identifier_filename from " + this->get_identifier());
  }

  auto strFilename = thisIdentifier.substr(firstBracketPos + 1, firstColonPos - firstBracketPos - 1);

  m_filename = state::find_filename( strFilename );
}

state::filename sobject_base::get_source_filename() const {
  return m_filename;
}


bool sobject_base::is_synthetic() const {
  const auto& idStr = this->m_identifier;
  return (idStr.find(SyntheticCharOpen) != std::string::npos and idStr.find(SyntheticCharClose) != std::string::npos);
}

bool sobject_base::contains(const sobject_base * srcLoc) const {
  return (not srcLoc->is_synthetic()) and (not this->is_synthetic()) and this->get_source_filename() == srcLoc->get_source_filename() and this->m_begin <= srcLoc->m_begin and srcLoc->m_end <= this->m_end;
}

bool sobject_base::is_before(const sobject_base * srcLoc) const {

  if (srcLoc->is_synthetic() or this->is_synthetic()) {
    throw std::logic_error("sobject_base:: Could not is_before : src-objects cannot be synthetic");
  }
  if (this->get_source_filename() != srcLoc->get_source_filename()) {
    throw std::logic_error("sobject_base:: Could not is_before : src-objects belonging to different files");
  }
  return this->m_begin < srcLoc->m_begin;
}

const std::string& sobject_base::get_data() const {
  return m_data;
}

void sobject_base::print(std::ostream& os) const {

  os << "\nSObj ID : " << this->get_identifier() << ". Kind :" << this->get_obj() << '\n';//  << " DATA : \n" << this->get_data() << '\n';
}


bool compare_base_source_objects::operator() (csob_t lhs, csob_t rhs) const {
  if (lhs == nullptr) { throw std::logic_error("Could not compare base source objects. Lhs is nullptr"); }
  if (rhs == nullptr) { throw std::logic_error("Could not compare base source objects. Rhs is nullptr"); }
  return lhs->get_identifier() < rhs->get_identifier();
}


} // namespace bld::src

std::ostream& operator<<(std::ostream& os, const bld::src::sobject_base& elem) {
  elem.print(os);
  return os;
}
