#pragma once
#include "IPaginationDataBookReader.h"
#include "PaginationDataReaderBase.h"



class PaginationDataBookReader : public IPaginationDataBookReader, public PaginationDataReaderBase
{
public:
	PaginationDataBookReader();
	virtual ~PaginationDataBookReader() override;

	virtual std::shared_ptr<PaginationDataBook> read(const nlohmann::json& jsPagination) const override;
};
