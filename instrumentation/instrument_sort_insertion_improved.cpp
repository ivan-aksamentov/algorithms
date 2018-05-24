#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_insertion_improved.h>

int main() {
    instrument(sort_insertion_improved, int64_t, 0, 1048576);
}

