#pragma once
#include <vector>



class BookmarkData;


class BookmarksData
{
	BookmarksData() = delete;
public:
	virtual ~BookmarksData();
	explicit BookmarksData(const bool enabled, std::vector<BookmarkData>&& marks);

	virtual bool isEnabled() const;
	virtual const std::vector<BookmarkData>& getMarks() const;

	virtual bool equal(const BookmarksData& other) const;

private:
	const bool m_enabled = false;
	const std::vector<BookmarkData> m_marks;
};
