#pragma once
#include "IBookItem.h"



class IPaginationBook;


class IBook : public IBookItem
{
public:
	virtual ~IBook() = default;

	virtual bool checkSelect(const std::string& itemName) = 0;
	virtual bool runSelect(const std::string& itemName) = 0;

	virtual const IPaginationBook* getPaginationBook() const = 0;
};
