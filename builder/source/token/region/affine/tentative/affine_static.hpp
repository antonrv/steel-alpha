

namespace bld::src::pc {


// Virtual
std::string affine_guard_mesh_affine_static::get_wrap_command() const {

  auto wrapVarName = m_dDeclRoot->get_wrap_variable_name();
  auto varName = m_dDeclRoot->get_variable_name(); 

  std::string dimStr = std::to_string(this->get_dimensions());
  std::string typeStr = "TYPE"; // TODO

  std::string gobalEmbedsStr = adapt_to_string( this->get_global_embeddings(),
      [] (const cpiece_t pc) {
        return static_unique_pointer_cast<const piece>( simplify_piece(pc) );
      },
      embeddings_to_bracket_string
    );

  retStr = "dep::affine_guard::mesh_affine_static<" + dimStr + ", " + typeStr + "> " + wrapVarNameStr + "(" + varNameStr + ", " + globalEmbedsStr + ")";

}


// Virtual
std::string affine_guard_mesh_affine_static::get_emit_arguments() const {


}


} // namespace bld::src::pc
