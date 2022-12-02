
export module SteelRT.Learn.Feat.Coder.Enumerate;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


namespace learn::feat::coder {

export
template <typename EnumSeqT>
class enumerate {

  using enum_type = typename EnumSeqT::value_type;

  using array_t = util::sequence::to_array_t<EnumSeqT>;
  
  static constexpr std::size_t size = EnumSeqT::size();

public:

  static constexpr std::size_t active_size = 1;
  static constexpr std::size_t full_size = size;

  using encoded_type = ushort_t; // enum_uint_t is valid, but it poses problem when printing it XXX 


  template <enum_type EnumVal>
  static void set_encoding( encoded_type& encodedValue ) noexcept {

    encodedValue = util::sequence::get_index_v< EnumSeqT, EnumVal >;
  }

};

} // namespace learn::feat::coder
