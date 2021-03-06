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

#include "Reg.h"

Array_D<Kernel*>  Reg::Kernels;
Array_D<EOS*>   Reg::EOSes;

void
Reg::Initialiser()
{
    Kernels.push_back (new QubicSplineKernel);
    Kernels.push_back (new QuinticSplineKernel);
    Kernels.push_back (new QuinticKernel);
    
    EOSes.push_back (new RelativeIdealGasEOS);
    EOSes.push_back (new TaitEOS);
    EOSes.push_back (new IdealGasEOS);
}
