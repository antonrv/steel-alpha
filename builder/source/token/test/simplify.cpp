
#include "source/token/test/interface.hpp"

#include "source/token/make/piece.hpp"
// #include "source/token/make/token.hpp" // TMP XXX

#include "source/token/simplify/interface.hpp"

#include "options/state/log.hpp"

#include <stdexcept>
#include <iostream>


namespace bld::src::pc {

static
void test_simplify(const std::string& inputStr, const std::string& expectStr) {

  auto pc = make_piece( inputStr );

  // Passed by reference, so pc may be replaced by another of other kind

  state::log<opt_kind::log_simplify>("Testing input", inputStr);

  auto simpl = simplify_piece( pc );

  if (simpl->get_pc_string() != expectStr) {
    throw std::runtime_error("test_simplify failed -unexpected string- for \"" + inputStr + "\". Got : \"" + simpl->get_pc_string() + "\". expected : \"" + expectStr + "\"");
  } else {
    // OK
  }
}

template <>
void run_tests<token_test::simplify>() {

  // auto wickedFrac = make_token< kind::fraction >( make_piece("a") , make_token< kind::fraction >( make_piece("a"), make_piece("b") ) );
  // std::cout << "Wick frac: " << wickedFrac->get_pc_string() << '\n';
  // // auto rng1 = make_token< kind::range >( make_num(0), edit_piece( wickedFrac ) );
  // auto rng2 = make_token< kind::range >( make_num(0), make_token< kind::cs_list >( edit_piece( wickedFrac ), edit_piece( wickedFrac ) ) );
  // // std::cout << "Wick range 1: " << rng1->get_pc_string() << " simpl : " << simplify_piece( rng1 )->get_pc_string() << '\n';
  // auto simpl = simplify_piece( rng2 );
  // std::cout << "Wick range 2: " << rng2->get_pc_string() << " simpl : " << simpl->get_pc_string() << '\n';

  test_simplify("13u", "13");
  test_simplify("13", "13");
  test_simplify("-13", "(-13)");
  test_simplify("var", "var");
  test_simplify("-var", "(-var)");
  test_simplify("0", "0");

  // Operate on fractions
  test_simplify("3/2", "(3/2)");
  test_simplify("-3/2", "(-1)*(3/2)");
  test_simplify("3/(-2)", "(-1)*(3/2)");
  test_simplify("(-3)/(-2)", "(3/2)");
  test_simplify("0/2", "0");

  test_simplify("a + a", "(2*a)");
  test_simplify("a + 3*a", "(4*a)");
  test_simplify("x*y*z + 3*x*y*z", "(4*x*y*z)");
  test_simplify("6*x*y*z*5 + 3*x*y*4*z", "(42*x*y*z)");

  test_simplify("21+3+524+j+(7*j)","(548+(8*j))");
  // test_simplify("4*((a*b)/(c*d))*5 + 5*((a*b)/(c*d))*6", "(50*(a*b)/(c*d))"); TODO

  test_simplify("21+3+524+j+(7*j)","(548+(8*j))");

  test_simplify("vara/varb", "(vara/varb)");
  test_simplify("-vara/varb", "(-1)*(vara/varb)");
  test_simplify("vara/(-varb)", "(-1)*(vara/varb)");
  test_simplify("(-vara)/(-varb)", "(vara/varb)");

  test_simplify("(vara*varb)/vara", "varb");
  test_simplify("(vara*varb)/varb", "vara");
  test_simplify("(vara*varb*varc)/vara", "(varb*varc)");
  test_simplify("(vara*varb*varc)/varb", "(vara*varc)");
  test_simplify("(vara*varb*varc)/varc", "(vara*varb)");

  test_simplify("(vara*varb*varc)/(vara*varb)", "varc");
  test_simplify("(vara*varb*varc)/(varb*varc)", "vara");
  test_simplify("(vara*varb*varc)/(vara*varc)", "varb");

  test_simplify("((-1)*vara*varb*varc)/(vara*varb)", "(-varc)");
  test_simplify("(vara*(-varb)*varc)/(varb*varc)", "(-vara)");
  test_simplify("(vara*varb*varc)/((-1)*vara*varc)", "(-varb)");
  test_simplify("(vara*varb*varc)/((-vara)*varc)", "(-varb)");
  test_simplify("(vara*varb*varc)/(vara*(-varc))", "(-varb)");

  test_simplify("(((iBs*iLV)+(iBs*off))/iBs)", "(iLV+off)");
  test_simplify("((((-1)*iBs*iLV)+(iBs*off))/iBs)", "((-iLV)+off)");
  test_simplify("((((-iBs)*iLV)+(iBs*off))/iBs)", "((-iLV)+off)");
  test_simplify("(((iBs*(-iLV))+(iBs*off))/iBs)", "((-iLV)+off)");

  test_simplify("(((iBs*iLV)+((-1)*iBs*off))/iBs)", "((-off)+iLV)");
  test_simplify("(((iBs*iLV)+((-iBs)*off))/iBs)", "((-off)+iLV)");
  test_simplify("(((iBs*iLV)+(iBs*(-off)))/iBs)", "((-off)+iLV)");

  test_simplify("((iBs*iLV)+(iBs*off))/(iBs*iLV)", "(1+(off/iLV))");
  test_simplify("(((-iBs)*iLV)+(iBs*off))/(iBs*iLV)", "((-1)+(off/iLV))");
  test_simplify("((iBs*(-iLV))+(iBs*off))/(iBs*iLV)", "((-1)+(off/iLV))");
  test_simplify("((-1)*(iBs*iLV)+(iBs*off))/(iBs*iLV)", "((-1)+(off/iLV))");

  test_simplify("((a*b*c)/(c*d))", "((a*b)/d)");
  test_simplify("((a*(b/d)*(e*(c/e))))/(e*(c/e))", "((a*b)/d)");

  test_simplify("(-1)*vara*varb + vara*varb","0");
  test_simplify("(-vara)*varb + vara*varb","0");
  test_simplify("vara*(-varb) + vara*varb","0");
  test_simplify("vara*varb + (-vara)*varb","0");
  test_simplify("vara*varb + vara*(-varb)","0");
  test_simplify("vara*varb + (-1)*vara*varb","0");

  test_simplify("8/varb", "(8/varb)");
  test_simplify("-8/varb", "(-1)*(8/varb)");
  test_simplify("8/(-varb)", "(-1)*(8/varb)");
  test_simplify("(-8)/(-varb)", "(8/varb)");

  test_simplify("vara/7", "(vara/7)");
  test_simplify("-vara/7", "(-1)*(vara/7)");
  test_simplify("vara/(-7)", "(-1)*(vara/7)");
  test_simplify("(-vara)/(-7)", "(vara/7)");

  test_simplify("6/2", "3");
  test_simplify("-6/2", "(-3)");
  test_simplify("6/(-2)", "(-3)");
  test_simplify("(-6)/(-2)", "3");

  test_simplify("6/6", "1");
  test_simplify("-6/6", "(-1)");
  test_simplify("6/(-6)", "(-1)");
  test_simplify("(-6)/(-6)", "1");

  test_simplify("var/var", "1");
  test_simplify("-var/var", "(-1)");
  test_simplify("(-var)/var", "(-1)");
  test_simplify("var/(-var)", "(-1)");
  test_simplify("(-var)/(-var)", "1");

  test_simplify("(a*b)/(c*d)", "((a*b)/(c*d))");
  test_simplify("(-a*b)/(c*d)", "(-1)*((a*b)/(c*d))");
  test_simplify("(a*b)/(-c*d)", "(-1)*((a*b)/(c*d))");
  test_simplify("(-a*b)/(-c*d)", "((a*b)/(c*d))");

  test_simplify("(a*b)/(a*b)", "1");
  test_simplify("(-a*b)/(a*b)", "(-1)");
  test_simplify("(a*b)/(-a*b)", "(-1)"); 
  test_simplify("(-a*b)/(-a*b)", "1");

  test_simplify("4*6/(8)", "3");

  test_simplify("6/(8/4)", "3");
  test_simplify("-6/(8/4)", "(-3)");
  test_simplify("6/(-8/4)", "(-3)");
  test_simplify("(-6)/(-8/4)", "3");



  test_simplify("0 + 6", "6");
  test_simplify("6- 6", "0");
  test_simplify("5 + 6", "11");
  test_simplify("5 - 6", "(-1)");
  test_simplify("5 + (-6)", "(-1)");
  test_simplify("-5 + 6", "1");
  test_simplify("-5 - 6", "(-11)");
  test_simplify("-5 + (-6)", "(-11)");
  test_simplify("42 - 42", "0");
  test_simplify("42 +(- 42)", "0");
  test_simplify("-42 + 42", "0");

  test_simplify("6/4 - 3/2", "0");
  test_simplify("6/4 + 3/2", "3");

  test_simplify("25 + 6/4 + 3/2", "28");

  test_simplify("var + 5 + 6", "(11+var)");
  test_simplify("var + 5 - 6", "((-1)+var)");
  test_simplify("var + 5 + (-6)", "((-1)+var)");
  test_simplify("var  -5 + 6", "(1+var)");
  test_simplify("var  -5 - 6", "((-11)+var)");
  test_simplify("var  -5 + (-6)", "((-11)+var)");
  test_simplify("var - var", "0");
  test_simplify("var +(- var)", "0");
  test_simplify("-var + var", "0");
  test_simplify("1*var + (-1)*var", "0");

  test_simplify("(5 + 6) + (7 +8)", "26");
  test_simplify("(5 + 6/3) + (10/2 + 16/4)", "16");

  test_simplify("(-28)+(4*8)", "4");
  test_simplify("(5 + 6/3) + (10/2 + 16/(4*8 - 28))", "16");


  test_simplify("-3*4", "(-12)");
  test_simplify("5*6*var", "(30*var)");
  test_simplify("5*(-6)*var", "(-1)*(30*var)");
  test_simplify("0*3*var", "0");


  test_simplify("3/1*var", "(3*var)");
  test_simplify("-3/1*var", "(-1)*(3*var)");
  test_simplify("1/3*var", "(var/3)");
  test_simplify("-1/3*var", "(-1)*(var/3)");

  test_simplify("1/(1/2)", "2");
  test_simplify("1/(-1/2)", "(-2)");
  test_simplify("1/(1/(-2))", "(-2)");

  test_simplify("(1/2)/2", "(1/4)");
  test_simplify("((-1)/2)/2", "(-1)*(1/4)");
  test_simplify("(1/(-2))/2", "(-1)*(1/4)");
  test_simplify("(1/2)/(-2)", "(-1)*(1/4)");
  
  test_simplify("(3/4)/(4/2)", "(3/8)");
  test_simplify("(-3/4)/(4/2)", "(-1)*(3/8)");
  test_simplify("(3/(-4))/(4/2)", "(-1)*(3/8)");
  test_simplify("(3/4)/((-4)/2)", "(-1)*(3/8)");
  test_simplify("(3/4)/(4/(-2))", "(-1)*(3/8)");
  test_simplify("(3/(-4))/(4/(-2))", "(3/8)");
  test_simplify("((-3)/(-4))/((-4)/(-2))", "(3/8)");

  test_simplify("3*(6*4*var)", "(72*var)");
  test_simplify("(-3)*(6*4*var)", "(-1)*(72*var)");
  test_simplify("3*((-6)*4*var)", "(-1)*(72*var)");
  test_simplify("3*(6*4*(-var))", "(-1)*(72*var)");

  test_simplify("varb*(6*4*vara)", "(24*vara*varb)");
  test_simplify("(-varb)*(6*4*vara)", "(-1)*(24*vara*varb)");
  test_simplify("varb*((-6)*4*vara)", "(-1)*(24*vara*varb)");
  test_simplify("varb*(6*4*(-vara))", "(-1)*(24*vara*varb)");

  test_simplify("(a*b*4)*(c*d*0)", "0");
  test_simplify("(a*b*4)*(c*d*8)", "(32*a*b*c*d)");
  test_simplify("(a*b*4)*(c*d*(-8))", "(-1)*(32*a*b*c*d)");
  test_simplify("(a*b*4*(5*10*e)*(2*f))*(c*d*8)", "(3200*a*b*c*d*e*f)");
  test_simplify("(a*b*4*(5*10*e)*((-2)*f))*(c*d*8)", "(-1)*(3200*a*b*c*d*e*f)");
  test_simplify("(a*b*4*(5*10*e)*((-2)*f))*(c*d*(-8))", "(3200*a*b*c*d*e*f)");

  test_simplify("a*(b+c)", "((a*b)+(a*c))");
  test_simplify("a*(b+c)*4", "((4*a*b)+(4*a*c))");
  test_simplify("a*5*(b+c)*4", "((20*a*b)+(20*a*c))");
  test_simplify("a*(-5)*(b+c)*4", "((-1)*(20*a*b)+(-1)*(20*a*c))");
  test_simplify("4*a*(5*b+2*c)", "((20*a*b)+(8*a*c))");
  test_simplify("4*a*((-5)*b+2*c)", "((-1)*(20*a*b)+(8*a*c))");

  test_simplify("5*6*10/3", "100");
  test_simplify("5*6*10/(-4)", "(-75)");
  test_simplify("5*6*10/(-4)*10", "(-750)");
  test_simplify("1/(1/(8/(2*2)))", "2");
  test_simplify("5*6*10/(-4*4)", "(-1)*(75/4)");

  test_simplify("5*6*20/10*(2*4)", "480");
  test_simplify("5*6*10/10*(2*4)", "240");
  test_simplify("5*6*10/10*((-2)*4)", "(-240)");

  test_simplify("(vara*varb)*5*6*20/10*(2*4)", "(480*vara*varb)");
  test_simplify("((vara*varb*10)/1)", "(10*vara*varb)");
  test_simplify("((vara*varb*480)/48)", "(10*vara*varb)");
  test_simplify("(vara*varb/48)*5*6*20/10*(2*4)", "(10*vara*varb)");

  test_simplify("(vara*varb)*5*0*20/10*(2*4)", "0");

  test_simplify("(a*(0+27))", "(27*a)");
  test_simplify("((a/b)*(0+27))", "((27*a)/b)");

  test_simplify("(nColBlocks*(nCols/nColBlocks)*(nRows/nRowBlocks))/(nColBlocks*(nCols/nColBlocks))", "(nRows/nRowBlocks)");
  test_simplify("((-r)*nCols*nRows)/nRowBlocks+(nCols*nRows*r)/nRowBlocks", "0");
  test_simplify("(r*nCols*(-27)*nRows)/nRowBlocks+(nCols*nRows*r)*(27/nRowBlocks)", "0");



}

} // namespace bld::src::pc
