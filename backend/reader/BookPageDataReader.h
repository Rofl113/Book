#pragma once
#include "IBookPageDataReader.h"




class BookPageDataReader : public IBookPageDataReader
{
public:
	BookPageDataReader();
	virtual ~BookPageDataReader() override;

	virtual IBookDataPage* read(const nlohmann::json& jsPage) const override;
};
