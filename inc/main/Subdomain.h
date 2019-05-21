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

#ifndef SUBDOMAIN_H
#define SUBDOMAIN_H

#include "EOS.h"
#include "Reg.h"

class Subdomain
{
public:
  // constructor & destructors
  Subdomain();
  ~Subdomain();

  // setter functions
  void Tensile_Instability_Set  (bool _is_active, double _TI_Coef, double _TI_Pow);
  void Shepard_Filter_Set (bool _is_active, uint _Shepard_Period = 40);
  void EOS_Set  (EOS_Name _eos_name, double _Cs, double _P0);

protected:
  // is "tensile instability" option true?
  bool has_TI;
  // required parameters for tensile instability
  double TI_Coef;
  double TI_Pow;

  // is "shepard filter" option true?
  bool has_Shepard;
  // required number of step shepard for shepard filter correction
  uint Shepard_Period;

  // speed of sound
  double Cs;
  // background (reference) pressure for EOS
  double P0;
  // EOS pointer
  EOS * eos;
};

#endif // SUBDOMAIN_H
