steel_builder_test_suite
mesh_single_uneven.cpp
/*

  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-4,c-1}];
  end_loc:[{r-9,c-1}];
  data:[voidfoo_wo(float*ptr,constunsignednCols){floatinit=13;for(unsignedcc=0;cc<nCols;cc++){ptr[cc]=init;}}];
  obj:[fun_def];

  name:[foo_wo];
  args:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000013>];
    1:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000026>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000016-000005>];
    1:[<builder/test/access_1d/mesh_single_uneven.cpp:000022-000005>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000001>];
    appId:[fooapp_wo];
    appImpl:[foo_wo];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-4,c-13}];
  end_loc:[{r-4,c-21}];
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
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000007-000005>];
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
        pcContent:[range[ Min0; MaxnCols ]];
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
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-4,c-26}];
  end_loc:[{r-4,c-41}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCols];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000006-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-4,c-48}];
  end_loc:[{r-9,c-1}];
  data:[{floatinit=13;for(unsignedcc=0;cc<nCols;cc++){ptr[cc]=init;}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-18}];
  data:[init];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[init init 13];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-5,c-16}];
  end_loc:[{r-5,c-16}];
  data:[13];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000005-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-8,c-3}];
  data:[for(unsignedcc=0;cc<nCols;cc++){ptr[cc]=init;}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-6,c-8}];
  end_loc:[{r-6,c-23}];
  data:[cc];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[cc init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-6,c-22}];
  end_loc:[{r-6,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000006-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-6,c-25}];
  end_loc:[{r-6,c-30}];
  data:[cc<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[cc lt nCols];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-6,c-30}];
  end_loc:[{r-6,c-30}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000026>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000006-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-6,c-37}];
  end_loc:[{r-6,c-39}];
  data:[cc++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[cc incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-6,c-43}];
  end_loc:[{r-8,c-3}];
  data:[{ptr[cc]=init;}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000048>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-7,c-5}];
  end_loc:[{r-7,c-15}];
  data:[ptr[cc]=init];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ptr[cc] assign init];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-7,c-9}];
  end_loc:[{r-7,c-9}];
  data:[cc];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[cc];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-7,c-15}];
  end_loc:[{r-7,c-15}];
  data:[init];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000005-000003>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[init];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-11,c-1}];
  end_loc:[{r-24,c-1}];
  data:[voidcaller_wo(float*ptrCaller,constunsignednElems,constunsignedbSize){unsignednBlocksEven=nElems/bSize;for(unsignedc=0;c<nBlocksEven;c++){foo_wo(&ptrCaller[c*bSize],bSize);}unsignedbSizeRemain=nElems%bSize;if(bSizeRemain!=0){foo_wo(&ptrCaller[nBlocksEven*bSize],bSizeRemain);}}];
  obj:[fun_def];

  name:[caller_wo];
  args:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000016>];
    1:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000035>];
    2:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000058>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000016-000005>];
    1:[<builder/test/access_1d/mesh_single_uneven.cpp:000022-000005>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000001>];
    appId:[caller_wo];
    appImpl:[caller_wo];
    returnType:[task::coro::dispatcher<app::impl::caller_wo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-11,c-16}];
  end_loc:[{r-11,c-24}];
  data:[float*p];
  obj:[data_decl];

  declKind:[fargument];
  varName:[ptrCaller];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000016-000014>];
    1:[<builder/test/access_1d/mesh_single_uneven.cpp:000022-000014>];
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
        pcContent:[range[ Min(0,(bSize*nBlocksEven)); Max((bSize+(bSize*nBlocksEven)),((nElems%bSize)+(bSize*nBlocksEven))) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max((nElems/bSize),(1+(nElems/bSize))) ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-11,c-35}];
  end_loc:[{r-11,c-50}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nElems];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000013-000026>];
    1:[<builder/test/access_1d/mesh_single_uneven.cpp:000019-000026>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-11,c-58}];
  end_loc:[{r-11,c-73}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSize];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/mesh_single_uneven.cpp:000013-000035>];
    1:[<builder/test/access_1d/mesh_single_uneven.cpp:000016-000026>];
    2:[<builder/test/access_1d/mesh_single_uneven.cpp:000016-000034>];
    3:[<builder/test/access_1d/mesh_single_uneven.cpp:000019-000035>];
    4:[<builder/test/access_1d/mesh_single_uneven.cpp:000022-000036>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-11,c-80}];
  end_loc:[{r-24,c-1}];
  data:[{unsignednBlocksEven=nElems/bSize;for(unsignedc=0;c<nBlocksEven;c++){foo_wo(&ptrCaller[c*bSize],bSize);}unsignedbSizeRemain=nElems%bSize;if(bSizeRemain!=0){foo_wo(&ptrCaller[nBlocksEven*bSize],bSizeRemain);}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-13,c-3}];
  end_loc:[{r-13,c-40}];
  data:[nBlocksEven];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nBlocksEven init (nElems/bSize)];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-13,c-26}];
  end_loc:[{r-13,c-26}];
  data:[nElems];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000035>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000013-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nElems];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-13,c-35}];
  end_loc:[{r-13,c-35}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000058>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000013-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-15,c-3}];
  end_loc:[{r-17,c-3}];
  data:[for(unsignedc=0;c<nBlocksEven;c++){foo_wo(&ptrCaller[c*bSize],bSize);}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-15,c-8}];
  end_loc:[{r-15,c-22}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-15,c-21}];
  end_loc:[{r-15,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000015-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-15,c-24}];
  end_loc:[{r-15,c-28}];
  data:[c<nBlocksEven];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c lt nBlocksEven];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-15,c-28}];
  end_loc:[{r-15,c-28}];
  data:[nBlocksEven];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000013-000003>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000015-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocksEven];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-15,c-41}];
  end_loc:[{r-15,c-42}];
  data:[c++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-15,c-46}];
  end_loc:[{r-17,c-3}];
  data:[{foo_wo(&ptrCaller[c*bSize],bSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000080>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-16,c-5}];
  end_loc:[{r-16,c-40}];
  data:[foo_wo(&ptrCaller[c*bSize],bSize)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000001>];
  caller:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_wo((bSize,&ptrCaller[(bSize*c)]))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-16,c-14}];
  end_loc:[{r-16,c-14}];
  data:[ptrCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000016>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000013>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptrCaller];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[c];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[bSize];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-16,c-24}];
  end_loc:[{r-16,c-24}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000015-000008>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000013>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-16,c-26}];
  end_loc:[{r-16,c-26}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000058>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000013>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-16,c-34}];
  end_loc:[{r-16,c-34}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000058>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-19,c-3}];
  end_loc:[{r-19,c-40}];
  data:[bSizeRemain];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bSizeRemain init (nElems%bSize)];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-19,c-26}];
  end_loc:[{r-19,c-26}];
  data:[nElems];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000035>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000019-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nElems];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-19,c-35}];
  end_loc:[{r-19,c-35}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000058>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000019-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-21,c-7}];
  end_loc:[{r-21,c-22}];
  data:[bSizeRemain!=0];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bSizeRemain neq 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-21,c-22}];
  end_loc:[{r-21,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000021-000007>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-21,c-25}];
  end_loc:[{r-23,c-3}];
  data:[{foo_wo(&ptrCaller[nBlocksEven*bSize],bSizeRemain);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000080>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-22,c-5}];
  end_loc:[{r-22,c-56}];
  data:[foo_wo(&ptrCaller[nBlocksEven*bSize],bSizeRemain)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000001>];
  caller:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_wo((bSizeRemain,&ptrCaller[(bSize*nBlocksEven)]))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-22,c-14}];
  end_loc:[{r-22,c-14}];
  data:[ptrCaller];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000016>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000013>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptrCaller];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-22,c-24}];
  end_loc:[{r-22,c-24}];
  data:[nBlocksEven];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000013-000003>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000013>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocksEven];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-22,c-36}];
  end_loc:[{r-22,c-36}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000011-000058>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000013>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[mesh_single_uneven.cpp];
  begin_loc:[{r-22,c-44}];
  end_loc:[{r-22,c-44}];
  data:[bSizeRemain];
  obj:[data_use];

  root:[<builder/test/access_1d/mesh_single_uneven.cpp:000019-000003>];
  callee_or_op:[<builder/test/access_1d/mesh_single_uneven.cpp:000004-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeRemain];
  ];
  memAccess:[NULL];
*/