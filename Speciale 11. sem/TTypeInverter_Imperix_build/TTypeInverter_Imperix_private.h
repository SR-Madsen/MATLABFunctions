//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TTypeInverter_Imperix_private.h
//
// Code generated for Simulink model 'TTypeInverter_Imperix'.
// To be implemented on the B-Box RCP or the B-Board PRO.
//
// Model version                  : 14.119
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Dec 21 14:14:34 2022
//
#ifndef RTW_HEADER_TTypeInverter_Imperix_private_h_
#define RTW_HEADER_TTypeInverter_Imperix_private_h_
#include "rtwtypes.h"
#include "TTypeInverter_Imperix.h"
#include "TTypeInverter_Imperix_types.h"

int Can_Write(unsigned int mailbox_id, void* data, int size);
int Eth_Write(unsigned int mailbox_id, void* data, int size);
void Adc_GetPointer(unsigned int input, unsigned int device, int16_T ** pointer);

#include "allIncludes.h"

tUserSafe SimulinkInterrupt(void);
void ConfigureReadTriggerDelayInNs(int);
extern void TTypeInverter_Impe_VariableGain(real32_T rtu_iL, real32_T rtu_e_in,
  real32_T *rty_e_out);
extern void TTypeInverter_Im_MATLABFunction(real32_T rtu_batt_p, real32_T
  rtu_vi_ref, real32_T rtu_batt_n, real32_T *rty_m);
extern void TTypeInverter_Imper_SqrtUsedFcn(const real32_T rtu_u[9], boolean_T
  rtu_isSqrtUsed, real32_T rty_P[9]);
extern void TTypeInv_MeasurementUpdate_Init(real32_T rty_Lykyhatkk1[3],
  P_MeasurementUpdate_TTypeInve_T *localP);
extern void TType_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[3],
  DW_MeasurementUpdate_TTypeInv_T *localDW, P_MeasurementUpdate_TTypeInve_T
  *localP);
extern void TTypeInverter_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[6], const real32_T rtu_yk[2], const real32_T rtu_Ck[6], const real32_T
  rtu_xhatkk1[3], const real32_T rtu_Dk[4], const real32_T rtu_uk[2], real32_T
  rty_Lykyhatkk1[3], DW_MeasurementUpdate_TTypeInv_T *localDW,
  P_MeasurementUpdate_TTypeInve_T *localP);
extern void TTypeInve_EnabledSubsystem_Init(real32_T rty_deltax[3],
  P_EnabledSubsystem_TTypeInver_T *localP);
extern void TTypeI_EnabledSubsystem_Disable(real32_T rty_deltax[3],
  DW_EnabledSubsystem_TTypeInve_T *localDW, P_EnabledSubsystem_TTypeInver_T
  *localP);
extern void TTypeInverter__EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[6], const real32_T rtu_Ck[6], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[3], real32_T rty_deltax[3], DW_EnabledSubsystem_TTypeInve_T
  *localDW, P_EnabledSubsystem_TTypeInver_T *localP);
extern void TTypeInverte_MovingAverage_Init(DW_MovingAverage_TTypeInverte_T
  *localDW);
extern void TTypeInvert_MovingAverage_Start(DW_MovingAverage_TTypeInverte_T
  *localDW);
extern void TTypeInverter_Imp_MovingAverage(real32_T rtu_0,
  B_MovingAverage_TTypeInverter_T *localB, DW_MovingAverage_TTypeInverte_T
  *localDW);
extern void TTypeInverte_MovingAverage_Term(DW_MovingAverage_TTypeInverte_T
  *localDW);

#endif                           // RTW_HEADER_TTypeInverter_Imperix_private_h_

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
