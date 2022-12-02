
export module SteelRT.Instrument.Frontend; // Will be directly SteelRT.Instrument


namespace instr {

export
template <typename... EnumEventT>
std::vector<raii_instrer> initialize(const char processIdentifier, const std::string& instrFn, util::tuple_t<EnumEventT...> ) {

  // Assert no EnumEventT for runner only is not coexisting with other event for pilot only

}

} // namespace instr
