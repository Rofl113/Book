#include "Book.h"
#include <algorithm>
#include "data/BookData.h"
#include "data/PaginationData.h"
#include "data/PaginationDataBook.h"
#include "IBoxPages.h"
#include "IBookItem.h"
#include "IManagerActions.h"
#include "IPagination.h"
#include "IPaginationBook.h"
#include "PaginationBase.h"
#include "PaginationBookBase.h"
#include "ManagerActionsBook.h"




Book::Book()
	: BookChapter()
{

}

Book::~Book()
{

}

const BookDataItem* Book::getData() const
{
	return ClassBase::getData();
}

IManagerActions* Book::getManagerActions()
{
	return ClassBase::getManagerActions();
}

bool Book::checkSelect(const std::string& itemName)
{
	const auto item = this->searchItem(itemName);
	return (item != nullptr);
}

bool Book::runSelect(const std::string& itemName)
{
	if (this->checkSelect(itemName))
	{
		if (auto item = this->searchItem(itemName))
		{
			m_itemCurName = itemName;
			if (auto manager = item->getManagerActions())
			{
				manager->run(IManagerActions::TypeAction::FIRST);
			}
			return true;
		}
	}
	return false;
}

IBookItem* Book::searchItem(const std::string& name)
{
	return ClassBase::searchItem(name);
}

std::unique_ptr<IManagerBookChapter> Book::createManagerActions()
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
	std::function<void()> funcUpdatePagination = [this]
	{
		const auto paginationBook = this->getPaginationBook();
		const auto managerChapter = this->getManagerChapter();
		const auto paginationManager = managerChapter->getPagination();
		if (paginationBook && paginationManager)
		{
			const auto indexChild = managerChapter->getChildCurrentIndex();
			if (const auto child = this->getChild(indexChild))
			{
				const auto& name = child->getData()->getName();
				const auto current = paginationBook->convertNumber(name, paginationManager->getCurrent());
				const auto count = paginationBook->convertCount(name);
				if (auto paginationBookRoot = dynamic_cast<PaginationBase*>(m_paginationBook.get()))
				{
					paginationBookRoot->setCurrent(current);
					paginationBookRoot->setCount(count);
				}
			}
		}
	};
	managerActions.reset(new ManagerActionsBook(std::move(funcGetChildsCount), std::move(funcGetChild), std::move(funcUpdatePagination)));
	return managerActions;
}

const IPagination* Book::getPagination() const
{
	return this->getPaginationBook();
}

const IPaginationBook* Book::getPaginationBook() const
{
	return m_paginationBook.get();
}

void Book::updateFromData()
{
	const auto data = dynamic_cast<const BookData*>(this->getData());
	if (nullptr == data)
	{
		return;
	}
	ClassBase::updateFromData();
	m_paginationBook.reset();
	if (const auto paginationData = data->getPaginationBook())
	{
		if (paginationData->isEnabled())
		{
			m_paginationBook.reset(new PaginationBookBase());
		}
	}
}
