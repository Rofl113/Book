#include "BookItemLoader.h"
#include "data/BookDataItem.h"



BookItemLoader::BookItemLoader()
{

}

BookItemLoader::~BookItemLoader()
{

}

std::unique_ptr<IBookItem> BookItemLoader::load(const std::shared_ptr<BookDataItem>& data) const
{
	std::unique_ptr<IBookItem> item;
	if (data)
	{
		const auto dataType = data->getType();
		if (m_loaders.count(dataType))
		{
			if (const auto loader = m_loaders.at(dataType))
			{
				item = loader->load(data);
			}
		}
	}
	return item;
}

void BookItemLoader::setLoader(const BookDataType& type, const std::shared_ptr<IBookItemLoader>& loaderPage)
{
	m_loaders[type] = loaderPage;
}
