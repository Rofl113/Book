#pragma once
#include <nlohmann/json.hpp>



class BookmarksData;


class IBookmarksDataReader
{
public:
	virtual ~IBookmarksDataReader() = default;

	virtual std::shared_ptr<BookmarksData> read(const nlohmann::json& jsBookmarks) const = 0;
};
