#include <cstdlib>
#include <cstring>

#include <benchmark/benchmark.h>
#include <numeric>
#include <random>

#include <algorithms/sort_merge_topdown_if_not_sorted.h>

constexpr const int n_min = 8;
constexpr const int n_max = 16777216;

static void sort_merge_topdown_if_not_sorted_random(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(a.begin(), a.end(), rng);

  for (auto _ : state) {
    sort_merge_topdown_if_not_sorted(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_merge_topdown_if_not_sorted_random)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_merge_topdown_if_not_sorted_sorted(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);

  for (auto _ : state) {
    sort_merge_topdown_if_not_sorted(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_merge_topdown_if_not_sorted_sorted)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_merge_topdown_if_not_sorted_reversed(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::iota(a.rbegin(), a.rend(), 0);

  for (auto _ : state) {
    sort_merge_topdown_if_not_sorted(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_merge_topdown_if_not_sorted_reversed)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_merge_topdown_if_not_sorted_constant(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::fill(a.begin(), a.end(), 5);

  for (auto _ : state) {
    sort_merge_topdown_if_not_sorted(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_merge_topdown_if_not_sorted_constant)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

static void sort_merge_topdown_if_not_sorted_intermittent(benchmark::State& state) {
  const auto n = state.range(0);
  std::vector<int> a(n);
  std::fill(a.begin(), a.end(), 5);
  for (int i = 0; i < n; i += 2) {
    a[i] = -a[i];
  }

  for (auto _ : state) {
    sort_merge_topdown_if_not_sorted(a.data(), n);
  }

  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_merge_topdown_if_not_sorted_intermittent)
    ->RangeMultiplier(2)
    ->Range(n_min, n_max)
    ->Complexity(benchmark::oN)
    ->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();

