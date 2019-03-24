#include "BookChapterDataReader.h"
#include "data/BookDataChapter.h"
#include "IBookItemDataReader.h"



BookChapterDataReader::BookChapterDataReader()
{

}

BookChapterDataReader::~BookChapterDataReader()
{

}

void BookChapterDataReader::setReaderItem(const IBookItemDataReader* readerItem)
{
	m_readerItem = readerItem;
}

const IBookItemDataReader* BookChapterDataReader::getReaderItem() const
{
	return m_readerItem;
}

IBookDataChapter* BookChapterDataReader::read(const nlohmann::json& jsChapter) const
{
	IBookDataChapter* data = nullptr;
	try
	{
		auto name = this->readName(jsChapter);
		auto childs = this->readChilds(jsChapter);
		data = new BookDataChapter(std::move(name), std::move(childs));
	}
	catch (...)
	{
		printf("Bad jsChapter: %s", jsChapter.dump().c_str());
		assert(0);
		data = nullptr;
	}
	return data;
}
