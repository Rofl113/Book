#pragma once
#include "IBookChapterDataReader.h"
#include "BookChapterDataReaderBase.h"



class IBookDataItem;


class BookChapterDataReader : public IBookChapterDataReader, public BookChapterDataReaderBase
{
public:
	BookChapterDataReader();
	virtual ~BookChapterDataReader() override;

	virtual IBookDataChapter* read(const nlohmann::json& jsChapter) const override;
	virtual void setReaderItem(const IBookItemDataReader* readerItem) override;

private:
	virtual const IBookItemDataReader* getReaderItem() const override;

	const IBookItemDataReader* m_readerItem = nullptr;
};
