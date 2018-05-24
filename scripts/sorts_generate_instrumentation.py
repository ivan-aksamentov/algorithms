import os

from config_sorts import sorts

template = """\
#include <cstdint>

#include "instrument_sort.h"
#include <algorithms/sort_{name}.h>

int main() {{
    instrument(sort_{name}, int64_t, 0, {n_max});
}}

"""

if __name__ == '__main__':
    this_dir = os.path.dirname(os.path.realpath(__file__))
    out_dir = os.path.join(this_dir, "..", "instrumentation")

    for name, n_max in sorts.items():
        filename = "{out_dir}/instrument_sort_{name}.cpp".format(
            out_dir=out_dir, name=name)

        print("Generating {:}".format(filename))

        with open(filename, "w") as f:
            f.write(template.format(name=name, n_max=n_max))
