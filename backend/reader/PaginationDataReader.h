#pragma once
#include "IPaginationDataReader.h"
#include "PaginationDataReaderBase.h"



class PaginationDataReader : public IPaginationDataReader, public PaginationDataReaderBase
{
public:
	PaginationDataReader();
	virtual ~PaginationDataReader() override;

	virtual IPaginationData* read(const nlohmann::json& jsPagination) const override;
};
