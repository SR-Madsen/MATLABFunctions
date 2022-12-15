//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TTypeInverter_Imperix_types.h
//
// Code generated for Simulink model 'TTypeInverter_Imperix'.
// To be implemented on the B-Box RCP or the B-Board PRO.
//
// Model version                  : 14.80
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Dec 15 11:55:42 2022
//
#ifndef RTW_HEADER_TTypeInverter_Imperix_types_h_
#define RTW_HEADER_TTypeInverter_Imperix_types_h_
#include "rtwtypes.h"
#ifndef struct_g_dsp_internal_SlidingWindowA_T
#define struct_g_dsp_internal_SlidingWindowA_T

struct g_dsp_internal_SlidingWindowA_T
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[3];
  real32_T pCumRevIndex;
  real32_T pModValueRev;
};

#endif                                // struct_g_dsp_internal_SlidingWindowA_T

#ifndef struct_cell_wrap_TTypeInverter_Imper_T
#define struct_cell_wrap_TTypeInverter_Imper_T

struct cell_wrap_TTypeInverter_Imper_T
{
  uint32_T f1[8];
};

#endif                                // struct_cell_wrap_TTypeInverter_Imper_T

#ifndef struct_dsp_simulink_MovingAverage_TT_T
#define struct_dsp_simulink_MovingAverage_TT_T

struct dsp_simulink_MovingAverage_TT_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_TTypeInverter_Imper_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                // struct_dsp_simulink_MovingAverage_TT_T

// Parameters (default storage)
typedef struct P_TTypeInverter_Imperix_T_ P_TTypeInverter_Imperix_T;

// Forward declaration for rtModel
typedef struct tag_RTM_TTypeInverter_Imperix_T RT_MODEL_TTypeInverter_Imperi_T;

#endif                             // RTW_HEADER_TTypeInverter_Imperix_types_h_

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
