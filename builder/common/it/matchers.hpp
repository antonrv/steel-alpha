#ifndef STEEL_COMPILER_COMMON_AST_MATCHER_ENUM_TRAITS_HPP
#define STEEL_COMPILER_COMMON_AST_MATCHER_ENUM_TRAITS_HPP

// #include "common/fun_sequences_std17.hpp"
// 
// ENUM_DEFINITION(bld, match_kind,
// function_def,
// function_call,
// task_decl,
// function_loop
// )


namespace bld {

  using namespace clang::ast_matchers;

enum class match_kind {
function_def,
function_call,
function_call_argument,
function_call_argument_ampsnd,
function_call_argument_subscript,
task_decl,
function_loop,
return_stmt_in_function,
ctxt_of_function,
any_ctxt,
var_decl,
assign_operator,
compare_operator,
unary_operator_int,
array_access,
pointer_access
};

template <match_kind MK>
struct mtraits;

//////////// BASE MATCHER
template <match_kind MK>
struct base_traits {
  template <typename CallbackT>
  static void bind_matcher(MatchFinder& mFinder, CallbackT& cbRef) {
    mFinder.addMatcher( mtraits<MK>::build_matcher().bind(mtraits<MK>::s_matchString), &cbRef );
  }
};

//////////// MATCH A FUNCTION WITH A BODY
template <>
struct mtraits<match_kind::function_def> : base_traits<match_kind::function_def> {
  static constexpr const char * s_matchString = "FunctionDefMatch";
  static auto build_matcher() {
    return functionDecl( has(compoundStmt()), isExpansionInMainFile() );
  }
};

//////////// MATCH A CALL TO A FUNCTION WITH A BODY
template <>
struct mtraits<match_kind::function_call> : base_traits<match_kind::function_call> {
  static constexpr const char * s_matchString = "FunctionCallMatch";
  static auto build_matcher() {
    return callExpr( callee( mtraits<match_kind::function_def>::build_matcher() ), isExpansionInMainFile() );
  }
};

//////////// MATCH A CALL ARGUMENT
template <>
struct mtraits<match_kind::function_call_argument> : base_traits<match_kind::function_call_argument> {
  static constexpr const char * s_matchString = "FunctionCallArgumentMatch";
  static auto build_matcher() {
    return declRefExpr( hasParent( mtraits<match_kind::function_call>::build_matcher() ), isExpansionInMainFile() );
  }
};

//////////// MATCH A CALL ARGUMENT with an ampersand
template <>
struct mtraits<match_kind::function_call_argument_ampsnd> : base_traits<match_kind::function_call_argument_ampsnd> {
  static constexpr const char * s_matchString = "FunctionCallArgumentAmpsndMatch";
  static auto build_matcher() {
    return unaryOperator( hasAncestor( mtraits<match_kind::function_call>::build_matcher() ), hasOperatorName("&"), isExpansionInMainFile() );
  }
};

//////////// MATCH A CALL ARGUMENT with an subscript
template <>
struct mtraits<match_kind::function_call_argument_subscript> : base_traits<match_kind::function_call_argument_subscript> {
  static constexpr const char * s_matchString = "FunctionCallArgumentSubscriptMatch";
  static auto build_matcher() {
    // return arraySubscriptExpr( hasParent( implicitCastExpr( hasParent( mtraits<match_kind::function_call>::build_matcher() ) ) ), isExpansionInMainFile() );
    return arraySubscriptExpr( hasAncestor( mtraits<match_kind::function_call>::build_matcher() ), unless( hasParent( mtraits<match_kind::function_call_argument_ampsnd>::build_matcher() ) ),  isExpansionInMainFile() );
  }
};

//////////// MATCH AN ANNOTATED FUNCTION (ie a TASK)
template <>
struct mtraits<match_kind::task_decl> : base_traits<match_kind::task_decl> {
  static constexpr const char * s_matchString = "TaskDeclMatch";
  static auto build_matcher() {
    return
      functionDecl(
        anyOf(
          hasAttr( clang::attr::STEELTask ),
          isMain()
        ),
        has(compoundStmt())
      );
  }
};

//////////// MATCH A LOOP IN A FUNCTION
template <>
struct mtraits<match_kind::function_loop> : base_traits<match_kind::function_loop> {
  static constexpr const char * s_matchString = "LoopInFunctionMatch";
  static auto build_matcher() {
    return forStmt( hasAncestor( mtraits<match_kind::function_def>::build_matcher() ), isExpansionInMainFile() );
  }
};


//////////// MATCH A RETURN STMT IN A FUNCTION
template <>
struct mtraits<match_kind::return_stmt_in_function> : base_traits<match_kind::return_stmt_in_function> {
  static constexpr const char * s_matchString = "ReturnStmtInFunction";
  static auto build_matcher() {
    return returnStmt( hasAncestor( mtraits<match_kind::function_def>::build_matcher() ), isExpansionInMainFile() );
  }
};

//////////// MATCH CONTEXTS OF FUNCTIONS
template <>
struct mtraits<match_kind::ctxt_of_function> : base_traits<match_kind::ctxt_of_function> {
  static constexpr const char * s_matchString = "FunctionCtxt";
  static auto build_matcher() {
    return compoundStmt( hasParent( mtraits<match_kind::function_def>::build_matcher() ), isExpansionInMainFile() );
  }
};

//////////// MATCH ANY CONTEXTS
template <>
struct mtraits<match_kind::any_ctxt> : base_traits<match_kind::any_ctxt> {
  static constexpr const char * s_matchString = "AnyCtxt";
  static auto build_matcher() {
    return compoundStmt( hasAncestor( mtraits<match_kind::function_def>::build_matcher() ), isExpansionInMainFile() );
  }
};

//////////// MATCH VAR DECL IN A BODY
template <>
struct mtraits<match_kind::var_decl> : base_traits<match_kind::var_decl> {
  static constexpr const char * s_matchString = "VarDecl";
  static auto build_matcher() {
    return declStmt( has(varDecl()), isExpansionInMainFile() ); // hasParent(compoundStmt());
  }
};


//////////// MATCH VAR ASSIGNMENT
template <>
struct mtraits<match_kind::assign_operator> : base_traits<match_kind::assign_operator> {
  static constexpr const char * s_matchString = "AssignOperator";
  static auto build_matcher() {
    return binaryOperator(isAssignmentOperator(), isExpansionInMainFile());
  }
};


//////////// MATCH COMPARE OPERATOR
template <>
struct mtraits<match_kind::compare_operator> : base_traits<match_kind::compare_operator> {
  static constexpr const char * s_matchString = "CompareOperator";
  static auto build_matcher() {
    return binaryOperator(isComparisonOperator(), isExpansionInMainFile());
  }
};

//////////// MATCH COMPARE OPERATOR
template <>
struct mtraits<match_kind::unary_operator_int> : base_traits<match_kind::unary_operator_int> {
  static constexpr const char * s_matchString = "UnaryOperatorInt";
  static auto build_matcher() {
    return unaryOperator(anyOf(hasOperatorName("++"), hasOperatorName("--")), isExpansionInMainFile());
  }
};

template <>
struct mtraits<match_kind::array_access> : base_traits<match_kind::array_access> {
  static constexpr const char * s_matchString = "ArrayAccess";
  static auto build_matcher() {
    return arraySubscriptExpr( isExpansionInMainFile());
  }
};

template <>
struct mtraits<match_kind::pointer_access> : base_traits<match_kind::pointer_access> {
  static constexpr const char * s_matchString = "PointerAccess";
  static auto build_matcher() {
    return unaryOperator(hasOperatorName("*"), isExpansionInMainFile());
  }
};

} // namespace bld

#endif // STEEL_COMPILER_COMMON_AST_MATCHER_ENUM_TRAITS_HPP
