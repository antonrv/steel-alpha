//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

////
[[steel::task("foo_rectangle_app")]]
void foo_rectangle(const float * bbb, int nCols, int nRows) {
  float r = 13.f;
  for (int row = 0; row < nRows; row++) {
    for (int col = 0; col < nCols; col++) {
      r = bbb[col + row*nCols];
    }
  }
}

task::coro::dispatcher<app::impl::caller_rectangle> caller_rectangle(task::attr::descriptor&  attrDesc, int nColsCaller, int nRowsCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<2,dep::mesh::single>(ppp, {/*embeds*/nColsCaller,1});

  co_await task::make_async<app::call::caller_rectangle_foo_rectangle_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0,0},{/*ranges*/range_t({0, nRowsCaller}),range_t({0, nColsCaller})}), nColsCaller, nRowsCaller);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_1d_blocks_app")]]
void foo_blocks(const float * bbb, int bSize, int nBlocks) {
  float r = 13.f;
  for (int bId = 0; bId < nBlocks; bId++) {
    for (int i = bId*bSize; i < bSize; i++) {
      r = bbb[i + bId*bSize];
    }
  }
}

task::coro::dispatcher<app::impl::caller_blocks> caller_blocks(task::attr::descriptor&  attrDesc, int bSizeCaller, int nBlocksCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<2,dep::mesh::single>(ppp, {/*embeds*/bSizeCaller,1});

  co_await task::make_async<app::call::caller_blocks_foo_1d_blocks_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0,0},{/*ranges*/range_t({0, nBlocksCaller}),range_t({0, bSizeCaller})}), bSizeCaller, nBlocksCaller);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_low_tri_app")]]
void foo_low_triangle(const float * bbb, int nCols, int nRows) {
  float r = 13.f;
  for (int row = 0; row < nRows; row++) {
    for (int col = 0; col < row; col++) {
      r = bbb[col + row*nCols];
    }
  }
}

task::coro::dispatcher<app::impl::caller_low_triangle> caller_low_triangle(task::attr::descriptor&  attrDesc, int nColsCaller, int nRowsCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<2,dep::mesh::single>(ppp, {/*embeds*/nColsCaller,1});

  co_await task::make_async<app::call::caller_low_triangle_foo_low_tri_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0,0},{/*ranges*/range_t({0, nRowsCaller}),range_t({0, nRowsCaller})}), nColsCaller, nRowsCaller);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_up_tri_app")]]
void foo_up_triangle(const float * bbb, int nCols, int nRows) {
  float r = 13.f;
  for (int row = 0; row < nRows; row++) {
    for (int col = row; col < nCols; col++) {
      r = bbb[col + row*nCols];
    }
  }
}

task::coro::dispatcher<app::impl::caller_up_triangle> caller_up_triangle(task::attr::descriptor&  attrDesc, int nColsCaller, int nRowsCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<2,dep::mesh::single>(ppp, {/*embeds*/nColsCaller,1});

  co_await task::make_async<app::call::caller_up_triangle_foo_up_tri_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0,0},{/*ranges*/range_t({0, nRowsCaller}),range_t({0, nColsCaller})}), nColsCaller, nRowsCaller);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}
