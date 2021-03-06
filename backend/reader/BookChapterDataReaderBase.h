#pragma once
#include <string>
#include <nlohmann/json.hpp>



class BookDataItem;
class IBookItemDataReader;


class BookChapterDataReaderBase
{
public:
	virtual ~BookChapterDataReaderBase() = default;

	std::string readName(const nlohmann::json& jsChapter) const;
	std::vector<std::shared_ptr<BookDataItem>> readChilds(const nlohmann::json& jsChapter) const;

protected:
	virtual const IBookItemDataReader* getReaderItem() const = 0;
};
