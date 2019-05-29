#include "BookmarksDataReader.h"
#include "data/BookmarksData.h"
#include "data/BookmarkData.h"



namespace
{
	static constexpr const auto KEY_ENABLED = "enanbled";
	static constexpr const auto KEY_MARKS = "marks";
	static constexpr const auto KEY_MARK_NAME = "name";
	static constexpr const auto KEY_MARK_ITEM_NAME = "item";
	static constexpr const auto KEY_MARK_MARKS = "marks";

	BookmarkData readMarks(const nlohmann::json& jsMark)
	{
		std::string nameMark = jsMark.at(KEY_MARK_NAME);
		std::string nameBookItem = jsMark.at(KEY_MARK_ITEM_NAME);
		std::vector<BookmarkData> childs;
		if (jsMark.count(KEY_MARK_MARKS))
		{
			const auto& jsChilds = jsMark[KEY_MARK_MARKS];
			if (jsChilds.is_array() && !jsChilds.is_null() && !jsChilds.empty())
			{
				for (const auto& jsChild : jsChilds)
				{
					childs.push_back(readMarks(jsChild));
				}
			}
		}
		return BookmarkData(std::move(nameMark), std::move(nameBookItem), std::move(childs));
	}
} // end namespace



BookmarksDataReader::BookmarksDataReader()
{

}

BookmarksDataReader::~BookmarksDataReader()
{

}

std::shared_ptr<BookmarksData> BookmarksDataReader::read(const nlohmann::json& jsBookmarks) const
{
	std::shared_ptr<BookmarksData> data;
	try
	{
		const bool enabled = jsBookmarks.at(KEY_ENABLED);
		std::vector<BookmarkData> childs;
		if (jsBookmarks.count(KEY_MARKS))
		{
			const auto& jsChilds = jsBookmarks[KEY_MARKS];
			if (jsChilds.is_array() && !jsChilds.is_null() && !jsChilds.empty())
			{
				for (const auto& jsChild : jsChilds)
				{
					childs.push_back(readMarks(jsChild));
				}
			}
		}
		data.reset(new BookmarksData(enabled, std::move(childs)));
	}
	catch (...)
	{
		throw;
	}
	return data;
}
