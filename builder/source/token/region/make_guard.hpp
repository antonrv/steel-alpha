
#include "source/token/typedef.hpp"

#include "source/token/region/affine/guard.hpp"
#include "source/token/region/point/guard.hpp"


namespace bld::src::pc {


std::unique_ptr<guard> 
make_mem_guard( std::vector<const access*> accessVec, cso_t<obj::data_decl> dDecl = nullptr );

} // namespace bld::src::pc
