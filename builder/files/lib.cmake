
add_library(SteelBuilderPaths SHARED

  files/name/def.cpp
  files/name/visible.cpp
  files/name/factory.cpp
  files/paths/aux.cpp
  files/paths/instantiations.cpp
)

target_compile_features(SteelBuilderPaths PRIVATE cxx_std_17)
target_compile_options(SteelBuilderPaths PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderPaths
  PUBLIC
  SteelBuilderCommon
)

#############################################
#############
############# FILES LIBRARY
#############
#############################################
add_library(SteelBuilderFiles SHARED

  files/felement/base.cpp
  files/felement/instantiations.cpp


  files/traits/code.cpp

  files/semantic/bitcode.cpp

  files/state/instantiate/input.cpp
  files/state/instantiate/sgraph.cpp
  files/state/instantiate/inspected.cpp
  files/state/instantiate/translation.cpp
  files/state/instantiate/runtime.cpp
  files/state/instantiate/autogen.cpp
  files/state/instantiate/compilable.cpp
  files/state/instantiate/compiled.cpp
  files/state/instantiate/executable.cpp

  files/state/register_yield.cpp
  files/state/find.cpp
)

target_compile_features(SteelBuilderFiles PRIVATE cxx_std_17)
target_compile_options(SteelBuilderFiles PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderFiles
  PUBLIC
  SteelBuilderPaths
  SteelBuilderOptions
)


add_library(SteelBuilderModules SHARED
  files/module/def.cpp
  files/state/module/def.cpp
)

target_compile_features(SteelBuilderModules PRIVATE cxx_std_17)
target_compile_options(SteelBuilderModules PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderModules
  PUBLIC
  SteelBuilderFiles
)
