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

#include"QubicSPLineKernel.h"

QubicSPLineKernel::QubicSPLineKernel()
{
  // Kernel::Kernel();
}
QubicSPLineKernel::~QubicSPLineKernel()
{}
void QubicSPLineKernel::Initialize (u_int dim, double h)
{}
double QubicSPLineKernel::KernelValue (const double & q)
{return 10;}
double QubicSPLineKernel::KernelFirstDerivative (const double & q)
{return 110;}
double QubicSPLineKernel::KernelSecondDerivative (const double & q)
{return 1110;}
double QubicSPLineKernel::KernelLaplacian (const double & q)
{return 1110;}
