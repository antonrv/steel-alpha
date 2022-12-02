
#include "source/object/data/decl.hpp"

#include "source/serial/make_serial.hpp"

namespace bld::src {

std::string sobject<obj::data_decl>::serial() const {

  // Not owned -> get its id only
  auto dUsesStr = transform_vec( this->get_data_uses(), [] (cso_t<obj::data_use> dUse ) { return dUse->get_identifier(); } );

  return sobject_base::serial() +
      make_serial<11>(
        {"declKind:","varName:","typeName:","translationType:","typeQual:","indir:","indirQual:","allowAcc:","dUses:","loopVar:","memGuard:"},
        m_declarationKind,
        m_variableName,
        m_typeName,
        m_translationType,
        m_typeQual,
        m_indirect,
        m_indirectQual,
        m_allowedAccess,
        dUsesStr,
        m_ownedLoopVar,
        m_ownedGuard
      );

}

} // namespace bld::src
