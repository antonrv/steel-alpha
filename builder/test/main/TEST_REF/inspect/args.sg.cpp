steel_builder_test_suite
args.cpp
/*

  path_str:[builder/test/main/];
  path:[steel_builder_test_suite];
  file:[args.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-5,c-1}];
  data:[intmain(intargc,constchar**argv){return0;}];
  obj:[fun_def];

  name:[main_entry];
  args:[
    0:[<builder/test/main/args.cpp:000003-000010>];
    1:[<builder/test/main/args.cpp:000003-000020>];
  ];
  retArg:[<builder/test/main/args.cpp:3:1>];
  bodyCalls:[
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/main/args.cpp:000003-000001>];
    appId:[main_entry];
    appImpl:[main_entry];
    returnType:[void];
    appendTypeParams:[
      0:[int&];
    ];
  ];


  path_str:[builder/test/main/];
  path:[steel_builder_test_suite];
  file:[args.cpp];
  begin_loc:[{r-3,c-10}];
  end_loc:[{r-3,c-14}];
  data:[inta];
  obj:[data_decl];

  declKind:[fargument];
  varName:[argc];
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


  path_str:[builder/test/main/];
  path:[steel_builder_test_suite];
  file:[args.cpp];
  begin_loc:[{r-3,c-20}];
  end_loc:[{r-3,c-33}];
  data:[constchar**a];
  obj:[data_decl];

  declKind:[fargument];
  varName:[argv];
  typeName:[char*];
  translationType:[std::add_pointer_t<std::add_const_t<char*>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/main/];
  path:[steel_builder_test_suite];
  file:[args.cpp];
  begin_loc:[{r-3,c-39}];
  end_loc:[{r-5,c-1}];
  data:[{return0;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/main/];
  path:[steel_builder_test_suite];
  file:[args.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-10}];
  data:[return0];
  obj:[fun_ret];

  context:[<builder/test/main/args.cpp:000003-000039>];


  path_str:[builder/test/main/];
  path:[steel_builder_test_suite];
  file:[args.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-3,c-1}];
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