
export module SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Util.Types;

// import SteelRT.Dep.FwDeclarations;

export import SteelRT.Dep.Dim.Types;
export import SteelRT.Dep.Dim.View;
export import SteelRT.Dep.Dim.View.Parameters;
export import SteelRT.Dep.MeshEnum;

// export import SteelRT.Dep.Dim.Mapper;


import <type_traits>;

export import <vector>;
import <utility>;

// import <iostream>; // DBG XXX

// // Fw decl
// namespace dep::state {
// template <typename T> struct is_readable;
// } // namespace dep::state

namespace dep::state {
  template <typename T> class readable;
  template <typename T> class writable;

} // namespace dep::state





namespace dep::guard::fnd::region {

export
template <mesh MeshKind, template <typename> class StateT, typename InputT, typename DimMapperT>
class container;

////////////// This state container provides O(1) access to state subregions in a n-Dim space. Instantiated from fnd::region::readable and fnd::region::writable.
export
template <template <typename> class StateT, typename InputT, typename DimMapperT>
class container <mesh::direct, StateT, InputT, DimMapperT> : public DimMapperT {
private:

  using super_dim_mapper = DimMapperT;

  static_assert( not std::is_pointer_v<InputT> );
  static_assert( not std::is_reference_v<InputT> );
  // static_assert( not std::is_const_v<InputT> );

  using T = InputT;

  using ptr_t = std::add_pointer_t<T>;

  static constexpr std::size_t Dim = DimMapperT::dimensions;

public:

  using arr_t = dim::array_t<Dim>;
  using arr_rng_t = dim::array_range_t<Dim>;

  using view_t = dim::view<Dim, T>;

  using state_t = StateT< view_t >;

private:


  struct state_view {
    state_t state;
    view_t view;

    state_view() : state(nullptr), view() {}
  };

  using vec_states_t = std::vector< state_view >;

  using iterator_t = typename vec_states_t::iterator;

  const ptr_t m_basePtr = nullptr;

  vec_states_t m_vecStates; // const TODO

  iterator_t m_beginIterator;

public:

  // Wrap a region starting from ptr until n
  container( T * ptr, arr_t&& globalEmbeds, arr_t&& localEmbeds, arr_rng_t&& callRanges ) :
    super_dim_mapper(std::forward<arr_t>(globalEmbeds), std::forward<arr_t>(localEmbeds), std::forward<arr_rng_t>(callRanges), dim::identity<0>{} ),
    m_basePtr(ptr),
    m_vecStates( super_dim_mapper::get_block_count() )
  {
    m_beginIterator = m_vecStates.begin();
    // No more reallocations possible for m_vecStates, so no possible invalidation of ptrs that states reference to
  }


  bool is_destroyable() noexcept {

    for (auto it = m_beginIterator; it != m_vecStates.end(); ++it) {
      if (not it->state.is_destroyable()) {
        m_beginIterator = it;
        return false;
      }
    }
    m_beginIterator = m_vecStates.end();
    return true;
  }

protected:

  state_t& get_element_state(arr_t&& coords, arr_rng_t&& ranges) noexcept {

    // O(1)
    state_view& stateViewRef = m_vecStates[ super_dim_mapper::get_block_position( coords, dim::identity<0>{} ) ];

    if (not stateViewRef.state.is_initialized()) {
      // Create view object by shifting the base ptr

      // std::cout << "Shifting ptr : " << super_dim_mapper::get_offset(ids...) << '\n';
      stateViewRef.view.set_ptr( m_basePtr + super_dim_mapper::get_element_position( coords, dim::identity<0>{} ) );

      stateViewRef.view.set_parameters( super_dim_mapper::get_view_parameters( coords, ranges ) );

      // Initialize the state from the new view object
      stateViewRef.state.initialize( stateViewRef.view );
    }

    return stateViewRef.state;
  }

};

} // namespace dep::guard::fnd::region
