#include "BookDataChapter.h"



BookDataChapter::BookDataChapter(const std::string& name, std::vector<std::shared_ptr<IBookDataItem> >&& childs)
	: BookDataItem(name, Type::CHAPTER)
	, m_childs(std::move(childs))
{

}

const std::vector<std::shared_ptr<IBookDataItem>>& BookDataChapter::getChilds() const
{
	return m_childs;
}

const IBookDataItem::Type& BookDataChapter::getType() const
{
	return BookDataItem::getType();
}

const std::string& BookDataChapter::getName() const
{
	return BookDataItem::getName();
}
