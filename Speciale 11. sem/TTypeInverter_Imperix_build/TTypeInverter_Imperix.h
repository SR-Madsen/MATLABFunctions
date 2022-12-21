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
// Model version                  : 14.119
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Dec 21 14:14:34 2022
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

// Block states (default storage) for system '<S97>/MeasurementUpdate'
struct DW_MeasurementUpdate_TTypeInv_T {
  boolean_T MeasurementUpdate_MODE;    // '<S97>/MeasurementUpdate'
};

// Block states (default storage) for system '<S103>/Enabled Subsystem'
struct DW_EnabledSubsystem_TTypeInve_T {
  boolean_T EnabledSubsystem_MODE;     // '<S103>/Enabled Subsystem'
};

// Block signals for system '<S32>/Moving Average'
struct B_MovingAverage_TTypeInverter_T {
  real32_T MovingAverage;              // '<S32>/Moving Average'
};

// Block states (default storage) for system '<S32>/Moving Average'
struct DW_MovingAverage_TTypeInverte_T {
  dsp_simulink_MovingAverage_TT_T obj; // '<S32>/Moving Average'
  boolean_T objisempty;                // '<S32>/Moving Average'
};

// Block signals (default storage)
struct B_TTypeInverter_Imperix_T {
  real32_T ADC;                        // '<S15>/ADC'
  real32_T ADC_l;                      // '<S17>/ADC'
  real32_T Saturation;                 // '<S19>/Saturation'
  real32_T ADC_j;                      // '<S42>/ADC'
  real32_T ADC_h;                      // '<S44>/ADC'
  real32_T Product[2];                 // '<S78>/Product'
  real32_T SFunction;                  // '<S61>/S-Function'
  real32_T io_hat;                     // '<S32>/Subtract2'
  real32_T SFunction_b;                // '<S75>/S-Function'
  real32_T e_vc;                       // '<S31>/Sum'
  real32_T Saturation_c;               // '<S53>/Saturation'
  real32_T e_iL;                       // '<S31>/Sum3'
  real32_T Switch2;                    // '<S52>/Switch2'
  real32_T DataTypeConversion;         // '<S69>/Data Type Conversion'
  real32_T DataTypeConversion2;        // '<S33>/Data Type Conversion2'
  real32_T DataTypeConversion3;        // '<S33>/Data Type Conversion3'
  real32_T DataTypeConversion1;        // '<S34>/Data Type Conversion1'
  real32_T DataTypeConversion2_l;      // '<S34>/Data Type Conversion2'
  real32_T DataTypeConversion3_e;      // '<S34>/Data Type Conversion3'
  real32_T ADC_p;                      // '<S158>/ADC'
  real32_T ADC_f;                      // '<S160>/ADC'
  real32_T Product_l[2];               // '<S194>/Product'
  real32_T SFunction_p;                // '<S177>/S-Function'
  real32_T io_hat_f;                   // '<S148>/Subtract2'
  real32_T SFunction_f;                // '<S191>/S-Function'
  real32_T e_vc_c;                     // '<S147>/Sum'
  real32_T Saturation_p;               // '<S169>/Saturation'
  real32_T e_iL_i;                     // '<S147>/Sum3'
  real32_T Switch2_a;                  // '<S168>/Switch2'
  real32_T DataTypeConversion_i;       // '<S185>/Data Type Conversion'
  real32_T DataTypeConversion2_b;      // '<S149>/Data Type Conversion2'
  real32_T DataTypeConversion3_c;      // '<S149>/Data Type Conversion3'
  real32_T DataTypeConversion1_a;      // '<S150>/Data Type Conversion1'
  real32_T DataTypeConversion2_o;      // '<S150>/Data Type Conversion2'
  real32_T DataTypeConversion3_i;      // '<S150>/Data Type Conversion3'
  real32_T ADC_a;                      // '<S274>/ADC'
  real32_T ADC_i;                      // '<S276>/ADC'
  real32_T Product_m[2];               // '<S310>/Product'
  real32_T SFunction_l;                // '<S293>/S-Function'
  real32_T io_hat_p;                   // '<S264>/Subtract2'
  real32_T SFunction_fd;               // '<S307>/S-Function'
  real32_T e_vc_i;                     // '<S263>/Sum'
  real32_T Saturation_k;               // '<S285>/Saturation'
  real32_T e_iL_c;                     // '<S263>/Sum3'
  real32_T Switch2_k;                  // '<S284>/Switch2'
  real32_T DataTypeConversion_b;       // '<S301>/Data Type Conversion'
  real32_T DataTypeConversion2_lx;     // '<S265>/Data Type Conversion2'
  real32_T DataTypeConversion3_k;      // '<S265>/Data Type Conversion3'
  real32_T DataTypeConversion1_o;      // '<S266>/Data Type Conversion1'
  real32_T DataTypeConversion2_e;      // '<S266>/Data Type Conversion2'
  real32_T DataTypeConversion3_h;      // '<S266>/Data Type Conversion3'
  real32_T Cast;                       // '<S7>/Cast'
  real32_T Cast1;                      // '<S7>/Cast1'
  real32_T Cast_m;                     // '<S8>/Cast'
  real32_T Cast1_e;                    // '<S8>/Cast1'
  real32_T Product2[3];                // '<S360>/Product2'
  real32_T Product3[3];                // '<S358>/Product3'
  real32_T m;                          // '<S263>/MATLAB Function'
  real32_T Product2_i[3];              // '<S244>/Product2'
  real32_T Product3_h[3];              // '<S242>/Product3'
  real32_T m_e;                        // '<S147>/MATLAB Function'
  real32_T Product2_d[3];              // '<S128>/Product2'
  real32_T Product3_f[3];              // '<S126>/Product3'
  real32_T m_c;                        // '<S31>/MATLAB Function'
  B_MovingAverage_TTypeInverter_T MovingAverage_pn;// '<S32>/Moving Average'
  B_MovingAverage_TTypeInverter_T MovingAverage_p;// '<S32>/Moving Average'
  B_MovingAverage_TTypeInverter_T MovingAverage;// '<S32>/Moving Average'
};

// Block states (default storage) for system '<Root>'
struct DW_TTypeInverter_Imperix_T {
  real_T SFunction_DSTATE;             // '<S378>/S-Function'
  real_T SFunction_DSTATE_m;           // '<S380>/S-Function'
  real_T SFunction_DSTATE_n;           // '<S22>/S-Function'
  real_T SFunction_DSTATE_l;           // '<S134>/S-Function'
  real_T SFunction_DSTATE_n0;          // '<S136>/S-Function'
  real_T SFunction_DSTATE_b;           // '<S138>/S-Function'
  real_T SFunction_DSTATE_i;           // '<S140>/S-Function'
  real_T SFunction_DSTATE_bh;          // '<S142>/S-Function'
  real_T SFunction_DSTATE_nd;          // '<S144>/S-Function'
  real_T SFunction_DSTATE_c;           // '<S61>/S-Function'
  real_T SFunction_DSTATE_ce;          // '<S75>/S-Function'
  real_T SFunction_DSTATE_k;           // '<S63>/S-Function'
  real_T SFunction_DSTATE_lw;          // '<S65>/S-Function'
  real_T SFunction_DSTATE_bb;          // '<S67>/S-Function'
  real_T SFunction_DSTATE_l1;          // '<S69>/S-Function'
  real_T SFunction_DSTATE_h;           // '<S71>/S-Function'
  real_T SFunction_DSTATE_h1;          // '<S250>/S-Function'
  real_T SFunction_DSTATE_nk;          // '<S252>/S-Function'
  real_T SFunction_DSTATE_bp;          // '<S254>/S-Function'
  real_T SFunction_DSTATE_hx;          // '<S256>/S-Function'
  real_T SFunction_DSTATE_g;           // '<S258>/S-Function'
  real_T SFunction_DSTATE_nu;          // '<S260>/S-Function'
  real_T SFunction_DSTATE_l5;          // '<S177>/S-Function'
  real_T SFunction_DSTATE_p;           // '<S191>/S-Function'
  real_T SFunction_DSTATE_hz;          // '<S179>/S-Function'
  real_T SFunction_DSTATE_d;           // '<S181>/S-Function'
  real_T SFunction_DSTATE_d5;          // '<S183>/S-Function'
  real_T SFunction_DSTATE_hw;          // '<S185>/S-Function'
  real_T SFunction_DSTATE_l50;         // '<S187>/S-Function'
  real_T SFunction_DSTATE_mo;          // '<S366>/S-Function'
  real_T SFunction_DSTATE_lf;          // '<S368>/S-Function'
  real_T SFunction_DSTATE_cc;          // '<S370>/S-Function'
  real_T SFunction_DSTATE_cr;          // '<S372>/S-Function'
  real_T SFunction_DSTATE_i3;          // '<S374>/S-Function'
  real_T SFunction_DSTATE_j;           // '<S376>/S-Function'
  real_T SFunction_DSTATE_m2;          // '<S293>/S-Function'
  real_T SFunction_DSTATE_lm;          // '<S307>/S-Function'
  real_T SFunction_DSTATE_ccr;         // '<S295>/S-Function'
  real_T SFunction_DSTATE_nf;          // '<S297>/S-Function'
  real_T SFunction_DSTATE_ip;          // '<S299>/S-Function'
  real_T SFunction_DSTATE_pt;          // '<S301>/S-Function'
  real_T SFunction_DSTATE_pv;          // '<S303>/S-Function'
  real_T lastSin;                      // '<S31>/Sine Wave'
  real_T lastCos;                      // '<S31>/Sine Wave'
  real_T lastSin_i;                    // '<S147>/Sine Wave'
  real_T lastCos_k;                    // '<S147>/Sine Wave'
  real_T lastSin_g;                    // '<S263>/Sine Wave'
  real_T lastCos_e;                    // '<S263>/Sine Wave'
  real32_T MemoryX_DSTATE[3];          // '<S76>/MemoryX'
  real32_T Delay1_DSTATE;              // '<S72>/Delay1'
  real32_T Delay3_DSTATE;              // '<S72>/Delay3'
  real32_T Delay4_DSTATE;              // '<S72>/Delay4'
  real32_T Delay5_DSTATE;              // '<S72>/Delay5'
  real32_T Delay3_DSTATE_o;            // '<S56>/Delay3'
  real32_T Delay4_DSTATE_e;            // '<S56>/Delay4'
  real32_T Delay5_DSTATE_b;            // '<S56>/Delay5'
  real32_T Delay3_DSTATE_p;            // '<S57>/Delay3'
  real32_T Delay4_DSTATE_d;            // '<S57>/Delay4'
  real32_T Delay5_DSTATE_f;            // '<S57>/Delay5'
  real32_T Delay3_DSTATE_pn;           // '<S54>/Delay3'
  real32_T Delay4_DSTATE_dg;           // '<S54>/Delay4'
  real32_T Delay5_DSTATE_a;            // '<S54>/Delay5'
  real32_T Delay3_DSTATE_b;            // '<S55>/Delay3'
  real32_T Delay4_DSTATE_dh;           // '<S55>/Delay4'
  real32_T Delay5_DSTATE_l;            // '<S55>/Delay5'
  real32_T GIDifferentiator_states[2]; // '<S32>/GI Differentiator'
  real32_T MemoryX_DSTATE_l[3];        // '<S192>/MemoryX'
  real32_T Delay1_DSTATE_h;            // '<S188>/Delay1'
  real32_T Delay3_DSTATE_l;            // '<S188>/Delay3'
  real32_T Delay4_DSTATE_k;            // '<S188>/Delay4'
  real32_T Delay5_DSTATE_c;            // '<S188>/Delay5'
  real32_T Delay3_DSTATE_f;            // '<S172>/Delay3'
  real32_T Delay4_DSTATE_o;            // '<S172>/Delay4'
  real32_T Delay5_DSTATE_k;            // '<S172>/Delay5'
  real32_T Delay3_DSTATE_i;            // '<S173>/Delay3'
  real32_T Delay4_DSTATE_dv;           // '<S173>/Delay4'
  real32_T Delay5_DSTATE_aq;           // '<S173>/Delay5'
  real32_T Delay3_DSTATE_j;            // '<S170>/Delay3'
  real32_T Delay4_DSTATE_c;            // '<S170>/Delay4'
  real32_T Delay5_DSTATE_d;            // '<S170>/Delay5'
  real32_T Delay3_DSTATE_a;            // '<S171>/Delay3'
  real32_T Delay4_DSTATE_kv;           // '<S171>/Delay4'
  real32_T Delay5_DSTATE_dx;           // '<S171>/Delay5'
  real32_T GIDifferentiator_states_j[2];// '<S148>/GI Differentiator'
  real32_T MemoryX_DSTATE_e[3];        // '<S308>/MemoryX'
  real32_T Delay1_DSTATE_hq;           // '<S304>/Delay1'
  real32_T Delay3_DSTATE_b5;           // '<S304>/Delay3'
  real32_T Delay4_DSTATE_j;            // '<S304>/Delay4'
  real32_T Delay5_DSTATE_j;            // '<S304>/Delay5'
  real32_T Delay3_DSTATE_k;            // '<S288>/Delay3'
  real32_T Delay4_DSTATE_on;           // '<S288>/Delay4'
  real32_T Delay5_DSTATE_e;            // '<S288>/Delay5'
  real32_T Delay3_DSTATE_m;            // '<S289>/Delay3'
  real32_T Delay4_DSTATE_p;            // '<S289>/Delay4'
  real32_T Delay5_DSTATE_m;            // '<S289>/Delay5'
  real32_T Delay3_DSTATE_am;           // '<S286>/Delay3'
  real32_T Delay4_DSTATE_h;            // '<S286>/Delay4'
  real32_T Delay5_DSTATE_co;           // '<S286>/Delay5'
  real32_T Delay3_DSTATE_fb;           // '<S287>/Delay3'
  real32_T Delay4_DSTATE_db;           // '<S287>/Delay4'
  real32_T Delay5_DSTATE_fp;           // '<S287>/Delay5'
  real32_T GIDifferentiator_states_n[2];// '<S264>/GI Differentiator'
  int32_T systemEnable;                // '<S31>/Sine Wave'
  int32_T systemEnable_n;              // '<S147>/Sine Wave'
  int32_T systemEnable_a;              // '<S263>/Sine Wave'
  boolean_T icLoad;                    // '<S76>/MemoryX'
  boolean_T icLoad_p;                  // '<S192>/MemoryX'
  boolean_T icLoad_b;                  // '<S308>/MemoryX'
  DW_MovingAverage_TTypeInverte_T MovingAverage_pn;// '<S32>/Moving Average'
  DW_EnabledSubsystem_TTypeInve_T EnabledSubsystem_f;// '<S335>/Enabled Subsystem' 
  DW_MeasurementUpdate_TTypeInv_T MeasurementUpdate_d;// '<S329>/MeasurementUpdate' 
  DW_MovingAverage_TTypeInverte_T MovingAverage_p;// '<S32>/Moving Average'
  DW_EnabledSubsystem_TTypeInve_T EnabledSubsystem_l;// '<S219>/Enabled Subsystem' 
  DW_MeasurementUpdate_TTypeInv_T MeasurementUpdate_f;// '<S213>/MeasurementUpdate' 
  DW_MovingAverage_TTypeInverte_T MovingAverage;// '<S32>/Moving Average'
  DW_EnabledSubsystem_TTypeInve_T EnabledSubsystem;// '<S103>/Enabled Subsystem' 
  DW_MeasurementUpdate_TTypeInv_T MeasurementUpdate;// '<S97>/MeasurementUpdate' 
};

// Parameters for system: '<S97>/MeasurementUpdate'
struct P_MeasurementUpdate_TTypeInve_T_ {
  real32_T Lykyhatkk1_Y0;              // Computed Parameter: Lykyhatkk1_Y0
                                          //  Referenced by: '<S126>/L*(y[k]-yhat[k|k-1])'

};

// Parameters for system: '<S103>/Enabled Subsystem'
struct P_EnabledSubsystem_TTypeInver_T_ {
  real32_T deltax_Y0;                  // Computed Parameter: deltax_Y0
                                          //  Referenced by: '<S128>/deltax'

};

// Parameters (default storage)
struct P_TTypeInverter_Imperix_T_ {
  real_T Vout_amp;                     // Variable: Vout_amp
                                          //  Referenced by:
                                          //    '<S31>/Sine Wave'
                                          //    '<S147>/Sine Wave'
                                          //    '<S263>/Sine Wave'

  real_T f_o;                          // Variable: f_o
                                          //  Referenced by:
                                          //    '<S31>/Sine Wave'
                                          //    '<S147>/Sine Wave'
                                          //    '<S263>/Sine Wave'

  real32_T Klim;                       // Variable: Klim
                                          //  Referenced by:
                                          //    '<S72>/Klim'
                                          //    '<S188>/Klim'
                                          //    '<S304>/Klim'

  real32_T R_Lc;                       // Variable: R_Lc
                                          //  Referenced by:
                                          //    '<S31>/Gain1'
                                          //    '<S147>/Gain1'
                                          //    '<S263>/Gain1'

  real32_T pr_sat_val;                 // Variable: pr_sat_val
                                          //  Referenced by:
                                          //    '<S53>/Saturation'
                                          //    '<S169>/Saturation'
                                          //    '<S285>/Saturation'

  real_T KalmanGainM_Value[6];         // Expression: pInitialization.M
                                          //  Referenced by: '<S77>/KalmanGainM'

