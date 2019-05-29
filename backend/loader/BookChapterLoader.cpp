#include "BookChapterLoader.h"
#include "IBookItemLoader.h"
#include "data/BookDataChapter.h"
#include "book/BookChapter.h"




BookChapterLoader::BookChapterLoader()
{

}

BookChapterLoader::~BookChapterLoader()
{

}

std::unique_ptr<IBookItem> BookChapterLoader::load(const std::shared_ptr<BookDataItem>& data) const
{
	std::unique_ptr<IBookItem> item;
	if (data)
	{
		// Create Chapter
		item.reset(new BookChapter());
		if (auto chapter = dynamic_cast<BookChapter*>(item.get()))
		{
			// Set Data
			chapter->setData(data);
			// Load childs
			{
				auto childs = this->loadChilds(data);
				chapter->setChilds(std::move(childs));
			}
		}
	}
	return item;
}

void BookChapterLoader::setLoaderItem(const IBookItemLoader* loaderItem)
{
	m_loaderItem = loaderItem;
}

const IBookItemLoader* BookChapterLoader::getLoaderItem() const
{
	return m_loaderItem;
}
