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

#include "Main.h"

Main::Main()
{
  // registering of objects in the Reg static class
  Reg::Initialiser();
  // default assignment of the first kernel in the registered kernel arrays
  // to the kernel pointer
  kernel = Reg::Kernels[1];
}

Main::~Main()
{}

void
Main::Kernel_Set(Kernels_Name _kernel_name, uint _dimension, double _smoothing_length)
{
  kernel->PrintName();
  kernel = Reg::Kernels[_kernel_name];

  assert((_dimension == 2 || _dimension == 3) &&
            "Dimesion of the model should be either 2 or 3.");

  kernel->Initialize(_dimension, _smoothing_length);
  dim = _dimension;
  h = _smoothing_length;

  // double i = 0.0;
  // while (i<=kernel->width+0.1)
  // {
  //   std::cout<< i <<" , ";
  //   std::cout<< kernel->Value(i) <<" , ";
  //   std::cout<< kernel->FirstDerivative(i) <<" , ";
  //   std::cout<< kernel->SecondDerivative(i) <<" , ";
  //   std::cout<< kernel->Laplacian(i) <<std::endl;
  //   i = i + 0.1;
  // }
  // std::cout<< std::endl;
}
