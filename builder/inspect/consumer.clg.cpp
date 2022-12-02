
#include "inspect/consumer.clg.hpp"
// #include "source/object/task/dependency_async_event.hpp"


// #include "paths/def.hpp"

#include "source/object/state/dump.hpp"

#include "options/state/decl.hpp"
#include "files/paths/aux.hpp"

#include "common/it/matchers.hpp"

#include "clang/AST/Decl.h"


namespace bld {

// The role of this AST consumer is to identify all function definitions, calls and task definitions, as well as loops whose variables access arrays.

////////////////////////////////////
////////////////////////////////////
//
// FUNCTIONS AST CONSUMER
//
////////////////////////////////////
////////////////////////////////////


FunctionsASTConsumer::FunctionsASTConsumer(const clang::SourceManager& sm, const clang::ASTContext& ac) :
m_functionDefCB(sm, ac),
m_varInitOpCB(sm, ac),
m_assignOpCB(sm, ac),
m_compareOpCB(sm, ac),
m_unaryIntOpCB(sm, ac),

m_functionCallCB(sm, ac),
m_functionLoopCB(sm, ac),
// m_arrayAccessCB(sm, ac),
// m_pointerAccessCB(sm, ac),

m_taskDeclCB(sm, ac),
m_regCtxtCB(sm, ac),
m_regReturnCB(sm, ac),


m_sequentialFinders(3)
{

  using namespace clang::ast_matchers;

  // Register all the elements that access data
  mtraits<match_kind::function_def>::bind_matcher(m_sequentialFinders[0], m_functionDefCB);
  mtraits<match_kind::var_decl>::bind_matcher(m_sequentialFinders[0], m_varInitOpCB);
  mtraits<match_kind::assign_operator>::bind_matcher(m_sequentialFinders[0], m_assignOpCB);
  mtraits<match_kind::compare_operator>::bind_matcher(m_sequentialFinders[0], m_compareOpCB);
  mtraits<match_kind::unary_operator_int>::bind_matcher(m_sequentialFinders[0], m_unaryIntOpCB);

  // // After function everything is registered, get all calls and all arguments
  mtraits<match_kind::function_call>::bind_matcher(m_sequentialFinders[1], m_functionCallCB);
  mtraits<match_kind::function_loop>::bind_matcher(m_sequentialFinders[1], m_functionLoopCB);

  // mtraits<match_kind::array_access>::bind_matcher(m_sequentialFinders[2], m_arrayAccessCB);
  // mtraits<match_kind::pointer_access>::bind_matcher(m_sequentialFinders[2], m_pointerAccessCB);


  // // Register all tagged functions, removing the associated function_def
  mtraits<match_kind::task_decl>::bind_matcher(m_sequentialFinders[2], m_taskDeclCB);

  mtraits<match_kind::any_ctxt>::bind_matcher(m_sequentialFinders[2], m_regCtxtCB);
  mtraits<match_kind::return_stmt_in_function>::bind_matcher(m_sequentialFinders[2], m_regReturnCB);

}

void FunctionsASTConsumer::HandleTranslationUnit(clang::ASTContext &Context) {

  // Sequential passes over previous callbacks
  for (auto& f : m_sequentialFinders) {
    f.matchAST(Context);
  }
}




////////////////////////////////////
////////////////////////////////////
//
// FUNCTIONS FRONTEND ACTION (done just once per TU)
//
////////////////////////////////////
////////////////////////////////////


FunctionsFrontendAction::FunctionsFrontendAction() { 

  if (state::options::is_set<opt_kind::app>()) {
    m_sourceKeyPath = key_path::pwd;
  } else if (state::options::is_set<opt_kind::runtime_test>()) {
    m_sourceKeyPath = key_path::steel_runtime_test_case;
  } else if (state::options::is_set<opt_kind::builder_test>()) {
    m_sourceKeyPath = key_path::steel_builder_test_suite;
  } else {
    throw std::runtime_error("Undefined source key path in FunctionsFrontendAction");
  }
}

// Create the AST consumer object for this action
std::unique_ptr<clang::ASTConsumer>
FunctionsFrontendAction::CreateASTConsumer(clang::CompilerInstance &CI, llvm::StringRef inspectedSrcFn) {

  state::files<file_kind::input>::record_filename( state::filename(m_sourceKeyPath, inspectedSrcFn.str(), path_require::exist ) );

  return std::make_unique<FunctionsASTConsumer>(CI.getSourceManager(), CI.getASTContext());
}

bool FunctionsFrontendAction::BeginSourceFileAction(clang::CompilerInstance& CI) {
  return true;
}

void FunctionsFrontendAction::EndSourceFileAction() {
  // Do nothing
}



////////////////////////////////////
////////////////////////////////////
//
// SET-TASK-INFO AST CONSUMER
//
////////////////////////////////////
////////////////////////////////////

SetTaskInfoASTConsumer::SetTaskInfoASTConsumer(const clang::SourceManager& sm, const clang::ASTContext& ac) :
m_taskDefCB(sm, ac)
{

  using namespace clang::ast_matchers;

  mtraits<match_kind::function_def>::bind_matcher(m_lastFinder, m_taskDefCB);
}

void SetTaskInfoASTConsumer::HandleTranslationUnit(clang::ASTContext &Context) {

  m_lastFinder.matchAST(Context);
}

////////////////////////////////////
////////////////////////////////////
//
// SET-TASK-INFO FRONTEND ACTION (done just once per TU) LAST FRONTEND ACTION to be applied to each file
//
////////////////////////////////////
////////////////////////////////////

SetTaskInfoFrontendAction::SetTaskInfoFrontendAction() {
  if (state::options::is_set<opt_kind::app>()) {
    m_sourceKeyPath = key_path::pwd;
  } else if (state::options::is_set<opt_kind::runtime_test>()) {
    m_sourceKeyPath = key_path::steel_runtime_test_case;
  } else if (state::options::is_set<opt_kind::builder_test>()) {
    m_sourceKeyPath = key_path::steel_builder_test_suite;
  } else {
    throw std::runtime_error("Undefined source key path in FunctionsFrontendAction");
  }
}


// Create the AST consumer object for this action
std::unique_ptr<clang::ASTConsumer>
SetTaskInfoFrontendAction::CreateASTConsumer(clang::CompilerInstance &CI, llvm::StringRef inspectedSrcFn) {

  m_inputFile = state::filename(m_sourceKeyPath, inspectedSrcFn.str(), path_require::exist );

  return std::make_unique<SetTaskInfoASTConsumer>(CI.getSourceManager(), CI.getASTContext());
}


bool SetTaskInfoFrontendAction::BeginSourceFileAction(clang::CompilerInstance& CI) {
  return true;
}


void SetTaskInfoFrontendAction::EndSourceFileAction() {

  std::string contentStr;

  if (m_inputFile.get_head() == key_path::pwd) {
    contentStr += m_inputFile.get_head_str() + "\n";
  } else {
    contentStr += std::string(util::enum_convert<key_path>::to_string_rt( m_inputFile.get_head() )) + "\n"; // Invariant path
  }
  contentStr += m_inputFile.get_tail() + "\n";

  {
    auto sgraphDump = "/*" + src::dump_belonging_to_file( m_inputFile ) + "*/";

    state::remove_path_in_string<key_path::steel_root>( sgraphDump );

    contentStr += sgraphDump;
  }


  // Register a new 'file_kind::sgraph' filename, in which the graph of source objects are dumped
  auto sgraphTargetFile = static_cast<modifiable_file*>( state::register_yield_coarse<file_kind::input>( m_inputFile ) );

  sgraphTargetFile->dump_content( contentStr );

  // Register a new 'file_kind::inspected' filename, to be digested by step::translate
  state::register_yield_coarse<file_kind::sgraph>( sgraphTargetFile->get_filename() );

}

} // namespace bld
