//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;


[[steel::task("fooapp_callee_x")]]
void foo_callee_x(float * ptr, const unsigned nCols) {
  float init = 13;
  for (unsigned cc = 0; cc < nCols; cc++) {
    ptr[cc] += init;
  }
}

[[steel::task("fooapp_callee_y")]]
void foo_callee_y(const float * ptr, const unsigned nCols) {
  float init = 13;
  for (unsigned cc = 0; cc < nCols; cc++) {
    init = ptr[cc];
  }
}


task::coro::dispatcher<app::impl::caller_same_callee> caller_same_callee(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nBlocks, const unsigned blockSize) {
auto wrap_ptrCaller = dep::wrap_region<1,dep::mesh::direct>(ptrCaller, {/*embeds*/1}, {/*embeds*/blockSize}, {/*ranges*/range_t({0, nBlocks})});

  unsigned nBlocksA = nBlocks;
  unsigned blockSizeA = blockSize;
  for (unsigned a = 0; a < nBlocksA; a++) {
    co_await task::make_async<app::call::caller_same_callee_fooapp_callee_x_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(a*blockSizeA)},{/*ranges*/range_t({(a*blockSizeA), (blockSizeA+(a*blockSizeA))})}), blockSizeA );
  }

  unsigned nBlocksB = nBlocks;
  unsigned blockSizeB = blockSize;
  for (unsigned b = 0; b < nBlocksB; b++) {
    co_await task::make_async<app::call::caller_same_callee_fooapp_callee_x_1>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(b*blockSizeB)},{/*ranges*/range_t({(b*blockSizeB), (blockSizeB+(b*blockSizeB))})}), blockSizeB );
  }

  unsigned nBlocksC = nBlocks;
  unsigned blockSizeC = blockSize;
  for (unsigned c = 0; c < nBlocksC; c++) {
    co_await task::make_async<app::call::caller_same_callee_fooapp_callee_x_2>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(blockSizeC*c)},{/*ranges*/range_t({(blockSizeC*c), (blockSizeC+(blockSizeC*c))})}), blockSizeC );
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller_different_callee> caller_different_callee(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nBlocks, const unsigned blockSize) {
auto wrap_ptrCaller = dep::wrap_region<1,dep::mesh::direct>(ptrCaller, {/*embeds*/1}, {/*embeds*/blockSize}, {/*ranges*/range_t({0, nBlocks})});

  unsigned nBlocksA = nBlocks;
  unsigned blockSizeA = blockSize;
  for (unsigned a = 0; a < nBlocksA; a++) {
    co_await task::make_async<app::call::caller_different_callee_fooapp_callee_x_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(a*blockSizeA)},{/*ranges*/range_t({(a*blockSizeA), (blockSizeA+(a*blockSizeA))})}), blockSizeA );
  }

  unsigned nBlocksB = nBlocks;
  unsigned blockSizeB = blockSize;
  for (unsigned b = 0; b < nBlocksB; b++) {
    co_await task::make_async<app::call::caller_different_callee_fooapp_callee_y_1>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_reader({/*coord*/(b*blockSizeB)},{/*ranges*/range_t({(b*blockSizeB), (blockSizeB+(b*blockSizeB))})}), blockSizeB );
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller_same_n_different_callee> caller_same_n_different_callee(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nBlocks, const unsigned blockSize) {
auto wrap_ptrCaller = dep::wrap_region<1,dep::mesh::direct>(ptrCaller, {/*embeds*/1}, {/*embeds*/blockSize}, {/*ranges*/range_t({0, nBlocks})});

  unsigned nBlocksA = nBlocks;
  unsigned blockSizeA = blockSize;
  for (unsigned a = 0; a < nBlocksA; a++) {
    co_await task::make_async<app::call::caller_same_n_different_callee_fooapp_callee_x_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(a*blockSizeA)},{/*ranges*/range_t({(a*blockSizeA), (blockSizeA+(a*blockSizeA))})}), blockSizeA );
  }

  unsigned nBlocksB = nBlocks;
  unsigned blockSizeB = blockSize;
  for (unsigned b = 0; b < nBlocksB; b++) {
    co_await task::make_async<app::call::caller_same_n_different_callee_fooapp_callee_y_1>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_reader({/*coord*/(b*blockSizeB)},{/*ranges*/range_t({(b*blockSizeB), (blockSizeB+(b*blockSizeB))})}), blockSizeB );
  }

  unsigned nBlocksC = nBlocks;
  unsigned blockSizeC = blockSize;
  for (unsigned c = 0; c < nBlocksC; c++) {
    co_await task::make_async<app::call::caller_same_n_different_callee_fooapp_callee_y_2>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_reader({/*coord*/(blockSizeC*c)},{/*ranges*/range_t({(blockSizeC*c), (blockSizeC+(blockSizeC*c))})}), blockSizeC );
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}
