import os

from config_sorts import sorts

template = """\
#include <cstdlib>
#include <cstring>

#include <benchmark/benchmark.h>
#include <numeric>
#include <random>

#include <algorithms/sort_{name}.h>

constexpr const int n_min = 8;
constexpr const int n_max = {n_max};

static void sort_{name}_random(benchmark::State& state) {{
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(a.begin(), a.end(), rng);

  for (auto _ : state) {{
    sort_{name}(a.data(), n);
  }}

  state.SetComplexityN(state.range(0));
}}

BENCHMARK(sort_{name}_random)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_{name}_sorted(benchmark::State& state) {{
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);

  for (auto _ : state) {{
    sort_{name}(a.data(), n);
  }}

  state.SetComplexityN(state.range(0));
}}

BENCHMARK(sort_{name}_sorted)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_{name}_reversed(benchmark::State& state) {{
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.rbegin(), a.rend(), 0);

  for (auto _ : state) {{
    sort_{name}(a.data(), n);
  }}

  state.SetComplexityN(state.range(0));
}}

BENCHMARK(sort_{name}_reversed)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_{name}_constant(benchmark::State& state) {{
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::fill(a.begin(), a.end(), 5);

  for (auto _ : state) {{
    sort_{name}(a.data(), n);
  }}

  state.SetComplexityN(state.range(0));
}}

BENCHMARK(sort_{name}_constant)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_{name}_intermittent(benchmark::State& state) {{
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::fill(a.begin(), a.end(), 5);
  for (int i = 0; i < n; i += 2) {{
    a[i] = -a[i];
  }}

  for (auto _ : state) {{
    sort_{name}(a.data(), n);
  }}

  state.SetComplexityN(state.range(0));
}}

BENCHMARK(sort_{name}_intermittent)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();

"""

if __name__ == '__main__':
    this_dir = os.path.dirname(os.path.realpath(__file__))
    out_dir = os.path.join(this_dir, "..", "benchmarks")

    for name, n_max in sorts.items():

        filename = "{out_dir}/bench_sort_{name}.cpp".format(
            out_dir=out_dir,name=name)

        print("Generating {:}".format(filename))

        with open(filename, "w") as f:
            f.write(template.format(name=name, n_max=n_max))
