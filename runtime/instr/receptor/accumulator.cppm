

export module SteelRT.Instrument.Receptor.Accumulator


namespace instr::receptor {


template <>
class backend <receptor::kind::accumulator> {
private:

  static std::mutex s_logMutex;

  static std::map<std::thread::id, std::pair<thread_id_t, std::string>> s_subscribedThreads;


  struct datum {
    enum_uint_t eventTypeId;
    enum_uint_t eventValueId;
    std::array<uchar_t, MaxDatumSize> buffer;
  };

  std::vector< datum > m_accumulated;

public:

  static constexpr receptor::usable allowed_use = receptor::usable::by_pilot;

public:

  static void subscribe_thread(thread_id_t thId, const std::string sv) {

    std::lock_guard<std::mutex> lck(s_logMutex);

    // std::cout << oss.str() << std::endl;
    // Put in other datum;

    s_subscribedThreads[std::this_thread::get_id()] = std::make_pair(thId, sv);

  }


  template <typename... EnumEventT>
  static raii_instrer initialize( const std::string& strLogFilename, util::tuple_t<EnumEventT...> ) {

    m_accumulated.resize( 1024 );
    // For all that has fixed format

    oss << "[ThreadId " << std::this_thread::get_id() << "] : Trace logger successfully initialized\n";
    oss << "Expected event kinds to receive : ";
    ((oss << event::type<EnumEventT>::name << ','), ...);
  }

private:

  template <typename... EnumEventT>
  static void finalize(util::tuple_t<EnumEventT...>) {
    // Ignore EnumEventT types
    std::ostringstream oss;
    oss << "[ThreadId " << std::this_thread::get_id() << "] : Trace logger successfully finalized";

    std::cout << oss.str() << std::endl;
  }


  template <
    auto EnumVal,
    util::req_t< event::is_enabled<decltype(EnumVal)> >...,
    typename... PrintArgT
  >
  static void trace(PrintArgT&&... args) noexcept {

    const auto& [intId, strId] = s_subscribedThreads[std::this_thread::get_id()];

    std::ostringstream oss;

    // Create datum XXX
    // oss << s_processId << " ::: " << "[" << strId << "] : event::" << event::type<decltype(EnumVal)>::name << "::" << event::value<EnumVal>::name << " -- ";
    ( (oss << args << ','), ... );

    std::lock_guard<std::mutex> lck(s_logMutex);

    m_accumulated.push_back( datum );
  }

};


} // namespace instr::receptor
