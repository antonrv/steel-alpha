


namespace instr {

  void log::subscribe_thread(thread_id_t thId, const std::string sv);

  template <typename... EnumTraceT>
  void log::initialize(std::tuple<EnumTraceT...>);

  template <typename... EnumTraceT>
  void log::finalize(std::tuple<EnumTraceT...>);

  template <
    auto EnumVal,
    util::req_t< event::is_enabled<decltype(EnumVal)> >...,
    typename... PrintArgT
  >
  void trace(PrintArgT&&... args);

  template <
    auto EnumVal,
    util::req_t< std::negation< event::is_enabled<decltype(EnumVal)> > >...,
    typename... PrintArgT
  >
  void trace(PrintArgT&&... args);

} // namespace instr

    // All arguments of TRACE commands are printed. The thread id is appended at the head.
    
    #define INITIALIZE_INSTRUMENT() instr::log::initialize(instr::filter_enum_trace_tuple_t<ENUM_EVENT_FULL_SEQUENCE>{})

    #define SUBSCRIBE_TRACE(thId, sv) instr::log::subscribe_thread(thId, sv)
    
    #define TRACE(EnumVal, ...) instr::log::trace<instr::event:: EnumVal>(__VA_ARGS__)

    // #define TRACE_CONVERT(OrigEnumV, EventT) instr::log::trace<steel::event_of_v<OrigEnumV, instr:: EventT>>( std::this_thread::get_id(), "")

    // #define QUANTIFY(EnumVal, q) instr::log::quantify<instr:: EnumVal>(std::this_thread::get_id(), q)
    
    #define FINALIZE_INSTRUMENT() instr::log::finalize(instr::filter_enum_trace_tuple_t<ENUM_EVENT_FULL_SEQUENCE>{})

#endif // ENABLE_TRACE_LOG == 1
