//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

////
[[steel::task("foo_block_app")]]
void foo_block(const float * bbb, int nCols, int nRows, int nDepth) {
  float r;
  for (int slice = 0; slice < nDepth; slice++) {
    for (int row = 0; row < nRows; row++) {
      for (int col = 0; col < nCols; col++) {
        r = bbb[col + row*nCols + slice*nCols*nRows];
      }
    }
  }
}

task::coro::dispatcher<app::impl::caller_block> caller_block(task::attr::descriptor&  attrDesc, int nColsCaller, int nRowsCaller, int nDepthCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<3,dep::mesh::single>(ppp, {/*embeds*/(nColsCaller*nRowsCaller),nColsCaller,1});

  co_await task::make_async<app::call::caller_block_foo_block_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0,0,0},{/*ranges*/range_t({0, nDepthCaller}),range_t({0, nRowsCaller}),range_t({0, nColsCaller})}), nColsCaller, nRowsCaller, nDepthCaller);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}
