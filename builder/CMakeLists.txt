set(DBG "-g")
#set(DBG "")

set(CMAKE_CXX_STANDARD 17)


#############################################
#############
############# COMMON LIBRARY
#############
#############################################
add_library(SteelBuilderCommon SHARED
  common/aux.cpp
  # element/base.cpp
)


target_compile_features(SteelBuilderCommon PRIVATE cxx_std_17)
target_compile_options(SteelBuilderCommon PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderCommon
  PUBLIC
  stdc++
  stdc++fs
  c++abi
)


include(files/lib.cmake)




include(source/lib.cmake)



include(options/lib.cmake)


#############################################
#############
############# TEST LIBRARY
#############
#############################################
add_library(SteelBuilderTest SHARED
  common/test/run.cpp
  common/test/compare.cpp
)

target_compile_features(SteelBuilderTest PRIVATE cxx_std_17)
target_compile_options(SteelBuilderTest PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderTest
  PUBLIC
  SteelBuilderFiles
  SteelBuilderOptions
)


#############################################
#############
############# COMMON CODE-INJECTION LIBRARY (for TG) (INTEGRATE IN OTHER TODO)
#############
#############################################
add_library(SteelBuilderInject SHARED
   common/inject/syntax_str.cpp
)
target_compile_features(SteelBuilderInject PRIVATE cxx_std_17)
target_compile_options(SteelBuilderInject PRIVATE -fexceptions -fno-rtti ${DBG})

target_link_libraries(SteelBuilderInject
  PUBLIC
  stdc++
  c++abi
)



include(inspect/lib.cmake)

include(translate/lib.cmake)
 
include(generate/lib.cmake)



# # #############################################
# # #############
# # ############# COMMON MIDDLEEND-STAGE LIBRARY (middleend is SCL)
# # #############
# # #############################################
# # add_library(SteelBuilderMiddlend SHARED
# #   files/state/translation.cpp
# #   files/state/generation.cpp
# #   files/state/runtime.cpp
# #   files/state/compilable.cpp
# #   state/elements_module.cpp
# #   element/module.cpp
# # )
# # 
# # target_compile_features(SteelBuilderMiddlend PRIVATE cxx_std_17)
# # target_compile_options(SteelBuilderMiddlend PRIVATE -fexceptions -fno-rtti ${DBG})
# # 
# # target_link_libraries(SteelBuilderMiddlend
# #   PUBLIC
# #   SteelBuilderPaths
# # )

include(scan/lib.cmake)


# # #############################################
# # #############
# # ############# BACKEND LIBRARY (DL stages are backend)
# # #############
# # #############################################
# # add_library(SteelBuilderBackend SHARED
# #   files/state/compiled.cpp
# # )
# # 
# # target_compile_features(SteelBuilderBackend PRIVATE cxx_std_17)
# # target_compile_options(SteelBuilderBackend PRIVATE -fexceptions -fno-rtti ${DBG})
# # 
# # 
# # target_link_libraries(SteelBuilderBackend
# #   PUBLIC
# #   SteelBuilderMiddlend
# # )
# 
include(compile/lib.cmake)
# 
include(link/lib.cmake)


include( driver/entry.cmake )
