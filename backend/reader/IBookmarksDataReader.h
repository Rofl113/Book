#pragma once
#include <nlohmann/json.hpp>



class IBookmarksData;


class IBookmarksDataReader
{
public:
	virtual ~IBookmarksDataReader() = default;

	virtual IBookmarksData* read(const nlohmann::json& jsBookmarks) const = 0;
};
