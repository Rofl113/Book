cmake_minimum_required(VERSION 3.2.0)

add_definitions(-Wextra -Wno-unused-parameter)

set(SOURCES
	./BookData.cpp
	./BookDataChapter.cpp
	./BookDataItem.cpp
	./BookDataPage.cpp
	./PaginationData.cpp
	./PaginationDataBook.cpp
	./BookmarkData.cpp
	./BookmarksData.cpp
	./ManagerActionsData.cpp
)

add_library(BookData ${SOURCES})

