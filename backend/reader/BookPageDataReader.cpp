#include "BookPageDataReader.h"
#include "data/BookDataPage.h"


namespace
{
	static constexpr const auto KEY_NAME = "name";
}


BookPageDataReader::BookPageDataReader()
{

}

BookPageDataReader::~BookPageDataReader()
{

}

IBookDataPage* BookPageDataReader::read(const nlohmann::json& jsPage) const
{
	IBookDataPage* data = nullptr;
	try
	{
		const std::string name = jsPage[KEY_NAME];
		data = new BookDataPage(name);
	}
	catch (...)
	{
		printf("Bad json: %s", jsPage.dump().c_str());
		assert(0);
	}
	return data;
}
