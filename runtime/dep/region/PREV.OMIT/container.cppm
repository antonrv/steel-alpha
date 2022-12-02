
export module SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Util.Types;

// import SteelRT.Dep.FwDeclarations;

export import SteelRT.Data.View;

export import SteelRT.Dep.Guard.Frontend.Mesh;


import <type_traits>;

import <vector>;
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


////////////// This container provides O(1) access to subregions in a 1D space. Instantiated from fnd::region::readable and fnd::region::writable
export
template <template <typename> class StateT, typename InputT, typename MeshT>
class container : public MeshT {
private:

  using mesh_super_type = MeshT;

  static_assert( not std::is_pointer_v<InputT> );
  static_assert( not std::is_reference_v<InputT> );
  // static_assert( not std::is_const_v<InputT> );

  using T = InputT;

  using ptr_t = std::add_pointer_t<T>;

  static constexpr std::size_t Dim = MeshT::dimensions;

public:

  using array_t = typename MeshT::array_t;

  using view_t = data::view<Dim, T>;

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

  vec_states_t m_vecStates;

  // array_t m_blockSizes;

  iterator_t m_beginIterator;

public:

  // Wrap a region starting from ptr until n
  container( T * ptr, array_t&& elemArray, array_t&& factorArray, range_t&& calleeRange ) :
    mesh_super_type(std::forward<array_t>(elemArray), std::forward<array_t>(factorArray), std::forward<range_t>(calleeRange), dim_identity<0>{} ),
    m_basePtr(ptr),
    m_vecStates( mesh_super_type::get_element_count() )
    // m_blockSizes( regionArray )
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

  template <typename... UintTs>
  state_t& get_element_state(UintTs... ids) noexcept {

    // O(1)
    state_view& stateViewRef = m_vecStates[ mesh_super_type::get_mesh_position(ids...) ];

    if (not stateViewRef.state.is_initialized()) {
      // Create view object by shifting the base ptr

      // std::cout << "Shifting ptr : " << mesh_super_type::get_offset(ids...) << '\n';
      stateViewRef.view.set_ptr( m_basePtr + mesh_super_type::get_offset(ids...) );

      // We could query the block size depending on the ids also (in case a partition that yields a remain). For the moment we assume fixed-sized blocks
      // stateViewRef.view.set_sizes( m_blockSizes ); // XXX set_sizes

      // Initialize the state from the new view object
      stateViewRef.state.initialize( stateViewRef.view );
    }

    return stateViewRef.state;
  }

};

} // namespace dep::guard::fnd::region
