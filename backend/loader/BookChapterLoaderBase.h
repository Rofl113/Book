#pragma once
#include <vector>
#include <memory>



class BookDataItem;
class IBookItem;
class IBookItemLoader;



class BookChapterLoaderBase
{
public:
	BookChapterLoaderBase();
	~BookChapterLoaderBase();

protected:
	virtual const IBookItemLoader* getLoaderItem() const = 0;
	std::vector<std::unique_ptr<IBookItem>> loadChilds(const std::shared_ptr<BookDataItem>& data) const;
};
