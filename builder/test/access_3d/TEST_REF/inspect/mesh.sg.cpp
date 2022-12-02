steel_builder_test_suite
mesh.cpp
/*

  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-1}];
  end_loc:[{r-12,c-1}];
  data:[voidfoo(float*ptr,constunsignednX,constunsignednY,constunsignednZ,constunsignedlocalStrideY,constunsignedlocalStrideZ){floatinit=13;for(unsignedkk=0;kk<nZ;kk++){for(unsignedjj=0;jj<nY;jj++){for(unsignedii=0;ii<nX;ii++){ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}}}}];
  obj:[fun_def];

  name:[foo];
  args:[
    0:[<builder/test/access_3d/mesh.cpp:000003-000010>];
    1:[<builder/test/access_3d/mesh.cpp:000003-000023>];
    2:[<builder/test/access_3d/mesh.cpp:000003-000042>];
    3:[<builder/test/access_3d/mesh.cpp:000003-000061>];
    4:[<builder/test/access_3d/mesh.cpp:000003-000080>];
    5:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  ];
  retArg:[NULL];
  bodyCalls:[
  ];
  externCalls:[
    0:[<builder/test/access_3d/mesh.cpp:000019-000009>];
    1:[<builder/test/access_3d/mesh.cpp:000033-000009>];
    2:[<builder/test/access_3d/mesh.cpp:000047-000009>];
    3:[<builder/test/access_3d/mesh.cpp:000061-000009>];
  ];
  task:[
    rootFunDef:[<builder/test/access_3d/mesh.cpp:000003-000001>];
    appId:[fooapp_3d];
    appImpl:[foo];
    returnType:[void];
    appendTypeParams:[
    ];
  ];


  path_str:[builder/test/access_3d/];
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
    0:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[factors];
        pcContent:[(localStrideY*localStrideZ)];
      ];
      1:[
        pcKind:[var];
        pcContent:[localStrideY];
      ];
      2:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnZ ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnY ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnX ]];
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
  file:[mesh.cpp];
  begin_loc:[{r-3,c-23}];
  end_loc:[{r-3,c-38}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000007-000034>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-42}];
  end_loc:[{r-3,c-57}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000006-000032>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-61}];
  end_loc:[{r-3,c-76}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000005-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-80}];
  end_loc:[{r-3,c-95}];
  data:[constunsignedl];
  obj:[data_decl];

  declKind:[fargument];
  varName:[localStrideY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000008-000029>];
    1:[<builder/test/access_3d/mesh.cpp:000008-000047>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-109}];
  end_loc:[{r-3,c-124}];
  data:[constunsignedl];
  obj:[data_decl];

  declKind:[fargument];
  varName:[localStrideZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000008-000016>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-3,c-138}];
  end_loc:[{r-12,c-1}];
  data:[{floatinit=13;for(unsignedkk=0;kk<nZ;kk++){for(unsignedjj=0;jj<nY;jj++){for(unsignedii=0;ii<nX;ii++){ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
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


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-4,c-16}];
  end_loc:[{r-4,c-16}];
  data:[13];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000004-000003>];
  terminal_root:[
    pcKind:[num];
    pcContent:[13];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-3}];
  end_loc:[{r-11,c-3}];
  data:[for(unsignedkk=0;kk<nZ;kk++){for(unsignedjj=0;jj<nY;jj++){for(unsignedii=0;ii<nX;ii++){ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-8}];
  end_loc:[{r-5,c-23}];
  data:[kk];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-22}];
  end_loc:[{r-5,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000005-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-25}];
  end_loc:[{r-5,c-30}];
  data:[kk<nZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk lt nZ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-30}];
  end_loc:[{r-5,c-30}];
  data:[nZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000003-000061>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000005-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-34}];
  end_loc:[{r-5,c-36}];
  data:[kk++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[kk incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-5,c-40}];
  end_loc:[{r-11,c-3}];
  data:[{for(unsignedjj=0;jj<nY;jj++){for(unsignedii=0;ii<nX;ii++){ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000003-000138>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-5}];
  end_loc:[{r-10,c-5}];
  data:[for(unsignedjj=0;jj<nY;jj++){for(unsignedii=0;ii<nX;ii++){ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000005-000003>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-10}];
  end_loc:[{r-6,c-25}];
  data:[jj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-24}];
  end_loc:[{r-6,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000006-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-27}];
  end_loc:[{r-6,c-32}];
  data:[jj<nY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj lt nY];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-32}];
  end_loc:[{r-6,c-32}];
  data:[nY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000003-000042>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000006-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-36}];
  end_loc:[{r-6,c-38}];
  data:[jj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[jj incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-6,c-42}];
  end_loc:[{r-10,c-5}];
  data:[{for(unsignedii=0;ii<nX;ii++){ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000005-000040>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-7}];
  end_loc:[{r-9,c-7}];
  data:[for(unsignedii=0;ii<nX;ii++){ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000006-000005>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-12}];
  end_loc:[{r-7,c-27}];
  data:[ii];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-26}];
  end_loc:[{r-7,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000007-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-29}];
  end_loc:[{r-7,c-34}];
  data:[ii<nX];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii lt nX];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-34}];
  end_loc:[{r-7,c-34}];
  data:[nX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000003-000023>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000007-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-38}];
  end_loc:[{r-7,c-40}];
  data:[ii++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ii incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-7,c-44}];
  end_loc:[{r-9,c-7}];
  data:[{ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init;}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000006-000042>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-9}];
  end_loc:[{r-8,c-68}];
  data:[ptr[kk*localStrideZ*localStrideY+jj*localStrideY+ii]=init];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[ptr[(ii+(jj*localStrideY)+(kk*localStrideY*localStrideZ))] assign init];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-13}];
  end_loc:[{r-8,c-13}];
  data:[kk];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000005-000008>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[kk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-16}];
  end_loc:[{r-8,c-16}];
  data:[localStrideZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[localStrideZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-29}];
  end_loc:[{r-8,c-29}];
  data:[localStrideY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[localStrideY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-44}];
  end_loc:[{r-8,c-44}];
  data:[jj];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000006-000010>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[jj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-47}];
  end_loc:[{r-8,c-47}];
  data:[localStrideY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[localStrideY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-62}];
  end_loc:[{r-8,c-62}];
  data:[ii];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000007-000012>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ii];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-8,c-68}];
  end_loc:[{r-8,c-68}];
  data:[init];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000004-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000008-000009>];
  terminal_root:[
    pcKind:[var];
    pcContent:[init];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-1}];
  end_loc:[{r-23,c-1}];
  data:[voidcaller1_foo(float*ptr,constunsignednBlockX,constunsignednBlockY,constunsignednBlockZ,constunsignedbSizeX,constunsignedbSizeY,constunsignedbSizeZ){for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}}];
  obj:[fun_def];

  name:[caller1_foo];
  args:[
    0:[<builder/test/access_3d/mesh.cpp:000014-000018>];
    1:[<builder/test/access_3d/mesh.cpp:000014-000031>];
    2:[<builder/test/access_3d/mesh.cpp:000014-000055>];
    3:[<builder/test/access_3d/mesh.cpp:000014-000079>];
    4:[<builder/test/access_3d/mesh.cpp:000014-000103>];
    5:[<builder/test/access_3d/mesh.cpp:000014-000126>];
    6:[<builder/test/access_3d/mesh.cpp:000014-000149>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_3d/mesh.cpp:000019-000009>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_3d/mesh.cpp:000014-000001>];
    appId:[caller1_foo];
    appImpl:[caller1_foo];
    returnType:[task::coro::dispatcher<app::impl::caller1_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-18}];
  end_loc:[{r-14,c-26}];
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
    0:[<builder/test/access_3d/mesh.cpp:000019-000015>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[factors];
        pcContent:[((bSizeX*nBlockX)*(bSizeY*nBlockY))];
      ];
      1:[
        pcKind:[factors];
        pcContent:[(bSizeX*nBlockX)];
      ];
      2:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(bSizeZ+(bSizeZ*nBlockZ)) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(bSizeY+(bSizeY*nBlockY)) ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(bSizeX+(bSizeX*nBlockX)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockZ ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockY ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockX ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-31}];
  end_loc:[{r-14,c-46}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000018-000034>];
    1:[<builder/test/access_3d/mesh.cpp:000019-000029>];
    2:[<builder/test/access_3d/mesh.cpp:000019-000071>];
    3:[<builder/test/access_3d/mesh.cpp:000019-000131>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-55}];
  end_loc:[{r-14,c-70}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000017-000032>];
    1:[<builder/test/access_3d/mesh.cpp:000019-000044>];
    2:[<builder/test/access_3d/mesh.cpp:000019-000147>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-79}];
  end_loc:[{r-14,c-94}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000016-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-103}];
  end_loc:[{r-14,c-118}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000019-000022>];
    1:[<builder/test/access_3d/mesh.cpp:000019-000064>];
    2:[<builder/test/access_3d/mesh.cpp:000019-000091>];
    3:[<builder/test/access_3d/mesh.cpp:000019-000100>];
    4:[<builder/test/access_3d/mesh.cpp:000019-000124>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-126}];
  end_loc:[{r-14,c-141}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000019-000037>];
    1:[<builder/test/access_3d/mesh.cpp:000019-000079>];
    2:[<builder/test/access_3d/mesh.cpp:000019-000108>];
    3:[<builder/test/access_3d/mesh.cpp:000019-000140>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-149}];
  end_loc:[{r-14,c-164}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000019-000052>];
    1:[<builder/test/access_3d/mesh.cpp:000019-000116>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-14,c-172}];
  end_loc:[{r-23,c-1}];
  data:[{for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-3}];
  end_loc:[{r-22,c-3}];
  data:[for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-8}];
  end_loc:[{r-16,c-23}];
  data:[bk];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-22}];
  end_loc:[{r-16,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000016-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-25}];
  end_loc:[{r-16,c-30}];
  data:[bk<nBlockZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk lt nBlockZ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-30}];
  end_loc:[{r-16,c-30}];
  data:[nBlockZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000079>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000016-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-39}];
  end_loc:[{r-16,c-41}];
  data:[bk++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-16,c-45}];
  end_loc:[{r-22,c-3}];
  data:[{for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000014-000172>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-5}];
  end_loc:[{r-21,c-5}];
  data:[for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000016-000003>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-10}];
  end_loc:[{r-17,c-25}];
  data:[bj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-24}];
  end_loc:[{r-17,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000017-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-27}];
  end_loc:[{r-17,c-32}];
  data:[bj<nBlockY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj lt nBlockY];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-32}];
  end_loc:[{r-17,c-32}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000017-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-41}];
  end_loc:[{r-17,c-43}];
  data:[bj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-17,c-47}];
  end_loc:[{r-21,c-5}];
  data:[{for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000016-000045>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-18,c-7}];
  end_loc:[{r-20,c-7}];
  data:[for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000017-000005>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-18,c-12}];
  end_loc:[{r-18,c-27}];
  data:[bi];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-18,c-26}];
  end_loc:[{r-18,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000018-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-18,c-29}];
  end_loc:[{r-18,c-34}];
  data:[bi<nBlockX];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi lt nBlockX];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-18,c-34}];
  end_loc:[{r-18,c-34}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000018-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-18,c-43}];
  end_loc:[{r-18,c-45}];
  data:[bi++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-18,c-49}];
  end_loc:[{r-20,c-7}];
  data:[{foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000017-000047>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-9}];
  end_loc:[{r-19,c-155}];
  data:[foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY)];
  obj:[fun_call];

  callee:[<builder/test/access_3d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_3d/mesh.cpp:000014-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((bSizeX,bSizeY,bSizeZ,&ptr[((bSizeX*bi)+(bSizeX*bSizeY*bj*nBlockX)+(bSizeX*bSizeY*bSizeZ*bk*nBlockX*nBlockY))],(bSizeX*nBlockX),(bSizeY*nBlockY)))];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-15}];
  end_loc:[{r-19,c-15}];
  data:[ptr];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000018>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[bk];
      ];
      1:[
        pcKind:[var];
        pcContent:[bj];
      ];
      2:[
        pcKind:[var];
        pcContent:[bi];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(bSizeX*bSizeY*bSizeZ*nBlockX*nBlockY)];
      ];
      1:[
        pcKind:[factors];
        pcContent:[(bSizeX*bSizeY*nBlockX)];
      ];
      2:[
        pcKind:[var];
        pcContent:[bSizeX];
      ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-19}];
  end_loc:[{r-19,c-19}];
  data:[bk];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000016-000008>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-22}];
  end_loc:[{r-19,c-22}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-29}];
  end_loc:[{r-19,c-29}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-37}];
  end_loc:[{r-19,c-37}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-44}];
  end_loc:[{r-19,c-44}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-52}];
  end_loc:[{r-19,c-52}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-61}];
  end_loc:[{r-19,c-61}];
  data:[bj];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000017-000010>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-64}];
  end_loc:[{r-19,c-64}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-71}];
  end_loc:[{r-19,c-71}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-79}];
  end_loc:[{r-19,c-79}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-88}];
  end_loc:[{r-19,c-88}];
  data:[bi];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000018-000012>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bi];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-91}];
  end_loc:[{r-19,c-91}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-100}];
  end_loc:[{r-19,c-100}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-108}];
  end_loc:[{r-19,c-108}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000042>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-116}];
  end_loc:[{r-19,c-116}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000061>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-124}];
  end_loc:[{r-19,c-124}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-131}];
  end_loc:[{r-19,c-131}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-140}];
  end_loc:[{r-19,c-140}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-19,c-147}];
  end_loc:[{r-19,c-147}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000014-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-1}];
  end_loc:[{r-37,c-1}];
  data:[voidcaller2_foo(float*ptr,constunsignednBlockX,constunsignednBlockY,constunsignednBlockZ,constunsignedbSizeX,constunsignedbSizeY,constunsignedbSizeZ){unsignedstrideY=bSizeX*nBlockX;unsignedstrideZ=bSizeY*nBlockY;for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}}}}];
  obj:[fun_def];

  name:[caller2_foo];
  args:[
    0:[<builder/test/access_3d/mesh.cpp:000025-000018>];
    1:[<builder/test/access_3d/mesh.cpp:000025-000031>];
    2:[<builder/test/access_3d/mesh.cpp:000025-000055>];
    3:[<builder/test/access_3d/mesh.cpp:000025-000079>];
    4:[<builder/test/access_3d/mesh.cpp:000025-000103>];
    5:[<builder/test/access_3d/mesh.cpp:000025-000126>];
    6:[<builder/test/access_3d/mesh.cpp:000025-000149>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_3d/mesh.cpp:000033-000009>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_3d/mesh.cpp:000025-000001>];
    appId:[caller2_foo];
    appImpl:[caller2_foo];
    returnType:[task::coro::dispatcher<app::impl::caller2_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-18}];
  end_loc:[{r-25,c-26}];
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
    0:[<builder/test/access_3d/mesh.cpp:000033-000015>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[factors];
        pcContent:[(strideY*strideZ)];
      ];
      1:[
        pcKind:[var];
        pcContent:[strideY];
      ];
      2:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min(0/(strideY*strideZ)); Max(bSizeZ+((bSizeX*bSizeY*bSizeZ*nBlockX*nBlockY*nBlockZ)/(strideY*strideZ))) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min(0/strideY); Max(bSizeY+((bSizeX*bSizeY*nBlockX*nBlockY)/strideY)) ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(bSizeX+(bSizeX*nBlockX)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockZ ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockY ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockX ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-31}];
  end_loc:[{r-25,c-46}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000027-000029>];
    1:[<builder/test/access_3d/mesh.cpp:000032-000034>];
    2:[<builder/test/access_3d/mesh.cpp:000033-000029>];
    3:[<builder/test/access_3d/mesh.cpp:000033-000071>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-55}];
  end_loc:[{r-25,c-70}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000028-000029>];
    1:[<builder/test/access_3d/mesh.cpp:000031-000032>];
    2:[<builder/test/access_3d/mesh.cpp:000033-000044>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-79}];
  end_loc:[{r-25,c-94}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000030-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-103}];
  end_loc:[{r-25,c-118}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000027-000022>];
    1:[<builder/test/access_3d/mesh.cpp:000033-000022>];
    2:[<builder/test/access_3d/mesh.cpp:000033-000064>];
    3:[<builder/test/access_3d/mesh.cpp:000033-000091>];
    4:[<builder/test/access_3d/mesh.cpp:000033-000100>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-126}];
  end_loc:[{r-25,c-141}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000028-000022>];
    1:[<builder/test/access_3d/mesh.cpp:000033-000037>];
    2:[<builder/test/access_3d/mesh.cpp:000033-000079>];
    3:[<builder/test/access_3d/mesh.cpp:000033-000108>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-149}];
  end_loc:[{r-25,c-164}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000033-000052>];
    1:[<builder/test/access_3d/mesh.cpp:000033-000116>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-25,c-172}];
  end_loc:[{r-37,c-1}];
  data:[{unsignedstrideY=bSizeX*nBlockX;unsignedstrideZ=bSizeY*nBlockY;for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-27,c-3}];
  end_loc:[{r-27,c-36}];
  data:[strideY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[strideY init (bSizeX*nBlockX)];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-27,c-22}];
  end_loc:[{r-27,c-22}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-27,c-29}];
  end_loc:[{r-27,c-29}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000027-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-28,c-3}];
  end_loc:[{r-28,c-36}];
  data:[strideZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[strideZ init (bSizeY*nBlockY)];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-28,c-22}];
  end_loc:[{r-28,c-22}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000028-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-28,c-29}];
  end_loc:[{r-28,c-29}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000028-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-30,c-3}];
  end_loc:[{r-36,c-3}];
  data:[for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-30,c-8}];
  end_loc:[{r-30,c-23}];
  data:[bk];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-30,c-22}];
  end_loc:[{r-30,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000030-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-30,c-25}];
  end_loc:[{r-30,c-30}];
  data:[bk<nBlockZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk lt nBlockZ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-30,c-30}];
  end_loc:[{r-30,c-30}];
  data:[nBlockZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000079>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000030-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-30,c-39}];
  end_loc:[{r-30,c-41}];
  data:[bk++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-30,c-45}];
  end_loc:[{r-36,c-3}];
  data:[{for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000025-000172>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-5}];
  end_loc:[{r-35,c-5}];
  data:[for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000030-000003>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-10}];
  end_loc:[{r-31,c-25}];
  data:[bj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-24}];
  end_loc:[{r-31,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000031-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-27}];
  end_loc:[{r-31,c-32}];
  data:[bj<nBlockY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj lt nBlockY];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-32}];
  end_loc:[{r-31,c-32}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000031-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-41}];
  end_loc:[{r-31,c-43}];
  data:[bj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-31,c-47}];
  end_loc:[{r-35,c-5}];
  data:[{for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000030-000045>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-7}];
  end_loc:[{r-34,c-7}];
  data:[for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000031-000005>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-12}];
  end_loc:[{r-32,c-27}];
  data:[bi];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-26}];
  end_loc:[{r-32,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000032-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-29}];
  end_loc:[{r-32,c-34}];
  data:[bi<nBlockX];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi lt nBlockX];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-34}];
  end_loc:[{r-32,c-34}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000032-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-43}];
  end_loc:[{r-32,c-45}];
  data:[bi++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-32,c-49}];
  end_loc:[{r-34,c-7}];
  data:[{foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000031-000047>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-9}];
  end_loc:[{r-33,c-141}];
  data:[foo(&ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ+bj*bSizeX*nBlockX*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,strideZ)];
  obj:[fun_call];

  callee:[<builder/test/access_3d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_3d/mesh.cpp:000025-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((bSizeX,bSizeY,bSizeZ,strideY,strideZ,&ptr[((bSizeX*bi)+(bSizeX*bSizeY*bj*nBlockX)+(bSizeX*bSizeY*bSizeZ*bk*nBlockX*nBlockY))]))];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-15}];
  end_loc:[{r-33,c-15}];
  data:[ptr];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000018>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[bk];
      ];
      1:[
        pcKind:[var];
        pcContent:[bj];
      ];
      2:[
        pcKind:[var];
        pcContent:[bi];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(bSizeX*bSizeY*bSizeZ*nBlockX*nBlockY)];
      ];
      1:[
        pcKind:[factors];
        pcContent:[(bSizeX*bSizeY*nBlockX)];
      ];
      2:[
        pcKind:[var];
        pcContent:[bSizeX];
      ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-19}];
  end_loc:[{r-33,c-19}];
  data:[bk];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000030-000008>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-22}];
  end_loc:[{r-33,c-22}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-29}];
  end_loc:[{r-33,c-29}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-37}];
  end_loc:[{r-33,c-37}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-44}];
  end_loc:[{r-33,c-44}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-52}];
  end_loc:[{r-33,c-52}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-61}];
  end_loc:[{r-33,c-61}];
  data:[bj];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000031-000010>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-64}];
  end_loc:[{r-33,c-64}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-71}];
  end_loc:[{r-33,c-71}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-79}];
  end_loc:[{r-33,c-79}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-88}];
  end_loc:[{r-33,c-88}];
  data:[bi];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000032-000012>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bi];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-91}];
  end_loc:[{r-33,c-91}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-100}];
  end_loc:[{r-33,c-100}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-108}];
  end_loc:[{r-33,c-108}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000042>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-116}];
  end_loc:[{r-33,c-116}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000025-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000061>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-124}];
  end_loc:[{r-33,c-124}];
  data:[strideY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000027-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  terminal_root:[
    pcKind:[var];
    pcContent:[strideY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-33,c-133}];
  end_loc:[{r-33,c-133}];
  data:[strideZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000028-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  terminal_root:[
    pcKind:[var];
    pcContent:[strideZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-1}];
  end_loc:[{r-51,c-1}];
  data:[voidcaller3_foo(float*ptr,constunsignednBlockX,constunsignednBlockY,constunsignednBlockZ,constunsignedbSizeX,constunsignedbSizeY,constunsignedbSizeZ){unsignedstrideY=bSizeX*nBlockX;unsignedstrideYZ=bSizeX*nBlockX*bSizeY*nBlockY;for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}}];
  obj:[fun_def];

  name:[caller3_foo];
  args:[
    0:[<builder/test/access_3d/mesh.cpp:000039-000018>];
    1:[<builder/test/access_3d/mesh.cpp:000039-000031>];
    2:[<builder/test/access_3d/mesh.cpp:000039-000055>];
    3:[<builder/test/access_3d/mesh.cpp:000039-000079>];
    4:[<builder/test/access_3d/mesh.cpp:000039-000103>];
    5:[<builder/test/access_3d/mesh.cpp:000039-000126>];
    6:[<builder/test/access_3d/mesh.cpp:000039-000149>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_3d/mesh.cpp:000047-000009>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_3d/mesh.cpp:000039-000001>];
    appId:[caller3_foo];
    appImpl:[caller3_foo];
    returnType:[task::coro::dispatcher<app::impl::caller3_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-18}];
  end_loc:[{r-39,c-26}];
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
    0:[<builder/test/access_3d/mesh.cpp:000047-000015>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[factors];
        pcContent:[((bSizeX*nBlockX)*(bSizeY*nBlockY))];
      ];
      1:[
        pcKind:[factors];
        pcContent:[(bSizeX*nBlockX)];
      ];
      2:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min(0/(bSizeX*bSizeY*nBlockX*nBlockY)); Max(bSizeZ+((bSizeZ*nBlockZ*strideYZ)/(bSizeX*bSizeY*nBlockX*nBlockY))) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min(0/(bSizeX*nBlockX)); Max(bSizeY+((bSizeY*nBlockY*strideY)/(bSizeX*nBlockX))) ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(bSizeX+(bSizeX*nBlockX)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockZ ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockY ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockX ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-31}];
  end_loc:[{r-39,c-46}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000041-000029>];
    1:[<builder/test/access_3d/mesh.cpp:000042-000030>];
    2:[<builder/test/access_3d/mesh.cpp:000046-000034>];
    3:[<builder/test/access_3d/mesh.cpp:000047-000103>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-55}];
  end_loc:[{r-39,c-70}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000042-000045>];
    1:[<builder/test/access_3d/mesh.cpp:000045-000032>];
    2:[<builder/test/access_3d/mesh.cpp:000047-000119>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-79}];
  end_loc:[{r-39,c-94}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000044-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-103}];
  end_loc:[{r-39,c-118}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000041-000022>];
    1:[<builder/test/access_3d/mesh.cpp:000042-000023>];
    2:[<builder/test/access_3d/mesh.cpp:000047-000063>];
    3:[<builder/test/access_3d/mesh.cpp:000047-000072>];
    4:[<builder/test/access_3d/mesh.cpp:000047-000096>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-126}];
  end_loc:[{r-39,c-141}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000042-000038>];
    1:[<builder/test/access_3d/mesh.cpp:000047-000051>];
    2:[<builder/test/access_3d/mesh.cpp:000047-000080>];
    3:[<builder/test/access_3d/mesh.cpp:000047-000112>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-149}];
  end_loc:[{r-39,c-164}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000047-000031>];
    1:[<builder/test/access_3d/mesh.cpp:000047-000088>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-39,c-172}];
  end_loc:[{r-51,c-1}];
  data:[{unsignedstrideY=bSizeX*nBlockX;unsignedstrideYZ=bSizeX*nBlockX*bSizeY*nBlockY;for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-41,c-3}];
  end_loc:[{r-41,c-36}];
  data:[strideY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[strideY init (bSizeX*nBlockX)];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-41,c-22}];
  end_loc:[{r-41,c-22}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000041-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-41,c-29}];
  end_loc:[{r-41,c-29}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000041-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-3}];
  end_loc:[{r-42,c-52}];
  data:[strideYZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[strideYZ init (bSizeX*bSizeY*nBlockX*nBlockY)];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-23}];
  end_loc:[{r-42,c-23}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000042-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-30}];
  end_loc:[{r-42,c-30}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000042-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-38}];
  end_loc:[{r-42,c-38}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000042-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-42,c-45}];
  end_loc:[{r-42,c-45}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000042-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-3}];
  end_loc:[{r-50,c-3}];
  data:[for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-8}];
  end_loc:[{r-44,c-23}];
  data:[bk];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-22}];
  end_loc:[{r-44,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000044-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-25}];
  end_loc:[{r-44,c-30}];
  data:[bk<nBlockZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk lt nBlockZ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-30}];
  end_loc:[{r-44,c-30}];
  data:[nBlockZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000079>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000044-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-39}];
  end_loc:[{r-44,c-41}];
  data:[bk++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-44,c-45}];
  end_loc:[{r-50,c-3}];
  data:[{for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000039-000172>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-45,c-5}];
  end_loc:[{r-49,c-5}];
  data:[for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000044-000003>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-45,c-10}];
  end_loc:[{r-45,c-25}];
  data:[bj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-45,c-24}];
  end_loc:[{r-45,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000045-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-45,c-27}];
  end_loc:[{r-45,c-32}];
  data:[bj<nBlockY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj lt nBlockY];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-45,c-32}];
  end_loc:[{r-45,c-32}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000045-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-45,c-41}];
  end_loc:[{r-45,c-43}];
  data:[bj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-45,c-47}];
  end_loc:[{r-49,c-5}];
  data:[{for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000044-000045>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-46,c-7}];
  end_loc:[{r-48,c-7}];
  data:[for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000045-000005>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-46,c-12}];
  end_loc:[{r-46,c-27}];
  data:[bi];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-46,c-26}];
  end_loc:[{r-46,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000046-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-46,c-29}];
  end_loc:[{r-46,c-34}];
  data:[bi<nBlockX];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi lt nBlockX];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-46,c-34}];
  end_loc:[{r-46,c-34}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000046-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-46,c-43}];
  end_loc:[{r-46,c-45}];
  data:[bi++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-46,c-49}];
  end_loc:[{r-48,c-7}];
  data:[{foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000045-000047>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-9}];
  end_loc:[{r-47,c-127}];
  data:[foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,bSizeX*nBlockX,bSizeY*nBlockY)];
  obj:[fun_call];

  callee:[<builder/test/access_3d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_3d/mesh.cpp:000039-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((bSizeX,bSizeY,bSizeZ,&ptr[((bSizeX*bi)+(bSizeY*bj*strideY)+(bSizeZ*bk*strideYZ))],(bSizeX*nBlockX),(bSizeY*nBlockY)))];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-15}];
  end_loc:[{r-47,c-15}];
  data:[ptr];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000018>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[bk];
      ];
      1:[
        pcKind:[var];
        pcContent:[bj];
      ];
      2:[
        pcKind:[var];
        pcContent:[bi];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(bSizeZ*strideYZ)];
      ];
      1:[
        pcKind:[factors];
        pcContent:[(bSizeY*strideY)];
      ];
      2:[
        pcKind:[var];
        pcContent:[bSizeX];
      ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-19}];
  end_loc:[{r-47,c-19}];
  data:[bk];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000044-000008>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-22}];
  end_loc:[{r-47,c-22}];
  data:[strideYZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000042-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[strideYZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-31}];
  end_loc:[{r-47,c-31}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-40}];
  end_loc:[{r-47,c-40}];
  data:[bj];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000045-000010>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-43}];
  end_loc:[{r-47,c-43}];
  data:[strideY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000041-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[strideY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-51}];
  end_loc:[{r-47,c-51}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-60}];
  end_loc:[{r-47,c-60}];
  data:[bi];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000046-000012>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bi];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-63}];
  end_loc:[{r-47,c-63}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-72}];
  end_loc:[{r-47,c-72}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-80}];
  end_loc:[{r-47,c-80}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000042>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-88}];
  end_loc:[{r-47,c-88}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000061>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-96}];
  end_loc:[{r-47,c-96}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-103}];
  end_loc:[{r-47,c-103}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-112}];
  end_loc:[{r-47,c-112}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-47,c-119}];
  end_loc:[{r-47,c-119}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000039-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-1}];
  end_loc:[{r-65,c-1}];
  data:[voidcaller4_foo(float*ptr,constunsignednBlockX,constunsignednBlockY,constunsignednBlockZ,constunsignedbSizeX,constunsignedbSizeY,constunsignedbSizeZ){unsignedstrideY=bSizeX*nBlockX;unsignedstrideYZ=bSizeX*nBlockX*bSizeY*nBlockY;for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}}}}];
  obj:[fun_def];

  name:[caller4_foo];
  args:[
    0:[<builder/test/access_3d/mesh.cpp:000053-000018>];
    1:[<builder/test/access_3d/mesh.cpp:000053-000031>];
    2:[<builder/test/access_3d/mesh.cpp:000053-000055>];
    3:[<builder/test/access_3d/mesh.cpp:000053-000079>];
    4:[<builder/test/access_3d/mesh.cpp:000053-000103>];
    5:[<builder/test/access_3d/mesh.cpp:000053-000126>];
    6:[<builder/test/access_3d/mesh.cpp:000053-000149>];
  ];
  retArg:[NULL];
  bodyCalls:[
    0:[<builder/test/access_3d/mesh.cpp:000061-000009>];
  ];
  externCalls:[
  ];
  task:[
    rootFunDef:[<builder/test/access_3d/mesh.cpp:000053-000001>];
    appId:[caller4_foo];
    appImpl:[caller4_foo];
    returnType:[task::coro::dispatcher<app::impl::caller4_foo>];
    appendTypeParams:[
      0:[task::attr::descriptor& ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-18}];
  end_loc:[{r-53,c-26}];
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
    0:[<builder/test/access_3d/mesh.cpp:000061-000015>];
  ];
  loopVar:[NULL];
  memGuard:[
    globalEmbeds:[
      0:[
        pcKind:[factors];
        pcContent:[(strideY*(bSizeY*nBlockY))];
      ];
      1:[
        pcKind:[var];
        pcContent:[strideY];
      ];
      2:[
        pcKind:[num];
        pcContent:[1];
      ];
    ];
    globalRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min(0/(bSizeY*nBlockY*strideY)); Max(bSizeZ+((bSizeZ*nBlockZ*strideYZ)/(bSizeY*nBlockY*strideY))) ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(bSizeY+(bSizeY*nBlockY)) ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; Max(bSizeX+(bSizeX*nBlockX)) ]];
      ];
    ];
    globalCallRanges:[
      0:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockZ ]];
      ];
      1:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockY ]];
      ];
      2:[
        pcKind:[range];
        pcContent:[range[ Min0; MaxnBlockX ]];
      ];
    ];
    globalOffsets:[
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-31}];
  end_loc:[{r-53,c-46}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000055-000029>];
    1:[<builder/test/access_3d/mesh.cpp:000056-000030>];
    2:[<builder/test/access_3d/mesh.cpp:000060-000034>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-55}];
  end_loc:[{r-53,c-70}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000056-000045>];
    1:[<builder/test/access_3d/mesh.cpp:000059-000032>];
    2:[<builder/test/access_3d/mesh.cpp:000061-000112>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-79}];
  end_loc:[{r-53,c-94}];
  data:[constunsignedn];
  obj:[data_decl];

  declKind:[fargument];
  varName:[nBlockZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000058-000030>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-103}];
  end_loc:[{r-53,c-118}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeX];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000055-000022>];
    1:[<builder/test/access_3d/mesh.cpp:000056-000023>];
    2:[<builder/test/access_3d/mesh.cpp:000061-000063>];
    3:[<builder/test/access_3d/mesh.cpp:000061-000072>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-126}];
  end_loc:[{r-53,c-141}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeY];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000056-000038>];
    1:[<builder/test/access_3d/mesh.cpp:000061-000051>];
    2:[<builder/test/access_3d/mesh.cpp:000061-000080>];
    3:[<builder/test/access_3d/mesh.cpp:000061-000105>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-149}];
  end_loc:[{r-53,c-164}];
  data:[constunsignedb];
  obj:[data_decl];

  declKind:[fargument];
  varName:[bSizeZ];
  typeName:[unsigned];
  translationType:[std::add_const_t<unsigned>];
  typeQual:[cnst];
  indir:[copy];
  indirQual:[undefined];
  allowAcc:[read_only];
  dUses:[
    0:[<builder/test/access_3d/mesh.cpp:000061-000031>];
    1:[<builder/test/access_3d/mesh.cpp:000061-000088>];
  ];
  loopVar:[NULL];
  memGuard:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-53,c-172}];
  end_loc:[{r-65,c-1}];
  data:[{unsignedstrideY=bSizeX*nBlockX;unsignedstrideYZ=bSizeX*nBlockX*bSizeY*nBlockY;for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}}}}];
  obj:[fun_ctxt];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-55,c-3}];
  end_loc:[{r-55,c-36}];
  data:[strideY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[strideY init (bSizeX*nBlockX)];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-55,c-22}];
  end_loc:[{r-55,c-22}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000055-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-55,c-29}];
  end_loc:[{r-55,c-29}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000055-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-56,c-3}];
  end_loc:[{r-56,c-52}];
  data:[strideYZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[strideYZ init (bSizeX*bSizeY*nBlockX*nBlockY)];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-56,c-23}];
  end_loc:[{r-56,c-23}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000056-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-56,c-30}];
  end_loc:[{r-56,c-30}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000056-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-56,c-38}];
  end_loc:[{r-56,c-38}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000056-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-56,c-45}];
  end_loc:[{r-56,c-45}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000056-000003>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-58,c-3}];
  end_loc:[{r-64,c-3}];
  data:[for(unsignedbk=0;bk<nBlockZ;bk++){for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}}}];
  obj:[fun_loop];

  parent:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-58,c-8}];
  end_loc:[{r-58,c-23}];
  data:[bk];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-58,c-22}];
  end_loc:[{r-58,c-22}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000058-000008>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-58,c-25}];
  end_loc:[{r-58,c-30}];
  data:[bk<nBlockZ];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk lt nBlockZ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-58,c-30}];
  end_loc:[{r-58,c-30}];
  data:[nBlockZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000079>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000058-000025>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-58,c-39}];
  end_loc:[{r-58,c-41}];
  data:[bk++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bk incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-58,c-45}];
  end_loc:[{r-64,c-3}];
  data:[{for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000053-000172>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-59,c-5}];
  end_loc:[{r-63,c-5}];
  data:[for(unsignedbj=0;bj<nBlockY;bj++){for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000058-000003>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-59,c-10}];
  end_loc:[{r-59,c-25}];
  data:[bj];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-59,c-24}];
  end_loc:[{r-59,c-24}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000059-000010>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-59,c-27}];
  end_loc:[{r-59,c-32}];
  data:[bj<nBlockY];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj lt nBlockY];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-59,c-32}];
  end_loc:[{r-59,c-32}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000059-000027>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-59,c-41}];
  end_loc:[{r-59,c-43}];
  data:[bj++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bj incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-59,c-47}];
  end_loc:[{r-63,c-5}];
  data:[{for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000058-000045>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-60,c-7}];
  end_loc:[{r-62,c-7}];
  data:[for(unsignedbi=0;bi<nBlockX;bi++){foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}];
  obj:[fun_loop];

  parent:[<builder/test/access_3d/mesh.cpp:000059-000005>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-60,c-12}];
  end_loc:[{r-60,c-27}];
  data:[bi];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi init 0];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-60,c-26}];
  end_loc:[{r-60,c-26}];
  data:[0];
  obj:[data_use];

  root:[NULL];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000060-000012>];
  terminal_root:[
    pcKind:[num];
    pcContent:[0];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-60,c-29}];
  end_loc:[{r-60,c-34}];
  data:[bi<nBlockX];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi lt nBlockX];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-60,c-34}];
  end_loc:[{r-60,c-34}];
  data:[nBlockX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000031>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000060-000029>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-60,c-43}];
  end_loc:[{r-60,c-45}];
  data:[bi++];
  obj:[bin_op];

  own:[
    pcKind:[binop];
    pcContent:[bi incr 1];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-60,c-49}];
  end_loc:[{r-62,c-7}];
  data:[{foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY);}];
  obj:[fun_ctxt];

  parent:[<builder/test/access_3d/mesh.cpp:000059-000047>];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-9}];
  end_loc:[{r-61,c-120}];
  data:[foo(&ptr[bk*strideYZ*bSizeZ+bj*strideY*bSizeY+bi*bSizeX],bSizeX,bSizeY,bSizeZ,strideY,bSizeY*nBlockY)];
  obj:[fun_call];

  callee:[<builder/test/access_3d/mesh.cpp:000003-000001>];
  caller:[<builder/test/access_3d/mesh.cpp:000053-000001>];
  own:[
    pcKind:[call];
    pcContent:[foo((bSizeX,bSizeY,bSizeZ,strideY,&ptr[((bSizeX*bi)+(bSizeY*bj*strideY)+(bSizeZ*bk*strideYZ))],(bSizeY*nBlockY)))];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-15}];
  end_loc:[{r-61,c-15}];
  data:[ptr];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000018>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[ptr];
  ];
  memAccess:[
    loopVars:[
      0:[
        pcKind:[var];
        pcContent:[bk];
      ];
      1:[
        pcKind:[var];
        pcContent:[bj];
      ];
      2:[
        pcKind:[var];
        pcContent:[bi];
      ];
    ];
    loovVarFactors:[
      0:[
        pcKind:[factors];
        pcContent:[(bSizeZ*strideYZ)];
      ];
      1:[
        pcKind:[factors];
        pcContent:[(bSizeY*strideY)];
      ];
      2:[
        pcKind:[var];
        pcContent:[bSizeX];
      ];
    ];
  ];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-19}];
  end_loc:[{r-61,c-19}];
  data:[bk];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000058-000008>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bk];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-22}];
  end_loc:[{r-61,c-22}];
  data:[strideYZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000056-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[strideYZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-31}];
  end_loc:[{r-61,c-31}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-40}];
  end_loc:[{r-61,c-40}];
  data:[bj];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000059-000010>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bj];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-43}];
  end_loc:[{r-61,c-43}];
  data:[strideY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000055-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[strideY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-51}];
  end_loc:[{r-61,c-51}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-60}];
  end_loc:[{r-61,c-60}];
  data:[bi];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000060-000012>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bi];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-63}];
  end_loc:[{r-61,c-63}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000010>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-72}];
  end_loc:[{r-61,c-72}];
  data:[bSizeX];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000103>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000023>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeX];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-80}];
  end_loc:[{r-61,c-80}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000042>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-88}];
  end_loc:[{r-61,c-88}];
  data:[bSizeZ];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000149>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000061>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeZ];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-96}];
  end_loc:[{r-61,c-96}];
  data:[strideY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000055-000003>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000080>];
  terminal_root:[
    pcKind:[var];
    pcContent:[strideY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-105}];
  end_loc:[{r-61,c-105}];
  data:[bSizeY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000126>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  terminal_root:[
    pcKind:[var];
    pcContent:[bSizeY];
  ];
  memAccess:[NULL];


  path_str:[builder/test/access_3d/];
  path:[steel_builder_test_suite];
  file:[mesh.cpp];
  begin_loc:[{r-61,c-112}];
  end_loc:[{r-61,c-112}];
  data:[nBlockY];
  obj:[data_use];

  root:[<builder/test/access_3d/mesh.cpp:000053-000055>];
  callee_or_op:[<builder/test/access_3d/mesh.cpp:000003-000109>];
  terminal_root:[
    pcKind:[var];
    pcContent:[nBlockY];
  ];
  memAccess:[NULL];
*/