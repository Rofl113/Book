cmake_minimum_required(VERSION 3.2.0)

add_definitions(-Wextra -Wno-unused-parameter)

include_directories(
	${JSON_INCLUDE_DIRECTORIES}
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
	./ManagerActionsDataReader.cpp
)

add_library(BookDataReader ${SOURCES})
target_link_libraries(BookDataReader BookData)

