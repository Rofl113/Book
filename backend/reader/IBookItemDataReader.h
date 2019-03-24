#pragma once
#include <nlohmann/json.hpp>



class IBookDataItem;
class IBookPageDataReader;
class IBookChapterDataReader;


class IBookItemDataReader
{
public:
	virtual ~IBookItemDataReader() = default;

	virtual IBookDataItem* read(const nlohmann::json& jsItem) const = 0;

	virtual void setReaderPage(const IBookPageDataReader* readerPage) = 0;
	virtual void setReaderChapter(const IBookChapterDataReader* readerChapter) = 0;
};
