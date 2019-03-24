#pragma once
#include "IPaginationDataBookReader.h"
#include "PaginationDataReaderBase.h"



class PaginationDataBookReader : public IPaginationDataBookReader, public PaginationDataReaderBase
{
public:
	PaginationDataBookReader();
	virtual ~PaginationDataBookReader() override;

	virtual PaginationDataBook* read(const nlohmann::json& jsPagination) const override;
};
