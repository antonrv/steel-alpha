
import SteelRT.Learn.Feat.TileCoder;

import SteelRT.Util.Values;

import <array>;
import <iostream>;

import <stdexcept>;

template <typename ArrayT>
std::string print( const ArrayT& arr, std::string name) {
  std::string str = name + " : ";
  for (auto v : arr) {
    str += std::to_string(v) + ',';
  }
  str += '\n';
  return str;
}

template <typename ArrayT>
void validate( const ArrayT& arrTest, ArrayT arrCorrect) {

  if (arrTest != arrCorrect) {
    throw std::runtime_error("Arrays are not the same : \n\t" + print(arrTest, "test") + " !=\n\t" + print(arrCorrect,"correct"));
  }
}

template <typename ArrayT>
void set_zero(ArrayT& arr) {
  for (auto& v : arr) {
    v = 0;
  }
}

using uint_t = unsigned;

void test_one_linear_tiling () {

  using tc_t = learn::feat::tile_coder<uint_t, 0, 16, 1, learn::feat::rescale::linear, 1>;

  tc_t tc;

  for (auto i = 0u; i < 16; i++) {

    std::array<uint_t, 1> enabledTiles;

    tc.get_active_tiles( enabledTiles.data(), i );

    validate( enabledTiles, {i} );
  }
}

void test_two_linear_tilings () {

  static constexpr std::size_t NTilings = 2;

  static constexpr std::size_t TileSize = 16 / NTilings;

  using tc_t = learn::feat::tile_coder<uint_t, 0, 16, TileSize, learn::feat::rescale::linear, NTilings>;

  tc_t tc;

  std::array<uint_t, NTilings> enabledTiles;

  {
    uint_t value = 0;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, global::NoIndex};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 1;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, global::NoIndex};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 2;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, global::NoIndex};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 3;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, global::NoIndex};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 4;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 5;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 6;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 7;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 8;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 9;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 10;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 11; 
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 12;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 13;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 14;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 15; 
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

}


