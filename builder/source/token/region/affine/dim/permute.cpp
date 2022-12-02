
#include "common/typedef.hpp"

#include <algorithm>

namespace bld {

static
std::vector< vec_bool_t > make_perms(unsigned n, unsigned k) {

  vec_bool_t vec(n,false);
  auto j = 0u;
  for (auto i = 0u; i < n and j < k; i++,j++) { vec[n - 1u - i] = true; }

  std::vector< vec_bool_t > retVec;

  do {
    retVec.push_back( vec );

  } while ( std::next_permutation( std::begin(vec), std::end(vec) ) );

  return retVec;
}

std::vector< vec_bool_t > make_binary_permutations(unsigned n) {

  std::vector< vec_bool_t > retVec;

  for (auto k = 0u; k <= n; k++) {
    auto nkPerms = make_perms(n, k);
    std::copy(std::begin(nkPerms), std::end(nkPerms), std::back_inserter(retVec));
  }

  return retVec;
}

} // namespace bld
