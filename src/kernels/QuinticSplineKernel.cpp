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

void QuinticSplineKernel::Initialize (u_int _dim, double _h)
{
  Kernel::Initialize(_dim, _h);
}

void QuinticSplineKernel::PrintName()
{
  std::cout<<"Kernel Type:   Quintic Spline"<<std::endl;
}

double QuinticSplineKernel::Value (const double & _q)
{return 20;}
double QuinticSplineKernel::FirstDerivative (const double & _q)
{return 220;}
double QuinticSplineKernel::SecondDerivative (const double & _q)
{return 2220;}
double QuinticSplineKernel::Laplacian (const double & _q)
{return 22220;}
