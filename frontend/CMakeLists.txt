cmake_minimum_required(VERSION 2.8.12)

include_directories(
)

if(BUILD_CONFIG STREQUAL "MAIN")
	add_subdirectory(main)

else()
	message(FATAL_ERROR "[EE] BUILD_CONFIG UNKNOWN")
endif()
