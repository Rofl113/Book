#pragma once
#include "IBookPageDataReader.h"




class BookPageDataReader : public IBookPageDataReader
{
public:
	BookPageDataReader();
	virtual ~BookPageDataReader() override;

	virtual std::shared_ptr<BookDataPage> read(const nlohmann::json& jsPage) const override;
};
