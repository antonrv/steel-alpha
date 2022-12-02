

#include "source/object/data/use.hpp"
#include "source/object/data/factory.hpp"

#include "source/object/state/decl.hpp"

#include "common/aux.hpp"
#include "common/util.hpp"

namespace bld::src {


template <typename ClangT>
void register_and_bind( const ClangT *cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sobject_base * dDeclCalleeOrOp, std::vector<pc::terminal_t> terminalsVec ) {

  // Basic consistency check
  for (auto trm : terminalsVec) {
    if (not trm->is_terminal()) {
      throw std::logic_error("PCK Consistency broken in register_bind");
    }
  }

  std::reverse( std::begin(terminalsVec), std::end(terminalsVec) );

  register_data_uses( cPtr, sm, ctxt, dDeclCalleeOrOp, terminalsVec );
}


} // namespace bld::src
