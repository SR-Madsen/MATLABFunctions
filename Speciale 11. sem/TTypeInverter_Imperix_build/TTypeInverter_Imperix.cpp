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
// Model version                  : 14.80
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Dec 15 11:55:42 2022
//
#include "TTypeInverter_Imperix.h"
#include "TTypeInverter_Imperix_types.h"
#include <math.h>
#include "rtwtypes.h"
#include "TTypeInverter_Imperix_private.h"

real32_T iL;                           // Probe
real32_T vc;                           // Probe
real32_T m;                            // Probe
real32_T Batt_P;                       // Probe
real32_T Batt_N;                       // Probe
int16_T* ix_raw_adc_ptr_0_0;
int16_T* ix_raw_adc_ptr_5_0;
int16_T* ix_raw_adc_ptr_3_0;
int16_T* ix_raw_adc_ptr_4_0;
real32_T Kc;                           // Tunable parameter
real32_T Kp;                           // Tunable parameter

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

// Model step function
void TTypeInverter_Imperix_step(void)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real_T lastSin_tmp;
  real32_T rtb_Akxhatkk1[3];
  real32_T tmp[3];
  real32_T rtb_Product[2];
  real32_T rtb_Reshapey[2];
  real32_T csum;
  real32_T cumRevIndex;
  real32_T modValueRev;
  real32_T rtb_Add_j0;
  real32_T rtb_Cdvcdtic;
  real32_T rtb_Sum2;
  real32_T rtb_e_iL;
  real32_T rtb_en;
  real32_T rtb_io;
  real32_T rtb_yn1;
  real32_T rtb_yn1_a;
  real32_T rtb_yn1_am;
  real32_T rtb_yn1_d;
  real32_T rtb_yn1_l;
  real32_T z;

  // S-Function (PROBE): '<S112>/S-Function'
  iL = TTypeInverter_Imperix_B.ADC_h;

  // S-Function (PROBE): '<S114>/S-Function'
  vc = TTypeInverter_Imperix_B.ADC;

  // S-Function (PROBE): '<S116>/S-Function'
  m = TTypeInverter_Imperix_B.Divide;

  // S-Function (PROBE): '<S118>/S-Function'
  Batt_P = TTypeInverter_Imperix_B.ADC_hc;

  // S-Function (PROBE): '<S120>/S-Function'
  Batt_N = TTypeInverter_Imperix_B.ADC_l;

  // S-Function (ADC): '<S21>/ADC'
  TTypeInverter_Imperix_B.ADC = (float)(*ix_raw_adc_ptr_0_0) * 0.012451F + 0.0F;

  // S-Function (ADC): '<S23>/ADC'
  TTypeInverter_Imperix_B.ADC_h = (float)(*ix_raw_adc_ptr_5_0) * 0.0066763F +
    0.0F;

  // S-Function (ADC): '<S25>/ADC'
  TTypeInverter_Imperix_B.ADC_hc = (float)(*ix_raw_adc_ptr_3_0) * 0.012451F +
    0.0F;

  // S-Function (ADC): '<S27>/ADC'
  TTypeInverter_Imperix_B.ADC_l = (float)(*ix_raw_adc_ptr_4_0) * 0.012451F +
    0.0F;

  // Reshape: '<S50>/Reshapey'
  rtb_Reshapey[0] = TTypeInverter_Imperix_B.ADC_h;
  rtb_Reshapey[1] = TTypeInverter_Imperix_B.ADC;

  // Delay: '<S50>/MemoryX' incorporates:
  //   Constant: '<S50>/X0'

  if (TTypeInverter_Imperix_DW.icLoad) {
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[0] =
      TTypeInverter_Imperix_P.X0_Value[0];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[1] =
      TTypeInverter_Imperix_P.X0_Value[1];
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[2] =
      TTypeInverter_Imperix_P.X0_Value[2];
  }

  // Outputs for Enabled SubSystem: '<S77>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S102>/Enable'

  // Constant: '<S50>/Enable'
  if (TTypeInverter_Imperix_P.Enable_Value) {
    TTypeInverter_Imperix_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S102>/Add1' incorporates:
    //   Constant: '<S50>/C'
    //   Delay: '<S50>/MemoryX'
    //   Product: '<S102>/Product'

    for (int32_T i = 0; i < 2; i++) {
      rtb_Product[i] = rtb_Reshapey[i] - ((TTypeInverter_Imperix_P.C_Value[i + 2]
        * TTypeInverter_Imperix_DW.MemoryX_DSTATE[1] +
        TTypeInverter_Imperix_P.C_Value[i] *
        TTypeInverter_Imperix_DW.MemoryX_DSTATE[0]) +
        TTypeInverter_Imperix_P.C_Value[i + 4] *
        TTypeInverter_Imperix_DW.MemoryX_DSTATE[2]);
    }

    // End of Sum: '<S102>/Add1'
    for (int32_T i = 0; i < 3; i++) {
      // Product: '<S102>/Product2' incorporates:
      //   Constant: '<S51>/KalmanGainM'
      //   DataTypeConversion: '<S94>/Conversion'

      TTypeInverter_Imperix_B.Product2[i] = 0.0F;
      TTypeInverter_Imperix_B.Product2[i] += static_cast<real32_T>
        (TTypeInverter_Imperix_P.KalmanGainM_Value[i]) * rtb_Product[0];
      TTypeInverter_Imperix_B.Product2[i] += static_cast<real32_T>
        (TTypeInverter_Imperix_P.KalmanGainM_Value[i + 3]) * rtb_Product[1];
    }
  } else if (TTypeInverter_Imperix_DW.EnabledSubsystem_MODE) {
    // Disable for Product: '<S102>/Product2' incorporates:
    //   Outport: '<S102>/deltax'

    TTypeInverter_Imperix_B.Product2[0] = TTypeInverter_Imperix_P.deltax_Y0;
    TTypeInverter_Imperix_B.Product2[1] = TTypeInverter_Imperix_P.deltax_Y0;
    TTypeInverter_Imperix_B.Product2[2] = TTypeInverter_Imperix_P.deltax_Y0;
    TTypeInverter_Imperix_DW.EnabledSubsystem_MODE = false;
  }

  // End of Outputs for SubSystem: '<S77>/Enabled Subsystem'

  // Sum: '<S77>/Add' incorporates:
  //   Delay: '<S50>/MemoryX'

  rtb_Akxhatkk1[0] = TTypeInverter_Imperix_B.Product2[0] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[0];
  rtb_Akxhatkk1[1] = TTypeInverter_Imperix_B.Product2[1] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[1];
  rtb_Akxhatkk1[2] = TTypeInverter_Imperix_B.Product2[2] +
    TTypeInverter_Imperix_DW.MemoryX_DSTATE[2];

  // Product: '<S52>/Product' incorporates:
  //   Constant: '<S50>/C'

  for (int32_T i = 0; i < 2; i++) {
    rtb_Product[i] = (TTypeInverter_Imperix_P.C_Value[i + 2] * rtb_Akxhatkk1[1]
                      + TTypeInverter_Imperix_P.C_Value[i] * rtb_Akxhatkk1[0]) +
      TTypeInverter_Imperix_P.C_Value[i + 4] * rtb_Akxhatkk1[2];
  }

  // End of Product: '<S52>/Product'

  // S-Function (TUNABLE_PARAM): '<S45>/S-Function'
  TTypeInverter_Imperix_B.SFunction = Kc;

  // S-Function (TUNABLE_PARAM): '<S49>/S-Function'
  TTypeInverter_Imperix_B.SFunction_b = Kp;

  // Sin: '<S9>/Sine Wave'
  if (TTypeInverter_Imperix_DW.systemEnable != 0) {
    lastSin_tmp = TTypeInverter_Imperix_P.f_o * 2.0 * 3.1415926535897931 *
      (((TTypeInverter_Imperix_M->Timing.clockTick0+
         TTypeInverter_Imperix_M->Timing.clockTickH0* 4294967296.0)) *
       1.0416000368143116E-5);
    TTypeInverter_Imperix_DW.lastSin = sin(lastSin_tmp);
    TTypeInverter_Imperix_DW.lastCos = cos(lastSin_tmp);
    TTypeInverter_Imperix_DW.systemEnable = 0;
  }

  // Sum: '<S9>/Sum' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion'
  //   Sin: '<S9>/Sine Wave'

  rtb_Add_j0 = static_cast<real32_T>(((TTypeInverter_Imperix_DW.lastSin *
    TTypeInverter_Imperix_P.SineWave_PCos + TTypeInverter_Imperix_DW.lastCos *
    TTypeInverter_Imperix_P.SineWave_PSin) *
    TTypeInverter_Imperix_P.SineWave_HCos + (TTypeInverter_Imperix_DW.lastCos *
    TTypeInverter_Imperix_P.SineWave_PCos - TTypeInverter_Imperix_DW.lastSin *
    TTypeInverter_Imperix_P.SineWave_PSin) *
    TTypeInverter_Imperix_P.SineWave_Hsin) * TTypeInverter_Imperix_P.Vout_amp +
    TTypeInverter_Imperix_P.SineWave_Bias) - rtb_Product[1];

  // Sum: '<S46>/Sum' incorporates:
  //   Delay: '<S46>/Delay1'
  //   Gain: '<S46>/Klim'

  rtb_en = rtb_Add_j0 - TTypeInverter_Imperix_P.Klim *
    TTypeInverter_Imperix_DW.Delay1_DSTATE;

  // Delay: '<S46>/Delay4'
  rtb_yn1 = TTypeInverter_Imperix_DW.Delay4_DSTATE;

  // Gain: '<S46>/1//b0' incorporates:
  //   Delay: '<S46>/Delay3'
  //   Delay: '<S46>/Delay4'
  //   Delay: '<S46>/Delay5'
  //   Gain: '<S46>/a0'
  //   Gain: '<S46>/a1'
  //   Gain: '<S46>/b1'
  //   Gain: '<S46>/b2'
  //   Sum: '<S46>/Sum3'
  //   Sum: '<S46>/Sum4'
  //   Sum: '<S46>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE = ((TTypeInverter_Imperix_P.a0_Gain *
    rtb_en - TTypeInverter_Imperix_P.a1_Gain *
    TTypeInverter_Imperix_DW.Delay3_DSTATE) + (TTypeInverter_Imperix_P.b1_Gain *
    TTypeInverter_Imperix_DW.Delay4_DSTATE - TTypeInverter_Imperix_P.b2_Gain *
    TTypeInverter_Imperix_DW.Delay5_DSTATE)) * TTypeInverter_Imperix_P.ub0_Gain;

  // Sum: '<S37>/Add' incorporates:
  //   Product: '<S37>/Product'

  rtb_Add_j0 = TTypeInverter_Imperix_B.SFunction_b * rtb_Add_j0 +
    TTypeInverter_Imperix_DW.Delay4_DSTATE;

  // Saturate: '<S37>/Saturation'
  if (rtb_Add_j0 > TTypeInverter_Imperix_P.pr_sat_val) {
    rtb_Cdvcdtic = TTypeInverter_Imperix_P.pr_sat_val;
  } else if (rtb_Add_j0 < TTypeInverter_Imperix_P.Saturation_LowerSat) {
    rtb_Cdvcdtic = TTypeInverter_Imperix_P.Saturation_LowerSat;
  } else {
    rtb_Cdvcdtic = rtb_Add_j0;
  }

  // End of Saturate: '<S37>/Saturation'

  // Sum: '<S9>/Sum3' incorporates:
  //   Sum: '<S10>/Subtract2'
  //   Sum: '<S9>/Sum1'

  rtb_e_iL = ((rtb_Akxhatkk1[0] - rtb_Akxhatkk1[2]) + rtb_Cdvcdtic) -
    rtb_Product[0];

  // MATLAB Function: '<S35>/Variable Gain'
  // MATLAB Function 'Closed_loop_control/Controllers/Current Controller/Variable Gain': '<S43>:1' 
  rtb_yn1_d = static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Product[0])));
  if (rtb_yn1_d <= 218.0F) {
    // '<S43>:1:4'
    // '<S43>:1:5'
    rtb_e_iL -= rtb_e_iL * rtb_yn1_d / 218.0F;
  } else {
    // '<S43>:1:7'
    rtb_e_iL = 0.0F;
  }

  // End of MATLAB Function: '<S35>/Variable Gain'

  // Delay: '<S40>/Delay4'
  rtb_yn1_d = TTypeInverter_Imperix_DW.Delay4_DSTATE_e;

  // Gain: '<S40>/1//b0' incorporates:
  //   Delay: '<S40>/Delay3'
  //   Delay: '<S40>/Delay4'
  //   Delay: '<S40>/Delay5'
  //   Gain: '<S40>/a0'
  //   Gain: '<S40>/a1'
  //   Gain: '<S40>/b1'
  //   Gain: '<S40>/b2'
  //   Sum: '<S40>/Sum3'
  //   Sum: '<S40>/Sum4'
  //   Sum: '<S40>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_e = ((TTypeInverter_Imperix_P.a0_Gain_j
    * rtb_e_iL - TTypeInverter_Imperix_P.a1_Gain_o *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_o) +
    (TTypeInverter_Imperix_P.b1_Gain_o *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_e -
     TTypeInverter_Imperix_P.b2_Gain_c *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_b)) *
    TTypeInverter_Imperix_P.ub0_Gain_m;

  // Delay: '<S41>/Delay4'
  rtb_yn1_a = TTypeInverter_Imperix_DW.Delay4_DSTATE_d;

  // Gain: '<S41>/1//b0' incorporates:
  //   Delay: '<S41>/Delay3'
  //   Delay: '<S41>/Delay4'
  //   Delay: '<S41>/Delay5'
  //   Gain: '<S41>/a0'
  //   Gain: '<S41>/a1'
  //   Gain: '<S41>/b1'
  //   Gain: '<S41>/b2'
  //   Sum: '<S41>/Sum3'
  //   Sum: '<S41>/Sum4'
  //   Sum: '<S41>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_d = ((TTypeInverter_Imperix_P.a0_Gain_m
    * rtb_e_iL - TTypeInverter_Imperix_P.a1_Gain_k *
    TTypeInverter_Imperix_DW.Delay3_DSTATE_p) +
    (TTypeInverter_Imperix_P.b1_Gain_i *
     TTypeInverter_Imperix_DW.Delay4_DSTATE_d -
     TTypeInverter_Imperix_P.b2_Gain_a *
     TTypeInverter_Imperix_DW.Delay5_DSTATE_f)) *
    TTypeInverter_Imperix_P.ub0_Gain_p;

  // Delay: '<S38>/Delay4'
  rtb_yn1_l = TTypeInverter_Imperix_DW.Delay4_DSTATE_dg;

  // Gain: '<S38>/1//b0' incorporates:
  //   Delay: '<S38>/Delay3'
  //   Delay: '<S38>/Delay4'
  //   Delay: '<S38>/Delay5'
  //   Gain: '<S38>/a0'
  //   Gain: '<S38>/a1'
  //   Gain: '<S38>/b1'
  //   Gain: '<S38>/b2'
  //   Sum: '<S38>/Sum3'
  //   Sum: '<S38>/Sum4'
  //   Sum: '<S38>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dg =
    ((TTypeInverter_Imperix_P.a0_Gain_b * rtb_e_iL -
      TTypeInverter_Imperix_P.a1_Gain_c *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_pn) +
     (TTypeInverter_Imperix_P.b1_Gain_p *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_dg -
      TTypeInverter_Imperix_P.b2_Gain_p *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_a)) *
    TTypeInverter_Imperix_P.ub0_Gain_mq;

  // Delay: '<S39>/Delay4'
  rtb_yn1_am = TTypeInverter_Imperix_DW.Delay4_DSTATE_dh;

  // Gain: '<S39>/1//b0' incorporates:
  //   Delay: '<S39>/Delay3'
  //   Delay: '<S39>/Delay4'
  //   Delay: '<S39>/Delay5'
  //   Gain: '<S39>/a0'
  //   Gain: '<S39>/a1'
  //   Gain: '<S39>/b1'
  //   Gain: '<S39>/b2'
  //   Sum: '<S39>/Sum3'
  //   Sum: '<S39>/Sum4'
  //   Sum: '<S39>/Sum5'

  TTypeInverter_Imperix_DW.Delay4_DSTATE_dh =
    ((TTypeInverter_Imperix_P.a0_Gain_g * rtb_e_iL -
      TTypeInverter_Imperix_P.a1_Gain_op *
      TTypeInverter_Imperix_DW.Delay3_DSTATE_b) +
     (TTypeInverter_Imperix_P.b1_Gain_l *
      TTypeInverter_Imperix_DW.Delay4_DSTATE_dh -
      TTypeInverter_Imperix_P.b2_Gain_j *
      TTypeInverter_Imperix_DW.Delay5_DSTATE_l)) *
    TTypeInverter_Imperix_P.ub0_Gain_k;

  // Sum: '<S9>/Sum2' incorporates:
  //   Gain: '<S9>/Gain1'
  //   Product: '<S35>/P Controller'
  //   Sum: '<S35>/Add'

  rtb_Sum2 = (((((TTypeInverter_Imperix_B.SFunction * rtb_e_iL +
                  TTypeInverter_Imperix_DW.Delay4_DSTATE_e) +
                 TTypeInverter_Imperix_DW.Delay4_DSTATE_d) +
                TTypeInverter_Imperix_DW.Delay4_DSTATE_dg) +
               TTypeInverter_Imperix_DW.Delay4_DSTATE_dh) +
              TTypeInverter_Imperix_P.R_Lc * rtb_Product[0]) + rtb_Product[1];

  // Switch: '<S36>/Switch2' incorporates:
  //   RelationalOperator: '<S36>/LowerRelop1'
  //   RelationalOperator: '<S36>/UpperRelop'
  //   Switch: '<S36>/Switch'

  if (rtb_Sum2 > TTypeInverter_Imperix_B.ADC_hc) {
    rtb_Sum2 = TTypeInverter_Imperix_B.ADC_hc;
  } else if (rtb_Sum2 < TTypeInverter_Imperix_B.ADC_l) {
    // Switch: '<S36>/Switch'
    rtb_Sum2 = TTypeInverter_Imperix_B.ADC_l;
  }

  // End of Switch: '<S36>/Switch2'

  // Product: '<S9>/Divide'
  TTypeInverter_Imperix_B.Divide = 1.0F / TTypeInverter_Imperix_B.ADC_hc *
    rtb_Sum2;

  // Saturate: '<S29>/Saturation'
  if (TTypeInverter_Imperix_P.Saturation_UpperSat < 0.0F) {
    // Saturate: '<S29>/Saturation'
    TTypeInverter_Imperix_B.Saturation =
      TTypeInverter_Imperix_P.Saturation_UpperSat;
  } else if (TTypeInverter_Imperix_P.Saturation_LowerSat_n > 0.0F) {
    // Saturate: '<S29>/Saturation'
    TTypeInverter_Imperix_B.Saturation =
      TTypeInverter_Imperix_P.Saturation_LowerSat_n;
  } else {
    // Saturate: '<S29>/Saturation'
    TTypeInverter_Imperix_B.Saturation = 0.0F;
  }

  // End of Saturate: '<S29>/Saturation'
  // Sum: '<S37>/Sum1' incorporates:
  //   Delay: '<S46>/Delay1'

  TTypeInverter_Imperix_DW.Delay1_DSTATE = rtb_Add_j0 - rtb_Cdvcdtic;

  // DiscreteTransferFcn: '<S10>/GI Differentiator'
  rtb_Add_j0 = ((TTypeInverter_Imperix_B.ADC -
                 TTypeInverter_Imperix_DW.GIDifferentiator_states[0] *
                 TTypeInverter_Imperix_P.GIDifferentiator_DenCoef[1]) -
                TTypeInverter_Imperix_DW.GIDifferentiator_states[1] *
                TTypeInverter_Imperix_P.GIDifferentiator_DenCoef[2]) /
    TTypeInverter_Imperix_P.GIDifferentiator_DenCoef[0];

  // Sum: '<S10>/Add' incorporates:
  //   DiscreteTransferFcn: '<S10>/GI Differentiator'

  rtb_io = TTypeInverter_Imperix_B.ADC_h -
    ((TTypeInverter_Imperix_P.GIDifferentiator_NumCoef[0] * rtb_Add_j0 +
      TTypeInverter_Imperix_DW.GIDifferentiator_states[0] *
      TTypeInverter_Imperix_P.GIDifferentiator_NumCoef[1]) +
     TTypeInverter_Imperix_DW.GIDifferentiator_states[1] *
     TTypeInverter_Imperix_P.GIDifferentiator_NumCoef[2]);

  // MATLABSystem: '<S10>/Moving Average'
  // MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S99>:1' 
  if (TTypeInverter_Imperix_DW.obj.TunablePropsChanged) {
    TTypeInverter_Imperix_DW.obj.TunablePropsChanged = false;
  }

  obj = TTypeInverter_Imperix_DW.obj.pStatistic;
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
  rtb_Akxhatkk1[0] = obj->pCumSumRev[0];
  rtb_Akxhatkk1[1] = obj->pCumSumRev[1];
  rtb_Akxhatkk1[2] = obj->pCumSumRev[2];
  modValueRev = obj->pModValueRev;
  z = 0.0F;
  rtb_Cdvcdtic = 0.0F;
  csum += rtb_io;
  if (modValueRev == 0.0F) {
    z = rtb_Akxhatkk1[static_cast<int32_T>(cumRevIndex) - 1] + csum;
  }

  rtb_Akxhatkk1[static_cast<int32_T>(cumRevIndex) - 1] = rtb_io;
  if (cumRevIndex != 3.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    rtb_Akxhatkk1[1] += rtb_Akxhatkk1[2];
    rtb_Akxhatkk1[0] += rtb_Akxhatkk1[1];
  }

  if (modValueRev == 0.0F) {
    rtb_Cdvcdtic = z / 4.0F;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = rtb_Akxhatkk1[0];
  obj->pCumSumRev[1] = rtb_Akxhatkk1[1];
  obj->pCumSumRev[2] = rtb_Akxhatkk1[2];
  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0F) {
    obj->pModValueRev = modValueRev - 1.0F;
  } else {
    obj->pModValueRev = 0.0F;
  }

  // Outputs for Enabled SubSystem: '<S71>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S100>/Enable'

  // Constant: '<S50>/Enable'
  if (TTypeInverter_Imperix_P.Enable_Value) {
    TTypeInverter_Imperix_DW.MeasurementUpdate_MODE = true;
    for (int32_T i = 0; i < 2; i++) {
      // Sum: '<S100>/Sum' incorporates:
      //   Constant: '<S50>/C'
      //   Constant: '<S50>/D'
      //   Delay: '<S50>/MemoryX'
      //   MATLABSystem: '<S10>/Moving Average'
      //   Product: '<S100>/C[k]*xhat[k|k-1]'
      //   Product: '<S100>/D[k]*u[k]'
      //   Reshape: '<S50>/Reshapeu'
      //   Sum: '<S100>/Add1'

      rtb_Product[i] = rtb_Reshapey[i] - (((TTypeInverter_Imperix_P.C_Value[i +
        2] * TTypeInverter_Imperix_DW.MemoryX_DSTATE[1] +
        TTypeInverter_Imperix_P.C_Value[i] *
        TTypeInverter_Imperix_DW.MemoryX_DSTATE[0]) +
        TTypeInverter_Imperix_P.C_Value[i + 4] *
        TTypeInverter_Imperix_DW.MemoryX_DSTATE[2]) +
        (TTypeInverter_Imperix_P.D_Value[i + 2] * rtb_Cdvcdtic +
         TTypeInverter_Imperix_P.D_Value[i] * rtb_Sum2));
    }

    for (int32_T i = 0; i < 3; i++) {
      // Product: '<S100>/Product3' incorporates:
      //   Constant: '<S51>/KalmanGainL'
      //   DataTypeConversion: '<S93>/Conversion'

      TTypeInverter_Imperix_B.Product3[i] = 0.0F;
      TTypeInverter_Imperix_B.Product3[i] += static_cast<real32_T>
        (TTypeInverter_Imperix_P.KalmanGainL_Value[i]) * rtb_Product[0];
      TTypeInverter_Imperix_B.Product3[i] += static_cast<real32_T>
        (TTypeInverter_Imperix_P.KalmanGainL_Value[i + 3]) * rtb_Product[1];
    }
  } else if (TTypeInverter_Imperix_DW.MeasurementUpdate_MODE) {
    // Disable for Product: '<S100>/Product3' incorporates:
    //   Outport: '<S100>/L*(y[k]-yhat[k|k-1])'

    TTypeInverter_Imperix_B.Product3[0] = TTypeInverter_Imperix_P.Lykyhatkk1_Y0;
    TTypeInverter_Imperix_B.Product3[1] = TTypeInverter_Imperix_P.Lykyhatkk1_Y0;
    TTypeInverter_Imperix_B.Product3[2] = TTypeInverter_Imperix_P.Lykyhatkk1_Y0;
    TTypeInverter_Imperix_DW.MeasurementUpdate_MODE = false;
  }

  // End of Outputs for SubSystem: '<S71>/MeasurementUpdate'

  // DataTypeConversion: '<S11>/Data Type Conversion2' incorporates:
  //   Constant: '<S11>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2 = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value);

  // DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
  //   Constant: '<S11>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3 = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value);

  // Outputs for Atomic SubSystem: '<S103>/generation'
  // S-Function (CB_PWM): '<S104>/PWM' incorporates:
  //   Constant: '<S29>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 0, TTypeInverter_Imperix_B.Divide, 0);

  // End of Outputs for SubSystem: '<S103>/generation'

  // DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
  //   Constant: '<S1>/Constant2'
  //   Sum: '<S1>/Add'

  TTypeInverter_Imperix_B.DataTypeConversion1 = static_cast<real32_T>
    (TTypeInverter_Imperix_B.Divide + TTypeInverter_Imperix_P.Constant2_Value);

  // DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
  //   Constant: '<S12>/phase'

  TTypeInverter_Imperix_B.DataTypeConversion2_l = static_cast<real32_T>
    (TTypeInverter_Imperix_P.phase_Value_j);

  // DataTypeConversion: '<S12>/Data Type Conversion3' incorporates:
  //   Constant: '<S12>/enable'

  TTypeInverter_Imperix_B.DataTypeConversion3_e = static_cast<real32_T>
    (TTypeInverter_Imperix_P.enable_Value_o);

  // Outputs for Atomic SubSystem: '<S105>/generation'
  // S-Function (CB_PWM): '<S106>/PWM' incorporates:
  //   Constant: '<S29>/clk_id'

  CbPwm_SetDutyCycle((tPwmOutput) 2, TTypeInverter_Imperix_B.DataTypeConversion1,
                     0);

  // End of Outputs for SubSystem: '<S105>/generation'

  // DataTypeConversion: '<S13>/Cast' incorporates:
  //   Constant: '<S13>/activate'

  TTypeInverter_Imperix_B.Cast = static_cast<real32_T>
    (TTypeInverter_Imperix_P.activate_Value);

  // DataTypeConversion: '<S13>/Cast1' incorporates:
  //   Constant: '<S1>/Constant3'

  TTypeInverter_Imperix_B.Cast1 = static_cast<real32_T>
    (TTypeInverter_Imperix_P.Constant3_Value);

  // Outputs for Atomic SubSystem: '<S107>/generation'
  // S-Function (DO_PWM): '<S108>/DO_PWM'
  if (TTypeInverter_Imperix_B.Cast1 > 0.0) {
    DoPwm_SetOn((tPwmOutput) 12, 0);
  } else {
    DoPwm_SetOff((tPwmOutput) 12, 0);
  }

  // End of Outputs for SubSystem: '<S107>/generation'

  // DataTypeConversion: '<S14>/Cast' incorporates:
  //   Constant: '<S14>/activate'

  TTypeInverter_Imperix_B.Cast_m = static_cast<real32_T>
    (TTypeInverter_Imperix_P.activate_Value_f);

  // DataTypeConversion: '<S14>/Cast1' incorporates:
  //   Constant: '<S1>/Constant3'
  //   DataTypeConversion: '<S13>/Cast1'

  TTypeInverter_Imperix_B.Cast1_e = static_cast<real32_T>
    (TTypeInverter_Imperix_P.Constant3_Value);

  // Outputs for Atomic SubSystem: '<S109>/generation'
  // S-Function (DO_PWM): '<S110>/DO_PWM'
  if (TTypeInverter_Imperix_B.Cast1_e > 0.0) {
    DoPwm_SetOn((tPwmOutput) 13, 0);
  } else {
    DoPwm_SetOff((tPwmOutput) 13, 0);
  }

  // End of Outputs for SubSystem: '<S109>/generation'

  // Update for Delay: '<S50>/MemoryX'
  TTypeInverter_Imperix_DW.icLoad = false;
  for (int32_T i = 0; i < 3; i++) {
    // Product: '<S71>/B[k]*u[k]' incorporates:
    //   Constant: '<S50>/B'
    //   MATLABSystem: '<S10>/Moving Average'
    //   Reshape: '<S50>/Reshapeu'

    rtb_Akxhatkk1[i] = TTypeInverter_Imperix_P.B_Value[i + 3] * rtb_Cdvcdtic +
      TTypeInverter_Imperix_P.B_Value[i] * rtb_Sum2;

    // Product: '<S71>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S50>/A'
    //   Delay: '<S50>/MemoryX'

    tmp[i] = (TTypeInverter_Imperix_P.A_Value[i + 3] *
              TTypeInverter_Imperix_DW.MemoryX_DSTATE[1] +
              TTypeInverter_Imperix_P.A_Value[i] *
              TTypeInverter_Imperix_DW.MemoryX_DSTATE[0]) +
      TTypeInverter_Imperix_P.A_Value[i + 6] *
      TTypeInverter_Imperix_DW.MemoryX_DSTATE[2];
  }

  // Update for Delay: '<S50>/MemoryX' incorporates:
  //   Sum: '<S71>/Add'

  TTypeInverter_Imperix_DW.MemoryX_DSTATE[0] = (rtb_Akxhatkk1[0] + tmp[0]) +
    TTypeInverter_Imperix_B.Product3[0];
  TTypeInverter_Imperix_DW.MemoryX_DSTATE[1] = (rtb_Akxhatkk1[1] + tmp[1]) +
    TTypeInverter_Imperix_B.Product3[1];
  TTypeInverter_Imperix_DW.MemoryX_DSTATE[2] = (rtb_Akxhatkk1[2] + tmp[2]) +
    TTypeInverter_Imperix_B.Product3[2];

  // Update for Sin: '<S9>/Sine Wave'
  lastSin_tmp = TTypeInverter_Imperix_DW.lastSin;
  TTypeInverter_Imperix_DW.lastSin = TTypeInverter_Imperix_DW.lastSin *
    TTypeInverter_Imperix_P.SineWave_HCos + TTypeInverter_Imperix_DW.lastCos *
    TTypeInverter_Imperix_P.SineWave_Hsin;
  TTypeInverter_Imperix_DW.lastCos = TTypeInverter_Imperix_DW.lastCos *
    TTypeInverter_Imperix_P.SineWave_HCos - lastSin_tmp *
    TTypeInverter_Imperix_P.SineWave_Hsin;

  // Update for Delay: '<S46>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE = rtb_en;

  // Update for Delay: '<S46>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE = rtb_yn1;

  // Update for Delay: '<S40>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_o = rtb_e_iL;

  // Update for Delay: '<S40>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_b = rtb_yn1_d;

  // Update for Delay: '<S41>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_p = rtb_e_iL;

  // Update for Delay: '<S41>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_f = rtb_yn1_a;

  // Update for Delay: '<S38>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_pn = rtb_e_iL;

  // Update for Delay: '<S38>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_a = rtb_yn1_l;

  // Update for Delay: '<S39>/Delay3'
  TTypeInverter_Imperix_DW.Delay3_DSTATE_b = rtb_e_iL;

  // Update for Delay: '<S39>/Delay5'
  TTypeInverter_Imperix_DW.Delay5_DSTATE_l = rtb_yn1_am;

  // Update for DiscreteTransferFcn: '<S10>/GI Differentiator'
  TTypeInverter_Imperix_DW.GIDifferentiator_states[1] =
    TTypeInverter_Imperix_DW.GIDifferentiator_states[0];
  TTypeInverter_Imperix_DW.GIDifferentiator_states[0] = rtb_Add_j0;

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
  {
    g_dsp_internal_SlidingWindowA_T *obj;

    // Start for S-Function (PROBE): '<S112>/S-Function'
    ConfigureProbe(&iL, 0);

    // Start for S-Function (PROBE): '<S114>/S-Function'
    ConfigureProbe(&vc, 0);

    // Start for S-Function (PROBE): '<S116>/S-Function'
    ConfigureProbe(&m, 0);

    // Start for S-Function (PROBE): '<S118>/S-Function'
    ConfigureProbe(&Batt_P, 0);

    // Start for S-Function (PROBE): '<S120>/S-Function'
    ConfigureProbe(&Batt_N, 0);

    // Start for S-Function (ADC): '<S21>/ADC'
    Adc_ConfigureInput(0, 0.012451F, 0.0F, 0);
    Adc_GetPointer(0, 0, &ix_raw_adc_ptr_0_0);

    // Start for S-Function (ADC): '<S23>/ADC'
    Adc_ConfigureInput(5, 0.0066763F, 0.0F, 0);
    Adc_GetPointer(5, 0, &ix_raw_adc_ptr_5_0);

    // Start for S-Function (ADC): '<S25>/ADC'
    Adc_ConfigureInput(3, 0.012451F, 0.0F, 0);
    Adc_GetPointer(3, 0, &ix_raw_adc_ptr_3_0);

    // Start for S-Function (ADC): '<S27>/ADC'
    Adc_ConfigureInput(4, 0.012451F, 0.0F, 0);
    Adc_GetPointer(4, 0, &ix_raw_adc_ptr_4_0);

    // Start for S-Function (TUNABLE_PARAM): '<S45>/S-Function'
    Kc = 2.5F;                         // Tunable parameter initialization
    ConfigureTunable(&Kc, 0, 0, 0.0F, 5.0F);

    // Start for S-Function (TUNABLE_PARAM): '<S49>/S-Function'
    Kp = 0.9444F;                      // Tunable parameter initialization
    ConfigureTunable(&Kp, 0, 0, 0.0F, 5.0F);

    // Start for S-Function (CLK): '<S29>/CLK1'
    Clock_SetFrequency((tClock) 1, 24000.0F);

    // Start for S-Function (IRQ): '<S32>/S-Function' incorporates:
    //   Constant: '<S34>/clk_id'

    ConfigureMainInterrupt(SimulinkInterrupt, (tClock)
      TTypeInverter_Imperix_P.clk_id_Value_o, 0.0F, 0U);
    Adc_AddSamplingEvent((TTypeInverter_Imperix_P.SFunction_P2));
    ConfigureReadTriggerDelayInNs(500U);

    // Start for S-Function (CLK): '<S34>/CLK1'
    Clock_SetFrequency((tClock) 0, 96006.1406F);

    // Start for MATLABSystem: '<S10>/Moving Average'
    TTypeInverter_Imperix_DW.obj.isInitialized = 0;
    TTypeInverter_Imperix_DW.obj.NumChannels = -1;
    TTypeInverter_Imperix_DW.obj.FrameLength = -1;
    TTypeInverter_Imperix_DW.obj.matlabCodegenIsDeleted = false;
    TTypeInverter__SystemCore_setup(&TTypeInverter_Imperix_DW.obj);

    // Start for Atomic SubSystem: '<S103>/generation'
    // Start for S-Function (CB_PWM): '<S104>/PWM' incorporates:
    //   Constant: '<S29>/clk_id'

    CbPwm_ConfigureClock((tPwmOutput) 0, (tClock)
                         TTypeInverter_Imperix_P.clk_id_Value, 0);
    CbPwm_ConfigureOutputMode((tPwmOutput) 0, (tPwmOutMode) 0, 0);
    CbPwm_ConfigureCarrier((tPwmOutput) 0, (tPwmCarrier) 0, 0);
    CbPwm_ConfigureDeadTime((tPwmOutput) 0, 1.0E-6F, 0);
    CbPwm_ConfigureUpdateRate((tPwmOutput) 0, (tPwmRate) 1, 0);
    CbPwm_SetPhase((tPwmOutput) 0, 0.0F, 0);
    CbPwm_SetDutyCycle((tPwmOutput) 0, 0.0F, 0);
    CbPwm_Activate((tPwmOutput) 0, 0);

    // End of Start for SubSystem: '<S103>/generation'

    // Start for Atomic SubSystem: '<S105>/generation'
    // Start for S-Function (CB_PWM): '<S106>/PWM' incorporates:
    //   Constant: '<S29>/clk_id'

    CbPwm_ConfigureClock((tPwmOutput) 2, (tClock)
                         TTypeInverter_Imperix_P.clk_id_Value, 0);
    CbPwm_ConfigureOutputMode((tPwmOutput) 2, (tPwmOutMode) 0, 0);
    CbPwm_ConfigureCarrier((tPwmOutput) 2, (tPwmCarrier) 0, 0);
    CbPwm_ConfigureDeadTime((tPwmOutput) 2, 1.0E-6F, 0);
    CbPwm_ConfigureUpdateRate((tPwmOutput) 2, (tPwmRate) 1, 0);
    CbPwm_SetPhase((tPwmOutput) 2, 0.0F, 0);
    CbPwm_SetDutyCycle((tPwmOutput) 2, 0.0F, 0);
    CbPwm_Activate((tPwmOutput) 2, 0);

    // End of Start for SubSystem: '<S105>/generation'

    // Start for Atomic SubSystem: '<S107>/generation'
    // Start for S-Function (DO_PWM): '<S108>/DO_PWM'
    DoPwm_ConfigureOutputMode((tPwmOutput) 12, (tPwmOutMode) 2, 0);
    DoPwm_Activate((tPwmOutput) 12, 0);

    // End of Start for SubSystem: '<S107>/generation'

    // Start for Atomic SubSystem: '<S109>/generation'
    // Start for S-Function (DO_PWM): '<S110>/DO_PWM'
    DoPwm_ConfigureOutputMode((tPwmOutput) 13, (tPwmOutMode) 2, 0);
    DoPwm_Activate((tPwmOutput) 13, 0);

    // End of Start for SubSystem: '<S109>/generation'

    // InitializeConditions for Delay: '<S50>/MemoryX'
    TTypeInverter_Imperix_DW.icLoad = true;

    // InitializeConditions for Delay: '<S46>/Delay1'
    TTypeInverter_Imperix_DW.Delay1_DSTATE =
      TTypeInverter_Imperix_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S46>/Delay3'
    TTypeInverter_Imperix_DW.Delay3_DSTATE =
      TTypeInverter_Imperix_P.Delay3_InitialCondition;

    // InitializeConditions for Gain: '<S46>/1//b0' incorporates:
    //   Delay: '<S46>/Delay4'

    TTypeInverter_Imperix_DW.Delay4_DSTATE =
      TTypeInverter_Imperix_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S46>/Delay5'
    TTypeInverter_Imperix_DW.Delay5_DSTATE =
      TTypeInverter_Imperix_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S40>/Delay3'
    TTypeInverter_Imperix_DW.Delay3_DSTATE_o =
      TTypeInverter_Imperix_P.Delay3_InitialCondition_c;

    // InitializeConditions for Gain: '<S40>/1//b0' incorporates:
    //   Delay: '<S40>/Delay4'

    TTypeInverter_Imperix_DW.Delay4_DSTATE_e =
      TTypeInverter_Imperix_P.Delay4_InitialCondition_f;

    // InitializeConditions for Delay: '<S40>/Delay5'
    TTypeInverter_Imperix_DW.Delay5_DSTATE_b =
      TTypeInverter_Imperix_P.Delay5_InitialCondition_l;

    // InitializeConditions for Delay: '<S41>/Delay3'
    TTypeInverter_Imperix_DW.Delay3_DSTATE_p =
      TTypeInverter_Imperix_P.Delay3_InitialCondition_p;

    // InitializeConditions for Gain: '<S41>/1//b0' incorporates:
    //   Delay: '<S41>/Delay4'

    TTypeInverter_Imperix_DW.Delay4_DSTATE_d =
      TTypeInverter_Imperix_P.Delay4_InitialCondition_m;

    // InitializeConditions for Delay: '<S41>/Delay5'
    TTypeInverter_Imperix_DW.Delay5_DSTATE_f =
      TTypeInverter_Imperix_P.Delay5_InitialCondition_o;

    // InitializeConditions for Delay: '<S38>/Delay3'
    TTypeInverter_Imperix_DW.Delay3_DSTATE_pn =
      TTypeInverter_Imperix_P.Delay3_InitialCondition_d;

    // InitializeConditions for Gain: '<S38>/1//b0' incorporates:
    //   Delay: '<S38>/Delay4'

    TTypeInverter_Imperix_DW.Delay4_DSTATE_dg =
      TTypeInverter_Imperix_P.Delay4_InitialCondition_fy;

    // InitializeConditions for Delay: '<S38>/Delay5'
    TTypeInverter_Imperix_DW.Delay5_DSTATE_a =
      TTypeInverter_Imperix_P.Delay5_InitialCondition_e;

    // InitializeConditions for Delay: '<S39>/Delay3'
    TTypeInverter_Imperix_DW.Delay3_DSTATE_b =
      TTypeInverter_Imperix_P.Delay3_InitialCondition_dr;

    // InitializeConditions for Gain: '<S39>/1//b0' incorporates:
    //   Delay: '<S39>/Delay4'

    TTypeInverter_Imperix_DW.Delay4_DSTATE_dh =
      TTypeInverter_Imperix_P.Delay4_InitialCondition_fyn;

    // InitializeConditions for Delay: '<S39>/Delay5'
    TTypeInverter_Imperix_DW.Delay5_DSTATE_l =
      TTypeInverter_Imperix_P.Delay5_InitialCondition_ew;

    // InitializeConditions for DiscreteTransferFcn: '<S10>/GI Differentiator'
    TTypeInverter_Imperix_DW.GIDifferentiator_states[0] =
      TTypeInverter_Imperix_P.GIDifferentiator_InitialStates;
    TTypeInverter_Imperix_DW.GIDifferentiator_states[1] =
      TTypeInverter_Imperix_P.GIDifferentiator_InitialStates;

    // SystemInitialize for Enabled SubSystem: '<S77>/Enabled Subsystem'
    // SystemInitialize for Product: '<S102>/Product2' incorporates:
    //   Outport: '<S102>/deltax'

    TTypeInverter_Imperix_B.Product2[0] = TTypeInverter_Imperix_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S77>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S71>/MeasurementUpdate'
    // SystemInitialize for Product: '<S100>/Product3' incorporates:
    //   Outport: '<S100>/L*(y[k]-yhat[k|k-1])'

    TTypeInverter_Imperix_B.Product3[0] = TTypeInverter_Imperix_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S71>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S77>/Enabled Subsystem'
    // SystemInitialize for Product: '<S102>/Product2' incorporates:
    //   Outport: '<S102>/deltax'

    TTypeInverter_Imperix_B.Product2[1] = TTypeInverter_Imperix_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S77>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S71>/MeasurementUpdate'
    // SystemInitialize for Product: '<S100>/Product3' incorporates:
    //   Outport: '<S100>/L*(y[k]-yhat[k|k-1])'

    TTypeInverter_Imperix_B.Product3[1] = TTypeInverter_Imperix_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S71>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S77>/Enabled Subsystem'
    // SystemInitialize for Product: '<S102>/Product2' incorporates:
    //   Outport: '<S102>/deltax'

    TTypeInverter_Imperix_B.Product2[2] = TTypeInverter_Imperix_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S77>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S71>/MeasurementUpdate'
    // SystemInitialize for Product: '<S100>/Product3' incorporates:
    //   Outport: '<S100>/L*(y[k]-yhat[k|k-1])'

    TTypeInverter_Imperix_B.Product3[2] = TTypeInverter_Imperix_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S71>/MeasurementUpdate'

    // InitializeConditions for MATLABSystem: '<S10>/Moving Average'
    obj = TTypeInverter_Imperix_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0F;
      obj->pCumSumRev[0] = 0.0F;
      obj->pCumSumRev[1] = 0.0F;
      obj->pCumSumRev[2] = 0.0F;
      obj->pCumRevIndex = 1.0F;
      obj->pModValueRev = 0.0F;
    }

    // End of InitializeConditions for MATLABSystem: '<S10>/Moving Average'

    // Enable for Sin: '<S9>/Sine Wave'
    TTypeInverter_Imperix_DW.systemEnable = 1;
  }
}

// Model terminate function
void TTypeInverter_Imperix_terminate(void)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  // Terminate for MATLABSystem: '<S10>/Moving Average'
  if (!TTypeInverter_Imperix_DW.obj.matlabCodegenIsDeleted) {
    TTypeInverter_Imperix_DW.obj.matlabCodegenIsDeleted = true;
    if ((TTypeInverter_Imperix_DW.obj.isInitialized == 1) &&
        TTypeInverter_Imperix_DW.obj.isSetupComplete) {
      obj = TTypeInverter_Imperix_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      TTypeInverter_Imperix_DW.obj.NumChannels = -1;
      TTypeInverter_Imperix_DW.obj.FrameLength = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S10>/Moving Average'
}

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
