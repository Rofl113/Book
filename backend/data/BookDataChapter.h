#pragma once
#include <vector>
#include <memory>
#include "BookDataItem.h"



class BookDataChapter : public BookDataItem
{
	using ClassBase = BookDataItem;
	BookDataChapter() = delete;
public:
	explicit BookDataChapter(const std::string& name, std::vector<std::shared_ptr<BookDataItem>>&& childs);

	virtual const std::vector<std::shared_ptr<BookDataItem>>& getChilds() const;

	virtual bool equal(const BookDataItem& other) const override;

protected:
	virtual const BookDataType& getType() const override;
	virtual const std::string& getName() const override;

private:
	std::vector<std::shared_ptr<BookDataItem>> m_childs;
};
