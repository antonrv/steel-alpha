
module;

#include <boost/interprocess/ipc/message_queue.hpp>

// #include <boost/process/pipe.hpp>
// #include <boost/process/child.hpp>
// #include <boost/process/io.hpp>

module SteelRT.Learn.IPC;

// Need explicit instantiation
namespace boost {

template void interprocess::message_queue_t<interprocess::offset_ptr<void, long, unsigned long, 0ul> >::receive(void*, unsigned long, unsigned long&, unsigned int&);

template bool interprocess::message_queue_t<interprocess::offset_ptr<void, long, unsigned long, 0ul> >::try_send(void const*, unsigned long, unsigned int);


} // namespace boost

namespace learn::ipc {

// boost::process::ipstream pipes::outStream;
// boost::process::ipstream pipes::errStream;
// boost::process::child pipes::pilotProcess;

} // namespace learn::ipc
