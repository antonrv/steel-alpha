steel_builder_test_suite
dot_product.cpp
/*

  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-5,c-1}];
  end_loc:[{r-9,c-1}];
  data:[voiddot_prod_v1(float*res,floatconst*aVec,floatconst*bVec,constunsignedn){for(unsignedi=0;i<n;i++){res[0]+=aVec[i]*bVec[i];}}];
  obj:[fun_def];

  name:[dot_prod_v1];
  args:[
    0:[<builder/test/access_1d/dot_product.cpp:000005-000018>];
    1:[<builder/test/access_1d/dot_product.cpp:000005-000031>];
    2:[<builder/test/access_1d/dot_product.cpp:000005-000051>];
    3:[<builder/test/access_1d/dot_product.cpp:000005-000071>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/dot_product.cpp:000030-000005>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/dot_product.cpp:000005-000001>];
    appId:[dot_prod_app];
    appImpl:[dot_prod_v1];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-5,c-18}];
  end_loc:[{r-5,c-26}];
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
    0:[<builder/test/access_1d/dot_product.cpp:000007-000005>];
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
  file:[dot_product.cpp];
  begin_loc:[{r-5,c-31}];
  end_loc:[{r-5,c-45}];
  data:[floatconst*a];
  obj:[data_decl];

  declKind:[fargument];
  varName:[aVec];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/dot_product.cpp:000007-000015>];
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
        pcContent:[range[ Min0; Maxn ]];
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
  file:[dot_product.cpp];
  begin_loc:[{r-5,c-51}];
  end_loc:[{r-5,c-65}];
  data:[floatconst*b];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bVec];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/dot_product.cpp:000007-000025>];
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
        pcContent:[range[ Min0; Maxn ]];
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
  file:[dot_product.cpp];
  begin_loc:[{r-5,c-71}];
  end_loc:[{r-5,c-86}];
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
    0:[<builder/test/access_1d/dot_product.cpp:000006-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-5,c-89}];
  end_loc:[{r-9,c-1}];
  data:[{for(unsignedi=0;i<n;i++){res[0]+=aVec[i]*bVec[i];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-6,c-3}];
  end_loc:[{r-8,c-3}];
  data:[for(unsignedi=0;i<n;i++){res[0]+=aVec[i]*bVec[i];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-6,c-8}];
  end_loc:[{r-6,c-22}];
  data:[i];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-6,c-21}];
  end_loc:[{r-6,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000006-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-6,c-24}];
  end_loc:[{r-6,c-28}];
  data:[i<n];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i lt n];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-6,c-28}];
  end_loc:[{r-6,c-28}];
  data:[n];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000005-000071>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000006-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[n];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-6,c-31}];
  end_loc:[{r-6,c-32}];
  data:[i++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-6,c-36}];
  end_loc:[{r-8,c-3}];
  data:[{res[0]+=aVec[i]*bVec[i];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/dot_product.cpp:000005-000089>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-7,c-5}];
  end_loc:[{r-7,c-31}];
  data:[res[0]+=aVec[i]*bVec[i]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[res[0] incr (aVec[i]*bVec[i])];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-7,c-9}];
  end_loc:[{r-7,c-9}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000007-000005>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-7,c-15}];
  end_loc:[{r-7,c-15}];
  data:[aVec];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000005-000031>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[aVec];
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
  file:[dot_product.cpp];
  begin_loc:[{r-7,c-20}];
  end_loc:[{r-7,c-20}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-7,c-25}];
  end_loc:[{r-7,c-25}];
  data:[bVec];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000005-000051>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bVec];
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
  file:[dot_product.cpp];
  begin_loc:[{r-7,c-30}];
  end_loc:[{r-7,c-30}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000006-000008>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000007-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-12,c-1}];
  end_loc:[{r-16,c-1}];
  data:[voidreduce(float*res,floatconst*vec,constunsignedn){for(unsignedi=0;i<n;i++){res[0]+=vec[i];}}];
  obj:[fun_def];

  name:[reduce];
  args:[
    0:[<builder/test/access_1d/dot_product.cpp:000012-000013>];
    1:[<builder/test/access_1d/dot_product.cpp:000012-000026>];
    2:[<builder/test/access_1d/dot_product.cpp:000012-000045>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_1d/dot_product.cpp:000034-000003>];
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/dot_product.cpp:000012-000001>];
    appId:[reduce_app];
    appImpl:[reduce];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-12,c-13}];
  end_loc:[{r-12,c-21}];
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
    0:[<builder/test/access_1d/dot_product.cpp:000014-000005>];
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
  file:[dot_product.cpp];
  begin_loc:[{r-12,c-26}];
  end_loc:[{r-12,c-40}];
  data:[floatconst*v];
  obj:[data_decl];

  declKind:[fargument];
  varName:[vec];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/dot_product.cpp:000014-000015>];
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
        pcContent:[range[ Min0; Maxn ]];
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
  file:[dot_product.cpp];
  begin_loc:[{r-12,c-45}];
  end_loc:[{r-12,c-60}];
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
    0:[<builder/test/access_1d/dot_product.cpp:000013-000027>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-12,c-63}];
  end_loc:[{r-16,c-1}];
  data:[{for(unsignedi=0;i<n;i++){res[0]+=vec[i];}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-13,c-3}];
  end_loc:[{r-15,c-3}];
  data:[for(unsignedi=0;i<n;i++){res[0]+=vec[i];}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-13,c-7}];
  end_loc:[{r-13,c-21}];
  data:[i];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-13,c-20}];
  end_loc:[{r-13,c-20}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000013-000007>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-13,c-23}];
  end_loc:[{r-13,c-27}];
  data:[i<n];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i lt n];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-13,c-27}];
  end_loc:[{r-13,c-27}];
  data:[n];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000012-000045>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000013-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[n];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-13,c-30}];
  end_loc:[{r-13,c-31}];
  data:[i++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[i incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-13,c-35}];
  end_loc:[{r-15,c-3}];
  data:[{res[0]+=vec[i];}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/dot_product.cpp:000012-000063>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-14,c-5}];
  end_loc:[{r-14,c-20}];
  data:[res[0]+=vec[i]];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[res[0] incr vec[i]];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-14,c-9}];
  end_loc:[{r-14,c-9}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000014-000005>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-14,c-15}];
  end_loc:[{r-14,c-15}];
  data:[vec];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000012-000026>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000014-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[vec];
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
  file:[dot_product.cpp];
  begin_loc:[{r-14,c-19}];
  end_loc:[{r-14,c-19}];
  data:[i];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000013-000007>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000014-000005>];
  terminal_root:[
    pcKind:[var];
    pcContent:[i];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-19,c-1}];
  end_loc:[{r-35,c-1}];
  data:[voiddot_prod_v2(float*res,floatconst*aPtr,floatconst*bPtr,constunsignedn,constunsignedblockSize){constunsignednBlocks=n/blockSize;//Createvectorofpartialresultsstd::vector<float>resVec;//(nBlocks,0);TODOresVec.resize(nBlocks);float*resPtr=resVec.data();//Computesmaller'nBlocks'dotproductsfor(unsignedb=0;b<nBlocks;b++){dot_prod_v1(&resPtr[b],&aPtr[b*blockSize],&bPtr[b*blockSize],blockSize);}floatresReduce=0;reduce(&resReduce,resPtr,nBlocks);}];
  obj:[fun_def];

  name:[dot_prod_v2];
  args:[
    0:[<builder/test/access_1d/dot_product.cpp:000019-000019>];
    1:[<builder/test/access_1d/dot_product.cpp:000019-000032>];
    2:[<builder/test/access_1d/dot_product.cpp:000019-000052>];
    3:[<builder/test/access_1d/dot_product.cpp:000019-000072>];
    4:[<builder/test/access_1d/dot_product.cpp:000019-000090>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_1d/dot_product.cpp:000030-000005>];
    1:[<builder/test/access_1d/dot_product.cpp:000034-000003>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_1d/dot_product.cpp:000019-000001>];
    appId:[dot_prod_app];
    appImpl:[dot_prod_v2];
    returnType:[task::coro::dispatcher<app::impl::dot_prod_v2>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-19,c-19}];
  end_loc:[{r-19,c-27}];
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
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-19,c-32}];
  end_loc:[{r-19,c-46}];
  data:[floatconst*a];
  obj:[data_decl];

  declKind:[fargument];
  varName:[aPtr];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/dot_product.cpp:000030-000031>];
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
        pcContent:[range[ Min0; Max(blockSize+(blockSize*nBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(n/blockSize) ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-19,c-52}];
  end_loc:[{r-19,c-66}];
  data:[floatconst*b];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bPtr];
  typeName:[float];
  translationType:[std::add_pointer_t<std::add_const_t<float>>];
  typeQual:[cnst];
  indir:[ptr];
  indirQual:[var];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/dot_product.cpp:000030-000051>];
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
        pcContent:[range[ Min0; Max(blockSize+(blockSize*nBlocks)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(n/blockSize) ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-19,c-72}];
  end_loc:[{r-19,c-87}];
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
    0:[<builder/test/access_1d/dot_product.cpp:000021-000028>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-19,c-90}];
  end_loc:[{r-19,c-105}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[blockSize];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_1d/dot_product.cpp:000021-000032>];
    1:[<builder/test/access_1d/dot_product.cpp:000030-000038>];
    2:[<builder/test/access_1d/dot_product.cpp:000030-000058>];
    3:[<builder/test/access_1d/dot_product.cpp:000030-000070>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-19,c-116}];
  end_loc:[{r-35,c-1}];
  data:[{constunsignednBlocks=n/blockSize;//Createvectorofpartialresultsstd::vector<float>resVec;//(nBlocks,0);TODOresVec.resize(nBlocks);float*resPtr=resVec.data();//Computesmaller'nBlocks'dotproductsfor(unsignedb=0;b<nBlocks;b++){dot_prod_v1(&resPtr[b],&aPtr[b*blockSize],&bPtr[b*blockSize],blockSize);}floatresReduce=0;reduce(&resReduce,resPtr,nBlocks);}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-21,c-3}];
  end_loc:[{r-21,c-41}];
  data:[nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[nBlocks init (n/blockSize)];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-21,c-28}];
  end_loc:[{r-21,c-28}];
  data:[n];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000019-000072>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000021-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[n];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-21,c-32}];
  end_loc:[{r-21,c-32}];
  data:[blockSize];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000019-000090>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000021-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[blockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-24,c-3}];
  end_loc:[{r-24,c-28}];
  data:[resVec];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[resVec init_default no-rhs];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-26,c-3}];
  end_loc:[{r-26,c-33}];
  data:[resPtr];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[resPtr init resVec(no-rhs)];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-29,c-3}];
  end_loc:[{r-31,c-3}];
  data:[for(unsignedb=0;b<nBlocks;b++){dot_prod_v1(&resPtr[b],&aPtr[b*blockSize],&bPtr[b*blockSize],blockSize);}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-29,c-8}];
  end_loc:[{r-29,c-22}];
  data:[b];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-29,c-21}];
  end_loc:[{r-29,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000029-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-29,c-24}];
  end_loc:[{r-29,c-28}];
  data:[b<nBlocks];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b lt nBlocks];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-29,c-28}];
  end_loc:[{r-29,c-28}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000021-000003>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000029-000024>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-29,c-37}];
  end_loc:[{r-29,c-38}];
  data:[b++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[b incr 1];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-29,c-42}];
  end_loc:[{r-31,c-3}];
  data:[{dot_prod_v1(&resPtr[b],&aPtr[b*blockSize],&bPtr[b*blockSize],blockSize);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_1d/dot_product.cpp:000019-000116>];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-5}];
  end_loc:[{r-30,c-80}];
  data:[dot_prod_v1(&resPtr[b],&aPtr[b*blockSize],&bPtr[b*blockSize],blockSize)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/dot_product.cpp:000005-000001>];
  caller:[<builder/test/access_1d/dot_product.cpp:000019-000001>];
  own:[
    pcKind:[call];
    pcContent:[dot_prod_v1((blockSize,&aPtr[(b*blockSize)],&bPtr[(b*blockSize)],&resPtr[b]))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-19}];
  end_loc:[{r-30,c-19}];
  data:[resPtr];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000018>];
  terminal_root:[
    pcKind:[var];
    pcContent:[resPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[b];
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
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-26}];
  end_loc:[{r-30,c-26}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000029-000008>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000018>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-31}];
  end_loc:[{r-30,c-31}];
  data:[aPtr];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000019-000032>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000031>];
  terminal_root:[
    pcKind:[var];
    pcContent:[aPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[b];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[blockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-36}];
  end_loc:[{r-30,c-36}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000029-000008>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000031>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-38}];
  end_loc:[{r-30,c-38}];
  data:[blockSize];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000019-000090>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000031>];
  terminal_root:[
    pcKind:[var];
    pcContent:[blockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-51}];
  end_loc:[{r-30,c-51}];
  data:[bPtr];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000019-000052>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000051>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bPtr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[b];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[var];
        pcContent:[blockSize];
      ];
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-56}];
  end_loc:[{r-30,c-56}];
  data:[b];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000029-000008>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000051>];
  terminal_root:[
    pcKind:[var];
    pcContent:[b];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-58}];
  end_loc:[{r-30,c-58}];
  data:[blockSize];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000019-000090>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000051>];
  terminal_root:[
    pcKind:[var];
    pcContent:[blockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-30,c-70}];
  end_loc:[{r-30,c-70}];
  data:[blockSize];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000019-000090>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000005-000071>];
  terminal_root:[
    pcKind:[var];
    pcContent:[blockSize];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-33,c-3}];
  end_loc:[{r-33,c-22}];
  data:[resReduce];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[resReduce init 0];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-33,c-21}];
  end_loc:[{r-33,c-21}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000033-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-34,c-3}];
  end_loc:[{r-34,c-37}];
  data:[reduce(&resReduce,resPtr,nBlocks)];
  obj:[fun_call];

  callee:[<builder/test/access_1d/dot_product.cpp:000012-000001>];
  caller:[<builder/test/access_1d/dot_product.cpp:000019-000001>];
  own:[
    pcKind:[call];
    pcContent:[reduce((nBlocks,resPtr,&resReduce))];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-34,c-11}];
  end_loc:[{r-34,c-11}];
  data:[resReduce];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000033-000003>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000012-000013>];
  terminal_root:[
    pcKind:[var];
    pcContent:[resReduce];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-34,c-22}];
  end_loc:[{r-34,c-22}];
  data:[resPtr];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000026-000003>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000012-000026>];
  terminal_root:[
    pcKind:[var];
    pcContent:[resPtr];
  ];
  memAccess:[
    loopVars:[
    ];
    loovVarFactors:[
    ];
  ];


  path_str:[builder/test/access_1d/];
  path:[steel_builder_test_suite];
  file:[dot_product.cpp];
  begin_loc:[{r-34,c-30}];
  end_loc:[{r-34,c-30}];
  data:[nBlocks];
  obj:[data_use];

  root:[<builder/test/access_1d/dot_product.cpp:000021-000003>];
  callee_or_op:[<builder/test/access_1d/dot_product.cpp:000012-000045>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlocks];
  ];
  memAccess:[NULL];
*/