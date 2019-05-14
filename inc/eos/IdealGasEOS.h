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

#ifndef IDEALGASEOS_H
#define IDEALGASEOS_H

#include "EOS.h"

class IdealGasEOS : public EOS
{
public:
  virtual void   PrintName();
  virtual double Pressure (double const & _Cs, double const & _P_ref, double const & _rho, double const & _rho_ref);
  virtual double Cs       (double const & _Cs, double const & _rho, double const & _rho_ref);
  virtual double rho      (double const & _Cs, double const & _P_ref, double const & _pressure, double const & _rho_ref);
};

#endif // IDEALGASEOS_H
