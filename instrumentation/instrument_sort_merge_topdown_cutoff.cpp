#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_merge_topdown_cutoff.h>

int main() {
    instrument(sort_merge_topdown_cutoff, int64_t, 0, 16777216);
}

