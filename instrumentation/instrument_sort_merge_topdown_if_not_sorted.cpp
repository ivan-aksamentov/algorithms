#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_merge_topdown_if_not_sorted.h>

int main() {
    instrument(sort_merge_topdown_if_not_sorted, int64_t, 0, 16777216);
}

