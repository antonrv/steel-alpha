steel_builder_test_suite
multiple_point.cpp
/*

  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-8,c-1}];
  data:[voidfoo_ro_multiple_point(constfloat*bbb,ints,inte){floatr;for(inti=s;i<e;i++){r=bbb[i];}}];
  obj:[fun_def];

  name:[foo_ro_multiple_point];
  args:[
    0:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
    1:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
    2:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/multiple_point.cpp:000019-000003>];
    1:[<builder/test/access_1d/multiple_point.cpp:000020-000003>];
    2:[<builder/test/access_1d/multiple_point.cpp:000021-000003>];
    3:[<builder/test/access_1d/multiple_point.cpp:000033-000003>];
    4:[<builder/test/access_1d/multiple_point.cpp:000034-000003>];
    5:[<builder/test/access_1d/multiple_point.cpp:000035-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/multiple_point.cpp:000003-000001>];
    appId:[foo_ro_multiple_point_app];
    appImpl:[foo_ro_multiple_point];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
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
    0:[<builder/test/access_1d/multiple_point.cpp:000006-000009>];
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
        pcContent:[range[ Mins; Maxe ]];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-47}];
  end_loc:[{r-3,c-51}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[s];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000005-000016>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-54}];
  end_loc:[{r-3,c-58}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[e];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000005-000023>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-3,c-61}];
  end_loc:[{r-8,c-1}];
  data:[{floatr;for(inti=s;i<e;i++){r=bbb[i];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
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


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-7,c-3}];
  data:[for(inti=s;i<e;i++){r=bbb[i];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-8}];
  end_loc:[{r-5,c-17}];
  data:[i];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i init s];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-16}];
  end_loc:[{r-5,c-16}];
  data:[s];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000005-000008>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-19}];
  end_loc:[{r-5,c-23}];
  data:[i<e];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i lt e];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-23}];
  end_loc:[{r-5,c-23}];
  data:[e];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000005-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-26}];
  end_loc:[{r-5,c-27}];
  data:[i++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-5,c-31}];
  end_loc:[{r-7,c-3}];
  data:[{r=bbb[i];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/multiple_point.cpp:000003-000061>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-6,c-5}];
  end_loc:[{r-6,c-14}];
  data:[r=bbb[i]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[i]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-6,c-9}];
  end_loc:[{r-6,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000006-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[i];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-6,c-13}];
  end_loc:[{r-6,c-13}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000005-000008>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000006-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-10,c-1}];
  end_loc:[{r-22,c-1}];
  data:[voidcaller_res_ro_multiple_point(){ints1=15;inte1=18;ints2=23;inte2=26;ints3=33;inte3=39;float*ppp;foo_ro_multiple_point(ppp,s1,e1);foo_ro_multiple_point(ppp,s2,e2);foo_ro_multiple_point(ppp,s3,e3);}];
  obj:[fun_def];

  name:[caller_res_ro_multiple_point];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/multiple_point.cpp:000019-000003>];
    1:[<builder/test/access_1d/multiple_point.cpp:000020-000003>];
    2:[<builder/test/access_1d/multiple_point.cpp:000021-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/multiple_point.cpp:000010-000001>];
    appId:[caller_res_ro_multiple_point];
    appImpl:[caller_res_ro_multiple_point];
    returnType:[task::coro::dispatcher<app::impl::caller_res_ro_multiple_point>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-10,c-37}];
  end_loc:[{r-22,c-1}];
  data:[{ints1=15;inte1=18;ints2=23;inte2=26;ints3=33;inte3=39;float*ppp;foo_ro_multiple_point(ppp,s1,e1);foo_ro_multiple_point(ppp,s2,e2);foo_ro_multiple_point(ppp,s3,e3);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-11,c-3}];
  end_loc:[{r-11,c-14}];
  data:[s1];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[s1 init 15];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-11,c-12}];
  end_loc:[{r-11,c-12}];
  data:[15];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000011-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[15];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-12,c-3}];
  end_loc:[{r-12,c-14}];
  data:[e1];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[e1 init 18];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-12,c-12}];
  end_loc:[{r-12,c-12}];
  data:[18];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000012-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[18];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-13,c-3}];
  end_loc:[{r-13,c-14}];
  data:[s2];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[s2 init 23];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-13,c-12}];
  end_loc:[{r-13,c-12}];
  data:[23];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000013-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[23];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-14,c-3}];
  end_loc:[{r-14,c-14}];
  data:[e2];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[e2 init 26];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-14,c-12}];
  end_loc:[{r-14,c-12}];
  data:[26];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000014-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[26];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-15,c-3}];
  end_loc:[{r-15,c-14}];
  data:[s3];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[s3 init 33];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-15,c-12}];
  end_loc:[{r-15,c-12}];
  data:[33];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000015-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[33];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-16,c-3}];
  end_loc:[{r-16,c-14}];
  data:[e3];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[e3 init 39];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-16,c-12}];
  end_loc:[{r-16,c-12}];
  data:[39];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000016-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[39];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-17,c-3}];
  end_loc:[{r-17,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-3}];
  end_loc:[{r-19,c-36}];
  data:[foo_ro_multiple_point(ppp,s1,e1)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_1d/multiple_point.cpp:000010-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((e1,ppp,s1))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-25}];
  end_loc:[{r-19,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000017-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-30}];
  end_loc:[{r-19,c-30}];
  data:[s1];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000011-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s1];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-19,c-34}];
  end_loc:[{r-19,c-34}];
  data:[e1];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000012-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e1];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-20,c-3}];
  end_loc:[{r-20,c-36}];
  data:[foo_ro_multiple_point(ppp,s2,e2)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_1d/multiple_point.cpp:000010-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((e2,ppp,s2))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-20,c-25}];
  end_loc:[{r-20,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000017-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-20,c-30}];
  end_loc:[{r-20,c-30}];
  data:[s2];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000013-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s2];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-20,c-34}];
  end_loc:[{r-20,c-34}];
  data:[e2];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e2];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-21,c-3}];
  end_loc:[{r-21,c-36}];
  data:[foo_ro_multiple_point(ppp,s3,e3)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_1d/multiple_point.cpp:000010-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((e3,ppp,s3))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-21,c-25}];
  end_loc:[{r-21,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000017-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-21,c-30}];
  end_loc:[{r-21,c-30}];
  data:[s3];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000015-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s3];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-21,c-34}];
  end_loc:[{r-21,c-34}];
  data:[e3];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000016-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e3];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-1}];
  end_loc:[{r-36,c-1}];
  data:[voidcaller_unres_ro_multiple_point(ints1Caller,inte1Caller,ints2Caller,inte2Caller,ints3Caller,inte3Caller){ints1=s1Caller;inte1=e1Caller;ints2=s2Caller;inte2=e2Caller;ints3=s3Caller;inte3=e3Caller;float*ppp;foo_ro_multiple_point(ppp,s1,e1);foo_ro_multiple_point(ppp,s2,e2);foo_ro_multiple_point(ppp,s3,e3);}];
  obj:[fun_def];

  name:[caller_unres_ro_multiple_point];
  args:[
    0:[<builder/test/access_1d/multiple_point.cpp:000024-000037>];
    1:[<builder/test/access_1d/multiple_point.cpp:000024-000051>];
    2:[<builder/test/access_1d/multiple_point.cpp:000024-000065>];
    3:[<builder/test/access_1d/multiple_point.cpp:000024-000079>];
    4:[<builder/test/access_1d/multiple_point.cpp:000024-000093>];
    5:[<builder/test/access_1d/multiple_point.cpp:000024-000107>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/multiple_point.cpp:000033-000003>];
    1:[<builder/test/access_1d/multiple_point.cpp:000034-000003>];
    2:[<builder/test/access_1d/multiple_point.cpp:000035-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/multiple_point.cpp:000024-000001>];
    appId:[caller_unres_ro_multiple_point];
    appImpl:[caller_unres_ro_multiple_point];
    returnType:[task::coro::dispatcher<app::impl::caller_unres_ro_multiple_point>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-37}];
  end_loc:[{r-24,c-41}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[s1Caller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000025-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-51}];
  end_loc:[{r-24,c-55}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[e1Caller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000026-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-65}];
  end_loc:[{r-24,c-69}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[s2Caller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000027-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-79}];
  end_loc:[{r-24,c-83}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[e2Caller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000028-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-93}];
  end_loc:[{r-24,c-97}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[s3Caller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000029-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-107}];
  end_loc:[{r-24,c-111}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[e3Caller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/multiple_point.cpp:000030-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-24,c-121}];
  end_loc:[{r-36,c-1}];
  data:[{ints1=s1Caller;inte1=e1Caller;ints2=s2Caller;inte2=e2Caller;ints3=s3Caller;inte3=e3Caller;float*ppp;foo_ro_multiple_point(ppp,s1,e1);foo_ro_multiple_point(ppp,s2,e2);foo_ro_multiple_point(ppp,s3,e3);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-25,c-3}];
  end_loc:[{r-25,c-20}];
  data:[s1];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[s1 init s1Caller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-25,c-12}];
  end_loc:[{r-25,c-12}];
  data:[s1Caller];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000024-000037>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000025-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s1Caller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-20}];
  data:[e1];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[e1 init e1Caller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-26,c-12}];
  end_loc:[{r-26,c-12}];
  data:[e1Caller];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000024-000051>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000026-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e1Caller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-27,c-20}];
  data:[s2];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[s2 init s2Caller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-27,c-12}];
  end_loc:[{r-27,c-12}];
  data:[s2Caller];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000024-000065>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s2Caller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-28,c-3}];
  end_loc:[{r-28,c-20}];
  data:[e2];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[e2 init e2Caller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-28,c-12}];
  end_loc:[{r-28,c-12}];
  data:[e2Caller];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000024-000079>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000028-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e2Caller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-29,c-3}];
  end_loc:[{r-29,c-20}];
  data:[s3];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[s3 init s3Caller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-29,c-12}];
  end_loc:[{r-29,c-12}];
  data:[s3Caller];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000024-000093>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000029-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s3Caller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-30,c-3}];
  end_loc:[{r-30,c-20}];
  data:[e3];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[e3 init e3Caller];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-30,c-12}];
  end_loc:[{r-30,c-12}];
  data:[e3Caller];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000024-000107>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000030-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e3Caller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-31,c-3}];
  end_loc:[{r-31,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-3}];
  end_loc:[{r-33,c-36}];
  data:[foo_ro_multiple_point(ppp,s1,e1)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_1d/multiple_point.cpp:000024-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((e1,ppp,s1))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-25}];
  end_loc:[{r-33,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000031-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-30}];
  end_loc:[{r-33,c-30}];
  data:[s1];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000025-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s1];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-33,c-34}];
  end_loc:[{r-33,c-34}];
  data:[e1];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e1];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-34,c-36}];
  data:[foo_ro_multiple_point(ppp,s2,e2)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_1d/multiple_point.cpp:000024-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((e2,ppp,s2))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-34,c-25}];
  end_loc:[{r-34,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000031-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-34,c-30}];
  end_loc:[{r-34,c-30}];
  data:[s2];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000027-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s2];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-34,c-34}];
  end_loc:[{r-34,c-34}];
  data:[e2];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000028-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e2];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-35,c-3}];
  end_loc:[{r-35,c-36}];
  data:[foo_ro_multiple_point(ppp,s3,e3)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/multiple_point.cpp:000003-000001>];
  caller:[<builder/test/access_1d/multiple_point.cpp:000024-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_ro_multiple_point((e3,ppp,s3))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-35,c-25}];
  end_loc:[{r-35,c-25}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000031-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000028>];
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
  file:[multiple_point.cpp];
  begin_loc:[{r-35,c-30}];
  end_loc:[{r-35,c-30}];
  data:[s3];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000029-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[s3];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[multiple_point.cpp];
  begin_loc:[{r-35,c-34}];
  end_loc:[{r-35,c-34}];
  data:[e3];
  obj:[data_use];

  root:[<builder/test/access_1d/multiple_point.cpp:000030-000003>];
  callee_or_op:[<builder/test/access_1d/multiple_point.cpp:000003-000054>];
  terminal_root:[
    pcKind:[var];
    pcContent:[e3];
  ];
  memAccess:[NULL];
*/