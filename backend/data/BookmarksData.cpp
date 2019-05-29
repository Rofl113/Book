#include "BookmarksData.h"
#include "BookmarkData.h"




BookmarksData::BookmarksData(const bool enabled, std::vector<BookmarkData>&& marks)
	: m_enabled(enabled)
	, m_marks(std::move(marks))
{

}

bool BookmarksData::isEnabled() const
{
	return m_enabled;
}

const std::vector<BookmarkData>& BookmarksData::getMarks() const
{
	return m_marks;
}

bool BookmarksData::equal(const BookmarksData& other) const
{
	if (this->isEnabled() != other.isEnabled())
	{
		return false;
	}
	if (this->getMarks() != other.getMarks())
	{
		return false;
	}
	return true;
}
