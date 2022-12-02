
#include "source/token/test/interface.hpp"

#include "source/token/make/piece.hpp"


#include <stdexcept>

namespace bld::src::pc {

static
void test_make(std::string str, kind expectKind, std::string expectStr) {

  auto baseElem = make_piece(str);

  auto gotKind = baseElem->get_kind();

  if (gotKind != expectKind) {
    throw std::runtime_error("test_make failed for kind " + str + " got " + std::to_string((int)gotKind) + ". expected : " + std::to_string((int)expectKind));
  }

  if (baseElem->get_pc_string() != expectStr) {
    throw std::runtime_error("test_make failed for " + str + " got " + baseElem->get_pc_string() + ". expected : " + expectStr);
  }
}


template <>
void run_tests<token_test::make>() {

  test_make( "333", kind::num, "333");
  test_make( "-333", kind::num, "(-333)" );
  test_make( "4124u", kind::num, "4124" );

  test_make( "var", kind::var, "var" );
  test_make( "var4", kind::var, "var4" );
  test_make( "_var4", kind::var, "_var4" );
  test_make( "-var", kind::var, "(-var)" );
  test_make( "-var4", kind::var, "(-var4)" );
  test_make( "-_var4", kind::var, "(-_var4)" );

  test_make( "3/2", kind::fraction, "(3/2)" );
  test_make( "-3/1", kind::fraction, "(-1)*(3/1)" );
  test_make( "3u/2", kind::fraction, "(3/2)" );
  test_make( "2/3u", kind::fraction, "(2/3)" );
  test_make( "3/(-1)", kind::fraction, "(-1)*(3/1)" );
  test_make( "-3/(-1)", kind::fraction, "(3/1)" );
  test_make( "(-3)/(-1)", kind::fraction, "(3/1)" );

  test_make( "vara/varb", kind::fraction, "(vara/varb)" );
  test_make( "-vara/varb", kind::fraction, "(-1)*(vara/varb)" );
  test_make( "vara/(-varb)", kind::fraction, "(-1)*(vara/varb)" );
  test_make( "(-vara)/(-varb)", kind::fraction, "(vara/varb)" );

  test_make( "842u/varb", kind::fraction, "(842/varb)" );
  test_make( "-842u/varb", kind::fraction, "(-1)*(842/varb)" );
  test_make( "842u/(-varb)", kind::fraction, "(-1)*(842/varb)" );
  test_make( "(-842u)/(-varb)", kind::fraction, "(842/varb)" );

  test_make( "-1/(3u*var)", kind::fraction, "(-1)*(1/(3*var))" );

  test_make( "a+b", kind::addends, "(a+b)");
  test_make( "a+b*c", kind::addends, "(a+(b*c))");
  test_make( "a+b*c*d/e", kind::addends, "(a+(b*c*(d/e)))");

  test_make( "b*c*d/e", kind::factors, "(b*c*(d/e))");
  test_make( "b*c*(-d)/e", kind::factors, "(-1)*(b*c*(d/e))");
  test_make( "-1*3u", kind::factors, "(-3)" );
  test_make( "1*vara*varb*3u", kind::factors, "(3*vara*varb)" );
  test_make( "1*vara*(-1)*varb*1*1*1*(-1)*(-1)*(-varb)*3u", kind::factors, "(3*vara*varb*varb)" );
  test_make( "1*vara*(-1)*varb*1*1*1*(-1)*(-1)*(-1)*(-varb)*3u", kind::factors, "(-1)*(3*vara*varb*varb)" );
}

} // namespace bld::src::pc
