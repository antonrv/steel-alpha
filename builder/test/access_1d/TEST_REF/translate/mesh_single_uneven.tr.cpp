//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;


[[steel::task("fooapp_wo")]]
void foo_wo(float * ptr, const unsigned nCols) {
  float init = 13;
  for (unsigned cc = 0; cc < nCols; cc++) {
    ptr[cc] = init;
  }
}

task::coro::dispatcher<app::impl::caller_wo> caller_wo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nElems, const unsigned bSize) {
auto wrap_ptrCaller = dep::wrap_region<1,dep::mesh::direct>(ptrCaller, {/*embeds*/1}, {/*embeds*/bSize}, {/*ranges*/range_t({0, rt::max((nElems/bSize),(1+(nElems/bSize)))})});

  unsigned nBlocksEven = nElems / bSize;

  for (unsigned c = 0; c < nBlocksEven; c++) {
    co_await task::make_async<app::call::caller_wo_fooapp_wo_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(bSize*c)},{/*ranges*/range_t({(bSize*c), (bSize+(bSize*c))})}), bSize );
  }

  unsigned bSizeRemain = nElems % bSize;

  if (bSizeRemain != 0) {
    co_await task::make_async<app::call::caller_wo_fooapp_wo_1>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(bSize*nBlocksEven)},{/*ranges*/range_t({(bSize*nBlocksEven), (bSizeRemain+(bSize*nBlocksEven))})}), bSizeRemain );
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}
