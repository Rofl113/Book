#include "BookChapterDataReaderBase.h"
#include "IBookItemDataReader.h"
#include "data/BookDataItem.h"



namespace
{
	static constexpr const auto KEY_NAME = "name";
	static constexpr const auto KEY_CHILDS = "childs";
} // end namespace


std::string BookChapterDataReaderBase::readName(const nlohmann::json& jsChapter) const
{
	return jsChapter.at(KEY_NAME);
}

std::vector<std::shared_ptr<BookDataItem>> BookChapterDataReaderBase::readChilds(const nlohmann::json& jsChapter) const
{
	std::vector<std::shared_ptr<BookDataItem>> childs;
	for (const auto& jsItem : jsChapter.at(KEY_CHILDS))
	{
		auto readerItem = this->getReaderItem();
		std::shared_ptr<BookDataItem> item (readerItem->read(jsItem));
		childs.push_back(std::move(item));
	}
	return childs;
}
