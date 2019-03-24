#pragma once
#include "BookDataItem.h"



class IBookDataPage : public IBookDataItem
{
public:
	virtual ~IBookDataPage() = default;
};
