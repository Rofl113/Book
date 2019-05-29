#include "ManagerActionsDataReader.h"
#include "data/ManagerActionsData.h"


namespace
{
	static constexpr const auto KEY_SETTINGS = "settings";
	static constexpr const auto KEY_DATA_SOURCE = "data_source";
} // end namespace


ManagerActionsDataReader::ManagerActionsDataReader()
{

}

ManagerActionsDataReader::~ManagerActionsDataReader()
{

}

std::shared_ptr<ManagerActionsData> ManagerActionsDataReader::read(const nlohmann::json& jsData) const
{
	std::shared_ptr<ManagerActionsData> data;
	try
	{
		std::string settings;
		if (jsData.count(KEY_SETTINGS))
		{
			settings = jsData.at(KEY_SETTINGS).dump();
		}
		std::string dataSourceName;
		if (jsData.count(KEY_DATA_SOURCE))
		{
			dataSourceName = jsData.at(KEY_DATA_SOURCE);
		}
		data.reset(new ManagerActionsData());
		data->setSettings(settings);
		data->setDataSourceName(dataSourceName);
		// TODO: надо понять где добавлять
		data->setDataSourceCollection({});
	}
	catch (...)
	{
		throw;
	}
	return data;
}
