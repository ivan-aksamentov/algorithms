#pragma once
#include "sort_insertion.h"

namespace details_sort_merge_cutoff {
template<typename T>
void merge(T* a, T* aux, int lo, int mid, int hi) {
    auto i = lo;
    auto j = mid + 1;

    for (auto k = lo; k <= hi; ++k) {
        aux[k] = a[k];
    }

    for (auto k = lo; k <= hi; ++k) {
        if      (i > mid)           a[k] = aux[j++];
        else if (j > hi)            a[k] = aux[i++];
        else if (aux[j] < aux[i])   a[k] = aux[j++];
        else                        a[k] = aux[i++];
    }
}

template<typename T>
void sort_merge_topdown_cutoff(T* a, T* aux, int lo, int hi) {
    if (hi <= lo)
        return;

    auto size = hi - lo;
    constexpr int cutoff_size = 10;
    if (size < cutoff_size)
        sort_insertion(a + lo, size);

    auto mid = lo + (hi - lo) / 2;
    sort_merge_topdown_cutoff(a, aux, lo, mid);
    sort_merge_topdown_cutoff(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}
}

template<typename T>
void sort_merge_topdown_cutoff(T* a, int size) {
    std::vector<T> aux(size);
    details_sort_merge_cutoff::sort_merge_topdown_cutoff(a, aux.data(), 0, size - 1);
}
