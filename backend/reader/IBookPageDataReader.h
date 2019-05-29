#pragma once
#include <nlohmann/json.hpp>



class BookDataPage;


class IBookPageDataReader
{
public:
	virtual ~IBookPageDataReader() = default;

	virtual std::shared_ptr<BookDataPage> read(const nlohmann::json& jsPage) const = 0;
};
