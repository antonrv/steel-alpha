
#include "source/object/data/use.hpp"

#include "source/object/data/decl.hpp"
#include "source/object/function/call.hpp"

// #include "source/token/make/piece.hpp"
#include "source/token/make/copy.hpp"
#include "source/token/region/make_access.hpp"


#include "common/util.hpp"

#include "source/object/state/def.hpp"


namespace bld::src {

///////////////////////////////////////////
//////////////
////////////// LOOP VARIABLE STUFF
//////////////
///////////////////////////////////////////

static
bool is_loop_var(pc::cpiece_t pc) {
  if (pc->get_kind() == pc::kind::var) {
    // Internally checks the dataUse->on_loop_variable or true if it is just pc::loop_var
    return static_cast<pc::ctoken_t<pc::kind::var>>(pc)->is_loop();
  }
  return false; 
}


bool sobject<obj::data_use>::on_loop_variable() const {
  return this->has_root() and this->get_root_data_decl()->get_loop_variable() != nullptr;
}


bool sobject<obj::data_use>::has_mem_access() const {
  return m_ownedMemAccess.get() != nullptr;
}

pc::caccess_t sobject<obj::data_use>::get_mem_access() const {
  if (not this->has_mem_access()) {
    throw std::logic_error("Cannot get_access in data_use. Not initialized");
  }
  return m_ownedMemAccess.get();
}


void sobject<obj::data_use>::set_mem_access() {

  // std::cout << "Setting access : " << this->get_identifier() << '\n';

  if (not this->on_address()) {
    throw std::logic_error("Cannot get_access in data_use that is not on_address");
  }

  m_ownedMemAccess = make_mem_access( this->get_single_access_piece().get(), is_loop_var, this );
}



///////////////////////////////////////////
//////////////
////////////// ARRAY STUFF
//////////////
///////////////////////////////////////////

///////////////
//
// GET_ACCESS_PIECES
//
///////////////

// Private
pc::own_cpiece_t
sobject<obj::data_use>::get_single_access_piece() const {

  auto termRootParent = m_terminalRoot->get_parent();

  if (termRootParent->get_kind() == pc::kind::offset) {
    // var[idx]
    auto parent = static_cast<pc::ctoken_t<pc::kind::offset>>(termRootParent);
    if (static_cast<pc::cterminal_t>(parent->get_base())->get_data_use()->get_identifier() == this->get_identifier()) {
      // m_terminalRoot is a base of a pc::kind::offset, so retrieve the index of that pc::kind::offset
      return const_piece( parent->get_index() );
    }
  }
  return pc::make_num(0);
}


bool sobject<obj::data_use>::on_ptr_address() const {

  return (this->is_indirect_ptr() or this->is_task_ref_argument()) and
    (this->get_access() != access_kind::init_default and
    this->get_access() != access_kind::init);
}


bool sobject<obj::data_use>::on_address() const {

  return (this->is_indirect_ref_argument() or this->is_task_ref_argument()) and
    (this->get_access() != access_kind::init_default and
    this->get_access() != access_kind::init);
}

bool sobject<obj::data_use>::on_callee_address() const {

  // This function returns true if the mem access in call site needs to be extended with an address in the callee site.

  if (this->is_direct_call_argument()) {

    auto indirFunArgCallee = this->get_callee_data_decl()->get_indirect();

    if (indirFunArgCallee != indir::ptr) {
      return false;
    }

    // From here we know that this data use is a direct call argument and the callee f arg is a ptr.
    // Generalize to ref in callee TODO

    auto termRootParent = m_terminalRoot->get_parent();

    if (termRootParent->get_kind() == pc::kind::offset) {

      auto parentAsOffset = static_cast<pc::ctoken_t<pc::kind::offset>>( termRootParent );

      // The parent of the offset is an address
      return parentAsOffset->get_parent()->get_kind() == pc::kind::address;

      // case YES:  call( &var[idx] );
      // case NO:  call( var[idx] ); // Eg ptr of ptr

    } else if (termRootParent->get_kind() == pc::kind::address) {

      // case YES:  call( &var );
      return true;
      // auto parentAsAddress = static_cast<pc::ctoken_t<pc::kind::address>>( termRootParent );

    } else if (termRootParent->get_kind() == pc::kind::cs_list) {

      // case 1 YES:  call( var );
      return true;
    }

  }
  return false;
}

bool sobject<obj::data_use>::is_indirect_ptr() const {

  if (this->has_root()) {

    return this->get_root_data_decl()->get_indirect() == indir::ptr;
  }
  return false;

}

bool sobject<obj::data_use>::is_indirect_ref_argument() const { // is_indirect_ref TODO

  if (this->has_root()) {

    auto thisIndir = this->get_root_data_decl()->get_indirect();

    return (thisIndir == indir::ptr or thisIndir == indir::ref); // ref only TODO
  }
  return false;
}


bool sobject<obj::data_use>::is_task_ref_argument() const {

  if (this->has_root() and this->is_direct_call_argument()) {
    auto calleeIndir = this->get_callee_data_decl()->get_indirect();
    return (calleeIndir == indir::ref or calleeIndir == indir::ptr);
  }
  return false;
}


bool sobject<obj::data_use>::is_callee_arg_copy() const {

  if (this->has_root() and this->is_direct_call_argument()) {
    return this->get_callee_data_decl()->get_indirect() == indir::copy;
  }
  return false;
}

bool sobject<obj::data_use>::is_callee_arg_ref() const {

  if (this->has_root() and this->is_direct_call_argument()) {
    return this->get_callee_data_decl()->get_indirect() == indir::ref;
  }
  return false;
}

bool sobject<obj::data_use>::is_callee_arg_ptr() const {

  if (this->has_root() and this->is_direct_call_argument()) {
    return this->get_callee_data_decl()->get_indirect() == indir::ptr;
  }
  return false;
}


csob_t sobject<obj::data_use>::get_local_context() const {

  // if (this->is_direct_call_argument()) {
    // return this->get_function_call();
  // } else if (this->has_operation()) {

  //   return this->get_operation();
  // } 
  auto fCall = state<obj::fun_call>::get_containing( this );
  if (fCall != nullptr) { // this->has_callee() ?= TODO

    // Not necessarily to be a direct call arg. We just want to retrieve a local context in which this var is defined

    return fCall;

  } else if (this->has_operation()) {

    // Not necessarily to be a direct operation arg. We just want to retrieve a local context in which this var is defined
    // return this->get_root_operation();
    return state<obj::bin_op>::get_containing( this );

  } else {
    // Reachable ?? TODO XXX
    return this->get_root_data_decl()->get_local_context();
  }
}

///////////////////////////////////////////
//////////////
////////////// TRANSLATION STUFF
//////////////
///////////////////////////////////////////

bool sobject<obj::data_use>::require_emit_backend() const {


  // if (not this->has_callee()) {
  // 
  //   // Maybe we can relax this too, as we will need to emit backends for synchronization on non-task calls and other sync ops
  //   throw std::logic_error("Cannot query require_emit_backend on data uses not in calls");
  // }

  if ((not this->is_direct_call_argument()) or (not this->has_root())) {
    return false;
  }
  

  if (this->on_address()) {
    return true;
  }

  auto dDeclCaller = this->get_root_data_decl();

  auto dDeclCallee = this->get_callee_data_decl(); 

  if (dDeclCallee->get_indirect() == indir::ref or dDeclCallee->get_indirect() == indir::ptr) {

    return true;
  }

  // The dDeclCallee receives a copy of the variable in the caller, so we count the number of rw uses that are calls to tasks.
  // require_wrap will return true in case consistency between sibling rws must be required.

  return dDeclCaller->require_wrap();
}

} // namespace bld::src
