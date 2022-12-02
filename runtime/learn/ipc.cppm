
module;

// #include <boost/process/pipe.hpp>
// #include <boost/process/child.hpp>
// #include <boost/process/io.hpp>

#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>



export module SteelRT.Learn.IPC;


import SteelRT.Util.Types;
import SteelRT.Learn.Types;

import SteelRT.Util.Assert;
#include "assert.hpp"

import <vector>;

// import <iostream>; // DBG XXX


namespace learn::ipc {


export
class parameters {
private:

  using elem_type = fp_t;

  using vec_size_t = std::vector<std::size_t>;

  const vec_size_t m_perLayerByteStart;
  const vec_size_t m_perLayerByteCount;

  using vec_fun_t = std::vector<learn::fun>;

  const vec_fun_t m_perLayerFunction;


  const str_t m_identifierStr;
  const approx::ann::propagate m_propagate = approx::ann::propagate::fwd;

  boost::interprocess::shared_memory_object m_shmemObj;
  boost::interprocess::mapped_region m_mapRegion;

private:

  static vec_size_t make_layer_starts( const vec_size_t& perLayerByteCount ) noexcept {

    vec_size_t retStarts(perLayerByteCount.size());

    retStarts[0] = sizeof(version_t);
    for (auto lId = 1u; lId < perLayerByteCount.size(); lId++) {
      retStarts[ lId ] = retStarts[ lId - 1 ] + perLayerByteCount[ lId - 1 ];
    }

    return retStarts;
  }


public:

  struct create_only_t {};
  struct open_only_t {};

  std::size_t get_total_size() const noexcept {
    auto lastId = m_perLayerByteStart.size() - 1;
    return m_perLayerByteStart[lastId] + m_perLayerByteCount[lastId];
  }

public:

  parameters( const vec_size_t& perLayerByteCount, const vec_fun_t& perLayerFunction, const str_t& shmemId, open_only_t, approx::ann::propagate annProp ) :
    m_perLayerByteStart( make_layer_starts(perLayerByteCount) ),
    m_perLayerByteCount(perLayerByteCount),
    m_perLayerFunction(perLayerFunction),
    m_identifierStr(shmemId),
    m_propagate(annProp),
    m_shmemObj( boost::interprocess::open_only, m_identifierStr.c_str(), boost::interprocess::read_only ),
    m_mapRegion( m_shmemObj, boost::interprocess::read_only, 0, get_total_size() )
  { 
    ensure(m_perLayerByteStart.size() == m_perLayerByteCount.size(), "Wrong layer count");
    ensure(m_perLayerByteStart.size() == m_perLayerFunction.size(), "Wrong layer count");

    if (m_propagate != approx::ann::propagate::fwd) {
      boost::interprocess::shared_memory_object::remove(m_identifierStr.c_str());
      throw std::logic_error("This ipc::parameters constructor expects forward propagation");
    }
  }

  // Read-write (pilot fwd/bwd-propagation) constructor
  parameters( const vec_size_t& perLayerByteCount, const vec_fun_t& perLayerFunction, const str_t& shmemId, create_only_t, approx::ann::propagate annProp ) :
    m_perLayerByteStart( make_layer_starts(perLayerByteCount) ),
    m_perLayerByteCount(perLayerByteCount),
    m_perLayerFunction(perLayerFunction),
    m_identifierStr(shmemId),
    m_propagate(annProp),
    m_shmemObj( boost::interprocess::create_only, m_identifierStr.c_str(), boost::interprocess::read_write ),
    m_mapRegion( m_shmemObj, boost::interprocess::read_write, 0, get_total_size() )
  {
    ensure(m_perLayerByteStart.size() == m_perLayerByteCount.size(), "Wrong layer count");
    ensure(m_perLayerByteStart.size() == m_perLayerFunction.size(), "Wrong layer count");

    if (m_propagate != approx::ann::propagate::bwd) {
      boost::interprocess::shared_memory_object::remove(m_identifierStr.c_str());
      throw std::logic_error("This ipc::parameters constructor expects backward propagation");
    }
    m_shmemObj.truncate( get_total_size() );
    // std::cout << "SHMEM Start : " << m_mapRegion.get_address() << std::endl; // DBG XXX
  }

  static void pre_remove( const str_t& shmemId ) noexcept {
    boost::interprocess::shared_memory_object::remove( shmemId.c_str() );
  }

  parameters() = delete;
  parameters(parameters&&) = delete;
  parameters(const parameters&) = delete;

  ~parameters() {
    if (m_propagate == approx::ann::propagate::bwd) {
      boost::interprocess::shared_memory_object::remove(m_identifierStr.c_str());
    }
  }

  const str_t& get_identifier() const noexcept {
    return m_identifierStr;
  }

  
  /// FULL CASTINGS
  template <typename RetType, std::size_t ParamLayerId, learn::fun ParamLayerFun>
  const RetType& get_cast() const {

    static_assert( ParamLayerFun == learn::fun::matrix or ParamLayerFun == learn::fun::sample_norm or ParamLayerFun == learn::fun::batch_norm or ParamLayerFun == learn::fun::bias );

    ensure(ParamLayerId < m_perLayerByteCount.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerByteStart.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerFunction.size(), "Out of bounds");
    ensure(m_perLayerByteCount[ParamLayerId] == sizeof(RetType), "Unexpected param elem count");
    ensure(m_perLayerFunction[ParamLayerId] == ParamLayerFun, "Unexpected param layer function");

    return *reinterpret_cast<RetType const *>( static_cast<char const *>( m_mapRegion.get_address() ) + m_perLayerByteStart[ParamLayerId] );
  }


