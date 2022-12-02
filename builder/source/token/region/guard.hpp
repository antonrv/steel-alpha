#ifndef PARSER_REGION_GUARD_HPP
#define PARSER_REGION_GUARD_HPP

#include "source/token/typedef.hpp"

#include "source/sequences.hpp"
#include "source/object/typedef.hpp"

#include <string>

namespace bld::src::pc {

class access;


class guard {
protected:

#ifndef PARSER_TEST
  cso_t<obj::data_decl> m_dDeclRoot = nullptr;
#endif // PARSER_TEST

protected:

  // Implementation depending on PARSER_TEST
  csob_t get_local_context() const;

public:
  guard(cso_t<obj::data_decl> dDecl);

  virtual ~guard() = 0;

  virtual mem_ak get_mem_guard_kind() const = 0;

#ifndef PARSER_TEST
  virtual std::string serial() const = 0;
#endif // PARSER_TEST


#ifndef PARSER_TEST

  // Called from wrap_create
  virtual std::string get_wrap_command() const = 0;

  // Called from emit_bnd
  virtual std::string get_emit_arguments( const access * acc ) const = 0;

#endif // PARSER_TEST

};

template <mem_ak MemAccK>
class mem_guard;

using point_guard = mem_guard<mem_ak::point>;
using affine_guard = mem_guard<mem_ak::affine>;

} // namespace bld::src::pc

#endif // PARSER_REGION_GUARD_HPP
