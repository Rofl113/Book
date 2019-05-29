#include "BookDataReader.h"
#include "BookItemDataReader.h"
#include "BookPageDataReader.h"
#include "BookChapterDataReader.h"
#include "PaginationDataBookReader.h"
#include "BookmarksDataReader.h"
#include "data/BookData.h"
#include "data/BookmarksData.h"



namespace
{
	static constexpr const auto KEY_PAGINATION = "pagination";
	static constexpr const auto KEY_BOOKMARKS = "bookmarks";
} // end namespace


BookDataReader::BookDataReader()
	: m_readerItem(new BookItemDataReader())
	, m_readerPage(new BookPageDataReader())
	, m_readerChapter(new BookChapterDataReader())
	, m_readerPaginationBook(new PaginationDataBookReader())
	, m_readerBookmarks(new BookmarksDataReader())
{
	// Устанавливаем зависимости
	m_readerItem->setReaderPage(m_readerPage);
	m_readerItem->setReaderChapter(m_readerChapter);
	m_readerChapter->setReaderItem(m_readerItem);
}

BookDataReader::~BookDataReader()
{
	// Убираем зависимости
	m_readerItem->setReaderPage(nullptr);
	m_readerItem->setReaderChapter(nullptr);
	m_readerChapter->setReaderItem(nullptr);
}

std::shared_ptr<BookData> BookDataReader::read(const nlohmann::json& jsBook) const
{
	std::shared_ptr<BookData> data;
	try
	{
		auto name = this->readName(jsBook);
		auto childs = this->readChilds(jsBook);
		data.reset(new BookData(std::move(name), std::move(childs)));
		if (jsBook.count(KEY_PAGINATION))
		{
			auto pagination = m_readerPaginationBook->read(jsBook[KEY_PAGINATION]);
			data->setPaginationBook(std::move(pagination));
		}
		if (jsBook.count(KEY_BOOKMARKS))
		{
			std::shared_ptr<BookmarksData> bookmarks (m_readerBookmarks->read(jsBook[KEY_BOOKMARKS]));
			data->setBookmarks(std::move(bookmarks));
		}
	}
	catch (...)
	{
		data.reset();
		throw;
	}
	return data;
}

const IBookItemDataReader* BookDataReader::getReaderItem() const
{
	return m_readerItem.get();
}
