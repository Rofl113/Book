cmake_minimum_required(VERSION 2.8.12)

include_directories(
)

set(SOURCES
	main.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIRECTORY})
add_executable(${BUILD_CONFIG} ${SOURCES})
target_link_libraries(${BUILD_CONFIG} ${LIBS})
