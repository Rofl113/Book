#pragma once
#include <map>
#include <functional>
#include "ManagerActionsChapter.h"




// Менеджер главы
class ManagerActionsBook : public ManagerActionsChapter
{
	using ClassBase = ManagerActionsChapter;
	ManagerActionsBook() = delete;
public:
	ManagerActionsBook(std::function<size_t()>&& funcGetChildsCount
					   , std::function<IBookItem*(const size_t)>&& funcGetChild
					   , std::function<void()>&& funcUpdatePagination);

private:
	virtual void updatePagination() override;

	const std::function<void()> m_funcUpdatePagination;
};
