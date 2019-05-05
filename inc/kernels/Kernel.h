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
  virtual void   Initialize (u_int _dim, double _h);
  virtual void   PrintName() = 0;
  // required calculated value based on q
  virtual double Value (const double & _q) = 0;
  virtual double FirstDerivative (const double & _q) = 0;
  virtual CVec   Gradient (const double & _q, const double & _r, const CVec & _x) = 0;
  virtual double SecondDerivative (const double & _q) = 0;
  virtual double Laplacian (const double & _q) = 0;
   // kernel width (based on compactness of a kernel) used for cell searching
   // in linked-list approach
  double width;

protected:
  // dimension of kernel
  u_int dim;
  // smoothing length
  double h;
  // constant coefficient of kernel based on dimension of kernel
  double C;
};

#endif // KERNEL_H
