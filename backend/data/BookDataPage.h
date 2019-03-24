#pragma once
#include "BookDataItem.h"
#include "IBookDataPage.h"



class BookDataPage : public BookDataItem, public IBookDataPage
{
	BookDataPage() = delete;
public:
	explicit BookDataPage(const std::string& name);

private:
	virtual const IBookDataItem::Type& getType() const override;
	virtual const std::string& getName() const override;
};
