
export module SteelRT.Dep.Guard.Frontend.Region;


import SteelRT.Dep.FwDeclarations;

import SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Dep.State;
export import SteelRT.Dep.Guard.Backend;

import <vector>;
import <array>;


namespace dep::guard::fnd::region {


using uint_t = unsigned int;


export
template <unsigned Dim, mode Mode, typename T>
class readable;

export
template <unsigned Dim, mode Mode, typename T>
class writable;



export
template <typename T>
class readable<1, mode::disjoint, T> : public container<1, mode::disjoint, state::readable, T> {

  using container_super_type = container<1, mode::disjoint, state::readable, T>;

  using view_t = typename container_super_type::view_t;

public:

  readable( T * ptr, uint_t size, uint_t blockSize) : container_super_type(ptr, size, blockSize) {}

  readable( const std::vector<T>& inVec, uint_t blockSize) : container_super_type(inVec.data(), 0, inVec.size(), blockSize) {}

  template <std::size_t ArrSize>
  readable( std::array<T, ArrSize>& inVec, uint_t blockSize) : container_super_type(inVec.data(), 0, inVec.size(), blockSize) {}

  bnd::readable< view_t > emit_bnd_reader(uint_t blockIdx) noexcept {
    // Return a bnd guard wrapping the new state, assuming that it is ready
    return bnd::readable< view_t >( container_super_type::get_element_state( blockIdx ) );
  }

};



export
template <typename T>
class writable<1, mode::disjoint, T> : public container<1, mode::disjoint, state::writable, T> {

  using container_super_type = container<1, mode::disjoint, state::writable, T>;

  using view_t = typename container_super_type::view_t;

public:

  writable( T * ptr, uint_t size, uint_t blockSize) : container_super_type(ptr, size, blockSize) {}

  writable( std::vector<T>& inVec, uint_t blockSize) : container_super_type(inVec.data(), 0, inVec.size(), blockSize) {}

  template <std::size_t ArrSize>
  writable( std::array<T, ArrSize>& inVec, uint_t blockSize) : container_super_type(inVec.data(), 0, inVec.size(), blockSize) {}

  bnd::readable<view_t> emit_bnd_reader(uint_t blockIdx) noexcept {
    // Return a bnd guard wrapping the new state, assuming that it is ready
    return bnd::readable<view_t>( container_super_type::get_element_state(blockIdx) );
  }

  bnd::writable<view_t> emit_bnd_writer(uint_t blockIdx) noexcept {

    auto& stateRef = container_super_type::get_element_state(blockIdx);

    state::readable<view_t> prevWriteStateAsReadable( stateRef );

    stateRef.reset();

    return bnd::writable<view_t>(prevWriteStateAsReadable, stateRef); // Await for previous
  }

};

} // namespace dep::guard::fnd::region
