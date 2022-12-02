
export module SteelRT.Instrument.Receptor.Logger;


namespace instr::receptor {


template <>
class backend <receptor::kind::logger> {
private:

  static std::mutex s_logMutex;
  static std::streambuf* s_oldLogBuf;
  static std::ofstream s_newOfs;

  static std::map<std::thread::id, std::pair<thread_id_t, std::string>> s_subscribedThreads;

public:

  static constexpr receptor::usable allowed_use = receptor::usable::by_either;

public:

  static void subscribe_thread(thread_id_t thId, const std::string sv) {
    std::ostringstream oss;
    oss << s_processId << " ::: " << "Subscribing thread : " << static_cast<unsigned>(thId) << " -> " << sv;

    std::lock_guard<std::mutex> lck(s_logMutex);

    std::clog << oss.str() << std::endl;

    s_subscribedThreads[ std::this_thread::get_id() ] = std::make_pair( thId, sv );
  }


  template <typename... EnumEventT>
  static raii_instrer initialize( const char processIdentifier, const std::string& strLogFilename, util::tuple_t<EnumEventT...> ) {


    s_processId = processIdentifier;

    s_newOfs = std::ofstream( strLogFilename.c_str() );

    std::ostringstream oss;

    oss << "[ThreadId " << std::this_thread::get_id() << "] : Trace logger successfully initialized\n";
    oss << "Expected event kinds to receive : ";
    ((oss << event::type<EnumEventT>::name << ','), ...);


    s_oldLogBuf = std::clog.rdbuf();
    std::clog.rdbuf(s_newOfs.rdbuf());
    std::clog << oss.str() << std::endl;


    subscribe_thread(global::MainThreadId, "MainThread");

    return raii_instrer( std::bind( &finalize<EnumEventT...>, util::tuple_t<EnumEventT...>{} ) );
  }

private:

  template <typename... EnumEventT>
  static void finalize(util::tuple_t<EnumEventT...>) {
    // Ignore EnumEventT types
    std::ostringstream oss;
    oss << "[ThreadId " << std::this_thread::get_id() << "] : Trace logger successfully finalized";

    std::clog << oss.str() << std::endl;
    std::clog.rdbuf(s_oldLogBuf);
  }

public:

  template <
    auto EnumVal,
    util::req_t< event::is_enabled<decltype(EnumVal)> >...,
    typename... PrintArgT
  >
  static void trace(PrintArgT&&... args) noexcept {

    const auto& [intId, strId] = s_subscribedThreads[std::this_thread::get_id()];

    std::ostringstream oss;

    oss << s_processId << " ::: " << "[" << strId << "] : event::" << event::type<decltype(EnumVal)>::name << "::" << event::value<EnumVal>::name << " -- ";
    ( (oss << args << ','), ... );

    std::lock_guard<std::mutex> lck(s_logMutex);
    
    std::clog << oss.str() << std::endl;
  }


  template <
    auto... EnumVal,
    util::req_t< std::conjunction<std::is_enum<decltype(EnumVal)>, instr::event::is_instrumentable<decltype(EnumVal)>...> >...
  >
  static void trace_conv() noexcept {

    const auto& [intId, strId] = s_subscribedThreads[ std::this_thread::get_id() ];

    std::ostringstream oss;

    oss << s_processId << " ::: " << "[" << strId << "] : event::";
    ((oss << event::type<decltype(EnumVal)>::name << "::" << event::value<EnumVal>::name << ','), ...);

    std::lock_guard<std::mutex> lck(s_logMutex);

    std::clog << oss.str() << std::endl;
  }

};


} // namespace instr::receptor
