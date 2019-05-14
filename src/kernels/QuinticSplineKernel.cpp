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

#include "QuinticSplineKernel.h"

QuinticSplineKernel::QuinticSplineKernel()
{
  width = 3.0;
}

inline void
QuinticSplineKernel::Initialize (u_int _dim, double _h)
{
  Kernel::Initialize(_dim, _h);
  dim ==2 ? C = 7.0/(478.0*gsl_pow_2(h)*M_PI) : C = 1.0/(120.0*gsl_pow_3(h)*M_PI);
}

inline void
QuinticSplineKernel::PrintName()
{
  std::cout<<"Kernel Type:   Quintic Spline"<<std::endl;
}

inline double
QuinticSplineKernel::Value (const double & _q)
{
  if      (_q>=3.0) return 0.0;
  else if (_q>=2.0)	return C* gsl_pow_5(3.0-_q);
  else if (_q>=1.0)	return C*(gsl_pow_5(3.0-_q)-6.0*gsl_pow_5(2.0-_q));
  else              return C*(gsl_pow_5(3.0-_q)-6.0*gsl_pow_5(2.0-_q)+15.0*gsl_pow_5(1.0-_q));
}

inline double
QuinticSplineKernel::FirstDerivative (const double & _q)
{
  if      (_q>=3.0) return 0.0;
  else if (_q>=2.0)	return C/h*-5.0* gsl_pow_4(3.0-_q);
  else if (_q>=1.0)	return C/h*-5.0*(gsl_pow_4(3.0-_q)-6.0*gsl_pow_4(2.0-_q));
  else              return C/h*-5.0*(gsl_pow_4(3.0-_q)-6.0*gsl_pow_4(2.0-_q)+15.0*gsl_pow_4(1.0-_q));
}

inline CVec
QuinticSplineKernel::Gradient (const double & _q, const double & _r, const CVec & _x)
{
  if (_q>0.0) return (FirstDerivative (_q)/_r)*_x;
  else        return CVec::Constant(0.0);
}

inline double
QuinticSplineKernel::SecondDerivative (const double & _q)
{
  if      (_q>=3.0) return 0.0;
  else if (_q>=2.0)	return C/gsl_pow_2(h)*20.0* gsl_pow_3(3.0-_q);
  else if (_q>=1.0)	return C/gsl_pow_2(h)*20.0*(gsl_pow_3(3.0-_q)-6.0*gsl_pow_3(2.0-_q));
  else              return C/gsl_pow_2(h)*20.0*(gsl_pow_3(3.0-_q)-6.0*gsl_pow_3(2.0-_q)+15.0*gsl_pow_3(1.0-_q));
}

inline double
QuinticSplineKernel::Laplacian (const double & _q)
{
  return SecondDerivative(_q) - (dim-1.0)*FirstDerivative(_q);
}
