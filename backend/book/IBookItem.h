#pragma once
#include <string>


class BookDataItem;
class IManagerActions;
class IPagination;



// Интерфейс управления элементом книги
class IBookItem
{
public:
	virtual ~IBookItem() = default;
	// Получить начальные данные по элементу
	virtual const BookDataItem* getData() const = 0;
	// Получить интерфейс менеджера действий по элементу
	virtual IManagerActions* getManagerActions() = 0;
	// Получить интерфейс нумерации элементов
	virtual const IPagination* getPagination() const = 0;
	// Получить интерфейс элемента по имени
	virtual IBookItem* searchItem(const std::string& name) = 0;
};
