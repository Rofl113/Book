#pragma once
#include <vector>
#include <map>



class PaginationData
{
	PaginationData() = delete;
public:
	virtual ~PaginationData() = default;
	explicit PaginationData(const bool enanbled);

	virtual bool isEnabled() const;

	virtual bool equal(const PaginationData& other) const;

private:
	const bool m_enanbled;
};
