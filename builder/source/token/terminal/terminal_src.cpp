

namespace bld::src::pc {


void token_tuple<1>::set_data_use(cso_t<obj::data_use> dUse) {
  if (m_dataUse != nullptr) {
    unsigned kindInt = static_cast<unsigned>( this->get_kind() );
    // std::cout << "This ptr terminal : " << this << ". Pck : " << this->get_kind() << '\n';
    throw std::logic_error("Data use already set in termina. Already set : " + this->get_pc_string() + " kind" + std::to_string(kindInt) + " input dUse : " + dUse->get_identifier()/* + ". Existing : " + m_dataUse->get_identifier()*/);
    // throw std::logic_error("Data use already set in terminal. Already set : " + m_dataUse->get_identifier() + ". Received : " + dUse->get_identifier());
  }
  if (dUse->has_root() and dUse->get_root_data_decl()->get_variable_name() != this->get_pc_string()) {
    throw std::logic_error("Could not set data use of terminal. Name mismatch. Data use : " + dUse->get_root_data_decl()->get_variable_name() + ". Terminal string : " + this->get_pc_string());
  }

  // std::cout << "Binding terminal \'"<< this->get_pc_string() << "\'" << this->get_kind() << ". ptr." << this << " with PARENT: ptr " << this->get_parent() << " and kind : " << this->get_parent()->get_kind() << " , against data_use " << dUse->get_identifier() << " : " << (dUse->has_root() ? dUse->get_root_data_decl()->get_variable_name() : "") << '\n';

  m_dataUse = dUse;
}

} // namespace bld::src::pc
