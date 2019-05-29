#include "PaginationDataReader.h"
#include "data/PaginationData.h"


PaginationDataReader::PaginationDataReader()
{

}

PaginationDataReader::~PaginationDataReader()
{

}

std::shared_ptr<PaginationData> PaginationDataReader::read(const nlohmann::json& jsPagination) const
{
	std::shared_ptr<PaginationData> data;
	try
	{
		const bool enanbled = this->readEnabled(jsPagination);
		data.reset(new PaginationData(enanbled));
	}
	catch (...)
	{
		throw;
	}
	return data;
}
