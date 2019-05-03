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

# macro to search throgh directories and subdirectories and
# returns a list of directories consisting files with the asked extention
MACRO(directory_list return_list file_extension)
    FILE(GLOB_RECURSE new_list "*.${file_extension}")
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO(directory_list)

# look up header file directories list and include them
directory_list(HEADERS_LIST "h")
include_directories(${HEADERS_LIST})

# includ all cpp files in the "src" directory to build a static library
FILE(GLOB_RECURSE PERSIANSPH_CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# include all cpp files in the "infile" directory to build executable files in the "bin" directory
FILE(GLOB_RECURSE EXECUTABLE_FILES ${CMAKE_SOURCE_DIR}/infile/*.cpp)
