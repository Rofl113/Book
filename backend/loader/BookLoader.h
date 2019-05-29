#pragma once
#include "BookChapterLoaderBase.h"



class IBook;
class BookDataItem;
class IBookItemLoader;


class BookLoader : public BookChapterLoaderBase
{
public:
	BookLoader();
	~BookLoader();

	std::unique_ptr<IBook> load(const std::shared_ptr<BookDataItem>& data);

private:
	virtual const IBookItemLoader* getLoaderItem() const override;
	// Вспомогательные элменты
	std::shared_ptr<IBookItemLoader> m_loaderItem;
	std::shared_ptr<IBookItemLoader> m_loaderPage;
	std::shared_ptr<IBookItemLoader> m_loaderChapter;
};
