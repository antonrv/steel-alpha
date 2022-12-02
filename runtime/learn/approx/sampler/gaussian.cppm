
export module SteelRT.Learn.Approx.Sampler.Gaussian;

  export import SteelRT.Learn.Approx.Sampler.Base;

import SteelRT.Learn.Types;


import SteelRT.Util.Assert;
#include "assert.hpp"


export
namespace learn::approx {

// Need to align to avoid false sharing when using samplers by different threads

template <>
class alignas(64) sampler<distribution::gaussian> : public base_sampler {
private:

  std::normal_distribution<fp_t> m_sampler;

  using param_t = typename std::normal_distribution<fp_t>::param_type;

public:

  sampler(seed_kind seedKind, seed_t seedValue) :
    base_sampler( seedKind, seedValue ),
    m_sampler(0.f, 1.f)  // mean 0 stddev 1
  {}

  // NOT NEEDED
  // sampler(fp_t mean, fp_t stddev, seed_kind seedKind, seed_t seedValue) :
  //   base_sampler( seedKind, seedValue ),
  //   m_sampler(mean, stddev)  // mean 0 stddev 1
  // {}


  fp_t sample( ) noexcept {
    return m_sampler(m_engine);
  }

  template <std::size_t N>
  array_t<N> sample_array( ) noexcept {

    array_t<N> samples;

    for (auto &s : samples) {
      s = m_sampler(m_engine);
    }
    return samples;
  }

  fp_t sample(fp_t mean, fp_t stddev) noexcept {
    ensure(stddev > 0, "Stddev in normal distribution must be positive");
    return m_sampler(m_engine, param_t(mean, stddev));
  }

};


} // namespace learn::approx
