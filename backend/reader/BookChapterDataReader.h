#pragma once
#include "IBookChapterDataReader.h"
#include "BookChapterDataReaderBase.h"



class BookChapterDataReader : public IBookChapterDataReader, public BookChapterDataReaderBase
{
public:
	BookChapterDataReader();
	virtual ~BookChapterDataReader() override;

	virtual std::shared_ptr<BookDataChapter> read(const nlohmann::json& jsChapter) const override;
	virtual void setReaderItem(const std::shared_ptr<IBookItemDataReader>& readerItem) override;

private:
	virtual const IBookItemDataReader* getReaderItem() const override;

	std::shared_ptr<IBookItemDataReader> m_readerItem;
};
