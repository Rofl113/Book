#pragma once
#include <string>



class IBookDataItem
{
public:
	virtual ~IBookDataItem() = default;

	enum class Type
	{
		NONE,
		PAGE,
		CHAPTER
	};
	virtual const Type& getType() const = 0;
	virtual const std::string& getName() const = 0;
};
