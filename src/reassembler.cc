#include "reassembler.hh"
#include "debug.hh"

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring )
{
  const uint64_t segment_end = first_index + data.size();
  if ( is_last_substring ) {
    eof_index_ = segment_end;
  }

  const uint64_t first_unacceptable_index = next_index_ + output_.writer().available_capacity();

  const uint64_t clipped_start = max( first_index, next_index_ );
  const uint64_t clipped_end = min( segment_end, first_unacceptable_index );

  if ( clipped_start < clipped_end ) {
    uint64_t merged_start = clipped_start;
    uint64_t merged_end = clipped_end;
    string merged_data = data.substr( clipped_start - first_index, clipped_end - clipped_start );

    auto it = tmp_stored.lower_bound( merged_start );
    if ( it != tmp_stored.begin() ) {
      auto prev = it;
      --prev;
      const uint64_t prev_start = prev->first;
      const uint64_t prev_end = prev_start + prev->second.size();
      if ( prev_end >= merged_start ) {
        it = prev;
      }
    }

    while ( it != tmp_stored.end() ) {
      const uint64_t cur_start = it->first;
      const uint64_t cur_end = cur_start + it->second.size();
      if ( cur_start > merged_end ) {
        break;
      }

      const uint64_t new_start = min( merged_start, cur_start );
      const uint64_t new_end = max( merged_end, cur_end );
      string new_data( new_end - new_start, '\0' );

      for ( uint64_t i = merged_start; i < merged_end; ++i ) {
        new_data[i - new_start] = merged_data[i - merged_start];
      }
      for ( uint64_t i = cur_start; i < cur_end; ++i ) {
        new_data[i - new_start] = it->second[i - cur_start];
      }

      merged_start = new_start;
      merged_end = new_end;
      merged_data = std::move( new_data );
      it = tmp_stored.erase( it );
    }

    tmp_stored.emplace( merged_start, std::move( merged_data ) );
  }

  while ( !tmp_stored.empty() ) {
    auto it = tmp_stored.begin();
    if ( it->first != next_index_ ) {
      break;
    }
    output_.writer().push( it->second );
    next_index_ += it->second.size();
    tmp_stored.erase( it );
  }

  if ( eof_index_.has_value() && next_index_ == eof_index_.value() ) {
    output_.writer().close();
  }
}

// How many bytes are stored in the Reassembler itself?
// This function is for testing only; don't add extra state to support it.
uint64_t Reassembler::count_bytes_pending() const
{
  uint64_t count = 0;
  for ( const auto& [index, data] : tmp_stored ) {
    (void)index;
    count += data.size();
  }
  return count;
}
