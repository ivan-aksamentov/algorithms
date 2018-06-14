#pragma once
#include <algorithm>
#include <cstddef>

using std::swap;

template <typename T>
void sort_selection(T* a, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    size_t imin = i;
    for (size_t j = i + 1; j < size; ++j)
      if (a[j] < a[imin])
        imin = j;
    if (imin != i)
      swap(a[i], a[imin]);
  }
}
