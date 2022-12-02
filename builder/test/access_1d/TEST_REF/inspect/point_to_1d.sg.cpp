steel_builder_test_suite
point_to_1d.cpp
/*

  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-5,c-1}];
  data:[voidinit_v0(float*res,floatval){res[0]=val;}];
  obj:[fun_def];

  name:[init_v0];
  args:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000003-000014>];
    1:[<builder/test/access_1d/point_to_1d.cpp:000003-000027>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000012-000005>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/point_to_1d.cpp:000003-000001>];
    appId:[init_app];
    appImpl:[init_v0];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-3,c-14}];
  end_loc:[{r-3,c-22}];
  data:[float*r];
  obj:[data_decl];

  declKind:[fargument];
  varName:[res];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000004-000003>];
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


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-3,c-27}];
  end_loc:[{r-3,c-33}];
  data:[floatv];
  obj:[data_decl];

  declKind:[fargument];
  varName:[val];
  typeName:[float];
  translationType:[float];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000004-000012>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-3,c-38}];
  end_loc:[{r-5,c-1}];
  data:[{res[0]=val;}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-12}];
  data:[res[0]=val];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[res[0] assign val];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-4,c-7}];
  end_loc:[{r-4,c-7}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000004-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-4,c-12}];
  end_loc:[{r-4,c-12}];
  data:[val];
  obj:[data_use];

  root:[<builder/test/access_1d/point_to_1d.cpp:000003-000027>];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000004-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[val];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-7,c-1}];
  end_loc:[{r-14,c-1}];
  data:[voidinit_caller_v0(float*res,constunsignedn){floatval=13;for(unsignedi=0;i<n;i++){init_v0(&res[i],val);}}];
  obj:[fun_def];

  name:[init_caller_v0];
  args:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000007-000022>];
    1:[<builder/test/access_1d/point_to_1d.cpp:000007-000035>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000012-000005>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/point_to_1d.cpp:000007-000001>];
    appId:[init_caller_v0];
    appImpl:[init_caller_v0];
    returnType:[task::coro::dispatcher<app::impl::init_caller_v0>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-7,c-22}];
  end_loc:[{r-7,c-30}];
  data:[float*r];
  obj:[data_decl];

  declKind:[fargument];
  varName:[res];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000012-000015>];
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
        pcContent:[range[ Min0; Max(1+n) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Maxn ]];
      ];
    ];
    globalOffsets:[
      0:[
        pcKind:[num];
        pcContent:[0];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-7,c-35}];
  end_loc:[{r-7,c-50}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[n];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/point_to_1d.cpp:000011-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-7,c-53}];
  end_loc:[{r-14,c-1}];
  data:[{floatval=13;for(unsignedi=0;i<n;i++){init_v0(&res[i],val);}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-9,c-3}];
  end_loc:[{r-9,c-17}];
  data:[val];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[val init 13];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-9,c-15}];
  end_loc:[{r-9,c-15}];
  data:[13];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000009-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-11,c-3}];
  end_loc:[{r-13,c-3}];
  data:[for(unsignedi=0;i<n;i++){init_v0(&res[i],val);}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-11,c-8}];
  end_loc:[{r-11,c-22}];
  data:[i];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-11,c-21}];
  end_loc:[{r-11,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000011-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-11,c-24}];
  end_loc:[{r-11,c-28}];
  data:[i<n];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i lt n];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-11,c-28}];
  end_loc:[{r-11,c-28}];
  data:[n];
  obj:[data_use];

  root:[<builder/test/access_1d/point_to_1d.cpp:000007-000035>];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000011-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[n];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-11,c-31}];
  end_loc:[{r-11,c-32}];
  data:[i++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-11,c-36}];
  end_loc:[{r-13,c-3}];
  data:[{init_v0(&res[i],val);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/point_to_1d.cpp:000007-000053>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-12,c-5}];
  end_loc:[{r-12,c-27}];
  data:[init_v0(&res[i],val)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/point_to_1d.cpp:000003-000001>];
  caller:[<builder/test/access_1d/point_to_1d.cpp:000007-000001>];
  own:[
    pcKind:[call];
    pcContent:[init_v0((val,&res[i]))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-12,c-15}];
  end_loc:[{r-12,c-15}];
  data:[res];
  obj:[data_use];

  root:[<builder/test/access_1d/point_to_1d.cpp:000007-000022>];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000003-000014>];
  terminal_root:[
    pcKind:[var];
    pcContent:[res];
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
  file:[point_to_1d.cpp];
  begin_loc:[{r-12,c-19}];
  end_loc:[{r-12,c-19}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_1d/point_to_1d.cpp:000011-000008>];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000003-000014>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[point_to_1d.cpp];
  begin_loc:[{r-12,c-23}];
  end_loc:[{r-12,c-23}];
  data:[val];
  obj:[data_use];

  root:[<builder/test/access_1d/point_to_1d.cpp:000009-000003>];
  callee_or_op:[<builder/test/access_1d/point_to_1d.cpp:000003-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[val];
  ];
  memAccess:[NULL];
*/