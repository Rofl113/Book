#pragma once
#include <string>
#include <map>
#include "BookDataItem.h"


class ManagerActionsData;


class BookDataPage : public BookDataItem
{
	BookDataPage() = delete;
public:
	explicit BookDataPage(const std::string& name
	, const std::map<std::string, std::shared_ptr<ManagerActionsData>>& managers = {}
	, const std::string& managerActionsName = {});
	virtual ~BookDataPage() override;

	const std::map<std::string, std::shared_ptr<ManagerActionsData>>& getManagers() const;
	const std::string& getManagerActionsName() const;

private:
	const std::map<std::string, std::shared_ptr<ManagerActionsData>> m_managers;
	const std::string m_managerActionsName;
};
