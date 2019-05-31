cmake_minimum_required(VERSION 3.2.0)

include_directories(
)

if(BUILD_CONFIG STREQUAL "MAIN")
	add_subdirectory(main)

elseif(BUILD_CONFIG STREQUAL "TEST")
	add_subdirectory(test)

else()
	message(FATAL_ERROR "[EE] BUILD_CONFIG UNKNOWN")
endif()
