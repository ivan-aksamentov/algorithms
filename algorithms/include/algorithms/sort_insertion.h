#pragma once

#include <algorithm>

using std::swap;

template <typename T>
void sort_insertion(T* a, int size) {
  for (int i = 0; i < size; ++i)
    for (int j = i; (j > 0) && (a[j] < a[j - 1]); --j)
      swap(a[j], a[j - 1]);
}
