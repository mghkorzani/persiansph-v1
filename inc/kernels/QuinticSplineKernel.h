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

#ifndef QUINTICSPLINEKERNEL_H
#define QUINTICSPLINEKERNEL_H

#include"Kernel.h"

class QuinticSplineKernel : public Kernel
{
public:
  // constructor
  QuinticSplineKernel();
  // virtual destructor
  virtual ~QuinticSplineKernel();
  // initializer function for the required parameters of the kernel
  virtual void Initialize (u_int dim, double h);
  virtual double KernelValue (const double & q);
  virtual double KernelFirstDerivative (const double & q);
  virtual double KernelSecondDerivative (const double & q);
  virtual double KernelLaplacian (const double & q);
};

#endif // QUINTICSPLINEKERNEL_H