void test_four_linear_tilings () {

  static constexpr std::size_t NTilings = 4;

  static constexpr std::size_t TileSize = 16 / NTilings;

  using tc_t = learn::feat::tile_coder<uint_t, 0, 16, TileSize, learn::feat::rescale::linear, NTilings>;

  tc_t tc;

  std::array<uint_t, NTilings> enabledTiles;

  {
    uint_t value = 0;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, global::NoIndex, global::NoIndex, global::NoIndex};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 1;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, 0, global::NoIndex, global::NoIndex};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 2;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, 0, 0, global::NoIndex};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 3;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {0, 0, 0, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 4;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 0, 0, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 5;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 1, 0, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 6;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 1, 1, 0};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 7;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {1, 1, 1, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 8;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {2, 1, 1, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 9;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {2, 2, 1, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 10;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {2, 2, 2, 1};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 11;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {2, 2, 2, 2};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 12;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {3, 2, 2, 2};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 13;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {3, 3, 2, 2};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 14;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {3, 3, 3, 2};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

  {
    uint_t value = 15;
    set_zero( enabledTiles );
    std::array<uint_t, NTilings> correctTiles = {3, 3, 3, 3};
    tc.get_active_tiles( enabledTiles.data(), value );
    validate( enabledTiles, correctTiles );
  }

}


void test_one_log_tilings () {

  static constexpr std::size_t NTilings = 1;

  static constexpr std::size_t TileSize = 1; // 8 / NTilings;

  using tc_t = learn::feat::tile_coder<uint_t, 1, 256, TileSize, learn::feat::rescale::log, NTilings>; // 0 to 7 inclusive [0, 8)

  tc_t tc;

  std::array<uint_t, NTilings> enabledTiles;

  {
    // [2^0, 2^1)
    std::array<uint_t, NTilings> correctTiles = {0};
    for (auto value = 1; value < 2; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^1, 2^2)
    std::array<uint_t, NTilings> correctTiles = {1};
    for (auto value = 2; value < 4; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^2, 2^3)
    std::array<uint_t, NTilings> correctTiles = {2};
    for (auto value = 4; value < 8; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^3, 2^4)
    std::array<uint_t, NTilings> correctTiles = {3};
    for (auto value = 8; value < 16; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^4, 2^5)
    std::array<uint_t, NTilings> correctTiles = {4};
    for (auto value = 16; value < 32; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^5, 2^6)
    std::array<uint_t, NTilings> correctTiles = {5};
    for (auto value = 32; value < 64; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^6, 2^7)
    std::array<uint_t, NTilings> correctTiles = {6};
    for (auto value = 64; value < 128; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^7, 2^8)
    std::array<uint_t, NTilings> correctTiles = {7};
    for (auto value = 128; value < 256; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }


}


void test_two_log_tilings () {

  static constexpr std::size_t NTilings = 2;

  static constexpr std::size_t TileSize = 8 / NTilings;

  using tc_t = learn::feat::tile_coder<uint_t, 1, 256, TileSize, learn::feat::rescale::log, NTilings>; // 0 to 7 inclusive [0, 8)

  tc_t tc;

  std::array<uint_t, NTilings> enabledTiles;

  {
    // [2^0, 2^2)
    std::array<uint_t, NTilings> correctTiles = {0, global::NoIndex};
    for (auto value = 1; value < 4; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^2, 2^4)
    std::array<uint_t, NTilings> correctTiles = {0, 0};
    for (auto value = 4; value < 16; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^4, 2^6)
    std::array<uint_t, NTilings> correctTiles = {1, 0};
    for (auto value = 16; value < 64; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^6, 2^8)
    std::array<uint_t, NTilings> correctTiles = {1, 1};
    for (auto value = 64; value < 256; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^8]
    std::array<uint_t, NTilings> correctTiles = {global::NoIndex, 1};
    for (auto value = 256; value <= 256; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

}

void test_four_log_tilings () {

  static constexpr std::size_t NTilings = 4;

  static constexpr std::size_t TileSize = 4;

  using tc_t = learn::feat::tile_coder<uint_t, 1, 256, TileSize, learn::feat::rescale::log, NTilings>; // 0 to 7 inclusive [0, 8)

  tc_t tc;

  std::array<uint_t, NTilings> enabledTiles;

  {
    // [2^0, 2^1)
    std::array<uint_t, NTilings> correctTiles = {0, global::NoIndex, global::NoIndex, global::NoIndex};
    for (auto value = 1; value < 2; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^1, 2^2)
    std::array<uint_t, NTilings> correctTiles = {0, 0, global::NoIndex, global::NoIndex};
    for (auto value = 2; value < 4; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^2, 2^3)
    std::array<uint_t, NTilings> correctTiles = {0, 0, 0, global::NoIndex};
    for (auto value = 4; value < 8; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^3, 2^4)
    std::array<uint_t, NTilings> correctTiles = {0, 0, 0, 0};
    for (auto value = 8; value < 16; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^4, 2^5)
    std::array<uint_t, NTilings> correctTiles = {1, 0, 0, 0};
    for (auto value = 16; value < 32; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^5, 2^6)
    std::array<uint_t, NTilings> correctTiles = {1, 1, 0, 0};
    for (auto value = 32; value < 64; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^6, 2^7)
    std::array<uint_t, NTilings> correctTiles = {1, 1, 1, 0};
    for (auto value = 64; value < 128; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^7, 2^8)
    std::array<uint_t, NTilings> correctTiles = {1, 1, 1, 1};
    for (auto value = 128; value < 256; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }

  {
    // [2^8]
    std::array<uint_t, NTilings> correctTiles = {global::NoIndex, 1, 1, 1};
    for (auto value = 256; value <= 256; value++) {

      set_zero( enabledTiles );
      tc.get_active_tiles( enabledTiles.data(), value );
      validate( enabledTiles, correctTiles );
    }
  }


}


int main(void) {


  try {

    test_one_linear_tiling();
    test_two_linear_tilings();
    test_four_linear_tilings();

    test_one_log_tilings();
    test_two_log_tilings();
    test_four_log_tilings();


  } catch (const std::exception& exc) {
    std::cerr << "Error caught : " << exc.what() << '\n';
    return 1;
  }

  std::cout << "OK\n";
  return 0;
}
