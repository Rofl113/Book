cmake_minimum_required(VERSION 2.8.12)

add_definitions(-Wextra -Wno-unused-parameter)

set(SOURCES
	./BookData.cpp
	./BookDataChapter.cpp
	./BookDataItem.cpp
	./BookDataPage.cpp
	./PaginationData.cpp
	./PaginationDataBook.cpp
)

add_library(BookData ${SOURCES})

