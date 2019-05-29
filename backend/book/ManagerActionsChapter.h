#pragma once
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <functional>
#include "IManagerBookChapter.h"



class IBookItem;
class PaginationBase;



// Менеджер главы
class ManagerActionsChapter : public IManagerBookChapter
{
	ManagerActionsChapter() = delete;
public:
	ManagerActionsChapter(std::function<size_t()>&& funcGetChildsCount
						  , std::function<IBookItem*(const size_t)>&& funcGetChild);

protected:
	// IManagerActions
	virtual bool check(const TypeAction action) const override;
	virtual bool run(const TypeAction action) override;
	virtual bool checkChoiceItem(const std::string& itemName) const override;
	virtual bool runChoiceItem(const std::string& itemName) override;

private:
	// IManagerBookItem
	virtual void setPagination(const bool enable) override;
	virtual const IPagination* getPagination() const override;
	// IManagerBookChapter
	virtual size_t getChildCurrentIndex() const override;

protected:
	virtual void updatePagination();

private:
	IManagerActions* getCurrentChildManager() const;
	const IPagination* getCurrentChildPagination() const;
	IBookItem* getCurrentChild() const;

	const std::function<size_t()> m_funcGetChildsCount;
	const std::function<IBookItem*(const size_t)> m_funcGetChild;
	size_t m_childCurrentIndex = 0;
	std::vector<size_t> m_childsStartPage;
	size_t m_childsPageCount = 0;
	std::unique_ptr<PaginationBase> m_pagination;
	std::map<const std::string, size_t> m_childs;
};
