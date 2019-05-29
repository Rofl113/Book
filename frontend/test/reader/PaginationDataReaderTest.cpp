#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "data/PaginationData.h"
#include "reader/PaginationDataReader.h"



TEST(pagination_data_reader, read_json_not_valid_empty)
{
	bool checkThrow = false;
	try
	{
		std::shared_ptr<PaginationData> data;
		const auto jsDataBad = nlohmann::json::parse("{}");
		const std::shared_ptr<PaginationDataReader> reader (new PaginationDataReader());
		reader->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(pagination_data_reader, read_json_valid)
{
	std::shared_ptr<PaginationData> dataOne (new PaginationData(true));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": true }");
	const std::shared_ptr<PaginationDataReader> reader (new PaginationDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(pagination_data_reader, read_json_not_valid)
{
	std::shared_ptr<PaginationData> dataOne (new PaginationData(true));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": false }");
	const std::shared_ptr<PaginationDataReader> reader (new PaginationDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}
