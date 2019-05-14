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

#include "QuinticKernel.h"

QuinticKernel::QuinticKernel()
{
  width = 2.0;
}

inline void
QuinticKernel::Initialize (u_int _dim, double _h)
{
  Kernel::Initialize(_dim, _h);
  dim ==2 ? C = 7.0/(4.0*gsl_pow_2(h)*M_PI) : C = 7.0/(8.0*gsl_pow_3(h)*M_PI);
}

inline void
QuinticKernel::PrintName()
{
  std::cout<<"Kernel Type:   Quintic"<<std::endl;
}

inline double
QuinticKernel::Value (const double & _q)
{
  if (_q>=2.0)  return 0.0;
  else          return C*gsl_pow_4(1.0-_q/2.0)*(2.0*_q+1.0);
}

inline double
QuinticKernel::FirstDerivative (const double & _q)
{
  if (_q>=2.0)  return 0.0;
  else          return -C/h*gsl_pow_3(1.0-_q/2.0)*(5.0*_q+2.0);
}

inline CVec
QuinticKernel::Gradient (const double & _q, const double & _r, const CVec & _x)
{
  if (_q>0.0) return (FirstDerivative (_q)/_r)*_x;
  else        return CVec::Constant(0.0);
}

inline double
QuinticKernel::SecondDerivative (const double & _q)
{
  if (_q>=2.0)  return 0.0;
  else          return C/gsl_pow_2(h)*gsl_pow_2(1.0-_q/2.0)*(10.0*_q-2.0);
}

inline double
QuinticKernel::Laplacian (const double & _q)
{
  return SecondDerivative(_q) - (dim-1.0)*FirstDerivative(_q);
}
