#pragma once
#include <vector>
#include "IBook.h"
#include "BookChapter.h"


class IBoxPages;
class IPaginationBook;
class IBookItem;



class Book : public BookChapter, public IBook
{
	using ClassBase = BookChapter;
public:
	Book();

	virtual ~Book() override;

	virtual const BookDataItem* getData() const override;
	virtual IManagerActions* getManagerActions() override;
	virtual const IPagination* getPagination() const override;

	virtual bool checkSelect(const std::string& itemName) override;
	virtual bool runSelect(const std::string& itemName) override;

	virtual const IPaginationBook* getPaginationBook() const override;

private:
	// BookItem
	void updateFromData() override;
	/**
	 * @ copy IBookItem
	 */
	virtual IBookItem* searchItem(const std::string& name) override;

	virtual std::unique_ptr<IManagerBookChapter> createManagerActions() override;

	std::string m_itemCurName;

	std::unique_ptr<IBookItem> m_rootTree;
	std::unique_ptr<IPaginationBook> m_paginationBook;
};
