export module SteelRT.Instrument;

// Need to export, to transitively export AllEvents
  export import SteelRT.Instrument.AllEvents;
  export import SteelRT.Instrument.Predicates;
  export import SteelRT.Instrument.FwDeclarations;
  
  export import SteelRT.Instrument.Ostream;
// import SteelRT.Util.Types;
// import SteelRT.Util.Values;
//export import SteelRT.Util.Require;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
// import SteelRT.Util.Tuple;

import <fstream>;
import <mutex>;
import <thread>;
import <string>;
export import <map>;
export import <sstream>;

  // fw declarations
namespace instr {

// When implemented other instrers different than logger, factor this out TODO
export
class raii_instrer {
  using callback_t = std::function<void(void)>;
  callback_t m_finalizeCallback;
public:
  raii_instrer(callback_t&& cb) : m_finalizeCallback(cb) {}

  ~raii_instrer() {
    m_finalizeCallback();
  }
};

class log {
private:
  static std::mutex s_logMutex;
  static std::streambuf* s_oldLogBuf;
  static std::ofstream s_newOfs;

  static char s_processId; // Either R or P (Runner or Pilot)

  static std::map<std::thread::id, std::pair<thread_id_t, std::string>> s_subscribedThreads;

public:

  static void subscribe_thread(thread_id_t thId, const std::string sv) {
    std::ostringstream oss;
    oss << s_processId << " ::: " << "Subscribing thread : " << static_cast<unsigned>(thId) << " -> " << sv;

    std::lock_guard<std::mutex> lck(s_logMutex);
    if (s_processId == 'R') {

      std::clog << oss.str() << std::endl;

    } else { // if (s_processId == 'P')

      std::cout << oss.str() << std::endl;
    }
    s_subscribedThreads[std::this_thread::get_id()] = std::make_pair(thId, sv);
  }

  template <typename... EnumEventT>
  static raii_instrer initialize( const char processIdentifier, const std::string& strLogFilename, util::tuple_t<EnumEventT...> ) {

    if  (processIdentifier != 'P' and processIdentifier != 'R') {
      throw std::runtime_error("Trace logger require process identifier 'R' (runner) or 'P' (pilot)");
    }
    if (strLogFilename.empty()) {
      throw std::runtime_error("Log filename must be non-empty");
    }

    s_processId = processIdentifier;

    // if (s_processId == 'R') {
    s_newOfs = std::ofstream( strLogFilename.c_str() );
    // }

    std::ostringstream oss;

    oss << "[ThreadId " << std::this_thread::get_id() << "] : Trace logger successfully initialized\n";
    oss << "Expected event kinds to receive : ";
    ((oss << event::type<EnumEventT>::name << ','), ...);

    if (s_processId == 'R') {

      s_oldLogBuf = std::clog.rdbuf();
      std::clog.rdbuf(s_newOfs.rdbuf());
      std::clog << oss.str() << std::endl;

    } else { // if (s_processId == 'P')
      s_oldLogBuf = std::clog.rdbuf();

      std::clog.rdbuf(s_newOfs.rdbuf());

      std::clog << oss.str() << std::endl;
      std::cout << oss.str() << std::endl;
    }

    subscribe_thread(global::MainThreadId, "MainThread");

    return raii_instrer( std::bind( &finalize<EnumEventT...>, util::tuple_t<EnumEventT...>{} ) );
  }


private:

  template <typename... EnumEventT>
  static void finalize(util::tuple_t<EnumEventT...>) {
    // Ignore EnumEventT types
    std::ostringstream oss;
    oss << "[ThreadId " << std::this_thread::get_id() << "] : Trace logger successfully finalized";

    if (s_processId == 'R') {
      std::clog << oss.str() << std::endl;
      std::clog.rdbuf(s_oldLogBuf);
    } else { // if (s_processId == 'P')
      std::clog << oss.str() << std::endl;
      std::clog.rdbuf(s_oldLogBuf);
    }
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
    
    if (s_processId == 'R') {
      std::clog << oss.str() << std::endl;
    } else { // if (s_processId == 'P') 

      if constexpr (not std::is_same_v<decltype(EnumVal), event::global_pilot>) {
        std::clog << oss.str() << std::endl;
      } else {
        std::cout << oss.str() << std::endl;
      }
    }
  }

  template <
    auto... EnumVal,
    util::req_t< std::conjunction<std::is_enum<decltype(EnumVal)>, instr::event::is_instrumentable<decltype(EnumVal)>...> >...
  >
  static void trace_conv() noexcept {

    const auto& [intId, strId] = s_subscribedThreads[std::this_thread::get_id()];

    std::ostringstream oss;

    oss << s_processId << " ::: " << "[" << strId << "] : event::";
    ((oss << event::type<decltype(EnumVal)>::name << "::" << event::value<EnumVal>::name << ','), ...);

    std::lock_guard<std::mutex> lck(s_logMutex);

    if (s_processId == 'R') {
      std::clog << oss.str() << std::endl;
    } else { // if (s_processId == 'P') 
      std::cout << oss.str() << std::endl;
    }
  }
};



////////////////////////////
//
// Actual public interface. Maps to a 'logging' instration
//
////////////////////////////

export
raii_instrer initialize(const char processIdentifier, const std::string& instrFn);

// export
// void finalize();

export
void subscribe_thread(thread_id_t thId, const std::string sv);

export
template <
  auto EnumVal,
  util::req_t< event::is_enabled<decltype(EnumVal)> >...,
  typename... PrintArgT
>
inline
void trace(PrintArgT&&... args) noexcept {
  log::trace<EnumVal>(std::forward<PrintArgT>(args)...);
}

export
template <
  auto EnumVal,
  util::req_t< std::negation< event::is_enabled<decltype(EnumVal)> > >...,
  typename... PrintArgT
>
inline
void trace(PrintArgT&&... args) noexcept {
  // Do nothing. Event type is disabled
}

// To instrument enum values that are instrumentable
export
template <
  auto... EnumVal,
  util::req_t< std::conjunction<std::is_enum<decltype(EnumVal)>, instr::event::is_instrumentable<decltype(EnumVal)>...> >...
>
inline
void trace_conv() noexcept {
  log::trace_conv<EnumVal...>();
}

} // namespace instr
