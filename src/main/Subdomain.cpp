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

#include "Subdomain.h"

Subdomain::Subdomain()
{}

Subdomain::~Subdomain()
{}

void
Subdomain::Tensile_Instability_Set (bool _is_active, double _initial_distance, double _TI_Coef, double _TI_Pow)
{
    has_TI = _is_active;
    TI_Coef = _TI_Coef;
    TI_Pow = _TI_Pow;
    init_dist = _initial_distance;
}

void
Subdomain::Shepard_Filter_Set (bool _is_active, uint _Shepard_Period)
{
    has_Shepard = _is_active;
    Shepard_Period = _Shepard_Period;
}

void
Subdomain::EOS_Set (EOS_Name _eos_name, double _Cs, double _P0)
{
    eos = Reg::EOSes[_eos_name];
    Cs = _Cs;
    P0 = _P0;
}
