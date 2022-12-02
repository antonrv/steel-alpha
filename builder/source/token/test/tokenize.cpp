
#include "source/token/test/interface.hpp"

#include "source/token/tokenize.hpp"

#include <stdexcept>


namespace bld::src::pc {

//////////////////////
//
// FAIL SYNTAX TEST
//
//////////////////////
static
void test_fail(const std::string& inputStr, std::string errStr) {

  bool errorCaught = false;

  try {

    auto retStr = preprocess(inputStr);

  } catch (const std::runtime_error& rte) {

    std::string retErrStr = rte.what();

    if (retErrStr.find(errStr) == std::string::npos) {
      throw std::runtime_error("Expected error containing \"" + errStr + "\"" + " but got \"" + retErrStr + "\" from input \"" + inputStr + "\"");
    } else {
      // Expected error caught, test passed
      errorCaught = true;
    }

  } catch (...) {
    // rethrow
    throw;
  }
  
  if (not errorCaught) {
    throw std::runtime_error("Expected error containing \"" + errStr + "\"" + " but did not get any error from \"" + inputStr + "\" from input \"" + inputStr + "\"");
  }
}


template <>
void run_tests<token_test::fail>() {


  test_fail("(()", ErrStrParen);
  test_fail("())", ErrStrParen);
  test_fail(")((", ErrStrParen);
  test_fail("(", ErrStrUnbalancedParen);
  test_fail("((", ErrStrUnbalancedParen);
  test_fail("(((", ErrStrUnbalancedParen);
  test_fail(")", ErrStrUnmatchedParen);
  test_fail("))", ErrStrUnmatchedParen);
  test_fail(")))", ErrStrUnmatchedParen);
  test_fail(")(", ErrStrUnmatchedParen);
  test_fail(")(", ErrStrUnmatchedParen);

  test_fail("[[]", ErrStrParen);
  test_fail("[]]", ErrStrParen);
  test_fail("][[", ErrStrParen);
  test_fail("[", ErrStrUnbalancedParen);
  test_fail("[[", ErrStrUnbalancedParen);
  test_fail("[[[", ErrStrUnbalancedParen);
  test_fail("]", ErrStrUnmatchedParen);
  test_fail("]]", ErrStrUnmatchedParen);
  test_fail("]]]", ErrStrUnmatchedParen);
  test_fail("][", ErrStrUnmatchedParen);
  test_fail("][", ErrStrUnmatchedParen);

  test_fail("**", ErrStrContiguousOp);
  test_fail("//", ErrStrContiguousOp);
  test_fail("+-", ErrStrContiguousOp);
  test_fail("+*", ErrStrContiguousOp);
  test_fail("+/", ErrStrContiguousOp);
  test_fail("-+", ErrStrContiguousOp);
  test_fail("-*", ErrStrContiguousOp);
  test_fail("-/", ErrStrContiguousOp);
  test_fail("*+", ErrStrContiguousOp);
  test_fail("*-", ErrStrContiguousOp);
  test_fail("*/", ErrStrContiguousOp);
  test_fail("/+", ErrStrContiguousOp);
  test_fail("/-", ErrStrContiguousOp);
  test_fail("/*", ErrStrContiguousOp);

}


//////////////////////
//
// TOKEN NUMS
//
//////////////////////


template <kind Kind>
static
void test_token(const std::string& inputStr, const std::string& expectStr);


template <kind Kind>
void test_token(const std::string& inputStr, const std::string& expectStr) {
  auto outStr = get_token<Kind>(inputStr);
  if (outStr != expectStr) {
    throw std::runtime_error("test_tokenize_tokens failed for \"" + inputStr + "\". Got : \"" + outStr + "\". Expected : \"" + expectStr + "\"");
  }
}



template <>
void run_tests<token_test::split>() {
  // Nums
  test_token<kind::num>("25+42", "25" );
  test_token<kind::num>("25-42", "25" );
  test_token<kind::num>("25-42", "25" );
  test_token<kind::num>("25*42", "25" );
  test_token<kind::num>("25*42", "25" );
  test_token<kind::num>("25/42", "25" );
  test_token<kind::num>("25/42", "25" );

  test_token<kind::num>("25+42u", "25" );
  test_token<kind::num>("25-42u", "25" );
  test_token<kind::num>("25-42u", "25" );
  test_token<kind::num>("25*42u", "25" );
  test_token<kind::num>("25*42u", "25" );
  test_token<kind::num>("25/42u", "25" );
  test_token<kind::num>("25/42u", "25" );

  test_token<kind::num>("25+var", "25" );
  test_token<kind::num>("25-var", "25" );
  test_token<kind::num>("25-var", "25" );
  test_token<kind::num>("25*var", "25" );
  test_token<kind::num>("25*var", "25" );
  test_token<kind::num>("25/var", "25" );
  test_token<kind::num>("25/var", "25" );

  test_token<kind::num>("25+(var)", "25" );
  test_token<kind::num>("25-(var)", "25" );
  test_token<kind::num>("25-(var)", "25" );
  test_token<kind::num>("25*(var)", "25" );
  test_token<kind::num>("25*(var)", "25" );
  test_token<kind::num>("25/(var)", "25" );
  test_token<kind::num>("25/(var)", "25" );

  // Vars
  test_token<kind::var>("var+42", "var" );
  test_token<kind::var>("var-42", "var" );
  test_token<kind::var>("var-42", "var" );
  test_token<kind::var>("var*42", "var" );
  test_token<kind::var>("var*42", "var" );
  test_token<kind::var>("var/42", "var" );
  test_token<kind::var>("var/42", "var" );

  test_token<kind::var>("var+42u", "var" );
  test_token<kind::var>("var-42u", "var" );
  test_token<kind::var>("var-42u", "var" );
  test_token<kind::var>("var*42u", "var" );
  test_token<kind::var>("var*42u", "var" );
  test_token<kind::var>("var/42u", "var" );
  test_token<kind::var>("var/42u", "var" );

  test_token<kind::var>("var+foo", "var" );
  test_token<kind::var>("var-foo", "var" );
  test_token<kind::var>("var-foo", "var" );
  test_token<kind::var>("var*foo", "var" );
  test_token<kind::var>("var*foo", "var" );
  test_token<kind::var>("var/foo", "var" );
  test_token<kind::var>("var/foo", "var" );

  test_token<kind::var>("var+(foo)", "var" );
  test_token<kind::var>("var-(foo)", "var" );
  test_token<kind::var>("var-(foo)", "var" );
  test_token<kind::var>("var*(foo)", "var" );
  test_token<kind::var>("var*(foo)", "var" );
  test_token<kind::var>("var/(foo)", "var" );
  test_token<kind::var>("var/(foo)", "var" );
}

} // namespace bld::src::pc
