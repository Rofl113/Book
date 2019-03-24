#pragma once
#include <vector>
#include <memory>
#include "IBookDataItem.h"



class IBookDataChapter : public IBookDataItem
{
public:
	virtual ~IBookDataChapter() = default;

	virtual const std::vector<std::shared_ptr<IBookDataItem>>& getChilds() const = 0;
};
