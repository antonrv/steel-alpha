
export module SteelRT.Opt.Predef;


import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;

import SteelRT.Learn.Types;


export
namespace opt {

enum class kind : enum_uint_t { app_args, pilot_weight_init, pilot_weight_close, pilot_seed_kind, pilot_seed_value, pilot_lrate_actor, pilot_lrate_critic, pilot_target_dir, pilot_minibatch, pilot_sample_batch_decay, pilot_regularization, pilot_adam_moment, pilot_adam_square, runner_seed_kind, runner_seed_value, runner_trials };

// This must be in the same order as the enum values above
using all_seq = util::sequence::enum_t<opt::kind, kind::app_args, kind::pilot_weight_init, kind::pilot_weight_close, kind::pilot_seed_kind, kind::pilot_seed_value, kind::pilot_lrate_actor, kind::pilot_lrate_critic, kind::pilot_target_dir, kind::pilot_minibatch, kind::pilot_sample_batch_decay, kind::pilot_regularization, kind::pilot_adam_moment, kind::pilot_adam_square, kind::runner_seed_kind, kind::runner_seed_value, kind::runner_trials >;

using runner_seq = util::sequence::enum_t< opt::kind, kind::app_args, kind::runner_seed_kind, kind::runner_seed_value, kind::runner_trials >;

using pilot_seq = util::sequence::enum_t< opt::kind, kind::pilot_weight_init, kind::pilot_weight_close, kind::pilot_seed_kind, kind::pilot_seed_value, kind::pilot_lrate_actor, kind::pilot_lrate_critic, kind::pilot_target_dir, kind::pilot_minibatch, kind::pilot_sample_batch_decay, kind::pilot_regularization, kind::pilot_adam_moment, kind::pilot_adam_square >;


template <opt::kind OptKind>
struct traits;

template <>
struct traits <opt::kind::app_args> {
  static constexpr const char * string_value = "-app-args";

  static constexpr bool expect_assignment = true;

  using value_type = std::string;

  static value_type convert( std::string optValue ) {
    return optValue;
  }

  static value_type get_default() {
    return "";
  }
};

//////////////// WEIGHTS OPEN
template <>
struct traits <opt::kind::pilot_weight_init> {
  static constexpr const char * string_value = "-pilot-weight-init";

  static constexpr bool expect_assignment = true;

  using value_type = learn::weights_open;

  static value_type convert( std::string optValue ) {
    if (optValue == "blank") {
      return learn::weights_open::blank;
    } else if (optValue == "try") {
      return learn::weights_open::try_reuse;
    } else if (optValue == "force") {
      return learn::weights_open::reuse;
    } else {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: [blank|try|force]");
    }
  }

  static value_type get_default() {
    return learn::weights_open::blank;
  }
};

//////////////// WEIGHTS CLOSE
template <>
struct traits <opt::kind::pilot_weight_close> {
  static constexpr const char * string_value = "-pilot-weight-close";

  static constexpr bool expect_assignment = true;

  using value_type = learn::weights_close;

  static value_type convert( std::string optValue ) {
    if (optValue == "discard") {
      return learn::weights_close::discard;
    } else if (optValue == "save") {
      return learn::weights_close::save;
    } else {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: [discard|save]");
    }
  }

  static value_type get_default() {
    return learn::weights_close::discard;
  }
};

//////////////// PILOT SEED KIND
template <>
struct traits <opt::kind::pilot_seed_kind> {
  static constexpr const char * string_value = "-pilot-seed-kind";

  static constexpr bool expect_assignment = true;

  using value_type = learn::seed_kind;

  static value_type convert( std::string optValue ) {
    if (optValue == "fix") {
      return learn::seed_kind::fix;
    } else if (optValue == "random") {
      return learn::seed_kind::rnd;
    } else {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: [fix|random]");
    }
  }

  static value_type get_default() {
    return learn::seed_kind::fix;
  }
};

//////////////// PILOT SEED KIND
template <>
struct traits <opt::kind::pilot_seed_value> {
  static constexpr const char * string_value = "-pilot-seed-value";

  static constexpr bool expect_assignment = true;

  using value_type = uint_t;

  static value_type convert( std::string optValue ) {
    return std::stoul( optValue );
  }

  static value_type get_default() {
    return 1111;
  }
};



//////////////// PILOT ACTOR LEARN RATE
template <>
struct traits <opt::kind::pilot_lrate_actor> {
  static constexpr const char * string_value = "-pilot-lrate-actor";

  static constexpr bool expect_assignment = true;

  using value_type = learn::fp_t;

  static value_type convert( std::string optValue ) {
    auto val = std::stof( optValue );

    if (val <= 0 or val >= 1) {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: in range (0, 1)");
    }
    return val;
  }

  static value_type get_default() {
    return 0.05f;
  }
};

//////////////// PILOT CRITIC LEARN RATE
template <>
struct traits <opt::kind::pilot_lrate_critic> {
  static constexpr const char * string_value = "-pilot-lrate-critic";

