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

#ifndef PARTICLE_H
#define PARTICLE_H

#include "MathUtil.h"
#include "Array.h"

class Particle
{
public:
  Particle();
  ~Particle();
  // particle identification tag number
  uint Tag;
  // particle position vector
  CVec X;
  // particle acceleration vector
  CVec A;
  // array of velocity vectors for using different integration scheme
  Array_D<CVec> V;
  // array of density for using different integration scheme
  Array_D<double> Rho;
  // reference density for using in EOS
  double Rho_Ref;
  // time derivative of density
  double dRho_dt;
  // particle pressure
  double P
  // particle mass
  double M;
  // artificial viscosity coefficients
  double 	Art_Vis_alpha;
  double 	Art_Vis_beta;

  // linked list required variables
  uint Linked_List
  Eigen::Matrix<uint, 3, 1> Cur_Cell;

  // OpenMP lock for each particle
  omp_lock_t particle_lock;
  // initial step indicator for time integrator
  bool Initial_Step;
  // step counter to be used for different integration scheme
  unit Step_Counter;
protected:

};

#endif // PARTICLE_H
