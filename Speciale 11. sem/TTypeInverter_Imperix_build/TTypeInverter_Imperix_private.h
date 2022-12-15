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
// Model version                  : 14.80
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Dec 15 11:55:42 2022
//
#ifndef RTW_HEADER_TTypeInverter_Imperix_private_h_
#define RTW_HEADER_TTypeInverter_Imperix_private_h_
#include "rtwtypes.h"
#include "TTypeInverter_Imperix_types.h"

int Can_Write(unsigned int mailbox_id, void* data, int size);
int Eth_Write(unsigned int mailbox_id, void* data, int size);
void Adc_GetPointer(unsigned int input, unsigned int device, int16_T ** pointer);

#include "allIncludes.h"

tUserSafe SimulinkInterrupt(void);
void ConfigureReadTriggerDelayInNs(int);

#endif                           // RTW_HEADER_TTypeInverter_Imperix_private_h_

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
