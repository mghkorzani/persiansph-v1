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

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cassert>

#include "Reg.h"
#include "Subdomain.h"
#include "Array.h"

class Main
{
public:
  // constructor
  Main();
  // virtual destructor
  virtual ~Main();
  // set kernel
  void Kernel_Set(Kernels_Name _kernel_name, uint _dimension, double _smoothing_length);

protected:
  // main kernel to be published
  Kernel * kernel;
  // array of subdomains
  Array_D<Subdomain> subdomains;
  // dimension of problem 2D or 3D - no 1D is implemented
  uint dim;
  // smoothing length for kernel
  double h;
};

#endif // MAIN_H
