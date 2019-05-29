#pragma once
#include "IBookItemLoader.h"




class IManagerBookItemFactory;



class BookPageLoader : public IBookItemLoader
{
public:
	BookPageLoader();
	virtual ~BookPageLoader() override;

	virtual std::unique_ptr<IBookItem> load(const std::shared_ptr<BookDataItem>& data) const override;

	void setManagerBookItemFactory(const std::shared_ptr<IManagerBookItemFactory>& managerFactory);

private:
	std::shared_ptr<IManagerBookItemFactory> m_managerFactory;
};
