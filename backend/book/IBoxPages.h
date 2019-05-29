#pragma once
#include <memory>
#include <string>


class IBookData;
class IBookItem;


class IBoxPages
{
protected:
	IBoxPages() = default;
public:
	virtual ~IBoxPages() = default;

	virtual void setBookData(const IBookData* bookData) = 0;
	virtual std::shared_ptr<IBookItem> getBookItem(const std::string& name) const = 0;
};
