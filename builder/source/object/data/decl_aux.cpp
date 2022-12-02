
#include "source/object/data/decl.hpp"

#include "source/object/function/context.hpp"

#include "source/object/data/use.hpp"


#include "source/token/make/copy.hpp"
#include "source/token/region/make_guard.hpp"


#include "source/object/function/loop.hpp"
#include "source/object/function/definition.hpp"


#include "source/object/state/def.hpp"

#include "common/util.hpp"

#include <algorithm>



namespace bld::src {


static
bool is_direct_data_use_of_operation(pc::ctoken_t<pc::kind::binop> opOverDataUse, cso_t<obj::data_use> dUse) {
  return dUse->is_direct_operator_argument() and dUse->get_terminal()->get_parent()->get_kind() == pc::kind::binop and static_cast<pc::ctoken_t<pc::kind::binop>>(dUse->get_terminal()->get_parent()) == opOverDataUse;
}

template <pc::lv_trait LVTrait>
static
bool is_data_use_within_loop_operation(pc::ctoken_t<pc::kind::binop> opOverDataUse, cso_t<obj::data_use> dUse);

template <>
bool is_data_use_within_loop_operation<pc::lv_trait::start>(pc::ctoken_t<pc::kind::binop> opOverDataUse, cso_t<obj::data_use> dUse) {

  return is_direct_data_use_of_operation(opOverDataUse, dUse) and
      (
        (opOverDataUse->get_opkind() == pc::opkind::init and opOverDataUse->get_use_access(dUse) == access_kind::init) or
        (opOverDataUse->get_opkind() == pc::opkind::assign and opOverDataUse->get_use_access(dUse) == access_kind::write_only)
      );
}

template <>
bool is_data_use_within_loop_operation<pc::lv_trait::bound>(pc::ctoken_t<pc::kind::binop> opOverDataUse, cso_t<obj::data_use> dUse) {

  return is_direct_data_use_of_operation(opOverDataUse, dUse) and
      (
        (opOverDataUse->is_compare() and opOverDataUse->get_use_access(dUse) == access_kind::read_only)
      );
}

template <>
bool is_data_use_within_loop_operation<pc::lv_trait::sweep>(pc::ctoken_t<pc::kind::binop> opOverDataUse, cso_t<obj::data_use> dUse) {
  return is_direct_data_use_of_operation(opOverDataUse, dUse) and
      (
        (opOverDataUse->get_opkind() == pc::opkind::incr or opOverDataUse->get_opkind() == pc::opkind::decr) and
        opOverDataUse->get_use_access(dUse) == access_kind::read_write
      );
}

template <pc::lv_trait LVTrait>
static
bool count_satisfy( unsigned cnt );

template <>
bool count_satisfy<pc::lv_trait::start>(unsigned cnt) {
  return cnt == 1;
}

template <>
bool count_satisfy<pc::lv_trait::bound>(unsigned cnt) {
  return cnt >= 1;
}

template <>
bool count_satisfy<pc::lv_trait::sweep>(unsigned cnt) {
  return cnt == 1;
}

template <pc::lv_trait LVTrait>
static
std::pair<pc::own_cpiece_t, pc::opkind>
maybe_build(const set_cso_t<obj::data_use>& dataUses) {

  auto lambdaDataInLoopOp = [] (cso_t<obj::data_use> dUse) {
      auto opOverDataUse = state<obj::bin_op>::get_containing( dUse );

      cso_t<obj::fun_loop> fLoop = nullptr;
      if (opOverDataUse != nullptr) {
        fLoop = state<obj::fun_loop>::get_containing( opOverDataUse );
      }

      if (opOverDataUse != nullptr and fLoop != nullptr) {
       //  std::cout << "BINOP " << opOverDataUse << " USE " << dUse << " " << LVTrait << '\n';
        return is_data_use_within_loop_operation< LVTrait >(opOverDataUse->get_operator_piece(), dUse);
      }
      return false;
    };

  // const auto& dataUses = dDecl->get_data_uses();

  // std::cout << "MAYBE BUILD Loop Var " << LVTrait << ". Data uses count : "<< std::count_if( std::begin(dataUses), std::end(dataUses), lambdaDataInLoopOp ) << '\n';


  if ( count_satisfy<LVTrait>( std::count_if( std::begin(dataUses), std::end(dataUses), lambdaDataInLoopOp ) ) ) {

    auto dUseUnique = *std::find_if( std::begin(dataUses), std::end(dataUses), lambdaDataInLoopOp );
    // std::cout << "Setting LOOP VAR << LVTrait << "\n";

    auto opUnique = state<obj::bin_op>::get_containing( dUseUnique );

    auto opPiece = opUnique->get_operator_piece();

    // return std::make_unique< token<pc::kind::binop> >( edit_piece( opPiece->get_lhs() ), transform_body_to_lparam( opPiece->get_rhs() ), opPiece->get_opkind() );
    return std::make_pair( edit_piece(opPiece->get_rhs()), opPiece->get_opkind() );

  } else {
    
    return std::make_pair( pc::make_undefined_lv_piece(), pc::opkind::undefined );
  }
}



void sobject<obj::data_decl>::maybe_detect_loop_variable() {

  // std::cout << "Maybe detect loop var : " << m_variableName << "...";

  if (this->check_loop_inner_properties()) {

    auto cstDataUses = this->get_data_uses();

    auto [startExpr, startOpk] = maybe_build<pc::lv_trait::start>( cstDataUses );
    auto [boundExpr, boundOpk] = maybe_build<pc::lv_trait::bound>( cstDataUses );
    auto [sweepExpr, sweepOpk] = maybe_build<pc::lv_trait::sweep>( cstDataUses );

    auto var = static_cast<pc::ctoken_t<pc::kind::var>>( (*cstDataUses.begin())->get_terminal() );

    m_ownedLoopVar = std::make_unique< pc::loop_var >( var, std::move(startExpr), startOpk, std::move(boundExpr), boundOpk, std::move(sweepExpr), sweepOpk );

    if (m_ownedLoopVar->all_defined()) {

      m_declarationKind = decl_kind::loop_variable;

      auto dUseDeclIt = std::find_if(std::begin(cstDataUses), std::end(cstDataUses),
          [] (cso_t<obj::data_use> dUse) {
            return dUse->get_access() == access_kind::init or dUse->get_access() == access_kind::write_only;
          });
      if (dUseDeclIt == std::end(cstDataUses)) {
        throw std::logic_error("Could not found representative dUse of new loopvar");
      }

      // std::cout << "========Built loop var : " << m_ownedLoopVar->get_info() << " all defined : " << m_ownedLoopVar->all_defined() << " : " << m_ownedLoopVar.get() << '\n';

    } else {

      // std::cout << "========At least one loop operation did not satisfy the properties to build a loop variable " << this->get_variable_name() << m_ownedLoopVar->get_info() << "\n";

      m_ownedLoopVar.reset();
    }

  } else {
    // std::cout << "this does not satisfy the basic properties for a loop variable\n";
  }
}



pc::cloopvar_t sobject<obj::data_decl>::get_loop_variable( ) const {
  return m_ownedLoopVar.get();
}


bool sobject<obj::data_decl>::has_guard() const {

  return m_ownedGuard.get() != nullptr;
}


pc::cguard_t
sobject<obj::data_decl>::get_guard() const {
  if (m_ownedGuard.get() == nullptr) {
    throw std::logic_error("Cannot get_guard in data_decl. Not initialized : " + this->get_identifier());
  }
  return m_ownedGuard.get();
}


void sobject<obj::data_decl>::set_guard() {

  // std::cout << "Setting guard : " << this->get_identifier() << '\n';

  auto dUses = this->edit_data_uses();

  if (dUses.empty()) {
    throw std::logic_error("Cannot make_guard. Empty uses : " + this->get_identifier());
  }

  auto allAccesses = transform_vec_if( dUses,  
      [] (sobject<obj::data_use> * dUse) {
        bool onAddr = dUse->on_address();
        if (onAddr) { dUse->set_mem_access(); }
        return onAddr;
      },
      [] (cso_t<obj::data_use> dUse) { return dUse->get_mem_access(); }
    );

  m_ownedGuard = pc::make_mem_guard( allAccesses, this );
}


bool sobject<obj::data_decl>::require_guard() const {


  auto dUsesThis = this->get_data_uses();

  auto nUsesArray = std::count_if(std::begin(dUsesThis), std::end(dUsesThis), [] (cso_t<obj::data_use> dUse) {
    return dUse->is_indirect_ref_argument();
  });

  auto fDefWithThis = this->get_root_function_definition();

  auto retBool = this->require_wrap() or (fDefWithThis != nullptr and this->m_declarationKind == decl_kind::fargument and (this->m_indirect == indir::ptr or this->m_indirect == indir::ref) and nUsesArray > 0);

  // std::cout << "require_guard return : " << this->get_identifier() << " : " << retBool << '\n';
  
  return retBool;
}

cso_t<obj::fun_def> sobject<obj::data_decl>::get_global_context() const {
  return this->get_root_function_definition();
}

csob_t sobject<obj::data_decl>::get_local_context() const {

  csob_t srcCtxt = nullptr;

  if (m_declarationKind == decl_kind::fargument or m_declarationKind == decl_kind::relaxed_fargument) {
    // Then we need to use the function body as the definitin context, as we allow other lparam to be placed after the m_dDeclRoot definition, but always before the start of the function body
    srcCtxt = this->get_root_function_definition()->get_body_context();

  } else {
    // Then m_dDeclRoot serves as a definition context. Expression will be transformed in terms of sth always defined before it.
    // srcCtxt = this; 
    srcCtxt = (*this->get_data_uses().begin())->get_operation();
  }

  if (srcCtxt == nullptr) {
    throw std::logic_error("Could not get_local_context in data_decl : nullptr");
  }

  return srcCtxt;
}


pc::cpiece_t sobject<obj::data_decl>::get_initialization() const {

  if (not this->is_set_once()) {
    throw std::logic_error("Could not get_initialization, not set once");
  }

  // Find the data use in this dDecl that has a access_kind::init
  auto dUses = this->get_data_uses();
  auto dUseInitIt = std::find_if(std::begin(dUses), std::end(dUses),
    [] (cso_t<obj::data_use> dUse) {
      return dUse->get_access() == access_kind::init or dUse->get_access() == access_kind::write_only;
    });
  if (dUseInitIt == std::end(dUses)) {
    throw std::runtime_error("Could not find data use initialization for : " + this->get_identifier() + ", varname : " + this->get_variable_name());
  }

  auto dUseInit = *dUseInitIt;

  // Get the associated operation
  if (not dUseInit->is_direct_operator_argument()) {
    throw std::runtime_error("Data use not in operation (transform_body_to_lparam");
  }

  auto initOp = dUseInit->get_operation();

  // return the rhs piece of the operation, recurse over it
  // std::cout << "\t\tReturning OP : " << initOp->get_operator_piece()->get_rhs()->get_pc_string() << '\n';

  return initOp->get_operator_piece()->get_rhs();
}


bool sobject<obj::data_decl>::is_set_once() const {

  if (m_declarationKind == decl_kind::loop_variable) {
    return true;
  }

  auto dUses = this->get_data_uses();

  auto editCount = std::count_if( std::begin(dUses), std::end(dUses),
    [] (cso_t<obj::data_use> dUse) {
      auto dUseAcc = dUse->get_access();
      if (dUseAcc == access_kind::init or dUseAcc == access_kind::read_write or dUseAcc == access_kind::write_only) {
        return true;
      }
      return false;
    } );

  bool setInside = m_declarationKind == decl_kind::body;
  bool setOutside = (m_declarationKind == decl_kind::fargument or m_declarationKind == decl_kind::relaxed_fargument);

  return ((editCount == 1 and setInside) or (editCount == 0 and setOutside));
}

} // namespace bld::src
