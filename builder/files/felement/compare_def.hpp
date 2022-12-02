#ifndef FILES_FELEMENT_COMPARE_DEF_HPP
#define FILES_FELEMENT_COMPARE_DEF_HPP

#include "files/typedef.hpp"


namespace bld {

template <file_kind FK, code CodK>
bool compare_files<FK, CodK>::operator()(cfile_t<FK, CodK> fa, cfile_t<FK, CodK> fb) const {
  return fa->get_identifier() < fb->get_identifier();
}


template <file_kind FK, code CodK>
bool compare_own_files<FK, CodK>::operator()(const own_file_t<FK, CodK>& fa, const own_file_t<FK, CodK>& fb) const {
  return fa->get_identifier() < fb->get_identifier();
}

} // namespace bld

#endif // FILES_FELEMENT_COMPARE_DEF_HPP
