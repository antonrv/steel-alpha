//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

////
[[steel::task("foo_lt_add")]]
void foo_lt_add(const float * bbb, int nn) {
  float r;
  for (int ii = 0; ii < nn; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_lt_add> caller_lt_add(task::attr::descriptor&  attrDesc, int nCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int nCall = nCaller;
  co_await task::make_async<app::call::caller_lt_add_foo_lt_add_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({0, nCall})}), nCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_leq_add")]]
void foo_leq_add(const float * bbb, int nn) {
  float r;
  for (int ii = 0; ii <= nn; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_leq_add> caller_leq_add(task::attr::descriptor&  attrDesc, int nCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int nCall = nCaller;
  co_await task::make_async<app::call::caller_leq_add_foo_leq_add_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({0, (1+nCall)})}), nCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_gt_sub")]]
void foo_gt_sub(const float * bbb, int nn) {
  float r;
  for (int ii = nn; ii > 0; ii--) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_gt_sub> caller_gt_sub(task::attr::descriptor&  attrDesc, int nCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int nCall = nCaller;
  co_await task::make_async<app::call::caller_gt_sub_foo_gt_sub_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({1, nCall})}), nCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_geq_sub")]]
void foo_geq_sub(const float * bbb, int nn) {
  float r;
  for (int ii = nn; ii >= 0; ii--) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_geq_sub> caller_geq_sub(task::attr::descriptor&  attrDesc, int nCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int nCall = nCaller;
  co_await task::make_async<app::call::caller_geq_sub_foo_geq_sub_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({0, (1+nCall)})}), nCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}
