cmake_minimum_required(VERSION 2.8.12)

add_definitions(-Wextra -Wno-unused-parameter)

include_directories(
	${JSON_INCLUDE}
)

set(SOURCES
	./BookChapterDataReader.cpp
	./BookDataReader.cpp
	./BookItemDataReader.cpp
	./BookPageDataReader.cpp
	./BookChapterDataReaderBase.cpp
	./PaginationDataReader.cpp
	./PaginationDataReaderBase.cpp
	./PaginationDataBookReader.cpp
	./BookmarksDataReader.cpp
)

add_library(BookDataReader ${SOURCES})
target_link_libraries(BookDataReader ${JSON_LIB})

