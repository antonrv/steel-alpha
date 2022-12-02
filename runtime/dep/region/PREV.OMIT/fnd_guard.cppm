
export module SteelRT.Dep.Guard.Frontend.Region;



import SteelRT.Util.Types;

import SteelRT.Dep.FwDeclarations;

import SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Dep.State;
export import SteelRT.Dep.Guard.Backend;

import <vector>;
import <array>;


namespace dep::guard::fnd::region {


export
template <std::size_t D, typename T>
class readable;

export
template <std::size_t D, typename T>
class writable;



export
template <std::size_t D, typename T>
class readable : public container<state::readable, T, mesh<D>> {
private:

  using container_super_type = container<state::readable, T, mesh<D>>;

  using view_t = typename container_super_type::view_t;

  using array_t = typename mesh<D>::array_t;

public:

  readable(T * ptr, array_t&& elemArray, array_t&& factorArray, range_t&& calleeRange) : container_super_type(ptr, std::forward<array_t>(elemArray), std::forward<array_t>(factorArray), std::forward<range_t>(calleeRange)) {}

  readable( const std::vector<T>& inVec, array_t&& elemArray, array_t&& factorArray, range_t&& calleeRange) : container_super_type(inVec.data(), std::forward<array_t>(elemArray), std::forward<array_t>(factorArray), std::forward<range_t>(calleeRange)) {}

  template <std::size_t ArrSize>
  readable( std::array<T, ArrSize>& inVec, array_t&& elemArray, array_t&& factorArray, range_t&& calleeRange) : container_super_type(inVec.data(), std::forward<array_t>(elemArray), std::forward<array_t>(factorArray), std::forward<range_t>(calleeRange)) {}


  template <typename... UintTs>
  bnd::readable< view_t > emit_bnd_reader(UintTs... ids) noexcept {
    // Return a bnd guard wrapping the new state, assuming that it is ready
    return bnd::readable< view_t >( container_super_type::get_element_state( ids... ) );
  }
};



export
template <std::size_t D, typename T>
class writable : public container<state::writable, T, mesh<D>> {

  using container_super_type = container<state::writable, T, mesh<D>>;

  using view_t = typename container_super_type::view_t;

  using array_t = typename mesh<D>::array_t;

public:


  writable( T * ptr, array_t&& elemArray, array_t&& factorArray, range_t&& calleeRange) : container_super_type(ptr, std::forward<array_t>(elemArray), std::forward<array_t>(factorArray), std::forward<range_t>(calleeRange)) {}


  writable( std::vector<T>& inVec, array_t&& elemArray, array_t&& factorArray, range_t&& calleeRange) : container_super_type(inVec.data(), std::forward<array_t>(elemArray), std::forward<array_t>(factorArray), std::forward<range_t>(calleeRange)) {}


  template <std::size_t ArrSize>
  writable( std::array<T, ArrSize>& inVec, array_t&& elemArray, array_t&& factorArray, range_t&& calleeRange) : container_super_type(inVec.data(), std::forward<array_t>(elemArray), std::forward<array_t>(factorArray), std::forward<range_t>(calleeRange)) {}



  template <typename... UintTs>
  bnd::readable< view_t > emit_bnd_reader(UintTs... ids) noexcept {
    // Return a bnd guard wrapping the new state, assuming that it is ready
    return bnd::readable<view_t>( container_super_type::get_element_state(ids... ) );
  }

  template <typename... UintTs>
  bnd::writable< view_t > emit_bnd_writer(UintTs... ids) noexcept {

    auto& stateRef = container_super_type::get_element_state( ids... );

    state::readable<view_t> prevWriteStateAsReadable( stateRef );

    stateRef.reset();

    return bnd::writable< view_t >(prevWriteStateAsReadable, stateRef); // Await for previous
  }
};

} // namespace dep::guard::fnd::region
