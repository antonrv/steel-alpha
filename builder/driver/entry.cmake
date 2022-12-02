
### TODO
# add_steel_driver_exec( steps ) {
# 
# // INITSTEPS = get initials of steps
# // LIBS = SteelBuilder$CapitalizeStep
# 
# add_clang_executable(steelbld-${INITSTEPS} driver/entry.cpp )
# target_compile_features(steelbld-${INITSTEPS} PRIVATE cxx_std_17)
# target_compile_options(steelbld-${INITSTEPS} PRIVATE -DINPUT_STEPS=${STEPS} -fexceptions -fno-rtti ${DBG})
# target_link_libraries(steelbld-${INITSTEPS} PUBLIC ${BUILDERLIBS})
# 
# }
# 
# add_steel_driver_exec(inspect)
# add_steel_driver_exec(inspect,translate)
# add_steel_driver_exec(inspect,translate,generate)
# add_steel_driver_exec(inspect,translate,generate,scan)
# add_steel_driver_exec(inspect,translate,generate,scan,compile)
# add_steel_driver_exec(inspect,translate,generate,scan,compile,link)


#############################################
#############
############# INSPECTOR EXECUTABLE
#############
#############################################
add_clang_executable(steelbld-i driver/entry.cpp )
target_compile_features(steelbld-i PRIVATE cxx_std_17)
target_compile_options(steelbld-i PRIVATE -DINPUT_STEPS=inspect -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-i PUBLIC SteelBuilderInspect)


#############################################
#############
############# TRANSLATOR EXECUTABLE
#############
#############################################
add_clang_executable(steelbld-t driver/entry.cpp )
target_compile_features(steelbld-t PRIVATE cxx_std_17)
target_compile_options(steelbld-t PRIVATE -DINPUT_STEPS=translate -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-t PUBLIC SteelBuilderTranslate)


#############################################
#############
############# GENERATOR EXECUTABLE
#############
#############################################
add_clang_executable(steelbld-g driver/entry.cpp )
target_compile_features(steelbld-g PRIVATE cxx_std_17)
target_compile_options(steelbld-g PRIVATE -DINPUT_STEPS=generate -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-g PUBLIC SteelBuilderGenerate)


#############################################
#############
############# SCAN EXECUTABLE
#############
#############################################
add_clang_executable(steelbld-s driver/entry.cpp )
target_compile_features(steelbld-s PRIVATE cxx_std_17)
target_compile_options(steelbld-s PRIVATE -DINPUT_STEPS=scan -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-s PUBLIC SteelBuilderScan)


#############################################
#############
############# COMPILE EXECUTABLE
#############
#############################################
add_clang_executable(steelbld-c driver/entry.cpp )
target_compile_features(steelbld-c PRIVATE cxx_std_17)
target_compile_options(steelbld-c PRIVATE -DINPUT_STEPS=compile -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-c PUBLIC SteelBuilderCompile)


#############################################
#############
############# LINK EXECUTABLE
#############
#############################################
add_clang_executable(steelbld-l driver/entry.cpp )
target_compile_features(steelbld-l PRIVATE cxx_std_17)
target_compile_options(steelbld-l PRIVATE -DINPUT_STEPS=link -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-l PUBLIC SteelBuilderLink)

#############################################
#############
############# BUILDING PIPELINES
#############
#############################################

add_clang_executable(steelbld-it driver/entry.cpp )
target_compile_features(steelbld-it PRIVATE cxx_std_17)
target_compile_options(steelbld-it PRIVATE -DINPUT_STEPS=inspect,translate -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-it PUBLIC SteelBuilderInspect SteelBuilderTranslate)

add_clang_executable(steelbld-itg driver/entry.cpp )
target_compile_features(steelbld-itg PRIVATE cxx_std_17)
target_compile_options(steelbld-itg PRIVATE -DINPUT_STEPS=inspect,translate,generate -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-itg PUBLIC SteelBuilderInspect SteelBuilderTranslate SteelBuilderGenerate)

add_clang_executable(steelbld-itgs driver/entry.cpp )
target_compile_features(steelbld-itgs PRIVATE cxx_std_17)
target_compile_options(steelbld-itgs PRIVATE -DINPUT_STEPS=inspect,translate,generate,scan -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-itgs PUBLIC SteelBuilderInspect SteelBuilderTranslate SteelBuilderGenerate SteelBuilderScan)

add_clang_executable(steelbld-itgsc driver/entry.cpp )
target_compile_features(steelbld-itgsc PRIVATE cxx_std_17)
target_compile_options(steelbld-itgsc PRIVATE -DINPUT_STEPS=inspect,translate,generate,scan,compile -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-itgsc PUBLIC SteelBuilderInspect SteelBuilderTranslate SteelBuilderGenerate SteelBuilderScan SteelBuilderCompile)

add_clang_executable(steelbld-itgscl driver/entry.cpp )
target_compile_features(steelbld-itgscl PRIVATE cxx_std_17)
target_compile_options(steelbld-itgscl PRIVATE -DINPUT_STEPS=inspect,translate,generate,scan,compile,link -fexceptions -fno-rtti ${DBG})
target_link_libraries(steelbld-itgscl PUBLIC SteelBuilderInspect SteelBuilderTranslate SteelBuilderGenerate SteelBuilderScan SteelBuilderCompile SteelBuilderLink)
