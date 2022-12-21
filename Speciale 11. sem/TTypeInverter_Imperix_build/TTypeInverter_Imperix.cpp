//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TTypeInverter_Imperix.cpp
//
// Code generated for Simulink model 'TTypeInverter_Imperix'.
// To be implemented on the B-Box RCP or the B-Board PRO.
//
// Model version                  : 14.119
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Dec 21 14:14:34 2022
//
#include "TTypeInverter_Imperix.h"
#include "rtwtypes.h"
#include "TTypeInverter_Imperix_types.h"
#include "TTypeInverter_Imperix_private.h"
#include <math.h>

real32_T Batt_P;                       // Probe
real32_T Batt_N;                       // Probe
int16_T* ix_raw_adc_ptr_3_0;
int16_T* ix_raw_adc_ptr_4_0;
real32_T iL_l1;                        // Probe
real32_T vc_l1;                        // Probe
real32_T io_hat_l1;                    // Probe
real32_T vc_hat_l1;                    // Probe
real32_T m_l1;                         // Probe
real32_T iL_hat_l1;                    // Probe
int16_T* ix_raw_adc_ptr_0_0;
int16_T* ix_raw_adc_ptr_5_0;
real32_T Kc_l1;                        // Tunable parameter
real32_T Kp_l1;                        // Tunable parameter
real32_T iL_ref_l1;                    // Probe
real32_T e_iL_l1;                      // Probe
real32_T e_vc_l1;                      // Probe
real32_T vc_ref_l1;                    // Probe
real32_T vi_ref_l1;                    // Probe
real32_T iL_l2;                        // Probe
real32_T vc_l2;                        // Probe
real32_T io_hat_l2;                    // Probe
real32_T vc_hat_l2;                    // Probe
real32_T m_l2;                         // Probe
real32_T iL_hat_l2;                    // Probe
int16_T* ix_raw_adc_ptr_1_0;
int16_T* ix_raw_adc_ptr_6_0;
real32_T Kc_l2;                        // Tunable parameter
real32_T Kp_l2;                        // Tunable parameter
real32_T iL_ref_l2;                    // Probe
real32_T e_iL_l2;                      // Probe
real32_T e_vc_l2;                      // Probe
real32_T vc_ref_l2;                    // Probe
real32_T vi_ref_l2;                    // Probe
real32_T iL_l3;                        // Probe
real32_T vc_l3;                        // Probe
real32_T io_hat_l3;                    // Probe
real32_T vc_hat_l3;                    // Probe
real32_T m_l3;                         // Probe
real32_T iL_hat_l3;                    // Probe
int16_T* ix_raw_adc_ptr_2_0;
int16_T* ix_raw_adc_ptr_7_0;
real32_T Kc_l3;                        // Tunable parameter
real32_T Kp_l3;                        // Tunable parameter
real32_T iL_ref_l3;                    // Probe
real32_T e_iL_l3;                      // Probe
real32_T e_vc_l3;                      // Probe
real32_T vc_ref_l3;                    // Probe
real32_T vi_ref_l3;                    // Probe

// Block signals (default storage)
B_TTypeInverter_Imperix_T TTypeInverter_Imperix_B;

// Block states (default storage)
DW_TTypeInverter_Imperix_T TTypeInverter_Imperix_DW;

// Real-time model
RT_MODEL_TTypeInverter_Imperi_T TTypeInverter_Imperix_M_ =
  RT_MODEL_TTypeInverter_Imperi_T();
RT_MODEL_TTypeInverter_Imperi_T *const TTypeInverter_Imperix_M =
  &TTypeInverter_Imperix_M_;

// Forward declaration for local functions
static void TTypeInverter__SystemCore_setup(dsp_simulink_MovingAverage_TT_T *obj);

//
// Output and update for atomic system:
//    '<S45>/Variable Gain'
//    '<S161>/Variable Gain'
//    '<S277>/Variable Gain'
//
void TTypeInverter_Impe_VariableGain(real32_T rtu_iL, real32_T rtu_e_in,
  real32_T *rty_e_out)
{
  real32_T tmp;

  // MATLAB Function 'Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Variable Gain': '<S59>:1' 
  tmp = static_cast<real32_T>(fabs(static_cast<real_T>(rtu_iL)));
  if (tmp <= 218.0F) {
    // '<S59>:1:4'
    // '<S59>:1:5'
    *rty_e_out = rtu_e_in - rtu_e_in * tmp / 218.0F;
  } else {
    // '<S59>:1:7'
    *rty_e_out = 0.0F;
  }
}

//
// Output and update for atomic system:
//    '<S31>/MATLAB Function'
//    '<S147>/MATLAB Function'
//    '<S263>/MATLAB Function'
//
void TTypeInverter_Im_MATLABFunction(real32_T rtu_batt_p, real32_T rtu_vi_ref,
  real32_T rtu_batt_n, real32_T *rty_m)
{
  // MATLAB Function 'Closed_loop_control/Phase 1 Control/Controllers/MATLAB Function': '<S46>:1' 
  if (rtu_vi_ref > 0.0F) {
    // '<S46>:1:3'
    // '<S46>:1:4'
    *rty_m = rtu_vi_ref / rtu_batt_p;
  } else if (rtu_vi_ref < 0.0F) {
    // '<S46>:1:5'
    // '<S46>:1:6'
    *rty_m = rtu_vi_ref / static_cast<real32_T>(fabs(static_cast<real_T>
      (rtu_batt_n)));
  } else {
    // '<S46>:1:8'
    *rty_m = 0.0F;
  }
}

//
// Output and update for atomic system:
//    '<S124>/SqrtUsedFcn'
//    '<S240>/SqrtUsedFcn'
//    '<S356>/SqrtUsedFcn'
//
void TTypeInverter_Imper_SqrtUsedFcn(const real32_T rtu_u[9], boolean_T
  rtu_isSqrtUsed, real32_T rty_P[9])
{
  // MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S125>:1' 
  if (rtu_isSqrtUsed) {
    // '<S125>:1:4'
    // '<S125>:1:5'
    for (int32_T i = 0; i < 3; i++) {
      for (int32_T i_0 = 0; i_0 < 3; i_0++) {
        int32_T tmp;
        tmp = 3 * i_0 + i;
        rty_P[tmp] = 0.0F;
        rty_P[tmp] += rtu_u[i] * rtu_u[i_0];
        rty_P[tmp] += rtu_u[i + 3] * rtu_u[i_0 + 3];
        rty_P[tmp] += rtu_u[i + 6] * rtu_u[i_0 + 6];
      }
    }
  } else {
    // '<S125>:1:7'
    for (int32_T i = 0; i < 9; i++) {
      rty_P[i] = rtu_u[i];
    }
  }
}

//
// System initialize for enable system:
//    '<S97>/MeasurementUpdate'
//    '<S213>/MeasurementUpdate'
//    '<S329>/MeasurementUpdate'
//
void TTypeInv_MeasurementUpdate_Init(real32_T rty_Lykyhatkk1[3],
  P_MeasurementUpdate_TTypeInve_T *localP)
{
  // SystemInitialize for Outport: '<S126>/L*(y[k]-yhat[k|k-1])'
  rty_Lykyhatkk1[0] = localP->Lykyhatkk1_Y0;
  rty_Lykyhatkk1[1] = localP->Lykyhatkk1_Y0;
  rty_Lykyhatkk1[2] = localP->Lykyhatkk1_Y0;
}

//
// Disable for enable system:
//    '<S97>/MeasurementUpdate'
//    '<S213>/MeasurementUpdate'
//    '<S329>/MeasurementUpdate'
//
void TType_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[3],
  DW_MeasurementUpdate_TTypeInv_T *localDW, P_MeasurementUpdate_TTypeInve_T
  *localP)
{
  // Outputs for Enabled SubSystem: '<S97>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S126>/Enable'

  // Disable for Outport: '<S126>/L*(y[k]-yhat[k|k-1])'
  rty_Lykyhatkk1[0] = localP->Lykyhatkk1_Y0;
  rty_Lykyhatkk1[1] = localP->Lykyhatkk1_Y0;
  rty_Lykyhatkk1[2] = localP->Lykyhatkk1_Y0;

  // End of Outputs for SubSystem: '<S97>/MeasurementUpdate'
  localDW->MeasurementUpdate_MODE = false;
}

//
// Output and update for enable system:
//    '<S97>/MeasurementUpdate'
//    '<S213>/MeasurementUpdate'
//    '<S329>/MeasurementUpdate'
//
void TTypeInverter_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[6], const real32_T rtu_yk[2], const real32_T rtu_Ck[6], const real32_T
  rtu_xhatkk1[3], const real32_T rtu_Dk[4], const real32_T rtu_uk[2], real32_T
  rty_Lykyhatkk1[3], DW_MeasurementUpdate_TTypeInv_T *localDW,
  P_MeasurementUpdate_TTypeInve_T *localP)
{
  real32_T rtu_yk_0[2];

  // Outputs for Enabled SubSystem: '<S97>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S126>/Enable'

  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;
    for (int32_T i = 0; i < 2; i++) {
      // Sum: '<S126>/Sum' incorporates:
      //   Product: '<S126>/C[k]*xhat[k|k-1]'
      //   Product: '<S126>/D[k]*u[k]'
      //   Sum: '<S126>/Add1'

      rtu_yk_0[i] = rtu_yk[i] - (((rtu_Ck[i + 2] * rtu_xhatkk1[1] + rtu_Ck[i] *
        rtu_xhatkk1[0]) + rtu_Ck[i + 4] * rtu_xhatkk1[2]) + (rtu_Dk[i + 2] *
        rtu_uk[1] + rtu_Dk[i] * rtu_uk[0]));
    }

    // Product: '<S126>/Product3'
    for (int32_T i = 0; i < 3; i++) {
      rty_Lykyhatkk1[i] = 0.0F;
      rty_Lykyhatkk1[i] += rtu_Lk[i] * rtu_yk_0[0];
      rty_Lykyhatkk1[i] += rtu_Lk[i + 3] * rtu_yk_0[1];
    }

    // End of Product: '<S126>/Product3'
  } else if (localDW->MeasurementUpdate_MODE) {
    TType_MeasurementUpdate_Disable(rty_Lykyhatkk1, localDW, localP);
  }

  // End of Outputs for SubSystem: '<S97>/MeasurementUpdate'
}

//
// System initialize for enable system:
//    '<S103>/Enabled Subsystem'
//    '<S219>/Enabled Subsystem'
//    '<S335>/Enabled Subsystem'
//
void TTypeInve_EnabledSubsystem_Init(real32_T rty_deltax[3],
  P_EnabledSubsystem_TTypeInver_T *localP)
{
  // SystemInitialize for Outport: '<S128>/deltax'
  rty_deltax[0] = localP->deltax_Y0;
  rty_deltax[1] = localP->deltax_Y0;
  rty_deltax[2] = localP->deltax_Y0;
}

//
// Disable for enable system:
//    '<S103>/Enabled Subsystem'
//    '<S219>/Enabled Subsystem'
//    '<S335>/Enabled Subsystem'
//
void TTypeI_EnabledSubsystem_Disable(real32_T rty_deltax[3],
  DW_EnabledSubsystem_TTypeInve_T *localDW, P_EnabledSubsystem_TTypeInver_T
  *localP)
{
  // Outputs for Enabled SubSystem: '<S103>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S128>/Enable'

  // Disable for Outport: '<S128>/deltax'
  rty_deltax[0] = localP->deltax_Y0;
  rty_deltax[1] = localP->deltax_Y0;
  rty_deltax[2] = localP->deltax_Y0;

  // End of Outputs for SubSystem: '<S103>/Enabled Subsystem'
  localDW->EnabledSubsystem_MODE = false;
}

//
// Output and update for enable system:
//    '<S103>/Enabled Subsystem'
//    '<S219>/Enabled Subsystem'
//    '<S335>/Enabled Subsystem'
//
void TTypeInverter__EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[6], const real32_T rtu_Ck[6], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[3], real32_T rty_deltax[3], DW_EnabledSubsystem_TTypeInve_T
  *localDW, P_EnabledSubsystem_TTypeInver_T *localP)
{
  real32_T rtu_yk_0[2];

  // Outputs for Enabled SubSystem: '<S103>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S128>/Enable'

  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    // Sum: '<S128>/Add1' incorporates:
    //   Product: '<S128>/Product'

    for (int32_T i = 0; i < 2; i++) {
      rtu_yk_0[i] = rtu_yk[i] - ((rtu_Ck[i + 2] * rtu_xhatkk1[1] + rtu_Ck[i] *
        rtu_xhatkk1[0]) + rtu_Ck[i + 4] * rtu_xhatkk1[2]);
    }

    // End of Sum: '<S128>/Add1'

    // Product: '<S128>/Product2'
    for (int32_T i = 0; i < 3; i++) {
      rty_deltax[i] = 0.0F;
      rty_deltax[i] += rtu_Mk[i] * rtu_yk_0[0];
      rty_deltax[i] += rtu_Mk[i + 3] * rtu_yk_0[1];
    }

    // End of Product: '<S128>/Product2'
  } else if (localDW->EnabledSubsystem_MODE) {
    TTypeI_EnabledSubsystem_Disable(rty_deltax, localDW, localP);
  }

  // End of Outputs for SubSystem: '<S103>/Enabled Subsystem'
}

static void TTypeInverter__SystemCore_setup(dsp_simulink_MovingAverage_TT_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

// System initialize for atomic system:
void TTypeInverte_MovingAverage_Init(DW_MovingAverage_TTypeInverte_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  // InitializeConditions for MATLABSystem: '<S32>/Moving Average'
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0F;
    obj->pCumSumRev[0] = 0.0F;
    obj->pCumSumRev[1] = 0.0F;
    obj->pCumSumRev[2] = 0.0F;
    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
  }

  // End of InitializeConditions for MATLABSystem: '<S32>/Moving Average'
}

// Start for atomic system:
void TTypeInvert_MovingAverage_Start(DW_MovingAverage_TTypeInverte_T *localDW)
{
  // Start for MATLABSystem: '<S32>/Moving Average'
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.FrameLength = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  TTypeInverter__SystemCore_setup(&localDW->obj);
}

