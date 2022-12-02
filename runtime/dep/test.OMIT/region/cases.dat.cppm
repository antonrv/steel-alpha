export module TestCases;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;
import SteelRT.Instrument.FwDeclarations;

export
namespace test{


//////// case_id
enum class case_id : enum_uint_t {dim1_disjoint_correct_order = 2};
using enabled_case_ids = util::sequence::enum_t<case_id, case_id::dim1_disjoint_correct_order>;
}
// namespace test

export
namespace instr::event{
template <> struct type<test::case_id>{
static constexpr const char * name = "case_id";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};
template <> struct value<test::case_id::dim1_disjoint_correct_order>{static constexpr const char * name = "dim1_disjoint_correct_order"; };
}
// namespace instr::event
