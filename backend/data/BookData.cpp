#include "BookData.h"
#include "PaginationDataBook.h"




BookData::~BookData()
{

}

BookData::BookData(const std::string& name, std::vector<std::shared_ptr<BookDataItem> >&& childs)
	: BookDataChapter(name, std::move(childs))
{

}

void BookData::setPaginationBook(const std::shared_ptr<PaginationDataBook>& pagination)
{
	BookDataChapter::setPagination(pagination);
}

const PaginationDataBook* BookData::getPaginationBook() const
{
	return dynamic_cast<const PaginationDataBook*>(BookDataChapter::getPagination());
}

void BookData::setBookmarks(std::shared_ptr<BookmarksData> bookmarks)
{
	m_bookmarks = bookmarks;
}

const BookmarksData* BookData::getBookmarks() const
{
	return m_bookmarks.get();
}

bool BookData::equal(const BookDataItem& other) const
{
	if (const auto otherBook = dynamic_cast<const BookData*>(&other))
	{
		if (false == ClassBase::equal(*otherBook))
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

void BookData::setPagination(const std::shared_ptr<PaginationData>& pagination)
{
	ClassBase::setPagination(pagination);
}

const std::vector<std::shared_ptr<BookDataItem> >& BookData::getChilds() const
{
	return ClassBase::getChilds();
}

const BookDataType& BookData::getType() const
{
	return ClassBase::getType();
}

const std::string& BookData::getName() const
{
	return ClassBase::getName();
}
