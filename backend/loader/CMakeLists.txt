cmake_minimum_required(VERSION 3.2.0)

add_definitions(-Wextra -Wno-unused-parameter)

set(SOURCES
	./BookChapterLoaderBase.cpp
	./BookChapterLoader.cpp
	./BookLoader.cpp
	./BookPageLoader.cpp
	./BookItemLoader.cpp
)

add_library(BookLoader ${SOURCES})
target_link_libraries(BookLoader BookData Book)

