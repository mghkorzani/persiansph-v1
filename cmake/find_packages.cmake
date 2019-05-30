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

SET (LIBS     ${LIBS})
SET (MISSING "")

# build a static library from all cpp files in PERSIANSPH_CPP_FILES variable
add_library(persiansph ${PERSIANSPH_CPP_FILES})
SET (LIBS ${LIBS} persiansph)

# searching for GSL library
find_package(GSL REQUIRED)
if(GSL_FOUND)
	INCLUDE_DIRECTORIES (${GSL_INCLUDE_DIRS})
	SET (LIBS ${LIBS} ${GSL_LIBRARIES})
else(GSL_FOUND)
  SET (MISSING " ${MISSING} GSL Library ")
endif(GSL_FOUND)

# searching for OPENMP library
find_package(OpenMP REQUIRED)
if(OPENMP_FOUND)
	# the modern way and old way should be tested
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
	# SET (LIBS ${LIBS} ${OpenMP_CXX_LIBRARIES})
else(OPENMP_FOUND)
  SET (MISSING " ${MISSING} OPENMP Library ")
endif(OPENMP_FOUND)

# path to eigen package. it should be modified later
INCLUDE_DIRECTORIES ("/usr/include/eigen")

# report the missing libraries name
if(MISSING)
	MESSAGE("!!!!!!!!!!!!!!!!!!!!!!!! Missing libraries =${MISSING} !!!!!!!!!!!!!!!!!!!!!!!!!!!!")
endif(MISSING)
