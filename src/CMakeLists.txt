cmake_minimum_required(VERSION 3.16)

# add the library that runs
add_library(rational_nums
	
		mini-gmp.h
		mini-mpq.h
		exact_double.h
		
		mini-gmp.c
		mini-mpq.c
 )
 
 # list include directories
	target_include_directories(rational_nums
		PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
	)