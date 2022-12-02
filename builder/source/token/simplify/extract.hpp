#ifndef PARSER_SIMPLIFY_EXTRACT_HPP
#define PARSER_SIMPLIFY_EXTRACT_HPP


namespace bld::src::pc {

  template <typename TokT, typename CTokenT>
  static
  std::vector<std::unique_ptr<TokT>> extract_tokens_in( CTokenT pc, std::function<bool(cpiece_t)> satFn ) {

    return transform_vec_if( pc->get_tokens(), 
      satFn,
      [] (cpiece_t pc) {
        return static_unique_pointer_cast<TokT>( edit_piece(pc) );
      });
  }

} // namespace bld::src::pc

#endif // PARSER_SIMPLIFY_EXTRACT_HPP
