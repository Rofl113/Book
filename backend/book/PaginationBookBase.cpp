#include "PaginationBookBase.h"




PaginationBookBase::~PaginationBookBase()
{

}

void PaginationBookBase::setGroups(std::map<std::string, std::vector<std::string> >&& dataGroups)
{
	m_dataGroups = std::move(dataGroups);
}

void PaginationBookBase::setPagesCount(std::map<std::string, size_t>&& pagesCount)
{
	m_pagesCount = std::move(pagesCount);
}

size_t PaginationBookBase::convertNumber(const std::string& pageName, const size_t& pageNumber) const
{
	size_t number = pageNumber;
	if (m_pageStart.count(pageName))
	{
		number += m_pageStart.at(pageName);
	}
	return number;
}

size_t PaginationBookBase::convertCount(const std::string& pageName) const
{
	if (m_pageCount.count(pageName))
	{
		return m_pageCount.at(pageName);
	}
	return 0;
}

size_t PaginationBookBase::getCurrent() const
{
	return ClassBase::getCurrent();
}

size_t PaginationBookBase::getCount() const
{
	return ClassBase::getCount();
}

void PaginationBookBase::updateData()
{
	m_pageStart.clear();
	m_pageCount.clear();
	if (m_dataGroups.empty())
	{
		return;
	}
	if (m_pagesCount.empty())
	{
		return;
	}
	std::map<std::string, size_t> pageStart;
	std::map<std::string, size_t> pageCount;
	for (const auto& it : m_dataGroups)
	{
//		const auto& group = it.first;
		const auto& pages = it.second;
		size_t count = 0;
		for (const auto& page : pages)
		{
			if (not m_pagesCount.count(page))
			{
				return;
			}
			pageStart[page] = count;
			count += m_pagesCount[page];
		}
		for (const auto& page : pages)
		{
			pageCount[page] = count;
		}
	}
	m_pageStart = std::move(pageStart);
	m_pageCount = std::move(pageCount);
}
