//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("fooapp_wo")]]
void foo(float * ptr, const unsigned nRows, const unsigned nCols, const unsigned stride) {
  float init = 13;
  for (unsigned rr = 0; rr < nRows; rr++) {
    for (unsigned cc = 0; cc < nCols; cc++) {
      ptr[rr*stride + cc] = init;
    }
  }
}

task::coro::dispatcher<app::impl::caller1_foo> caller1_foo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
auto wrap_ptrCaller = dep::wrap_region<2,dep::mesh::direct>(ptrCaller, {/*embeds*/(chunkColsCaller*nColBlocks),1}, {/*embeds*/chunkRowsCaller,chunkColsCaller}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});
  unsigned stride = nColBlocks*chunkColsCaller*chunkRowsCaller;
  unsigned localStride = nColBlocks*chunkColsCaller;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      co_await task::make_async<app::call::caller1_foo_fooapp_wo_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/((r*stride)/localStride),(c*chunkColsCaller)},{/*ranges*/range_t({((r*stride)/localStride), (chunkRowsCaller+((r*stride)/localStride))}),range_t({(c*chunkColsCaller), (chunkColsCaller+(c*chunkColsCaller))})}), chunkRowsCaller, chunkColsCaller, localStride );
    }
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller2_foo> caller2_foo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
auto wrap_ptrCaller = dep::wrap_region<2,dep::mesh::direct>(ptrCaller, {/*embeds*/(chunkColsCaller*nColBlocks),1}, {/*embeds*/chunkRowsCaller,chunkColsCaller}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});
  unsigned localStride = nColBlocks*chunkColsCaller;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      co_await task::make_async<app::call::caller2_foo_fooapp_wo_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(chunkRowsCaller*r),(c*chunkColsCaller)},{/*ranges*/range_t({(chunkRowsCaller*r), (chunkRowsCaller+(chunkRowsCaller*r))}),range_t({(c*chunkColsCaller), (chunkColsCaller+(c*chunkColsCaller))})}), chunkRowsCaller, chunkColsCaller, localStride );
    }
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller3_foo> caller3_foo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nRowBlocks, const unsigned nColBlocks, const unsigned chunkRowsCaller, const unsigned chunkColsCaller) {
auto wrap_ptrCaller = dep::wrap_region<2,dep::mesh::direct>(ptrCaller, {/*embeds*/(chunkColsCaller*nColBlocks),1}, {/*embeds*/chunkRowsCaller,chunkColsCaller}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      co_await task::make_async<app::call::caller3_foo_fooapp_wo_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(chunkRowsCaller*r),(c*chunkColsCaller)},{/*ranges*/range_t({(chunkRowsCaller*r), (chunkRowsCaller+(chunkRowsCaller*r))}),range_t({(c*chunkColsCaller), (chunkColsCaller+(c*chunkColsCaller))})}), chunkRowsCaller, chunkColsCaller, nColBlocks*chunkColsCaller );
    }
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller4_foo> caller4_foo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nRows, const unsigned nCols, const unsigned nRowBlocks, const unsigned nColBlocks) {
auto wrap_ptrCaller = dep::wrap_region<2,dep::mesh::direct>(ptrCaller, {/*embeds*/nCols,1}, {/*embeds*/(nRows/nRowBlocks),(nCols/nColBlocks)}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});
  unsigned chunkRowsCaller = nRows / nRowBlocks;
  unsigned chunkColsCaller = nCols / nColBlocks;
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      co_await task::make_async<app::call::caller4_foo_fooapp_wo_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(chunkRowsCaller*r),(c*chunkColsCaller)},{/*ranges*/range_t({(chunkRowsCaller*r), (chunkRowsCaller+(chunkRowsCaller*r))}),range_t({(c*chunkColsCaller), (chunkColsCaller+(c*chunkColsCaller))})}), chunkRowsCaller, chunkColsCaller, nCols );
    }
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller5_foo> caller5_foo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nRows, const unsigned nCols, const unsigned nRowBlocks, const unsigned nColBlocks) {
auto wrap_ptrCaller = dep::wrap_region<2,dep::mesh::direct>(ptrCaller, {/*embeds*/nCols,1}, {/*embeds*/(nRows/nRowBlocks),(nCols/nColBlocks)}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});
  for (unsigned r = 0; r < nRowBlocks; r++) {
    for (unsigned c = 0; c < nColBlocks; c++) {
      co_await task::make_async<app::call::caller5_foo_fooapp_wo_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/((nRows*r)/nRowBlocks),((c*nCols)/nColBlocks)},{/*ranges*/range_t({((nRows*r)/nRowBlocks), ((nRows/nRowBlocks)+((nRows*r)/nRowBlocks))}),range_t({((c*nCols)/nColBlocks), ((nCols/nColBlocks)+((c*nCols)/nColBlocks))})}), (nRows/nRowBlocks), (nCols/nColBlocks), nCols );
    }
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}
