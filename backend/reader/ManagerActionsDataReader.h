#pragma once
#include "IManagerActionsDataReader.h"



class ManagerActionsDataReader : public IManagerActionsDataReader
{
public:
	ManagerActionsDataReader();
	virtual ~ManagerActionsDataReader() override;

	virtual std::shared_ptr<ManagerActionsData> read(const nlohmann::json& jsData) const override;
};
