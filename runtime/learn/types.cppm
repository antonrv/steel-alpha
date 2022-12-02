
export module SteelRT.Learn.Types;

import SteelRT.Util.Types;

import <array>;
import <tuple>;
import <string>;

export
namespace learn {

// Appart from specifying scalar functions, activ also specifies functions between layers (ie softmax and matrix)
enum class fun : enum_uint_t { input, linear, relu, leaky_relu, sigmoid, tanh, exp, softmax, encode, matrix, bias, sample_norm, batch_norm };



enum class weights_open : enum_uint_t { blank, try_reuse, reuse };
enum class weights_close : enum_uint_t { discard, save };
enum class seed_kind : enum_uint_t { fix, rnd };

using seed_t = uint_t;

using fp_t = float;

using thread_count_t = uint_t;

using version_t = uint_t; // Version of the weights used by runner and updated by pilot

namespace pilot {

  struct cfg {

    weights_open open = weights_open::blank; // ::pilot only
    weights_close close = weights_close::discard; // ::pilot only
    seed_kind seed; // both ::pilot and ::runner
    seed_t seedValue; // both ::pilot and ::runner
    std::string targetDir;
    uint_t miniBatchSize; // ::pilot only
    fp_t expMovAvgDecay; // Used to compute exp moving averages in sample_norm layers.
    fp_t regularization; // Used to update the weights in matrix layers.
    fp_t actorLearnRate;
    fp_t criticLearnRate;
    fp_t adamMoment; // Used to update the weights in matrix and batch_norm layers
    fp_t adamSquare; // Used to update the weights in matrix and batch_norm layers

    // cfg(weights_open o, weights_close c, seed_kind sk, seed_t sv, std::string td) : open(o), close(c), seed(sk), seedValue(sv), targetDir(td) {}

    std::string get_string() const noexcept {
      return "open: " + std::string(open == weights_open::blank ? "blank" : (open == weights_open::try_reuse ? "try_reuse": "reuse" )) +
             ", close: " + std::string(close == weights_close::discard ? "discard" : "save") +
             ", seedKind: " + std::string(seed == seed_kind::fix ? "fix" : "rnd") +
             ", seedValue: " + std::to_string(seedValue) +
             ", targetDir: " + targetDir +
             ", miniBatchSize: " + std::to_string(miniBatchSize) + 
             ", expMovAvgDecay:" + std::to_string(expMovAvgDecay) + 
             ", regularization:" + std::to_string(regularization) + 
             ", actorLearnRate:" + std::to_string(actorLearnRate) + 
             ", criticLearnRate:" + std::to_string(criticLearnRate) + 
             ", adamMoment:" + std::to_string(adamMoment) + 
             ", adamSquare:" + std::to_string(adamSquare);
    }
  };

  // struct update_info {
  //   fp_t tdError = 0;
  //   fp_t avgReward = 0;
  //   fp_t prevStateValue = 0;
  //   fp_t curStateValue = 0;
  // };

} // namespace pilot

namespace runner {

  struct cfg {
    seed_kind seed; // both ::pilot and ::runner
    seed_t seedValue; // both ::pilot and ::runner 

    std::string get_string() const noexcept {
      return "seedKind: " + std::string(seed == seed_kind::fix ? "fix" : "rnd") + ", seedValue: " + std::to_string(seedValue);
    }
  };

} // namespace runner


// struct weights_mode {
//   weights_open open = weights_open::blank; // ::pilot only
//   weights_close close = weights_close::discard; // ::pilot only
//   seed_kind seed = seed_kind::fix; // both ::pilot and ::runner
//   seed_t seedValue = 1111; // both ::pilot and ::runner 
// };


namespace approx::ann {

  enum class propagate : enum_uint_t { fwd, bwd };

  enum class width : enum_uint_t { single, batch };

  template <ann::width Width, typename StoreT>
  class values;

