steel_builder_test_suite
basic_call.cpp
/*

  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-4,c-1}];
  end_loc:[{r-9,c-1}];
  data:[voidfoo_whole_ro(constfloat*bbb,intnn){floatr;for(intii=0;ii<nn;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_whole_ro];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000004-000019>];
    1:[<builder/test/access_1d/basic_call.cpp:000004-000038>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000015-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000004-000001>];
    appId:[foo_whole_ro_app];
    appImpl:[foo_whole_ro];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-4,c-19}];
  end_loc:[{r-4,c-33}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000007-000009>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-4,c-38}];
  end_loc:[{r-4,c-42}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000006-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-4,c-46}];
  end_loc:[{r-9,c-1}];
  data:[{floatr;for(intii=0;ii<nn;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-8,c-3}];
  data:[for(intii=0;ii<nn;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-6,c-17}];
  end_loc:[{r-6,c-17}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000006-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-6,c-25}];
  end_loc:[{r-6,c-25}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000004-000038>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000006-000020>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-6,c-35}];
  end_loc:[{r-8,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/basic_call.cpp:000004-000046>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-7,c-9}];
  end_loc:[{r-7,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000004-000019>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000007-000005>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-7,c-13}];
  end_loc:[{r-7,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-11,c-1}];
  end_loc:[{r-16,c-1}];
  data:[voidcaller_ro(intnCaller){float*ppp;intnCall=nCaller;foo_whole_ro(ppp,nCall);}];
  obj:[fun_def];

  name:[caller_ro];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000011-000016>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000015-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000011-000001>];
    appId:[caller_ro];
    appImpl:[caller_ro];
    returnType:[task::coro::dispatcher<app::impl::caller_ro>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-11,c-16}];
  end_loc:[{r-11,c-20}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000014-000015>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-11,c-29}];
  end_loc:[{r-16,c-1}];
  data:[{float*ppp;intnCall=nCaller;foo_whole_ro(ppp,nCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-14,c-15}];
  end_loc:[{r-14,c-15}];
  data:[nCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000011-000016>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000014-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-15,c-3}];
  end_loc:[{r-15,c-26}];
  data:[foo_whole_ro(ppp,nCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/basic_call.cpp:000004-000001>];
  caller:[<builder/test/access_1d/basic_call.cpp:000011-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_whole_ro((nCall,ppp))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-15,c-16}];
  end_loc:[{r-15,c-16}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000012-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000004-000019>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-15,c-21}];
  end_loc:[{r-15,c-21}];
  data:[nCall];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000004-000038>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-20,c-1}];
  end_loc:[{r-25,c-1}];
  data:[voidfoo_portion_ro(constfloat*bbb,intsn,inten){floatr;for(intii=sn;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_portion_ro];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000020-000021>];
    1:[<builder/test/access_1d/basic_call.cpp:000020-000040>];
    2:[<builder/test/access_1d/basic_call.cpp:000020-000048>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000032-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000020-000001>];
    appId:[foo_portion_ro_app];
    appImpl:[foo_portion_ro];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-20,c-21}];
  end_loc:[{r-20,c-35}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000023-000009>];
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
        pcContent:[range[ Minsn; Maxen ]];
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
  file:[basic_call.cpp];
  begin_loc:[{r-20,c-40}];
  end_loc:[{r-20,c-44}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[sn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000022-000017>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-20,c-48}];
  end_loc:[{r-20,c-52}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[en];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000022-000026>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-20,c-56}];
  end_loc:[{r-25,c-1}];
  data:[{floatr;for(intii=sn;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-22,c-3}];
  end_loc:[{r-24,c-3}];
  data:[for(intii=sn;ii<en;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-22,c-8}];
  end_loc:[{r-22,c-19}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init sn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-22,c-17}];
  end_loc:[{r-22,c-17}];
  data:[sn];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000020-000040>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000022-000008>];
  terminal_root:[
    pcKind:[var];
    pcContent:[sn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-22,c-21}];
  end_loc:[{r-22,c-26}];
  data:[ii<en];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt en];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-22,c-26}];
  end_loc:[{r-22,c-26}];
  data:[en];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000020-000048>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000022-000021>];
  terminal_root:[
    pcKind:[var];
    pcContent:[en];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-22,c-36}];
  end_loc:[{r-24,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/basic_call.cpp:000020-000056>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-23,c-9}];
  end_loc:[{r-23,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000020-000021>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000023-000005>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-23,c-13}];
  end_loc:[{r-23,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000022-000008>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000023-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-27,c-1}];
  end_loc:[{r-33,c-1}];
  data:[voidcaller_ro(intsnCaller,intenCaller){float*ppp;intsnCall=snCaller;intenCall=enCaller;foo_portion_ro(ppp,snCall,enCall);}];
  obj:[fun_def];

  name:[caller_ro];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000027-000016>];
    1:[<builder/test/access_1d/basic_call.cpp:000027-000030>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000032-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000027-000001>];
    appId:[caller_ro];
    appImpl:[caller_ro];
    returnType:[task::coro::dispatcher<app::impl::caller_ro>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-27,c-16}];
  end_loc:[{r-27,c-20}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[snCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000030-000016>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-27,c-30}];
  end_loc:[{r-27,c-34}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[enCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000031-000016>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-27,c-44}];
  end_loc:[{r-33,c-1}];
  data:[{float*ppp;intsnCall=snCaller;intenCall=enCaller;foo_portion_ro(ppp,snCall,enCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
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
  file:[basic_call.cpp];
  begin_loc:[{r-30,c-3}];
  end_loc:[{r-30,c-24}];
  data:[snCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[snCall init snCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-30,c-16}];
  end_loc:[{r-30,c-16}];
  data:[snCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000027-000016>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000030-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[snCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-31,c-3}];
  end_loc:[{r-31,c-24}];
  data:[enCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[enCall init enCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-31,c-16}];
  end_loc:[{r-31,c-16}];
  data:[enCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000027-000030>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000031-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[enCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-32,c-3}];
  end_loc:[{r-32,c-37}];
  data:[foo_portion_ro(ppp,snCall,enCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/basic_call.cpp:000020-000001>];
  caller:[<builder/test/access_1d/basic_call.cpp:000027-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_portion_ro((enCall,ppp,snCall))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-32,c-18}];
  end_loc:[{r-32,c-18}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000028-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000020-000021>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-32,c-23}];
  end_loc:[{r-32,c-23}];
  data:[snCall];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000030-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000020-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[snCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-32,c-31}];
  end_loc:[{r-32,c-31}];
  data:[enCall];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000031-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000020-000048>];
  terminal_root:[
    pcKind:[var];
    pcContent:[enCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-37,c-1}];
  end_loc:[{r-42,c-1}];
  data:[voidfoo_whole_rw(float*bbb,intnn){floatr;for(intii=0;ii<nn;ii++){bbb[ii]=r;}}];
  obj:[fun_def];

  name:[foo_whole_rw];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000037-000019>];
    1:[<builder/test/access_1d/basic_call.cpp:000037-000032>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000048-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000037-000001>];
    appId:[foo_whole_rw_app];
    appImpl:[foo_whole_rw];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-37,c-19}];
  end_loc:[{r-37,c-27}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000040-000005>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-37,c-32}];
  end_loc:[{r-37,c-36}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000039-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-37,c-40}];
  end_loc:[{r-42,c-1}];
  data:[{floatr;for(intii=0;ii<nn;ii++){bbb[ii]=r;}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-38,c-3}];
  end_loc:[{r-38,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-39,c-3}];
  end_loc:[{r-41,c-3}];
  data:[for(intii=0;ii<nn;ii++){bbb[ii]=r;}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-39,c-8}];
  end_loc:[{r-39,c-18}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-39,c-17}];
  end_loc:[{r-39,c-17}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000039-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-39,c-20}];
  end_loc:[{r-39,c-25}];
  data:[ii<nn];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-39,c-25}];
  end_loc:[{r-39,c-25}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000037-000032>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000039-000020>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-39,c-29}];
  end_loc:[{r-39,c-31}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-39,c-35}];
  end_loc:[{r-41,c-3}];
  data:[{bbb[ii]=r;}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/basic_call.cpp:000037-000040>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-40,c-5}];
  end_loc:[{r-40,c-15}];
  data:[bbb[ii]=r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bbb[ii] assign r];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-40,c-9}];
  end_loc:[{r-40,c-9}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000039-000008>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000040-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-40,c-15}];
  end_loc:[{r-40,c-15}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000038-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000040-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-44,c-1}];
  end_loc:[{r-49,c-1}];
  data:[voidcaller_rw(intnCaller){float*ppp;intnCall=nCaller;foo_whole_rw(ppp,nCall);}];
  obj:[fun_def];

  name:[caller_rw];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000044-000016>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000048-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000044-000001>];
    appId:[caller_rw];
    appImpl:[caller_rw];
    returnType:[task::coro::dispatcher<app::impl::caller_rw>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-44,c-16}];
  end_loc:[{r-44,c-20}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000047-000015>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-44,c-29}];
  end_loc:[{r-49,c-1}];
  data:[{float*ppp;intnCall=nCaller;foo_whole_rw(ppp,nCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-45,c-3}];
  end_loc:[{r-45,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-47,c-3}];
  end_loc:[{r-47,c-22}];
  data:[nCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nCall init nCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-47,c-15}];
  end_loc:[{r-47,c-15}];
  data:[nCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000044-000016>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000047-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-48,c-3}];
  end_loc:[{r-48,c-26}];
  data:[foo_whole_rw(ppp,nCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/basic_call.cpp:000037-000001>];
  caller:[<builder/test/access_1d/basic_call.cpp:000044-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_whole_rw((nCall,ppp))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-48,c-16}];
  end_loc:[{r-48,c-16}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000045-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000037-000019>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-48,c-21}];
  end_loc:[{r-48,c-21}];
  data:[nCall];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000047-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000037-000032>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-53,c-1}];
  end_loc:[{r-58,c-1}];
  data:[voidfoo_portion_rw(constfloat*bbb,intsn,inten){floatr;for(intii=sn;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_portion_rw];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000053-000021>];
    1:[<builder/test/access_1d/basic_call.cpp:000053-000040>];
    2:[<builder/test/access_1d/basic_call.cpp:000053-000048>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000065-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000053-000001>];
    appId:[foo_portion_rw_app];
    appImpl:[foo_portion_rw];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-53,c-21}];
  end_loc:[{r-53,c-35}];
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
    0:[<builder/test/access_1d/basic_call.cpp:000056-000009>];
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
        pcContent:[range[ Minsn; Maxen ]];
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
  file:[basic_call.cpp];
  begin_loc:[{r-53,c-40}];
  end_loc:[{r-53,c-44}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[sn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000055-000017>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-53,c-48}];
  end_loc:[{r-53,c-52}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[en];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000055-000026>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-53,c-56}];
  end_loc:[{r-58,c-1}];
  data:[{floatr;for(intii=sn;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-54,c-3}];
  end_loc:[{r-54,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-55,c-3}];
  end_loc:[{r-57,c-3}];
  data:[for(intii=sn;ii<en;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-55,c-8}];
  end_loc:[{r-55,c-19}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init sn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-55,c-17}];
  end_loc:[{r-55,c-17}];
  data:[sn];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000053-000040>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000055-000008>];
  terminal_root:[
    pcKind:[var];
    pcContent:[sn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-55,c-21}];
  end_loc:[{r-55,c-26}];
  data:[ii<en];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt en];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-55,c-26}];
  end_loc:[{r-55,c-26}];
  data:[en];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000053-000048>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000055-000021>];
  terminal_root:[
    pcKind:[var];
    pcContent:[en];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-55,c-30}];
  end_loc:[{r-55,c-32}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-55,c-36}];
  end_loc:[{r-57,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/basic_call.cpp:000053-000056>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-56,c-5}];
  end_loc:[{r-56,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-56,c-9}];
  end_loc:[{r-56,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000053-000021>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000056-000005>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-56,c-13}];
  end_loc:[{r-56,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000055-000008>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000056-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-60,c-1}];
  end_loc:[{r-66,c-1}];
  data:[voidcaller_rw(intsnCaller,intenCaller){float*ppp;intsnCall=snCaller;intenCall=enCaller;foo_portion_rw(ppp,snCall,enCall);}];
  obj:[fun_def];

  name:[caller_rw];
  args:[
    0:[<builder/test/access_1d/basic_call.cpp:000060-000016>];
    1:[<builder/test/access_1d/basic_call.cpp:000060-000030>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/basic_call.cpp:000065-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/basic_call.cpp:000060-000001>];
    appId:[caller_rw];
    appImpl:[caller_rw];
    returnType:[task::coro::dispatcher<app::impl::caller_rw>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-60,c-16}];
  end_loc:[{r-60,c-20}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[snCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000063-000016>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-60,c-30}];
  end_loc:[{r-60,c-34}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[enCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/basic_call.cpp:000064-000016>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-60,c-44}];
  end_loc:[{r-66,c-1}];
  data:[{float*ppp;intsnCall=snCaller;intenCall=enCaller;foo_portion_rw(ppp,snCall,enCall);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-61,c-3}];
  end_loc:[{r-61,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-63,c-3}];
  end_loc:[{r-63,c-24}];
  data:[snCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[snCall init snCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-63,c-16}];
  end_loc:[{r-63,c-16}];
  data:[snCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000060-000016>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000063-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[snCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-64,c-3}];
  end_loc:[{r-64,c-24}];
  data:[enCall];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[enCall init enCaller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-64,c-16}];
  end_loc:[{r-64,c-16}];
  data:[enCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000060-000030>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000064-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[enCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-65,c-3}];
  end_loc:[{r-65,c-37}];
  data:[foo_portion_rw(ppp,snCall,enCall)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/basic_call.cpp:000053-000001>];
  caller:[<builder/test/access_1d/basic_call.cpp:000060-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_portion_rw((enCall,ppp,snCall))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-65,c-18}];
  end_loc:[{r-65,c-18}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000061-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000053-000021>];
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
  file:[basic_call.cpp];
  begin_loc:[{r-65,c-23}];
  end_loc:[{r-65,c-23}];
  data:[snCall];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000063-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000053-000040>];
  terminal_root:[
    pcKind:[var];
    pcContent:[snCall];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[basic_call.cpp];
  begin_loc:[{r-65,c-31}];
  end_loc:[{r-65,c-31}];
  data:[enCall];
  obj:[data_use];

  root:[<builder/test/access_1d/basic_call.cpp:000064-000003>];
  callee_or_op:[<builder/test/access_1d/basic_call.cpp:000053-000048>];
  terminal_root:[
    pcKind:[var];
    pcContent:[enCall];
  ];
  memAccess:[NULL];
*/