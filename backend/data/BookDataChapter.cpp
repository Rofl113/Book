#include "BookDataChapter.h"
#include "BookDataType.h"



BookDataChapter::BookDataChapter(const std::string& name, std::vector<std::shared_ptr<BookDataItem> >&& childs)
	: BookDataItem(name, BookDataType::CHAPTER)
	, m_childs(std::move(childs))
{

}

const std::vector<std::shared_ptr<BookDataItem>>& BookDataChapter::getChilds() const
{
	return m_childs;
}

bool BookDataChapter::equal(const BookDataItem& other) const
{
	if (const auto otherChapter = dynamic_cast<const BookDataChapter*>(&other))
	{
		if (not ClassBase::equal(*otherChapter))
		{
			return false;
		}
		if (this->getChilds().size() != otherChapter->getChilds().size())
		{
			return false;
		}
		const auto& childsThis = this->getChilds();
		const auto& childsOther = otherChapter->getChilds();
		for (size_t i = 0; i < childsThis.size(); ++i)
		{
			if (not childsThis[i]->equal(*childsOther[i].get()))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

const BookDataType& BookDataChapter::getType() const
{
	return BookDataItem::getType();
}

const std::string& BookDataChapter::getName() const
{
	return BookDataItem::getName();
}
