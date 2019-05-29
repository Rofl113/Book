#pragma once
#include "BookItem.h"
#include <vector>
#include <memory>


class BookDataChapter;
class IManagerBookChapter;


class BookChapter : public BookItem
{
	using ClassBase = BookItem;
public:
	BookChapter();

	const IBookItem* getChildCurrent() const;
	const BookDataChapter* getDataChapter() const;

	void setChilds(std::vector<std::unique_ptr<IBookItem>>&& childs);

protected:
	const std::vector<std::unique_ptr<IBookItem>>& getChilds() const;
	// IBookItem
	virtual IManagerActions* getManagerActions() override;
	virtual const IPagination* getPagination() const override;
	virtual IBookItem* searchItem(const std::string& name) override;
	// BookItem
	void updateFromData() override;

	virtual std::unique_ptr<IManagerBookChapter> createManagerActions();

	IManagerBookChapter* getManagerChapter() const;

	const IBookItem* getChild(const size_t index) const;

private:
	std::vector<std::unique_ptr<IBookItem>> m_childs;
	std::unique_ptr<IManagerBookChapter> m_managerActions;
};
