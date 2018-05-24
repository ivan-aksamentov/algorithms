#include <cstdlib>
#include <cstring>

#include <benchmark/benchmark.h>
#include <numeric>
#include <random>

#include <algorithms/sort_insertion_improved.h>

constexpr const int n_min = 8;
constexpr const int n_max = 1048576;

static void sort_insertion_improved_random(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(a.begin(), a.end(), rng);

  for (auto _ : state) {
    sort_insertion_improved(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_insertion_improved_random)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_insertion_improved_sorted(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);

  for (auto _ : state) {
    sort_insertion_improved(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_insertion_improved_sorted)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_insertion_improved_reversed(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.rbegin(), a.rend(), 0);

  for (auto _ : state) {
    sort_insertion_improved(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_insertion_improved_reversed)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_insertion_improved_constant(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::fill(a.begin(), a.end(), 5);

  for (auto _ : state) {
    sort_insertion_improved(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_insertion_improved_constant)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_insertion_improved_intermittent(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::fill(a.begin(), a.end(), 5);
  for (int i = 0; i < n; i += 2) {
    a[i] = -a[i];
  }

  for (auto _ : state) {
    sort_insertion_improved(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_insertion_improved_intermittent)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();

