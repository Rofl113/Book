#include "PaginationDataReader.h"
#include "data/PaginationData.h"


PaginationDataReader::PaginationDataReader()
{

}

PaginationDataReader::~PaginationDataReader()
{

}

IPaginationData* PaginationDataReader::read(const nlohmann::json& jsPagination) const
{
	IPaginationData* data = nullptr;
	try
	{
		const bool enanbled = this->readEnabled(jsPagination);
		data = new PaginationData(enanbled);
	}
	catch (...)
	{
		printf("Bad jsPagination: %s", jsPagination.dump().c_str());
		assert(0);
	}
	return data;
}
