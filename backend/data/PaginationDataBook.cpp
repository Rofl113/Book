#include "PaginationDataBook.h"





PaginationDataBook::~PaginationDataBook()
{

}

PaginationDataBook::PaginationDataBook(const bool enanbled, std::map<std::string, std::vector<std::string>>&& groups)
	: PaginationData(enanbled)
	, m_groupsItems(std::move(groups))
{

}

const std::map<std::string, std::vector<std::string> >& PaginationDataBook::getGroupsItems() const
{
	return m_groupsItems;
}

bool PaginationDataBook::isEnabled() const
{
	return ClassBase::isEnabled();
}

bool PaginationDataBook::equal(const PaginationData& other) const
{
	if (const auto otherData = dynamic_cast<const PaginationDataBook*>(&other))
	{
		if (false == ClassBase::equal(*otherData))
		{
			return false;
		}
		if (this->getGroupsItems() != otherData->getGroupsItems())
		{
			return false;
		}
	}
	return true;
}
