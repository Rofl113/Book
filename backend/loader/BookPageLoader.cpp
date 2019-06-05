#include "BookPageLoader.h"
#include "data/BookDataPage.h"
#include "book/BookPage.h"



BookPageLoader::BookPageLoader()
{

}

BookPageLoader::~BookPageLoader()
{

}

std::unique_ptr<IBookItem> BookPageLoader::load(const std::shared_ptr<BookDataItem>& data) const
{
	std::unique_ptr<IBookItem> item;
	if (data)
	{
		item.reset(new BookPage());
		if (auto page = dynamic_cast<BookPage*>(item.get()))
		{
			page->setData(data);
		}
	}
	return item;
}
