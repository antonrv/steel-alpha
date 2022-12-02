export module Platform.Traits;

export import Plat.EnumDefinitions;

import SteelRT.Util.Types;
import SteelRT.Util.Sequence;
import App.EnumDefinitions;

import <cstdint>;

namespace plat {


export
template <processor PIdOrMemId>
struct ptraits;

// On envy
// L1d:
// cat /sys/devices/system/cpu/cpu0/cache/index0/size 
// 32K
// L1i:
// cat /sys/devices/system/cpu/cpu0/cache/index1/size 
// 32K
// L2:
// cat /sys/devices/system/cpu/cpu0/cache/index2/size 
// 256K
// L3:
// cat /sys/devices/system/cpu/cpu0/cache/index3/size 
// 6144K

export
template <>
struct ptraits<processor::smp0> {

  static constexpr unsigned core_count = 4; // Inferred from 'cat /proc/cpuinfo' or lscpu
  static constexpr unsigned threads_per_core = 2; // Inferred from 'cat /proc/cpuinfo' or lscpu
  static constexpr unsigned max_threads = 8; // Just the product of the above
  static constexpr arch arch_value = arch::x86_64; // Inferred from 'uname -m' or lscpu
  static constexpr host host_value = host::hpenvy; // Inferred from 'uname -n' or enum node node_value

  using frequency_set = util::sequence::enum_t<freq, ghz800, ghz2400>; // Info freqs per core ?

  static constexpr std::size_t cache_kb_L1 = 256; // lscpu
  static constexpr std::size_t cache_kb_L2 = 1024; // lscpu
  static constexpr std::size_t cache_kb_L3 = 6144; // lscpu

  // static constexpr  str_identifier = "smp0"; // Enum macro conversion
  // using allowed_app_values = util::sequence::enum_t<app::id, app::id::poison_pill, app::id::ent, app::id::foo, app::id::bar, app::id::zee>; Deduced from app::id arch 
};

export
template <>
struct ptraits<processor::cuda_device_geforce_gt_740m> {

  static constexpr unsigned core_count = 2; // deviceQuery # SM
  static constexpr unsigned threads_per_core = 4; // Max number of streams per SM. Any (not too big) number
  static constexpr unsigned max_threads = 8; // Just the product of the above
  static constexpr arch arch_value = arch::cuda_sm_35; // deviceQuery compute major
  static constexpr host host_value = host::hpenvy; // Inferred from 'uname -n' or enum node node_value


};

export
template <processor PIdOrMemId>
struct mtraits;

struct mtraits<memspace::smp0> {
  static constexpr memkind kind = memkind::volatil;
  static constexpr std::size_t size_mb = 1000000;// 16gb;
  static constexpr const char * mount = "";
};

struct mtraits<memspace::disk> {
  static constexpr memkind kind = memkind::persistent;
  static constexpr std::size_t size_mb = 1000000;// 16gb;
  static constexpr const char * mount = "/tmp/";
};


// // This sequence reflects all possible groups
// export
// enum class group : enum_uint_t {smp0, smp1, numa};
// 
// // This order reflects proximity
// export
// enum class interconnect : enum_uint_t {coherent_noc, coherent_numa};


// export
// template <group GId>
// struct group_traits;

// export
// template <>
// struct group_traits<group::smp0> {
//   using processor_seq = util::sequence::enum_t<processor, processor::core0, processor::core1>;
//   static constexpr interconnect interconnect_kind = interconnect::coherent_noc;
// };
// 
// export
// template <>
// struct group_traits<group::smp1> {
//   using processor_seq = util::sequence::enum_t<processor, processor::core2, processor::core3>;
//   static constexpr interconnect interconnect_kind = interconnect::coherent_noc;
// };
// 
// export
// template <>
// struct group_traits<group::numa> {
//   using processor_seq = util::sequence::unique_t< util::sequence::intersect_t< group_traits<group::smp0>::processor_seq, group_traits<group::smp1>::processor_seq > >;
//   static constexpr interconnect interconnect_kind = interconnect::coherent_numa;
// };

} // namespace plat
