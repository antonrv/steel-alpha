#include "files/felement/base.hpp"

#include "files/paths/decl.hpp"
#include "files/name/decl.hpp"


namespace bld {

base_felement::base_felement(const state::filename& fn) :
  m_identifier(fn.get_full_name()),
  m_filename(fn)
{}

base_felement::base_felement(const state::filename& fn, std::filesystem::file_time_type ftt) :
  m_identifier(fn.get_full_name()),
  m_filename(fn),
  m_lastModificationTime(ftt)
{}

base_felement::~base_felement() {}

const std::string& base_felement::get_identifier() const {
  return m_identifier;
}


const state::filename& base_felement::get_filename() const {
  return m_filename;
}

void base_felement::update_modification_time() {
  m_lastModificationTime = std::filesystem::last_write_time(this->get_identifier());
}

bool compare_base_files::operator()(cfileb_t fa, cfileb_t fb) const {
  return fa->get_identifier() < fb->get_identifier();
}


// std::string base_felement::get_modification_time() const {
//   std::time_t cftime = std::filesystem::file_time_type::clock::to_time_t(m_lastModificationTime);
//   return std::string( std::asctime(std::localtime(&cftime)) );
// }

} // namespace bld
