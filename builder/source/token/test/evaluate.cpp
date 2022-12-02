
#include "source/token/test/interface.hpp"

#include "source/token/make/piece.hpp"

#include "source/token/combine/interface.hpp"



#include <string>
#include <stdexcept>
#include <iostream>


namespace bld::src::pc {

static
void test_evaluate(std::string opStr, res expectRes) {

  // std::cout << "Testing " << opStr << '\n';

  auto pc = make_piece( opStr );

  if (pc->get_kind() != kind::binop) {
    throw std::runtime_error("Expected kind::binop");
  }

  auto binOp = static_cast<ctoken_t<kind::binop>>(pc.get());

  if (not binOp->is_compare()) {
    throw std::runtime_error("test_evaluate failed - expected predicate operation");
  }

  auto gotRes = binOp->evaluate();
  if (gotRes != expectRes) {

    throw std::runtime_error("eval_tests_fail : "  + opStr + " result should be " + util::enum_convert<res>::to_string_rt(expectRes) + " but got " + to_string(gotRes));

  }

}

static
void test_equal(std::string inputAStr, std::string inputBStr, bool expect) {

  auto pcA = make_piece( inputAStr );
  auto pcB = make_piece( inputBStr );

  if (are_equal(pcA.get(), pcB.get()) != expect) {
    throw std::runtime_error("eval_tests_fail. Tokens not equal are_equal( A, B ) returned false for \"" + inputAStr + "\", \"" + inputBStr + "\"");
  }
}



template <>
void run_tests<token_test::evaluate>() {

  test_equal("1","1", true);
  test_equal("a","a", true);
  test_equal("27","27", true);
  test_equal("-27","-27", true);
  test_equal("-a","-a", true);
  test_equal("1","a", false);
  test_equal("a","1", false);

  test_evaluate("1==1", res::tru);
  test_evaluate("1!=1", res::fal);
  test_evaluate("1<1", res::fal);
  test_evaluate("1<=1", res::tru);
  test_evaluate("1>1", res::fal);
  test_evaluate("1>=1", res::tru);

  test_evaluate("1==2", res::fal);
  test_evaluate("1!=2", res::tru);
  test_evaluate("1<2", res::tru);
  test_evaluate("1<=2", res::tru);
  test_evaluate("1>2", res::fal);
  test_evaluate("1>=2", res::fal);

  test_evaluate("1==var", res::unk);
  test_evaluate("1!=var", res::unk);
  test_evaluate("1<var", res::unk);
  test_evaluate("1<=var", res::unk);
  test_evaluate("1>var", res::unk);
  test_evaluate("1>=var", res::unk);

  test_evaluate("var==2", res::unk);
  test_evaluate("var!=2", res::unk);
  test_evaluate("var<2", res::unk);
  test_evaluate("var<=2", res::unk);
  test_evaluate("var>2", res::unk);
  test_evaluate("var>=2", res::unk);

  test_evaluate("vara==varb", res::unk);
  test_evaluate("vara!=varb", res::unk);
  test_evaluate("vara<varb", res::unk);
  test_evaluate("vara<=varb", res::unk);
  test_evaluate("vara>varb", res::unk);
  test_evaluate("vara>=varb", res::unk);

  test_evaluate("vara==vara", res::tru);
  test_evaluate("vara!=vara", res::fal);
  test_evaluate("vara<vara", res::fal);
  test_evaluate("vara<=vara", res::tru);
  test_evaluate("vara>vara", res::fal);
  test_evaluate("vara>=vara", res::tru);

  test_evaluate("1==1*1", res::tru);
  test_evaluate("0==0*1", res::tru);
  test_evaluate("0==0*var", res::tru);

  test_evaluate("1==var/var", res::tru);
  test_evaluate("1==var/var", res::tru);
  test_evaluate("-1==(-var)/var", res::tru);
  test_evaluate("-1==var/(-var)", res::tru);

  test_evaluate("a*b==b*a", res::tru);
  test_evaluate("a*b*c==a*c*b", res::tru);
  test_evaluate("a*b*c==b*a*c", res::tru);
  test_evaluate("a*b*c==c*b*a", res::tru);
  test_evaluate("a*b*c==c*b*a", res::tru);

  // mod ops
  test_evaluate("a%b<b", res::tru);
  test_evaluate("a%b<=b", res::tru);
  test_evaluate("a%b>b", res::fal);
  test_evaluate("a%b>=b", res::fal);
  test_evaluate("a%b==b", res::fal);
  test_evaluate("a%b!=b", res::tru);

  test_evaluate("b<a%b", res::fal);
  test_evaluate("b<=a%b", res::fal);
  test_evaluate("b>a%b", res::tru);
  test_evaluate("b>=a%b", res::tru);
  test_evaluate("b==a%b", res::fal);
  test_evaluate("b!=a%b", res::tru);

  test_evaluate("(a+b*c)%(d*e+f)< (d*e+f)", res::tru);
  test_evaluate("(a+b*c)%(d*e+f)<=(d*e+f)", res::tru);
  test_evaluate("(a+b*c)%(d*e+f)> (d*e+f)", res::fal);
  test_evaluate("(a+b*c)%(d*e+f)>=(d*e+f)", res::fal);
  test_evaluate("(a+b*c)%(d*e+f)==(d*e+f)", res::fal);
  test_evaluate("(a+b*c)%(d*e+f)!=(d*e+f)", res::tru);

  test_evaluate("(((nElems%bSize)+(bSize*(nElems/bSize)))+(-1)*(bSize*(nElems/bSize))) <= (bSize+((bSize*nBlocksEven)+(-1)*(bSize*nBlocksEven)))", res::tru);

}

} // namespace bld::src::pc
