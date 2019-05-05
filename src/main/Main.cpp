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

#include"Main.h"

Main::Main()
{
  // default assignment of the first kernel in the registered kernel arrays
  // to the kernel pointer
  kernel = RO.Reg_Kernels[0];
}

Main::~Main()
{}

inline void
Main::Kernel_Set(Kernels_Name kernel_name)
{
  kernel = RO.Reg_Kernels[kernel_name];

  kernel->Initialize(3,1.0);
  double i = 0.0;
  while (i<=kernel->width+0.1)
  {
    std::cout<< i <<" , ";
    std::cout<< kernel->Value(i) <<" , ";
    std::cout<< kernel->FirstDerivative(i) <<" , ";
    std::cout<< kernel->SecondDerivative(i) <<" , ";
    std::cout<< kernel->Laplacian(i) <<std::endl;
    i = i + 0.1;
  }
  std::cout<< std::endl;

}
