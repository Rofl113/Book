#include "BookChapter.h"
#include "data/BookDataItem.h"
#include "data/BookDataChapter.h"
#include "data/PaginationData.h"
#include "ManagerActionsChapter.h"
#include "IBookItem.h"




BookChapter::BookChapter()
{
}

IBookItem* BookChapter::searchItem(const std::string& name)
{
	// ClassBase
	if (auto item = ClassBase::searchItem(name))
	{
		return item;
	}
	// BookChapter
	for (const auto& child : this->getChilds())
	{
		if (auto item = child->searchItem(name))
		{
			return item;
		}
	}
	return nullptr;
}

void BookChapter::updateFromData()
{
	// Create manager chapter
	m_managerActions = this->createManagerActions();
	// manager chapter set pagination
	if (const auto data = this->getDataChapter())
	{
		if (const auto dataPagination = data->getPagination())
		{
			m_managerActions->setPagination(dataPagination->isEnabled());
		}
	}
}

std::unique_ptr<IManagerBookChapter> BookChapter::createManagerActions()
{
	std::unique_ptr<IManagerBookChapter> managerActions;
	std::function<size_t()> funcGetChildsCount = [this]
	{
		return this->getChilds().size();
	};
	std::function<IBookItem*(const size_t)> funcGetChild = [this] (const size_t index) -> IBookItem*
	{
		const auto& childs = this->getChilds();
		if (childs.size() > index)
		{
			return childs.at(index).get();
		}
		return nullptr;
	};
	managerActions.reset(new ManagerActionsChapter(std::move(funcGetChildsCount), std::move(funcGetChild)));
	return managerActions;
}

IManagerBookChapter* BookChapter::getManagerChapter() const
{
	return m_managerActions.get();
}

const IBookItem* BookChapter::getChild(const size_t index) const
{
	const auto& childs = this->getChilds();
	if (childs.size() > index)
	{
		return childs.at(index).get();
	}
	return nullptr;
}

const IBookItem* BookChapter::getChildCurrent() const
{
	if (auto managerActions = m_managerActions.get())
	{
		return this->getChild(managerActions->getChildCurrentIndex());
	}
	return nullptr;
}

const BookDataChapter* BookChapter::getDataChapter() const
{
	return dynamic_cast<const BookDataChapter*>(this->getData());
}

void BookChapter::setChilds(std::vector<std::unique_ptr<IBookItem> >&& childs)
{
	m_childs = std::move(childs);
}

const std::vector<std::unique_ptr<IBookItem> >& BookChapter::getChilds() const
{
	return m_childs;
}

IManagerActions* BookChapter::getManagerActions()
{
	return m_managerActions.get();
}

const IPagination* BookChapter::getPagination() const
{
	if (m_managerActions)
	{
		return m_managerActions->getPagination();
	}
	return nullptr;
}
