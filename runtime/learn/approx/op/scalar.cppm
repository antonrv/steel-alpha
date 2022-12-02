

export module SteelRT.Learn.Approx.Operations.Scalar;

import SteelRT.Util.Types;
import SteelRT.Learn.Types;

import <cmath>;


export
namespace learn::approx::op {


enum class eval : enum_uint_t { direct, derivative };

template <fun Fun>
struct traits;

template <>
struct traits<fun::linear> {

  template <eval Eval>
  static fp_t compute(fp_t value) noexcept;

  template <>
  fp_t compute<eval::direct>(fp_t value) noexcept {
    return value;
  }

  template <>
  fp_t compute<eval::derivative>(fp_t value) noexcept {
    return 1.f;
  }
};


template <>
struct traits<fun::relu> {

  template <eval Eval>
  static fp_t compute(fp_t value) noexcept;

  template <>
  fp_t compute<eval::direct>(fp_t value) noexcept {
    return value < 0.f ? 0.f : value;
  }

  template <>
  fp_t compute<eval::derivative>(fp_t value) noexcept {
    return value < 0.f ? 0.f : 1.f;
  }
};

template <>
struct traits<fun::leaky_relu> {

  template <eval Eval>
  static fp_t compute(fp_t value) noexcept;

  static constexpr const fp_t leakFactor = 0.01f;

  template <>
  fp_t compute<eval::direct>(fp_t value) noexcept {
    return value < 0.f ? leakFactor * value : value;
  }

  template <>
  fp_t compute<eval::derivative>(fp_t value) noexcept {
    return value < 0.f ? leakFactor : 1.f;
  }
};

template <>
struct traits<fun::sigmoid> {

  template <eval Eval>
  static fp_t compute(fp_t value) noexcept;

  template <>
  fp_t compute<eval::direct>(fp_t value) noexcept {
    return 1.f / (1.f + std::expf(-value));
  }

  template <>
  fp_t compute<eval::derivative>(fp_t value) noexcept {
    fp_t tmp = compute<eval::direct>(value);
    return tmp*(1.f - tmp);
  }
};

template <>
struct traits<fun::tanh> {

  template <eval Eval>
  static fp_t compute(fp_t value) noexcept;

  template <>
  fp_t compute<eval::direct>(fp_t value) noexcept {
    fp_t expPlus = std::expf(value);
    fp_t expMinus = std::expf(-value);
    return (expPlus - expMinus) / (expPlus + expMinus);
  }

  template <>
  fp_t compute<eval::derivative>(fp_t value) noexcept {
    fp_t tmp = compute<eval::direct>(value);
    return 1.f - tmp*tmp;
  }
};


template <>
struct traits<fun::exp> {

  template <eval Eval>
  static fp_t compute(fp_t value) noexcept;

  template <>
  fp_t compute<eval::direct>(fp_t value) noexcept {
    return std::expf(value);
  }

  template <>
  fp_t compute<eval::derivative>(fp_t value) noexcept {
    return std::expf(value);
  }
};


template < fun Fun, eval Eval, typename ValuesT >
void apply_on( ValuesT& outValues, const ValuesT& inValues ) {

  for (auto i = 0u; i < inValues.size(); i++) {
    outValues[i] = traits<Fun>::template compute<Eval>( inValues[i] );
  }
}


} // namespace learn::approx::op
