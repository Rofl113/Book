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
		item.reset(new BookPage(m_managerFactory));
		if (auto page = dynamic_cast<BookPage*>(item.get()))
		{
			page->setData(data);
		}
	}
	return item;
}

void BookPageLoader::setManagerBookItemFactory(const std::shared_ptr<IManagerBookItemFactory>& managerFactory)
{
	m_managerFactory = managerFactory;
}
