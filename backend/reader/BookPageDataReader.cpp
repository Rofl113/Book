#include "BookPageDataReader.h"
#include "data/BookDataPage.h"
#include "ManagerActionsDataReader.h"


namespace
{
	static constexpr const auto KEY_NAME = "name";
	static constexpr const auto KEY_MANAGERS = "managers";
	static constexpr const auto KEY_MANAGER_ACTIONS = "manager_actions";
}


BookPageDataReader::BookPageDataReader()
{

}

BookPageDataReader::~BookPageDataReader()
{

}

std::shared_ptr<BookDataPage> BookPageDataReader::read(const nlohmann::json& jsPage) const
{
	std::shared_ptr<BookDataPage> data;
	try
	{
		const std::string name = jsPage.at(KEY_NAME);
		std::map<std::string, std::shared_ptr<ManagerActionsData>> managers;
		if (jsPage.count(KEY_MANAGERS))
		{
			ManagerActionsDataReader readerManager;
			const auto& jsManagers = jsPage.at(KEY_MANAGERS);
			for (const auto& jsManager : jsManagers.items())
			{
				const std::string name = jsManager.key();
				const auto& jsManagerData = jsManager.value();
				if (auto manager = readerManager.read(jsManagerData))
				{
					managers[name] = std::move(manager);
				}
			}
		}
		std::string managerActionsName;
		if (jsPage.count(KEY_MANAGER_ACTIONS))
		{
			managerActionsName = jsPage.at(KEY_MANAGER_ACTIONS);
		}
		data.reset(new BookDataPage(name, std::move(managers), std::move(managerActionsName)));
	}
	catch (...)
	{
		throw;
	}
	return data;
}
