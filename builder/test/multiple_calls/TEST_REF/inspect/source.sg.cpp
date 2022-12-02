steel_builder_test_suite
source.cpp
/*

  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-1}];
  end_loc:[{r-4,c-1}];
  data:[voidzee(int&a,floatb,constcharc){a+=b+c;}];
  obj:[fun_def];

  name:[zee];
  args:[
    0:[<builder/test/multiple_calls/source.cpp:000002-000010>];
    1:[<builder/test/multiple_calls/source.cpp:000002-000018>];
    2:[<builder/test/multiple_calls/source.cpp:000002-000027>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/multiple_calls/source.cpp:000020-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/multiple_calls/source.cpp:000002-000001>];
    appId:[zeeapp];
    appImpl:[zee];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-10}];
  end_loc:[{r-2,c-15}];
  data:[int&a];
  obj:[data_decl];

  declKind:[fargument];
  varName:[a];
  typeName:[int];
  translationType:[std::add_lvalue_reference_t<int>];
  typeQual:[var];
  indir:[ref];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000003-000003>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-18}];
  end_loc:[{r-2,c-24}];
  data:[floatb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[b];
  typeName:[float];
  translationType:[float];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000003-000008>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-27}];
  end_loc:[{r-2,c-38}];
  data:[constcharc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[c];
  typeName:[char];
  translationType:[std::add_const_t<char>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000003-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-41}];
  end_loc:[{r-4,c-1}];
  data:[{a+=b+c;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-3,c-3}];
  end_loc:[{r-3,c-12}];
  data:[a+=b+c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a incr (b+c)];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-3,c-8}];
  end_loc:[{r-3,c-8}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000002-000018>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000003-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-3,c-12}];
  end_loc:[{r-3,c-12}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000002-000027>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000003-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-7,c-1}];
  end_loc:[{r-9,c-1}];
  data:[voidfoo(int&a){a+=13;}];
  obj:[fun_def];

  name:[foo];
  args:[
    0:[<builder/test/multiple_calls/source.cpp:000007-000010>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/multiple_calls/source.cpp:000022-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/multiple_calls/source.cpp:000007-000001>];
    appId:[fooapp];
    appImpl:[foo];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-7,c-10}];
  end_loc:[{r-7,c-15}];
  data:[int&a];
  obj:[data_decl];

  declKind:[fargument];
  varName:[a];
  typeName:[int];
  translationType:[std::add_lvalue_reference_t<int>];
  typeQual:[var];
  indir:[ref];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000008-000003>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-7,c-18}];
  end_loc:[{r-9,c-1}];
  data:[{a+=13;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-8,c-3}];
  end_loc:[{r-8,c-8}];
  data:[a+=13];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a incr 13];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-8,c-8}];
  end_loc:[{r-8,c-8}];
  data:[13];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000008-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-12,c-1}];
  end_loc:[{r-14,c-1}];
  data:[voidkuu(constint&a){intb=a;}];
  obj:[fun_def];

  name:[kuu];
  args:[
    0:[<builder/test/multiple_calls/source.cpp:000012-000010>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/multiple_calls/source.cpp:000024-000003>];
    1:[<builder/test/multiple_calls/source.cpp:000025-000003>];
    2:[<builder/test/multiple_calls/source.cpp:000026-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/multiple_calls/source.cpp:000012-000001>];
    appId:[kuuapp];
    appImpl:[kuu];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-12,c-10}];
  end_loc:[{r-12,c-21}];
  data:[constint&a];
  obj:[data_decl];

  declKind:[fargument];
  varName:[a];
  typeName:[int];
  translationType:[std::add_lvalue_reference_t<std::add_const_t<int>>];
  typeQual:[cnst];
  indir:[ref];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000013-000011>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-12,c-24}];
  end_loc:[{r-14,c-1}];
  data:[{intb=a;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-13,c-3}];
  end_loc:[{r-13,c-12}];
  data:[b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b init a];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-13,c-11}];
  end_loc:[{r-13,c-11}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000012-000010>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000013-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-18,c-1}];
  end_loc:[{r-27,c-1}];
  data:[voidbar(inta,floatb,constcharc){zee(a,b,c);foo(a);kuu(a);kuu(a);kuu(a);}];
  obj:[fun_def];

  name:[bar];
  args:[
    0:[<builder/test/multiple_calls/source.cpp:000018-000010>];
    1:[<builder/test/multiple_calls/source.cpp:000018-000017>];
    2:[<builder/test/multiple_calls/source.cpp:000018-000026>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/multiple_calls/source.cpp:000020-000003>];
    1:[<builder/test/multiple_calls/source.cpp:000022-000003>];
    2:[<builder/test/multiple_calls/source.cpp:000024-000003>];
    3:[<builder/test/multiple_calls/source.cpp:000025-000003>];
    4:[<builder/test/multiple_calls/source.cpp:000026-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/multiple_calls/source.cpp:000018-000001>];
    appId:[barapp];
    appImpl:[bar];
    returnType:[task::coro::dispatcher<app::impl::bar>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-18,c-10}];
  end_loc:[{r-18,c-14}];
  data:[inta];
  obj:[data_decl];

  declKind:[fargument];
  varName:[a];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000020-000007>];
    1:[<builder/test/multiple_calls/source.cpp:000022-000007>];
    2:[<builder/test/multiple_calls/source.cpp:000024-000007>];
    3:[<builder/test/multiple_calls/source.cpp:000025-000007>];
    4:[<builder/test/multiple_calls/source.cpp:000026-000007>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-18,c-17}];
  end_loc:[{r-18,c-23}];
  data:[floatb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[b];
  typeName:[float];
  translationType:[float];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000020-000010>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-18,c-26}];
  end_loc:[{r-18,c-37}];
  data:[constcharc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[c];
  typeName:[char];
  translationType:[std::add_const_t<char>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/multiple_calls/source.cpp:000020-000013>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-18,c-40}];
  end_loc:[{r-27,c-1}];
  data:[{zee(a,b,c);foo(a);kuu(a);kuu(a);kuu(a);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-20,c-3}];
  end_loc:[{r-20,c-14}];
  data:[zee(a,b,c)];
  obj:[fun_call];

  callee:[<builder/test/multiple_calls/source.cpp:000002-000001>];
  caller:[<builder/test/multiple_calls/source.cpp:000018-000001>];
  own:[
    pcKind:[call];
    pcContent:[zee((a,b,c))];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-20,c-7}];
  end_loc:[{r-20,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000018-000010>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000002-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-20,c-10}];
  end_loc:[{r-20,c-10}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000018-000017>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000002-000018>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-20,c-13}];
  end_loc:[{r-20,c-13}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000018-000026>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000002-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-22,c-3}];
  end_loc:[{r-22,c-8}];
  data:[foo(a)];
  obj:[fun_call];

  callee:[<builder/test/multiple_calls/source.cpp:000007-000001>];
  caller:[<builder/test/multiple_calls/source.cpp:000018-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo(a)];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-22,c-7}];
  end_loc:[{r-22,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000018-000010>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000007-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-24,c-3}];
  end_loc:[{r-24,c-8}];
  data:[kuu(a)];
  obj:[fun_call];

  callee:[<builder/test/multiple_calls/source.cpp:000012-000001>];
  caller:[<builder/test/multiple_calls/source.cpp:000018-000001>];
  own:[
    pcKind:[call];
    pcContent:[kuu(a)];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-24,c-7}];
  end_loc:[{r-24,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000018-000010>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000012-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-25,c-3}];
  end_loc:[{r-25,c-8}];
  data:[kuu(a)];
  obj:[fun_call];

  callee:[<builder/test/multiple_calls/source.cpp:000012-000001>];
  caller:[<builder/test/multiple_calls/source.cpp:000018-000001>];
  own:[
    pcKind:[call];
    pcContent:[kuu(a)];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-25,c-7}];
  end_loc:[{r-25,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000018-000010>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000012-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-8}];
  data:[kuu(a)];
  obj:[fun_call];

  callee:[<builder/test/multiple_calls/source.cpp:000012-000001>];
  caller:[<builder/test/multiple_calls/source.cpp:000018-000001>];
  own:[
    pcKind:[call];
    pcContent:[kuu(a)];
  ];


  path_str:[builder/test/multiple_calls/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-26,c-7}];
  end_loc:[{r-26,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/multiple_calls/source.cpp:000018-000010>];
  callee_or_op:[<builder/test/multiple_calls/source.cpp:000012-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];
*/