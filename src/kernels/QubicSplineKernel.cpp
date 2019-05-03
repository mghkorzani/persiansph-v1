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

#include"QubicSplineKernel.h"

QubicSplineKernel::QubicSplineKernel()
{
  width = 2.0;
}

void QubicSplineKernel::Initialize (u_int _dim, double _h)
{
  Kernel::Initialize(_dim, _h);
  dim == 2 ? C = 10.0/(7.0*h*h*PSPH::PI) : C = 1.0/(h*h*h*PSPH::PI);
}

void QubicSplineKernel::PrintName()
{
  std::cout<<"Kernel Type:   Qubic Spline"<<std::endl;
}

double QubicSplineKernel::Value (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q>=1.0) return C*0.25*pow(2.0-_q,3);
  else              return C*(1.0-1.5*_q*_q+0.75*_q*_q*_q);
}

double QubicSplineKernel::FirstDerivative (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q> 1.0) return C/h*-0.75*pow(2.0-_q,2);
  else              return C/h*(-3.0*_q+2.25*_q*_q);
}

double QubicSplineKernel::SecondDerivative (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q> 1.0) return C/h/h*1.5*(2.0-_q);
  else              return C/h/h*(-3.0+4.5*_q);
}

double QubicSplineKernel::Laplacian (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q> 1.0) return C/h/h*(1.5*(2.0-_q) + (dim-1.0)/_q * (-0.75*(2.0-_q)*(2.0-_q)));
  else              return C/h/h*(-3.0+4.5*_q  + (dim-1.0)/_q * (-3.0*_q+2.25*_q*_q));
}
