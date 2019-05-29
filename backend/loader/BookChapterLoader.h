#pragma once
#include "IBookItemLoader.h"
#include "BookChapterLoaderBase.h"



class BookChapterLoader : public IBookItemLoader, public BookChapterLoaderBase
{
public:
	BookChapterLoader();
	~BookChapterLoader();

	virtual std::unique_ptr<IBookItem> load(const std::shared_ptr<BookDataItem>& data) const override;

	void setLoaderItem(const IBookItemLoader* loaderItem);

private:
	virtual const IBookItemLoader* getLoaderItem() const override;

	const IBookItemLoader* m_loaderItem = nullptr;
};
