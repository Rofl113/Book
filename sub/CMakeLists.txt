cmake_minimum_required(VERSION 2.8.12)


#add_subdirectory(json)

if(BUILD_CONFIG STREQUAL "MAIN")

elseif(BUILD_CONFIG STREQUAL "TEST")
	add_subdirectory(googletest)

else()
	message(FATAL_ERROR "[EE] BUILD_CONFIG UNKNOWN")
endif()
