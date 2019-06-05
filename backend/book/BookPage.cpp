#include "BookPage.h"
#include "PaginationBase.h"
#include "IManagerBookItem.h"
#include "IManagerBookItemFactory.h"
#include "data/PaginationData.h"
#include "data/BookDataPage.h"




IManagerActions* BookPage::getManagerActions()
{
	return this->getManagerActionsPage();
}

const IPagination* BookPage::getPagination() const
{
	if (const auto manager = this->getManagerActionsPage())
	{
		return manager->getPagination();
	}
	return nullptr;
}

void BookPage::updateFromData()
{
	m_managers.clear();
	const auto data = dynamic_cast<const BookDataPage*>(this->getData());
	if (nullptr == data)
	{
		return;
	}
	// Reload managers
	{
		for (const auto& itManager : data->getManagers())
		{
			const auto& name = itManager.first;
			if (const auto data = itManager.second)
			{
				m_managers[name] = this->createManager(data);
			}
		}
	}
	// Set Pagination Manager
	if (auto manager = this->getManagerActionsPage())
	{
		const auto dataPagination = data->getPagination();
		const bool isEnabled = (dataPagination) ? dataPagination->isEnabled() : false;
		manager->setPagination(isEnabled);
	}
}

std::unique_ptr<IManagerBookItem> BookPage::createManager(const std::shared_ptr<ManagerActionsData>& data)
{
	// Реализация в наследниках
	return {};
}

std::string BookPage::getManagerActionsName() const
{
	const auto data = dynamic_cast<const BookDataPage*>(this->getData());
	if (data)
	{
		return data->getManagerActionsName();
	}
	return {};
}

IManagerBookItem* BookPage::getManagerActionsPage() const
{
	const auto name = this->getManagerActionsName();
	if (m_managers.count(name))
	{
		return m_managers.at(name).get();
	}
	return nullptr;
}
