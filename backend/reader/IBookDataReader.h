#pragma once
#include <memory>
#include <nlohmann/json.hpp>



class BookData;


class IBookDataReader
{
public:
	virtual ~IBookDataReader() = default;

	virtual std::shared_ptr<BookData> read(const nlohmann::json& jsBook) const = 0;
};