// Output and update for atomic system:
void TTypeInverter_Imp_MovingAverage(real32_T rtu_0,
  B_MovingAverage_TTypeInverter_T *localB, DW_MovingAverage_TTypeInverte_T
  *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real32_T csumrev[3];
  real32_T csum;
  real32_T cumRevIndex;
  real32_T modValueRev;
  real32_T z;

  // MATLABSystem: '<S32>/Moving Average'
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0F;
    obj->pCumSumRev[0] = 0.0F;
    obj->pCumSumRev[1] = 0.0F;
    obj->pCumSumRev[2] = 0.0F;
    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0F;
    obj->pCumSumRev[0] = 0.0F;
    obj->pCumSumRev[1] = 0.0F;
    obj->pCumSumRev[2] = 0.0F;
    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  csumrev[0] = obj->pCumSumRev[0];
  csumrev[1] = obj->pCumSumRev[1];
  csumrev[2] = obj->pCumSumRev[2];
  modValueRev = obj->pModValueRev;
  z = 0.0F;

  // MATLABSystem: '<S32>/Moving Average'
  localB->MovingAverage = 0.0F;

  // MATLABSystem: '<S32>/Moving Average'
  csum += rtu_0;
  if (modValueRev == 0.0F) {
    z = csumrev[static_cast<int32_T>(cumRevIndex) - 1] + csum;
  }

  csumrev[static_cast<int32_T>(cumRevIndex) - 1] = rtu_0;
  if (cumRevIndex != 3.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    csumrev[1] += csumrev[2];
    csumrev[0] += csumrev[1];
  }

  if (modValueRev == 0.0F) {
    // MATLABSystem: '<S32>/Moving Average'
    localB->MovingAverage = z / 4.0F;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = csumrev[0];
  obj->pCumSumRev[1] = csumrev[1];
  obj->pCumSumRev[2] = csumrev[2];
  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0F) {
    obj->pModValueRev = modValueRev - 1.0F;
  } else {
    obj->pModValueRev = 0.0F;
  }
}

// Termination for atomic system:
void TTypeInverte_MovingAverage_Term(DW_MovingAverage_TTypeInverte_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  // Terminate for MATLABSystem: '<S32>/Moving Average'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
      localDW->obj.FrameLength = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S32>/Moving Average'
}

