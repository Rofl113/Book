#pragma once


class IPaginationData
{
public:
	virtual ~IPaginationData() = default;

	virtual bool isEnabled() const = 0;
};
