


namespace instr::receptor {

  enum class kind : enum_uint_t { logger, outstream, accumulator, extrae };

  enum class usable : enum_uint_t { by_runner, by_pilot, by_either };

template <kind RecepKind>
class backend;


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



} // namespace instr
