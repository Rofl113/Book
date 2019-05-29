#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "data/BookmarksData.h"
#include "data/BookmarkData.h"
#include "reader/BookmarksDataReader.h"



TEST(bookmarks_data_reader, read_json_not_valid_empty)
{
	bool checkThrow = false;
	try
	{
		const auto jsDataBad = nlohmann::json::parse("{}");
		const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
		reader->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(bookmarks_data_reader, read_json_valid)
{
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(true, {}));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": true }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(bookmarks_data_reader, read_json_not_valid)
{
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(true, {}));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": false }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(bookmarks_data_reader, read_json_not_valid_empty_childs)
{
	std::vector<BookmarkData> bookmarks;
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(true, std::move(bookmarks)));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": false }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(bookmarks_data_reader, read_json_valid_empty_childs_not_json)
{
	std::vector<BookmarkData> bookmarks;
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(false, std::move(bookmarks)));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": false }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(bookmarks_data_reader, read_json_valid_empty_childs_json)
{
	std::vector<BookmarkData> bookmarks;
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(false, std::move(bookmarks)));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": false, \"marks\": {} }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(bookmarks_data_reader, read_json_valid_one_childs)
{
	std::vector<BookmarkData> bookmarks
	{
		BookmarkData("name", "item", {})
	};
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(true, std::move(bookmarks)));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": true, \"marks\": [ { \"name\": \"name\", \"item\": \"item\", \"marks\": [] } ] }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(bookmarks_data_reader, read_json_not_valid_one_childs_values)
{
	std::vector<BookmarkData> bookmarks
	{
		BookmarkData{ "nameA", "item", {} }
	};
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(true, std::move(bookmarks)));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": true, \"marks\": [ { \"name\": \"nameB\", \"item\": \"item\", \"marks\": [] } ] }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(bookmarks_data_reader, read_json_not_valid_one_childs_name)
{
	std::vector<BookmarkData> bookmarks
	{
		BookmarkData{ "nameA", "item", {} }
	};
	const std::shared_ptr<BookmarksData> dataOne (new BookmarksData(true, std::move(bookmarks)));
	const auto jsData = nlohmann::json::parse("{ \"enanbled\": true, \"marks\": [ { \"name\": \"nameB\", \"item\": \"item\", \"marks\": [] } ] }");
	const std::shared_ptr<BookmarksDataReader> reader (new BookmarksDataReader());
	const auto dataTwo = reader->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}
