#include <gtest/gtest.h>
#include "data/BookData.h"
#include "book/Book.h"
#include "loader/BookLoader.h"



TEST(book_loader, data_empty)
{
	bool checkBad = true;
	try
	{
		std::shared_ptr<BookDataItem> data;
		const std::shared_ptr<BookLoader> loader (new BookLoader());
		const auto page = loader->load(data);
		checkBad = (nullptr == page);
	}
	catch (...)
	{
		checkBad = true;
	}
	EXPECT_TRUE(checkBad);
}

TEST(book_loader, data_book)
{
	bool checkBad = true;
	try
	{
		std::shared_ptr<BookDataItem> data (new BookData("book", {}));
		const std::shared_ptr<BookLoader> loader (new BookLoader());
		const auto book = loader->load(data);
		if (book)
		{
			if (const auto pageData = book->getData())
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
