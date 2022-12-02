
export module SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Util.Types;

import SteelRT.Dep.FwDeclarations;

export import SteelRT.Data.View;


import <type_traits>;

import <vector>;
import <utility>;



namespace dep::guard::fnd::region {

////////////// This container provides O(1) access to subregions in a 1D space. Instantiated from fnd::region::readable and fnd::region::writable
export
template <template <typename> class StateT, typename T>
class container<1, mode::disjoint, StateT, T> {

  static_assert( not std::is_pointer_v<T> );
  static_assert( not std::is_reference_v<T> );

  using ptr_t = std::add_pointer_t<T>;


public:

  using view_t = data::view<1, T>;

  using state_t = StateT< view_t >;

private:

  using vec_elem_t = std::pair<state_t, view_t>;

  using vec_states_t = std::vector< vec_elem_t >;

  using iterator_t = typename vec_states_t::iterator;

  const ptr_t m_basePtr = nullptr;
  const uint_t m_blockSize = 0;
  const uint_t m_remainSize = 0;

  vec_states_t m_vecStates;

  iterator_t m_beginIterator;

public:

  // Wrap a region starting from ptr until n
  container( T * ptr, uint_t size, uint_t blockSize) :
    m_basePtr(ptr),
    m_vecStates(size / blockSize + (size % blockSize != 0 ? 1 : 0), std::make_pair(state_t(nullptr), view_t())), // Set the states uninitialized
    m_blockSize(blockSize),
    m_remainSize(size % blockSize),
    m_beginIterator(m_vecStates.begin())
  {
    // No more reallocations possible for m_vecStates, so no possible invalidation of ptrs that states reference to
  }

  uint_t get_blocks() const noexcept {
    return m_vecStates.size();
  }


  bool is_destroyable() noexcept {

    for (auto it = m_beginIterator; it != m_vecStates.end(); ++it) {
      m_beginIterator = it;
      if (not std::get<state_t>(*it).is_destroyable()) {
        return false;
      }
    }
    return true;
  }

protected:

  state_t& get_element_state(uint_t blockIdx) noexcept {

    vec_elem_t& vecElemRef = m_vecStates[blockIdx];

    if (not std::get<state_t>(vecElemRef).is_initialized()) {
      // Create view object by shifting the base ptr
      std::get<view_t>(vecElemRef).set_ptr( m_basePtr + blockIdx * m_blockSize );
      std::get<view_t>(vecElemRef).set_size( blockIdx == m_vecStates.size() - 1 && m_remainSize > 0 ? m_remainSize : m_blockSize );

      // Initialize the state from the new view object
      std::get<state_t>(vecElemRef).initialize( std::get<view_t>(vecElemRef) );
    }

    return std::get< state_t >(vecElemRef);
  }

};

} // namespace dep::guard::fnd::region
