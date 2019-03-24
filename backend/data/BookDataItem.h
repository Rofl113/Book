#pragma once
#include "IBookDataItem.h"
#include <memory>



class IPaginationData;


class BookDataItem : public IBookDataItem
{
	BookDataItem() = delete;
public:
	explicit BookDataItem(const std::string& name, const Type& type);

	// Имя узла - (страницы или главы)
	virtual const std::string& getName() const override;
	virtual const Type& getType() const override;
	// Настройки нумерации страниц
	void setPagination(const std::shared_ptr<IPaginationData>& pagination);
	const IPaginationData* getPagination() const;

private:
	// Имя узла - (страницы или главы)
	const std::string m_name;
	// Тип узла - (страница или глава или книга)
	const Type m_type;
	// Настройки нумерации страниц
	std::shared_ptr<IPaginationData> m_pagination;
};
