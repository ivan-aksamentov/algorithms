#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_insertion.h>

int main() {
    instrument(sort_insertion, int64_t, 0, 262144);
}

