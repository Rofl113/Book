#pragma once
#include "IBookmarksDataReader.h"



class BookmarksDataReader : public IBookmarksDataReader
{
public:
	BookmarksDataReader();
	virtual ~BookmarksDataReader() override;

	virtual std::shared_ptr<BookmarksData> read(const nlohmann::json& jsBookmarks) const override;
};
