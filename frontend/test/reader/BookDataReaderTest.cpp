#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "data/BookData.h"
#include "data/BookDataPage.h"
#include "data/BookDataChapter.h"
#include "reader/BookDataReader.h"
#include "reader/BookChapterDataReader.h"
#include "reader/BookItemDataReader.h"
#include "reader/BookPageDataReader.h"



TEST(book_data_reader, read_json_not_valid_empty)
{
	bool checkThrow = false;
	try
	{
		std::shared_ptr<BookData> data;
		const auto jsDataBad = nlohmann::json::parse("{}");
		const std::shared_ptr<IBookDataReader> readerData (new BookDataReader());
		readerData->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(book_data_reader, read_json_not_valid_not_childs)
{
	bool checkThrow = false;
	try
	{
		std::shared_ptr<BookData> data;
		const auto jsDataBad = nlohmann::json::parse("{ \"name\": \"book\" }");
		const std::shared_ptr<IBookDataReader> readerData (new BookDataReader());
		readerData->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(book_data_reader, read_json_empty_childs)
{
	const std::shared_ptr<BookData> dataOne (new BookData("book", {}));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"book\", \"childs\": [] }");
	const std::shared_ptr<IBookDataReader> readerData (new BookDataReader());
	const auto dataTwo = readerData->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(book_data_reader, read_json_one_childs)
{
	const std::shared_ptr<BookDataPage> dataPage (new BookDataPage("page"));
	const std::shared_ptr<BookData> dataOne (new BookData("book", { dataPage }));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"book\", \"childs\": [ { \"name\": \"page\" } ] }");
	const std::shared_ptr<IBookDataReader> readerDataBook (new BookDataReader());
	const auto dataTwo = readerDataBook->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(book_data_reader, read_json_two_childs)
{
	const std::shared_ptr<BookDataPage> dataPageOne (new BookDataPage("pageOne"));
	const std::shared_ptr<BookDataPage> dataPageTwo (new BookDataPage("pageTwo"));
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter", { dataPageOne, dataPageTwo }));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter\", \"childs\": [ { \"name\": \"pageOne\" }, { \"name\": \"pageTwo\" } ] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const std::shared_ptr<IBookItemDataReader> readerDataItem (new BookItemDataReader());
	readerDataItem->setReaderPage(readerDataPage);
	readerDataItem->setReaderChapter(readerDataChapter);
	readerDataChapter->setReaderItem(readerDataItem);
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}
