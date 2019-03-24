#pragma once
#include <nlohmann/json.hpp>
#include "IBookItemDataReader.h"



class IBookDataItem;


class BookItemDataReader : public IBookItemDataReader
{
public:
	BookItemDataReader();
	virtual ~BookItemDataReader() override;

	virtual IBookDataItem* read(const nlohmann::json& jsItem) const override;

	virtual void setReaderPage(const IBookPageDataReader* readerPage) override;
	virtual void setReaderChapter(const IBookChapterDataReader* readerChapter) override;

private:
	const IBookPageDataReader* m_readerPage = nullptr;
	const IBookChapterDataReader* m_readerChapter = nullptr;
};
