#pragma once
#include <string>
#include <map>
#include "BookDataChapter.h"



class PaginationDataBook;
class BookmarksData;


class BookData : public BookDataChapter
{
	using ClassBase = BookDataChapter;
	BookData() = delete;
public:
	virtual ~BookData() override;
	explicit BookData(const std::string& name, std::vector<std::shared_ptr<BookDataItem> >&& childs);

	virtual void setPaginationBook(const std::shared_ptr<PaginationDataBook>& pagination);
	virtual const PaginationDataBook* getPaginationBook() const;

	virtual void setBookmarks(std::shared_ptr<BookmarksData> bookmarks);
	virtual const BookmarksData* getBookmarks() const;

	virtual bool equal(const BookDataItem& other) const override;

private:
	// Используем setPaginationBook
	virtual void setPagination(const std::shared_ptr<PaginationData>& pagination) override;
	virtual const std::vector<std::shared_ptr<BookDataItem>>& getChilds() const override;
	virtual const BookDataType& getType() const override;
	virtual const std::string& getName() const override;

	std::shared_ptr<BookmarksData> m_bookmarks;
};
