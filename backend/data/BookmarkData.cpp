#include "BookmarkData.h"




BookmarkData::BookmarkData(const std::string&& name
						   , const std::string&& itemBookName
						   , const std::vector<BookmarkData>&& childs)
	: m_name(std::move(name))
	, m_itemBookName(std::move(itemBookName))
	, m_childs(std::move(childs))
{

}

bool BookmarkData::operator==(const BookmarkData& other) const
{
	if (this->getName() != other.getName())
	{
		return false;
	}
	if (this->getItemBookName() != other.getItemBookName())
	{
		return false;
	}
	if (this->getChilds() != other.getChilds())
	{
		return false;
	}
	return true;
}

bool BookmarkData::operator!=(const BookmarkData& other) const
{
	return BookmarkData::operator==(other);
}

const std::string& BookmarkData::getName() const
{
	return m_name;
}

const std::string& BookmarkData::getItemBookName() const
{
	return m_itemBookName;
}

const std::vector<BookmarkData>& BookmarkData::getChilds() const
{
	return m_childs;
}
