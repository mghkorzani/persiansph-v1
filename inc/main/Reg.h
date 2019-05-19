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

#ifndef REG_H
#define REG_H

#include "Array.h"

// header of all registered kernels
#include "QubicSplineKernel.h"
#include "QuinticSplineKernel.h"
#include "QuinticKernel.h"

// header of all registered EOS
#include "RelativeIdealGasEOS.h"
#include "TaitEOS.h"
#include "IdealGasEOS.h"

class Reg
{
public:
  // all dynamic arrays should be initialised in this function
  // this function is called in the constructor of the Main class
  static void Initialiser();

  // registering kernels
  static Array_D<Kernel*>  Kernels;
  // registering eos
  static Array_D<EOS*>     EOSes;
};

enum Kernels_Name
        {Qubic_Spline = 0 , Quintic_Spline , Quintic};

enum EOS_Name
        {Relative_Ideal_Gas = 0 , Tait , Ideal_Gas};

#endif // REG_H
