cmake_minimum_required(VERSION 3.2.0)

include_directories(
	${JSON_INCLUDE_DIRECTORIES}
)

set(SOURCES
	./BookChapterDataReader.cpp
	./BookDataReader.cpp
	./IBookDataReader.h
	./BookItemDataReader.cpp
	./BookPageDataReader.cpp
	./BookChapterDataReaderBase.cpp
	./PaginationDataReader.cpp
	./PaginationDataReaderBase.cpp
	./PaginationDataBookReader.cpp
	./BookmarksDataReader.cpp
	./ManagerActionsDataReader.cpp
	./IManagerActionsDataReader.h
)

add_library(BookDataReader ${SOURCES})
target_link_libraries(BookDataReader BookData)

