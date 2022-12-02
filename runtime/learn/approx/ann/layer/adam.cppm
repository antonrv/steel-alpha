
export module SteelRT.Learn.Approx.NeuralNet.Layer.Adam;


import SteelRT.Util.Types;
import SteelRT.Learn.Types;

import <cmath>;


namespace learn::approx::ann {


export
template <std::size_t N>
class adam {

  fp_t m_paramMoment = 0;
  fp_t m_paramSquare = 0;

  fp_t m_oneMinusMoment = 1;
  fp_t m_oneMinusSquare = 1;

  uint_t m_step = 0;

  array_t<N> m_gradient;
  array_t<N> m_correctMoment;
  array_t<N> m_correctSquare;

public:


  void set_parameters( fp_t paramMoment, fp_t paramSquare ) noexcept {

    m_gradient.fill(0);
    m_correctMoment.fill(0);
    m_correctSquare.fill(0);

    m_paramMoment = paramMoment;
    m_paramSquare = paramSquare;

    m_oneMinusMoment = 1 - m_paramMoment;
    m_oneMinusSquare = 1 - m_paramSquare;
  }


  array_t<N>& edit_gradient() noexcept {
    return m_gradient;
  }


  const array_t<N>& get_gradient() const noexcept {
    return m_gradient;
  }


  void correct_gradient( ) {

    if ( m_paramMoment == 0.f and m_paramSquare == 0.f ) {
      return;
    }

    m_step++;
  
    const fp_t momentBias = 1.f / (1.f - std::powf(m_paramMoment, m_step));
    const fp_t squareBias = 1.f / (1.f - std::powf(m_paramSquare, m_step));
 
    for (auto i = 0u; i < N; i++) { 
  
      fp_t& valueCorrectMoment = m_correctMoment[i];
      fp_t& valueCorrectSquare = m_correctSquare[i];
      fp_t& valueGradient = m_gradient[i];
  
      valueCorrectMoment = ( m_paramMoment * valueCorrectMoment + m_oneMinusMoment * valueGradient ) * momentBias;
  
      valueCorrectSquare = ( m_paramSquare * valueCorrectSquare + m_oneMinusSquare * valueGradient * valueGradient ) * squareBias;
  
      valueCorrectMoment = valueCorrectMoment / ( std::sqrtf( valueCorrectSquare ) + 1e-8 );
    }
  }

};

} // namespace learn::approx::ann
