
#include "source/token/test/interface.hpp"

#include "source/token/make/piece.hpp"


#include <stdexcept>

namespace bld::src::pc {

template <kind Kind>
static
void test_piece_kind(const std::string& str);


template <kind Kind>
void test_piece_kind(const std::string& str) {

  auto baseElem = make_piece(str);

  auto gotKind = baseElem->get_kind();

  if (gotKind != Kind) {
    throw std::runtime_error("test_piece_kind failed for kind " + str + " got " + util::enum_convert<kind>::to_string_rt(gotKind) + ". expected : " + util::enum_convert<kind>::to_string<Kind>());
  }
}



template <>
void run_tests<token_test::piece_kind>() {

  test_piece_kind<kind::offset>("a[27+var]");
  test_piece_kind<kind::offset>("ptrvec[jj*stride+ii]");
  test_piece_kind<kind::call>("foo(b+4)");
  test_piece_kind<kind::call>("foo(b+4)");

  test_piece_kind<kind::binop>("a[27+var]=b");
  test_piece_kind<kind::binop>("b=a[27+var]");

  test_piece_kind<kind::binop>("a[27+var]=b[63-32*i]");
  test_piece_kind<kind::binop>("b[63-32*i]=a[27+var]");

  test_piece_kind<kind::binop>("a[27+var]=foo(27)");
  test_piece_kind<kind::binop>("foo(27)=a[27+var]");

  test_piece_kind<kind::binop>("a++");
  test_piece_kind<kind::binop>("a--");

}

} // namespace bld::src::pc
