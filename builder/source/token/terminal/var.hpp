#ifndef VAR_DECL_HPP_HPP
#define VAR_DECL_HPP_HPP


#include "source/token/terminal/terminal.hpp"


namespace bld::src::pc {

class loop_var;

template <>
class token<kind::var> : public terminal {
public:

private:
// #ifdef PARSER_TEST
  std::string m_name;
// #endif // PARSER_TEST

public:

  token();

  token(const std::string& is);


  token(const token& other) = default;
  // token(const token& other);

  kind get_kind() const final override;

  virtual std::string get_pc_string() const override;

  std::string get_unsigned_name() const;

  bool goes_after_than( ctoken_t<kind::var> lv ) const;

  virtual bool is_loop() const;
  virtual bool is_synth() const;
  virtual bool is_raw() const;

  virtual const loop_var * get_loop_variable() const;
};


class synth_var : public token<kind::var> {

protected:
  std::string m_name;

public:

  synth_var(const synth_var& rs) = default;

  synth_var(std::string is);

  virtual std::string get_pc_string() const override;

  bool is_synth() const final override;
};


class raw_str : public synth_var {

public:

  raw_str(const raw_str& rs) = default;

  raw_str(std::string is);

  std::string get_pc_string() const final override;

  bool is_raw() const final override;
};

} // namespace bld::src::pc

#endif // VAR_DECL_HPP_HPP
