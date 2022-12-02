
export module SteelRT.Dep.Guard.Frontend.Mesh;

import SteelRT.Util.Types;
import SteelRT.Dep.FwDeclarations;

import <array>;

namespace dep {

template <std::size_t Dim>
class mesh;


export
template <std::size_t D>
struct dim_identity {};

export
template <>
class mesh<0> {
private:

  // const ulong_t m_offset = 0;
public:

  mesh() = delete;
  mesh(mesh<0>&&) = default;

  template <std::size_t InputDim, std::size_t D>
  mesh(const std::array<ulong_t, InputDim>& nElems, const std::array<ulong_t, InputDim>& varFactors, const range_t calleeRange, dim_identity<D>) {}

  ulong_t get_offset() const noexcept {
    return 0;
  }

  ulong_t get_mesh_position() const noexcept {
    return 0;
  }

  ulong_t get_element_count() const noexcept {
    return 1;
  }

  // template <std::size_t D>
  // std:array<ulong_t, D> get_block_sizes() {
  //   return std::array<ulong_t, 0>();
  // }
};


export
template <std::size_t Dim>
class mesh : public mesh<Dim - 1> {
private:
  using super_type = mesh<Dim - 1>;

  const ulong_t m_elementCount = 0;
  const ulong_t m_variableFactor = 0; // Factor that multiplies
  const range_t m_calleeRange = {0,0};

public:

  static constexpr std::size_t dimensions = Dim;

  using idx_t = std::size_t;

  using array_t = std::array<ulong_t, Dim>;
  using array_range_t = std::array<range_t, Dim>;

  template <std::size_t InputDim, std::size_t D>
  mesh(std::array<ulong_t, InputDim> nElems, std::array<ulong_t, InputDim> varFactors, range_t calleeRange, dim_identity<D>) :
    super_type( nElems, varFactors, calleeRange, dim_identity<D+1>{} ),
    m_elementCount(std::get<D>(nElems)),
    m_variableFactor(std::get<D>(varFactors)),
    m_calleeRange(calleeRange)
  {}

  mesh(mesh&&) = default;

  ulong_t get_variable_factor() const noexcept {
    return m_variableFactor;
  }

  template <typename... IdxT>
  ulong_t get_offset(idx_t thisIdx, IdxT... ids) const noexcept {
    return thisIdx * m_variableFactor + super_type::get_offset( ids... );
  }

  template <typename... IdxT>
  ulong_t get_mesh_position(idx_t thisIdx, IdxT... ids) const noexcept {
    return thisIdx + m_elementCount * super_type::get_mesh_position( ids... );
  }

  ulong_t get_element_count() const noexcept {
    return m_elementCount * super_type::get_element_count();
  }

  ulong_t get_callee_count() const noexcept {
    return m_calleeRange.end - m_calleeRange.begin + 1;
  }

  // template <std::size_t D>
  // std:array<ulong_t, D> get_block_sizes() {
  //   return array_cat(m_range, super_type::get_block_sizes<D>()); // TODO
  // }

};

} // namespace dep