  template <typename T>
  struct is_values : std::false_type {};

  template <ann::width Width, typename StoreT>
  struct is_values < values<Width, StoreT> > : std::true_type {};

  template <typename T>
  struct is_batch_values : std::false_type {};

  template <ann::width Width, typename StoreT>
  struct is_batch_values < values<Width, StoreT> > {
    static constexpr bool value = (Width == ann::width::batch);
  };

  template <typename T>
  struct is_single_values : std::false_type {};

  template <ann::width Width, typename StoreT>
  struct is_single_values < values<Width, StoreT> > {
    static constexpr bool value = (Width == ann::width::single);
  };

  using batch_rewards_t = ann::values< ann::width::batch, std::array<fp_t, 1> >;

  using batch_state_values_t = ann::values< ann::width::batch, std::array<fp_t, 1> >;

  using batch_errors_t = ann::values< ann::width::batch, std::array<fp_t, 1> >;

  template <typename InputStateT>
  using batch_states_t = ann::values< ann::width::batch, InputStateT >;

  template <typename ActionT>
  using batch_actions_t = ann::values< ann::width::batch, std::array<ActionT, 1> >;

} // namespace approx::ann




namespace feat {
  struct terminal_state {};
} // namespace feat

namespace intf::msg {

  enum class ctg : enum_uint_t { undef, terminate, tasking, threading, delegating };
  
  enum class kind : enum_uint_t { undef, inference_start, inference_end, end };
  
  using ctxt_id_t = ushort_t;
  
  inline constexpr const ctxt_id_t UndefContext = std::numeric_limits<ctxt_id_t>::max();
  
  
  // Just a tag to unique determine task descriptors pointers
  using task_id_t = youth_t; // std::uintptr_t; BAD
  
  inline constexpr const task_id_t TerminateTaskId = 0;
  inline constexpr const task_id_t UndefinedTaskId = 1;

} // namespace intf::msg


namespace intf::runner {

  template <msg::ctg MsgCtg, typename NativeT>
  class aux;

} // namespace intf::runner

namespace intf::pilot {

  template <msg::ctg MsgCtg, typename NativeT>
  class aux;

} // namespace intf::pilot


template <std::size_t N>
using array_t = std::array<fp_t, N>;

template <std::size_t N>
using array_idx_t = std::array<uint_t, N>;

template <std::size_t Rows, std::size_t Cols>
using matrix_t = std::array< array_t<Cols>, Rows >;

template <std::size_t BwNeuronCount, std::size_t FwNeuronCount>
using matrix_net_t = matrix_t<FwNeuronCount, BwNeuronCount>;

template <typename T>
struct size;

template <typename T, std::size_t N>
struct size< std::array<T, N> > { static constexpr std::size_t value = std::tuple_size_v<std::array<T,N>>; };

template <typename T>
struct size< approx::ann::values<approx::ann::width::single, T> > { static constexpr std::size_t value = size<T>::value; };

template <typename T>
inline constexpr std::size_t size_v = size<T>::value;

template <typename MatrixT>
inline constexpr std::size_t rows_v = std::tuple_size_v<MatrixT>;

template <typename MatrixT>
inline constexpr std::size_t cols_v = std::tuple_size_v<typename MatrixT::value_type>;


template <typename T>
struct is_index_array : std::false_type {};

template <std::size_t N>
struct is_index_array<array_idx_t<N>> : std::true_type {};


template <typename T>
struct is_fp_array : std::false_type {};

template <std::size_t N>
struct is_fp_array<array_t<N>> : std::true_type {};



template <typename T>
struct is_fp : std::false_type {};

template <>
struct is_fp<fp_t> : std::true_type {};



template <typename T>
struct is_int : std::false_type {};

template <>
struct is_int<int_t> : std::true_type {};



template <typename T>
struct is_uint : std::false_type {};

template <>
struct is_uint<uint_t> : std::true_type {};


} // namespace learn
