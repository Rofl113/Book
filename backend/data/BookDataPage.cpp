#include "BookDataPage.h"




BookDataPage::BookDataPage(const std::string& name)
	: BookDataItem(name, Type::PAGE)
{

}

const IBookDataItem::Type& BookDataPage::getType() const
{
	return BookDataItem::getType();
}

const std::string& BookDataPage::getName() const
{
	return BookDataItem::getName();
}
