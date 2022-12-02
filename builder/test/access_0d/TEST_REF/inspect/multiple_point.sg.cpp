steel_builder_test_suite
multiple_point.cpp
/*

  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-6,c-1}];
  data:[voidfoo_ro_multiple_point(constfloat*bbb,inti){floatr;r=bbb[i];}];
  obj:[fun_def];

  name:[foo_ro_multiple_point];
  args:[
    0:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
    1:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/multiple_point.cpp:000014-000003>];
    1:[<builder/test/access_0d/multiple_point.cpp:000015-000003>];
    2:[<builder/test/access_0d/multiple_point.cpp:000016-000003>];
    3:[<builder/test/access_0d/multiple_point.cpp:000025-000003>];
    4:[<builder/test/access_0d/multiple_point.cpp:000026-000003>];
    5:[<builder/test/access_0d/multiple_point.cpp:000027-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_point.cpp:000003-000001>];
    appId:[foo_ro_multiple_point_app];
    appImpl:[foo_ro_multiple_point];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-28}];
  end_loc:[{r-3,c-42}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000005-000007>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-47}];
  end_loc:[{r-3,c-51}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000005-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-54}];
  end_loc:[{r-6,c-1}];
  data:[{floatr;r=bbb[i];}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
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
  file:[multiple_point.cpp];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-7}];
  end_loc:[{r-5,c-7}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000005-000003>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-11}];
  end_loc:[{r-5,c-11}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-8,c-1}];
  end_loc:[{r-17,c-1}];
  data:[voidcaller1_ro_multiple_point(){inta=15;intb=23;intc=37;float*ppp;foo_ro_multiple_point(ppp,a);foo_ro_multiple_point(ppp,b);foo_ro_multiple_point(ppp,c);}];
  obj:[fun_def];

  name:[caller1_ro_multiple_point];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_point.cpp:000014-000003>];
    1:[<builder/test/access_0d/multiple_point.cpp:000015-000003>];
    2:[<builder/test/access_0d/multiple_point.cpp:000016-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_point.cpp:000008-000001>];
    appId:[caller1_ro_multiple_point];
    appImpl:[caller1_ro_multiple_point];
    returnType:[task::coro::dispatcher<app::impl::caller1_ro_multiple_point>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-8,c-34}];
  end_loc:[{r-17,c-1}];
  data:[{inta=15;intb=23;intc=37;float*ppp;foo_ro_multiple_point(ppp,a);foo_ro_multiple_point(ppp,b);foo_ro_multiple_point(ppp,c);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-9,c-3}];
  end_loc:[{r-9,c-13}];
  data:[a];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a init 15];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-9,c-11}];
  end_loc:[{r-9,c-11}];
  data:[15];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000009-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[15];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-10,c-3}];
  end_loc:[{r-10,c-13}];
  data:[b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b init 23];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-10,c-11}];
  end_loc:[{r-10,c-11}];
  data:[23];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000010-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[23];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-11,c-3}];
  end_loc:[{r-11,c-13}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 37];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-11,c-11}];
  end_loc:[{r-11,c-11}];
  data:[37];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000011-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[37];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-12,c-3}];
  end_loc:[{r-12,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-14,c-3}];
  end_loc:[{r-14,c-31}];
  data:[foo_ro_multiple_point(ppp,a)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000008-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((a,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-14,c-25}];
  end_loc:[{r-14,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000012-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-14,c-30}];
  end_loc:[{r-14,c-30}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000009-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-15,c-3}];
  end_loc:[{r-15,c-31}];
  data:[foo_ro_multiple_point(ppp,b)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000008-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((b,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-15,c-25}];
  end_loc:[{r-15,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000012-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-15,c-30}];
  end_loc:[{r-15,c-30}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000010-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-16,c-3}];
  end_loc:[{r-16,c-31}];
  data:[foo_ro_multiple_point(ppp,c)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000008-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((c,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-16,c-25}];
  end_loc:[{r-16,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000012-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-16,c-30}];
  end_loc:[{r-16,c-30}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000011-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-1}];
  end_loc:[{r-28,c-1}];
  data:[voidcaller2_ro_multiple_point(inti,intj,intk){inta=i;intb=j;intc=k;float*ppp;foo_ro_multiple_point(ppp,a);foo_ro_multiple_point(ppp,b);foo_ro_multiple_point(ppp,c);}];
  obj:[fun_def];

  name:[caller2_ro_multiple_point];
  args:[
    0:[<builder/test/access_0d/multiple_point.cpp:000019-000032>];
    1:[<builder/test/access_0d/multiple_point.cpp:000019-000039>];
    2:[<builder/test/access_0d/multiple_point.cpp:000019-000046>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_point.cpp:000025-000003>];
    1:[<builder/test/access_0d/multiple_point.cpp:000026-000003>];
    2:[<builder/test/access_0d/multiple_point.cpp:000027-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_point.cpp:000019-000001>];
    appId:[caller2_ro_multiple_point];
    appImpl:[caller2_ro_multiple_point];
    returnType:[task::coro::dispatcher<app::impl::caller2_ro_multiple_point>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-32}];
  end_loc:[{r-19,c-36}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000020-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-39}];
  end_loc:[{r-19,c-43}];
  data:[intj];
  obj:[data_decl];

  declKind:[fargument];
  varName:[j];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_point.cpp:000021-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-46}];
  end_loc:[{r-19,c-50}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000022-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-53}];
  end_loc:[{r-28,c-1}];
  data:[{inta=i;intb=j;intc=k;float*ppp;foo_ro_multiple_point(ppp,a);foo_ro_multiple_point(ppp,b);foo_ro_multiple_point(ppp,c);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-20,c-3}];
  end_loc:[{r-20,c-12}];
  data:[a];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a init i];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-20,c-11}];
  end_loc:[{r-20,c-11}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000019-000032>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000020-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-21,c-3}];
  end_loc:[{r-21,c-12}];
  data:[b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b init j];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-21,c-11}];
  end_loc:[{r-21,c-11}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000019-000039>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000021-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-22,c-3}];
  end_loc:[{r-22,c-12}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init k];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-22,c-11}];
  end_loc:[{r-22,c-11}];
  data:[k];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000019-000046>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000022-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[k];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-23,c-3}];
  end_loc:[{r-23,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-25,c-3}];
  end_loc:[{r-25,c-31}];
  data:[foo_ro_multiple_point(ppp,a)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000019-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((a,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-25,c-25}];
  end_loc:[{r-25,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-25,c-30}];
  end_loc:[{r-25,c-30}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000020-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-31}];
  data:[foo_ro_multiple_point(ppp,b)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000019-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((b,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-26,c-25}];
  end_loc:[{r-26,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-26,c-30}];
  end_loc:[{r-26,c-30}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000021-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-27,c-31}];
  data:[foo_ro_multiple_point(ppp,c)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000019-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((c,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-27,c-25}];
  end_loc:[{r-27,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-27,c-30}];
  end_loc:[{r-27,c-30}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-1}];
  end_loc:[{r-36,c-1}];
  data:[voidfoo_rw_multiple_point(float*bbb,inti){floatr;bbb[i]=r;}];
  obj:[fun_def];

  name:[foo_rw_multiple_point];
  args:[
    0:[<builder/test/access_0d/multiple_point.cpp:000033-000028>];
    1:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/multiple_point.cpp:000044-000003>];
    1:[<builder/test/access_0d/multiple_point.cpp:000045-000003>];
    2:[<builder/test/access_0d/multiple_point.cpp:000046-000003>];
    3:[<builder/test/access_0d/multiple_point.cpp:000055-000003>];
    4:[<builder/test/access_0d/multiple_point.cpp:000056-000003>];
    5:[<builder/test/access_0d/multiple_point.cpp:000057-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_point.cpp:000033-000001>];
    appId:[foo_rw_multiple_point_app];
    appImpl:[foo_rw_multiple_point];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-28}];
  end_loc:[{r-33,c-36}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000035-000003>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-41}];
  end_loc:[{r-33,c-45}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000035-000007>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-48}];
  end_loc:[{r-36,c-1}];
  data:[{floatr;bbb[i]=r;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-34,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-35,c-3}];
  end_loc:[{r-35,c-12}];
  data:[bbb[i]=r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bbb[i] assign r];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-35,c-7}];
  end_loc:[{r-35,c-7}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000035-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-35,c-12}];
  end_loc:[{r-35,c-12}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000034-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000035-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-38,c-1}];
  end_loc:[{r-47,c-1}];
  data:[voidcaller1_rw_multiple_point(){inta=15;intb=23;intc=37;float*ppp;foo_rw_multiple_point(ppp,a);foo_rw_multiple_point(ppp,b);foo_rw_multiple_point(ppp,c);}];
  obj:[fun_def];

  name:[caller1_rw_multiple_point];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_point.cpp:000044-000003>];
    1:[<builder/test/access_0d/multiple_point.cpp:000045-000003>];
    2:[<builder/test/access_0d/multiple_point.cpp:000046-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_point.cpp:000038-000001>];
    appId:[caller1_rw_multiple_point];
    appImpl:[caller1_rw_multiple_point];
    returnType:[task::coro::dispatcher<app::impl::caller1_rw_multiple_point>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-38,c-34}];
  end_loc:[{r-47,c-1}];
  data:[{inta=15;intb=23;intc=37;float*ppp;foo_rw_multiple_point(ppp,a);foo_rw_multiple_point(ppp,b);foo_rw_multiple_point(ppp,c);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-39,c-3}];
  end_loc:[{r-39,c-13}];
  data:[a];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a init 15];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-39,c-11}];
  end_loc:[{r-39,c-11}];
  data:[15];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000039-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[15];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-40,c-3}];
  end_loc:[{r-40,c-13}];
  data:[b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b init 23];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-40,c-11}];
  end_loc:[{r-40,c-11}];
  data:[23];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000040-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[23];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-41,c-3}];
  end_loc:[{r-41,c-13}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 37];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-41,c-11}];
  end_loc:[{r-41,c-11}];
  data:[37];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000041-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[37];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-42,c-3}];
  end_loc:[{r-42,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-44,c-3}];
  end_loc:[{r-44,c-31}];
  data:[foo_rw_multiple_point(ppp,a)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000033-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000038-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_point((a,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-44,c-25}];
  end_loc:[{r-44,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000042-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-44,c-30}];
  end_loc:[{r-44,c-30}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000039-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-45,c-3}];
  end_loc:[{r-45,c-31}];
  data:[foo_rw_multiple_point(ppp,b)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000033-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000038-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_point((b,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-45,c-25}];
  end_loc:[{r-45,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000042-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-45,c-30}];
  end_loc:[{r-45,c-30}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-46,c-3}];
  end_loc:[{r-46,c-31}];
  data:[foo_rw_multiple_point(ppp,c)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000033-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000038-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_point((c,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-46,c-25}];
  end_loc:[{r-46,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000042-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-46,c-30}];
  end_loc:[{r-46,c-30}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000041-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-49,c-1}];
  end_loc:[{r-58,c-1}];
  data:[voidcaller2_rw_multiple_point(inti,intj,intk){inta=i;intb=j;intc=k;float*ppp;foo_rw_multiple_point(ppp,a);foo_rw_multiple_point(ppp,b);foo_rw_multiple_point(ppp,c);}];
  obj:[fun_def];

  name:[caller2_rw_multiple_point];
  args:[
    0:[<builder/test/access_0d/multiple_point.cpp:000049-000032>];
    1:[<builder/test/access_0d/multiple_point.cpp:000049-000039>];
    2:[<builder/test/access_0d/multiple_point.cpp:000049-000046>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/multiple_point.cpp:000055-000003>];
    1:[<builder/test/access_0d/multiple_point.cpp:000056-000003>];
    2:[<builder/test/access_0d/multiple_point.cpp:000057-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/multiple_point.cpp:000049-000001>];
    appId:[caller2_rw_multiple_point];
    appImpl:[caller2_rw_multiple_point];
    returnType:[task::coro::dispatcher<app::impl::caller2_rw_multiple_point>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-49,c-32}];
  end_loc:[{r-49,c-36}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000050-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-49,c-39}];
  end_loc:[{r-49,c-43}];
  data:[intj];
  obj:[data_decl];

  declKind:[fargument];
  varName:[j];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_0d/multiple_point.cpp:000051-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-49,c-46}];
  end_loc:[{r-49,c-50}];
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
    0:[<builder/test/access_0d/multiple_point.cpp:000052-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-49,c-53}];
  end_loc:[{r-58,c-1}];
  data:[{inta=i;intb=j;intc=k;float*ppp;foo_rw_multiple_point(ppp,a);foo_rw_multiple_point(ppp,b);foo_rw_multiple_point(ppp,c);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-50,c-3}];
  end_loc:[{r-50,c-12}];
  data:[a];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a init i];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-50,c-11}];
  end_loc:[{r-50,c-11}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000049-000032>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000050-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-51,c-3}];
  end_loc:[{r-51,c-12}];
  data:[b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b init j];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-51,c-11}];
  end_loc:[{r-51,c-11}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000049-000039>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000051-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-52,c-3}];
  end_loc:[{r-52,c-12}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init k];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-52,c-11}];
  end_loc:[{r-52,c-11}];
  data:[k];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000049-000046>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000052-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[k];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-55,c-3}];
  end_loc:[{r-55,c-31}];
  data:[foo_rw_multiple_point(ppp,a)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000033-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000049-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_point((a,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-55,c-25}];
  end_loc:[{r-55,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000053-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-55,c-30}];
  end_loc:[{r-55,c-30}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000050-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-56,c-3}];
  end_loc:[{r-56,c-31}];
  data:[foo_rw_multiple_point(ppp,b)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000033-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000049-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_point((b,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-56,c-25}];
  end_loc:[{r-56,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000053-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-56,c-30}];
  end_loc:[{r-56,c-30}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000051-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-57,c-3}];
  end_loc:[{r-57,c-31}];
  data:[foo_rw_multiple_point(ppp,c)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/multiple_point.cpp:000033-000001>];
  caller:[<builder/test/access_0d/multiple_point.cpp:000049-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_multiple_point((c,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-57,c-25}];
  end_loc:[{r-57,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000053-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-57,c-30}];
  end_loc:[{r-57,c-30}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_0d/multiple_point.cpp:000052-000003>];
  callee_or_op:[<builder/test/access_0d/multiple_point.cpp:000033-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];
*/