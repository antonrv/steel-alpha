
export module SteelRT.Learn.Agent.Common.Threader.Single;

  export import SteelRT.Learn.Feat.Encoder;
  export import SteelRT.Learn.Feat.Layer;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Util.App;


namespace learn::agent::common {


export
template <plat::processor ProcId, typename NativeT>
class threader_single {
private:

  using all_multithread_proc_ids = typename NativeT::all_multithread_proc_ids;

protected:
  // Will be empty if ProcId is the first processor in the sequence
  using preceeding_proc_sequence = util::sequence::trim_tail_from_t< all_multithread_proc_ids, util::sequence::get_index_v<all_multithread_proc_ids, ProcId> >;

private:

  // ------  Ref active_threads encoders
  template <plat::processor AnyProcId> 
  using encoder_of_t = feat::encoder<feat::kind::active_threads, typename NativeT::template ptraits_of<AnyProcId>>;

  // Types of encoders
  using tuple_thread_encoder = util::tuple::lift_enums_t< preceeding_proc_sequence, encoder_of_t >;


  template <typename EncoderT> 
  using encoder_ref_of_t = feat::encoder<feat::kind::ref, EncoderT>;


  // ------ Ref main_param encoder
  using main_param_encoder = feat::encoder<feat::kind::app_params, app::tuple_call_feed_t<NativeT::main_call> >;
  using main_param_ref_encoder = encoder_ref_of_t< main_param_encoder >;

protected:

  using tuple_encoders =
    util::tuple::cat_t<
      util::tuple::lift_t< tuple_thread_encoder, encoder_ref_of_t >,
      util::tuple_t< main_param_ref_encoder >
    >;

  static constexpr std::size_t NHiddenLayers = 1; // HYPERPARAM XXX
  static constexpr std::size_t NHiddenNeurons = 5; // HYPERPARAM XXX

  static constexpr std::size_t NUsers = 1;

  static constexpr std::size_t max_threads = NativeT::template max_threads<ProcId>;

  static str_t str_identifier() {
    return str_t("actor_threader_" + NativeT::template get_proc_str<ProcId>());
  }
};


} // namespace learn::agent::common
