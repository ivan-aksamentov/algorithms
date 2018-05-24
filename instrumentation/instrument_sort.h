#include <algorithm>
#include <cinttypes>
#include <functional>
#include <random>
#include <vector>

#include "details/instrument_policy_count_operations.h"
#include "details/instrumented_t.h"
#include "details/literals.h"

namespace algorithms {

void print_int_human_readable(int64_t val, int base = 1024) {
  const char prefixes[] = "0kMGTPEZY";
  char const* prefix = prefixes;
  long double valf = static_cast<long double>(val);

  while (valf > base && prefixes) {
    valf = valf / base;
    ++prefix;
  }

  printf("%7.1Lf%c", valf, *prefix);
}

template <typename T>
void do_instrument(std::function<void(T*, size_t)> f, size_t n,
                   const std::string& name) {
  std::vector<T> a(n);
  std::iota(a.begin(), a.end(), 0);
  std::random_device rd;
  std::mt19937 rng(rd());
  std::shuffle(a.begin(), a.end(), rng);

  const auto& lg = InstrumentPolicy_CountOperations::log;
  InstrumentPolicy_CountOperations::log.reset();

  f(a.data(), a.size());

  print_int_human_readable(n);
  printf(" | ");
  print_int_human_readable(lg.swaps);
  print_int_human_readable(static_cast<int64_t>(lg.swap_distance_avg));
  print_int_human_readable(lg.swap_distance_max);
  printf(" | ");
  print_int_human_readable(lg.less_comparisons);
  print_int_human_readable(static_cast<int64_t>(lg.less_distance_avg));
  print_int_human_readable(lg.less_distance_max);
  printf(" | ");
  printf("\n");
}

template <typename T>
void do_instrument(std::function<void(T*, size_t)> f, size_t n_min,
                   size_t n_max, const std::string& name) {
  printf("%-8s", "n");
  printf(" | ");
  printf("%-24s", "       swaps");
  printf(" | ");
  printf("%-24s", "     comparisons");
  printf(" | ");

  printf("\n");

  printf("%-8s", "");

  printf(" | ");

  printf("%-8s", " count");
  printf("%-16s", "    distance");

  printf(" | ");

  printf("%-8s", " count");
  printf("%-16s", "    distance");

  printf(" | ");

  printf("\n");

  printf("%-8s", "");

  printf(" | ");

  printf("%-8s", "");
  printf("%-8s", "   avg");
  printf("%-8s", "   max");

  printf(" | ");

  printf("%-8s", "");
  printf("%-8s", "   avg");
  printf("%-8s", "   max");

  printf(" | ");

  printf("\n");

  printf("----------------------------------------------------------------");

  printf("\n");

  for (size_t i = 0, n = n_min; n <= n_max;
       n = static_cast<size_t>(std::pow(2, (++i)))) {
    do_instrument<T>(f, n, name);
  }
}
}  // namespace algorithms

#define instrument(function, type, n_min, n_max)                \
  algorithms::do_instrument<algorithms::instrumented_t<         \
      type, algorithms::InstrumentPolicy_CountOperations>>(     \
      function<algorithms::instrumented_t<                      \
          type, algorithms::InstrumentPolicy_CountOperations>>, \
      n_min, n_max, #function "_" #type);
