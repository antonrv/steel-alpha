steel_builder_test_suite
shapes.cpp
/*

  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-4,c-1}];
  end_loc:[{r-11,c-1}];
  data:[voidfoo_rectangle(constfloat*bbb,intnCols,intnRows){floatr=13.f;for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols];}}}];
  obj:[fun_def];

  name:[foo_rectangle];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000004-000020>];
    1:[<builder/test/access_2d/shapes.cpp:000004-000039>];
    2:[<builder/test/access_2d/shapes.cpp:000004-000050>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000016-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000004-000001>];
    appId:[foo_rectangle_app];
    appImpl:[foo_rectangle];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-4,c-20}];
  end_loc:[{r-4,c-34}];
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
    0:[<builder/test/access_2d/shapes.cpp:000008-000011>];
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
  file:[shapes.cpp];
  begin_loc:[{r-4,c-39}];
  end_loc:[{r-4,c-43}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCols];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000007-000029>];
    1:[<builder/test/access_2d/shapes.cpp:000008-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-4,c-50}];
  end_loc:[{r-4,c-54}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000006-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-4,c-61}];
  end_loc:[{r-11,c-1}];
  data:[{floatr=13.f;for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-17}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 13];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-5,c-13}];
  end_loc:[{r-5,c-13}];
  data:[13.f];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000005-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-10,c-3}];
  data:[for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-6,c-8}];
  end_loc:[{r-6,c-19}];
  data:[row];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-6,c-18}];
  end_loc:[{r-6,c-18}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000006-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-6,c-21}];
  end_loc:[{r-6,c-27}];
  data:[row<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-6,c-27}];
  end_loc:[{r-6,c-27}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000004-000050>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000006-000021>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-6,c-34}];
  end_loc:[{r-6,c-37}];
  data:[row++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-6,c-41}];
  end_loc:[{r-10,c-3}];
  data:[{for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000004-000061>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-7,c-5}];
  end_loc:[{r-9,c-5}];
  data:[for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/shapes.cpp:000006-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-7,c-10}];
  end_loc:[{r-7,c-21}];
  data:[col];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-7,c-20}];
  end_loc:[{r-7,c-20}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000007-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-7,c-23}];
  end_loc:[{r-7,c-29}];
  data:[col<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col lt nCols];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-7,c-29}];
  end_loc:[{r-7,c-29}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000004-000039>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-7,c-36}];
  end_loc:[{r-7,c-39}];
  data:[col++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-7,c-43}];
  end_loc:[{r-9,c-5}];
  data:[{r=bbb[col+row*nCols];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000006-000041>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-8,c-7}];
  end_loc:[{r-8,c-30}];
  data:[r=bbb[col+row*nCols]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[(col+(nCols*row))]];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-8,c-11}];
  end_loc:[{r-8,c-11}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000004-000020>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000008-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[row];
      ];
      1:[
        pcKind:[var];
        pcContent:[col];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[nCols];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-8,c-15}];
  end_loc:[{r-8,c-15}];
  data:[col];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000007-000010>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000008-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[col];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-8,c-21}];
  end_loc:[{r-8,c-21}];
  data:[row];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000008-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[row];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-8,c-25}];
  end_loc:[{r-8,c-25}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000004-000039>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000008-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-13,c-1}];
  end_loc:[{r-17,c-1}];
  data:[voidcaller_rectangle(intnColsCaller,intnRowsCaller){float*ppp;foo_rectangle(ppp,nColsCaller,nRowsCaller);}];
  obj:[fun_def];

  name:[caller_rectangle];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000013-000023>];
    1:[<builder/test/access_2d/shapes.cpp:000013-000040>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000016-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000013-000001>];
    appId:[caller_rectangle];
    appImpl:[caller_rectangle];
    returnType:[task::coro::dispatcher<app::impl::caller_rectangle>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-13,c-23}];
  end_loc:[{r-13,c-27}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColsCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000016-000022>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-13,c-40}];
  end_loc:[{r-13,c-44}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowsCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000016-000035>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-13,c-57}];
  end_loc:[{r-17,c-1}];
  data:[{float*ppp;foo_rectangle(ppp,nColsCaller,nRowsCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-14,c-3}];
  end_loc:[{r-14,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-16,c-3}];
  end_loc:[{r-16,c-46}];
  data:[foo_rectangle(ppp,nColsCaller,nRowsCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/shapes.cpp:000004-000001>];
  caller:[<builder/test/access_2d/shapes.cpp:000013-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_rectangle((nColsCaller,nRowsCaller,ppp))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-16,c-17}];
  end_loc:[{r-16,c-17}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000014-000003>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000004-000020>];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-16,c-22}];
  end_loc:[{r-16,c-22}];
  data:[nColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000013-000023>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000004-000039>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-16,c-35}];
  end_loc:[{r-16,c-35}];
  data:[nRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000013-000040>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000004-000050>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-21,c-1}];
  end_loc:[{r-28,c-1}];
  data:[voidfoo_blocks(constfloat*bbb,intbSize,intnBlocks){floatr=13.f;for(intbId=0;bId<nBlocks;bId++){for(inti=bId*bSize;i<bSize;i++){r=bbb[i+bId*bSize];}}}];
  obj:[fun_def];

  name:[foo_blocks];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000021-000017>];
    1:[<builder/test/access_2d/shapes.cpp:000021-000036>];
    2:[<builder/test/access_2d/shapes.cpp:000021-000047>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000033-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000021-000001>];
    appId:[foo_1d_blocks_app];
    appImpl:[foo_blocks];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-21,c-17}];
  end_loc:[{r-21,c-31}];
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
    0:[<builder/test/access_2d/shapes.cpp:000025-000011>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[bSize];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxbSize ]];
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
  file:[shapes.cpp];
  begin_loc:[{r-21,c-36}];
  end_loc:[{r-21,c-40}];
  data:[intb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSize];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000024-000022>];
    1:[<builder/test/access_2d/shapes.cpp:000024-000033>];
    2:[<builder/test/access_2d/shapes.cpp:000025-000023>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-21,c-47}];
  end_loc:[{r-21,c-51}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlocks];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000023-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-21,c-60}];
  end_loc:[{r-28,c-1}];
  data:[{floatr=13.f;for(intbId=0;bId<nBlocks;bId++){for(inti=bId*bSize;i<bSize;i++){r=bbb[i+bId*bSize];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-22,c-3}];
  end_loc:[{r-22,c-17}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 13];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-22,c-13}];
  end_loc:[{r-22,c-13}];
  data:[13.f];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000022-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-23,c-3}];
  end_loc:[{r-27,c-3}];
  data:[for(intbId=0;bId<nBlocks;bId++){for(inti=bId*bSize;i<bSize;i++){r=bbb[i+bId*bSize];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-23,c-8}];
  end_loc:[{r-23,c-19}];
  data:[bId];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bId init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-23,c-18}];
  end_loc:[{r-23,c-18}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000023-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-23,c-21}];
  end_loc:[{r-23,c-27}];
  data:[bId<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bId lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-23,c-27}];
  end_loc:[{r-23,c-27}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000021-000047>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000023-000021>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-23,c-36}];
  end_loc:[{r-23,c-39}];
  data:[bId++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bId incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-23,c-43}];
  end_loc:[{r-27,c-3}];
  data:[{for(inti=bId*bSize;i<bSize;i++){r=bbb[i+bId*bSize];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000021-000060>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-5}];
  end_loc:[{r-26,c-5}];
  data:[for(inti=bId*bSize;i<bSize;i++){r=bbb[i+bId*bSize];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/shapes.cpp:000023-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-10}];
  end_loc:[{r-24,c-27}];
  data:[i];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i init (bId*bSize)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-18}];
  end_loc:[{r-24,c-18}];
  data:[bId];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000023-000008>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000024-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bId];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-22}];
  end_loc:[{r-24,c-22}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000021-000036>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000024-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-29}];
  end_loc:[{r-24,c-33}];
  data:[i<bSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i lt bSize];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-33}];
  end_loc:[{r-24,c-33}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000021-000036>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000024-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-40}];
  end_loc:[{r-24,c-41}];
  data:[i++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-24,c-45}];
  end_loc:[{r-26,c-5}];
  data:[{r=bbb[i+bId*bSize];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000023-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-25,c-7}];
  end_loc:[{r-25,c-28}];
  data:[r=bbb[i+bId*bSize]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[(i+(bId*bSize))]];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-25,c-11}];
  end_loc:[{r-25,c-11}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000021-000017>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000025-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[bId];
      ];
      1:[
        pcKind:[var];
        pcContent:[i];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[bSize];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-25,c-15}];
  end_loc:[{r-25,c-15}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000024-000010>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000025-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-25,c-19}];
  end_loc:[{r-25,c-19}];
  data:[bId];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000023-000008>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000025-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bId];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-25,c-23}];
  end_loc:[{r-25,c-23}];
  data:[bSize];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000021-000036>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000025-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-30,c-1}];
  end_loc:[{r-34,c-1}];
  data:[voidcaller_blocks(intbSizeCaller,intnBlocksCaller){float*ppp;foo_blocks(ppp,bSizeCaller,nBlocksCaller);}];
  obj:[fun_def];

  name:[caller_blocks];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000030-000020>];
    1:[<builder/test/access_2d/shapes.cpp:000030-000037>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000033-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000030-000001>];
    appId:[caller_blocks];
    appImpl:[caller_blocks];
    returnType:[task::coro::dispatcher<app::impl::caller_blocks>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-30,c-20}];
  end_loc:[{r-30,c-24}];
  data:[intb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000033-000019>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-30,c-37}];
  end_loc:[{r-30,c-41}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlocksCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000033-000032>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-30,c-56}];
  end_loc:[{r-34,c-1}];
  data:[{float*ppp;foo_blocks(ppp,bSizeCaller,nBlocksCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-31,c-3}];
  end_loc:[{r-31,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-33,c-3}];
  end_loc:[{r-33,c-45}];
  data:[foo_blocks(ppp,bSizeCaller,nBlocksCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/shapes.cpp:000021-000001>];
  caller:[<builder/test/access_2d/shapes.cpp:000030-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_blocks((bSizeCaller,nBlocksCaller,ppp))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-33,c-14}];
  end_loc:[{r-33,c-14}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000031-000003>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000021-000017>];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-33,c-19}];
  end_loc:[{r-33,c-19}];
  data:[bSizeCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000030-000020>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000021-000036>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-33,c-32}];
  end_loc:[{r-33,c-32}];
  data:[nBlocksCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000030-000037>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000021-000047>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocksCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-38,c-1}];
  end_loc:[{r-45,c-1}];
  data:[voidfoo_low_triangle(constfloat*bbb,intnCols,intnRows){floatr=13.f;for(introw=0;row<nRows;row++){for(intcol=0;col<row;col++){r=bbb[col+row*nCols];}}}];
  obj:[fun_def];

  name:[foo_low_triangle];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000038-000023>];
    1:[<builder/test/access_2d/shapes.cpp:000038-000042>];
    2:[<builder/test/access_2d/shapes.cpp:000038-000053>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000050-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000038-000001>];
    appId:[foo_low_tri_app];
    appImpl:[foo_low_triangle];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-38,c-23}];
  end_loc:[{r-38,c-37}];
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
    0:[<builder/test/access_2d/shapes.cpp:000042-000011>];
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
        pcContent:[range[ Min0; MaxnRows ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRows ]];
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
  file:[shapes.cpp];
  begin_loc:[{r-38,c-42}];
  end_loc:[{r-38,c-46}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCols];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000042-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-38,c-53}];
  end_loc:[{r-38,c-57}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000040-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-38,c-64}];
  end_loc:[{r-45,c-1}];
  data:[{floatr=13.f;for(introw=0;row<nRows;row++){for(intcol=0;col<row;col++){r=bbb[col+row*nCols];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-39,c-3}];
  end_loc:[{r-39,c-17}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 13];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-39,c-13}];
  end_loc:[{r-39,c-13}];
  data:[13.f];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000039-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-40,c-3}];
  end_loc:[{r-44,c-3}];
  data:[for(introw=0;row<nRows;row++){for(intcol=0;col<row;col++){r=bbb[col+row*nCols];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-40,c-8}];
  end_loc:[{r-40,c-19}];
  data:[row];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-40,c-18}];
  end_loc:[{r-40,c-18}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000040-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-40,c-21}];
  end_loc:[{r-40,c-27}];
  data:[row<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-40,c-27}];
  end_loc:[{r-40,c-27}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000038-000053>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000040-000021>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-40,c-34}];
  end_loc:[{r-40,c-37}];
  data:[row++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-40,c-41}];
  end_loc:[{r-44,c-3}];
  data:[{for(intcol=0;col<row;col++){r=bbb[col+row*nCols];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000038-000064>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-41,c-5}];
  end_loc:[{r-43,c-5}];
  data:[for(intcol=0;col<row;col++){r=bbb[col+row*nCols];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/shapes.cpp:000040-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-41,c-10}];
  end_loc:[{r-41,c-21}];
  data:[col];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-41,c-20}];
  end_loc:[{r-41,c-20}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000041-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-41,c-23}];
  end_loc:[{r-41,c-29}];
  data:[col<row];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col lt row];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-41,c-29}];
  end_loc:[{r-41,c-29}];
  data:[row];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000040-000008>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000041-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[row];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-41,c-34}];
  end_loc:[{r-41,c-37}];
  data:[col++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-41,c-41}];
  end_loc:[{r-43,c-5}];
  data:[{r=bbb[col+row*nCols];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000040-000041>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-42,c-7}];
  end_loc:[{r-42,c-30}];
  data:[r=bbb[col+row*nCols]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[(col+(nCols*row))]];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-42,c-11}];
  end_loc:[{r-42,c-11}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000038-000023>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000042-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[row];
      ];
      1:[
        pcKind:[var];
        pcContent:[col];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[nCols];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-42,c-15}];
  end_loc:[{r-42,c-15}];
  data:[col];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000041-000010>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000042-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[col];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-42,c-21}];
  end_loc:[{r-42,c-21}];
  data:[row];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000040-000008>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000042-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[row];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-42,c-25}];
  end_loc:[{r-42,c-25}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000038-000042>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000042-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-47,c-1}];
  end_loc:[{r-51,c-1}];
  data:[voidcaller_low_triangle(intnColsCaller,intnRowsCaller){float*ppp;foo_low_triangle(ppp,nColsCaller,nRowsCaller);}];
  obj:[fun_def];

  name:[caller_low_triangle];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000047-000026>];
    1:[<builder/test/access_2d/shapes.cpp:000047-000043>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000050-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000047-000001>];
    appId:[caller_low_triangle];
    appImpl:[caller_low_triangle];
    returnType:[task::coro::dispatcher<app::impl::caller_low_triangle>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-47,c-26}];
  end_loc:[{r-47,c-30}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColsCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000050-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-47,c-43}];
  end_loc:[{r-47,c-47}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowsCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000050-000038>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-47,c-60}];
  end_loc:[{r-51,c-1}];
  data:[{float*ppp;foo_low_triangle(ppp,nColsCaller,nRowsCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-48,c-3}];
  end_loc:[{r-48,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-50,c-3}];
  end_loc:[{r-50,c-49}];
  data:[foo_low_triangle(ppp,nColsCaller,nRowsCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/shapes.cpp:000038-000001>];
  caller:[<builder/test/access_2d/shapes.cpp:000047-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_low_triangle((nColsCaller,nRowsCaller,ppp))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-50,c-20}];
  end_loc:[{r-50,c-20}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000048-000003>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000038-000023>];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-50,c-25}];
  end_loc:[{r-50,c-25}];
  data:[nColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000047-000026>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000038-000042>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-50,c-38}];
  end_loc:[{r-50,c-38}];
  data:[nRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000047-000043>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000038-000053>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-55,c-1}];
  end_loc:[{r-62,c-1}];
  data:[voidfoo_up_triangle(constfloat*bbb,intnCols,intnRows){floatr=13.f;for(introw=0;row<nRows;row++){for(intcol=row;col<nCols;col++){r=bbb[col+row*nCols];}}}];
  obj:[fun_def];

  name:[foo_up_triangle];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000055-000022>];
    1:[<builder/test/access_2d/shapes.cpp:000055-000041>];
    2:[<builder/test/access_2d/shapes.cpp:000055-000052>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000067-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000055-000001>];
    appId:[foo_up_tri_app];
    appImpl:[foo_up_triangle];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-55,c-22}];
  end_loc:[{r-55,c-36}];
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
    0:[<builder/test/access_2d/shapes.cpp:000059-000011>];
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
  file:[shapes.cpp];
  begin_loc:[{r-55,c-41}];
  end_loc:[{r-55,c-45}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCols];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000058-000031>];
    1:[<builder/test/access_2d/shapes.cpp:000059-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-55,c-52}];
  end_loc:[{r-55,c-56}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000057-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-55,c-63}];
  end_loc:[{r-62,c-1}];
  data:[{floatr=13.f;for(introw=0;row<nRows;row++){for(intcol=row;col<nCols;col++){r=bbb[col+row*nCols];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-56,c-3}];
  end_loc:[{r-56,c-17}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init 13];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-56,c-13}];
  end_loc:[{r-56,c-13}];
  data:[13.f];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000056-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-57,c-3}];
  end_loc:[{r-61,c-3}];
  data:[for(introw=0;row<nRows;row++){for(intcol=row;col<nCols;col++){r=bbb[col+row*nCols];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-57,c-8}];
  end_loc:[{r-57,c-19}];
  data:[row];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-57,c-18}];
  end_loc:[{r-57,c-18}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000057-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-57,c-21}];
  end_loc:[{r-57,c-27}];
  data:[row<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-57,c-27}];
  end_loc:[{r-57,c-27}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000055-000052>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000057-000021>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-57,c-34}];
  end_loc:[{r-57,c-37}];
  data:[row++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-57,c-41}];
  end_loc:[{r-61,c-3}];
  data:[{for(intcol=row;col<nCols;col++){r=bbb[col+row*nCols];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000055-000063>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-58,c-5}];
  end_loc:[{r-60,c-5}];
  data:[for(intcol=row;col<nCols;col++){r=bbb[col+row*nCols];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/shapes.cpp:000057-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-58,c-10}];
  end_loc:[{r-58,c-23}];
  data:[col];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col init row];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-58,c-20}];
  end_loc:[{r-58,c-20}];
  data:[row];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000057-000008>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000058-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[row];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-58,c-25}];
  end_loc:[{r-58,c-31}];
  data:[col<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col lt nCols];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-58,c-31}];
  end_loc:[{r-58,c-31}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000055-000041>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000058-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-58,c-38}];
  end_loc:[{r-58,c-41}];
  data:[col++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-58,c-45}];
  end_loc:[{r-60,c-5}];
  data:[{r=bbb[col+row*nCols];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/shapes.cpp:000057-000041>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-59,c-7}];
  end_loc:[{r-59,c-30}];
  data:[r=bbb[col+row*nCols]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[(col+(nCols*row))]];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-59,c-11}];
  end_loc:[{r-59,c-11}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000055-000022>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000059-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[row];
      ];
      1:[
        pcKind:[var];
        pcContent:[col];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[nCols];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-59,c-15}];
  end_loc:[{r-59,c-15}];
  data:[col];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000058-000010>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000059-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[col];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-59,c-21}];
  end_loc:[{r-59,c-21}];
  data:[row];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000057-000008>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000059-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[row];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-59,c-25}];
  end_loc:[{r-59,c-25}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000055-000041>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000059-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-64,c-1}];
  end_loc:[{r-68,c-1}];
  data:[voidcaller_up_triangle(intnColsCaller,intnRowsCaller){float*ppp;foo_up_triangle(ppp,nColsCaller,nRowsCaller);}];
  obj:[fun_def];

  name:[caller_up_triangle];
  args:[
    0:[<builder/test/access_2d/shapes.cpp:000064-000025>];
    1:[<builder/test/access_2d/shapes.cpp:000064-000042>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/shapes.cpp:000067-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/shapes.cpp:000064-000001>];
    appId:[caller_up_triangle];
    appImpl:[caller_up_triangle];
    returnType:[task::coro::dispatcher<app::impl::caller_up_triangle>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-64,c-25}];
  end_loc:[{r-64,c-29}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColsCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000067-000024>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-64,c-42}];
  end_loc:[{r-64,c-46}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowsCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/shapes.cpp:000067-000037>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-64,c-59}];
  end_loc:[{r-68,c-1}];
  data:[{float*ppp;foo_up_triangle(ppp,nColsCaller,nRowsCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-65,c-3}];
  end_loc:[{r-65,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-67,c-3}];
  end_loc:[{r-67,c-48}];
  data:[foo_up_triangle(ppp,nColsCaller,nRowsCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/shapes.cpp:000055-000001>];
  caller:[<builder/test/access_2d/shapes.cpp:000064-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_up_triangle((nColsCaller,nRowsCaller,ppp))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-67,c-19}];
  end_loc:[{r-67,c-19}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000065-000003>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000055-000022>];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-67,c-24}];
  end_loc:[{r-67,c-24}];
  data:[nColsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000064-000025>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000055-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[shapes.cpp];
  begin_loc:[{r-67,c-37}];
  end_loc:[{r-67,c-37}];
  data:[nRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_2d/shapes.cpp:000064-000042>];
  callee_or_op:[<builder/test/access_2d/shapes.cpp:000055-000052>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowsCaller];
  ];
  memAccess:[NULL];
*/