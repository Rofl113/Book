cmake_minimum_required(VERSION 3.2.0)

set(SOURCES
	./BookData.cpp
	./BookDataType.h
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

