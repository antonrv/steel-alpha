
#include "source/token/region/point/access.hpp"

// #include "source/token/region/point/guard.hpp"


namespace bld::src::pc {

mem_access<mem_ak::point>::mem_access( cpiece_t inputPc, cso_t<obj::data_use> dUse ) :
super_type(inputPc, dUse)
{}


mem_ak mem_access<mem_ak::point>::get_mem_access_kind() const {
  return mem_ak::point;
}

////// Serial
#ifndef PARSER_TEST
std::string mem_access<mem_ak::point>::serial() const {

  return "serialized:mem_access<mem_ak::point>:no-fields";
  // make_serial<0>();
}
#endif // PARSER_TEST



} // namespace bld::src::pc
