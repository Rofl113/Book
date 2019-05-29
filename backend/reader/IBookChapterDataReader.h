#pragma once
#include <memory>
#include <nlohmann/json.hpp>



class BookDataChapter;
class IBookItemDataReader;


class IBookChapterDataReader
{
public:
	virtual ~IBookChapterDataReader() = default;

	virtual std::shared_ptr<BookDataChapter> read(const nlohmann::json& jsChapter) const = 0;
	virtual void setReaderItem(const std::shared_ptr<IBookItemDataReader>& readerItem) = 0;
};
