
export module SteelRT.Test.BaseRunner;

import SteelRT.Util.Types;
import SteelRT.Util.Sequence;
export import SteelRT.Util.Indexable;

import SteelRT.Instrument.FwDeclarations;

export import SteelRT.Instrument;

export import SteelRT.Util.Values;

import SteelRT.Test.FwDeclarations;

export import <stdexcept>;
export import <iostream>;
export import <map>;
export import <string>;

export
namespace test {

template <typename DerivedRunnerT, case_id... CaseIds>
class base_runner {
private:

  const std::string m_testSuiteName = "undefined";

  using err_t = std::exception;
  using errors_t = std::map< std::string, err_t>;
  errors_t m_errors;

  template <case_id CaseId>
  void run_and_verify() {

    m_instrFn = m_testSuiteName + "_" + instr::event::value<CaseId>::name + ".log";

    try {

      {
        auto raiiInstr = instr::initialize(m_instrFn);

        static_cast<DerivedRunnerT*>(this)->template run_case<CaseId>();

      } // raiiInstr deleted. Trace dumped
      
      static_cast<DerivedRunnerT*>(this)->template verify_case<CaseId>();

      auto sig = global::get_signal();
      if (sig != 0) {
        throw std::runtime_error("Received signal : " + std::to_string(sig));
      }

      std::cerr << "Runtime test OK : " + m_instrFn + "\n";

    } catch (const std::exception& e) {

      std::cerr << "Runtime test FAILED : " + m_instrFn + " : " << e.what();

      // Set to 0 again to avoid failure on following test
      if (auto sig = global::get_signal()) {
        std::cerr << ". Got signal : " << sig << '\n';
        global::signal_handler(0);
      } else {
        std::cerr << '\n';
      }

      m_errors[m_instrFn] = err_t(e);
    }

  }


protected:

  std::string m_instrFn; // visible by derived

public:

  base_runner(std::string runnerStr) : m_testSuiteName(runnerStr) {}

  void run_cases() {
    ( run_and_verify<CaseIds>(), ... );
 
    if (not m_errors.empty()) {
      std::cout << "Got " << m_errors.size() << " errors in " + m_testSuiteName + "\n";
    }
    // Examine errors
    // for (auto [tn, err] : m_errors) {
    //   std::cerr << "Test : " << tn << ". Error : " << err.what() << '\n';
    // }
  }

};


} // namespace test
