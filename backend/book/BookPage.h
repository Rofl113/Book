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
public:
	virtual ~BookPage() override = default;
	BookPage() = default;

protected:
	// IBookItem
	virtual IManagerActions* getManagerActions() override;
	virtual const IPagination* getPagination() const override;
	// BookItem
	virtual void updateFromData() override;

	virtual std::unique_ptr<IManagerBookItem> createManager(const std::shared_ptr<ManagerActionsData>& data);

private:
	std::string getManagerActionsName() const;
	IManagerBookItem* getManagerActionsPage() const;

	std::map<std::string, std::unique_ptr<IManagerBookItem>> m_managers;
};
