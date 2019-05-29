#pragma once


/**
 * @brief Интерфейс управления действиями
 */
class IManagerActions
{
public:
	virtual ~IManagerActions() = default;

	enum class TypeAction
	{
		NONE,
		FIRST,
		LAST,
		PREV,
		NEXT
	};

	virtual bool check(const TypeAction action) const = 0;
	virtual bool run(const TypeAction action) = 0;
};
