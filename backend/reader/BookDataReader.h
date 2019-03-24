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
	~BookDataReader();

	virtual IBookData* read(const nlohmann::json& jsBook) const override;

private:
	virtual const IBookItemDataReader* getReaderItem() const override;
	// Вспомогательные элменты
	std::unique_ptr<IBookItemDataReader> m_readerItem;
	std::unique_ptr<IBookPageDataReader> m_readerPage;
	std::unique_ptr<IBookChapterDataReader> m_readerChapter;
	std::unique_ptr<IPaginationDataBookReader> m_readerPaginationBook;
	std::unique_ptr<IBookmarksDataReader> m_readerBookmarks;
};
