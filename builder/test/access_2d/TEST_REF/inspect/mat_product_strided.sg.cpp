steel_builder_test_suite
mat_product_strided.cpp
/*

  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-4,c-1}];
  end_loc:[{r-16,c-1}];
  data:[voidmat_product_v1_kernel_strided(float*outMat,floatconst*inMatA,floatconst*inMatB,unsignedmSize,unsignednSize,unsignedkSize,unsignedoutStride,unsignedinAStride,unsignedinBStride){for(unsignedmm=0;mm<mSize;mm++){for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}}}}];
  obj:[fun_def];

  name:[mat_product_v1_kernel_strided];
  args:[
    0:[<builder/test/access_2d/mat_product_strided.cpp:000005-000003>];
    1:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
    2:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
    3:[<builder/test/access_2d/mat_product_strided.cpp:000006-000003>];
    4:[<builder/test/access_2d/mat_product_strided.cpp:000006-000019>];
    5:[<builder/test/access_2d/mat_product_strided.cpp:000006-000035>];
    6:[<builder/test/access_2d/mat_product_strided.cpp:000007-000003>];
    7:[<builder/test/access_2d/mat_product_strided.cpp:000007-000023>];
    8:[<builder/test/access_2d/mat_product_strided.cpp:000007-000043>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_2d/mat_product_strided.cpp:000037-000009>];
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_strided.cpp:000004-000001>];
    appId:[mat_product_app];
    appImpl:[mat_product_v1_kernel_strided];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-5,c-11}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
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
  file:[mat_product_strided.cpp];
  begin_loc:[{r-5,c-19}];
  end_loc:[{r-5,c-33}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000012-000040>];
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
  file:[mat_product_strided.cpp];
  begin_loc:[{r-5,c-41}];
  end_loc:[{r-5,c-55}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000012-000070>];
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
  file:[mat_product_strided.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-6,c-12}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000009-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-6,c-19}];
  end_loc:[{r-6,c-28}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000010-000032>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-6,c-35}];
  end_loc:[{r-6,c-44}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000011-000034>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-7,c-3}];
  end_loc:[{r-7,c-12}];
  data:[unsignedo];
  obj:[data_decl];

  declKind:[fargument];
  varName:[outStride];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_strided.cpp:000012-000021>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-7,c-23}];
  end_loc:[{r-7,c-32}];
  data:[unsignedi];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inAStride];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_strided.cpp:000012-000052>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-7,c-43}];
  end_loc:[{r-7,c-52}];
  data:[unsignedi];
  obj:[data_decl];

  declKind:[fargument];
  varName:[inBStride];
  typeName:[unsigned];
  translationType:[unsigned];
  typeQual:[var];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_2d/mat_product_strided.cpp:000012-000082>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-8,c-1}];
  end_loc:[{r-16,c-1}];
  data:[{for(unsignedmm=0;mm<mSize;mm++){for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-9,c-3}];
  end_loc:[{r-15,c-3}];
  data:[for(unsignedmm=0;mm<mSize;mm++){for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-9,c-8}];
  end_loc:[{r-9,c-23}];
  data:[mm];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mm init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-9,c-22}];
  end_loc:[{r-9,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000009-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-9,c-25}];
  end_loc:[{r-9,c-30}];
  data:[mm<mSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mm lt mSize];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-9,c-30}];
  end_loc:[{r-9,c-30}];
  data:[mSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000006-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000009-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-9,c-37}];
  end_loc:[{r-9,c-39}];
  data:[mm++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mm incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-9,c-43}];
  end_loc:[{r-15,c-3}];
  data:[{for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000008-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-10,c-5}];
  end_loc:[{r-14,c-5}];
  data:[for(unsignednn=0;nn<nSize;nn++){for(unsignedkk=0;kk<kSize;kk++){outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000009-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-10,c-10}];
  end_loc:[{r-10,c-25}];
  data:[nn];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nn init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-10,c-24}];
  end_loc:[{r-10,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000010-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-10,c-27}];
  end_loc:[{r-10,c-32}];
  data:[nn<nSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nn lt nSize];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-10,c-32}];
  end_loc:[{r-10,c-32}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000006-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000010-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-10,c-39}];
  end_loc:[{r-10,c-41}];
  data:[nn++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nn incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-10,c-45}];
  end_loc:[{r-14,c-5}];
  data:[{for(unsignedkk=0;kk<kSize;kk++){outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000009-000043>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-11,c-7}];
  end_loc:[{r-13,c-7}];
  data:[for(unsignedkk=0;kk<kSize;kk++){outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000010-000005>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-11,c-12}];
  end_loc:[{r-11,c-27}];
  data:[kk];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-11,c-26}];
  end_loc:[{r-11,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000011-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-11,c-29}];
  end_loc:[{r-11,c-34}];
  data:[kk<kSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk lt kSize];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-11,c-34}];
  end_loc:[{r-11,c-34}];
  data:[kSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000006-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000011-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-11,c-41}];
  end_loc:[{r-11,c-43}];
  data:[kk++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-11,c-47}];
  end_loc:[{r-13,c-7}];
  data:[{outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000010-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-9}];
  end_loc:[{r-12,c-96}];
  data:[outMat[mm*outStride+nn]+=inMatA[mm*inAStride+kk]*inMatB[kk*inBStride+nn]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[outMat[(nn+(mm*outStride))] incr (inMatA[(kk+(inAStride*mm))]*inMatB[(nn+(inBStride*kk))])];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-16}];
  end_loc:[{r-12,c-16}];
  data:[mm];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000009-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mm];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-21}];
  end_loc:[{r-12,c-21}];
  data:[outStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000007-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[outStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-33}];
  end_loc:[{r-12,c-33}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000010-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-40}];
  end_loc:[{r-12,c-40}];
  data:[inMatA];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
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
        pcContent:[inAStride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-47}];
  end_loc:[{r-12,c-47}];
  data:[mm];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000009-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mm];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-52}];
  end_loc:[{r-12,c-52}];
  data:[inAStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000007-000023>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inAStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-64}];
  end_loc:[{r-12,c-64}];
  data:[kk];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000011-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-70}];
  end_loc:[{r-12,c-70}];
  data:[inMatB];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
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
        pcContent:[inBStride];
      ];
      1:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-77}];
  end_loc:[{r-12,c-77}];
  data:[kk];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000011-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-82}];
  end_loc:[{r-12,c-82}];
  data:[inBStride];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000007-000043>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[inBStride];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-12,c-94}];
  end_loc:[{r-12,c-94}];
  data:[nn];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000010-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000012-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nn];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-20,c-1}];
  end_loc:[{r-41,c-1}];
  data:[voidmat_product_v2_block_strided(float*outMat,floatconst*inMatA,floatconst*inMatB,unsignedmSize,unsignednSize,unsignedkSize,unsignedmBlocks,unsignednBlocks,unsignedkBlocks){unsignedmBlockSize=mSize/mBlocks;unsignednBlockSize=nSize/nBlocks;unsignedkBlockSize=kSize/kBlocks;////////////////MATRIXSTRIDEDBLOCKPRODUCT//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}}}}];
  obj:[fun_def];

  name:[mat_product_v2_block_strided];
  args:[
    0:[<builder/test/access_2d/mat_product_strided.cpp:000021-000003>];
    1:[<builder/test/access_2d/mat_product_strided.cpp:000021-000019>];
    2:[<builder/test/access_2d/mat_product_strided.cpp:000021-000041>];
    3:[<builder/test/access_2d/mat_product_strided.cpp:000022-000003>];
    4:[<builder/test/access_2d/mat_product_strided.cpp:000022-000019>];
    5:[<builder/test/access_2d/mat_product_strided.cpp:000022-000035>];
    6:[<builder/test/access_2d/mat_product_strided.cpp:000023-000003>];
    7:[<builder/test/access_2d/mat_product_strided.cpp:000023-000021>];
    8:[<builder/test/access_2d/mat_product_strided.cpp:000023-000039>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_2d/mat_product_strided.cpp:000037-000009>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_2d/mat_product_strided.cpp:000020-000001>];
    appId:[mat_product_app];
    appImpl:[mat_product_v2_block_strided];
    returnType:[task::coro::dispatcher<app::impl::mat_product_v2_block_strided>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-21,c-3}];
  end_loc:[{r-21,c-11}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000037-000041>];
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
  file:[mat_product_strided.cpp];
  begin_loc:[{r-21,c-19}];
  end_loc:[{r-21,c-33}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000037-000093>];
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
  file:[mat_product_strided.cpp];
  begin_loc:[{r-21,c-41}];
  end_loc:[{r-21,c-55}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000037-000145>];
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
  file:[mat_product_strided.cpp];
  begin_loc:[{r-22,c-3}];
  end_loc:[{r-22,c-12}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000025-000025>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-22,c-19}];
  end_loc:[{r-22,c-28}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000026-000025>];
    1:[<builder/test/access_2d/mat_product_strided.cpp:000037-000053>];
    2:[<builder/test/access_2d/mat_product_strided.cpp:000037-000157>];
    3:[<builder/test/access_2d/mat_product_strided.cpp:000037-000232>];
    4:[<builder/test/access_2d/mat_product_strided.cpp:000037-000246>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-22,c-35}];
  end_loc:[{r-22,c-44}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000027-000025>];
    1:[<builder/test/access_2d/mat_product_strided.cpp:000037-000105>];
    2:[<builder/test/access_2d/mat_product_strided.cpp:000037-000239>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-23,c-3}];
  end_loc:[{r-23,c-12}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000025-000033>];
    1:[<builder/test/access_2d/mat_product_strided.cpp:000034-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-23,c-21}];
  end_loc:[{r-23,c-30}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000026-000033>];
    1:[<builder/test/access_2d/mat_product_strided.cpp:000035-000032>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-23,c-39}];
  end_loc:[{r-23,c-48}];
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
    0:[<builder/test/access_2d/mat_product_strided.cpp:000027-000033>];
    1:[<builder/test/access_2d/mat_product_strided.cpp:000036-000034>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-24,c-1}];
  end_loc:[{r-41,c-1}];
  data:[{unsignedmBlockSize=mSize/mBlocks;unsignednBlockSize=nSize/nBlocks;unsignedkBlockSize=kSize/kBlocks;////////////////MATRIXSTRIDEDBLOCKPRODUCT//////////////for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-25,c-3}];
  end_loc:[{r-25,c-40}];
  data:[mBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mBlockSize init (mSize/mBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-25,c-25}];
  end_loc:[{r-25,c-25}];
  data:[mSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000025-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-25,c-33}];
  end_loc:[{r-25,c-33}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000025-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-40}];
  data:[nBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nBlockSize init (nSize/nBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-26,c-25}];
  end_loc:[{r-26,c-25}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000026-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-26,c-33}];
  end_loc:[{r-26,c-33}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000023-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000026-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-27,c-40}];
  data:[kBlockSize];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kBlockSize init (kSize/kBlocks)];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-27,c-25}];
  end_loc:[{r-27,c-25}];
  data:[kSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-27,c-33}];
  end_loc:[{r-27,c-33}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000023-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-40,c-3}];
  data:[for(unsignedmb=0;mb<mBlocks;mb++){for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-34,c-8}];
  end_loc:[{r-34,c-23}];
  data:[mb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-34,c-22}];
  end_loc:[{r-34,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000034-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-34,c-25}];
  end_loc:[{r-34,c-30}];
  data:[mb<mBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb lt mBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-34,c-30}];
  end_loc:[{r-34,c-30}];
  data:[mBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000023-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000034-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-34,c-39}];
  end_loc:[{r-34,c-41}];
  data:[mb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[mb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-34,c-45}];
  end_loc:[{r-40,c-3}];
  data:[{for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000024-000001>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-35,c-5}];
  end_loc:[{r-39,c-5}];
  data:[for(unsignednb=0;nb<nBlocks;nb++){for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000034-000003>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-35,c-10}];
  end_loc:[{r-35,c-25}];
  data:[nb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-35,c-24}];
  end_loc:[{r-35,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000035-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-35,c-27}];
  end_loc:[{r-35,c-32}];
  data:[nb<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb lt nBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-35,c-32}];
  end_loc:[{r-35,c-32}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000023-000021>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000035-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-35,c-41}];
  end_loc:[{r-35,c-43}];
  data:[nb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-35,c-47}];
  end_loc:[{r-39,c-5}];
  data:[{for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000034-000045>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-36,c-7}];
  end_loc:[{r-38,c-7}];
  data:[for(unsignedkb=0;kb<kBlocks;kb++){mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}];
  obj:[fun_loop];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000035-000005>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-36,c-12}];
  end_loc:[{r-36,c-27}];
  data:[kb];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb init 0];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-36,c-26}];
  end_loc:[{r-36,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000036-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-36,c-29}];
  end_loc:[{r-36,c-34}];
  data:[kb<kBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb lt kBlocks];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-36,c-34}];
  end_loc:[{r-36,c-34}];
  data:[kBlocks];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000023-000039>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000036-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-36,c-43}];
  end_loc:[{r-36,c-45}];
  data:[kb++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kb incr 1];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-36,c-49}];
  end_loc:[{r-38,c-7}];
  data:[{mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_2d/mat_product_strided.cpp:000035-000047>];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-9}];
  end_loc:[{r-37,c-251}];
  data:[mat_product_v1_kernel_strided(&outMat[mb*nSize*mBlockSize+nb*nBlockSize],&inMatA[mb*kSize*mBlockSize+kb*kBlockSize],&inMatB[kb*nSize*kBlockSize+nb*nBlockSize],mBlockSize,nBlockSize,kBlockSize,nSize,kSize,nSize)];
  obj:[fun_call];

  callee:[<builder/test/access_2d/mat_product_strided.cpp:000004-000001>];
  caller:[<builder/test/access_2d/mat_product_strided.cpp:000020-000001>];
  own:[
    pcKind:[call];
    pcContent:[mat_product_v1_kernel_strided((kBlockSize,kSize,mBlockSize,nBlockSize,nSize,nSize,&inMatA[((kBlockSize*kb)+(kSize*mBlockSize*mb))],&inMatB[((nBlockSize*nb)+(kBlockSize*kb*nSize))],&outMat[((nBlockSize*nb)+(mBlockSize*mb*nSize))]))];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-41}];
  end_loc:[{r-37,c-41}];
  data:[outMat];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000021-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000003>];
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
        pcContent:[(mBlockSize*nSize)];
      ];
      1:[
        pcKind:[var];
        pcContent:[nBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-48}];
  end_loc:[{r-37,c-48}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000034-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-53}];
  end_loc:[{r-37,c-53}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-61}];
  end_loc:[{r-37,c-61}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000025-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-74}];
  end_loc:[{r-37,c-74}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000035-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-79}];
  end_loc:[{r-37,c-79}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-93}];
  end_loc:[{r-37,c-93}];
  data:[inMatA];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000021-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
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
        pcContent:[(kSize*mBlockSize)];
      ];
      1:[
        pcKind:[var];
        pcContent:[kBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-100}];
  end_loc:[{r-37,c-100}];
  data:[mb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000034-000008>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-105}];
  end_loc:[{r-37,c-105}];
  data:[kSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-113}];
  end_loc:[{r-37,c-113}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000025-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-126}];
  end_loc:[{r-37,c-126}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000036-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-131}];
  end_loc:[{r-37,c-131}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000027-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-145}];
  end_loc:[{r-37,c-145}];
  data:[inMatB];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000021-000041>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
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
        pcContent:[(kBlockSize*nSize)];
      ];
      1:[
        pcKind:[var];
        pcContent:[nBlockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-152}];
  end_loc:[{r-37,c-152}];
  data:[kb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000036-000012>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-157}];
  end_loc:[{r-37,c-157}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-165}];
  end_loc:[{r-37,c-165}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000027-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-178}];
  end_loc:[{r-37,c-178}];
  data:[nb];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000035-000010>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nb];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-183}];
  end_loc:[{r-37,c-183}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000005-000041>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-196}];
  end_loc:[{r-37,c-196}];
  data:[mBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000025-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000006-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[mBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-208}];
  end_loc:[{r-37,c-208}];
  data:[nBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000006-000019>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-220}];
  end_loc:[{r-37,c-220}];
  data:[kBlockSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000027-000003>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000006-000035>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kBlockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-232}];
  end_loc:[{r-37,c-232}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000007-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-239}];
  end_loc:[{r-37,c-239}];
  data:[kSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000035>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000007-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_2d/];
  path:[steel_builder_test_suite];
  file:[mat_product_strided.cpp];
  begin_loc:[{r-37,c-246}];
  end_loc:[{r-37,c-246}];
  data:[nSize];
  obj:[data_use];

  root:[<builder/test/access_2d/mat_product_strided.cpp:000022-000019>];
  callee_or_op:[<builder/test/access_2d/mat_product_strided.cpp:000007-000043>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nSize];
  ];
  memAccess:[NULL];
*/