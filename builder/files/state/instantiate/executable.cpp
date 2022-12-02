
#include "files/state/def.hpp"

namespace bld::state {

// CLASS
template class files<file_kind::executable>;


// TEMPLATED METHODS

// template set_own_file_t<file_kind::executable, code::interface>& files<file_kind::executable>::get_owned_files<code::interface>();
// template set_own_file_t<file_kind::executable, code::implementation>& files<file_kind::executable>::get_owned_files<code::implementation>();
template set_own_file_t<file_kind::executable, code::entry>& files<file_kind::executable>::get_owned_files<code::entry>();


// template file_t<file_kind::executable, code::interface> files<file_kind::executable>::record<code::interface>(filename id);
// template file_t<file_kind::executable, code::implementation> files<file_kind::executable>::record<code::implementation>(filename id);
template file_t<file_kind::executable, code::entry> files<file_kind::executable>::record<code::entry>(filename id);

// template file_t<file_kind::executable, code::interface> files<file_kind::executable>::get_file_element<code::interface>(const std::string& id);
// template file_t<file_kind::executable, code::implementation> files<file_kind::executable>::get_file_element<code::implementation>(const std::string& id);
template file_t<file_kind::executable, code::entry> files<file_kind::executable>::get_file_element<code::entry>(const std::string& id);

// template set_file_t<file_kind::executable, code::interface> files<file_kind::executable>::get_raw<code::interface>();
// template set_file_t<file_kind::executable, code::implementation> files<file_kind::executable>::get_raw<code::implementation>();
template set_file_t<file_kind::executable, code::entry> files<file_kind::executable>::get_raw<code::entry>();

// template cfile_t<file_kind::executable, code::interface> files<file_kind::executable>::find_file<code::interface>(const std::string& id);
// template cfile_t<file_kind::executable, code::implementation> files<file_kind::executable>::find_file<code::implementation>(const std::string& id);
template cfile_t<file_kind::executable, code::entry> files<file_kind::executable>::find_file<code::entry>(const std::string& id);


// Non templated methods
//   void files<file_kind::executable>::print_elements();
//   const base_file_t files<file_kind::executable>::get_poly_file(const std::string& id);
//   template void files<file_kind::executable>::record_filename(filename fn);


} // namespace bld::state
