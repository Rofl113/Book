#include "ManagerActionsData.h"



ManagerActionsData::ManagerActionsData()
{

}

void ManagerActionsData::setSettings(const std::string& settings)
{
	m_settings = settings;
}

void ManagerActionsData::setDataSourceName(const std::string& dataSourceName)
{
	m_dataSourceName = dataSourceName;
}

void ManagerActionsData::setDataSourceCollection(const std::shared_ptr<DataSourceCollection>& collectionDataSource)
{
	m_collectionDataSource = collectionDataSource;
}

const std::string& ManagerActionsData::getSettings() const
{
	return m_settings;
}

const std::string& ManagerActionsData::getDataSourceName() const
{
	return m_dataSourceName;
}

const DataSourceCollection* ManagerActionsData::getDataSourceCollection() const
{
	return m_collectionDataSource.get();
}

bool ManagerActionsData::equal(const ManagerActionsData& other) const
{
	if (this->getSettings() != other.getSettings())
	{
		return false;
	}
	if (this->getDataSourceName() != other.getDataSourceName())
	{
		return false;
	}
	if (this->getDataSourceCollection() != other.getDataSourceCollection())
	{
		return false;
	}
	return true;
}
