#pragma once

#include <algorithm>
#include <cstdint>

// Find longest sequence of 0 bits in a positive integer
// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
int binary_gap(uint32_t N) {
  int current_gap = 0;  // length of the gap so far
  int longest_gap = 0;
  bool in_gap = false;  // have we encountered an opening 1?

  while (N) {
    while (!(N & 1)) {
      N = N >> 1;
      ++current_gap;
    }

    if (in_gap) {
      longest_gap = std::max(current_gap, longest_gap);
    }

    N = N >> 1;
    in_gap = true;
    current_gap = 0;
  }
  return longest_gap;
}
