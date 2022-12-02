
export module SteelRT.Learn.Approx.Sampler.Base;

import SteelRT.Util.Types;

import SteelRT.Learn.Types;

export import <random>;

import SteelRT.Util.Assert;
#include "assert.hpp"

import <iostream>; // TMP XXX

namespace learn::approx {


export
enum class distribution : enum_uint_t { gaussian, uniform, discrete };

export
class base_sampler {
protected:

  std::random_device m_randDevice;
  std::mt19937 m_engine;

public:

  base_sampler( seed_kind seedKind, seed_t seedValue ) {


    if (seedKind == seed_kind::fix) {
 
      m_engine = std::mt19937(seedValue);

    } else if (seedKind == seed_kind::rnd) {

      auto rndSeed = m_randDevice();
      // std::cout << "RND SEED : " << rndSeed << std::endl;
      m_engine = std::mt19937(rndSeed);

    } else {

      ensure(0, "Unreachable seed_kind mode");
    }
  }

};



export
template <distribution Dist>
class sampler;


} // namespace lear::approx
