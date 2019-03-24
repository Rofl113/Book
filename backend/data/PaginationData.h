#pragma once
#include "IPaginationData.h"
#include <vector>
#include <map>



class PaginationData : public IPaginationData
{
	PaginationData() = delete;
public:
	explicit PaginationData(const bool enanbled);

	virtual bool isEnabled() const override;

private:
	const bool m_enanbled;
};
