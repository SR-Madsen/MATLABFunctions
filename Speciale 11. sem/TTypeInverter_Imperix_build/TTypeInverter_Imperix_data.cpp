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
// Model version                  : 14.80
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Dec 15 11:55:42 2022
//
#include "TTypeInverter_Imperix.h"

// Block parameters (default storage)
P_TTypeInverter_Imperix_T TTypeInverter_Imperix_P = {
  // Variable: Vout_amp
  //  Referenced by: '<S9>/Sine Wave'

  325.26911934581187,

  // Variable: f_o
  //  Referenced by: '<S9>/Sine Wave'

  50.0,

  // Variable: Klim
  //  Referenced by: '<S46>/Klim'

  5.0F,

  // Variable: R_Lc
  //  Referenced by: '<S9>/Gain1'

  0.0056F,

  // Variable: pr_sat_val
  //  Referenced by: '<S37>/Saturation'

  218.0F,

  // Expression: pInitialization.M
  //  Referenced by: '<S51>/KalmanGainM'

  { 0.999341661553191, 0.00043094928634882651, -0.047883861620127609,
    -1.1003743894055663E-5, 0.99243303004061489, 0.84074856297085421 },

  // Expression: 0
  //  Referenced by: '<S9>/Sine Wave'

  0.0,

  // Computed Parameter: SineWave_Hsin
  //  Referenced by: '<S9>/Sine Wave'

  0.0032722771837927307,

  // Computed Parameter: SineWave_HCos
  //  Referenced by: '<S9>/Sine Wave'

  0.999994646086684,

  // Computed Parameter: SineWave_PSin
  //  Referenced by: '<S9>/Sine Wave'

  -0.0032722771837927307,

  // Computed Parameter: SineWave_PCos
  //  Referenced by: '<S9>/Sine Wave'

  0.999994646086684,

  // Expression: 1
  //  Referenced by: '<S1>/Constant2'

  1.0,

  // Expression: pInitialization.Z
  //  Referenced by: '<S51>/CovarianceZ'

  { 0.00065940632202419048, 2.8435788762030271E-7, -3.1595721753628731E-5,
    2.8435788762030266E-7, 0.00027476527563298687, -0.030493317078871363,
    -3.1595721753628737E-5, -0.030493317078871367, 3.38817697366433 },

  // Expression: pInitialization.L
  //  Referenced by: '<S51>/KalmanGainL'

  { 0.99965472441749481, -0.0161941777780293, -0.047882553467110144,
    -0.13204369704812893, 1.2843105206419132, 0.840565559846477 },

  // Expression: PHASE
  //  Referenced by: '<S11>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S11>/enable'

  1.0,

  // Expression: PHASE
  //  Referenced by: '<S12>/phase'

  0.0,

  // Expression: 1
  //  Referenced by: '<S12>/enable'

  1.0,

  // Expression: 1
  //  Referenced by: '<S1>/Constant3'

  1.0,

  // Expression: 1
  //  Referenced by: '<S13>/activate'

  1.0,

  // Expression: 1
  //  Referenced by: '<S14>/activate'

  1.0,

  // Computed Parameter: Lykyhatkk1_Y0
  //  Referenced by: '<S100>/L*(y[k]-yhat[k|k-1])'

  0.0F,

  // Computed Parameter: deltax_Y0
  //  Referenced by: '<S102>/deltax'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S104>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S104>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S104>/PWM'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S106>/PWM'

  1.0E-6F,

  // Expression: single(duty)
  //  Referenced by: '<S106>/PWM'

  0.0F,

  // Expression: single(phase)
  //  Referenced by: '<S106>/PWM'

  0.0F,

  // Expression: single(deadtime)
  //  Referenced by: '<S108>/DO_PWM'

  1.0E-6F,

  // Expression: single(deadtime)
  //  Referenced by: '<S110>/DO_PWM'

  1.0E-6F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S112>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S112>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S114>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S114>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S116>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S116>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S118>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S118>/S-Function'

  10.0F,

  // Expression: single(CAN_TX_FREQ)
  //  Referenced by: '<S120>/S-Function'

  10.0F,

  // Expression: single(ETH_TX_FREQ)
  //  Referenced by: '<S120>/S-Function'

  10.0F,

  // Expression: single(gain)
  //  Referenced by: '<S21>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S21>/ADC'

  0.0F,

  // Expression: single(gain)
  //  Referenced by: '<S23>/ADC'

  0.0066763F,

  // Expression: single(offset)
  //  Referenced by: '<S23>/ADC'

  0.0F,

  // Expression: single(gain)
  //  Referenced by: '<S25>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S25>/ADC'

  0.0F,

  // Expression: single(gain)
  //  Referenced by: '<S27>/ADC'

  0.012451F,

  // Expression: single(offset)
  //  Referenced by: '<S27>/ADC'

  0.0F,

  // Computed Parameter: C_Value
  //  Referenced by: '<S50>/C'

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.009F },

  // Computed Parameter: X0_Value
  //  Referenced by: '<S50>/X0'

  { 0.0F, 0.0F, 0.0F },

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S45>/S-Function'

  2.5F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S45>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S45>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S45>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S45>/S-Function'

  0.0F,

  // Expression: single(INITIALVAL)
  //  Referenced by: '<S49>/S-Function'

  0.9444F,

  // Expression: single(VAL_MIN)
  //  Referenced by: '<S49>/S-Function'

  0.0F,

  // Expression: single(VAL_MAX)
  //  Referenced by: '<S49>/S-Function'

  5.0F,

  // Expression: single(0)
  //  Referenced by: '<S49>/S-Function'

  0.0F,

  // Expression: single(0)
  //  Referenced by: '<S49>/S-Function'

  0.0F,

  // Computed Parameter: Delay1_InitialCondition
  //  Referenced by: '<S46>/Delay1'

  0.0F,

  // Computed Parameter: a0_Gain
  //  Referenced by: '<S46>/a0'

  12.9185991F,

  // Computed Parameter: Delay3_InitialCondition
  //  Referenced by: '<S46>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain
  //  Referenced by: '<S46>/a1'

  12.9185295F,

  // Computed Parameter: Delay4_InitialCondition
  //  Referenced by: '<S46>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain
  //  Referenced by: '<S46>/b1'

  628.318F,

  // Computed Parameter: Delay5_InitialCondition
  //  Referenced by: '<S46>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain
  //  Referenced by: '<S46>/b2'

  314.15863F,

  // Computed Parameter: ub0_Gain
  //  Referenced by: '<S46>/1//b0'

  0.00318306359F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S37>/Saturation'

  -218.0F,

  // Computed Parameter: a0_Gain_j
  //  Referenced by: '<S40>/a0'

  2.06698F,

  // Computed Parameter: Delay3_InitialCondition_c
  //  Referenced by: '<S40>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_o
  //  Referenced by: '<S40>/a1'

  2.06670308F,

  // Computed Parameter: Delay4_InitialCondition_f
  //  Referenced by: '<S40>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_o
  //  Referenced by: '<S40>/b1'

  3141.19238F,

  // Computed Parameter: Delay5_InitialCondition_l
  //  Referenced by: '<S40>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_c
  //  Referenced by: '<S40>/b2'

  1570.79614F,

  // Computed Parameter: ub0_Gain_m
  //  Referenced by: '<S40>/1//b0'

  0.000636611483F,

  // Computed Parameter: a0_Gain_m
  //  Referenced by: '<S41>/a0'

  3.10046983F,

  // Computed Parameter: Delay3_InitialCondition_p
  //  Referenced by: '<S41>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_k
  //  Referenced by: '<S41>/a1'

  3.09965634F,

  // Computed Parameter: Delay4_InitialCondition_m
  //  Referenced by: '<S41>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_i
  //  Referenced by: '<S41>/b1'

  4397.10449F,

  // Computed Parameter: Delay5_InitialCondition_o
  //  Referenced by: '<S41>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_a
  //  Referenced by: '<S41>/b2'

  2199.11475F,

  // Computed Parameter: ub0_Gain_p
  //  Referenced by: '<S41>/1//b0'

  0.000454722467F,

  // Computed Parameter: a0_Gain_b
  //  Referenced by: '<S38>/a0'

  2.46727562F,

  // Computed Parameter: Delay3_InitialCondition_d
  //  Referenced by: '<S38>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_c
  //  Referenced by: '<S38>/a1'

  2.46430397F,

  // Computed Parameter: Delay4_InitialCondition_fy
  //  Referenced by: '<S38>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_p
  //  Referenced by: '<S38>/b1'

  9413.48828F,

  // Computed Parameter: Delay5_InitialCondition_e
  //  Referenced by: '<S38>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_p
  //  Referenced by: '<S38>/b2'

  4712.38916F,

  // Computed Parameter: ub0_Gain_mq
  //  Referenced by: '<S38>/1//b0'

  0.000212203813F,

  // Computed Parameter: a0_Gain_g
  //  Referenced by: '<S39>/a0'

  3.45418572F,

  // Computed Parameter: Delay3_InitialCondition_dr
  //  Referenced by: '<S39>/Delay3'

  0.0F,

  // Computed Parameter: a1_Gain_op
  //  Referenced by: '<S39>/a1'

  3.44603348F,

  // Computed Parameter: Delay4_InitialCondition_fyn
  //  Referenced by: '<S39>/Delay4'

  0.0F,

  // Computed Parameter: b1_Gain_l
  //  Referenced by: '<S39>/b1'

  13163.6338F,

  // Computed Parameter: Delay5_InitialCondition_ew
  //  Referenced by: '<S39>/Delay5'

  0.0F,

  // Computed Parameter: b2_Gain_j
  //  Referenced by: '<S39>/b2'

  6597.34473F,

  // Computed Parameter: ub0_Gain_k
  //  Referenced by: '<S39>/1//b0'

  0.000151574146F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S29>/Saturation'

  50000.0F,

  // Computed Parameter: Saturation_LowerSat_n
  //  Referenced by: '<S29>/Saturation'

  10000.0F,

  // Expression: single(frequency)
  //  Referenced by: '<S29>/CLK1'

  24000.0F,

  // Expression: single(phase_vector)
  //  Referenced by: '<S32>/S-Function'

  0.0F,

  // Expression: single(interrupt_phase)
  //  Referenced by: '<S32>/S-Function'

  0.0F,

  // Expression: single(frequency)
  //  Referenced by: '<S34>/CLK1'

  96006.1406F,

  // Computed Parameter: GIDifferentiator_NumCoef
  //  Referenced by: '<S10>/GI Differentiator'

  { 3.81076908F, -2.39778709F, -1.41298211F },

  // Computed Parameter: GIDifferentiator_DenCoef
  //  Referenced by: '<S10>/GI Differentiator'

  { 1.0F, 0.690541804F, 0.123144709F },

  // Computed Parameter: GIDifferentiator_InitialStates
  //  Referenced by: '<S10>/GI Differentiator'

  0.0F,

  // Computed Parameter: A_Value
  //  Referenced by: '<S50>/A'

  { 0.99935478F, -3.36059403E-9F, -1.9356083E-8F, -0.11521478F, 0.999972284F,
    -0.000159694886F, -0.0210404694F, 0.347196549F, 0.999970853F },

  // Computed Parameter: B_Value
  //  Referenced by: '<S50>/B'

  { 0.115215905F, 6.00106091E-7F, 3.45644344E-6F, -6.28799679E-9F,
    1.51889509E-7F, 8.74935324E-7F },

  // Computed Parameter: D_Value
  //  Referenced by: '<S50>/D'

  { 0.0F, 0.0F, 0.0F, 0.0F },

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S112>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S112>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S114>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S114>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S116>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S116>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S118>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S118>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S120>/S-Function'

  1000000U,

  // Expression: uint32(ETH_PORT)
  //  Referenced by: '<S120>/S-Function'

  2000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S45>/S-Function'

  1000000U,

  // Expression: uint32(CAN_BAUDRATE)
  //  Referenced by: '<S49>/S-Function'

  1000000U,

  // Expression: int16(lane)
  //  Referenced by: '<S104>/PWM'

  0,

  // Expression: int16(carrier)
  //  Referenced by: '<S104>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S104>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S104>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S104>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S104>/PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S106>/PWM'

  2,

  // Expression: int16(carrier)
  //  Referenced by: '<S106>/PWM'

  0,

  // Expression: int16(rate)
  //  Referenced by: '<S106>/PWM'

  1,

  // Expression: int16(outconf)
  //  Referenced by: '<S106>/PWM'

  2,

  // Expression: int16(outmode)
  //  Referenced by: '<S106>/PWM'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S106>/PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S108>/DO_PWM'

  12,

  // Expression: int16(outconf)
  //  Referenced by: '<S108>/DO_PWM'

  1,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S108>/DO_PWM'

  0,

  // Expression: int16(lane)
  //  Referenced by: '<S110>/DO_PWM'

  13,

  // Expression: int16(outconf)
  //  Referenced by: '<S110>/DO_PWM'

  1,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S110>/DO_PWM'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S112>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S112>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S114>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S114>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S116>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S116>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S118>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S118>/S-Function'

  0,

  // Expression: int16(DATATYPE)
  //  Referenced by: '<S120>/S-Function'

  1,

  // Expression: int16(0)
  //  Referenced by: '<S120>/S-Function'

  0,

  // Expression: int16(channel)
  //  Referenced by: '<S21>/ADC'

  0,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S21>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S21>/ADC'

  1,

  // Expression: int16(channel)
  //  Referenced by: '<S23>/ADC'

  5,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S23>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S23>/ADC'

  1,

  // Expression: int16(channel)
  //  Referenced by: '<S25>/ADC'

  3,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S25>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S25>/ADC'

  1,

  // Expression: int16(channel)
  //  Referenced by: '<S27>/ADC'

  4,

  // Expression: int16(nbBbx)
  //  Referenced by: '<S27>/ADC'

  0,

  // Expression: int16(outputwidth)
  //  Referenced by: '<S27>/ADC'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S45>/S-Function'

  1,

  // Expression: int16(DATA_TYPE)
  //  Referenced by: '<S49>/S-Function'

  1,

  // Computed Parameter: clk_id_Value
  //  Referenced by: '<S29>/clk_id'

  1,

  // Expression: int16(id)
  //  Referenced by: '<S29>/CLK1'

  1,

  // Computed Parameter: clk_id_Value_o
  //  Referenced by: '<S34>/clk_id'

  0,

  // Expression: int16(id)
  //  Referenced by: '<S34>/CLK1'

  0,

  // Computed Parameter: SFunction_P1
  //  Referenced by: '<S112>/S-Function'

  { 105U, 76U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S112>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S112>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S112>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14
  //  Referenced by: '<S112>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_g
  //  Referenced by: '<S114>/S-Function'

  { 118U, 99U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S114>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S114>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S114>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_f
  //  Referenced by: '<S114>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_i
  //  Referenced by: '<S116>/S-Function'

  109U,

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S116>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S116>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S116>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_p
  //  Referenced by: '<S116>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_k
  //  Referenced by: '<S118>/S-Function'

  { 66U, 97U, 116U, 116U, 95U, 80U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S118>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S118>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S118>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_n
  //  Referenced by: '<S118>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_d
  //  Referenced by: '<S120>/S-Function'

  { 66U, 97U, 116U, 116U, 95U, 78U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S120>/S-Function'

  0U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S120>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S120>/S-Function'

  1U,

  // Computed Parameter: SFunction_P14_g
  //  Referenced by: '<S120>/S-Function'

  { 101U, 109U, 112U, 116U, 121U },

  // Computed Parameter: SFunction_P1_e
  //  Referenced by: '<S45>/S-Function'

  { 75U, 99U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S45>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S45>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S45>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S45>/S-Function'

  2000U,

  // Computed Parameter: SFunction_P1_m
  //  Referenced by: '<S49>/S-Function'

  { 75U, 112U },

  // Expression: uint16(CAN_MB_ID)
  //  Referenced by: '<S49>/S-Function'

  1U,

  // Expression: uint16(CAN_ADDRESS)
  //  Referenced by: '<S49>/S-Function'

  0U,

  // Expression: uint16(ETH_MB_ID)
  //  Referenced by: '<S49>/S-Function'

  2U,

  // Expression: uint16(ETH_PORT)
  //  Referenced by: '<S49>/S-Function'

  2000U,

  // Expression: uint16(interrupt_pstsclr)
  //  Referenced by: '<S32>/S-Function'

  0U,

  // Expression: uint16(private_adc_delay_ns)
  //  Referenced by: '<S32>/S-Function'

  500U,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S104>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S104>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S104>/PWM'

  false,

  // Expression: boolean(dutyrealtime)
  //  Referenced by: '<S106>/PWM'

  true,

  // Expression: boolean(phaserealtime)
  //  Referenced by: '<S106>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S106>/PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S108>/DO_PWM'

  false,

  // Expression: boolean(activaterealtime)
  //  Referenced by: '<S110>/DO_PWM'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S112>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S112>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S112>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S112>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S114>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S114>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S114>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S114>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S116>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S116>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S116>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S116>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S118>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S118>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S118>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S118>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S120>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S120>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S120>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S120>/S-Function'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S21>/ADC'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S23>/ADC'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S25>/ADC'

  false,

  // Expression: boolean(usehist)
  //  Referenced by: '<S27>/ADC'

  false,

  // Expression: true()
  //  Referenced by: '<S50>/Enable'

  true,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S45>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S45>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S45>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S45>/S-Function'

  false,

  // Expression: boolean(CAN_ENABLED)
  //  Referenced by: '<S49>/S-Function'

  false,

  // Expression: boolean(CAN_BIG_ENDIAN)
  //  Referenced by: '<S49>/S-Function'

  false,

  // Expression: boolean(ETH_ENABLED)
  //  Referenced by: '<S49>/S-Function'

  false,

  // Expression: boolean(ETH_BIG_ENDIAN)
  //  Referenced by: '<S49>/S-Function'

  false,

  // Expression: boolean(var_freq)
  //  Referenced by: '<S29>/CLK1'

  false,

  // Expression: boolean(var_freq)
  //  Referenced by: '<S34>/CLK1'

  false,

  // Expression: pInitialization.isSqrtUsed
  //  Referenced by: '<S98>/isSqrtUsed'

  false
};

//
// End of automatically generated code
// Copyright imperix ltd. Switzerland 2021
// [EOF]
//
