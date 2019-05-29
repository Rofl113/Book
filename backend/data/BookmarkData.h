#pragma once
#include <string>
#include <vector>




class BookmarkData
{
	BookmarkData() = delete;
public:
	virtual ~BookmarkData() = default;
	explicit BookmarkData(const std::string&& name, const std::string&& itemBookName, const std::vector<BookmarkData>&& childs);

	bool operator==(const BookmarkData& other) const;
	bool operator!=(const BookmarkData& other) const;

	const std::string& getName() const;
	const std::string& getItemBookName() const;
	const std::vector<BookmarkData>& getChilds() const;

private:
	const std::string m_name;
	const std::string m_itemBookName;
	const std::vector<BookmarkData> m_childs;
};
