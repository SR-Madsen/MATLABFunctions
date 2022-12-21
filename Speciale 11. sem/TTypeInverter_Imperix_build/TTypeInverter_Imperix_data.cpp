//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TTypeInverter_Imperix_data.cpp
//
// Code generated for Simulink model 'TTypeInverter_Imperix'.
// To be implemented on the B-Box RCP or the B-Board PRO.
//
// Model version                  : 14.119
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Dec 21 14:14:34 2022
//
#include "TTypeInverter_Imperix.h"

// Block parameters (default storage)
P_TTypeInverter_Imperix_T TTypeInverter_Imperix_P = {
  // Variable: Vout_amp
  //  Referenced by:
  //    '<S31>/Sine Wave'
  //    '<S147>/Sine Wave'
  //    '<S263>/Sine Wave'

  325.26911934581187,

  // Variable: f_o
  //  Referenced by:
  //    '<S31>/Sine Wave'
  //    '<S147>/Sine Wave'
  //    '<S263>/Sine Wave'

  50.0,

  // Variable: Klim
  //  Referenced by:
  //    '<S72>/Klim'
  //    '<S188>/Klim'
  //    '<S304>/Klim'

  5.0F,

  // Variable: R_Lc
  //  Referenced by:
  //    '<S31>/Gain1'
  //    '<S147>/Gain1'
  //    '<S263>/Gain1'

  0.0056F,

  // Variable: pr_sat_val
  //  Referenced by:
  //    '<S53>/Saturation'
  //    '<S169>/Saturation'
  //    '<S285>/Saturation'

  218.0F,

  // Expression: pInitialization.M
  //  Referenced by: '<S77>/KalmanGainM'

  { 0.999341661553191, 0.00043094928634882651, -0.047883861620127609,
    -1.1003743894055663E-5, 0.99243303004061489, 0.84074856297085421 },

  // Expression: 0
  //  Referenced by: '<S31>/Sine Wave'

  0.0,

  // Computed Parameter: SineWave_Hsin
  //  Referenced by: '<S31>/Sine Wave'

  0.0032722771837927307,

  // Computed Parameter: SineWave_HCos
  //  Referenced by: '<S31>/Sine Wave'

  0.999994646086684,

  // Computed Parameter: SineWave_PSin
  //  Referenced by: '<S31>/Sine Wave'

  -0.0032722771837927307,

  // Computed Parameter: SineWave_PCos
  //  Referenced by: '<S31>/Sine Wave'

  0.999994646086684,

  // Expression: 1
  //  Referenced by: '<S9>/Constant2'

  1.0,

  // Expression: pInitialization.Z
  //  Referenced by: '<S77>/CovarianceZ'

  { 0.00065940632202419048, 2.8435788762030271E-7, -3.1595721753628731E-5,
    2.8435788762030266E-7, 0.00027476527563298687, -0.030493317078871363,
    -3.1595721753628737E-5, -0.030493317078871367, 3.38817697366433 },

  // Expression: pInitialization.L
  //  Referenced by: '<S77>/KalmanGainL'

  { 0.99965472441749481, -0.0161941777780293, -0.047882553467110144,
    -0.13204369704812893, 1.2843105206419132, 0.840565559846477 },

  // Expression: PHASE
  //  Referenced by: '<S33>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S33>/enable'

  1.0,

  // Expression: PHASE
  //  Referenced by: '<S34>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S34>/enable'

  1.0,

  // Expression: pInitialization.M
  //  Referenced by: '<S193>/KalmanGainM'

  { 0.999341661553191, 0.00043094928634882651, -0.047883861620127609,
    -1.1003743894055663E-5, 0.99243303004061489, 0.84074856297085421 },

  // Expression: 0
  //  Referenced by: '<S147>/Sine Wave'

  0.0,

  // Computed Parameter: SineWave_Hsin_b
  //  Referenced by: '<S147>/Sine Wave'

  0.0032722771837927307,

  // Computed Parameter: SineWave_HCos_d
  //  Referenced by: '<S147>/Sine Wave'

  0.999994646086684,

  // Computed Parameter: SineWave_PSin_n
  //  Referenced by: '<S147>/Sine Wave'

  0.86765690575139387,

  // Computed Parameter: SineWave_PCos_j
  //  Referenced by: '<S147>/Sine Wave'

  -0.49716344787395311,

  // Expression: 1
  //  Referenced by: '<S10>/Constant2'

  1.0,

  // Expression: pInitialization.Z
  //  Referenced by: '<S193>/CovarianceZ'

  { 0.00065940632202419048, 2.8435788762030271E-7, -3.1595721753628731E-5,
    2.8435788762030266E-7, 0.00027476527563298687, -0.030493317078871363,
    -3.1595721753628737E-5, -0.030493317078871367, 3.38817697366433 },

  // Expression: pInitialization.L
  //  Referenced by: '<S193>/KalmanGainL'

  { 0.99965472441749481, -0.0161941777780293, -0.047882553467110144,
    -0.13204369704812893, 1.2843105206419132, 0.840565559846477 },

  // Expression: PHASE
  //  Referenced by: '<S149>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S149>/enable'

  1.0,

  // Expression: PHASE
  //  Referenced by: '<S150>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S150>/enable'

  1.0,

  // Expression: pInitialization.M
  //  Referenced by: '<S309>/KalmanGainM'

  { 0.999341661553191, 0.00043094928634882651, -0.047883861620127609,
    -1.1003743894055663E-5, 0.99243303004061489, 0.84074856297085421 },

  // Expression: 0
  //  Referenced by: '<S263>/Sine Wave'

  0.0,

  // Computed Parameter: SineWave_Hsin_e
  //  Referenced by: '<S263>/Sine Wave'

  0.0032722771837927307,

  // Computed Parameter: SineWave_HCos_n
  //  Referenced by: '<S263>/Sine Wave'

  0.999994646086684,

  // Computed Parameter: SineWave_PSin_g
  //  Referenced by: '<S263>/Sine Wave'

  -0.86438462856760079,

  // Computed Parameter: SineWave_PCos_a
  //  Referenced by: '<S263>/Sine Wave'

  -0.50283119821273115,

  // Expression: 1
  //  Referenced by: '<S11>/Constant2'

  1.0,

  // Expression: pInitialization.Z
  //  Referenced by: '<S309>/CovarianceZ'

  { 0.00065940632202419048, 2.8435788762030271E-7, -3.1595721753628731E-5,
    2.8435788762030266E-7, 0.00027476527563298687, -0.030493317078871363,
    -3.1595721753628737E-5, -0.030493317078871367, 3.38817697366433 },

  // Expression: pInitialization.L
  //  Referenced by: '<S309>/KalmanGainL'

  { 0.99965472441749481, -0.0161941777780293, -0.047882553467110144,
    -0.13204369704812893, 1.2843105206419132, 0.840565559846477 },

  // Expression: PHASE
  //  Referenced by: '<S265>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S265>/enable'

  1.0,

  // Expression: PHASE
  //  Referenced by: '<S266>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S266>/enable'

  1.0,

  // Expression: 1
  //  Referenced by: '<S1>/Constant3'

  1.0,

  // Expression: 1
  //  Referenced by: '<S7>/activate'

  1.0,

  // Expression: 1
  //  Referenced by: '<S8>/activate'

  1.0,

  // Expression: single(deadtime)
  //  Referenced by: '<S26>/DO_PWM'

  1.0E-6F,

  // Expression: single(deadtime)
  //  Referenced by: '<S28>/DO_PWM'

  1.0E-6F,

  // Expression: single(deadtime)
  //  Referenced by: '<S130>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S130>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S130>/PWM'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S132>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S132>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S132>/PWM'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S246>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S246>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S246>/PWM'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S248>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S248>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S248>/PWM'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S362>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S362>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S362>/PWM'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S364>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S364>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S364>/PWM'

  0.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S378>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S378>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S380>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S380>/S-Function'

  10.0F,

  // Expression: single(gain)
  //  Referenced by: '<S15>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S15>/ADC'

  0.0F,

  // Expression: single(gain)
  //  Referenced by: '<S17>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S17>/ADC'

  0.0F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S19>/Saturation'

  50000.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S19>/Saturation'

  10000.0F,

  // Expression: single(frequency)
  //  Referenced by: '<S19>/CLK1'

  24000.0F,

  // Expression: single(phase_vector)
  //  Referenced by: '<S22>/S-Function'

  0.0F,

  // Expression: single(interrupt_phase)
  //  Referenced by: '<S22>/S-Function'

  0.0F,

  // Expression: single(frequency)
  //  Referenced by: '<S24>/CLK1'

  96006.1406F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S134>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S134>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S136>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S136>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S138>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S138>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S140>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S140>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S142>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S142>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S144>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S144>/S-Function'

  10.0F,

  // Expression: single(gain)
  //  Referenced by: '<S42>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S42>/ADC'

  0.0F,

  // Expression: single(gain)
  //  Referenced by: '<S44>/ADC'

  0.0066763F,

  // Expression: single(offset)
  //  Referenced by: '<S44>/ADC'

  0.0F,

  // Computed Parameter: C_Value
  //  Referenced by: '<S76>/C'

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.009F },

  // Computed Parameter: X0_Value
  //  Referenced by: '<S76>/X0'

  { 0.0F, 0.0F, 0.0F },

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S61>/S-Function'

  2.5F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S61>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S61>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S61>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S61>/S-Function'

  0.0F,

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S75>/S-Function'

  0.9444F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S75>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S75>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S75>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S75>/S-Function'

  0.0F,

  // Computed Parameter: Delay1_InitialCondition
  //  Referenced by: '<S72>/Delay1'

  0.0F,

  // Computed Parameter: a0_Gain
  //  Referenced by: '<S72>/a0'

  12.9185991F,

  // Computed Parameter: Delay3_InitialCondition
  //  Referenced by: '<S72>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain
  //  Referenced by: '<S72>/a1'

  12.9185295F,

  // Computed Parameter: Delay4_InitialCondition
  //  Referenced by: '<S72>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain
  //  Referenced by: '<S72>/b1'

  628.318F,

  // Computed Parameter: Delay5_InitialCondition
  //  Referenced by: '<S72>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain
  //  Referenced by: '<S72>/b2'

  314.15863F,

  // Computed Parameter: ub0_Gain
  //  Referenced by: '<S72>/1//b0'

  0.00318306359F,

  // Computed Parameter: Saturation_LowerSat_a
  //  Referenced by: '<S53>/Saturation'

  -218.0F,

  // Computed Parameter: a0_Gain_j
  //  Referenced by: '<S56>/a0'

  2.06698F,

  // Computed Parameter: Delay3_InitialCondition_c
  //  Referenced by: '<S56>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_o
  //  Referenced by: '<S56>/a1'

  2.06670308F,

  // Computed Parameter: Delay4_InitialCondition_f
  //  Referenced by: '<S56>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_o
  //  Referenced by: '<S56>/b1'

  3141.19238F,

  // Computed Parameter: Delay5_InitialCondition_l
  //  Referenced by: '<S56>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_c
  //  Referenced by: '<S56>/b2'

  1570.79614F,

  // Computed Parameter: ub0_Gain_m
  //  Referenced by: '<S56>/1//b0'

  0.000636611483F,

  // Computed Parameter: a0_Gain_m
  //  Referenced by: '<S57>/a0'

  3.10046983F,

  // Computed Parameter: Delay3_InitialCondition_p
  //  Referenced by: '<S57>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_k
  //  Referenced by: '<S57>/a1'

  3.09965634F,

  // Computed Parameter: Delay4_InitialCondition_m
  //  Referenced by: '<S57>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_i
  //  Referenced by: '<S57>/b1'

  4397.10449F,

  // Computed Parameter: Delay5_InitialCondition_o
  //  Referenced by: '<S57>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_a
  //  Referenced by: '<S57>/b2'

  2199.11475F,

  // Computed Parameter: ub0_Gain_p
  //  Referenced by: '<S57>/1//b0'

  0.000454722467F,

  // Computed Parameter: a0_Gain_b
  //  Referenced by: '<S54>/a0'

  2.46727562F,

  // Computed Parameter: Delay3_InitialCondition_d
  //  Referenced by: '<S54>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_c
  //  Referenced by: '<S54>/a1'

  2.46430397F,

  // Computed Parameter: Delay4_InitialCondition_fy
  //  Referenced by: '<S54>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_p
  //  Referenced by: '<S54>/b1'

  9413.48828F,

  // Computed Parameter: Delay5_InitialCondition_e
  //  Referenced by: '<S54>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_p
  //  Referenced by: '<S54>/b2'

  4712.38916F,

  // Computed Parameter: ub0_Gain_mq
  //  Referenced by: '<S54>/1//b0'

  0.000212203813F,

  // Computed Parameter: a0_Gain_g
  //  Referenced by: '<S55>/a0'

  3.45418572F,

  // Computed Parameter: Delay3_InitialCondition_dr
  //  Referenced by: '<S55>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_op
  //  Referenced by: '<S55>/a1'

  3.44603348F,

  // Computed Parameter: Delay4_InitialCondition_fyn
  //  Referenced by: '<S55>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_l
  //  Referenced by: '<S55>/b1'

  13163.6338F,

  // Computed Parameter: Delay5_InitialCondition_ew
  //  Referenced by: '<S55>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_j
  //  Referenced by: '<S55>/b2'

  6597.34473F,

  // Computed Parameter: ub0_Gain_k
  //  Referenced by: '<S55>/1//b0'

  0.000151574146F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S63>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S63>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S65>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S65>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S67>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S67>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S69>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S69>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S71>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S71>/S-Function'

  10.0F,

  // Computed Parameter: GIDifferentiator_NumCoef
  //  Referenced by: '<S32>/GI Differentiator'

  { 3.81076908F, -2.39778709F, -1.41298211F },

  // Computed Parameter: GIDifferentiator_DenCoef
  //  Referenced by: '<S32>/GI Differentiator'

  { 1.0F, 0.690541804F, 0.123144709F },

  // Computed Parameter: GIDifferentiator_InitialStates
  //  Referenced by: '<S32>/GI Differentiator'

  0.0F,

  // Computed Parameter: A_Value
  //  Referenced by: '<S76>/A'

  { 0.99935478F, -3.36059403E-9F, -1.9356083E-8F, -0.11521478F, 0.999972284F,
    -0.000159694886F, -0.0210404694F, 0.347196549F, 0.999970853F },

  // Computed Parameter: B_Value
  //  Referenced by: '<S76>/B'

  { 0.115215905F, 6.00106091E-7F, 3.45644344E-6F, -6.28799679E-9F,
    1.51889509E-7F, 8.74935324E-7F },

  // Computed Parameter: D_Value
  //  Referenced by: '<S76>/D'

  { 0.0F, 0.0F, 0.0F, 0.0F },

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S250>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S250>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S252>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S252>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S254>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S254>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S256>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S256>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S258>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S258>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S260>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S260>/S-Function'

  10.0F,

  // Expression: single(gain)
  //  Referenced by: '<S158>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S158>/ADC'

  0.0F,

  // Expression: single(gain)
  //  Referenced by: '<S160>/ADC'

  0.0066763F,

  // Expression: single(offset)
  //  Referenced by: '<S160>/ADC'

  0.0F,

  // Computed Parameter: C_Value_j
  //  Referenced by: '<S192>/C'

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.009F },

  // Computed Parameter: X0_Value_f
  //  Referenced by: '<S192>/X0'

  { 0.0F, 0.0F, 0.0F },

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S177>/S-Function'

  2.5F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S177>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S177>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S177>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S177>/S-Function'

  0.0F,

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S191>/S-Function'

  0.9444F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S191>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S191>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S191>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S191>/S-Function'

  0.0F,

  // Computed Parameter: Delay1_InitialCondition_c
  //  Referenced by: '<S188>/Delay1'

  0.0F,

  // Computed Parameter: a0_Gain_a
  //  Referenced by: '<S188>/a0'

  12.9185991F,

  // Computed Parameter: Delay3_InitialCondition_o
  //  Referenced by: '<S188>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_n
  //  Referenced by: '<S188>/a1'

  12.9185295F,

  // Computed Parameter: Delay4_InitialCondition_j
  //  Referenced by: '<S188>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_d
  //  Referenced by: '<S188>/b1'

  628.318F,

  // Computed Parameter: Delay5_InitialCondition_p
  //  Referenced by: '<S188>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_n
  //  Referenced by: '<S188>/b2'

  314.15863F,

  // Computed Parameter: ub0_Gain_c
  //  Referenced by: '<S188>/1//b0'

  0.00318306359F,

  // Computed Parameter: Saturation_LowerSat_b
  //  Referenced by: '<S169>/Saturation'

  -218.0F,

  // Computed Parameter: a0_Gain_o
  //  Referenced by: '<S172>/a0'

  2.06698F,

  // Computed Parameter: Delay3_InitialCondition_dv
  //  Referenced by: '<S172>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_l
  //  Referenced by: '<S172>/a1'

  2.06670308F,

  // Computed Parameter: Delay4_InitialCondition_e
  //  Referenced by: '<S172>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_e
  //  Referenced by: '<S172>/b1'

  3141.19238F,

  // Computed Parameter: Delay5_InitialCondition_k
  //  Referenced by: '<S172>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_i
  //  Referenced by: '<S172>/b2'

  1570.79614F,

  // Computed Parameter: ub0_Gain_ps
  //  Referenced by: '<S172>/1//b0'

  0.000636611483F,

  // Computed Parameter: a0_Gain_mp
  //  Referenced by: '<S173>/a0'

  3.10046983F,

  // Computed Parameter: Delay3_InitialCondition_k
  //  Referenced by: '<S173>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_o3
  //  Referenced by: '<S173>/a1'

  3.09965634F,

  // Computed Parameter: Delay4_InitialCondition_h
  //  Referenced by: '<S173>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_di
  //  Referenced by: '<S173>/b1'

  4397.10449F,

  // Computed Parameter: Delay5_InitialCondition_i
  //  Referenced by: '<S173>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_e
  //  Referenced by: '<S173>/b2'

  2199.11475F,

  // Computed Parameter: ub0_Gain_g
  //  Referenced by: '<S173>/1//b0'

  0.000454722467F,

  // Computed Parameter: a0_Gain_n
  //  Referenced by: '<S170>/a0'

  2.46727562F,

  // Computed Parameter: Delay3_InitialCondition_a
  //  Referenced by: '<S170>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_a
  //  Referenced by: '<S170>/a1'

  2.46430397F,

  // Computed Parameter: Delay4_InitialCondition_g
  //  Referenced by: '<S170>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_h
  //  Referenced by: '<S170>/b1'

  9413.48828F,

  // Computed Parameter: Delay5_InitialCondition_m
  //  Referenced by: '<S170>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_m
  //  Referenced by: '<S170>/b2'

  4712.38916F,

  // Computed Parameter: ub0_Gain_h
  //  Referenced by: '<S170>/1//b0'

  0.000212203813F,

  // Computed Parameter: a0_Gain_f
  //  Referenced by: '<S171>/a0'

  3.45418572F,

  // Computed Parameter: Delay3_InitialCondition_f
  //  Referenced by: '<S171>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_f
  //  Referenced by: '<S171>/a1'

  3.44603348F,

  // Computed Parameter: Delay4_InitialCondition_c
  //  Referenced by: '<S171>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_j
  //  Referenced by: '<S171>/b1'

  13163.6338F,

  // Computed Parameter: Delay5_InitialCondition_ez
  //  Referenced by: '<S171>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_ch
  //  Referenced by: '<S171>/b2'

  6597.34473F,

  // Computed Parameter: ub0_Gain_he
  //  Referenced by: '<S171>/1//b0'

  0.000151574146F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S179>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S179>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S181>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S181>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S183>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S183>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S185>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S185>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S187>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S187>/S-Function'

  10.0F,

  // Computed Parameter: GIDifferentiator_NumCoef_e
  //  Referenced by: '<S148>/GI Differentiator'

  { 3.81076908F, -2.39778709F, -1.41298211F },

  // Computed Parameter: GIDifferentiator_DenCoef_m
  //  Referenced by: '<S148>/GI Differentiator'

  { 1.0F, 0.690541804F, 0.123144709F },

  // Computed Parameter: GIDifferentiator_InitialState_o
  //  Referenced by: '<S148>/GI Differentiator'

  0.0F,

  // Computed Parameter: A_Value_k
  //  Referenced by: '<S192>/A'

  { 0.99935478F, -3.36059403E-9F, -1.9356083E-8F, -0.11521478F, 0.999972284F,
    -0.000159694886F, -0.0210404694F, 0.347196549F, 0.999970853F },

  // Computed Parameter: B_Value_f
  //  Referenced by: '<S192>/B'

  { 0.115215905F, 6.00106091E-7F, 3.45644344E-6F, -6.28799679E-9F,
    1.51889509E-7F, 8.74935324E-7F },

  // Computed Parameter: D_Value_g
  //  Referenced by: '<S192>/D'

  { 0.0F, 0.0F, 0.0F, 0.0F },

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S366>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S366>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S368>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S368>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S370>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S370>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S372>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S372>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S374>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S374>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S376>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S376>/S-Function'

  10.0F,

  // Expression: single(gain)
  //  Referenced by: '<S274>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S274>/ADC'

  0.0F,

  // Expression: single(gain)
  //  Referenced by: '<S276>/ADC'

  0.0066763F,

  // Expression: single(offset)
  //  Referenced by: '<S276>/ADC'

  0.0F,

  // Computed Parameter: C_Value_c
  //  Referenced by: '<S308>/C'

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.009F },

  // Computed Parameter: X0_Value_i
  //  Referenced by: '<S308>/X0'

  { 0.0F, 0.0F, 0.0F },

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S293>/S-Function'

  2.5F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S293>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S293>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S293>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S293>/S-Function'

  0.0F,

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S307>/S-Function'

  0.9444F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S307>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S307>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S307>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S307>/S-Function'

  0.0F,

  // Computed Parameter: Delay1_InitialCondition_a
  //  Referenced by: '<S304>/Delay1'

  0.0F,

  // Computed Parameter: a0_Gain_e
  //  Referenced by: '<S304>/a0'

  12.9185991F,

  // Computed Parameter: Delay3_InitialCondition_ct
  //  Referenced by: '<S304>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_kb
  //  Referenced by: '<S304>/a1'

  12.9185295F,

  // Computed Parameter: Delay4_InitialCondition_d
  //  Referenced by: '<S304>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_j5
  //  Referenced by: '<S304>/b1'

  628.318F,

  // Computed Parameter: Delay5_InitialCondition_em
  //  Referenced by: '<S304>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_l
  //  Referenced by: '<S304>/b2'

  314.15863F,

  // Computed Parameter: ub0_Gain_i
  //  Referenced by: '<S304>/1//b0'

  0.00318306359F,

  // Computed Parameter: Saturation_LowerSat_k
  //  Referenced by: '<S285>/Saturation'

  -218.0F,

  // Computed Parameter: a0_Gain_nt
  //  Referenced by: '<S288>/a0'

  2.06698F,

  // Computed Parameter: Delay3_InitialCondition_om
  //  Referenced by: '<S288>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_ap
  //  Referenced by: '<S288>/a1'

  2.06670308F,

  // Computed Parameter: Delay4_InitialCondition_d1
  //  Referenced by: '<S288>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_ep
  //  Referenced by: '<S288>/b1'

  3141.19238F,

  // Computed Parameter: Delay5_InitialCondition_c
  //  Referenced by: '<S288>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_f
  //  Referenced by: '<S288>/b2'

  1570.79614F,

  // Computed Parameter: ub0_Gain_e
  //  Referenced by: '<S288>/1//b0'

  0.000636611483F,

  // Computed Parameter: a0_Gain_f0
  //  Referenced by: '<S289>/a0'

  3.10046983F,

  // Computed Parameter: Delay3_InitialCondition_ke
  //  Referenced by: '<S289>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_h
  //  Referenced by: '<S289>/a1'

  3.09965634F,

  // Computed Parameter: Delay4_InitialCondition_jc
  //  Referenced by: '<S289>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_oj
  //  Referenced by: '<S289>/b1'

  4397.10449F,

  // Computed Parameter: Delay5_InitialCondition_p0
  //  Referenced by: '<S289>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_o
  //  Referenced by: '<S289>/b2'

  2199.11475F,

  // Computed Parameter: ub0_Gain_g5
  //  Referenced by: '<S289>/1//b0'

  0.000454722467F,

  // Computed Parameter: a0_Gain_p
  //  Referenced by: '<S286>/a0'

  2.46727562F,

  // Computed Parameter: Delay3_InitialCondition_py
  //  Referenced by: '<S286>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_e
  //  Referenced by: '<S286>/a1'

  2.46430397F,

  // Computed Parameter: Delay4_InitialCondition_a
  //  Referenced by: '<S286>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_ih
  //  Referenced by: '<S286>/b1'

  9413.48828F,

  // Computed Parameter: Delay5_InitialCondition_id
  //  Referenced by: '<S286>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_mf
  //  Referenced by: '<S286>/b2'

  4712.38916F,

  // Computed Parameter: ub0_Gain_h1
  //  Referenced by: '<S286>/1//b0'

  0.000212203813F,

  // Computed Parameter: a0_Gain_l
  //  Referenced by: '<S287>/a0'

  3.45418572F,

  // Computed Parameter: Delay3_InitialCondition_i
  //  Referenced by: '<S287>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_m
  //  Referenced by: '<S287>/a1'

  3.44603348F,

  // Computed Parameter: Delay4_InitialCondition_hn
  //  Referenced by: '<S287>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_ot
  //  Referenced by: '<S287>/b1'

  13163.6338F,

  // Computed Parameter: Delay5_InitialCondition_i1
  //  Referenced by: '<S287>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_d
  //  Referenced by: '<S287>/b2'

  6597.34473F,

  // Computed Parameter: ub0_Gain_kl
  //  Referenced by: '<S287>/1//b0'

  0.000151574146F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S295>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S295>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S297>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S297>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S299>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S299>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S301>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S301>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S303>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S303>/S-Function'

  10.0F,

  // Computed Parameter: GIDifferentiator_NumCoef_m
  //  Referenced by: '<S264>/GI Differentiator'

  { 3.81076908F, -2.39778709F, -1.41298211F },

  // Computed Parameter: GIDifferentiator_DenCoef_ms
  //  Referenced by: '<S264>/GI Differentiator'

  { 1.0F, 0.690541804F, 0.123144709F },

  // Computed Parameter: GIDifferentiator_InitialState_e
  //  Referenced by: '<S264>/GI Differentiator'

  0.0F,

  // Computed Parameter: A_Value_f
  //  Referenced by: '<S308>/A'

  { 0.99935478F, -3.36059403E-9F, -1.9356083E-8F, -0.11521478F, 0.999972284F,
    -0.000159694886F, -0.0210404694F, 0.347196549F, 0.999970853F },

  // Computed Parameter: B_Value_d
  //  Referenced by: '<S308>/B'

  { 0.115215905F, 6.00106091E-7F, 3.45644344E-6F, -6.28799679E-9F,
    1.51889509E-7F, 8.74935324E-7F },

  // Computed Parameter: D_Value_i
  //  Referenced by: '<S308>/D'

  { 0.0F, 0.0F, 0.0F, 0.0F },

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S378>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S378>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S380>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S380>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S134>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S134>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S136>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S136>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S138>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S138>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S140>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S140>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S142>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S142>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S144>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S144>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S61>/S-Function'

  1000000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S75>/S-Function'

  1000000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S63>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S63>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S65>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S65>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S67>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S67>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S69>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S69>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S71>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S71>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S250>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S250>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S252>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S252>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S254>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S254>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S256>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S256>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S258>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S258>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S260>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S260>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S177>/S-Function'

  1000000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S191>/S-Function'

  1000000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S179>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S179>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S181>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S181>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S183>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S183>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S185>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S185>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S187>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S187>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S366>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S366>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S368>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S368>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S370>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S370>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S372>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S372>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S374>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S374>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S376>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S376>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S293>/S-Function'

  1000000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S307>/S-Function'

  1000000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S295>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S295>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S297>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S297>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S299>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S299>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S301>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S301>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S303>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S303>/S-Function'

  2000U,

  // Expression: int16(lane)
  //  Referenced by: '<S26>/DO_PWM'

  12,

  // Expression: int16(outconf)
  //  Referenced by: '<S26>/DO_PWM'

  1,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S26>/DO_PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S28>/DO_PWM'

  13,

  // Expression: int16(outconf)
  //  Referenced by: '<S28>/DO_PWM'

  1,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S28>/DO_PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S130>/PWM'

  0,

  // Expression: int16(carrier)
  //  Referenced by: '<S130>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S130>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S130>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S130>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S130>/PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S132>/PWM'

  2,

  // Expression: int16(carrier)
  //  Referenced by: '<S132>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S132>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S132>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S132>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S132>/PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S246>/PWM'

  4,

  // Expression: int16(carrier)
  //  Referenced by: '<S246>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S246>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S246>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S246>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S246>/PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S248>/PWM'

  6,

  // Expression: int16(carrier)
  //  Referenced by: '<S248>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S248>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S248>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S248>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S248>/PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S362>/PWM'

  8,

  // Expression: int16(carrier)
  //  Referenced by: '<S362>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S362>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S362>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S362>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S362>/PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S364>/PWM'

  10,

  // Expression: int16(carrier)
  //  Referenced by: '<S364>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S364>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S364>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S364>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S364>/PWM'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S378>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S378>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S380>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S380>/S-Function'

  0,

  // Expression: int16(channel)
  //  Referenced by: '<S15>/ADC'

  3,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S15>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S15>/ADC'

  1,

  // Expression: int16(channel)
  //  Referenced by: '<S17>/ADC'

  4,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S17>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S17>/ADC'

  1,

  // Computed Parameter: clk_id_Value
  //  Referenced by: '<S19>/clk_id'

  1,

  // Expression: int16(id)
  //  Referenced by: '<S19>/CLK1'

  1,

  // Computed Parameter: clk_id_Value_o
  //  Referenced by: '<S24>/clk_id'

  0,

  // Expression: int16(id)
  //  Referenced by: '<S24>/CLK1'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S134>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S134>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S136>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S136>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S138>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S138>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S140>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S140>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S142>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S142>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S144>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S144>/S-Function'

  0,

  // Expression: int16(channel)
  //  Referenced by: '<S42>/ADC'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S42>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S42>/ADC'

  1,

  // Expression: int16(channel)
  //  Referenced by: '<S44>/ADC'

  5,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S44>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S44>/ADC'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S61>/S-Function'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S75>/S-Function'

  1,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S63>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S63>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S65>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S65>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S67>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S67>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S69>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S69>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S71>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S71>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S250>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S250>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S252>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S252>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S254>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S254>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S256>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S256>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S258>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S258>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S260>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S260>/S-Function'

  0,

  // Expression: int16(channel)
  //  Referenced by: '<S158>/ADC'

  1,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S158>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S158>/ADC'

  1,

  // Expression: int16(channel)
  //  Referenced by: '<S160>/ADC'

  6,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S160>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S160>/ADC'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S177>/S-Function'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S191>/S-Function'

  1,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S179>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S179>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S181>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S181>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S183>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S183>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S185>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S185>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S187>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S187>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S366>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S366>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S368>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S368>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S370>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S370>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S372>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S372>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S374>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S374>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S376>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S376>/S-Function'

  0,

  // Expression: int16(channel)
  //  Referenced by: '<S274>/ADC'

  2,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S274>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S274>/ADC'

  1,

  // Expression: int16(channel)
  //  Referenced by: '<S276>/ADC'

  7,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S276>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S276>/ADC'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S293>/S-Function'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S307>/S-Function'

  1,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S295>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S295>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S297>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S297>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S299>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S299>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S301>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S301>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S303>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S303>/S-Function'

  0,

  // Computed Parameter: SFunction_P1
  //  Referenced by: '<S378>/S-Function'

  { 66U, 97U, 116U, 116U, 95U, 80U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S378>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S378>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S378>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14
  //  Referenced by: '<S378>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_d
  //  Referenced by: '<S380>/S-Function'

  { 66U, 97U, 116U, 116U, 95U, 78U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S380>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S380>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S380>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_g
  //  Referenced by: '<S380>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Expression: uint16(interrupt_pstsclr)
  //  Referenced by: '<S22>/S-Function'

  0U,

  // Expression: uint16(private_adc_delay_ns)
  //  Referenced by: '<S22>/S-Function'

  500U,

  // Computed Parameter: SFunction_P1_i
  //  Referenced by: '<S134>/S-Function'

  { 105U, 76U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S134>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S134>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S134>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_p
  //  Referenced by: '<S134>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_g
  //  Referenced by: '<S136>/S-Function'

  { 118U, 99U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S136>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S136>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S136>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_f
  //  Referenced by: '<S136>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_b
  //  Referenced by: '<S138>/S-Function'

  { 105U, 111U, 95U, 104U, 97U, 116U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S138>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S138>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S138>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_d
  //  Referenced by: '<S138>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_n
  //  Referenced by: '<S140>/S-Function'

  { 118U, 99U, 95U, 104U, 97U, 116U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S140>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S140>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S140>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_a
  //  Referenced by: '<S140>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_if
  //  Referenced by: '<S142>/S-Function'

  { 109U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S142>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S142>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S142>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_pf
  //  Referenced by: '<S142>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_h
  //  Referenced by: '<S144>/S-Function'

  { 105U, 76U, 95U, 104U, 97U, 116U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S144>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S144>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S144>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_j
  //  Referenced by: '<S144>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_e
  //  Referenced by: '<S61>/S-Function'

  { 75U, 99U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S61>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S61>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S61>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S61>/S-Function'

  2000U,

  // Computed Parameter: SFunction_P1_m
  //  Referenced by: '<S75>/S-Function'

  { 75U, 112U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S75>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S75>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S75>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S75>/S-Function'

  2000U,

  // Computed Parameter: SFunction_P1_gq
  //  Referenced by: '<S63>/S-Function'

  { 105U, 76U, 95U, 114U, 101U, 102U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S63>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S63>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S63>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_al
  //  Referenced by: '<S63>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_j
  //  Referenced by: '<S65>/S-Function'

  { 101U, 95U, 105U, 76U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S65>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S65>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S65>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_pz
  //  Referenced by: '<S65>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_ig
  //  Referenced by: '<S67>/S-Function'

  { 101U, 95U, 118U, 99U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S67>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S67>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S67>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_em
  //  Referenced by: '<S67>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_bi
  //  Referenced by: '<S69>/S-Function'

  { 118U, 99U, 95U, 114U, 101U, 102U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S69>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S69>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S69>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_k
  //  Referenced by: '<S69>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_k
  //  Referenced by: '<S71>/S-Function'

  { 118U, 105U, 95U, 114U, 101U, 102U, 95U, 108U, 49U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S71>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S71>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S71>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_m3
  //  Referenced by: '<S71>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_gv
  //  Referenced by: '<S250>/S-Function'

  { 105U, 76U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S250>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S250>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S250>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_gh
  //  Referenced by: '<S250>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_b0
  //  Referenced by: '<S252>/S-Function'

  { 118U, 99U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S252>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S252>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S252>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_l
  //  Referenced by: '<S252>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_c
  //  Referenced by: '<S254>/S-Function'

  { 105U, 111U, 95U, 104U, 97U, 116U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S254>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S254>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S254>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_a4
  //  Referenced by: '<S254>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_e0
  //  Referenced by: '<S256>/S-Function'

  { 118U, 99U, 95U, 104U, 97U, 116U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S256>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S256>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S256>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_i
  //  Referenced by: '<S256>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_p
  //  Referenced by: '<S258>/S-Function'

  { 109U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S258>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S258>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S258>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_n
  //  Referenced by: '<S258>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_jm
  //  Referenced by: '<S260>/S-Function'

  { 105U, 76U, 95U, 104U, 97U, 116U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S260>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S260>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S260>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_dr
  //  Referenced by: '<S260>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_l
  //  Referenced by: '<S177>/S-Function'

  { 75U, 99U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S177>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S177>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S177>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S177>/S-Function'

  2000U,

  // Computed Parameter: SFunction_P1_is
  //  Referenced by: '<S191>/S-Function'

  { 75U, 112U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S191>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S191>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S191>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S191>/S-Function'

  2000U,

  // Computed Parameter: SFunction_P1_eh
  //  Referenced by: '<S179>/S-Function'

  { 105U, 76U, 95U, 114U, 101U, 102U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S179>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S179>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S179>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_hc
  //  Referenced by: '<S179>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_l2
  //  Referenced by: '<S181>/S-Function'

  { 101U, 95U, 105U, 76U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S181>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S181>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S181>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_dg
  //  Referenced by: '<S181>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_ey
  //  Referenced by: '<S183>/S-Function'

  { 101U, 95U, 118U, 99U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S183>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S183>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S183>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_ne
  //  Referenced by: '<S183>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_jj
  //  Referenced by: '<S185>/S-Function'

  { 118U, 99U, 95U, 114U, 101U, 102U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S185>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S185>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S185>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_a2
  //  Referenced by: '<S185>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_po
  //  Referenced by: '<S187>/S-Function'

  { 118U, 105U, 95U, 114U, 101U, 102U, 95U, 108U, 50U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S187>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S187>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S187>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_i4
  //  Referenced by: '<S187>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_o
  //  Referenced by: '<S366>/S-Function'

  { 105U, 76U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S366>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S366>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S366>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_o
  //  Referenced by: '<S366>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_c1
  //  Referenced by: '<S368>/S-Function'

  { 118U, 99U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S368>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S368>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S368>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_ps
  //  Referenced by: '<S368>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_io
  //  Referenced by: '<S370>/S-Function'

  { 105U, 111U, 95U, 104U, 97U, 116U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S370>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S370>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S370>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_h5
  //  Referenced by: '<S370>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_ji
  //  Referenced by: '<S372>/S-Function'

  { 118U, 99U, 95U, 104U, 97U, 116U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S372>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S372>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S372>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_d1
  //  Referenced by: '<S372>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_a
  //  Referenced by: '<S374>/S-Function'

  { 109U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S374>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S374>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S374>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_a3
  //  Referenced by: '<S374>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_e0r
  //  Referenced by: '<S376>/S-Function'

  { 105U, 76U, 95U, 104U, 97U, 116U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S376>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S376>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S376>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_pi
  //  Referenced by: '<S376>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_a1
  //  Referenced by: '<S293>/S-Function'

  { 75U, 99U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S293>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S293>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S293>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S293>/S-Function'

  2000U,

  // Computed Parameter: SFunction_P1_kj
  //  Referenced by: '<S307>/S-Function'

  { 75U, 112U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S307>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S307>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S307>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S307>/S-Function'

  2000U,

  // Computed Parameter: SFunction_P1_cn
  //  Referenced by: '<S295>/S-Function'

  { 105U, 76U, 95U, 114U, 101U, 102U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S295>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S295>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S295>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_ld
  //  Referenced by: '<S295>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_g3
  //  Referenced by: '<S297>/S-Function'

  { 101U, 95U, 105U, 76U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S297>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S297>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S297>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_ak
  //  Referenced by: '<S297>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_bm
  //  Referenced by: '<S299>/S-Function'

  { 101U, 95U, 118U, 99U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S299>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S299>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S299>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_gw
  //  Referenced by: '<S299>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_gt
  //  Referenced by: '<S301>/S-Function'

  { 118U, 99U, 95U, 114U, 101U, 102U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S301>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S301>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S301>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_hj
  //  Referenced by: '<S301>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_k1
  //  Referenced by: '<S303>/S-Function'

  { 118U, 105U, 95U, 114U, 101U, 102U, 95U, 108U, 51U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S303>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S303>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S303>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_ki
  //  Referenced by: '<S303>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S26>/DO_PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S28>/DO_PWM'

  false,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S130>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S130>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S130>/PWM'

  false,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S132>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S132>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S132>/PWM'

  false,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S246>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S246>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S246>/PWM'

  false,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S248>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S248>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S248>/PWM'

  false,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S362>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S362>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S362>/PWM'

  false,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S364>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S364>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S364>/PWM'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S378>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S378>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S378>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S378>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S380>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S380>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S380>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S380>/S-Function'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S15>/ADC'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S17>/ADC'

  false,

  // Expression: boolean(var_freq)
  //  Referenced by: '<S19>/CLK1'

  false,

  // Expression: boolean(var_freq)
  //  Referenced by: '<S24>/CLK1'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S134>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S134>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S134>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S134>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S136>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S136>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S136>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S136>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S138>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S138>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S138>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S138>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S140>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S140>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S140>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S140>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S142>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S142>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S142>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S142>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S144>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S144>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S144>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S144>/S-Function'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S42>/ADC'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S44>/ADC'

  false,

  // Expression: true()
  //  Referenced by: '<S76>/Enable'

  true,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S61>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S61>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S61>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S61>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S75>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S75>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S75>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S75>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S63>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S63>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S63>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S63>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S65>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S65>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S65>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S65>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S67>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S67>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S67>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S67>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S69>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S69>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S69>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S69>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S71>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S71>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S71>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S71>/S-Function'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S124>/isSqrtUsed'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S250>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S250>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S250>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S250>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S252>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S252>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S252>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S252>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S254>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S254>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S254>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S254>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S256>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S256>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S256>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S256>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S258>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S258>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S258>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S258>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S260>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S260>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S260>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S260>/S-Function'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S158>/ADC'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S160>/ADC'

  false,

  // Expression: true()
  //  Referenced by: '<S192>/Enable'

  true,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S177>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S177>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S177>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S177>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S191>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S191>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S191>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S191>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S179>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S179>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S179>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S179>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S181>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S181>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S181>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S181>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S183>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S183>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S183>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S183>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S185>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S185>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S185>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S185>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S187>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S187>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S187>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S187>/S-Function'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S240>/isSqrtUsed'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S366>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S366>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S366>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S366>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S368>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S368>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S368>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S368>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S370>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S370>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S370>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S370>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S372>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S372>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S372>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S372>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S374>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S374>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S374>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S374>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S376>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S376>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S376>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S376>/S-Function'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S274>/ADC'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S276>/ADC'

  false,

  // Expression: true()
  //  Referenced by: '<S308>/Enable'

  true,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S293>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S293>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S293>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S293>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S307>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S307>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S307>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S307>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S295>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S295>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S295>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S295>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S297>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S297>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S297>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S297>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S299>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S299>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S299>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S299>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S301>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S301>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S301>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S301>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S303>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S303>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S303>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S303>/S-Function'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S356>/isSqrtUsed'

  false,

  // Start of '<S335>/Enabled Subsystem'
  {
    // Computed Parameter: deltax_Y0
    //  Referenced by: '<S360>/deltax'

    0.0F
  }
  ,

  // End of '<S335>/Enabled Subsystem'

  // Start of '<S329>/MeasurementUpdate'
  {
    // Computed Parameter: Lykyhatkk1_Y0
    //  Referenced by: '<S358>/L*(y[k]-yhat[k|k-1])'

    0.0F
  }
  ,

  // End of '<S329>/MeasurementUpdate'

  // Start of '<S219>/Enabled Subsystem'
  {
    // Computed Parameter: deltax_Y0
    //  Referenced by: '<S244>/deltax'

    0.0F
  }
  ,

  // End of '<S219>/Enabled Subsystem'

  // Start of '<S213>/MeasurementUpdate'
  {
    // Computed Parameter: Lykyhatkk1_Y0
    //  Referenced by: '<S242>/L*(y[k]-yhat[k|k-1])'

    0.0F
  }
  ,

  // End of '<S213>/MeasurementUpdate'

  // Start of '<S103>/Enabled Subsystem'
  {
    // Computed Parameter: deltax_Y0
    //  Referenced by: '<S128>/deltax'

    0.0F
  }
  ,

  // End of '<S103>/Enabled Subsystem'

  // Start of '<S97>/MeasurementUpdate'
  {
    // Computed Parameter: Lykyhatkk1_Y0
    //  Referenced by: '<S126>/L*(y[k]-yhat[k|k-1])'

    0.0F
  }
  // End of '<S97>/MeasurementUpdate'
};

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
