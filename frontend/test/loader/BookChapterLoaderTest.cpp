#include <gtest/gtest.h>
#include "data/BookDataChapter.h"
#include "book/BookPage.h"
#include "loader/BookChapterLoader.h"



TEST(book_chapter_loader, data_empty)
{
	bool checkBad = true;
	try
	{
		std::shared_ptr<BookDataItem> data;
		const std::shared_ptr<IBookItemLoader> loader (new BookChapterLoader());
		const auto page = loader->load(data);
		checkBad = (nullptr == page);
	}
	catch (...)
	{
		checkBad = true;
	}
	EXPECT_TRUE(checkBad);
}

TEST(book_chapter_loader, data_chapter)
{
	bool checkBad = true;
	try
	{
		std::shared_ptr<BookDataItem> data (new BookDataChapter("page", {}));
		const std::shared_ptr<IBookItemLoader> loader (new BookChapterLoader());
		const auto page = loader->load(data);
		if (page)
		{
			if (const auto pageData = page->getData())
			{
				checkBad = !data->equal(*pageData);
			}
		}
	}
	catch (...)
	{
		checkBad = true;
	}
	EXPECT_FALSE(checkBad);
}
