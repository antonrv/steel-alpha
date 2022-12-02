
#include "source/object/function/definition.hpp"

#include "source/object/function/call.hpp"
#include "source/object/data/decl.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src {

std::string sobject<obj::fun_def>::serial() const {

  auto argsStr = transform_vec( this->get_arguments(), [] ( cso_t<obj::data_decl> dDecl) { return dDecl->get_identifier(); } );
  auto bodyCallsStr = transform_vec( this->get_body_calls(), [] ( cso_t<obj::fun_call> fCall ) { return fCall->get_identifier(); } );
  auto externCallsStr = transform_vec( this->get_extern_calls(), [] ( cso_t<obj::fun_call> fCall ) { return fCall->get_identifier(); } );

  return sobject_base::serial() +
      make_serial<6>(
        {"name:","args:","retArg:","bodyCalls:","externCalls:","task:"},
        m_functionName,
        argsStr,
        std::string(m_argumentReturn ? m_argumentReturn->get_identifier() : "NULL"),
        bodyCallsStr,
        externCallsStr,
        m_ownedTask
    );

}

} // namespace bld::src
