#pragma once
#include "IPaginationDataReader.h"
#include "PaginationDataReaderBase.h"



class PaginationDataReader : public IPaginationDataReader, public PaginationDataReaderBase
{
public:
	PaginationDataReader();
	virtual ~PaginationDataReader() override;

	virtual std::shared_ptr<PaginationData> read(const nlohmann::json& jsPagination) const override;
};
