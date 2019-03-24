#pragma once
#include <nlohmann/json.hpp>



class IBookDataChapter;
class IBookItemDataReader;


class IBookChapterDataReader
{
public:
	virtual ~IBookChapterDataReader() = default;

	virtual IBookDataChapter* read(const nlohmann::json& jsPage) const = 0;

	virtual void setReaderItem(const IBookItemDataReader* readerItem) = 0;
};
