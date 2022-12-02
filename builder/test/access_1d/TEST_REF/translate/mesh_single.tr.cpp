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

task::coro::dispatcher<app::impl::caller_wo> caller_wo(task::attr::descriptor&  attrDesc, float * ptrCaller, const unsigned nColBlocks, const unsigned chunkColsCaller) {
auto wrap_ptrCaller = dep::wrap_region<1,dep::mesh::direct>(ptrCaller, {/*embeds*/1}, {/*embeds*/chunkColsCaller}, {/*ranges*/range_t({0, nColBlocks})});
  for (unsigned c = 0; c < nColBlocks; c++) {
    co_await task::make_async<app::call::caller_wo_fooapp_wo_0>(attrDesc.depth + 1,  wrap_ptrCaller.emit_bnd_writer({/*coord*/(c*chunkColsCaller)},{/*ranges*/range_t({(c*chunkColsCaller), (chunkColsCaller+(c*chunkColsCaller))})}), chunkColsCaller );
  }

while (not dep::all_destroyable(wrap_ptrCaller)) { co_await task::coro::suspend(); }
}