// Model step function
void TTypeInverter_Imperix_step(void)
{
  // local block i/o variables
  real32_T rtb_io;
  real32_T rtb_io_c;
  real32_T rtb_io_i;
  real_T rtb_Add;
  real32_T rtb_Conversion_pm[9];
  real32_T rtb_P_m[9];
  real32_T rtb_Conversion[6];
  real32_T tmp[3];
  real32_T tmp_0[3];
  real32_T tmp_1[3];
  real32_T tmp_2[3];
  real32_T rtb_Reshapeu[2];
  real32_T rtb_Reshapeu_m[2];
  real32_T rtb_Reshapey[2];
  real32_T rtb_Reshapey_i[2];
  real32_T GIDifferentiator_tmp;
  real32_T GIDifferentiator_tmp_m;
  real32_T rtb_Add_o;
  real32_T rtb_Bkuk_idx_0;
  real32_T rtb_Bkuk_idx_1;
  real32_T rtb_Bkuk_idx_2;
  real32_T rtb_e_out_e;
  real32_T rtb_e_out_g;
  real32_T rtb_en;
  real32_T rtb_en_e;
  real32_T rtb_yn1;
  real32_T rtb_yn1_a;
  real32_T rtb_yn1_bk;
  real32_T rtb_yn1_c3;
  real32_T rtb_yn1_d;
  real32_T rtb_yn1_e;
  real32_T rtb_yn1_e2w;
  real32_T rtb_yn1_ge;
  real32_T rtb_yn1_in;
  real32_T rtb_yn1_j;
  real32_T rtb_yn1_k;
  real32_T rtb_yn1_kz;
  real32_T rtb_yn1_nd;
  real32_T rtb_yn1_nk;

  // S-Function (PROBE): '<S378>/S-Function'
  Batt_P = TTypeInverter_Imperix_B.ADC;

  // S-Function (PROBE): '<S380>/S-Function'
  Batt_N = TTypeInverter_Imperix_B.ADC_l;

  // S-Function (ADC): '<S15>/ADC'
  TTypeInverter_Imperix_B.ADC = (float)(*ix_raw_adc_ptr_3_0) * 0.012451F + 0.0F;

  // S-Function (ADC): '<S17>/ADC'
  TTypeInverter_Imperix_B.ADC_l = (float)(*ix_raw_adc_ptr_4_0) * 0.012451F +
    0.0F;

  // Saturate: '<S19>/Saturation'
  if (TTypeInverter_Imperix_P.Saturation_UpperSat < 0.0F) {
    // Saturate: '<S19>/Saturation'
    TTypeInverter_Imperix_B.Saturation =
      TTypeInverter_Imperix_P.Saturation_UpperSat;
  } else if (TTypeInverter_Imperix_P.Saturation_LowerSat > 0.0F) {
    // Saturate: '<S19>/Saturation'
    TTypeInverter_Imperix_B.Saturation =
      TTypeInverter_Imperix_P.Saturation_LowerSat;
  } else {
    // Saturate: '<S19>/Saturation'
    TTypeInverter_Imperix_B.Saturation = 0.0F;
  }

  // End of Saturate: '<S19>/Saturation'
  // S-Function (PROBE): '<S134>/S-Function'
  iL_l1 = TTypeInverter_Imperix_B.ADC_h;

  // S-Function (PROBE): '<S136>/S-Function'
  vc_l1 = TTypeInverter_Imperix_B.ADC_j;

  // S-Function (PROBE): '<S138>/S-Function'
  io_hat_l1 = TTypeInverter_Imperix_B.io_hat;

  // S-Function (PROBE): '<S140>/S-Function'
  vc_hat_l1 = TTypeInverter_Imperix_B.Product[1];

  // S-Function (PROBE): '<S142>/S-Function'
  m_l1 = TTypeInverter_Imperix_B.m_c;

  // S-Function (PROBE): '<S144>/S-Function'
  iL_hat_l1 = TTypeInverter_Imperix_B.Product[0];

  // S-Function (ADC): '<S42>/ADC'
  TTypeInverter_Imperix_B.ADC_j = (float)(*ix_raw_adc_ptr_0_0) * 0.012451F +
    0.0F;

  // S-Function (ADC): '<S44>/ADC'
  TTypeInverter_Imperix_B.ADC_h = (float)(*ix_raw_adc_ptr_5_0) * 0.0066763F +
    0.0F;

  // DataTypeConversion: '<S120>/Conversion' incorporates:
  //   Constant: '<S77>/KalmanGainM'

  for (int32_T i = 0; i < 6; i++) {
    rtb_Conversion[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.KalmanGainM_Value[i]);
  }

  // End of DataTypeConversion: '<S120>/Conversion'

  // Reshape: '<S76>/Reshapey'
  rtb_Reshapey[0] = TTypeInverter_Imperix_B.ADC_h;
  rtb_Reshapey[1] = TTypeInverter_Imperix_B.ADC_j;

  // Delay: '<S76>/MemoryX' incorporates:
  //   Constant: '<S76>/X0'

  if (TTypeInverter_Imperix_DW.icLoad) {
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[0] =
      TTypeInverter_Imperix_P.X0_Value[0];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[1] =
      TTypeInverter_Imperix_P.X0_Value[1];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[2] =
      TTypeInverter_Imperix_P.X0_Value[2];
  }

  // Outputs for Enabled SubSystem: '<S103>/Enabled Subsystem'
  // Constant: '<S76>/Enable' incorporates:
  //   Constant: '<S76>/C'
  //   Delay: '<S76>/MemoryX'

  TTypeInverter__EnabledSubsystem(TTypeInverter_Imperix_P.Enable_Value,
    rtb_Conversion, TTypeInverter_Imperix_P.C_Value, rtb_Reshapey,
    TTypeInverter_Imperix_DW.MemoryX_DSTATE, TTypeInverter_Imperix_B.Product2_d,
    &TTypeInverter_Imperix_DW.EnabledSubsystem,
    &TTypeInverter_Imperix_P.EnabledSubsystem);

  // End of Outputs for SubSystem: '<S103>/Enabled Subsystem'

  // Sum: '<S103>/Add' incorporates:
  //   Delay: '<S76>/MemoryX'

  rtb_Bkuk_idx_0 = TTypeInverter_Imperix_B.Product2_d[0] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[0];
  rtb_Bkuk_idx_1 = TTypeInverter_Imperix_B.Product2_d[1] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[1];
  rtb_Bkuk_idx_2 = TTypeInverter_Imperix_B.Product2_d[2] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[2];
  for (int32_T i = 0; i < 2; i++) {
    // Product: '<S78>/Product' incorporates:
    //   Constant: '<S76>/C'

    TTypeInverter_Imperix_B.Product[i] = 0.0F;
    TTypeInverter_Imperix_B.Product[i] += TTypeInverter_Imperix_P.C_Value[i] *
      rtb_Bkuk_idx_0;
    TTypeInverter_Imperix_B.Product[i] += TTypeInverter_Imperix_P.C_Value[i + 2]
      * rtb_Bkuk_idx_1;
    TTypeInverter_Imperix_B.Product[i] += TTypeInverter_Imperix_P.C_Value[i + 4]
      * rtb_Bkuk_idx_2;
  }

  // S-Function (TUNABLE_PARAM): '<S61>/S-Function'
  TTypeInverter_Imperix_B.SFunction = Kc_l1;

  // Sum: '<S32>/Subtract2'
  TTypeInverter_Imperix_B.io_hat = rtb_Bkuk_idx_0 - rtb_Bkuk_idx_2;

  // S-Function (TUNABLE_PARAM): '<S75>/S-Function'
  TTypeInverter_Imperix_B.SFunction_b = Kp_l1;

  // Sin: '<S31>/Sine Wave'
  if (TTypeInverter_Imperix_DW.systemEnable != 0) {
    rtb_Add = TTypeInverter_Imperix_P.f_o * 2.0 * 3.1415926535897931 *
      (((TTypeInverter_Imperix_M->Timing.clockTick0+
         TTypeInverter_Imperix_M->Timing.clockTickH0* 4294967296.0)) *
       1.0416000368143116E-5);
    TTypeInverter_Imperix_DW.lastSin = sin(rtb_Add);
    TTypeInverter_Imperix_DW.lastCos = cos(rtb_Add);
    TTypeInverter_Imperix_DW.systemEnable = 0;
  }

  rtb_Add = ((TTypeInverter_Imperix_DW.lastSin *
              TTypeInverter_Imperix_P.SineWave_PCos +
              TTypeInverter_Imperix_DW.lastCos *
              TTypeInverter_Imperix_P.SineWave_PSin) *
             TTypeInverter_Imperix_P.SineWave_HCos +
             (TTypeInverter_Imperix_DW.lastCos *
              TTypeInverter_Imperix_P.SineWave_PCos -
              TTypeInverter_Imperix_DW.lastSin *
              TTypeInverter_Imperix_P.SineWave_PSin) *
             TTypeInverter_Imperix_P.SineWave_Hsin) *
    TTypeInverter_Imperix_P.Vout_amp + TTypeInverter_Imperix_P.SineWave_Bias;

  // End of Sin: '<S31>/Sine Wave'

  // Sum: '<S31>/Sum' incorporates:
  //   DataTypeConversion: '<S31>/Data Type Conversion'

  TTypeInverter_Imperix_B.e_vc = static_cast<real32_T>(rtb_Add) -
    TTypeInverter_Imperix_B.Product[1];

  // Sum: '<S72>/Sum' incorporates:
  //   Delay: '<S72>/Delay1'
  //   Gain: '<S72>/Klim'

  rtb_en = TTypeInverter_Imperix_B.e_vc - TTypeInverter_Imperix_P.Klim *
    TTypeInverter_Imperix_DW.Delay1_DSTATE;

  // Delay: '<S72>/Delay4'
  rtb_yn1 = TTypeInverter_Imperix_DW.Delay4_DSTATE;

  // Gain: '<S72>/1//b0' incorporates:
  //   Delay: '<S72>/Delay3'
  //   Delay: '<S72>/Delay4'
  //   Delay: '<S72>/Delay5'
  //   Gain: '<S72>/a0'
  //   Gain: '<S72>/a1'
  //   Gain: '<S72>/b1'
  //   Gain: '<S72>/b2'
  //   Sum: '<S72>/Sum3'
  //   Sum: '<S72>/Sum4'
  //   Sum: '<S72>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE = ((TTypeInverter_Imperix_P.a0_Gain *
    rtb_en - TTypeInverter_Imperix_P.a1_Gain *
    TTypeInverter_Imperix_DW.Delay3_DSTATE) + (TTypeInverter_Imperix_P.b1_Gain *
    TTypeInverter_Imperix_DW.Delay4_DSTATE - TTypeInverter_Imperix_P.b2_Gain *
    TTypeInverter_Imperix_DW.Delay5_DSTATE)) * TTypeInverter_Imperix_P.ub0_Gain;

  // Sum: '<S53>/Add' incorporates:
  //   Product: '<S53>/Product'

  rtb_Add_o = TTypeInverter_Imperix_B.SFunction_b * TTypeInverter_Imperix_B.e_vc
    + TTypeInverter_Imperix_DW.Delay4_DSTATE;

  // Saturate: '<S53>/Saturation'
  if (rtb_Add_o > TTypeInverter_Imperix_P.pr_sat_val) {
    // Saturate: '<S53>/Saturation'
    TTypeInverter_Imperix_B.Saturation_c = TTypeInverter_Imperix_P.pr_sat_val;
  } else if (rtb_Add_o < TTypeInverter_Imperix_P.Saturation_LowerSat_a) {
    // Saturate: '<S53>/Saturation'
    TTypeInverter_Imperix_B.Saturation_c =
      TTypeInverter_Imperix_P.Saturation_LowerSat_a;
  } else {
    // Saturate: '<S53>/Saturation'
    TTypeInverter_Imperix_B.Saturation_c = rtb_Add_o;
  }

  // End of Saturate: '<S53>/Saturation'

  // Sum: '<S31>/Sum3' incorporates:
  //   Sum: '<S31>/Sum1'

  TTypeInverter_Imperix_B.e_iL = (TTypeInverter_Imperix_B.io_hat +
    TTypeInverter_Imperix_B.Saturation_c) - TTypeInverter_Imperix_B.Product[0];

  // MATLAB Function: '<S45>/Variable Gain'
  TTypeInverter_Impe_VariableGain(TTypeInverter_Imperix_B.Product[0],
    TTypeInverter_Imperix_B.e_iL, &rtb_e_out_g);

  // Delay: '<S56>/Delay4'
  rtb_yn1_d = TTypeInverter_Imperix_DW.Delay4_DSTATE_e;

  // Gain: '<S56>/1//b0' incorporates:
  //   Delay: '<S56>/Delay3'
  //   Delay: '<S56>/Delay4'
  //   Delay: '<S56>/Delay5'
  //   Gain: '<S56>/a0'
  //   Gain: '<S56>/a1'
  //   Gain: '<S56>/b1'
  //   Gain: '<S56>/b2'
  //   Sum: '<S56>/Sum3'
  //   Sum: '<S56>/Sum4'
  //   Sum: '<S56>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_e = ((TTypeInverter_Imperix_P.a0_Gain_j
    * rtb_e_out_g - TTypeInverter_Imperix_P.a1_Gain_o *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_o) +
    (TTypeInverter_Imperix_P.b1_Gain_o *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_e -
     TTypeInverter_Imperix_P.b2_Gain_c *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_b)) *
    TTypeInverter_Imperix_P.ub0_Gain_m;

  // Delay: '<S57>/Delay4'
  rtb_yn1_in = TTypeInverter_Imperix_DW.Delay4_DSTATE_d;

  // Gain: '<S57>/1//b0' incorporates:
  //   Delay: '<S57>/Delay3'
  //   Delay: '<S57>/Delay4'
  //   Delay: '<S57>/Delay5'
  //   Gain: '<S57>/a0'
  //   Gain: '<S57>/a1'
  //   Gain: '<S57>/b1'
  //   Gain: '<S57>/b2'
  //   Sum: '<S57>/Sum3'
  //   Sum: '<S57>/Sum4'
  //   Sum: '<S57>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_d = ((TTypeInverter_Imperix_P.a0_Gain_m
    * rtb_e_out_g - TTypeInverter_Imperix_P.a1_Gain_k *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_p) +
    (TTypeInverter_Imperix_P.b1_Gain_i *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_d -
     TTypeInverter_Imperix_P.b2_Gain_a *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_f)) *
    TTypeInverter_Imperix_P.ub0_Gain_p;

  // Delay: '<S54>/Delay4'
  rtb_yn1_e2w = TTypeInverter_Imperix_DW.Delay4_DSTATE_dg;

  // Gain: '<S54>/1//b0' incorporates:
  //   Delay: '<S54>/Delay3'
  //   Delay: '<S54>/Delay4'
  //   Delay: '<S54>/Delay5'
  //   Gain: '<S54>/a0'
  //   Gain: '<S54>/a1'
  //   Gain: '<S54>/b1'
  //   Gain: '<S54>/b2'
  //   Sum: '<S54>/Sum3'
  //   Sum: '<S54>/Sum4'
  //   Sum: '<S54>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dg =
    ((TTypeInverter_Imperix_P.a0_Gain_b * rtb_e_out_g -
      TTypeInverter_Imperix_P.a1_Gain_c *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_pn) +
     (TTypeInverter_Imperix_P.b1_Gain_p *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_dg -
      TTypeInverter_Imperix_P.b2_Gain_p *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_a)) *
    TTypeInverter_Imperix_P.ub0_Gain_mq;

  // Delay: '<S55>/Delay4'
  rtb_yn1_ge = TTypeInverter_Imperix_DW.Delay4_DSTATE_dh;

  // Gain: '<S55>/1//b0' incorporates:
  //   Delay: '<S55>/Delay3'
  //   Delay: '<S55>/Delay4'
  //   Delay: '<S55>/Delay5'
  //   Gain: '<S55>/a0'
  //   Gain: '<S55>/a1'
  //   Gain: '<S55>/b1'
  //   Gain: '<S55>/b2'
  //   Sum: '<S55>/Sum3'
  //   Sum: '<S55>/Sum4'
  //   Sum: '<S55>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dh =
    ((TTypeInverter_Imperix_P.a0_Gain_g * rtb_e_out_g -
      TTypeInverter_Imperix_P.a1_Gain_op *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_b) +
     (TTypeInverter_Imperix_P.b1_Gain_l *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_dh -
      TTypeInverter_Imperix_P.b2_Gain_j *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_l)) *
    TTypeInverter_Imperix_P.ub0_Gain_k;

  // Sum: '<S31>/Sum2' incorporates:
  //   Gain: '<S31>/Gain1'
  //   Product: '<S45>/P Controller'
  //   Sum: '<S45>/Add'

  TTypeInverter_Imperix_B.Switch2 = (((((TTypeInverter_Imperix_B.SFunction *
    rtb_e_out_g + TTypeInverter_Imperix_DW.Delay4_DSTATE_e) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_d) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_dg) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_dh) + TTypeInverter_Imperix_P.R_Lc *
    TTypeInverter_Imperix_B.Product[0]) + TTypeInverter_Imperix_B.Product[1];

  // Switch: '<S52>/Switch2' incorporates:
  //   RelationalOperator: '<S52>/LowerRelop1'
  //   RelationalOperator: '<S52>/UpperRelop'
  //   Switch: '<S52>/Switch'

  if (TTypeInverter_Imperix_B.Switch2 > TTypeInverter_Imperix_B.ADC) {
    // Sum: '<S31>/Sum2' incorporates:
    //   Switch: '<S52>/Switch2'

    TTypeInverter_Imperix_B.Switch2 = TTypeInverter_Imperix_B.ADC;
  } else if (TTypeInverter_Imperix_B.Switch2 < TTypeInverter_Imperix_B.ADC_l) {
    // Sum: '<S31>/Sum2' incorporates:
    //   Switch: '<S52>/Switch'
    //   Switch: '<S52>/Switch2'

    TTypeInverter_Imperix_B.Switch2 = TTypeInverter_Imperix_B.ADC_l;
  }

  // End of Switch: '<S52>/Switch2'

  // MATLAB Function: '<S31>/MATLAB Function'
  TTypeInverter_Im_MATLABFunction(TTypeInverter_Imperix_B.ADC,
    TTypeInverter_Imperix_B.Switch2, TTypeInverter_Imperix_B.ADC_l,
    &TTypeInverter_Imperix_B.m_c);

  // S-Function (PROBE): '<S63>/S-Function'
  iL_ref_l1 = TTypeInverter_Imperix_B.Saturation_c;

  // S-Function (PROBE): '<S65>/S-Function'
  e_iL_l1 = TTypeInverter_Imperix_B.e_iL;

  // S-Function (PROBE): '<S67>/S-Function'
  e_vc_l1 = TTypeInverter_Imperix_B.e_vc;

  // S-Function (PROBE): '<S69>/S-Function'
  vc_ref_l1 = TTypeInverter_Imperix_B.DataTypeConversion;

  // DataTypeConversion: '<S69>/Data Type Conversion'
  TTypeInverter_Imperix_B.DataTypeConversion = static_cast<real32_T>(rtb_Add);

  // S-Function (PROBE): '<S71>/S-Function'
  vi_ref_l1 = TTypeInverter_Imperix_B.Switch2;

  // Sum: '<S53>/Sum1' incorporates:
  //   Delay: '<S72>/Delay1'

  TTypeInverter_Imperix_DW.Delay1_DSTATE = rtb_Add_o -
    TTypeInverter_Imperix_B.Saturation_c;

  // DiscreteTransferFcn: '<S32>/GI Differentiator'
  GIDifferentiator_tmp = ((TTypeInverter_Imperix_B.ADC_j -
    TTypeInverter_Imperix_DW.GIDifferentiator_states[0] *
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef[1]) -
    TTypeInverter_Imperix_DW.GIDifferentiator_states[1] *
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef[2]) /
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef[0];

  // Sum: '<S32>/Add' incorporates:
  //   DiscreteTransferFcn: '<S32>/GI Differentiator'

  rtb_io = TTypeInverter_Imperix_B.ADC_h -
    ((TTypeInverter_Imperix_P.GIDifferentiator_NumCoef[0] * GIDifferentiator_tmp
      + TTypeInverter_Imperix_DW.GIDifferentiator_states[0] *
      TTypeInverter_Imperix_P.GIDifferentiator_NumCoef[1]) +
     TTypeInverter_Imperix_DW.GIDifferentiator_states[1] *
     TTypeInverter_Imperix_P.GIDifferentiator_NumCoef[2]);

  // DataTypeConversion: '<S119>/Conversion' incorporates:
  //   Constant: '<S77>/KalmanGainL'

  for (int32_T i = 0; i < 6; i++) {
    rtb_Conversion[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.KalmanGainL_Value[i]);
  }

  // End of DataTypeConversion: '<S119>/Conversion'

  // DataTypeConversion: '<S122>/Conversion' incorporates:
  //   Constant: '<S77>/CovarianceZ'

  for (int32_T i = 0; i < 9; i++) {
    rtb_Conversion_pm[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.CovarianceZ_Value[i]);
  }

  // End of DataTypeConversion: '<S122>/Conversion'

  // MATLAB Function: '<S124>/SqrtUsedFcn' incorporates:
  //   Constant: '<S124>/isSqrtUsed'

  TTypeInverter_Imper_SqrtUsedFcn(rtb_Conversion_pm,
    TTypeInverter_Imperix_P.isSqrtUsed_Value, rtb_P_m);
  TTypeInverter_Imp_MovingAverage(rtb_io, &TTypeInverter_Imperix_B.MovingAverage,
    &TTypeInverter_Imperix_DW.MovingAverage);

  // Reshape: '<S76>/Reshapeu'
  rtb_Reshapeu[0] = TTypeInverter_Imperix_B.Switch2;
  rtb_Reshapeu[1] = TTypeInverter_Imperix_B.MovingAverage.MovingAverage;

  // Outputs for Enabled SubSystem: '<S97>/MeasurementUpdate'
  // Constant: '<S76>/Enable' incorporates:
  //   Constant: '<S76>/C'
  //   Constant: '<S76>/D'
  //   Delay: '<S76>/MemoryX'

  TTypeInverter_MeasurementUpdate(TTypeInverter_Imperix_P.Enable_Value,
    rtb_Conversion, rtb_Reshapey, TTypeInverter_Imperix_P.C_Value,
    TTypeInverter_Imperix_DW.MemoryX_DSTATE, TTypeInverter_Imperix_P.D_Value,
    rtb_Reshapeu, TTypeInverter_Imperix_B.Product3_f,
    &TTypeInverter_Imperix_DW.MeasurementUpdate,
    &TTypeInverter_Imperix_P.MeasurementUpdate);

  // End of Outputs for SubSystem: '<S97>/MeasurementUpdate'

  // DataTypeConversion: '<S33>/Data Type Conversion2' incorporates:
  //   Constant: '<S33>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2 = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value);

  // DataTypeConversion: '<S33>/Data Type Conversion3' incorporates:
  //   Constant: '<S33>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3 = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value);

  // Outputs for Atomic SubSystem: '<S129>/generation'
  // S-Function (CB_PWM): '<S130>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 0, TTypeInverter_Imperix_B.m_c, 0);

  // End of Outputs for SubSystem: '<S129>/generation'

  // DataTypeConversion: '<S34>/Data Type Conversion1' incorporates:
  //   Constant: '<S9>/Constant2'
  //   Sum: '<S9>/Add'

  TTypeInverter_Imperix_B.DataTypeConversion1 = static_cast<real32_T>
    (TTypeInverter_Imperix_B.m_c + TTypeInverter_Imperix_P.Constant2_Value);

  // DataTypeConversion: '<S34>/Data Type Conversion2' incorporates:
  //   Constant: '<S34>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2_l = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value_j);

  // DataTypeConversion: '<S34>/Data Type Conversion3' incorporates:
  //   Constant: '<S34>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3_e = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value_o);

  // Outputs for Atomic SubSystem: '<S131>/generation'
  // S-Function (CB_PWM): '<S132>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 2, TTypeInverter_Imperix_B.DataTypeConversion1,
                     0);

  // End of Outputs for SubSystem: '<S131>/generation'

  // S-Function (PROBE): '<S250>/S-Function'
  iL_l2 = TTypeInverter_Imperix_B.ADC_f;

  // S-Function (PROBE): '<S252>/S-Function'
  vc_l2 = TTypeInverter_Imperix_B.ADC_p;

  // S-Function (PROBE): '<S254>/S-Function'
  io_hat_l2 = TTypeInverter_Imperix_B.io_hat_f;

  // S-Function (PROBE): '<S256>/S-Function'
  vc_hat_l2 = TTypeInverter_Imperix_B.Product_l[1];

  // S-Function (PROBE): '<S258>/S-Function'
  m_l2 = TTypeInverter_Imperix_B.m_e;

  // S-Function (PROBE): '<S260>/S-Function'
  iL_hat_l2 = TTypeInverter_Imperix_B.Product_l[0];

  // S-Function (ADC): '<S158>/ADC'
  TTypeInverter_Imperix_B.ADC_p = (float)(*ix_raw_adc_ptr_1_0) * 0.012451F +
    0.0F;

  // S-Function (ADC): '<S160>/ADC'
  TTypeInverter_Imperix_B.ADC_f = (float)(*ix_raw_adc_ptr_6_0) * 0.0066763F +
    0.0F;

  // DataTypeConversion: '<S236>/Conversion' incorporates:
  //   Constant: '<S193>/KalmanGainM'

  for (int32_T i = 0; i < 6; i++) {
    rtb_Conversion[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.KalmanGainM_Value_j[i]);
  }

  // End of DataTypeConversion: '<S236>/Conversion'

  // Reshape: '<S192>/Reshapey'
  rtb_Reshapey_i[0] = TTypeInverter_Imperix_B.ADC_f;
  rtb_Reshapey_i[1] = TTypeInverter_Imperix_B.ADC_p;

  // Delay: '<S192>/MemoryX' incorporates:
  //   Constant: '<S192>/X0'

  if (TTypeInverter_Imperix_DW.icLoad_p) {
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[0] =
      TTypeInverter_Imperix_P.X0_Value_f[0];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[1] =
      TTypeInverter_Imperix_P.X0_Value_f[1];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[2] =
      TTypeInverter_Imperix_P.X0_Value_f[2];
  }

  // Outputs for Enabled SubSystem: '<S219>/Enabled Subsystem'
  // Constant: '<S192>/Enable' incorporates:
  //   Constant: '<S192>/C'
  //   Delay: '<S192>/MemoryX'

  TTypeInverter__EnabledSubsystem(TTypeInverter_Imperix_P.Enable_Value_m,
    rtb_Conversion, TTypeInverter_Imperix_P.C_Value_j, rtb_Reshapey_i,
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l,
    TTypeInverter_Imperix_B.Product2_i,
    &TTypeInverter_Imperix_DW.EnabledSubsystem_l,
    &TTypeInverter_Imperix_P.EnabledSubsystem_l);

  // End of Outputs for SubSystem: '<S219>/Enabled Subsystem'

  // Sum: '<S219>/Add' incorporates:
  //   Delay: '<S192>/MemoryX'

  rtb_Bkuk_idx_0 = TTypeInverter_Imperix_B.Product2_i[0] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[0];
  rtb_Bkuk_idx_1 = TTypeInverter_Imperix_B.Product2_i[1] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[1];
  rtb_Bkuk_idx_2 = TTypeInverter_Imperix_B.Product2_i[2] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[2];
  for (int32_T i = 0; i < 2; i++) {
    // Product: '<S194>/Product' incorporates:
    //   Constant: '<S192>/C'

    TTypeInverter_Imperix_B.Product_l[i] = 0.0F;
    TTypeInverter_Imperix_B.Product_l[i] += TTypeInverter_Imperix_P.C_Value_j[i]
      * rtb_Bkuk_idx_0;
    TTypeInverter_Imperix_B.Product_l[i] += TTypeInverter_Imperix_P.C_Value_j[i
      + 2] * rtb_Bkuk_idx_1;
    TTypeInverter_Imperix_B.Product_l[i] += TTypeInverter_Imperix_P.C_Value_j[i
      + 4] * rtb_Bkuk_idx_2;
  }

  // S-Function (TUNABLE_PARAM): '<S177>/S-Function'
  TTypeInverter_Imperix_B.SFunction_p = Kc_l2;

  // Sum: '<S148>/Subtract2'
  TTypeInverter_Imperix_B.io_hat_f = rtb_Bkuk_idx_0 - rtb_Bkuk_idx_2;

  // S-Function (TUNABLE_PARAM): '<S191>/S-Function'
  TTypeInverter_Imperix_B.SFunction_f = Kp_l2;

  // Sin: '<S147>/Sine Wave'
  if (TTypeInverter_Imperix_DW.systemEnable_n != 0) {
    rtb_Add = TTypeInverter_Imperix_P.f_o * 2.0 * 3.1415926535897931 *
      (((TTypeInverter_Imperix_M->Timing.clockTick0+
         TTypeInverter_Imperix_M->Timing.clockTickH0* 4294967296.0)) *
       1.0416000368143116E-5);
    TTypeInverter_Imperix_DW.lastSin_i = sin(rtb_Add);
    TTypeInverter_Imperix_DW.lastCos_k = cos(rtb_Add);
    TTypeInverter_Imperix_DW.systemEnable_n = 0;
  }

  rtb_Add = ((TTypeInverter_Imperix_DW.lastSin_i *
              TTypeInverter_Imperix_P.SineWave_PCos_j +
              TTypeInverter_Imperix_DW.lastCos_k *
              TTypeInverter_Imperix_P.SineWave_PSin_n) *
             TTypeInverter_Imperix_P.SineWave_HCos_d +
             (TTypeInverter_Imperix_DW.lastCos_k *
              TTypeInverter_Imperix_P.SineWave_PCos_j -
              TTypeInverter_Imperix_DW.lastSin_i *
              TTypeInverter_Imperix_P.SineWave_PSin_n) *
             TTypeInverter_Imperix_P.SineWave_Hsin_b) *
    TTypeInverter_Imperix_P.Vout_amp + TTypeInverter_Imperix_P.SineWave_Bias_a;

  // End of Sin: '<S147>/Sine Wave'

  // Sum: '<S147>/Sum' incorporates:
  //   DataTypeConversion: '<S147>/Data Type Conversion'

  TTypeInverter_Imperix_B.e_vc_c = static_cast<real32_T>(rtb_Add) -
    TTypeInverter_Imperix_B.Product_l[1];

  // Sum: '<S188>/Sum' incorporates:
  //   Delay: '<S188>/Delay1'
  //   Gain: '<S188>/Klim'

  rtb_en_e = TTypeInverter_Imperix_B.e_vc_c - TTypeInverter_Imperix_P.Klim *
    TTypeInverter_Imperix_DW.Delay1_DSTATE_h;

  // Delay: '<S188>/Delay4'
  rtb_yn1_j = TTypeInverter_Imperix_DW.Delay4_DSTATE_k;

  // Gain: '<S188>/1//b0' incorporates:
  //   Delay: '<S188>/Delay3'
  //   Delay: '<S188>/Delay4'
  //   Delay: '<S188>/Delay5'
  //   Gain: '<S188>/a0'
  //   Gain: '<S188>/a1'
  //   Gain: '<S188>/b1'
  //   Gain: '<S188>/b2'
  //   Sum: '<S188>/Sum3'
  //   Sum: '<S188>/Sum4'
  //   Sum: '<S188>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_k = ((TTypeInverter_Imperix_P.a0_Gain_a
    * rtb_en_e - TTypeInverter_Imperix_P.a1_Gain_n *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_l) +
    (TTypeInverter_Imperix_P.b1_Gain_d *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_k -
     TTypeInverter_Imperix_P.b2_Gain_n *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_c)) *
    TTypeInverter_Imperix_P.ub0_Gain_c;

  // Sum: '<S169>/Add' incorporates:
  //   Product: '<S169>/Product'

  rtb_Add_o = TTypeInverter_Imperix_B.SFunction_f *
    TTypeInverter_Imperix_B.e_vc_c + TTypeInverter_Imperix_DW.Delay4_DSTATE_k;

  // Saturate: '<S169>/Saturation'
  if (rtb_Add_o > TTypeInverter_Imperix_P.pr_sat_val) {
    // Saturate: '<S169>/Saturation'
    TTypeInverter_Imperix_B.Saturation_p = TTypeInverter_Imperix_P.pr_sat_val;
  } else if (rtb_Add_o < TTypeInverter_Imperix_P.Saturation_LowerSat_b) {
    // Saturate: '<S169>/Saturation'
    TTypeInverter_Imperix_B.Saturation_p =
      TTypeInverter_Imperix_P.Saturation_LowerSat_b;
  } else {
    // Saturate: '<S169>/Saturation'
    TTypeInverter_Imperix_B.Saturation_p = rtb_Add_o;
  }

  // End of Saturate: '<S169>/Saturation'

  // Sum: '<S147>/Sum3' incorporates:
  //   Sum: '<S147>/Sum1'

  TTypeInverter_Imperix_B.e_iL_i = (TTypeInverter_Imperix_B.io_hat_f +
    TTypeInverter_Imperix_B.Saturation_p) - TTypeInverter_Imperix_B.Product_l[0];

  // MATLAB Function: '<S161>/Variable Gain'
  TTypeInverter_Impe_VariableGain(TTypeInverter_Imperix_B.Product_l[0],
    TTypeInverter_Imperix_B.e_iL_i, &rtb_e_out_e);

  // Delay: '<S172>/Delay4'
  rtb_yn1_c3 = TTypeInverter_Imperix_DW.Delay4_DSTATE_o;

  // Gain: '<S172>/1//b0' incorporates:
  //   Delay: '<S172>/Delay3'
  //   Delay: '<S172>/Delay4'
  //   Delay: '<S172>/Delay5'
  //   Gain: '<S172>/a0'
  //   Gain: '<S172>/a1'
  //   Gain: '<S172>/b1'
  //   Gain: '<S172>/b2'
  //   Sum: '<S172>/Sum3'
  //   Sum: '<S172>/Sum4'
  //   Sum: '<S172>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_o = ((TTypeInverter_Imperix_P.a0_Gain_o
    * rtb_e_out_e - TTypeInverter_Imperix_P.a1_Gain_l *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_f) +
    (TTypeInverter_Imperix_P.b1_Gain_e *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_o -
     TTypeInverter_Imperix_P.b2_Gain_i *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_k)) *
    TTypeInverter_Imperix_P.ub0_Gain_ps;

  // Delay: '<S173>/Delay4'
  rtb_yn1_e = TTypeInverter_Imperix_DW.Delay4_DSTATE_dv;

  // Gain: '<S173>/1//b0' incorporates:
  //   Delay: '<S173>/Delay3'
  //   Delay: '<S173>/Delay4'
  //   Delay: '<S173>/Delay5'
  //   Gain: '<S173>/a0'
  //   Gain: '<S173>/a1'
  //   Gain: '<S173>/b1'
  //   Gain: '<S173>/b2'
  //   Sum: '<S173>/Sum3'
  //   Sum: '<S173>/Sum4'
  //   Sum: '<S173>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dv =
    ((TTypeInverter_Imperix_P.a0_Gain_mp * rtb_e_out_e -
      TTypeInverter_Imperix_P.a1_Gain_o3 *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_i) +
     (TTypeInverter_Imperix_P.b1_Gain_di *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_dv -
      TTypeInverter_Imperix_P.b2_Gain_e *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_aq)) *
    TTypeInverter_Imperix_P.ub0_Gain_g;

  // Delay: '<S170>/Delay4'
  rtb_yn1_nd = TTypeInverter_Imperix_DW.Delay4_DSTATE_c;

  // Gain: '<S170>/1//b0' incorporates:
  //   Delay: '<S170>/Delay3'
  //   Delay: '<S170>/Delay4'
  //   Delay: '<S170>/Delay5'
  //   Gain: '<S170>/a0'
  //   Gain: '<S170>/a1'
  //   Gain: '<S170>/b1'
  //   Gain: '<S170>/b2'
  //   Sum: '<S170>/Sum3'
  //   Sum: '<S170>/Sum4'
  //   Sum: '<S170>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_c = ((TTypeInverter_Imperix_P.a0_Gain_n
    * rtb_e_out_e - TTypeInverter_Imperix_P.a1_Gain_a *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_j) +
    (TTypeInverter_Imperix_P.b1_Gain_h *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_c -
     TTypeInverter_Imperix_P.b2_Gain_m *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_d)) *
    TTypeInverter_Imperix_P.ub0_Gain_h;

  // Delay: '<S171>/Delay4'
  rtb_yn1_kz = TTypeInverter_Imperix_DW.Delay4_DSTATE_kv;

  // Gain: '<S171>/1//b0' incorporates:
  //   Delay: '<S171>/Delay3'
  //   Delay: '<S171>/Delay4'
  //   Delay: '<S171>/Delay5'
  //   Gain: '<S171>/a0'
  //   Gain: '<S171>/a1'
  //   Gain: '<S171>/b1'
  //   Gain: '<S171>/b2'
  //   Sum: '<S171>/Sum3'
  //   Sum: '<S171>/Sum4'
  //   Sum: '<S171>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_kv =
    ((TTypeInverter_Imperix_P.a0_Gain_f * rtb_e_out_e -
      TTypeInverter_Imperix_P.a1_Gain_f *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_a) +
     (TTypeInverter_Imperix_P.b1_Gain_j *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_kv -
      TTypeInverter_Imperix_P.b2_Gain_ch *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_dx)) *
    TTypeInverter_Imperix_P.ub0_Gain_he;

  // Sum: '<S147>/Sum2' incorporates:
  //   Gain: '<S147>/Gain1'
  //   Product: '<S161>/P Controller'
  //   Sum: '<S161>/Add'

  TTypeInverter_Imperix_B.Switch2_a = (((((TTypeInverter_Imperix_B.SFunction_p *
    rtb_e_out_e + TTypeInverter_Imperix_DW.Delay4_DSTATE_o) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_dv) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_c) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_kv) + TTypeInverter_Imperix_P.R_Lc *
    TTypeInverter_Imperix_B.Product_l[0]) + TTypeInverter_Imperix_B.Product_l[1];

  // Switch: '<S168>/Switch2' incorporates:
  //   RelationalOperator: '<S168>/LowerRelop1'
  //   RelationalOperator: '<S168>/UpperRelop'
  //   Switch: '<S168>/Switch'

  if (TTypeInverter_Imperix_B.Switch2_a > TTypeInverter_Imperix_B.ADC) {
    // Sum: '<S147>/Sum2' incorporates:
    //   Switch: '<S168>/Switch2'

    TTypeInverter_Imperix_B.Switch2_a = TTypeInverter_Imperix_B.ADC;
  } else if (TTypeInverter_Imperix_B.Switch2_a < TTypeInverter_Imperix_B.ADC_l)
  {
    // Sum: '<S147>/Sum2' incorporates:
    //   Switch: '<S168>/Switch'
    //   Switch: '<S168>/Switch2'

    TTypeInverter_Imperix_B.Switch2_a = TTypeInverter_Imperix_B.ADC_l;
  }

  // End of Switch: '<S168>/Switch2'

  // MATLAB Function: '<S147>/MATLAB Function'
  TTypeInverter_Im_MATLABFunction(TTypeInverter_Imperix_B.ADC,
    TTypeInverter_Imperix_B.Switch2_a, TTypeInverter_Imperix_B.ADC_l,
    &TTypeInverter_Imperix_B.m_e);

  // S-Function (PROBE): '<S179>/S-Function'
  iL_ref_l2 = TTypeInverter_Imperix_B.Saturation_p;

  // S-Function (PROBE): '<S181>/S-Function'
  e_iL_l2 = TTypeInverter_Imperix_B.e_iL_i;

  // S-Function (PROBE): '<S183>/S-Function'
  e_vc_l2 = TTypeInverter_Imperix_B.e_vc_c;

  // S-Function (PROBE): '<S185>/S-Function'
  vc_ref_l2 = TTypeInverter_Imperix_B.DataTypeConversion_i;

  // DataTypeConversion: '<S185>/Data Type Conversion'
  TTypeInverter_Imperix_B.DataTypeConversion_i = static_cast<real32_T>(rtb_Add);

  // S-Function (PROBE): '<S187>/S-Function'
  vi_ref_l2 = TTypeInverter_Imperix_B.Switch2_a;

  // Sum: '<S169>/Sum1' incorporates:
  //   Delay: '<S188>/Delay1'

  TTypeInverter_Imperix_DW.Delay1_DSTATE_h = rtb_Add_o -
    TTypeInverter_Imperix_B.Saturation_p;

  // DiscreteTransferFcn: '<S148>/GI Differentiator'
  GIDifferentiator_tmp_m = ((TTypeInverter_Imperix_B.ADC_p -
    TTypeInverter_Imperix_DW.GIDifferentiator_states_j[0] *
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef_m[1]) -
    TTypeInverter_Imperix_DW.GIDifferentiator_states_j[1] *
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef_m[2]) /
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef_m[0];

  // Sum: '<S148>/Add' incorporates:
  //   DiscreteTransferFcn: '<S148>/GI Differentiator'

  rtb_io_c = TTypeInverter_Imperix_B.ADC_f -
    ((TTypeInverter_Imperix_P.GIDifferentiator_NumCoef_e[0] *
      GIDifferentiator_tmp_m +
      TTypeInverter_Imperix_DW.GIDifferentiator_states_j[0] *
      TTypeInverter_Imperix_P.GIDifferentiator_NumCoef_e[1]) +
     TTypeInverter_Imperix_DW.GIDifferentiator_states_j[1] *
     TTypeInverter_Imperix_P.GIDifferentiator_NumCoef_e[2]);

  // DataTypeConversion: '<S235>/Conversion' incorporates:
  //   Constant: '<S193>/KalmanGainL'

  for (int32_T i = 0; i < 6; i++) {
    rtb_Conversion[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.KalmanGainL_Value_o[i]);
  }

  // End of DataTypeConversion: '<S235>/Conversion'

  // DataTypeConversion: '<S238>/Conversion' incorporates:
  //   Constant: '<S193>/CovarianceZ'

  for (int32_T i = 0; i < 9; i++) {
    rtb_Conversion_pm[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.CovarianceZ_Value_i[i]);
  }

  // End of DataTypeConversion: '<S238>/Conversion'

  // MATLAB Function: '<S240>/SqrtUsedFcn' incorporates:
  //   Constant: '<S240>/isSqrtUsed'

  TTypeInverter_Imper_SqrtUsedFcn(rtb_Conversion_pm,
    TTypeInverter_Imperix_P.isSqrtUsed_Value_k, rtb_P_m);
  TTypeInverter_Imp_MovingAverage(rtb_io_c,
    &TTypeInverter_Imperix_B.MovingAverage_p,
    &TTypeInverter_Imperix_DW.MovingAverage_p);

  // Reshape: '<S192>/Reshapeu'
  rtb_Reshapey[0] = TTypeInverter_Imperix_B.Switch2_a;
  rtb_Reshapey[1] = TTypeInverter_Imperix_B.MovingAverage_p.MovingAverage;

  // Outputs for Enabled SubSystem: '<S213>/MeasurementUpdate'
  // Constant: '<S192>/Enable' incorporates:
  //   Constant: '<S192>/C'
  //   Constant: '<S192>/D'
  //   Delay: '<S192>/MemoryX'

  TTypeInverter_MeasurementUpdate(TTypeInverter_Imperix_P.Enable_Value_m,
    rtb_Conversion, rtb_Reshapey_i, TTypeInverter_Imperix_P.C_Value_j,
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l, TTypeInverter_Imperix_P.D_Value_g,
    rtb_Reshapey, TTypeInverter_Imperix_B.Product3_h,
    &TTypeInverter_Imperix_DW.MeasurementUpdate_f,
    &TTypeInverter_Imperix_P.MeasurementUpdate_f);

  // End of Outputs for SubSystem: '<S213>/MeasurementUpdate'

  // DataTypeConversion: '<S149>/Data Type Conversion2' incorporates:
  //   Constant: '<S149>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2_b = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value_c);

  // DataTypeConversion: '<S149>/Data Type Conversion3' incorporates:
  //   Constant: '<S149>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3_c = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value_h);

  // Outputs for Atomic SubSystem: '<S245>/generation'
  // S-Function (CB_PWM): '<S246>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 4, TTypeInverter_Imperix_B.m_e, 0);

  // End of Outputs for SubSystem: '<S245>/generation'

  // DataTypeConversion: '<S150>/Data Type Conversion1' incorporates:
  //   Constant: '<S10>/Constant2'
  //   Sum: '<S10>/Add'

  TTypeInverter_Imperix_B.DataTypeConversion1_a = static_cast<real32_T>
    (TTypeInverter_Imperix_B.m_e + TTypeInverter_Imperix_P.Constant2_Value_e);

  // DataTypeConversion: '<S150>/Data Type Conversion2' incorporates:
  //   Constant: '<S150>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2_o = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value_d);

  // DataTypeConversion: '<S150>/Data Type Conversion3' incorporates:
  //   Constant: '<S150>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3_i = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value_p);

  // Outputs for Atomic SubSystem: '<S247>/generation'
  // S-Function (CB_PWM): '<S248>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 6,
                     TTypeInverter_Imperix_B.DataTypeConversion1_a, 0);

  // End of Outputs for SubSystem: '<S247>/generation'

  // S-Function (PROBE): '<S366>/S-Function'
  iL_l3 = TTypeInverter_Imperix_B.ADC_i;

  // S-Function (PROBE): '<S368>/S-Function'
  vc_l3 = TTypeInverter_Imperix_B.ADC_a;

  // S-Function (PROBE): '<S370>/S-Function'
  io_hat_l3 = TTypeInverter_Imperix_B.io_hat_p;

  // S-Function (PROBE): '<S372>/S-Function'
  vc_hat_l3 = TTypeInverter_Imperix_B.Product_m[1];

  // S-Function (PROBE): '<S374>/S-Function'
  m_l3 = TTypeInverter_Imperix_B.m;

  // S-Function (PROBE): '<S376>/S-Function'
  iL_hat_l3 = TTypeInverter_Imperix_B.Product_m[0];

  // S-Function (ADC): '<S274>/ADC'
  TTypeInverter_Imperix_B.ADC_a = (float)(*ix_raw_adc_ptr_2_0) * 0.012451F +
    0.0F;

  // S-Function (ADC): '<S276>/ADC'
  TTypeInverter_Imperix_B.ADC_i = (float)(*ix_raw_adc_ptr_7_0) * 0.0066763F +
    0.0F;

  // DataTypeConversion: '<S352>/Conversion' incorporates:
  //   Constant: '<S309>/KalmanGainM'

  for (int32_T i = 0; i < 6; i++) {
    rtb_Conversion[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.KalmanGainM_Value_i[i]);
  }

  // End of DataTypeConversion: '<S352>/Conversion'

  // Reshape: '<S308>/Reshapey'
  rtb_Reshapey_i[0] = TTypeInverter_Imperix_B.ADC_i;
  rtb_Reshapey_i[1] = TTypeInverter_Imperix_B.ADC_a;

  // Delay: '<S308>/MemoryX' incorporates:
  //   Constant: '<S308>/X0'

  if (TTypeInverter_Imperix_DW.icLoad_b) {
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[0] =
      TTypeInverter_Imperix_P.X0_Value_i[0];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[1] =
      TTypeInverter_Imperix_P.X0_Value_i[1];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[2] =
      TTypeInverter_Imperix_P.X0_Value_i[2];
  }

  // Outputs for Enabled SubSystem: '<S335>/Enabled Subsystem'
  // Constant: '<S308>/Enable' incorporates:
  //   Constant: '<S308>/C'
  //   Delay: '<S308>/MemoryX'

  TTypeInverter__EnabledSubsystem(TTypeInverter_Imperix_P.Enable_Value_k,
    rtb_Conversion, TTypeInverter_Imperix_P.C_Value_c, rtb_Reshapey_i,
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e, TTypeInverter_Imperix_B.Product2,
    &TTypeInverter_Imperix_DW.EnabledSubsystem_f,
    &TTypeInverter_Imperix_P.EnabledSubsystem_f);

  // End of Outputs for SubSystem: '<S335>/Enabled Subsystem'

  // Sum: '<S335>/Add' incorporates:
  //   Delay: '<S308>/MemoryX'

  rtb_Bkuk_idx_0 = TTypeInverter_Imperix_B.Product2[0] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[0];
  rtb_Bkuk_idx_1 = TTypeInverter_Imperix_B.Product2[1] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[1];
  rtb_Bkuk_idx_2 = TTypeInverter_Imperix_B.Product2[2] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[2];
  for (int32_T i = 0; i < 2; i++) {
    // Product: '<S310>/Product' incorporates:
    //   Constant: '<S308>/C'

    TTypeInverter_Imperix_B.Product_m[i] = 0.0F;
    TTypeInverter_Imperix_B.Product_m[i] += TTypeInverter_Imperix_P.C_Value_c[i]
      * rtb_Bkuk_idx_0;
    TTypeInverter_Imperix_B.Product_m[i] += TTypeInverter_Imperix_P.C_Value_c[i
      + 2] * rtb_Bkuk_idx_1;
    TTypeInverter_Imperix_B.Product_m[i] += TTypeInverter_Imperix_P.C_Value_c[i
      + 4] * rtb_Bkuk_idx_2;
  }

  // S-Function (TUNABLE_PARAM): '<S293>/S-Function'
  TTypeInverter_Imperix_B.SFunction_l = Kc_l3;

  // Sum: '<S264>/Subtract2'
  TTypeInverter_Imperix_B.io_hat_p = rtb_Bkuk_idx_0 - rtb_Bkuk_idx_2;

  // S-Function (TUNABLE_PARAM): '<S307>/S-Function'
  TTypeInverter_Imperix_B.SFunction_fd = Kp_l3;

  // Sin: '<S263>/Sine Wave'
  if (TTypeInverter_Imperix_DW.systemEnable_a != 0) {
    TTypeInverter_Imperix_DW.lastSin_g = sin(TTypeInverter_Imperix_P.f_o * 2.0 *
      3.1415926535897931 * (((TTypeInverter_Imperix_M->Timing.clockTick0+
      TTypeInverter_Imperix_M->Timing.clockTickH0* 4294967296.0)) *
      1.0416000368143116E-5));
    TTypeInverter_Imperix_DW.lastCos_e = cos(TTypeInverter_Imperix_P.f_o * 2.0 *
      3.1415926535897931 * (((TTypeInverter_Imperix_M->Timing.clockTick0+
      TTypeInverter_Imperix_M->Timing.clockTickH0* 4294967296.0)) *
      1.0416000368143116E-5));
    TTypeInverter_Imperix_DW.systemEnable_a = 0;
  }

  rtb_Add = ((TTypeInverter_Imperix_DW.lastSin_g *
              TTypeInverter_Imperix_P.SineWave_PCos_a +
              TTypeInverter_Imperix_DW.lastCos_e *
              TTypeInverter_Imperix_P.SineWave_PSin_g) *
             TTypeInverter_Imperix_P.SineWave_HCos_n +
             (TTypeInverter_Imperix_DW.lastCos_e *
              TTypeInverter_Imperix_P.SineWave_PCos_a -
              TTypeInverter_Imperix_DW.lastSin_g *
              TTypeInverter_Imperix_P.SineWave_PSin_g) *
             TTypeInverter_Imperix_P.SineWave_Hsin_e) *
    TTypeInverter_Imperix_P.Vout_amp + TTypeInverter_Imperix_P.SineWave_Bias_k;

  // End of Sin: '<S263>/Sine Wave'

  // Sum: '<S263>/Sum' incorporates:
  //   DataTypeConversion: '<S263>/Data Type Conversion'

  TTypeInverter_Imperix_B.e_vc_i = static_cast<real32_T>(rtb_Add) -
    TTypeInverter_Imperix_B.Product_m[1];

  // Sum: '<S304>/Sum' incorporates:
  //   Delay: '<S304>/Delay1'
  //   Gain: '<S304>/Klim'

  rtb_Bkuk_idx_0 = TTypeInverter_Imperix_B.e_vc_i - TTypeInverter_Imperix_P.Klim
    * TTypeInverter_Imperix_DW.Delay1_DSTATE_hq;

  // Delay: '<S304>/Delay4'
  rtb_Bkuk_idx_1 = TTypeInverter_Imperix_DW.Delay4_DSTATE_j;

  // Gain: '<S304>/1//b0' incorporates:
  //   Delay: '<S304>/Delay3'
  //   Delay: '<S304>/Delay4'
  //   Delay: '<S304>/Delay5'
  //   Gain: '<S304>/a0'
  //   Gain: '<S304>/a1'
  //   Gain: '<S304>/b1'
  //   Gain: '<S304>/b2'
  //   Sum: '<S304>/Sum3'
  //   Sum: '<S304>/Sum4'
  //   Sum: '<S304>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_j = ((TTypeInverter_Imperix_P.a0_Gain_e
    * rtb_Bkuk_idx_0 - TTypeInverter_Imperix_P.a1_Gain_kb *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_b5) +
    (TTypeInverter_Imperix_P.b1_Gain_j5 *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_j -
     TTypeInverter_Imperix_P.b2_Gain_l *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_j)) *
    TTypeInverter_Imperix_P.ub0_Gain_i;

  // Sum: '<S285>/Add' incorporates:
  //   Product: '<S285>/Product'

  rtb_Add_o = TTypeInverter_Imperix_B.SFunction_fd *
    TTypeInverter_Imperix_B.e_vc_i + TTypeInverter_Imperix_DW.Delay4_DSTATE_j;

  // Saturate: '<S285>/Saturation'
  if (rtb_Add_o > TTypeInverter_Imperix_P.pr_sat_val) {
    // Saturate: '<S285>/Saturation'
    TTypeInverter_Imperix_B.Saturation_k = TTypeInverter_Imperix_P.pr_sat_val;
  } else if (rtb_Add_o < TTypeInverter_Imperix_P.Saturation_LowerSat_k) {
    // Saturate: '<S285>/Saturation'
    TTypeInverter_Imperix_B.Saturation_k =
      TTypeInverter_Imperix_P.Saturation_LowerSat_k;
  } else {
    // Saturate: '<S285>/Saturation'
    TTypeInverter_Imperix_B.Saturation_k = rtb_Add_o;
  }

  // End of Saturate: '<S285>/Saturation'

  // Sum: '<S263>/Sum3' incorporates:
  //   Sum: '<S263>/Sum1'

  TTypeInverter_Imperix_B.e_iL_c = (TTypeInverter_Imperix_B.io_hat_p +
    TTypeInverter_Imperix_B.Saturation_k) - TTypeInverter_Imperix_B.Product_m[0];

  // MATLAB Function: '<S277>/Variable Gain'
  TTypeInverter_Impe_VariableGain(TTypeInverter_Imperix_B.Product_m[0],
    TTypeInverter_Imperix_B.e_iL_c, &rtb_Bkuk_idx_2);

  // Delay: '<S288>/Delay4'
  rtb_yn1_a = TTypeInverter_Imperix_DW.Delay4_DSTATE_on;

  // Gain: '<S288>/1//b0' incorporates:
  //   Delay: '<S288>/Delay3'
  //   Delay: '<S288>/Delay4'
  //   Delay: '<S288>/Delay5'
  //   Gain: '<S288>/a0'
  //   Gain: '<S288>/a1'
  //   Gain: '<S288>/b1'
  //   Gain: '<S288>/b2'
  //   Sum: '<S288>/Sum3'
  //   Sum: '<S288>/Sum4'
  //   Sum: '<S288>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_on =
    ((TTypeInverter_Imperix_P.a0_Gain_nt * rtb_Bkuk_idx_2 -
      TTypeInverter_Imperix_P.a1_Gain_ap *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_k) +
     (TTypeInverter_Imperix_P.b1_Gain_ep *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_on -
      TTypeInverter_Imperix_P.b2_Gain_f *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_e)) *
    TTypeInverter_Imperix_P.ub0_Gain_e;

  // Delay: '<S289>/Delay4'
  rtb_yn1_k = TTypeInverter_Imperix_DW.Delay4_DSTATE_p;

  // Gain: '<S289>/1//b0' incorporates:
  //   Delay: '<S289>/Delay3'
  //   Delay: '<S289>/Delay4'
  //   Delay: '<S289>/Delay5'
  //   Gain: '<S289>/a0'
  //   Gain: '<S289>/a1'
  //   Gain: '<S289>/b1'
  //   Gain: '<S289>/b2'
  //   Sum: '<S289>/Sum3'
  //   Sum: '<S289>/Sum4'
  //   Sum: '<S289>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_p =
    ((TTypeInverter_Imperix_P.a0_Gain_f0 * rtb_Bkuk_idx_2 -
      TTypeInverter_Imperix_P.a1_Gain_h *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_m) +
     (TTypeInverter_Imperix_P.b1_Gain_oj *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_p -
      TTypeInverter_Imperix_P.b2_Gain_o *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_m)) *
    TTypeInverter_Imperix_P.ub0_Gain_g5;

  // Delay: '<S286>/Delay4'
  rtb_yn1_nk = TTypeInverter_Imperix_DW.Delay4_DSTATE_h;

  // Gain: '<S286>/1//b0' incorporates:
  //   Delay: '<S286>/Delay3'
  //   Delay: '<S286>/Delay4'
  //   Delay: '<S286>/Delay5'
  //   Gain: '<S286>/a0'
  //   Gain: '<S286>/a1'
  //   Gain: '<S286>/b1'
  //   Gain: '<S286>/b2'
  //   Sum: '<S286>/Sum3'
  //   Sum: '<S286>/Sum4'
  //   Sum: '<S286>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_h = ((TTypeInverter_Imperix_P.a0_Gain_p
    * rtb_Bkuk_idx_2 - TTypeInverter_Imperix_P.a1_Gain_e *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_am) +
    (TTypeInverter_Imperix_P.b1_Gain_ih *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_h -
     TTypeInverter_Imperix_P.b2_Gain_mf *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_co)) *
    TTypeInverter_Imperix_P.ub0_Gain_h1;

  // Delay: '<S287>/Delay4'
  rtb_yn1_bk = TTypeInverter_Imperix_DW.Delay4_DSTATE_db;

  // Gain: '<S287>/1//b0' incorporates:
  //   Delay: '<S287>/Delay3'
  //   Delay: '<S287>/Delay4'
  //   Delay: '<S287>/Delay5'
  //   Gain: '<S287>/a0'
  //   Gain: '<S287>/a1'
  //   Gain: '<S287>/b1'
  //   Gain: '<S287>/b2'
  //   Sum: '<S287>/Sum3'
  //   Sum: '<S287>/Sum4'
  //   Sum: '<S287>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_db =
    ((TTypeInverter_Imperix_P.a0_Gain_l * rtb_Bkuk_idx_2 -
      TTypeInverter_Imperix_P.a1_Gain_m *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_fb) +
     (TTypeInverter_Imperix_P.b1_Gain_ot *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_db -
      TTypeInverter_Imperix_P.b2_Gain_d *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_fp)) *
    TTypeInverter_Imperix_P.ub0_Gain_kl;

  // Sum: '<S263>/Sum2' incorporates:
  //   Gain: '<S263>/Gain1'
  //   Product: '<S277>/P Controller'
  //   Sum: '<S277>/Add'

  TTypeInverter_Imperix_B.Switch2_k = (((((TTypeInverter_Imperix_B.SFunction_l *
    rtb_Bkuk_idx_2 + TTypeInverter_Imperix_DW.Delay4_DSTATE_on) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_p) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_h) +
    TTypeInverter_Imperix_DW.Delay4_DSTATE_db) + TTypeInverter_Imperix_P.R_Lc *
    TTypeInverter_Imperix_B.Product_m[0]) + TTypeInverter_Imperix_B.Product_m[1];

  // Switch: '<S284>/Switch2' incorporates:
  //   RelationalOperator: '<S284>/LowerRelop1'
  //   RelationalOperator: '<S284>/UpperRelop'
  //   Switch: '<S284>/Switch'

  if (TTypeInverter_Imperix_B.Switch2_k > TTypeInverter_Imperix_B.ADC) {
    // Sum: '<S263>/Sum2' incorporates:
    //   Switch: '<S284>/Switch2'

    TTypeInverter_Imperix_B.Switch2_k = TTypeInverter_Imperix_B.ADC;
  } else if (TTypeInverter_Imperix_B.Switch2_k < TTypeInverter_Imperix_B.ADC_l)
  {
    // Sum: '<S263>/Sum2' incorporates:
    //   Switch: '<S284>/Switch'
    //   Switch: '<S284>/Switch2'

    TTypeInverter_Imperix_B.Switch2_k = TTypeInverter_Imperix_B.ADC_l;
  }

  // End of Switch: '<S284>/Switch2'

  // MATLAB Function: '<S263>/MATLAB Function'
  TTypeInverter_Im_MATLABFunction(TTypeInverter_Imperix_B.ADC,
    TTypeInverter_Imperix_B.Switch2_k, TTypeInverter_Imperix_B.ADC_l,
    &TTypeInverter_Imperix_B.m);

  // S-Function (PROBE): '<S295>/S-Function'
  iL_ref_l3 = TTypeInverter_Imperix_B.Saturation_k;

  // S-Function (PROBE): '<S297>/S-Function'
  e_iL_l3 = TTypeInverter_Imperix_B.e_iL_c;

  // S-Function (PROBE): '<S299>/S-Function'
  e_vc_l3 = TTypeInverter_Imperix_B.e_vc_i;

  // S-Function (PROBE): '<S301>/S-Function'
  vc_ref_l3 = TTypeInverter_Imperix_B.DataTypeConversion_b;

  // DataTypeConversion: '<S301>/Data Type Conversion'
  TTypeInverter_Imperix_B.DataTypeConversion_b = static_cast<real32_T>(rtb_Add);

  // S-Function (PROBE): '<S303>/S-Function'
  vi_ref_l3 = TTypeInverter_Imperix_B.Switch2_k;

  // Sum: '<S285>/Sum1' incorporates:
  //   Delay: '<S304>/Delay1'

  TTypeInverter_Imperix_DW.Delay1_DSTATE_hq = rtb_Add_o -
    TTypeInverter_Imperix_B.Saturation_k;

  // DiscreteTransferFcn: '<S264>/GI Differentiator'
  rtb_Add_o = ((TTypeInverter_Imperix_B.ADC_a -
                TTypeInverter_Imperix_DW.GIDifferentiator_states_n[0] *
                TTypeInverter_Imperix_P.GIDifferentiator_DenCoef_ms[1]) -
               TTypeInverter_Imperix_DW.GIDifferentiator_states_n[1] *
               TTypeInverter_Imperix_P.GIDifferentiator_DenCoef_ms[2]) /
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef_ms[0];

  // Sum: '<S264>/Add' incorporates:
  //   DiscreteTransferFcn: '<S264>/GI Differentiator'

  rtb_io_i = TTypeInverter_Imperix_B.ADC_i -
    ((TTypeInverter_Imperix_P.GIDifferentiator_NumCoef_m[0] * rtb_Add_o +
      TTypeInverter_Imperix_DW.GIDifferentiator_states_n[0] *
      TTypeInverter_Imperix_P.GIDifferentiator_NumCoef_m[1]) +
     TTypeInverter_Imperix_DW.GIDifferentiator_states_n[1] *
     TTypeInverter_Imperix_P.GIDifferentiator_NumCoef_m[2]);

  // DataTypeConversion: '<S351>/Conversion' incorporates:
  //   Constant: '<S309>/KalmanGainL'

  for (int32_T i = 0; i < 6; i++) {
    rtb_Conversion[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.KalmanGainL_Value_c[i]);
  }

  // End of DataTypeConversion: '<S351>/Conversion'

  // DataTypeConversion: '<S354>/Conversion' incorporates:
  //   Constant: '<S309>/CovarianceZ'

  for (int32_T i = 0; i < 9; i++) {
    rtb_Conversion_pm[i] = static_cast<real32_T>
      (TTypeInverter_Imperix_P.CovarianceZ_Value_k[i]);
  }

  // End of DataTypeConversion: '<S354>/Conversion'

  // MATLAB Function: '<S356>/SqrtUsedFcn' incorporates:
  //   Constant: '<S356>/isSqrtUsed'

  TTypeInverter_Imper_SqrtUsedFcn(rtb_Conversion_pm,
    TTypeInverter_Imperix_P.isSqrtUsed_Value_c, rtb_P_m);
  TTypeInverter_Imp_MovingAverage(rtb_io_i,
    &TTypeInverter_Imperix_B.MovingAverage_pn,
    &TTypeInverter_Imperix_DW.MovingAverage_pn);

  // Reshape: '<S308>/Reshapeu'
  rtb_Reshapeu_m[0] = TTypeInverter_Imperix_B.Switch2_k;
  rtb_Reshapeu_m[1] = TTypeInverter_Imperix_B.MovingAverage_pn.MovingAverage;

  // Outputs for Enabled SubSystem: '<S329>/MeasurementUpdate'
  // Constant: '<S308>/Enable' incorporates:
  //   Constant: '<S308>/C'
  //   Constant: '<S308>/D'
  //   Delay: '<S308>/MemoryX'

  TTypeInverter_MeasurementUpdate(TTypeInverter_Imperix_P.Enable_Value_k,
    rtb_Conversion, rtb_Reshapey_i, TTypeInverter_Imperix_P.C_Value_c,
    TTypeInverter_Imperix_DW.MemoryX_DSTATE_e, TTypeInverter_Imperix_P.D_Value_i,
    rtb_Reshapeu_m, TTypeInverter_Imperix_B.Product3,
    &TTypeInverter_Imperix_DW.MeasurementUpdate_d,
    &TTypeInverter_Imperix_P.MeasurementUpdate_d);

  // End of Outputs for SubSystem: '<S329>/MeasurementUpdate'

  // DataTypeConversion: '<S265>/Data Type Conversion2' incorporates:
  //   Constant: '<S265>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2_lx = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value_i);

  // DataTypeConversion: '<S265>/Data Type Conversion3' incorporates:
  //   Constant: '<S265>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3_k = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value_e);

  // Outputs for Atomic SubSystem: '<S361>/generation'
  // S-Function (CB_PWM): '<S362>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 8, TTypeInverter_Imperix_B.m, 0);

  // End of Outputs for SubSystem: '<S361>/generation'

  // DataTypeConversion: '<S266>/Data Type Conversion1' incorporates:
  //   Constant: '<S11>/Constant2'
  //   Sum: '<S11>/Add'

  TTypeInverter_Imperix_B.DataTypeConversion1_o = static_cast<real32_T>
    (TTypeInverter_Imperix_B.m + TTypeInverter_Imperix_P.Constant2_Value_o);

  // DataTypeConversion: '<S266>/Data Type Conversion2' incorporates:
  //   Constant: '<S266>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2_e = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value_b);

  // DataTypeConversion: '<S266>/Data Type Conversion3' incorporates:
  //   Constant: '<S266>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3_h = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value_k);

  // Outputs for Atomic SubSystem: '<S363>/generation'
  // S-Function (CB_PWM): '<S364>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 10,
                     TTypeInverter_Imperix_B.DataTypeConversion1_o, 0);

  // End of Outputs for SubSystem: '<S363>/generation'

  // DataTypeConversion: '<S7>/Cast' incorporates:
  //   Constant: '<S7>/activate'

  TTypeInverter_Imperix_B.Cast = static_cast<real32_T>
    (TTypeInverter_Imperix_P.activate_Value);

  // DataTypeConversion: '<S7>/Cast1' incorporates:
  //   Constant: '<S1>/Constant3'

  TTypeInverter_Imperix_B.Cast1 = static_cast<real32_T>
    (TTypeInverter_Imperix_P.Constant3_Value);

  // Outputs for Atomic SubSystem: '<S25>/generation'
  // S-Function (DO_PWM): '<S26>/DO_PWM'
  if (TTypeInverter_Imperix_B.Cast1 > 0.0) {
    DoPwm_SetOn((tPwmOutput) 12, 0);
  } else {
    DoPwm_SetOff((tPwmOutput) 12, 0);
  }

  // End of Outputs for SubSystem: '<S25>/generation'

  // DataTypeConversion: '<S8>/Cast' incorporates:
  //   Constant: '<S8>/activate'

  TTypeInverter_Imperix_B.Cast_m = static_cast<real32_T>
    (TTypeInverter_Imperix_P.activate_Value_f);

  // DataTypeConversion: '<S8>/Cast1' incorporates:
  //   Constant: '<S1>/Constant3'
  //   DataTypeConversion: '<S7>/Cast1'

  TTypeInverter_Imperix_B.Cast1_e = static_cast<real32_T>
    (TTypeInverter_Imperix_P.Constant3_Value);

  // Outputs for Atomic SubSystem: '<S27>/generation'
  // S-Function (DO_PWM): '<S28>/DO_PWM'
  if (TTypeInverter_Imperix_B.Cast1_e > 0.0) {
    DoPwm_SetOn((tPwmOutput) 13, 0);
  } else {
    DoPwm_SetOff((tPwmOutput) 13, 0);
  }

  // End of Outputs for SubSystem: '<S27>/generation'

  // Update for Delay: '<S76>/MemoryX'
  TTypeInverter_Imperix_DW.icLoad = false;
  for (int32_T i = 0; i < 3; i++) {
    // Product: '<S97>/B[k]*u[k]' incorporates:
    //   Constant: '<S76>/B'
    //   Reshape: '<S76>/Reshapeu'

    tmp[i] = TTypeInverter_Imperix_P.B_Value[i + 3] *
      TTypeInverter_Imperix_B.MovingAverage.MovingAverage +
      TTypeInverter_Imperix_P.B_Value[i] * TTypeInverter_Imperix_B.Switch2;

    // Product: '<S97>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S76>/A'
    //   Delay: '<S76>/MemoryX'

    tmp_0[i] = (TTypeInverter_Imperix_P.A_Value[i + 3] *
                TTypeInverter_Imperix_DW.MemoryX_DSTATE[1] +
                TTypeInverter_Imperix_P.A_Value[i] *
                TTypeInverter_Imperix_DW.MemoryX_DSTATE[0]) +
      TTypeInverter_Imperix_P.A_Value[i + 6] *
      TTypeInverter_Imperix_DW.MemoryX_DSTATE[2];
  }

  // Update for Sin: '<S31>/Sine Wave'
  rtb_Add = TTypeInverter_Imperix_DW.lastSin;
  TTypeInverter_Imperix_DW.lastSin = TTypeInverter_Imperix_DW.lastSin *
    TTypeInverter_Imperix_P.SineWave_HCos + TTypeInverter_Imperix_DW.lastCos *
    TTypeInverter_Imperix_P.SineWave_Hsin;
  TTypeInverter_Imperix_DW.lastCos = TTypeInverter_Imperix_DW.lastCos *
    TTypeInverter_Imperix_P.SineWave_HCos - rtb_Add *
    TTypeInverter_Imperix_P.SineWave_Hsin;

  // Update for Delay: '<S72>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE = rtb_en;

  // Update for Delay: '<S72>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE = rtb_yn1;

  // Update for Delay: '<S56>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_o = rtb_e_out_g;

  // Update for Delay: '<S56>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_b = rtb_yn1_d;

  // Update for Delay: '<S57>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_p = rtb_e_out_g;

  // Update for Delay: '<S57>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_f = rtb_yn1_in;

  // Update for Delay: '<S54>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_pn = rtb_e_out_g;

  // Update for Delay: '<S54>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_a = rtb_yn1_e2w;

  // Update for Delay: '<S55>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_b = rtb_e_out_g;

  // Update for Delay: '<S55>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_l = rtb_yn1_ge;

  // Update for DiscreteTransferFcn: '<S32>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states[1] =
    TTypeInverter_Imperix_DW.GIDifferentiator_states[0];
  TTypeInverter_Imperix_DW.GIDifferentiator_states[0] = GIDifferentiator_tmp;

  // Update for Delay: '<S192>/MemoryX'
  TTypeInverter_Imperix_DW.icLoad_p = false;
  for (int32_T i = 0; i < 3; i++) {
    // Update for Delay: '<S76>/MemoryX' incorporates:
    //   Sum: '<S97>/Add'

    TTypeInverter_Imperix_DW.MemoryX_DSTATE[i] = (tmp[i] + tmp_0[i]) +
      TTypeInverter_Imperix_B.Product3_f[i];

    // Product: '<S213>/B[k]*u[k]' incorporates:
    //   Constant: '<S192>/B'
    //   Reshape: '<S192>/Reshapeu'

    tmp_1[i] = TTypeInverter_Imperix_P.B_Value_f[i + 3] *
      TTypeInverter_Imperix_B.MovingAverage_p.MovingAverage +
      TTypeInverter_Imperix_P.B_Value_f[i] * TTypeInverter_Imperix_B.Switch2_a;

    // Product: '<S213>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S192>/A'
    //   Delay: '<S192>/MemoryX'

    tmp_2[i] = (TTypeInverter_Imperix_P.A_Value_k[i + 3] *
                TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[1] +
                TTypeInverter_Imperix_P.A_Value_k[i] *
                TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[0]) +
      TTypeInverter_Imperix_P.A_Value_k[i + 6] *
      TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[2];
  }

  // Update for Sin: '<S147>/Sine Wave'
  rtb_Add = TTypeInverter_Imperix_DW.lastSin_i;
  TTypeInverter_Imperix_DW.lastSin_i = TTypeInverter_Imperix_DW.lastSin_i *
    TTypeInverter_Imperix_P.SineWave_HCos_d + TTypeInverter_Imperix_DW.lastCos_k
    * TTypeInverter_Imperix_P.SineWave_Hsin_b;
  TTypeInverter_Imperix_DW.lastCos_k = TTypeInverter_Imperix_DW.lastCos_k *
    TTypeInverter_Imperix_P.SineWave_HCos_d - rtb_Add *
    TTypeInverter_Imperix_P.SineWave_Hsin_b;

  // Update for Delay: '<S188>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_l = rtb_en_e;

  // Update for Delay: '<S188>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_c = rtb_yn1_j;

  // Update for Delay: '<S172>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_f = rtb_e_out_e;

  // Update for Delay: '<S172>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_k = rtb_yn1_c3;

  // Update for Delay: '<S173>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_i = rtb_e_out_e;

  // Update for Delay: '<S173>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_aq = rtb_yn1_e;

  // Update for Delay: '<S170>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_j = rtb_e_out_e;

  // Update for Delay: '<S170>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_d = rtb_yn1_nd;

  // Update for Delay: '<S171>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_a = rtb_e_out_e;

  // Update for Delay: '<S171>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_dx = rtb_yn1_kz;

  // Update for DiscreteTransferFcn: '<S148>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states_j[1] =
    TTypeInverter_Imperix_DW.GIDifferentiator_states_j[0];
  TTypeInverter_Imperix_DW.GIDifferentiator_states_j[0] = GIDifferentiator_tmp_m;

  // Update for Delay: '<S308>/MemoryX'
  TTypeInverter_Imperix_DW.icLoad_b = false;
  for (int32_T i = 0; i < 3; i++) {
    // Update for Delay: '<S192>/MemoryX' incorporates:
    //   Sum: '<S213>/Add'

    TTypeInverter_Imperix_DW.MemoryX_DSTATE_l[i] = (tmp_1[i] + tmp_2[i]) +
      TTypeInverter_Imperix_B.Product3_h[i];

    // Product: '<S329>/B[k]*u[k]' incorporates:
    //   Constant: '<S308>/B'
    //   Reshape: '<S308>/Reshapeu'

    tmp[i] = TTypeInverter_Imperix_P.B_Value_d[i + 3] *
      TTypeInverter_Imperix_B.MovingAverage_pn.MovingAverage +
      TTypeInverter_Imperix_P.B_Value_d[i] * TTypeInverter_Imperix_B.Switch2_k;

    // Product: '<S329>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S308>/A'
    //   Delay: '<S308>/MemoryX'

    tmp_0[i] = (TTypeInverter_Imperix_P.A_Value_f[i + 3] *
                TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[1] +
                TTypeInverter_Imperix_P.A_Value_f[i] *
                TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[0]) +
      TTypeInverter_Imperix_P.A_Value_f[i + 6] *
      TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[2];
  }

  // Update for Delay: '<S308>/MemoryX' incorporates:
  //   Sum: '<S329>/Add'

  TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[0] = (tmp[0] + tmp_0[0]) +
    TTypeInverter_Imperix_B.Product3[0];
  TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[1] = (tmp[1] + tmp_0[1]) +
    TTypeInverter_Imperix_B.Product3[1];
  TTypeInverter_Imperix_DW.MemoryX_DSTATE_e[2] = (tmp[2] + tmp_0[2]) +
    TTypeInverter_Imperix_B.Product3[2];

  // Update for Sin: '<S263>/Sine Wave'
  rtb_Add = TTypeInverter_Imperix_DW.lastSin_g;
  TTypeInverter_Imperix_DW.lastSin_g = TTypeInverter_Imperix_DW.lastSin_g *
    TTypeInverter_Imperix_P.SineWave_HCos_n + TTypeInverter_Imperix_DW.lastCos_e
    * TTypeInverter_Imperix_P.SineWave_Hsin_e;
  TTypeInverter_Imperix_DW.lastCos_e = TTypeInverter_Imperix_DW.lastCos_e *
    TTypeInverter_Imperix_P.SineWave_HCos_n - rtb_Add *
    TTypeInverter_Imperix_P.SineWave_Hsin_e;

  // Update for Delay: '<S304>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_b5 = rtb_Bkuk_idx_0;

  // Update for Delay: '<S304>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_j = rtb_Bkuk_idx_1;

  // Update for Delay: '<S288>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_k = rtb_Bkuk_idx_2;

  // Update for Delay: '<S288>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_e = rtb_yn1_a;

  // Update for Delay: '<S289>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_m = rtb_Bkuk_idx_2;

  // Update for Delay: '<S289>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_m = rtb_yn1_k;

  // Update for Delay: '<S286>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_am = rtb_Bkuk_idx_2;

  // Update for Delay: '<S286>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_co = rtb_yn1_nk;

  // Update for Delay: '<S287>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_fb = rtb_Bkuk_idx_2;

  // Update for Delay: '<S287>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_fp = rtb_yn1_bk;

  // Update for DiscreteTransferFcn: '<S264>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states_n[1] =
    TTypeInverter_Imperix_DW.GIDifferentiator_states_n[0];
  TTypeInverter_Imperix_DW.GIDifferentiator_states_n[0] = rtb_Add_o;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 1.0416000368143116E-5, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.
  //  Timer of this task consists of two 32 bit unsigned integers.
  //  The two integers represent the low bits Timing.clockTick0 and the high bits
  //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

  TTypeInverter_Imperix_M->Timing.clockTick0++;
  if (!TTypeInverter_Imperix_M->Timing.clockTick0) {
    TTypeInverter_Imperix_M->Timing.clockTickH0++;
  }
}

