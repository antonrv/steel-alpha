steel_builder_test_suite
arithmetic.cpp
/*

  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-7,c-1}];
  data:[voidfoo_ro_arit(constfloat*bbb,inti){intii=i+3;floatr;r=bbb[ii+99+7*ii+425];}];
  obj:[fun_def];

  name:[foo_ro_arit];
  args:[
    0:[<builder/test/access_0d/arithmetic.cpp:000003-000018>];
    1:[<builder/test/access_0d/arithmetic.cpp:000003-000037>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/arithmetic.cpp:000013-000003>];
    1:[<builder/test/access_0d/arithmetic.cpp:000020-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/arithmetic.cpp:000003-000001>];
    appId:[foo_ro_arit_app];
    appImpl:[foo_ro_arit];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-3,c-18}];
  end_loc:[{r-3,c-32}];
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
    0:[<builder/test/access_0d/arithmetic.cpp:000006-000007>];
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
        pcContent:[ii];
      ];
      1:[
        pcKind:[num];
        pcContent:[99];
      ];
      2:[
        pcKind:[factors];
        pcContent:[(7*ii)];
      ];
      3:[
        pcKind:[num];
        pcContent:[425];
      ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-3,c-37}];
  end_loc:[{r-3,c-41}];
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
    0:[<builder/test/access_0d/arithmetic.cpp:000004-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-3,c-44}];
  end_loc:[{r-7,c-1}];
  data:[{intii=i+3;floatr;r=bbb[ii+99+7*ii+425];}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-17}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init (3+i)];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-4,c-12}];
  end_loc:[{r-4,c-12}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000003-000037>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000004-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-4,c-16}];
  end_loc:[{r-4,c-16}];
  data:[3];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000004-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[3];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-6,c-31}];
  data:[r=bbb[ii+99+7*ii+425]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[(425+99+ii+(7*ii))]];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-6,c-7}];
  end_loc:[{r-6,c-7}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000003-000018>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000006-000003>];
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
  file:[arithmetic.cpp];
  begin_loc:[{r-6,c-11}];
  end_loc:[{r-6,c-11}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000004-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000006-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-6,c-16}];
  end_loc:[{r-6,c-16}];
  data:[99];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000006-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[99];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-6,c-21}];
  end_loc:[{r-6,c-21}];
  data:[7];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000006-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[7];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-6,c-23}];
  end_loc:[{r-6,c-23}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000004-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000006-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-6,c-28}];
  end_loc:[{r-6,c-28}];
  data:[425];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000006-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[425];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-9,c-1}];
  end_loc:[{r-14,c-1}];
  data:[voidcaller_foo_ro_arit_1(){intj=11;float*ppp;foo_ro_arit(ppp,j);}];
  obj:[fun_def];

  name:[caller_foo_ro_arit_1];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/arithmetic.cpp:000013-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/arithmetic.cpp:000009-000001>];
    appId:[caller_foo_ro_arit_1];
    appImpl:[caller_foo_ro_arit_1];
    returnType:[task::coro::dispatcher<app::impl::caller_foo_ro_arit_1>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-9,c-29}];
  end_loc:[{r-14,c-1}];
  data:[{intj=11;float*ppp;foo_ro_arit(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-10,c-3}];
  end_loc:[{r-10,c-13}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init 11];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-10,c-11}];
  end_loc:[{r-10,c-11}];
  data:[11];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000010-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[11];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-11,c-3}];
  end_loc:[{r-11,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-13,c-3}];
  end_loc:[{r-13,c-21}];
  data:[foo_ro_arit(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/arithmetic.cpp:000003-000001>];
  caller:[<builder/test/access_0d/arithmetic.cpp:000009-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_arit((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-13,c-15}];
  end_loc:[{r-13,c-15}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000011-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000003-000018>];
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
  file:[arithmetic.cpp];
  begin_loc:[{r-13,c-20}];
  end_loc:[{r-13,c-20}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000010-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000003-000037>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-16,c-1}];
  end_loc:[{r-21,c-1}];
  data:[voidcaller_foo_ro_arit_2(intk){intj=k;float*ppp;foo_ro_arit(ppp,j);}];
  obj:[fun_def];

  name:[caller_foo_ro_arit_2];
  args:[
    0:[<builder/test/access_0d/arithmetic.cpp:000016-000027>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/arithmetic.cpp:000020-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/arithmetic.cpp:000016-000001>];
    appId:[caller_foo_ro_arit_2];
    appImpl:[caller_foo_ro_arit_2];
    returnType:[task::coro::dispatcher<app::impl::caller_foo_ro_arit_2>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-16,c-27}];
  end_loc:[{r-16,c-31}];
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
    0:[<builder/test/access_0d/arithmetic.cpp:000017-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-16,c-34}];
  end_loc:[{r-21,c-1}];
  data:[{intj=k;float*ppp;foo_ro_arit(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-17,c-3}];
  end_loc:[{r-17,c-12}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init k];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-17,c-11}];
  end_loc:[{r-17,c-11}];
  data:[k];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000016-000027>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000017-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[k];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-18,c-3}];
  end_loc:[{r-18,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-20,c-3}];
  end_loc:[{r-20,c-21}];
  data:[foo_ro_arit(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/arithmetic.cpp:000003-000001>];
  caller:[<builder/test/access_0d/arithmetic.cpp:000016-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_arit((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-20,c-15}];
  end_loc:[{r-20,c-15}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000018-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000003-000018>];
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
  file:[arithmetic.cpp];
  begin_loc:[{r-20,c-20}];
  end_loc:[{r-20,c-20}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000017-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000003-000037>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-24,c-1}];
  end_loc:[{r-28,c-1}];
  data:[voidfoo_rw_arit(float*bbb,inti){intii=i+3;floatr;bbb[ii+99+7*ii+425]=r;}];
  obj:[fun_def];

  name:[foo_rw_arit];
  args:[
    0:[<builder/test/access_0d/arithmetic.cpp:000024-000018>];
    1:[<builder/test/access_0d/arithmetic.cpp:000024-000031>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_0d/arithmetic.cpp:000034-000003>];
    1:[<builder/test/access_0d/arithmetic.cpp:000041-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/arithmetic.cpp:000024-000001>];
    appId:[foo_rw_arit_app];
    appImpl:[foo_rw_arit];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-24,c-18}];
  end_loc:[{r-24,c-26}];
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
    0:[<builder/test/access_0d/arithmetic.cpp:000027-000003>];
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
        pcContent:[ii];
      ];
      1:[
        pcKind:[num];
        pcContent:[99];
      ];
      2:[
        pcKind:[factors];
        pcContent:[(7*ii)];
      ];
      3:[
        pcKind:[num];
        pcContent:[425];
      ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-24,c-31}];
  end_loc:[{r-24,c-35}];
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
    0:[<builder/test/access_0d/arithmetic.cpp:000025-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-24,c-38}];
  end_loc:[{r-28,c-1}];
  data:[{intii=i+3;floatr;bbb[ii+99+7*ii+425]=r;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-25,c-3}];
  end_loc:[{r-25,c-17}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init (3+i)];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-25,c-12}];
  end_loc:[{r-25,c-12}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000024-000031>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000025-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-25,c-16}];
  end_loc:[{r-25,c-16}];
  data:[3];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000025-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[3];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-27,c-31}];
  data:[bbb[ii+99+7*ii+425]=r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bbb[(425+99+ii+(7*ii))] assign r];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-27,c-7}];
  end_loc:[{r-27,c-7}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000025-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-27,c-12}];
  end_loc:[{r-27,c-12}];
  data:[99];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000027-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[99];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-27,c-17}];
  end_loc:[{r-27,c-17}];
  data:[7];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000027-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[7];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-27,c-19}];
  end_loc:[{r-27,c-19}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000025-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-27,c-24}];
  end_loc:[{r-27,c-24}];
  data:[425];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000027-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[425];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-27,c-31}];
  end_loc:[{r-27,c-31}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-30,c-1}];
  end_loc:[{r-35,c-1}];
  data:[voidcaller_foo_rw_arit_1(){intj=11;float*ppp;foo_rw_arit(ppp,j);}];
  obj:[fun_def];

  name:[caller_foo_rw_arit_1];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/arithmetic.cpp:000034-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/arithmetic.cpp:000030-000001>];
    appId:[caller_foo_rw_arit_1];
    appImpl:[caller_foo_rw_arit_1];
    returnType:[task::coro::dispatcher<app::impl::caller_foo_rw_arit_1>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-30,c-29}];
  end_loc:[{r-35,c-1}];
  data:[{intj=11;float*ppp;foo_rw_arit(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-31,c-3}];
  end_loc:[{r-31,c-13}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init 11];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-31,c-11}];
  end_loc:[{r-31,c-11}];
  data:[11];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000031-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[11];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-32,c-3}];
  end_loc:[{r-32,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-34,c-21}];
  data:[foo_rw_arit(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/arithmetic.cpp:000024-000001>];
  caller:[<builder/test/access_0d/arithmetic.cpp:000030-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_arit((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-34,c-15}];
  end_loc:[{r-34,c-15}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000032-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000024-000018>];
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
  file:[arithmetic.cpp];
  begin_loc:[{r-34,c-20}];
  end_loc:[{r-34,c-20}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000031-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000024-000031>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-37,c-1}];
  end_loc:[{r-42,c-1}];
  data:[voidcaller_foo_rw_arit_2(intk){intj=k;float*ppp;foo_rw_arit(ppp,j);}];
  obj:[fun_def];

  name:[caller_foo_rw_arit_2];
  args:[
    0:[<builder/test/access_0d/arithmetic.cpp:000037-000027>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_0d/arithmetic.cpp:000041-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_0d/arithmetic.cpp:000037-000001>];
    appId:[caller_foo_rw_arit_2];
    appImpl:[caller_foo_rw_arit_2];
    returnType:[task::coro::dispatcher<app::impl::caller_foo_rw_arit_2>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-37,c-27}];
  end_loc:[{r-37,c-31}];
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
    0:[<builder/test/access_0d/arithmetic.cpp:000038-000011>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-37,c-34}];
  end_loc:[{r-42,c-1}];
  data:[{intj=k;float*ppp;foo_rw_arit(ppp,j);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-38,c-3}];
  end_loc:[{r-38,c-12}];
  data:[j];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[j init k];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-38,c-11}];
  end_loc:[{r-38,c-11}];
  data:[k];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000037-000027>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000038-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[k];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-39,c-3}];
  end_loc:[{r-39,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-41,c-3}];
  end_loc:[{r-41,c-21}];
  data:[foo_rw_arit(ppp,j)];
  obj:[fun_call];

  callee:[<builder/test/access_0d/arithmetic.cpp:000024-000001>];
  caller:[<builder/test/access_0d/arithmetic.cpp:000037-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rw_arit((j,ppp))];
  ];


  path_str:[builder/test/access_0d/];
  path:[steel_builder_test_suite];
  file:[arithmetic.cpp];
  begin_loc:[{r-41,c-15}];
  end_loc:[{r-41,c-15}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000039-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000024-000018>];
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
  file:[arithmetic.cpp];
  begin_loc:[{r-41,c-20}];
  end_loc:[{r-41,c-20}];
  data:[j];
  obj:[data_use];

  root:[<builder/test/access_0d/arithmetic.cpp:000038-000003>];
  callee_or_op:[<builder/test/access_0d/arithmetic.cpp:000024-000031>];
  terminal_root:[
    pcKind:[var];
    pcContent:[j];
  ];
  memAccess:[NULL];
*/