#include "BookItem.h"
#include "data/BookDataItem.h"

#include "data/PaginationData.h"
#include "PaginationBase.h"



void BookItem::setData(const std::shared_ptr<BookDataItem>& data)
{
	m_data = data;
	// Обновляем данные
	this->updateFromData();
}

const BookDataItem* BookItem::getData() const
{
	return m_data.get();
}

IBookItem* BookItem::searchItem(const std::string& name)
{
	if (const auto data = this->getData())
	{
		if (name == data->getName())
		{
			return this;
		}
	}
	return nullptr;
}

