#pragma once

namespace details_sort_merge_topdown_nc {
template <typename T>
void merge_with_pingpong(T* a, T* aux, int lo, int mid, int hi) {
  auto i = lo;
  auto j = mid + 1;

  for (auto k = lo; k <= hi; ++k) {
    if (i > mid)
      aux[k] = a[j++];
    else if (j > hi)
      aux[k] = a[i++];
    else if (a[j] < a[i])
      aux[k] = a[j++];
    else
      aux[k] = a[i++];
  }
}

template <typename T>
void sort_merge_topdown_nc(T* a, T* aux, int lo, int hi) {
  if (hi <= lo)
    return;
  auto mid = lo + (hi - lo) / 2;
  sort_merge_topdown_nc(aux, a, lo, mid);
  sort_merge_topdown_nc(aux, a, mid + 1, hi);
  merge_with_pingpong(aux, a, lo, mid, hi);
}
}  // namespace details_sort_merge_topdown_nc

template <typename T>
void sort_merge_topdown_nc(T* a, int size) {
  std::vector<T> aux(a, a + size);
  details_sort_merge_topdown_nc::sort_merge_topdown_nc(
      a, aux.data(), 0, size - 1);
}
