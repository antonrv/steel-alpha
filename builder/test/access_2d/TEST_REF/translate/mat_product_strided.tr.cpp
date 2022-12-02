//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;


[[steel::task("mat_product_app")]]
void mat_product_v1_kernel_strided(
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize,
  unsigned outStride, unsigned inAStride, unsigned inBStride)
{
  for (unsigned mm = 0; mm < mSize; mm++) {
    for (unsigned nn = 0; nn < nSize; nn++) {
      for (unsigned kk = 0; kk < kSize; kk++) {
        outMat[mm * outStride + nn] += inMatA[mm * inAStride + kk] * inMatB[kk * inBStride + nn];
      }
    }
  }
}


[[steel::task("mat_product_app")]] // [[steel::manage("mBlocks=divisor(mSize)")]] [[steel::manage("nBlocks=divisor(nSize)")]] [[steel::manage("kBlocks=divisor(kSize)")]]
task::coro::dispatcher<app::impl::mat_product_v2_block_strided> mat_product_v2_block_strided(task::attr::descriptor&  attrDesc, 
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize,
  unsigned mBlocks, unsigned nBlocks, unsigned kBlocks)
{
auto wrap_outMat = dep::wrap_region<2,dep::mesh::direct>(outMat, {/*embeds*/nSize,1}, {/*embeds*/(mSize/mBlocks),(nSize/nBlocks)}, {/*ranges*/range_t({0, mBlocks}),range_t({0, nBlocks})});
auto wrap_inMatA = dep::wrap_region<2,dep::mesh::direct>(inMatA, {/*embeds*/kSize,1}, {/*embeds*/(mSize/mBlocks),(kSize/kBlocks)}, {/*ranges*/range_t({0, mBlocks}),range_t({0, kBlocks})});
auto wrap_inMatB = dep::wrap_region<2,dep::mesh::direct>(inMatB, {/*embeds*/nSize,1}, {/*embeds*/(kSize/kBlocks),(nSize/nBlocks)}, {/*ranges*/range_t({0, kBlocks}),range_t({0, nBlocks})});
  unsigned mBlockSize = mSize / mBlocks;
  unsigned nBlockSize = nSize / nBlocks;
  unsigned kBlockSize = kSize / kBlocks;

  ////////////
  //
  // MATRIX STRIDED BLOCK PRODUCT
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      for (unsigned kb = 0; kb < kBlocks; kb++) {
        co_await task::make_async<app::call::mat_product_v2_block_strided_mat_product_app_0>(attrDesc.depth + 1,  wrap_outMat.emit_bnd_writer({/*coord*/(mBlockSize*mb),(nBlockSize*nb)},{/*ranges*/range_t({(mBlockSize*mb), (mBlockSize+(mBlockSize*mb))}),range_t({(nBlockSize*nb), (nBlockSize+(nBlockSize*nb))})}), wrap_inMatA.emit_bnd_reader({/*coord*/(mBlockSize*mb),(kBlockSize*kb)},{/*ranges*/range_t({(mBlockSize*mb), (mBlockSize+(mBlockSize*mb))}),range_t({(kBlockSize*kb), (kBlockSize+(kBlockSize*kb))})}), wrap_inMatB.emit_bnd_reader({/*coord*/(kBlockSize*kb),(nBlockSize*nb)},{/*ranges*/range_t({(kBlockSize*kb), (kBlockSize+(kBlockSize*kb))}),range_t({(nBlockSize*nb), (nBlockSize+(nBlockSize*nb))})}), mBlockSize, nBlockSize, kBlockSize, nSize, kSize, nSize);
      }
    }
  }

while (not dep::all_destroyable(wrap_outMat,wrap_inMatA,wrap_inMatB)) { co_await task::coro::suspend(); }
}
