#pragma once

namespace details_sort_merge_topdown {
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
void sort_merge_topdown(T* a, T* aux, int lo, int hi) {
    if (hi <= lo)
        return;
    auto mid = lo + (hi - lo) / 2;
    sort_merge_topdown(a, aux, lo, mid);
    sort_merge_topdown(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}
}

template<typename T>
void sort_merge_topdown(T* a, int size) {
    std::vector<T> aux(size);
    details_sort_merge_topdown::sort_merge_topdown(a, aux.data(), 0, size - 1);
}
