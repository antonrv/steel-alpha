
#include "inspect/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "source/object/function/binary.hpp" 

#include "source/object/state/def.hpp" 

// #include "options/state/decl.hpp"

namespace bld {


template <>
void Callback<callback_kind::detect_var_init, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::DeclStmt *declStmt = Result.Nodes.getNodeAs<clang::DeclStmt>(mtraits<match_kind::var_decl>::s_matchString);

  if (declStmt == nullptr) {
    throw std::logic_error("Wrong node match for detect_var_init");
  }

  src::state<src::obj::bin_op>::make(declStmt, m_sourceManager, m_astContext);
}


template <>
void Callback<callback_kind::detect_assignment, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::BinaryOperator *binOp = Result.Nodes.getNodeAs<clang::BinaryOperator>(mtraits<match_kind::assign_operator>::s_matchString);

  if (binOp == nullptr) {
    throw std::logic_error("Wrong node match for binary operator");
  }

  src::state<src::obj::bin_op>::make(binOp, m_sourceManager, m_astContext);

}


template <>
void Callback<callback_kind::detect_comparison, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::BinaryOperator *binOp = Result.Nodes.getNodeAs<clang::BinaryOperator>(mtraits<match_kind::compare_operator>::s_matchString);

  if (binOp == nullptr) {
    throw std::logic_error("Wrong node match for binary operator");
  }

  src::state<src::obj::bin_op>::make(binOp, m_sourceManager, m_astContext);
}


template <>
void Callback<callback_kind::detect_unary_int, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::UnaryOperator *unOp = Result.Nodes.getNodeAs<clang::UnaryOperator>(mtraits<match_kind::unary_operator_int>::s_matchString);

  if (unOp == nullptr) {
    throw std::logic_error("Wrong node match for binary operator");
  }

  src::state<src::obj::bin_op>::make(unOp, m_sourceManager, m_astContext);
}

} // namespace bld
