#pragma once

namespace details_sort_merge_topdown_if_not_sorted {
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
void sort_merge_topdown_if_not_sorted(T* a, T* aux, int lo, int hi) {
    if (hi <= lo)
        return;
    auto mid = lo + (hi - lo) / 2;
    sort_merge_topdown_if_not_sorted(a, aux, lo, mid);
    sort_merge_topdown_if_not_sorted(a, aux, mid + 1, hi);

    if (a[mid] < a[mid + 1])
        return;

    merge(a, aux, lo, mid, hi);
}
}

template<typename T>
void sort_merge_topdown_if_not_sorted(T* a, int size) {
    std::vector<T> aux(size);
    details_sort_merge_topdown_if_not_sorted::sort_merge_topdown_if_not_sorted(
        a, aux.data(), 0, size - 1);
}
