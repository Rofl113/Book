#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "data/BookDataPage.h"
#include "reader/BookPageDataReader.h"



TEST(book_page_data_reader, read_json_not_valid_empty)
{
	bool checkThrow = false;
	try
	{
		std::shared_ptr<BookDataPage> data;
		const auto jsDataBad = nlohmann::json::parse("{}");
		const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
		readerDataPage->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(book_page_data_reader, read_json_valid)
{
	const std::shared_ptr<BookDataPage> bookDataPageOne (new BookDataPage("pageA"));
	const auto jsDataPage = nlohmann::json::parse("{ \"name\": \"pageA\" }");
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const auto bookDataPageTwo = readerDataPage->read(jsDataPage);
	EXPECT_TRUE(bookDataPageOne->equal(*bookDataPageTwo.get()));
}

TEST(book_page_data_reader, read_json_not_valid)
{
	const std::shared_ptr<BookDataPage> bookDataPageOne (new BookDataPage("pageA"));
	const auto jsDataPage = nlohmann::json::parse("{ \"name\": \"pageB\" }");
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const auto bookDataPageTwo = readerDataPage->read(jsDataPage);
	EXPECT_FALSE(bookDataPageOne->equal(*bookDataPageTwo.get()));
}