  real_T SineWave_Bias;                // Expression: 0
                                          //  Referenced by: '<S31>/Sine Wave'

  real_T SineWave_Hsin;                // Computed Parameter: SineWave_Hsin
                                          //  Referenced by: '<S31>/Sine Wave'

  real_T SineWave_HCos;                // Computed Parameter: SineWave_HCos
                                          //  Referenced by: '<S31>/Sine Wave'

  real_T SineWave_PSin;                // Computed Parameter: SineWave_PSin
                                          //  Referenced by: '<S31>/Sine Wave'

  real_T SineWave_PCos;                // Computed Parameter: SineWave_PCos
                                          //  Referenced by: '<S31>/Sine Wave'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<S9>/Constant2'

  real_T CovarianceZ_Value[9];         // Expression: pInitialization.Z
                                          //  Referenced by: '<S77>/CovarianceZ'

  real_T KalmanGainL_Value[6];         // Expression: pInitialization.L
                                          //  Referenced by: '<S77>/KalmanGainL'

  real_T phase_Value;                  // Expression: PHASE
                                          //  Referenced by: '<S33>/phase'

  real_T enable_Value;                 // Expression: 1
                                          //  Referenced by: '<S33>/enable'

  real_T phase_Value_j;                // Expression: PHASE
                                          //  Referenced by: '<S34>/phase'

  real_T enable_Value_o;               // Expression: 1
                                          //  Referenced by: '<S34>/enable'

  real_T KalmanGainM_Value_j[6];       // Expression: pInitialization.M
                                          //  Referenced by: '<S193>/KalmanGainM'

  real_T SineWave_Bias_a;              // Expression: 0
                                          //  Referenced by: '<S147>/Sine Wave'

  real_T SineWave_Hsin_b;              // Computed Parameter: SineWave_Hsin_b
                                          //  Referenced by: '<S147>/Sine Wave'

  real_T SineWave_HCos_d;              // Computed Parameter: SineWave_HCos_d
                                          //  Referenced by: '<S147>/Sine Wave'

  real_T SineWave_PSin_n;              // Computed Parameter: SineWave_PSin_n
                                          //  Referenced by: '<S147>/Sine Wave'

  real_T SineWave_PCos_j;              // Computed Parameter: SineWave_PCos_j
                                          //  Referenced by: '<S147>/Sine Wave'

  real_T Constant2_Value_e;            // Expression: 1
                                          //  Referenced by: '<S10>/Constant2'

  real_T CovarianceZ_Value_i[9];       // Expression: pInitialization.Z
                                          //  Referenced by: '<S193>/CovarianceZ'

  real_T KalmanGainL_Value_o[6];       // Expression: pInitialization.L
                                          //  Referenced by: '<S193>/KalmanGainL'

  real_T phase_Value_c;                // Expression: PHASE
                                          //  Referenced by: '<S149>/phase'

  real_T enable_Value_h;               // Expression: 1
                                          //  Referenced by: '<S149>/enable'

  real_T phase_Value_d;                // Expression: PHASE
                                          //  Referenced by: '<S150>/phase'

  real_T enable_Value_p;               // Expression: 1
                                          //  Referenced by: '<S150>/enable'

  real_T KalmanGainM_Value_i[6];       // Expression: pInitialization.M
                                          //  Referenced by: '<S309>/KalmanGainM'

  real_T SineWave_Bias_k;              // Expression: 0
                                          //  Referenced by: '<S263>/Sine Wave'

  real_T SineWave_Hsin_e;              // Computed Parameter: SineWave_Hsin_e
                                          //  Referenced by: '<S263>/Sine Wave'

  real_T SineWave_HCos_n;              // Computed Parameter: SineWave_HCos_n
                                          //  Referenced by: '<S263>/Sine Wave'

  real_T SineWave_PSin_g;              // Computed Parameter: SineWave_PSin_g
                                          //  Referenced by: '<S263>/Sine Wave'

  real_T SineWave_PCos_a;              // Computed Parameter: SineWave_PCos_a
                                          //  Referenced by: '<S263>/Sine Wave'

  real_T Constant2_Value_o;            // Expression: 1
                                          //  Referenced by: '<S11>/Constant2'

  real_T CovarianceZ_Value_k[9];       // Expression: pInitialization.Z
                                          //  Referenced by: '<S309>/CovarianceZ'

  real_T KalmanGainL_Value_c[6];       // Expression: pInitialization.L
                                          //  Referenced by: '<S309>/KalmanGainL'

  real_T phase_Value_i;                // Expression: PHASE
                                          //  Referenced by: '<S265>/phase'

  real_T enable_Value_e;               // Expression: 1
                                          //  Referenced by: '<S265>/enable'

  real_T phase_Value_b;                // Expression: PHASE
                                          //  Referenced by: '<S266>/phase'

  real_T enable_Value_k;               // Expression: 1
                                          //  Referenced by: '<S266>/enable'

  real_T Constant3_Value;              // Expression: 1
                                          //  Referenced by: '<S1>/Constant3'

  real_T activate_Value;               // Expression: 1
                                          //  Referenced by: '<S7>/activate'

  real_T activate_Value_f;             // Expression: 1
                                          //  Referenced by: '<S8>/activate'

  real32_T DO_PWM_P2;                  // Expression: single(deadtime)
                                          //  Referenced by: '<S26>/DO_PWM'

  real32_T DO_PWM_P2_n;                // Expression: single(deadtime)
                                          //  Referenced by: '<S28>/DO_PWM'

  real32_T PWM_P2;                     // Expression: single(deadtime)
                                          //  Referenced by: '<S130>/PWM'

  real32_T PWM_P3;                     // Expression: single(duty)
                                          //  Referenced by: '<S130>/PWM'

  real32_T PWM_P4;                     // Expression: single(phase)
                                          //  Referenced by: '<S130>/PWM'

  real32_T PWM_P2_a;                   // Expression: single(deadtime)
                                          //  Referenced by: '<S132>/PWM'

  real32_T PWM_P3_f;                   // Expression: single(duty)
                                          //  Referenced by: '<S132>/PWM'

  real32_T PWM_P4_h;                   // Expression: single(phase)
                                          //  Referenced by: '<S132>/PWM'

  real32_T PWM_P2_m;                   // Expression: single(deadtime)
                                          //  Referenced by: '<S246>/PWM'

  real32_T PWM_P3_b;                   // Expression: single(duty)
                                          //  Referenced by: '<S246>/PWM'

  real32_T PWM_P4_n;                   // Expression: single(phase)
                                          //  Referenced by: '<S246>/PWM'

  real32_T PWM_P2_i;                   // Expression: single(deadtime)
                                          //  Referenced by: '<S248>/PWM'

  real32_T PWM_P3_o;                   // Expression: single(duty)
                                          //  Referenced by: '<S248>/PWM'

  real32_T PWM_P4_d;                   // Expression: single(phase)
                                          //  Referenced by: '<S248>/PWM'

  real32_T PWM_P2_e;                   // Expression: single(deadtime)
                                          //  Referenced by: '<S362>/PWM'

  real32_T PWM_P3_bi;                  // Expression: single(duty)
                                          //  Referenced by: '<S362>/PWM'

  real32_T PWM_P4_i;                   // Expression: single(phase)
                                          //  Referenced by: '<S362>/PWM'

  real32_T PWM_P2_ir;                  // Expression: single(deadtime)
                                          //  Referenced by: '<S364>/PWM'

  real32_T PWM_P3_e;                   // Expression: single(duty)
                                          //  Referenced by: '<S364>/PWM'

  real32_T PWM_P4_m;                   // Expression: single(phase)
                                          //  Referenced by: '<S364>/PWM'

  real32_T SFunction_P6;               // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S378>/S-Function'

  real32_T SFunction_P12;              // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S378>/S-Function'

  real32_T SFunction_P6_g;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S380>/S-Function'

  real32_T SFunction_P12_e;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S380>/S-Function'

  real32_T ADC_P2;                     // Expression: single(gain)
                                          //  Referenced by: '<S15>/ADC'

  real32_T ADC_P3;                     // Expression: single(offset)
                                          //  Referenced by: '<S15>/ADC'

  real32_T ADC_P2_o;                   // Expression: single(gain)
                                          //  Referenced by: '<S17>/ADC'

  real32_T ADC_P3_c;                   // Expression: single(offset)
                                          //  Referenced by: '<S17>/ADC'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S19>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S19>/Saturation'

  real32_T CLK1_P2;                    // Expression: single(frequency)
                                          //  Referenced by: '<S19>/CLK1'

  real32_T SFunction_P2;               // Expression: single(phase_vector)
                                          //  Referenced by: '<S22>/S-Function'

  real32_T SFunction_P3;               // Expression: single(interrupt_phase)
                                          //  Referenced by: '<S22>/S-Function'

  real32_T CLK1_P2_i;                  // Expression: single(frequency)
                                          //  Referenced by: '<S24>/CLK1'

  real32_T SFunction_P6_a;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S134>/S-Function'

  real32_T SFunction_P12_a;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S134>/S-Function'

  real32_T SFunction_P6_n;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S136>/S-Function'

  real32_T SFunction_P12_f;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S136>/S-Function'

  real32_T SFunction_P6_o;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S138>/S-Function'

  real32_T SFunction_P12_p;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S138>/S-Function'

  real32_T SFunction_P6_gu;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S140>/S-Function'

  real32_T SFunction_P12_c;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S140>/S-Function'

  real32_T SFunction_P6_k;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S142>/S-Function'

  real32_T SFunction_P12_h;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S142>/S-Function'

  real32_T SFunction_P6_l;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S144>/S-Function'

  real32_T SFunction_P12_b;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S144>/S-Function'

  real32_T ADC_P2_n;                   // Expression: single(gain)
                                          //  Referenced by: '<S42>/ADC'

  real32_T ADC_P3_o;                   // Expression: single(offset)
                                          //  Referenced by: '<S42>/ADC'

  real32_T ADC_P2_f;                   // Expression: single(gain)
                                          //  Referenced by: '<S44>/ADC'

  real32_T ADC_P3_of;                  // Expression: single(offset)
                                          //  Referenced by: '<S44>/ADC'

  real32_T C_Value[6];                 // Computed Parameter: C_Value
                                          //  Referenced by: '<S76>/C'

  real32_T X0_Value[3];                // Computed Parameter: X0_Value
                                          //  Referenced by: '<S76>/X0'

  real32_T SFunction_P3_i;             // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S61>/S-Function'

  real32_T SFunction_P4;               // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S61>/S-Function'

  real32_T SFunction_P5;               // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S61>/S-Function'

  real32_T SFunction_P6_m;             // Expression: single(0)
                                          //  Referenced by: '<S61>/S-Function'

  real32_T SFunction_P7;               // Expression: single(0)
                                          //  Referenced by: '<S61>/S-Function'

  real32_T SFunction_P3_b;             // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S75>/S-Function'

  real32_T SFunction_P4_g;             // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S75>/S-Function'

  real32_T SFunction_P5_k;             // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S75>/S-Function'

  real32_T SFunction_P6_b;             // Expression: single(0)
                                          //  Referenced by: '<S75>/S-Function'

  real32_T SFunction_P7_e;             // Expression: single(0)
                                          //  Referenced by: '<S75>/S-Function'

  real32_T Delay1_InitialCondition;
                                  // Computed Parameter: Delay1_InitialCondition
                                     //  Referenced by: '<S72>/Delay1'

  real32_T a0_Gain;                    // Computed Parameter: a0_Gain
                                          //  Referenced by: '<S72>/a0'

  real32_T Delay3_InitialCondition;
                                  // Computed Parameter: Delay3_InitialCondition
                                     //  Referenced by: '<S72>/Delay3'

  real32_T a1_Gain;                    // Computed Parameter: a1_Gain
                                          //  Referenced by: '<S72>/a1'

  real32_T Delay4_InitialCondition;
                                  // Computed Parameter: Delay4_InitialCondition
                                     //  Referenced by: '<S72>/Delay4'

  real32_T b1_Gain;                    // Computed Parameter: b1_Gain
                                          //  Referenced by: '<S72>/b1'

  real32_T Delay5_InitialCondition;
                                  // Computed Parameter: Delay5_InitialCondition
                                     //  Referenced by: '<S72>/Delay5'

  real32_T b2_Gain;                    // Computed Parameter: b2_Gain
                                          //  Referenced by: '<S72>/b2'

  real32_T ub0_Gain;                   // Computed Parameter: ub0_Gain
                                          //  Referenced by: '<S72>/1//b0'

  real32_T Saturation_LowerSat_a;   // Computed Parameter: Saturation_LowerSat_a
                                       //  Referenced by: '<S53>/Saturation'

  real32_T a0_Gain_j;                  // Computed Parameter: a0_Gain_j
                                          //  Referenced by: '<S56>/a0'

  real32_T Delay3_InitialCondition_c;
                                // Computed Parameter: Delay3_InitialCondition_c
                                   //  Referenced by: '<S56>/Delay3'

  real32_T a1_Gain_o;                  // Computed Parameter: a1_Gain_o
                                          //  Referenced by: '<S56>/a1'

  real32_T Delay4_InitialCondition_f;
                                // Computed Parameter: Delay4_InitialCondition_f
                                   //  Referenced by: '<S56>/Delay4'

  real32_T b1_Gain_o;                  // Computed Parameter: b1_Gain_o
                                          //  Referenced by: '<S56>/b1'

  real32_T Delay5_InitialCondition_l;
                                // Computed Parameter: Delay5_InitialCondition_l
                                   //  Referenced by: '<S56>/Delay5'

  real32_T b2_Gain_c;                  // Computed Parameter: b2_Gain_c
                                          //  Referenced by: '<S56>/b2'

  real32_T ub0_Gain_m;                 // Computed Parameter: ub0_Gain_m
                                          //  Referenced by: '<S56>/1//b0'

  real32_T a0_Gain_m;                  // Computed Parameter: a0_Gain_m
                                          //  Referenced by: '<S57>/a0'

  real32_T Delay3_InitialCondition_p;
                                // Computed Parameter: Delay3_InitialCondition_p
                                   //  Referenced by: '<S57>/Delay3'

  real32_T a1_Gain_k;                  // Computed Parameter: a1_Gain_k
                                          //  Referenced by: '<S57>/a1'

  real32_T Delay4_InitialCondition_m;
                                // Computed Parameter: Delay4_InitialCondition_m
                                   //  Referenced by: '<S57>/Delay4'

  real32_T b1_Gain_i;                  // Computed Parameter: b1_Gain_i
                                          //  Referenced by: '<S57>/b1'

  real32_T Delay5_InitialCondition_o;
                                // Computed Parameter: Delay5_InitialCondition_o
                                   //  Referenced by: '<S57>/Delay5'

  real32_T b2_Gain_a;                  // Computed Parameter: b2_Gain_a
                                          //  Referenced by: '<S57>/b2'

  real32_T ub0_Gain_p;                 // Computed Parameter: ub0_Gain_p
                                          //  Referenced by: '<S57>/1//b0'

  real32_T a0_Gain_b;                  // Computed Parameter: a0_Gain_b
                                          //  Referenced by: '<S54>/a0'

  real32_T Delay3_InitialCondition_d;
                                // Computed Parameter: Delay3_InitialCondition_d
                                   //  Referenced by: '<S54>/Delay3'

  real32_T a1_Gain_c;                  // Computed Parameter: a1_Gain_c
                                          //  Referenced by: '<S54>/a1'

  real32_T Delay4_InitialCondition_fy;
                               // Computed Parameter: Delay4_InitialCondition_fy
                                  //  Referenced by: '<S54>/Delay4'

  real32_T b1_Gain_p;                  // Computed Parameter: b1_Gain_p
                                          //  Referenced by: '<S54>/b1'

  real32_T Delay5_InitialCondition_e;
                                // Computed Parameter: Delay5_InitialCondition_e
                                   //  Referenced by: '<S54>/Delay5'

  real32_T b2_Gain_p;                  // Computed Parameter: b2_Gain_p
                                          //  Referenced by: '<S54>/b2'

  real32_T ub0_Gain_mq;                // Computed Parameter: ub0_Gain_mq
                                          //  Referenced by: '<S54>/1//b0'

  real32_T a0_Gain_g;                  // Computed Parameter: a0_Gain_g
                                          //  Referenced by: '<S55>/a0'

  real32_T Delay3_InitialCondition_dr;
                               // Computed Parameter: Delay3_InitialCondition_dr
                                  //  Referenced by: '<S55>/Delay3'

  real32_T a1_Gain_op;                 // Computed Parameter: a1_Gain_op
                                          //  Referenced by: '<S55>/a1'

  real32_T Delay4_InitialCondition_fyn;
                              // Computed Parameter: Delay4_InitialCondition_fyn
                                 //  Referenced by: '<S55>/Delay4'

  real32_T b1_Gain_l;                  // Computed Parameter: b1_Gain_l
                                          //  Referenced by: '<S55>/b1'

  real32_T Delay5_InitialCondition_ew;
                               // Computed Parameter: Delay5_InitialCondition_ew
                                  //  Referenced by: '<S55>/Delay5'

  real32_T b2_Gain_j;                  // Computed Parameter: b2_Gain_j
                                          //  Referenced by: '<S55>/b2'

  real32_T ub0_Gain_k;                 // Computed Parameter: ub0_Gain_k
                                          //  Referenced by: '<S55>/1//b0'

