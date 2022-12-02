#include "scan/lexer_def.hpp"

namespace bld {


scan_lexer::scan_lexer():
      FileMgr(FileMgrOpts),
      DiagID(new clang::DiagnosticIDs()),
      Diags(DiagID, new clang::DiagnosticOptions, new clang::IgnoringDiagConsumer()),
      SourceMgr(Diags, FileMgr),
      TargetOpts(new clang::TargetOptions)

{
    TargetOpts->Triple = "x86_64-unknown-linux-gnu";
    Target = clang::TargetInfo::CreateTargetInfo(Diags, TargetOpts);

//    clang::HeaderSearch HeaderInfo(std::make_shared<clang::HeaderSearchOptions>(), SourceMgr, Diags, LangOpts, Target.get());
//
//    m_preprocessorUptr = std::make_unique<clang::Preprocessor>(
//        std::make_shared<clang::PreprocessorOptions>(), Diags, LangOpts, SourceMgr,
//        HeaderInfo, ModLoader,
//        /*IILookup =*/nullptr,
//        /*OwnsHeaderSearch =*/false);
//
//    m_preprocessorUptr->Initialize(*Target);
}


} // namespace bld
