#ifndef PARSER_REGION_POINT_ACCESS_HPP
#define PARSER_REGION_POINT_ACCESS_HPP


#include "source/token/typedef.hpp"

#include "source/token/region/access.hpp"
#include "source/token/region/guard.hpp"

namespace bld::src::pc {


template <>
class mem_access<mem_ak::point> : public access {

  using super_type = access;

public:
  // Main constructor
  mem_access( cpiece_t inputPc, cso_t<obj::data_use> dUse = nullptr );

  mem_ak get_mem_access_kind() const final override;

#ifndef PARSER_TEST
  std::string serial() const final override;
#endif // PARSER_TEST

};

} // namespace bld::src::pc

#endif // PARSER_REGION_POINT_ACCESS_HPP
