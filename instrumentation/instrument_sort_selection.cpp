#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_selection.h>

int main() {
    instrument(sort_selection, int64_t, 0, 262144);
}

