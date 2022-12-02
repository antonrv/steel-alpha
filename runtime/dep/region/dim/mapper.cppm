
export module SteelRT.Dep.Dim.Mapper;

import SteelRT.Util.Basic;

import SteelRT.Dep.Dim.Types;

import SteelRT.Dep.Dim.View.Parameters;



namespace dep::dim {

template <std::size_t Dim>
class mapper;




export
template <>
class mapper<0> {
private:

  // const ulong_t m_offset = 0;
public:

  mapper() = delete;
  mapper(mapper<0>&&) = default;

  template <std::size_t InputDim, std::size_t D>
  mapper(
      array_t<InputDim> globalEmbeds,
      array_t<InputDim> localEmbeds,
      array_range_t<InputDim> callRanges,
      identity<D>) {}


  // Common for single_mesh and multiple_mesh
  template <std::size_t InputDim, std::size_t D>
  ulong_t get_element_position( array_t<InputDim> coords, identity<D> ) const noexcept {
    return 0;
  }

  // Exclusive for single_mesh
  ulong get_block_count() const noexcept {
    return 1;
  }

  // Exclusive for single_mesh
  template <std::size_t InputDim, std::size_t D>
  ulong_t get_block_position( array_t<InputDim> coords, identity<D> ) const noexcept {
    return 0;
  }

  template <std::size_t InputDim, std::size_t D>
  void set_global_embeds( array_t<InputDim>& setEmbeds, identity<D> ) const noexcept { }
};

// Pending optimizations:
// · Cache block product into m_prodBlocks
// · Data view parameters not stored for each data view object, but shared (ptr to parameters struct in mapper), in mesh::direct


export
template <std::size_t Dim>
class mapper : public mapper<Dim - 1> {
private:
  using super_type = mapper<Dim - 1>;

  const ulong_t m_globalEmbed = 0;
  const ulong_t m_localEmbed = 0;
  const ulong_t m_blockCount = 0;
  // const ulong_t m_prodBlocks = 0;

public:


  static constexpr std::size_t dimensions = Dim;

  using idx_t = std::size_t;


  template <std::size_t InputDim, std::size_t D>
  mapper(
      array_t<InputDim> globalEmbeds,
      array_t<InputDim> localEmbeds,
      array_range_t<InputDim> callRanges,
      identity<D> ) :
    super_type( globalEmbeds, localEmbeds, callRanges, identity<D+1>{} ),
    m_globalEmbed( std::get<D>(globalEmbeds) ),
    m_localEmbed( std::get<D>(localEmbeds) ),
    m_blockCount( std::get<D>(callRanges).end - std::get<D>(callRanges).begin )
    // m_prodBlocks( super_type::get_block_count() ) // We can cache the product. Note that we do not account this m_blockCount in this product
    // m_callRange(std::get<D>(callRanges))
  {}

  mapper(mapper&&) = default;

  // Common for mesh::direct and mesh::tree. A n-dim -> 1-dim map in elements
  template <std::size_t InputDim, std::size_t D>
  ulong_t get_element_position( array_t<InputDim> coords, identity<D> ) const noexcept {
    return std::get<D>(coords) * m_globalEmbed + super_type::get_element_position( coords, identity<D+1>{} );
  }

  // Exclusive for single_mesh. To initialize the vector of n-dim states
  ulong_t get_block_count() const noexcept {
    return m_blockCount * super_type::get_block_count();
  }

  // Exclusive for mesh::direct. To locate the n-dim substate in the vector of substates. A n-dim -> 1-dim map in blocks
  // NakedCoord_i = Coord_i / LocalEmbed_i;
  // Block position = NakedCoord_i * nB_j * nB_k * nB_l * ... + NakedCoord_j * nB_k * nB_l * ... + NakedCoord_k * nB_l + ... + NakedCoord_last * 1;
  template <std::size_t InputDim, std::size_t D>
  ulong_t get_block_position( array_t<InputDim> coords, identity<D> ) const noexcept {
    // Ensure std::get<D>(coords) % m_localEmbed == 0. Emit signal. Otherwise the compiler fucked up.
    return (std::get<D>(coords) / m_localEmbed) * super_type::get_block_count() + super_type::get_block_position( coords, identity<D+1>{} );
    // return ( std::get<D>(coords) / m_localEmbed ) * m_prodBlocks + super_type::get_block_position( coords, identity<D+1>{} ); // Cached
  }

  template <std::size_t InputDim, std::size_t D>
  void set_global_embeds( array_t<InputDim>& setEmbeds, identity<D> ) const noexcept {
    setEmbeds[D] = m_globalEmbed;
    super_type::set_global_embeds( setEmbeds, identity<D+1>{} );
  }


  view_parameters<Dim> get_view_parameters( array_t<Dim> coords, array_range_t<Dim> memRanges ) const noexcept {

    array_t<Dim> globalEmbeds;
    set_global_embeds( globalEmbeds, identity<0>{} );

    array_t<Dim> sizes;
    array_t<Dim> offsets;
    array_t<Dim> spacing;

    for (auto d = 0u; d < Dim; d++) {
      sizes[d] = memRanges[d].end - memRanges[d].begin; // Amount of elements in each dimension
      offsets[d] = memRanges[d].begin - coords[d]; // Normally offsets are 0, because start of range matches the coordinate
      spacing[d] = 0; // It could be set from the increment operation in the loop of the downstream uses. Not set for the moment
    }
    
    return view_parameters<Dim>( {globalEmbeds, sizes, offsets, spacing} );
  }

};

} // namespace dep::dim
