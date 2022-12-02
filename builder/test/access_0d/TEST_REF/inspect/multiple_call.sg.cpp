steel_builder_test_suite
multiple_call.cpp
/*

  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-6,c-1}];
  data:[voidfoo_ro_multiple(constfloat*bbb,inti){floatr;r=bbb[i];}];
  obj:[fun_def];

  name:[foo_ro_multiple];
  args:[
    0:[<builder/test/access_0d/multiple_call.cpp:000003-000022>];
    1:[<builder/test/access_0d/multiple_call.cpp:000003-000041>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000017-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000019-000003>];
    2:[<builder/test/access_0d/multiple_call.cpp:000026-000003>];
    3:[<builder/test/access_0d/multiple_call.cpp:000028-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000003-000001>];
    appId:[foo_ro_multiple_call_app];
    appImpl:[foo_ro_multiple];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-3,c-22}];
  end_loc:[{r-3,c-36}];
  data:[constfloat*b];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bbb];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000005-000007>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
    ];
    globalRanges:[
    ];
    globalCallRanges:[
    ];
    globalOffsets:[
      0:[
        pcKind:[var];
        pcContent:[i];
      ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-3,c-41}];
  end_loc:[{r-3,c-45}];
  data:[inti];
  obj:[data_decl];

  declKind:[fargument];
  varName:[i];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000005-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-3,c-48}];
  end_loc:[{r-6,c-1}];
  data:[{floatr;r=bbb[i];}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-12}];
  data:[r=bbb[i]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[i]];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-5,c-7}];
  end_loc:[{r-5,c-7}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000003-000022>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-5,c-11}];
  end_loc:[{r-5,c-11}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000003-000041>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-8,c-1}];
  end_loc:[{r-11,c-1}];
  data:[voidbar_ro_multiple(constfloat*bbb,inti){floatr;r=bbb[i];}];
  obj:[fun_def];

  name:[bar_ro_multiple];
  args:[
    0:[<builder/test/access_0d/multiple_call.cpp:000008-000022>];
    1:[<builder/test/access_0d/multiple_call.cpp:000008-000041>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000018-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000027-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000008-000001>];
    appId:[bar_ro_multiple_call_app];
    appImpl:[bar_ro_multiple];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-8,c-22}];
  end_loc:[{r-8,c-36}];
  data:[constfloat*b];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bbb];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000010-000007>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
    ];
    globalRanges:[
    ];
    globalCallRanges:[
    ];
    globalOffsets:[
      0:[
        pcKind:[var];
        pcContent:[i];
      ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-8,c-41}];
  end_loc:[{r-8,c-45}];
  data:[inti];
  obj:[data_decl];

  declKind:[fargument];
  varName:[i];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000010-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-8,c-48}];
  end_loc:[{r-11,c-1}];
  data:[{floatr;r=bbb[i];}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-9,c-3}];
  end_loc:[{r-9,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-10,c-3}];
  end_loc:[{r-10,c-12}];
  data:[r=bbb[i]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[i]];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-10,c-7}];
  end_loc:[{r-10,c-7}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000008-000022>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000010-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-10,c-11}];
  end_loc:[{r-10,c-11}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000008-000041>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000010-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-13,c-1}];
  end_loc:[{r-20,c-1}];
  data:[voidcaller1_ro_multiple_call(){intj=4;float*ppp;foo_ro_multiple(ppp,j);bar_ro_multiple(ppp,j);foo_ro_multiple(ppp,j);}];
  obj:[fun_def];

  name:[caller1_ro_multiple_call];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000017-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000018-000003>];
    2:[<builder/test/access_0d/multiple_call.cpp:000019-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000013-000001>];
    appId:[caller1_ro_multiple_call];
    appImpl:[caller1_ro_multiple_call];
    returnType:[task::coro::dispatcher<app::impl::caller1_ro_multiple_call>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-13,c-33}];
  end_loc:[{r-20,c-1}];
  data:[{intj=4;float*ppp;foo_ro_multiple(ppp,j);bar_ro_multiple(ppp,j);foo_ro_multiple(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-14,c-3}];
  end_loc:[{r-14,c-12}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init 4];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-14,c-11}];
  end_loc:[{r-14,c-11}];
  data:[4];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000014-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[4];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-15,c-3}];
  end_loc:[{r-15,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-17,c-3}];
  end_loc:[{r-17,c-25}];
  data:[foo_ro_multiple(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000013-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-17,c-19}];
  end_loc:[{r-17,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000015-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-17,c-24}];
  end_loc:[{r-17,c-24}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-18,c-3}];
  end_loc:[{r-18,c-25}];
  data:[bar_ro_multiple(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000008-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000013-000001>];
  own:[
    pcKind:[call];
    pcContent:[bar_ro_multiple((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-18,c-19}];
  end_loc:[{r-18,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000015-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000008-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-18,c-24}];
  end_loc:[{r-18,c-24}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000008-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-19,c-3}];
  end_loc:[{r-19,c-25}];
  data:[foo_ro_multiple(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000013-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-19,c-19}];
  end_loc:[{r-19,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000015-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-19,c-24}];
  end_loc:[{r-19,c-24}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-22,c-1}];
  end_loc:[{r-29,c-1}];
  data:[voidcaller2_ro_multiple_call(intk){intj=k;float*ppp;foo_ro_multiple(ppp,j);bar_ro_multiple(ppp,j);foo_ro_multiple(ppp,j);}];
  obj:[fun_def];

  name:[caller2_ro_multiple_call];
  args:[
    0:[<builder/test/access_0d/multiple_call.cpp:000022-000031>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000026-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000027-000003>];
    2:[<builder/test/access_0d/multiple_call.cpp:000028-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000022-000001>];
    appId:[caller2_ro_multiple_call];
    appImpl:[caller2_ro_multiple_call];
    returnType:[task::coro::dispatcher<app::impl::caller2_ro_multiple_call>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-22,c-31}];
  end_loc:[{r-22,c-35}];
  data:[intk];
  obj:[data_decl];

  declKind:[fargument];
  varName:[k];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000023-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-22,c-38}];
  end_loc:[{r-29,c-1}];
  data:[{intj=k;float*ppp;foo_ro_multiple(ppp,j);bar_ro_multiple(ppp,j);foo_ro_multiple(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-23,c-3}];
  end_loc:[{r-23,c-12}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init k];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-23,c-11}];
  end_loc:[{r-23,c-11}];
  data:[k];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000022-000031>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000023-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[k];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-24,c-3}];
  end_loc:[{r-24,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-25}];
  data:[foo_ro_multiple(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000022-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-26,c-19}];
  end_loc:[{r-26,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000024-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-26,c-24}];
  end_loc:[{r-26,c-24}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-27,c-25}];
  data:[bar_ro_multiple(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000008-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000022-000001>];
  own:[
    pcKind:[call];
    pcContent:[bar_ro_multiple((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-27,c-19}];
  end_loc:[{r-27,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000024-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000008-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-27,c-24}];
  end_loc:[{r-27,c-24}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000008-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-28,c-3}];
  end_loc:[{r-28,c-25}];
  data:[foo_ro_multiple(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000022-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-28,c-19}];
  end_loc:[{r-28,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000024-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-28,c-24}];
  end_loc:[{r-28,c-24}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000003-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-32,c-1}];
  end_loc:[{r-35,c-1}];
  data:[voidfoo_rw_multiple_call(float*bbb,inti){floatr;bbb[i]=r;}];
  obj:[fun_def];

  name:[foo_rw_multiple_call];
  args:[
    0:[<builder/test/access_0d/multiple_call.cpp:000032-000027>];
    1:[<builder/test/access_0d/multiple_call.cpp:000032-000040>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000046-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000048-000003>];
    2:[<builder/test/access_0d/multiple_call.cpp:000055-000003>];
    3:[<builder/test/access_0d/multiple_call.cpp:000057-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000032-000001>];
    appId:[foo_rw_multiple_call_app];
    appImpl:[foo_rw_multiple_call];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-32,c-27}];
  end_loc:[{r-32,c-35}];
  data:[float*b];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bbb];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000034-000003>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
    ];
    globalRanges:[
    ];
    globalCallRanges:[
    ];
    globalOffsets:[
      0:[
        pcKind:[var];
        pcContent:[i];
      ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-32,c-40}];
  end_loc:[{r-32,c-44}];
  data:[inti];
  obj:[data_decl];

  declKind:[fargument];
  varName:[i];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000034-000007>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-32,c-47}];
  end_loc:[{r-35,c-1}];
  data:[{floatr;bbb[i]=r;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-33,c-3}];
  end_loc:[{r-33,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-34,c-12}];
  data:[bbb[i]=r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bbb[i] assign r];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-34,c-7}];
  end_loc:[{r-34,c-7}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000032-000040>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000034-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-34,c-12}];
  end_loc:[{r-34,c-12}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000033-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000034-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-37,c-1}];
  end_loc:[{r-40,c-1}];
  data:[voidbar_rw_multiple_call(float*bbb,inti){floatr;bbb[i]=r;}];
  obj:[fun_def];

  name:[bar_rw_multiple_call];
  args:[
    0:[<builder/test/access_0d/multiple_call.cpp:000037-000027>];
    1:[<builder/test/access_0d/multiple_call.cpp:000037-000040>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000047-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000056-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000037-000001>];
    appId:[bar_rw_multiple_call_app];
    appImpl:[bar_rw_multiple_call];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-37,c-27}];
  end_loc:[{r-37,c-35}];
  data:[float*b];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bbb];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000039-000003>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
    ];
    globalRanges:[
    ];
    globalCallRanges:[
    ];
    globalOffsets:[
      0:[
        pcKind:[var];
        pcContent:[i];
      ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-37,c-40}];
  end_loc:[{r-37,c-44}];
  data:[inti];
  obj:[data_decl];

  declKind:[fargument];
  varName:[i];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000039-000007>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-37,c-47}];
  end_loc:[{r-40,c-1}];
  data:[{floatr;bbb[i]=r;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-38,c-3}];
  end_loc:[{r-38,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-39,c-3}];
  end_loc:[{r-39,c-12}];
  data:[bbb[i]=r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bbb[i] assign r];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-39,c-7}];
  end_loc:[{r-39,c-7}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000037-000040>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000039-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-39,c-12}];
  end_loc:[{r-39,c-12}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000038-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000039-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-42,c-1}];
  end_loc:[{r-49,c-1}];
  data:[voidcaller1_rw_multiple_call(){intj=4;float*ppp;foo_rw_multiple_call(ppp,j);bar_rw_multiple_call(ppp,j);foo_rw_multiple_call(ppp,j);}];
  obj:[fun_def];

  name:[caller1_rw_multiple_call];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000046-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000047-000003>];
    2:[<builder/test/access_0d/multiple_call.cpp:000048-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000042-000001>];
    appId:[caller1_rw_multiple_call];
    appImpl:[caller1_rw_multiple_call];
    returnType:[task::coro::dispatcher<app::impl::caller1_rw_multiple_call>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-42,c-33}];
  end_loc:[{r-49,c-1}];
  data:[{intj=4;float*ppp;foo_rw_multiple_call(ppp,j);bar_rw_multiple_call(ppp,j);foo_rw_multiple_call(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-43,c-3}];
  end_loc:[{r-43,c-12}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init 4];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-43,c-11}];
  end_loc:[{r-43,c-11}];
  data:[4];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000043-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[4];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-44,c-3}];
  end_loc:[{r-44,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-46,c-3}];
  end_loc:[{r-46,c-30}];
  data:[foo_rw_multiple_call(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000032-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000042-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_call((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-46,c-24}];
  end_loc:[{r-46,c-24}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000044-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-46,c-29}];
  end_loc:[{r-46,c-29}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000043-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-47,c-3}];
  end_loc:[{r-47,c-30}];
  data:[bar_rw_multiple_call(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000037-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000042-000001>];
  own:[
    pcKind:[call];
    pcContent:[bar_rw_multiple_call((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-47,c-24}];
  end_loc:[{r-47,c-24}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000044-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000037-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-47,c-29}];
  end_loc:[{r-47,c-29}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000043-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000037-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-48,c-3}];
  end_loc:[{r-48,c-30}];
  data:[foo_rw_multiple_call(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000032-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000042-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_call((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-48,c-24}];
  end_loc:[{r-48,c-24}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000044-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-48,c-29}];
  end_loc:[{r-48,c-29}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000043-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-51,c-1}];
  end_loc:[{r-58,c-1}];
  data:[voidcaller2_rw_multiple_call(intk){intj=k;float*ppp;foo_rw_multiple_call(ppp,j);bar_rw_multiple_call(ppp,j);foo_rw_multiple_call(ppp,j);}];
  obj:[fun_def];

  name:[caller2_rw_multiple_call];
  args:[
    0:[<builder/test/access_0d/multiple_call.cpp:000051-000031>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_call.cpp:000055-000003>];
    1:[<builder/test/access_0d/multiple_call.cpp:000056-000003>];
    2:[<builder/test/access_0d/multiple_call.cpp:000057-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_call.cpp:000051-000001>];
    appId:[caller2_rw_multiple_call];
    appImpl:[caller2_rw_multiple_call];
    returnType:[task::coro::dispatcher<app::impl::caller2_rw_multiple_call>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-51,c-31}];
  end_loc:[{r-51,c-35}];
  data:[intk];
  obj:[data_decl];

  declKind:[fargument];
  varName:[k];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_call.cpp:000052-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-51,c-38}];
  end_loc:[{r-58,c-1}];
  data:[{intj=k;float*ppp;foo_rw_multiple_call(ppp,j);bar_rw_multiple_call(ppp,j);foo_rw_multiple_call(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-52,c-3}];
  end_loc:[{r-52,c-12}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init k];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-52,c-11}];
  end_loc:[{r-52,c-11}];
  data:[k];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000051-000031>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000052-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[k];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-53,c-3}];
  end_loc:[{r-53,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-55,c-3}];
  end_loc:[{r-55,c-30}];
  data:[foo_rw_multiple_call(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000032-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000051-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_call((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-55,c-24}];
  end_loc:[{r-55,c-24}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000053-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-55,c-29}];
  end_loc:[{r-55,c-29}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000052-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-56,c-3}];
  end_loc:[{r-56,c-30}];
  data:[bar_rw_multiple_call(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000037-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000051-000001>];
  own:[
    pcKind:[call];
    pcContent:[bar_rw_multiple_call((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-56,c-24}];
  end_loc:[{r-56,c-24}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000053-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000037-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-56,c-29}];
  end_loc:[{r-56,c-29}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000052-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000037-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-57,c-3}];
  end_loc:[{r-57,c-30}];
  data:[foo_rw_multiple_call(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_call.cpp:000032-000001>];
  caller:[<builder/test/access_0d/multiple_call.cpp:000051-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_call((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-57,c-24}];
  end_loc:[{r-57,c-24}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000053-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ppp];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_call.cpp];
  begin_loc:[{r-57,c-29}];
  end_loc:[{r-57,c-29}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_call.cpp:000052-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_call.cpp:000032-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];
*/