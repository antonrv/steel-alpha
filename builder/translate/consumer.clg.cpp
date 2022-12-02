#ifndef STEEL_COMPILER_TRANSLATION_INSTRUCTION_FND_ACTIONS_HPP
#define STEEL_COMPILER_TRANSLATION_INSTRUCTION_FND_ACTIONS_HPP


#include "translate/consumer.clg.hpp"

#include "llvm/Support/raw_ostream.h"


#include "files/interface.hpp"
#include "options/state/decl.hpp"

#include "common/it/matchers.hpp"

/////// Clang headers
#include "clang/Frontend/CompilerInstance.h"


namespace bld {


static constexpr const char * HeaderTxt = "//////////////////////////////////////\n"
                                          "// \n"
                                          "// Translation file. Do not modify. \n"
                                          "// \n"
                                          "//////////////////////////////////////\n\n";

////////////////////////////////////
////////////////////////////////////
//
// TRANSLATE AST CONSUMER
//
////////////////////////////////////
////////////////////////////////////
// template void mtraits<match_kind::function_call>::bind_matcher<Callback<callback_kind::translate_task_call, step::translate>>(MatchFinder& , Callback<callback_kind::translate_task_call, step::translate>& );


TranslateASTConsumer::TranslateASTConsumer(const clang::SourceManager& sm, const clang::ASTContext& ac,clang::Rewriter &R) :
// // m_kernelDeclCB(sm, ac, R),
// // m_varInitFromKernelCallCB(sm, ac, R),
// // m_assignOpWithMaybeKernelDepCB(sm, ac, R),
m_taskDefCB(sm, ac, R),
m_taskCallCB(sm, ac, R),
m_taskCallArgumentCB(sm, ac, R),
m_taskCallArgumentAmpsndCB(sm, ac, R),
m_taskCallArgumentSubscriptCB(sm, ac, R),
m_returnInTaskCB(sm, ac, R),
m_argumentWrapCB(sm, ac, R),
m_vardeclWrapCB(sm, ac, R),
m_vardeclDestroyCB(sm, ac, R)
// m_varDeclWrapCB(sm, ac, R)
// // m_paramDeclWrapCB(sm, ac, R)
// // m_kernelReturnCB(sm, ac, R),
{
  // ---- FIRST PASS

  // // mtraits<match_kind::task_decl>::bind_matcher(m_1stMatchFinder, m_kernelDeclCB);

  mtraits<match_kind::function_def>::bind_matcher(m_1stMatchFinder, m_taskDefCB);

  mtraits<match_kind::function_call_argument>::bind_matcher(m_1stMatchFinder, m_taskCallArgumentCB);

  mtraits<match_kind::function_call_argument_ampsnd>::bind_matcher(m_1stMatchFinder, m_taskCallArgumentAmpsndCB);

  mtraits<match_kind::function_call_argument_subscript>::bind_matcher(m_1stMatchFinder, m_taskCallArgumentSubscriptCB);

  mtraits<match_kind::return_stmt_in_function>::bind_matcher(m_1stMatchFinder, m_returnInTaskCB);

  // Need to be done in other matchfinder than function_call_argument matcher
  mtraits<match_kind::function_call>::bind_matcher(m_2ndMatchFinder, m_taskCallCB);

  mtraits<match_kind::ctxt_of_function>::bind_matcher(m_2ndMatchFinder, m_argumentWrapCB);
  mtraits<match_kind::var_decl>::bind_matcher(m_2ndMatchFinder, m_vardeclWrapCB);
  mtraits<match_kind::any_ctxt>::bind_matcher(m_2ndMatchFinder, m_vardeclDestroyCB);

  // mtraits<match_kind::decl_stmt_in_function>::bind_matcher(m_1stMatchFinder, m_varDeclWrapCB);

  // // mtraits<match_kind::function_def>::bind_matcher(m_1stMatchFinder, m_paramDeclWrapCB);

  // // mtraits<match_kind::async_event_in_return>::bind_matcher(m_1stMatchFinder, m_varInitFromKernelCallCB);

  // // mtraits<match_kind::assign_op_with_maybe_kernel_dep>::bind_matcher(m_1stMatchFinder, m_assignOpWithMaybeKernelDepCB);


}

void TranslateASTConsumer::HandleTranslationUnit(clang::ASTContext &Context) {
  m_1stMatchFinder.matchAST(Context);
  m_2ndMatchFinder.matchAST(Context);
  // m_3rdMatchFinder.matchAST(Context);
}


////////////////////////////////////
////////////////////////////////////
//
// TRANSLATE FRONTEND ACTION 
//
////////////////////////////////////
////////////////////////////////////

TranslateFrontendAction::TranslateFrontendAction() {
  if (state::options::is_set<opt_kind::app>()) {
    m_sourceKeyPath = key_path::pwd;
  } else if (state::options::is_set<opt_kind::runtime_test>()) {
    m_sourceKeyPath = key_path::steel_runtime_test_case;
  } else if (state::options::is_set<opt_kind::builder_test>()) {
    m_sourceKeyPath = key_path::steel_builder_test_suite;
  } else {
    throw std::runtime_error("Undefined source key path in TranslateFrontendAction");
  }
}


// Create the AST consumer object for this action
std::unique_ptr<clang::ASTConsumer> TranslateFrontendAction::CreateASTConsumer(clang::CompilerInstance &CI, llvm::StringRef inspectedSrcFn) {

  m_translateTargetFile = static_cast<modifiable_file*>( state::register_yield_coarse<file_kind::inspected>( state::filename(m_sourceKeyPath, inspectedSrcFn.str(), path_require::exist ) ) );

  m_rewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
  return std::make_unique<TranslateASTConsumer>(CI.getSourceManager(), CI.getASTContext(), m_rewriter);
}

bool TranslateFrontendAction::BeginSourceFileAction(clang::CompilerInstance& CI) {
  return true;
}


void TranslateFrontendAction::EndSourceFileAction() {
  // std::cout << "Within EndSourceFileAction\n";

  std::string rewrittenContent; // needed? TODO

  llvm::raw_string_ostream newStream(rewrittenContent);

  m_rewriter.getEditBuffer(m_rewriter.getSourceMgr().getMainFileID()).write(newStream);

  std::string& str = newStream.str();

  std::string headInsertion(HeaderTxt);
  headInsertion += "module App.Proxy;\n";

  str.insert(0, headInsertion);

  m_translateTargetFile->dump_content(str);
}


} // namespace bld

#endif // STEEL_COMPÌLER_TRANSLATION_INSTRUCTION_FND_ACTIONS_HPP
