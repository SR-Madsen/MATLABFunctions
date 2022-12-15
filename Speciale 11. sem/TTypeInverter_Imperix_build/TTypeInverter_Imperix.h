//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TTypeInverter_Imperix.h
//
// Code generated for Simulink model 'TTypeInverter_Imperix'.
// To be implemented on the B-Box RCP or the B-Board PRO.
//
// Model version                  : 14.80
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Dec 15 11:55:42 2022
//
#ifndef RTW_HEADER_TTypeInverter_Imperix_h_
#define RTW_HEADER_TTypeInverter_Imperix_h_
#include "rtwtypes.h"
#include "TTypeInverter_Imperix_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_TTypeInverter_Imperix_T {
  real32_T ADC;                        // '<S21>/ADC'
  real32_T ADC_h;                      // '<S23>/ADC'
  real32_T ADC_hc;                     // '<S25>/ADC'
  real32_T ADC_l;                      // '<S27>/ADC'
  real32_T SFunction;                  // '<S45>/S-Function'
  real32_T SFunction_b;                // '<S49>/S-Function'
  real32_T Divide;                     // '<S9>/Divide'
  real32_T Saturation;                 // '<S29>/Saturation'
  real32_T DataTypeConversion2;        // '<S11>/Data Type Conversion2'
  real32_T DataTypeConversion3;        // '<S11>/Data Type Conversion3'
  real32_T DataTypeConversion1;        // '<S12>/Data Type Conversion1'
  real32_T DataTypeConversion2_l;      // '<S12>/Data Type Conversion2'
  real32_T DataTypeConversion3_e;      // '<S12>/Data Type Conversion3'
  real32_T Cast;                       // '<S13>/Cast'
  real32_T Cast1;                      // '<S13>/Cast1'
  real32_T Cast_m;                     // '<S14>/Cast'
  real32_T Cast1_e;                    // '<S14>/Cast1'
  real32_T Product2[3];                // '<S102>/Product2'
  real32_T Product3[3];                // '<S100>/Product3'
};

// Block states (default storage) for system '<Root>'
struct DW_TTypeInverter_Imperix_T {
  dsp_simulink_MovingAverage_TT_T obj; // '<S10>/Moving Average'
  real_T SFunction_DSTATE;             // '<S112>/S-Function'
  real_T SFunction_DSTATE_n;           // '<S114>/S-Function'
  real_T SFunction_DSTATE_b;           // '<S116>/S-Function'
  real_T SFunction_DSTATE_p;           // '<S118>/S-Function'
  real_T SFunction_DSTATE_m;           // '<S120>/S-Function'
  real_T SFunction_DSTATE_c;           // '<S45>/S-Function'
  real_T SFunction_DSTATE_ce;          // '<S49>/S-Function'
  real_T SFunction_DSTATE_n5;          // '<S32>/S-Function'
  real_T lastSin;                      // '<S9>/Sine Wave'
  real_T lastCos;                      // '<S9>/Sine Wave'
  real32_T MemoryX_DSTATE[3];          // '<S50>/MemoryX'
  real32_T Delay1_DSTATE;              // '<S46>/Delay1'
  real32_T Delay3_DSTATE;              // '<S46>/Delay3'
  real32_T Delay4_DSTATE;              // '<S46>/Delay4'
  real32_T Delay5_DSTATE;              // '<S46>/Delay5'
  real32_T Delay3_DSTATE_o;            // '<S40>/Delay3'
  real32_T Delay4_DSTATE_e;            // '<S40>/Delay4'
  real32_T Delay5_DSTATE_b;            // '<S40>/Delay5'
  real32_T Delay3_DSTATE_p;            // '<S41>/Delay3'
  real32_T Delay4_DSTATE_d;            // '<S41>/Delay4'
  real32_T Delay5_DSTATE_f;            // '<S41>/Delay5'
  real32_T Delay3_DSTATE_pn;           // '<S38>/Delay3'
  real32_T Delay4_DSTATE_dg;           // '<S38>/Delay4'
  real32_T Delay5_DSTATE_a;            // '<S38>/Delay5'
  real32_T Delay3_DSTATE_b;            // '<S39>/Delay3'
  real32_T Delay4_DSTATE_dh;           // '<S39>/Delay4'
  real32_T Delay5_DSTATE_l;            // '<S39>/Delay5'
  real32_T GIDifferentiator_states[2]; // '<S10>/GI Differentiator'
  int32_T systemEnable;                // '<S9>/Sine Wave'
  boolean_T icLoad;                    // '<S50>/MemoryX'
  boolean_T EnabledSubsystem_MODE;     // '<S77>/Enabled Subsystem'
  boolean_T MeasurementUpdate_MODE;    // '<S71>/MeasurementUpdate'
};

// Parameters (default storage)
struct P_TTypeInverter_Imperix_T_ {
  real_T Vout_amp;                     // Variable: Vout_amp
                                          //  Referenced by: '<S9>/Sine Wave'

  real_T f_o;                          // Variable: f_o
                                          //  Referenced by: '<S9>/Sine Wave'

  real32_T Klim;                       // Variable: Klim
                                          //  Referenced by: '<S46>/Klim'

