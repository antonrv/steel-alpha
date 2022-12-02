steel_builder_test_suite
bounds.cpp
/*

  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-4,c-1}];
  end_loc:[{r-9,c-1}];
  data:[voidfoo_lt_add(constfloat*bbb,intnn){floatr;for(intii=0;ii<nn;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_lt_add];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000004-000017>];
    1:[<builder/test/access_1d/bounds.cpp:000004-000036>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000015-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000004-000001>];
    appId:[foo_lt_add];
    appImpl:[foo_lt_add];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-4,c-17}];
  end_loc:[{r-4,c-31}];
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
    0:[<builder/test/access_1d/bounds.cpp:000007-000009>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Maxnn ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min; Max ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-4,c-36}];
  end_loc:[{r-4,c-40}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000006-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-4,c-44}];
  end_loc:[{r-9,c-1}];
  data:[{floatr;for(intii=0;ii<nn;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-8,c-3}];
  data:[for(intii=0;ii<nn;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-6,c-8}];
  end_loc:[{r-6,c-18}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-6,c-17}];
  end_loc:[{r-6,c-17}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000006-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-6,c-20}];
  end_loc:[{r-6,c-25}];
  data:[ii<nn];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-6,c-25}];
  end_loc:[{r-6,c-25}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000004-000036>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000006-000020>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-6,c-29}];
  end_loc:[{r-6,c-31}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-6,c-35}];
  end_loc:[{r-8,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/bounds.cpp:000004-000044>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-7,c-5}];
  end_loc:[{r-7,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-7,c-9}];
  end_loc:[{r-7,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000004-000017>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-7,c-13}];
  end_loc:[{r-7,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-11,c-1}];
  end_loc:[{r-16,c-1}];
  data:[voidcaller_lt_add(intnCaller){float*ppp;intnCall=nCaller;foo_lt_add(ppp,nCall);}];
  obj:[fun_def];

  name:[caller_lt_add];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000011-000020>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000015-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000011-000001>];
    appId:[caller_lt_add];
    appImpl:[caller_lt_add];
    returnType:[task::coro::dispatcher<app::impl::caller_lt_add>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-11,c-20}];
  end_loc:[{r-11,c-24}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000014-000015>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-11,c-33}];
  end_loc:[{r-16,c-1}];
  data:[{float*ppp;intnCall=nCaller;foo_lt_add(ppp,nCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-12,c-3}];
  end_loc:[{r-12,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-14,c-3}];
  end_loc:[{r-14,c-22}];
  data:[nCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nCall init nCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-14,c-15}];
  end_loc:[{r-14,c-15}];
  data:[nCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000011-000020>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000014-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-15,c-3}];
  end_loc:[{r-15,c-24}];
  data:[foo_lt_add(ppp,nCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/bounds.cpp:000004-000001>];
  caller:[<builder/test/access_1d/bounds.cpp:000011-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_lt_add((nCall,ppp))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-15,c-14}];
  end_loc:[{r-15,c-14}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000012-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000004-000017>];
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


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-15,c-19}];
  end_loc:[{r-15,c-19}];
  data:[nCall];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000004-000036>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-20,c-1}];
  end_loc:[{r-25,c-1}];
  data:[voidfoo_leq_add(constfloat*bbb,intnn){floatr;for(intii=0;ii<=nn;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_leq_add];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000020-000018>];
    1:[<builder/test/access_1d/bounds.cpp:000020-000037>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000031-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000020-000001>];
    appId:[foo_leq_add];
    appImpl:[foo_leq_add];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-20,c-18}];
  end_loc:[{r-20,c-32}];
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
    0:[<builder/test/access_1d/bounds.cpp:000023-000009>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(1+nn) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min; Max ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-20,c-37}];
  end_loc:[{r-20,c-41}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000022-000026>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-20,c-45}];
  end_loc:[{r-25,c-1}];
  data:[{floatr;for(intii=0;ii<=nn;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-21,c-3}];
  end_loc:[{r-21,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-22,c-3}];
  end_loc:[{r-24,c-3}];
  data:[for(intii=0;ii<=nn;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-22,c-8}];
  end_loc:[{r-22,c-18}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-22,c-17}];
  end_loc:[{r-22,c-17}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000022-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-22,c-20}];
  end_loc:[{r-22,c-26}];
  data:[ii<=nn];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii leq nn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-22,c-26}];
  end_loc:[{r-22,c-26}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000020-000037>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000022-000020>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-22,c-30}];
  end_loc:[{r-22,c-32}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-22,c-36}];
  end_loc:[{r-24,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/bounds.cpp:000020-000045>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-23,c-5}];
  end_loc:[{r-23,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-23,c-9}];
  end_loc:[{r-23,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000020-000018>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000023-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-23,c-13}];
  end_loc:[{r-23,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000022-000008>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000023-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-27,c-1}];
  end_loc:[{r-32,c-1}];
  data:[voidcaller_leq_add(intnCaller){float*ppp;intnCall=nCaller;foo_leq_add(ppp,nCall);}];
  obj:[fun_def];

  name:[caller_leq_add];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000027-000021>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000031-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000027-000001>];
    appId:[caller_leq_add];
    appImpl:[caller_leq_add];
    returnType:[task::coro::dispatcher<app::impl::caller_leq_add>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-27,c-21}];
  end_loc:[{r-27,c-25}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000030-000015>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-27,c-34}];
  end_loc:[{r-32,c-1}];
  data:[{float*ppp;intnCall=nCaller;foo_leq_add(ppp,nCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-28,c-3}];
  end_loc:[{r-28,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-30,c-3}];
  end_loc:[{r-30,c-22}];
  data:[nCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nCall init nCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-30,c-15}];
  end_loc:[{r-30,c-15}];
  data:[nCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000027-000021>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000030-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-31,c-3}];
  end_loc:[{r-31,c-25}];
  data:[foo_leq_add(ppp,nCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/bounds.cpp:000020-000001>];
  caller:[<builder/test/access_1d/bounds.cpp:000027-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_leq_add((nCall,ppp))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-31,c-15}];
  end_loc:[{r-31,c-15}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000028-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000020-000018>];
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


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-31,c-20}];
  end_loc:[{r-31,c-20}];
  data:[nCall];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000030-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000020-000037>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-36,c-1}];
  end_loc:[{r-41,c-1}];
  data:[voidfoo_gt_sub(constfloat*bbb,intnn){floatr;for(intii=nn;ii>0;ii--){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_gt_sub];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000036-000017>];
    1:[<builder/test/access_1d/bounds.cpp:000036-000036>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000047-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000036-000001>];
    appId:[foo_gt_sub];
    appImpl:[foo_gt_sub];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-36,c-17}];
  end_loc:[{r-36,c-31}];
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
    0:[<builder/test/access_1d/bounds.cpp:000039-000009>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min1; Maxnn ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min; Max ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-36,c-36}];
  end_loc:[{r-36,c-40}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000038-000017>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-36,c-44}];
  end_loc:[{r-41,c-1}];
  data:[{floatr;for(intii=nn;ii>0;ii--){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-37,c-3}];
  end_loc:[{r-37,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-38,c-3}];
  end_loc:[{r-40,c-3}];
  data:[for(intii=nn;ii>0;ii--){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-38,c-8}];
  end_loc:[{r-38,c-19}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init nn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-38,c-17}];
  end_loc:[{r-38,c-17}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000036-000036>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000038-000008>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-38,c-21}];
  end_loc:[{r-38,c-26}];
  data:[ii>0];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii gt 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-38,c-26}];
  end_loc:[{r-38,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000038-000021>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-38,c-29}];
  end_loc:[{r-38,c-31}];
  data:[ii--];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii decr (-1)];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-38,c-35}];
  end_loc:[{r-40,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/bounds.cpp:000036-000044>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-39,c-5}];
  end_loc:[{r-39,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-39,c-9}];
  end_loc:[{r-39,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000036-000017>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000039-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-39,c-13}];
  end_loc:[{r-39,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000038-000008>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000039-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-43,c-1}];
  end_loc:[{r-48,c-1}];
  data:[voidcaller_gt_sub(intnCaller){float*ppp;intnCall=nCaller;foo_gt_sub(ppp,nCall);}];
  obj:[fun_def];

  name:[caller_gt_sub];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000043-000020>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000047-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000043-000001>];
    appId:[caller_gt_sub];
    appImpl:[caller_gt_sub];
    returnType:[task::coro::dispatcher<app::impl::caller_gt_sub>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-43,c-20}];
  end_loc:[{r-43,c-24}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000046-000015>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-43,c-33}];
  end_loc:[{r-48,c-1}];
  data:[{float*ppp;intnCall=nCaller;foo_gt_sub(ppp,nCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-44,c-3}];
  end_loc:[{r-44,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-46,c-3}];
  end_loc:[{r-46,c-22}];
  data:[nCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nCall init nCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-46,c-15}];
  end_loc:[{r-46,c-15}];
  data:[nCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000043-000020>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000046-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-47,c-3}];
  end_loc:[{r-47,c-24}];
  data:[foo_gt_sub(ppp,nCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/bounds.cpp:000036-000001>];
  caller:[<builder/test/access_1d/bounds.cpp:000043-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_gt_sub((nCall,ppp))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-47,c-14}];
  end_loc:[{r-47,c-14}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000044-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000036-000017>];
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


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-47,c-19}];
  end_loc:[{r-47,c-19}];
  data:[nCall];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000046-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000036-000036>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-52,c-1}];
  end_loc:[{r-57,c-1}];
  data:[voidfoo_geq_sub(constfloat*bbb,intnn){floatr;for(intii=nn;ii>=0;ii--){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_geq_sub];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000052-000018>];
    1:[<builder/test/access_1d/bounds.cpp:000052-000037>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000063-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000052-000001>];
    appId:[foo_geq_sub];
    appImpl:[foo_geq_sub];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-52,c-18}];
  end_loc:[{r-52,c-32}];
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
    0:[<builder/test/access_1d/bounds.cpp:000055-000009>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(1+nn) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min; Max ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-52,c-37}];
  end_loc:[{r-52,c-41}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000054-000017>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-52,c-45}];
  end_loc:[{r-57,c-1}];
  data:[{floatr;for(intii=nn;ii>=0;ii--){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-53,c-3}];
  end_loc:[{r-53,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-54,c-3}];
  end_loc:[{r-56,c-3}];
  data:[for(intii=nn;ii>=0;ii--){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-54,c-8}];
  end_loc:[{r-54,c-19}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init nn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-54,c-17}];
  end_loc:[{r-54,c-17}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000052-000037>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000054-000008>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-54,c-21}];
  end_loc:[{r-54,c-27}];
  data:[ii>=0];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii geq 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-54,c-27}];
  end_loc:[{r-54,c-27}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000054-000021>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-54,c-30}];
  end_loc:[{r-54,c-32}];
  data:[ii--];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii decr (-1)];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-54,c-36}];
  end_loc:[{r-56,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/bounds.cpp:000052-000045>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-55,c-5}];
  end_loc:[{r-55,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-55,c-9}];
  end_loc:[{r-55,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000052-000018>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000055-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-55,c-13}];
  end_loc:[{r-55,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000054-000008>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000055-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-59,c-1}];
  end_loc:[{r-64,c-1}];
  data:[voidcaller_geq_sub(intnCaller){float*ppp;intnCall=nCaller;foo_geq_sub(ppp,nCall);}];
  obj:[fun_def];

  name:[caller_geq_sub];
  args:[
    0:[<builder/test/access_1d/bounds.cpp:000059-000021>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/bounds.cpp:000063-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/bounds.cpp:000059-000001>];
    appId:[caller_geq_sub];
    appImpl:[caller_geq_sub];
    returnType:[task::coro::dispatcher<app::impl::caller_geq_sub>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-59,c-21}];
  end_loc:[{r-59,c-25}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/bounds.cpp:000062-000015>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-59,c-34}];
  end_loc:[{r-64,c-1}];
  data:[{float*ppp;intnCall=nCaller;foo_geq_sub(ppp,nCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-60,c-3}];
  end_loc:[{r-60,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-62,c-3}];
  end_loc:[{r-62,c-22}];
  data:[nCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nCall init nCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-62,c-15}];
  end_loc:[{r-62,c-15}];
  data:[nCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000059-000021>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000062-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-63,c-3}];
  end_loc:[{r-63,c-25}];
  data:[foo_geq_sub(ppp,nCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/bounds.cpp:000052-000001>];
  caller:[<builder/test/access_1d/bounds.cpp:000059-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_geq_sub((nCall,ppp))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-63,c-15}];
  end_loc:[{r-63,c-15}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000052-000018>];
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


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[bounds.cpp];
  begin_loc:[{r-63,c-20}];
  end_loc:[{r-63,c-20}];
  data:[nCall];
  obj:[data_use];

  root:[<builder/test/access_1d/bounds.cpp:000062-000003>];
  callee_or_op:[<builder/test/access_1d/bounds.cpp:000052-000037>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCall];
  ];
  memAccess:[NULL];
*/