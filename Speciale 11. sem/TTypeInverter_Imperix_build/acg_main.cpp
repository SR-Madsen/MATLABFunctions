//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: acg_main.cpp
//
// Code generated for Simulink model 'TTypeInverter_Imperix'.
// To be implemented on the B-Box RCP or the B-Board PRO.
//
// Model version                  : 14.119
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Dec 21 14:14:34 2022
//
#include "User/user.h"
#include "extern_user.h"
#include "Core/core.h"
#include "TTypeInverter_Imperix.h"

tUserSafe UserInit(void)
{
  TTypeInverter_Imperix_initialize();
  return SAFE;
}

tUserSafe SimulinkInterrupt(void)
{
  TTypeInverter_Imperix_step();
  return SAFE;
}

void UserError(tErrorSource source)
{
}

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
