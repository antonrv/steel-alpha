#ifndef STEEL_COMPILER_GENERATION_GENERATOR_HPP
#define STEEL_COMPILER_GENERATION_GENERATOR_HPP

#include "source/object/function/call.hpp"

#include "generate/gen_kind_enum.hpp"

#include "files/typedef.hpp"

#include "files/name/decl.hpp"

namespace bld {


class generator {


  // Needed to generate files from user applications
  src::vec_ctask_t m_taskDefinitions;

  src::set_cso_t<src::obj::fun_call> m_taskCalls;


  // state::filename m_rtInstrumentEventsFn;

  // state::filename m_rtTestCasesFn;

public:

  // generator(const src::vec_ctask_t& ink, const input_calls_t& inc, state::filename ifn) : m_taskDefinitions(ink), m_taskCalls(inc), m_rtInstrumentEventsFn(ifn) {}
  generator() {}

  template <gen_kind GK>
  cfileb_t run(key_path targetKp, state::filename fn);

  void set_kernel_elements(src::vec_ctask_t kernels, src::set_cso_t<src::obj::fun_call> calls) {
    m_taskDefinitions = kernels;
    m_taskCalls = calls;
  }

  // void set_rt_test_cases(state::filename rtcases) {
  //   m_rtTestCasesFn = rtcases;
  // }

  // void set_rt_instrument_filename(state::filename rtinst) {
  //   m_rtInstrumentEventsFn = rtinst;
  // }
};

} // namespace bld

#endif // STEEL_COMPILER_GENERATION_GENERATOR_HPP