  real32_T SFunction_P6_e;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S63>/S-Function'

  real32_T SFunction_P12_g;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S63>/S-Function'

  real32_T SFunction_P6_ah;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S65>/S-Function'

  real32_T SFunction_P12_hs;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S65>/S-Function'

  real32_T SFunction_P6_ow;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S67>/S-Function'

  real32_T SFunction_P12_i;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S67>/S-Function'

  real32_T SFunction_P6_c;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S69>/S-Function'

  real32_T SFunction_P12_bv;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S69>/S-Function'

  real32_T SFunction_P6_o0;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S71>/S-Function'

  real32_T SFunction_P12_an;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S71>/S-Function'

  real32_T GIDifferentiator_NumCoef[3];
                                 // Computed Parameter: GIDifferentiator_NumCoef
                                    //  Referenced by: '<S32>/GI Differentiator'

  real32_T GIDifferentiator_DenCoef[3];
                                 // Computed Parameter: GIDifferentiator_DenCoef
                                    //  Referenced by: '<S32>/GI Differentiator'

  real32_T GIDifferentiator_InitialStates;
                           // Computed Parameter: GIDifferentiator_InitialStates
                              //  Referenced by: '<S32>/GI Differentiator'

  real32_T A_Value[9];                 // Computed Parameter: A_Value
                                          //  Referenced by: '<S76>/A'

  real32_T B_Value[6];                 // Computed Parameter: B_Value
                                          //  Referenced by: '<S76>/B'

  real32_T D_Value[4];                 // Computed Parameter: D_Value
                                          //  Referenced by: '<S76>/D'

  real32_T SFunction_P6_nz;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S250>/S-Function'

  real32_T SFunction_P12_ba;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S250>/S-Function'

  real32_T SFunction_P6_mm;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S252>/S-Function'

  real32_T SFunction_P12_es;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S252>/S-Function'

  real32_T SFunction_P6_ahc;           // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S254>/S-Function'

  real32_T SFunction_P12_o;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S254>/S-Function'

  real32_T SFunction_P6_oq;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S256>/S-Function'

  real32_T SFunction_P12_n;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S256>/S-Function'

  real32_T SFunction_P6_j;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S258>/S-Function'

  real32_T SFunction_P12_fs;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S258>/S-Function'

  real32_T SFunction_P6_ce;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S260>/S-Function'

  real32_T SFunction_P12_pp;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S260>/S-Function'

  real32_T ADC_P2_p;                   // Expression: single(gain)
                                          //  Referenced by: '<S158>/ADC'

  real32_T ADC_P3_cp;                  // Expression: single(offset)
                                          //  Referenced by: '<S158>/ADC'

  real32_T ADC_P2_k;                   // Expression: single(gain)
                                          //  Referenced by: '<S160>/ADC'

  real32_T ADC_P3_d;                   // Expression: single(offset)
                                          //  Referenced by: '<S160>/ADC'

  real32_T C_Value_j[6];               // Computed Parameter: C_Value_j
                                          //  Referenced by: '<S192>/C'

  real32_T X0_Value_f[3];              // Computed Parameter: X0_Value_f
                                          //  Referenced by: '<S192>/X0'

  real32_T SFunction_P3_c;             // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S177>/S-Function'

  real32_T SFunction_P4_a;             // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S177>/S-Function'

  real32_T SFunction_P5_i;             // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S177>/S-Function'

  real32_T SFunction_P6_h;             // Expression: single(0)
                                          //  Referenced by: '<S177>/S-Function'

  real32_T SFunction_P7_h;             // Expression: single(0)
                                          //  Referenced by: '<S177>/S-Function'

  real32_T SFunction_P3_cd;            // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S191>/S-Function'

  real32_T SFunction_P4_h;             // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S191>/S-Function'

  real32_T SFunction_P5_d;             // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S191>/S-Function'

  real32_T SFunction_P6_lu;            // Expression: single(0)
                                          //  Referenced by: '<S191>/S-Function'

  real32_T SFunction_P7_l;             // Expression: single(0)
                                          //  Referenced by: '<S191>/S-Function'

  real32_T Delay1_InitialCondition_c;
                                // Computed Parameter: Delay1_InitialCondition_c
                                   //  Referenced by: '<S188>/Delay1'

  real32_T a0_Gain_a;                  // Computed Parameter: a0_Gain_a
                                          //  Referenced by: '<S188>/a0'

  real32_T Delay3_InitialCondition_o;
                                // Computed Parameter: Delay3_InitialCondition_o
                                   //  Referenced by: '<S188>/Delay3'

  real32_T a1_Gain_n;                  // Computed Parameter: a1_Gain_n
                                          //  Referenced by: '<S188>/a1'

  real32_T Delay4_InitialCondition_j;
                                // Computed Parameter: Delay4_InitialCondition_j
                                   //  Referenced by: '<S188>/Delay4'

  real32_T b1_Gain_d;                  // Computed Parameter: b1_Gain_d
                                          //  Referenced by: '<S188>/b1'

  real32_T Delay5_InitialCondition_p;
                                // Computed Parameter: Delay5_InitialCondition_p
                                   //  Referenced by: '<S188>/Delay5'

  real32_T b2_Gain_n;                  // Computed Parameter: b2_Gain_n
                                          //  Referenced by: '<S188>/b2'

  real32_T ub0_Gain_c;                 // Computed Parameter: ub0_Gain_c
                                          //  Referenced by: '<S188>/1//b0'

  real32_T Saturation_LowerSat_b;   // Computed Parameter: Saturation_LowerSat_b
                                       //  Referenced by: '<S169>/Saturation'

  real32_T a0_Gain_o;                  // Computed Parameter: a0_Gain_o
                                          //  Referenced by: '<S172>/a0'

  real32_T Delay3_InitialCondition_dv;
                               // Computed Parameter: Delay3_InitialCondition_dv
                                  //  Referenced by: '<S172>/Delay3'

  real32_T a1_Gain_l;                  // Computed Parameter: a1_Gain_l
                                          //  Referenced by: '<S172>/a1'

  real32_T Delay4_InitialCondition_e;
                                // Computed Parameter: Delay4_InitialCondition_e
                                   //  Referenced by: '<S172>/Delay4'

  real32_T b1_Gain_e;                  // Computed Parameter: b1_Gain_e
                                          //  Referenced by: '<S172>/b1'

  real32_T Delay5_InitialCondition_k;
                                // Computed Parameter: Delay5_InitialCondition_k
                                   //  Referenced by: '<S172>/Delay5'

  real32_T b2_Gain_i;                  // Computed Parameter: b2_Gain_i
                                          //  Referenced by: '<S172>/b2'

  real32_T ub0_Gain_ps;                // Computed Parameter: ub0_Gain_ps
                                          //  Referenced by: '<S172>/1//b0'

  real32_T a0_Gain_mp;                 // Computed Parameter: a0_Gain_mp
                                          //  Referenced by: '<S173>/a0'

  real32_T Delay3_InitialCondition_k;
                                // Computed Parameter: Delay3_InitialCondition_k
                                   //  Referenced by: '<S173>/Delay3'

  real32_T a1_Gain_o3;                 // Computed Parameter: a1_Gain_o3
                                          //  Referenced by: '<S173>/a1'

  real32_T Delay4_InitialCondition_h;
                                // Computed Parameter: Delay4_InitialCondition_h
                                   //  Referenced by: '<S173>/Delay4'

  real32_T b1_Gain_di;                 // Computed Parameter: b1_Gain_di
                                          //  Referenced by: '<S173>/b1'

  real32_T Delay5_InitialCondition_i;
                                // Computed Parameter: Delay5_InitialCondition_i
                                   //  Referenced by: '<S173>/Delay5'

  real32_T b2_Gain_e;                  // Computed Parameter: b2_Gain_e
                                          //  Referenced by: '<S173>/b2'

  real32_T ub0_Gain_g;                 // Computed Parameter: ub0_Gain_g
                                          //  Referenced by: '<S173>/1//b0'

  real32_T a0_Gain_n;                  // Computed Parameter: a0_Gain_n
                                          //  Referenced by: '<S170>/a0'

  real32_T Delay3_InitialCondition_a;
                                // Computed Parameter: Delay3_InitialCondition_a
                                   //  Referenced by: '<S170>/Delay3'

  real32_T a1_Gain_a;                  // Computed Parameter: a1_Gain_a
                                          //  Referenced by: '<S170>/a1'

  real32_T Delay4_InitialCondition_g;
                                // Computed Parameter: Delay4_InitialCondition_g
                                   //  Referenced by: '<S170>/Delay4'

  real32_T b1_Gain_h;                  // Computed Parameter: b1_Gain_h
                                          //  Referenced by: '<S170>/b1'

  real32_T Delay5_InitialCondition_m;
                                // Computed Parameter: Delay5_InitialCondition_m
                                   //  Referenced by: '<S170>/Delay5'

  real32_T b2_Gain_m;                  // Computed Parameter: b2_Gain_m
                                          //  Referenced by: '<S170>/b2'

  real32_T ub0_Gain_h;                 // Computed Parameter: ub0_Gain_h
                                          //  Referenced by: '<S170>/1//b0'

  real32_T a0_Gain_f;                  // Computed Parameter: a0_Gain_f
                                          //  Referenced by: '<S171>/a0'

  real32_T Delay3_InitialCondition_f;
                                // Computed Parameter: Delay3_InitialCondition_f
                                   //  Referenced by: '<S171>/Delay3'

  real32_T a1_Gain_f;                  // Computed Parameter: a1_Gain_f
                                          //  Referenced by: '<S171>/a1'

  real32_T Delay4_InitialCondition_c;
                                // Computed Parameter: Delay4_InitialCondition_c
                                   //  Referenced by: '<S171>/Delay4'

  real32_T b1_Gain_j;                  // Computed Parameter: b1_Gain_j
                                          //  Referenced by: '<S171>/b1'

  real32_T Delay5_InitialCondition_ez;
                               // Computed Parameter: Delay5_InitialCondition_ez
                                  //  Referenced by: '<S171>/Delay5'

  real32_T b2_Gain_ch;                 // Computed Parameter: b2_Gain_ch
                                          //  Referenced by: '<S171>/b2'

  real32_T ub0_Gain_he;                // Computed Parameter: ub0_Gain_he
                                          //  Referenced by: '<S171>/1//b0'

  real32_T SFunction_P6_j2;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S179>/S-Function'

  real32_T SFunction_P12_m;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S179>/S-Function'

  real32_T SFunction_P6_bu;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S181>/S-Function'

  real32_T SFunction_P12_pf;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S181>/S-Function'

  real32_T SFunction_P6_oj;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S183>/S-Function'

  real32_T SFunction_P12_fe;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S183>/S-Function'

  real32_T SFunction_P6_d;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S185>/S-Function'

  real32_T SFunction_P12_hr;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S185>/S-Function'

  real32_T SFunction_P6_lb;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S187>/S-Function'

  real32_T SFunction_P12_my;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S187>/S-Function'

  real32_T GIDifferentiator_NumCoef_e[3];
                               // Computed Parameter: GIDifferentiator_NumCoef_e
                                  //  Referenced by: '<S148>/GI Differentiator'

  real32_T GIDifferentiator_DenCoef_m[3];
                               // Computed Parameter: GIDifferentiator_DenCoef_m
                                  //  Referenced by: '<S148>/GI Differentiator'

  real32_T GIDifferentiator_InitialState_o;
                          // Computed Parameter: GIDifferentiator_InitialState_o
                             //  Referenced by: '<S148>/GI Differentiator'

  real32_T A_Value_k[9];               // Computed Parameter: A_Value_k
                                          //  Referenced by: '<S192>/A'

  real32_T B_Value_f[6];               // Computed Parameter: B_Value_f
                                          //  Referenced by: '<S192>/B'

  real32_T D_Value_g[4];               // Computed Parameter: D_Value_g
                                          //  Referenced by: '<S192>/D'

  real32_T SFunction_P6_bh;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S366>/S-Function'

  real32_T SFunction_P12_g5;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S366>/S-Function'

  real32_T SFunction_P6_je;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S368>/S-Function'

  real32_T SFunction_P12_bm;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S368>/S-Function'

  real32_T SFunction_P6_h1;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S370>/S-Function'

  real32_T SFunction_P12_ao;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S370>/S-Function'

  real32_T SFunction_P6_p;             // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S372>/S-Function'

  real32_T SFunction_P12_l;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S372>/S-Function'

  real32_T SFunction_P6_bl;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S374>/S-Function'

  real32_T SFunction_P12_mg;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S374>/S-Function'

  real32_T SFunction_P6_gn;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S376>/S-Function'

  real32_T SFunction_P12_ea;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S376>/S-Function'

  real32_T ADC_P2_j;                   // Expression: single(gain)
                                          //  Referenced by: '<S274>/ADC'

  real32_T ADC_P3_cy;                  // Expression: single(offset)
                                          //  Referenced by: '<S274>/ADC'

  real32_T ADC_P2_m;                   // Expression: single(gain)
                                          //  Referenced by: '<S276>/ADC'

  real32_T ADC_P3_p;                   // Expression: single(offset)
                                          //  Referenced by: '<S276>/ADC'

  real32_T C_Value_c[6];               // Computed Parameter: C_Value_c
                                          //  Referenced by: '<S308>/C'

  real32_T X0_Value_i[3];              // Computed Parameter: X0_Value_i
                                          //  Referenced by: '<S308>/X0'

  real32_T SFunction_P3_ib;            // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S293>/S-Function'

  real32_T SFunction_P4_d;             // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S293>/S-Function'

  real32_T SFunction_P5_e;             // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S293>/S-Function'

  real32_T SFunction_P6_gk;            // Expression: single(0)
                                          //  Referenced by: '<S293>/S-Function'

  real32_T SFunction_P7_b;             // Expression: single(0)
                                          //  Referenced by: '<S293>/S-Function'

  real32_T SFunction_P3_d;             // Expression: single(INITIALVAL)
                                          //  Referenced by: '<S307>/S-Function'

  real32_T SFunction_P4_k;             // Expression: single(VAL_MIN)
                                          //  Referenced by: '<S307>/S-Function'

  real32_T SFunction_P5_j;             // Expression: single(VAL_MAX)
                                          //  Referenced by: '<S307>/S-Function'

  real32_T SFunction_P6_d5;            // Expression: single(0)
                                          //  Referenced by: '<S307>/S-Function'

  real32_T SFunction_P7_d;             // Expression: single(0)
                                          //  Referenced by: '<S307>/S-Function'

  real32_T Delay1_InitialCondition_a;
                                // Computed Parameter: Delay1_InitialCondition_a
                                   //  Referenced by: '<S304>/Delay1'

  real32_T a0_Gain_e;                  // Computed Parameter: a0_Gain_e
                                          //  Referenced by: '<S304>/a0'

  real32_T Delay3_InitialCondition_ct;
                               // Computed Parameter: Delay3_InitialCondition_ct
                                  //  Referenced by: '<S304>/Delay3'

  real32_T a1_Gain_kb;                 // Computed Parameter: a1_Gain_kb
                                          //  Referenced by: '<S304>/a1'

  real32_T Delay4_InitialCondition_d;
                                // Computed Parameter: Delay4_InitialCondition_d
                                   //  Referenced by: '<S304>/Delay4'

  real32_T b1_Gain_j5;                 // Computed Parameter: b1_Gain_j5
                                          //  Referenced by: '<S304>/b1'

  real32_T Delay5_InitialCondition_em;
                               // Computed Parameter: Delay5_InitialCondition_em
                                  //  Referenced by: '<S304>/Delay5'

  real32_T b2_Gain_l;                  // Computed Parameter: b2_Gain_l
                                          //  Referenced by: '<S304>/b2'

  real32_T ub0_Gain_i;                 // Computed Parameter: ub0_Gain_i
                                          //  Referenced by: '<S304>/1//b0'

  real32_T Saturation_LowerSat_k;   // Computed Parameter: Saturation_LowerSat_k
                                       //  Referenced by: '<S285>/Saturation'

  real32_T a0_Gain_nt;                 // Computed Parameter: a0_Gain_nt
                                          //  Referenced by: '<S288>/a0'

  real32_T Delay3_InitialCondition_om;
                               // Computed Parameter: Delay3_InitialCondition_om
                                  //  Referenced by: '<S288>/Delay3'

  real32_T a1_Gain_ap;                 // Computed Parameter: a1_Gain_ap
                                          //  Referenced by: '<S288>/a1'

  real32_T Delay4_InitialCondition_d1;
                               // Computed Parameter: Delay4_InitialCondition_d1
                                  //  Referenced by: '<S288>/Delay4'

  real32_T b1_Gain_ep;                 // Computed Parameter: b1_Gain_ep
                                          //  Referenced by: '<S288>/b1'

  real32_T Delay5_InitialCondition_c;
                                // Computed Parameter: Delay5_InitialCondition_c
                                   //  Referenced by: '<S288>/Delay5'

  real32_T b2_Gain_f;                  // Computed Parameter: b2_Gain_f
                                          //  Referenced by: '<S288>/b2'

  real32_T ub0_Gain_e;                 // Computed Parameter: ub0_Gain_e
                                          //  Referenced by: '<S288>/1//b0'

  real32_T a0_Gain_f0;                 // Computed Parameter: a0_Gain_f0
                                          //  Referenced by: '<S289>/a0'

