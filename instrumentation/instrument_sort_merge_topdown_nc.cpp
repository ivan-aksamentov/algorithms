#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_merge_topdown_nc.h>

int main() {
    instrument(sort_merge_topdown_nc, int64_t, 0, 16777216);
}

