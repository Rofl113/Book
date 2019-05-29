#pragma once
#include <string>
#include <map>
#include <memory>
#include "BookItem.h"
#include "data/BookDataPage.h"



class IManagerBookItem;
class IManagerBookItemFactory;



class BookPage : public BookItem
{
	using ClassBase = BookItem;
	BookPage() = delete;
public:
	BookPage(const std::shared_ptr<IManagerBookItemFactory>& managerFactory);

protected:
	// IBookItem
	virtual IManagerActions* getManagerActions() override;
	virtual const IPagination* getPagination() const override;
	// BookItem
	virtual void updateFromData() override;

private:
	std::string getManagerActionsName() const;
	IManagerBookItem* getManagerActionsPage() const;

	const std::shared_ptr<IManagerBookItemFactory> m_managerFactory;
	std::map<std::string, std::unique_ptr<IManagerBookItem>> m_managers;
};
