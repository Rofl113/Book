#include "BookLoader.h"
#include "data/BookData.h"
#include "data/BookDataType.h"
#include "book/Book.h"
#include "BookItemLoader.h"
#include "BookChapterLoader.h"
#include "BookPageLoader.h"




BookLoader::BookLoader()
	: m_loaderItem(new BookItemLoader())
	, m_loaderPage(new BookPageLoader())
	, m_loaderChapter(new BookChapterLoader())
{
	// Установка зависимостей
	if (auto chapter = dynamic_cast<BookChapterLoader*>(m_loaderChapter.get()))
	{
		chapter->setLoaderItem(m_loaderItem.get());
	}
	if (auto loaderItem = dynamic_cast<BookItemLoader*>(m_loaderItem.get()))
	{
		// Add Page
		loaderItem->setLoader(BookDataType::PAGE, m_loaderPage);
		// Add Chapter
		loaderItem->setLoader(BookDataType::CHAPTER, m_loaderChapter);
	}
}

BookLoader::~BookLoader()
{

}

std::unique_ptr<IBook> BookLoader::load(const std::shared_ptr<BookDataItem>& data)
{
	std::unique_ptr<IBook> out;
	if (data)
	{
		// Create Chapter
		out.reset(new Book());
		if (auto book = dynamic_cast<Book*>(out.get()))
		{
			// Set Data
			book->setData(data);
			// Load childs
			{
				auto childs = this->loadChilds(data);
				book->setChilds(std::move(childs));
			}
		}
	}
	return out;
}

const IBookItemLoader* BookLoader::getLoaderItem() const
{
	return m_loaderItem.get();
}
