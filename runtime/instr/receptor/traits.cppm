


namespace instr::event {

  enum class kind : enum_uint_t { option, mandatory };

  enum class cost : enum_uint_t { intensive, extensive };



template <>
struct traits <event::global_runner> {
  static constexpr event::kind event_kind = event::kind::option;
  static constexpr event::cost event_cost = event::cost::intensive;
  static constexpr receptor::usable allowed_users = receptor::usable::by_runner;
};

template <>
struct traits <event::global_pilot> {
  static constexpr event::kind event_kind = event::kind::mandatory;
  static constexpr event::cost event_cost = event::cost::intensive;
  static constexpr receptor::usable allowed_users = receptor::usable::by_pilot;
};


template <>
struct traits <event::learn_monitor> {

  static constexpr event::kind event_kind = event::kind::option;
  static constexpr event::cost event_cost = event::cost::extensive;
  static constexpr receptor::usable allowed_users = receptor::usable::by_pilot;

  // We could do the following. NO, will require additional template parameters in receptor::backend, and we don't want that. Process as pure strings
  // // Trace formatting info (for accumulator)
  // using fixed_format = util::sequence::enum_t<event::learn_monitor,
  //     event::learn_monitor::update_step,
  //     event::learn_monitor::update_result
  //   >;

  // template <event::learn_monitor EnumV>
  // struct format_of;

  // template <>
  // struct format_of <event::learn_monitor::update_step> {
  //   using type = std::tuple<float, float, float>;
  // };

  // template <>
  // struct format_of <event::learn_monitor::update_result> {
  //   using type = std::tuple<float, float, float, float>;
  // };

};


} // namespace instr::event
