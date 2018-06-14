#pragma once

namespace algorithms {

template <typename T, typename InstrumentPolicy>
struct instrumented_t : public InstrumentPolicy {
  typedef T value_type;

  value_type value;

  inline instrumented_t() {
    InstrumentPolicy::on_default_constructed();
  }

  inline ~instrumented_t() {
    InstrumentPolicy::on_destructed();
  }

  inline instrumented_t(const value_type& v) : value(v) {
    InstrumentPolicy::on_copy_constructed();
  }

  inline instrumented_t(const value_type&& v) : value(std::move(v)) {
    InstrumentPolicy::on_move_constructed();
  }

  inline instrumented_t& operator=(const value_type& v) {
    InstrumentPolicy::on_copy_assigned();
    value = v;
    return *this;
  }

  inline instrumented_t& operator=(const value_type&& v) {
    InstrumentPolicy::on_move_assigned();
    value = std::move(v);
    return *this;
  }

  inline bool operator==(const instrumented_t& r) const {
    InstrumentPolicy::on_compared_equal(ptr_distance_to(r));
    return value == r.value;
  }

  inline bool operator<(const instrumented_t& r) const {
    InstrumentPolicy::on_compared_less(ptr_distance_to(r));
    return value < r.value;
  }

  inline void swap(instrumented_t& r) {
    using std::swap;
    InstrumentPolicy::on_swapped(ptr_distance_to(r));
    swap(value, r.value);
  }

 private:
  ptrdiff_t ptr_distance_to(const instrumented_t& r) const {
    return std::abs(std::distance(&(value), &(r.value)));
    ;
  }
};

template <typename T, typename InstrumentPolicy>
inline void swap(
    instrumented_t<T, InstrumentPolicy>& l,
    instrumented_t<T, InstrumentPolicy>& r) {
  l.swap(r);
}

template <typename T, typename InstrumentPolicy>
inline bool operator==(
    const instrumented_t<T, InstrumentPolicy>& l,
    const instrumented_t<T, InstrumentPolicy>& r) {
  return l.operator==(r);
}

template <typename T, typename InstrumentPolicy>
inline bool operator<(
    const instrumented_t<T, InstrumentPolicy>& l,
    const instrumented_t<T, InstrumentPolicy>& r) {
  return l.operator<(r);
}
}  // namespace algorithms
