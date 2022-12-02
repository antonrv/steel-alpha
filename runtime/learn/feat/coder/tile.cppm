
export module SteelRT.Learn.Feat.Coder.Tile;

  import SteelRT.Learn.Feat.Coder.Rescale;

import SteelRT.Learn.Types;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;




// import SteelRT.Instrument;
// 
// import SteelRT.Instrument.Predicates;
// 


// import <array>;

  // --- Things to do TODO
  // We could extend this to multiple dimensions (eg parameters of a MM). Probably not needed. Same effect by upstream/caller dim extension
  // C++20-compliant compiler will allow T being float/double.


namespace learn::feat::coder {




// template <typename T, T InRangeMin, T TileSize, rescale Rescale >
template <typename T, T InRangeMin, T InRangeMax, T TileSize >
struct single_tile {

  // static_assert((Rescale == rescale::log and InRangeMin > 0) or Rescale == rescale::linear);

  // static constexpr std::size_t RangeMin = scale_value<Rescale>::Convert(InRangeMin);

  static uint_t get_active_tile( const T convValue ) noexcept {

    // std::cout << "in value : " << static_cast<uint_t>(convValue) << ". Range min " << static_cast<uint_t>(InRangeMin) << '\n';

    // instr::trace<instr::event::learn_agent::pick_implement_encode_app_param>(); // testing instrument

    return (convValue < InRangeMin or convValue >= InRangeMax) ? global::NoIndex : static_cast< uint_t >( (convValue - InRangeMin) / TileSize );
  }
};
  
  
export
template < typename T, T InRangeMin, T InRangeMax, T TileSize, rescale Rescale, typename TilingIdSeq >
class tile_detail;


export
template < typename T, T InRangeMin, T InRangeMax, T TileSize, rescale Rescale, std::size_t... TilingIds >
class tile_detail< T, InRangeMin, InRangeMax, TileSize, Rescale, util::sequence::index_t<TilingIds...> > 
{


  static constexpr std::size_t NTilings = sizeof...(TilingIds);

  static_assert(NTilings <= TileSize);

  static constexpr T RangeMin = scale_value<Rescale>::Convert( InRangeMin );
  static constexpr T RangeMax = scale_value<Rescale>::Convert( InRangeMax );


public:


  static constexpr std::size_t active_size = NTilings;

  static constexpr std::size_t full_size = (RangeMax - RangeMin) / TileSize * NTilings;

  using return_type = uint_t;

  using encoded_type = array_idx_t< active_size >;

private:

  template <std::size_t TilingId>
  static void get_active_tile_of_tiling( encoded_type& encodedValues, const T convValue ) noexcept {

    static constexpr T TilingShift = TilingId * (TileSize / NTilings);

    // using this_single_tile = single_tile< T, RangeMin + TilingShift, TileSize, Rescale >;
    using this_single_tile = single_tile< T, RangeMin + TilingShift, RangeMax + TilingShift, TileSize >;

    encodedValues[ TilingId ] = this_single_tile::get_active_tile( convValue );

    // std::cout << "Computed tiling Id " << TilingId << " of value " << static_cast<uint_t>(convValue) << " using coder Min : " << RangeMin + TilingShift << ". Max : " << RangeMax + TilingShift << ". Tile Size : " << static_cast<uint_t>(TileSize) <<  ". Got : " << allTileIds[ 0 ] << ". ptr : " << &allTileIds[0] << '\n';
  }


public:

  static void set_encoding( encoded_type& encodedValues, const T value ) noexcept {

    ( get_active_tile_of_tiling< TilingIds >( encodedValues, scale_value<Rescale>::convert(value) ), ... );
  }

};


export
template <typename T, T RangeMin, T RangeMax, T TileSize, rescale Rescale, std::size_t NTilings >
using tile = tile_detail< T, RangeMin, RangeMax, TileSize, Rescale, util::sequence::make_index_t<NTilings> >;


// Default for impl arguments without any defined range. High discrimination between log intervals, nearest neighbors (+/-1) generalizations:
// eg uint_t (32bits) --> Min = 1, Max = 2^32, TileSize = 2, rescale::log, tilings = <0,1>
export
template <typename T>
using default_log_tile = tile_detail< T, std::numeric_limits<T>::min() + (std::is_unsigned_v<T>)*1, std::numeric_limits<T>::max(), /*TileSize*/2, rescale::log, util::sequence::make_index_t<2> >;



} // namespace learn::feat

// No need for derivation from tile_detail
// :
//   public single_tile<
//     T,
//     RangeMin + TilingIds * (TileSize / sizeof...(TilingIds)),
//     RangeMax + TilingIds * (TileSize / sizeof...(TilingIds)),
//     TileSize
//   > ...

// One hot encoding not needed
// private:
//   template <std::size_t TilingId>
//   static void set_one_hot( std::array<bool, OneHotEncode>& oneHot, const T value ) noexcept {
// 
//     static constexpr T TilingShift = TilingId * (TileSize / NTilings);
// 
//     using super_single_tile = single_tile< T, RangeMin + TilingShift, RangeMax + TilingShift, TileSize >;
// 
//     oneHot[ TilingId * NTilings + super_single_tile::get_active_tile( value ) ] = true;
// 
//   }
// 
// 
// public:
//   static std::array<bool, full_size> get_one_hot( const T value ) noexcept {
// 
//     // TEST TODO
// 
//     std::array<bool, full_size> oneHot;
// 
//     // Set to eros / False TODO
// 
//     ( set_one_hot< TilingIds >( oneHot, value ), ... );
// 
//     return oneHot;
//   }

// Not needed, array not created but passed from selector as a ptr
// private:
// 
//   template <std::size_t TilingId>
//   static void get_active_tile_of_tiling( std::array<uint_t, active_size>& allTileIds, const T value ) noexcept {
// 
//     static constexpr T TilingShift = TilingId * (TileSize / NTilings);
// 
//     using super_single_tile = single_tile< T, RangeMin + TilingShift, RangeMax + TilingShift, TileSize >;
// 
//     allTileIds[ TilingId ] = super_single_tile::get_active_tile( value );
//   }
// 
// 
// public:
// 
//   static std::array<uint_t, active_size> set_encoding( const T value ) noexcept {
// 
//     // TEST TODO
// 
//     std::array<uint_t, active_size> allTileIds;
// 
//     ( get_tile_of_tiling< TilingIds >( allTileIds, value ), ... );
// 
//     return allTileIds;
//   }
