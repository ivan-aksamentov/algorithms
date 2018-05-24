#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_quick.h>

int main() {
    instrument(sort_quick, int64_t, 0, 16777216);
}

