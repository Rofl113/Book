#include "BookChapterDataReaderBase.h"
#include "IBookItemDataReader.h"
#include "data/IBookDataItem.h"



namespace
{
	static constexpr const auto KEY_NAME = "name";
	static constexpr const auto KEY_CHILDS = "childs";
} // end namespace


std::string BookChapterDataReaderBase::readName(const nlohmann::json& jsChapter) const
{
	return jsChapter[KEY_NAME];
}

std::vector<std::shared_ptr<IBookDataItem>> BookChapterDataReaderBase::readChilds(const nlohmann::json& jsChapter) const
{
	std::vector<std::shared_ptr<IBookDataItem>> childs;
	for (const auto& jsItem : jsChapter[KEY_CHILDS])
	{
		auto readerItem = this->getReaderItem();
		std::shared_ptr<IBookDataItem> item (readerItem->read(jsItem));
		childs.push_back(std::move(item));
	}
	return childs;
}
