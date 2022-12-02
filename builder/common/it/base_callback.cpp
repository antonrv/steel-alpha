#include "common/it/base_callback.hpp"

namespace bld {

BaseCB::BaseCB(const clang::SourceManager& sm, const clang::ASTContext& ac) : m_sourceManager(sm), m_astContext(ac) {}


} // BaseCB
