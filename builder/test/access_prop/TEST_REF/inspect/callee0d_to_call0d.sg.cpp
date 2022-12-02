steel_builder_test_suite
callee0d_to_call0d.cpp
/*

  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-6,c-1}];
  data:[voidcallee_offset(float*bbb,inti){floatr;bbb[i]=r;}];
  obj:[fun_def];

  name:[callee_offset];
  args:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000003-000020>];
    1:[<builder/test/access_prop/callee0d_to_call0d.cpp:000003-000033>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000012-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_prop/callee0d_to_call0d.cpp:000003-000001>];
    appId:[callee_offset_app];
    appImpl:[callee_offset];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-3,c-20}];
  end_loc:[{r-3,c-28}];
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
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000005-000003>];
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


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-3,c-33}];
  end_loc:[{r-3,c-37}];
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
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000005-000007>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-3,c-40}];
  end_loc:[{r-6,c-1}];
  data:[{floatr;bbb[i]=r;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-12}];
  data:[bbb[i]=r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bbb[i] assign r];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-5,c-7}];
  end_loc:[{r-5,c-7}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_prop/callee0d_to_call0d.cpp:000003-000033>];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-5,c-12}];
  end_loc:[{r-5,c-12}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_prop/callee0d_to_call0d.cpp:000004-000003>];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-8,c-1}];
  end_loc:[{r-13,c-1}];
  data:[voidcaller_offset(float*ptr){inta=15;callee_offset(ptr,a);}];
  obj:[fun_def];

  name:[caller_offset];
  args:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000008-000020>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000012-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_prop/callee0d_to_call0d.cpp:000008-000001>];
    appId:[caller_offset];
    appImpl:[caller_offset];
    returnType:[task::coro::dispatcher<app::impl::caller_offset>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-8,c-20}];
  end_loc:[{r-8,c-28}];
  data:[float*p];
  obj:[data_decl];

  declKind:[fargument];
  varName:[ptr];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000012-000018>];
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
        pcContent:[a];
      ];
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-8,c-33}];
  end_loc:[{r-13,c-1}];
  data:[{inta=15;callee_offset(ptr,a);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-10,c-3}];
  end_loc:[{r-10,c-13}];
  data:[a];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a init 15];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-10,c-11}];
  end_loc:[{r-10,c-11}];
  data:[15];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000010-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[15];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-12,c-3}];
  end_loc:[{r-12,c-25}];
  data:[callee_offset(ptr,a)];
  obj:[fun_call];

  callee:[<builder/test/access_prop/callee0d_to_call0d.cpp:000003-000001>];
  caller:[<builder/test/access_prop/callee0d_to_call0d.cpp:000008-000001>];
  own:[
    pcKind:[call];
    pcContent:[callee_offset((a,ptr))];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-12,c-18}];
  end_loc:[{r-12,c-18}];
  data:[ptr];
  obj:[data_use];

  root:[<builder/test/access_prop/callee0d_to_call0d.cpp:000008-000020>];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000003-000020>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptr];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-12,c-23}];
  end_loc:[{r-12,c-23}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/access_prop/callee0d_to_call0d.cpp:000010-000003>];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000003-000033>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-16,c-1}];
  end_loc:[{r-19,c-1}];
  data:[voidcallee_no_offset(float*bbb){floatr;bbb[0]=r;}];
  obj:[fun_def];

  name:[callee_no_offset];
  args:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000016-000023>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000025-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_prop/callee0d_to_call0d.cpp:000016-000001>];
    appId:[callee_no_offset_app];
    appImpl:[callee_no_offset];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-16,c-23}];
  end_loc:[{r-16,c-31}];
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
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000018-000003>];
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
        pcKind:[num];
        pcContent:[0];
      ];
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-16,c-36}];
  end_loc:[{r-19,c-1}];
  data:[{floatr;bbb[0]=r;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-17,c-3}];
  end_loc:[{r-17,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-18,c-3}];
  end_loc:[{r-18,c-12}];
  data:[bbb[0]=r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bbb[0] assign r];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-18,c-7}];
  end_loc:[{r-18,c-7}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000018-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-18,c-12}];
  end_loc:[{r-18,c-12}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_prop/callee0d_to_call0d.cpp:000017-000003>];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000018-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-21,c-1}];
  end_loc:[{r-26,c-1}];
  data:[voidcaller_no_offset(float*ptr){inta=15;callee_no_offset(ptr);}];
  obj:[fun_def];

  name:[caller_no_offset];
  args:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000021-000023>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000025-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_prop/callee0d_to_call0d.cpp:000021-000001>];
    appId:[caller_no_offset];
    appImpl:[caller_no_offset];
    returnType:[task::coro::dispatcher<app::impl::caller_no_offset>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-21,c-23}];
  end_loc:[{r-21,c-31}];
  data:[float*p];
  obj:[data_decl];

  declKind:[fargument];
  varName:[ptr];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_prop/callee0d_to_call0d.cpp:000025-000021>];
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
        pcKind:[num];
        pcContent:[0];
      ];
    ];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-21,c-36}];
  end_loc:[{r-26,c-1}];
  data:[{inta=15;callee_no_offset(ptr);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-23,c-3}];
  end_loc:[{r-23,c-13}];
  data:[a];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a init 15];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-23,c-11}];
  end_loc:[{r-23,c-11}];
  data:[15];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000023-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[15];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-25,c-3}];
  end_loc:[{r-25,c-25}];
  data:[callee_no_offset(ptr)];
  obj:[fun_call];

  callee:[<builder/test/access_prop/callee0d_to_call0d.cpp:000016-000001>];
  caller:[<builder/test/access_prop/callee0d_to_call0d.cpp:000021-000001>];
  own:[
    pcKind:[call];
    pcContent:[callee_no_offset(ptr)];
  ];


  path_str:[builder/test/access_prop/];
  path:[steel_builder_test_suite];
  file:[callee0d_to_call0d.cpp];
  begin_loc:[{r-25,c-21}];
  end_loc:[{r-25,c-21}];
  data:[ptr];
  obj:[data_use];

  root:[<builder/test/access_prop/callee0d_to_call0d.cpp:000021-000023>];
  callee_or_op:[<builder/test/access_prop/callee0d_to_call0d.cpp:000016-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptr];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];
*/