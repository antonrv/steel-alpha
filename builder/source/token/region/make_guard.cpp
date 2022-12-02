
#include "source/token/region/make_guard.hpp"

#include "common/util.hpp"

namespace bld::src::pc {


std::unique_ptr<guard> 
make_mem_guard( std::vector<const access*> accessVec, cso_t<obj::data_decl> dDecl ) {

  auto nTotal = accessVec.size();

  auto nPoints = (unsigned long) std::count_if( std::begin(accessVec), std::end(accessVec),
      [] (const access * acc) { return acc->get_mem_access_kind() == mem_ak::point; } );

  auto nAffines = (unsigned long) std::count_if( std::begin(accessVec), std::end(accessVec),
      [] (const access * acc) { return acc->get_mem_access_kind() == mem_ak::affine; } );


  if (nAffines == nTotal) {

    auto accessAffVec = transform_vec( accessVec, [] (const access * acc) { return static_cast<const mem_access<mem_ak::affine>*>(acc); } );

    return std::make_unique< mem_guard<mem_ak::affine> >( accessAffVec, dDecl );
  }

  if (nPoints == nTotal) { // All points

    auto accessPointVec = transform_vec( accessVec, [] (const access * acc) { return static_cast<const mem_access<mem_ak::point>*>(acc); } );

    return std::make_unique< mem_guard<mem_ak::point> >( accessPointVec, dDecl );
  }

  throw std::runtime_error("Implement make_mem_guard. nAffines : " + std::to_string(nAffines) + ", nPoints : " + std::to_string(nPoints));

}

} // namespace bld::src::pc
