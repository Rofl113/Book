#pragma once
#include <stddef.h>
#include <vector>
#include <string>
#include <map>
#include "IPagination.h"



class IPaginationBook : public IPagination
{
protected:
	IPaginationBook() = default;
public:
	virtual ~IPaginationBook() = default;

	virtual void setGroups(std::map<std::string, std::vector<std::string>>&& dataGroups) = 0;
	virtual void setPagesCount(std::map<std::string, size_t>&& pagesCount) = 0;

	virtual size_t convertNumber(const std::string& pageName, const size_t& pageNumber) const = 0;
	virtual size_t convertCount(const std::string& pageName) const = 0;
};
