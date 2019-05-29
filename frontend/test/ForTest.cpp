#include <gtest/gtest.h>
#include <vector>


TEST(for_test, slow)
{
	std::vector<size_t> arrayOne (100000, 2);
	std::vector<size_t> arrayTwo (200000, 1);
	for (size_t i = 0; i < arrayOne.size(); ++i)
	{
		for (size_t j = 0; j < arrayTwo.size(); ++j)
		{
			arrayTwo[j] = arrayTwo[j] * arrayOne[i];
		}
	}
}

TEST(for_test, fast)
{
	std::vector<size_t> arrayOne (100000, 2);
	std::vector<size_t> arrayTwo (200000, 1);
	for (size_t i = 0; i < arrayOne.size(); ++i)
	{
		const auto& one = arrayOne[i];
		for (size_t j = 0; j < arrayTwo.size(); ++j)
		{
			arrayTwo[j] = arrayTwo[j] * one;
		}
	}
}

TEST(for_test, fast_fast)
{
	std::vector<size_t> arrayOne (100000, 2);
	std::vector<size_t> arrayTwo (200000, 1);
	for (size_t i = 0; i < arrayOne.size(); ++i)
	{
		const auto& one = arrayOne[i];
		for (size_t j = 0; j < arrayTwo.size(); ++j)
		{
			arrayOne[i] *= one;
		}
	}
}