  template <typename RetType, std::size_t ParamLayerId, learn::fun ParamLayerFun>
  RetType& edit_cast() noexcept {

    static_assert( ParamLayerFun == learn::fun::matrix or ParamLayerFun == learn::fun::sample_norm or ParamLayerFun == learn::fun::batch_norm or ParamLayerFun == learn::fun::bias );

    ensure(ParamLayerId < m_perLayerByteCount.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerByteStart.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerFunction.size(), "Out of bounds");
    ensure(m_perLayerByteCount[ParamLayerId] == sizeof(RetType), "Unexpected param elem count");
    ensure(m_perLayerFunction[ParamLayerId] == ParamLayerFun, "Unexpected param layer function");

    return *reinterpret_cast<RetType*>( static_cast<char *>( m_mapRegion.get_address() ) + m_perLayerByteStart[ParamLayerId] );
  }


  /// PARTIAL CASTINGS
  template <typename RetType, std::size_t ParamLayerId, learn::fun ParamLayerFun, std::size_t ByteShift>
  const RetType& get_partial_cast() const noexcept {

    static_assert( ParamLayerFun == learn::fun::matrix or ParamLayerFun == learn::fun::sample_norm or ParamLayerFun == learn::fun::batch_norm or ParamLayerFun == learn::fun::bias );

    ensure(ParamLayerId < m_perLayerByteCount.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerByteStart.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerFunction.size(), "Out of bounds");

    ensure(sizeof(RetType) + ByteShift <= m_perLayerByteCount[ParamLayerId], "Out of bounds in partial cast" );
    ensure(m_perLayerFunction[ParamLayerId] == ParamLayerFun, "Unexpected param layer function");

    return *reinterpret_cast<RetType const *>( static_cast<char const *>( m_mapRegion.get_address() ) + m_perLayerByteStart[ParamLayerId] + ByteShift );
  }


  template <typename RetType, std::size_t ParamLayerId, learn::fun ParamLayerFun, std::size_t ByteShift>
  RetType& edit_partial_cast() noexcept {

    static_assert( ParamLayerFun == learn::fun::matrix or ParamLayerFun == learn::fun::sample_norm or ParamLayerFun == learn::fun::batch_norm or ParamLayerFun == learn::fun::bias );

    ensure(ParamLayerId < m_perLayerByteCount.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerByteStart.size(), "Out of bounds");
    ensure(ParamLayerId < m_perLayerFunction.size(), "Out of bounds");

    ensure(sizeof(RetType) + ByteShift <= m_perLayerByteCount[ParamLayerId], "Out of bounds in partial cast" );
    ensure(m_perLayerFunction[ParamLayerId] == ParamLayerFun, "Unexpected param layer function");

    return *reinterpret_cast<RetType*>( static_cast<char *>( m_mapRegion.get_address() ) + m_perLayerByteStart[ParamLayerId] + ByteShift );
  }


  void update_version() noexcept {
    // Version is the first element
    (*static_cast<version_t*>( m_mapRegion.get_address() ))++;
  }

  version_t get_version() const noexcept {
    // Version is the first element
    return (*static_cast<version_t const *>( m_mapRegion.get_address() ));
  }


  void * edit_ptr() const noexcept {
    return static_cast<void *>( m_mapRegion.get_address() );
  }

  void const * get_ptr() const noexcept {
    return static_cast<void const *>( m_mapRegion.get_address() );
  }

};



export
class queue {
private:

  const str_t m_identifier;

  boost::interprocess::message_queue m_boostQueue;

protected:

  // Runner constructor
  queue(const str_t& queueIdStr) :
    m_identifier(queueIdStr),
    m_boostQueue( boost::interprocess::open_only, queueIdStr.c_str() )
  {}


  // Pilot constructor
  queue(const str_t& queueIdStr, std::size_t maxNumMsg, std::size_t maxMsgSize) :
    m_identifier(queueIdStr),
    m_boostQueue( boost::interprocess::create_only, queueIdStr.c_str(), maxNumMsg, maxMsgSize )
  {}



  // Callable from pilot only
  bool remove( ) {
    return boost::interprocess::message_queue::remove( m_identifier.c_str() );
  }

  static bool pre_remove( const str_t& idStr ) {
    return boost::interprocess::message_queue::remove( idStr.c_str() );
  }



protected:

  template <std::size_t MessageSize>
  bool try_send( void const * msgAddr ) {

    // This may fail if queue is full. In that case the msg is discarded, but importantly the worker won't be blocked
    // Caller will emit a warning if could not send message
    return m_boostQueue.try_send( msgAddr, MessageSize, /*priority*/0 );
  }


protected:

  template <std::size_t MaxMsgSize>
  std::size_t receive( void * recBuffer ) {

    std::size_t receivedSize;
    unsigned int receivedPriority;

    // Blocks until message is received
    m_boostQueue.receive( recBuffer, MaxMsgSize, receivedSize, receivedPriority );

    // Copy buffer
    return receivedSize;

  }

public:

  std::size_t get_num_msg() const noexcept {
    return m_boostQueue.get_num_msg();
  }

};


} // namespace learn::ipc
