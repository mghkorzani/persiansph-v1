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

#ifndef KERNEL_H
#define KERNEL_H

#include"MathUtil.h"

class Kernel
{
public:
  // constructor
  Kernel();
  // virtual destructor
  virtual ~Kernel();
  // initializer function for the required parameters of the kernel
  virtual void Initialize (u_int dim, double h);
  virtual double KernelValue (const double & q) = 0;
  virtual double KernelFirstDerivative (const double & q) = 0;
  virtual double KernelSecondDerivative (const double & q) = 0;
  virtual double KernelLaplacian (const double & q) = 0;

protected:
  // dimension of kernel
  u_int _dim;
  // smoothing length
  double _h;
  // constant coefficient of kernel based on dimension of kernel
  double _c;
};

#endif // KERNEL_H
