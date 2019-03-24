#pragma once
#include <nlohmann/json.hpp>


class PaginationData;


class PaginationDataReaderBase
{
public:
	bool readEnabled(const nlohmann::json& jsPagination) const;
};
