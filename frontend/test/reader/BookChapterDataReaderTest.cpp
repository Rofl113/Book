#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "data/BookDataChapter.h"
#include "data/BookDataPage.h"
#include "reader/BookChapterDataReader.h"
#include "reader/BookItemDataReader.h"
#include "reader/BookPageDataReader.h"



TEST(book_chapter_data_reader, read_json_bad_empty)
{
	bool checkThrow = false;
	try
	{
		std::shared_ptr<BookDataChapter> data;
		const auto jsDataBad = nlohmann::json::parse("{}");
		const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
		readerDataChapter->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(book_chapter_data_reader, read_json_bad_not_childs)
{
	bool checkThrow = false;
	try
	{
		std::shared_ptr<BookDataChapter> data;
		const auto jsDataBad = nlohmann::json::parse("{ \"name\": \"chapter\" }");
		const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
		readerDataChapter->read(jsDataBad);
		checkThrow = false;
	}
	catch (...)
	{
		checkThrow = true;
	}
	EXPECT_TRUE(checkThrow);
}

TEST(book_chapter_data_reader, read_json_bad_name)
{
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter1", {}));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter2\", \"childs\": [] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(book_chapter_data_reader, read_json_empty_childs)
{
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter", {}));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter\", \"childs\": [] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(book_chapter_data_reader, read_json_one_child)
{
	const std::shared_ptr<BookDataPage> dataPage (new BookDataPage("page"));
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter", { dataPage }));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter\", \"childs\": [ { \"name\": \"page\" } ] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const std::shared_ptr<IBookItemDataReader> readerDataItem (new BookItemDataReader());
	readerDataItem->setReaderPage(readerDataPage);
	readerDataItem->setReaderChapter(readerDataChapter);
	readerDataChapter->setReaderItem(readerDataItem);
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(book_chapter_data_reader, read_json_one_child_bad)
{
	const std::shared_ptr<BookDataPage> dataPage (new BookDataPage("page1"));
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter", { dataPage }));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter\", \"childs\": [ { \"name\": \"page2\" } ] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const std::shared_ptr<IBookItemDataReader> readerDataItem (new BookItemDataReader());
	readerDataItem->setReaderPage(readerDataPage);
	readerDataItem->setReaderChapter(readerDataChapter);
	readerDataChapter->setReaderItem(readerDataItem);
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(book_chapter_data_reader, read_json_two_childs)
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

TEST(book_chapter_data_reader, read_json_two_childs_bad)
{
	const std::shared_ptr<BookDataPage> dataPageOne (new BookDataPage("pageOne"));
	const std::shared_ptr<BookDataPage> dataPageTwo (new BookDataPage("pageTwo"));
	const std::shared_ptr<BookDataPage> dataPageThree (new BookDataPage("pageThree"));
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter", { dataPageOne, dataPageTwo, dataPageThree }));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter\", \"childs\": [ { \"name\": \"pageOne\" }, { \"name\": \"pageTwo\" } ] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const std::shared_ptr<IBookItemDataReader> readerDataItem (new BookItemDataReader());
	readerDataItem->setReaderPage(readerDataPage);
	readerDataItem->setReaderChapter(readerDataChapter);
	readerDataChapter->setReaderItem(readerDataItem);
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(book_chapter_data_reader, read_json_two_childs_bad_name)
{
	const std::shared_ptr<BookDataPage> dataPageOne (new BookDataPage("pageOne"));
	const std::shared_ptr<BookDataPage> dataPageTwo (new BookDataPage("pageOne"));
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter", { dataPageOne, dataPageTwo }));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter\", \"childs\": [ { \"name\": \"pageOne\" }, { \"name\": \"pageTwo\" } ] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const std::shared_ptr<IBookItemDataReader> readerDataItem (new BookItemDataReader());
	readerDataItem->setReaderPage(readerDataPage);
	readerDataItem->setReaderChapter(readerDataChapter);
	readerDataChapter->setReaderItem(readerDataItem);
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(book_chapter_data_reader, read_json_two_childs_bad_name_js)
{
	const std::shared_ptr<BookDataPage> dataPageOne (new BookDataPage("pageOne"));
	const std::shared_ptr<BookDataPage> dataPageTwo (new BookDataPage("pageTwo"));
	const std::shared_ptr<BookDataChapter> dataOne (new BookDataChapter("chapter", { dataPageOne, dataPageTwo }));
	const auto jsData = nlohmann::json::parse("{ \"name\": \"chapter\", \"childs\": [ { \"name\": \"pageOne\" }, { \"name\": \"pageOne\" } ] }");
	const std::shared_ptr<IBookChapterDataReader> readerDataChapter (new BookChapterDataReader());
	const std::shared_ptr<IBookPageDataReader> readerDataPage (new BookPageDataReader());
	const std::shared_ptr<IBookItemDataReader> readerDataItem (new BookItemDataReader());
	readerDataItem->setReaderPage(readerDataPage);
	readerDataItem->setReaderChapter(readerDataChapter);
	readerDataChapter->setReaderItem(readerDataItem);
	const auto dataTwo = readerDataChapter->read(jsData);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}
