#include "BookDataItem.h"
#include "PaginationData.h"



BookDataItem::~BookDataItem()
{

}

BookDataItem::BookDataItem(const std::string& name, const BookDataType& type)
	: m_name(name)
	, m_type(type)
{

}

const std::string& BookDataItem::getName() const
{
	return m_name;
}

const BookDataType& BookDataItem::getType() const
{
	return m_type;
}

void BookDataItem::setPagination(const std::shared_ptr<PaginationData>& pagination)
{
	m_pagination = pagination;
}

const PaginationData* BookDataItem::getPagination() const
{
	return m_pagination.get();
}

bool BookDataItem::equal(const BookDataItem& other) const
{
	if (this->getName() != other.getName())
	{
		return false;
	}
	if (this->getType() != other.getType())
	{
		return false;
	}
	const auto paginationThis = this->getPagination();
	const auto paginationOther = other.getPagination();
	if (paginationThis && paginationOther)
	{
		if (false == paginationThis->equal(*paginationOther))
		{
			return true;
		}
	}
	else if (!!paginationThis ^ !!paginationOther)
	{
		return false;
	}
	return true;
}
