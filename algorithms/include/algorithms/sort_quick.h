#pragma once

#include <algorithm>

namespace details_sort_quick {

using std::swap;

template <typename T>
int partition(T* a, int lo, int hi) {
  auto i = lo;
  auto j = hi + 1;

  while (true) {
    while (a[++i] < a[lo]) {
      if (i == hi)
        break;
    }

    while (a[lo] < a[--j]) {
      if (j == lo)
        break;
    }

    if (i >= j)
      break;

    swap(a[i], a[j]);
  }

  swap(a[lo], a[j]);

  return j;
}

template <typename T>
void sort_quick_impl(T* a, int lo, int hi) {
  if (hi <= lo)
    return;
  int j = partition(a, lo, hi);
  sort_quick_impl(a, lo, j - 1);
  sort_quick_impl(a, j + 1, hi);
}

}  // namespace details_sort_quick

template <typename T>
void sort_quick(T* a, int size) {
  std::random_shuffle(a, a + size);
  details_sort_quick::sort_quick_impl(a, 0, size - 1);
}
