#ifndef FILES_TYPEDEF_HPP
#define FILES_TYPEDEF_HPP

#include "files/enum.hpp"

#include <set>
#include <memory>

namespace bld::state {
  class filename;
} // namespace bld::state

namespace bld {

class base_felement;

using fileb_t = std::add_pointer_t<base_felement>;
using cfileb_t = std::add_pointer_t<std::add_const_t<base_felement>>;

template <file_kind FK, code CodK>
class felement;

template <file_kind FK, code CodK>
using file_t = std::add_pointer_t<felement<FK,CodK>>;

template <file_kind FK, code CodK>
using own_file_t = std::unique_ptr<felement<FK,CodK>>;

template <file_kind FK, code CodK>
using cfile_t = std::add_pointer_t<std::add_const_t<felement<FK,CodK>>>;


// Defined in files/felement/compare_def.hpp"
template <file_kind FK, code CodK>
struct compare_files {
  bool operator()(cfile_t<FK, CodK> fa, cfile_t<FK, CodK> fb) const;
};

template <file_kind FK, code CodK>
using set_file_t = std::set<file_t<FK,CodK>, compare_files<FK,CodK>>;

template <file_kind FK, code CodK>
using set_cfile_t = std::set<cfile_t<FK,CodK>, compare_files<FK,CodK>>;


struct compare_base_files {
  bool operator()(cfileb_t fa, cfileb_t fb) const;
};

using set_fileb_t = std::set<fileb_t, compare_base_files>;
using set_cfileb_t = std::set<cfileb_t, compare_base_files>;

template <file_kind FK, code CodK>
struct compare_own_files {
  bool operator()(const own_file_t<FK, CodK>& fa, const own_file_t<FK, CodK>& fb) const;
};

template <file_kind FK, code CodK>
using set_own_file_t = std::set<own_file_t<FK,CodK>, compare_own_files<FK,CodK>>;

class module;

using module_t = std::add_pointer_t<module>;
using cmodule_t = std::add_pointer_t<std::add_const_t<module>>;

struct compare_modules {
  bool operator()(cmodule_t ma, cmodule_t mb) const;
};

using set_module_t = std::set<module_t, compare_modules>;
using set_cmodule_t = std::set<cmodule_t, compare_modules>;

using own_module_t = std::unique_ptr<module>;

struct compare_own_modules {
  bool operator()(const own_module_t& ma, const own_module_t& mb) const;
};

using set_own_module_t = std::set<own_module_t, compare_own_modules>;

} // namespace bld

#endif // FILES_TYPEDEF_HPP
