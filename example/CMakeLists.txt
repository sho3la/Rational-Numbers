cmake_minimum_required(VERSION 3.16)

set(SOURCE_FILES example.cpp)

add_executable(example ${SOURCE_FILES})

target_link_libraries(example
	PRIVATE
		rational_nums
)