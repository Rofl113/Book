#pragma once
#include <stddef.h>
#include "IManagerActions.h"


class IPagination;


class IManagerBookItem : public IManagerActions
{
public:
	virtual ~IManagerBookItem() = default;

	virtual void setPagination(const bool enable) = 0;
	virtual const IPagination* getPagination() const = 0;
};