  real32_T Delay3_InitialCondition_ke;
                               // Computed Parameter: Delay3_InitialCondition_ke
                                  //  Referenced by: '<S289>/Delay3'

  real32_T a1_Gain_h;                  // Computed Parameter: a1_Gain_h
                                          //  Referenced by: '<S289>/a1'

  real32_T Delay4_InitialCondition_jc;
                               // Computed Parameter: Delay4_InitialCondition_jc
                                  //  Referenced by: '<S289>/Delay4'

  real32_T b1_Gain_oj;                 // Computed Parameter: b1_Gain_oj
                                          //  Referenced by: '<S289>/b1'

  real32_T Delay5_InitialCondition_p0;
                               // Computed Parameter: Delay5_InitialCondition_p0
                                  //  Referenced by: '<S289>/Delay5'

  real32_T b2_Gain_o;                  // Computed Parameter: b2_Gain_o
                                          //  Referenced by: '<S289>/b2'

  real32_T ub0_Gain_g5;                // Computed Parameter: ub0_Gain_g5
                                          //  Referenced by: '<S289>/1//b0'

  real32_T a0_Gain_p;                  // Computed Parameter: a0_Gain_p
                                          //  Referenced by: '<S286>/a0'

  real32_T Delay3_InitialCondition_py;
                               // Computed Parameter: Delay3_InitialCondition_py
                                  //  Referenced by: '<S286>/Delay3'

  real32_T a1_Gain_e;                  // Computed Parameter: a1_Gain_e
                                          //  Referenced by: '<S286>/a1'

  real32_T Delay4_InitialCondition_a;
                                // Computed Parameter: Delay4_InitialCondition_a
                                   //  Referenced by: '<S286>/Delay4'

  real32_T b1_Gain_ih;                 // Computed Parameter: b1_Gain_ih
                                          //  Referenced by: '<S286>/b1'

  real32_T Delay5_InitialCondition_id;
                               // Computed Parameter: Delay5_InitialCondition_id
                                  //  Referenced by: '<S286>/Delay5'

  real32_T b2_Gain_mf;                 // Computed Parameter: b2_Gain_mf
                                          //  Referenced by: '<S286>/b2'

  real32_T ub0_Gain_h1;                // Computed Parameter: ub0_Gain_h1
                                          //  Referenced by: '<S286>/1//b0'

  real32_T a0_Gain_l;                  // Computed Parameter: a0_Gain_l
                                          //  Referenced by: '<S287>/a0'

  real32_T Delay3_InitialCondition_i;
                                // Computed Parameter: Delay3_InitialCondition_i
                                   //  Referenced by: '<S287>/Delay3'

  real32_T a1_Gain_m;                  // Computed Parameter: a1_Gain_m
                                          //  Referenced by: '<S287>/a1'

  real32_T Delay4_InitialCondition_hn;
                               // Computed Parameter: Delay4_InitialCondition_hn
                                  //  Referenced by: '<S287>/Delay4'

  real32_T b1_Gain_ot;                 // Computed Parameter: b1_Gain_ot
                                          //  Referenced by: '<S287>/b1'

  real32_T Delay5_InitialCondition_i1;
                               // Computed Parameter: Delay5_InitialCondition_i1
                                  //  Referenced by: '<S287>/Delay5'

  real32_T b2_Gain_d;                  // Computed Parameter: b2_Gain_d
                                          //  Referenced by: '<S287>/b2'

  real32_T ub0_Gain_kl;                // Computed Parameter: ub0_Gain_kl
                                          //  Referenced by: '<S287>/1//b0'

  real32_T SFunction_P6_cs;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S295>/S-Function'

  real32_T SFunction_P12_nk;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S295>/S-Function'

  real32_T SFunction_P6_cl;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S297>/S-Function'

  real32_T SFunction_P12_cq;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S297>/S-Function'

  real32_T SFunction_P6_mi;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S299>/S-Function'

  real32_T SFunction_P12_ms;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S299>/S-Function'

  real32_T SFunction_P6_cc;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S301>/S-Function'

  real32_T SFunction_P12_d;            // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S301>/S-Function'

  real32_T SFunction_P6_g5;            // Expression: single(CAN_TX_FREQ)
                                          //  Referenced by: '<S303>/S-Function'

  real32_T SFunction_P12_d4;           // Expression: single(ETH_TX_FREQ)
                                          //  Referenced by: '<S303>/S-Function'

  real32_T GIDifferentiator_NumCoef_m[3];
                               // Computed Parameter: GIDifferentiator_NumCoef_m
                                  //  Referenced by: '<S264>/GI Differentiator'

  real32_T GIDifferentiator_DenCoef_ms[3];
                              // Computed Parameter: GIDifferentiator_DenCoef_ms
                                 //  Referenced by: '<S264>/GI Differentiator'

  real32_T GIDifferentiator_InitialState_e;
                          // Computed Parameter: GIDifferentiator_InitialState_e
                             //  Referenced by: '<S264>/GI Differentiator'

  real32_T A_Value_f[9];               // Computed Parameter: A_Value_f
                                          //  Referenced by: '<S308>/A'

  real32_T B_Value_d[6];               // Computed Parameter: B_Value_d
                                          //  Referenced by: '<S308>/B'

  real32_T D_Value_i[4];               // Computed Parameter: D_Value_i
                                          //  Referenced by: '<S308>/D'

  uint32_T SFunction_P7_k;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S378>/S-Function'

  uint32_T SFunction_P13;              // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S378>/S-Function'

  uint32_T SFunction_P7_i;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S380>/S-Function'

  uint32_T SFunction_P13_b;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S380>/S-Function'

  uint32_T SFunction_P7_ii;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S134>/S-Function'

  uint32_T SFunction_P13_l;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S134>/S-Function'

  uint32_T SFunction_P7_bg;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S136>/S-Function'

  uint32_T SFunction_P13_i;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S136>/S-Function'

  uint32_T SFunction_P7_c;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S138>/S-Function'

  uint32_T SFunction_P13_n;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S138>/S-Function'

  uint32_T SFunction_P7_f;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S140>/S-Function'

  uint32_T SFunction_P13_a;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S140>/S-Function'

  uint32_T SFunction_P7_p;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S142>/S-Function'

  uint32_T SFunction_P13_nw;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S142>/S-Function'

  uint32_T SFunction_P7_kg;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S144>/S-Function'

  uint32_T SFunction_P13_k;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S144>/S-Function'

  uint32_T SFunction_P10;              // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S61>/S-Function'

  uint32_T SFunction_P10_d;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S75>/S-Function'

  uint32_T SFunction_P7_ir;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S63>/S-Function'

  uint32_T SFunction_P13_m;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S63>/S-Function'

  uint32_T SFunction_P7_m;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S65>/S-Function'

  uint32_T SFunction_P13_c;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S65>/S-Function'

  uint32_T SFunction_P7_fi;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S67>/S-Function'

  uint32_T SFunction_P13_f;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S67>/S-Function'

  uint32_T SFunction_P7_j;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S69>/S-Function'

  uint32_T SFunction_P13_p;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S69>/S-Function'

  uint32_T SFunction_P7_g;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S71>/S-Function'

  uint32_T SFunction_P13_ls;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S71>/S-Function'

  uint32_T SFunction_P7_eo;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S250>/S-Function'

  uint32_T SFunction_P13_n1;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S250>/S-Function'

  uint32_T SFunction_P7_dz;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S252>/S-Function'

  uint32_T SFunction_P13_bj;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S252>/S-Function'

  uint32_T SFunction_P7_i0;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S254>/S-Function'

  uint32_T SFunction_P13_kz;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S254>/S-Function'

  uint32_T SFunction_P7_a;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S256>/S-Function'

  uint32_T SFunction_P13_e;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S256>/S-Function'

  uint32_T SFunction_P7_ht;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S258>/S-Function'

  uint32_T SFunction_P13_ci;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S258>/S-Function'

  uint32_T SFunction_P7_az;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S260>/S-Function'

  uint32_T SFunction_P13_b0;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S260>/S-Function'

  uint32_T SFunction_P10_p;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S177>/S-Function'

  uint32_T SFunction_P10_f;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S191>/S-Function'

  uint32_T SFunction_P7_ai;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S179>/S-Function'

  uint32_T SFunction_P13_d;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S179>/S-Function'

  uint32_T SFunction_P7_p3;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S181>/S-Function'

  uint32_T SFunction_P13_pt;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S181>/S-Function'

  uint32_T SFunction_P7_n;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S183>/S-Function'

  uint32_T SFunction_P13_h;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S183>/S-Function'

  uint32_T SFunction_P7_o;             // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S185>/S-Function'

  uint32_T SFunction_P13_ah;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S185>/S-Function'

  uint32_T SFunction_P7_fx;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S187>/S-Function'

  uint32_T SFunction_P13_ce;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S187>/S-Function'

  uint32_T SFunction_P7_bl;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S366>/S-Function'

  uint32_T SFunction_P13_i2;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S366>/S-Function'

  uint32_T SFunction_P7_gp;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S368>/S-Function'

  uint32_T SFunction_P13_c2;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S368>/S-Function'

  uint32_T SFunction_P7_l0;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S370>/S-Function'

  uint32_T SFunction_P13_o;            // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S370>/S-Function'

  uint32_T SFunction_P7_pb;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S372>/S-Function'

  uint32_T SFunction_P13_ih;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S372>/S-Function'

  uint32_T SFunction_P7_dp;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S374>/S-Function'

  uint32_T SFunction_P13_ad;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S374>/S-Function'

  uint32_T SFunction_P7_ej;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S376>/S-Function'

  uint32_T SFunction_P13_p3;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S376>/S-Function'

  uint32_T SFunction_P10_o;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S293>/S-Function'

  uint32_T SFunction_P10_p5;           // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S307>/S-Function'

  uint32_T SFunction_P7_bu;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S295>/S-Function'

  uint32_T SFunction_P13_ew;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S295>/S-Function'

  uint32_T SFunction_P7_l0g;           // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S297>/S-Function'

  uint32_T SFunction_P13_fa;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S297>/S-Function'

  uint32_T SFunction_P7_l2;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S299>/S-Function'

  uint32_T SFunction_P13_dz;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S299>/S-Function'

  uint32_T SFunction_P7_c1;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S301>/S-Function'

  uint32_T SFunction_P13_as;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S301>/S-Function'

  uint32_T SFunction_P7_g5;            // Expression: uint32(CAN_BAUDRATE)
                                          //  Referenced by: '<S303>/S-Function'

  uint32_T SFunction_P13_l2;           // Expression: uint32(ETH_PORT)
                                          //  Referenced by: '<S303>/S-Function'

  int16_T DO_PWM_P1;                   // Expression: int16(lane)
                                          //  Referenced by: '<S26>/DO_PWM'

  int16_T DO_PWM_P3;                   // Expression: int16(outconf)
                                          //  Referenced by: '<S26>/DO_PWM'

  int16_T DO_PWM_P4;                   // Expression: int16(nbBbx)
                                          //  Referenced by: '<S26>/DO_PWM'

  int16_T DO_PWM_P1_i;                 // Expression: int16(lane)
                                          //  Referenced by: '<S28>/DO_PWM'

  int16_T DO_PWM_P3_a;                 // Expression: int16(outconf)
                                          //  Referenced by: '<S28>/DO_PWM'

  int16_T DO_PWM_P4_g;                 // Expression: int16(nbBbx)
                                          //  Referenced by: '<S28>/DO_PWM'

  int16_T PWM_P1;                      // Expression: int16(lane)
                                          //  Referenced by: '<S130>/PWM'

  int16_T PWM_P5;                      // Expression: int16(carrier)
                                          //  Referenced by: '<S130>/PWM'

  int16_T PWM_P6;                      // Expression: int16(rate)
                                          //  Referenced by: '<S130>/PWM'

  int16_T PWM_P7;                      // Expression: int16(outconf)
                                          //  Referenced by: '<S130>/PWM'

  int16_T PWM_P8;                      // Expression: int16(outmode)
                                          //  Referenced by: '<S130>/PWM'

  int16_T PWM_P9;                      // Expression: int16(nbBbx)
                                          //  Referenced by: '<S130>/PWM'

  int16_T PWM_P1_d;                    // Expression: int16(lane)
                                          //  Referenced by: '<S132>/PWM'

  int16_T PWM_P5_e;                    // Expression: int16(carrier)
                                          //  Referenced by: '<S132>/PWM'

  int16_T PWM_P6_g;                    // Expression: int16(rate)
                                          //  Referenced by: '<S132>/PWM'

  int16_T PWM_P7_e;                    // Expression: int16(outconf)
                                          //  Referenced by: '<S132>/PWM'

  int16_T PWM_P8_a;                    // Expression: int16(outmode)
                                          //  Referenced by: '<S132>/PWM'

  int16_T PWM_P9_j;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S132>/PWM'

  int16_T PWM_P1_c;                    // Expression: int16(lane)
                                          //  Referenced by: '<S246>/PWM'

  int16_T PWM_P5_f;                    // Expression: int16(carrier)
                                          //  Referenced by: '<S246>/PWM'

  int16_T PWM_P6_c;                    // Expression: int16(rate)
                                          //  Referenced by: '<S246>/PWM'

  int16_T PWM_P7_h;                    // Expression: int16(outconf)
                                          //  Referenced by: '<S246>/PWM'

  int16_T PWM_P8_p;                    // Expression: int16(outmode)
                                          //  Referenced by: '<S246>/PWM'

  int16_T PWM_P9_b;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S246>/PWM'

  int16_T PWM_P1_l;                    // Expression: int16(lane)
                                          //  Referenced by: '<S248>/PWM'

  int16_T PWM_P5_d;                    // Expression: int16(carrier)
                                          //  Referenced by: '<S248>/PWM'

  int16_T PWM_P6_l;                    // Expression: int16(rate)
                                          //  Referenced by: '<S248>/PWM'

  int16_T PWM_P7_a;                    // Expression: int16(outconf)
                                          //  Referenced by: '<S248>/PWM'

  int16_T PWM_P8_pz;                   // Expression: int16(outmode)
                                          //  Referenced by: '<S248>/PWM'

  int16_T PWM_P9_c;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S248>/PWM'

  int16_T PWM_P1_i;                    // Expression: int16(lane)
                                          //  Referenced by: '<S362>/PWM'

  int16_T PWM_P5_l;                    // Expression: int16(carrier)
                                          //  Referenced by: '<S362>/PWM'

  int16_T PWM_P6_cw;                   // Expression: int16(rate)
                                          //  Referenced by: '<S362>/PWM'

  int16_T PWM_P7_c;                    // Expression: int16(outconf)
                                          //  Referenced by: '<S362>/PWM'

  int16_T PWM_P8_n;                    // Expression: int16(outmode)
                                          //  Referenced by: '<S362>/PWM'

  int16_T PWM_P9_cf;                   // Expression: int16(nbBbx)
                                          //  Referenced by: '<S362>/PWM'

  int16_T PWM_P1_f;                    // Expression: int16(lane)
                                          //  Referenced by: '<S364>/PWM'

  int16_T PWM_P5_dr;                   // Expression: int16(carrier)
                                          //  Referenced by: '<S364>/PWM'

  int16_T PWM_P6_cn;                   // Expression: int16(rate)
                                          //  Referenced by: '<S364>/PWM'

  int16_T PWM_P7_n;                    // Expression: int16(outconf)
                                          //  Referenced by: '<S364>/PWM'

  int16_T PWM_P8_f;                    // Expression: int16(outmode)
                                          //  Referenced by: '<S364>/PWM'

  int16_T PWM_P9_j3;                   // Expression: int16(nbBbx)
                                          //  Referenced by: '<S364>/PWM'

  int16_T SFunction_P2_b;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S378>/S-Function'

  int16_T SFunction_P3_g;              // Expression: int16(0)
                                          //  Referenced by: '<S378>/S-Function'

  int16_T SFunction_P2_i;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S380>/S-Function'

  int16_T SFunction_P3_n;              // Expression: int16(0)
                                          //  Referenced by: '<S380>/S-Function'

  int16_T ADC_P1;                      // Expression: int16(channel)
                                          //  Referenced by: '<S15>/ADC'

  int16_T ADC_P4;                      // Expression: int16(nbBbx)
                                          //  Referenced by: '<S15>/ADC'

  int16_T ADC_P6;                      // Expression: int16(outputwidth)
                                          //  Referenced by: '<S15>/ADC'

  int16_T ADC_P1_p;                    // Expression: int16(channel)
                                          //  Referenced by: '<S17>/ADC'

  int16_T ADC_P4_i;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S17>/ADC'

  int16_T ADC_P6_e;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S17>/ADC'

  int16_T clk_id_Value;                // Computed Parameter: clk_id_Value
                                          //  Referenced by: '<S19>/clk_id'

  int16_T CLK1_P1;                     // Expression: int16(id)
                                          //  Referenced by: '<S19>/CLK1'

  int16_T clk_id_Value_o;              // Computed Parameter: clk_id_Value_o
                                          //  Referenced by: '<S24>/clk_id'

  int16_T CLK1_P1_c;                   // Expression: int16(id)
                                          //  Referenced by: '<S24>/CLK1'

  int16_T SFunction_P2_il;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S134>/S-Function'

  int16_T SFunction_P3_p;              // Expression: int16(0)
                                          //  Referenced by: '<S134>/S-Function'

  int16_T SFunction_P2_p;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S136>/S-Function'

  int16_T SFunction_P3_m;              // Expression: int16(0)
                                          //  Referenced by: '<S136>/S-Function'

