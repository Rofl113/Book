#include "BookItemDataReader.h"
#include "IBookChapterDataReader.h"
#include "IBookPageDataReader.h"
#include "data/BookDataChapter.h"
#include "data/BookDataPage.h"



namespace
{
	static constexpr const auto KEY_NAME = "name";
	static constexpr const auto KEY_CHILDS = "childs";
} // end namespace


BookItemDataReader::BookItemDataReader()
{

}

BookItemDataReader::~BookItemDataReader()
{

}

std::shared_ptr<BookDataItem> BookItemDataReader::read(const nlohmann::json& jsItem) const
{
	std::shared_ptr<BookDataItem> data;
	try
	{
		// Chapter
		if (jsItem.count(KEY_CHILDS))
		{
			data = m_readerChapter->read(jsItem);
		}
		// Page
		else if (jsItem.count(KEY_NAME))
		{
			data = m_readerPage->read(jsItem);
		}
		// BAD DATA
		else
		{
			data = nullptr;
		}
	}
	catch (...)
	{
		data = nullptr;
		printf("Bad jsItem: %s", jsItem.dump().c_str());
		assert(0);
	}
	return data;
}

void BookItemDataReader::setReaderPage(const std::shared_ptr<IBookPageDataReader>& readerPage)
{
	m_readerPage = readerPage;
}

void BookItemDataReader::setReaderChapter(const std::shared_ptr<IBookChapterDataReader>& readerChapter)
{
	m_readerChapter = readerChapter;
}
