steel_builder_test_suite
mat_product_blocked.cpp
/*

  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-6,c-1}];
  end_loc:[{r-9,c-1}];
  data:[voidallocate_matrix(float*&packMatrix,unsignednRows,unsignednCols){packMatrix=static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));//packMatrix=(float*)std::malloc(nRows*nCols*sizeof(float));HANDLEwithpck::undefinedTODO}];
  obj:[fun_def];

  name:[allocate_matrix];
  args:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000043>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000059>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000090-000007>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000096-000007>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000102-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000001>];
    appId:[matrix_allocate];
    appImpl:[allocate_matrix];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-6,c-22}];
  end_loc:[{r-6,c-31}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000007-000003>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-6,c-43}];
  end_loc:[{r-6,c-52}];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-6,c-59}];
  end_loc:[{r-6,c-68}];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-6,c-75}];
  end_loc:[{r-9,c-1}];
  data:[{packMatrix=static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));//packMatrix=(float*)std::malloc(nRows*nCols*sizeof(float));HANDLEwithpck::undefinedTODO}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-7,c-3}];
  end_loc:[{r-7,c-74}];
  data:[packMatrix=static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)))];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[packMatrix assign static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-12,c-1}];
  end_loc:[{r-14,c-1}];
  data:[voiddeallocate_matrix(float*packMatrix){std::free(packMatrix);}];
  obj:[fun_def];

  name:[deallocate_matrix];
  args:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000167-000007>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000173-000007>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000179-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000001>];
    appId:[matrix_deallocate];
    appImpl:[deallocate_matrix];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-12,c-24}];
  end_loc:[{r-12,c-32}];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-12,c-44}];
  end_loc:[{r-14,c-1}];
  data:[{std::free(packMatrix);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-17,c-1}];
  end_loc:[{r-28,c-1}];
  data:[voidmat_product_v0_kernel_compact(float*outMat,floatconst*inMatA,floatconst*inMatB,unsignedmSize,unsignednSize,unsignedkSize){for(unsignedmm=0;mm<mSize;mm++){for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}}}}];
  obj:[fun_def];

  name:[mat_product_v0_kernel_compact];
  args:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000003>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000019>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000041>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000003>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000019>];
    5:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000035>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000141-000009>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_blocked.cpp:000017-000001>];
    appId:[mat_product_app];
    appImpl:[mat_product_v0_kernel_compact];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-18,c-3}];
  end_loc:[{r-18,c-11}];
  data:[float*o];
  obj:[data_decl];

  declKind:[fargument];
  varName:[outMat];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[nSize];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxmSize ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnSize ]];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-18,c-19}];
  end_loc:[{r-18,c-33}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inMatA];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000036>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[kSize];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxmSize ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxkSize ]];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-18,c-41}];
  end_loc:[{r-18,c-55}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inMatB];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000062>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[nSize];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxkSize ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnSize ]];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-19,c-3}];
  end_loc:[{r-19,c-12}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000021-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-19,c-19}];
  end_loc:[{r-19,c-28}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000022-000032>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000021>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000074>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-19,c-35}];
  end_loc:[{r-19,c-44}];
  data:[unsignedk];
  obj:[data_decl];

  declKind:[fargument];
  varName:[kSize];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000023-000034>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000048>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-20,c-1}];
  end_loc:[{r-28,c-1}];
  data:[{for(unsignedmm=0;mm<mSize;mm++){for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-21,c-3}];
  end_loc:[{r-27,c-3}];
  data:[for(unsignedmm=0;mm<mSize;mm++){for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-21,c-8}];
  end_loc:[{r-21,c-23}];
  data:[mm];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mm init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-21,c-22}];
  end_loc:[{r-21,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000021-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-21,c-25}];
  end_loc:[{r-21,c-30}];
  data:[mm<mSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mm lt mSize];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-21,c-30}];
  end_loc:[{r-21,c-30}];
  data:[mSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000021-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-21,c-37}];
  end_loc:[{r-21,c-39}];
  data:[mm++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mm incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-21,c-43}];
  end_loc:[{r-27,c-3}];
  data:[{for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000020-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-22,c-5}];
  end_loc:[{r-26,c-5}];
  data:[for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000021-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-22,c-10}];
  end_loc:[{r-22,c-25}];
  data:[nn];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nn init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-22,c-24}];
  end_loc:[{r-22,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000022-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-22,c-27}];
  end_loc:[{r-22,c-32}];
  data:[nn<nSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nn lt nSize];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-22,c-32}];
  end_loc:[{r-22,c-32}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000022-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-22,c-39}];
  end_loc:[{r-22,c-41}];
  data:[nn++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nn incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-22,c-45}];
  end_loc:[{r-26,c-5}];
  data:[{for(unsignedkk=0;kk<kSize;kk++){outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000021-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-23,c-7}];
  end_loc:[{r-25,c-7}];
  data:[for(unsignedkk=0;kk<kSize;kk++){outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000022-000005>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-23,c-12}];
  end_loc:[{r-23,c-27}];
  data:[kk];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-23,c-26}];
  end_loc:[{r-23,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000023-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-23,c-29}];
  end_loc:[{r-23,c-34}];
  data:[kk<kSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk lt kSize];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-23,c-34}];
  end_loc:[{r-23,c-34}];
  data:[kSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000023-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-23,c-41}];
  end_loc:[{r-23,c-43}];
  data:[kk++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-23,c-47}];
  end_loc:[{r-25,c-7}];
  data:[{outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000022-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-9}];
  end_loc:[{r-24,c-84}];
  data:[outMat[mm*nSize+nn]+=inMatA[mm*kSize+kk]*inMatB[kk*nSize+nn]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outMat[(nn+(mm*nSize))] incr (inMatA[(kk+(kSize*mm))]*inMatB[(nn+(kk*nSize))])];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-16}];
  end_loc:[{r-24,c-16}];
  data:[mm];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000021-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mm];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-21}];
  end_loc:[{r-24,c-21}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-29}];
  end_loc:[{r-24,c-29}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000022-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-36}];
  end_loc:[{r-24,c-36}];
  data:[inMatA];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inMatA];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mm];
      ];
      1:[
        pcKind:[var];
        pcContent:[kk];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[kSize];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-43}];
  end_loc:[{r-24,c-43}];
  data:[mm];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000021-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mm];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-48}];
  end_loc:[{r-24,c-48}];
  data:[kSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-56}];
  end_loc:[{r-24,c-56}];
  data:[kk];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000023-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-62}];
  end_loc:[{r-24,c-62}];
  data:[inMatB];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000041>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inMatB];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[kk];
      ];
      1:[
        pcKind:[var];
        pcContent:[nn];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[nSize];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-69}];
  end_loc:[{r-24,c-69}];
  data:[kk];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000023-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-74}];
  end_loc:[{r-24,c-74}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-24,c-82}];
  end_loc:[{r-24,c-82}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000022-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000024-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-32,c-1}];
  end_loc:[{r-41,c-1}];
  data:[voidpack_matrix(float*packMatrix,floatconst*unpackMatrix,unsignednRows,unsignednCols,unsignedstride){for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}}];
  obj:[fun_def];

  name:[pack_matrix];
  args:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000003>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000019>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000035>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000115-000007>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000122-000007>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000129-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_blocked.cpp:000032-000001>];
    appId:[app_pack];
    appImpl:[pack_matrix];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-33,c-3}];
  end_loc:[{r-33,c-11}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-33,c-23}];
  end_loc:[{r-33,c-37}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000035>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-34,c-12}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000036-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-34,c-19}];
  end_loc:[{r-34,c-28}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000037-000032>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000021>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-34,c-35}];
  end_loc:[{r-34,c-44}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000051>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-35,c-1}];
  end_loc:[{r-41,c-1}];
  data:[{for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-36,c-3}];
  end_loc:[{r-40,c-3}];
  data:[for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-36,c-8}];
  end_loc:[{r-36,c-23}];
  data:[jj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-36,c-22}];
  end_loc:[{r-36,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000036-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-36,c-25}];
  end_loc:[{r-36,c-30}];
  data:[jj<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-36,c-30}];
  end_loc:[{r-36,c-30}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000036-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-36,c-37}];
  end_loc:[{r-36,c-39}];
  data:[jj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-36,c-43}];
  end_loc:[{r-40,c-3}];
  data:[{for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000035-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-37,c-5}];
  end_loc:[{r-39,c-5}];
  data:[for(unsignedii=0;ii<nCols;ii++){packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000036-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-37,c-10}];
  end_loc:[{r-37,c-25}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-37,c-24}];
  end_loc:[{r-37,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000037-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-37,c-27}];
  end_loc:[{r-37,c-32}];
  data:[ii<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nCols];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-37,c-32}];
  end_loc:[{r-37,c-32}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000037-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-37,c-39}];
  end_loc:[{r-37,c-41}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-37,c-45}];
  end_loc:[{r-39,c-5}];
  data:[{packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000036-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-7}];
  end_loc:[{r-38,c-62}];
  data:[packMatrix[jj*nCols+ii]=unpackMatrix[jj*stride+ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[packMatrix[(ii+(jj*nCols))] assign unpackMatrix[(ii+(jj*stride))]];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-18}];
  end_loc:[{r-38,c-18}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000036-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-21}];
  end_loc:[{r-38,c-21}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-29}];
  end_loc:[{r-38,c-29}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000037-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-35}];
  end_loc:[{r-38,c-35}];
  data:[unpackMatrix];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-48}];
  end_loc:[{r-38,c-48}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000036-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-51}];
  end_loc:[{r-38,c-51}];
  data:[stride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[stride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-38,c-60}];
  end_loc:[{r-38,c-60}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000037-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000038-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-44,c-1}];
  end_loc:[{r-53,c-1}];
  data:[voidunpack_matrix(float*unpackMatrix,floatconst*packMatrix,unsignednRows,unsignednCols,unsignedstride){for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){unpackMatrix[jj*stride+ii]=packMatrix[jj*nCols+ii];}}}];
  obj:[fun_def];

  name:[unpack_matrix];
  args:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000003>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000025>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000003>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000019>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000035>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000156-000007>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_blocked.cpp:000044-000001>];
    appId:[app_unpack];
    appImpl:[unpack_matrix];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-45,c-3}];
  end_loc:[{r-45,c-11}];
  data:[float*u];
  obj:[data_decl];

  declKind:[fargument];
  varName:[unpackMatrix];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-45,c-25}];
  end_loc:[{r-45,c-39}];
  data:[floatconst*p];
  obj:[data_decl];

  declKind:[fargument];
  varName:[packMatrix];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000038>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-46,c-3}];
  end_loc:[{r-46,c-12}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000048-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-46,c-19}];
  end_loc:[{r-46,c-28}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000049-000032>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000052>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-46,c-35}];
  end_loc:[{r-46,c-44}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000023>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-47,c-1}];
  end_loc:[{r-53,c-1}];
  data:[{for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){unpackMatrix[jj*stride+ii]=packMatrix[jj*nCols+ii];}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-48,c-3}];
  end_loc:[{r-52,c-3}];
  data:[for(unsignedjj=0;jj<nRows;jj++){for(unsignedii=0;ii<nCols;ii++){unpackMatrix[jj*stride+ii]=packMatrix[jj*nCols+ii];}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-48,c-8}];
  end_loc:[{r-48,c-23}];
  data:[jj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-48,c-22}];
  end_loc:[{r-48,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000048-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-48,c-25}];
  end_loc:[{r-48,c-30}];
  data:[jj<nRows];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj lt nRows];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-48,c-30}];
  end_loc:[{r-48,c-30}];
  data:[nRows];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000048-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nRows];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-48,c-37}];
  end_loc:[{r-48,c-39}];
  data:[jj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-48,c-43}];
  end_loc:[{r-52,c-3}];
  data:[{for(unsignedii=0;ii<nCols;ii++){unpackMatrix[jj*stride+ii]=packMatrix[jj*nCols+ii];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000047-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-49,c-5}];
  end_loc:[{r-51,c-5}];
  data:[for(unsignedii=0;ii<nCols;ii++){unpackMatrix[jj*stride+ii]=packMatrix[jj*nCols+ii];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000048-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-49,c-10}];
  end_loc:[{r-49,c-25}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-49,c-24}];
  end_loc:[{r-49,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000049-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-49,c-27}];
  end_loc:[{r-49,c-32}];
  data:[ii<nCols];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nCols];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-49,c-32}];
  end_loc:[{r-49,c-32}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000049-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-49,c-39}];
  end_loc:[{r-49,c-41}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-49,c-45}];
  end_loc:[{r-51,c-5}];
  data:[{unpackMatrix[jj*stride+ii]=packMatrix[jj*nCols+ii];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000048-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-7}];
  end_loc:[{r-50,c-62}];
  data:[unpackMatrix[jj*stride+ii]=packMatrix[jj*nCols+ii]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[unpackMatrix[(ii+(jj*stride))] assign packMatrix[(ii+(jj*nCols))]];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-20}];
  end_loc:[{r-50,c-20}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000048-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-23}];
  end_loc:[{r-50,c-23}];
  data:[stride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[stride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-32}];
  end_loc:[{r-50,c-32}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000049-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-38}];
  end_loc:[{r-50,c-38}];
  data:[packMatrix];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000025>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[packMatrix];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-49}];
  end_loc:[{r-50,c-49}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000048-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-52}];
  end_loc:[{r-50,c-52}];
  data:[nCols];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nCols];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-50,c-60}];
  end_loc:[{r-50,c-60}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000049-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000050-000007>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-57,c-1}];
  end_loc:[{r-182,c-1}];
  data:[voidmat_product_v3_block_compact(float*outMat,floatconst*inMatA,floatconst*inMatB,unsignedmSize,unsignednSize,unsignedkSize,unsignedmBlocks,unsignednBlocks,unsignedkBlocks){std::vector<float*>outCompact;outCompact.resize(mBlocks*nBlocks);float**outCompactPtr=outCompact.data();std::vector<float*>inACompact;inACompact.resize(mBlocks*kBlocks);float**inACompactPtr=inACompact.data();std::vector<float*>inBCompact;inBCompact.resize(kBlocks*nBlocks);float**inBCompactPtr=inBCompact.data();unsignedmBlockSize=mSize/mBlocks;unsignednBlockSize=nSize/nBlocks;unsignedkBlockSize=kSize/kBlocks;unsignedoutStride=nBlockSize*nBlocks;unsignedinAStride=kBlockSize*kBlocks;unsignedinBStride=nBlockSize*nBlocks;////////////////MATRIXALLOCATION//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}for(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){allocate_matrix(inACompactPtr[mb*kBlocks+kb],mBlockSize,kBlockSize);}}for(unsignedkb=0;kb<kBlocks;kb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(inBCompactPtr[kb*nBlocks+nb],kBlockSize,nBlockSize);}}////////////////MATRIXPACKING////////////////OUT:Strided->compactfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}//INA:Strided->compactfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inACompactPtr[mb*kBlocks+kb],&inMatA[mb*inAStride*mBlockSize+kb*kBlockSize],mBlockSize,kBlockSize,inAStride);}}//INB:Strided->compactfor(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inBCompactPtr[kb*nBlocks+nb],&inMatB[kb*inBStride*kBlockSize+nb*nBlockSize],kBlockSize,nBlockSize,inBStride);}}////////////////MATRIXCOMPACTBLOCKPRODUCT//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}}}////////////////MATRIXUNPACKING////////////////OUT:Compact->stridedfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){unpack_matrix(&outMat[mb*outStride*mBlockSize+nb*nBlockSize],outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize,outStride);}}////////////////MATRIXDEALLOCATION//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}for(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){deallocate_matrix(inACompactPtr[mb*kBlocks+kb]);}}for(unsignedkb=0;kb<kBlocks;kb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(inBCompactPtr[kb*nBlocks+nb]);}}}];
  obj:[fun_def];

  name:[mat_product_v3_block_compact];
  args:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000058-000003>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000058-000019>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000058-000041>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000059-000003>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000059-000019>];
    5:[<builder/test/access_2d/mat_product_blocked.cpp:000059-000035>];
    6:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
    7:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
    8:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000090-000007>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000096-000007>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000102-000007>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000115-000007>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000122-000007>];
    5:[<builder/test/access_2d/mat_product_blocked.cpp:000129-000007>];
    6:[<builder/test/access_2d/mat_product_blocked.cpp:000141-000009>];
    7:[<builder/test/access_2d/mat_product_blocked.cpp:000156-000007>];
    8:[<builder/test/access_2d/mat_product_blocked.cpp:000167-000007>];
    9:[<builder/test/access_2d/mat_product_blocked.cpp:000173-000007>];
    10:[<builder/test/access_2d/mat_product_blocked.cpp:000179-000007>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
    appId:[mat_product_app];
    appImpl:[mat_product_v3_block_compact];
    returnType:[task::coro::dispatcher<app::impl::mat_product_v3_block_compact>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-58,c-3}];
  end_loc:[{r-58,c-11}];
  data:[float*o];
  obj:[data_decl];

  declKind:[fargument];
  varName:[outMat];
  typeName:[float];
  translationType:[std::add_pointer_t<float>];
  typeQual:[var];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_write];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000115-000055>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000156-000023>];
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
        pcContent:[range[ Min(0,0); Max((mBlockSize+(mBlockSize*mBlocks)),(mBlockSize+(mBlockSize*mBlocks))) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min(0,0); Max((nBlockSize+(nBlockSize*nBlocks)),(nBlockSize+(nBlockSize*nBlocks))) ]];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-58,c-19}];
  end_loc:[{r-58,c-33}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inMatA];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000122-000055>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[inAStride];
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
        pcContent:[range[ Min0; Max(kBlockSize+(kBlockSize*kBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxmBlocks ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxkBlocks ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-58,c-41}];
  end_loc:[{r-58,c-55}];
  data:[floatconst*i];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inMatB];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000129-000055>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[var];
        pcContent:[inBStride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(kBlockSize+(kBlockSize*kBlocks)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(nBlockSize+(nBlockSize*nBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxkBlocks ]];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-59,c-3}];
  end_loc:[{r-59,c-12}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-59,c-19}];
  end_loc:[{r-59,c-28}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-59,c-35}];
  end_loc:[{r-59,c-44}];
  data:[unsignedk];
  obj:[data_decl];

  declKind:[fargument];
  varName:[kSize];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-60,c-3}];
  end_loc:[{r-60,c-12}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000033>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000088-000030>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000094-000030>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000113-000030>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000120-000030>];
    5:[<builder/test/access_2d/mat_product_blocked.cpp:000138-000030>];
    6:[<builder/test/access_2d/mat_product_blocked.cpp:000154-000030>];
    7:[<builder/test/access_2d/mat_product_blocked.cpp:000165-000030>];
    8:[<builder/test/access_2d/mat_product_blocked.cpp:000171-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-60,c-21}];
  end_loc:[{r-60,c-30}];
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
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000033>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000079-000035>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000081-000035>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000089-000032>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000090-000042>];
    5:[<builder/test/access_2d/mat_product_blocked.cpp:000101-000032>];
    6:[<builder/test/access_2d/mat_product_blocked.cpp:000102-000042>];
    7:[<builder/test/access_2d/mat_product_blocked.cpp:000114-000032>];
    8:[<builder/test/access_2d/mat_product_blocked.cpp:000115-000038>];
    9:[<builder/test/access_2d/mat_product_blocked.cpp:000127-000030>];
    10:[<builder/test/access_2d/mat_product_blocked.cpp:000129-000038>];
    11:[<builder/test/access_2d/mat_product_blocked.cpp:000139-000032>];
    12:[<builder/test/access_2d/mat_product_blocked.cpp:000141-000057>];
    13:[<builder/test/access_2d/mat_product_blocked.cpp:000141-000121>];
    14:[<builder/test/access_2d/mat_product_blocked.cpp:000155-000032>];
    15:[<builder/test/access_2d/mat_product_blocked.cpp:000156-000090>];
    16:[<builder/test/access_2d/mat_product_blocked.cpp:000166-000032>];
    17:[<builder/test/access_2d/mat_product_blocked.cpp:000167-000044>];
    18:[<builder/test/access_2d/mat_product_blocked.cpp:000178-000032>];
    19:[<builder/test/access_2d/mat_product_blocked.cpp:000179-000044>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-60,c-39}];
  end_loc:[{r-60,c-48}];
  data:[unsignedk];
  obj:[data_decl];

  declKind:[fargument];
  varName:[kBlocks];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000033>];
    1:[<builder/test/access_2d/mat_product_blocked.cpp:000080-000035>];
    2:[<builder/test/access_2d/mat_product_blocked.cpp:000095-000032>];
    3:[<builder/test/access_2d/mat_product_blocked.cpp:000096-000042>];
    4:[<builder/test/access_2d/mat_product_blocked.cpp:000100-000030>];
    5:[<builder/test/access_2d/mat_product_blocked.cpp:000121-000032>];
    6:[<builder/test/access_2d/mat_product_blocked.cpp:000122-000038>];
    7:[<builder/test/access_2d/mat_product_blocked.cpp:000128-000032>];
    8:[<builder/test/access_2d/mat_product_blocked.cpp:000140-000034>];
    9:[<builder/test/access_2d/mat_product_blocked.cpp:000141-000089>];
    10:[<builder/test/access_2d/mat_product_blocked.cpp:000172-000032>];
    11:[<builder/test/access_2d/mat_product_blocked.cpp:000173-000044>];
    12:[<builder/test/access_2d/mat_product_blocked.cpp:000177-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-61,c-1}];
  end_loc:[{r-182,c-1}];
  data:[{std::vector<float*>outCompact;outCompact.resize(mBlocks*nBlocks);float**outCompactPtr=outCompact.data();std::vector<float*>inACompact;inACompact.resize(mBlocks*kBlocks);float**inACompactPtr=inACompact.data();std::vector<float*>inBCompact;inBCompact.resize(kBlocks*nBlocks);float**inBCompactPtr=inBCompact.data();unsignedmBlockSize=mSize/mBlocks;unsignednBlockSize=nSize/nBlocks;unsignedkBlockSize=kSize/kBlocks;unsignedoutStride=nBlockSize*nBlocks;unsignedinAStride=kBlockSize*kBlocks;unsignedinBStride=nBlockSize*nBlocks;////////////////MATRIXALLOCATION//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}for(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){allocate_matrix(inACompactPtr[mb*kBlocks+kb],mBlockSize,kBlockSize);}}for(unsignedkb=0;kb<kBlocks;kb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(inBCompactPtr[kb*nBlocks+nb],kBlockSize,nBlockSize);}}////////////////MATRIXPACKING////////////////OUT:Strided->compactfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}//INA:Strided->compactfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inACompactPtr[mb*kBlocks+kb],&inMatA[mb*inAStride*mBlockSize+kb*kBlockSize],mBlockSize,kBlockSize,inAStride);}}//INB:Strided->compactfor(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inBCompactPtr[kb*nBlocks+nb],&inMatB[kb*inBStride*kBlockSize+nb*nBlockSize],kBlockSize,nBlockSize,inBStride);}}////////////////MATRIXCOMPACTBLOCKPRODUCT//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}}}////////////////MATRIXUNPACKING////////////////OUT:Compact->stridedfor(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){unpack_matrix(&outMat[mb*outStride*mBlockSize+nb*nBlockSize],outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize,outStride);}}////////////////MATRIXDEALLOCATION//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}for(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){deallocate_matrix(inACompactPtr[mb*kBlocks+kb]);}}for(unsignedkb=0;kb<kBlocks;kb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(inBCompactPtr[kb*nBlocks+nb]);}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-63,c-3}];
  end_loc:[{r-63,c-33}];
  data:[outCompact];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outCompact init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-65,c-3}];
  end_loc:[{r-65,c-45}];
  data:[outCompactPtr];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outCompactPtr init outCompact(no-rhs)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-67,c-3}];
  end_loc:[{r-67,c-33}];
  data:[inACompact];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[inACompact init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-69,c-3}];
  end_loc:[{r-69,c-45}];
  data:[inACompactPtr];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[inACompactPtr init inACompact(no-rhs)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-71,c-3}];
  end_loc:[{r-71,c-33}];
  data:[inBCompact];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[inBCompact init_default no-rhs];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-73,c-3}];
  end_loc:[{r-73,c-45}];
  data:[inBCompactPtr];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[inBCompactPtr init inBCompact(no-rhs)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-75,c-3}];
  end_loc:[{r-75,c-40}];
  data:[mBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mBlockSize init (mSize/mBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-75,c-25}];
  end_loc:[{r-75,c-25}];
  data:[mSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000059-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-75,c-33}];
  end_loc:[{r-75,c-33}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-76,c-3}];
  end_loc:[{r-76,c-40}];
  data:[nBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nBlockSize init (nSize/nBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-76,c-25}];
  end_loc:[{r-76,c-25}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000059-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-76,c-33}];
  end_loc:[{r-76,c-33}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-77,c-3}];
  end_loc:[{r-77,c-40}];
  data:[kBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kBlockSize init (kSize/kBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-77,c-25}];
  end_loc:[{r-77,c-25}];
  data:[kSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000059-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-77,c-33}];
  end_loc:[{r-77,c-33}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-79,c-3}];
  end_loc:[{r-79,c-42}];
  data:[outStride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outStride init (nBlockSize*nBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-79,c-24}];
  end_loc:[{r-79,c-24}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000079-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-79,c-35}];
  end_loc:[{r-79,c-35}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000079-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-80,c-3}];
  end_loc:[{r-80,c-42}];
  data:[inAStride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[inAStride init (kBlockSize*kBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-80,c-24}];
  end_loc:[{r-80,c-24}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000080-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-80,c-35}];
  end_loc:[{r-80,c-35}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000080-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-81,c-3}];
  end_loc:[{r-81,c-42}];
  data:[inBStride];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[inBStride init (nBlockSize*nBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-81,c-24}];
  end_loc:[{r-81,c-24}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000081-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-81,c-35}];
  end_loc:[{r-81,c-35}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000081-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-88,c-3}];
  end_loc:[{r-92,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-88,c-8}];
  end_loc:[{r-88,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-88,c-22}];
  end_loc:[{r-88,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000088-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-88,c-25}];
  end_loc:[{r-88,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-88,c-30}];
  end_loc:[{r-88,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000088-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-88,c-39}];
  end_loc:[{r-88,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-88,c-45}];
  end_loc:[{r-92,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-89,c-5}];
  end_loc:[{r-91,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000088-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-89,c-10}];
  end_loc:[{r-89,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-89,c-24}];
  end_loc:[{r-89,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000089-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-89,c-27}];
  end_loc:[{r-89,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-89,c-32}];
  end_loc:[{r-89,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000089-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-89,c-41}];
  end_loc:[{r-89,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-89,c-47}];
  end_loc:[{r-91,c-5}];
  data:[{allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000088-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-90,c-7}];
  end_loc:[{r-90,c-81}];
  data:[allocate_matrix(outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[allocate_matrix((mBlockSize,nBlockSize,outCompactPtr[(nb+(mb*nBlocks))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-90,c-24}];
  end_loc:[{r-90,c-24}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000065-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-90,c-39}];
  end_loc:[{r-90,c-39}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000088-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-90,c-42}];
  end_loc:[{r-90,c-42}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-90,c-52}];
  end_loc:[{r-90,c-52}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000089-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-90,c-58}];
  end_loc:[{r-90,c-58}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-90,c-70}];
  end_loc:[{r-90,c-70}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000059>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-94,c-3}];
  end_loc:[{r-98,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){allocate_matrix(inACompactPtr[mb*kBlocks+kb],mBlockSize,kBlockSize);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-94,c-8}];
  end_loc:[{r-94,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-94,c-22}];
  end_loc:[{r-94,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000094-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-94,c-25}];
  end_loc:[{r-94,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-94,c-30}];
  end_loc:[{r-94,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000094-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-94,c-39}];
  end_loc:[{r-94,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-94,c-45}];
  end_loc:[{r-98,c-3}];
  data:[{for(unsignedkb=0;kb<kBlocks;kb++){allocate_matrix(inACompactPtr[mb*kBlocks+kb],mBlockSize,kBlockSize);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-95,c-5}];
  end_loc:[{r-97,c-5}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){allocate_matrix(inACompactPtr[mb*kBlocks+kb],mBlockSize,kBlockSize);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000094-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-95,c-10}];
  end_loc:[{r-95,c-25}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-95,c-24}];
  end_loc:[{r-95,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000095-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-95,c-27}];
  end_loc:[{r-95,c-32}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-95,c-32}];
  end_loc:[{r-95,c-32}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000095-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-95,c-41}];
  end_loc:[{r-95,c-43}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-95,c-47}];
  end_loc:[{r-97,c-5}];
  data:[{allocate_matrix(inACompactPtr[mb*kBlocks+kb],mBlockSize,kBlockSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000094-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-96,c-7}];
  end_loc:[{r-96,c-81}];
  data:[allocate_matrix(inACompactPtr[mb*kBlocks+kb],mBlockSize,kBlockSize)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[allocate_matrix((kBlockSize,mBlockSize,inACompactPtr[(kb+(kBlocks*mb))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-96,c-24}];
  end_loc:[{r-96,c-24}];
  data:[inACompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000069-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inACompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[kb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[kBlocks];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-96,c-39}];
  end_loc:[{r-96,c-39}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000094-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-96,c-42}];
  end_loc:[{r-96,c-42}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-96,c-52}];
  end_loc:[{r-96,c-52}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000095-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-96,c-58}];
  end_loc:[{r-96,c-58}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-96,c-70}];
  end_loc:[{r-96,c-70}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000059>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-100,c-3}];
  end_loc:[{r-104,c-3}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(inBCompactPtr[kb*nBlocks+nb],kBlockSize,nBlockSize);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-100,c-8}];
  end_loc:[{r-100,c-23}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-100,c-22}];
  end_loc:[{r-100,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000100-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-100,c-25}];
  end_loc:[{r-100,c-30}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-100,c-30}];
  end_loc:[{r-100,c-30}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000100-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-100,c-39}];
  end_loc:[{r-100,c-41}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-100,c-45}];
  end_loc:[{r-104,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(inBCompactPtr[kb*nBlocks+nb],kBlockSize,nBlockSize);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-101,c-5}];
  end_loc:[{r-103,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){allocate_matrix(inBCompactPtr[kb*nBlocks+nb],kBlockSize,nBlockSize);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000100-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-101,c-10}];
  end_loc:[{r-101,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-101,c-24}];
  end_loc:[{r-101,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000101-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-101,c-27}];
  end_loc:[{r-101,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-101,c-32}];
  end_loc:[{r-101,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000101-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-101,c-41}];
  end_loc:[{r-101,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-101,c-47}];
  end_loc:[{r-103,c-5}];
  data:[{allocate_matrix(inBCompactPtr[kb*nBlocks+nb],kBlockSize,nBlockSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000100-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-102,c-7}];
  end_loc:[{r-102,c-81}];
  data:[allocate_matrix(inBCompactPtr[kb*nBlocks+nb],kBlockSize,nBlockSize)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[allocate_matrix((kBlockSize,nBlockSize,inBCompactPtr[(nb+(kb*nBlocks))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-102,c-24}];
  end_loc:[{r-102,c-24}];
  data:[inBCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000073-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inBCompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[kb];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-102,c-39}];
  end_loc:[{r-102,c-39}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000100-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-102,c-42}];
  end_loc:[{r-102,c-42}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-102,c-52}];
  end_loc:[{r-102,c-52}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000101-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000022>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-102,c-58}];
  end_loc:[{r-102,c-58}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-102,c-70}];
  end_loc:[{r-102,c-70}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000006-000059>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-113,c-3}];
  end_loc:[{r-117,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-113,c-8}];
  end_loc:[{r-113,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-113,c-22}];
  end_loc:[{r-113,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000113-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-113,c-25}];
  end_loc:[{r-113,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-113,c-30}];
  end_loc:[{r-113,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000113-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-113,c-39}];
  end_loc:[{r-113,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-113,c-45}];
  end_loc:[{r-117,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-114,c-5}];
  end_loc:[{r-116,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000113-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-114,c-10}];
  end_loc:[{r-114,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-114,c-24}];
  end_loc:[{r-114,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000114-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-114,c-27}];
  end_loc:[{r-114,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-114,c-32}];
  end_loc:[{r-114,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000114-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-114,c-41}];
  end_loc:[{r-114,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-114,c-47}];
  end_loc:[{r-116,c-5}];
  data:[{pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000113-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-7}];
  end_loc:[{r-115,c-138}];
  data:[pack_matrix(outCompactPtr[mb*nBlocks+nb],&outMat[mb*outStride*mBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,outStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000032-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[pack_matrix((mBlockSize,nBlockSize,outStride,outCompactPtr[(nb+(mb*nBlocks))],&outMat[((nBlockSize*nb)+(mBlockSize*mb*outStride))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-20}];
  end_loc:[{r-115,c-20}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000065-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-35}];
  end_loc:[{r-115,c-35}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000113-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-38}];
  end_loc:[{r-115,c-38}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-48}];
  end_loc:[{r-115,c-48}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000114-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-55}];
  end_loc:[{r-115,c-55}];
  data:[outMat];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000058-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-62}];
  end_loc:[{r-115,c-62}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000113-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-65}];
  end_loc:[{r-115,c-65}];
  data:[outStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000079-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-75}];
  end_loc:[{r-115,c-75}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-88}];
  end_loc:[{r-115,c-88}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000114-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-91}];
  end_loc:[{r-115,c-91}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-104}];
  end_loc:[{r-115,c-104}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-116}];
  end_loc:[{r-115,c-116}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-115,c-128}];
  end_loc:[{r-115,c-128}];
  data:[outStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000079-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-120,c-3}];
  end_loc:[{r-124,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inACompactPtr[mb*kBlocks+kb],&inMatA[mb*inAStride*mBlockSize+kb*kBlockSize],mBlockSize,kBlockSize,inAStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-120,c-8}];
  end_loc:[{r-120,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-120,c-22}];
  end_loc:[{r-120,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000120-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-120,c-25}];
  end_loc:[{r-120,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-120,c-30}];
  end_loc:[{r-120,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000120-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-120,c-39}];
  end_loc:[{r-120,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-120,c-45}];
  end_loc:[{r-124,c-3}];
  data:[{for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inACompactPtr[mb*kBlocks+kb],&inMatA[mb*inAStride*mBlockSize+kb*kBlockSize],mBlockSize,kBlockSize,inAStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-121,c-5}];
  end_loc:[{r-123,c-5}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inACompactPtr[mb*kBlocks+kb],&inMatA[mb*inAStride*mBlockSize+kb*kBlockSize],mBlockSize,kBlockSize,inAStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000120-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-121,c-10}];
  end_loc:[{r-121,c-25}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-121,c-24}];
  end_loc:[{r-121,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000121-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-121,c-27}];
  end_loc:[{r-121,c-32}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-121,c-32}];
  end_loc:[{r-121,c-32}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000121-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-121,c-41}];
  end_loc:[{r-121,c-43}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-121,c-47}];
  end_loc:[{r-123,c-5}];
  data:[{pack_matrix(inACompactPtr[mb*kBlocks+kb],&inMatA[mb*inAStride*mBlockSize+kb*kBlockSize],mBlockSize,kBlockSize,inAStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000120-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-7}];
  end_loc:[{r-122,c-138}];
  data:[pack_matrix(inACompactPtr[mb*kBlocks+kb],&inMatA[mb*inAStride*mBlockSize+kb*kBlockSize],mBlockSize,kBlockSize,inAStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000032-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[pack_matrix((inAStride,kBlockSize,mBlockSize,inACompactPtr[(kb+(kBlocks*mb))],&inMatA[((kBlockSize*kb)+(inAStride*mBlockSize*mb))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-20}];
  end_loc:[{r-122,c-20}];
  data:[inACompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000069-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inACompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[kb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[kBlocks];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-35}];
  end_loc:[{r-122,c-35}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000120-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-38}];
  end_loc:[{r-122,c-38}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-48}];
  end_loc:[{r-122,c-48}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000121-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-55}];
  end_loc:[{r-122,c-55}];
  data:[inMatA];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000058-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inMatA];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[kb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(inAStride*mBlockSize)];
      ];
      1:[
        pcKind:[var];
        pcContent:[kBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-62}];
  end_loc:[{r-122,c-62}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000120-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-65}];
  end_loc:[{r-122,c-65}];
  data:[inAStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000080-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inAStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-75}];
  end_loc:[{r-122,c-75}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-88}];
  end_loc:[{r-122,c-88}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000121-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-91}];
  end_loc:[{r-122,c-91}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-104}];
  end_loc:[{r-122,c-104}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-116}];
  end_loc:[{r-122,c-116}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-122,c-128}];
  end_loc:[{r-122,c-128}];
  data:[inAStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000080-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inAStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-127,c-3}];
  end_loc:[{r-131,c-3}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inBCompactPtr[kb*nBlocks+nb],&inMatB[kb*inBStride*kBlockSize+nb*nBlockSize],kBlockSize,nBlockSize,inBStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-127,c-8}];
  end_loc:[{r-127,c-23}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-127,c-22}];
  end_loc:[{r-127,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000127-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-127,c-25}];
  end_loc:[{r-127,c-30}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-127,c-30}];
  end_loc:[{r-127,c-30}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000127-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-127,c-39}];
  end_loc:[{r-127,c-41}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-127,c-45}];
  end_loc:[{r-131,c-3}];
  data:[{for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inBCompactPtr[kb*nBlocks+nb],&inMatB[kb*inBStride*kBlockSize+nb*nBlockSize],kBlockSize,nBlockSize,inBStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-128,c-5}];
  end_loc:[{r-130,c-5}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){pack_matrix(inBCompactPtr[kb*nBlocks+nb],&inMatB[kb*inBStride*kBlockSize+nb*nBlockSize],kBlockSize,nBlockSize,inBStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000127-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-128,c-10}];
  end_loc:[{r-128,c-25}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-128,c-24}];
  end_loc:[{r-128,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000128-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-128,c-27}];
  end_loc:[{r-128,c-32}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-128,c-32}];
  end_loc:[{r-128,c-32}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000128-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-128,c-41}];
  end_loc:[{r-128,c-43}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-128,c-47}];
  end_loc:[{r-130,c-5}];
  data:[{pack_matrix(inBCompactPtr[kb*nBlocks+nb],&inMatB[kb*inBStride*kBlockSize+nb*nBlockSize],kBlockSize,nBlockSize,inBStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000127-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-7}];
  end_loc:[{r-129,c-138}];
  data:[pack_matrix(inBCompactPtr[kb*nBlocks+nb],&inMatB[kb*inBStride*kBlockSize+nb*nBlockSize],kBlockSize,nBlockSize,inBStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000032-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[pack_matrix((inBStride,kBlockSize,nBlockSize,inBCompactPtr[(nb+(kb*nBlocks))],&inMatB[((nBlockSize*nb)+(inBStride*kBlockSize*kb))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-20}];
  end_loc:[{r-129,c-20}];
  data:[inBCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000073-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inBCompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[kb];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-35}];
  end_loc:[{r-129,c-35}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000128-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-38}];
  end_loc:[{r-129,c-38}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-48}];
  end_loc:[{r-129,c-48}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000127-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-55}];
  end_loc:[{r-129,c-55}];
  data:[inMatB];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000058-000041>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inMatB];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[kb];
      ];
      1:[
        pcKind:[var];
        pcContent:[nb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(inBStride*kBlockSize)];
      ];
      1:[
        pcKind:[var];
        pcContent:[nBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-62}];
  end_loc:[{r-129,c-62}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000128-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-65}];
  end_loc:[{r-129,c-65}];
  data:[inBStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000081-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inBStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-75}];
  end_loc:[{r-129,c-75}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-88}];
  end_loc:[{r-129,c-88}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000127-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-91}];
  end_loc:[{r-129,c-91}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000033-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-104}];
  end_loc:[{r-129,c-104}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-116}];
  end_loc:[{r-129,c-116}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-129,c-128}];
  end_loc:[{r-129,c-128}];
  data:[inBStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000081-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000034-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inBStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-138,c-3}];
  end_loc:[{r-144,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-138,c-8}];
  end_loc:[{r-138,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-138,c-22}];
  end_loc:[{r-138,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000138-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-138,c-25}];
  end_loc:[{r-138,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-138,c-30}];
  end_loc:[{r-138,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000138-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-138,c-39}];
  end_loc:[{r-138,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-138,c-45}];
  end_loc:[{r-144,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-139,c-5}];
  end_loc:[{r-143,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000138-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-139,c-10}];
  end_loc:[{r-139,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-139,c-24}];
  end_loc:[{r-139,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000139-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-139,c-27}];
  end_loc:[{r-139,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-139,c-32}];
  end_loc:[{r-139,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000139-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-139,c-41}];
  end_loc:[{r-139,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-139,c-47}];
  end_loc:[{r-143,c-5}];
  data:[{for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000138-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-140,c-7}];
  end_loc:[{r-142,c-7}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000139-000005>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-140,c-12}];
  end_loc:[{r-140,c-27}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-140,c-26}];
  end_loc:[{r-140,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000140-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-140,c-29}];
  end_loc:[{r-140,c-34}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-140,c-34}];
  end_loc:[{r-140,c-34}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000140-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-140,c-43}];
  end_loc:[{r-140,c-45}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-140,c-49}];
  end_loc:[{r-142,c-7}];
  data:[{mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000139-000047>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-9}];
  end_loc:[{r-141,c-171}];
  data:[mat_product_v0_kernel_compact(outCompactPtr[mb*nBlocks+nb],inACompactPtr[mb*kBlocks+kb],inBCompactPtr[kb*nBlocks+nb],mBlockSize,nBlockSize,kBlockSize)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000017-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[mat_product_v0_kernel_compact((kBlockSize,mBlockSize,nBlockSize,inACompactPtr[(kb+(kBlocks*mb))],inBCompactPtr[(nb+(kb*nBlocks))],outCompactPtr[(nb+(mb*nBlocks))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-40}];
  end_loc:[{r-141,c-40}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000065-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000003>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-54}];
  end_loc:[{r-141,c-54}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000138-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-57}];
  end_loc:[{r-141,c-57}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-67}];
  end_loc:[{r-141,c-67}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000139-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-72}];
  end_loc:[{r-141,c-72}];
  data:[inACompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000069-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inACompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[kb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[kBlocks];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-86}];
  end_loc:[{r-141,c-86}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000138-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-89}];
  end_loc:[{r-141,c-89}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-99}];
  end_loc:[{r-141,c-99}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000140-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-104}];
  end_loc:[{r-141,c-104}];
  data:[inBCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000073-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inBCompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[kb];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-118}];
  end_loc:[{r-141,c-118}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000140-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-121}];
  end_loc:[{r-141,c-121}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-131}];
  end_loc:[{r-141,c-131}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000139-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000018-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-136}];
  end_loc:[{r-141,c-136}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-148}];
  end_loc:[{r-141,c-148}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-141,c-160}];
  end_loc:[{r-141,c-160}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000077-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000019-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-154,c-3}];
  end_loc:[{r-158,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){unpack_matrix(&outMat[mb*outStride*mBlockSize+nb*nBlockSize],outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize,outStride);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-154,c-8}];
  end_loc:[{r-154,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-154,c-22}];
  end_loc:[{r-154,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000154-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-154,c-25}];
  end_loc:[{r-154,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-154,c-30}];
  end_loc:[{r-154,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000154-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-154,c-39}];
  end_loc:[{r-154,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-154,c-45}];
  end_loc:[{r-158,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){unpack_matrix(&outMat[mb*outStride*mBlockSize+nb*nBlockSize],outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize,outStride);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-155,c-5}];
  end_loc:[{r-157,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){unpack_matrix(&outMat[mb*outStride*mBlockSize+nb*nBlockSize],outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize,outStride);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000154-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-155,c-10}];
  end_loc:[{r-155,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-155,c-24}];
  end_loc:[{r-155,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000155-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-155,c-27}];
  end_loc:[{r-155,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-155,c-32}];
  end_loc:[{r-155,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000155-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-155,c-41}];
  end_loc:[{r-155,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-155,c-47}];
  end_loc:[{r-157,c-5}];
  data:[{unpack_matrix(&outMat[mb*outStride*mBlockSize+nb*nBlockSize],outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize,outStride);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000154-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-7}];
  end_loc:[{r-156,c-140}];
  data:[unpack_matrix(&outMat[mb*outStride*mBlockSize+nb*nBlockSize],outCompactPtr[mb*nBlocks+nb],mBlockSize,nBlockSize,outStride)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000044-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[unpack_matrix((mBlockSize,nBlockSize,outStride,outCompactPtr[(nb+(mb*nBlocks))],&outMat[((nBlockSize*nb)+(mBlockSize*mb*outStride))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-23}];
  end_loc:[{r-156,c-23}];
  data:[outMat];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000058-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000003>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-30}];
  end_loc:[{r-156,c-30}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000154-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-33}];
  end_loc:[{r-156,c-33}];
  data:[outStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000079-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-43}];
  end_loc:[{r-156,c-43}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-56}];
  end_loc:[{r-156,c-56}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000155-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-59}];
  end_loc:[{r-156,c-59}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-72}];
  end_loc:[{r-156,c-72}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000065-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000025>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-87}];
  end_loc:[{r-156,c-87}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000154-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-90}];
  end_loc:[{r-156,c-90}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-100}];
  end_loc:[{r-156,c-100}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000155-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000045-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-106}];
  end_loc:[{r-156,c-106}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000075-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-118}];
  end_loc:[{r-156,c-118}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000076-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-156,c-130}];
  end_loc:[{r-156,c-130}];
  data:[outStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000079-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000046-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-165,c-3}];
  end_loc:[{r-169,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-165,c-8}];
  end_loc:[{r-165,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-165,c-22}];
  end_loc:[{r-165,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000165-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-165,c-25}];
  end_loc:[{r-165,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-165,c-30}];
  end_loc:[{r-165,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000165-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-165,c-39}];
  end_loc:[{r-165,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-165,c-45}];
  end_loc:[{r-169,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-166,c-5}];
  end_loc:[{r-168,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000165-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-166,c-10}];
  end_loc:[{r-166,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-166,c-24}];
  end_loc:[{r-166,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000166-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-166,c-27}];
  end_loc:[{r-166,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-166,c-32}];
  end_loc:[{r-166,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000166-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-166,c-41}];
  end_loc:[{r-166,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-166,c-47}];
  end_loc:[{r-168,c-5}];
  data:[{deallocate_matrix(outCompactPtr[mb*nBlocks+nb]);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000165-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-167,c-7}];
  end_loc:[{r-167,c-59}];
  data:[deallocate_matrix(outCompactPtr[mb*nBlocks+nb])];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[deallocate_matrix(outCompactPtr[(nb+(mb*nBlocks))])];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-167,c-26}];
  end_loc:[{r-167,c-26}];
  data:[outCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000065-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-167,c-41}];
  end_loc:[{r-167,c-41}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000165-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-167,c-44}];
  end_loc:[{r-167,c-44}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-167,c-54}];
  end_loc:[{r-167,c-54}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000166-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-171,c-3}];
  end_loc:[{r-175,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignedkb=0;kb<kBlocks;kb++){deallocate_matrix(inACompactPtr[mb*kBlocks+kb]);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-171,c-8}];
  end_loc:[{r-171,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-171,c-22}];
  end_loc:[{r-171,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000171-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-171,c-25}];
  end_loc:[{r-171,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-171,c-30}];
  end_loc:[{r-171,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000171-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-171,c-39}];
  end_loc:[{r-171,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-171,c-45}];
  end_loc:[{r-175,c-3}];
  data:[{for(unsignedkb=0;kb<kBlocks;kb++){deallocate_matrix(inACompactPtr[mb*kBlocks+kb]);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-172,c-5}];
  end_loc:[{r-174,c-5}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){deallocate_matrix(inACompactPtr[mb*kBlocks+kb]);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000171-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-172,c-10}];
  end_loc:[{r-172,c-25}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-172,c-24}];
  end_loc:[{r-172,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000172-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-172,c-27}];
  end_loc:[{r-172,c-32}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-172,c-32}];
  end_loc:[{r-172,c-32}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000172-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-172,c-41}];
  end_loc:[{r-172,c-43}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-172,c-47}];
  end_loc:[{r-174,c-5}];
  data:[{deallocate_matrix(inACompactPtr[mb*kBlocks+kb]);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000171-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-173,c-7}];
  end_loc:[{r-173,c-59}];
  data:[deallocate_matrix(inACompactPtr[mb*kBlocks+kb])];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[deallocate_matrix(inACompactPtr[(kb+(kBlocks*mb))])];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-173,c-26}];
  end_loc:[{r-173,c-26}];
  data:[inACompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000069-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inACompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[mb];
      ];
      1:[
        pcKind:[var];
        pcContent:[kb];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[kBlocks];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-173,c-41}];
  end_loc:[{r-173,c-41}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000171-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-173,c-44}];
  end_loc:[{r-173,c-44}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-173,c-54}];
  end_loc:[{r-173,c-54}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000172-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-177,c-3}];
  end_loc:[{r-181,c-3}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(inBCompactPtr[kb*nBlocks+nb]);}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-177,c-8}];
  end_loc:[{r-177,c-23}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-177,c-22}];
  end_loc:[{r-177,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000177-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-177,c-25}];
  end_loc:[{r-177,c-30}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-177,c-30}];
  end_loc:[{r-177,c-30}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000177-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-177,c-39}];
  end_loc:[{r-177,c-41}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-177,c-45}];
  end_loc:[{r-181,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(inBCompactPtr[kb*nBlocks+nb]);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000061-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-178,c-5}];
  end_loc:[{r-180,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){deallocate_matrix(inBCompactPtr[kb*nBlocks+nb]);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000177-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-178,c-10}];
  end_loc:[{r-178,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-178,c-24}];
  end_loc:[{r-178,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000178-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-178,c-27}];
  end_loc:[{r-178,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-178,c-32}];
  end_loc:[{r-178,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000178-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-178,c-41}];
  end_loc:[{r-178,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-178,c-47}];
  end_loc:[{r-180,c-5}];
  data:[{deallocate_matrix(inBCompactPtr[kb*nBlocks+nb]);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_blocked.cpp:000177-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-179,c-7}];
  end_loc:[{r-179,c-59}];
  data:[deallocate_matrix(inBCompactPtr[kb*nBlocks+nb])];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000001>];
  caller:[<builder/test/access_2d/mat_product_blocked.cpp:000057-000001>];
  own:[
    pcKind:[call];
    pcContent:[deallocate_matrix(inBCompactPtr[(nb+(kb*nBlocks))])];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-179,c-26}];
  end_loc:[{r-179,c-26}];
  data:[inBCompactPtr];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000073-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inBCompactPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[kb];
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
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-179,c-41}];
  end_loc:[{r-179,c-41}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000177-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-179,c-44}];
  end_loc:[{r-179,c-44}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000060-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_blocked.cpp];
  begin_loc:[{r-179,c-54}];
  end_loc:[{r-179,c-54}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_blocked.cpp:000178-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_blocked.cpp:000012-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];
*/