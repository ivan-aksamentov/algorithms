#pragma once

#include <algorithm>

using std::swap;

template <typename T>
void sort_shell(T* a, size_t size) {
  if (size == 2) {
    if (a[1] < a[0]) {
      swap(a[0], a[1]);
    }
    return;
  }

  size_t h = 0;
  while (h < size / 3) {
    h = 3 * h + 1;
  }

  while (h >= 1) {
    for (size_t i = 0; i < size; ++i)
      for (size_t j = i; (j >= h) && (a[j] < a[j - h]); j -= h)
        swap(a[j], a[j - h]);
    h = h / 3;
  }
}
