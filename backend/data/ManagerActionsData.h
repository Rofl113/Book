#pragma once
#include <string>
#include <memory>



class DataSourceCollection;


class ManagerActionsData
{
public:
	ManagerActionsData();
	void setSettings(const std::string& settings);
	void setDataSourceName(const std::string& dataSourceName);
	void setDataSourceCollection(const std::shared_ptr<DataSourceCollection>& collectionDataSource);

	const std::string& getSettings() const;
	const std::string& getDataSourceName() const;
	const DataSourceCollection* getDataSourceCollection() const;

	virtual bool equal(const ManagerActionsData& other) const;

private:
	std::string m_settings;
	std::string m_dataSourceName;
	std::shared_ptr<DataSourceCollection> m_collectionDataSource;

};
