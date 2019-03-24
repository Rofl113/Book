#pragma once
#include <vector>
#include <memory>
#include "IBookDataChapter.h"
#include "BookDataItem.h"



class BookDataChapter : public BookDataItem, public IBookDataChapter
{
	BookDataChapter() = delete;
public:
	explicit BookDataChapter(const std::string& name, std::vector<std::shared_ptr<IBookDataItem>>&& childs);

	virtual const std::vector<std::shared_ptr<IBookDataItem>>& getChilds() const override;

private:
	virtual const Type& getType() const override;
	virtual const std::string& getName() const override;

	std::vector<std::shared_ptr<IBookDataItem>> m_childs;
};