  int16_T SFunction_P2_n;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S138>/S-Function'

  int16_T SFunction_P3_dx;             // Expression: int16(0)
                                          //  Referenced by: '<S138>/S-Function'

  int16_T SFunction_P2_g;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S140>/S-Function'

  int16_T SFunction_P3_nu;             // Expression: int16(0)
                                          //  Referenced by: '<S140>/S-Function'

  int16_T SFunction_P2_nv;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S142>/S-Function'

  int16_T SFunction_P3_nq;             // Expression: int16(0)
                                          //  Referenced by: '<S142>/S-Function'

  int16_T SFunction_P2_i5;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S144>/S-Function'

  int16_T SFunction_P3_a;              // Expression: int16(0)
                                          //  Referenced by: '<S144>/S-Function'

  int16_T ADC_P1_a;                    // Expression: int16(channel)
                                          //  Referenced by: '<S42>/ADC'

  int16_T ADC_P4_e;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S42>/ADC'

  int16_T ADC_P6_j;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S42>/ADC'

  int16_T ADC_P1_e;                    // Expression: int16(channel)
                                          //  Referenced by: '<S44>/ADC'

  int16_T ADC_P4_m;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S44>/ADC'

  int16_T ADC_P6_j0;                   // Expression: int16(outputwidth)
                                          //  Referenced by: '<S44>/ADC'

  int16_T SFunction_P2_d;              // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S61>/S-Function'

  int16_T SFunction_P2_f;              // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S75>/S-Function'

  int16_T SFunction_P2_nvt;            // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S63>/S-Function'

  int16_T SFunction_P3_e;              // Expression: int16(0)
                                          //  Referenced by: '<S63>/S-Function'

  int16_T SFunction_P2_c;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S65>/S-Function'

  int16_T SFunction_P3_an;             // Expression: int16(0)
                                          //  Referenced by: '<S65>/S-Function'

  int16_T SFunction_P2_co;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S67>/S-Function'

  int16_T SFunction_P3_j;              // Expression: int16(0)
                                          //  Referenced by: '<S67>/S-Function'

  int16_T SFunction_P2_j;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S69>/S-Function'

  int16_T SFunction_P3_dh;             // Expression: int16(0)
                                          //  Referenced by: '<S69>/S-Function'

  int16_T SFunction_P2_a;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S71>/S-Function'

  int16_T SFunction_P3_ds;             // Expression: int16(0)
                                          //  Referenced by: '<S71>/S-Function'

  int16_T SFunction_P2_dg;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S250>/S-Function'

  int16_T SFunction_P3_gq;             // Expression: int16(0)
                                          //  Referenced by: '<S250>/S-Function'

  int16_T SFunction_P2_m;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S252>/S-Function'

  int16_T SFunction_P3_ay;             // Expression: int16(0)
                                          //  Referenced by: '<S252>/S-Function'

  int16_T SFunction_P2_nn;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S254>/S-Function'

  int16_T SFunction_P3_p1;             // Expression: int16(0)
                                          //  Referenced by: '<S254>/S-Function'

  int16_T SFunction_P2_k;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S256>/S-Function'

  int16_T SFunction_P3_l;              // Expression: int16(0)
                                          //  Referenced by: '<S256>/S-Function'

  int16_T SFunction_P2_g4;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S258>/S-Function'

  int16_T SFunction_P3_ls;             // Expression: int16(0)
                                          //  Referenced by: '<S258>/S-Function'

  int16_T SFunction_P2_l;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S260>/S-Function'

  int16_T SFunction_P3_o;              // Expression: int16(0)
                                          //  Referenced by: '<S260>/S-Function'

  int16_T ADC_P1_l;                    // Expression: int16(channel)
                                          //  Referenced by: '<S158>/ADC'

  int16_T ADC_P4_p;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S158>/ADC'

  int16_T ADC_P6_a;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S158>/ADC'

  int16_T ADC_P1_ey;                   // Expression: int16(channel)
                                          //  Referenced by: '<S160>/ADC'

  int16_T ADC_P4_o;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S160>/ADC'

  int16_T ADC_P6_n;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S160>/ADC'

  int16_T SFunction_P2_b5;             // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S177>/S-Function'

  int16_T SFunction_P2_ki;             // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S191>/S-Function'

  int16_T SFunction_P2_e;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S179>/S-Function'

  int16_T SFunction_P3_g4;             // Expression: int16(0)
                                          //  Referenced by: '<S179>/S-Function'

  int16_T SFunction_P2_cd;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S181>/S-Function'

  int16_T SFunction_P3_gm;             // Expression: int16(0)
                                          //  Referenced by: '<S181>/S-Function'

  int16_T SFunction_P2_o;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S183>/S-Function'

  int16_T SFunction_P3_ii;             // Expression: int16(0)
                                          //  Referenced by: '<S183>/S-Function'

  int16_T SFunction_P2_gc;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S185>/S-Function'

  int16_T SFunction_P3_iu;             // Expression: int16(0)
                                          //  Referenced by: '<S185>/S-Function'

  int16_T SFunction_P2_e1;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S187>/S-Function'

  int16_T SFunction_P3_dxm;            // Expression: int16(0)
                                          //  Referenced by: '<S187>/S-Function'

  int16_T SFunction_P2_c5;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S366>/S-Function'

  int16_T SFunction_P3_f;              // Expression: int16(0)
                                          //  Referenced by: '<S366>/S-Function'

  int16_T SFunction_P2_pg;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S368>/S-Function'

  int16_T SFunction_P3_ld;             // Expression: int16(0)
                                          //  Referenced by: '<S368>/S-Function'

  int16_T SFunction_P2_h;              // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S370>/S-Function'

  int16_T SFunction_P3_jf;             // Expression: int16(0)
                                          //  Referenced by: '<S370>/S-Function'

  int16_T SFunction_P2_pm;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S372>/S-Function'

  int16_T SFunction_P3_dn;             // Expression: int16(0)
                                          //  Referenced by: '<S372>/S-Function'

  int16_T SFunction_P2_av;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S374>/S-Function'

  int16_T SFunction_P3_h;              // Expression: int16(0)
                                          //  Referenced by: '<S374>/S-Function'

  int16_T SFunction_P2_ae;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S376>/S-Function'

  int16_T SFunction_P3_ns;             // Expression: int16(0)
                                          //  Referenced by: '<S376>/S-Function'

  int16_T ADC_P1_i;                    // Expression: int16(channel)
                                          //  Referenced by: '<S274>/ADC'

  int16_T ADC_P4_or;                   // Expression: int16(nbBbx)
                                          //  Referenced by: '<S274>/ADC'

  int16_T ADC_P6_no;                   // Expression: int16(outputwidth)
                                          //  Referenced by: '<S274>/ADC'

  int16_T ADC_P1_o;                    // Expression: int16(channel)
                                          //  Referenced by: '<S276>/ADC'

  int16_T ADC_P4_g;                    // Expression: int16(nbBbx)
                                          //  Referenced by: '<S276>/ADC'

  int16_T ADC_P6_o;                    // Expression: int16(outputwidth)
                                          //  Referenced by: '<S276>/ADC'

  int16_T SFunction_P2_bj;             // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S293>/S-Function'

  int16_T SFunction_P2_gj;             // Expression: int16(DATA_TYPE)
                                          //  Referenced by: '<S307>/S-Function'

  int16_T SFunction_P2_ke;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S295>/S-Function'

  int16_T SFunction_P3_h3;             // Expression: int16(0)
                                          //  Referenced by: '<S295>/S-Function'

  int16_T SFunction_P2_e2;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S297>/S-Function'

  int16_T SFunction_P3_fo;             // Expression: int16(0)
                                          //  Referenced by: '<S297>/S-Function'

  int16_T SFunction_P2_f4;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S299>/S-Function'

  int16_T SFunction_P3_gr;             // Expression: int16(0)
                                          //  Referenced by: '<S299>/S-Function'

  int16_T SFunction_P2_ms;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S301>/S-Function'

  int16_T SFunction_P3_nh;             // Expression: int16(0)
                                          //  Referenced by: '<S301>/S-Function'

  int16_T SFunction_P2_lm;             // Expression: int16(DATATYPE)
                                          //  Referenced by: '<S303>/S-Function'

  int16_T SFunction_P3_ap;             // Expression: int16(0)
                                          //  Referenced by: '<S303>/S-Function'

  uint16_T SFunction_P1[6];            // Computed Parameter: SFunction_P1
                                          //  Referenced by: '<S378>/S-Function'

  uint16_T SFunction_P5_p;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S378>/S-Function'

  uint16_T SFunction_P8;               // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S378>/S-Function'

  uint16_T SFunction_P11;              // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S378>/S-Function'

  uint16_T SFunction_P14[5];           // Computed Parameter: SFunction_P14
                                          //  Referenced by: '<S378>/S-Function'

  uint16_T SFunction_P1_d[6];          // Computed Parameter: SFunction_P1_d
                                          //  Referenced by: '<S380>/S-Function'

  uint16_T SFunction_P5_l;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S380>/S-Function'

  uint16_T SFunction_P8_n;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S380>/S-Function'

  uint16_T SFunction_P11_c;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S380>/S-Function'

  uint16_T SFunction_P14_g[5];         // Computed Parameter: SFunction_P14_g
                                          //  Referenced by: '<S380>/S-Function'

  uint16_T SFunction_P1_f;             // Expression: uint16(interrupt_pstsclr)
                                          //  Referenced by: '<S22>/S-Function'

  uint16_T SFunction_P4_i;           // Expression: uint16(private_adc_delay_ns)
                                        //  Referenced by: '<S22>/S-Function'

  uint16_T SFunction_P1_i[5];          // Computed Parameter: SFunction_P1_i
                                          //  Referenced by: '<S134>/S-Function'

  uint16_T SFunction_P5_a;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S134>/S-Function'

  uint16_T SFunction_P8_o;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S134>/S-Function'

  uint16_T SFunction_P11_p;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S134>/S-Function'

  uint16_T SFunction_P14_p[5];         // Computed Parameter: SFunction_P14_p
                                          //  Referenced by: '<S134>/S-Function'

  uint16_T SFunction_P1_g[5];          // Computed Parameter: SFunction_P1_g
                                          //  Referenced by: '<S136>/S-Function'

  uint16_T SFunction_P5_g;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S136>/S-Function'

  uint16_T SFunction_P8_p;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S136>/S-Function'

  uint16_T SFunction_P11_e;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S136>/S-Function'

  uint16_T SFunction_P14_f[5];         // Computed Parameter: SFunction_P14_f
                                          //  Referenced by: '<S136>/S-Function'

  uint16_T SFunction_P1_b[9];          // Computed Parameter: SFunction_P1_b
                                          //  Referenced by: '<S138>/S-Function'

  uint16_T SFunction_P5_c;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S138>/S-Function'

  uint16_T SFunction_P8_no;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S138>/S-Function'

  uint16_T SFunction_P11_h;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S138>/S-Function'

  uint16_T SFunction_P14_d[5];         // Computed Parameter: SFunction_P14_d
                                          //  Referenced by: '<S138>/S-Function'

  uint16_T SFunction_P1_n[9];          // Computed Parameter: SFunction_P1_n
                                          //  Referenced by: '<S140>/S-Function'

  uint16_T SFunction_P5_n;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S140>/S-Function'

  uint16_T SFunction_P8_o0;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S140>/S-Function'

  uint16_T SFunction_P11_hk;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S140>/S-Function'

  uint16_T SFunction_P14_a[5];         // Computed Parameter: SFunction_P14_a
                                          //  Referenced by: '<S140>/S-Function'

  uint16_T SFunction_P1_if[4];         // Computed Parameter: SFunction_P1_if
                                          //  Referenced by: '<S142>/S-Function'

  uint16_T SFunction_P5_dq;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S142>/S-Function'

  uint16_T SFunction_P8_d;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S142>/S-Function'

  uint16_T SFunction_P11_i;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S142>/S-Function'

  uint16_T SFunction_P14_pf[5];        // Computed Parameter: SFunction_P14_pf
                                          //  Referenced by: '<S142>/S-Function'

  uint16_T SFunction_P1_h[9];          // Computed Parameter: SFunction_P1_h
                                          //  Referenced by: '<S144>/S-Function'

  uint16_T SFunction_P5_jq;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S144>/S-Function'

  uint16_T SFunction_P8_dh;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S144>/S-Function'

  uint16_T SFunction_P11_n;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S144>/S-Function'

  uint16_T SFunction_P14_j[5];         // Computed Parameter: SFunction_P14_j
                                          //  Referenced by: '<S144>/S-Function'

  uint16_T SFunction_P1_e[5];          // Computed Parameter: SFunction_P1_e
                                          //  Referenced by: '<S61>/S-Function'

  uint16_T SFunction_P9;               // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S61>/S-Function'

  uint16_T SFunction_P11_nf;           // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S61>/S-Function'

  uint16_T SFunction_P14_e;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S61>/S-Function'

  uint16_T SFunction_P15;              // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S61>/S-Function'

  uint16_T SFunction_P1_m[5];          // Computed Parameter: SFunction_P1_m
                                          //  Referenced by: '<S75>/S-Function'

  uint16_T SFunction_P9_a;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S75>/S-Function'

  uint16_T SFunction_P11_ie;           // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S75>/S-Function'

  uint16_T SFunction_P14_m;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S75>/S-Function'

  uint16_T SFunction_P15_g;            // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S75>/S-Function'

  uint16_T SFunction_P1_gq[9];         // Computed Parameter: SFunction_P1_gq
                                          //  Referenced by: '<S63>/S-Function'

  uint16_T SFunction_P5_na;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S63>/S-Function'

  uint16_T SFunction_P8_h;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S63>/S-Function'

  uint16_T SFunction_P11_l;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S63>/S-Function'

  uint16_T SFunction_P14_al[5];        // Computed Parameter: SFunction_P14_al
                                          //  Referenced by: '<S63>/S-Function'

  uint16_T SFunction_P1_j[7];          // Computed Parameter: SFunction_P1_j
                                          //  Referenced by: '<S65>/S-Function'

  uint16_T SFunction_P5_iz;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S65>/S-Function'

  uint16_T SFunction_P8_pc;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S65>/S-Function'

  uint16_T SFunction_P11_o;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S65>/S-Function'

  uint16_T SFunction_P14_pz[5];        // Computed Parameter: SFunction_P14_pz
                                          //  Referenced by: '<S65>/S-Function'

  uint16_T SFunction_P1_ig[7];         // Computed Parameter: SFunction_P1_ig
                                          //  Referenced by: '<S67>/S-Function'

  uint16_T SFunction_P5_h;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S67>/S-Function'

  uint16_T SFunction_P8_f;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S67>/S-Function'

  uint16_T SFunction_P11_a;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S67>/S-Function'

  uint16_T SFunction_P14_em[5];        // Computed Parameter: SFunction_P14_em
                                          //  Referenced by: '<S67>/S-Function'

  uint16_T SFunction_P1_bi[9];         // Computed Parameter: SFunction_P1_bi
                                          //  Referenced by: '<S69>/S-Function'

  uint16_T SFunction_P5_h3;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S69>/S-Function'

  uint16_T SFunction_P8_a;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S69>/S-Function'

  uint16_T SFunction_P11_b;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S69>/S-Function'

  uint16_T SFunction_P14_k[5];         // Computed Parameter: SFunction_P14_k
                                          //  Referenced by: '<S69>/S-Function'

  uint16_T SFunction_P1_k[9];          // Computed Parameter: SFunction_P1_k
                                          //  Referenced by: '<S71>/S-Function'

  uint16_T SFunction_P5_dqc;           // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S71>/S-Function'

  uint16_T SFunction_P8_l;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S71>/S-Function'

  uint16_T SFunction_P11_az;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S71>/S-Function'

  uint16_T SFunction_P14_m3[5];        // Computed Parameter: SFunction_P14_m3
                                          //  Referenced by: '<S71>/S-Function'

  uint16_T SFunction_P1_gv[5];         // Computed Parameter: SFunction_P1_gv
                                          //  Referenced by: '<S250>/S-Function'

  uint16_T SFunction_P5_o;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S250>/S-Function'

  uint16_T SFunction_P8_at;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S250>/S-Function'

  uint16_T SFunction_P11_ox;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S250>/S-Function'

  uint16_T SFunction_P14_gh[5];        // Computed Parameter: SFunction_P14_gh
                                          //  Referenced by: '<S250>/S-Function'

  uint16_T SFunction_P1_b0[5];         // Computed Parameter: SFunction_P1_b0
                                          //  Referenced by: '<S252>/S-Function'

  uint16_T SFunction_P5_ht;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S252>/S-Function'

  uint16_T SFunction_P8_e;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S252>/S-Function'

  uint16_T SFunction_P11_ib;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S252>/S-Function'

  uint16_T SFunction_P14_l[5];         // Computed Parameter: SFunction_P14_l
                                          //  Referenced by: '<S252>/S-Function'

  uint16_T SFunction_P1_c[9];          // Computed Parameter: SFunction_P1_c
                                          //  Referenced by: '<S254>/S-Function'

  uint16_T SFunction_P5_ea;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S254>/S-Function'

  uint16_T SFunction_P8_pp;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S254>/S-Function'

  uint16_T SFunction_P11_ir;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S254>/S-Function'

