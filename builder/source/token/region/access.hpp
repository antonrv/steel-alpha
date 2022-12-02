#ifndef PARSER_REGION_ACCESS_HPP
#define PARSER_REGION_ACCESS_HPP

#include "source/token/typedef.hpp"

#include "source/sequences.hpp"
#include "source/object/typedef.hpp"

#include <string>


namespace bld::src::pc {


class guard;


class access {
private:

  own_cpiece_t m_originalPc;

#ifndef PARSER_TEST
  cso_t<obj::data_use> m_dUseRoot = nullptr;
#else // PARSER_TEST enabled
  const guard * m_downstreamGuard = nullptr;
#endif // PARSER_TEST


protected:

  cpiece_t get_original() const;

  std::string get_info() const;
public:

  access( cpiece_t origPc, cso_t<obj::data_use> dUse );

  access(const access& );

  access(access&& ) = default; // needed ??

  virtual ~access() = 0;

  mem_expr_trans get_mem_expr_transformation() const;

  virtual mem_ak get_mem_access_kind() const = 0;


  // Virtual because it may be overriden in mem_ak::non_affine
  // virtual own_cpiece_t<kind::range> get_original_range() const;

  // Implementations differ depending on PARSER_TEST
  const guard * get_downstream_guard() const;

  // Implementations differ depending on PARSER_TEST
  piece_context get_local_context() const;

  // Implementations differ depending on PARSER_TEST
  piece_context get_highest_local_context() const;

  // Implementations differ depending on PARSER_TEST
  bool is_task_ref_argument() const;

#ifndef PARSER_TEST
  // Get / Set root data use :
  cso_t<obj::data_use> get_root_data_use() const;

  void set_root_data_use( cso_t<obj::data_use> dUseRoot);

  virtual std::string serial() const = 0;


  bool is_on_call_within_loop() const;


#else // PARSER_TEST enabled

  void set_downstream_guard(const guard * dsGuard);

#endif // PARSER_TEST


};


template <mem_ak MemAccK>
class mem_access;

using point_access = mem_access<mem_ak::point>;
using affine_access = mem_access<mem_ak::affine>;
using nonaffine_access = mem_access<mem_ak::non_affine>;
using indirect_access = mem_access<mem_ak::indirect>;

} // namespace bld::src::pc

#endif // PARSER_REGION_ACCESS_HPP
