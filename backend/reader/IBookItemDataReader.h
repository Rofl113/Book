#pragma once
#include <nlohmann/json.hpp>



class BookDataItem;
class IBookPageDataReader;
class IBookChapterDataReader;


class IBookItemDataReader
{
public:
	virtual ~IBookItemDataReader() = default;
	virtual std::shared_ptr<BookDataItem> read(const nlohmann::json& jsItem) const = 0;

	virtual void setReaderPage(const std::shared_ptr<IBookPageDataReader>& readerPage) = 0;
	virtual void setReaderChapter(const std::shared_ptr<IBookChapterDataReader>& readerChapter) = 0;
};
