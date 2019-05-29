#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "data/PaginationDataBook.h"
#include "reader/PaginationDataBookReader.h"



TEST(pagination_data_book_reader, read_json_not_valid_empty)
{
	bool checkThrow = false;
	try
	{
		std::shared_ptr<PaginationDataBook> data;
		const auto jsDataBad = nlohmann::json::parse("{}");
		const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
		reader->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(pagination_data_book_reader, read_json_valid)
{
	std::shared_ptr<PaginationDataBook> dataOne (new PaginationDataBook(true, {}));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": true }");
	const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(pagination_data_book_reader, read_json_not_valid)
{
	std::shared_ptr<PaginationDataBook> dataOne (new PaginationDataBook(true, {}));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": false }");
	const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(pagination_data_book_reader, read_json_not_valid_empty_childs)
{
	std::map<std::string, std::vector<std::string>> groups
	{
		{ "keyA", { "v1", "v2", "v3" } }
	};
	std::shared_ptr<PaginationDataBook> dataOne (new PaginationDataBook(true, std::move(groups)));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": false }");
	const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(pagination_data_book_reader, read_json_valid_empty_childs)
{
	std::map<std::string, std::vector<std::string>> groups;
	std::shared_ptr<PaginationDataBook> dataOne (new PaginationDataBook(false, std::move(groups)));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": false, \"groups\": {} }");
	const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(pagination_data_book_reader, read_json_valid_one_childs)
{
	std::map<std::string, std::vector<std::string>> groups
	{
		{ "keyA", { "v1", "v2", "v3" } }
	};
	std::shared_ptr<PaginationDataBook> dataOne (new PaginationDataBook(true, std::move(groups)));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": true, \"groups\": {\"keyA\": [\"v1\", \"v2\", \"v3\"] } }");
	const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(pagination_data_book_reader, read_json_not_valid_one_childs_values)
{
	std::map<std::string, std::vector<std::string>> groups
	{
		{ "keyA", { "v1", "v2" } }
	};
	std::shared_ptr<PaginationDataBook> dataOne (new PaginationDataBook(true, std::move(groups)));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": true, \"groups\": {\"keyA\": [\"v1\", \"v2\", \"v3\"] } }");
	const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(pagination_data_book_reader, read_json_not_valid_one_childs_name)
{
	std::map<std::string, std::vector<std::string>> groups
	{
		{ "keyB", { "v1", "v2", "v3" } }
	};
	std::shared_ptr<PaginationDataBook> dataOne (new PaginationDataBook(true, std::move(groups)));
	const auto jsDataPage = nlohmann::json::parse("{ \"enanbled\": true, \"groups\": {\"keyA\": [\"v1\", \"v2\", \"v3\"] } }");
	const std::shared_ptr<PaginationDataBookReader> reader (new PaginationDataBookReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}
