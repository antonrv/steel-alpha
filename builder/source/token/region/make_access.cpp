
#include "source/token/region/make_access.hpp"

#include "source/token/factorize.hpp"

#ifndef PARSER_TEST
  #include "source/object/data/use.hpp"
#endif // PARSER_TEST

// Derived classes declared in make_access.hpp

#include <iostream> // DBG XXX

namespace bld::src::pc {

#ifndef PARSER_TEST
static
mem_ak deduce_mem_access_kind( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, cso_t<obj::data_use> dUse ) {

  if (inputPc->is_arith()) {

    auto cnt = count_contiguous_factors(inputPc, lvLambda);

    if ((cnt == 0 and dUse->is_callee_arg_ref()) or (cnt == 0 and (not dUse->is_direct_call_argument()) and not dUse->is_indirect_ptr())) {
      return mem_ak::point;
    } else if (cnt == 1 or (cnt == 0 and (dUse->is_callee_arg_ptr() or dUse->is_indirect_ptr()))) {
      return mem_ak::affine;
    } else {
      return mem_ak::non_affine;
    }

  } else if (inputPc->get_kind() == kind::offset or inputPc->get_kind() == kind::call) {

    return mem_ak::indirect;

  } else {

    throw std::runtime_error("Could not deduce_mem_access_kind : Unhandled case");
  }
}
#else
mem_ak deduce_mem_access_kind( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, cso_t<obj::data_use> dUse ) {

  if (inputPc->is_arith()) {

    auto cnt = count_contiguous_factors(inputPc, lvLambda);

    if (cnt == 0 or cnt == 1) {
      return mem_ak::affine;
    } else {
      return mem_ak::non_affine;
    }

  } else if (inputPc->get_kind() == kind::offset or inputPc->get_kind() == kind::call) {

    return mem_ak::indirect;

  } else {

    throw std::runtime_error("Could not deduce_mem_access_kind : Unhandled case");
  }
}


#endif // PARSER_TEST


std::unique_ptr<access> 
make_mem_access( cpiece_t inputPc, std::function<bool(cpiece_t)> lvLambda, cso_t<obj::data_use> dUse ) {

  // std::cout << "MAKING MEM ACCESS FROM " << dUse << " : " << inputPc->get_pc_string() << " ptr " << inputPc << '\n';

  auto memAccKind = deduce_mem_access_kind( inputPc, lvLambda, dUse );

  if (memAccKind == mem_ak::point) {

    // return std::make_unique< mem_access<mem_ak::affine> >( inputPc, lvLambda, dUse );
    return std::make_unique< mem_access<mem_ak::point> >( inputPc, dUse );

  } else if (memAccKind == mem_ak::affine) {
  
    return std::make_unique< mem_access<mem_ak::affine> >( inputPc, lvLambda, dUse );

  } else if (memAccKind == mem_ak::non_affine) {
  
    throw std::runtime_error("TO BE IMPLEMENTED : make_mem_access for non_affine");

    // return std::make_unique< mem_access<mem_ak::non_affine> >( inputPc, dUse );

  } else if (memAccKind == mem_ak::indirect) {

    throw std::runtime_error("TO BE IMPLEMENTED : make_mem_access for indirect");

    // return std::make_unique< mem_access<mem_ak::indirect> >( inputPc, dUse );

  } else {

    throw std::runtime_error("Could not make_mem_access : Unknown expression for : " + inputPc->get_pc_string() + " of data use");
  }

}

} // namespace bld::src::pc