  real32_T R_Lc;                       // Variable: R_Lc
                                          //  Referenced by: '<S9>/Gain1'

  real32_T pr_sat_val;                 // Variable: pr_sat_val
                                          //  Referenced by: '<S37>/Saturation'

  real_T KalmanGainM_Value[6];         // Expression: pInitialization.M
                                          //  Referenced by: '<S51>/KalmanGainM'

  real_T SineWave_Bias;                // Expression: 0
                                          //  Referenced by: '<S9>/Sine Wave'

  real_T SineWave_Hsin;                // Computed Parameter: SineWave_Hsin
                                          //  Referenced by: '<S9>/Sine Wave'

  real_T SineWave_HCos;                // Computed Parameter: SineWave_HCos
                                          //  Referenced by: '<S9>/Sine Wave'

  real_T SineWave_PSin;                // Computed Parameter: SineWave_PSin
                                          //  Referenced by: '<S9>/Sine Wave'

  real_T SineWave_PCos;                // Computed Parameter: SineWave_PCos
                                          //  Referenced by: '<S9>/Sine Wave'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<S1>/Constant2'

  real_T CovarianceZ_Value[9];         // Expression: pInitialization.Z
                                          //  Referenced by: '<S51>/CovarianceZ'

  real_T KalmanGainL_Value[6];         // Expression: pInitialization.L
                                          //  Referenced by: '<S51>/KalmanGainL'

  real_T phase_Value;                  // Expression: PHASE
                                          //  Referenced by: '<S11>/phase'

  real_T enable_Value;                 // Expression: 1
                                          //  Referenced by: '<S11>/enable'

  real_T phase_Value_j;                // Expression: PHASE
                                          //  Referenced by: '<S12>/phase'

  real_T enable_Value_o;               // Expression: 1
                                          //  Referenced by: '<S12>/enable'

  real_T Constant3_Value;              // Expression: 1
                                          //  Referenced by: '<S1>/Constant3'

  real_T activate_Value;               // Expression: 1
                                          //  Referenced by: '<S13>/activate'

  real_T activate_Value_f;             // Expression: 1
                                          //  Referenced by: '<S14>/activate'

  real32_T Lykyhatkk1_Y0;              // Computed Parameter: Lykyhatkk1_Y0
                                          //  Referenced by: '<S100>/L*(y[k]-yhat[k|k-1])'

  real32_T deltax_Y0;                  // Computed Parameter: deltax_Y0
                                          //  Referenced by: '<S102>/deltax'

  real32_T PWM_P2;                     // Expression: single(deadtime)
                                          //  Referenced by: '<S104>/PWM'

  real32_T PWM_P3;                     // Expression: single(duty)
                                          //  Referenced by: '<S104>/PWM'

  real32_T PWM_P4;                     // Expression: single(phase)
                                          //  Referenced by: '<S104>/PWM'

  real32_T PWM_P2_a;                   // Expression: single(deadtime)
                                          //  Referenced by: '<S106>/PWM'

  real32_T PWM_P3_f;                   // Expression: single(duty)
                                          //  Referenced by: '<S106>/PWM'

  real32_T PWM_P4_h;                   // Expression: single(phase)
                                          //  Referenced by: '<S106>/PWM'

  real32_T DO_PWM_P2;                  // Expression: single(deadtime)
                                          //  Referenced by: '<S108>/DO_PWM'

  real32_T DO_PWM_P2_n;                // Expression: single(deadtime)
                                          //  Referenced by: '<S110>/DO_PWM'

  real32_T SFunction_P6;               // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S112>/S-Function'

  real32_T SFunction_P12;              // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S112>/S-Function'

  real32_T SFunction_P6_n;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S114>/S-Function'

  real32_T SFunction_P12_f;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S114>/S-Function'

  real32_T SFunction_P6_k;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S116>/S-Function'

  real32_T SFunction_P12_h;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S116>/S-Function'

  real32_T SFunction_P6_kz;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S118>/S-Function'

  real32_T SFunction_P12_g;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S118>/S-Function'

  real32_T SFunction_P6_g;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S120>/S-Function'

  real32_T SFunction_P12_e;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S120>/S-Function'

  real32_T ADC_P2;                     // Expression: single(gain)
                                          //  Referenced by: '<S21>/ADC'

  real32_T ADC_P3;                     // Expression: single(offset)
                                          //  Referenced by: '<S21>/ADC'

  real32_T ADC_P2_f;                   // Expression: single(gain)
                                          //  Referenced by: '<S23>/ADC'

  real32_T ADC_P3_o;                   // Expression: single(offset)
                                          //  Referenced by: '<S23>/ADC'

  real32_T ADC_P2_i;                   // Expression: single(gain)
                                          //  Referenced by: '<S25>/ADC'

  real32_T ADC_P3_c;                   // Expression: single(offset)
                                          //  Referenced by: '<S25>/ADC'

  real32_T ADC_P2_o;                   // Expression: single(gain)
                                          //  Referenced by: '<S27>/ADC'

  real32_T ADC_P3_ch;                  // Expression: single(offset)
                                          //  Referenced by: '<S27>/ADC'

  real32_T C_Value[6];                 // Computed Parameter: C_Value
                                          //  Referenced by: '<S50>/C'

