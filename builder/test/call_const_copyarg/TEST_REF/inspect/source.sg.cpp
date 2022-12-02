steel_builder_test_suite
source.cpp
/*

  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-1}];
  end_loc:[{r-3,c-1}];
  data:[voidfoo(inta){}];
  obj:[fun_def];

  name:[foo];
  args:[
    0:[<builder/test/call_const_copyarg/source.cpp:000002-000010>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/call_const_copyarg/source.cpp:000009-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/call_const_copyarg/source.cpp:000002-000001>];
    appId:[fooapp];
    appImpl:[foo];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-10}];
  end_loc:[{r-2,c-14}];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-17}];
  end_loc:[{r-3,c-1}];
  data:[{}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-5,c-1}];
  end_loc:[{r-12,c-1}];
  data:[intmain(){constinta=4;foo(a);return0;}];
  obj:[fun_def];

  name:[main_entry];
  args:[
  ];
  retArg:[<builder/test/call_const_copyarg/source.cpp:5:1>];
  bodyCalls:[
    0:[<builder/test/call_const_copyarg/source.cpp:000009-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/call_const_copyarg/source.cpp:000005-000001>];
    appId:[main_entry];
    appImpl:[main_entry];
    returnType:[task::coro::dispatcher<app::impl::main_entry>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
      1:[int&];
    ];
  ];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-5,c-12}];
  end_loc:[{r-12,c-1}];
  data:[{constinta=4;foo(a);return0;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-7,c-3}];
  end_loc:[{r-7,c-18}];
  data:[a];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a init 4];
  ];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-7,c-17}];
  end_loc:[{r-7,c-17}];
  data:[4];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/call_const_copyarg/source.cpp:000007-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[4];
  ];
  memAccess:[NULL];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-9,c-3}];
  end_loc:[{r-9,c-8}];
  data:[foo(a)];
  obj:[fun_call];

  callee:[<builder/test/call_const_copyarg/source.cpp:000002-000001>];
  caller:[<builder/test/call_const_copyarg/source.cpp:000005-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo(a)];
  ];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-9,c-7}];
  end_loc:[{r-9,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/call_const_copyarg/source.cpp:000007-000003>];
  callee_or_op:[<builder/test/call_const_copyarg/source.cpp:000002-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[NULL];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-11,c-3}];
  end_loc:[{r-11,c-10}];
  data:[return0];
  obj:[fun_ret];

  context:[<builder/test/call_const_copyarg/source.cpp:000005-000012>];


  path_str:[builder/test/call_const_copyarg/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-5,c-1}];
  end_loc:[{r-5,c-1}];
  data:[int&];
  obj:[data_decl];

  declKind:[return_parameter];
  varName:[];
  typeName:[int];
  translationType:[std::add_lvalue_reference_t<int>];
  typeQual:[var];
  indir:[ref];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
  ];
  loopVar:[NULL];
  memGuard:[NULL];
*/