// Model initialize function
void TTypeInverter_Imperix_initialize(void)
{
  // Start for S-Function (PROBE): '<S378>/S-Function'
  ConfigureProbe(&Batt_P, 0);

  // Start for S-Function (PROBE): '<S380>/S-Function'
  ConfigureProbe(&Batt_N, 0);

  // Start for S-Function (ADC): '<S15>/ADC'
  Adc_ConfigureInput(3, 0.012451F, 0.0F, 0);
  Adc_GetPointer(3, 0, &ix_raw_adc_ptr_3_0);

  // Start for S-Function (ADC): '<S17>/ADC'
  Adc_ConfigureInput(4, 0.012451F, 0.0F, 0);
  Adc_GetPointer(4, 0, &ix_raw_adc_ptr_4_0);

  // Start for S-Function (CLK): '<S19>/CLK1'
  Clock_SetFrequency((tClock) 1, 24000.0F);

  // Start for S-Function (IRQ): '<S22>/S-Function' incorporates:
  //   Constant: '<S24>/clk_id'

  ConfigureMainInterrupt(SimulinkInterrupt, (tClock)
    TTypeInverter_Imperix_P.clk_id_Value_o, 0.0F, 0U);
  Adc_AddSamplingEvent((TTypeInverter_Imperix_P.SFunction_P2));
  ConfigureReadTriggerDelayInNs(500U);

  // Start for S-Function (CLK): '<S24>/CLK1'
  Clock_SetFrequency((tClock) 0, 96006.1406F);

  // Start for S-Function (PROBE): '<S134>/S-Function'
  ConfigureProbe(&iL_l1, 0);

  // Start for S-Function (PROBE): '<S136>/S-Function'
  ConfigureProbe(&vc_l1, 0);

  // Start for S-Function (PROBE): '<S138>/S-Function'
  ConfigureProbe(&io_hat_l1, 0);

  // Start for S-Function (PROBE): '<S140>/S-Function'
  ConfigureProbe(&vc_hat_l1, 0);

  // Start for S-Function (PROBE): '<S142>/S-Function'
  ConfigureProbe(&m_l1, 0);

  // Start for S-Function (PROBE): '<S144>/S-Function'
  ConfigureProbe(&iL_hat_l1, 0);

  // Start for S-Function (ADC): '<S42>/ADC'
  Adc_ConfigureInput(0, 0.012451F, 0.0F, 0);
  Adc_GetPointer(0, 0, &ix_raw_adc_ptr_0_0);

  // Start for S-Function (ADC): '<S44>/ADC'
  Adc_ConfigureInput(5, 0.0066763F, 0.0F, 0);
  Adc_GetPointer(5, 0, &ix_raw_adc_ptr_5_0);

  // Start for S-Function (TUNABLE_PARAM): '<S61>/S-Function'
  Kc_l1 = 2.5F;                        // Tunable parameter initialization
  ConfigureTunable(&Kc_l1, 0, 0, 0.0F, 5.0F);

  // Start for S-Function (TUNABLE_PARAM): '<S75>/S-Function'
  Kp_l1 = 0.9444F;                     // Tunable parameter initialization
  ConfigureTunable(&Kp_l1, 0, 0, 0.0F, 5.0F);

  // Start for S-Function (PROBE): '<S63>/S-Function'
  ConfigureProbe(&iL_ref_l1, 0);

  // Start for S-Function (PROBE): '<S65>/S-Function'
  ConfigureProbe(&e_iL_l1, 0);

  // Start for S-Function (PROBE): '<S67>/S-Function'
  ConfigureProbe(&e_vc_l1, 0);

  // Start for S-Function (PROBE): '<S69>/S-Function'
  ConfigureProbe(&vc_ref_l1, 0);

  // Start for S-Function (PROBE): '<S71>/S-Function'
  ConfigureProbe(&vi_ref_l1, 0);
  TTypeInvert_MovingAverage_Start(&TTypeInverter_Imperix_DW.MovingAverage);

  // Start for Atomic SubSystem: '<S129>/generation'

  // Start for S-Function (CB_PWM): '<S130>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_ConfigureClock((tPwmOutput) 0, (tClock)
                       TTypeInverter_Imperix_P.clk_id_Value, 0);
  CbPwm_ConfigureOutputMode((tPwmOutput) 0, (tPwmOutMode) 0, 0);
  CbPwm_ConfigureCarrier((tPwmOutput) 0, (tPwmCarrier) 0, 0);
  CbPwm_ConfigureDeadTime((tPwmOutput) 0, 1.0E-6F, 0);
  CbPwm_ConfigureUpdateRate((tPwmOutput) 0, (tPwmRate) 1, 0);
  CbPwm_SetPhase((tPwmOutput) 0, 0.0F, 0);
  CbPwm_SetDutyCycle((tPwmOutput) 0, 0.0F, 0);
  CbPwm_Activate((tPwmOutput) 0, 0);

  // End of Start for SubSystem: '<S129>/generation'

  // Start for Atomic SubSystem: '<S131>/generation'

  // Start for S-Function (CB_PWM): '<S132>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_ConfigureClock((tPwmOutput) 2, (tClock)
                       TTypeInverter_Imperix_P.clk_id_Value, 0);
  CbPwm_ConfigureOutputMode((tPwmOutput) 2, (tPwmOutMode) 0, 0);
  CbPwm_ConfigureCarrier((tPwmOutput) 2, (tPwmCarrier) 0, 0);
  CbPwm_ConfigureDeadTime((tPwmOutput) 2, 1.0E-6F, 0);
  CbPwm_ConfigureUpdateRate((tPwmOutput) 2, (tPwmRate) 1, 0);
  CbPwm_SetPhase((tPwmOutput) 2, 0.0F, 0);
  CbPwm_SetDutyCycle((tPwmOutput) 2, 0.0F, 0);
  CbPwm_Activate((tPwmOutput) 2, 0);

  // End of Start for SubSystem: '<S131>/generation'

  // Start for S-Function (PROBE): '<S250>/S-Function'
  ConfigureProbe(&iL_l2, 0);

  // Start for S-Function (PROBE): '<S252>/S-Function'
  ConfigureProbe(&vc_l2, 0);

  // Start for S-Function (PROBE): '<S254>/S-Function'
  ConfigureProbe(&io_hat_l2, 0);

  // Start for S-Function (PROBE): '<S256>/S-Function'
  ConfigureProbe(&vc_hat_l2, 0);

  // Start for S-Function (PROBE): '<S258>/S-Function'
  ConfigureProbe(&m_l2, 0);

  // Start for S-Function (PROBE): '<S260>/S-Function'
  ConfigureProbe(&iL_hat_l2, 0);

  // Start for S-Function (ADC): '<S158>/ADC'
  Adc_ConfigureInput(1, 0.012451F, 0.0F, 0);
  Adc_GetPointer(1, 0, &ix_raw_adc_ptr_1_0);

  // Start for S-Function (ADC): '<S160>/ADC'
  Adc_ConfigureInput(6, 0.0066763F, 0.0F, 0);
  Adc_GetPointer(6, 0, &ix_raw_adc_ptr_6_0);

  // Start for S-Function (TUNABLE_PARAM): '<S177>/S-Function'
  Kc_l2 = 2.5F;                        // Tunable parameter initialization
  ConfigureTunable(&Kc_l2, 0, 0, 0.0F, 5.0F);

  // Start for S-Function (TUNABLE_PARAM): '<S191>/S-Function'
  Kp_l2 = 0.9444F;                     // Tunable parameter initialization
  ConfigureTunable(&Kp_l2, 0, 0, 0.0F, 5.0F);

  // Start for S-Function (PROBE): '<S179>/S-Function'
  ConfigureProbe(&iL_ref_l2, 0);

  // Start for S-Function (PROBE): '<S181>/S-Function'
  ConfigureProbe(&e_iL_l2, 0);

  // Start for S-Function (PROBE): '<S183>/S-Function'
  ConfigureProbe(&e_vc_l2, 0);

  // Start for S-Function (PROBE): '<S185>/S-Function'
  ConfigureProbe(&vc_ref_l2, 0);

  // Start for S-Function (PROBE): '<S187>/S-Function'
  ConfigureProbe(&vi_ref_l2, 0);
  TTypeInvert_MovingAverage_Start(&TTypeInverter_Imperix_DW.MovingAverage_p);

  // Start for Atomic SubSystem: '<S245>/generation'

  // Start for S-Function (CB_PWM): '<S246>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_ConfigureClock((tPwmOutput) 4, (tClock)
                       TTypeInverter_Imperix_P.clk_id_Value, 0);
  CbPwm_ConfigureOutputMode((tPwmOutput) 4, (tPwmOutMode) 0, 0);
  CbPwm_ConfigureCarrier((tPwmOutput) 4, (tPwmCarrier) 0, 0);
  CbPwm_ConfigureDeadTime((tPwmOutput) 4, 1.0E-6F, 0);
  CbPwm_ConfigureUpdateRate((tPwmOutput) 4, (tPwmRate) 1, 0);
  CbPwm_SetPhase((tPwmOutput) 4, 0.0F, 0);
  CbPwm_SetDutyCycle((tPwmOutput) 4, 0.0F, 0);
  CbPwm_Activate((tPwmOutput) 4, 0);

  // End of Start for SubSystem: '<S245>/generation'

  // Start for Atomic SubSystem: '<S247>/generation'

  // Start for S-Function (CB_PWM): '<S248>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_ConfigureClock((tPwmOutput) 6, (tClock)
                       TTypeInverter_Imperix_P.clk_id_Value, 0);
  CbPwm_ConfigureOutputMode((tPwmOutput) 6, (tPwmOutMode) 0, 0);
  CbPwm_ConfigureCarrier((tPwmOutput) 6, (tPwmCarrier) 0, 0);
  CbPwm_ConfigureDeadTime((tPwmOutput) 6, 1.0E-6F, 0);
  CbPwm_ConfigureUpdateRate((tPwmOutput) 6, (tPwmRate) 1, 0);
  CbPwm_SetPhase((tPwmOutput) 6, 0.0F, 0);
  CbPwm_SetDutyCycle((tPwmOutput) 6, 0.0F, 0);
  CbPwm_Activate((tPwmOutput) 6, 0);

  // End of Start for SubSystem: '<S247>/generation'

  // Start for S-Function (PROBE): '<S366>/S-Function'
  ConfigureProbe(&iL_l3, 0);

  // Start for S-Function (PROBE): '<S368>/S-Function'
  ConfigureProbe(&vc_l3, 0);

  // Start for S-Function (PROBE): '<S370>/S-Function'
  ConfigureProbe(&io_hat_l3, 0);

  // Start for S-Function (PROBE): '<S372>/S-Function'
  ConfigureProbe(&vc_hat_l3, 0);

  // Start for S-Function (PROBE): '<S374>/S-Function'
  ConfigureProbe(&m_l3, 0);

  // Start for S-Function (PROBE): '<S376>/S-Function'
  ConfigureProbe(&iL_hat_l3, 0);

  // Start for S-Function (ADC): '<S274>/ADC'
  Adc_ConfigureInput(2, 0.012451F, 0.0F, 0);
  Adc_GetPointer(2, 0, &ix_raw_adc_ptr_2_0);

  // Start for S-Function (ADC): '<S276>/ADC'
  Adc_ConfigureInput(7, 0.0066763F, 0.0F, 0);
  Adc_GetPointer(7, 0, &ix_raw_adc_ptr_7_0);

  // Start for S-Function (TUNABLE_PARAM): '<S293>/S-Function'
  Kc_l3 = 2.5F;                        // Tunable parameter initialization
  ConfigureTunable(&Kc_l3, 0, 0, 0.0F, 5.0F);

  // Start for S-Function (TUNABLE_PARAM): '<S307>/S-Function'
  Kp_l3 = 0.9444F;                     // Tunable parameter initialization
  ConfigureTunable(&Kp_l3, 0, 0, 0.0F, 5.0F);

  // Start for S-Function (PROBE): '<S295>/S-Function'
  ConfigureProbe(&iL_ref_l3, 0);

  // Start for S-Function (PROBE): '<S297>/S-Function'
  ConfigureProbe(&e_iL_l3, 0);

  // Start for S-Function (PROBE): '<S299>/S-Function'
  ConfigureProbe(&e_vc_l3, 0);

  // Start for S-Function (PROBE): '<S301>/S-Function'
  ConfigureProbe(&vc_ref_l3, 0);

  // Start for S-Function (PROBE): '<S303>/S-Function'
  ConfigureProbe(&vi_ref_l3, 0);
  TTypeInvert_MovingAverage_Start(&TTypeInverter_Imperix_DW.MovingAverage_pn);

  // Start for Atomic SubSystem: '<S361>/generation'

  // Start for S-Function (CB_PWM): '<S362>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_ConfigureClock((tPwmOutput) 8, (tClock)
                       TTypeInverter_Imperix_P.clk_id_Value, 0);
  CbPwm_ConfigureOutputMode((tPwmOutput) 8, (tPwmOutMode) 0, 0);
  CbPwm_ConfigureCarrier((tPwmOutput) 8, (tPwmCarrier) 0, 0);
  CbPwm_ConfigureDeadTime((tPwmOutput) 8, 1.0E-6F, 0);
  CbPwm_ConfigureUpdateRate((tPwmOutput) 8, (tPwmRate) 1, 0);
  CbPwm_SetPhase((tPwmOutput) 8, 0.0F, 0);
  CbPwm_SetDutyCycle((tPwmOutput) 8, 0.0F, 0);
  CbPwm_Activate((tPwmOutput) 8, 0);

  // End of Start for SubSystem: '<S361>/generation'

  // Start for Atomic SubSystem: '<S363>/generation'

  // Start for S-Function (CB_PWM): '<S364>/PWM' incorporates:
  //   Constant: '<S19>/clk_id'

  CbPwm_ConfigureClock((tPwmOutput) 10, (tClock)
                       TTypeInverter_Imperix_P.clk_id_Value, 0);
  CbPwm_ConfigureOutputMode((tPwmOutput) 10, (tPwmOutMode) 0, 0);
  CbPwm_ConfigureCarrier((tPwmOutput) 10, (tPwmCarrier) 0, 0);
  CbPwm_ConfigureDeadTime((tPwmOutput) 10, 1.0E-6F, 0);
  CbPwm_ConfigureUpdateRate((tPwmOutput) 10, (tPwmRate) 1, 0);
  CbPwm_SetPhase((tPwmOutput) 10, 0.0F, 0);
  CbPwm_SetDutyCycle((tPwmOutput) 10, 0.0F, 0);
  CbPwm_Activate((tPwmOutput) 10, 0);

  // End of Start for SubSystem: '<S363>/generation'

  // Start for Atomic SubSystem: '<S25>/generation'

  // Start for S-Function (DO_PWM): '<S26>/DO_PWM'
  DoPwm_ConfigureOutputMode((tPwmOutput) 12, (tPwmOutMode) 2, 0);
  DoPwm_Activate((tPwmOutput) 12, 0);

  // End of Start for SubSystem: '<S25>/generation'

  // Start for Atomic SubSystem: '<S27>/generation'

  // Start for S-Function (DO_PWM): '<S28>/DO_PWM'
  DoPwm_ConfigureOutputMode((tPwmOutput) 13, (tPwmOutMode) 2, 0);
  DoPwm_Activate((tPwmOutput) 13, 0);

  // End of Start for SubSystem: '<S27>/generation'

  // InitializeConditions for Delay: '<S76>/MemoryX'
  TTypeInverter_Imperix_DW.icLoad = true;

  // InitializeConditions for Delay: '<S72>/Delay1'
  TTypeInverter_Imperix_DW.Delay1_DSTATE =
    TTypeInverter_Imperix_P.Delay1_InitialCondition;

  // InitializeConditions for Delay: '<S72>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE =
    TTypeInverter_Imperix_P.Delay3_InitialCondition;

  // InitializeConditions for Gain: '<S72>/1//b0' incorporates:
  //   Delay: '<S72>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE =
    TTypeInverter_Imperix_P.Delay4_InitialCondition;

  // InitializeConditions for Delay: '<S72>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE =
    TTypeInverter_Imperix_P.Delay5_InitialCondition;

  // InitializeConditions for Delay: '<S56>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_o =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_c;

  // InitializeConditions for Gain: '<S56>/1//b0' incorporates:
  //   Delay: '<S56>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_e =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_f;

  // InitializeConditions for Delay: '<S56>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_b =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_l;

  // InitializeConditions for Delay: '<S57>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_p =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_p;

  // InitializeConditions for Gain: '<S57>/1//b0' incorporates:
  //   Delay: '<S57>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_d =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_m;

  // InitializeConditions for Delay: '<S57>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_f =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_o;

  // InitializeConditions for Delay: '<S54>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_pn =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_d;

  // InitializeConditions for Gain: '<S54>/1//b0' incorporates:
  //   Delay: '<S54>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dg =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_fy;

  // InitializeConditions for Delay: '<S54>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_a =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_e;

  // InitializeConditions for Delay: '<S55>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_b =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_dr;

  // InitializeConditions for Gain: '<S55>/1//b0' incorporates:
  //   Delay: '<S55>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dh =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_fyn;

  // InitializeConditions for Delay: '<S55>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_l =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_ew;

  // InitializeConditions for Delay: '<S192>/MemoryX'
  TTypeInverter_Imperix_DW.icLoad_p = true;

  // InitializeConditions for Delay: '<S188>/Delay1'
  TTypeInverter_Imperix_DW.Delay1_DSTATE_h =
    TTypeInverter_Imperix_P.Delay1_InitialCondition_c;

  // InitializeConditions for Delay: '<S188>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_l =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_o;

  // InitializeConditions for Gain: '<S188>/1//b0' incorporates:
  //   Delay: '<S188>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_k =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_j;

  // InitializeConditions for Delay: '<S188>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_c =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_p;

  // InitializeConditions for Delay: '<S172>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_f =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_dv;

  // InitializeConditions for Gain: '<S172>/1//b0' incorporates:
  //   Delay: '<S172>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_o =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_e;

  // InitializeConditions for Delay: '<S172>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_k =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_k;

  // InitializeConditions for Delay: '<S173>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_i =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_k;

  // InitializeConditions for Gain: '<S173>/1//b0' incorporates:
  //   Delay: '<S173>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dv =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_h;

  // InitializeConditions for Delay: '<S173>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_aq =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_i;

  // InitializeConditions for Delay: '<S170>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_j =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_a;

  // InitializeConditions for Gain: '<S170>/1//b0' incorporates:
  //   Delay: '<S170>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_c =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_g;

  // InitializeConditions for Delay: '<S170>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_d =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_m;

  // InitializeConditions for Delay: '<S171>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_a =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_f;

  // InitializeConditions for Gain: '<S171>/1//b0' incorporates:
  //   Delay: '<S171>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_kv =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_c;

  // InitializeConditions for Delay: '<S171>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_dx =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_ez;

  // InitializeConditions for Delay: '<S308>/MemoryX'
  TTypeInverter_Imperix_DW.icLoad_b = true;

  // InitializeConditions for Delay: '<S304>/Delay1'
  TTypeInverter_Imperix_DW.Delay1_DSTATE_hq =
    TTypeInverter_Imperix_P.Delay1_InitialCondition_a;

  // InitializeConditions for Delay: '<S304>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_b5 =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_ct;

  // InitializeConditions for Gain: '<S304>/1//b0' incorporates:
  //   Delay: '<S304>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_j =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_d;

  // InitializeConditions for Delay: '<S304>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_j =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_em;

  // InitializeConditions for Delay: '<S288>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_k =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_om;

  // InitializeConditions for Gain: '<S288>/1//b0' incorporates:
  //   Delay: '<S288>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_on =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_d1;

  // InitializeConditions for Delay: '<S288>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_e =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_c;

  // InitializeConditions for Delay: '<S289>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_m =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_ke;

  // InitializeConditions for Gain: '<S289>/1//b0' incorporates:
  //   Delay: '<S289>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_p =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_jc;

  // InitializeConditions for Delay: '<S289>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_m =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_p0;

  // InitializeConditions for Delay: '<S286>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_am =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_py;

  // InitializeConditions for Gain: '<S286>/1//b0' incorporates:
  //   Delay: '<S286>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_h =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_a;

  // InitializeConditions for Delay: '<S286>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_co =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_id;

  // InitializeConditions for Delay: '<S287>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_fb =
    TTypeInverter_Imperix_P.Delay3_InitialCondition_i;

  // InitializeConditions for Gain: '<S287>/1//b0' incorporates:
  //   Delay: '<S287>/Delay4'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_db =
    TTypeInverter_Imperix_P.Delay4_InitialCondition_hn;

  // InitializeConditions for Delay: '<S287>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_fp =
    TTypeInverter_Imperix_P.Delay5_InitialCondition_i1;

  // InitializeConditions for DiscreteTransferFcn: '<S32>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states[0] =
    TTypeInverter_Imperix_P.GIDifferentiator_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<S148>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states_j[0] =
    TTypeInverter_Imperix_P.GIDifferentiator_InitialState_o;

  // InitializeConditions for DiscreteTransferFcn: '<S264>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states_n[0] =
    TTypeInverter_Imperix_P.GIDifferentiator_InitialState_e;

  // InitializeConditions for DiscreteTransferFcn: '<S32>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states[1] =
    TTypeInverter_Imperix_P.GIDifferentiator_InitialStates;

  // InitializeConditions for DiscreteTransferFcn: '<S148>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states_j[1] =
    TTypeInverter_Imperix_P.GIDifferentiator_InitialState_o;

  // InitializeConditions for DiscreteTransferFcn: '<S264>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states_n[1] =
    TTypeInverter_Imperix_P.GIDifferentiator_InitialState_e;

  // SystemInitialize for Enabled SubSystem: '<S103>/Enabled Subsystem'
  TTypeInve_EnabledSubsystem_Init(TTypeInverter_Imperix_B.Product2_d,
    &TTypeInverter_Imperix_P.EnabledSubsystem);

  // End of SystemInitialize for SubSystem: '<S103>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S97>/MeasurementUpdate'
  TTypeInv_MeasurementUpdate_Init(TTypeInverter_Imperix_B.Product3_f,
    &TTypeInverter_Imperix_P.MeasurementUpdate);

  // End of SystemInitialize for SubSystem: '<S97>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S219>/Enabled Subsystem'
  TTypeInve_EnabledSubsystem_Init(TTypeInverter_Imperix_B.Product2_i,
    &TTypeInverter_Imperix_P.EnabledSubsystem_l);

  // End of SystemInitialize for SubSystem: '<S219>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S213>/MeasurementUpdate'
  TTypeInv_MeasurementUpdate_Init(TTypeInverter_Imperix_B.Product3_h,
    &TTypeInverter_Imperix_P.MeasurementUpdate_f);

  // End of SystemInitialize for SubSystem: '<S213>/MeasurementUpdate'

  // SystemInitialize for Enabled SubSystem: '<S335>/Enabled Subsystem'
  TTypeInve_EnabledSubsystem_Init(TTypeInverter_Imperix_B.Product2,
    &TTypeInverter_Imperix_P.EnabledSubsystem_f);

  // End of SystemInitialize for SubSystem: '<S335>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S329>/MeasurementUpdate'
  TTypeInv_MeasurementUpdate_Init(TTypeInverter_Imperix_B.Product3,
    &TTypeInverter_Imperix_P.MeasurementUpdate_d);

  // End of SystemInitialize for SubSystem: '<S329>/MeasurementUpdate'
  TTypeInverte_MovingAverage_Init(&TTypeInverter_Imperix_DW.MovingAverage);
  TTypeInverte_MovingAverage_Init(&TTypeInverter_Imperix_DW.MovingAverage_p);
  TTypeInverte_MovingAverage_Init(&TTypeInverter_Imperix_DW.MovingAverage_pn);

  // Enable for Sin: '<S31>/Sine Wave'
  TTypeInverter_Imperix_DW.systemEnable = 1;

  // Enable for Sin: '<S147>/Sine Wave'
  TTypeInverter_Imperix_DW.systemEnable_n = 1;

  // Enable for Sin: '<S263>/Sine Wave'
  TTypeInverter_Imperix_DW.systemEnable_a = 1;
}

// Model terminate function
void TTypeInverter_Imperix_terminate(void)
{
  TTypeInverte_MovingAverage_Term(&TTypeInverter_Imperix_DW.MovingAverage);
  TTypeInverte_MovingAverage_Term(&TTypeInverter_Imperix_DW.MovingAverage_p);
  TTypeInverte_MovingAverage_Term(&TTypeInverter_Imperix_DW.MovingAverage_pn);
}

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
