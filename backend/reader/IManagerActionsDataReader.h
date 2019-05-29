#pragma once
#include <memory>
#include <nlohmann/json.hpp>




class ManagerActionsData;

class IManagerActionsDataReader
{
public:
	virtual ~IManagerActionsDataReader() = default;

	virtual std::shared_ptr<ManagerActionsData> read(const nlohmann::json& jsData) const = 0;
};
