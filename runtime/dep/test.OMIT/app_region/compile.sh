


########## Autogen app enums
run/gen_events dep/test/app_region/enum.dat app

########## Compile app
clang++-11 -std=c++2a -stdlib=libc++ -fmodules --precompile dep/test/app_region/enum.dat.cppm \
  -fmodules-cache-path=pcm/std \
  -fmodule-file=pcm/util/types.pcm \
  -fmodule-file=pcm/util/values.pcm \
  -fmodule-file=pcm/util/sequence.pcm \
  -fmodule-file=pcm/instr/fw_decl.pcm \
  -o pcm/dep/test/app_region/enum.dat.pcm

clang++-11 -std=c++2a -stdlib=libc++ -fmodules --precompile dep/test/app_region/traits_ag.cppm \
  -fmodules-cache-path=pcm/std \
  -fmodule-file=pcm/util/types.pcm \
  -fmodule-file=pcm/util/tuple.pcm \
  -fmodule-file=pcm/util/fw_decl_app.pcm \
  -fmodule-file=pcm/util/sequence.pcm \
  -fmodule-file=pcm/dep/test/app_region/enum.dat.pcm \
  -fmodule-file=pcm/dep/bnd_guard.pcm \
  -fmodule-file=pcm/data/view_1d.pcm \
  -o pcm/dep/test/app_region/traits_ag.pcm

clang++-11 -std=c++2a -stdlib=libc++ -fmodules --precompile dep/test/app_region/user_kernel_tr.cppm \
  -fmodules-cache-path=pcm/std \
  -fmodule-file=pcm/dep/test/app_region/enum.dat.pcm \
  -fmodule-file=pcm/data/view_1d.pcm \
  -o pcm/dep/test/app_region/user_kernel_tr.pcm

clang++-11 -std=c++2a -stdlib=libc++ -fmodules -c dep/test/app_region/user_kernel_tr.cpp \
  -fmodules-cache-path=pcm/std \
  -g \
  -fmodule-file=pcm/dep/test/app_region/user_kernel_tr.pcm \
  -o obj/dep/test/app_region/user_kernel_tr.o

clang++-11 -std=c++2a -stdlib=libc++ -fmodules --precompile dep/test/app_region/proxy_kernel_ag.cppm \
  -fmodules-cache-path=pcm/std \
  -fmodule-file=pcm/dep/test/app_region/traits_ag.pcm \
  -fmodule-file=pcm/util/types.pcm \
  -fmodule-file=pcm/util/fw_decl_app.pcm \
  -fmodule-file=pcm/dep/test/app_region/user_kernel_tr.pcm \
  -fmodule-file=pcm/util/sequence.pcm \
  -o pcm/dep/test/app_region/proxy_kernel_ag.pcm

# clang++-11 -std=c++2a -stdlib=libc++ -fmodules --precompile dep/test/app_region/proxy_kernel_ag.cppm \
