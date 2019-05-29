#pragma once
#include <map>
#include <memory>
#include "IBookItemLoader.h"


enum class BookDataType;


class BookItemLoader : public IBookItemLoader
{
public:
	BookItemLoader();
	~BookItemLoader();

	virtual std::unique_ptr<IBookItem> load(const std::shared_ptr<BookDataItem>& data) const override;
	void setLoader(const BookDataType& type, const std::shared_ptr<IBookItemLoader>& loaderPage);

private:
	std::map<BookDataType, std::shared_ptr<IBookItemLoader>> m_loaders;
};
