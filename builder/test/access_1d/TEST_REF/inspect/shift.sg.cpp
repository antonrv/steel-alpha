steel_builder_test_suite
shift.cpp
/*

  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-4,c-1}];
  end_loc:[{r-9,c-1}];
  data:[voidfoo_shift_literal(constfloat*bbb){floatr;for(intii=0;ii<42;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_shift_literal];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000004-000024>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/shift.cpp:000013-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000004-000001>];
    appId:[foo_shift_literal];
    appImpl:[foo_shift_literal];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-4,c-24}];
  end_loc:[{r-4,c-38}];
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
    0:[<builder/test/access_1d/shift.cpp:000007-000009>];
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
        pcContent:[range[ Min0; Max42 ]];
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
  file:[shift.cpp];
  begin_loc:[{r-4,c-43}];
  end_loc:[{r-9,c-1}];
  data:[{floatr;for(intii=0;ii<42;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-8,c-3}];
  data:[for(intii=0;ii<42;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-6,c-8}];
  end_loc:[{r-6,c-18}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-6,c-17}];
  end_loc:[{r-6,c-17}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000006-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-6,c-20}];
  end_loc:[{r-6,c-25}];
  data:[ii<42];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt 42];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-6,c-25}];
  end_loc:[{r-6,c-25}];
  data:[42];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000006-000020>];
  terminal_root:[
    pcKind:[num];
    pcContent:[42];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-6,c-29}];
  end_loc:[{r-6,c-31}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-6,c-35}];
  end_loc:[{r-8,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/shift.cpp:000004-000043>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-7,c-5}];
  end_loc:[{r-7,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-7,c-9}];
  end_loc:[{r-7,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000004-000024>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
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
  file:[shift.cpp];
  begin_loc:[{r-7,c-13}];
  end_loc:[{r-7,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-11,c-1}];
  end_loc:[{r-14,c-1}];
  data:[voidcaller_shift_literal(intshift,constfloat*bbb){float*ppp;foo_shift_literal(&ppp[shift]);}];
  obj:[fun_def];

  name:[caller_shift_literal];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000011-000027>];
    1:[<builder/test/access_1d/shift.cpp:000011-000038>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/shift.cpp:000013-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000011-000001>];
    appId:[caller_shift_literal];
    appImpl:[caller_shift_literal];
    returnType:[task::coro::dispatcher<app::impl::caller_shift_literal>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-11,c-27}];
  end_loc:[{r-11,c-31}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[shift];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000013-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-11,c-38}];
  end_loc:[{r-11,c-52}];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-11,c-57}];
  end_loc:[{r-14,c-1}];
  data:[{float*ppp;foo_shift_literal(&ppp[shift]);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-12,c-3}];
  end_loc:[{r-12,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-13,c-3}];
  end_loc:[{r-13,c-34}];
  data:[foo_shift_literal(&ppp[shift])];
  obj:[fun_call];

  callee:[<builder/test/access_1d/shift.cpp:000004-000001>];
  caller:[<builder/test/access_1d/shift.cpp:000011-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_shift_literal(&ppp[shift])];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-13,c-23}];
  end_loc:[{r-13,c-23}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000012-000003>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000004-000024>];
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
  file:[shift.cpp];
  begin_loc:[{r-13,c-27}];
  end_loc:[{r-13,c-27}];
  data:[shift];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000011-000027>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000004-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[shift];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-18,c-1}];
  end_loc:[{r-23,c-1}];
  data:[voidfoo_shift_start(constfloat*bbb,intsn){floatr;for(intii=sn;ii<42;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_shift_start];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000018-000022>];
    1:[<builder/test/access_1d/shift.cpp:000018-000041>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/shift.cpp:000027-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000018-000001>];
    appId:[foo_shift_start];
    appImpl:[foo_shift_start];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-18,c-22}];
  end_loc:[{r-18,c-36}];
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
    0:[<builder/test/access_1d/shift.cpp:000021-000009>];
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
        pcContent:[range[ Minsn; Max42 ]];
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
  file:[shift.cpp];
  begin_loc:[{r-18,c-41}];
  end_loc:[{r-18,c-45}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[sn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000020-000017>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-18,c-49}];
  end_loc:[{r-23,c-1}];
  data:[{floatr;for(intii=sn;ii<42;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-19,c-3}];
  end_loc:[{r-19,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-20,c-3}];
  end_loc:[{r-22,c-3}];
  data:[for(intii=sn;ii<42;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-20,c-8}];
  end_loc:[{r-20,c-19}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init sn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-20,c-17}];
  end_loc:[{r-20,c-17}];
  data:[sn];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000018-000041>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000020-000008>];
  terminal_root:[
    pcKind:[var];
    pcContent:[sn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-20,c-21}];
  end_loc:[{r-20,c-26}];
  data:[ii<42];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt 42];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-20,c-26}];
  end_loc:[{r-20,c-26}];
  data:[42];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000020-000021>];
  terminal_root:[
    pcKind:[num];
    pcContent:[42];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-20,c-30}];
  end_loc:[{r-20,c-32}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-20,c-36}];
  end_loc:[{r-22,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/shift.cpp:000018-000049>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-21,c-5}];
  end_loc:[{r-21,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-21,c-9}];
  end_loc:[{r-21,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000018-000022>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000021-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
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
  file:[shift.cpp];
  begin_loc:[{r-21,c-13}];
  end_loc:[{r-21,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000020-000008>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000021-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-25,c-1}];
  end_loc:[{r-28,c-1}];
  data:[voidcaller_shift_start(intshift,constfloat*bbb,intsnCaller){float*ppp;foo_shift_start(&ppp[shift],snCaller);}];
  obj:[fun_def];

  name:[caller_shift_start];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000025-000025>];
    1:[<builder/test/access_1d/shift.cpp:000025-000036>];
    2:[<builder/test/access_1d/shift.cpp:000025-000055>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/shift.cpp:000027-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000025-000001>];
    appId:[caller_shift_start];
    appImpl:[caller_shift_start];
    returnType:[task::coro::dispatcher<app::impl::caller_shift_start>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-25,c-25}];
  end_loc:[{r-25,c-29}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[shift];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000027-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-25,c-36}];
  end_loc:[{r-25,c-50}];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-25,c-55}];
  end_loc:[{r-25,c-59}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[snCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000027-000033>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-25,c-69}];
  end_loc:[{r-28,c-1}];
  data:[{float*ppp;foo_shift_start(&ppp[shift],snCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-27,c-42}];
  data:[foo_shift_start(&ppp[shift],snCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/shift.cpp:000018-000001>];
  caller:[<builder/test/access_1d/shift.cpp:000025-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_shift_start((snCaller,&ppp[shift]))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-27,c-21}];
  end_loc:[{r-27,c-21}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000018-000022>];
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
  file:[shift.cpp];
  begin_loc:[{r-27,c-25}];
  end_loc:[{r-27,c-25}];
  data:[shift];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000025-000025>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000018-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[shift];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-27,c-33}];
  end_loc:[{r-27,c-33}];
  data:[snCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000025-000055>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000018-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[snCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-32,c-1}];
  end_loc:[{r-37,c-1}];
  data:[voidfoo_shift_end(constfloat*bbb,inten){floatr;for(intii=0;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_shift_end];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000032-000020>];
    1:[<builder/test/access_1d/shift.cpp:000032-000039>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/shift.cpp:000041-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000032-000001>];
    appId:[foo_shift_end];
    appImpl:[foo_shift_end];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-32,c-20}];
  end_loc:[{r-32,c-34}];
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
    0:[<builder/test/access_1d/shift.cpp:000035-000009>];
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
        pcContent:[range[ Min0; Maxen ]];
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
  file:[shift.cpp];
  begin_loc:[{r-32,c-39}];
  end_loc:[{r-32,c-43}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[en];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000034-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-32,c-47}];
  end_loc:[{r-37,c-1}];
  data:[{floatr;for(intii=0;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-33,c-3}];
  end_loc:[{r-33,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-36,c-3}];
  data:[for(intii=0;ii<en;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-34,c-8}];
  end_loc:[{r-34,c-18}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-34,c-17}];
  end_loc:[{r-34,c-17}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000034-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-34,c-20}];
  end_loc:[{r-34,c-25}];
  data:[ii<en];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt en];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-34,c-25}];
  end_loc:[{r-34,c-25}];
  data:[en];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000032-000039>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000034-000020>];
  terminal_root:[
    pcKind:[var];
    pcContent:[en];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-34,c-29}];
  end_loc:[{r-34,c-31}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-34,c-35}];
  end_loc:[{r-36,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/shift.cpp:000032-000047>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-35,c-5}];
  end_loc:[{r-35,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-35,c-9}];
  end_loc:[{r-35,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000032-000020>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000035-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
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
  file:[shift.cpp];
  begin_loc:[{r-35,c-13}];
  end_loc:[{r-35,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000034-000008>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000035-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-39,c-1}];
  end_loc:[{r-42,c-1}];
  data:[voidcaller_shift_end(intshift,constfloat*bbb,intenCaller){float*ppp;foo_shift_end(&ppp[shift],enCaller);}];
  obj:[fun_def];

  name:[caller_shift_end];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000039-000023>];
    1:[<builder/test/access_1d/shift.cpp:000039-000034>];
    2:[<builder/test/access_1d/shift.cpp:000039-000053>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/shift.cpp:000041-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000039-000001>];
    appId:[caller_shift_end];
    appImpl:[caller_shift_end];
    returnType:[task::coro::dispatcher<app::impl::caller_shift_end>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-39,c-23}];
  end_loc:[{r-39,c-27}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[shift];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000041-000023>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-39,c-34}];
  end_loc:[{r-39,c-48}];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-39,c-53}];
  end_loc:[{r-39,c-57}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[enCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000041-000031>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-39,c-67}];
  end_loc:[{r-42,c-1}];
  data:[{float*ppp;foo_shift_end(&ppp[shift],enCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-40,c-3}];
  end_loc:[{r-40,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-41,c-3}];
  end_loc:[{r-41,c-40}];
  data:[foo_shift_end(&ppp[shift],enCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/shift.cpp:000032-000001>];
  caller:[<builder/test/access_1d/shift.cpp:000039-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_shift_end((enCaller,&ppp[shift]))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-41,c-19}];
  end_loc:[{r-41,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000032-000020>];
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
  file:[shift.cpp];
  begin_loc:[{r-41,c-23}];
  end_loc:[{r-41,c-23}];
  data:[shift];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000039-000023>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000032-000020>];
  terminal_root:[
    pcKind:[var];
    pcContent:[shift];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-41,c-31}];
  end_loc:[{r-41,c-31}];
  data:[enCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000039-000053>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000032-000039>];
  terminal_root:[
    pcKind:[var];
    pcContent:[enCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-47,c-1}];
  end_loc:[{r-52,c-1}];
  data:[voidfoo_shift_start_end(constfloat*bbb,intsn,inten){floatr;for(intii=sn;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_def];

  name:[foo_shift_start_end];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000047-000026>];
    1:[<builder/test/access_1d/shift.cpp:000047-000045>];
    2:[<builder/test/access_1d/shift.cpp:000047-000053>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/shift.cpp:000056-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000047-000001>];
    appId:[foo_shift_start_end];
    appImpl:[foo_shift_start_end];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-47,c-26}];
  end_loc:[{r-47,c-40}];
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
    0:[<builder/test/access_1d/shift.cpp:000050-000009>];
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
        pcContent:[range[ Minsn; Maxen ]];
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
  file:[shift.cpp];
  begin_loc:[{r-47,c-45}];
  end_loc:[{r-47,c-49}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[sn];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000049-000017>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-47,c-53}];
  end_loc:[{r-47,c-57}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[en];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000049-000026>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-47,c-61}];
  end_loc:[{r-52,c-1}];
  data:[{floatr;for(intii=sn;ii<en;ii++){r=bbb[ii];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-48,c-3}];
  end_loc:[{r-48,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-49,c-3}];
  end_loc:[{r-51,c-3}];
  data:[for(intii=sn;ii<en;ii++){r=bbb[ii];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-49,c-8}];
  end_loc:[{r-49,c-19}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init sn];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-49,c-17}];
  end_loc:[{r-49,c-17}];
  data:[sn];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000047-000045>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000049-000008>];
  terminal_root:[
    pcKind:[var];
    pcContent:[sn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-49,c-21}];
  end_loc:[{r-49,c-26}];
  data:[ii<en];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt en];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-49,c-26}];
  end_loc:[{r-49,c-26}];
  data:[en];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000047-000053>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000049-000021>];
  terminal_root:[
    pcKind:[var];
    pcContent:[en];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-49,c-30}];
  end_loc:[{r-49,c-32}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-49,c-36}];
  end_loc:[{r-51,c-3}];
  data:[{r=bbb[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/shift.cpp:000047-000061>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-50,c-5}];
  end_loc:[{r-50,c-15}];
  data:[r=bbb[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[ii]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-50,c-9}];
  end_loc:[{r-50,c-9}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000047-000026>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000050-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[ii];
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
  file:[shift.cpp];
  begin_loc:[{r-50,c-13}];
  end_loc:[{r-50,c-13}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000049-000008>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000050-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-54,c-1}];
  end_loc:[{r-57,c-1}];
  data:[voidcaller_shift_start_end(intshift,intsnCaller,intenCaller){float*ppp;foo_shift_start_end(&ppp[shift],snCaller,enCaller);}];
  obj:[fun_def];

  name:[caller_shift_start_end];
  args:[
    0:[<builder/test/access_1d/shift.cpp:000054-000029>];
    1:[<builder/test/access_1d/shift.cpp:000054-000040>];
    2:[<builder/test/access_1d/shift.cpp:000054-000054>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/shift.cpp:000056-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/shift.cpp:000054-000001>];
    appId:[caller_shift_start_end];
    appImpl:[caller_shift_start_end];
    returnType:[task::coro::dispatcher<app::impl::caller_shift_start_end>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-54,c-29}];
  end_loc:[{r-54,c-33}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[shift];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000056-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-54,c-40}];
  end_loc:[{r-54,c-44}];
  data:[ints];
  obj:[data_decl];

  declKind:[fargument];
  varName:[snCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000056-000036>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-54,c-54}];
  end_loc:[{r-54,c-58}];
  data:[inte];
  obj:[data_decl];

  declKind:[fargument];
  varName:[enCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/shift.cpp:000056-000046>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-54,c-68}];
  end_loc:[{r-57,c-1}];
  data:[{float*ppp;foo_shift_start_end(&ppp[shift],snCaller,enCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-55,c-3}];
  end_loc:[{r-55,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-56,c-3}];
  end_loc:[{r-56,c-54}];
  data:[foo_shift_start_end(&ppp[shift],snCaller,enCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/shift.cpp:000047-000001>];
  caller:[<builder/test/access_1d/shift.cpp:000054-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_shift_start_end((enCaller,snCaller,&ppp[shift]))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-56,c-24}];
  end_loc:[{r-56,c-24}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000055-000003>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000047-000026>];
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
  file:[shift.cpp];
  begin_loc:[{r-56,c-28}];
  end_loc:[{r-56,c-28}];
  data:[shift];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000054-000029>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000047-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[shift];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-56,c-36}];
  end_loc:[{r-56,c-36}];
  data:[snCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000054-000040>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000047-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[snCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[shift.cpp];
  begin_loc:[{r-56,c-46}];
  end_loc:[{r-56,c-46}];
  data:[enCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/shift.cpp:000054-000054>];
  callee_or_op:[<builder/test/access_1d/shift.cpp:000047-000053>];
  terminal_root:[
    pcKind:[var];
    pcContent:[enCaller];
  ];
  memAccess:[NULL];
*/