#include "BookData.h"
#include "PaginationDataBook.h"
#include "IBookmarksData.h"




BookData::BookData(const std::string& name, std::vector<std::shared_ptr<IBookDataItem> >&& childs)
	: BookDataChapter(name, std::move(childs))
{

}

void BookData::setPagination(PaginationDataBook* pagination)
{
	const std::shared_ptr<IPaginationData> data (pagination);
	BookDataChapter::setPagination(data);
}

const PaginationDataBook* BookData::getPagination() const
{
	return dynamic_cast<const PaginationDataBook*>(BookDataChapter::getPagination());
}

void BookData::setBookmarks(const std::shared_ptr<IBookmarksData>& bookmarks)
{
	m_bookmarks = bookmarks;
}

const IBookmarksData* BookData::getBookmarks() const
{
	return m_bookmarks.get();
}
