#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

#define TEST_SORT(function)                                               \
                                                                          \
  class function : public testing::TestWithParam<std::vector<int>> {};    \
                                                                          \
  TEST_P(function, sort) {                                                \
    std::vector<int> actual = GetParam();                                 \
    sort_##function(actual.data(), actual.size());                        \
                                                                          \
    std::vector<int> expected = GetParam();                               \
    std::sort(expected.begin(), expected.end());                          \
                                                                          \
    EXPECT_EQ(expected, actual);                                          \
  }                                                                       \
                                                                          \
  INSTANTIATE_TEST_CASE_P(                                                \
      Sort, function,                                                     \
      ::testing::Values(                                                  \
          std::vector<int>{0}, std::vector<int>{-1}, std::vector<int>{1}, \
          std::vector<int>{}, std::vector<int>{1, -1},                    \
          std::vector<int>{1, 0, -1},                                     \
          std::vector<int>{40, 97, 14, 63, 21, 76, 87, 47, 36, 29},       \
          std::vector<int>{25, -44, -28, 2, -48, 38, 42, -7, 27, 43},     \
          std::vector<int>{5, 5, 5, 5, 5, 5, 5, 5, 5, 5},                 \
          std::vector<int>{-5, -5, -5, -5, -5, -5, -5, -5, -5, -5},       \
          std::vector<int>{5, -5, 5, -5, 5, -5, 5, -5, 5, -5},            \
          std::vector<int>{-5, -5, 5, 5, -5, 5, 5, -5, -5, 5},            \
          std::vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1, 0},                 \
          std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},                 \
          std::vector<int>{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5},         \
          std::vector<int>{5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5}));

struct Pair {
  int first, second;
};

inline bool operator<(const Pair& lhs, const Pair& rhs) {
  return lhs.first < rhs.first;
}

inline bool operator==(const Pair& lhs, const Pair& rhs) {
  return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

#define TEST_SORT_STABLE(function)                                             \
                                                                               \
  TEST_SORT(function);                                                         \
                                                                               \
  class function##_stable : public testing::TestWithParam<std::vector<Pair>> { \
  };                                                                           \
                                                                               \
  TEST_P(function##_stable, sort_stable) {                                     \
    std::vector<Pair> actual = GetParam();                                     \
    sort_##function(actual.data(), actual.size());                             \
                                                                               \
    std::vector<Pair> expected = GetParam();                                   \
    std::stable_sort(expected.begin(), expected.end());                        \
                                                                               \
    EXPECT_EQ(expected, actual);                                               \
  }                                                                            \
                                                                               \
  INSTANTIATE_TEST_CASE_P(                                                     \
      SortStable, function##_stable,                                           \
      ::testing::Values(                                                       \
          std::vector<Pair>{{1, 0}, {-1, 0}},                                  \
          std::vector<Pair>{{1, 0}, {1, 0}, {0, 0}, {0, 1}, {-1, 0}, {-1, 0}}, \
          std::vector<Pair>{{1, 0}, {1, 1}, {0, 0}, {0, 1}, {-1, 0}, {-1, 1}}, \
          std::vector<Pair>{{1, 1}, {1, 0}, {0, 1}, {0, 0}, {-1, 1}, {-1, 0}}, \
          std::vector<Pair>{{5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}},   \
          std::vector<Pair>{{5, 5}, {5, 4}, {5, 3}, {5, 2}, {5, 1}, {5, 0}},   \
          std::vector<Pair>{{5, 8}, {5, 6}, {5, 1}, {5, 0}, {5, 4}, {5, 9}}));
