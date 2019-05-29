#pragma once
#include <nlohmann/json.hpp>
#include "IBookItemDataReader.h"




class BookItemDataReader : public IBookItemDataReader
{
public:
	BookItemDataReader();
	virtual ~BookItemDataReader() override;

	virtual std::shared_ptr<BookDataItem> read(const nlohmann::json& jsItem) const override;

	virtual void setReaderPage(const std::shared_ptr<IBookPageDataReader>& readerPage) override;
	virtual void setReaderChapter(const std::shared_ptr<IBookChapterDataReader>& readerChapter) override;

private:
	std::shared_ptr<IBookPageDataReader> m_readerPage;
	std::shared_ptr<IBookChapterDataReader> m_readerChapter;
};
