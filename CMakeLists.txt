CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT (PersianSPH)

# move all library and executable files to "bin" and ".lib" directories
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/.lib)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)

INCLUDE (${CMAKE_SOURCE_DIR}/cmake/addon.cmake)

# look up header file directories list and include them
directory_list(HEADERS_LIST "h")
include_directories(${HEADERS_LIST})

# building a static library from all cpp files in the "src" directory
FILE(GLOB_RECURSE PERSIANSPH_CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(persiansph ${PERSIANSPH_CPP_FILES})

# include all cpp files in the "infile" directory to build executable files in the "bin" directory
FILE(GLOB_RECURSE EXECUTABLE_FILES ${CMAKE_SOURCE_DIR}/infile/*.cpp)

# build executable files and link them to libraries
FOREACH(var ${EXECUTABLE_FILES})
	GET_FILENAME_COMPONENT(file_name ${var} NAME_WE)
  ADD_EXECUTABLE        (${file_name} ${var})
	target_link_libraries(${file_name} persiansph)
ENDFOREACH(var)
