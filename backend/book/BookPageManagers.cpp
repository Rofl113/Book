#include "BookPageManagers.h"
#include "ManagerActionsBase.h"
#include "PaginationInfoBase.h"


namespace
{
	class ManagerActionsSlave : public ManagerActionsBase
	{
		ManagerActionsSlave() = delete;
	public:
		ManagerActionsSlave(IManager* managerLeading)
			: m_managerLeading(managerLeading)
		{
			// Менеджер не должен быть nullptr
		}

	protected:
		virtual bool _check(const TypeAction& action) const
		{
			return m_managerLeading->check(action);
		}
		virtual bool _run(const TypeAction& action)
		{
			return m_managerLeading->run(action);
		}

	private:
		IManager* const m_managerLeading;
	};
} // end namespace

BookPageManagers::BookPageManagers(const BookDataPage& /*data*/, std::map<std::string, std::unique_ptr<IManager> >&& managers, std::string&& executive)
	: BookPage()
	, m_managers(managers)
	, m_executive((managers.count(executive) ? managers.at(executive).get() : nullptr))
{
}

ManagerActionsBase* BookPageManagers::createManagerActions()
{
	// Если есть управляющий менеджер ...
	if (m_executive)
	{
		// ... то создаем логику на основе данного менеджера
		return new ManagerActionsSlave(m_executive);
	}
	// если управляющего менеджера нет - то создаем стандартный
	return ClassBase::createManagerActions();
}

PaginationInfoBase* BookPageManagers::createPaginationInfo()
{
	// Создаем стандартный объект
	auto paginationInfo = ClassBase::createPaginationInfo();
	// Если есть управляющий класс то ...
	if (m_executive)
	{
		// Берем значение о количестве у него
		paginationInfo->setCount(m_executive->getCount());
	}
	return paginationInfo;
}
