//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

#include <vector>

[[steel::task("dot_prod_app")]]
void dot_prod_v1(float * res, float const * aVec, float const * bVec, const unsigned n) {
  for (unsigned i = 0; i < n; i++) {
    res[0] += aVec[i] * bVec[i];
  }
}

[[steel::task("reduce_app")]]
void reduce(float * res, float const * vec, const unsigned n) {
  for(unsigned i = 0; i < n; i++) {
    res[0] += vec[i];
  }
}

[[steel::task("dot_prod_app")]] // [[steel::manage("blockSize=divisor(n)")]]
task::coro::dispatcher<app::impl::dot_prod_v2> dot_prod_v2(task::attr::descriptor&  attrDesc,  float * res, float const * aPtr, float const * bPtr, const unsigned n, const unsigned blockSize) {
auto wrap_aPtr = dep::wrap_region<1,dep::mesh::direct>(aPtr, {/*embeds*/1}, {/*embeds*/blockSize}, {/*ranges*/range_t({0, (n/blockSize)})});
auto wrap_bPtr = dep::wrap_region<1,dep::mesh::direct>(bPtr, {/*embeds*/1}, {/*embeds*/blockSize}, {/*ranges*/range_t({0, (n/blockSize)})});

  const unsigned nBlocks = n / blockSize;

  // Create vector of partial results
  std::vector<float> resVec;// (nBlocks, 0); TODO
  resVec.resize(nBlocks);
  float * resPtr = resVec.data();
auto wrap_resPtr = dep::wrap_region<1,dep::mesh::tree>(resPtr, {/*embeds*/1});

  // Compute smaller 'nBlocks' dot products
  for (unsigned b = 0; b < nBlocks; b++) {
    co_await task::make_async<app::call::dot_prod_v2_dot_prod_app_0>(attrDesc.depth + 1,  wrap_resPtr.emit_bnd_writer({/*coord*/b},{/*ranges*/range_t({b, (1+b)})}), wrap_aPtr.emit_bnd_reader({/*coord*/(b*blockSize)},{/*ranges*/range_t({(b*blockSize), (blockSize+(b*blockSize))})}), wrap_bPtr.emit_bnd_reader({/*coord*/(b*blockSize)},{/*ranges*/range_t({(b*blockSize), (blockSize+(b*blockSize))})}), blockSize );
  }

  float resReduce = 0;
auto wrap_resReduce = dep::wrap_region<0>(resReduce);
  co_await task::make_async<app::call::dot_prod_v2_reduce_app_1>(attrDesc.depth + 1, wrap_resReduce.emit_bnd_writer(0, /*ds-off*/0), wrap_resPtr.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({0, nBlocks})}), nBlocks);

while (not dep::all_destroyable(wrap_aPtr,wrap_bPtr,wrap_resPtr,wrap_resReduce)) { co_await task::coro::suspend(); }
}
