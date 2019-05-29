#pragma once
#include <memory>
#include "IBookItem.h"

#include "IManagerActions.h"
#include "IPagination.h"


class BookItem : public IBookItem
{
public:
	virtual void setData(const std::shared_ptr<BookDataItem>& data);
	// IBookItem
	virtual const BookDataItem* getData() const override;

protected:
	virtual void updateFromData() = 0;

protected:
	// IBookItem
	virtual IBookItem* searchItem(const std::string& name) override;

private:
	// начальные данные
	std::shared_ptr<BookDataItem> m_data;
};
