steel_builder_test_suite
block.cpp
/*

  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-4,c-1}];
  end_loc:[{r-13,c-1}];
  data:[voidfoo_block(constfloat*bbb,intnCols,intnRows,intnDepth){floatr;for(intslice=0;slice<nDepth;slice++){for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols+slice*nCols*nRows];}}}}];
  obj:[fun_def];

  name:[foo_block];
  args:[
    0:[<builder/test/access_3d/block.cpp:000004-000016>];
    1:[<builder/test/access_3d/block.cpp:000004-000035>];
    2:[<builder/test/access_3d/block.cpp:000004-000046>];
    3:[<builder/test/access_3d/block.cpp:000004-000057>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_3d/block.cpp:000018-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_3d/block.cpp:000004-000001>];
    appId:[foo_block_app];
    appImpl:[foo_block];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-4,c-16}];
  end_loc:[{r-4,c-30}];
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
    0:[<builder/test/access_3d/block.cpp:000009-000013>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[factors];
        pcContent:[(nCols*nRows)];
      ];
      1:[
        pcKind:[var];
        pcContent:[nCols];
      ];
      2:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnDepth ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnRows ]];
      ];
      2:[
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
      2:[
        pcKind:[range];
        pcContent:[range[ Min; Max ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-4,c-35}];
  end_loc:[{r-4,c-39}];
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
    0:[<builder/test/access_3d/block.cpp:000008-000031>];
    1:[<builder/test/access_3d/block.cpp:000009-000027>];
    2:[<builder/test/access_3d/block.cpp:000009-000041>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-4,c-46}];
  end_loc:[{r-4,c-50}];
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
    0:[<builder/test/access_3d/block.cpp:000007-000029>];
    1:[<builder/test/access_3d/block.cpp:000009-000047>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-4,c-57}];
  end_loc:[{r-4,c-61}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nDepth];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/block.cpp:000006-000031>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-4,c-69}];
  end_loc:[{r-13,c-1}];
  data:[{floatr;for(intslice=0;slice<nDepth;slice++){for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols+slice*nCols*nRows];}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-10}];
  data:[r];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r init_default no-rhs];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-12,c-3}];
  data:[for(intslice=0;slice<nDepth;slice++){for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols+slice*nCols*nRows];}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-6,c-8}];
  end_loc:[{r-6,c-21}];
  data:[slice];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[slice init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-6,c-20}];
  end_loc:[{r-6,c-20}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/block.cpp:000006-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-6,c-23}];
  end_loc:[{r-6,c-31}];
  data:[slice<nDepth];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[slice lt nDepth];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-6,c-31}];
  end_loc:[{r-6,c-31}];
  data:[nDepth];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000004-000057>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000006-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nDepth];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-6,c-39}];
  end_loc:[{r-6,c-44}];
  data:[slice++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[slice incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-6,c-48}];
  end_loc:[{r-12,c-3}];
  data:[{for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols+slice*nCols*nRows];}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/block.cpp:000004-000069>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-7,c-5}];
  end_loc:[{r-11,c-5}];
  data:[for(introw=0;row<nRows;row++){for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols+slice*nCols*nRows];}}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/block.cpp:000006-000003>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-7,c-10}];
  end_loc:[{r-7,c-21}];
  data:[row];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-7,c-20}];
  end_loc:[{r-7,c-20}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/block.cpp:000007-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-7,c-23}];
  end_loc:[{r-7,c-29}];
  data:[row<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row lt nRows];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-7,c-29}];
  end_loc:[{r-7,c-29}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000004-000046>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-7,c-36}];
  end_loc:[{r-7,c-39}];
  data:[row++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[row incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-7,c-43}];
  end_loc:[{r-11,c-5}];
  data:[{for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols+slice*nCols*nRows];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/block.cpp:000006-000048>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-8,c-7}];
  end_loc:[{r-10,c-7}];
  data:[for(intcol=0;col<nCols;col++){r=bbb[col+row*nCols+slice*nCols*nRows];}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/block.cpp:000007-000005>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-8,c-12}];
  end_loc:[{r-8,c-23}];
  data:[col];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-8,c-22}];
  end_loc:[{r-8,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/block.cpp:000008-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-8,c-25}];
  end_loc:[{r-8,c-31}];
  data:[col<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col lt nCols];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-8,c-31}];
  end_loc:[{r-8,c-31}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000004-000035>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000008-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-8,c-38}];
  end_loc:[{r-8,c-41}];
  data:[col++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[col incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-8,c-45}];
  end_loc:[{r-10,c-7}];
  data:[{r=bbb[col+row*nCols+slice*nCols*nRows];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/block.cpp:000007-000043>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-9}];
  end_loc:[{r-9,c-52}];
  data:[r=bbb[col+row*nCols+slice*nCols*nRows]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[r assign bbb[(col+(nCols*row)+(nCols*nRows*slice))]];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-13}];
  end_loc:[{r-9,c-13}];
  data:[bbb];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000004-000016>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000009-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bbb];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[slice];
      ];
      1:[
        pcKind:[var];
        pcContent:[row];
      ];
      2:[
        pcKind:[var];
        pcContent:[col];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(nCols*nRows)];
      ];
      1:[
        pcKind:[var];
        pcContent:[nCols];
      ];
      2:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-17}];
  end_loc:[{r-9,c-17}];
  data:[col];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000008-000012>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000009-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[col];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-23}];
  end_loc:[{r-9,c-23}];
  data:[row];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000007-000010>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000009-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[row];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-27}];
  end_loc:[{r-9,c-27}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000004-000035>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000009-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-35}];
  end_loc:[{r-9,c-35}];
  data:[slice];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000009-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[slice];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-41}];
  end_loc:[{r-9,c-41}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000004-000035>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000009-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-9,c-47}];
  end_loc:[{r-9,c-47}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000004-000046>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000009-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-15,c-1}];
  end_loc:[{r-19,c-1}];
  data:[voidcaller_block(intnColsCaller,intnRowsCaller,intnDepthCaller){float*ppp;foo_block(ppp,nColsCaller,nRowsCaller,nDepthCaller);}];
  obj:[fun_def];

  name:[caller_block];
  args:[
    0:[<builder/test/access_3d/block.cpp:000015-000019>];
    1:[<builder/test/access_3d/block.cpp:000015-000036>];
    2:[<builder/test/access_3d/block.cpp:000015-000053>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_3d/block.cpp:000018-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_3d/block.cpp:000015-000001>];
    appId:[caller_block];
    appImpl:[caller_block];
    returnType:[task::coro::dispatcher<app::impl::caller_block>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-15,c-19}];
  end_loc:[{r-15,c-23}];
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
    0:[<builder/test/access_3d/block.cpp:000018-000018>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-15,c-36}];
  end_loc:[{r-15,c-40}];
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
    0:[<builder/test/access_3d/block.cpp:000018-000031>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-15,c-53}];
  end_loc:[{r-15,c-57}];
  data:[intn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nDepthCaller];
  typeName:[int];
  translationType:[int];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/block.cpp:000018-000044>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-15,c-71}];
  end_loc:[{r-19,c-1}];
  data:[{float*ppp;foo_block(ppp,nColsCaller,nRowsCaller,nDepthCaller);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-16,c-3}];
  end_loc:[{r-16,c-14}];
  data:[ppp];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ppp init_default no-rhs];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-18,c-3}];
  end_loc:[{r-18,c-56}];
  data:[foo_block(ppp,nColsCaller,nRowsCaller,nDepthCaller)];
  obj:[fun_call];

  callee:[<builder/test/access_3d/block.cpp:000004-000001>];
  caller:[<builder/test/access_3d/block.cpp:000015-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo_block((nColsCaller,nDepthCaller,nRowsCaller,ppp))];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-18,c-13}];
  end_loc:[{r-18,c-13}];
  data:[ppp];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000016-000003>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000004-000016>];
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


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-18,c-18}];
  end_loc:[{r-18,c-18}];
  data:[nColsCaller];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000015-000019>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000004-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-18,c-31}];
  end_loc:[{r-18,c-31}];
  data:[nRowsCaller];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000015-000036>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000004-000046>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowsCaller];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[block.cpp];
  begin_loc:[{r-18,c-44}];
  end_loc:[{r-18,c-44}];
  data:[nDepthCaller];
  obj:[data_use];

  root:[<builder/test/access_3d/block.cpp:000015-000053>];
  callee_or_op:[<builder/test/access_3d/block.cpp:000004-000057>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nDepthCaller];
  ];
  memAccess:[NULL];
*/