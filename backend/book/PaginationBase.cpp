#include "PaginationBase.h"



void PaginationBase::setCurrent(const size_t value)
{
	m_current = value;
}

void PaginationBase::setCount(const size_t value)
{
	m_count = value;
}

size_t PaginationBase::getCurrent() const
{
	return m_current;
}

size_t PaginationBase::getCount() const
{
	return m_count;
}