  real32_T X0_Value[3];                // Computed Parameter: X0_Value
                                          //  Referenced by: '<S50>/X0'

  real32_T SFunction_P3;               // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S45>/S-Function'

  real32_T SFunction_P4;               // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S45>/S-Function'

  real32_T SFunction_P5;               // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S45>/S-Function'

  real32_T SFunction_P6_m;             // Expression: single(0)
                                          //  Referenced by: '<S45>/S-Function'

  real32_T SFunction_P7;               // Expression: single(0)
                                          //  Referenced by: '<S45>/S-Function'

  real32_T SFunction_P3_b;             // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S49>/S-Function'

  real32_T SFunction_P4_g;             // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S49>/S-Function'

  real32_T SFunction_P5_k;             // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S49>/S-Function'

  real32_T SFunction_P6_b;             // Expression: single(0)
                                          //  Referenced by: '<S49>/S-Function'

  real32_T SFunction_P7_e;             // Expression: single(0)
                                          //  Referenced by: '<S49>/S-Function'

  real32_T Delay1_InitialCondition;
                                  // Computed Parameter: Delay1_InitialCondition
                                     //  Referenced by: '<S46>/Delay1'

  real32_T a0_Gain;                    // Computed Parameter: a0_Gain
                                          //  Referenced by: '<S46>/a0'

  real32_T Delay3_InitialCondition;
                                  // Computed Parameter: Delay3_InitialCondition
                                     //  Referenced by: '<S46>/Delay3'

  real32_T a1_Gain;                    // Computed Parameter: a1_Gain
                                          //  Referenced by: '<S46>/a1'

  real32_T Delay4_InitialCondition;
                                  // Computed Parameter: Delay4_InitialCondition
                                     //  Referenced by: '<S46>/Delay4'

  real32_T b1_Gain;                    // Computed Parameter: b1_Gain
                                          //  Referenced by: '<S46>/b1'

  real32_T Delay5_InitialCondition;
                                  // Computed Parameter: Delay5_InitialCondition
                                     //  Referenced by: '<S46>/Delay5'

  real32_T b2_Gain;                    // Computed Parameter: b2_Gain
                                          //  Referenced by: '<S46>/b2'

  real32_T ub0_Gain;                   // Computed Parameter: ub0_Gain
                                          //  Referenced by: '<S46>/1//b0'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S37>/Saturation'

  real32_T a0_Gain_j;                  // Computed Parameter: a0_Gain_j
                                          //  Referenced by: '<S40>/a0'

  real32_T Delay3_InitialCondition_c;
                                // Computed Parameter: Delay3_InitialCondition_c
                                   //  Referenced by: '<S40>/Delay3'

  real32_T a1_Gain_o;                  // Computed Parameter: a1_Gain_o
                                          //  Referenced by: '<S40>/a1'

  real32_T Delay4_InitialCondition_f;
                                // Computed Parameter: Delay4_InitialCondition_f
                                   //  Referenced by: '<S40>/Delay4'

  real32_T b1_Gain_o;                  // Computed Parameter: b1_Gain_o
                                          //  Referenced by: '<S40>/b1'

  real32_T Delay5_InitialCondition_l;
                                // Computed Parameter: Delay5_InitialCondition_l
                                   //  Referenced by: '<S40>/Delay5'

  real32_T b2_Gain_c;                  // Computed Parameter: b2_Gain_c
                                          //  Referenced by: '<S40>/b2'

  real32_T ub0_Gain_m;                 // Computed Parameter: ub0_Gain_m
                                          //  Referenced by: '<S40>/1//b0'

  real32_T a0_Gain_m;                  // Computed Parameter: a0_Gain_m
                                          //  Referenced by: '<S41>/a0'

  real32_T Delay3_InitialCondition_p;
                                // Computed Parameter: Delay3_InitialCondition_p
                                   //  Referenced by: '<S41>/Delay3'

  real32_T a1_Gain_k;                  // Computed Parameter: a1_Gain_k
                                          //  Referenced by: '<S41>/a1'

  real32_T Delay4_InitialCondition_m;
                                // Computed Parameter: Delay4_InitialCondition_m
                                   //  Referenced by: '<S41>/Delay4'

  real32_T b1_Gain_i;                  // Computed Parameter: b1_Gain_i
                                          //  Referenced by: '<S41>/b1'

  real32_T Delay5_InitialCondition_o;
                                // Computed Parameter: Delay5_InitialCondition_o
                                   //  Referenced by: '<S41>/Delay5'

  real32_T b2_Gain_a;                  // Computed Parameter: b2_Gain_a
                                          //  Referenced by: '<S41>/b2'

  real32_T ub0_Gain_p;                 // Computed Parameter: ub0_Gain_p
                                          //  Referenced by: '<S41>/1//b0'

  real32_T a0_Gain_b;                  // Computed Parameter: a0_Gain_b
                                          //  Referenced by: '<S38>/a0'

  real32_T Delay3_InitialCondition_d;
                                // Computed Parameter: Delay3_InitialCondition_d
                                   //  Referenced by: '<S38>/Delay3'

  real32_T a1_Gain_c;                  // Computed Parameter: a1_Gain_c
                                          //  Referenced by: '<S38>/a1'

