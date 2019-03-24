#pragma once
#include <nlohmann/json.hpp>



class IBookDataPage;


class IBookPageDataReader
{
public:
	virtual ~IBookPageDataReader() = default;

	virtual IBookDataPage* read(const nlohmann::json& jsPage) const = 0;
};
