

#include "source/token/make/piece.hpp"

#include "source/token/simplify/interface.hpp"

#include "source/token/region/affine/access.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <numeric>

using namespace bld::src::pc;

int main(int argc, const char ** argv) {

  // Enable options usage from cli TODO

  try {

    vec_string_t vArgs(argv, argv + argc);

    if (vArgs.size() == 1) {
      std::string egStr;
      egStr += vArgs[0] + " 'a + b*5 + 37 + 4'\n";
      egStr += vArgs[0] + " '4 + 5'\n";
      egStr += vArgs[0] + " 'a*b/(b*c)'\n";
      egStr += vArgs[0] + " 'affine:iLV'\n";
      egStr += vArgs[0] + " 'affine:iLV*4 + jLV*stride'\n";
  
      throw std::runtime_error("Introduce arithmetic expression to parse and simplify. Examples:\n" + egStr);
    }
    vArgs.erase(std::begin(vArgs));
    auto inputStr = std::accumulate(std::begin(vArgs), std::end(vArgs), std::string(), [] (const std::string& cum, const std::string& str) {return cum + str;});

    const std::string affineStr = "affine:";
    bool isAffine = false;

    if (inputStr.find(affineStr) != std::string::npos) {

      inputStr = inputStr.substr( inputStr.find(affineStr) + affineStr.size() );
      isAffine = true;
    }


    // std::cout << "Passing " << inputStr << '\n';
    auto pc = bld::src::pc::make_piece( inputStr );

    std::cout << "Input as : " << pc->get_kind() << "\n\t" << pc->get_pc_string() << '\n';

    own_piece_t simpl;

    if (pc->get_kind() == kind::binop) {

      auto binop = static_cast<ctoken_t<kind::binop>>(pc.get());

      if (binop->is_compare()) {
        std::cout << "Result : " << binop->evaluate() << '\n';
      } else {
        std::cout << "No output\n";
      }

    } else {

      simpl = simplify_piece( pc );

    
      if (isAffine) {

        affine_access affExpr( simpl.get(),
          [] (cpiece_t pc) {
            if (pc->get_kind() == kind::var) {
              return static_cast<ctoken_t<kind::var>>(pc)->get_unsigned_name().find("LV") != std::string::npos;
            }
            return false;
          });
        std::cout << "Output as affine : " << affExpr.get_info() << '\n';

      } else {

        std::cout << "Output as : " << simpl->get_kind() << "\n\t" << simpl->get_pc_string() << '\n';
      }

    }


  } catch ( const std::runtime_error& rte) {

    std::cerr << "Runtime error : " << rte.what() << '\n';

  } catch ( const std::logic_error& le) {

    std::cerr << "Logic error : " << le.what() << '\n';

  } catch ( ... ) {

    std::cerr << "Unknown error\n";
  }

  return 0;
}
