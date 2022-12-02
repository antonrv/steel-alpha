steel_builder_test_suite
mat_vec_product.cpp
/*

  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-12,c-1}];
  data:[voidmat_vec_v1(float*vecRes,floatconst*inputMat,floatconst*inputVec,unsignednCols,unsignednRows,unsignedstride){for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){vecRes[ii]+=inputMat[jj*stride+ii]*inputVec[ii];}}}];
  obj:[fun_def];

  name:[mat_vec_v1];
  args:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000004-000003>];
    1:[<builder/test/access_2d/mat_vec_product.cpp:000004-000019>];
    2:[<builder/test/access_2d/mat_vec_product.cpp:000004-000043>];
    3:[<builder/test/access_2d/mat_vec_product.cpp:000005-000003>];
    4:[<builder/test/access_2d/mat_vec_product.cpp:000005-000019>];
    5:[<builder/test/access_2d/mat_vec_product.cpp:000005-000035>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000029-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_vec_product.cpp:000003-000001>];
    appId:[mat_vec_app];
    appImpl:[mat_vec_v1];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-4,c-3}];
  end_loc:[{r-4,c-11}];
  data:[float*v];
  obj:[data_decl];

  declKind:[fargument];
  varName:[vecRes];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-4,c-19}];
  end_loc:[{r-4,c-33}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inputMat];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000009-000021>];
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
  file:[mat_vec_product.cpp];
  begin_loc:[{r-4,c-43}];
  end_loc:[{r-4,c-57}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inputVec];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000009-000048>];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-12}];
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
    0:[<builder/test/access_2d/mat_vec_product.cpp:000008-000032>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-5,c-19}];
  end_loc:[{r-5,c-28}];
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
    0:[<builder/test/access_2d/mat_vec_product.cpp:000007-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-5,c-35}];
  end_loc:[{r-5,c-44}];
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
    0:[<builder/test/access_2d/mat_vec_product.cpp:000009-000033>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-6,c-1}];
  end_loc:[{r-12,c-1}];
  data:[{for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){vecRes[ii]+=inputMat[jj*stride+ii]*inputVec[ii];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-7,c-3}];
  end_loc:[{r-11,c-3}];
  data:[for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){vecRes[ii]+=inputMat[jj*stride+ii]*inputVec[ii];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-7,c-8}];
  end_loc:[{r-7,c-23}];
  data:[jj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-7,c-22}];
  end_loc:[{r-7,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000007-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-7,c-25}];
  end_loc:[{r-7,c-30}];
  data:[jj<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-7,c-30}];
  end_loc:[{r-7,c-30}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000005-000019>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000007-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-7,c-37}];
  end_loc:[{r-7,c-39}];
  data:[jj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-7,c-43}];
  end_loc:[{r-11,c-3}];
  data:[{for(unsignedii=0;ii<nCols;ii++){vecRes[ii]+=inputMat[jj*stride+ii]*inputVec[ii];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_vec_product.cpp:000006-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-8,c-5}];
  end_loc:[{r-10,c-5}];
  data:[for(unsignedii=0;ii<nCols;ii++){vecRes[ii]+=inputMat[jj*stride+ii]*inputVec[ii];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_vec_product.cpp:000007-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-8,c-10}];
  end_loc:[{r-8,c-25}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-8,c-24}];
  end_loc:[{r-8,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000008-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-8,c-27}];
  end_loc:[{r-8,c-32}];
  data:[ii<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nCols];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-8,c-32}];
  end_loc:[{r-8,c-32}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000005-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000008-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-8,c-39}];
  end_loc:[{r-8,c-41}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-8,c-45}];
  end_loc:[{r-10,c-5}];
  data:[{vecRes[ii]+=inputMat[jj*stride+ii]*inputVec[ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_vec_product.cpp:000007-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-7}];
  end_loc:[{r-9,c-59}];
  data:[vecRes[ii]+=inputMat[jj*stride+ii]*inputVec[ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[vecRes[ii] incr (inputMat[(ii+(jj*stride))]*inputVec[ii])];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-14}];
  end_loc:[{r-9,c-14}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000008-000010>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-21}];
  end_loc:[{r-9,c-21}];
  data:[inputMat];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000004-000019>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inputMat];
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
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-30}];
  end_loc:[{r-9,c-30}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000007-000008>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-33}];
  end_loc:[{r-9,c-33}];
  data:[stride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000005-000035>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[stride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-42}];
  end_loc:[{r-9,c-42}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000008-000010>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-48}];
  end_loc:[{r-9,c-48}];
  data:[inputVec];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000004-000043>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inputVec];
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


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-9,c-57}];
  end_loc:[{r-9,c-57}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000008-000010>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000009-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-16,c-1}];
  end_loc:[{r-32,c-1}];
  data:[voidmat_vec_v2(float*vecRes,floatconst*inputMat,floatconst*inputVec,unsignednCols,unsignednRows,unsignednColBlocks,unsignednRowBlocks){unsignedcolBlockSize=nCols/nColBlocks;unsignedrowBlockSize=nRows/nRowBlocks;unsignedstride=nColBlocks*colBlockSize*rowBlockSize;unsignedlocalStride=colBlockSize*nColBlocks;for(unsignedjj=0;jj<nRowBlocks;jj++){for(unsignedii=0;ii<nColBlocks;ii++){mat_vec_v1(&vecRes[ii*colBlockSize],&inputMat[jj*stride+ii*colBlockSize],&inputVec[ii*colBlockSize],colBlockSize,rowBlockSize,localStride);}}}];
  obj:[fun_def];

  name:[mat_vec_v2];
  args:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000017-000003>];
    1:[<builder/test/access_2d/mat_vec_product.cpp:000017-000019>];
    2:[<builder/test/access_2d/mat_vec_product.cpp:000017-000043>];
    3:[<builder/test/access_2d/mat_vec_product.cpp:000018-000003>];
    4:[<builder/test/access_2d/mat_vec_product.cpp:000018-000019>];
    5:[<builder/test/access_2d/mat_vec_product.cpp:000019-000003>];
    6:[<builder/test/access_2d/mat_vec_product.cpp:000019-000024>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000029-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_vec_product.cpp:000016-000001>];
    appId:[mat_vec_app];
    appImpl:[mat_vec_v2];
    returnType:[task::coro::dispatcher<app::impl::mat_vec_v2>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-17,c-3}];
  end_loc:[{r-17,c-11}];
  data:[float*v];
  obj:[data_decl];

  declKind:[fargument];
  varName:[vecRes];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000029-000020>];
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
        pcContent:[range[ Min0; Max(colBlockSize+(colBlockSize*nColBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnColBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-17,c-19}];
  end_loc:[{r-17,c-33}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inputMat];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000029-000046>];
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
        pcContent:[range[ Min(0/localStride); Max(rowBlockSize+((nRowBlocks*stride)/localStride)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(colBlockSize+(colBlockSize*nColBlocks)) ]];
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
  file:[mat_vec_product.cpp];
  begin_loc:[{r-17,c-43}];
  end_loc:[{r-17,c-57}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inputVec];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000029-000086>];
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
        pcContent:[range[ Min0; Max(colBlockSize+(colBlockSize*nColBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnColBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-18,c-3}];
  end_loc:[{r-18,c-12}];
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
    0:[<builder/test/access_2d/mat_vec_product.cpp:000022-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-18,c-19}];
  end_loc:[{r-18,c-28}];
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
    0:[<builder/test/access_2d/mat_vec_product.cpp:000023-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-19,c-3}];
  end_loc:[{r-19,c-12}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nColBlocks];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000022-000035>];
    1:[<builder/test/access_2d/mat_vec_product.cpp:000024-000021>];
    2:[<builder/test/access_2d/mat_vec_product.cpp:000025-000041>];
    3:[<builder/test/access_2d/mat_vec_product.cpp:000028-000032>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-19,c-24}];
  end_loc:[{r-19,c-33}];
  data:[unsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nRowBlocks];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_vec_product.cpp:000023-000035>];
    1:[<builder/test/access_2d/mat_vec_product.cpp:000027-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-20,c-1}];
  end_loc:[{r-32,c-1}];
  data:[{unsignedcolBlockSize=nCols/nColBlocks;unsignedrowBlockSize=nRows/nRowBlocks;unsignedstride=nColBlocks*colBlockSize*rowBlockSize;unsignedlocalStride=colBlockSize*nColBlocks;for(unsignedjj=0;jj<nRowBlocks;jj++){for(unsignedii=0;ii<nColBlocks;ii++){mat_vec_v1(&vecRes[ii*colBlockSize],&inputMat[jj*stride+ii*colBlockSize],&inputVec[ii*colBlockSize],colBlockSize,rowBlockSize,localStride);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-22,c-3}];
  end_loc:[{r-22,c-45}];
  data:[colBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[colBlockSize init (nCols/nColBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-22,c-27}];
  end_loc:[{r-22,c-27}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000018-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-22,c-35}];
  end_loc:[{r-22,c-35}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000019-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-23,c-3}];
  end_loc:[{r-23,c-45}];
  data:[rowBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[rowBlockSize init (nRows/nRowBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-23,c-27}];
  end_loc:[{r-23,c-27}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000018-000019>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000023-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-23,c-35}];
  end_loc:[{r-23,c-35}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000019-000024>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000023-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-24,c-3}];
  end_loc:[{r-24,c-61}];
  data:[stride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[stride init (colBlockSize*nColBlocks*rowBlockSize)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-24,c-21}];
  end_loc:[{r-24,c-21}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000019-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000024-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-24,c-34}];
  end_loc:[{r-24,c-34}];
  data:[colBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000024-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[colBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-24,c-49}];
  end_loc:[{r-24,c-49}];
  data:[rowBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000024-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[rowBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-25,c-3}];
  end_loc:[{r-25,c-51}];
  data:[localStride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[localStride init (colBlockSize*nColBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-25,c-26}];
  end_loc:[{r-25,c-26}];
  data:[colBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000025-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[colBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-25,c-41}];
  end_loc:[{r-25,c-41}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000019-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000025-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-31,c-3}];
  data:[for(unsignedjj=0;jj<nRowBlocks;jj++){for(unsignedii=0;ii<nColBlocks;ii++){mat_vec_v1(&vecRes[ii*colBlockSize],&inputMat[jj*stride+ii*colBlockSize],&inputVec[ii*colBlockSize],colBlockSize,rowBlockSize,localStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-27,c-8}];
  end_loc:[{r-27,c-23}];
  data:[jj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-27,c-22}];
  end_loc:[{r-27,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000027-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-27,c-25}];
  end_loc:[{r-27,c-30}];
  data:[jj<nRowBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj lt nRowBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-27,c-30}];
  end_loc:[{r-27,c-30}];
  data:[nRowBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000019-000024>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000027-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRowBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-27,c-42}];
  end_loc:[{r-27,c-44}];
  data:[jj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-27,c-48}];
  end_loc:[{r-31,c-3}];
  data:[{for(unsignedii=0;ii<nColBlocks;ii++){mat_vec_v1(&vecRes[ii*colBlockSize],&inputMat[jj*stride+ii*colBlockSize],&inputVec[ii*colBlockSize],colBlockSize,rowBlockSize,localStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_vec_product.cpp:000020-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-28,c-5}];
  end_loc:[{r-30,c-5}];
  data:[for(unsignedii=0;ii<nColBlocks;ii++){mat_vec_v1(&vecRes[ii*colBlockSize],&inputMat[jj*stride+ii*colBlockSize],&inputVec[ii*colBlockSize],colBlockSize,rowBlockSize,localStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_vec_product.cpp:000027-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-28,c-10}];
  end_loc:[{r-28,c-25}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-28,c-24}];
  end_loc:[{r-28,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000028-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-28,c-27}];
  end_loc:[{r-28,c-32}];
  data:[ii<nColBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nColBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-28,c-32}];
  end_loc:[{r-28,c-32}];
  data:[nColBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000019-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000028-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nColBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-28,c-44}];
  end_loc:[{r-28,c-46}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-28,c-50}];
  end_loc:[{r-30,c-5}];
  data:[{mat_vec_v1(&vecRes[ii*colBlockSize],&inputMat[jj*stride+ii*colBlockSize],&inputVec[ii*colBlockSize],colBlockSize,rowBlockSize,localStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_vec_product.cpp:000027-000048>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-7}];
  end_loc:[{r-29,c-153}];
  data:[mat_vec_v1(&vecRes[ii*colBlockSize],&inputMat[jj*stride+ii*colBlockSize],&inputVec[ii*colBlockSize],colBlockSize,rowBlockSize,localStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_vec_product.cpp:000003-000001>];
  caller:[<builder/test/access_2d/mat_vec_product.cpp:000016-000001>];
  own:[
    pcKind:[call];
    pcContent:[mat_vec_v1((colBlockSize,localStride,rowBlockSize,&inputMat[((colBlockSize*ii)+(jj*stride))],&inputVec[(colBlockSize*ii)],&vecRes[(colBlockSize*ii)]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-20}];
  end_loc:[{r-29,c-20}];
  data:[vecRes];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000017-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[vecRes];
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
        pcKind:[var];
        pcContent:[colBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-27}];
  end_loc:[{r-29,c-27}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000028-000010>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-30}];
  end_loc:[{r-29,c-30}];
  data:[colBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[colBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-46}];
  end_loc:[{r-29,c-46}];
  data:[inputMat];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000017-000019>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inputMat];
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
        pcKind:[var];
        pcContent:[colBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-55}];
  end_loc:[{r-29,c-55}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000027-000008>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-58}];
  end_loc:[{r-29,c-58}];
  data:[stride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000024-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[stride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-67}];
  end_loc:[{r-29,c-67}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000028-000010>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-70}];
  end_loc:[{r-29,c-70}];
  data:[colBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[colBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-86}];
  end_loc:[{r-29,c-86}];
  data:[inputVec];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000017-000043>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inputVec];
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
        pcKind:[var];
        pcContent:[colBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-95}];
  end_loc:[{r-29,c-95}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000028-000010>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-98}];
  end_loc:[{r-29,c-98}];
  data:[colBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000004-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[colBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-113}];
  end_loc:[{r-29,c-113}];
  data:[colBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[colBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-127}];
  end_loc:[{r-29,c-127}];
  data:[rowBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000005-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[rowBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_vec_product.cpp];
  begin_loc:[{r-29,c-141}];
  end_loc:[{r-29,c-141}];
  data:[localStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_vec_product.cpp:000025-000003>];
  callee_or_op:[<builder/test/access_2d/mat_vec_product.cpp:000005-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[localStride];
  ];
  memAccess:[NULL];
*/