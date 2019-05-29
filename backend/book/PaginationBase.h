#pragma once
#include "IPagination.h"



class PaginationBase : public IPagination
{
public:
	// Settings
	virtual void setCurrent(const size_t value);
	virtual void setCount(const size_t value);
	// IPagination
	virtual size_t getCurrent() const override;
	virtual size_t getCount() const override;

private:
	size_t m_current = 0;
	size_t m_count = 0;
};

