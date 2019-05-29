#pragma once
#include <string>
#include "IManagerBookItem.h"



class IManagerBookChapter : public IManagerBookItem
{
public:
	virtual ~IManagerBookChapter() override = default;

	virtual bool checkChoiceItem(const std::string& itemName) const = 0;
	virtual bool runChoiceItem(const std::string& itemName) = 0;
	virtual size_t getChildCurrentIndex() const = 0;
};
