steel_builder_test_suite
source.cpp
/*

  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-1}];
  end_loc:[{r-6,c-1}];
  data:[voidzee(int&a){intb=13;a=b;}];
  obj:[fun_def];

  name:[zee];
  args:[
    0:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000002-000010>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000012-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000002-000001>];
    appId:[zeeapp];
    appImpl:[zee];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
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
    0:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000005-000003>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-2,c-18}];
  end_loc:[{r-6,c-1}];
  data:[{intb=13;a=b;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-13}];
  data:[b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b init 13];
  ];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-4,c-11}];
  end_loc:[{r-4,c-11}];
  data:[13];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000004-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-7}];
  data:[a=b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[a assign b];
  ];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-5,c-7}];
  end_loc:[{r-5,c-7}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000004-000003>];
  callee_or_op:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-10,c-1}];
  end_loc:[{r-15,c-1}];
  data:[voidbar(inta){zee(a);return;}];
  obj:[fun_def];

  name:[bar];
  args:[
    0:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000010-000010>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000012-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000010-000001>];
    appId:[barapp];
    appImpl:[bar];
    returnType:[task::coro::dispatcher<app::impl::bar>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-10,c-10}];
  end_loc:[{r-10,c-14}];
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
    0:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000012-000007>];
  ];
  loopVar:[NULL];
  memGuard:[serialized:mem_guard<mem_ak::point>:no-fields];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-10,c-17}];
  end_loc:[{r-15,c-1}];
  data:[{zee(a);return;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-12,c-3}];
  end_loc:[{r-12,c-8}];
  data:[zee(a)];
  obj:[fun_call];

  callee:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000002-000001>];
  caller:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000010-000001>];
  own:[
    pcKind:[call];
    pcContent:[zee(a)];
  ];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-12,c-7}];
  end_loc:[{r-12,c-7}];
  data:[a];
  obj:[data_use];

  root:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000010-000010>];
  callee_or_op:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000002-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[a];
  ];
  memAccess:[serialized:mem_access<mem_ak::point>:no-fields];


  path_str:[builder/test/call_rw_refarg_param_void_return/];
  path:[steel_builder_test_suite];
  file:[source.cpp];
  begin_loc:[{r-14,c-3}];
  end_loc:[{r-14,c-3}];
  data:[r];
  obj:[fun_ret];

  context:[<builder/test/call_rw_refarg_param_void_return/source.cpp:000010-000017>];
*/