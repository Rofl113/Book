#include <gtest/gtest.h>
#include "data/BookDataPage.h"
#include "book/BookPage.h"
#include "loader/BookPageLoader.h"



TEST(book_page_loader, data_empty)
{
	bool checkBad = true;
	try
	{
		std::shared_ptr<BookDataItem> data;
		const std::shared_ptr<IBookItemLoader> loader (new BookPageLoader());
		const auto page = loader->load(data);
		checkBad = (nullptr == page);
	}
	catch (...)
	{
		checkBad = true;
	}
	EXPECT_TRUE(checkBad);
}

TEST(book_page_loader, data_page)
{
	bool checkBad = true;
	try
	{
		std::shared_ptr<BookDataItem> data (new BookDataPage("page"));
		const std::shared_ptr<IBookItemLoader> loader (new BookPageLoader());
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
