#pragma once
#include <memory>



class PaginationDataBook;
class IBookmarksData;


class IBookData
{
public:
	virtual ~IBookData() = default;

	virtual void setPagination(PaginationDataBook* pagination) = 0;
	virtual const PaginationDataBook* getPagination() const = 0;

	virtual void setBookmarks(const std::shared_ptr<IBookmarksData>& bookmarks) = 0;
	virtual const IBookmarksData* getBookmarks() const = 0;
};
