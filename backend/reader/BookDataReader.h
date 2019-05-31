#pragma once
#include <memory>
#include <nlohmann/json.hpp>
#include "BookChapterDataReaderBase.h"
#include "IBookDataReader.h"



class IBookItemDataReader;
class IBookPageDataReader;
class IBookChapterDataReader;
class IPaginationDataBookReader;
class IBookmarksDataReader;


class BookDataReader : public IBookDataReader, public BookChapterDataReaderBase
{
public:
	BookDataReader();
	virtual ~BookDataReader() override;

	virtual std::shared_ptr<BookData> read(const nlohmann::json& jsBook) const override;

private:
	virtual const IBookItemDataReader* getReaderItem() const override;
	// Вспомогательные элменты
	std::shared_ptr<IBookItemDataReader> m_readerItem;
	std::shared_ptr<IBookPageDataReader> m_readerPage;
	std::shared_ptr<IBookChapterDataReader> m_readerChapter;
	std::shared_ptr<IPaginationDataBookReader> m_readerPaginationBook;
	std::shared_ptr<IBookmarksDataReader> m_readerBookmarks;
};
