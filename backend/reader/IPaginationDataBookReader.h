#pragma once
#include <nlohmann/json.hpp>



class PaginationDataBook;


class IPaginationDataBookReader
{
public:
	virtual ~IPaginationDataBookReader() = default;

	virtual PaginationDataBook* read(const nlohmann::json& jsPagination) const = 0;
};
