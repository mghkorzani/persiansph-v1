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

#include"QuinticKernel.h"

QuinticKernel::QuinticKernel()
{
  width = 2.0;
}

void QuinticKernel::Initialize (u_int _dim, double _h)
{
  Kernel::Initialize(_dim, _h);
  dim ==2 ? C = 7.0/(4.0*h*h*PSPH::PI) : C = 7.0/(8.0*h*h*h*PSPH::PI);
}

void QuinticKernel::PrintName()
{
  std::cout<<"Kernel Type:   Quintic"<<std::endl;
}

double QuinticKernel::Value (const double & _q)
{
  if    (_q>=2.0) return 0.0;
  else            return C*pow((1.0-_q/2.0),4.0)*(2.0*_q+1.0);
}

double QuinticKernel::FirstDerivative (const double & _q)
{
  if      (_q>=2.0) return 0.0;
  else if (_q> 0.0) return -5.0*C/h/h*pow((1.0-_q/2.0),3.0);
  else              return -5.0*C/h/h*(pow((1.0-_q/2.0),3.0)-1.5*_q*pow((1.0-_q/2.0),2.0));
}

double QuinticKernel::SecondDerivative (const double & _q)
{
  if    (_q>=2.0) return 0.0;
  else            return C/h/h*pow((1.0-_q/2.0),2.0)*(10.0*_q-5.0);
}

double QuinticKernel::Laplacian (const double & _q)
{
  if    (_q>=2.0) return 0.0;
  else            return C/h/h*(pow((1.0-_q/2.0),2.0)*(10.0*_q-5.0) + -5.0*(dim-1.0)*pow((1.0-_q/2.0),3.0));
}