  real32_T Delay4_InitialCondition_fy;
                               // Computed Parameter: Delay4_InitialCondition_fy
                                  //  Referenced by: '<S38>/Delay4'

  real32_T b1_Gain_p;                  // Computed Parameter: b1_Gain_p
                                          //  Referenced by: '<S38>/b1'

  real32_T Delay5_InitialCondition_e;
                                // Computed Parameter: Delay5_InitialCondition_e
                                   //  Referenced by: '<S38>/Delay5'

  real32_T b2_Gain_p;                  // Computed Parameter: b2_Gain_p
                                          //  Referenced by: '<S38>/b2'

  real32_T ub0_Gain_mq;                // Computed Parameter: ub0_Gain_mq
                                          //  Referenced by: '<S38>/1//b0'

  real32_T a0_Gain_g;                  // Computed Parameter: a0_Gain_g
                                          //  Referenced by: '<S39>/a0'

  real32_T Delay3_InitialCondition_dr;
                               // Computed Parameter: Delay3_InitialCondition_dr
                                  //  Referenced by: '<S39>/Delay3'

  real32_T a1_Gain_op;                 // Computed Parameter: a1_Gain_op
                                          //  Referenced by: '<S39>/a1'

  real32_T Delay4_InitialCondition_fyn;
                              // Computed Parameter: Delay4_InitialCondition_fyn
                                 //  Referenced by: '<S39>/Delay4'

  real32_T b1_Gain_l;                  // Computed Parameter: b1_Gain_l
                                          //  Referenced by: '<S39>/b1'

  real32_T Delay5_InitialCondition_ew;
                               // Computed Parameter: Delay5_InitialCondition_ew
                                  //  Referenced by: '<S39>/Delay5'

  real32_T b2_Gain_j;                  // Computed Parameter: b2_Gain_j
                                          //  Referenced by: '<S39>/b2'

  real32_T ub0_Gain_k;                 // Computed Parameter: ub0_Gain_k
                                          //  Referenced by: '<S39>/1//b0'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S29>/Saturation'

  real32_T Saturation_LowerSat_n;   // Computed Parameter: Saturation_LowerSat_n
                                       //  Referenced by: '<S29>/Saturation'

  real32_T CLK1_P2;                    // Expression: single(frequency)
                                          //  Referenced by: '<S29>/CLK1'

  real32_T SFunction_P2;               // Expression: single(phase_vector)
                                          //  Referenced by: '<S32>/S-Function'

  real32_T SFunction_P3_m;             // Expression: single(interrupt_phase)
                                          //  Referenced by: '<S32>/S-Function'

  real32_T CLK1_P2_i;                  // Expression: single(frequency)
                                          //  Referenced by: '<S34>/CLK1'

  real32_T GIDifferentiator_NumCoef[3];
                                 // Computed Parameter: GIDifferentiator_NumCoef
                                    //  Referenced by: '<S10>/GI Differentiator'

  real32_T GIDifferentiator_DenCoef[3];
                                 // Computed Parameter: GIDifferentiator_DenCoef
                                    //  Referenced by: '<S10>/GI Differentiator'

  real32_T GIDifferentiator_InitialStates;
                           // Computed Parameter: GIDifferentiator_InitialStates
                              //  Referenced by: '<S10>/GI Differentiator'

  real32_T A_Value[9];                 // Computed Parameter: A_Value
                                          //  Referenced by: '<S50>/A'

  real32_T B_Value[6];                 // Computed Parameter: B_Value
                                          //  Referenced by: '<S50>/B'

  real32_T D_Value[4];                 // Computed Parameter: D_Value
                                          //  Referenced by: '<S50>/D'

  uint32_T SFunction_P7_i;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S112>/S-Function'

  uint32_T SFunction_P13;              // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S112>/S-Function'

  uint32_T SFunction_P7_b;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S114>/S-Function'

  uint32_T SFunction_P13_i;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S114>/S-Function'

  uint32_T SFunction_P7_p;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S116>/S-Function'

  uint32_T SFunction_P13_n;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S116>/S-Function'

  uint32_T SFunction_P7_k;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S118>/S-Function'

  uint32_T SFunction_P13_h;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S118>/S-Function'

  uint32_T SFunction_P7_ia;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S120>/S-Function'

  uint32_T SFunction_P13_b;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S120>/S-Function'

  uint32_T SFunction_P10;              // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S45>/S-Function'

  uint32_T SFunction_P10_d;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S49>/S-Function'

  int16_T PWM_P1;                      // Expression: int16(lane)
                                          //  Referenced by: '<S104>/PWM'

  int16_T PWM_P5;                      // Expression: int16(carrier)
                                          //  Referenced by: '<S104>/PWM'

  int16_T PWM_P6;                      // Expression: int16(rate)
                                          //  Referenced by: '<S104>/PWM'

  int16_T PWM_P7;                      // Expression: int16(outconf)
                                          //  Referenced by: '<S104>/PWM'

  int16_T PWM_P8;                      // Expression: int16(outmode)
                                          //  Referenced by: '<S104>/PWM'

  int16_T PWM_P9;                      // Expression: int16(nbBbx)
                                          //  Referenced by: '<S104>/PWM'

