import os

from config_sorts import sorts

template = """\
#include "test_sort.h"

using std::swap;

#include <algorithms/sort_{name}.h>

TEST_SORT({name})

"""

if __name__ == '__main__':
    this_dir = os.path.dirname(os.path.realpath(__file__))
    out_dir = os.path.join(this_dir, "..", "tests")

    for name, _ in sorts.items():
        filename = "{out_dir}/test_sort_{name}.cpp".format(
            out_dir=out_dir, name=name)

        print("Generating {:}".format(filename))

        with open(filename, "w") as f:
            f.write(template.format(name=name))
