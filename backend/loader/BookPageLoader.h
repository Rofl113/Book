#pragma once
#include "IBookItemLoader.h"



class BookPageLoader : public IBookItemLoader
{
public:
	BookPageLoader();
	virtual ~BookPageLoader() override;

	virtual std::unique_ptr<IBookItem> load(const std::shared_ptr<BookDataItem>& data) const override;
};
