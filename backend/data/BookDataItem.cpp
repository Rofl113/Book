#include "BookDataItem.h"


BookDataItem::BookDataItem(const std::string& name, const Type& type)
	: m_name(name)
	, m_type(type)
{

}

const std::string& BookDataItem::getName() const
{
	return m_name;
}

const IBookDataItem::Type& BookDataItem::getType() const
{
	return m_type;
}

void BookDataItem::setPagination(const std::shared_ptr<IPaginationData>& pagination)
{
	m_pagination = pagination;
}

const IPaginationData* BookDataItem::getPagination() const
{
	return m_pagination.get();
}
