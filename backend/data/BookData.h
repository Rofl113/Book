#pragma once
#include <string>
#include <map>
#include "BookDataChapter.h"
#include "IBookData.h"



class IBookmarksData;


class BookData : public IBookData, public BookDataChapter
{
	BookData() = delete;
public:
	explicit BookData(const std::string& name, std::vector<std::shared_ptr<IBookDataItem> >&& childs);

	virtual void setPagination(PaginationDataBook* pagination) override;
	virtual const PaginationDataBook* getPagination() const override;

	virtual void setBookmarks(const std::shared_ptr<IBookmarksData>& bookmarks) override;
	virtual const IBookmarksData* getBookmarks() const override;

private:
	std::shared_ptr<IBookmarksData> m_bookmarks;
};
