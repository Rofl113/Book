#pragma once
#include <nlohmann/json.hpp>



class IPaginationData;


class IPaginationDataReader
{
public:
	virtual ~IPaginationDataReader() = default;

	virtual IPaginationData* read(const nlohmann::json& jsPagination) const = 0;
};
