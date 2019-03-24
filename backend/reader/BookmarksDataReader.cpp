#include "BookmarksDataReader.h"



namespace
{
	static constexpr const auto KEY_MARKS = "marks";
	static constexpr const auto KEY_MARK_ITEM_NAME = "name";
	static constexpr const auto KEY_MARK_MARKS = "marks";
} // end namespace


BookmarksDataReader::BookmarksDataReader()
{

}

BookmarksDataReader::~BookmarksDataReader()
{

}

IBookmarksData* BookmarksDataReader::read(const nlohmann::json& jsBookmarks) const
{
	IBookmarksData* data = nullptr;
	try
	{
		// Нет пока данных
		data = nullptr;
	}
	catch (...)
	{
		printf("Bad jsBookmarks: %s", jsBookmarks.dump().c_str());
		assert(0);
	}
	return data;
}
