cmake_minimum_required(VERSION 3.2.0)

add_definitions(-Wextra -Wno-unused-parameter)

set(SOURCES
	./Book.cpp
	./BookChapter.cpp
	./BookItem.cpp
	./BookItemRoot.cpp
	./BookPage.cpp
	./PaginationBase.cpp
	./PaginationBookBase.cpp
	./ManagerActionsChapter.cpp
	./ManagerActionsBook.cpp
#	./ManagerActionsBookNew.cpp
)

add_library(Book ${SOURCES})
target_link_libraries(Book BookData)

foreach(file ${SOURCES})
  message(STATUS "file='${file}'")
endforeach()
