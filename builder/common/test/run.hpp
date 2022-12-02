
#include "common/step_enum.hpp"

#include "files/typedef.hpp"

#include <string>

#include <functional>


namespace bld::test {

using run_src_t = std::function<set_cfileb_t(state::filename)>;

void run_on_suites( run_src_t testFun, step stepVal );

} // namespace bld::test
