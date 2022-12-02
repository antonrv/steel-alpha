#ifndef STEEL_CPOMPILER_ELEMENT_FILE_ENUM_HPP
#define STEEL_CPOMPILER_ELEMENT_FILE_ENUM_HPP

#include "common/fun_sequences_std17.hpp"


#define ALL_FILE_KINDS \
undefined, \
input, \
sgraph, \
inspected, \
translation, \
runtime, \
autogen, \
compilable, \
compiled, \
executable

ENUM_DEFINITION(bld, file_kind, ALL_FILE_KINDS)
ENABLE_SEQUENCE(bld, file_kind, ALL_FILE_KINDS)


ENUM_DEFINITION(bld, code, undefined, interface, implementation, entry)






#define ALL_EXTS \
implementation, \
entry, \
header, \
module_interface, \
module_precompiled, \
object, \
executable, \
sgraph, \
translation, \
autogen, \
undefined, \
any, \
none

ENUM_DEFINITION(bld, ext, ALL_EXTS)

ENABLE_SEQUENCE(bld, ext, ALL_EXTS)

#endif // STEEL_CPOMPILER_ELEMENT_FILE_ENUM_HPP
