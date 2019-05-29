#pragma once
#include <stddef.h>


// Интерфес информации по нумерации
class IPagination
{
public:
	virtual ~IPagination() = default;
	// Номер текущего элемента (страниц)
	virtual size_t getCurrent() const = 0;
	// Количество элементов (страниц)
	virtual size_t getCount() const = 0;
};
