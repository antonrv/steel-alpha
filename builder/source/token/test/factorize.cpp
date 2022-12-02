
#include "source/token/test/interface.hpp"

#include "source/token/make/piece.hpp"

#include "source/token/factorize.hpp"

#include <stdexcept>
#include <iostream>

namespace bld::src::pc {

static
void test_factorize_var(const std::string inputStr, const std::string expectStr) {

  auto pc = make_piece( inputStr );

  auto fct = extract_factors( pc.get(),
    [] (cpiece_t pivPc) {
      return pivPc->get_kind() == kind::var and static_cast<ctoken_t<kind::var>>(pivPc)->get_unsigned_name() == "VAR";
    }
    );

  if (fct->get_pc_string() != expectStr) {
    throw std::runtime_error("test_factorize failed -unexpected factors- for \"" + inputStr + "\". Got : \"" + fct->get_pc_string() + "\". expected : \"" + expectStr + "\"");
  }

}

// static
// void test_common_factors(const std::string inputAStr, const std::string inputBStr, const std::string expectStr) {
// 
//   auto pcA = make_piece( inputAStr );
//   auto pcB = make_piece( inputBStr );
// 
//   auto fct = extract_common_factors( pcA.get(), pcB.get() );
// 
//   if (fct->get_pc_string() != expectStr) {
//     throw std::runtime_error("test_factorize failed -unexpected common factors- for \"" + inputAStr + "\" and \"" + inputBStr + "\". Got : \"" + fct->get_pc_string() + "\". expected : \"" + expectStr + "\"");
//   }
// }



template <>
void run_tests<token_test::factorize>() {

  test_factorize_var("a", "0");
  test_factorize_var("VAR", "1");
  test_factorize_var("-VAR", "(-1)");

  test_factorize_var("a*b*VAR", "(a*b)");
  test_factorize_var("a*b*(-VAR)", "(-1)*(a*b)");
  test_factorize_var("VAR/(512*a*b)", "((1/512)/(a*b))");
  test_factorize_var("VAR", "1");
  test_factorize_var("1*VAR", "1");

  test_factorize_var("27 + VAR", "1");
  test_factorize_var("27*VAR + VAR", "28");
  test_factorize_var("27*VAR + (1+2*VAR)", "29");

  test_factorize_var("(a*VAR + b*VAR)", "(a+b)");
  test_factorize_var("(a*VAR + b*c*VAR)", "(a+(b*c))");
  test_factorize_var("((c*b)+(d*e*VAR))", "(d*e)");

  test_factorize_var("(a*(b+c*VAR))", "(a*c)");

  test_factorize_var("(a*(b+c*(d + e*VAR)))", "(a*c*e)");
  test_factorize_var("(a*(b+c*(d + e*(f + g*VAR))))", "(a*c*e*g)");


  test_factorize_var("(((c*b)+(d*e*VAR))+(cc+(b*rr)))", "(d*e)");
  test_factorize_var("(((c*b)+(d*e*u))+(cc+(b*VAR)))", "b");
  test_factorize_var("(((c*b)+(d*e*u))+f*(cc+(b*VAR)))", "(b*f)");


  // test_extract_from("1", "1", "1");


  // test_extract_from("1", "a", "a");
  // test_extract_from("a", "1", "0");

  // test_extract_from("4", "a", "4");
  // test_extract_from("a", "4", "4");

  // test_extract_from("4", "a", "4");
  // test_extract_from("a", "4", "4");
  // test_extract_from("a", "a", "a");

  // test_extract_from("a", "b", "1");
  // test_extract_from("b", "a", "1");


  // test_extract_from("b/a", "b", "b");
  // 

  // test_extract_from("a*a", "a", "a");
  // test_extract_from("a*27", "a", "a");
  // test_extract_from("a*27", "27", "27");

  // test_extract_from("(a+b)", "a", "1"); // a do not intersect with (a+b)
  // test_extract_from("(a+b)", "c", "1");
}

} // namespace bld::src::pc
