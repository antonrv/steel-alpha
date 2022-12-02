
#include "source/object/data/transform/interface.hpp"

#include "source/object/data/decl.hpp"
#include "source/object/data/use.hpp"

#include "source/token/terminal/var.hpp"
#include "source/token/multiple/multiple.hpp"


namespace bld::src {


static
void collect_local_contexts_detail( pc::cpiece_t inputPc, set_csob_t& collectLocalCtxtSet ) {


  if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::var ) {

    auto var = static_cast<pc::ctoken_t<pc::kind::var>>(inputPc);

    auto dUse = var->get_data_use();

    collectLocalCtxtSet.insert( dUse->get_local_context() );

    auto dDeclRoot = dUse->get_root_data_decl();

    auto declKind = dDeclRoot->get_decl_kind();

    if (var->is_loop()) {

      // Nothing to collect, do nothing

    } else if (dDeclRoot->is_set_once() and declKind == decl_kind::body) {


      collectLocalCtxtSet.insert( dDeclRoot );

      // Recurse over its definition
      collect_local_contexts_detail( dDeclRoot->get_initialization(), collectLocalCtxtSet );

    } else if (declKind == decl_kind::fargument or declKind == decl_kind::relaxed_fargument) {

      collectLocalCtxtSet.insert( dDeclRoot->get_local_context() );

    } else {

      // Not set once, so no more valid local contexts to collect, do nothing
      // Or decl kind is already fargument, so no more higher contexts to collect
    }

  } else if (inputPc->is_terminal() and inputPc->get_kind() == pc::kind::num ) {

    // Nothing to collect, do nothing

  } else if (inputPc->is_multiple()) {

    auto mul = static_cast<const pc::multiple *>(inputPc);

    auto toks = mul->get_tokens();

    // Recurse over tokens
    for (auto mt : toks) {
      collect_local_contexts_detail( mt, collectLocalCtxtSet );
    }
     
  } else {
    throw std::logic_error("Unreachable in collect_local_contexts_detail");
  }

  return;
}

set_csob_t collect_local_contexts( pc::cpiece_t inputPc ) {

  set_csob_t retSet;

  collect_local_contexts_detail( inputPc, retSet );

  return retSet;
}

} // namespace bld::src
