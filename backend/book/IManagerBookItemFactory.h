#pragma once
#include <memory>
#include "IManagerActions.h"


class IManagerBookItem;
class ManagerActionsData;


class IManagerBookItemFactory
{
public:
	virtual ~IManagerBookItemFactory() = default;

	virtual std::unique_ptr<IManagerBookItem> create(const std::shared_ptr<ManagerActionsData>& data) const = 0;
};
