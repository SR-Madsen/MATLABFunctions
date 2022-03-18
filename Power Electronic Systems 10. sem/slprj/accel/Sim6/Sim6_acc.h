#ifndef RTW_HEADER_Sim6_acc_h_
#define RTW_HEADER_Sim6_acc_h_
#include <stddef.h>
#include <string.h>
#ifndef Sim6_acc_COMMON_INCLUDES_
#define Sim6_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "Sim6_acc_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_defines.h"
typedef struct { real_T B_2_0_0 ; real_T B_2_1_0 ; }
B_Subsystempi2delay_Sim6_T ; typedef struct { int32_T
Subsystempi2delay_sysIdxToRun ; int8_T Subsystempi2delay_SubsysRanBC ;
boolean_T Subsystempi2delay_MODE ; char_T pad_Subsystempi2delay_MODE [ 2 ] ;
} DW_Subsystempi2delay_Sim6_T ; typedef struct { real_T B_3_0_0 ; real_T
B_3_1_0 ; } B_Subsystem1_Sim6_T ; typedef struct { int32_T
Subsystem1_sysIdxToRun ; int8_T Subsystem1_SubsysRanBC ; boolean_T
Subsystem1_MODE ; char_T pad_Subsystem1_MODE [ 2 ] ; } DW_Subsystem1_Sim6_T ;
typedef struct { creal_T B_4_14_0 ; real_T B_16_0_0 ; real_T B_16_14_0 [ 3 ]
; real_T B_16_15_0 [ 12 ] ; real_T B_16_15_1 [ 6 ] ; real_T B_16_22_0 ;
real_T B_16_32_0 [ 3 ] ; real_T B_16_33_0 ; real_T B_16_34_0 ; real_T
B_16_39_0 ; real_T B_16_40_0 ; real_T B_16_41_0 ; real_T B_16_43_0 ; real_T
B_16_45_0 ; real_T B_16_50_0 ; real_T B_16_51_0 ; real_T B_16_52_0 ; real_T
B_16_54_0 ; real_T B_16_56_0 ; real_T B_16_58_0 [ 3 ] ; real_T B_16_60_0 ;
real_T B_16_61_0 ; real_T B_16_62_0 ; real_T B_16_64_0 ; real_T B_16_66_0 ;
real_T B_16_67_0 ; real_T B_16_68_0 ; real_T B_16_69_0 ; real_T B_16_71_0 ;
real_T B_16_73_0 ; real_T B_16_74_0 ; real_T B_16_75_0 ; real_T B_16_76_0 ;
real_T B_16_77_0 ; real_T B_16_78_0 ; real_T B_16_79_0 ; real_T B_16_80_0 ;
real_T B_16_81_0 ; real_T B_16_82_0 ; real_T B_16_83_0 ; real_T B_16_84_0 ;
real_T B_16_85_0 ; real_T B_16_86_0 ; real_T B_16_87_0 ; real_T B_16_88_0 ;
real_T B_16_89_0 ; real_T B_16_90_0 ; real_T B_16_91_0 ; real_T B_16_92_0 ;
real_T B_16_93_0 ; real_T B_16_94_0 ; real_T B_16_99_0 ; real_T B_16_100_0 ;
real_T B_16_101_0 ; real_T B_16_102_0 [ 3 ] ; real_T B_16_103_0 [ 3 ] ;
real_T B_16_106_0 [ 2 ] ; real_T B_16_109_0 [ 2 ] ; real_T B_16_110_0 [ 3 ] ;
real_T B_16_111_0 [ 3 ] ; real_T B_16_112_0 [ 3 ] ; real_T B_16_114_0 ;
real_T B_16_116_0 ; real_T B_16_118_0 ; real_T B_16_121_0 ; real_T B_16_123_0
; real_T B_16_125_0 ; real_T B_16_129_0 ; real_T B_16_132_0 ; real_T
B_16_134_0 ; real_T B_16_135_0 ; real_T B_16_137_0 ; real_T B_16_141_0 ;
real_T B_16_143_0 ; real_T B_16_144_0 ; real_T B_16_146_0 ; real_T B_16_150_0
; real_T B_16_153_0 [ 6 ] ; real_T B_16_0_0_m ; real_T B_16_1_0 ; real_T
B_16_2_0 ; real_T B_16_3_0 ; real_T B_16_4_0 ; real_T B_16_6_0 ; real_T
B_16_7_0 ; real_T B_16_8_0 ; real_T B_16_14_0_c [ 2 ] ; real_T B_16_16_0 ;
real_T B_16_17_0 ; real_T B_16_24_0 ; real_T B_16_26_0 ; real_T B_16_28_0 [ 3
] ; real_T B_16_30_0 ; real_T B_16_31_0 ; real_T B_16_32_0_k ; real_T
B_15_1_0 ; real_T B_15_2_0 ; real_T B_15_8_0 ; real_T B_15_11_0 ; real_T
B_15_14_0 ; real_T B_15_16_0 ; real_T B_15_17_0 ; real_T B_15_19_0 ; real_T
B_15_20_0 ; real_T B_15_1_0_c ; real_T B_15_4_0 ; real_T B_15_5_0 ; real_T
B_15_11_0_b ; real_T B_15_14_0_p ; real_T B_15_17_0_c ; real_T B_15_18_0 ;
real_T B_15_20_0_f ; real_T B_15_24_0 ; real_T B_15_25_0 ; real_T B_15_26_0 ;
real_T B_10_6_0 [ 3 ] ; real_T B_10_10_0 [ 3 ] ; real_T B_10_1_0 ; real_T
B_10_8_0 [ 3 ] ; real_T B_10_9_0 ; real_T B_10_11_0 ; real_T B_10_18_0 [ 3 ]
; real_T B_10_19_0 ; real_T B_9_0_0 ; real_T B_9_1_0 ; real_T B_8_0_0 ;
real_T B_8_1_0 ; real_T B_5_0_0 ; real_T B_5_1_0 ; real_T B_4_0_0 ; real_T
B_4_1_0 ; real_T B_4_2_0 ; real_T B_4_4_0 ; real_T B_4_6_0 ; real_T B_4_7_0 ;
real_T B_4_8_0 ; real_T B_4_9_0 ; real_T B_4_11_0 ; real_T B_4_13_0 ; real_T
B_4_15_0 ; real_T B_4_16_0 ; real_T B_4_17_0 ; real_T B_4_18_0 ; real_T
B_4_19_0 ; real_T B_4_20_0 ; real_T B_4_21_0 ; real_T B_4_22_0 [ 3 ] ; real_T
B_4_23_0 [ 3 ] ; real_T B_4_26_0 [ 2 ] ; real_T B_4_0_0_g ; real_T B_4_1_0_g
; real_T B_1_0_0 ; real_T B_1_1_0 ; real_T B_0_0_0 ; real_T B_0_1_0 ; real_T
B_16_26_0_m [ 3 ] ; uint8_T B_16_11_0 ; uint8_T B_16_13_0 ; uint8_T B_16_20_0
; uint8_T B_16_22_0_n ; uint8_T B_4_4_0_p ; uint8_T B_4_6_0_l ; boolean_T
B_16_59_0 ; boolean_T B_16_70_0 ; boolean_T B_16_151_0 [ 3 ] ; boolean_T
B_15_15_0 ; boolean_T B_15_8_0_j ; boolean_T B_15_9_0 ; boolean_T B_15_10_0 ;
boolean_T B_15_12_0 ; boolean_T B_15_22_0 ; boolean_T B_4_3_0 ; boolean_T
B_4_10_0 ; char_T pad_B_4_10_0 [ 5 ] ; B_Subsystem1_Sim6_T Subsystem1 ;
B_Subsystempi2delay_Sim6_T Subsystempi2delay ; B_Subsystem1_Sim6_T
Subsystem1_m5 ; B_Subsystempi2delay_Sim6_T Subsystempi2delay_j ; } B_Sim6_T ;
typedef struct { real_T StateSpace_DSTATE [ 2 ] ; real_T Delay11_DSTATE ;
real_T FFInt_DSTATE ; real_T Delay11_DSTATE_d ; real_T FFInt_DSTATE_g ;
real_T DiscreteTimeIntegrator_DSTATE ; real_T DiscreteTimeIntegrator1_DSTATE
; real_T UnitDelay_DSTATE ; real_T Initial_FirstOutputTime ; real_T
Memory_PreviousInput ; real_T Memory_PreviousInput_a ; real_T PrevYA ; real_T
PrevYB ; real_T LastMajorTimeA ; real_T LastMajorTimeB ; real_T
Memory_PreviousInput_l ; real_T Memory_PreviousInput_o ; struct { real_T
modelTStart ; } VariableTransportDelay_RWORK ; struct { real_T modelTStart ;
} VariableTransportDelay_RWORK_i ; struct { real_T modelTStart ; }
VariableTransportDelay_RWORK_e ; struct { void * AS ; void * BS ; void * CS ;
void * DS ; void * DX_COL ; void * BD_COL ; void * TMP1 ; void * TMP2 ; void
* XTMP ; void * SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void * SW_CHG ;
void * G_STATE ; void * USWLAST ; void * XKM12 ; void * XKP12 ; void * XLAST
; void * ULAST ; void * IDX_SW_CHG ; void * Y_SWITCH ; void * SWITCH_TYPES ;
void * IDX_OUT_SW ; void * SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; }
StateSpace_PWORK ; void * Scope1_PWORK [ 2 ] ; struct { void * TUbufferPtrs [
3 ] ; } VariableTransportDelay_PWORK ; void * Scope1_PWORK_b [ 2 ] ; void *
Scope2_PWORK [ 2 ] ; struct { void * TUbufferPtrs [ 3 ] ; }
VariableTransportDelay_PWORK_p ; struct { void * TUbufferPtrs [ 3 ] ; }
VariableTransportDelay_PWORK_c ; int32_T Signalgenerator_sysIdxToRun ;
int32_T TmpAtomicSubsysAtSwitch2Inport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtMultiportSwitch1Inport4_sysIdxToRun ; int32_T
TmpAtomicSubsysAtMultiportSwitch1Inport2_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch3Inport1_sysIdxToRun ; int32_T
HarmonicGenerator_sysIdxToRun ; int32_T Subsystem1_sysIdxToRun ; int32_T
Subsystempi2delay_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
AutomaticGainControl_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_k ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_b ; uint32_T m_bpIndex ; int_T
StateSpace_IWORK [ 11 ] ; int_T Integrator_IWORK ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
VariableTransportDelay_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; }
VariableTransportDelay_IWORK_f ; struct { int_T Tail ; int_T Head ; int_T
Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
VariableTransportDelay_IWORK_j ; int_T P10kW_MODE ; int_T Integrator_MODE ;
int_T Integrator_MODE_i ; int_T Saturation2_MODE ; int_T Saturation_MODE ;
int8_T Signalgenerator_SubsysRanBC ; int8_T HarmonicGenerator_SubsysRanBC ;
int8_T Subsystem1_SubsysRanBC ; int8_T Subsystempi2delay_SubsysRanBC ; int8_T
AutomaticGainControl_SubsysRanBC ; uint8_T FFInt_NumInitCond ; uint8_T
FFInt_NumInitCond_h ; uint8_T DiscreteTimeIntegrator_NumInitCond ; uint8_T
DiscreteTimeIntegrator1_NumInitCond ; boolean_T RelationalOperator_Mode ;
boolean_T RelationalOperator_Mode_c ; boolean_T RelationalOperator2_Mode [ 3
] ; boolean_T RelationalOperator_Mode_g ; boolean_T RelationalOperator_Mode_j
; boolean_T Signalgenerator_MODE ; boolean_T HarmonicGenerator_MODE ;
boolean_T Subsystem1_MODE ; boolean_T Subsystempi2delay_MODE ; boolean_T
AutomaticGainControl_MODE ; char_T pad_AutomaticGainControl_MODE [ 7 ] ;
DW_Subsystem1_Sim6_T Subsystem1 ; DW_Subsystempi2delay_Sim6_T
Subsystempi2delay ; DW_Subsystem1_Sim6_T Subsystem1_m5 ;
DW_Subsystempi2delay_Sim6_T Subsystempi2delay_j ; } DW_Sim6_T ; typedef
struct { real_T Integrator_CSTATE ; real_T Integrator_CSTATE_c ; real_T
VariableTransportDelay_CSTATE ; real_T integrator_CSTATE ; real_T
TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ; real_T
Integrator_x2_CSTATE ; real_T TransferFcn1_CSTATE [ 2 ] ; real_T
TransferFcn2_CSTATE [ 2 ] ; real_T TransferFcn_CSTATE_a [ 2 ] ; real_T
TransferFcn_CSTATE_n [ 2 ] ; real_T TransferFcn1_CSTATE_f [ 2 ] ; real_T
TransferFcn2_CSTATE_h [ 2 ] ; real_T TransferFcn_CSTATE_k [ 2 ] ; real_T
TransferFcn1_CSTATE_n [ 2 ] ; real_T TransferFcn2_CSTATE_l [ 2 ] ; real_T
VariableTransportDelay_CSTATE_g ; real_T integrator_CSTATE_o ; real_T
VariableTransportDelay_CSTATE_e ; real_T integrator_CSTATE_h ; } X_Sim6_T ;
typedef struct { real_T Integrator_CSTATE ; real_T Integrator_CSTATE_c ;
real_T VariableTransportDelay_CSTATE ; real_T integrator_CSTATE ; real_T
TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ; real_T
Integrator_x2_CSTATE ; real_T TransferFcn1_CSTATE [ 2 ] ; real_T
TransferFcn2_CSTATE [ 2 ] ; real_T TransferFcn_CSTATE_a [ 2 ] ; real_T
TransferFcn_CSTATE_n [ 2 ] ; real_T TransferFcn1_CSTATE_f [ 2 ] ; real_T
TransferFcn2_CSTATE_h [ 2 ] ; real_T TransferFcn_CSTATE_k [ 2 ] ; real_T
TransferFcn1_CSTATE_n [ 2 ] ; real_T TransferFcn2_CSTATE_l [ 2 ] ; real_T
VariableTransportDelay_CSTATE_g ; real_T integrator_CSTATE_o ; real_T
VariableTransportDelay_CSTATE_e ; real_T integrator_CSTATE_h ; } XDot_Sim6_T
; typedef struct { boolean_T Integrator_CSTATE ; boolean_T
Integrator_CSTATE_c ; boolean_T VariableTransportDelay_CSTATE ; boolean_T
integrator_CSTATE ; boolean_T TransferFcn_CSTATE ; boolean_T
Integrator_x1_CSTATE ; boolean_T Integrator_x2_CSTATE ; boolean_T
TransferFcn1_CSTATE [ 2 ] ; boolean_T TransferFcn2_CSTATE [ 2 ] ; boolean_T
TransferFcn_CSTATE_a [ 2 ] ; boolean_T TransferFcn_CSTATE_n [ 2 ] ; boolean_T
TransferFcn1_CSTATE_f [ 2 ] ; boolean_T TransferFcn2_CSTATE_h [ 2 ] ;
boolean_T TransferFcn_CSTATE_k [ 2 ] ; boolean_T TransferFcn1_CSTATE_n [ 2 ]
; boolean_T TransferFcn2_CSTATE_l [ 2 ] ; boolean_T
VariableTransportDelay_CSTATE_g ; boolean_T integrator_CSTATE_o ; boolean_T
VariableTransportDelay_CSTATE_e ; boolean_T integrator_CSTATE_h ; }
XDis_Sim6_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE ; real_T
integrator_CSTATE ; real_T TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ;
real_T Integrator_x2_CSTATE ; real_T TransferFcn1_CSTATE [ 2 ] ; real_T
TransferFcn2_CSTATE [ 2 ] ; real_T TransferFcn_CSTATE_a [ 2 ] ; real_T
TransferFcn_CSTATE_n [ 2 ] ; real_T TransferFcn1_CSTATE_f [ 2 ] ; real_T
TransferFcn2_CSTATE_h [ 2 ] ; real_T TransferFcn_CSTATE_k [ 2 ] ; real_T
TransferFcn1_CSTATE_n [ 2 ] ; real_T TransferFcn2_CSTATE_l [ 2 ] ; real_T
VariableTransportDelay_CSTATE_g ; real_T integrator_CSTATE_o ; real_T
VariableTransportDelay_CSTATE_e ; real_T integrator_CSTATE_h ; }
CStateAbsTol_Sim6_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE ; real_T
integrator_CSTATE ; real_T TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ;
real_T Integrator_x2_CSTATE ; real_T TransferFcn1_CSTATE [ 2 ] ; real_T
TransferFcn2_CSTATE [ 2 ] ; real_T TransferFcn_CSTATE_a [ 2 ] ; real_T
TransferFcn_CSTATE_n [ 2 ] ; real_T TransferFcn1_CSTATE_f [ 2 ] ; real_T
TransferFcn2_CSTATE_h [ 2 ] ; real_T TransferFcn_CSTATE_k [ 2 ] ; real_T
TransferFcn1_CSTATE_n [ 2 ] ; real_T TransferFcn2_CSTATE_l [ 2 ] ; real_T
VariableTransportDelay_CSTATE_g ; real_T integrator_CSTATE_o ; real_T
VariableTransportDelay_CSTATE_e ; real_T integrator_CSTATE_h ; }
CXPtMin_Sim6_T ; typedef struct { real_T Integrator_CSTATE ; real_T
Integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE ; real_T
integrator_CSTATE ; real_T TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ;
real_T Integrator_x2_CSTATE ; real_T TransferFcn1_CSTATE [ 2 ] ; real_T
TransferFcn2_CSTATE [ 2 ] ; real_T TransferFcn_CSTATE_a [ 2 ] ; real_T
TransferFcn_CSTATE_n [ 2 ] ; real_T TransferFcn1_CSTATE_f [ 2 ] ; real_T
TransferFcn2_CSTATE_h [ 2 ] ; real_T TransferFcn_CSTATE_k [ 2 ] ; real_T
TransferFcn1_CSTATE_n [ 2 ] ; real_T TransferFcn2_CSTATE_l [ 2 ] ; real_T
VariableTransportDelay_CSTATE_g ; real_T integrator_CSTATE_o ; real_T
VariableTransportDelay_CSTATE_e ; real_T integrator_CSTATE_h ; }
CXPtMax_Sim6_T ; typedef struct { real_T P10kW_StepTime_ZC ; real_T
RelationalOperator_RelopInput_ZC ; real_T Integrator_Reset_ZC ; real_T
Integrator_IntgUpLimit_ZC ; real_T Integrator_IntgLoLimit_ZC ; real_T
Integrator_LeaveSaturate_ZC ; real_T HitCrossing_HitNoOutput_ZC ; real_T
Integrator_IntgUpLimit_ZC_d ; real_T Integrator_IntgLoLimit_ZC_d ; real_T
Integrator_LeaveSaturate_ZC_i ; real_T RelationalOperator_RelopInput_ZC_a ;
real_T Saturation2_UprLim_ZC ; real_T Saturation2_LwrLim_ZC ; real_T
RelationalOperator2_RelopInput_ZC [ 3 ] ; real_T
RelationalOperator_RelopInput_ZC_m ; real_T
RelationalOperator_RelopInput_ZC_e ; real_T Saturation_UprLim_ZC ; real_T
Saturation_LwrLim_ZC ; } ZCV_Sim6_T ; typedef struct { ZCSigState
P10kW_StepTime_ZCE ; ZCSigState RelationalOperator_RelopInput_ZCE ;
ZCSigState Integrator_Reset_ZCE ; ZCSigState Integrator_IntgUpLimit_ZCE ;
ZCSigState Integrator_IntgLoLimit_ZCE ; ZCSigState
Integrator_LeaveSaturate_ZCE ; ZCSigState HitCrossing_HitNoOutput_ZCE ;
ZCSigState Integrator_IntgUpLimit_ZCE_l ; ZCSigState
Integrator_IntgLoLimit_ZCE_a ; ZCSigState Integrator_LeaveSaturate_ZCE_i ;
ZCSigState RelationalOperator_RelopInput_ZCE_m ; ZCSigState
Saturation2_UprLim_ZCE ; ZCSigState Saturation2_LwrLim_ZCE ; ZCSigState
RelationalOperator2_RelopInput_ZCE [ 3 ] ; ZCSigState
RelationalOperator_RelopInput_ZCE_i ; ZCSigState
RelationalOperator_RelopInput_ZCE_f ; ZCSigState Saturation_UprLim_ZCE ;
ZCSigState Saturation_LwrLim_ZCE ; } PrevZCX_Sim6_T ; struct
P_Subsystempi2delay_Sim6_T_ { real_T P_0 [ 2 ] ; } ; struct
P_Subsystem1_Sim6_T_ { real_T P_0 [ 2 ] ; } ; struct P_Sim6_T_ { real_T P_0 ;
real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ;
real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T
P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 [ 9 ] ; real_T P_16 ; real_T
P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 [
2 ] ; real_T P_23 [ 2 ] ; real_T P_24 ; real_T P_25 ; real_T P_26 ; real_T
P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T P_32 ;
real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 ; real_T
P_38 [ 3 ] ; real_T P_39 [ 3 ] ; real_T P_40 [ 3 ] ; real_T P_41 ; real_T
P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 [ 3 ] ; real_T
P_47 [ 3 ] ; real_T P_48 [ 3 ] ; real_T P_49 ; real_T P_50 ; real_T P_51 ;
real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 [ 8 ] ; real_T P_56 [ 8
] ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ;
real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T
P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ;
real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T
P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ;
real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ; real_T
P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T P_94 [
2 ] ; real_T P_95 [ 4 ] ; real_T P_96 [ 2 ] ; real_T P_97 [ 20 ] ; real_T
P_98 [ 2 ] ; real_T P_99 [ 24 ] ; real_T P_100 [ 2 ] ; real_T P_101 [ 120 ] ;
real_T P_102 [ 2 ] ; real_T P_103 [ 2 ] ; real_T P_104 ; real_T P_105 ;
real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ; real_T P_110 ;
real_T P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ; real_T P_115 ;
real_T P_116 ; real_T P_117 ; real_T P_118 ; real_T P_119 ; real_T P_120 ;
real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ; real_T P_125 ;
real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ; real_T P_130 ;
real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ; real_T P_135 ;
real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 ; real_T P_140 ;
real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T P_144 ; real_T P_145 ;
real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T P_149 ; real_T P_150 ;
real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ; real_T P_155 ;
real_T P_156 ; real_T P_157 ; real_T P_158 ; real_T P_159 ; real_T P_160 ;
real_T P_161 ; real_T P_162 [ 9 ] ; real_T P_163 ; real_T P_164 [ 9 ] ;
real_T P_165 ; real_T P_166 [ 2 ] ; real_T P_167 [ 2 ] ; real_T P_168 ;
real_T P_169 [ 2 ] ; real_T P_170 [ 2 ] ; real_T P_171 ; real_T P_172 [ 2 ] ;
real_T P_173 [ 2 ] ; real_T P_174 ; real_T P_175 ; real_T P_176 ; real_T
P_177 ; real_T P_178 [ 3 ] ; real_T P_179 [ 3 ] ; real_T P_180 ; real_T P_181
; real_T P_182 [ 2 ] ; real_T P_183 [ 2 ] ; real_T P_184 [ 2 ] ; real_T P_185
[ 2 ] ; real_T P_186 ; real_T P_187 [ 2 ] ; real_T P_188 [ 2 ] ; real_T P_189
; real_T P_190 ; real_T P_191 ; real_T P_192 [ 2 ] ; real_T P_193 [ 2 ] ;
real_T P_194 [ 2 ] ; real_T P_195 [ 2 ] ; real_T P_196 ; real_T P_197 [ 2 ] ;
real_T P_198 [ 2 ] ; real_T P_199 ; real_T P_200 ; real_T P_201 ; real_T
P_202 ; real_T P_203 ; real_T P_204 ; real_T P_205 ; real_T P_206 ; real_T
P_207 ; real_T P_208 ; real_T P_209 ; real_T P_210 ; real_T P_211 ; real_T
P_212 [ 2 ] ; real_T P_213 ; real_T P_214 ; real_T P_215 ; real_T P_216 ;
real_T P_217 ; real_T P_218 ; real_T P_219 ; real_T P_220 ; real_T P_221 ;
real_T P_222 [ 3 ] ; real_T P_223 ; real_T P_224 ; real_T P_225 ; boolean_T
P_226 ; char_T pad_P_226 [ 7 ] ; P_Subsystem1_Sim6_T Subsystem1 ;
P_Subsystempi2delay_Sim6_T Subsystempi2delay ; P_Subsystem1_Sim6_T
Subsystem1_m5 ; P_Subsystempi2delay_Sim6_T Subsystempi2delay_j ; } ; extern
P_Sim6_T Sim6_rtDefaultP ;
#endif
