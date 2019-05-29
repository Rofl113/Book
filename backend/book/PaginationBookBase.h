#pragma once
#include "PaginationBase.h"
#include "IPaginationBook.h"



class PaginationBookBase : public PaginationBase, public IPaginationBook
{
	using ClassBase = PaginationBase;
public:
	// IPaginationBook
	virtual void setGroups(std::map<std::string, std::vector<std::string>>&& dataGroups) override;
	virtual void setPagesCount(std::map<std::string, size_t>&& pagesCount) override;
	virtual size_t convertNumber(const std::string& pageName, const size_t& pageNumber) const override;
	virtual size_t convertCount(const std::string& pageName) const override;
	// IPagination
	virtual size_t getCurrent() const override;
	virtual size_t getCount() const override;

private:
	void updateData();

	std::map<std::string, std::vector<std::string>> m_dataGroups;
	std::map<std::string, size_t> m_pagesCount;

	std::map<std::string, size_t> m_pageStart;
	std::map<std::string, size_t> m_pageCount;
};
