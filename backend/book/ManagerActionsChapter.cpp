#include "ManagerActionsChapter.h"
#include "IBookItem.h"
#include "IPagination.h"
#include "PaginationBase.h"
#include "data/BookDataItem.h"




ManagerActionsChapter::ManagerActionsChapter(std::function<size_t ()>&& funcGetChildsCount
											 , std::function<IBookItem* (const size_t)>&& funcGetChild)
	: m_funcGetChildsCount(std::move(funcGetChildsCount))
	, m_funcGetChild(std::move(funcGetChild))
{
	if (m_funcGetChildsCount && m_funcGetChild)
	{
		const size_t size = m_funcGetChildsCount();
		size_t startPage = 0;
		for(size_t i = 0; i < size; ++i)
		{
			if (const auto child = m_funcGetChild(i))
			{
				if (const auto pagination = child->getPagination())
				{
					m_childsStartPage.push_back(startPage);
					startPage += pagination->getCount();
				}
			}
		}
		m_childsPageCount = startPage;
		// Обновляем данные по именам
		for (size_t i = 0; i < size; ++i)
		{
			if (const auto child = funcGetChild(i))
			{
				const auto name = child->getData()->getName();
				m_childs[name] = i;
			}
		}
	}
}

void ManagerActionsChapter::setPagination(const bool enable)
{
	if (enable)
	{
		if (nullptr == m_pagination)
		{
			m_pagination.reset(new PaginationBase());
			this->updatePagination();
		}
	}
	else
	{
		m_pagination.reset();
	}
}

const IPagination* ManagerActionsChapter::getPagination() const
{
	return m_pagination.get();
}

bool ManagerActionsChapter::check(const IManagerActions::TypeAction action) const
{
	if (!m_funcGetChildsCount && !m_funcGetChild)
	{
		return false;
	}
	const auto count = m_funcGetChildsCount();
	// Если не получается то ...
	switch (action)
	{
	case TypeAction::FIRST:
		return (count > 0);

	case TypeAction::LAST:
		return (count > 0);

	case TypeAction::PREV:
		if (const auto managerChild = this->getCurrentChildManager())
		{
			if (managerChild->check(action))
			{
				return true;
			}
			else
			{
				return (m_childCurrentIndex > 0);
			}
		}
		return false;

	case TypeAction::NEXT:
		if (const auto managerChild = this->getCurrentChildManager())
		{
			if (managerChild->check(action))
			{
				return true;
			}
			else
			{
				const auto indexNext = (m_childCurrentIndex + 1);
				return (indexNext < count);
			}
		}
		return false;

	default:
		return false;
	}
}

bool ManagerActionsChapter::run(const IManagerActions::TypeAction action)
{
	if (false == this->check(action))
	{
		return false;
	}
	bool result = false;
	const auto count = m_funcGetChildsCount();
	// Если не получается то ...
	switch (action)
	{
	case TypeAction::FIRST:
		m_childCurrentIndex = 0;
		if (const auto managerChild = this->getCurrentChildManager())
		{
			result = managerChild->run(action);
		}
		break;

	case TypeAction::LAST:
		m_childCurrentIndex = (count - 1);
		if (const auto managerChild = this->getCurrentChildManager())
		{
			result = managerChild->run(action);
		}
		break;

	case TypeAction::PREV:
		if (const auto managerChild = this->getCurrentChildManager())
		{
			if (managerChild->run(action))
			{
				result = true;
			}
			else
			{
				if (m_childCurrentIndex > 0)
				{
					m_childCurrentIndex -= 1;
					if (const auto managerChildPrev = this->getCurrentChildManager())
					{
						if (managerChildPrev->run(TypeAction::LAST))
						{
							result = true;
						}
					}
				}
			}
		}
		break;

	case TypeAction::NEXT:
		if (const auto managerChild = this->getCurrentChildManager())
		{
			if (managerChild->check(action))
			{
				result = true;
			}
			else
			{
				const auto indexNext = (m_childCurrentIndex + 1);
				if (indexNext < count)
				{
					m_childCurrentIndex = indexNext;
					if (const auto managerChildNext = this->getCurrentChildManager())
					{
						if (managerChildNext->run(TypeAction::FIRST))
						{
							result = true;
						}
					}
				}
			}
		}
		break;

	default:
		break;
	}
	this->updatePagination();
	return result;
}

bool ManagerActionsChapter::runChoiceItem(const std::string& itemName)
{
	if (false == this->checkChoiceItem(itemName))
	{
		return false;
	}
	const auto index = m_childs.at(itemName);
	if (const auto item = m_funcGetChild(index))
	{
		m_childCurrentIndex = index;
		return true;
	}
	return false;
}

bool ManagerActionsChapter::checkChoiceItem(const std::string& itemName) const
{
	return m_childs.count(itemName);
}

size_t ManagerActionsChapter::getChildCurrentIndex() const
{
	return m_childCurrentIndex;
}

IManagerActions* ManagerActionsChapter::getCurrentChildManager() const
{
	if (auto child = this->getCurrentChild())
	{
		return child->getManagerActions();
	}
	return nullptr;
}

const IPagination* ManagerActionsChapter::getCurrentChildPagination() const
{
	if (auto child = this->getCurrentChild())
	{
		return child->getPagination();
	}
	return nullptr;
}

IBookItem* ManagerActionsChapter::getCurrentChild() const
{
	if (m_funcGetChildsCount && m_funcGetChild)
	{
		const auto count = m_funcGetChildsCount();
		if (count > m_childCurrentIndex)
		{
			return m_funcGetChild(m_childCurrentIndex);
		}
	}
	return nullptr;
}

void ManagerActionsChapter::updatePagination()
{
	if (auto pagination = m_pagination.get())
	{
		size_t current = 0;
		if (const auto paginationChild = this->getCurrentChildPagination())
		{
			current += paginationChild->getCurrent();
			current += m_childsStartPage[m_childCurrentIndex];
		}
		pagination->setCurrent(current);
		pagination->setCount(m_childsPageCount);
	}
}
