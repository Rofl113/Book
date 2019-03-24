#include "PaginationDataReaderBase.h"
#include "data/PaginationData.h"


namespace
{
	static constexpr const auto KEY_ENABLED = "enanbled";
}

bool PaginationDataReaderBase::readEnabled(const nlohmann::json& jsPagination) const
{
	return jsPagination[KEY_ENABLED];
}
