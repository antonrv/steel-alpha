//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("mat_vec_app")]]
void mat_vec_v1(
  float * vecRes, float const * inputMat, float const * inputVec,
  unsigned nCols, unsigned nRows, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      vecRes[ii] += inputMat[jj*stride + ii] * inputVec[ii];
    }
  }
}


[[steel::task("mat_vec_app")]] // [[steel::manage("nColBlocks=divisor(nCols)")]] [[steel::manage("nRowBlocks=divisor(nRows)")]]
task::coro::dispatcher<app::impl::mat_vec_v2> mat_vec_v2(task::attr::descriptor&  attrDesc, 
  float * vecRes, float const * inputMat, float const * inputVec,
  unsigned nCols, unsigned nRows,
  unsigned nColBlocks, unsigned nRowBlocks)
{
auto wrap_vecRes = dep::wrap_region<1,dep::mesh::direct>(vecRes, {/*embeds*/1}, {/*embeds*/(nCols/nColBlocks)}, {/*ranges*/range_t({0, nColBlocks})});
auto wrap_inputMat = dep::wrap_region<2,dep::mesh::direct>(inputMat, {/*embeds*/nCols,1}, {/*embeds*/(nRows/nRowBlocks),(nCols/nColBlocks)}, {/*ranges*/range_t({0, nRowBlocks}),range_t({0, nColBlocks})});
auto wrap_inputVec = dep::wrap_region<1,dep::mesh::direct>(inputVec, {/*embeds*/1}, {/*embeds*/(nCols/nColBlocks)}, {/*ranges*/range_t({0, nColBlocks})});

  unsigned colBlockSize = nCols / nColBlocks;
  unsigned rowBlockSize = nRows / nRowBlocks;
  unsigned stride = nColBlocks * colBlockSize * rowBlockSize;
  unsigned localStride = colBlockSize * nColBlocks;

  for (unsigned jj = 0; jj < nRowBlocks; jj++) {
    for (unsigned ii = 0; ii < nColBlocks; ii++) {
      co_await task::make_async<app::call::mat_vec_v2_mat_vec_app_0>(attrDesc.depth + 1,  wrap_vecRes.emit_bnd_writer({/*coord*/(colBlockSize*ii)},{/*ranges*/range_t({(colBlockSize*ii), (colBlockSize+(colBlockSize*ii))})}), wrap_inputMat.emit_bnd_reader({/*coord*/((jj*stride)/localStride),(colBlockSize*ii)},{/*ranges*/range_t({((jj*stride)/localStride), (rowBlockSize+((jj*stride)/localStride))}),range_t({(colBlockSize*ii), (colBlockSize+(colBlockSize*ii))})}), wrap_inputVec.emit_bnd_reader({/*coord*/(colBlockSize*ii)},{/*ranges*/range_t({(colBlockSize*ii), (colBlockSize+(colBlockSize*ii))})}), colBlockSize, rowBlockSize, localStride );
    }
  }

while (not dep::all_destroyable(wrap_vecRes,wrap_inputMat,wrap_inputVec)) { co_await task::coro::suspend(); }
}
