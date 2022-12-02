
export module SteelRT.Learn.Feat.Encoder.Call;

  export import SteelRT.Learn.Feat.Encoder.Base;
  export import SteelRT.Learn.Feat.Coder.Enumerate;

import SteelRT.Util.Types;
import SteelRT.Util.App;


export
namespace learn::feat {


template <typename ImplSeqT> // ImplSeqT compatible in a ProcId
struct aux_call {

  using compatible_proc_calls = app::cat_calls_of_t< ImplSeqT >;

  using coder_type = coder::enumerate<compatible_proc_calls>;

  using encoded_type = typename coder_type::encoded_type;
};


template <typename ImplSeqT>
class encoder <feat::kind::app_call, ImplSeqT> :
public encoder_base< typename aux_call<ImplSeqT>::encoded_type >
{

private:

  using super_type = encoder_base< typename aux_call<ImplSeqT>::encoded_type >;

  using coder_type = typename aux_call<ImplSeqT>::coder_type;


public:

  static constexpr std::size_t need_weights = coder_type::full_size;

  static constexpr feat::kind feat_kind = feat::kind::app_call;


  template <typename DescPtrT>
  void set_encoded_features( const DescPtrT desc ) noexcept {
   
    static constexpr app::call AppCall = std::remove_pointer_t< DescPtrT >::app_call;

    // static constexpr std::size_t ThisAppCallIdx = util::sequence::get_index_v< compatible_proc_calls, AppCall >;

    coder_type::template set_encoding< AppCall >( super_type::m_encoded );
  }

};



} // namespace learn::feat
