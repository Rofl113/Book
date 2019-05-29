#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "data/ManagerActionsData.h"
#include "reader/ManagerActionsDataReader.h"


TEST(manager_actions_data_reader, read_json_valid_settings)
{
	std::shared_ptr<ManagerActionsData> dataOne (new ManagerActionsData());
	dataOne->setSettings("{\"key\":\"value\"}");
	const auto jsDataPage = nlohmann::json::parse("{ \"settings\": {\"key\":\"value\"} }");
	const std::shared_ptr<IManagerActionsDataReader> reader (new ManagerActionsDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(manager_actions_data_reader, read_json_valid_data_source_name)
{
	std::shared_ptr<ManagerActionsData> dataOne (new ManagerActionsData());
	dataOne->setDataSourceName("data_source_name");
	const auto jsDataPage = nlohmann::json::parse("{ \"data_source\": \"data_source_name\" }");
	const std::shared_ptr<IManagerActionsDataReader> reader (new ManagerActionsDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(manager_actions_data_reader, read_json_valid_all)
{
	std::shared_ptr<ManagerActionsData> dataOne (new ManagerActionsData());
	dataOne->setSettings("{\"key\":\"value\"}");
	dataOne->setDataSourceName("data_source_name");
	const auto jsDataPage = nlohmann::json::parse("{ \"settings\": {\"key\":\"value\"}, \"data_source\": \"data_source_name\" }");
	const std::shared_ptr<IManagerActionsDataReader> reader (new ManagerActionsDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_TRUE(dataOne->equal(*dataTwo.get()));
}

TEST(manager_actions_data_reader, read_json_not_valid_settings)
{
	std::shared_ptr<ManagerActionsData> dataOne (new ManagerActionsData());
	dataOne->setSettings("{\"key\":\"value\"}");
	const auto jsDataPage = nlohmann::json::parse("{ \"settings\": {\"key\":\"value_bad\"} }");
	const std::shared_ptr<IManagerActionsDataReader> reader (new ManagerActionsDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(manager_actions_data_reader, read_json_not_valid_data_source_name)
{
	std::shared_ptr<ManagerActionsData> dataOne (new ManagerActionsData());
	dataOne->setDataSourceName("data_source_name");
	const auto jsDataPage = nlohmann::json::parse("{ \"data_source\": \"data_source_name_bad\" }");
	const std::shared_ptr<IManagerActionsDataReader> reader (new ManagerActionsDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}

TEST(manager_actions_data_reader, read_json_not_valid_all)
{
	std::shared_ptr<ManagerActionsData> dataOne (new ManagerActionsData());
	dataOne->setSettings("{ \"key\": \"value\" }");
	dataOne->setDataSourceName("data_source_name");
	const auto jsDataPage = nlohmann::json::parse("{ \"settings\": { \"key\": \"value_bad\" }, \"data_source\": \"data_source_name_bad\" }");
	const std::shared_ptr<IManagerActionsDataReader> reader (new ManagerActionsDataReader());
	const auto dataTwo = reader->read(jsDataPage);
	EXPECT_FALSE(dataOne->equal(*dataTwo.get()));
}
