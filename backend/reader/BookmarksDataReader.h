#pragma once
#include "IBookmarksDataReader.h"



class BookmarksDataReader : public IBookmarksDataReader
{
public:
	BookmarksDataReader();
	virtual ~BookmarksDataReader() override;

	virtual IBookmarksData* read(const nlohmann::json& jsBookmarks) const override;
};