  int16_T PWM_P1_d;                    // Expression: int16(lane)
                                          //  Referenced by: '<S106>/PWM'

  int16_T PWM_P5_e;                    // Expression: int16(carrier)
                                          //  Referenced by: '<S106>/PWM'

  int16_T PWM_P6_g;                    // Expression: int16(rate)
                                          //  Referenced by: '<S106>/PWM'

  int16_T PWM_P7_e;                    // Expression: int16(outconf)
                                          //  Referenced by: '<S106>/PWM'

  int16_T PWM_P8_a;                    // Expression: int16(outmode)
                                          //  Referenced by: '<S106>/PWM'

  int16_T PWM_P9_j;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S106>/PWM'

  int16_T DO_PWM_P1;                   // Expression: int16(lane)
                                          //  Referenced by: '<S108>/DO_PWM'

  int16_T DO_PWM_P3;                   // Expression: int16(outconf)
                                          //  Referenced by: '<S108>/DO_PWM'

  int16_T DO_PWM_P4;                   // Expression: int16(nbBbx)
                                          //  Referenced by: '<S108>/DO_PWM'

  int16_T DO_PWM_P1_i;                 // Expression: int16(lane)
                                          //  Referenced by: '<S110>/DO_PWM'

  int16_T DO_PWM_P3_a;                 // Expression: int16(outconf)
                                          //  Referenced by: '<S110>/DO_PWM'

  int16_T DO_PWM_P4_g;                 // Expression: int16(nbBbx)
                                          //  Referenced by: '<S110>/DO_PWM'

  int16_T SFunction_P2_i;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S112>/S-Function'

  int16_T SFunction_P3_p;              // Expression: int16(0)
                                          //  Referenced by: '<S112>/S-Function'

  int16_T SFunction_P2_p;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S114>/S-Function'

  int16_T SFunction_P3_mc;             // Expression: int16(0)
                                          //  Referenced by: '<S114>/S-Function'

  int16_T SFunction_P2_n;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S116>/S-Function'

  int16_T SFunction_P3_n;              // Expression: int16(0)
                                          //  Referenced by: '<S116>/S-Function'

  int16_T SFunction_P2_b;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S118>/S-Function'

  int16_T SFunction_P3_g;              // Expression: int16(0)
                                          //  Referenced by: '<S118>/S-Function'

  int16_T SFunction_P2_ii;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S120>/S-Function'

  int16_T SFunction_P3_nm;             // Expression: int16(0)
                                          //  Referenced by: '<S120>/S-Function'

  int16_T ADC_P1;                      // Expression: int16(channel)
                                          //  Referenced by: '<S21>/ADC'

  int16_T ADC_P4;                      // Expression: int16(nbBbx)
                                          //  Referenced by: '<S21>/ADC'

  int16_T ADC_P6;                      // Expression: int16(outputwidth)
                                          //  Referenced by: '<S21>/ADC'

  int16_T ADC_P1_e;                    // Expression: int16(channel)
                                          //  Referenced by: '<S23>/ADC'

  int16_T ADC_P4_m;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S23>/ADC'

  int16_T ADC_P6_j;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S23>/ADC'

  int16_T ADC_P1_h;                    // Expression: int16(channel)
                                          //  Referenced by: '<S25>/ADC'

  int16_T ADC_P4_f;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S25>/ADC'

  int16_T ADC_P6_m;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S25>/ADC'

  int16_T ADC_P1_p;                    // Expression: int16(channel)
                                          //  Referenced by: '<S27>/ADC'

  int16_T ADC_P4_i;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S27>/ADC'

  int16_T ADC_P6_e;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S27>/ADC'

  int16_T SFunction_P2_d;              // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S45>/S-Function'

  int16_T SFunction_P2_f;              // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S49>/S-Function'

  int16_T clk_id_Value;                // Computed Parameter: clk_id_Value
                                          //  Referenced by: '<S29>/clk_id'

  int16_T CLK1_P1;                     // Expression: int16(id)
                                          //  Referenced by: '<S29>/CLK1'

  int16_T clk_id_Value_o;              // Computed Parameter: clk_id_Value_o
                                          //  Referenced by: '<S34>/clk_id'

  int16_T CLK1_P1_c;                   // Expression: int16(id)
                                          //  Referenced by: '<S34>/CLK1'

  uint16_T SFunction_P1[2];            // Computed Parameter: SFunction_P1
                                          //  Referenced by: '<S112>/S-Function'

  uint16_T SFunction_P5_a;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S112>/S-Function'

  uint16_T SFunction_P8;               // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S112>/S-Function'

  uint16_T SFunction_P11;              // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S112>/S-Function'

  uint16_T SFunction_P14[5];           // Computed Parameter: SFunction_P14
                                          //  Referenced by: '<S112>/S-Function'

  uint16_T SFunction_P1_g[2];          // Computed Parameter: SFunction_P1_g
                                          //  Referenced by: '<S114>/S-Function'

  uint16_T SFunction_P5_g;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S114>/S-Function'

  uint16_T SFunction_P8_p;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S114>/S-Function'

  uint16_T SFunction_P11_e;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S114>/S-Function'

  uint16_T SFunction_P14_f[5];         // Computed Parameter: SFunction_P14_f
                                          //  Referenced by: '<S114>/S-Function'

