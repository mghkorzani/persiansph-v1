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

#include "RelativeIdealGasEOS.h"

inline void
RelativeIdealGasEOS::PrintName()
{
  std::cout<<"EOS Type:   Relative Ideal Gas EOS (Cs^2*(rho-rho_ref))"<<std::endl;
}

inline double
RelativeIdealGasEOS::Pressure (double const & _Cs, double const & _P_ref, double const & _rho, double const & _rho_ref)
{
  return _P_ref+gsl_pow_2(_Cs)*(_rho-_rho_ref);
}

inline double
RelativeIdealGasEOS::Cs (double const & _Cs, double const & _rho, double const & _rho_ref)
{
  return _Cs;
}

inline double
RelativeIdealGasEOS::rho (double const & _Cs, double const & _P_ref, double const & _pressure, double const & _rho_ref)
{
  return (_pressure-_P_ref)/gsl_pow_2(_Cs)+_rho_ref;
}
