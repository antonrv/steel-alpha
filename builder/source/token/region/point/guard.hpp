#ifndef PARSER_REGION_POINT_GUARD_HPP
#define PARSER_REGION_POINT_GUARD_HPP

#include "source/token/region/guard.hpp" // Base

#include "source/token/region/point/access.hpp"


namespace bld::src::pc {


template <>
class mem_guard <mem_ak::point> : public guard {

using super_type = guard;

private:

  const std::vector<const point_access*> m_pointAccesses;


public:

  mem_guard( const std::vector<const point_access*>& pts, cso_t<obj::data_decl> dDecl = nullptr );

  ~mem_guard();

  virtual mem_ak get_mem_guard_kind() const final override;

#ifndef PARSER_TEST

public:

  // Called from wrap_create
  std::string get_wrap_command() const final override;

  // Called from emit_bnd
  std::string get_emit_arguments( const access * acc ) const final override;

  std::string serial() const final override;

#endif // PARSER_TEST

};


} // namespace bld::src::pc

#endif // PARSER_REGION_POINT_GUARD_HPP
