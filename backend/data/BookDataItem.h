#pragma once
#include <string>
#include <memory>



class PaginationData;
enum class BookDataType;


class BookDataItem
{
	BookDataItem() = delete;
public:
	virtual ~BookDataItem();
	explicit BookDataItem(const std::string& name, const BookDataType& type);

	// Имя узла - (страницы или главы)
	virtual const std::string& getName() const;
	virtual const BookDataType& getType() const;
	// Настройки нумерации страниц
	virtual void setPagination(const std::shared_ptr<PaginationData>& pagination);
	virtual const PaginationData* getPagination() const;

	virtual bool equal(const BookDataItem& other) const;

private:
	// Имя узла - (страницы или главы)
	const std::string m_name;
	// Тип узла - (страница или глава или книга)
	const BookDataType m_type;
	// Настройки нумерации страниц
	std::shared_ptr<PaginationData> m_pagination;
};
