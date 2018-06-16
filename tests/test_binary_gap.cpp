#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithms/binary_gap.h>

class BinaryGapTest : public testing::TestWithParam<std::pair<int, int>> {};

TEST_P(BinaryGapTest, finds_gap) {
  int input, output;
  std::tie(input, output) = GetParam();
  EXPECT_EQ(output, binary_gap(input));
}

INSTANTIATE_TEST_CASE_P(
    BinaryGap,
    BinaryGapTest,
    ::testing::Values(
        // Pairs of (input integer, expected result)
        std::make_pair(0b00000000000000000000000000000000, 0),
        std::make_pair(0b00000000000000000000000000000001, 0),
        std::make_pair(0b00000000000000000000000000001000, 0),
        std::make_pair(0b00000000000000000000000000011000, 0),
        std::make_pair(0b00000000000000000000000000111000, 0),
        std::make_pair(0b00000000000000000000000000101000, 1),
        std::make_pair(0b00000000000000000000000000000101, 1),
        std::make_pair(0b00000000000000000000000000001001, 2),
        std::make_pair(0b00000000000000000000001000000001, 8),
        std::make_pair(0b10000000000000000000000000000001, 30),
        std::make_pair(0b10000000000000001000000000000001, 15),
        std::make_pair(0b10000000000000010000000000000001, 15),
        std::make_pair(0b10000000000000000000000000000001, 30),
        std::make_pair(0b10000000000000000000000000000001, 30),
        std::make_pair(0b10000000000000000010000000010001, 17),
        std::make_pair(0b10001000000100000000000010010000, 12),
        std::make_pair(0b10001000000100000000000000010000, 15),
        std::make_pair(0b00000000000000000010000010010000, 5),
        std::make_pair(0b11111111111111111111111111111111, 0),
        std::make_pair(0b01111111111111111111111111111111, 0),
        std::make_pair(0b11111111111111111111111111111110, 0),
        std::make_pair(0b01111111111111111111111111111110, 0),
        std::make_pair(0b01111111111111110011111111111110, 2),
        std::make_pair(0b01111000000111110011111111111110, 6)));
