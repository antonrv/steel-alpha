steel_builder_test_suite
source.cpp
/*

  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-1}];
  end_loc:[{r-4,c-1}];
  data:[voidzee(int&a,floatb,constcharc){a=13;}];
  obj:[fun_def];

  name:[zee];
  args:[
    0:[<builder/test/call_copyargs/source.cpp:000002-000010>];
    1:[<builder/test/call_copyargs/source.cpp:000002-000018>];
    2:[<builder/test/call_copyargs/source.cpp:000002-000027>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/call_copyargs/source.cpp:000010-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/call_copyargs/source.cpp:000002-000001>];
    appId:[zeeapp];
    appImpl:[zee];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/call_copyargs/];
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
    0:[<builder/test/call_copyargs/source.cpp:000003-000003>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/call_copyargs/];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/call_copyargs/];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-41}];
  end_loc:[{r-4,c-1}];
  data:[{a=13;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-3,c-3}];
  end_loc:[{r-3,c-7}];
  data:[a=13];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a assign 13];
  ];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-3,c-7}];
  end_loc:[{r-3,c-7}];
  data:[13];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/call_copyargs/source.cpp:000003-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-8,c-1}];
  end_loc:[{r-11,c-1}];
  data:[voidbar(inta,floatb,constcharc){zee(a,b,c);}];
  obj:[fun_def];

  name:[bar];
  args:[
    0:[<builder/test/call_copyargs/source.cpp:000008-000010>];
    1:[<builder/test/call_copyargs/source.cpp:000008-000017>];
    2:[<builder/test/call_copyargs/source.cpp:000008-000026>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/call_copyargs/source.cpp:000010-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/call_copyargs/source.cpp:000008-000001>];
    appId:[barapp];
    appImpl:[bar];
    returnType:[task::coro::dispatcher<app::impl::bar>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-8,c-10}];
  end_loc:[{r-8,c-14}];
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
    0:[<builder/test/call_copyargs/source.cpp:000010-000007>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-8,c-17}];
  end_loc:[{r-8,c-23}];
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
    0:[<builder/test/call_copyargs/source.cpp:000010-000010>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-8,c-26}];
  end_loc:[{r-8,c-37}];
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
    0:[<builder/test/call_copyargs/source.cpp:000010-000013>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-8,c-40}];
  end_loc:[{r-11,c-1}];
  data:[{zee(a,b,c);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-10,c-3}];
  end_loc:[{r-10,c-14}];
  data:[zee(a,b,c)];
  obj:[fun_call];

  callee:[<builder/test/call_copyargs/source.cpp:000002-000001>];
  caller:[<builder/test/call_copyargs/source.cpp:000008-000001>];
  own:[
    pcKind:[call];
    pcContent:[zee((a,b,c))];
  ];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-10,c-7}];
  end_loc:[{r-10,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/call_copyargs/source.cpp:000008-000010>];
  callee_or_op:[<builder/test/call_copyargs/source.cpp:000002-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-10,c-10}];
  end_loc:[{r-10,c-10}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/call_copyargs/source.cpp:000008-000017>];
  callee_or_op:[<builder/test/call_copyargs/source.cpp:000002-000018>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/call_copyargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-10,c-13}];
  end_loc:[{r-10,c-13}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/call_copyargs/source.cpp:000008-000026>];
  callee_or_op:[<builder/test/call_copyargs/source.cpp:000002-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];
*/