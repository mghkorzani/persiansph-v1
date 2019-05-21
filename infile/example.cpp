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

#include <iostream>
#include "Main.h"

using namespace std;

int main(int argc, char **argv)
{
    Main Maziar;

    Mat m = Mat::Random();
    RVec a;
    CVec b;
    a = RVec::Constant(1);
    b = CVec::Constant(2);

    std::cout<<m<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<a*m<<std::endl;
    std::cout<<m*b<<std::endl;
    std::cout<<a*b<<std::endl;
    std::cout<<b*a<<std::endl;


    Maziar.Kernel_Set(Qubic_Spline, 3, 1);
    Maziar.Kernel_Set(Quintic, 3, 1);
    Maziar.Kernel_Set(Quintic_Spline, 3, 1);

    return 0;
}
