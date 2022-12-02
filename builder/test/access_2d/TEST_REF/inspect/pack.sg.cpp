steel_builder_test_suite
pack.cpp
/*

  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-6,c-1}];
  end_loc:[{r-15,c-1}];
  data:[voidpack_matrix(float*packMatrix,floatconst*unpackMatrix,unsignednRows,unsignednCols,unsignedstride){for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}}];
  obj:[fun_def];

  name:[pack_matrix];
  args:[
    0:[<builder/test/access_2d/pack.cpp:000007-000003>];
    1:[<builder/test/access_2d/pack.cpp:000007-000023>];
    2:[<builder/test/access_2d/pack.cpp:000008-000003>];
    3:[<builder/test/access_2d/pack.cpp:000008-000019>];
    4:[<builder/test/access_2d/pack.cpp:000008-000035>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/pack.cpp:000053-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/pack.cpp:000006-000001>];
    appId:[matrix_pack];
    appImpl:[pack_matrix];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-7,c-3}];
  end_loc:[{r-7,c-11}];
  data:[float*p];
  obj:[data_decl];

  declKind:[fargument];
  varName:[packMatrix];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000012-000007>];
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
  file:[pack.cpp];
  begin_loc:[{r-7,c-23}];
  end_loc:[{r-7,c-37}];
  data:[floatconst*u];
  obj:[data_decl];

  declKind:[fargument];
  varName:[unpackMatrix];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000012-000035>];
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
  file:[pack.cpp];
  begin_loc:[{r-8,c-3}];
  end_loc:[{r-8,c-12}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000010-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-8,c-19}];
  end_loc:[{r-8,c-28}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCols];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000011-000032>];
    1:[<builder/test/access_2d/pack.cpp:000012-000021>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-8,c-35}];
  end_loc:[{r-8,c-44}];
  data:[unsigneds];
  obj:[data_decl];

  declKind:[fargument];
  varName:[stride];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000012-000051>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-9,c-1}];
  end_loc:[{r-15,c-1}];
  data:[{for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-10,c-3}];
  end_loc:[{r-14,c-3}];
  data:[for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-10,c-8}];
  end_loc:[{r-10,c-23}];
  data:[jj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-10,c-22}];
  end_loc:[{r-10,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000010-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-10,c-25}];
  end_loc:[{r-10,c-30}];
  data:[jj<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-10,c-30}];
  end_loc:[{r-10,c-30}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000008-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000010-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-10,c-37}];
  end_loc:[{r-10,c-39}];
  data:[jj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-10,c-43}];
  end_loc:[{r-14,c-3}];
  data:[{for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000009-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-11,c-5}];
  end_loc:[{r-13,c-5}];
  data:[for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/pack.cpp:000010-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-11,c-10}];
  end_loc:[{r-11,c-25}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-11,c-24}];
  end_loc:[{r-11,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000011-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-11,c-27}];
  end_loc:[{r-11,c-32}];
  data:[ii<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nCols];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-11,c-32}];
  end_loc:[{r-11,c-32}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000008-000019>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000011-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-11,c-39}];
  end_loc:[{r-11,c-41}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-11,c-45}];
  end_loc:[{r-13,c-5}];
  data:[{packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000010-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-7}];
  end_loc:[{r-12,c-62}];
  data:[packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[packMatrix[(ii+(jj*nCols))] assign unpackMatrix[(ii+(jj*stride))]];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-18}];
  end_loc:[{r-12,c-18}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000010-000008>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000012-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-21}];
  end_loc:[{r-12,c-21}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000008-000019>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000012-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-29}];
  end_loc:[{r-12,c-29}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000011-000010>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000012-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-35}];
  end_loc:[{r-12,c-35}];
  data:[unpackMatrix];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000007-000023>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000012-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[unpackMatrix];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[jj];
      ];
      1:[
        pcKind:[var];
        pcContent:[ii];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[stride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-48}];
  end_loc:[{r-12,c-48}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000010-000008>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000012-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-51}];
  end_loc:[{r-12,c-51}];
  data:[stride];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000008-000035>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000012-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[stride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-12,c-60}];
  end_loc:[{r-12,c-60}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000011-000010>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000012-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-18,c-1}];
  end_loc:[{r-21,c-1}];
  data:[voidallocate_matrix(float*&packMatrix,unsignednRows,unsignednCols){packMatrix=static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));//packMatrix=(float*)std::malloc(nRows*nCols*sizeof(float));HANDLEwithpck::undefinedTODO}];
  obj:[fun_def];

  name:[allocate_matrix];
  args:[
    0:[<builder/test/access_2d/pack.cpp:000018-000022>];
    1:[<builder/test/access_2d/pack.cpp:000018-000043>];
    2:[<builder/test/access_2d/pack.cpp:000018-000059>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/pack.cpp:000046-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/pack.cpp:000018-000001>];
    appId:[matrix_allocate];
    appImpl:[allocate_matrix];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-18,c-22}];
  end_loc:[{r-18,c-31}];
  data:[float*&p];
  obj:[data_decl];

  declKind:[fargument];
  varName:[packMatrix];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000019-000003>];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-18,c-43}];
  end_loc:[{r-18,c-52}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRows];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-18,c-59}];
  end_loc:[{r-18,c-68}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nCols];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-18,c-75}];
  end_loc:[{r-21,c-1}];
  data:[{packMatrix=static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));//packMatrix=(float*)std::malloc(nRows*nCols*sizeof(float));HANDLEwithpck::undefinedTODO}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-19,c-3}];
  end_loc:[{r-19,c-74}];
  data:[packMatrix=static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)))];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[packMatrix assign static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-24,c-1}];
  end_loc:[{r-26,c-1}];
  data:[voiddeallocate_matrix(float*&packMatrix){std::free(packMatrix);}];
  obj:[fun_def];

  name:[deallocate_matrix];
  args:[
    0:[<builder/test/access_2d/pack.cpp:000024-000024>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/pack.cpp:000059-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/pack.cpp:000024-000001>];
    appId:[matrix_deallocate];
    appImpl:[deallocate_matrix];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-24,c-24}];
  end_loc:[{r-24,c-33}];
  data:[float*&p];
  obj:[data_decl];

  declKind:[fargument];
  varName:[packMatrix];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-24,c-45}];
  end_loc:[{r-26,c-1}];
  data:[{std::free(packMatrix);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-29,c-1}];
  end_loc:[{r-63,c-1}];
  data:[voidpack_matrix_caller(floatconst*outMat,unsignedmSize,unsignednSize,unsignedmBlocks,unsignednBlocks){std::vector<float*>outCompact;outCompact.resize(mBlocks*nBlocks);float**outCompactPtr=outCompact.data();unsignedmBlockSize=mSize/mBlocks;unsignednBlockSize=nSize/nBlocks;unsignedoutStride=nBlockSize*nBlocks;for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}//Strided->compactfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}}];
  obj:[fun_def];

  name:[pack_matrix_caller];
  args:[
    0:[<builder/test/access_2d/pack.cpp:000030-000003>];
    1:[<builder/test/access_2d/pack.cpp:000031-000003>];
    2:[<builder/test/access_2d/pack.cpp:000031-000019>];
    3:[<builder/test/access_2d/pack.cpp:000032-000003>];
    4:[<builder/test/access_2d/pack.cpp:000032-000021>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/pack.cpp:000046-000007>];
    1:[<builder/test/access_2d/pack.cpp:000053-000007>];
    2:[<builder/test/access_2d/pack.cpp:000059-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/pack.cpp:000029-000001>];
    appId:[pack_matrix_caller];
    appImpl:[pack_matrix_caller];
    returnType:[task::coro::dispatcher<app::impl::pack_matrix_caller>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-30,c-3}];
  end_loc:[{r-30,c-17}];
  data:[floatconst*o];
  obj:[data_decl];

  declKind:[fargument];
  varName:[outMat];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000053-000055>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[outStride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(mBlockSize+(mBlockSize*mBlocks)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(nBlockSize+(nBlockSize*nBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxmBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-31,c-3}];
  end_loc:[{r-31,c-12}];
  data:[unsignedm];
  obj:[data_decl];

  declKind:[fargument];
  varName:[mSize];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000039-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-31,c-19}];
  end_loc:[{r-31,c-28}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nSize];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000040-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-32,c-3}];
  end_loc:[{r-32,c-12}];
  data:[unsignedm];
  obj:[data_decl];

  declKind:[fargument];
  varName:[mBlocks];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000039-000033>];
    1:[<builder/test/access_2d/pack.cpp:000044-000030>];
    2:[<builder/test/access_2d/pack.cpp:000051-000030>];
    3:[<builder/test/access_2d/pack.cpp:000057-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-32,c-21}];
  end_loc:[{r-32,c-30}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlocks];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/pack.cpp:000040-000033>];
    1:[<builder/test/access_2d/pack.cpp:000042-000035>];
    2:[<builder/test/access_2d/pack.cpp:000045-000032>];
    3:[<builder/test/access_2d/pack.cpp:000046-000042>];
    4:[<builder/test/access_2d/pack.cpp:000052-000032>];
    5:[<builder/test/access_2d/pack.cpp:000053-000038>];
    6:[<builder/test/access_2d/pack.cpp:000058-000032>];
    7:[<builder/test/access_2d/pack.cpp:000059-000044>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-33,c-1}];
  end_loc:[{r-63,c-1}];
  data:[{std::vector<float*>outCompact;outCompact.resize(mBlocks*nBlocks);float**outCompactPtr=outCompact.data();unsignedmBlockSize=mSize/mBlocks;unsignednBlockSize=nSize/nBlocks;unsignedoutStride=nBlockSize*nBlocks;for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}//Strided->compactfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-35,c-3}];
  end_loc:[{r-35,c-33}];
  data:[outCompact];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outCompact init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-37,c-3}];
  end_loc:[{r-37,c-45}];
  data:[outCompactPtr];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outCompactPtr init outCompact(no-rhs)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-39,c-3}];
  end_loc:[{r-39,c-40}];
  data:[mBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mBlockSize init (mSize/mBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-39,c-25}];
  end_loc:[{r-39,c-25}];
  data:[mSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000031-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000039-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-39,c-33}];
  end_loc:[{r-39,c-33}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000039-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-40,c-3}];
  end_loc:[{r-40,c-40}];
  data:[nBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nBlockSize init (nSize/nBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-40,c-25}];
  end_loc:[{r-40,c-25}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000031-000019>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000040-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-40,c-33}];
  end_loc:[{r-40,c-33}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000040-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-42,c-3}];
  end_loc:[{r-42,c-42}];
  data:[outStride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outStride init (nBlockSize*nBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-42,c-24}];
  end_loc:[{r-42,c-24}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000042-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-42,c-35}];
  end_loc:[{r-42,c-35}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000042-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-44,c-3}];
  end_loc:[{r-48,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-44,c-8}];
  end_loc:[{r-44,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-44,c-22}];
  end_loc:[{r-44,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000044-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-44,c-25}];
  end_loc:[{r-44,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-44,c-30}];
  end_loc:[{r-44,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000044-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-44,c-39}];
  end_loc:[{r-44,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-44,c-45}];
  end_loc:[{r-48,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000033-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-45,c-5}];
  end_loc:[{r-47,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/pack.cpp:000044-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-45,c-10}];
  end_loc:[{r-45,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-45,c-24}];
  end_loc:[{r-45,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000045-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-45,c-27}];
  end_loc:[{r-45,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-45,c-32}];
  end_loc:[{r-45,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000045-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-45,c-41}];
  end_loc:[{r-45,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-45,c-47}];
  end_loc:[{r-47,c-5}];
  data:[{allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000044-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-46,c-7}];
  end_loc:[{r-46,c-81}];
  data:[allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/pack.cpp:000018-000001>];
  caller:[<builder/test/access_2d/pack.cpp:000029-000001>];
  own:[
    pcKind:[call];
    pcContent:[allocate_matrix((mBlockSize,nBlockSize,outCompactPtr[(nb+(mb*nBlocks))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-46,c-24}];
  end_loc:[{r-46,c-24}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000037-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000018-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outCompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[nb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[nBlocks];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-46,c-39}];
  end_loc:[{r-46,c-39}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000044-000008>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000018-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-46,c-42}];
  end_loc:[{r-46,c-42}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000018-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-46,c-52}];
  end_loc:[{r-46,c-52}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000045-000010>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000018-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-46,c-58}];
  end_loc:[{r-46,c-58}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000039-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000018-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-46,c-70}];
  end_loc:[{r-46,c-70}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000018-000059>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-51,c-3}];
  end_loc:[{r-55,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-51,c-8}];
  end_loc:[{r-51,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-51,c-22}];
  end_loc:[{r-51,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000051-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-51,c-25}];
  end_loc:[{r-51,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-51,c-30}];
  end_loc:[{r-51,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000051-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-51,c-39}];
  end_loc:[{r-51,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-51,c-45}];
  end_loc:[{r-55,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000033-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-52,c-5}];
  end_loc:[{r-54,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/pack.cpp:000051-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-52,c-10}];
  end_loc:[{r-52,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-52,c-24}];
  end_loc:[{r-52,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000052-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-52,c-27}];
  end_loc:[{r-52,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-52,c-32}];
  end_loc:[{r-52,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000052-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-52,c-41}];
  end_loc:[{r-52,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-52,c-47}];
  end_loc:[{r-54,c-5}];
  data:[{pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000051-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-7}];
  end_loc:[{r-53,c-138}];
  data:[pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/pack.cpp:000006-000001>];
  caller:[<builder/test/access_2d/pack.cpp:000029-000001>];
  own:[
    pcKind:[call];
    pcContent:[pack_matrix((mBlockSize,nBlockSize,outStride,outCompactPtr[(nb+(mb*nBlocks))],&outMat[((nBlockSize*nb)+(mBlockSize*mb*outStride))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-20}];
  end_loc:[{r-53,c-20}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000037-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outCompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[nb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[nBlocks];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-35}];
  end_loc:[{r-53,c-35}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000051-000008>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-38}];
  end_loc:[{r-53,c-38}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-48}];
  end_loc:[{r-53,c-48}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000052-000010>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-55}];
  end_loc:[{r-53,c-55}];
  data:[outMat];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000030-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outMat];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[nb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(mBlockSize*outStride)];
      ];
      1:[
        pcKind:[var];
        pcContent:[nBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-62}];
  end_loc:[{r-53,c-62}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000051-000008>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-65}];
  end_loc:[{r-53,c-65}];
  data:[outStride];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000042-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-75}];
  end_loc:[{r-53,c-75}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000039-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-88}];
  end_loc:[{r-53,c-88}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000052-000010>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-91}];
  end_loc:[{r-53,c-91}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-104}];
  end_loc:[{r-53,c-104}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000039-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000008-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-116}];
  end_loc:[{r-53,c-116}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000040-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000008-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-53,c-128}];
  end_loc:[{r-53,c-128}];
  data:[outStride];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000042-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000008-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-57,c-3}];
  end_loc:[{r-61,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-57,c-8}];
  end_loc:[{r-57,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-57,c-22}];
  end_loc:[{r-57,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000057-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-57,c-25}];
  end_loc:[{r-57,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-57,c-30}];
  end_loc:[{r-57,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000057-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-57,c-39}];
  end_loc:[{r-57,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-57,c-45}];
  end_loc:[{r-61,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000033-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-58,c-5}];
  end_loc:[{r-60,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/pack.cpp:000057-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-58,c-10}];
  end_loc:[{r-58,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-58,c-24}];
  end_loc:[{r-58,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000058-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-58,c-27}];
  end_loc:[{r-58,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-58,c-32}];
  end_loc:[{r-58,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000058-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-58,c-41}];
  end_loc:[{r-58,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-58,c-47}];
  end_loc:[{r-60,c-5}];
  data:[{deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/pack.cpp:000057-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-59,c-7}];
  end_loc:[{r-59,c-59}];
  data:[deallocate_matrix(outCompactPtr[mb*nBlocks+nb])];
  obj:[fun_call];

  callee:[<builder/test/access_2d/pack.cpp:000024-000001>];
  caller:[<builder/test/access_2d/pack.cpp:000029-000001>];
  own:[
    pcKind:[call];
    pcContent:[deallocate_matrix(outCompactPtr[(nb+(mb*nBlocks))])];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-59,c-26}];
  end_loc:[{r-59,c-26}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000037-000003>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000024-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outCompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[nb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[nBlocks];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-59,c-41}];
  end_loc:[{r-59,c-41}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000057-000008>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000024-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-59,c-44}];
  end_loc:[{r-59,c-44}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000032-000021>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000024-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[pack.cpp];
  begin_loc:[{r-59,c-54}];
  end_loc:[{r-59,c-54}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/pack.cpp:000058-000010>];
  callee_or_op:[<builder/test/access_2d/pack.cpp:000024-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];
*/