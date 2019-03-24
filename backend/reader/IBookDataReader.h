#pragma once
#include <nlohmann/json.hpp>



class IBookData;


class IBookDataReader
{
public:
	virtual ~IBookDataReader() = default;

	virtual IBookData* read(const nlohmann::json& jsBook) const = 0;
};
