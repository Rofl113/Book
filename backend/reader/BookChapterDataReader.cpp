#include "BookChapterDataReader.h"
#include "data/BookDataChapter.h"
#include "IBookItemDataReader.h"



BookChapterDataReader::BookChapterDataReader()
{

}

BookChapterDataReader::~BookChapterDataReader()
{

}

void BookChapterDataReader::setReaderItem(const std::shared_ptr<IBookItemDataReader>& readerItem)
{
	m_readerItem = readerItem;
}

const IBookItemDataReader* BookChapterDataReader::getReaderItem() const
{
	return m_readerItem.get();
}

std::shared_ptr<BookDataChapter> BookChapterDataReader::read(const nlohmann::json& jsChapter) const
{
	std::shared_ptr<BookDataChapter> data;
	try
	{
		auto name = this->readName(jsChapter);
		auto childs = this->readChilds(jsChapter);
		data.reset(new BookDataChapter(std::move(name), std::move(childs)));
	}
	catch (...)
	{
		data.reset();
		throw;
	}
	return data;
}
