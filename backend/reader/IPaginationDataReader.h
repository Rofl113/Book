#pragma once
#include <nlohmann/json.hpp>



class PaginationData;


class IPaginationDataReader
{
public:
	virtual ~IPaginationDataReader() = default;

	virtual std::shared_ptr<PaginationData> read(const nlohmann::json& jsPagination) const = 0;
};
