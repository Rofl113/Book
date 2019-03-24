#include "PaginationData.h"



PaginationData::PaginationData(const bool enanbled)
	: m_enanbled(enanbled)
{

}

bool PaginationData::isEnabled() const
{
	return m_enanbled;
}
