#include <math.h>
#include "Sim6_acc.h"
#include "Sim6_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T Sim6_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T *
tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * *
uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = *
bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ;
int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf = *
uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0
; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
Sim6_acc_rt_VTDelayfindtDInterpolate ( real_T x , real_T * uBuf , int_T bufSz
, int_T head , int_T tail , int_T * pLast , real_T t , real_T tStart ,
boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput , real_T
initOutput , real_T * appliedDelay ) { int_T n , k ; real_T f ; int_T kp1 ;
real_T tminustD , tL , tR , uD , uL , uR , fU ; real_T * tBuf = uBuf + bufSz
; real_T * xBuf = uBuf + 2 * bufSz ; if ( minorStepAndTAtLastMajorOutput ) {
if ( * pLast == head ) { * pLast = ( * pLast == 0 ) ? bufSz - 1 : * pLast - 1
; } head = ( head == 0 ) ? bufSz - 1 : head - 1 ; } if ( x <= 1 ) { return
initOutput ; } k = * pLast ; n = 0 ; for ( ; ; ) { n ++ ; if ( n > bufSz )
break ; if ( x - xBuf [ k ] > 1.0 ) { if ( k == head ) { int_T km1 ; f = ( x
- 1.0 - xBuf [ k ] ) / ( x - xBuf [ k ] ) ; tminustD = ( 1.0 - f ) * tBuf [ k
] + f * t ; km1 = k - 1 ; if ( km1 < 0 ) km1 = bufSz - 1 ; tL = tBuf [ km1 ]
; tR = tBuf [ k ] ; uL = uBuf [ km1 ] ; uR = uBuf [ k ] ; break ; } kp1 = k +
1 ; if ( kp1 == bufSz ) kp1 = 0 ; if ( x - xBuf [ kp1 ] <= 1.0 ) { f = ( x -
1.0 - xBuf [ k ] ) / ( xBuf [ kp1 ] - xBuf [ k ] ) ; tL = tBuf [ k ] ; tR =
tBuf [ kp1 ] ; uL = uBuf [ k ] ; uR = uBuf [ kp1 ] ; tminustD = ( 1.0 - f ) *
tL + f * tR ; break ; } k = kp1 ; } else { if ( k == tail ) { f = ( x - 1.0 )
/ xBuf [ k ] ; if ( discrete ) { return ( uBuf [ tail ] ) ; } kp1 = k + 1 ;
if ( kp1 == bufSz ) kp1 = 0 ; tminustD = ( 1 - f ) * tStart + f * tBuf [ k ]
; tL = tBuf [ k ] ; tR = tBuf [ kp1 ] ; uL = uBuf [ k ] ; uR = uBuf [ kp1 ] ;
break ; } k = k - 1 ; if ( k < 0 ) k = bufSz - 1 ; } } * pLast = k ; if ( tR
== tL ) { fU = 1.0 ; } else { fU = ( tminustD - tL ) / ( tR - tL ) ; } if (
discrete ) { uD = ( fU > ( 1.0 - fU ) ) ? uR : uL ; } else { uD = ( 1.0 - fU
) * uL + fU * uR ; } * appliedDelay = t - tminustD ; return uD ; } real_T
look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T prevIndex [ ] , uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ;
uint32_T bpIdx ; uint32_T found ; uint32_T iLeft ; uint32_T iRght ; if ( u0
<= bp0 [ 0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] -
bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = prevIndex [ 0U ]
; iLeft = 0U ; iRght = maxIndex ; found = 0U ; while ( found == 0U ) { if (
u0 < bp0 [ bpIdx ] ) { iRght = bpIdx - 1U ; bpIdx = ( ( bpIdx + iLeft ) - 1U
) >> 1U ; } else if ( u0 < bp0 [ bpIdx + 1U ] ) { found = 1U ; } else { iLeft
= bpIdx + 1U ; bpIdx = ( ( bpIdx + iRght ) + 1U ) >> 1U ; } } frac = ( u0 -
bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx =
maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] -
bp0 [ maxIndex - 1U ] ) ; } prevIndex [ 0U ] = bpIdx ; yL_0d0 = table [ bpIdx
] ; return ( table [ bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } void
rt_ssGetBlockPath ( SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * *
path ) { _ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void
rt_ssSet_slErrMsg ( void * S , void * diag ) { SimStruct * castedS = (
SimStruct * ) S ; if ( ! _ssIsErrorStatusAslErrMsg ( castedS ) ) {
_ssSet_slErrMsg ( castedS , diag ) ; } else { _ssDiscardDiagnostic ( castedS
, diag ) ; } } void rt_ssReportDiagnosticAsWarning ( void * S , void * diag )
{ _ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } void
Sim6_Subsystempi2delay_Init ( SimStruct * S , B_Subsystempi2delay_Sim6_T *
localB , P_Subsystempi2delay_Sim6_T * localP ) { localB -> B_2_0_0 = localP
-> P_0 [ 0 ] ; localB -> B_2_1_0 = localP -> P_0 [ 1 ] ; } void
Sim6_Subsystempi2delay_Disable ( SimStruct * S , DW_Subsystempi2delay_Sim6_T
* localDW ) { localDW -> Subsystempi2delay_MODE = false ; } void
Sim6_Subsystempi2delay ( SimStruct * S , uint8_T rtu_Enable , const real_T
rtu_alpha_beta [ 2 ] , real_T rtu_wt , B_Subsystempi2delay_Sim6_T * localB ,
DW_Subsystempi2delay_Sim6_T * localDW ) { int32_T isHit ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( rtu_Enable > 0 ) { if ( ! localDW -> Subsystempi2delay_MODE
) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } localDW ->
Subsystempi2delay_MODE = true ; } } else if ( localDW ->
Subsystempi2delay_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
Sim6_Subsystempi2delay_Disable ( S , localDW ) ; } } if ( localDW ->
Subsystempi2delay_MODE ) { localB -> B_2_0_0 = rtu_alpha_beta [ 0 ] *
muDoubleScalarSin ( rtu_wt ) - rtu_alpha_beta [ 1 ] * muDoubleScalarCos (
rtu_wt ) ; localB -> B_2_1_0 = rtu_alpha_beta [ 0 ] * muDoubleScalarCos (
rtu_wt ) + rtu_alpha_beta [ 1 ] * muDoubleScalarSin ( rtu_wt ) ; if (
ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( localDW ->
Subsystempi2delay_SubsysRanBC ) ; } } } void Sim6_Subsystempi2delay_Term (
SimStruct * const S ) { } void Sim6_Subsystem1_Init ( SimStruct * S ,
B_Subsystem1_Sim6_T * localB , P_Subsystem1_Sim6_T * localP ) { localB ->
B_3_0_0 = localP -> P_0 [ 0 ] ; localB -> B_3_1_0 = localP -> P_0 [ 1 ] ; }
void Sim6_Subsystem1_Disable ( SimStruct * S , DW_Subsystem1_Sim6_T * localDW
) { localDW -> Subsystem1_MODE = false ; } void Sim6_Subsystem1 ( SimStruct *
S , uint8_T rtu_Enable , const real_T rtu_alpha_beta [ 2 ] , real_T rtu_wt ,
B_Subsystem1_Sim6_T * localB , DW_Subsystem1_Sim6_T * localDW ) { int32_T
isHit ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && (
ssIsMajorTimeStep ( S ) != 0 ) ) { if ( rtu_Enable > 0 ) { if ( ! localDW ->
Subsystem1_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } localDW ->
Subsystem1_MODE = true ; } } else if ( localDW -> Subsystem1_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; Sim6_Subsystem1_Disable (
S , localDW ) ; } } if ( localDW -> Subsystem1_MODE ) { localB -> B_3_0_0 =
rtu_alpha_beta [ 0 ] * muDoubleScalarCos ( rtu_wt ) + rtu_alpha_beta [ 1 ] *
muDoubleScalarSin ( rtu_wt ) ; localB -> B_3_1_0 = - rtu_alpha_beta [ 0 ] *
muDoubleScalarSin ( rtu_wt ) + rtu_alpha_beta [ 1 ] * muDoubleScalarCos (
rtu_wt ) ; if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( localDW ->
Subsystem1_SubsysRanBC ) ; } } } void Sim6_Subsystem1_Term ( SimStruct *
const S ) { } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T
B_16_12_0 ; B_Sim6_T * _rtB ; DW_Sim6_T * _rtDW ; P_Sim6_T * _rtP ;
PrevZCX_Sim6_T * _rtZCE ; X_Sim6_T * _rtX ; real_T B_16_4_0_idx_0 ; real_T
B_16_4_0_idx_1 ; real_T B_16_8_0_idx_0 ; real_T B_16_8_0_idx_1 ; real_T
B_16_8_0_idx_2 ; real_T rtb_B_10_0_0 ; real_T rtb_B_15_3_0 ; real_T
rtb_B_15_7_0 ; real_T rtb_B_16_27_0 ; real_T rtb_B_16_28_0 ; real_T
rtb_B_16_42_0 ; real_T rtb_B_16_53_0 ; real_T tmp ; int32_T isHit ; boolean_T
didZcEventOccur ; _rtDW = ( ( DW_Sim6_T * ) ssGetRootDWork ( S ) ) ; _rtZCE =
( ( PrevZCX_Sim6_T * ) _ssGetPrevZCSigState ( S ) ) ; _rtX = ( ( X_Sim6_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_Sim6_T * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( B_Sim6_T * ) _ssGetModelBlockIO ( S ) ) ; isHit = ssIsSampleHit (
S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_16_0_0 = _rtP -> P_91 ; isHit =
ssIsSampleHit ( S , 3 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( _rtB -> B_16_0_0 > 0.0 ) { if ( ! _rtDW ->
Signalgenerator_MODE ) { if ( ssGetTaskTime ( S , 3 ) != ssGetTStart ( S ) )
{ ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Signalgenerator_MODE = true ; } } else if ( _rtDW -> Signalgenerator_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW ->
DiscreteTimeIntegrator_DSTATE = _rtB -> B_15_2_0 ; _rtDW ->
DiscreteTimeIntegrator1_DSTATE = _rtB -> B_15_8_0 ; _rtB -> B_15_1_0 = _rtP
-> P_51 ; _rtB -> B_15_15_0 = _rtP -> P_226 ; _rtB -> B_15_17_0 = _rtP ->
P_52 ; _rtB -> B_15_16_0 = _rtP -> P_53 ; _rtB -> B_15_19_0 = _rtP -> P_54 ;
_rtDW -> Signalgenerator_MODE = false ; } } if ( _rtDW ->
Signalgenerator_MODE ) { isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_15_1_0 = rt_Lookup ( & _rtP -> P_55 [ 0 ] , 8 , ssGetTaskTime
( S , 3 ) , & _rtP -> P_56 [ 0 ] ) ; _rtB -> B_15_2_0 = _rtDW ->
DiscreteTimeIntegrator_DSTATE ; if ( ssGetTaskTime ( S , 3 ) < _rtP -> P_59 )
{ rtb_B_15_3_0 = _rtP -> P_60 ; } else { rtb_B_15_3_0 = _rtP -> P_61 ; } if (
ssGetTaskTime ( S , 3 ) < _rtP -> P_62 ) { rtb_B_15_7_0 = _rtP -> P_63 ; }
else { rtb_B_15_7_0 = _rtP -> P_64 ; } _rtB -> B_15_8_0 = _rtDW ->
DiscreteTimeIntegrator1_DSTATE ; if ( rtb_B_15_3_0 >= _rtP -> P_68 ) { switch
( ( int32_T ) _rtB -> B_15_11_0_b ) { case 1 : _rtB -> B_15_11_0 = _rtB ->
B_15_25_0 * rtb_B_15_7_0 ; break ; case 2 : _rtB -> B_15_11_0 = _rtB ->
B_15_8_0 ; break ; case 3 : _rtB -> B_15_11_0 = muDoubleScalarSin ( _rtB ->
B_15_8_0 * _rtB -> B_15_20_0_f ) * _rtB -> B_15_26_0 ; break ; default : _rtB
-> B_15_11_0 = _rtB -> B_15_18_0 ; break ; } } else { _rtB -> B_15_11_0 =
_rtDW -> UnitDelay_DSTATE ; } if ( ( ! ( rtb_B_15_3_0 != 0.0 ) ) && _rtB ->
B_15_22_0 ) { rtb_B_15_3_0 = _rtB -> B_15_14_0_p ; } else { rtb_B_15_3_0 =
_rtB -> B_15_11_0 ; } if ( _rtB -> B_15_10_0 ) { tmp = rtb_B_15_3_0 ; } else
{ tmp = _rtB -> B_15_5_0 ; } _rtB -> B_15_14_0 = _rtP -> P_69 * tmp ; _rtB ->
B_15_15_0 = ( _rtB -> B_15_12_0 && _rtB -> B_15_8_0_j ) ; _rtB -> B_15_16_0 =
_rtB -> B_15_2_0 ; if ( _rtB -> B_15_8_0_j ) { _rtB -> B_15_17_0 =
rtb_B_15_3_0 ; } else { _rtB -> B_15_17_0 = _rtB -> B_15_1_0_c ; } if ( _rtB
-> B_15_9_0 ) { _rtB -> B_15_19_0 = _rtP -> P_50 * rtb_B_15_3_0 ; } else {
_rtB -> B_15_19_0 = _rtB -> B_15_4_0 ; } if ( rtb_B_15_7_0 >= _rtP -> P_70 )
{ _rtB -> B_15_20_0 = _rtB -> B_15_24_0 ; } else { _rtB -> B_15_20_0 = _rtB
-> B_15_17_0_c ; } } if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW
-> Signalgenerator_SubsysRanBC ) ; } } rtb_B_15_7_0 = _rtB -> B_15_17_0 +
_rtB -> B_16_31_0 ; if ( _rtB -> B_15_15_0 ) { rtb_B_15_3_0 = _rtB ->
B_15_1_0 ; } else { rtb_B_15_3_0 = rtb_B_15_7_0 ; } B_16_4_0_idx_0 =
rtb_B_15_3_0 ; if ( _rtB -> B_16_30_0 >= _rtP -> P_92 ) { B_16_4_0_idx_1 =
rtb_B_15_7_0 ; } else { B_16_4_0_idx_1 = rtb_B_15_3_0 ; } rtb_B_15_7_0 =
ssGetTaskTime ( S , 3 ) * _rtB -> B_16_24_0 + _rtB -> B_15_16_0 ;
B_16_8_0_idx_0 = ( _rtB -> B_16_26_0 + _rtB -> B_16_28_0 [ 0 ] ) + _rtB ->
B_15_19_0 ; B_16_8_0_idx_1 = ( _rtB -> B_16_26_0 + _rtB -> B_16_28_0 [ 1 ] )
+ _rtB -> B_15_19_0 ; B_16_8_0_idx_2 = ( _rtB -> B_16_26_0 + _rtB ->
B_16_28_0 [ 2 ] ) + _rtB -> B_15_19_0 ; B_16_12_0 = _rtP -> P_93 ; isHit =
ssIsSampleHit ( S , 3 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( B_16_12_0 > 0.0 ) { if ( ! _rtDW -> HarmonicGenerator_MODE
) { if ( ssGetTaskTime ( S , 3 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
HarmonicGenerator_MODE = true ; } } else if ( _rtDW -> HarmonicGenerator_MODE
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_10_6_0 [ 0 ]
= _rtP -> P_24 ; _rtB -> B_10_10_0 [ 0 ] = _rtP -> P_25 ; _rtB -> B_10_6_0 [
1 ] = _rtP -> P_24 ; _rtB -> B_10_10_0 [ 1 ] = _rtP -> P_25 ; _rtB ->
B_10_6_0 [ 2 ] = _rtP -> P_24 ; _rtB -> B_10_10_0 [ 2 ] = _rtP -> P_25 ;
_rtDW -> HarmonicGenerator_MODE = false ; } } if ( _rtDW ->
HarmonicGenerator_MODE ) { isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit
!= 0 ) { rtb_B_10_0_0 = _rtP -> P_26 * rtb_B_15_7_0 ; if ( ssGetTaskTime ( S
, 3 ) < _rtP -> P_27 ) { tmp = _rtP -> P_28 ; } else { tmp = _rtP -> P_29 ; }
if ( ssGetTaskTime ( S , 3 ) < _rtP -> P_30 ) { rtb_B_15_3_0 = _rtP -> P_31 ;
} else { rtb_B_15_3_0 = _rtP -> P_32 ; } rtb_B_15_3_0 += tmp ; _rtB ->
B_10_6_0 [ 0 ] = muDoubleScalarSin ( ( rtb_B_10_0_0 + _rtB -> B_10_1_0 ) +
_rtB -> B_10_8_0 [ 0 ] ) * ( rtb_B_15_3_0 * _rtB -> B_10_9_0 ) ; _rtB ->
B_10_6_0 [ 1 ] = muDoubleScalarSin ( ( rtb_B_10_0_0 + _rtB -> B_10_1_0 ) +
_rtB -> B_10_8_0 [ 1 ] ) * ( rtb_B_15_3_0 * _rtB -> B_10_9_0 ) ; _rtB ->
B_10_6_0 [ 2 ] = muDoubleScalarSin ( ( rtb_B_10_0_0 + _rtB -> B_10_1_0 ) +
_rtB -> B_10_8_0 [ 2 ] ) * ( rtb_B_15_3_0 * _rtB -> B_10_9_0 ) ; rtb_B_10_0_0
= _rtP -> P_33 * rtb_B_15_7_0 ; _rtB -> B_10_10_0 [ 0 ] = muDoubleScalarSin (
( rtb_B_10_0_0 + _rtB -> B_10_11_0 ) + _rtB -> B_10_18_0 [ 0 ] ) * (
rtb_B_15_3_0 * _rtB -> B_10_19_0 ) ; _rtB -> B_10_10_0 [ 1 ] =
muDoubleScalarSin ( ( rtb_B_10_0_0 + _rtB -> B_10_11_0 ) + _rtB -> B_10_18_0
[ 1 ] ) * ( rtb_B_15_3_0 * _rtB -> B_10_19_0 ) ; _rtB -> B_10_10_0 [ 2 ] =
muDoubleScalarSin ( ( rtb_B_10_0_0 + _rtB -> B_10_11_0 ) + _rtB -> B_10_18_0
[ 2 ] ) * ( rtb_B_15_3_0 * _rtB -> B_10_19_0 ) ; } if ( ssIsMajorTimeStep ( S
) != 0 ) { srUpdateBC ( _rtDW -> HarmonicGenerator_SubsysRanBC ) ; } } _rtB
-> B_16_14_0 [ 0 ] = ( muDoubleScalarSin ( rtb_B_15_7_0 + B_16_8_0_idx_0 ) *
B_16_4_0_idx_0 + _rtB -> B_10_6_0 [ 0 ] ) + _rtB -> B_10_10_0 [ 0 ] ; _rtB ->
B_16_14_0 [ 1 ] = ( muDoubleScalarSin ( rtb_B_15_7_0 + B_16_8_0_idx_1 ) *
B_16_4_0_idx_1 + _rtB -> B_10_6_0 [ 1 ] ) + _rtB -> B_10_10_0 [ 1 ] ; _rtB ->
B_16_14_0 [ 2 ] = ( muDoubleScalarSin ( rtb_B_15_7_0 + B_16_8_0_idx_2 ) *
B_16_4_0_idx_1 + _rtB -> B_10_6_0 [ 2 ] ) + _rtB -> B_10_10_0 [ 2 ] ;
ssCallAccelRunBlock ( S , 16 , 15 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> P10kW_MODE = (
ssGetTaskTime ( S , 1 ) >= _rtP -> P_104 ) ; if ( _rtDW -> P10kW_MODE == 1 )
{ _rtB -> B_16_22_0 = _rtP -> P_106 ; } else { _rtB -> B_16_22_0 = _rtP ->
P_105 ; } } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_16_26_0_m [ 0 ] = _rtP -> P_107 * _rtB -> B_16_15_0 [ 6 ] * _rtP -> P_110 ;
_rtB -> B_16_26_0_m [ 1 ] = _rtP -> P_108 * _rtB -> B_16_15_0 [ 7 ] * _rtP ->
P_110 ; _rtB -> B_16_26_0_m [ 2 ] = _rtP -> P_109 * _rtB -> B_16_15_0 [ 8 ] *
_rtP -> P_110 ; rtb_B_16_27_0 = ( ( _rtB -> B_16_26_0_m [ 0 ] - 0.5 * _rtB ->
B_16_26_0_m [ 1 ] ) - 0.5 * _rtB -> B_16_26_0_m [ 2 ] ) * 0.816496580927726 ;
rtb_B_16_28_0 = ( ( 0.0 * _rtB -> B_16_26_0_m [ 0 ] + 0.8660254037844386 *
_rtB -> B_16_26_0_m [ 1 ] ) - 0.8660254037844386 * _rtB -> B_16_26_0_m [ 2 ]
) * 0.816496580927726 ; _rtB -> B_16_32_0 [ 0 ] = _rtP -> P_111 * _rtB ->
B_16_15_0 [ 9 ] * _rtP -> P_114 ; _rtB -> B_16_32_0 [ 1 ] = _rtP -> P_112 *
_rtB -> B_16_15_0 [ 10 ] * _rtP -> P_114 ; _rtB -> B_16_32_0 [ 2 ] = _rtP ->
P_113 * _rtB -> B_16_15_0 [ 11 ] * _rtP -> P_114 ; } isHit = ssIsSampleHit (
S , 4 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_16_33_0 = ( ( _rtB -> B_16_32_0 [
0 ] - 0.5 * _rtB -> B_16_32_0 [ 1 ] ) - 0.5 * _rtB -> B_16_32_0 [ 2 ] ) *
0.816496580927726 ; _rtB -> B_16_34_0 = ( ( 0.0 * _rtB -> B_16_32_0 [ 0 ] +
0.8660254037844386 * _rtB -> B_16_32_0 [ 1 ] ) - 0.8660254037844386 * _rtB ->
B_16_32_0 [ 2 ] ) * 0.816496580927726 ; } isHit = ssIsSampleHit ( S , 3 , 0 )
; if ( isHit != 0 ) { _rtB -> B_16_39_0 = ( rtb_B_16_27_0 * _rtB -> B_16_33_0
+ rtb_B_16_28_0 * _rtB -> B_16_34_0 ) * _rtP -> P_115 - _rtP -> P_117 * _rtDW
-> Delay11_DSTATE ; _rtB -> B_16_40_0 = _rtB -> B_16_39_0 + _rtDW ->
Delay11_DSTATE ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_16_41_0 = _rtB -> B_16_22_0 - _rtB -> B_16_40_0 ; } isHit =
ssIsSampleHit ( S , 4 , 0 ) ; if ( isHit != 0 ) { rtb_B_16_42_0 = _rtB ->
B_16_1_0 * _rtB -> B_16_41_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_16_43_0 = _rtDW -> FFInt_DSTATE ; } isHit =
ssIsSampleHit ( S , 4 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_16_45_0 = _rtB ->
B_16_43_0 * _rtB -> B_16_2_0 + rtb_B_16_42_0 ; } isHit = ssIsSampleHit ( S ,
3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_16_50_0 = ( rtb_B_16_27_0 * _rtB ->
B_16_34_0 - rtb_B_16_28_0 * _rtB -> B_16_33_0 ) * _rtP -> P_120 - _rtP ->
P_122 * _rtDW -> Delay11_DSTATE_d ; _rtB -> B_16_51_0 = _rtB -> B_16_50_0 +
_rtDW -> Delay11_DSTATE_d ; _rtB -> B_16_52_0 = _rtB -> B_16_17_0 - _rtB ->
B_16_51_0 ; } isHit = ssIsSampleHit ( S , 4 , 0 ) ; if ( isHit != 0 ) {
rtb_B_16_53_0 = _rtB -> B_16_3_0 * _rtB -> B_16_52_0 ; } isHit =
ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_16_54_0 = _rtDW
-> FFInt_DSTATE_g ; } isHit = ssIsSampleHit ( S , 4 , 0 ) ; if ( isHit != 0 )
{ _rtB -> B_16_56_0 = _rtB -> B_16_54_0 * _rtB -> B_16_4_0 + rtb_B_16_53_0 ;
ssCallAccelRunBlock ( S , 16 , 57 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_16_58_0 [ 0 ] =
_rtP -> P_125 * _rtB -> B_16_26_0_m [ 0 ] ; _rtB -> B_16_58_0 [ 1 ] = _rtP ->
P_125 * _rtB -> B_16_26_0_m [ 1 ] ; _rtB -> B_16_58_0 [ 2 ] = _rtP -> P_125 *
_rtB -> B_16_26_0_m [ 2 ] ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
RelationalOperator_Mode = ( _rtX -> Integrator_CSTATE > _rtB -> B_16_7_0 ) ;
} _rtB -> B_16_59_0 = _rtDW -> RelationalOperator_Mode ; } _rtB -> B_16_60_0
= _rtX -> Integrator_CSTATE - _rtB -> B_16_7_0 ; if ( ( _rtDW ->
Initial_FirstOutputTime == ( rtMinusInf ) ) || ( _rtDW ->
Initial_FirstOutputTime == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
Initial_FirstOutputTime = ssGetTaskTime ( S , 0 ) ; _rtB -> B_16_61_0 = _rtP
-> P_126 ; } else { _rtB -> B_16_61_0 = _rtB -> B_16_60_0 ; } if (
ssIsMajorTimeStep ( S ) != 0 ) { didZcEventOccur = ( _rtB -> B_16_59_0 && (
_rtZCE -> Integrator_Reset_ZCE != 1 ) ) ; _rtZCE -> Integrator_Reset_ZCE =
_rtB -> B_16_59_0 ; if ( didZcEventOccur || ( _rtDW -> Integrator_IWORK != 0
) ) { _rtX -> Integrator_CSTATE = _rtB -> B_16_61_0 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; } if ( _rtX ->
Integrator_CSTATE >= _rtP -> P_127 ) { if ( _rtX -> Integrator_CSTATE != _rtP
-> P_127 ) { _rtX -> Integrator_CSTATE = _rtP -> P_127 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE = 3 ; } else if ( _rtX -> Integrator_CSTATE <= _rtP -> P_128
) { if ( _rtX -> Integrator_CSTATE != _rtP -> P_128 ) { _rtX ->
Integrator_CSTATE = _rtP -> P_128 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE = 4 ; } else { if ( _rtDW -> Integrator_MODE != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW -> Integrator_MODE
= 0 ; } _rtB -> B_16_62_0 = _rtX -> Integrator_CSTATE ; } else { _rtB ->
B_16_62_0 = _rtX -> Integrator_CSTATE ; } isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { _rtB -> B_16_64_0 = _rtDW -> Memory_PreviousInput ; if
( ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtB -> B_16_6_0 > 0.0 ) { if ( !
_rtDW -> AutomaticGainControl_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } (
void ) memset ( & ( ( ( XDis_Sim6_T * ) ssGetContStateDisabled ( S ) ) ->
VariableTransportDelay_CSTATE_g ) , 0 , 4 * sizeof ( boolean_T ) ) ; _rtDW ->
AutomaticGainControl_MODE = true ; } } else { if ( ssGetTaskTime ( S , 1 ) ==
ssGetTStart ( S ) ) { ( void ) memset ( & ( ( ( XDis_Sim6_T * )
ssGetContStateDisabled ( S ) ) -> VariableTransportDelay_CSTATE_g ) , 1 , 4 *
sizeof ( boolean_T ) ) ; } if ( _rtDW -> AutomaticGainControl_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & ( ( (
XDis_Sim6_T * ) ssGetContStateDisabled ( S ) ) ->
VariableTransportDelay_CSTATE_g ) , 1 , 4 * sizeof ( boolean_T ) ) ; if (
_rtDW -> Subsystempi2delay_j . Subsystempi2delay_MODE ) {
Sim6_Subsystempi2delay_Disable ( S , & _rtDW -> Subsystempi2delay_j ) ; } if
( _rtDW -> Subsystem1_m5 . Subsystem1_MODE ) { Sim6_Subsystem1_Disable ( S ,
& _rtDW -> Subsystem1_m5 ) ; } _rtDW -> AutomaticGainControl_MODE = false ; }
} } } if ( _rtDW -> AutomaticGainControl_MODE ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> VariableTransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( S ) ; real_T appliedDelay ; _rtB -> B_4_0_0 =
Sim6_acc_rt_VTDelayfindtDInterpolate ( ( ( X_Sim6_T * ) ssGetContStates ( S )
) -> VariableTransportDelay_CSTATE_g , * uBuffer , _rtDW ->
VariableTransportDelay_IWORK_f . CircularBufSize , _rtDW ->
VariableTransportDelay_IWORK_f . Head , _rtDW ->
VariableTransportDelay_IWORK_f . Tail , & _rtDW ->
VariableTransportDelay_IWORK_f . Last , simTime , 0.0 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
, _rtP -> P_2 , & appliedDelay ) ; } _rtB -> B_4_1_0 = _rtX ->
integrator_CSTATE_o ; _rtB -> B_4_2_0 = ssGetT ( S ) ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) {
_rtDW -> RelationalOperator_Mode_g = ( _rtB -> B_4_2_0 >= _rtB -> B_4_0_0_g )
; } _rtB -> B_4_3_0 = _rtDW -> RelationalOperator_Mode_g ; _rtB -> B_4_4_0 =
_rtDW -> Memory_PreviousInput_l ; } if ( _rtB -> B_4_3_0 ) { _rtB -> B_0_0_0
= _rtB -> B_4_1_0 - _rtB -> B_4_0_0 ; _rtB -> B_0_1_0 = _rtB -> B_0_0_0 *
_rtB -> B_16_64_0 ; _rtB -> B_4_6_0 = _rtB -> B_0_1_0 ; } else { _rtB ->
B_4_6_0 = _rtB -> B_4_4_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> VariableTransportDelay_PWORK_c . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T appliedDelay ; _rtB -> B_4_7_0 =
Sim6_acc_rt_VTDelayfindtDInterpolate ( ( ( X_Sim6_T * ) ssGetContStates ( S )
) -> VariableTransportDelay_CSTATE_e , * uBuffer , _rtDW ->
VariableTransportDelay_IWORK_j . CircularBufSize , _rtDW ->
VariableTransportDelay_IWORK_j . Head , _rtDW ->
VariableTransportDelay_IWORK_j . Tail , & _rtDW ->
VariableTransportDelay_IWORK_j . Last , simTime , 0.0 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
, _rtP -> P_6 , & appliedDelay ) ; } _rtB -> B_4_8_0 = _rtX ->
integrator_CSTATE_h ; _rtB -> B_4_9_0 = ssGetT ( S ) ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) {
_rtDW -> RelationalOperator_Mode_j = ( _rtB -> B_4_9_0 >= _rtB -> B_4_1_0_g )
; } _rtB -> B_4_10_0 = _rtDW -> RelationalOperator_Mode_j ; _rtB -> B_4_11_0
= _rtDW -> Memory_PreviousInput_o ; } if ( _rtB -> B_4_10_0 ) { _rtB ->
B_1_0_0 = _rtB -> B_4_8_0 - _rtB -> B_4_7_0 ; _rtB -> B_1_1_0 = _rtB ->
B_1_0_0 * _rtB -> B_16_64_0 ; _rtB -> B_4_13_0 = _rtB -> B_1_1_0 ; } else {
_rtB -> B_4_13_0 = _rtB -> B_4_11_0 ; } _rtB -> B_4_14_0 . re = _rtB ->
B_4_6_0 ; _rtB -> B_4_14_0 . im = _rtB -> B_4_13_0 ; _rtB -> B_4_15_0 =
muDoubleScalarHypot ( _rtB -> B_4_14_0 . re , _rtB -> B_4_14_0 . im ) ; if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Saturation_MODE = _rtB -> B_4_15_0
>= _rtP -> P_9 ? 1 : _rtB -> B_4_15_0 > _rtP -> P_10 ? 0 : - 1 ; } _rtB ->
B_4_16_0 = _rtDW -> Saturation_MODE == 1 ? _rtP -> P_9 : _rtDW ->
Saturation_MODE == - 1 ? _rtP -> P_10 : _rtB -> B_4_15_0 ; _rtB -> B_4_17_0 =
1.0 / _rtB -> B_4_16_0 ; if ( _rtB -> B_16_64_0 > _rtP -> P_11 ) { _rtB ->
B_4_18_0 = _rtP -> P_11 ; } else if ( _rtB -> B_16_64_0 < _rtP -> P_12 ) {
_rtB -> B_4_18_0 = _rtP -> P_12 ; } else { _rtB -> B_4_18_0 = _rtB ->
B_16_64_0 ; } _rtB -> B_4_19_0 = 1.0 / _rtB -> B_4_18_0 ; if ( _rtB ->
B_16_64_0 > _rtP -> P_13 ) { _rtB -> B_4_20_0 = _rtP -> P_13 ; } else if (
_rtB -> B_16_64_0 < _rtP -> P_14 ) { _rtB -> B_4_20_0 = _rtP -> P_14 ; } else
{ _rtB -> B_4_20_0 = _rtB -> B_16_64_0 ; } _rtB -> B_4_21_0 = 1.0 / _rtB ->
B_4_20_0 ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB -> B_4_22_0 [
isHit ] = 0.0 ; _rtB -> B_4_22_0 [ isHit ] += _rtP -> P_15 [ isHit ] * _rtB
-> B_16_58_0 [ 0 ] ; _rtB -> B_4_22_0 [ isHit ] += _rtP -> P_15 [ isHit + 3 ]
* _rtB -> B_16_58_0 [ 1 ] ; _rtB -> B_4_22_0 [ isHit ] += _rtP -> P_15 [
isHit + 6 ] * _rtB -> B_16_58_0 [ 2 ] ; _rtB -> B_4_23_0 [ isHit ] = _rtP ->
P_16 * _rtB -> B_4_22_0 [ isHit ] ; } Sim6_Subsystempi2delay ( S , _rtB ->
B_4_6_0_l , & _rtB -> B_4_23_0 [ 0 ] , _rtB -> B_16_62_0 , & _rtB ->
Subsystempi2delay_j , & _rtDW -> Subsystempi2delay_j ) ; Sim6_Subsystem1 ( S
, _rtB -> B_4_4_0_p , & _rtB -> B_4_23_0 [ 0 ] , _rtB -> B_16_62_0 , & _rtB
-> Subsystem1_m5 , & _rtDW -> Subsystem1_m5 ) ; if ( _rtB -> B_4_4_0_p != 0 )
{ _rtB -> B_4_26_0 [ 0 ] = _rtB -> Subsystem1_m5 . B_3_0_0 ; _rtB -> B_4_26_0
[ 1 ] = _rtB -> Subsystem1_m5 . B_3_1_0 ; } else { _rtB -> B_4_26_0 [ 0 ] =
_rtB -> Subsystempi2delay_j . B_2_0_0 ; _rtB -> B_4_26_0 [ 1 ] = _rtB ->
Subsystempi2delay_j . B_2_1_0 ; } if ( ssIsMajorTimeStep ( S ) != 0 ) {
srUpdateBC ( _rtDW -> AutomaticGainControl_SubsysRanBC ) ; } } if (
ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtX -> Integrator_CSTATE_c >= _rtP ->
P_132 ) { if ( _rtX -> Integrator_CSTATE_c != _rtP -> P_132 ) { _rtX ->
Integrator_CSTATE_c = _rtP -> P_132 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE_i = 3 ; } else if ( _rtX -> Integrator_CSTATE_c <= _rtP ->
P_133 ) { if ( _rtX -> Integrator_CSTATE_c != _rtP -> P_133 ) { _rtX ->
Integrator_CSTATE_c = _rtP -> P_133 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE_i = 4 ; } else { if ( _rtDW -> Integrator_MODE_i != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE_i = 0 ; } _rtB -> B_16_66_0 = _rtX -> Integrator_CSTATE_c ; }
else { _rtB -> B_16_66_0 = _rtX -> Integrator_CSTATE_c ; } { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> VariableTransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T appliedDelay ;
_rtB -> B_16_67_0 = Sim6_acc_rt_VTDelayfindtDInterpolate ( ( ( X_Sim6_T * )
ssGetContStates ( S ) ) -> VariableTransportDelay_CSTATE , * uBuffer , _rtDW
-> VariableTransportDelay_IWORK . CircularBufSize , _rtDW ->
VariableTransportDelay_IWORK . Head , _rtDW -> VariableTransportDelay_IWORK .
Tail , & _rtDW -> VariableTransportDelay_IWORK . Last , simTime , 0.0 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) , _rtP -> P_135 , & appliedDelay ) ; } _rtB -> B_16_68_0 =
_rtX -> integrator_CSTATE ; _rtB -> B_16_69_0 = ssGetT ( S ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> RelationalOperator_Mode_c = ( _rtB -> B_16_69_0 >= _rtB
-> B_16_8_0 ) ; } _rtB -> B_16_70_0 = _rtDW -> RelationalOperator_Mode_c ;
_rtB -> B_16_71_0 = _rtDW -> Memory_PreviousInput_a ; } if ( _rtB ->
B_16_70_0 ) { _rtB -> B_5_0_0 = _rtB -> B_16_68_0 - _rtB -> B_16_67_0 ; _rtB
-> B_5_1_0 = _rtB -> B_5_0_0 * _rtB -> B_16_64_0 ; _rtB -> B_16_73_0 = _rtB
-> B_5_1_0 ; } else { _rtB -> B_16_73_0 = _rtB -> B_16_71_0 ; } _rtB ->
B_16_74_0 = _rtB -> B_16_73_0 * _rtB -> B_4_17_0 ; _rtB -> B_16_75_0 = _rtP
-> P_138 * _rtB -> B_16_74_0 ; _rtB -> B_16_76_0 = _rtP -> P_139 * _rtB ->
B_16_74_0 ; _rtB -> B_16_77_0 = _rtP -> P_140 * _rtB -> B_16_74_0 ; _rtB ->
B_16_78_0 = 0.0 ; _rtB -> B_16_78_0 += _rtP -> P_142 * _rtX ->
TransferFcn_CSTATE ; _rtB -> B_16_78_0 += _rtP -> P_143 * _rtB -> B_16_77_0 ;
_rtB -> B_16_79_0 = ( _rtB -> B_16_75_0 + _rtB -> B_16_66_0 ) + _rtB ->
B_16_78_0 ; if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Saturation2_MODE =
_rtB -> B_16_79_0 >= _rtP -> P_144 ? 1 : _rtB -> B_16_79_0 > _rtP -> P_145 ?
0 : - 1 ; } _rtB -> B_16_80_0 = _rtDW -> Saturation2_MODE == 1 ? _rtP ->
P_144 : _rtDW -> Saturation2_MODE == - 1 ? _rtP -> P_145 : _rtB -> B_16_79_0
; _rtB -> B_16_81_0 = _rtP -> P_146 * _rtB -> B_16_80_0 ; if ( ( _rtDW ->
LastMajorTimeA >= ssGetTaskTime ( S , 0 ) ) && ( _rtDW -> LastMajorTimeB >=
ssGetTaskTime ( S , 0 ) ) ) { _rtB -> B_16_82_0 = _rtB -> B_16_81_0 ; } else
{ if ( ( ( _rtDW -> LastMajorTimeA < _rtDW -> LastMajorTimeB ) && ( _rtDW ->
LastMajorTimeB < ssGetTaskTime ( S , 0 ) ) ) || ( ( _rtDW -> LastMajorTimeA
>= _rtDW -> LastMajorTimeB ) && ( _rtDW -> LastMajorTimeA >= ssGetTaskTime (
S , 0 ) ) ) ) { rtb_B_16_42_0 = ssGetTaskTime ( S , 0 ) - _rtDW ->
LastMajorTimeB ; rtb_B_16_27_0 = _rtDW -> PrevYB ; } else { rtb_B_16_42_0 =
ssGetTaskTime ( S , 0 ) - _rtDW -> LastMajorTimeA ; rtb_B_16_27_0 = _rtDW ->
PrevYA ; } rtb_B_16_53_0 = rtb_B_16_42_0 * _rtP -> P_147 ; rtb_B_16_28_0 =
_rtB -> B_16_81_0 - rtb_B_16_27_0 ; if ( rtb_B_16_28_0 > rtb_B_16_53_0 ) {
_rtB -> B_16_82_0 = rtb_B_16_27_0 + rtb_B_16_53_0 ; } else { rtb_B_16_42_0 *=
_rtP -> P_148 ; if ( rtb_B_16_28_0 < rtb_B_16_42_0 ) { _rtB -> B_16_82_0 =
rtb_B_16_27_0 + rtb_B_16_42_0 ; } else { _rtB -> B_16_82_0 = _rtB ->
B_16_81_0 ; } } } _rtB -> B_16_83_0 = _rtX -> Integrator_x1_CSTATE ; _rtB ->
B_16_84_0 = _rtP -> P_150 * _rtB -> B_16_83_0 ; _rtB -> B_16_85_0 = _rtX ->
Integrator_x2_CSTATE ; _rtB -> B_16_86_0 = _rtP -> P_152 * _rtB -> B_16_85_0
; _rtB -> B_16_87_0 = _rtP -> P_153 * _rtB -> B_16_83_0 ; _rtB -> B_16_88_0 =
_rtP -> P_154 * _rtB -> B_16_85_0 ; _rtB -> B_16_89_0 = _rtB -> B_16_84_0 +
_rtB -> B_16_86_0 ; _rtB -> B_16_90_0 = _rtB -> B_16_87_0 + _rtB -> B_16_88_0
; _rtB -> B_16_91_0 = _rtP -> P_155 * _rtB -> B_16_82_0 ; _rtB -> B_16_92_0 =
_rtB -> B_16_89_0 + _rtB -> B_16_91_0 ; _rtB -> B_16_93_0 = _rtP -> P_156 *
_rtB -> B_16_82_0 ; _rtB -> B_16_94_0 = _rtB -> B_16_90_0 + _rtB -> B_16_93_0
; _rtB -> B_16_99_0 = ( _rtP -> P_157 * _rtB -> B_16_83_0 + _rtP -> P_158 *
_rtB -> B_16_85_0 ) + _rtP -> P_159 * _rtB -> B_16_82_0 ; if ( _rtB ->
B_16_64_0 > _rtP -> P_160 ) { _rtB -> B_16_100_0 = _rtP -> P_160 ; } else if
( _rtB -> B_16_64_0 < _rtP -> P_161 ) { _rtB -> B_16_100_0 = _rtP -> P_161 ;
} else { _rtB -> B_16_100_0 = _rtB -> B_16_64_0 ; } _rtB -> B_16_101_0 = 1.0
/ _rtB -> B_16_100_0 ; for ( isHit = 0 ; isHit < 3 ; isHit ++ ) { _rtB ->
B_16_102_0 [ isHit ] = 0.0 ; _rtB -> B_16_102_0 [ isHit ] += _rtP -> P_162 [
isHit ] * _rtB -> B_16_58_0 [ 0 ] ; _rtB -> B_16_102_0 [ isHit ] += _rtP ->
P_162 [ isHit + 3 ] * _rtB -> B_16_58_0 [ 1 ] ; _rtB -> B_16_102_0 [ isHit ]
+= _rtP -> P_162 [ isHit + 6 ] * _rtB -> B_16_58_0 [ 2 ] ; _rtB -> B_16_103_0
[ isHit ] = _rtP -> P_163 * _rtB -> B_16_102_0 [ isHit ] ; }
Sim6_Subsystempi2delay ( S , _rtB -> B_16_13_0 , & _rtB -> B_16_103_0 [ 0 ] ,
_rtB -> B_16_62_0 , & _rtB -> Subsystempi2delay , & _rtDW ->
Subsystempi2delay ) ; Sim6_Subsystem1 ( S , _rtB -> B_16_11_0 , & _rtB ->
B_16_103_0 [ 0 ] , _rtB -> B_16_62_0 , & _rtB -> Subsystem1 , & _rtDW ->
Subsystem1 ) ; if ( _rtB -> B_16_11_0 != 0 ) { _rtB -> B_16_106_0 [ 0 ] =
_rtB -> Subsystem1 . B_3_0_0 ; _rtB -> B_16_106_0 [ 1 ] = _rtB -> Subsystem1
. B_3_1_0 ; } else { _rtB -> B_16_106_0 [ 0 ] = _rtB -> Subsystempi2delay .
B_2_0_0 ; _rtB -> B_16_106_0 [ 1 ] = _rtB -> Subsystempi2delay . B_2_1_0 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && (
ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB -> B_16_20_0 > 0 ) { if ( !
_rtDW -> Subsystem1_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S
) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Subsystem1_MODE = true ; } } else if ( _rtDW -> Subsystem1_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW -> Subsystem1_MODE =
false ; } } if ( _rtDW -> Subsystem1_MODE ) { _rtB -> B_9_0_0 = _rtB ->
B_16_45_0 * muDoubleScalarCos ( _rtB -> B_16_62_0 ) - _rtB -> B_16_56_0 *
muDoubleScalarSin ( _rtB -> B_16_62_0 ) ; _rtB -> B_9_1_0 = _rtB -> B_16_45_0
* muDoubleScalarSin ( _rtB -> B_16_62_0 ) + _rtB -> B_16_56_0 *
muDoubleScalarCos ( _rtB -> B_16_62_0 ) ; if ( ssIsMajorTimeStep ( S ) != 0 )
{ srUpdateBC ( _rtDW -> Subsystem1_SubsysRanBC ) ; } } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) {
if ( _rtB -> B_16_22_0_n > 0 ) { if ( ! _rtDW -> Subsystempi2delay_MODE ) {
if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Subsystempi2delay_MODE = true ; } } else if ( _rtDW -> Subsystempi2delay_MODE
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW ->
Subsystempi2delay_MODE = false ; } } if ( _rtDW -> Subsystempi2delay_MODE ) {
_rtB -> B_8_0_0 = _rtB -> B_16_45_0 * muDoubleScalarSin ( _rtB -> B_16_62_0 )
+ _rtB -> B_16_56_0 * muDoubleScalarCos ( _rtB -> B_16_62_0 ) ; _rtB ->
B_8_1_0 = - _rtB -> B_16_45_0 * muDoubleScalarCos ( _rtB -> B_16_62_0 ) +
_rtB -> B_16_56_0 * muDoubleScalarSin ( _rtB -> B_16_62_0 ) ; if (
ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW ->
Subsystempi2delay_SubsysRanBC ) ; } } if ( _rtB -> B_16_20_0 != 0 ) { _rtB ->
B_16_109_0 [ 0 ] = _rtB -> B_9_0_0 ; _rtB -> B_16_109_0 [ 1 ] = _rtB ->
B_9_1_0 ; } else { _rtB -> B_16_109_0 [ 0 ] = _rtB -> B_8_0_0 ; _rtB ->
B_16_109_0 [ 1 ] = _rtB -> B_8_1_0 ; } _rtB -> B_16_110_0 [ 0 ] = _rtB ->
B_16_109_0 [ 0 ] ; _rtB -> B_16_110_0 [ 1 ] = _rtB -> B_16_109_0 [ 1 ] ; _rtB
-> B_16_110_0 [ 2 ] = _rtB -> B_16_0_0_m ; for ( isHit = 0 ; isHit < 3 ;
isHit ++ ) { _rtB -> B_16_111_0 [ isHit ] = 0.0 ; _rtB -> B_16_111_0 [ isHit
] += _rtP -> P_164 [ isHit ] * _rtB -> B_16_110_0 [ 0 ] ; _rtB -> B_16_111_0
[ isHit ] += _rtP -> P_164 [ isHit + 3 ] * _rtB -> B_16_110_0 [ 1 ] ; _rtB ->
B_16_111_0 [ isHit ] += _rtP -> P_164 [ isHit + 6 ] * _rtB -> B_16_110_0 [ 2
] ; _rtB -> B_16_112_0 [ isHit ] = _rtB -> B_16_111_0 [ isHit ] - _rtB ->
B_16_32_0 [ isHit ] ; } _rtB -> B_16_114_0 = 0.0 ; _rtB -> B_16_114_0 += _rtP
-> P_167 [ 0 ] * _rtX -> TransferFcn1_CSTATE [ 0 ] ; _rtB -> B_16_114_0 +=
_rtP -> P_167 [ 1 ] * _rtX -> TransferFcn1_CSTATE [ 1 ] ; _rtB -> B_16_116_0
= 0.0 ; _rtB -> B_16_116_0 += _rtP -> P_170 [ 0 ] * _rtX ->
TransferFcn2_CSTATE [ 0 ] ; _rtB -> B_16_116_0 += _rtP -> P_170 [ 1 ] * _rtX
-> TransferFcn2_CSTATE [ 1 ] ; _rtB -> B_16_118_0 = 0.0 ; _rtB -> B_16_118_0
+= _rtP -> P_173 [ 0 ] * _rtX -> TransferFcn_CSTATE_a [ 0 ] ; _rtB ->
B_16_118_0 += _rtP -> P_173 [ 1 ] * _rtX -> TransferFcn_CSTATE_a [ 1 ] ; _rtB
-> B_16_121_0 = ( ( _rtP -> P_168 * _rtB -> B_16_114_0 + _rtB -> B_16_118_0 )
+ _rtP -> P_171 * _rtB -> B_16_116_0 ) * _rtP -> P_174 + _rtP -> P_165 * _rtB
-> B_16_112_0 [ 2 ] ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ _rtB -> B_16_123_0 = _rtP -> P_175 ; } rtb_B_16_27_0 = ssGetT ( S ) + _rtB
-> B_16_123_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_16_125_0 = _rtP -> P_176 ; } rtb_B_16_27_0 = look1_pbinlxpw ( _rtP
-> P_177 * muDoubleScalarRem ( rtb_B_16_27_0 , _rtB -> B_16_125_0 ) , _rtP ->
P_179 , _rtP -> P_178 , & _rtDW -> m_bpIndex , 2U ) ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_16_129_0 = _rtP -> P_180 ; } _rtB
-> B_16_132_0 = ( ( rtb_B_16_27_0 - _rtB -> B_16_129_0 ) * _rtB -> B_16_16_0
+ _rtB -> B_16_14_0_c [ 0 ] ) + _rtB -> B_16_16_0 ; _rtB -> B_16_134_0 = 0.0
; _rtB -> B_16_134_0 += _rtP -> P_183 [ 0 ] * _rtX -> TransferFcn_CSTATE_n [
0 ] ; _rtB -> B_16_134_0 += _rtP -> P_183 [ 1 ] * _rtX ->
TransferFcn_CSTATE_n [ 1 ] ; _rtB -> B_16_135_0 = 0.0 ; _rtB -> B_16_135_0 +=
_rtP -> P_185 [ 0 ] * _rtX -> TransferFcn1_CSTATE_f [ 0 ] ; _rtB ->
B_16_135_0 += _rtP -> P_185 [ 1 ] * _rtX -> TransferFcn1_CSTATE_f [ 1 ] ;
_rtB -> B_16_137_0 = 0.0 ; _rtB -> B_16_137_0 += _rtP -> P_188 [ 0 ] * _rtX
-> TransferFcn2_CSTATE_h [ 0 ] ; _rtB -> B_16_137_0 += _rtP -> P_188 [ 1 ] *
_rtX -> TransferFcn2_CSTATE_h [ 1 ] ; _rtB -> B_16_141_0 = ( ( _rtP -> P_186
* _rtB -> B_16_135_0 + _rtB -> B_16_134_0 ) + _rtP -> P_189 * _rtB ->
B_16_137_0 ) * _rtP -> P_190 + _rtP -> P_181 * _rtB -> B_16_112_0 [ 0 ] ;
_rtB -> B_16_143_0 = 0.0 ; _rtB -> B_16_143_0 += _rtP -> P_193 [ 0 ] * _rtX
-> TransferFcn_CSTATE_k [ 0 ] ; _rtB -> B_16_143_0 += _rtP -> P_193 [ 1 ] *
_rtX -> TransferFcn_CSTATE_k [ 1 ] ; _rtB -> B_16_144_0 = 0.0 ; _rtB ->
B_16_144_0 += _rtP -> P_195 [ 0 ] * _rtX -> TransferFcn1_CSTATE_n [ 0 ] ;
_rtB -> B_16_144_0 += _rtP -> P_195 [ 1 ] * _rtX -> TransferFcn1_CSTATE_n [ 1
] ; _rtB -> B_16_146_0 = 0.0 ; _rtB -> B_16_146_0 += _rtP -> P_198 [ 0 ] *
_rtX -> TransferFcn2_CSTATE_l [ 0 ] ; _rtB -> B_16_146_0 += _rtP -> P_198 [ 1
] * _rtX -> TransferFcn2_CSTATE_l [ 1 ] ; _rtB -> B_16_150_0 = ( ( _rtP ->
P_196 * _rtB -> B_16_144_0 + _rtB -> B_16_143_0 ) + _rtP -> P_199 * _rtB ->
B_16_146_0 ) * _rtP -> P_200 + _rtP -> P_191 * _rtB -> B_16_112_0 [ 1 ] ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> RelationalOperator2_Mode [ 0 ] = (
_rtB -> B_16_141_0 >= _rtB -> B_16_132_0 ) ; _rtDW ->
RelationalOperator2_Mode [ 1 ] = ( _rtB -> B_16_150_0 >= _rtB -> B_16_132_0 )
; _rtDW -> RelationalOperator2_Mode [ 2 ] = ( _rtB -> B_16_121_0 >= _rtB ->
B_16_132_0 ) ; } _rtB -> B_16_151_0 [ 0 ] = _rtDW -> RelationalOperator2_Mode
[ 0 ] ; _rtB -> B_16_151_0 [ 1 ] = _rtDW -> RelationalOperator2_Mode [ 1 ] ;
_rtB -> B_16_151_0 [ 2 ] = _rtDW -> RelationalOperator2_Mode [ 2 ] ; } _rtB
-> B_16_153_0 [ 0 ] = _rtB -> B_16_151_0 [ 0 ] ; _rtB -> B_16_153_0 [ 1 ] = !
_rtB -> B_16_151_0 [ 0 ] ; _rtB -> B_16_153_0 [ 2 ] = _rtB -> B_16_151_0 [ 1
] ; _rtB -> B_16_153_0 [ 3 ] = ! _rtB -> B_16_151_0 [ 1 ] ; _rtB ->
B_16_153_0 [ 4 ] = _rtB -> B_16_151_0 [ 2 ] ; _rtB -> B_16_153_0 [ 5 ] = !
_rtB -> B_16_151_0 [ 2 ] ; isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit
!= 0 ) { ssCallAccelRunBlock ( S , 16 , 154 , SS_CALL_MDL_OUTPUTS ) ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
16 , 155 , SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID6 ( SimStruct * S , int_T tid ) { B_Sim6_T * _rtB ; DW_Sim6_T *
_rtDW ; P_Sim6_T * _rtP ; _rtDW = ( ( DW_Sim6_T * ) ssGetRootDWork ( S ) ) ;
_rtP = ( ( P_Sim6_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Sim6_T * )
_ssGetModelBlockIO ( S ) ) ; _rtB -> B_16_0_0_m = _rtP -> P_201 ; _rtB ->
B_16_1_0 = _rtP -> P_202 ; _rtB -> B_16_2_0 = _rtP -> P_203 ; _rtB ->
B_16_3_0 = _rtP -> P_204 ; _rtB -> B_16_4_0 = _rtP -> P_205 ; _rtB ->
B_4_0_0_g = _rtP -> P_17 ; _rtB -> B_4_1_0_g = _rtP -> P_18 ; _rtB ->
B_4_4_0_p = ( uint8_T ) ( _rtP -> P_19 == _rtP -> P_20 ) ; _rtB -> B_4_6_0_l
= ( uint8_T ) ( _rtP -> P_19 == _rtP -> P_21 ) ; if ( ssIsMajorTimeStep ( S )
!= 0 ) { srUpdateBC ( _rtDW -> AutomaticGainControl_SubsysRanBC ) ; } _rtB ->
B_16_6_0 = _rtP -> P_206 ; _rtB -> B_16_7_0 = _rtP -> P_207 ; _rtB ->
B_16_8_0 = _rtP -> P_208 ; _rtB -> B_16_11_0 = ( uint8_T ) ( _rtP -> P_209 ==
_rtP -> P_210 ) ; _rtB -> B_16_13_0 = ( uint8_T ) ( _rtP -> P_209 == _rtP ->
P_211 ) ; _rtB -> B_16_14_0_c [ 0 ] = _rtP -> P_212 [ 0 ] ; _rtB ->
B_16_14_0_c [ 1 ] = _rtP -> P_212 [ 1 ] ; _rtB -> B_16_16_0 = ( _rtB ->
B_16_14_0_c [ 1 ] - _rtB -> B_16_14_0_c [ 0 ] ) * _rtP -> P_213 ; _rtB ->
B_16_17_0 = _rtP -> P_214 ; _rtB -> B_16_20_0 = ( uint8_T ) ( _rtP -> P_215
== _rtP -> P_216 ) ; _rtB -> B_16_22_0_n = ( uint8_T ) ( _rtP -> P_215 ==
_rtP -> P_217 ) ; _rtB -> B_16_24_0 = _rtP -> P_219 * _rtP -> P_218 ; _rtB ->
B_16_26_0 = _rtP -> P_221 * _rtP -> P_220 ; _rtB -> B_10_1_0 = _rtP -> P_35 *
_rtP -> P_34 ; switch ( ( int32_T ) ( _rtP -> P_36 + _rtP -> P_37 ) ) { case
1 : _rtB -> B_10_8_0 [ 0 ] = _rtP -> P_38 [ 0 ] ; _rtB -> B_10_8_0 [ 1 ] =
_rtP -> P_38 [ 1 ] ; _rtB -> B_10_8_0 [ 2 ] = _rtP -> P_38 [ 2 ] ; break ;
case 2 : _rtB -> B_10_8_0 [ 0 ] = _rtP -> P_39 [ 0 ] ; _rtB -> B_10_8_0 [ 1 ]
= _rtP -> P_39 [ 1 ] ; _rtB -> B_10_8_0 [ 2 ] = _rtP -> P_39 [ 2 ] ; break ;
default : _rtB -> B_10_8_0 [ 0 ] = _rtP -> P_40 [ 0 ] ; _rtB -> B_10_8_0 [ 1
] = _rtP -> P_40 [ 1 ] ; _rtB -> B_10_8_0 [ 2 ] = _rtP -> P_40 [ 2 ] ; break
; } _rtB -> B_10_9_0 = _rtP -> P_41 ; _rtB -> B_10_11_0 = _rtP -> P_43 * _rtP
-> P_42 ; switch ( ( int32_T ) ( _rtP -> P_44 + _rtP -> P_45 ) ) { case 1 :
_rtB -> B_10_18_0 [ 0 ] = _rtP -> P_46 [ 0 ] ; _rtB -> B_10_18_0 [ 1 ] = _rtP
-> P_46 [ 1 ] ; _rtB -> B_10_18_0 [ 2 ] = _rtP -> P_46 [ 2 ] ; break ; case 2
: _rtB -> B_10_18_0 [ 0 ] = _rtP -> P_47 [ 0 ] ; _rtB -> B_10_18_0 [ 1 ] =
_rtP -> P_47 [ 1 ] ; _rtB -> B_10_18_0 [ 2 ] = _rtP -> P_47 [ 2 ] ; break ;
default : _rtB -> B_10_18_0 [ 0 ] = _rtP -> P_48 [ 0 ] ; _rtB -> B_10_18_0 [
1 ] = _rtP -> P_48 [ 1 ] ; _rtB -> B_10_18_0 [ 2 ] = _rtP -> P_48 [ 2 ] ;
break ; } _rtB -> B_10_19_0 = _rtP -> P_49 ; if ( ssIsMajorTimeStep ( S ) !=
0 ) { srUpdateBC ( _rtDW -> HarmonicGenerator_SubsysRanBC ) ; } _rtB ->
B_16_28_0 [ 0 ] = _rtP -> P_222 [ 0 ] ; _rtB -> B_16_28_0 [ 1 ] = _rtP ->
P_222 [ 1 ] ; _rtB -> B_16_28_0 [ 2 ] = _rtP -> P_222 [ 2 ] ; _rtB ->
B_15_1_0_c = _rtP -> P_72 ; _rtB -> B_15_4_0 = _rtP -> P_75 ; _rtB ->
B_15_5_0 = _rtP -> P_76 ; _rtB -> B_15_8_0_j = ( _rtP -> P_78 == _rtP -> P_71
) ; _rtB -> B_15_9_0 = ( _rtP -> P_78 == _rtP -> P_73 ) ; _rtB -> B_15_10_0 =
( _rtP -> P_78 == _rtP -> P_74 ) ; _rtB -> B_15_11_0_b = _rtP -> P_79 ; _rtB
-> B_15_12_0 = ( _rtB -> B_15_11_0_b == _rtP -> P_77 ) ; _rtB -> B_15_14_0_p
= _rtP -> P_81 ; _rtB -> B_15_17_0_c = _rtP -> P_84 ; _rtB -> B_15_18_0 =
_rtP -> P_85 ; _rtB -> B_15_20_0_f = _rtP -> P_87 * _rtP -> P_86 ; _rtB ->
B_15_22_0 = ( _rtB -> B_15_11_0_b == _rtP -> P_83 ) ; if ( _rtB ->
B_15_11_0_b == _rtP -> P_80 ) { _rtB -> B_15_24_0 = _rtP -> P_88 ; } else {
_rtB -> B_15_24_0 = _rtP -> P_82 ; } _rtB -> B_15_25_0 = _rtP -> P_89 ; _rtB
-> B_15_26_0 = _rtP -> P_90 ; if ( ssIsMajorTimeStep ( S ) != 0 ) {
srUpdateBC ( _rtDW -> Signalgenerator_SubsysRanBC ) ; } _rtB -> B_16_30_0 =
_rtP -> P_223 ; _rtB -> B_16_31_0 = _rtP -> P_224 ; _rtB -> B_16_32_0_k =
_rtP -> P_225 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_Sim6_T * _rtB ;
DW_Sim6_T * _rtDW ; P_Sim6_T * _rtP ; XDis_Sim6_T * _rtXdis ; int32_T isHit ;
_rtDW = ( ( DW_Sim6_T * ) ssGetRootDWork ( S ) ) ; _rtXdis = ( ( XDis_Sim6_T
* ) ssGetContStateDisabled ( S ) ) ; _rtP = ( ( P_Sim6_T * ) ssGetModelRtp (
S ) ) ; _rtB = ( ( B_Sim6_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { if ( _rtDW ->
Signalgenerator_MODE ) { isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit !=
0 ) { _rtDW -> DiscreteTimeIntegrator_DSTATE += _rtP -> P_57 * _rtB ->
B_15_14_0 ; _rtDW -> DiscreteTimeIntegrator1_DSTATE += _rtP -> P_65 * _rtB ->
B_15_20_0 ; _rtDW -> UnitDelay_DSTATE = _rtB -> B_15_11_0 ; } }
ssCallAccelRunBlock ( S , 16 , 15 , SS_CALL_MDL_UPDATE ) ; _rtDW ->
Delay11_DSTATE = _rtB -> B_16_39_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtDW -> FFInt_DSTATE += _rtP -> P_118 * _rtB ->
B_16_41_0 ; } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { _rtDW
-> Delay11_DSTATE_d = _rtB -> B_16_50_0 ; _rtDW -> FFInt_DSTATE_g += _rtP ->
P_123 * _rtB -> B_16_52_0 ; } _rtDW -> Integrator_IWORK = 0 ; switch ( _rtDW
-> Integrator_MODE ) { case 3 : if ( _rtB -> B_16_80_0 < 0.0 ) { _rtDW ->
Integrator_MODE = 1 ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
break ; case 4 : if ( _rtB -> B_16_80_0 > 0.0 ) { _rtDW -> Integrator_MODE =
2 ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } break ; } _rtXdis ->
Integrator_CSTATE = ( ( _rtDW -> Integrator_MODE == 3 ) || ( _rtDW ->
Integrator_MODE == 4 ) ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { _rtDW -> Memory_PreviousInput = _rtB -> B_16_99_0 ; } if ( _rtDW ->
AutomaticGainControl_MODE ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> VariableTransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; _rtDW -> VariableTransportDelay_IWORK_f . Head = ( ( _rtDW ->
VariableTransportDelay_IWORK_f . Head < ( _rtDW ->
VariableTransportDelay_IWORK_f . CircularBufSize - 1 ) ) ? ( _rtDW ->
VariableTransportDelay_IWORK_f . Head + 1 ) : 0 ) ; if ( _rtDW ->
VariableTransportDelay_IWORK_f . Head == _rtDW ->
VariableTransportDelay_IWORK_f . Tail ) { if ( !
Sim6_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay_IWORK_f . CircularBufSize , & _rtDW ->
VariableTransportDelay_IWORK_f . Tail , & _rtDW ->
VariableTransportDelay_IWORK_f . Head , & _rtDW ->
VariableTransportDelay_IWORK_f . Last , simTime - _rtP -> P_1 , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 1 , & _rtDW -> VariableTransportDelay_IWORK_f .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "vtdelay memory allocation error"
) ; return ; } } ( * uBuffer + _rtDW -> VariableTransportDelay_IWORK_f .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_f . Head ] =
simTime ; ( * uBuffer + 2 * _rtDW -> VariableTransportDelay_IWORK_f .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_f . Head ] = ( (
X_Sim6_T * ) ssGetContStates ( S ) ) -> VariableTransportDelay_CSTATE_g ; ( *
uBuffer ) [ _rtDW -> VariableTransportDelay_IWORK_f . Head ] = _rtB ->
B_4_1_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW
-> Memory_PreviousInput_l = _rtB -> B_4_6_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> VariableTransportDelay_PWORK_c . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> VariableTransportDelay_IWORK_j .
Head = ( ( _rtDW -> VariableTransportDelay_IWORK_j . Head < ( _rtDW ->
VariableTransportDelay_IWORK_j . CircularBufSize - 1 ) ) ? ( _rtDW ->
VariableTransportDelay_IWORK_j . Head + 1 ) : 0 ) ; if ( _rtDW ->
VariableTransportDelay_IWORK_j . Head == _rtDW ->
VariableTransportDelay_IWORK_j . Tail ) { if ( !
Sim6_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay_IWORK_j . CircularBufSize , & _rtDW ->
VariableTransportDelay_IWORK_j . Tail , & _rtDW ->
VariableTransportDelay_IWORK_j . Head , & _rtDW ->
VariableTransportDelay_IWORK_j . Last , simTime - _rtP -> P_5 , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 1 , & _rtDW -> VariableTransportDelay_IWORK_j .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "vtdelay memory allocation error"
) ; return ; } } ( * uBuffer + _rtDW -> VariableTransportDelay_IWORK_j .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_j . Head ] =
simTime ; ( * uBuffer + 2 * _rtDW -> VariableTransportDelay_IWORK_j .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_j . Head ] = ( (
X_Sim6_T * ) ssGetContStates ( S ) ) -> VariableTransportDelay_CSTATE_e ; ( *
uBuffer ) [ _rtDW -> VariableTransportDelay_IWORK_j . Head ] = _rtB ->
B_4_8_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW
-> Memory_PreviousInput_o = _rtB -> B_4_13_0 ; } } switch ( _rtDW ->
Integrator_MODE_i ) { case 3 : if ( _rtB -> B_16_76_0 < 0.0 ) { _rtDW ->
Integrator_MODE_i = 1 ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
break ; case 4 : if ( _rtB -> B_16_76_0 > 0.0 ) { _rtDW -> Integrator_MODE_i
= 2 ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } break ; } _rtXdis
-> Integrator_CSTATE_c = ( ( _rtDW -> Integrator_MODE_i == 3 ) || ( _rtDW ->
Integrator_MODE_i == 4 ) ) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
VariableTransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
S ) ; _rtDW -> VariableTransportDelay_IWORK . Head = ( ( _rtDW ->
VariableTransportDelay_IWORK . Head < ( _rtDW -> VariableTransportDelay_IWORK
. CircularBufSize - 1 ) ) ? ( _rtDW -> VariableTransportDelay_IWORK . Head +
1 ) : 0 ) ; if ( _rtDW -> VariableTransportDelay_IWORK . Head == _rtDW ->
VariableTransportDelay_IWORK . Tail ) { if ( !
Sim6_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize , & _rtDW ->
VariableTransportDelay_IWORK . Tail , & _rtDW -> VariableTransportDelay_IWORK
. Head , & _rtDW -> VariableTransportDelay_IWORK . Last , simTime - _rtP ->
P_134 , uBuffer , ( boolean_T ) 0 , ( boolean_T ) 1 , & _rtDW ->
VariableTransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"vtdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = simTime ; ( * uBuffer + 2 * _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = ( ( X_Sim6_T * ) ssGetContStates ( S
) ) -> VariableTransportDelay_CSTATE ; ( * uBuffer ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = _rtB -> B_16_68_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_a = _rtB -> B_16_73_0 ; } if ( _rtDW -> LastMajorTimeA
== ( rtInf ) ) { _rtDW -> LastMajorTimeA = ssGetTaskTime ( S , 0 ) ; _rtDW ->
PrevYA = _rtB -> B_16_82_0 ; } else if ( _rtDW -> LastMajorTimeB == ( rtInf )
) { _rtDW -> LastMajorTimeB = ssGetTaskTime ( S , 0 ) ; _rtDW -> PrevYB =
_rtB -> B_16_82_0 ; } else if ( _rtDW -> LastMajorTimeA < _rtDW ->
LastMajorTimeB ) { _rtDW -> LastMajorTimeA = ssGetTaskTime ( S , 0 ) ; _rtDW
-> PrevYA = _rtB -> B_16_82_0 ; } else { _rtDW -> LastMajorTimeB =
ssGetTaskTime ( S , 0 ) ; _rtDW -> PrevYB = _rtB -> B_16_82_0 ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID6 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_Sim6_T * _rtB ; DW_Sim6_T *
_rtDW ; P_Sim6_T * _rtP ; XDis_Sim6_T * _rtXdis ; XDot_Sim6_T * _rtXdot ;
X_Sim6_T * _rtX ; _rtDW = ( ( DW_Sim6_T * ) ssGetRootDWork ( S ) ) ; _rtXdis
= ( ( XDis_Sim6_T * ) ssGetContStateDisabled ( S ) ) ; _rtXdot = ( (
XDot_Sim6_T * ) ssGetdX ( S ) ) ; _rtX = ( ( X_Sim6_T * ) ssGetContStates ( S
) ) ; _rtP = ( ( P_Sim6_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Sim6_T * )
_ssGetModelBlockIO ( S ) ) ; if ( _rtXdis -> Integrator_CSTATE ) { _rtXdot ->
Integrator_CSTATE = 0.0 ; } else { _rtXdot -> Integrator_CSTATE = _rtB ->
B_16_80_0 ; } if ( _rtDW -> AutomaticGainControl_MODE ) { { real_T
instantDelay ; instantDelay = _rtB -> B_4_19_0 ; if ( instantDelay > _rtP ->
P_1 ) { instantDelay = _rtP -> P_1 ; } if ( instantDelay < 0.0 ) { ( (
XDot_Sim6_T * ) ssGetdX ( S ) ) -> VariableTransportDelay_CSTATE_g = 0 ; }
else { ( ( XDot_Sim6_T * ) ssGetdX ( S ) ) -> VariableTransportDelay_CSTATE_g
= 1.0 / instantDelay ; } } _rtXdot -> integrator_CSTATE_o = _rtB -> B_4_26_0
[ 0 ] ; { real_T instantDelay ; instantDelay = _rtB -> B_4_21_0 ; if (
instantDelay > _rtP -> P_5 ) { instantDelay = _rtP -> P_5 ; } if (
instantDelay < 0.0 ) { ( ( XDot_Sim6_T * ) ssGetdX ( S ) ) ->
VariableTransportDelay_CSTATE_e = 0 ; } else { ( ( XDot_Sim6_T * ) ssGetdX (
S ) ) -> VariableTransportDelay_CSTATE_e = 1.0 / instantDelay ; } } _rtXdot
-> integrator_CSTATE_h = _rtB -> B_4_26_0 [ 1 ] ; } else { { real_T * dx ;
int_T i ; dx = & ( ( ( XDot_Sim6_T * ) ssGetdX ( S ) ) ->
VariableTransportDelay_CSTATE_g ) ; for ( i = 0 ; i < 4 ; i ++ ) { dx [ i ] =
0.0 ; } } } if ( _rtXdis -> Integrator_CSTATE_c ) { _rtXdot ->
Integrator_CSTATE_c = 0.0 ; } else { _rtXdot -> Integrator_CSTATE_c = _rtB ->
B_16_76_0 ; } { real_T instantDelay ; instantDelay = _rtB -> B_16_101_0 ; if
( instantDelay > _rtP -> P_134 ) { instantDelay = _rtP -> P_134 ; } if (
instantDelay < 0.0 ) { ( ( XDot_Sim6_T * ) ssGetdX ( S ) ) ->
VariableTransportDelay_CSTATE = 0 ; } else { ( ( XDot_Sim6_T * ) ssGetdX ( S
) ) -> VariableTransportDelay_CSTATE = 1.0 / instantDelay ; } } _rtXdot ->
integrator_CSTATE = _rtB -> B_16_106_0 [ 1 ] ; _rtXdot -> TransferFcn_CSTATE
= 0.0 ; _rtXdot -> TransferFcn_CSTATE += _rtP -> P_141 * _rtX ->
TransferFcn_CSTATE ; _rtXdot -> TransferFcn_CSTATE += _rtB -> B_16_77_0 ;
_rtXdot -> Integrator_x1_CSTATE = _rtB -> B_16_92_0 ; _rtXdot ->
Integrator_x2_CSTATE = _rtB -> B_16_94_0 ; _rtXdot -> TransferFcn1_CSTATE [ 0
] = 0.0 ; _rtXdot -> TransferFcn1_CSTATE [ 0 ] += _rtP -> P_166 [ 0 ] * _rtX
-> TransferFcn1_CSTATE [ 0 ] ; _rtXdot -> TransferFcn1_CSTATE [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn1_CSTATE [ 0 ] += _rtP -> P_166 [ 1 ] * _rtX ->
TransferFcn1_CSTATE [ 1 ] ; _rtXdot -> TransferFcn1_CSTATE [ 1 ] += _rtX ->
TransferFcn1_CSTATE [ 0 ] ; _rtXdot -> TransferFcn1_CSTATE [ 0 ] += _rtB ->
B_16_112_0 [ 2 ] ; _rtXdot -> TransferFcn2_CSTATE [ 0 ] = 0.0 ; _rtXdot ->
TransferFcn2_CSTATE [ 0 ] += _rtP -> P_169 [ 0 ] * _rtX ->
TransferFcn2_CSTATE [ 0 ] ; _rtXdot -> TransferFcn2_CSTATE [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn2_CSTATE [ 0 ] += _rtP -> P_169 [ 1 ] * _rtX ->
TransferFcn2_CSTATE [ 1 ] ; _rtXdot -> TransferFcn2_CSTATE [ 1 ] += _rtX ->
TransferFcn2_CSTATE [ 0 ] ; _rtXdot -> TransferFcn2_CSTATE [ 0 ] += _rtB ->
B_16_112_0 [ 2 ] ; _rtXdot -> TransferFcn_CSTATE_a [ 0 ] = 0.0 ; _rtXdot ->
TransferFcn_CSTATE_a [ 0 ] += _rtP -> P_172 [ 0 ] * _rtX ->
TransferFcn_CSTATE_a [ 0 ] ; _rtXdot -> TransferFcn_CSTATE_a [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn_CSTATE_a [ 0 ] += _rtP -> P_172 [ 1 ] * _rtX ->
TransferFcn_CSTATE_a [ 1 ] ; _rtXdot -> TransferFcn_CSTATE_a [ 1 ] += _rtX ->
TransferFcn_CSTATE_a [ 0 ] ; _rtXdot -> TransferFcn_CSTATE_a [ 0 ] += _rtB ->
B_16_112_0 [ 2 ] ; _rtXdot -> TransferFcn_CSTATE_n [ 0 ] = 0.0 ; _rtXdot ->
TransferFcn_CSTATE_n [ 0 ] += _rtP -> P_182 [ 0 ] * _rtX ->
TransferFcn_CSTATE_n [ 0 ] ; _rtXdot -> TransferFcn_CSTATE_n [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn_CSTATE_n [ 0 ] += _rtP -> P_182 [ 1 ] * _rtX ->
TransferFcn_CSTATE_n [ 1 ] ; _rtXdot -> TransferFcn_CSTATE_n [ 1 ] += _rtX ->
TransferFcn_CSTATE_n [ 0 ] ; _rtXdot -> TransferFcn_CSTATE_n [ 0 ] += _rtB ->
B_16_112_0 [ 0 ] ; _rtXdot -> TransferFcn1_CSTATE_f [ 0 ] = 0.0 ; _rtXdot ->
TransferFcn1_CSTATE_f [ 0 ] += _rtP -> P_184 [ 0 ] * _rtX ->
TransferFcn1_CSTATE_f [ 0 ] ; _rtXdot -> TransferFcn1_CSTATE_f [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn1_CSTATE_f [ 0 ] += _rtP -> P_184 [ 1 ] * _rtX ->
TransferFcn1_CSTATE_f [ 1 ] ; _rtXdot -> TransferFcn1_CSTATE_f [ 1 ] += _rtX
-> TransferFcn1_CSTATE_f [ 0 ] ; _rtXdot -> TransferFcn1_CSTATE_f [ 0 ] +=
_rtB -> B_16_112_0 [ 0 ] ; _rtXdot -> TransferFcn2_CSTATE_h [ 0 ] = 0.0 ;
_rtXdot -> TransferFcn2_CSTATE_h [ 0 ] += _rtP -> P_187 [ 0 ] * _rtX ->
TransferFcn2_CSTATE_h [ 0 ] ; _rtXdot -> TransferFcn2_CSTATE_h [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn2_CSTATE_h [ 0 ] += _rtP -> P_187 [ 1 ] * _rtX ->
TransferFcn2_CSTATE_h [ 1 ] ; _rtXdot -> TransferFcn2_CSTATE_h [ 1 ] += _rtX
-> TransferFcn2_CSTATE_h [ 0 ] ; _rtXdot -> TransferFcn2_CSTATE_h [ 0 ] +=
_rtB -> B_16_112_0 [ 0 ] ; _rtXdot -> TransferFcn_CSTATE_k [ 0 ] = 0.0 ;
_rtXdot -> TransferFcn_CSTATE_k [ 0 ] += _rtP -> P_192 [ 0 ] * _rtX ->
TransferFcn_CSTATE_k [ 0 ] ; _rtXdot -> TransferFcn_CSTATE_k [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn_CSTATE_k [ 0 ] += _rtP -> P_192 [ 1 ] * _rtX ->
TransferFcn_CSTATE_k [ 1 ] ; _rtXdot -> TransferFcn_CSTATE_k [ 1 ] += _rtX ->
TransferFcn_CSTATE_k [ 0 ] ; _rtXdot -> TransferFcn_CSTATE_k [ 0 ] += _rtB ->
B_16_112_0 [ 1 ] ; _rtXdot -> TransferFcn1_CSTATE_n [ 0 ] = 0.0 ; _rtXdot ->
TransferFcn1_CSTATE_n [ 0 ] += _rtP -> P_194 [ 0 ] * _rtX ->
TransferFcn1_CSTATE_n [ 0 ] ; _rtXdot -> TransferFcn1_CSTATE_n [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn1_CSTATE_n [ 0 ] += _rtP -> P_194 [ 1 ] * _rtX ->
TransferFcn1_CSTATE_n [ 1 ] ; _rtXdot -> TransferFcn1_CSTATE_n [ 1 ] += _rtX
-> TransferFcn1_CSTATE_n [ 0 ] ; _rtXdot -> TransferFcn1_CSTATE_n [ 0 ] +=
_rtB -> B_16_112_0 [ 1 ] ; _rtXdot -> TransferFcn2_CSTATE_l [ 0 ] = 0.0 ;
_rtXdot -> TransferFcn2_CSTATE_l [ 0 ] += _rtP -> P_197 [ 0 ] * _rtX ->
TransferFcn2_CSTATE_l [ 0 ] ; _rtXdot -> TransferFcn2_CSTATE_l [ 1 ] = 0.0 ;
_rtXdot -> TransferFcn2_CSTATE_l [ 0 ] += _rtP -> P_197 [ 1 ] * _rtX ->
TransferFcn2_CSTATE_l [ 1 ] ; _rtXdot -> TransferFcn2_CSTATE_l [ 1 ] += _rtX
-> TransferFcn2_CSTATE_l [ 0 ] ; _rtXdot -> TransferFcn2_CSTATE_l [ 0 ] +=
_rtB -> B_16_112_0 [ 1 ] ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_Sim6_T * _rtB ; DW_Sim6_T
* _rtDW ; P_Sim6_T * _rtP ; X_Sim6_T * _rtX ; ZCV_Sim6_T * _rtZCSV ; _rtDW =
( ( DW_Sim6_T * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( ( ZCV_Sim6_T * )
ssGetSolverZcSignalVector ( S ) ) ; _rtX = ( ( X_Sim6_T * ) ssGetContStates (
S ) ) ; _rtP = ( ( P_Sim6_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Sim6_T *
) _ssGetModelBlockIO ( S ) ) ; _rtZCSV -> P10kW_StepTime_ZC = ssGetT ( S ) -
_rtP -> P_104 ; _rtZCSV -> RelationalOperator_RelopInput_ZC = _rtX ->
Integrator_CSTATE - _rtB -> B_16_7_0 ; switch ( _rtDW -> Integrator_MODE ) {
case 1 : _rtZCSV -> Integrator_IntgUpLimit_ZC = 0.0 ; _rtZCSV ->
Integrator_IntgLoLimit_ZC = _rtP -> P_127 - _rtP -> P_128 ; break ; case 2 :
_rtZCSV -> Integrator_IntgUpLimit_ZC = _rtP -> P_128 - _rtP -> P_127 ;
_rtZCSV -> Integrator_IntgLoLimit_ZC = 0.0 ; break ; default : _rtZCSV ->
Integrator_IntgUpLimit_ZC = _rtX -> Integrator_CSTATE - _rtP -> P_127 ;
_rtZCSV -> Integrator_IntgLoLimit_ZC = _rtX -> Integrator_CSTATE - _rtP ->
P_128 ; break ; } if ( ( _rtDW -> Integrator_MODE == 3 ) || ( _rtDW ->
Integrator_MODE == 4 ) ) { _rtZCSV -> Integrator_LeaveSaturate_ZC = _rtB ->
B_16_80_0 ; } else { _rtZCSV -> Integrator_LeaveSaturate_ZC = 0.0 ; } _rtZCSV
-> HitCrossing_HitNoOutput_ZC = _rtB -> B_16_62_0 - _rtP -> P_129 ; if (
_rtDW -> AutomaticGainControl_MODE ) { _rtZCSV ->
RelationalOperator_RelopInput_ZC_m = _rtB -> B_4_2_0 - _rtB -> B_4_0_0_g ;
_rtZCSV -> RelationalOperator_RelopInput_ZC_e = _rtB -> B_4_9_0 - _rtB ->
B_4_1_0_g ; _rtZCSV -> Saturation_UprLim_ZC = _rtB -> B_4_15_0 - _rtP -> P_9
; _rtZCSV -> Saturation_LwrLim_ZC = _rtB -> B_4_15_0 - _rtP -> P_10 ; } else
{ { real_T * zcsv = & ( ( ( ZCV_Sim6_T * ) ssGetSolverZcSignalVector ( S ) )
-> RelationalOperator_RelopInput_ZC_m ) ; int_T i ; for ( i = 0 ; i < 4 ; i
++ ) { zcsv [ i ] = 0.0 ; } } } switch ( _rtDW -> Integrator_MODE_i ) { case
1 : _rtZCSV -> Integrator_IntgUpLimit_ZC_d = 0.0 ; _rtZCSV ->
Integrator_IntgLoLimit_ZC_d = _rtP -> P_132 - _rtP -> P_133 ; break ; case 2
: _rtZCSV -> Integrator_IntgUpLimit_ZC_d = _rtP -> P_133 - _rtP -> P_132 ;
_rtZCSV -> Integrator_IntgLoLimit_ZC_d = 0.0 ; break ; default : _rtZCSV ->
Integrator_IntgUpLimit_ZC_d = _rtX -> Integrator_CSTATE_c - _rtP -> P_132 ;
_rtZCSV -> Integrator_IntgLoLimit_ZC_d = _rtX -> Integrator_CSTATE_c - _rtP
-> P_133 ; break ; } if ( ( _rtDW -> Integrator_MODE_i == 3 ) || ( _rtDW ->
Integrator_MODE_i == 4 ) ) { _rtZCSV -> Integrator_LeaveSaturate_ZC_i = _rtB
-> B_16_76_0 ; } else { _rtZCSV -> Integrator_LeaveSaturate_ZC_i = 0.0 ; }
_rtZCSV -> RelationalOperator_RelopInput_ZC_a = _rtB -> B_16_69_0 - _rtB ->
B_16_8_0 ; _rtZCSV -> Saturation2_UprLim_ZC = _rtB -> B_16_79_0 - _rtP ->
P_144 ; _rtZCSV -> Saturation2_LwrLim_ZC = _rtB -> B_16_79_0 - _rtP -> P_145
; _rtZCSV -> RelationalOperator2_RelopInput_ZC [ 0 ] = _rtB -> B_16_141_0 -
_rtB -> B_16_132_0 ; _rtZCSV -> RelationalOperator2_RelopInput_ZC [ 1 ] =
_rtB -> B_16_150_0 - _rtB -> B_16_132_0 ; _rtZCSV ->
RelationalOperator2_RelopInput_ZC [ 2 ] = _rtB -> B_16_121_0 - _rtB ->
B_16_132_0 ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 1024297409U ) ; ssSetChecksumVal ( S , 1 ,
3226815322U ) ; ssSetChecksumVal ( S , 2 , 677713276U ) ; ssSetChecksumVal (
S , 3 , 79958242U ) ; { mxArray * slVerStructMat = ( NULL ) ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == ( NULL ) ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "10.4" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_Sim6_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_Sim6_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_Sim6_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & Sim6_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( ( P_Sim6_T
* ) ssGetModelRtp ( S ) ) -> P_9 = rtInf ; ( ( P_Sim6_T * ) ssGetModelRtp ( S
) ) -> P_127 = rtInf ; ( ( P_Sim6_T * ) ssGetModelRtp ( S ) ) -> P_128 =
rtMinusInf ; ( ( P_Sim6_T * ) ssGetModelRtp ( S ) ) -> P_132 = rtInf ; ( (
P_Sim6_T * ) ssGetModelRtp ( S ) ) -> P_144 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { slAccRegPrmChangeFcn ( S ,
mdlOutputsTID6 ) ; } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
