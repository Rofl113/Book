#include "PaginationDataReaderBase.h"
#include "data/PaginationData.h"


namespace
{
	static constexpr const auto KEY_ENABLED = "enanbled";
} // end namespace

bool PaginationDataReaderBase::readEnabled(const nlohmann::json& jsPagination) const
{
	return jsPagination.at(KEY_ENABLED);
}
