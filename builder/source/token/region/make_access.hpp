
#include "source/token/typedef.hpp"

#include "source/token/region/point/access.hpp"
#include "source/token/region/affine/access.hpp"

// TODO
// #include "source/token/region/nonaffine/access.hpp"
// #include "source/token/region/indirect/access.hpp"

namespace bld::src::pc {


std::unique_ptr<access> 
make_mem_access( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, cso_t<obj::data_use> dUse = nullptr );

} // namespace bld::src::pc
