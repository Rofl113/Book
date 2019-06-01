#pragma once
#include <vector>
#include <map>
#include "PaginationData.h"



class PaginationDataBook : public PaginationData
{
	using ClassBase = PaginationData;
	PaginationDataBook() = delete;
public:
	virtual ~PaginationDataBook() override;
	explicit PaginationDataBook(const bool enanbled, std::map<std::string, std::vector<std::string>>&& groups);
	virtual const std::map<std::string, std::vector<std::string>>& getGroupsItems() const;
	virtual bool isEnabled() const override;

	virtual bool equal(const PaginationData& other) const override;

private:
	std::map<std::string, std::vector<std::string>> m_groupsItems;
};
