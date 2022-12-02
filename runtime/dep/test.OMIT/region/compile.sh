

########## Autogen test case_id
run/gen_events dep/test/region/cases.dat test

clang++-11 -std=c++2a -stdlib=libc++ -fmodules --precompile dep/test/region/cases.dat.cppm \
  -fmodules-cache-path=pcm/std \
  -fmodule-file=pcm/util/types.pcm \
  -fmodule-file=pcm/util/values.pcm \
  -fmodule-file=pcm/util/sequence.pcm \
  -fmodule-file=pcm/instr/fw_decl.pcm \
  -o pcm/dep/test/region/cases.dat.pcm

# clang++-11 -std=c++2a -stdlib=libc++ -fmodules  --precompile dep/test/region/enable_events.cppm \
#   -fmodule-file=pcm/instr/events.dat.pcm \
#   -o pcm/dep/test/region/enable_events.pcm


clang++-11 -std=c++2a -stdlib=libc++ -fmodules --precompile dep/test/region/run_cases.cppm \
  -fmodules-cache-path=pcm/std \
  -fmodule-file=pcm/safe/check.pcm \
  -fmodule-file=pcm/test/interface.pcm \
  -fmodule-file=pcm/test/interface.pcm \
  -fmodule-file=pcm/test/base_runner.pcm \
  -fmodule-file=pcm/dep/test/region/cases.dat.pcm \
  -o pcm/dep/test/region/run_cases.pcm
  # -fmodule-file=pcm/dep/test/region/enable_events.pcm \


clang++-11 -std=c++2a -stdlib=libc++ -fmodules -c dep/test/region/run_cases.cpp \
  -fmodules-cache-path=pcm/std \
  -g \
  -fmodule-file=pcm/dep/test/region/run_cases.pcm \
  -fmodule-file=pcm/dep/interface.pcm \
  -fmodule-file=pcm/dep/test/app_region/traits_ag.pcm \
  -fmodule-file=pcm/dep/test/app_region/proxy_kernel_ag.pcm \
  -fmodule-file=pcm/dep/test/app_region/user_kernel_tr.pcm \
  -o obj/dep/test/region/run_cases.o


clang++-11 -std=c++2a -stdlib=libc++ -fmodules test/main.cxx \
  -fmodules-cache-path=pcm/std \
  -g \
  -fmodule-file=pcm/dep/test/region/run_cases.pcm \
  obj/descriptor_state.o \
  obj/instr_interface.o \
  obj/dep/test/app_region/user_kernel_tr.o \
  obj/dep/test/region/run_cases.o \
  obj/util/values.o \
  obj/safe/assert.o \
  -o run/dep_region.rn
