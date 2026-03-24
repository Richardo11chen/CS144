#include "wrapping_integers.hh"
#include "debug.hh"

using namespace std;

Wrap32 Wrap32::wrap( uint64_t n, Wrap32 zero_point )
{
  // Your code here.
  return Wrap32 { zero_point.raw_value_ + static_cast<uint32_t>( n ) };
}

uint64_t Wrap32::unwrap( Wrap32 zero_point, uint64_t checkpoint ) const
{
  // Your code here.
  static constexpr uint64_t MOD = 1ULL << 32;

  // Offset in one wrap cycle: (this - zero_point) mod 2^32.
  const uint64_t offset = static_cast<uint32_t>( raw_value_ - zero_point.raw_value_ );

  // Candidate with the same upper 32 bits as checkpoint.
  uint64_t candidate = ( checkpoint & 0xFFFFFFFF00000000ULL ) + offset;
  // uint64_t k = checkpoint / MOD;
  // uint64_t candidate = k * MOD + offset;
  // Adjust by one cycle if that yields a closer absolute sequence number.
  if ( candidate <= checkpoint ) {
    if ( checkpoint - candidate > ( MOD >> 1 ) && candidate <= UINT64_MAX - MOD ) {
      candidate += MOD;
    }
  } else {
    if ( candidate - checkpoint > ( MOD >> 1 ) && candidate >= MOD ) {
      candidate -= MOD;
    }
  }
  return candidate;
}
