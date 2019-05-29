cmake_minimum_required(VERSION 3.2.0)

include_directories(
	../../sub/googletest/googletest/include
	../../backend
	${JSON_INCLUDE_DIRECTORIES}
)

set(SOURCES
	main.cpp
	# Reader
	reader/BookPageDataReaderTest.cpp
	reader/BookChapterDataReaderTest.cpp
	reader/BookDataReaderTest.cpp
	reader/PaginationDataReaderTest.cpp
	reader/PaginationDataBookReaderTest.cpp
	reader/BookmarksDataReaderTest.cpp
	reader/ManagerActionsDataReaderTest.cpp
	# Loader
	loader/BookPageLoaderTest.cpp
	loader/BookChapterLoaderTest.cpp
	loader/BookLoaderTest.cpp
)

add_definitions(-gdwarf-4)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIRECTORY}
	)
add_executable(${BUILD_CONFIG} ${SOURCES})

if(DEBUG_MODE)
	set(GT_LIBS gtestd gtest_maind)
else()
	set(GT_LIBS gtest gtest_main)
endif()

set(BOOK_LIBS BookDataReader BookLoader)

set(LIBS pthread stdc++ m ${GT_LIBS} ${BOOK_LIBS})

target_link_libraries(${BUILD_CONFIG} ${LIBS})