  uint16_T SFunction_P14_a4[5];        // Computed Parameter: SFunction_P14_a4
                                          //  Referenced by: '<S254>/S-Function'

  uint16_T SFunction_P1_e0[9];         // Computed Parameter: SFunction_P1_e0
                                          //  Referenced by: '<S256>/S-Function'

  uint16_T SFunction_P5_hk;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S256>/S-Function'

  uint16_T SFunction_P8_i;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S256>/S-Function'

  uint16_T SFunction_P11_f;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S256>/S-Function'

  uint16_T SFunction_P14_i[5];         // Computed Parameter: SFunction_P14_i
                                          //  Referenced by: '<S256>/S-Function'

  uint16_T SFunction_P1_p[4];          // Computed Parameter: SFunction_P1_p
                                          //  Referenced by: '<S258>/S-Function'

  uint16_T SFunction_P5_ci;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S258>/S-Function'

  uint16_T SFunction_P8_b;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S258>/S-Function'

  uint16_T SFunction_P11_pi;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S258>/S-Function'

  uint16_T SFunction_P14_n[5];         // Computed Parameter: SFunction_P14_n
                                          //  Referenced by: '<S258>/S-Function'

  uint16_T SFunction_P1_jm[9];         // Computed Parameter: SFunction_P1_jm
                                          //  Referenced by: '<S260>/S-Function'

  uint16_T SFunction_P5_iv;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S260>/S-Function'

  uint16_T SFunction_P8_pr;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S260>/S-Function'

  uint16_T SFunction_P11_c0;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S260>/S-Function'

  uint16_T SFunction_P14_dr[5];        // Computed Parameter: SFunction_P14_dr
                                          //  Referenced by: '<S260>/S-Function'

  uint16_T SFunction_P1_l[5];          // Computed Parameter: SFunction_P1_l
                                          //  Referenced by: '<S177>/S-Function'

  uint16_T SFunction_P9_l;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S177>/S-Function'

  uint16_T SFunction_P11_j;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S177>/S-Function'

  uint16_T SFunction_P14_am;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S177>/S-Function'

  uint16_T SFunction_P15_b;            // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S177>/S-Function'

  uint16_T SFunction_P1_is[5];         // Computed Parameter: SFunction_P1_is
                                          //  Referenced by: '<S191>/S-Function'

  uint16_T SFunction_P9_i;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S191>/S-Function'

  uint16_T SFunction_P11_c4;           // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S191>/S-Function'

  uint16_T SFunction_P14_h;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S191>/S-Function'

  uint16_T SFunction_P15_l;            // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S191>/S-Function'

  uint16_T SFunction_P1_eh[9];         // Computed Parameter: SFunction_P1_eh
                                          //  Referenced by: '<S179>/S-Function'

  uint16_T SFunction_P5_f;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S179>/S-Function'

  uint16_T SFunction_P8_bi;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S179>/S-Function'

  uint16_T SFunction_P11_hg;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S179>/S-Function'

  uint16_T SFunction_P14_hc[5];        // Computed Parameter: SFunction_P14_hc
                                          //  Referenced by: '<S179>/S-Function'

  uint16_T SFunction_P1_l2[7];         // Computed Parameter: SFunction_P1_l2
                                          //  Referenced by: '<S181>/S-Function'

  uint16_T SFunction_P5_d0;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S181>/S-Function'

  uint16_T SFunction_P8_b1;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S181>/S-Function'

  uint16_T SFunction_P11_bh;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S181>/S-Function'

  uint16_T SFunction_P14_dg[5];        // Computed Parameter: SFunction_P14_dg
                                          //  Referenced by: '<S181>/S-Function'

  uint16_T SFunction_P1_ey[7];         // Computed Parameter: SFunction_P1_ey
                                          //  Referenced by: '<S183>/S-Function'

  uint16_T SFunction_P5_m;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S183>/S-Function'

  uint16_T SFunction_P8_ly;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S183>/S-Function'

  uint16_T SFunction_P11_d;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S183>/S-Function'

  uint16_T SFunction_P14_ne[5];        // Computed Parameter: SFunction_P14_ne
                                          //  Referenced by: '<S183>/S-Function'

  uint16_T SFunction_P1_jj[9];         // Computed Parameter: SFunction_P1_jj
                                          //  Referenced by: '<S185>/S-Function'

  uint16_T SFunction_P5_cs;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S185>/S-Function'

  uint16_T SFunction_P8_nb;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S185>/S-Function'

  uint16_T SFunction_P11_l1;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S185>/S-Function'

  uint16_T SFunction_P14_a2[5];        // Computed Parameter: SFunction_P14_a2
                                          //  Referenced by: '<S185>/S-Function'

  uint16_T SFunction_P1_po[9];         // Computed Parameter: SFunction_P1_po
                                          //  Referenced by: '<S187>/S-Function'

  uint16_T SFunction_P5_ei;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S187>/S-Function'

  uint16_T SFunction_P8_lf;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S187>/S-Function'

  uint16_T SFunction_P11_ct;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S187>/S-Function'

  uint16_T SFunction_P14_i4[5];        // Computed Parameter: SFunction_P14_i4
                                          //  Referenced by: '<S187>/S-Function'

  uint16_T SFunction_P1_o[5];          // Computed Parameter: SFunction_P1_o
                                          //  Referenced by: '<S366>/S-Function'

  uint16_T SFunction_P5_it;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S366>/S-Function'

  uint16_T SFunction_P8_ov;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S366>/S-Function'

  uint16_T SFunction_P11_f3;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S366>/S-Function'

  uint16_T SFunction_P14_o[5];         // Computed Parameter: SFunction_P14_o
                                          //  Referenced by: '<S366>/S-Function'

  uint16_T SFunction_P1_c1[5];         // Computed Parameter: SFunction_P1_c1
                                          //  Referenced by: '<S368>/S-Function'

  uint16_T SFunction_P5_b;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S368>/S-Function'

  uint16_T SFunction_P8_fb;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S368>/S-Function'

  uint16_T SFunction_P11_nt;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S368>/S-Function'

  uint16_T SFunction_P14_ps[5];        // Computed Parameter: SFunction_P14_ps
                                          //  Referenced by: '<S368>/S-Function'

  uint16_T SFunction_P1_io[9];         // Computed Parameter: SFunction_P1_io
                                          //  Referenced by: '<S370>/S-Function'

  uint16_T SFunction_P5_ar;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S370>/S-Function'

  uint16_T SFunction_P8_g;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S370>/S-Function'

  uint16_T SFunction_P11_j2;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S370>/S-Function'

  uint16_T SFunction_P14_h5[5];        // Computed Parameter: SFunction_P14_h5
                                          //  Referenced by: '<S370>/S-Function'

  uint16_T SFunction_P1_ji[9];         // Computed Parameter: SFunction_P1_ji
                                          //  Referenced by: '<S372>/S-Function'

  uint16_T SFunction_P5_p2;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S372>/S-Function'

  uint16_T SFunction_P8_k;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S372>/S-Function'

  uint16_T SFunction_P11_fk;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S372>/S-Function'

  uint16_T SFunction_P14_d1[5];        // Computed Parameter: SFunction_P14_d1
                                          //  Referenced by: '<S372>/S-Function'

  uint16_T SFunction_P1_a[4];          // Computed Parameter: SFunction_P1_a
                                          //  Referenced by: '<S374>/S-Function'

  uint16_T SFunction_P5_kz;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S374>/S-Function'

  uint16_T SFunction_P8_c;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S374>/S-Function'

  uint16_T SFunction_P11_fc;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S374>/S-Function'

  uint16_T SFunction_P14_a3[5];        // Computed Parameter: SFunction_P14_a3
                                          //  Referenced by: '<S374>/S-Function'

  uint16_T SFunction_P1_e0r[9];        // Computed Parameter: SFunction_P1_e0r
                                          //  Referenced by: '<S376>/S-Function'

  uint16_T SFunction_P5_jk;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S376>/S-Function'

  uint16_T SFunction_P8_j;             // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S376>/S-Function'

  uint16_T SFunction_P11_e5;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S376>/S-Function'

  uint16_T SFunction_P14_pi[5];        // Computed Parameter: SFunction_P14_pi
                                          //  Referenced by: '<S376>/S-Function'

  uint16_T SFunction_P1_a1[5];         // Computed Parameter: SFunction_P1_a1
                                          //  Referenced by: '<S293>/S-Function'

  uint16_T SFunction_P9_m;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S293>/S-Function'

  uint16_T SFunction_P11_k;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S293>/S-Function'

  uint16_T SFunction_P14_ep;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S293>/S-Function'

  uint16_T SFunction_P15_n;            // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S293>/S-Function'

  uint16_T SFunction_P1_kj[5];         // Computed Parameter: SFunction_P1_kj
                                          //  Referenced by: '<S307>/S-Function'

  uint16_T SFunction_P9_d;             // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S307>/S-Function'

  uint16_T SFunction_P11_oj;           // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S307>/S-Function'

  uint16_T SFunction_P14_c;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S307>/S-Function'

  uint16_T SFunction_P15_nc;           // Expression: uint16(ETH_PORT)
                                          //  Referenced by: '<S307>/S-Function'

  uint16_T SFunction_P1_cn[9];         // Computed Parameter: SFunction_P1_cn
                                          //  Referenced by: '<S295>/S-Function'

  uint16_T SFunction_P5_ps;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S295>/S-Function'

  uint16_T SFunction_P8_a3;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S295>/S-Function'

  uint16_T SFunction_P11_ew;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S295>/S-Function'

  uint16_T SFunction_P14_ld[5];        // Computed Parameter: SFunction_P14_ld
                                          //  Referenced by: '<S295>/S-Function'

  uint16_T SFunction_P1_g3[7];         // Computed Parameter: SFunction_P1_g3
                                          //  Referenced by: '<S297>/S-Function'

  uint16_T SFunction_P5_oh;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S297>/S-Function'

  uint16_T SFunction_P8_d1;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S297>/S-Function'

  uint16_T SFunction_P11_ev;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S297>/S-Function'

  uint16_T SFunction_P14_ak[5];        // Computed Parameter: SFunction_P14_ak
                                          //  Referenced by: '<S297>/S-Function'

  uint16_T SFunction_P1_bm[7];         // Computed Parameter: SFunction_P1_bm
                                          //  Referenced by: '<S299>/S-Function'

  uint16_T SFunction_P5_dk;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S299>/S-Function'

  uint16_T SFunction_P8_pl;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S299>/S-Function'

  uint16_T SFunction_P11_g;            // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S299>/S-Function'

  uint16_T SFunction_P14_gw[5];        // Computed Parameter: SFunction_P14_gw
                                          //  Referenced by: '<S299>/S-Function'

  uint16_T SFunction_P1_gt[9];         // Computed Parameter: SFunction_P1_gt
                                          //  Referenced by: '<S301>/S-Function'

  uint16_T SFunction_P5_pm;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S301>/S-Function'

  uint16_T SFunction_P8_c3;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S301>/S-Function'

  uint16_T SFunction_P11_kd;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S301>/S-Function'

  uint16_T SFunction_P14_hj[5];        // Computed Parameter: SFunction_P14_hj
                                          //  Referenced by: '<S301>/S-Function'

  uint16_T SFunction_P1_k1[9];         // Computed Parameter: SFunction_P1_k1
                                          //  Referenced by: '<S303>/S-Function'

  uint16_T SFunction_P5_lo;            // Expression: uint16(CAN_MB_ID)
                                          //  Referenced by: '<S303>/S-Function'

  uint16_T SFunction_P8_eg;            // Expression: uint16(CAN_ADDRESS)
                                          //  Referenced by: '<S303>/S-Function'

  uint16_T SFunction_P11_jt;           // Expression: uint16(ETH_MB_ID)
                                          //  Referenced by: '<S303>/S-Function'

  uint16_T SFunction_P14_ki[5];        // Computed Parameter: SFunction_P14_ki
                                          //  Referenced by: '<S303>/S-Function'

  boolean_T DO_PWM_P5;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S26>/DO_PWM'

  boolean_T DO_PWM_P5_k;               // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S28>/DO_PWM'

  boolean_T PWM_P10;                   // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S130>/PWM'

  boolean_T PWM_P11;                   // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S130>/PWM'

  boolean_T PWM_P12;                   // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S130>/PWM'

  boolean_T PWM_P10_o;                 // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S132>/PWM'

  boolean_T PWM_P11_f;                 // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S132>/PWM'

  boolean_T PWM_P12_h;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S132>/PWM'

  boolean_T PWM_P10_f;                 // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S246>/PWM'

  boolean_T PWM_P11_g;                 // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S246>/PWM'

  boolean_T PWM_P12_n;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S246>/PWM'

  boolean_T PWM_P10_c;                 // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S248>/PWM'

  boolean_T PWM_P11_p;                 // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S248>/PWM'

  boolean_T PWM_P12_d;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S248>/PWM'

  boolean_T PWM_P10_i;                 // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S362>/PWM'

  boolean_T PWM_P11_m;                 // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S362>/PWM'

  boolean_T PWM_P12_f;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S362>/PWM'

  boolean_T PWM_P10_n;                 // Expression: boolean(dutyrealtime)
                                          //  Referenced by: '<S364>/PWM'

  boolean_T PWM_P11_c;                 // Expression: boolean(phaserealtime)
                                          //  Referenced by: '<S364>/PWM'

  boolean_T PWM_P12_c;                 // Expression: boolean(activaterealtime)
                                          //  Referenced by: '<S364>/PWM'

  boolean_T SFunction_P4_kz;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S378>/S-Function'

  boolean_T SFunction_P9_aa;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S378>/S-Function'

  boolean_T SFunction_P10_i;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S378>/S-Function'

  boolean_T SFunction_P15_h;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S378>/S-Function'

  boolean_T SFunction_P4_a1;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S380>/S-Function'

  boolean_T SFunction_P9_c;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S380>/S-Function'

  boolean_T SFunction_P10_g;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S380>/S-Function'

  boolean_T SFunction_P15_j;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S380>/S-Function'

  boolean_T ADC_P5;                    // Expression: boolean(usehist)
                                          //  Referenced by: '<S15>/ADC'

  boolean_T ADC_P5_d;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S17>/ADC'

  boolean_T CLK1_P3;                   // Expression: boolean(var_freq)
                                          //  Referenced by: '<S19>/CLK1'

  boolean_T CLK1_P3_d;                 // Expression: boolean(var_freq)
                                          //  Referenced by: '<S24>/CLK1'

  boolean_T SFunction_P4_dw;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S134>/S-Function'

  boolean_T SFunction_P9_f;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S134>/S-Function'

  boolean_T SFunction_P10_c;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S134>/S-Function'

  boolean_T SFunction_P15_o;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S134>/S-Function'

  boolean_T SFunction_P4_f;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S136>/S-Function'

  boolean_T SFunction_P9_b;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S136>/S-Function'

  boolean_T SFunction_P10_b;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S136>/S-Function'

  boolean_T SFunction_P15_c;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S136>/S-Function'

  boolean_T SFunction_P4_gg;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S138>/S-Function'

  boolean_T SFunction_P9_e;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S138>/S-Function'

  boolean_T SFunction_P10_k;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S138>/S-Function'

  boolean_T SFunction_P15_bq;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S138>/S-Function'

  boolean_T SFunction_P4_kw;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S140>/S-Function'

  boolean_T SFunction_P9_fp;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S140>/S-Function'

  boolean_T SFunction_P10_iw;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S140>/S-Function'

  boolean_T SFunction_P15_e;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S140>/S-Function'

  boolean_T SFunction_P4_j;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S142>/S-Function'

  boolean_T SFunction_P9_m1;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S142>/S-Function'

  boolean_T SFunction_P10_a;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S142>/S-Function'

  boolean_T SFunction_P15_gb;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S142>/S-Function'

  boolean_T SFunction_P4_e;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S144>/S-Function'

  boolean_T SFunction_P9_en;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S144>/S-Function'

  boolean_T SFunction_P10_bz;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S144>/S-Function'

  boolean_T SFunction_P15_hh;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S144>/S-Function'

  boolean_T ADC_P5_h;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S42>/ADC'

  boolean_T ADC_P5_dg;                 // Expression: boolean(usehist)
                                          //  Referenced by: '<S44>/ADC'

  boolean_T Enable_Value;              // Expression: true()
                                          //  Referenced by: '<S76>/Enable'

  boolean_T SFunction_P8_bk;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S61>/S-Function'

  boolean_T SFunction_P12_ej;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S61>/S-Function'

  boolean_T SFunction_P13_f2;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S61>/S-Function'

  boolean_T SFunction_P16;             // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S61>/S-Function'

  boolean_T SFunction_P8_dn;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S75>/S-Function'

  boolean_T SFunction_P12_ih;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S75>/S-Function'

  boolean_T SFunction_P13_eg;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S75>/S-Function'

  boolean_T SFunction_P16_n;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S75>/S-Function'

  boolean_T SFunction_P4_kf;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S63>/S-Function'

  boolean_T SFunction_P9_lj;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S63>/S-Function'

  boolean_T SFunction_P10_pg;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S63>/S-Function'

  boolean_T SFunction_P15_ej;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S63>/S-Function'

  boolean_T SFunction_P4_o;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S65>/S-Function'

  boolean_T SFunction_P9_is;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S65>/S-Function'

  boolean_T SFunction_P10_a0;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S65>/S-Function'

  boolean_T SFunction_P15_hd;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S65>/S-Function'

