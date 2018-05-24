#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_shell.h>

int main() {
    instrument(sort_shell, int64_t, 0, 1048576);
}

