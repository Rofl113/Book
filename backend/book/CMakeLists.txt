cmake_minimum_required(VERSION 3.2.0)

set(SOURCES
	./Book.h
	./Book.cpp
	./BookChapter.h
	./BookChapter.cpp
	./BookItem.h
	./BookItem.cpp
	./BookItemRoot.h
	./BookItemRoot.cpp
	./BookPage.h
	./BookPage.cpp
	./PaginationBase.h
	./PaginationBase.cpp
	./PaginationBookBase.h
	./PaginationBookBase.cpp
	./ManagerActionsChapter.h
	./ManagerActionsChapter.cpp
	./ManagerActionsBook.h
	./ManagerActionsBook.cpp
	# i
	./IPagination.h
	./IPaginationBook.h
	./IBoxPages.h
	./IBookItem.h
	./IManagerActions.h
	./IBook.h
)

add_library(Book ${SOURCES})
target_link_libraries(Book BookData)
