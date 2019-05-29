#pragma once
#include <nlohmann/json.hpp>



class PaginationDataBook;


class IPaginationDataBookReader
{
public:
	virtual ~IPaginationDataBookReader() = default;

	virtual std::shared_ptr<PaginationDataBook> read(const nlohmann::json& jsPagination) const = 0;
};
