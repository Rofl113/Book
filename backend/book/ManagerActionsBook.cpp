#include "ManagerActionsBook.h"
#include "PaginationBase.h"
#include "IBookItem.h"
#include "data/BookDataItem.h"




ManagerActionsBook::ManagerActionsBook(std::function<size_t()>&& funcGetChildsCount
									   , std::function<IBookItem*(const size_t)>&& funcGetChild
									   , std::function<void()>&& funcUpdatePagination)

	: ClassBase(std::move(funcGetChildsCount), std::move(funcGetChild))
	, m_funcUpdatePagination(std::move(funcUpdatePagination))
{
}

void ManagerActionsBook::updatePagination()
{
	ClassBase::updatePagination();
	// Проверяем группу нумераций
	if (m_funcUpdatePagination)
	{
		m_funcUpdatePagination();
	}
}
