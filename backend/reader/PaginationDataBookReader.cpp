#include "PaginationDataBookReader.h"
#include "data/PaginationDataBook.h"




namespace
{
	static constexpr const auto KEY_GROUPS = "groups";
} // end namespace


PaginationDataBookReader::PaginationDataBookReader()
{

}

PaginationDataBookReader::~PaginationDataBookReader()
{

}

PaginationDataBook* PaginationDataBookReader::read(const nlohmann::json& jsPagination) const
{
	PaginationDataBook* data = nullptr;
	try
	{
		const bool enanbled = this->readEnabled(jsPagination);
		std::map<std::string, std::vector<std::string>> groups;
		if (jsPagination.count(KEY_GROUPS))
		{
			for (const auto& jsIt : jsPagination[KEY_GROUPS].items())
			{
				const std::string group = jsIt.key();
				std::vector<std::string> items = jsIt.value();
				groups[group] = std::move(items);
			}
		}
		data = new PaginationDataBook(enanbled, std::move(groups));
	}
	catch (...)
	{
		printf("Bad jsPagination: %s", jsPagination.dump().c_str());
		assert(0);
	}
	return data;
}
