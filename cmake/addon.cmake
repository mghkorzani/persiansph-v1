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

# options to get user-defined flags for compiler
OPTION(A_MAKE_VERBOSE       "Show additional messages during compilation/linking?" OFF)
OPTION(A_MAKE_ALL_WARNINGS  "Make with all warnings (-Wall)"                       ON )
OPTION(A_MAKE_DEBUG_SYMBOLS "Make with debug symbols (-g)"                         OFF)
OPTION(A_MAKE_OPTIMIZED     "Make optimized (-O3)"                                 ON )

IF(A_MAKE_VERBOSE)
	SET (CMAKE_VERBOSE_MAKEFILE TRUE)
ENDIF(A_MAKE_VERBOSE)

IF(A_MAKE_ALL_WARNINGS)
	ADD_DEFINITIONS (-Wall)
ENDIF(A_MAKE_ALL_WARNINGS)

IF(A_MAKE_DEBUG_SYMBOLS)
	ADD_DEFINITIONS (-g)
ENDIF(A_MAKE_DEBUG_SYMBOLS)

IF(A_MAKE_OPTIMIZED)
	ADD_DEFINITIONS (-O3)
ENDIF(A_MAKE_OPTIMIZED)

# add extra flags for compiler
ADD_DEFINITIONS(-fmessage-length=0)
ADD_DEFINITIONS(-std=c++11)
ADD_DEFINITIONS(-fpermissive)

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