  uint16_T SFunction_P1_i;             // Computed Parameter: SFunction_P1_i
                                          //  Referenced by: '<S116>/S-Function'

  uint16_T SFunction_P5_d;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S116>/S-Function'

  uint16_T SFunction_P8_d;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S116>/S-Function'

  uint16_T SFunction_P11_i;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S116>/S-Function'

  uint16_T SFunction_P14_p[5];         // Computed Parameter: SFunction_P14_p
                                          //  Referenced by: '<S116>/S-Function'

  uint16_T SFunction_P1_k[6];          // Computed Parameter: SFunction_P1_k
                                          //  Referenced by: '<S118>/S-Function'

  uint16_T SFunction_P5_p;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S118>/S-Function'

  uint16_T SFunction_P8_c;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S118>/S-Function'

  uint16_T SFunction_P11_g;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S118>/S-Function'

  uint16_T SFunction_P14_n[5];         // Computed Parameter: SFunction_P14_n
                                          //  Referenced by: '<S118>/S-Function'

  uint16_T SFunction_P1_d[6];          // Computed Parameter: SFunction_P1_d
                                          //  Referenced by: '<S120>/S-Function'

  uint16_T SFunction_P5_l;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S120>/S-Function'

  uint16_T SFunction_P8_n;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S120>/S-Function'

  uint16_T SFunction_P11_c;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S120>/S-Function'

  uint16_T SFunction_P14_g[5];         // Computed Parameter: SFunction_P14_g
                                          //  Referenced by: '<S120>/S-Function'

  uint16_T SFunction_P1_e[2];          // Computed Parameter: SFunction_P1_e
                                          //  Referenced by: '<S45>/S-Function'

  uint16_T SFunction_P9;               // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S45>/S-Function'

  uint16_T SFunction_P11_n;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S45>/S-Function'

  uint16_T SFunction_P14_e;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S45>/S-Function'

  uint16_T SFunction_P15;              // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S45>/S-Function'

  uint16_T SFunction_P1_m[2];          // Computed Parameter: SFunction_P1_m
                                          //  Referenced by: '<S49>/S-Function'

  uint16_T SFunction_P9_a;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S49>/S-Function'

  uint16_T SFunction_P11_ie;           // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S49>/S-Function'

  uint16_T SFunction_P14_m;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S49>/S-Function'

  uint16_T SFunction_P15_g;            // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S49>/S-Function'

  uint16_T SFunction_P1_f;             // Expression: uint16(interrupt_pstsclr)
                                          //  Referenced by: '<S32>/S-Function'

  uint16_T SFunction_P4_i;           // Expression: uint16(private_adc_delay_ns)
                                        //  Referenced by: '<S32>/S-Function'

  boolean_T PWM_P10;                   // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S104>/PWM'

  boolean_T PWM_P11;                   // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S104>/PWM'

  boolean_T PWM_P12;                   // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S104>/PWM'

  boolean_T PWM_P10_o;                 // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S106>/PWM'

  boolean_T PWM_P11_f;                 // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S106>/PWM'

  boolean_T PWM_P12_h;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S106>/PWM'

  boolean_T DO_PWM_P5;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S108>/DO_PWM'

  boolean_T DO_PWM_P5_k;               // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S110>/DO_PWM'

  boolean_T SFunction_P4_d;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S112>/S-Function'

  boolean_T SFunction_P9_f;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S112>/S-Function'

  boolean_T SFunction_P10_c;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S112>/S-Function'

  boolean_T SFunction_P15_o;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S112>/S-Function'

  boolean_T SFunction_P4_f;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S114>/S-Function'

  boolean_T SFunction_P9_b;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S114>/S-Function'

  boolean_T SFunction_P10_b;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S114>/S-Function'

  boolean_T SFunction_P15_c;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S114>/S-Function'

  boolean_T SFunction_P4_j;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S116>/S-Function'

  boolean_T SFunction_P9_m;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S116>/S-Function'

  boolean_T SFunction_P10_a;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S116>/S-Function'

  boolean_T SFunction_P15_gb;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S116>/S-Function'

  boolean_T SFunction_P4_k;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S118>/S-Function'

  boolean_T SFunction_P9_aa;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S118>/S-Function'

  boolean_T SFunction_P10_i;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S118>/S-Function'

  boolean_T SFunction_P15_h;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S118>/S-Function'

  boolean_T SFunction_P4_a;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S120>/S-Function'

  boolean_T SFunction_P9_c;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S120>/S-Function'

  boolean_T SFunction_P10_g;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S120>/S-Function'

  boolean_T SFunction_P15_j;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S120>/S-Function'

  boolean_T ADC_P5;                    // Expression: boolean(usehist)
                                          //  Referenced by: '<S21>/ADC'

  boolean_T ADC_P5_d;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S23>/ADC'

  boolean_T ADC_P5_m;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S25>/ADC'

  boolean_T ADC_P5_dy;                 // Expression: boolean(usehist)
                                          //  Referenced by: '<S27>/ADC'

  boolean_T Enable_Value;              // Expression: true()
                                          //  Referenced by: '<S50>/Enable'

  boolean_T SFunction_P8_b;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S45>/S-Function'

