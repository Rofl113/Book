#include "PaginationDataBook.h"





PaginationDataBook::PaginationDataBook(const bool enanbled, std::map<std::string, std::vector<std::string>>&& groups)
: PaginationData(enanbled)
, m_groupsItems(std::move(groups))
{

}

const std::map<std::string, std::vector<std::string> >& PaginationDataBook::getGroupsItems() const
{
	return m_groupsItems;
}
