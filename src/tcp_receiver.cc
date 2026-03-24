#include "tcp_receiver.hh"
#include "debug.hh"

#include <algorithm>

using namespace std;

void TCPReceiver::receive( TCPSenderMessage message )
{
  // Your code here.
  if ( message.RST ) {
    rst_ = true;
    reassembler_.reader().set_error();
    return;
  }

  if ( !syn_received_ ) {
    if ( !message.SYN ) {
      return;
    }
    syn_received_ = true;
    isn_ = message.seqno;
  }

  // Absolute checkpoint near the first unassembled sequence number.
  const uint64_t checkpoint = writer().bytes_pushed() + 1 + writer().is_closed();
  const uint64_t abs_seqno = message.seqno.unwrap( isn_, checkpoint );

  // Convert absolute seqno space (includes SYN) to stream index space (payload starts at 0).
  const uint64_t stream_index = abs_seqno + static_cast<uint64_t>( message.SYN ) - 1;
  reassembler_.insert( stream_index, std::move( message.payload ), message.FIN );
}

TCPReceiverMessage TCPReceiver::send() const
{
  // Your code here.
  TCPReceiverMessage msg;

  if ( syn_received_ ) {
    const uint64_t ack_abs = writer().bytes_pushed() + 1 + writer().is_closed();
    msg.ackno = Wrap32::wrap( ack_abs, isn_ );
  }

  msg.window_size = static_cast<uint16_t>( min( writer().available_capacity(), static_cast<uint64_t>( UINT16_MAX ) ) );
  msg.RST = rst_ || reader().has_error();
  return msg;
}
