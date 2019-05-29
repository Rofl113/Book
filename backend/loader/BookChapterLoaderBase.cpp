#include "BookChapterLoaderBase.h"
#include "IBookItemLoader.h"
#include "data/BookDataChapter.h"
#include "book/BookChapter.h"




BookChapterLoaderBase::BookChapterLoaderBase()
{

}

BookChapterLoaderBase::~BookChapterLoaderBase()
{

}

std::vector<std::unique_ptr<IBookItem>> BookChapterLoaderBase::loadChilds(const std::shared_ptr<BookDataItem>& data) const
{
	std::vector<std::unique_ptr<IBookItem>> childs;
	if (const auto loaderItem = this->getLoaderItem())
	{
		if (const auto dataChapter = dynamic_cast<const BookDataChapter*>(data.get()))
		{
			for (const auto& dataChild : dataChapter->getChilds())
			{
				childs.push_back(loaderItem->load(dataChild));
			}
		}
	}
	return childs;
}