  boolean_T SFunction_P12_ej;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S45>/S-Function'

  boolean_T SFunction_P13_f;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S45>/S-Function'

  boolean_T SFunction_P16;             // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S45>/S-Function'

  boolean_T SFunction_P8_dn;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S49>/S-Function'

  boolean_T SFunction_P12_i;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S49>/S-Function'

  boolean_T SFunction_P13_e;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S49>/S-Function'

  boolean_T SFunction_P16_n;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S49>/S-Function'

  boolean_T CLK1_P3;                   // Expression: boolean(var_freq)
                                          //  Referenced by: '<S29>/CLK1'

  boolean_T CLK1_P3_d;                 // Expression: boolean(var_freq)
                                          //  Referenced by: '<S34>/CLK1'

  boolean_T isSqrtUsed_Value;          // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S98>/isSqrtUsed'

};

// Real-time Model Data Structure
struct tag_RTM_TTypeInverter_Imperix_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_TTypeInverter_Imperix_T TTypeInverter_Imperix_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_TTypeInverter_Imperix_T TTypeInverter_Imperix_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_TTypeInverter_Imperix_T TTypeInverter_Imperix_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void TTypeInverter_Imperix_initialize(void);
  extern void TTypeInverter_Imperix_step(void);
  extern void TTypeInverter_Imperix_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_TTypeInverter_Imperi_T *const TTypeInverter_Imperix_M;

#ifdef __cplusplus

}