  boolean_T SFunction_P4_da;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S67>/S-Function'

  boolean_T SFunction_P9_mr;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S67>/S-Function'

  boolean_T SFunction_P10_i0;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S67>/S-Function'

  boolean_T SFunction_P15_od;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S67>/S-Function'

  boolean_T SFunction_P4_jw;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S69>/S-Function'

  boolean_T SFunction_P9_n;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S69>/S-Function'

  boolean_T SFunction_P10_il;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S69>/S-Function'

  boolean_T SFunction_P15_k;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S69>/S-Function'

  boolean_T SFunction_P4_ff;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S71>/S-Function'

  boolean_T SFunction_P9_nw;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S71>/S-Function'

  boolean_T SFunction_P10_ke;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S71>/S-Function'

  boolean_T SFunction_P15_nl;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S71>/S-Function'

  boolean_T isSqrtUsed_Value;          // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S124>/isSqrtUsed'

  boolean_T SFunction_P4_b;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S250>/S-Function'

  boolean_T SFunction_P9_d5;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S250>/S-Function'

  boolean_T SFunction_P10_kv;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S250>/S-Function'

  boolean_T SFunction_P15_hm;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S250>/S-Function'

  boolean_T SFunction_P4_ik;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S252>/S-Function'

  boolean_T SFunction_P9_ff;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S252>/S-Function'

  boolean_T SFunction_P10_e;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S252>/S-Function'

  boolean_T SFunction_P15_oq;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S252>/S-Function'

  boolean_T SFunction_P4_ep;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S254>/S-Function'

  boolean_T SFunction_P9_la;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S254>/S-Function'

  boolean_T SFunction_P10_ex;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S254>/S-Function'

  boolean_T SFunction_P15_co;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S254>/S-Function'

  boolean_T SFunction_P4_p;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S256>/S-Function'

  boolean_T SFunction_P9_m1a;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S256>/S-Function'

  boolean_T SFunction_P10_bu;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S256>/S-Function'

  boolean_T SFunction_P15_lt;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S256>/S-Function'

  boolean_T SFunction_P4_n;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S258>/S-Function'

  boolean_T SFunction_P9_eg;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S258>/S-Function'

  boolean_T SFunction_P10_b4;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S258>/S-Function'

  boolean_T SFunction_P15_bu;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S258>/S-Function'

  boolean_T SFunction_P4_iy;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S260>/S-Function'

  boolean_T SFunction_P9_c3;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S260>/S-Function'

  boolean_T SFunction_P10_at;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S260>/S-Function'

  boolean_T SFunction_P15_ei;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S260>/S-Function'

  boolean_T ADC_P5_a;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S158>/ADC'

  boolean_T ADC_P5_f;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S160>/ADC'

  boolean_T Enable_Value_m;            // Expression: true()
                                          //  Referenced by: '<S192>/Enable'

  boolean_T SFunction_P8_je;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S177>/S-Function'

  boolean_T SFunction_P12_bz;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S177>/S-Function'

  boolean_T SFunction_P13_ol;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S177>/S-Function'

  boolean_T SFunction_P16_c;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S177>/S-Function'

  boolean_T SFunction_P8_ck;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S191>/S-Function'

  boolean_T SFunction_P12_ip;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S191>/S-Function'

  boolean_T SFunction_P13_ed;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S191>/S-Function'

  boolean_T SFunction_P16_g;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S191>/S-Function'

  boolean_T SFunction_P4_c;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S179>/S-Function'

  boolean_T SFunction_P9_o;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S179>/S-Function'

  boolean_T SFunction_P10_l;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S179>/S-Function'

  boolean_T SFunction_P15_ko;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S179>/S-Function'

  boolean_T SFunction_P4_ex;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S181>/S-Function'

  boolean_T SFunction_P9_ok;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S181>/S-Function'

  boolean_T SFunction_P10_h;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S181>/S-Function'

  boolean_T SFunction_P15_ls;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S181>/S-Function'

  boolean_T SFunction_P4_py;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S183>/S-Function'

  boolean_T SFunction_P9_g;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S183>/S-Function'

  boolean_T SFunction_P10_lt;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S183>/S-Function'

  boolean_T SFunction_P15_o0;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S183>/S-Function'

  boolean_T SFunction_P4_ce;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S185>/S-Function'

  boolean_T SFunction_P9_fx;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S185>/S-Function'

  boolean_T SFunction_P10_j;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S185>/S-Function'

  boolean_T SFunction_P15_lsr;         // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S185>/S-Function'

  boolean_T SFunction_P4_hz;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S187>/S-Function'

  boolean_T SFunction_P9_fn;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S187>/S-Function'

  boolean_T SFunction_P10_n;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S187>/S-Function'

  boolean_T SFunction_P15_m;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S187>/S-Function'

  boolean_T isSqrtUsed_Value_k;        // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S240>/isSqrtUsed'

  boolean_T SFunction_P4_cv;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S366>/S-Function'

  boolean_T SFunction_P9_ar;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S366>/S-Function'

  boolean_T SFunction_P10_m;           // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S366>/S-Function'

  boolean_T SFunction_P15_lj;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S366>/S-Function'

  boolean_T SFunction_P4_ag;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S368>/S-Function'

  boolean_T SFunction_P9_nz;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S368>/S-Function'

  boolean_T SFunction_P10_on;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S368>/S-Function'

  boolean_T SFunction_P15_na;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S368>/S-Function'

  boolean_T SFunction_P4_ju;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S370>/S-Function'

  boolean_T SFunction_P9_i3;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S370>/S-Function'

  boolean_T SFunction_P10_iu;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S370>/S-Function'

  boolean_T SFunction_P15_d;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S370>/S-Function'

  boolean_T SFunction_P4_l;            // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S372>/S-Function'

  boolean_T SFunction_P9_k;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S372>/S-Function'

  boolean_T SFunction_P10_eq;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S372>/S-Function'

  boolean_T SFunction_P15_ci;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S372>/S-Function'

  boolean_T SFunction_P4_om;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S374>/S-Function'

  boolean_T SFunction_P9_mz;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S374>/S-Function'

  boolean_T SFunction_P10_kj;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S374>/S-Function'

  boolean_T SFunction_P15_a;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S374>/S-Function'

  boolean_T SFunction_P4_k5;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S376>/S-Function'

  boolean_T SFunction_P9_ih;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S376>/S-Function'

  boolean_T SFunction_P10_fa;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S376>/S-Function'

  boolean_T SFunction_P15_jx;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S376>/S-Function'

  boolean_T ADC_P5_n;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S274>/ADC'

  boolean_T ADC_P5_o;                  // Expression: boolean(usehist)
                                          //  Referenced by: '<S276>/ADC'

  boolean_T Enable_Value_k;            // Expression: true()
                                          //  Referenced by: '<S308>/Enable'

  boolean_T SFunction_P8_dr;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S293>/S-Function'

  boolean_T SFunction_P12_oo;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S293>/S-Function'

  boolean_T SFunction_P13_ff;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S293>/S-Function'

  boolean_T SFunction_P16_d;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S293>/S-Function'

  boolean_T SFunction_P8_nbo;          // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S307>/S-Function'

  boolean_T SFunction_P12_gm;          // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S307>/S-Function'

  boolean_T SFunction_P13_dm;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S307>/S-Function'

  boolean_T SFunction_P16_gu;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S307>/S-Function'

  boolean_T SFunction_P4_hx;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S295>/S-Function'

  boolean_T SFunction_P9_de;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S295>/S-Function'

  boolean_T SFunction_P10_ee;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S295>/S-Function'

  boolean_T SFunction_P15_ou;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S295>/S-Function'

  boolean_T SFunction_P4_n3;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S297>/S-Function'

  boolean_T SFunction_P9_h;            // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S297>/S-Function'

  boolean_T SFunction_P10_a0l;         // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S297>/S-Function'

  boolean_T SFunction_P15_ks;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S297>/S-Function'

  boolean_T SFunction_P4_gj;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S299>/S-Function'

  boolean_T SFunction_P9_kb;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S299>/S-Function'

  boolean_T SFunction_P10_iux;         // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S299>/S-Function'

  boolean_T SFunction_P15_f;           // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S299>/S-Function'

  boolean_T SFunction_P4_oc;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S301>/S-Function'

  boolean_T SFunction_P9_lt;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S301>/S-Function'

  boolean_T SFunction_P10_lg;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S301>/S-Function'

  boolean_T SFunction_P15_hc;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S301>/S-Function'

  boolean_T SFunction_P4_bg;           // Expression: boolean(CAN_ENABLED)
                                          //  Referenced by: '<S303>/S-Function'

  boolean_T SFunction_P9_kr;           // Expression: boolean(CAN_BIG_ENDIAN)
                                          //  Referenced by: '<S303>/S-Function'

  boolean_T SFunction_P10_m4;          // Expression: boolean(ETH_ENABLED)
                                          //  Referenced by: '<S303>/S-Function'

  boolean_T SFunction_P15_bz;          // Expression: boolean(ETH_BIG_ENDIAN)
                                          //  Referenced by: '<S303>/S-Function'

  boolean_T isSqrtUsed_Value_c;        // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S356>/isSqrtUsed'

