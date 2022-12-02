
export module SteelRT.Learn.Approx.NeuralNet.Layer.Values;


import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Require;

import SteelRT.Learn.Types;

import SteelRT.Util.Assert;
#include "assert.hpp"

// TMP XXX
import SteelRT.Instrument;
import SteelRT.Instrument.Predicates;

// export import <vector>;
export import <array>;


export
namespace learn::approx::ann {


template <ann::propagate Prop, ann::width Width, learn::fun Fun, std::size_t BwNeuronCount, std::size_t FwNeuronCount, class Enable = util::enabler_t>
class layer;



template <typename StoreT>
class values <ann::width::single, StoreT> {
protected:


  using all_values_t = StoreT;

  all_values_t m_values;

public:

  static constexpr ann::width ann_width = ann::width::single;

  using value_type = typename StoreT::value_type;

  static constexpr std::size_t element_count = std::tuple_size_v<all_values_t>;

public:

  values() {
    set_zeros();
  }

  void set_zeros() noexcept {
    for (auto& v : m_values) { v = value_type(0); }
  }

  value_type& operator[]( uint_t idx ) noexcept {
    ensure( idx < m_values.size(), "Out of bounds");
    return m_values[idx];
  }

  value_type operator[]( uint_t idx ) const noexcept {
    ensure( idx < m_values.size(), "Out of bounds");
    return m_values[idx];
  }


  void copy_values( const values& other ) noexcept {
    m_values = other.values;
  }


  const all_values_t& get_values() const noexcept {
    return m_values;
  }


  StoreT& edit_values() noexcept {
    return m_values;
  }


  std::size_t size() const noexcept {
    return m_values.size();
  }

};



template <typename StoreT>
class values <ann::width::batch, StoreT> {
protected:

  using all_values_t = std::array< StoreT, global::MaxBatchSize >;

  all_values_t m_valuesSamples;

  uint_t m_currentBatchSize = global::MaxBatchSize;

public:

  static constexpr ann::width ann_width = ann::width::batch;

  template <typename T>
  struct value_type_of { using type = T; };

  template <typename T,std::size_t N>
  struct value_type_of <std::array<T,N>> { using type = T; };

  using value_type = typename value_type_of<StoreT>::type;

  using store_type = StoreT;

public:

  values( ) {
    set_zeros();
  }

  values( uint_t maxBatchSize ) {
    resize(maxBatchSize);
    set_zeros();
  }

  void set_zeros() noexcept {
    if constexpr (std::is_integral_v<value_type>) {
      for (auto s = 0u; s < m_currentBatchSize; s++) {
        m_valuesSamples[s].fill(value_type(0));
      }
    }
  }

  // void copy_values( const values& other ) {
  //   m_valuesSamples = other.values;
  // }

  void resize( uint_t size ) noexcept {
    m_currentBatchSize = size;
    set_zeros();
  }

  const StoreT& get_values( uint_t sampleId ) const noexcept {
    ensure( sampleId < m_currentBatchSize, "Out of bounds. Resize first");
    return m_valuesSamples[ sampleId ];
  }


  StoreT& edit_values( uint_t sampleId ) noexcept {
    ensure( sampleId < m_currentBatchSize, "Out of bounds. Resize first");
    return m_valuesSamples[ sampleId ];
  }

  uint_t get_batch_size() const noexcept {
    return m_currentBatchSize;
  }

};


} // namespace learn::approx::ann
