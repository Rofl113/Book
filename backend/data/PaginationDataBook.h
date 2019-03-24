#pragma once
#include "PaginationData.h"
#include <vector>
#include <map>



class PaginationDataBook : public PaginationData
{
	PaginationDataBook() = delete;
public:
	explicit PaginationDataBook(const bool enanbled, std::map<std::string, std::vector<std::string>>&& groups);

	const std::map<std::string, std::vector<std::string>>& getGroupsItems() const;

private:
	std::map<std::string, std::vector<std::string>> m_groupsItems;
};
