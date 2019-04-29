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
  _kernel = _RO.Reg_Kernels[0];
}

Main::~Main()
{}

void Main::Kernel_Set(Kernels_Name kernel_name)
{
  _kernel = _RO.Reg_Kernels[kernel_name];

    std::cout<< _kernel->KernelValue(10) <<std::endl;
    std::cout<< _kernel->KernelFirstDerivative(10) <<std::endl;
    std::cout<< _kernel->KernelSecondDerivative(10) <<std::endl;
    std::cout<< _kernel->KernelLaplacian(10) <<std::endl;
    std::cout<< "Kernel_Set is printing" <<std::endl;
}
