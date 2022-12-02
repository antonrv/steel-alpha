


export module RunTestCases;

export import SteelRT.Test.BaseRunner;

export import TestCases; // Enum definitions

export import SteelRT.Instrument.EnabledEvents;

export import SteelRT.Safe;



export
namespace test {

class runner :
public
base_runner< runner,
    case_id::dim1_disjoint_correct_order
>
{
private:

  using super_type = base_runner< runner,
    case_id::dim1_disjoint_correct_order
  >;

public:
  template <case_id CaseId>
  void run_case();

  template <case_id CaseId>
  void verify_case();


public:
  runner(const std::string& filename) : super_type(filename) {}

};


} // namespace test
