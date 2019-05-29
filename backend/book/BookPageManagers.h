#pragma once
#include "BookPage.h"
#include "IManager.h"


class BookPageManagers : public BookPage
{
	using ClassBase = BookPage;
	BookPageManagers() = delete;
public:
	BookPageManagers(const BookDataPage& data, std::map<std::string, std::unique_ptr<IManager>>&& managers, std::string&& executive);

protected:
	virtual IManagerActions* createManagerActions() override;
	virtual PaginationInfoBase* createPaginationInfo() override;

private:
	const std::map<std::string, std::unique_ptr<IManager>> m_managers;
	IManager * const m_executive;
};
