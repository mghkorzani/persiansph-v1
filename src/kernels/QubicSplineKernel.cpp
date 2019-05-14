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

#include "QubicSplineKernel.h"

QubicSplineKernel::QubicSplineKernel()
{
  width = 2.0;
}

inline void
QubicSplineKernel::Initialize (u_int _dim, double _h)
{
  Kernel::Initialize(_dim, _h);
  dim == 2 ? C = 10.0/(7.0*gsl_pow_2(h)*M_PI) : C = 1.0/(gsl_pow_3(h)*M_PI);
}

inline void
QubicSplineKernel::PrintName()
{
  std::cout<<"Kernel Type:   Qubic Spline"<<std::endl;
}

inline double
QubicSplineKernel::Value (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q>=1.0) return C*0.25*gsl_pow_3(2.0-_q);
  else              return C*(1.0-1.5*gsl_pow_2(_q)+0.75*gsl_pow_3(_q));
}

inline double
QubicSplineKernel::FirstDerivative (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q>=1.0) return C/h*-0.75*gsl_pow_2(2.0-_q);
  else              return C/h*(-3.0*_q+2.25*gsl_pow_2(_q));
}

inline CVec
QubicSplineKernel::Gradient (const double & _q, const double & _r, const CVec & _x)
{
  if (_q>0.0) return (FirstDerivative (_q)/_r)*_x;
  else        return CVec::Constant(0.0);
}

inline double
QubicSplineKernel::SecondDerivative (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q>=1.0) return C/gsl_pow_2(h)*( 3.0-1.5*_q);
  else              return C/gsl_pow_2(h)*(-3.0+4.5*_q);
}

inline double
QubicSplineKernel::Laplacian (const double & _q)
{
  return SecondDerivative(_q) - (dim-1.0)*FirstDerivative(_q);
}
