#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity )
  : buffer_(), bytes_pushed_( 0 ), bytes_popped_( 0 ), capacity_( capacity ), closed_( false ), error_( false )
{}

void Writer::push( string data )
{
  if ( is_closed() ) {
    return;
  }
  if ( data.size() > available_capacity() ) {
    data.resize( available_capacity() );
  }
  buffer_ += data;
  bytes_pushed_ += data.size();
}

void Writer::close()
{
  closed_ = true;
}

bool Writer::is_closed() const
{
  return closed_;
}

uint64_t Writer::available_capacity() const
{
  return capacity_ - buffer_.size(); // Your code here.
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_pushed_; // Your code here.
}

string_view Reader::peek() const
{
  return string_view( buffer_.data(), buffer_.size() ); // Your code here.
}

void Reader::pop( uint64_t len )
{
  buffer_.erase( 0, len ); // Your code here.
  bytes_popped_ += len;
}

bool Reader::is_finished() const
{
  return closed_ && buffer_.empty();
}

uint64_t Reader::bytes_buffered() const
{
  return buffer_.size(); // Your code here.
}

uint64_t Reader::bytes_popped() const
{
  return bytes_popped_; // Your code here.
}
