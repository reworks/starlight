///
/// AlgorithmTest.cpp
/// tests
///
/// Refer to LICENSE.txt for more details.
///

#include <gtest/gtest.h>

#include <galaxy/algorithm/Algorithm.hpp>

TEST(Algorithm, Normalize)
{
	constexpr auto max      = 100;
	constexpr auto value    = 50;
	constexpr auto expected = 0.5f;

	auto result = galaxy::algorithm::normalize(value, max);
	EXPECT_EQ(expected, result);
}

TEST(Algorithm, VectorContains)
{
	constexpr auto value          = 42;
	const std::vector<int> values = {20, 42, 100};
	const std::vector<int> empty  = {};

	const auto result1 = galaxy::algorithm::contains(values, value);
	EXPECT_TRUE(result1 != values.end());
	EXPECT_TRUE(*result1 == value);

	const auto result2 = galaxy::algorithm::contains(empty, value);
	EXPECT_TRUE(result2 == empty.end());
}
