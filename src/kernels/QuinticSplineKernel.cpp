/****************************************set c*******************************************
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

#include"QuinticSplineKernel.h"

QuinticSplineKernel::QuinticSplineKernel()
{
  std::cout<< "QuinticSplineKernel constructor called" <<std::endl;
  // Kernel::Kernel();
}
QuinticSplineKernel::~QuinticSplineKernel()
{}
void QuinticSplineKernel::Initialize (u_int dim, double h)
{}
double QuinticSplineKernel::KernelValue (const double & q)
{return 20;}
double QuinticSplineKernel::KernelFirstDerivative (const double & q)
{return 220;}
double QuinticSplineKernel::KernelSecondDerivative (const double & q)
{return 2220;}
double QuinticSplineKernel::KernelLaplacian (const double & q)
{return 22220;}
