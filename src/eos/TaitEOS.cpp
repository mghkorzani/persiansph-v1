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

#include"TaitEOS.h"

inline void
TaitEOS::PrintName()
{
  std::cout<<"EOS Type:   Tait EOS"<<std::endl;
}

inline double
TaitEOS::Pressure (double const & _Cs, double const & _P_ref, double const & _rho, double const & _rho_ref)
{
  return _P_ref+(_rho_ref*gsl_pow_2(_Cs)/7.0)*(gsl_pow_7(_rho/_rho_ref)-1.0);
}

inline double
TaitEOS::Cs (double const & _Cs, double const & _rho, double const & _rho_ref)
{
  return _Cs*gsl_pow_3(_rho/_rho_ref);
}

inline double
TaitEOS::rho (double const & _Cs, double const & _P_ref, double const & _pressure, double const & _rho_ref)
{
  // 1/7 is estimated as 0.1428571429
  return _rho_ref*pow( 7.0*(_pressure-_P_ref)/(_rho_ref*gsl_pow_2(_Cs))+1.0 , 0.1428571429);
}
