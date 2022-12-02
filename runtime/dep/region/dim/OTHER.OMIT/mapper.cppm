
export module SteelRT.Dep.Guard.Frontend.Mesh;

import SteelRT.Util.Types;
import SteelRT.Dep.FwDeclarations;

import <array>;

namespace dep {

template <std::size_t Dim>
class dim_mapper;


export
template <std::size_t Dim>
class dim_mapper {

public:

  static constexpr std::size_t dimensions = Dim;

  using idx_t = std::size_t;

  using array_t = std::array<ulong_t, Dim>;
  using array_range_t = std::array<range_t, Dim>;

private:

  array_t m_globalEmbeddings;
  array_t m_localEmbeddings;
  array_range_t m_callRanges;

 
public: 

  template <std::size_t InputDim>
  dim_mapper( std::array<ulong_t, InputDim> globalEmbeds, std::array<ulong_t, InputDim> localEmbeds, std::array<range_t, InputDim> callRanges ) :
    m_globalEmbeddings( globalEmbeds )
    m_localEmbeddings( localEmbeds ) 
    m_callRanges( callRanges ),
    m_blocksCount( fold_product( net_range(callRanges) ) )
  {}

  dim_mapper(dim_mapper&&) = default;

  // Common for mesh::direct and mesh::tree. A n-dim -> 1-dim map in elements. Used to shift the pointer a certain amount of elements
  ulong_t get_element_position( array_t coords ) const noexcept {
  // Elem pos = Sum_d ( coord_d * ge_d )
    return fold_product_sum( coords, m_globalEmbeddings );
  }

  // Exclusive for single_mesh. To initialize the vector of n-dim states
  ulong_t get_block_count() const noexcept {
    return m_blocksCount;
  }

  // Exclusive for mesh::direct. To locate the n-dim substate in the vector of substates. A n-dim -> 1-dim map in blocks
  // NakedCoord_i = Coord_i / LocalEmbed_i;
  // Block position = NakedCoord_i * nB_j * nB_k * nB_l * ... + NakedCoord_j * nB_k * nB_l * ... + NakedCoord_k * nB_l + ... + NakedCoord_last * 1;
  ulong_t get_block_position( array_t coords ) const noexcept {
    // Ensure std::get<D>(coords) % m_localEmbed == 0. Emit signal. Otherwise the compiler fucked up.
    auto nakedCoords = point_division(coords, m_localEmbeddings);

    auto netRanges = net_range(m_callRanges);
    array_t prods;
      prods[d] = nakedCoords[d] * netRanges[

    return fold_sum( prods );
    
    return (std::get<D>(coords) / m_localEmbed) * super_type::get_block_count() + super_type::get_block_position( coords, dim_identity<D+1>{} );
    // return ( std::get<D>(coords) / m_localEmbed ) * m_prodBlocks + super_type::get_block_position( coords, dim_identity<D+1>{} ); // Cached
  }

  array_t get_strides() const noexcept {

  }

  array_t get_sizes() const noexcept {

  }

};

} // namespace dep
