steel_builder_test_suite
source.cpp
/*

  path_str:[builder/test/call_noargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-1}];
  end_loc:[{r-3,c-1}];
  data:[voidfoo(){}];
  obj:[fun_def];

  name:[foo];
  args:[
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/call_noargs/source.cpp:000007-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/call_noargs/source.cpp:000002-000001>];
    appId:[fooapp];
    appImpl:[foo];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/call_noargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-12}];
  end_loc:[{r-3,c-1}];
  data:[{}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_noargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-5,c-1}];
  end_loc:[{r-10,c-1}];
  data:[intmain(){foo();return0;}];
  obj:[fun_def];

  name:[main_entry];
  args:[
  ];
  retArg:[<builder/test/call_noargs/source.cpp:5:1>];
  bodyCalls:[
    0:[<builder/test/call_noargs/source.cpp:000007-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/call_noargs/source.cpp:000005-000001>];
    appId:[main_entry];
    appImpl:[main_entry];
    returnType:[task::coro::dispatcher<app::impl::main_entry>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
      1:[int&];
    ];
  ];


  path_str:[builder/test/call_noargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-5,c-12}];
  end_loc:[{r-10,c-1}];
  data:[{foo();return0;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_noargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-7,c-3}];
  end_loc:[{r-7,c-7}];
  data:[foo()];
  obj:[fun_call];

  callee:[<builder/test/call_noargs/source.cpp:000002-000001>];
  caller:[<builder/test/call_noargs/source.cpp:000005-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo(no-rhs)];
  ];


  path_str:[builder/test/call_noargs/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-9,c-3}];
  end_loc:[{r-9,c-10}];
  data:[return0];
  obj:[fun_ret];

  context:[<builder/test/call_noargs/source.cpp:000005-000012>];


  path_str:[builder/test/call_noargs/];
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