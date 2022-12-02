
export module SteelRT.Dep.Guard.Frontend.Region;

import SteelRT.Util.Basic;

export import SteelRT.Dep.Guard.Backend;
export import SteelRT.Dep.Dim.Mapper;


import SteelRT.Dep.Guard.Frontend.Container; // Internally exports all dep::dim stuff

import SteelRT.Dep.State; // Needed during Container instantiation


import <vector>;
import <array>;


namespace dep::guard::fnd::region {


export
template <mesh MeshKind, std::size_t D, typename T>
class readable;

export
template <mesh MeshKind, std::size_t D, typename T>
class writable;

////////////// MESH DIRECT

export
template <std::size_t D, typename T>
class readable<mesh::direct, D, T> : public container<mesh::direct, state::readable, T, dim::mapper<D>> {
private:

  using container_super_type = container<mesh::direct, state::readable, T, dim::mapper<D>>;

  using view_t = typename container_super_type::view_t;

  using arr_t = typename dim::array_t<D>;
  using arr_rng_t = typename dim::array_range_t<D>;

public:

  readable(T * ptr, arr_t&& globalEmbeds, arr_t&& localEmbeds, arr_rng_t&& callRanges) : container_super_type(ptr, std::forward<arr_t>(globalEmbeds), std::forward<arr_t>(localEmbeds), std::forward<arr_rng_t>(callRanges)) {}

  // readable( const std::vector<T>& inVec, arr_t&& elemArray, arr_t&& globalEmbeds, range_t&& localEmbeds) : container_super_type(inVec.data(), std::forward<arr_t>(elemArray), std::forward<arr_t>(globalEmbeds), std::forward<range_t>(localEmbeds)) {}

  // template <std::size_t ArrSize>
  // readable( std::array<T, ArrSize>& inVec, arr_t&& elemArray, arr_t&& globalEmbeds, range_t&& localEmbeds) : container_super_type(inVec.data(), std::forward<arr_t>(elemArray), std::forward<arr_t>(globalEmbeds), std::forward<range_t>(localEmbeds)) {}


  template <typename... UintTs>
  bnd::readable< view_t > emit_bnd_reader(arr_t&& coords, arr_rng_t&& ranges) noexcept {
    // Return a bnd guard wrapping the new state, assuming that it is ready
    return bnd::readable< view_t >( container_super_type::get_element_state( std::forward<arr_t>(coords), std::forward<arr_rng_t>(ranges) ) );
  }
};



export
template <std::size_t D, typename T>
class writable<mesh::direct, D, T> : public container<mesh::direct, state::writable, T, dim::mapper<D>> {

  using container_super_type = container<mesh::direct, state::writable, T, dim::mapper<D>>;

  using view_t = typename container_super_type::view_t;

  using arr_t = typename dim::array_t<D>;
  using arr_rng_t = typename dim::array_range_t<D>;

public:


  writable(T * ptr, arr_t&& globalEmbeds, arr_t&& localEmbeds, arr_rng_t&& callRanges) : container_super_type(ptr, std::forward<arr_t>(globalEmbeds), std::forward<arr_t>(localEmbeds), std::forward<arr_rng_t>(callRanges)) {}


  // writable( std::vector<T>& inVec, arr_t&& elemArray, arr_t&& globalEmbeds, range_t&& localEmbeds) : container_super_type(inVec.data(), std::forward<arr_t>(elemArray), std::forward<arr_t>(globalEmbeds), std::forward<range_t>(localEmbeds)) {}


  // template <std::size_t ArrSize>
  // writable( std::array<T, ArrSize>& inVec, arr_t&& elemArray, arr_t&& globalEmbeds, range_t&& localEmbeds) : container_super_type(inVec.data(), std::forward<arr_t>(elemArray), std::forward<arr_t>(globalEmbeds), std::forward<range_t>(localEmbeds)) {}



  bnd::readable< view_t > emit_bnd_reader(arr_t&& coords, arr_rng_t&& ranges) noexcept {
    // Return a bnd guard wrapping the new state, assuming that it is ready
    return bnd::readable< view_t >( container_super_type::get_element_state( std::forward<arr_t>(coords), std::forward<arr_rng_t>(ranges) ) );
  }

  bnd::writable< view_t > emit_bnd_writer(arr_t&& coords, arr_rng_t&& ranges) noexcept {

    auto& stateRef = container_super_type::get_element_state( std::forward<arr_t>(coords), std::forward<arr_rng_t>(ranges) );

    state::readable< view_t > prevWriteStateAsReadable( stateRef );

    stateRef.reset();

    return bnd::writable< view_t >( prevWriteStateAsReadable, stateRef ); // Await for previous
  }
};


////////////// MESH SINGLE
// Single : access to extract a dep::backend is done just once during the lifetime of the fnd guard, so no need to do more things during emit_X

export
template <std::size_t D, typename T>
class readable<mesh::single, D, T> {
private:

  using view_t = dim::view<D, T>;

  using state_t = state::readable< view_t >;

  struct state_view {
    state_t state;
    view_t view;

    state_view() : state(nullptr), view() {}
  };

  state_view m_stateView;

public:

  readable(T * ptr) {
    m_stateView.view.set_ptr( ptr );
    // m_stateView.view.set_parameters( ); Not needed
    m_stateView.state.initialize( m_stateView.view );
  }

  bnd::readable< view_t > emit_bnd_reader() noexcept {
    return bnd::readable< view_t >( m_stateView.state );
  }

};

export
template <std::size_t D, typename T>
class writable<mesh::single, D, T> {
private:

  using view_t = dim::view<D, T>;

  using state_t = state::writable< view_t >;

  struct state_view {
    state_t state;
    view_t view;

    state_view() : state(nullptr), view() {}
  };

  state_view m_stateView;

public:

  writable(T * ptr) {
    m_stateView.view.set_ptr( ptr );
    // m_stateView.view.set_parameters( ); Not needed
    m_stateView.state.initialize( m_stateView.view );
  }

  bnd::readable< view_t > emit_bnd_reader() noexcept {
    return bnd::readable< view_t >( m_stateView.state );
  }

  bnd::writable< view_t > emit_bnd_writer() noexcept {

    state::readable< view_t > prevWriteStateAsReadable( m_stateView.state );

    m_stateView.state.reset();

    return bnd::writable< view_t >( prevWriteStateAsReadable, m_stateView.state );
  }
};

} // namespace dep::guard::fnd::region
