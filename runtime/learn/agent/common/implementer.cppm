
export module SteelRT.Learn.Agent.Common.Implementer;

  export import SteelRT.Learn.Feat.Encoder;
  export import SteelRT.Learn.Feat.Layer;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;


namespace learn::agent::common {

export
template <plat::processor ProcId, typename AppGroupT, typename NativeT>
class implementer {
private:

  ////////////////// Global/Ref read-only encoders

  // ------  Ref active_threads encoders
  template <plat::processor AnyProcId> 
  using encoder_of_t = feat::encoder<feat::kind::active_threads, typename NativeT::template ptraits_of<AnyProcId>>;

  // Types of encoders
  using thread_encoder_tuple = util::tuple::lift_enums_t< typename NativeT::all_multithread_proc_ids, encoder_of_t >;

  template <typename EncoderT> 
  using encoder_ref_of_t = feat::encoder<feat::kind::ref, EncoderT>;


  // ------ Ref main_param encoder
  using main_param_encoder = feat::encoder<feat::kind::app_params, app::tuple_call_feed_t<NativeT::main_call> >;
  using main_param_ref_encoder = encoder_ref_of_t< main_param_encoder >;


  using ref_encoders_t =
    util::tuple::cat_t<
      util::tuple::lift_t< thread_encoder_tuple, encoder_ref_of_t >,
      util::tuple_t< main_param_ref_encoder >
    >;

  template <typename RefEncoderT>
  using reference_encoder_type_of_t = typename RefEncoderT::reference_encoder_type;

  using referenced_encoders_t = util::tuple::lift_t< ref_encoders_t, reference_encoder_type_of_t >;



  ////////////////// Local editable encoders

  template <app::impl AppImpl>
  using belong_to_appgroup = std::is_same< app::group_impl_of_t<AppImpl>, AppGroupT >;

protected:

  // This is the action space: all the implementations runnable on ProcId compatible with AppGroupT
  using actions_seq = util::sequence::filter_t< typename NativeT::template compatible_processable_impls<ProcId>, belong_to_appgroup >;

  using action_type = typename actions_seq::value_type;

private:

  // Pick the head for example, does not matter as all of them share the same tuple_resolve_t, hence same tuple_feed_t
  using tuple_feed_t = app::tuple_feed_t< util::sequence::head_v< actions_seq > >;
  // using tuple_feed_t = app::tuple_feed_t< util::sequence::head_v< app::impls_of_t<AppGroupT::id_value> > >; WRONG

  using local_encoders_t =
    util::tuple_t<
      feat::encoder<feat::kind::depth, depth_t>,
      feat::encoder<feat::kind::app_call, actions_seq>,
      feat::encoder<feat::kind::app_params, tuple_feed_t>
    >;

protected:

  ////////////////// Aggregate all encoders
  using tuple_encoders = util::tuple::cat_t< ref_encoders_t, local_encoders_t >;


protected:

  static constexpr std::size_t NUsers = NativeT::template max_threads<ProcId>;

  static constexpr std::size_t NHiddenLayers = 0; // HYPERPARAM XXX
  static constexpr std::size_t NHiddenNeurons = 5; // HYPERPARAM XXX

protected:

  // Apparently when C++20 is fully implemented we could turn this into constexpr
  static str_t str_identifier() {
    return str_t("actor_implementer_" + NativeT::template get_proc_str<ProcId>() + "_" + NativeT::template get_appgroup_str<AppGroupT>());
  }

};

} // namespace learn::agent::common