  static constexpr bool expect_assignment = true;

  using value_type = learn::fp_t;

  static value_type convert( std::string optValue ) {
    auto val = std::stof( optValue );

    if (val <= 0 or val >= 1) {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: in range (0, 1)");
    }
    return val;
  }

  static value_type get_default() {
    return 0.1f;
  }
};

//////////////// PILOT TARGET DIR
template <>
struct traits <opt::kind::pilot_target_dir> {
  static constexpr const char * string_value = "-pilot-target-dir";

  static constexpr bool expect_assignment = true;

  using value_type = std::string;

  static value_type convert( std::string optValue ) {
    return optValue + std::string(optValue[optValue.size()-1] == '/' ? "" : "/"); // Append bar if not having
  }

  static value_type get_default() {
    return "";
  }
};

//////////////// PILOT MINIBATCH
template <>
struct traits <opt::kind::pilot_minibatch> {
  static constexpr const char * string_value = "-pilot-minibatch";

  static constexpr bool expect_assignment = true;

  using value_type = uint_t;

  static value_type convert( std::string optValue ) {
    auto mb = std::stoul( optValue );
    if (mb > global::MaxBatchSize) {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Max value is " + std::to_string(global::MaxBatchSize));
    }
    return mb;
  }

  static value_type get_default() {
    return 32;
  }
};

//////////////// PILOT SAMPLE BATCH DECAY
template <>
struct traits <opt::kind::pilot_sample_batch_decay> {
  static constexpr const char * string_value = "-pilot-sbdecay";

  static constexpr bool expect_assignment = true;

  using value_type = learn::fp_t;

  static value_type convert( std::string optValue ) {
    auto val = std::stof( optValue );

    if (val <= 0 or val >= 1) {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: in range (0, 1)");
    }
    return val;
  }

  static value_type get_default() {
    return 0.9f;
  }
};

//////////////// PILOT REGULARIZATION
template <>
struct traits <opt::kind::pilot_regularization> {
  static constexpr const char * string_value = "-pilot-regularization";

  static constexpr bool expect_assignment = true;

  using value_type = learn::fp_t;

  static value_type convert( std::string optValue ) {
    auto val = std::stof( optValue );

    if (val < 0 or val >= 1) {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: in range [0, 1)");
    }
    return val;
  }

  static value_type get_default() {
    return 0.7f;
  }
};

//////////////// PILOT ADAM MOMENT
template <>
struct traits <opt::kind::pilot_adam_moment> {
  static constexpr const char * string_value = "-pilot-adam-moment";

  static constexpr bool expect_assignment = true;

  using value_type = learn::fp_t;

  static value_type convert( std::string optValue ) {
    auto val = std::stof( optValue );

    if (val < 0 or val >= 1) {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: in range [0, 1)");
    }
    return val;
  }
  

  static value_type get_default() {
    return 0.9f;
  }
};

//////////////// PILOT ADAM SQUARE
template <>
struct traits <opt::kind::pilot_adam_square> {
  static constexpr const char * string_value = "-pilot-adam-square";

  static constexpr bool expect_assignment = true;

  using value_type = learn::fp_t;

  static value_type convert( std::string optValue ) {
    auto val = std::stof( optValue );

    if (val < 0 or val >= 1) {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: in range [0, 1)");
    }
    return val;
  }

  static value_type get_default() {
    return 0.999f;
  }
};




//////////////// RUNNER SEED KIND
template <>
struct traits <opt::kind::runner_seed_kind> {
  static constexpr const char * string_value = "-runner-seed-kind";

  static constexpr bool expect_assignment = true;

  using value_type = learn::seed_kind;

  static value_type convert( std::string optValue ) {
    if (optValue == "fix") {
      return learn::seed_kind::fix;
    } else if (optValue == "random") {
      return learn::seed_kind::rnd;
    } else {
      throw std::runtime_error("Invalid option in '" + std::string(string_value) + "' : '" + optValue + "'. Allowed: [fix|random]");
    }
  }

  static value_type get_default() {
    return learn::seed_kind::fix;
  }
};

//////////////// RUNNER SEED VALUE
template <>
struct traits <opt::kind::runner_seed_value> {
  static constexpr const char * string_value = "-runner-seed-value";

  static constexpr bool expect_assignment = true;

  using value_type = uint_t;

  static value_type convert( std::string optValue ) {
    return std::stoul( optValue );
  }

  static value_type get_default() {
    return 1111;
  }
};

//////////////// RUNNER TRIALS
template <>
struct traits <opt::kind::runner_trials> {
  static constexpr const char * string_value = "-runner-trials";

  static constexpr bool expect_assignment = true;

  using value_type = uint_t;

  static value_type convert( std::string optValue ) {
    return std::stoul( optValue );
  }

  static value_type get_default() {
    return 1;
  }
};



} // namespace opt
