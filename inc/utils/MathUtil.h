/***********************************************************************************
* PersianSPH - Multi-Layered Environment to Simulate Multi-Physical Systems        *
*                using Smoothed Particle Hydrodynamics method                      *
*                                                                                  *
* Copyright (C) 2018 Maziar Gholami Korzani                                        *
*                                                                                  *
* This file is part of PersianSPH                                                  *
*                                                                                  *
* This is free software; you can redistribute it and/or modify it under the        *
* terms of the GNU General Public License as published by the Free Software        *
* Foundation; either version 3 of the License, or (at your option) any later       *
* version.                                                                         *
*                                                                                  *
* This program is distributed in the hope that it will be useful, but WITHOUT ANY  *
* WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A  *
* PARTICULAR PURPOSE. See the GNU General Public License for more details.         *
*                                                                                  *
* You should have received a copy of the GNU General Public License along with     *
* PersianSPH; if not, see <http://www.gnu.org/licenses/>                           *
************************************************************************************/

#ifndef MATHUTIL_H
#define MATHUTIL_H

// standard c++ libraries
#include <cmath>
#include <iostream>

// including OpenMP library for shared memory parallelization
#include <omp.h>

// Eigen library for matrices and vectors
#include <Eigen/Dense>

// GSL library for math calculations
#include <gsl/gsl_math.h>

typedef unsigned int uint;
/** 3x3 Matrix. */
typedef Eigen::Matrix3d Mat;
/** 3x1 Vector. */
typedef Eigen::Vector3d CVec;
/** 3x1 Vector. */
typedef Eigen::RowVector3d RVec;

#endif // MATHUTIL_H
