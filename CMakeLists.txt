#####################################################################################
# PersianSPH - Multi-Layered Environment to Simulate Multi-Physical Systems         #
#                using Smoothed Particle Hydrodynamics method                       #
#                                                                                   #
# Copyright (C) 2018 Maziar Gholami Korzani                                         #
#                                                                                   #
# This file is part of PersianSPH                                                   #
#                                                                                   #
# This is free software; you can redistribute it and/or modify it under the         #
# terms of the GNU General Public License as published by the Free Software         #
# Foundation; either version 3 of the License, or (at your option) any later        #
# version.                                                                          #
#                                                                                   #
# This program is distributed in the hope that it will be useful, but WITHOUT ANY   #
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A   #
# PARTICULAR PURPOSE. See the GNU General Public License for more details.          #
#                                                                                   #
# You should have received a copy of the GNU General Public License along with      #
# PersianSPH; if not, see <http://www.gnu.org/licenses/>                            #
#####################################################################################

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
