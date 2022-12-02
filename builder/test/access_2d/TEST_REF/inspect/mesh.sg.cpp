steel_builder_test_suite
mesh.cpp
/*

  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-10,c-1}];
  data:[voidfoo(float*ptr,constunsignednRows,constunsignednCols,constunsignedstride){floatinit=13;for(unsignedrr=0;rr<nRows;rr++){for(unsignedcc=0;cc<nCols;cc++){ptr[rr*stride+cc]=init;}}}];
  obj:[fun_def];

  name:[foo];
  args:[
    0:[<builder/test/access_2d/mesh.cpp:000003-000010>];
    1:[<builder/test/access_2d/mesh.cpp:000003-000023>];
    2:[<builder/test/access_2d/mesh.cpp:000003-000045>];
    3:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mesh.cpp:000017-000007>];
    1:[<builder/test/access_2d/mesh.cpp:000026-000007>];
    2:[<builder/test/access_2d/mesh.cpp:000034-000007>];
    3:[<builder/test/access_2d/mesh.cpp:000044-000007>];
    4:[<builder/test/access_2d/mesh.cpp:000052-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mesh.cpp:000003-000001>];
    appId:[fooapp_wo];
    appImpl:[foo];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-10}];
  end_loc:[{r-3,c-18}];
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
    0:[<builder/test/access_2d/mesh.cpp:000007-000007>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[stride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRows ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnCols ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min; Max ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min; Max ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-23}];
  end_loc:[{r-3,c-38}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000005-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-45}];
  end_loc:[{r-3,c-60}];
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
    0:[<builder/test/access_2d/mesh.cpp:000006-000032>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-67}];
  end_loc:[{r-3,c-82}];
  data:[constunsigneds];
  obj:[data_decl];

  declKind:[fargument];
  varName:[stride];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000007-000014>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-90}];
  end_loc:[{r-10,c-1}];
  data:[{floatinit=13;for(unsignedrr=0;rr<nRows;rr++){for(unsignedcc=0;cc<nCols;cc++){ptr[rr*stride+cc]=init;}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-18}];
  data:[init];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[init init 13];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-4,c-16}];
  end_loc:[{r-4,c-16}];
  data:[13];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000004-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-9,c-3}];
  data:[for(unsignedrr=0;rr<nRows;rr++){for(unsignedcc=0;cc<nCols;cc++){ptr[rr*stride+cc]=init;}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-8}];
  end_loc:[{r-5,c-23}];
  data:[rr];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[rr init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-22}];
  end_loc:[{r-5,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000005-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-25}];
  end_loc:[{r-5,c-30}];
  data:[rr<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[rr lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-30}];
  end_loc:[{r-5,c-30}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000003-000023>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000005-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-37}];
  end_loc:[{r-5,c-39}];
  data:[rr++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[rr incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-43}];
  end_loc:[{r-9,c-3}];
  data:[{for(unsignedcc=0;cc<nCols;cc++){ptr[rr*stride+cc]=init;}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000003-000090>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-5}];
  end_loc:[{r-8,c-5}];
  data:[for(unsignedcc=0;cc<nCols;cc++){ptr[rr*stride+cc]=init;}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mesh.cpp:000005-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-10}];
  end_loc:[{r-6,c-25}];
  data:[cc];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[cc init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-24}];
  end_loc:[{r-6,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000006-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-27}];
  end_loc:[{r-6,c-32}];
  data:[cc<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[cc lt nCols];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-32}];
  end_loc:[{r-6,c-32}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000003-000045>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000006-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-39}];
  end_loc:[{r-6,c-41}];
  data:[cc++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[cc incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-45}];
  end_loc:[{r-8,c-5}];
  data:[{ptr[rr*stride+cc]=init;}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000005-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-7}];
  end_loc:[{r-7,c-29}];
  data:[ptr[rr*stride+cc]=init];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ptr[(cc+(rr*stride))] assign init];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-11}];
  end_loc:[{r-7,c-11}];
  data:[rr];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000005-000008>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000007-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[rr];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-14}];
  end_loc:[{r-7,c-14}];
  data:[stride];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000007-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[stride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-23}];
  end_loc:[{r-7,c-23}];
  data:[cc];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000006-000010>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000007-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[cc];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-29}];
  end_loc:[{r-7,c-29}];
  data:[init];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000004-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000007-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[init];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-12,c-1}];
  end_loc:[{r-20,c-1}];
  data:[voidcaller1_foo(float*ptrCaller,constunsignednRowBlocks,constunsignednColBlocks,constunsignedchunkRowsCaller,constunsignedchunkColsCaller){unsignedstride=nColBlocks*chunkColsCaller*chunkRowsCaller;unsignedlocalStride=nColBlocks*chunkColsCaller;for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*stride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}}];
  obj:[fun_def];

  name:[caller1_foo];
  args:[
    0:[<builder/test/access_2d/mesh.cpp:000012-000018>];
    1:[<builder/test/access_2d/mesh.cpp:000012-000037>];
    2:[<builder/test/access_2d/mesh.cpp:000012-000064>];
    3:[<builder/test/access_2d/mesh.cpp:000012-000091>];
    4:[<builder/test/access_2d/mesh.cpp:000012-000123>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mesh.cpp:000017-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mesh.cpp:000012-000001>];
    appId:[caller1_foo];
    appImpl:[caller1_foo];
    returnType:[task::coro::dispatcher<app::impl::caller1_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-12,c-18}];
  end_loc:[{r-12,c-26}];
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
    0:[<builder/test/access_2d/mesh.cpp:000017-000013>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[localStride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min(0/localStride); Max(chunkRowsCaller+((nRowBlocks*stride)/localStride)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(chunkColsCaller+(chunkColsCaller*nColBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRowBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnColBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-12,c-37}];
  end_loc:[{r-12,c-52}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000015-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-12,c-64}];
  end_loc:[{r-12,c-79}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000013-000021>];
    1:[<builder/test/access_2d/mesh.cpp:000014-000026>];
    2:[<builder/test/access_2d/mesh.cpp:000016-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-12,c-91}];
  end_loc:[{r-12,c-106}];
  data:[constunsignedc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[chunkRowsCaller];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000013-000048>];
    1:[<builder/test/access_2d/mesh.cpp:000017-000054>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-12,c-123}];
  end_loc:[{r-12,c-138}];
  data:[constunsignedc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[chunkColsCaller];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000013-000032>];
    1:[<builder/test/access_2d/mesh.cpp:000014-000037>];
    2:[<builder/test/access_2d/mesh.cpp:000017-000036>];
    3:[<builder/test/access_2d/mesh.cpp:000017-000071>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-12,c-155}];
  end_loc:[{r-20,c-1}];
  data:[{unsignedstride=nColBlocks*chunkColsCaller*chunkRowsCaller;unsignedlocalStride=nColBlocks*chunkColsCaller;for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*stride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-13,c-3}];
  end_loc:[{r-13,c-63}];
  data:[stride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[stride init (chunkColsCaller*chunkRowsCaller*nColBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-13,c-21}];
  end_loc:[{r-13,c-21}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000013-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-13,c-32}];
  end_loc:[{r-13,c-32}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000013-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-13,c-48}];
  end_loc:[{r-13,c-48}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000091>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000013-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-3}];
  end_loc:[{r-14,c-52}];
  data:[localStride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[localStride init (chunkColsCaller*nColBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-26}];
  end_loc:[{r-14,c-26}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000014-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-37}];
  end_loc:[{r-14,c-37}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000014-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-15,c-3}];
  end_loc:[{r-19,c-3}];
  data:[for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*stride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-15,c-8}];
  end_loc:[{r-15,c-22}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-15,c-21}];
  end_loc:[{r-15,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000015-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-15,c-24}];
  end_loc:[{r-15,c-28}];
  data:[r<nRowBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r lt nRowBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-15,c-28}];
  end_loc:[{r-15,c-28}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000037>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000015-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-15,c-40}];
  end_loc:[{r-15,c-41}];
  data:[r++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-15,c-45}];
  end_loc:[{r-19,c-3}];
  data:[{for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*stride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000012-000155>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-5}];
  end_loc:[{r-18,c-5}];
  data:[for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*stride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mesh.cpp:000015-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-10}];
  end_loc:[{r-16,c-24}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-23}];
  end_loc:[{r-16,c-23}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000016-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-26}];
  end_loc:[{r-16,c-30}];
  data:[c<nColBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c lt nColBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-30}];
  end_loc:[{r-16,c-30}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000016-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-42}];
  end_loc:[{r-16,c-43}];
  data:[c++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-47}];
  end_loc:[{r-18,c-5}];
  data:[{foo(&ptrCaller[r*stride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000015-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-7}];
  end_loc:[{r-17,c-100}];
  data:[foo(&ptrCaller[r*stride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_2d/mesh.cpp:000012-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((chunkColsCaller,chunkRowsCaller,localStride,&ptrCaller[((c*chunkColsCaller)+(r*stride))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-13}];
  end_loc:[{r-17,c-13}];
  data:[ptrCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000018>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptrCaller];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[r];
      ];
      1:[
        pcKind:[var];
        pcContent:[c];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[stride];
      ];
      1:[
        pcKind:[var];
        pcContent:[chunkColsCaller];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-23}];
  end_loc:[{r-17,c-23}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000015-000008>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-25}];
  end_loc:[{r-17,c-25}];
  data:[stride];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000013-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[stride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-34}];
  end_loc:[{r-17,c-34}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000016-000010>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-36}];
  end_loc:[{r-17,c-36}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-54}];
  end_loc:[{r-17,c-54}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000091>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-71}];
  end_loc:[{r-17,c-71}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000012-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-88}];
  end_loc:[{r-17,c-88}];
  data:[localStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  terminal_root:[
    pcKind:[var];
    pcContent:[localStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-22,c-1}];
  end_loc:[{r-29,c-1}];
  data:[voidcaller2_foo(float*ptrCaller,constunsignednRowBlocks,constunsignednColBlocks,constunsignedchunkRowsCaller,constunsignedchunkColsCaller){unsignedlocalStride=nColBlocks*chunkColsCaller;for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*localStride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}}];
  obj:[fun_def];

  name:[caller2_foo];
  args:[
    0:[<builder/test/access_2d/mesh.cpp:000022-000018>];
    1:[<builder/test/access_2d/mesh.cpp:000022-000037>];
    2:[<builder/test/access_2d/mesh.cpp:000022-000064>];
    3:[<builder/test/access_2d/mesh.cpp:000022-000091>];
    4:[<builder/test/access_2d/mesh.cpp:000022-000123>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mesh.cpp:000026-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mesh.cpp:000022-000001>];
    appId:[caller2_foo];
    appImpl:[caller2_foo];
    returnType:[task::coro::dispatcher<app::impl::caller2_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-22,c-18}];
  end_loc:[{r-22,c-26}];
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
    0:[<builder/test/access_2d/mesh.cpp:000026-000013>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[localStride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(chunkRowsCaller+(chunkRowsCaller*nRowBlocks)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(chunkColsCaller+(chunkColsCaller*nColBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRowBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnColBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-22,c-37}];
  end_loc:[{r-22,c-52}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000024-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-22,c-64}];
  end_loc:[{r-22,c-79}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000023-000026>];
    1:[<builder/test/access_2d/mesh.cpp:000025-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-22,c-91}];
  end_loc:[{r-22,c-106}];
  data:[constunsignedc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[chunkRowsCaller];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000026-000025>];
    1:[<builder/test/access_2d/mesh.cpp:000026-000075>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-22,c-123}];
  end_loc:[{r-22,c-138}];
  data:[constunsignedc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[chunkColsCaller];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000023-000037>];
    1:[<builder/test/access_2d/mesh.cpp:000026-000057>];
    2:[<builder/test/access_2d/mesh.cpp:000026-000092>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-22,c-155}];
  end_loc:[{r-29,c-1}];
  data:[{unsignedlocalStride=nColBlocks*chunkColsCaller;for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*localStride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-23,c-3}];
  end_loc:[{r-23,c-52}];
  data:[localStride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[localStride init (chunkColsCaller*nColBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-23,c-26}];
  end_loc:[{r-23,c-26}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000023-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-23,c-37}];
  end_loc:[{r-23,c-37}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000023-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-24,c-3}];
  end_loc:[{r-28,c-3}];
  data:[for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*localStride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-24,c-8}];
  end_loc:[{r-24,c-22}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-24,c-21}];
  end_loc:[{r-24,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000024-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-24,c-24}];
  end_loc:[{r-24,c-28}];
  data:[r<nRowBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r lt nRowBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-24,c-28}];
  end_loc:[{r-24,c-28}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000037>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000024-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-24,c-40}];
  end_loc:[{r-24,c-41}];
  data:[r++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-24,c-45}];
  end_loc:[{r-28,c-3}];
  data:[{for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*localStride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000022-000155>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-5}];
  end_loc:[{r-27,c-5}];
  data:[for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*localStride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mesh.cpp:000024-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-10}];
  end_loc:[{r-25,c-24}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-23}];
  end_loc:[{r-25,c-23}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000025-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-26}];
  end_loc:[{r-25,c-30}];
  data:[c<nColBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c lt nColBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-30}];
  end_loc:[{r-25,c-30}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000025-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-42}];
  end_loc:[{r-25,c-43}];
  data:[c++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-47}];
  end_loc:[{r-27,c-5}];
  data:[{foo(&ptrCaller[r*chunkRowsCaller*localStride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000024-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-7}];
  end_loc:[{r-26,c-121}];
  data:[foo(&ptrCaller[r*chunkRowsCaller*localStride+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,localStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_2d/mesh.cpp:000022-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((chunkColsCaller,chunkRowsCaller,localStride,&ptrCaller[((c*chunkColsCaller)+(chunkRowsCaller*localStride*r))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-13}];
  end_loc:[{r-26,c-13}];
  data:[ptrCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000018>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptrCaller];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[r];
      ];
      1:[
        pcKind:[var];
        pcContent:[c];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(chunkRowsCaller*localStride)];
      ];
      1:[
        pcKind:[var];
        pcContent:[chunkColsCaller];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-23}];
  end_loc:[{r-26,c-23}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000024-000008>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-25}];
  end_loc:[{r-26,c-25}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000091>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-41}];
  end_loc:[{r-26,c-41}];
  data:[localStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[localStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-55}];
  end_loc:[{r-26,c-55}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000025-000010>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-57}];
  end_loc:[{r-26,c-57}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-75}];
  end_loc:[{r-26,c-75}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000091>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-92}];
  end_loc:[{r-26,c-92}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000022-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-26,c-109}];
  end_loc:[{r-26,c-109}];
  data:[localStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  terminal_root:[
    pcKind:[var];
    pcContent:[localStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-1}];
  end_loc:[{r-37,c-1}];
  data:[voidcaller3_foo(float*ptrCaller,constunsignednRowBlocks,constunsignednColBlocks,constunsignedchunkRowsCaller,constunsignedchunkColsCaller){for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nColBlocks*chunkColsCaller);}}}];
  obj:[fun_def];

  name:[caller3_foo];
  args:[
    0:[<builder/test/access_2d/mesh.cpp:000031-000018>];
    1:[<builder/test/access_2d/mesh.cpp:000031-000037>];
    2:[<builder/test/access_2d/mesh.cpp:000031-000064>];
    3:[<builder/test/access_2d/mesh.cpp:000031-000091>];
    4:[<builder/test/access_2d/mesh.cpp:000031-000123>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mesh.cpp:000034-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mesh.cpp:000031-000001>];
    appId:[caller3_foo];
    appImpl:[caller3_foo];
    returnType:[task::coro::dispatcher<app::impl::caller3_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-18}];
  end_loc:[{r-31,c-26}];
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
    0:[<builder/test/access_2d/mesh.cpp:000034-000013>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[factors];
        pcContent:[(chunkColsCaller*nColBlocks)];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(chunkRowsCaller+(chunkRowsCaller*nRowBlocks)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(chunkColsCaller+(chunkColsCaller*nColBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRowBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnColBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-37}];
  end_loc:[{r-31,c-52}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000032-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-64}];
  end_loc:[{r-31,c-79}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000033-000030>];
    1:[<builder/test/access_2d/mesh.cpp:000034-000041>];
    2:[<builder/test/access_2d/mesh.cpp:000034-000124>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-91}];
  end_loc:[{r-31,c-106}];
  data:[constunsignedc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[chunkRowsCaller];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000034-000025>];
    1:[<builder/test/access_2d/mesh.cpp:000034-000090>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-123}];
  end_loc:[{r-31,c-138}];
  data:[constunsignedc];
  obj:[data_decl];

  declKind:[fargument];
  varName:[chunkColsCaller];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000034-000052>];
    1:[<builder/test/access_2d/mesh.cpp:000034-000072>];
    2:[<builder/test/access_2d/mesh.cpp:000034-000107>];
    3:[<builder/test/access_2d/mesh.cpp:000034-000135>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-155}];
  end_loc:[{r-37,c-1}];
  data:[{for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nColBlocks*chunkColsCaller);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-3}];
  end_loc:[{r-36,c-3}];
  data:[for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nColBlocks*chunkColsCaller);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-8}];
  end_loc:[{r-32,c-22}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-21}];
  end_loc:[{r-32,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000032-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-24}];
  end_loc:[{r-32,c-28}];
  data:[r<nRowBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r lt nRowBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-28}];
  end_loc:[{r-32,c-28}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000037>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000032-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-40}];
  end_loc:[{r-32,c-41}];
  data:[r++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-45}];
  end_loc:[{r-36,c-3}];
  data:[{for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nColBlocks*chunkColsCaller);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000031-000155>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-5}];
  end_loc:[{r-35,c-5}];
  data:[for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nColBlocks*chunkColsCaller);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mesh.cpp:000032-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-10}];
  end_loc:[{r-33,c-24}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-23}];
  end_loc:[{r-33,c-23}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000033-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-26}];
  end_loc:[{r-33,c-30}];
  data:[c<nColBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c lt nColBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-30}];
  end_loc:[{r-33,c-30}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000033-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-42}];
  end_loc:[{r-33,c-43}];
  data:[c++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-47}];
  end_loc:[{r-35,c-5}];
  data:[{foo(&ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nColBlocks*chunkColsCaller);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000032-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-7}];
  end_loc:[{r-34,c-151}];
  data:[foo(&ptrCaller[r*chunkRowsCaller*nColBlocks*chunkColsCaller+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nColBlocks*chunkColsCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_2d/mesh.cpp:000031-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((chunkColsCaller,chunkRowsCaller,&ptrCaller[((c*chunkColsCaller)+(chunkColsCaller*chunkRowsCaller*nColBlocks*r))],(chunkColsCaller*nColBlocks)))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-13}];
  end_loc:[{r-34,c-13}];
  data:[ptrCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000018>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptrCaller];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[r];
      ];
      1:[
        pcKind:[var];
        pcContent:[c];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(chunkColsCaller*chunkRowsCaller*nColBlocks)];
      ];
      1:[
        pcKind:[var];
        pcContent:[chunkColsCaller];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-23}];
  end_loc:[{r-34,c-23}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000032-000008>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-25}];
  end_loc:[{r-34,c-25}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000091>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-41}];
  end_loc:[{r-34,c-41}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-52}];
  end_loc:[{r-34,c-52}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-70}];
  end_loc:[{r-34,c-70}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000033-000010>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-72}];
  end_loc:[{r-34,c-72}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-90}];
  end_loc:[{r-34,c-90}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000091>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-107}];
  end_loc:[{r-34,c-107}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-124}];
  end_loc:[{r-34,c-124}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000064>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-34,c-135}];
  end_loc:[{r-34,c-135}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000031-000123>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-1}];
  end_loc:[{r-47,c-1}];
  data:[voidcaller4_foo(float*ptrCaller,constunsignednRows,constunsignednCols,constunsignednRowBlocks,constunsignednColBlocks){unsignedchunkRowsCaller=nRows/nRowBlocks;unsignedchunkColsCaller=nCols/nColBlocks;for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nCols+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nCols);}}}];
  obj:[fun_def];

  name:[caller4_foo];
  args:[
    0:[<builder/test/access_2d/mesh.cpp:000039-000018>];
    1:[<builder/test/access_2d/mesh.cpp:000039-000037>];
    2:[<builder/test/access_2d/mesh.cpp:000039-000059>];
    3:[<builder/test/access_2d/mesh.cpp:000039-000081>];
    4:[<builder/test/access_2d/mesh.cpp:000039-000108>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mesh.cpp:000044-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mesh.cpp:000039-000001>];
    appId:[caller4_foo];
    appImpl:[caller4_foo];
    returnType:[task::coro::dispatcher<app::impl::caller4_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-18}];
  end_loc:[{r-39,c-26}];
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
    0:[<builder/test/access_2d/mesh.cpp:000044-000013>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[nCols];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(chunkRowsCaller+(chunkRowsCaller*nRowBlocks)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(chunkColsCaller+(chunkColsCaller*nColBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRowBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnColBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-37}];
  end_loc:[{r-39,c-52}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000040-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-59}];
  end_loc:[{r-39,c-74}];
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
    0:[<builder/test/access_2d/mesh.cpp:000041-000030>];
    1:[<builder/test/access_2d/mesh.cpp:000044-000041>];
    2:[<builder/test/access_2d/mesh.cpp:000044-000103>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-81}];
  end_loc:[{r-39,c-96}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000040-000038>];
    1:[<builder/test/access_2d/mesh.cpp:000042-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-108}];
  end_loc:[{r-39,c-123}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000041-000038>];
    1:[<builder/test/access_2d/mesh.cpp:000043-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-135}];
  end_loc:[{r-47,c-1}];
  data:[{unsignedchunkRowsCaller=nRows/nRowBlocks;unsignedchunkColsCaller=nCols/nColBlocks;for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nCols+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nCols);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-40,c-3}];
  end_loc:[{r-40,c-48}];
  data:[chunkRowsCaller];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[chunkRowsCaller init (nRows/nRowBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-40,c-30}];
  end_loc:[{r-40,c-30}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000037>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000040-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-40,c-38}];
  end_loc:[{r-40,c-38}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000081>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000040-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-41,c-3}];
  end_loc:[{r-41,c-48}];
  data:[chunkColsCaller];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[chunkColsCaller init (nCols/nColBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-41,c-30}];
  end_loc:[{r-41,c-30}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000059>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000041-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-41,c-38}];
  end_loc:[{r-41,c-38}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000108>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000041-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-3}];
  end_loc:[{r-46,c-3}];
  data:[for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nCols+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nCols);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-8}];
  end_loc:[{r-42,c-22}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-21}];
  end_loc:[{r-42,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000042-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-24}];
  end_loc:[{r-42,c-28}];
  data:[r<nRowBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r lt nRowBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-28}];
  end_loc:[{r-42,c-28}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000081>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000042-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-40}];
  end_loc:[{r-42,c-41}];
  data:[r++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-45}];
  end_loc:[{r-46,c-3}];
  data:[{for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nCols+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nCols);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000039-000135>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-43,c-5}];
  end_loc:[{r-45,c-5}];
  data:[for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*chunkRowsCaller*nCols+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nCols);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mesh.cpp:000042-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-43,c-10}];
  end_loc:[{r-43,c-24}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-43,c-23}];
  end_loc:[{r-43,c-23}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000043-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-43,c-26}];
  end_loc:[{r-43,c-30}];
  data:[c<nColBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c lt nColBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-43,c-30}];
  end_loc:[{r-43,c-30}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000108>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000043-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-43,c-42}];
  end_loc:[{r-43,c-43}];
  data:[c++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-43,c-47}];
  end_loc:[{r-45,c-5}];
  data:[{foo(&ptrCaller[r*chunkRowsCaller*nCols+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nCols);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000042-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-7}];
  end_loc:[{r-44,c-109}];
  data:[foo(&ptrCaller[r*chunkRowsCaller*nCols+c*chunkColsCaller],chunkRowsCaller,chunkColsCaller,nCols)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_2d/mesh.cpp:000039-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((chunkColsCaller,chunkRowsCaller,nCols,&ptrCaller[((c*chunkColsCaller)+(chunkRowsCaller*nCols*r))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-13}];
  end_loc:[{r-44,c-13}];
  data:[ptrCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000018>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptrCaller];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[r];
      ];
      1:[
        pcKind:[var];
        pcContent:[c];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(chunkRowsCaller*nCols)];
      ];
      1:[
        pcKind:[var];
        pcContent:[chunkColsCaller];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-23}];
  end_loc:[{r-44,c-23}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000042-000008>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-25}];
  end_loc:[{r-44,c-25}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-41}];
  end_loc:[{r-44,c-41}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000059>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-49}];
  end_loc:[{r-44,c-49}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000043-000010>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-51}];
  end_loc:[{r-44,c-51}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000041-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-69}];
  end_loc:[{r-44,c-69}];
  data:[chunkRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-86}];
  end_loc:[{r-44,c-86}];
  data:[chunkColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000041-000003>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[chunkColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-103}];
  end_loc:[{r-44,c-103}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000039-000059>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-49,c-1}];
  end_loc:[{r-55,c-1}];
  data:[voidcaller5_foo(float*ptrCaller,constunsignednRows,constunsignednCols,constunsignednRowBlocks,constunsignednColBlocks){for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*(nRows/nRowBlocks)*nCols+c*(nCols/nColBlocks)],(nRows/nRowBlocks),(nCols/nColBlocks),nCols);}}}];
  obj:[fun_def];

  name:[caller5_foo];
  args:[
    0:[<builder/test/access_2d/mesh.cpp:000049-000018>];
    1:[<builder/test/access_2d/mesh.cpp:000049-000037>];
    2:[<builder/test/access_2d/mesh.cpp:000049-000059>];
    3:[<builder/test/access_2d/mesh.cpp:000049-000081>];
    4:[<builder/test/access_2d/mesh.cpp:000049-000108>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mesh.cpp:000052-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mesh.cpp:000049-000001>];
    appId:[caller5_foo];
    appImpl:[caller5_foo];
    returnType:[task::coro::dispatcher<app::impl::caller5_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-49,c-18}];
  end_loc:[{r-49,c-26}];
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
    0:[<builder/test/access_2d/mesh.cpp:000052-000013>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[nCols];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min(0/nRowBlocks); Max((nRows/nRowBlocks)+((nRowBlocks*nRows)/nRowBlocks)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min(0/nColBlocks); Max((nCols/nColBlocks)+((nColBlocks*nCols)/nColBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRowBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnColBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-49,c-37}];
  end_loc:[{r-49,c-52}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000052-000026>];
    1:[<builder/test/access_2d/mesh.cpp:000052-000076>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-49,c-59}];
  end_loc:[{r-49,c-74}];
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
    0:[<builder/test/access_2d/mesh.cpp:000052-000044>];
    1:[<builder/test/access_2d/mesh.cpp:000052-000055>];
    2:[<builder/test/access_2d/mesh.cpp:000052-000096>];
    3:[<builder/test/access_2d/mesh.cpp:000052-000115>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-49,c-81}];
  end_loc:[{r-49,c-96}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000050-000028>];
    1:[<builder/test/access_2d/mesh.cpp:000052-000032>];
    2:[<builder/test/access_2d/mesh.cpp:000052-000082>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-49,c-108}];
  end_loc:[{r-49,c-123}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColBlocks];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mesh.cpp:000051-000030>];
    1:[<builder/test/access_2d/mesh.cpp:000052-000061>];
    2:[<builder/test/access_2d/mesh.cpp:000052-000102>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-49,c-135}];
  end_loc:[{r-55,c-1}];
  data:[{for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*(nRows/nRowBlocks)*nCols+c*(nCols/nColBlocks)],(nRows/nRowBlocks),(nCols/nColBlocks),nCols);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-50,c-3}];
  end_loc:[{r-54,c-3}];
  data:[for(unsignedr=0;r<nRowBlocks;r++){for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*(nRows/nRowBlocks)*nCols+c*(nCols/nColBlocks)],(nRows/nRowBlocks),(nCols/nColBlocks),nCols);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-50,c-8}];
  end_loc:[{r-50,c-22}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-50,c-21}];
  end_loc:[{r-50,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000050-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-50,c-24}];
  end_loc:[{r-50,c-28}];
  data:[r<nRowBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r lt nRowBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-50,c-28}];
  end_loc:[{r-50,c-28}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000081>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000050-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-50,c-40}];
  end_loc:[{r-50,c-41}];
  data:[r++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-50,c-45}];
  end_loc:[{r-54,c-3}];
  data:[{for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*(nRows/nRowBlocks)*nCols+c*(nCols/nColBlocks)],(nRows/nRowBlocks),(nCols/nColBlocks),nCols);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000049-000135>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-51,c-5}];
  end_loc:[{r-53,c-5}];
  data:[for(unsignedc=0;c<nColBlocks;c++){foo(&ptrCaller[r*(nRows/nRowBlocks)*nCols+c*(nCols/nColBlocks)],(nRows/nRowBlocks),(nCols/nColBlocks),nCols);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mesh.cpp:000050-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-51,c-10}];
  end_loc:[{r-51,c-24}];
  data:[c];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-51,c-23}];
  end_loc:[{r-51,c-23}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000051-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-51,c-26}];
  end_loc:[{r-51,c-30}];
  data:[c<nColBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c lt nColBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-51,c-30}];
  end_loc:[{r-51,c-30}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000108>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000051-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-51,c-42}];
  end_loc:[{r-51,c-43}];
  data:[c++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[c incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-51,c-47}];
  end_loc:[{r-53,c-5}];
  data:[{foo(&ptrCaller[r*(nRows/nRowBlocks)*nCols+c*(nCols/nColBlocks)],(nRows/nRowBlocks),(nCols/nColBlocks),nCols);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mesh.cpp:000050-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-7}];
  end_loc:[{r-52,c-121}];
  data:[foo(&ptrCaller[r*(nRows/nRowBlocks)*nCols+c*(nCols/nColBlocks)],(nRows/nRowBlocks),(nCols/nColBlocks),nCols)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_2d/mesh.cpp:000049-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((nCols,(nCols/nColBlocks),(nRows/nRowBlocks),&ptrCaller[((c*(nCols/nColBlocks))+(nCols*r*(nRows/nRowBlocks)))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-13}];
  end_loc:[{r-52,c-13}];
  data:[ptrCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000018>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptrCaller];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[r];
      ];
      1:[
        pcKind:[var];
        pcContent:[c];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[fraction];
        pcContent:[((nCols*nRows)/nRowBlocks)];
      ];
      1:[
        pcKind:[fraction];
        pcContent:[(nCols/nColBlocks)];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-23}];
  end_loc:[{r-52,c-23}];
  data:[r];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000050-000008>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[r];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-26}];
  end_loc:[{r-52,c-26}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000037>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-32}];
  end_loc:[{r-52,c-32}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000081>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-44}];
  end_loc:[{r-52,c-44}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000059>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-52}];
  end_loc:[{r-52,c-52}];
  data:[c];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000051-000010>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[c];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-55}];
  end_loc:[{r-52,c-55}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000059>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-61}];
  end_loc:[{r-52,c-61}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000108>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-76}];
  end_loc:[{r-52,c-76}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000037>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-82}];
  end_loc:[{r-52,c-82}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000081>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-96}];
  end_loc:[{r-52,c-96}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000059>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-102}];
  end_loc:[{r-52,c-102}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000108>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-52,c-115}];
  end_loc:[{r-52,c-115}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mesh.cpp:000049-000059>];
  callee_or_op:[<builder/test/access_2d/mesh.cpp:000003-000067>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];
*/