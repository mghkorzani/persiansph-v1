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

QuinticSplineKernel::QuinticSplineKernel()
{
  width = 3.0;
}

void QuinticSplineKernel::Initialize (u_int _dim, double _h)
{
  Kernel::Initialize(_dim, _h);
  dim ==2 ? C = 7.0/(478.0*h*h*PSPH::PI) : C = 1.0/(120.0*h*h*h*PSPH::PI);
}

void QuinticSplineKernel::PrintName()
{
  std::cout<<"Kernel Type:   Quintic Spline"<<std::endl;
}

double QuinticSplineKernel::Value (const double & _q)
{
  if      (_q>=3.0) return 0.0;
  else if (_q> 2.0)	return C*(pow(3.0-_q,5.0));
  else if (_q> 1.0)	return C*(pow(3.0-_q,5.0)-6.0*pow(2.0-_q,5.0));
  else              return C*(pow(3.0-_q,5.0)-6.0*pow(2.0-_q,5.0)+15.0*pow(1.0-_q,5.0));
}

double QuinticSplineKernel::FirstDerivative (const double & _q)
{
  if      (_q>=3.0) return 0.0;
  else if (_q> 2.0)	return C/_q/h/h*(-5.0*pow(3.0-_q,4.0));
  else if (_q> 1.0)	return C/_q/h/h*(-5.0*pow(3.0-_q,4.0)+30.0*pow(2.0-_q,4.0));
  else if (_q> 0.0)	return C/_q/h/h*(-5.0*pow(3.0-_q,4.0)+30.0*pow(2.0-_q,4.0)-75.0*pow(1.0-_q,4.0));
  else              return C/h/h  *(20.0*pow(3.0-_q,3.0)-120.0*pow(2.0-_q,3.0)+300.0*pow(1.0-_q,3.0));
}

double QuinticSplineKernel::SecondDerivative (const double & _q)
{
  if      (_q>=3.0) return 0.0;
  else if (_q> 2.0)	return C/h/h*(20.0*pow(3.0-_q,3.0));
  else if (_q> 1.0)	return C/h/h*(20.0*pow(3.0-_q,3.0)-120.0*pow(2.0-_q,3.0));
  else              return C/h/h*(20.0*pow(3.0-_q,3.0)-120.0*pow(2.0-_q,3.0)+300.0*pow(1.0-_q,3.0));
}

double QuinticSplineKernel::Laplacian (const double & _q)
{
  if      (_q>=3.0) return 0.0;
  else if (_q> 2.0) return C/h/h*((20.0*pow((3.0-_q),3.0)) + (dim-1.0)/_q*(-5.0*pow((3.0-_q),4.0)));
  else if (_q> 1.0) return C/h/h*((20.0*pow((3.0-_q),3.0)-120.0*pow((2-_q),3.0)) + (dim-1.0)/_q*(-5.0*pow((3.0-_q),4.0)+30.0*pow((2.0-_q),4.0)));
  else              return C/h/h*((20.0*pow((3.0-_q),3.0)-120.0*pow((2-_q),3.0)+300.0*pow((1-_q),3.0)) + (dim-1.0)/_q*(-5.0*pow((3.0-_q),4.0)+30.0*pow((2.0-_q),4.0)-75.0*pow((1.0-_q),4.0)));
}
