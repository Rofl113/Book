#include "PaginationData.h"



PaginationData::PaginationData(const bool enanbled)
	: m_enanbled(enanbled)
{

}

bool PaginationData::isEnabled() const
{
	return m_enanbled;
}

bool PaginationData::equal(const PaginationData& other) const
{
	if (this->isEnabled() != other.isEnabled())
	{
		return false;
	}
	return true;
}