  P_EnabledSubsystem_TTypeInver_T EnabledSubsystem_f;// '<S335>/Enabled Subsystem' 
  P_MeasurementUpdate_TTypeInve_T MeasurementUpdate_d;// '<S329>/MeasurementUpdate' 
  P_EnabledSubsystem_TTypeInver_T EnabledSubsystem_l;// '<S219>/Enabled Subsystem' 
  P_MeasurementUpdate_TTypeInve_T MeasurementUpdate_f;// '<S213>/MeasurementUpdate' 
  P_EnabledSubsystem_TTypeInver_T EnabledSubsystem;// '<S103>/Enabled Subsystem' 
  P_MeasurementUpdate_TTypeInve_T MeasurementUpdate;// '<S97>/MeasurementUpdate' 
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
//  Block '<S9>/CBPWM' : Unused code path elimination
//  Block '<S45>/Scope' : Unused code path elimination
//  Block '<S31>/Error Scope' : Unused code path elimination
//  Block '<S31>/Reference Scope' : Unused code path elimination
//  Block '<S52>/Data Type Duplicate' : Unused code path elimination
//  Block '<S52>/Data Type Propagation' : Unused code path elimination
//  Block '<S119>/Data Type Duplicate' : Unused code path elimination
//  Block '<S120>/Data Type Duplicate' : Unused code path elimination
//  Block '<S121>/Conversion' : Unused code path elimination
//  Block '<S121>/Data Type Duplicate' : Unused code path elimination
//  Block '<S122>/Data Type Duplicate' : Unused code path elimination
//  Block '<S80>/Data Type Duplicate' : Unused code path elimination
//  Block '<S81>/Data Type Duplicate' : Unused code path elimination
//  Block '<S82>/Data Type Duplicate' : Unused code path elimination
//  Block '<S83>/Data Type Duplicate' : Unused code path elimination
//  Block '<S85>/Data Type Duplicate' : Unused code path elimination
//  Block '<S86>/Data Type Duplicate' : Unused code path elimination
//  Block '<S87>/Data Type Duplicate' : Unused code path elimination
//  Block '<S88>/Conversion' : Unused code path elimination
//  Block '<S88>/Data Type Duplicate' : Unused code path elimination
//  Block '<S89>/Data Type Duplicate' : Unused code path elimination
//  Block '<S90>/Data Type Duplicate' : Unused code path elimination
//  Block '<S91>/Data Type Duplicate' : Unused code path elimination
//  Block '<S93>/Data Type Duplicate' : Unused code path elimination
//  Block '<S94>/Data Type Duplicate' : Unused code path elimination
//  Block '<S76>/G' : Unused code path elimination
//  Block '<S76>/H' : Unused code path elimination
//  Block '<S76>/N' : Unused code path elimination
//  Block '<S76>/P0' : Unused code path elimination
//  Block '<S76>/Q' : Unused code path elimination
//  Block '<S76>/R' : Unused code path elimination
//  Block '<S117>/CheckSignalProperties' : Unused code path elimination
//  Block '<S118>/CheckSignalProperties' : Unused code path elimination
//  Block '<S32>/Scope' : Unused code path elimination
//  Block '<S32>/Scope1' : Unused code path elimination
//  Block '<S32>/Scope2' : Unused code path elimination
//  Block '<S32>/Scope3' : Unused code path elimination
//  Block '<S9>/Scope1' : Unused code path elimination
//  Block '<S10>/CBPWM' : Unused code path elimination
//  Block '<S161>/Scope' : Unused code path elimination
//  Block '<S147>/Error Scope' : Unused code path elimination
//  Block '<S147>/Reference Scope' : Unused code path elimination
//  Block '<S168>/Data Type Duplicate' : Unused code path elimination
//  Block '<S168>/Data Type Propagation' : Unused code path elimination
//  Block '<S235>/Data Type Duplicate' : Unused code path elimination
//  Block '<S236>/Data Type Duplicate' : Unused code path elimination
//  Block '<S237>/Conversion' : Unused code path elimination
//  Block '<S237>/Data Type Duplicate' : Unused code path elimination
//  Block '<S238>/Data Type Duplicate' : Unused code path elimination
//  Block '<S196>/Data Type Duplicate' : Unused code path elimination
//  Block '<S197>/Data Type Duplicate' : Unused code path elimination
//  Block '<S198>/Data Type Duplicate' : Unused code path elimination
//  Block '<S199>/Data Type Duplicate' : Unused code path elimination
//  Block '<S201>/Data Type Duplicate' : Unused code path elimination
//  Block '<S202>/Data Type Duplicate' : Unused code path elimination
//  Block '<S203>/Data Type Duplicate' : Unused code path elimination
//  Block '<S204>/Conversion' : Unused code path elimination
//  Block '<S204>/Data Type Duplicate' : Unused code path elimination
//  Block '<S205>/Data Type Duplicate' : Unused code path elimination
//  Block '<S206>/Data Type Duplicate' : Unused code path elimination
//  Block '<S207>/Data Type Duplicate' : Unused code path elimination
//  Block '<S209>/Data Type Duplicate' : Unused code path elimination
//  Block '<S210>/Data Type Duplicate' : Unused code path elimination
//  Block '<S192>/G' : Unused code path elimination
//  Block '<S192>/H' : Unused code path elimination
//  Block '<S192>/N' : Unused code path elimination
//  Block '<S192>/P0' : Unused code path elimination
//  Block '<S192>/Q' : Unused code path elimination
//  Block '<S192>/R' : Unused code path elimination
//  Block '<S233>/CheckSignalProperties' : Unused code path elimination
//  Block '<S234>/CheckSignalProperties' : Unused code path elimination
//  Block '<S148>/Scope' : Unused code path elimination
//  Block '<S148>/Scope1' : Unused code path elimination
//  Block '<S148>/Scope2' : Unused code path elimination
//  Block '<S148>/Scope3' : Unused code path elimination
//  Block '<S10>/Scope1' : Unused code path elimination
//  Block '<S11>/CBPWM' : Unused code path elimination
//  Block '<S277>/Scope' : Unused code path elimination
//  Block '<S263>/Error Scope' : Unused code path elimination
//  Block '<S263>/Reference Scope' : Unused code path elimination
//  Block '<S284>/Data Type Duplicate' : Unused code path elimination
//  Block '<S284>/Data Type Propagation' : Unused code path elimination
//  Block '<S351>/Data Type Duplicate' : Unused code path elimination
//  Block '<S352>/Data Type Duplicate' : Unused code path elimination
//  Block '<S353>/Conversion' : Unused code path elimination
//  Block '<S353>/Data Type Duplicate' : Unused code path elimination
//  Block '<S354>/Data Type Duplicate' : Unused code path elimination
//  Block '<S312>/Data Type Duplicate' : Unused code path elimination
//  Block '<S313>/Data Type Duplicate' : Unused code path elimination
//  Block '<S314>/Data Type Duplicate' : Unused code path elimination
//  Block '<S315>/Data Type Duplicate' : Unused code path elimination
//  Block '<S317>/Data Type Duplicate' : Unused code path elimination
//  Block '<S318>/Data Type Duplicate' : Unused code path elimination
//  Block '<S319>/Data Type Duplicate' : Unused code path elimination
//  Block '<S320>/Conversion' : Unused code path elimination
//  Block '<S320>/Data Type Duplicate' : Unused code path elimination
//  Block '<S321>/Data Type Duplicate' : Unused code path elimination
//  Block '<S322>/Data Type Duplicate' : Unused code path elimination
//  Block '<S323>/Data Type Duplicate' : Unused code path elimination
//  Block '<S325>/Data Type Duplicate' : Unused code path elimination
//  Block '<S326>/Data Type Duplicate' : Unused code path elimination
//  Block '<S308>/G' : Unused code path elimination
//  Block '<S308>/H' : Unused code path elimination
//  Block '<S308>/N' : Unused code path elimination
//  Block '<S308>/P0' : Unused code path elimination
//  Block '<S308>/Q' : Unused code path elimination
//  Block '<S308>/R' : Unused code path elimination
//  Block '<S349>/CheckSignalProperties' : Unused code path elimination
//  Block '<S350>/CheckSignalProperties' : Unused code path elimination
//  Block '<S264>/Scope' : Unused code path elimination
//  Block '<S264>/Scope1' : Unused code path elimination
//  Block '<S264>/Scope2' : Unused code path elimination
//  Block '<S264>/Scope3' : Unused code path elimination
//  Block '<S11>/Scope1' : Unused code path elimination
//  Block '<S1>/Scope' : Unused code path elimination
//  Block '<Root>/Memory' : Unused code path elimination
//  Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S63>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S65>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S67>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S71>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S93>/Conversion' : Eliminate redundant data type conversion
//  Block '<S97>/Reshape' : Reshape block reduction
//  Block '<S76>/ReshapeX0' : Reshape block reduction
//  Block '<S76>/Reshapexhat' : Reshape block reduction
//  Block '<S76>/Reshapeyhat' : Reshape block reduction
//  Block '<S33>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S134>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S136>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S138>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S140>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S142>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S144>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S179>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S181>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S183>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S187>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S209>/Conversion' : Eliminate redundant data type conversion
//  Block '<S213>/Reshape' : Reshape block reduction
//  Block '<S192>/ReshapeX0' : Reshape block reduction
//  Block '<S192>/Reshapexhat' : Reshape block reduction
//  Block '<S192>/Reshapeyhat' : Reshape block reduction
//  Block '<S149>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S250>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S252>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S254>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S256>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S258>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S260>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S295>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S297>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S299>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S303>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S325>/Conversion' : Eliminate redundant data type conversion
//  Block '<S329>/Reshape' : Reshape block reduction
//  Block '<S308>/ReshapeX0' : Reshape block reduction
//  Block '<S308>/Reshapexhat' : Reshape block reduction
//  Block '<S308>/Reshapeyhat' : Reshape block reduction
//  Block '<S265>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S366>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S368>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S370>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S372>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S374>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S376>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S378>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S380>/Data Type Conversion' : Eliminate redundant data type conversion


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
//  '<S3>'   : 'TTypeInverter_Imperix/Closed_loop_control/ADC2'
//  '<S4>'   : 'TTypeInverter_Imperix/Closed_loop_control/ADC3'
//  '<S5>'   : 'TTypeInverter_Imperix/Closed_loop_control/CLK'
//  '<S6>'   : 'TTypeInverter_Imperix/Closed_loop_control/Configuration'
//  '<S7>'   : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO'
//  '<S8>'   : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO1'
//  '<S9>'   : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control'
//  '<S10>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control'
//  '<S11>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control'
//  '<S12>'  : 'TTypeInverter_Imperix/Closed_loop_control/Probe7'
//  '<S13>'  : 'TTypeInverter_Imperix/Closed_loop_control/Probe8'
//  '<S14>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC2/sub'
//  '<S15>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC2/sub/generation'
//  '<S16>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC3/sub'
//  '<S17>'  : 'TTypeInverter_Imperix/Closed_loop_control/ADC3/sub/generation'
//  '<S18>'  : 'TTypeInverter_Imperix/Closed_loop_control/CLK/sub'
//  '<S19>'  : 'TTypeInverter_Imperix/Closed_loop_control/CLK/sub/generation'
//  '<S20>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/Sampling clock'
//  '<S21>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/clk0'
//  '<S22>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/Sampling clock/generation'
//  '<S23>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/clk0/sub'
//  '<S24>'  : 'TTypeInverter_Imperix/Closed_loop_control/Configuration/clk0/sub/generation'
//  '<S25>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO/sub'
//  '<S26>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO/sub/generation'
//  '<S27>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO1/sub'
//  '<S28>'  : 'TTypeInverter_Imperix/Closed_loop_control/PWM_DO1/sub/generation'
//  '<S29>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/ADC'
//  '<S30>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/ADC1'
//  '<S31>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers'
//  '<S32>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter'
//  '<S33>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/PWM_CB'
//  '<S34>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/PWM_CB1'
//  '<S35>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe'
//  '<S36>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe1'
//  '<S37>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe10'
//  '<S38>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe11'
//  '<S39>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe2'
//  '<S40>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe9'
//  '<S41>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/ADC/sub'
//  '<S42>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/ADC/sub/generation'
//  '<S43>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/ADC1/sub'
//  '<S44>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/ADC1/sub/generation'
//  '<S45>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller'
//  '<S46>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/MATLAB Function'
//  '<S47>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe1'
//  '<S48>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe2'
//  '<S49>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe3'
//  '<S50>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe4'
//  '<S51>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe7'
//  '<S52>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Saturation Dynamic'
//  '<S53>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Voltage Controller'
//  '<S54>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Impulse Invariant PR - HC15'
//  '<S55>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Impulse Invariant PR - HC21'
//  '<S56>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Impulse Invariant PR - HC5'
//  '<S57>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Impulse Invariant PR - HC7'
//  '<S58>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Tunable parameter'
//  '<S59>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Variable Gain'
//  '<S60>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Tunable parameter/sub'
//  '<S61>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Current Controller/Tunable parameter/sub/generation'
//  '<S62>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe1/sub'
//  '<S63>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe1/sub/generation'
//  '<S64>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe2/sub'
//  '<S65>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe2/sub/generation'
//  '<S66>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe3/sub'
//  '<S67>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe3/sub/generation'
//  '<S68>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe4/sub'
//  '<S69>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe4/sub/generation'
//  '<S70>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe7/sub'
//  '<S71>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Probe7/sub/generation'
//  '<S72>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Voltage Controller/Impulse Invariant PR - Fundamental'
//  '<S73>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Voltage Controller/Tunable parameter'
//  '<S74>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Voltage Controller/Tunable parameter/sub'
//  '<S75>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Controllers/Voltage Controller/Tunable parameter/sub/generation'
//  '<S76>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter'
//  '<S77>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CalculatePL'
//  '<S78>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CalculateYhat'
//  '<S79>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator'
//  '<S80>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionA'
//  '<S81>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionB'
//  '<S82>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionC'
//  '<S83>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionD'
//  '<S84>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionEnable'
//  '<S85>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionG'
//  '<S86>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionH'
//  '<S87>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionN'
//  '<S88>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionP'
//  '<S89>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionP0'
//  '<S90>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionQ'
//  '<S91>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionR'
//  '<S92>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionReset'
//  '<S93>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionX'
//  '<S94>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionX0'
//  '<S95>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/DataTypeConversionu'
//  '<S96>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/MemoryP'
//  '<S97>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/Observer'
//  '<S98>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/ReducedQRN'
//  '<S99>'  : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/Reset'
//  '<S100>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/ScalarExpansionP0'
//  '<S101>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/ScalarExpansionQ'
//  '<S102>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/ScalarExpansionR'
//  '<S103>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/UseCurrentEstimator'
//  '<S104>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkA'
//  '<S105>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkB'
//  '<S106>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkC'
//  '<S107>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkD'
//  '<S108>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkEnable'
//  '<S109>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkG'
//  '<S110>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkH'
//  '<S111>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkN'
//  '<S112>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkP0'
//  '<S113>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkQ'
//  '<S114>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkR'
//  '<S115>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkReset'
//  '<S116>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checkX0'
//  '<S117>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checku'
//  '<S118>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/checky'
//  '<S119>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
//  '<S120>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
//  '<S121>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
//  '<S122>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
//  '<S123>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CalculatePL/Ground'
//  '<S124>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
//  '<S125>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S126>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/Observer/MeasurementUpdate'
//  '<S127>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/ReducedQRN/Ground'
//  '<S128>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Kalman Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
//  '<S129>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/PWM_CB/sub'
//  '<S130>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/PWM_CB/sub/generation'
//  '<S131>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/PWM_CB1/sub'
//  '<S132>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/PWM_CB1/sub/generation'
//  '<S133>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe/sub'
//  '<S134>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe/sub/generation'
//  '<S135>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe1/sub'
//  '<S136>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe1/sub/generation'
//  '<S137>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe10/sub'
//  '<S138>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe10/sub/generation'
//  '<S139>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe11/sub'
//  '<S140>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe11/sub/generation'
//  '<S141>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe2/sub'
//  '<S142>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe2/sub/generation'
//  '<S143>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe9/sub'
//  '<S144>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 1 Control/Probe9/sub/generation'
//  '<S145>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/ADC'
//  '<S146>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/ADC1'
//  '<S147>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers'
//  '<S148>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter'
//  '<S149>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/PWM_CB'
//  '<S150>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/PWM_CB1'
//  '<S151>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe'
//  '<S152>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe1'
//  '<S153>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe10'
//  '<S154>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe11'
//  '<S155>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe2'
//  '<S156>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe9'
//  '<S157>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/ADC/sub'
//  '<S158>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/ADC/sub/generation'
//  '<S159>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/ADC1/sub'
//  '<S160>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/ADC1/sub/generation'
//  '<S161>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller'
//  '<S162>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/MATLAB Function'
//  '<S163>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe1'
//  '<S164>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe2'
//  '<S165>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe3'
//  '<S166>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe4'
//  '<S167>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe7'
//  '<S168>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Saturation Dynamic'
//  '<S169>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Voltage Controller'
//  '<S170>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Impulse Invariant PR - HC15'
//  '<S171>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Impulse Invariant PR - HC21'
//  '<S172>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Impulse Invariant PR - HC5'
//  '<S173>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Impulse Invariant PR - HC7'
//  '<S174>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Tunable parameter'
//  '<S175>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Variable Gain'
//  '<S176>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Tunable parameter/sub'
//  '<S177>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Current Controller/Tunable parameter/sub/generation'
//  '<S178>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe1/sub'
//  '<S179>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe1/sub/generation'
//  '<S180>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe2/sub'
//  '<S181>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe2/sub/generation'
//  '<S182>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe3/sub'
//  '<S183>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe3/sub/generation'
//  '<S184>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe4/sub'
//  '<S185>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe4/sub/generation'
//  '<S186>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe7/sub'
//  '<S187>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Probe7/sub/generation'
//  '<S188>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Voltage Controller/Impulse Invariant PR - Fundamental'
//  '<S189>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Voltage Controller/Tunable parameter'
//  '<S190>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Voltage Controller/Tunable parameter/sub'
//  '<S191>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Controllers/Voltage Controller/Tunable parameter/sub/generation'
//  '<S192>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter'
//  '<S193>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CalculatePL'
//  '<S194>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CalculateYhat'
//  '<S195>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator'
//  '<S196>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionA'
//  '<S197>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionB'
//  '<S198>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionC'
//  '<S199>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionD'
//  '<S200>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionEnable'
//  '<S201>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionG'
//  '<S202>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionH'
//  '<S203>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionN'
//  '<S204>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionP'
//  '<S205>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionP0'
//  '<S206>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionQ'
//  '<S207>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionR'
//  '<S208>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionReset'
//  '<S209>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionX'
//  '<S210>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionX0'
//  '<S211>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/DataTypeConversionu'
//  '<S212>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/MemoryP'
//  '<S213>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/Observer'
//  '<S214>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/ReducedQRN'
//  '<S215>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/Reset'
//  '<S216>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/ScalarExpansionP0'
//  '<S217>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/ScalarExpansionQ'
//  '<S218>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/ScalarExpansionR'
//  '<S219>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/UseCurrentEstimator'
//  '<S220>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkA'
//  '<S221>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkB'
//  '<S222>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkC'
//  '<S223>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkD'
//  '<S224>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkEnable'
//  '<S225>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkG'
//  '<S226>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkH'
//  '<S227>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkN'
//  '<S228>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkP0'
//  '<S229>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkQ'
//  '<S230>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkR'
//  '<S231>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkReset'
//  '<S232>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checkX0'
//  '<S233>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checku'
//  '<S234>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/checky'
//  '<S235>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
//  '<S236>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
//  '<S237>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
//  '<S238>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
//  '<S239>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CalculatePL/Ground'
//  '<S240>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
//  '<S241>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S242>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/Observer/MeasurementUpdate'
//  '<S243>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/ReducedQRN/Ground'
//  '<S244>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Kalman Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
//  '<S245>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/PWM_CB/sub'
//  '<S246>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/PWM_CB/sub/generation'
//  '<S247>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/PWM_CB1/sub'
//  '<S248>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/PWM_CB1/sub/generation'
//  '<S249>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe/sub'
//  '<S250>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe/sub/generation'
//  '<S251>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe1/sub'
//  '<S252>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe1/sub/generation'
//  '<S253>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe10/sub'
//  '<S254>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe10/sub/generation'
//  '<S255>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe11/sub'
//  '<S256>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe11/sub/generation'
//  '<S257>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe2/sub'
//  '<S258>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe2/sub/generation'
//  '<S259>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe9/sub'
//  '<S260>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 2 Control/Probe9/sub/generation'
//  '<S261>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/ADC'
//  '<S262>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/ADC1'
//  '<S263>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers'
//  '<S264>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter'
//  '<S265>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/PWM_CB'
//  '<S266>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/PWM_CB1'
//  '<S267>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe'
//  '<S268>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe1'
//  '<S269>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe10'
//  '<S270>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe11'
//  '<S271>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe2'
//  '<S272>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe9'
//  '<S273>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/ADC/sub'
//  '<S274>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/ADC/sub/generation'
//  '<S275>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/ADC1/sub'
//  '<S276>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/ADC1/sub/generation'
//  '<S277>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller'
//  '<S278>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/MATLAB Function'
//  '<S279>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe1'
//  '<S280>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe2'
//  '<S281>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe3'
//  '<S282>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe4'
//  '<S283>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe7'
//  '<S284>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Saturation Dynamic'
//  '<S285>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Voltage Controller'
//  '<S286>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Impulse Invariant PR - HC15'
//  '<S287>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Impulse Invariant PR - HC21'
//  '<S288>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Impulse Invariant PR - HC5'
//  '<S289>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Impulse Invariant PR - HC7'
//  '<S290>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Tunable parameter'
//  '<S291>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Variable Gain'
//  '<S292>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Tunable parameter/sub'
//  '<S293>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Current Controller/Tunable parameter/sub/generation'
//  '<S294>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe1/sub'
//  '<S295>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe1/sub/generation'
//  '<S296>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe2/sub'
//  '<S297>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe2/sub/generation'
//  '<S298>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe3/sub'
//  '<S299>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe3/sub/generation'
//  '<S300>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe4/sub'
//  '<S301>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe4/sub/generation'
//  '<S302>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe7/sub'
//  '<S303>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Probe7/sub/generation'
//  '<S304>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Voltage Controller/Impulse Invariant PR - Fundamental'
//  '<S305>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Voltage Controller/Tunable parameter'
//  '<S306>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Voltage Controller/Tunable parameter/sub'
//  '<S307>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Controllers/Voltage Controller/Tunable parameter/sub/generation'
//  '<S308>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter'
//  '<S309>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CalculatePL'
//  '<S310>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CalculateYhat'
//  '<S311>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator'
//  '<S312>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionA'
//  '<S313>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionB'
//  '<S314>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionC'
//  '<S315>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionD'
//  '<S316>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionEnable'
//  '<S317>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionG'
//  '<S318>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionH'
//  '<S319>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionN'
//  '<S320>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionP'
//  '<S321>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionP0'
//  '<S322>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionQ'
//  '<S323>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionR'
//  '<S324>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionReset'
//  '<S325>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionX'
//  '<S326>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionX0'
//  '<S327>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/DataTypeConversionu'
//  '<S328>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/MemoryP'
//  '<S329>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/Observer'
//  '<S330>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/ReducedQRN'
//  '<S331>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/Reset'
//  '<S332>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/ScalarExpansionP0'
//  '<S333>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/ScalarExpansionQ'
//  '<S334>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/ScalarExpansionR'
//  '<S335>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/UseCurrentEstimator'
//  '<S336>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkA'
//  '<S337>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkB'
//  '<S338>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkC'
//  '<S339>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkD'
//  '<S340>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkEnable'
//  '<S341>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkG'
//  '<S342>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkH'
//  '<S343>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkN'
//  '<S344>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkP0'
//  '<S345>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkQ'
//  '<S346>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkR'
//  '<S347>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkReset'
//  '<S348>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checkX0'
//  '<S349>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checku'
//  '<S350>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/checky'
//  '<S351>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
//  '<S352>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
//  '<S353>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
//  '<S354>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
//  '<S355>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CalculatePL/Ground'
//  '<S356>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
//  '<S357>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S358>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/Observer/MeasurementUpdate'
//  '<S359>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/ReducedQRN/Ground'
//  '<S360>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Kalman Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
//  '<S361>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/PWM_CB/sub'
//  '<S362>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/PWM_CB/sub/generation'
//  '<S363>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/PWM_CB1/sub'
//  '<S364>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/PWM_CB1/sub/generation'
//  '<S365>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe/sub'
//  '<S366>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe/sub/generation'
//  '<S367>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe1/sub'
//  '<S368>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe1/sub/generation'
//  '<S369>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe10/sub'
//  '<S370>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe10/sub/generation'
//  '<S371>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe11/sub'
//  '<S372>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe11/sub/generation'
//  '<S373>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe2/sub'
//  '<S374>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe2/sub/generation'
//  '<S375>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe9/sub'
//  '<S376>' : 'TTypeInverter_Imperix/Closed_loop_control/Phase 3 Control/Probe9/sub/generation'
//  '<S377>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe7/sub'
//  '<S378>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe7/sub/generation'
//  '<S379>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe8/sub'
//  '<S380>' : 'TTypeInverter_Imperix/Closed_loop_control/Probe8/sub/generation'

#endif                                 // RTW_HEADER_TTypeInverter_Imperix_h_

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
