#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>

#include <details/update_average.h>

namespace algorithms {
struct OperationsCounter {
  uint64_t default_constructions;
  uint64_t destructions;
  uint64_t copy_constructions;
  uint64_t move_constructions;
  uint64_t copy_assignments;
  uint64_t move_assignments;
  mutable uint64_t less_comparisons;
  mutable uint64_t equal_comparisons;
  uint64_t swaps;
  ptrdiff_t swap_distance_max;
  ptrdiff_t swap_distance_min;
  long double swap_distance_avg;

  mutable ptrdiff_t less_distance_max;
  mutable ptrdiff_t less_distance_min;
  mutable long double less_distance_avg;

  OperationsCounter() {
    reset();
  }

  void reset() {
    default_constructions = 0;
    destructions = 0;
    copy_constructions = 0;
    move_constructions = 0;
    copy_assignments = 0;
    move_assignments = 0;
    less_comparisons = 0;
    equal_comparisons = 0;
    swaps = 0;

    swap_distance_max = 0;
    swap_distance_min = std::numeric_limits<ptrdiff_t>::max();
    swap_distance_avg = 0.0l;

    less_distance_max = 0;
    less_distance_min = std::numeric_limits<ptrdiff_t>::max();
    less_distance_avg = 0.0l;
  }

  void on_default_constructed() {
    ++default_constructions;
  }

  void on_destructed() {
    ++destructions;
  }

  void on_copy_constructed() {
    ++copy_constructions;
  }

  void on_move_constructed() {
    ++move_constructions;
  }

  void on_copy_assigned() {
    ++copy_assignments;
  }

  void on_move_assigned() {
    ++move_assignments;
  }

  void on_compared_less(ptrdiff_t distance) const {
    ++less_comparisons;
    less_distance_min = std::min(distance, less_distance_min);
    less_distance_max = std::max(distance, less_distance_max);
    less_distance_avg =
        update_average(distance, less_distance_avg, less_comparisons);
  }

  void on_compared_equal(ptrdiff_t distance) const {
    ++equal_comparisons;
  }

  void on_swapped(ptrdiff_t distance) {
    ++swaps;
    swap_distance_min = std::min(distance, swap_distance_min);
    swap_distance_max = std::max(distance, swap_distance_max);
    swap_distance_avg = update_average(distance, swap_distance_avg, swaps);
  }
};

struct InstrumentPolicy_CountOperations {
  static OperationsCounter log;

  const OperationsCounter& get_log() const {
    return log;
  }

  OperationsCounter& get_log() {
    return log;
  }

  void reset() {
    log.reset();
  }

  void on_default_constructed() {
    log.on_default_constructed();
  }

  void on_destructed() {
    log.on_destructed();
  }

  void on_copy_constructed() {
    log.on_copy_constructed();
  }

  void on_move_constructed() {
    log.on_move_constructed();
  }

  void on_copy_assigned() {
    log.on_move_assigned();
  }

  void on_move_assigned() {
    log.on_move_assigned();
  }

  void on_compared_less(ptrdiff_t distance) const {
    log.on_compared_less(distance);
  }

  void on_compared_equal(ptrdiff_t distance) const {
    log.on_compared_equal(distance);
  }

  void on_swapped(ptrdiff_t distance) {
    log.on_swapped(distance);
  }
};

OperationsCounter InstrumentPolicy_CountOperations::log;
}  // namespace algorithms