#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/CBPWM' : Unused code path elimination
//  Block '<S35>/Scope' : Unused code path elimination
//  Block '<S9>/Error Scope' : Unused code path elimination
//  Block '<S9>/Reference Scope' : Unused code path elimination
//  Block '<S36>/Data Type Duplicate' : Unused code path elimination
//  Block '<S36>/Data Type Propagation' : Unused code path elimination
//  Block '<S93>/Data Type Duplicate' : Unused code path elimination
//  Block '<S94>/Data Type Duplicate' : Unused code path elimination
//  Block '<S95>/Conversion' : Unused code path elimination
//  Block '<S95>/Data Type Duplicate' : Unused code path elimination
//  Block '<S96>/Data Type Duplicate' : Unused code path elimination
//  Block '<S54>/Data Type Duplicate' : Unused code path elimination
//  Block '<S55>/Data Type Duplicate' : Unused code path elimination
//  Block '<S56>/Data Type Duplicate' : Unused code path elimination
//  Block '<S57>/Data Type Duplicate' : Unused code path elimination
//  Block '<S59>/Data Type Duplicate' : Unused code path elimination
//  Block '<S60>/Data Type Duplicate' : Unused code path elimination
//  Block '<S61>/Data Type Duplicate' : Unused code path elimination
//  Block '<S62>/Conversion' : Unused code path elimination
//  Block '<S62>/Data Type Duplicate' : Unused code path elimination
//  Block '<S63>/Data Type Duplicate' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S67>/Data Type Duplicate' : Unused code path elimination
//  Block '<S68>/Data Type Duplicate' : Unused code path elimination
//  Block '<S50>/G' : Unused code path elimination
//  Block '<S50>/H' : Unused code path elimination
//  Block '<S50>/N' : Unused code path elimination
//  Block '<S50>/P0' : Unused code path elimination
//  Block '<S50>/Q' : Unused code path elimination
//  Block '<S50>/R' : Unused code path elimination
//  Block '<S91>/CheckSignalProperties' : Unused code path elimination
//  Block '<S92>/CheckSignalProperties' : Unused code path elimination
//  Block '<S10>/Scope' : Unused code path elimination
//  Block '<S10>/Scope1' : Unused code path elimination
//  Block '<S10>/Scope2' : Unused code path elimination
//  Block '<S10>/Scope3' : Unused code path elimination
//  Block '<S1>/Scope' : Unused code path elimination
//  Block '<S1>/Scope1' : Unused code path elimination
//  Block '<Root>/Memory' : Unused code path elimination
//  Block '<S7>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S67>/Conversion' : Eliminate redundant data type conversion
//  Block '<S71>/Reshape' : Reshape block reduction
//  Block '<S50>/ReshapeX0' : Reshape block reduction
//  Block '<S50>/Reshapexhat' : Reshape block reduction
//  Block '<S50>/Reshapeyhat' : Reshape block reduction
//  Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S112>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S114>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S116>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S118>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S120>/Data Type Conversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'TTypeInverter_Imperix'
//  '<S1>'   : 'TTypeInverter_Imperix/Closed_loop_control'
//  '<S2>'   : 'TTypeInverter_Imperix/Plant_Model'
//  '<S3>'   : 'TTypeInverter_Imperix/Closed_loop_control/ADC'
//  '<S4>'   : 'TTypeInverter_Imperix/Closed_loop_control/ADC1'
//  '<S5>'   : 'TTypeInverter_Imperix/Closed_loop_control/ADC2'
//  '<S6>'   : 'TTypeInverter_Imperix/Closed_loop_control/ADC3'
//  '<S7>'   : 'TTypeInverter_Imperix/Closed_loop_control/CLK'
//  '<S8>'   : 'TTypeInverter_Imperix/Closed_loop_control/Configuration'
//  '<S9>'   : 'TTypeInverter_Imperix/Closed_loop_control/Controllers'
//  '<S10>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter'
//  '<S11>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_CB'
//  '<S12>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_CB1'
//  '<S13>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO'
//  '<S14>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO1'
//  '<S15>'  : 'TTypeInverter_Imperix/Closed_loop_control/Probe'
//  '<S16>'  : 'TTypeInverter_Imperix/Closed_loop_control/Probe1'
//  '<S17>'  : 'TTypeInverter_Imperix/Closed_loop_control/Probe2'
//  '<S18>'  : 'TTypeInverter_Imperix/Closed_loop_control/Probe7'
//  '<S19>'  : 'TTypeInverter_Imperix/Closed_loop_control/Probe8'
//  '<S20>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC/sub'
//  '<S21>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC/sub/generation'
//  '<S22>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC1/sub'
//  '<S23>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC1/sub/generation'
//  '<S24>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC2/sub'
//  '<S25>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC2/sub/generation'
//  '<S26>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC3/sub'
//  '<S27>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC3/sub/generation'
//  '<S28>'  : 'TTypeInverter_Imperix/Closed_loop_control/CLK/sub'
//  '<S29>'  : 'TTypeInverter_Imperix/Closed_loop_control/CLK/sub/generation'
//  '<S30>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/Sampling clock'
//  '<S31>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/clk0'
//  '<S32>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/Sampling clock/generation'
//  '<S33>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/clk0/sub'
//  '<S34>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/clk0/sub/generation'
//  '<S35>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller'
//  '<S36>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Saturation Dynamic'
//  '<S37>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Voltage Controller'
//  '<S38>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Impulse Invariant PR - HC15'
//  '<S39>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Impulse Invariant PR - HC21'
//  '<S40>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Impulse Invariant PR - HC5'
//  '<S41>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Impulse Invariant PR - HC7'
//  '<S42>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Tunable parameter'
//  '<S43>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Variable Gain'
//  '<S44>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Tunable parameter/sub'
//  '<S45>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Current Controller/Tunable parameter/sub/generation'
//  '<S46>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Voltage Controller/Impulse Invariant PR - Fundamental'
//  '<S47>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Voltage Controller/Tunable parameter'
//  '<S48>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Voltage Controller/Tunable parameter/sub'
//  '<S49>'  : 'TTypeInverter_Imperix/Closed_loop_control/Controllers/Voltage Controller/Tunable parameter/sub/generation'
//  '<S50>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter'
//  '<S51>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CalculatePL'
//  '<S52>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CalculateYhat'
//  '<S53>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator'
//  '<S54>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionA'
//  '<S55>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionB'
//  '<S56>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionC'
//  '<S57>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionD'
//  '<S58>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionEnable'
//  '<S59>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionG'
//  '<S60>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionH'
//  '<S61>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionN'
//  '<S62>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionP'
//  '<S63>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionP0'
//  '<S64>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionQ'
//  '<S65>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionR'
//  '<S66>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionReset'
//  '<S67>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionX'
//  '<S68>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionX0'
//  '<S69>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/DataTypeConversionu'
//  '<S70>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/MemoryP'
//  '<S71>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/Observer'
//  '<S72>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/ReducedQRN'
//  '<S73>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/Reset'
//  '<S74>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/ScalarExpansionP0'
//  '<S75>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/ScalarExpansionQ'
//  '<S76>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/ScalarExpansionR'
//  '<S77>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/UseCurrentEstimator'
//  '<S78>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkA'
//  '<S79>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkB'
//  '<S80>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkC'
//  '<S81>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkD'
//  '<S82>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkEnable'
//  '<S83>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkG'
//  '<S84>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkH'
//  '<S85>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkN'
//  '<S86>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkP0'
//  '<S87>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkQ'
//  '<S88>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkR'
//  '<S89>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkReset'
//  '<S90>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checkX0'
//  '<S91>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checku'
//  '<S92>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/checky'
//  '<S93>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
//  '<S94>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
//  '<S95>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
//  '<S96>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
//  '<S97>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CalculatePL/Ground'
//  '<S98>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
//  '<S99>'  : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S100>' : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/Observer/MeasurementUpdate'
//  '<S101>' : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/ReducedQRN/Ground'
//  '<S102>' : 'TTypeInverter_Imperix/Closed_loop_control/Kalman Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
//  '<S103>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_CB/sub'
//  '<S104>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_CB/sub/generation'
//  '<S105>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_CB1/sub'
//  '<S106>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_CB1/sub/generation'
//  '<S107>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO/sub'
//  '<S108>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO/sub/generation'
//  '<S109>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO1/sub'
//  '<S110>' : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO1/sub/generation'
//  '<S111>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe/sub'
//  '<S112>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe/sub/generation'
//  '<S113>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe1/sub'
//  '<S114>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe1/sub/generation'
//  '<S115>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe2/sub'
//  '<S116>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe2/sub/generation'
//  '<S117>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe7/sub'
//  '<S118>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe7/sub/generation'
//  '<S119>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe8/sub'
//  '<S120>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe8/sub/generation'

#endif                                 // RTW_HEADER_TTypeInverter_Imperix_h_

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
