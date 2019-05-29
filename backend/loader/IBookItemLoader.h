#pragma once
#include <memory>
#include "book/IBookItem.h"


class BookDataItem;


class IBookItemLoader
{
public:
	virtual ~IBookItemLoader() = default;
	virtual std::unique_ptr<IBookItem> load(const std::shared_ptr<BookDataItem>& data) const = 0;
};
