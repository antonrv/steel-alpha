
export module SteelRT.Task.Descriptor.Feed;

import SteelRT.Util.Meta;

import SteelRT.Util.AppWork;

import SteelRT.Util.FwDeclarations.Task;

import <tuple>;


namespace learn::feat {


  template < app::call AppCall, std::size_t ArgId >
  auto extract_single_feed( app::tuple_std_args_t<AppCall>& callTupleRef ) {
    return std::get< ArgId >( callTupleRef );
  }
  
  template < app::call AppCall, std::size_t... FeedIds >
  app::tuple_std_feed_t<AppCall>
  extract_feed_detail(  app::tuple_std_args_t<AppCall>& callTupleRef, util::sequence::index_t<FeedIds...> ) {
    return std::make_tuple( extract_single_feed<AppCall, FeedIds>( callTupleRef ) ... );
  }


export
template < app::call AppCall >
app::tuple_std_feed_t<AppCall>
extract_feed( workload::poly_desc_t polyDesc ) {

  using CallStdTupleT = app::tuple_std_args_t<AppCall>;

  CallStdTupleT& callTupleRef = *static_cast<CallStdTupleT*>( static_cast< task::descriptor<AppCall, CallStdTupleT>* >( polyDesc ) );

  using FeedIdSeqT = app::seq_call_feed_t<AppCall>;

  return extract_feed_detail<AppCall>( callTupleRef, FeedIdSeqT{} );
}

} // namespace learn::feat
