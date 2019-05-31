#include "BookDataPage.h"
#include "BookDataType.h"




BookDataPage::BookDataPage(const std::string& name
						   , const std::map<std::string, std::shared_ptr<ManagerActionsData>>& managers
						   , const std::string& managerActionsName)

	: BookDataItem(name, BookDataType::PAGE)
	, m_managers(managers)
	, m_managerActionsName(managerActionsName)
{

}

BookDataPage::~BookDataPage()
{

}

const std::map<std::string, std::shared_ptr<ManagerActionsData>>& BookDataPage::getManagers() const
{
	return m_managers;
}

const std::string& BookDataPage::getManagerActionsName() const
{
	return m_managerActionsName;
}
