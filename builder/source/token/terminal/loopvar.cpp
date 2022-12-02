
#include "source/token/terminal/loopvar.hpp"

#include "source/token/combine/interface.hpp"

#include "common/util.hpp"
#include "source/token/make/copy.hpp"


namespace bld::src::pc {

///////////////// LOOPOPS  <--- MULTIPLE

#ifdef PARSER_TEST
static loop_var::opkinds_t UndefinedOps({opkind::undefined, opkind::undefined, opkind::undefined});
#endif // PARSER_TEST

own_cpiece_t make_undefined_lv_piece() {
  return make_num( 9999 );
}

// Main constructor
loop_var::loop_var(ctoken_t<kind::var> var, own_cpiece_t startOp, opkind startOpk, own_cpiece_t boundOp, opkind boundOpk, own_cpiece_t sweepOp, opkind sweepOpk) :
super_type(*var), // Copy constructor
m_operations({std::move(startOp), std::move(boundOp), std::move(sweepOp)}),
m_opkinds({startOpk, boundOpk, sweepOpk})
{ }

// Testing purposes
#ifdef PARSER_TEST
loop_var::loop_var(const token<kind::var>& inVar) :
super_type(inVar), // Copy constructor
m_operations({make_num(0), make_num(0), make_num(0)}),
m_opkinds(UndefinedOps)
{ }
#endif // PARSER_TEST

loop_var::loop_var(const loop_var& other) :
super_type(other), // Copy constructor
m_operations({
  edit_piece(other.get_expression<lv_trait::start>()),
  edit_piece(other.get_expression<lv_trait::bound>()),
  edit_piece(other.get_expression<lv_trait::sweep>())
}),
m_opkinds(other.m_opkinds)
{}

std::string loop_var::get_info() const {

  if (this->all_defined()) {
    return 
      "\nLoopOps{Start : " + this->get_expression<lv_trait::start>()->get_pc_string() + ";" +
      "Bound : " + this->get_expression<lv_trait::bound>()->get_pc_string() + ";" +
      "Sweep : " + this->get_expression<lv_trait::sweep>()->get_pc_string() + "|"
      "Var:" + super_type::get_pc_string() + "}";
  
  } else {

    std::string str = "\n\tStart : " +
      this->get_expression<lv_trait::start>()->get_pc_string() + " " + util::enum_convert<opkind>::to_string_rt(get_opkind<lv_trait::start>()) + "\n\tBound : " +
      this->get_expression<lv_trait::bound>()->get_pc_string() + " " + util::enum_convert<opkind>::to_string_rt(get_opkind<lv_trait::bound>()) + "\n\tSweep : " +
      this->get_expression<lv_trait::sweep>()->get_pc_string() + " " + util::enum_convert<opkind>::to_string_rt(get_opkind<lv_trait::sweep>()) + "\n";

    return 
      "\nLoopOps{NotAllDefined|" + str +
      "Var:" + super_type::get_pc_string() + "}";
  }

}

bool loop_var::nested_in( const loop_var * lv ) const {
  return super_type::goes_after_than( lv );
}

bool loop_var::all_defined() const {

  auto undefPc = make_undefined_lv_piece();

  return
      not (this->get_opkind<lv_trait::start>() == opkind::undefined) and
      not (this->get_opkind<lv_trait::bound>() == opkind::undefined) and
      not (this->get_opkind<lv_trait::sweep>() == opkind::undefined) and
      (not are_equal( this->get_expression<lv_trait::start>(), undefPc.get()) ) and
      (not are_equal( this->get_expression<lv_trait::bound>(), undefPc.get()) ) and
      (not are_equal( this->get_expression<lv_trait::sweep>(), undefPc.get()) );
}

std::array<opkind, 3> loop_var::get_opkinds() const {
  return m_opkinds;
}

// Overrides virtual
bool loop_var::is_loop() const {
  return true;
}

// Overrides virtual
const loop_var * loop_var::get_loop_variable() const {
  return this;
}


} // namespace bld::src::pc
