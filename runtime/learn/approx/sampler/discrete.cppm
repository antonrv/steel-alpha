
export module SteelRT.Learn.Approx.Sampler.Discrete;

export import SteelRT.Learn.Approx.Sampler.Base;


import SteelRT.Learn.Types;


import SteelRT.Util.Assert;
#include "assert.hpp"

export
namespace learn::approx {

// Need to align to avoid false sharing when using samplers by different threads (No more, they are packed into smart ptrs):w


template <>
class sampler<distribution::discrete> : public base_sampler {
private:

  std::uniform_real_distribution<fp_t> m_sampler;

public:

  sampler(seed_kind seedKind, seed_t seedValue) :
    base_sampler( seedKind, seedValue ),
    m_sampler( 0.f, 1.f ) 
  {}


  template <typename ArrayT>
  unsigned sample( const ArrayT& values ) noexcept {
    // Values denote probabilities

    // Throw dice in [0,1]
    auto rnd = m_sampler(m_engine);

    typename ArrayT::value_type sumVals = 0;

    unsigned i = 0u;
    while(i < values.size()) {
      sumVals += values[i];
      if (rnd <= sumVals) {
        return i;
      }
      i++;
    }
    // ensure(0, "Unreachable while sampling discrete"); We relax this, as fp sum is not exact
    return values.size() - 1;
  }

};


} // namespace learn::approx
