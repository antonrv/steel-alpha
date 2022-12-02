
#include "source/object/typedef.hpp"
#include "source/token/typedef.hpp"

namespace bld::src {

class alignable {
private:

  pc::cpiece_t innerPiece;
  cso_t<obj::fun_def> global;
  pc::piece_context local;

public:
  alignable(pc::cpiece_t pc);

  alignable(pc::piece_context loc);

  alignable(const alignable&) = default;
  // alignable(alignable&&) = default;

  pc::cpiece_t get_piece() const;
  cso_t<obj::fun_def> get_global() const;
  pc::piece_context get_local() const;

};

pc::own_piece_t align_to_target( const alignable& inputAlignable, const alignable& targetAlignable );

} // namespace bld::src
