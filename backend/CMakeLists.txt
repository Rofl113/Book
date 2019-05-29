cmake_minimum_required(VERSION 3.2.0)


include_directories(
	./
)

# data
add_subdirectory(data)

# reader
add_subdirectory(reader)

# loader
add_subdirectory(loader)

# book
add_subdirectory(book)
