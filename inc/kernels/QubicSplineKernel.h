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

#ifndef QUBICSPLINEKERNEL_H
#define QUBICSPLINEKERNEL_H

#include "Kernel.h"

class QubicSplineKernel : public Kernel
{
public:
  QubicSplineKernel();
  virtual void Initialize (u_int _dim, double _h);
  virtual void PrintName();
  virtual double Value (const double & _q);
  virtual double FirstDerivative (const double & _q);
  virtual CVec   Gradient (const double & _q, const double & _r, const CVec & _x);
  virtual double SecondDerivative (const double & _q);
  virtual double Laplacian (const double & _q);
};

#endif // QUBICSPLINEKERNEL_H
