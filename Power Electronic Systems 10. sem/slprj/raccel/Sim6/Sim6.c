#include "rt_logging_mmi.h"
#include "Sim6_capi.h"
#include <math.h>
#include "Sim6.h"
#include "Sim6_private.h"
#include "Sim6_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 6 , & stopRequested ) ; }
rtExtModeShutdown ( 6 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 7 ; const char_T
* gbl_raccel_Version = "10.4 (R2021b) 14-May-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
const real_T Sim6_RGND = 0.0 ; B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ;
static SimStruct model_S ; SimStruct * const rtS = & model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ;
if ( istransportdelay ) { numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; }
testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <=
tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T *
tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T
newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr ) { *
maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer *
newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false )
; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_VTDelayfindtDInterpolate ( real_T x , real_T * uBuf , int_T bufSz , int_T
head , int_T tail , int_T * pLast , real_T t , real_T tStart , boolean_T
discrete , boolean_T minorStepAndTAtLastMajorOutput , real_T initOutput ,
real_T * appliedDelay ) { int_T n , k ; real_T f ; int_T kp1 ; real_T
tminustD , tL , tR , uD , uL , uR , fU ; real_T * tBuf = uBuf + bufSz ;
real_T * xBuf = uBuf + 2 * bufSz ; if ( minorStepAndTAtLastMajorOutput ) { if
( * pLast == head ) { * pLast = ( * pLast == 0 ) ? bufSz - 1 : * pLast - 1 ;
} head = ( head == 0 ) ? bufSz - 1 : head - 1 ; } if ( x <= 1 ) { return
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
] ; return ( table [ bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void lnng4k1xu3 (
ez1qc1u4ss * localB , lnfuzpqlv0 * localP ) { localB -> j2nl0k3bjo = localP
-> dq_Y0 [ 0 ] ; localB -> dxu5h4veqy = localP -> dq_Y0 [ 1 ] ; } void
lxyv23omal ( etsotvigvh * localDW ) { localDW -> eya5d5vx55 = false ; } void
eaxqlp5nrz ( SimStruct * rtS_p , etsotvigvh * localDW ) { localDW ->
eya5d5vx55 = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS_p ) ; }
void gpv2q2mna0 ( SimStruct * rtS_i , uint8_T oznahafnyb , const real_T
io15qqqqo2 [ 2 ] , real_T owa45pty5f , ez1qc1u4ss * localB , etsotvigvh *
localDW ) { if ( ssIsSampleHit ( rtS_i , 1 , 0 ) && ssIsMajorTimeStep ( rtS_i
) ) { if ( oznahafnyb > 0 ) { if ( ! localDW -> eya5d5vx55 ) { if (
ssGetTaskTime ( rtS_i , 1 ) != ssGetTStart ( rtS_i ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } localDW ->
eya5d5vx55 = true ; } } else if ( localDW -> eya5d5vx55 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; lxyv23omal ( localDW )
; } } if ( localDW -> eya5d5vx55 ) { localB -> j2nl0k3bjo = io15qqqqo2 [ 0 ]
* muDoubleScalarSin ( owa45pty5f ) - io15qqqqo2 [ 1 ] * muDoubleScalarCos (
owa45pty5f ) ; localB -> dxu5h4veqy = io15qqqqo2 [ 0 ] * muDoubleScalarCos (
owa45pty5f ) + io15qqqqo2 [ 1 ] * muDoubleScalarSin ( owa45pty5f ) ; if (
ssIsMajorTimeStep ( rtS_i ) ) { srUpdateBC ( localDW -> ofjd3uadhp ) ; } } }
void doezucbrrq ( b000baele5 * localB , anyxbustxf * localP ) { localB ->
otn2ta4rye = localP -> dq_Y0 [ 0 ] ; localB -> ow32b43xgs = localP -> dq_Y0 [
1 ] ; } void dibibutkg4 ( htflfovccy * localDW ) { localDW -> mvk4qyxu0n =
false ; } void d3q41qgird ( SimStruct * rtS_i , htflfovccy * localDW ) {
localDW -> mvk4qyxu0n = false ; ssSetBlockStateForSolverChangedAtMajorStep (
rtS_i ) ; } void aa2j2wnloo ( SimStruct * rtS_g , uint8_T lmolwjupgu , const
real_T fwlcyrlim1 [ 2 ] , real_T krnqok132n , b000baele5 * localB ,
htflfovccy * localDW ) { if ( ssIsSampleHit ( rtS_g , 1 , 0 ) &&
ssIsMajorTimeStep ( rtS_g ) ) { if ( lmolwjupgu > 0 ) { if ( ! localDW ->
mvk4qyxu0n ) { if ( ssGetTaskTime ( rtS_g , 1 ) != ssGetTStart ( rtS_g ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_g ) ; } localDW ->
mvk4qyxu0n = true ; } } else if ( localDW -> mvk4qyxu0n ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_g ) ; dibibutkg4 ( localDW )
; } } if ( localDW -> mvk4qyxu0n ) { localB -> otn2ta4rye = fwlcyrlim1 [ 0 ]
* muDoubleScalarCos ( krnqok132n ) + fwlcyrlim1 [ 1 ] * muDoubleScalarSin (
krnqok132n ) ; localB -> ow32b43xgs = - fwlcyrlim1 [ 0 ] * muDoubleScalarSin
( krnqok132n ) + fwlcyrlim1 [ 1 ] * muDoubleScalarCos ( krnqok132n ) ; if (
ssIsMajorTimeStep ( rtS_g ) ) { srUpdateBC ( localDW -> fqy4beoqau ) ; } } }
void MdlInitialize ( void ) { int32_T i ; boolean_T tmp ; { int32_T i , j ;
real_T * As = ( real_T * ) rtDW . empra3chml . AS ; real_T * Bs = ( real_T *
) rtDW . empra3chml . BS ; real_T * Cs = ( real_T * ) rtDW . empra3chml . CS
; real_T * Ds = ( real_T * ) rtDW . empra3chml . DS ; real_T * X0 = ( real_T
* ) & rtDW . naju1uwbkg [ 0 ] ; for ( i = 0 ; i < 2 ; i ++ ) { X0 [ i ] = (
rtP . StateSpace_X0_param [ i ] ) ; } for ( i = 0 ; i < 2 ; i ++ ) { for ( j
= 0 ; j < 2 ; j ++ ) As [ i * 2 + j ] = ( rtP . StateSpace_AS_param [ i + j *
2 ] ) ; for ( j = 0 ; j < 10 ; j ++ ) Bs [ i * 10 + j ] = ( rtP .
StateSpace_BS_param [ i + j * 2 ] ) ; } for ( i = 0 ; i < 12 ; i ++ ) { for (
j = 0 ; j < 2 ; j ++ ) Cs [ i * 2 + j ] = ( rtP . StateSpace_CS_param [ i + j
* 12 ] ) ; } for ( i = 0 ; i < 12 ; i ++ ) { for ( j = 0 ; j < 10 ; j ++ ) Ds
[ i * 10 + j ] = ( rtP . StateSpace_DS_param [ i + j * 12 ] ) ; } { int_T *
switch_status = ( int_T * ) rtDW . empra3chml . SWITCH_STATUS ; int_T *
gState = ( int_T * ) rtDW . empra3chml . G_STATE ; real_T * yswitch = (
real_T * ) rtDW . empra3chml . Y_SWITCH ; int_T * switchTypes = ( int_T * )
rtDW . empra3chml . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * ) rtDW .
empra3chml . IDX_OUT_SW ; int_T * switch_status_init = ( int_T * ) rtDW .
empra3chml . SWITCH_STATUS_INIT ; switch_status [ 0 ] = 0 ;
switch_status_init [ 0 ] = 0 ; gState [ 0 ] = ( int_T ) 0.0 ; yswitch [ 0 ] =
1 / 0.001 ; switchTypes [ 0 ] = ( int_T ) 7.0 ; idxOutSw [ 0 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 1 ] = 0 ; switch_status_init [ 1 ] = 0 ; gState [
1 ] = ( int_T ) 0.0 ; yswitch [ 1 ] = 1 / 0.001 ; switchTypes [ 1 ] = ( int_T
) 7.0 ; idxOutSw [ 1 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 2 ] = 0 ;
switch_status_init [ 2 ] = 0 ; gState [ 2 ] = ( int_T ) 0.0 ; yswitch [ 2 ] =
1 / 0.001 ; switchTypes [ 2 ] = ( int_T ) 7.0 ; idxOutSw [ 2 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 3 ] = 0 ; switch_status_init [ 3 ] = 0 ; gState [
3 ] = ( int_T ) 0.0 ; yswitch [ 3 ] = 1 / 0.001 ; switchTypes [ 3 ] = ( int_T
) 7.0 ; idxOutSw [ 3 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 4 ] = 0 ;
switch_status_init [ 4 ] = 0 ; gState [ 4 ] = ( int_T ) 0.0 ; yswitch [ 4 ] =
1 / 0.001 ; switchTypes [ 4 ] = ( int_T ) 7.0 ; idxOutSw [ 4 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 5 ] = 0 ; switch_status_init [ 5 ] = 0 ; gState [
5 ] = ( int_T ) 0.0 ; yswitch [ 5 ] = 1 / 0.001 ; switchTypes [ 5 ] = ( int_T
) 7.0 ; idxOutSw [ 5 ] = ( ( int_T ) 0.0 ) - 1 ; } } for ( i = 0 ; i < 6 ; i
++ ) { rtDW . iz4mjb3fpi [ i ] = rtP . UnitDelay_InitialCondition_hnsfjn5hxn
; } rtDW . kanrys502u = rtP . Delay11_InitialCondition ; rtDW . il2g04n2zg =
rtP . FFInt_IC ; rtDW . lc4skbr0sd = rtP .
Delay11_InitialCondition_dkcmnnrtrg ; rtDW . kmcobpcqvr = rtP .
FFInt_IC_dnt3xnjdp2 ; rtDW . kuxuhbis4w = 1 ; if ( ssIsFirstInitCond ( rtS )
) { rtX . iumu3kzzhr = 0.0 ; tmp = slIsRapidAcceleratorSimulating ( ) ; if (
tmp ) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . kuxuhbis4w =
! tmp ; } else { rtDW . kuxuhbis4w = 1 ; } } rtDW . o4yzgxidzo = rtP .
Memory_InitialCondition_cmy5m3zyx0 ; rtX . iip1hksxhe = rtP . Continuous_Init
; rtX . imjxbjnrao = 0.0 ; rtX . hvdzss0qy0 = rtP . integrator_IC_fa2zkozxvn
; rtDW . puptsnuvic = rtP . Memory_InitialCondition_mxilddonen ; rtX .
mgdsbp3tlu = 0.0 ; rtDW . hrtqjrd53x = ( rtInf ) ; rtDW . pvzxgas2b3 = (
rtInf ) ; rtX . mlt40cyrau = rtP . Integrator_x1_IC ; rtX . fb24y2esxb = rtP
. Integrator_x2_IC ; rtX . jh55bpubqj [ 0 ] = 0.0 ; rtX . jn4nrdhpx1 [ 0 ] =
0.0 ; rtX . fyyiprok3t [ 0 ] = 0.0 ; rtX . bjpvgeyygb [ 0 ] = 0.0 ; rtX .
jkhhrdnef2 [ 0 ] = 0.0 ; rtX . ns23ofbiao [ 0 ] = 0.0 ; rtX . fozte2xjae [ 0
] = 0.0 ; rtX . ggl1vuf0v0 [ 0 ] = 0.0 ; rtX . eavqvzqdwf [ 0 ] = 0.0 ; rtX .
jh55bpubqj [ 1 ] = 0.0 ; rtX . jn4nrdhpx1 [ 1 ] = 0.0 ; rtX . fyyiprok3t [ 1
] = 0.0 ; rtX . bjpvgeyygb [ 1 ] = 0.0 ; rtX . jkhhrdnef2 [ 1 ] = 0.0 ; rtX .
ns23ofbiao [ 1 ] = 0.0 ; rtX . fozte2xjae [ 1 ] = 0.0 ; rtX . ggl1vuf0v0 [ 1
] = 0.0 ; rtX . eavqvzqdwf [ 1 ] = 0.0 ; rtDW . dcvx0x0nhj = rtP .
UnitDelay_InitialCondition_kjuilmwono ; rtX . bpxu1bsrls = 0.0 ; rtX .
c2tj4z32zx = rtP . integrator_IC ; rtDW . edvu1xljbk = rtP .
Memory_InitialCondition ; rtX . jbjlk4lmud = 0.0 ; rtX . hcrv11zemx = rtP .
integrator_IC_g14ialcirz ; rtDW . d3leen4kcy = rtP .
Memory_InitialCondition_bz4nohehtu ; lnng4k1xu3 ( & rtB . gpv2q2mna0v , & rtP
. gpv2q2mna0v ) ; doezucbrrq ( & rtB . aa2j2wnloo2 , & rtP . aa2j2wnloo2 ) ;
rtB . pe3tnbqbgy = rtP . Gain_Y0 ; lnng4k1xu3 ( & rtB . gbv0nikqj2 , & rtP .
gbv0nikqj2 ) ; doezucbrrq ( & rtB . hl5zrirewt , & rtP . hl5zrirewt ) ; rtB .
gahdo2523m = rtP . alpha_beta_Y0_pg4urrpzbu [ 0 ] ; rtB . brq4reciat = rtP .
alpha_beta_Y0_pg4urrpzbu [ 1 ] ; rtB . mv2ve5xuao = rtP . alpha_beta_Y0 [ 0 ]
; rtB . lzxedsxie0 = rtP . alpha_beta_Y0 [ 1 ] ; rtDW . jonetifjdl = rtP .
DiscreteTimeIntegrator_IC ; rtDW . k5octspggf = rtP .
DiscreteTimeIntegrator1_IC ; rtDW . kurtqaimb2 = rtP .
UnitDelay_InitialCondition ; } void MdlEnable ( void ) { rtDW . cbxygsrulg =
1 ; rtDW . oehqsdtju1 = 1 ; rtDW . ebrnrfebzf = 1 ; } void MdlStart ( void )
{ { bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [
] = { 3 , 3 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 } ;
static int_T rt_ScopeSignalDimensions [ ] = { 3 , 3 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" } ; static char_T rt_ScopeSignalTitles [
] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] = { 0 , 0 } ; static
boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 , 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; BuiltInDTypeId
dTypes [ 2 ] = { SS_DOUBLE , SS_DOUBLE } ; static char_T rt_ScopeBlockName [
] = "Sim6/Scope1" ; static int_T rt_ScopeFrameData [ ] = { 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) } ; rt_ScopeSignalInfo . numSignals = 2 ;
rt_ScopeSignalInfo . numCols = rt_ScopeSignalWidths ; rt_ScopeSignalInfo .
numDims = rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . nowwneuenp . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "ScopeData2" , 1 , 0 , 2 , 1.0E-6 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . nowwneuenp .
LoggedData [ 0 ] == ( NULL ) ) return ; } rtDW . ovo53pq3zf = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( void ) memset ( & ( (
( XDis * ) ssGetContStateDisabled ( rtS ) ) -> bpxu1bsrls ) , 1 , 4 * sizeof
( boolean_T ) ) ; { int_T j ; char ptrKey [ 1024 ] ; { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 3 , 8192 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" )
; return ; } rtDW . itw05pv4q1 . Tail = 0 ; rtDW . itw05pv4q1 . Head = 0 ;
rtDW . itw05pv4q1 . Last = 0 ; rtDW . itw05pv4q1 . CircularBufSize = 8192 ;
for ( j = 0 ; j < 8192 ; j ++ ) { pBuffer [ j ] = rtP .
VariableTransportDelay_InitOutput ; pBuffer [ 8192 + j ] = ssGetT ( rtS ) ; }
pBuffer [ 2 * 8192 ] = 0.0 ; rtDW . mlq3s0zii4 . TUbufferPtrs [ 0 ] = ( void
* ) & pBuffer [ 0 ] ; sprintf ( ptrKey ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)1/Model/Variable\nTransport Delay_TUbuffer%d"
, 0 ) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( &
rtDW . mlq3s0zii4 . TUbufferPtrs [ 0 ] ) , 3 * 8192 * sizeof ( real_T ) , (
NULL ) , ( NULL ) ) ; } } { int_T j ; char ptrKey [ 1024 ] ; { real_T *
pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 3 , 8192 , sizeof ( real_T ) ) ;
if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } rtDW . oyd0zxlfez . Tail = 0
; rtDW . oyd0zxlfez . Head = 0 ; rtDW . oyd0zxlfez . Last = 0 ; rtDW .
oyd0zxlfez . CircularBufSize = 8192 ; for ( j = 0 ; j < 8192 ; j ++ ) {
pBuffer [ j ] = rtP . VariableTransportDelay_InitOutput_d5upbocuak ; pBuffer
[ 8192 + j ] = ssGetT ( rtS ) ; } pBuffer [ 2 * 8192 ] = 0.0 ; rtDW .
n2b5jg51yt . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; sprintf (
ptrKey ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)2/Model/Variable\nTransport Delay_TUbuffer%d"
, 0 ) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( &
rtDW . n2b5jg51yt . TUbufferPtrs [ 0 ] ) , 3 * 8192 * sizeof ( real_T ) , (
NULL ) , ( NULL ) ) ; } } eaxqlp5nrz ( rtS , & rtDW . gpv2q2mna0v ) ;
d3q41qgird ( rtS , & rtDW . aa2j2wnloo2 ) ; rtDW . o2b5vrjagl = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . nf2gbckq3n =
false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW .
hsca3knam3 = 0U ; rtDW . loledzy1qu = 0U ; rtP . SineWaveA_Hsin =
muDoubleScalarSin ( 6.2831853071795862 * rtP . ThreePhaseSource_Frequency *
1.0E-6 ) ; rtP . SineWaveA_HCos = muDoubleScalarCos ( 6.2831853071795862 *
rtP . ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveA_PSin =
muDoubleScalarSin ( 0.0 - 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveA_PCos =
muDoubleScalarCos ( 0.0 - 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveB_Hsin =
muDoubleScalarSin ( 6.2831853071795862 * rtP . ThreePhaseSource_Frequency *
1.0E-6 ) ; rtP . SineWaveB_HCos = muDoubleScalarCos ( 6.2831853071795862 *
rtP . ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveB_PSin =
muDoubleScalarSin ( - 2.0943951023931953 - 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveB_PCos =
muDoubleScalarCos ( - 2.0943951023931953 - 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveC_Hsin =
muDoubleScalarSin ( 6.2831853071795862 * rtP . ThreePhaseSource_Frequency *
1.0E-6 ) ; rtP . SineWaveC_HCos = muDoubleScalarCos ( 6.2831853071795862 *
rtP . ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveC_PSin =
muDoubleScalarSin ( 2.0943951023931953 - 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * 1.0E-6 ) ; rtP . SineWaveC_PCos =
muDoubleScalarCos ( 2.0943951023931953 - 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * 1.0E-6 ) ; { rtDW . empra3chml . AS = ( real_T *
) calloc ( 2 * 2 , sizeof ( real_T ) ) ; rtDW . empra3chml . BS = ( real_T *
) calloc ( 2 * 10 , sizeof ( real_T ) ) ; rtDW . empra3chml . CS = ( real_T *
) calloc ( 12 * 2 , sizeof ( real_T ) ) ; rtDW . empra3chml . DS = ( real_T *
) calloc ( 12 * 10 , sizeof ( real_T ) ) ; rtDW . empra3chml . DX_COL = (
real_T * ) calloc ( 12 , sizeof ( real_T ) ) ; rtDW . empra3chml . TMP2 = (
real_T * ) calloc ( 10 , sizeof ( real_T ) ) ; rtDW . empra3chml . BD_COL = (
real_T * ) calloc ( 2 , sizeof ( real_T ) ) ; rtDW . empra3chml . TMP1 = (
real_T * ) calloc ( 2 , sizeof ( real_T ) ) ; rtDW . empra3chml . XTMP = (
real_T * ) calloc ( 2 , sizeof ( real_T ) ) ; rtDW . empra3chml .
SWITCH_STATUS = ( int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW .
empra3chml . SW_CHG = ( int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW .
empra3chml . G_STATE = ( int_T * ) calloc ( 6 , sizeof ( int_T ) ) ; rtDW .
empra3chml . Y_SWITCH = ( real_T * ) calloc ( 6 , sizeof ( real_T ) ) ; rtDW
. empra3chml . SWITCH_TYPES = ( int_T * ) calloc ( 6 , sizeof ( int_T ) ) ;
rtDW . empra3chml . IDX_OUT_SW = ( int_T * ) calloc ( 6 , sizeof ( int_T ) )
; rtDW . empra3chml . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 6 , sizeof (
int_T ) ) ; rtDW . empra3chml . USWLAST = ( real_T * ) calloc ( 6 , sizeof (
real_T ) ) ; } rtDW . aw1t1zwgas = 0U ; rtDW . aisofpnorv = 0U ; rtB .
k01onl4g5t = rtP . Initial_Value ; rtDW . bwt1hrltpz = ( rtMinusInf ) ; {
int_T j ; char ptrKey [ 1024 ] ; { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 3 , 8192 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ;
} rtDW . e3u5ld2y51 . Tail = 0 ; rtDW . e3u5ld2y51 . Head = 0 ; rtDW .
e3u5ld2y51 . Last = 0 ; rtDW . e3u5ld2y51 . CircularBufSize = 8192 ; for ( j
= 0 ; j < 8192 ; j ++ ) { pBuffer [ j ] = rtP .
VariableTransportDelay_InitOutput_ly4stoovo0 ; pBuffer [ 8192 + j ] = ssGetT
( rtS ) ; } pBuffer [ 2 * 8192 ] = 0.0 ; rtDW . nr4hpz0s5b . TUbufferPtrs [ 0
] = ( void * ) & pBuffer [ 0 ] ; sprintf ( ptrKey ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Variable Frequency\nMean value/Model/Variable\nTransport Delay_TUbuffer%d"
, 0 ) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( &
rtDW . nr4hpz0s5b . TUbufferPtrs [ 0 ] ) , 3 * 8192 * sizeof ( real_T ) , (
NULL ) , ( NULL ) ) ; } } eaxqlp5nrz ( rtS , & rtDW . gbv0nikqj2 ) ;
d3q41qgird ( rtS , & rtDW . hl5zrirewt ) ; rtDW . bv4jm4qenv = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . fbzp2gawrm =
false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; MdlInitialize (
) ; MdlEnable ( ) ; } void MdlOutputs ( int_T tid ) { real_T dz5jyu5ho0 ;
real_T itji0osmqd ; real_T je2ubjyoi0 ; real_T jmmiv3kip3 ; int32_T i ;
boolean_T didZcEventOccur ; srClearBC ( rtDW . gpv2q2mna0v . ofjd3uadhp ) ;
srClearBC ( rtDW . aa2j2wnloo2 . fqy4beoqau ) ; srClearBC ( rtDW . oxvhzb4uhf
) ; srClearBC ( rtDW . kza5ow0kr4 ) ; srClearBC ( rtDW . c2l3p2qtjf ) ;
srClearBC ( rtDW . mvk1crirkl ) ; srClearBC ( rtDW . ee4ok4zlel ) ; if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( rtDW . cbxygsrulg != 0 ) { rtDW .
m3xa5qdlgu = muDoubleScalarSin ( 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * ssGetTaskTime ( rtS , 3 ) ) ; rtDW . g4a2feilda
= muDoubleScalarCos ( 6.2831853071795862 * rtP . ThreePhaseSource_Frequency *
ssGetTaskTime ( rtS , 3 ) ) ; rtDW . cbxygsrulg = 0 ; } rtB . gktfzcs3fd = (
( rtDW . m3xa5qdlgu * rtP . SineWaveA_PCos + rtDW . g4a2feilda * rtP .
SineWaveA_PSin ) * rtP . SineWaveA_HCos + ( rtDW . g4a2feilda * rtP .
SineWaveA_PCos - rtDW . m3xa5qdlgu * rtP . SineWaveA_PSin ) * rtP .
SineWaveA_Hsin ) * rtP . SineWaveA_Amp + rtP . SineWaveA_Bias ; if ( rtDW .
oehqsdtju1 != 0 ) { rtDW . ati3zogtqu = muDoubleScalarSin (
6.2831853071795862 * rtP . ThreePhaseSource_Frequency * ssGetTaskTime ( rtS ,
3 ) ) ; rtDW . n5yzxageiq = muDoubleScalarCos ( 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * ssGetTaskTime ( rtS , 3 ) ) ; rtDW . oehqsdtju1
= 0 ; } rtB . dbmx3g5hpc = ( ( rtDW . ati3zogtqu * rtP . SineWaveB_PCos +
rtDW . n5yzxageiq * rtP . SineWaveB_PSin ) * rtP . SineWaveB_HCos + ( rtDW .
n5yzxageiq * rtP . SineWaveB_PCos - rtDW . ati3zogtqu * rtP . SineWaveB_PSin
) * rtP . SineWaveB_Hsin ) * rtP . SineWaveB_Amp + rtP . SineWaveB_Bias ; if
( rtDW . ebrnrfebzf != 0 ) { rtDW . hxzxqy2ytd = muDoubleScalarSin (
6.2831853071795862 * rtP . ThreePhaseSource_Frequency * ssGetTaskTime ( rtS ,
3 ) ) ; rtDW . lpdpgewspm = muDoubleScalarCos ( 6.2831853071795862 * rtP .
ThreePhaseSource_Frequency * ssGetTaskTime ( rtS , 3 ) ) ; rtDW . ebrnrfebzf
= 0 ; } rtB . dm5evipofq = ( ( rtDW . hxzxqy2ytd * rtP . SineWaveC_PCos +
rtDW . lpdpgewspm * rtP . SineWaveC_PSin ) * rtP . SineWaveC_HCos + ( rtDW .
lpdpgewspm * rtP . SineWaveC_PCos - rtDW . hxzxqy2ytd * rtP . SineWaveC_PSin
) * rtP . SineWaveC_Hsin ) * rtP . SineWaveC_Amp + rtP . SineWaveC_Bias ; {
real_T accum ; int_T * switch_status = ( int_T * ) rtDW . empra3chml .
SWITCH_STATUS ; int_T * switch_status_init = ( int_T * ) rtDW . empra3chml .
SWITCH_STATUS_INIT ; int_T * SwitchChange = ( int_T * ) rtDW . empra3chml .
SW_CHG ; int_T * gState = ( int_T * ) rtDW . empra3chml . G_STATE ; real_T *
yswitch = ( real_T * ) rtDW . empra3chml . Y_SWITCH ; int_T * switchTypes = (
int_T * ) rtDW . empra3chml . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * )
rtDW . empra3chml . IDX_OUT_SW ; real_T * DxCol = ( real_T * ) rtDW .
empra3chml . DX_COL ; real_T * tmp2 = ( real_T * ) rtDW . empra3chml . TMP2 ;
real_T * BDcol = ( real_T * ) rtDW . empra3chml . BD_COL ; real_T * tmp1 = (
real_T * ) rtDW . empra3chml . TMP1 ; real_T * uswlast = ( real_T * ) rtDW .
empra3chml . USWLAST ; int_T newState ; int_T swChanged = 0 ; int loopsToDo =
20 ; real_T temp ; memcpy ( switch_status_init , switch_status , 6 * sizeof (
int_T ) ) ; memcpy ( uswlast , & rtB . bpposa5psj [ 0 ] , 6 * sizeof ( real_T
) ) ; do { if ( loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0
; i1 < 6 ; i1 ++ ) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init
[ i1 ] - switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ]
= switch_status_init [ i1 ] ; } } } else { real_T * Cs = ( real_T * ) rtDW .
empra3chml . CS ; real_T * Ds = ( real_T * ) rtDW . empra3chml . DS ; { int_T
i1 ; real_T * y0 = & rtB . bpposa5psj [ 0 ] ; for ( i1 = 0 ; i1 < 12 ; i1 ++
) { accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . naju1uwbkg [ 0 ] ; accum += *
( Cs ++ ) * rtDW . naju1uwbkg [ 1 ] ; { int_T i2 ; const real_T * u0 ; for (
i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += * ( Ds ++ ) * 0.0 ; } accum += * ( Ds ++
) * rtP . Vdc_Amplitude ; accum += * ( Ds ++ ) * rtB . gktfzcs3fd ; accum +=
* ( Ds ++ ) * rtB . dbmx3g5hpc ; accum += * ( Ds ++ ) * rtB . dm5evipofq ; }
y0 [ i1 ] = accum ; } } swChanged = 0 ; { int_T i1 ; real_T * y0 = & rtB .
bpposa5psj [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { newState = ( ( y0 [ i1 ]
> 0.0 ) && ( gState [ i1 ] > 0 ) ) || ( y0 [ i1 ] < 0.0 ) ? 1 : ( ( ( y0 [ i1
] > 0.0 ) && gState [ i1 ] == 0 ) ? 0 : switch_status [ i1 ] ) ; swChanged =
( ( SwitchChange [ i1 ] = newState - switch_status [ i1 ] ) != 0 ) ? 1 :
swChanged ; switch_status [ i1 ] = newState ; } } } if ( swChanged ) { real_T
* As = ( real_T * ) rtDW . empra3chml . AS ; real_T * Cs = ( real_T * ) rtDW
. empra3chml . CS ; real_T * Bs = ( real_T * ) rtDW . empra3chml . BS ;
real_T * Ds = ( real_T * ) rtDW . empra3chml . DS ; real_T a1 ; { int_T i1 ;
for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { if ( SwitchChange [ i1 ] != 0 ) { a1 =
1000.0 * SwitchChange [ i1 ] ; temp = 1 / ( 1 - Ds [ i1 * 11 ] * a1 ) ; {
int_T i2 ; for ( i2 = 0 ; i2 < 12 ; i2 ++ ) { DxCol [ i2 ] = Ds [ i2 * 10 +
i1 ] * temp * a1 ; } } DxCol [ i1 ] = temp ; BDcol [ 0 ] = Bs [ 0 + i1 ] * a1
; BDcol [ 1 ] = Bs [ 10 + i1 ] * a1 ; memcpy ( tmp1 , & Cs [ i1 * 2 ] , 2 *
sizeof ( real_T ) ) ; memset ( & Cs [ i1 * 2 ] , '\0' , 2 * sizeof ( real_T )
) ; memcpy ( tmp2 , & Ds [ i1 * 10 ] , 10 * sizeof ( real_T ) ) ; memset ( &
Ds [ i1 * 10 ] , '\0' , 10 * sizeof ( real_T ) ) ; { int_T i2 ; for ( i2 = 0
; i2 < 12 ; i2 ++ ) { a1 = DxCol [ i2 ] ; Cs [ i2 * 2 + 0 ] += a1 * tmp1 [ 0
] ; Cs [ i2 * 2 + 1 ] += a1 * tmp1 [ 1 ] ; { int_T i3 ; for ( i3 = 0 ; i3 <
10 ; i3 ++ ) { Ds [ i2 * 10 + i3 ] += a1 * tmp2 [ i3 ] ; } } } } a1 = BDcol [
0 ] ; As [ 0 + 0 ] += a1 * Cs [ i1 * 2 + 0 ] ; As [ 0 + 1 ] += a1 * Cs [ i1 *
2 + 1 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 10 ; i2 ++ ) { Bs [ 0 + i2 ] += a1
* Ds [ i1 * 10 + i2 ] ; } } a1 = BDcol [ 1 ] ; As [ 2 + 0 ] += a1 * Cs [ i1 *
2 + 0 ] ; As [ 2 + 1 ] += a1 * Cs [ i1 * 2 + 1 ] ; { int_T i2 ; for ( i2 = 0
; i2 < 10 ; i2 ++ ) { Bs [ 10 + i2 ] += a1 * Ds [ i1 * 10 + i2 ] ; } } } } }
} } while ( swChanged > 0 && -- loopsToDo > 0 ) ; if ( loopsToDo == 0 ) {
real_T * Cs = ( real_T * ) rtDW . empra3chml . CS ; real_T * Ds = ( real_T *
) rtDW . empra3chml . DS ; { int_T i1 ; real_T * y0 = & rtB . bpposa5psj [ 0
] ; for ( i1 = 0 ; i1 < 12 ; i1 ++ ) { accum = 0.0 ; accum += * ( Cs ++ ) *
rtDW . naju1uwbkg [ 0 ] ; accum += * ( Cs ++ ) * rtDW . naju1uwbkg [ 1 ] ; {
int_T i2 ; const real_T * u0 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { accum += * (
Ds ++ ) * 0.0 ; } accum += * ( Ds ++ ) * rtP . Vdc_Amplitude ; accum += * (
Ds ++ ) * rtB . gktfzcs3fd ; accum += * ( Ds ++ ) * rtB . dbmx3g5hpc ; accum
+= * ( Ds ++ ) * rtB . dm5evipofq ; } y0 [ i1 ] = accum ; } } } { int_T i1 ;
real_T * y1 = & rtB . a03vq2btj3 [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { y1
[ i1 ] = ( real_T ) switch_status [ i1 ] ; } } } for ( i = 0 ; i < 6 ; i ++ )
{ if ( rtB . a03vq2btj3 [ i ] >= rtP . Switch_Threshold_h0h0hrbrds ) {
jmmiv3kip3 = rtP . uRon_Gain * rtB . bpposa5psj [ i ] ; } else { jmmiv3kip3 =
rtP . u4_Value ; } if ( jmmiv3kip3 > rtP . Saturation_UpperSat_lphrbvohc0 ) {
rtB . bgjph5tzti [ i ] = rtP . Saturation_UpperSat_lphrbvohc0 ; } else if (
jmmiv3kip3 < rtP . Saturation_LowerSat_gyzt3s021b ) { rtB . bgjph5tzti [ i ]
= rtP . Saturation_LowerSat_gyzt3s021b ; } else { rtB . bgjph5tzti [ i ] =
jmmiv3kip3 ; } } rtB . djau2g1olc [ 0 ] = rtP . donotdeletethisgain_Gain *
rtB . bpposa5psj [ 6 ] * rtP . Kv1_Gain ; rtB . djau2g1olc [ 1 ] = rtP .
donotdeletethisgain_Gain_cjkn1fmmwf * rtB . bpposa5psj [ 7 ] * rtP . Kv1_Gain
; rtB . djau2g1olc [ 2 ] = rtP . donotdeletethisgain_Gain_p4xdjo1x0c * rtB .
bpposa5psj [ 8 ] * rtP . Kv1_Gain ; jmmiv3kip3 = ( ( rtB . djau2g1olc [ 0 ] -
0.5 * rtB . djau2g1olc [ 1 ] ) - 0.5 * rtB . djau2g1olc [ 2 ] ) *
0.816496580927726 ; je2ubjyoi0 = ( ( 0.0 * rtB . djau2g1olc [ 0 ] +
0.8660254037844386 * rtB . djau2g1olc [ 1 ] ) - 0.8660254037844386 * rtB .
djau2g1olc [ 2 ] ) * 0.816496580927726 ; rtB . paaqohv05q [ 0 ] = rtP .
donotdeletethisgain_Gain_f05p010jfj * rtB . bpposa5psj [ 9 ] * rtP . Kv_Gain
; rtB . paaqohv05q [ 1 ] = rtP . donotdeletethisgain_Gain_om0hzrwmvi * rtB .
bpposa5psj [ 10 ] * rtP . Kv_Gain ; rtB . paaqohv05q [ 2 ] = rtP .
donotdeletethisgain_Gain_pj4emxjkfc * rtB . bpposa5psj [ 11 ] * rtP . Kv_Gain
; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . dg3sdnhfhz = (
ssGetTaskTime ( rtS , 1 ) >= rtP . P10kW_Time ) ; if ( rtDW . dg3sdnhfhz == 1
) { rtB . kqg04a251b = rtP . P10kW_YFinal ; } else { rtB . kqg04a251b = rtP .
P10kW_Y0 ; } } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . k2t2anegon = ( (
rtB . paaqohv05q [ 0 ] - 0.5 * rtB . paaqohv05q [ 1 ] ) - 0.5 * rtB .
paaqohv05q [ 2 ] ) * 0.816496580927726 ; rtB . fo12qitrhm = ( ( 0.0 * rtB .
paaqohv05q [ 0 ] + 0.8660254037844386 * rtB . paaqohv05q [ 1 ] ) -
0.8660254037844386 * rtB . paaqohv05q [ 2 ] ) * 0.816496580927726 ; } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . kkx3bsha4q = ( jmmiv3kip3 * rtB .
k2t2anegon + je2ubjyoi0 * rtB . fo12qitrhm ) * rtP . s1_Gain - rtP . a21_Gain
* rtDW . kanrys502u ; rtB . prxgf4reyt = rtB . kkx3bsha4q + rtDW . kanrys502u
; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . dtyrdyfgxc = rtB .
kqg04a251b - rtB . prxgf4reyt ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB
. lhih2qrjjs = rtDW . il2g04n2zg ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) {
itji0osmqd = rtP . KppP * rtB . dtyrdyfgxc ; } if ( ssIsSampleHit ( rtS , 3 ,
0 ) ) { rtB . m5uukj3ycd = ( jmmiv3kip3 * rtB . fo12qitrhm - je2ubjyoi0 * rtB
. k2t2anegon ) * rtP . s1_Gain_hko4bmcnti - rtP . a21_Gain_igtn11js15 * rtDW
. lc4skbr0sd ; rtB . kq0uqgcvcf = rtB . m5uukj3ycd + rtDW . lc4skbr0sd ; rtB
. k5kueqchg5 = rtB . dcuhhc42lm - rtB . kq0uqgcvcf ; } if ( ssIsSampleHit (
rtS , 4 , 0 ) ) { rtB . j2eixrpwyy = rtB . lhih2qrjjs * rtP . KipP +
itji0osmqd ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . m5bsg3jkvc = rtDW
. kmcobpcqvr ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . exoldmyxco =
rtB . m5bsg3jkvc * rtP . KipQ + rtP . KppQ * rtB . k5kueqchg5 ; } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . ffvcceoghv [ 0 ] = rtP .
Gain1_Gain_mmba2zpssf * rtB . djau2g1olc [ 0 ] ; rtB . ffvcceoghv [ 1 ] = rtP
. Gain1_Gain_mmba2zpssf * rtB . djau2g1olc [ 1 ] ; rtB . ffvcceoghv [ 2 ] =
rtP . Gain1_Gain_mmba2zpssf * rtB . djau2g1olc [ 2 ] ; } if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . oacr45potf = (
rtX . iumu3kzzhr > rtP . Constant2_Value_awyv320bt3 ) ; } rtB . hzmul4slgt =
rtDW . oacr45potf ; } rtB . dgq4jw1zua = rtX . iumu3kzzhr - rtP .
Constant2_Value_awyv320bt3 ; if ( ( rtDW . bwt1hrltpz == ( rtMinusInf ) ) ||
( rtDW . bwt1hrltpz == ssGetTaskTime ( rtS , 0 ) ) ) { rtDW . bwt1hrltpz =
ssGetTaskTime ( rtS , 0 ) ; rtB . k01onl4g5t = rtP . Initial_Value ; } else {
rtB . k01onl4g5t = rtB . dgq4jw1zua ; } if ( ssIsMajorTimeStep ( rtS ) ) {
didZcEventOccur = ( rtB . hzmul4slgt && ( rtPrevZCX . ff24yskbma != POS_ZCSIG
) ) ; rtPrevZCX . ff24yskbma = rtB . hzmul4slgt ; if ( didZcEventOccur || (
rtDW . kuxuhbis4w != 0 ) ) { rtX . iumu3kzzhr = rtB . k01onl4g5t ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; } if ( rtX .
iumu3kzzhr >= rtP . Integrator_UpperSat ) { if ( rtX . iumu3kzzhr != rtP .
Integrator_UpperSat ) { rtX . iumu3kzzhr = rtP . Integrator_UpperSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; } rtDW .
chgudtwki5 = 3 ; } else if ( rtX . iumu3kzzhr <= rtP . Integrator_LowerSat )
{ if ( rtX . iumu3kzzhr != rtP . Integrator_LowerSat ) { rtX . iumu3kzzhr =
rtP . Integrator_LowerSat ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; } rtDW .
chgudtwki5 = 4 ; } else { if ( rtDW . chgudtwki5 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . chgudtwki5 = 0
; } rtB . llqrd441m5 = rtX . iumu3kzzhr ; } else { rtB . llqrd441m5 = rtX .
iumu3kzzhr ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . exj242slie = rtDW
. o4yzgxidzo ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtP .
Constant1_Value_bnn31ave1a > 0.0 ) { if ( ! rtDW . ovo53pq3zf ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } ( void ) memset ( & (
( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> bpxu1bsrls ) , 0 , 4 *
sizeof ( boolean_T ) ) ; rtDW . ovo53pq3zf = true ; } } else { if (
ssGetTaskTime ( rtS , 1 ) == ssGetTStart ( rtS ) ) { ( void ) memset ( & ( (
( XDis * ) ssGetContStateDisabled ( rtS ) ) -> bpxu1bsrls ) , 1 , 4 * sizeof
( boolean_T ) ) ; } if ( rtDW . ovo53pq3zf ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( void ) memset ( & ( (
( XDis * ) ssGetContStateDisabled ( rtS ) ) -> bpxu1bsrls ) , 1 , 4 * sizeof
( boolean_T ) ) ; if ( rtDW . gpv2q2mna0v . eya5d5vx55 ) { lxyv23omal ( &
rtDW . gpv2q2mna0v ) ; } if ( rtDW . aa2j2wnloo2 . mvk4qyxu0n ) { dibibutkg4
( & rtDW . aa2j2wnloo2 ) ; } rtDW . ovo53pq3zf = false ; } } } } if ( rtDW .
ovo53pq3zf ) { { real_T * * uBuffer = ( real_T * * ) & rtDW . mlq3s0zii4 .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T appliedDelay ;
rtB . jqerscg1zt = rt_VTDelayfindtDInterpolate ( rtX . bpxu1bsrls , * uBuffer
, rtDW . itw05pv4q1 . CircularBufSize , rtDW . itw05pv4q1 . Head , rtDW .
itw05pv4q1 . Tail , & rtDW . itw05pv4q1 . Last , simTime , 0.0 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) , rtP . VariableTransportDelay_InitOutput , & appliedDelay
) ; } rtB . pqq2mzl5yy = rtX . c2tj4z32zx ; rtB . emtuteg24p = ssGetT ( rtS )
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . navvsf1ufo = ( rtB . emtuteg24p >= rtP . Constant_Value ) ; } rtB .
kiunlxs5sx = rtDW . navvsf1ufo ; rtB . gfw00daf11 = rtDW . edvu1xljbk ; } if
( rtB . kiunlxs5sx ) { rtB . e3pcbwyj3i = rtB . pqq2mzl5yy - rtB . jqerscg1zt
; rtB . aah0x3cxyl = rtB . e3pcbwyj3i * rtB . exj242slie ; rtB . klqpdibj32 =
rtB . aah0x3cxyl ; } else { rtB . klqpdibj32 = rtB . gfw00daf11 ; } { real_T
* * uBuffer = ( real_T * * ) & rtDW . n2b5jg51yt . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( rtS ) ; real_T appliedDelay ; rtB . jdm55m0vau =
rt_VTDelayfindtDInterpolate ( rtX . jbjlk4lmud , * uBuffer , rtDW .
oyd0zxlfez . CircularBufSize , rtDW . oyd0zxlfez . Head , rtDW . oyd0zxlfez .
Tail , & rtDW . oyd0zxlfez . Last , simTime , 0.0 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS
) ) ) , rtP . VariableTransportDelay_InitOutput_d5upbocuak , & appliedDelay )
; } rtB . hohn5tgzlv = rtX . hcrv11zemx ; rtB . asbptj5zaz = ssGetT ( rtS ) ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . fbyhlicb5e = ( rtB . asbptj5zaz >= rtP . Constant_Value_n0qkhh1fth ) ;
} rtB . bx3i1gippc = rtDW . fbyhlicb5e ; rtB . nred03mov5 = rtDW . d3leen4kcy
; } if ( rtB . bx3i1gippc ) { rtB . fdljtyo4lz = rtB . hohn5tgzlv - rtB .
jdm55m0vau ; rtB . jwdiimvvl4 = rtB . fdljtyo4lz * rtB . exj242slie ; rtB .
onjteuktwt = rtB . jwdiimvvl4 ; } else { rtB . onjteuktwt = rtB . nred03mov5
; } rtB . gap4mluorh . re = rtB . klqpdibj32 ; rtB . gap4mluorh . im = rtB .
onjteuktwt ; rtB . jfashjspdq = muDoubleScalarHypot ( rtB . gap4mluorh . re ,
rtB . gap4mluorh . im ) ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
lguevo5cl5 = rtB . jfashjspdq >= rtP . Saturation_UpperSat ? 1 : rtB .
jfashjspdq > rtP . Saturation_LowerSat ? 0 : - 1 ; } rtB . hujgllbkhe = rtDW
. lguevo5cl5 == 1 ? rtP . Saturation_UpperSat : rtDW . lguevo5cl5 == - 1 ?
rtP . Saturation_LowerSat : rtB . jfashjspdq ; rtB . pe3tnbqbgy = 1.0 / rtB .
hujgllbkhe ; if ( rtB . exj242slie > rtP . Toavoiddivisionbyzero_UpperSat ) {
rtB . emd031udec = rtP . Toavoiddivisionbyzero_UpperSat ; } else if ( rtB .
exj242slie < rtP . Toavoiddivisionbyzero_LowerSat ) { rtB . emd031udec = rtP
. Toavoiddivisionbyzero_LowerSat ; } else { rtB . emd031udec = rtB .
exj242slie ; } rtB . hs004dp4hy = 1.0 / rtB . emd031udec ; if ( rtB .
exj242slie > rtP . Toavoiddivisionbyzero_UpperSat_amv5dob4gd ) { rtB .
lejcvssl30 = rtP . Toavoiddivisionbyzero_UpperSat_amv5dob4gd ; } else if (
rtB . exj242slie < rtP . Toavoiddivisionbyzero_LowerSat_dsvy2fn0ag ) { rtB .
lejcvssl30 = rtP . Toavoiddivisionbyzero_LowerSat_dsvy2fn0ag ; } else { rtB .
lejcvssl30 = rtB . exj242slie ; } rtB . omw4a1utb1 = 1.0 / rtB . lejcvssl30 ;
for ( i = 0 ; i < 3 ; i ++ ) { rtB . aiseatx5p4 [ i ] = 0.0 ; rtB .
aiseatx5p4 [ i ] += rtP . Gain3_Gain [ i ] * rtB . ffvcceoghv [ 0 ] ; rtB .
aiseatx5p4 [ i ] += rtP . Gain3_Gain [ i + 3 ] * rtB . ffvcceoghv [ 1 ] ; rtB
. aiseatx5p4 [ i ] += rtP . Gain3_Gain [ i + 6 ] * rtB . ffvcceoghv [ 2 ] ;
rtB . lsxposbkab [ i ] = rtP . Gain1_Gain * rtB . aiseatx5p4 [ i ] ; }
gpv2q2mna0 ( rtS , rtB . jr2eclq22h , & rtB . lsxposbkab [ 0 ] , rtB .
llqrd441m5 , & rtB . gpv2q2mna0v , & rtDW . gpv2q2mna0v ) ; aa2j2wnloo ( rtS
, rtB . eo33rm2kiy , & rtB . lsxposbkab [ 0 ] , rtB . llqrd441m5 , & rtB .
aa2j2wnloo2 , & rtDW . aa2j2wnloo2 ) ; if ( rtB . eo33rm2kiy != 0 ) { rtB .
p52yfpva5l [ 0 ] = rtB . aa2j2wnloo2 . otn2ta4rye ; rtB . p52yfpva5l [ 1 ] =
rtB . aa2j2wnloo2 . ow32b43xgs ; } else { rtB . p52yfpva5l [ 0 ] = rtB .
gpv2q2mna0v . j2nl0k3bjo ; rtB . p52yfpva5l [ 1 ] = rtB . gpv2q2mna0v .
dxu5h4veqy ; } if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
oxvhzb4uhf ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX . iip1hksxhe
>= rtP . Integrator_UpperSat_pm1zhfhqin ) { if ( rtX . iip1hksxhe != rtP .
Integrator_UpperSat_pm1zhfhqin ) { rtX . iip1hksxhe = rtP .
Integrator_UpperSat_pm1zhfhqin ; ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; } rtDW . cxei33jqmq = 3 ; } else if ( rtX . iip1hksxhe <= rtP .
Integrator_LowerSat_nkt4rnjn03 ) { if ( rtX . iip1hksxhe != rtP .
Integrator_LowerSat_nkt4rnjn03 ) { rtX . iip1hksxhe = rtP .
Integrator_LowerSat_nkt4rnjn03 ; ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; } rtDW . cxei33jqmq = 4 ; } else { if ( rtDW . cxei33jqmq != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . cxei33jqmq = 0
; } rtB . ckayt42vf3 = rtX . iip1hksxhe ; } else { rtB . ckayt42vf3 = rtX .
iip1hksxhe ; } { real_T * * uBuffer = ( real_T * * ) & rtDW . nr4hpz0s5b .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T appliedDelay ;
rtB . oijk30i103 = rt_VTDelayfindtDInterpolate ( rtX . imjxbjnrao , * uBuffer
, rtDW . e3u5ld2y51 . CircularBufSize , rtDW . e3u5ld2y51 . Head , rtDW .
e3u5ld2y51 . Tail , & rtDW . e3u5ld2y51 . Last , simTime , 0.0 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) ==
ssGetT ( rtS ) ) ) , rtP . VariableTransportDelay_InitOutput_ly4stoovo0 , &
appliedDelay ) ; } rtB . jkth2sfciv = rtX . hvdzss0qy0 ; rtB . psgxvcmjhn =
ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . lp022slzwu = ( rtB . psgxvcmjhn >= rtP .
Constant_Value_amasrcypll ) ; } rtB . lbe40ygcva = rtDW . lp022slzwu ; rtB .
mqhymewypv = rtDW . puptsnuvic ; } if ( rtB . lbe40ygcva ) { rtB . f2eidvmh01
= rtB . jkth2sfciv - rtB . oijk30i103 ; rtB . ermyprlyya = rtB . f2eidvmh01 *
rtB . exj242slie ; rtB . hhnk2g0wfl = rtB . ermyprlyya ; } else { rtB .
hhnk2g0wfl = rtB . mqhymewypv ; } rtB . gphcjhvv1a = rtB . hhnk2g0wfl * rtB .
pe3tnbqbgy ; rtB . jvo1ddk5yj = rtP . Continuous_Kp * rtB . gphcjhvv1a ; rtB
. gbqdu1hcwl = rtP . Continuous_Ki * rtB . gphcjhvv1a ; rtB . k0pwj4jxiq =
rtP . Continuous_Kd * rtB . gphcjhvv1a ; rtB . dijcpphi4p = 0.0 ; rtB .
dijcpphi4p += rtP . TransferFcn_C * rtX . mgdsbp3tlu ; rtB . dijcpphi4p +=
rtP . TransferFcn_D * rtB . k0pwj4jxiq ; rtB . amr33vumq0 = ( rtB .
jvo1ddk5yj + rtB . ckayt42vf3 ) + rtB . dijcpphi4p ; if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . bisetz5iuz = rtB . amr33vumq0 >= rtP . Saturation2_UpperSat
? 1 : rtB . amr33vumq0 > rtP . Saturation2_LowerSat ? 0 : - 1 ; } rtB .
gc2xht4yqo = rtDW . bisetz5iuz == 1 ? rtP . Saturation2_UpperSat : rtDW .
bisetz5iuz == - 1 ? rtP . Saturation2_LowerSat : rtB . amr33vumq0 ; rtB .
iosedcm1tf = rtP . Gain10_Gain * rtB . gc2xht4yqo ; if ( ( rtDW . hrtqjrd53x
>= ssGetTaskTime ( rtS , 0 ) ) && ( rtDW . pvzxgas2b3 >= ssGetTaskTime ( rtS
, 0 ) ) ) { rtB . oll4rfkmhz = rtB . iosedcm1tf ; } else { if ( ( ( rtDW .
hrtqjrd53x < rtDW . pvzxgas2b3 ) && ( rtDW . pvzxgas2b3 < ssGetTaskTime ( rtS
, 0 ) ) ) || ( ( rtDW . hrtqjrd53x >= rtDW . pvzxgas2b3 ) && ( rtDW .
hrtqjrd53x >= ssGetTaskTime ( rtS , 0 ) ) ) ) { itji0osmqd = ssGetTaskTime (
rtS , 0 ) - rtDW . pvzxgas2b3 ; jmmiv3kip3 = rtDW . ejvm3rk4rw ; } else {
itji0osmqd = ssGetTaskTime ( rtS , 0 ) - rtDW . hrtqjrd53x ; jmmiv3kip3 =
rtDW . do51saudm1 ; } dz5jyu5ho0 = itji0osmqd * rtP . RateLimiter_RisingLim ;
je2ubjyoi0 = rtB . iosedcm1tf - jmmiv3kip3 ; if ( je2ubjyoi0 > dz5jyu5ho0 ) {
rtB . oll4rfkmhz = jmmiv3kip3 + dz5jyu5ho0 ; } else { itji0osmqd *= rtP .
RateLimiter_FallingLim ; if ( je2ubjyoi0 < itji0osmqd ) { rtB . oll4rfkmhz =
jmmiv3kip3 + itji0osmqd ; } else { rtB . oll4rfkmhz = rtB . iosedcm1tf ; } }
} rtB . cnh4llzau0 = rtX . mlt40cyrau ; rtB . aebuj4jliw = rtP . A11_Gain *
rtB . cnh4llzau0 ; rtB . f2yfeiz4wx = rtX . fb24y2esxb ; rtB . mm4x5kerfj =
rtP . A12_Gain * rtB . f2yfeiz4wx ; rtB . ejg1ybzhgl = rtP . A21_Gain * rtB .
cnh4llzau0 ; rtB . k1rxqwgc5o = rtP . A22_Gain * rtB . f2yfeiz4wx ; rtB .
n4ots5cknz = rtB . aebuj4jliw + rtB . mm4x5kerfj ; rtB . brzgt5o0ly = rtB .
ejg1ybzhgl + rtB . k1rxqwgc5o ; rtB . fbrwvcuz2e = rtP . B11_Gain * rtB .
oll4rfkmhz ; rtB . lrkvpii4gh = rtB . n4ots5cknz + rtB . fbrwvcuz2e ; rtB .
orccexijhq = rtP . B21_Gain * rtB . oll4rfkmhz ; rtB . erof3sa2ef = rtB .
brzgt5o0ly + rtB . orccexijhq ; rtB . kyvouqb0no = ( rtP . C11_Gain * rtB .
cnh4llzau0 + rtP . C12_Gain * rtB . f2yfeiz4wx ) + rtP . Du_Gain * rtB .
oll4rfkmhz ; if ( rtB . exj242slie > rtP .
Toavoiddivisionbyzero_UpperSat_ipy2dfjdyr ) { rtB . gungbq04sb = rtP .
Toavoiddivisionbyzero_UpperSat_ipy2dfjdyr ; } else if ( rtB . exj242slie <
rtP . Toavoiddivisionbyzero_LowerSat_ipo4dvmiva ) { rtB . gungbq04sb = rtP .
Toavoiddivisionbyzero_LowerSat_ipo4dvmiva ; } else { rtB . gungbq04sb = rtB .
exj242slie ; } rtB . b4jfht23g2 = 1.0 / rtB . gungbq04sb ; for ( i = 0 ; i <
3 ; i ++ ) { rtB . f0vgkk3bhk [ i ] = 0.0 ; rtB . f0vgkk3bhk [ i ] += rtP .
Gain3_Gain_jp2ndmjqu5 [ i ] * rtB . ffvcceoghv [ 0 ] ; rtB . f0vgkk3bhk [ i ]
+= rtP . Gain3_Gain_jp2ndmjqu5 [ i + 3 ] * rtB . ffvcceoghv [ 1 ] ; rtB .
f0vgkk3bhk [ i ] += rtP . Gain3_Gain_jp2ndmjqu5 [ i + 6 ] * rtB . ffvcceoghv
[ 2 ] ; rtB . dvkqumepgk [ i ] = rtP . Gain1_Gain_nhidfscigt * rtB .
f0vgkk3bhk [ i ] ; } gpv2q2mna0 ( rtS , rtB . bjycl5wbcz , & rtB . dvkqumepgk
[ 0 ] , rtB . llqrd441m5 , & rtB . gbv0nikqj2 , & rtDW . gbv0nikqj2 ) ;
aa2j2wnloo ( rtS , rtB . ejjuk1fwje , & rtB . dvkqumepgk [ 0 ] , rtB .
llqrd441m5 , & rtB . hl5zrirewt , & rtDW . hl5zrirewt ) ; if ( rtB .
ejjuk1fwje != 0 ) { rtB . fvbww5mjui [ 0 ] = rtB . hl5zrirewt . otn2ta4rye ;
rtB . fvbww5mjui [ 1 ] = rtB . hl5zrirewt . ow32b43xgs ; } else { rtB .
fvbww5mjui [ 0 ] = rtB . gbv0nikqj2 . j2nl0k3bjo ; rtB . fvbww5mjui [ 1 ] =
rtB . gbv0nikqj2 . dxu5h4veqy ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) &&
ssIsMajorTimeStep ( rtS ) ) { if ( rtB . ogehm3eyx3 > 0 ) { if ( ! rtDW .
bv4jm4qenv ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . bv4jm4qenv =
true ; } } else if ( rtDW . bv4jm4qenv ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . bv4jm4qenv =
false ; } } if ( rtDW . bv4jm4qenv ) { rtB . gahdo2523m = rtB . j2eixrpwyy *
muDoubleScalarCos ( rtB . llqrd441m5 ) - rtB . exoldmyxco * muDoubleScalarSin
( rtB . llqrd441m5 ) ; rtB . brq4reciat = rtB . j2eixrpwyy *
muDoubleScalarSin ( rtB . llqrd441m5 ) + rtB . exoldmyxco * muDoubleScalarCos
( rtB . llqrd441m5 ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
c2l3p2qtjf ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsMajorTimeStep (
rtS ) ) { if ( rtB . oakfin4jis > 0 ) { if ( ! rtDW . fbzp2gawrm ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . fbzp2gawrm =
true ; } } else if ( rtDW . fbzp2gawrm ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . fbzp2gawrm =
false ; } } if ( rtDW . fbzp2gawrm ) { rtB . mv2ve5xuao = rtB . j2eixrpwyy *
muDoubleScalarSin ( rtB . llqrd441m5 ) + rtB . exoldmyxco * muDoubleScalarCos
( rtB . llqrd441m5 ) ; rtB . lzxedsxie0 = - rtB . j2eixrpwyy *
muDoubleScalarCos ( rtB . llqrd441m5 ) + rtB . exoldmyxco * muDoubleScalarSin
( rtB . llqrd441m5 ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
kza5ow0kr4 ) ; } } if ( rtB . ogehm3eyx3 != 0 ) { rtB . gimxw5025n [ 0 ] =
rtB . gahdo2523m ; rtB . gimxw5025n [ 1 ] = rtB . brq4reciat ; } else { rtB .
gimxw5025n [ 0 ] = rtB . mv2ve5xuao ; rtB . gimxw5025n [ 1 ] = rtB .
lzxedsxie0 ; } rtB . j2ygziwuza [ 0 ] = rtB . gimxw5025n [ 0 ] ; rtB .
j2ygziwuza [ 1 ] = rtB . gimxw5025n [ 1 ] ; rtB . j2ygziwuza [ 2 ] = rtP .
Constant_Value_faygct0s2b ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . i3co5cpqer [
i ] = 0.0 ; rtB . i3co5cpqer [ i ] += rtP . Gain3_Gain_mvygasyxhr [ i ] * rtB
. j2ygziwuza [ 0 ] ; rtB . i3co5cpqer [ i ] += rtP . Gain3_Gain_mvygasyxhr [
i + 3 ] * rtB . j2ygziwuza [ 1 ] ; rtB . i3co5cpqer [ i ] += rtP .
Gain3_Gain_mvygasyxhr [ i + 6 ] * rtB . j2ygziwuza [ 2 ] ; rtB . pusmndwhp4 [
i ] = rtB . i3co5cpqer [ i ] - rtB . paaqohv05q [ i ] ; } rtB . li0okspf41 =
0.0 ; rtB . li0okspf41 += rtP . TransferFcn1_C [ 0 ] * rtX . jh55bpubqj [ 0 ]
; rtB . li0okspf41 += rtP . TransferFcn1_C [ 1 ] * rtX . jh55bpubqj [ 1 ] ;
rtB . eqrscq4msa = 0.0 ; rtB . eqrscq4msa += rtP . TransferFcn2_C [ 0 ] * rtX
. jn4nrdhpx1 [ 0 ] ; rtB . eqrscq4msa += rtP . TransferFcn2_C [ 1 ] * rtX .
jn4nrdhpx1 [ 1 ] ; rtB . mv0i5cphjf = 0.0 ; rtB . mv0i5cphjf += rtP .
TransferFcn_C_ebeqd4pm5a [ 0 ] * rtX . fyyiprok3t [ 0 ] ; rtB . mv0i5cphjf +=
rtP . TransferFcn_C_ebeqd4pm5a [ 1 ] * rtX . fyyiprok3t [ 1 ] ; rtB .
bt2aomm4y4 = ( ( rtP . Gain2_Gain_asqeevkcou * rtB . li0okspf41 + rtB .
mv0i5cphjf ) + rtP . Gain3_Gain_gnz4vn3ehd * rtB . eqrscq4msa ) * rtP . ki +
rtP . kp * rtB . pusmndwhp4 [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . bj5uxavhae = rtP . Constant3_Value_nxfd0r3vwv ; rtB . a4ynar3r0p = rtP
. Constant4_Value_pzmijoxky1 ; } jmmiv3kip3 = look1_pbinlxpw (
muDoubleScalarRem ( ssGetT ( rtS ) + rtB . bj5uxavhae , rtB . a4ynar3r0p ) *
rtP . uib1_Gain , rtP . uDLookupTable_bp01Data , rtP .
uDLookupTable_tableData , & rtDW . mr1ke3zacb , 2U ) ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . kd4hozccoi = rtP . Constant2_Value_imsydp4sjx ; } rtB
. itzulpyuw2 = ( ( jmmiv3kip3 - rtB . kd4hozccoi ) * rtB . dsjsfniaum + rtP .
PWMGenerator2Level_MinMax [ 0 ] ) + rtB . dsjsfniaum ; rtB . otuvlsx5ys = 0.0
; rtB . otuvlsx5ys += rtP . TransferFcn_C_gvrgkkm0gy [ 0 ] * rtX . bjpvgeyygb
[ 0 ] ; rtB . otuvlsx5ys += rtP . TransferFcn_C_gvrgkkm0gy [ 1 ] * rtX .
bjpvgeyygb [ 1 ] ; rtB . j0n1jzgntq = 0.0 ; rtB . j0n1jzgntq += rtP .
TransferFcn1_C_kgy1sslmk0 [ 0 ] * rtX . jkhhrdnef2 [ 0 ] ; rtB . j0n1jzgntq
+= rtP . TransferFcn1_C_kgy1sslmk0 [ 1 ] * rtX . jkhhrdnef2 [ 1 ] ; rtB .
jmwusjiov1 = 0.0 ; rtB . jmwusjiov1 += rtP . TransferFcn2_C_hvsgpr5esg [ 0 ]
* rtX . ns23ofbiao [ 0 ] ; rtB . jmwusjiov1 += rtP .
TransferFcn2_C_hvsgpr5esg [ 1 ] * rtX . ns23ofbiao [ 1 ] ; rtB . jb4fsta5my =
( ( rtP . Gain2_Gain_nzx0saocj4 * rtB . j0n1jzgntq + rtB . otuvlsx5ys ) + rtP
. Gain3_Gain_hmwjolcezb * rtB . jmwusjiov1 ) * rtP . ki + rtP . kp * rtB .
pusmndwhp4 [ 0 ] ; rtB . hm5ofsqtib = 0.0 ; rtB . hm5ofsqtib += rtP .
TransferFcn_C_ieerxo0rjq [ 0 ] * rtX . fozte2xjae [ 0 ] ; rtB . hm5ofsqtib +=
rtP . TransferFcn_C_ieerxo0rjq [ 1 ] * rtX . fozte2xjae [ 1 ] ; rtB .
amhtuysrig = 0.0 ; rtB . amhtuysrig += rtP . TransferFcn1_C_lx3veeshxb [ 0 ]
* rtX . ggl1vuf0v0 [ 0 ] ; rtB . amhtuysrig += rtP .
TransferFcn1_C_lx3veeshxb [ 1 ] * rtX . ggl1vuf0v0 [ 1 ] ; rtB . aylp23sizt =
0.0 ; rtB . aylp23sizt += rtP . TransferFcn2_C_kjbo4vmtza [ 0 ] * rtX .
eavqvzqdwf [ 0 ] ; rtB . aylp23sizt += rtP . TransferFcn2_C_kjbo4vmtza [ 1 ]
* rtX . eavqvzqdwf [ 1 ] ; rtB . fdwocsfez5 = ( ( rtP . Gain2_Gain_n2c2zc5fut
* rtB . amhtuysrig + rtB . hm5ofsqtib ) + rtP . Gain3_Gain_gzq4wqubv2 * rtB .
aylp23sizt ) * rtP . ki + rtP . kp * rtB . pusmndwhp4 [ 1 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
ls1rbfacqf [ 0 ] = ( rtB . jb4fsta5my >= rtB . itzulpyuw2 ) ; rtDW .
ls1rbfacqf [ 1 ] = ( rtB . fdwocsfez5 >= rtB . itzulpyuw2 ) ; rtDW .
ls1rbfacqf [ 2 ] = ( rtB . bt2aomm4y4 >= rtB . itzulpyuw2 ) ; } rtB .
ejejjrbn43 [ 0 ] = rtDW . ls1rbfacqf [ 0 ] ; rtB . ejejjrbn43 [ 1 ] = rtDW .
ls1rbfacqf [ 1 ] ; rtB . ejejjrbn43 [ 2 ] = rtDW . ls1rbfacqf [ 2 ] ; } rtB .
cdgmcxdgxx [ 0 ] = rtB . ejejjrbn43 [ 0 ] ; rtB . cdgmcxdgxx [ 1 ] = ! rtB .
ejejjrbn43 [ 0 ] ; rtB . cdgmcxdgxx [ 2 ] = rtB . ejejjrbn43 [ 1 ] ; rtB .
cdgmcxdgxx [ 3 ] = ! rtB . ejejjrbn43 [ 1 ] ; rtB . cdgmcxdgxx [ 4 ] = rtB .
ejejjrbn43 [ 2 ] ; rtB . cdgmcxdgxx [ 5 ] = ! rtB . ejejjrbn43 [ 2 ] ; if (
ssIsSampleHit ( rtS , 5 , 0 ) ) { rtB . it4rtc1qod = rtDW . dcvx0x0nhj ; } if
( ssIsSampleHit ( rtS , 3 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) {
StructLogVar * svar = ( StructLogVar * ) rtDW . nowwneuenp . LoggedData [ 0 ]
; LogVar * var = svar -> signals . values ; { double locTime = ssGetTaskTime
( rtS , 3 ) ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ;
} { real_T up0 [ 3 ] ; up0 [ 0 ] = rtB . djau2g1olc [ 0 ] ; up0 [ 1 ] = rtB .
djau2g1olc [ 1 ] ; up0 [ 2 ] = rtB . djau2g1olc [ 2 ] ; rt_UpdateLogVar ( (
LogVar * ) var , up0 , 0 ) ; var = var -> next ; } { real_T up1 [ 3 ] ; up1 [
0 ] = rtB . paaqohv05q [ 0 ] ; up1 [ 1 ] = rtB . paaqohv05q [ 1 ] ; up1 [ 2 ]
= rtB . paaqohv05q [ 2 ] ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 ) ; }
} } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } if ( ssIsSampleHit ( rtS , 3 , 0
) ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtP .
ThreePhaseProgrammableVoltageSource_VariationEntity - 1.0 > 0.0 ) { if ( !
rtDW . nf2gbckq3n ) { if ( ssGetTaskTime ( rtS , 3 ) != ssGetTStart ( rtS ) )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . nf2gbckq3n =
true ; } } else if ( rtDW . nf2gbckq3n ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . jonetifjdl = rtB
. osecmroasz ; rtDW . k5octspggf = rtB . gei3qlbkau ; rtDW . nf2gbckq3n =
false ; } } if ( rtDW . nf2gbckq3n ) { if ( ssIsSampleHit ( rtS , 3 , 0 ) ) {
rtB . osecmroasz = rtDW . jonetifjdl ; if ( ssGetTaskTime ( rtS , 3 ) < rtP .
VariationSubSystem_Toff_Variation ) { je2ubjyoi0 = rtP . Step1_Y0 ; } else {
je2ubjyoi0 = rtP . Step1_YFinal ; } if ( ssGetTaskTime ( rtS , 3 ) < rtP .
VariationSubSystem_Ton_Variation ) { jmmiv3kip3 = rtP . Step_Y0 ; } else {
jmmiv3kip3 = rtP . Step_YFinal ; } rtB . gei3qlbkau = rtDW . k5octspggf ; if
( je2ubjyoi0 >= rtP . Switch2_Threshold ) { switch ( ( int32_T ) rtP .
ThreePhaseProgrammableVoltageSource_VariationType ) { case 1 : rtB .
k2r2gd5thc = rtP . VariationSubSystem_VariationStep * jmmiv3kip3 ; break ;
case 2 : rtB . k2r2gd5thc = rtB . gei3qlbkau ; break ; case 3 : rtB .
k2r2gd5thc = muDoubleScalarSin ( rtB . gei3qlbkau * rtB . dfsza0jb3r ) * rtP
. VariationSubSystem_VariationMag ; break ; default : rtB . k2r2gd5thc = rtP
. Constant5_Value_bojg2v1nr1 ; break ; } } else { rtB . k2r2gd5thc = rtDW .
kurtqaimb2 ; } if ( rtB . g524d0rboe ) { if ( ( ! ( je2ubjyoi0 != 0.0 ) ) &&
rtB . k0zgmoo03i ) { je2ubjyoi0 = rtP . Constant1_Value ; } else { je2ubjyoi0
= rtB . k2r2gd5thc ; } } else { je2ubjyoi0 = rtP . Constant5_Value ; } rtB .
hxgcychvxe = rtP . Gain2_Gain * je2ubjyoi0 ; if ( jmmiv3kip3 >= rtP .
Switch_Threshold ) { rtB . ojpmhqp3hb = rtB . aydt5pakqc ; } else { rtB .
ojpmhqp3hb = rtP . Constant4_Value ; } } if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . ee4ok4zlel ) ; } } } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID6 ( int_T tid ) { rtB . eo33rm2kiy = ( uint8_T ) ( rtP .
AlphaBetaZerotodq0_Alignment == rtP . CompareToConstant_const ) ; rtB .
jr2eclq22h = ( uint8_T ) ( rtP . AlphaBetaZerotodq0_Alignment == rtP .
CompareToConstant1_const ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC (
rtDW . oxvhzb4uhf ) ; } rtB . ejjuk1fwje = ( uint8_T ) ( rtP .
AlphaBetaZerotodq0_Alignment_hohufqrubs == rtP .
CompareToConstant_const_c3zde2cbi4 ) ; rtB . bjycl5wbcz = ( uint8_T ) ( rtP .
AlphaBetaZerotodq0_Alignment_hohufqrubs == rtP .
CompareToConstant1_const_efjr5x0wsv ) ; rtB . dsjsfniaum = ( rtP .
PWMGenerator2Level_MinMax [ 1 ] - rtP . PWMGenerator2Level_MinMax [ 0 ] ) *
rtP . Gain1_Gain_bxyi0qtgnl ; rtB . dcuhhc42lm = rtP . Q_Value ; rtB .
ogehm3eyx3 = ( uint8_T ) ( rtP . dq0toAlphaBetaZero_Alignment == rtP .
CompareToConstant_const_gsz3trqyjp ) ; rtB . oakfin4jis = ( uint8_T ) ( rtP .
dq0toAlphaBetaZero_Alignment == rtP . CompareToConstant1_const_hw4vovlkze ) ;
rtB . g524d0rboe = ( rtP .
ThreePhaseProgrammableVoltageSource_VariationEntity == rtP . Constant3_Value
) ; rtB . dfsza0jb3r = rtP . Gain1_Gain_onz34q5f5w * rtP .
VariationSubSystem_VariationFreq ; rtB . k0zgmoo03i = ( rtP .
ThreePhaseProgrammableVoltageSource_VariationType == rtP .
Constant3_Value_jeehzqq2f5 ) ; if ( rtP .
ThreePhaseProgrammableVoltageSource_VariationType == rtP .
Constant_Value_dvamm1lycs ) { rtB . aydt5pakqc = rtP .
VariationSubSystem_VariationRate ; } else { rtB . aydt5pakqc = rtP .
Constant2_Value ; } if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ee4ok4zlel ) ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
XDis * _rtXdis ; real_T HoldSine ; int32_T i ; _rtXdis = ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) ; if ( ssIsSampleHit ( rtS , 3 , 0 ) ) {
HoldSine = rtDW . m3xa5qdlgu ; rtDW . m3xa5qdlgu = rtDW . m3xa5qdlgu * rtP .
SineWaveA_HCos + rtDW . g4a2feilda * rtP . SineWaveA_Hsin ; rtDW . g4a2feilda
= rtDW . g4a2feilda * rtP . SineWaveA_HCos - HoldSine * rtP . SineWaveA_Hsin
; HoldSine = rtDW . ati3zogtqu ; rtDW . ati3zogtqu = rtDW . ati3zogtqu * rtP
. SineWaveB_HCos + rtDW . n5yzxageiq * rtP . SineWaveB_Hsin ; rtDW .
n5yzxageiq = rtDW . n5yzxageiq * rtP . SineWaveB_HCos - HoldSine * rtP .
SineWaveB_Hsin ; HoldSine = rtDW . hxzxqy2ytd ; rtDW . hxzxqy2ytd = rtDW .
hxzxqy2ytd * rtP . SineWaveC_HCos + rtDW . lpdpgewspm * rtP . SineWaveC_Hsin
; rtDW . lpdpgewspm = rtDW . lpdpgewspm * rtP . SineWaveC_HCos - HoldSine *
rtP . SineWaveC_Hsin ; { const real_T * As = ( real_T * ) rtDW . empra3chml .
AS ; const real_T * Bs = ( real_T * ) rtDW . empra3chml . BS ; real_T * xtmp
= ( real_T * ) rtDW . empra3chml . XTMP ; real_T accum ; accum = 0.0 ; accum
+= * ( As ++ ) * rtDW . naju1uwbkg [ 0 ] ; accum += * ( As ++ ) * rtDW .
naju1uwbkg [ 1 ] ; { int_T i1 ; const real_T * u0 ; for ( i1 = 0 ; i1 < 6 ;
i1 ++ ) { accum += * ( Bs ++ ) * 0.0 ; } accum += * ( Bs ++ ) * rtP .
Vdc_Amplitude ; accum += * ( Bs ++ ) * rtB . gktfzcs3fd ; accum += * ( Bs ++
) * rtB . dbmx3g5hpc ; accum += * ( Bs ++ ) * rtB . dm5evipofq ; } xtmp [ 0 ]
= accum ; accum = 0.0 ; accum += * ( As ++ ) * rtDW . naju1uwbkg [ 0 ] ;
accum += * ( As ++ ) * rtDW . naju1uwbkg [ 1 ] ; { int_T i1 ; const real_T *
u0 ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { accum += * ( Bs ++ ) * 0.0 ; } accum
+= * ( Bs ++ ) * rtP . Vdc_Amplitude ; accum += * ( Bs ++ ) * rtB .
gktfzcs3fd ; accum += * ( Bs ++ ) * rtB . dbmx3g5hpc ; accum += * ( Bs ++ ) *
rtB . dm5evipofq ; } xtmp [ 1 ] = accum ; rtDW . naju1uwbkg [ 0 ] = xtmp [ 0
] ; rtDW . naju1uwbkg [ 1 ] = xtmp [ 1 ] ; { int_T * gState = ( int_T * )
rtDW . empra3chml . G_STATE ; { int_T i1 ; const real_T * u1 = & rtB .
cdgmcxdgxx [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { * ( gState ++ ) = (
int_T ) u1 [ i1 ] ; } } } } for ( i = 0 ; i < 6 ; i ++ ) { rtDW . iz4mjb3fpi
[ i ] = rtB . bgjph5tzti [ i ] ; } rtDW . kanrys502u = rtB . kkx3bsha4q ;
rtDW . lc4skbr0sd = rtB . m5uukj3ycd ; rtDW . kmcobpcqvr += rtP .
FFInt_gainval_ajjzcdjezz * rtB . k5kueqchg5 ; } if ( ssIsSampleHit ( rtS , 2
, 0 ) ) { rtDW . il2g04n2zg += rtP . FFInt_gainval * rtB . dtyrdyfgxc ; }
rtDW . kuxuhbis4w = 0 ; switch ( rtDW . chgudtwki5 ) { case 3 : if ( rtB .
gc2xht4yqo < 0.0 ) { rtDW . chgudtwki5 = 1 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; case 4 : if (
rtB . gc2xht4yqo > 0.0 ) { rtDW . chgudtwki5 = 2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; } _rtXdis ->
iumu3kzzhr = ( ( rtDW . chgudtwki5 == 3 ) || ( rtDW . chgudtwki5 == 4 ) ) ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . o4yzgxidzo = rtB . kyvouqb0no ;
} if ( rtDW . ovo53pq3zf ) { { real_T * * uBuffer = ( real_T * * ) & rtDW .
mlq3s0zii4 . TUbufferPtrs [ 0 ] ; int numBuffers = 2 ; numBuffers = 3 ;
real_T simTime = ssGetT ( rtS ) ; rtDW . itw05pv4q1 . Head = ( ( rtDW .
itw05pv4q1 . Head < ( rtDW . itw05pv4q1 . CircularBufSize - 1 ) ) ? ( rtDW .
itw05pv4q1 . Head + 1 ) : 0 ) ; if ( rtDW . itw05pv4q1 . Head == rtDW .
itw05pv4q1 . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
itw05pv4q1 . CircularBufSize , & rtDW . itw05pv4q1 . Tail , & rtDW .
itw05pv4q1 . Head , & rtDW . itw05pv4q1 . Last , simTime - rtP .
VariableTransportDelay_MaxDelay , uBuffer , ( boolean_T ) 0 , ( boolean_T ) 1
, & rtDW . itw05pv4q1 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)1/Model/Variable\nTransport Delay_TUbuffer0"
, ( void * * ) ( & uBuffer [ 0 ] ) , numBuffers * rtDW . itw05pv4q1 .
CircularBufSize * sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer +
rtDW . itw05pv4q1 . CircularBufSize ) [ rtDW . itw05pv4q1 . Head ] = simTime
; ( * uBuffer + 2 * rtDW . itw05pv4q1 . CircularBufSize ) [ rtDW . itw05pv4q1
. Head ] = rtX . bpxu1bsrls ; ( * uBuffer ) [ rtDW . itw05pv4q1 . Head ] =
rtB . pqq2mzl5yy ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . edvu1xljbk
= rtB . klqpdibj32 ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
n2b5jg51yt . TUbufferPtrs [ 0 ] ; int numBuffers = 2 ; numBuffers = 3 ;
real_T simTime = ssGetT ( rtS ) ; rtDW . oyd0zxlfez . Head = ( ( rtDW .
oyd0zxlfez . Head < ( rtDW . oyd0zxlfez . CircularBufSize - 1 ) ) ? ( rtDW .
oyd0zxlfez . Head + 1 ) : 0 ) ; if ( rtDW . oyd0zxlfez . Head == rtDW .
oyd0zxlfez . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
oyd0zxlfez . CircularBufSize , & rtDW . oyd0zxlfez . Tail , & rtDW .
oyd0zxlfez . Head , & rtDW . oyd0zxlfez . Last , simTime - rtP .
VariableTransportDelay_MaxDelay_evwrynr4yh , uBuffer , ( boolean_T ) 0 , (
boolean_T ) 1 , & rtDW . oyd0zxlfez . MaxNewBufSize ) ) { ssSetErrorStatus (
rtS , "vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)2/Model/Variable\nTransport Delay_TUbuffer0"
, ( void * * ) ( & uBuffer [ 0 ] ) , numBuffers * rtDW . oyd0zxlfez .
CircularBufSize * sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer +
rtDW . oyd0zxlfez . CircularBufSize ) [ rtDW . oyd0zxlfez . Head ] = simTime
; ( * uBuffer + 2 * rtDW . oyd0zxlfez . CircularBufSize ) [ rtDW . oyd0zxlfez
. Head ] = rtX . jbjlk4lmud ; ( * uBuffer ) [ rtDW . oyd0zxlfez . Head ] =
rtB . hohn5tgzlv ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . d3leen4kcy
= rtB . onjteuktwt ; } } switch ( rtDW . cxei33jqmq ) { case 3 : if ( rtB .
gbqdu1hcwl < 0.0 ) { rtDW . cxei33jqmq = 1 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; case 4 : if (
rtB . gbqdu1hcwl > 0.0 ) { rtDW . cxei33jqmq = 2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; } _rtXdis ->
iip1hksxhe = ( ( rtDW . cxei33jqmq == 3 ) || ( rtDW . cxei33jqmq == 4 ) ) ; {
real_T * * uBuffer = ( real_T * * ) & rtDW . nr4hpz0s5b . TUbufferPtrs [ 0 ]
; int numBuffers = 2 ; numBuffers = 3 ; real_T simTime = ssGetT ( rtS ) ;
rtDW . e3u5ld2y51 . Head = ( ( rtDW . e3u5ld2y51 . Head < ( rtDW . e3u5ld2y51
. CircularBufSize - 1 ) ) ? ( rtDW . e3u5ld2y51 . Head + 1 ) : 0 ) ; if (
rtDW . e3u5ld2y51 . Head == rtDW . e3u5ld2y51 . Tail ) { if ( !
rt_TDelayUpdateTailOrGrowBuf ( & rtDW . e3u5ld2y51 . CircularBufSize , & rtDW
. e3u5ld2y51 . Tail , & rtDW . e3u5ld2y51 . Head , & rtDW . e3u5ld2y51 . Last
, simTime - rtP . VariableTransportDelay_MaxDelay_gjh2uwsyu4 , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 1 , & rtDW . e3u5ld2y51 . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Variable Frequency\nMean value/Model/Variable\nTransport Delay_TUbuffer0"
, ( void * * ) ( & uBuffer [ 0 ] ) , numBuffers * rtDW . e3u5ld2y51 .
CircularBufSize * sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer +
rtDW . e3u5ld2y51 . CircularBufSize ) [ rtDW . e3u5ld2y51 . Head ] = simTime
; ( * uBuffer + 2 * rtDW . e3u5ld2y51 . CircularBufSize ) [ rtDW . e3u5ld2y51
. Head ] = rtX . imjxbjnrao ; ( * uBuffer ) [ rtDW . e3u5ld2y51 . Head ] =
rtB . jkth2sfciv ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . puptsnuvic
= rtB . hhnk2g0wfl ; } if ( rtDW . hrtqjrd53x == ( rtInf ) ) { rtDW .
hrtqjrd53x = ssGetTaskTime ( rtS , 0 ) ; rtDW . do51saudm1 = rtB . oll4rfkmhz
; } else if ( rtDW . pvzxgas2b3 == ( rtInf ) ) { rtDW . pvzxgas2b3 =
ssGetTaskTime ( rtS , 0 ) ; rtDW . ejvm3rk4rw = rtB . oll4rfkmhz ; } else if
( rtDW . hrtqjrd53x < rtDW . pvzxgas2b3 ) { rtDW . hrtqjrd53x = ssGetTaskTime
( rtS , 0 ) ; rtDW . do51saudm1 = rtB . oll4rfkmhz ; } else { rtDW .
pvzxgas2b3 = ssGetTaskTime ( rtS , 0 ) ; rtDW . ejvm3rk4rw = rtB . oll4rfkmhz
; } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { rtDW . dcvx0x0nhj = rtB .
it4rtc1qod ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) && rtDW . nf2gbckq3n &&
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW . jonetifjdl += rtP .
DiscreteTimeIntegrator_gainval * rtB . hxgcychvxe ; rtDW . k5octspggf += rtP
. DiscreteTimeIntegrator1_gainval * rtB . ojpmhqp3hb ; rtDW . kurtqaimb2 =
rtB . k2r2gd5thc ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID6 ( int_T
tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDis *
_rtXdis ; XDot * _rtXdot ; _rtXdis = ( ( XDis * ) ssGetContStateDisabled (
rtS ) ) ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; if ( _rtXdis ->
iumu3kzzhr ) { _rtXdot -> iumu3kzzhr = 0.0 ; } else { _rtXdot -> iumu3kzzhr =
rtB . gc2xht4yqo ; } if ( rtDW . ovo53pq3zf ) { { real_T instantDelay ;
instantDelay = rtB . hs004dp4hy ; if ( instantDelay > rtP .
VariableTransportDelay_MaxDelay ) { instantDelay = rtP .
VariableTransportDelay_MaxDelay ; } if ( instantDelay < 0.0 ) { ( ( XDot * )
ssGetdX ( rtS ) ) -> bpxu1bsrls = 0 ; } else { ( ( XDot * ) ssGetdX ( rtS ) )
-> bpxu1bsrls = 1.0 / instantDelay ; } } _rtXdot -> c2tj4z32zx = rtB .
p52yfpva5l [ 0 ] ; { real_T instantDelay ; instantDelay = rtB . omw4a1utb1 ;
if ( instantDelay > rtP . VariableTransportDelay_MaxDelay_evwrynr4yh ) {
instantDelay = rtP . VariableTransportDelay_MaxDelay_evwrynr4yh ; } if (
instantDelay < 0.0 ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> jbjlk4lmud = 0 ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> jbjlk4lmud = 1.0 / instantDelay ; }
} _rtXdot -> hcrv11zemx = rtB . p52yfpva5l [ 1 ] ; } else { { real_T * dx ;
int_T i ; dx = & ( ( ( XDot * ) ssGetdX ( rtS ) ) -> bpxu1bsrls ) ; for ( i =
0 ; i < 4 ; i ++ ) { dx [ i ] = 0.0 ; } } } if ( _rtXdis -> iip1hksxhe ) {
_rtXdot -> iip1hksxhe = 0.0 ; } else { _rtXdot -> iip1hksxhe = rtB .
gbqdu1hcwl ; } { real_T instantDelay ; instantDelay = rtB . b4jfht23g2 ; if (
instantDelay > rtP . VariableTransportDelay_MaxDelay_gjh2uwsyu4 ) {
instantDelay = rtP . VariableTransportDelay_MaxDelay_gjh2uwsyu4 ; } if (
instantDelay < 0.0 ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> imjxbjnrao = 0 ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> imjxbjnrao = 1.0 / instantDelay ; }
} _rtXdot -> hvdzss0qy0 = rtB . fvbww5mjui [ 1 ] ; _rtXdot -> mgdsbp3tlu =
0.0 ; _rtXdot -> mgdsbp3tlu += rtP . TransferFcn_A * rtX . mgdsbp3tlu ;
_rtXdot -> mgdsbp3tlu += rtB . k0pwj4jxiq ; _rtXdot -> mlt40cyrau = rtB .
lrkvpii4gh ; _rtXdot -> fb24y2esxb = rtB . erof3sa2ef ; _rtXdot -> jh55bpubqj
[ 0 ] = 0.0 ; _rtXdot -> jh55bpubqj [ 0 ] += rtP . TransferFcn1_A [ 0 ] * rtX
. jh55bpubqj [ 0 ] ; _rtXdot -> jh55bpubqj [ 1 ] = 0.0 ; _rtXdot ->
jh55bpubqj [ 0 ] += rtP . TransferFcn1_A [ 1 ] * rtX . jh55bpubqj [ 1 ] ;
_rtXdot -> jh55bpubqj [ 1 ] += rtX . jh55bpubqj [ 0 ] ; _rtXdot -> jh55bpubqj
[ 0 ] += rtB . pusmndwhp4 [ 2 ] ; _rtXdot -> jn4nrdhpx1 [ 0 ] = 0.0 ; _rtXdot
-> jn4nrdhpx1 [ 0 ] += rtP . TransferFcn2_A [ 0 ] * rtX . jn4nrdhpx1 [ 0 ] ;
_rtXdot -> jn4nrdhpx1 [ 1 ] = 0.0 ; _rtXdot -> jn4nrdhpx1 [ 0 ] += rtP .
TransferFcn2_A [ 1 ] * rtX . jn4nrdhpx1 [ 1 ] ; _rtXdot -> jn4nrdhpx1 [ 1 ]
+= rtX . jn4nrdhpx1 [ 0 ] ; _rtXdot -> jn4nrdhpx1 [ 0 ] += rtB . pusmndwhp4 [
2 ] ; _rtXdot -> fyyiprok3t [ 0 ] = 0.0 ; _rtXdot -> fyyiprok3t [ 0 ] += rtP
. TransferFcn_A_dt3anvvvjk [ 0 ] * rtX . fyyiprok3t [ 0 ] ; _rtXdot ->
fyyiprok3t [ 1 ] = 0.0 ; _rtXdot -> fyyiprok3t [ 0 ] += rtP .
TransferFcn_A_dt3anvvvjk [ 1 ] * rtX . fyyiprok3t [ 1 ] ; _rtXdot ->
fyyiprok3t [ 1 ] += rtX . fyyiprok3t [ 0 ] ; _rtXdot -> fyyiprok3t [ 0 ] +=
rtB . pusmndwhp4 [ 2 ] ; _rtXdot -> bjpvgeyygb [ 0 ] = 0.0 ; _rtXdot ->
bjpvgeyygb [ 0 ] += rtP . TransferFcn_A_nzocbi1yil [ 0 ] * rtX . bjpvgeyygb [
0 ] ; _rtXdot -> bjpvgeyygb [ 1 ] = 0.0 ; _rtXdot -> bjpvgeyygb [ 0 ] += rtP
. TransferFcn_A_nzocbi1yil [ 1 ] * rtX . bjpvgeyygb [ 1 ] ; _rtXdot ->
bjpvgeyygb [ 1 ] += rtX . bjpvgeyygb [ 0 ] ; _rtXdot -> bjpvgeyygb [ 0 ] +=
rtB . pusmndwhp4 [ 0 ] ; _rtXdot -> jkhhrdnef2 [ 0 ] = 0.0 ; _rtXdot ->
jkhhrdnef2 [ 0 ] += rtP . TransferFcn1_A_oq1eexzdia [ 0 ] * rtX . jkhhrdnef2
[ 0 ] ; _rtXdot -> jkhhrdnef2 [ 1 ] = 0.0 ; _rtXdot -> jkhhrdnef2 [ 0 ] +=
rtP . TransferFcn1_A_oq1eexzdia [ 1 ] * rtX . jkhhrdnef2 [ 1 ] ; _rtXdot ->
jkhhrdnef2 [ 1 ] += rtX . jkhhrdnef2 [ 0 ] ; _rtXdot -> jkhhrdnef2 [ 0 ] +=
rtB . pusmndwhp4 [ 0 ] ; _rtXdot -> ns23ofbiao [ 0 ] = 0.0 ; _rtXdot ->
ns23ofbiao [ 0 ] += rtP . TransferFcn2_A_ls5rzge3gu [ 0 ] * rtX . ns23ofbiao
[ 0 ] ; _rtXdot -> ns23ofbiao [ 1 ] = 0.0 ; _rtXdot -> ns23ofbiao [ 0 ] +=
rtP . TransferFcn2_A_ls5rzge3gu [ 1 ] * rtX . ns23ofbiao [ 1 ] ; _rtXdot ->
ns23ofbiao [ 1 ] += rtX . ns23ofbiao [ 0 ] ; _rtXdot -> ns23ofbiao [ 0 ] +=
rtB . pusmndwhp4 [ 0 ] ; _rtXdot -> fozte2xjae [ 0 ] = 0.0 ; _rtXdot ->
fozte2xjae [ 0 ] += rtP . TransferFcn_A_ctlxcv4srh [ 0 ] * rtX . fozte2xjae [
0 ] ; _rtXdot -> fozte2xjae [ 1 ] = 0.0 ; _rtXdot -> fozte2xjae [ 0 ] += rtP
. TransferFcn_A_ctlxcv4srh [ 1 ] * rtX . fozte2xjae [ 1 ] ; _rtXdot ->
fozte2xjae [ 1 ] += rtX . fozte2xjae [ 0 ] ; _rtXdot -> fozte2xjae [ 0 ] +=
rtB . pusmndwhp4 [ 1 ] ; _rtXdot -> ggl1vuf0v0 [ 0 ] = 0.0 ; _rtXdot ->
ggl1vuf0v0 [ 0 ] += rtP . TransferFcn1_A_dxdwz5zlll [ 0 ] * rtX . ggl1vuf0v0
[ 0 ] ; _rtXdot -> ggl1vuf0v0 [ 1 ] = 0.0 ; _rtXdot -> ggl1vuf0v0 [ 0 ] +=
rtP . TransferFcn1_A_dxdwz5zlll [ 1 ] * rtX . ggl1vuf0v0 [ 1 ] ; _rtXdot ->
ggl1vuf0v0 [ 1 ] += rtX . ggl1vuf0v0 [ 0 ] ; _rtXdot -> ggl1vuf0v0 [ 0 ] +=
rtB . pusmndwhp4 [ 1 ] ; _rtXdot -> eavqvzqdwf [ 0 ] = 0.0 ; _rtXdot ->
eavqvzqdwf [ 0 ] += rtP . TransferFcn2_A_pejgnp0mdw [ 0 ] * rtX . eavqvzqdwf
[ 0 ] ; _rtXdot -> eavqvzqdwf [ 1 ] = 0.0 ; _rtXdot -> eavqvzqdwf [ 0 ] +=
rtP . TransferFcn2_A_pejgnp0mdw [ 1 ] * rtX . eavqvzqdwf [ 1 ] ; _rtXdot ->
eavqvzqdwf [ 1 ] += rtX . eavqvzqdwf [ 0 ] ; _rtXdot -> eavqvzqdwf [ 0 ] +=
rtB . pusmndwhp4 [ 1 ] ; } void MdlProjection ( void ) { } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> dprhnx0hk5 = ssGetT ( rtS )
- rtP . P10kW_Time ; _rtZCSV -> nmcpophsx3 = rtX . iumu3kzzhr - rtP .
Constant2_Value_awyv320bt3 ; switch ( rtDW . chgudtwki5 ) { case 1 : _rtZCSV
-> jgpeeoiue2 = 0.0 ; _rtZCSV -> iuxaqwhjjh = rtP . Integrator_UpperSat - rtP
. Integrator_LowerSat ; break ; case 2 : _rtZCSV -> jgpeeoiue2 = rtP .
Integrator_LowerSat - rtP . Integrator_UpperSat ; _rtZCSV -> iuxaqwhjjh = 0.0
; break ; default : _rtZCSV -> jgpeeoiue2 = rtX . iumu3kzzhr - rtP .
Integrator_UpperSat ; _rtZCSV -> iuxaqwhjjh = rtX . iumu3kzzhr - rtP .
Integrator_LowerSat ; break ; } if ( ( rtDW . chgudtwki5 == 3 ) || ( rtDW .
chgudtwki5 == 4 ) ) { _rtZCSV -> oqivsa4eyr = rtB . gc2xht4yqo ; } else {
_rtZCSV -> oqivsa4eyr = 0.0 ; } _rtZCSV -> m1itfgxaol = rtB . llqrd441m5 -
rtP . HitCrossing_Offset ; if ( rtDW . ovo53pq3zf ) { _rtZCSV -> jd55xiah2i =
rtB . emtuteg24p - rtP . Constant_Value ; _rtZCSV -> kcppnfkfuz = rtB .
asbptj5zaz - rtP . Constant_Value_n0qkhh1fth ; _rtZCSV -> kpi30mmi2d = rtB .
jfashjspdq - rtP . Saturation_UpperSat ; _rtZCSV -> flx3eb04bc = rtB .
jfashjspdq - rtP . Saturation_LowerSat ; } else { { real_T * zcsv = & ( ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> jd55xiah2i ) ; int_T i ; for (
i = 0 ; i < 4 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } switch ( rtDW . cxei33jqmq
) { case 1 : _rtZCSV -> ix3q42sklm = 0.0 ; _rtZCSV -> jdi1rp00nt = rtP .
Integrator_UpperSat_pm1zhfhqin - rtP . Integrator_LowerSat_nkt4rnjn03 ; break
; case 2 : _rtZCSV -> ix3q42sklm = rtP . Integrator_LowerSat_nkt4rnjn03 - rtP
. Integrator_UpperSat_pm1zhfhqin ; _rtZCSV -> jdi1rp00nt = 0.0 ; break ;
default : _rtZCSV -> ix3q42sklm = rtX . iip1hksxhe - rtP .
Integrator_UpperSat_pm1zhfhqin ; _rtZCSV -> jdi1rp00nt = rtX . iip1hksxhe -
rtP . Integrator_LowerSat_nkt4rnjn03 ; break ; } if ( ( rtDW . cxei33jqmq ==
3 ) || ( rtDW . cxei33jqmq == 4 ) ) { _rtZCSV -> d2qflxrvek = rtB .
gbqdu1hcwl ; } else { _rtZCSV -> d2qflxrvek = 0.0 ; } _rtZCSV -> fipbq4kbkj =
rtB . psgxvcmjhn - rtP . Constant_Value_amasrcypll ; _rtZCSV -> impstjptgt =
rtB . amr33vumq0 - rtP . Saturation2_UpperSat ; _rtZCSV -> nocih0nohz = rtB .
amr33vumq0 - rtP . Saturation2_LowerSat ; _rtZCSV -> m43iiyidnn [ 0 ] = rtB .
jb4fsta5my - rtB . itzulpyuw2 ; _rtZCSV -> m43iiyidnn [ 1 ] = rtB .
fdwocsfez5 - rtB . itzulpyuw2 ; _rtZCSV -> m43iiyidnn [ 2 ] = rtB .
bt2aomm4y4 - rtB . itzulpyuw2 ; } void MdlTerminate ( void ) {
rt_TDelayFreeBuf ( rtDW . mlq3s0zii4 . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . n2b5jg51yt . TUbufferPtrs [ 0 ] ) ; { free ( rtDW .
empra3chml . AS ) ; free ( rtDW . empra3chml . BS ) ; free ( rtDW .
empra3chml . CS ) ; free ( rtDW . empra3chml . DS ) ; free ( rtDW .
empra3chml . DX_COL ) ; free ( rtDW . empra3chml . TMP2 ) ; free ( rtDW .
empra3chml . BD_COL ) ; free ( rtDW . empra3chml . TMP1 ) ; free ( rtDW .
empra3chml . XTMP ) ; free ( rtDW . empra3chml . G_STATE ) ; free ( rtDW .
empra3chml . SWITCH_STATUS ) ; free ( rtDW . empra3chml . SW_CHG ) ; free (
rtDW . empra3chml . SWITCH_STATUS_INIT ) ; } rt_TDelayFreeBuf ( rtDW .
nr4hpz0s5b . TUbufferPtrs [ 0 ] ) ; } static void mr_Sim6_cacheDataAsMxArray
( mxArray * destArray , mwIndex i , int j , const void * srcData , size_t
numBytes ) ; static void mr_Sim6_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_Sim6_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_Sim6_restoreDataFromMxArray ( void * destData , const mxArray
* srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_Sim6_cacheBitFieldToMxArray ( mxArray
* destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_Sim6_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_Sim6_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_Sim6_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_Sim6_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void
mr_Sim6_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T *
varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j )
) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T
* ) srcData , numBytes ) ; } static void
mr_Sim6_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_Sim6_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_Sim6_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_Sim6_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber
( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( double ) fieldVal )
) ; } static uint_T mr_Sim6_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_Sim6_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_Sim6_GetDWork ( ) { static const char * ssDWFieldNames [ 3
] = { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Sim6_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 69 ] = {
"rtDW.naju1uwbkg" , "rtDW.iz4mjb3fpi" , "rtDW.kanrys502u" , "rtDW.il2g04n2zg"
, "rtDW.lc4skbr0sd" , "rtDW.kmcobpcqvr" , "rtDW.dcvx0x0nhj" ,
"rtDW.jonetifjdl" , "rtDW.k5octspggf" , "rtDW.kurtqaimb2" , "rtDW.m3xa5qdlgu"
, "rtDW.g4a2feilda" , "rtDW.ati3zogtqu" , "rtDW.n5yzxageiq" ,
"rtDW.hxzxqy2ytd" , "rtDW.lpdpgewspm" , "rtDW.bwt1hrltpz" , "rtDW.o4yzgxidzo"
, "rtDW.puptsnuvic" , "rtDW.do51saudm1" , "rtDW.ejvm3rk4rw" ,
"rtDW.hrtqjrd53x" , "rtDW.pvzxgas2b3" , "rtDW.edvu1xljbk" , "rtDW.d3leen4kcy"
, "rtDW.jycqzsqlqh" , "rtDW.omzfzlvkmy" , "rtDW.hrjhnmw2gy" ,
"rtDW.cbxygsrulg" , "rtDW.oehqsdtju1" , "rtDW.ebrnrfebzf" , "rtDW.mr1ke3zacb"
, "rtDW.crtkqsbmaj" , "rtDW.kuxuhbis4w" , "rtDW.e3u5ld2y51" ,
"rtDW.itw05pv4q1" , "rtDW.oyd0zxlfez" , "rtDW.dg3sdnhfhz" , "rtDW.chgudtwki5"
, "rtDW.cxei33jqmq" , "rtDW.bisetz5iuz" , "rtDW.lguevo5cl5" ,
"rtDW.ee4ok4zlel" , "rtDW.mvk1crirkl" , "rtDW.c2l3p2qtjf" , "rtDW.kza5ow0kr4"
, "rtDW.oxvhzb4uhf" , "rtDW.aw1t1zwgas" , "rtDW.aisofpnorv" ,
"rtDW.hsca3knam3" , "rtDW.loledzy1qu" , "rtDW.oacr45potf" , "rtDW.lp022slzwu"
, "rtDW.ls1rbfacqf" , "rtDW.navvsf1ufo" , "rtDW.fbyhlicb5e" ,
"rtDW.nf2gbckq3n" , "rtDW.o2b5vrjagl" , "rtDW.bv4jm4qenv" , "rtDW.fbzp2gawrm"
, "rtDW.ovo53pq3zf" , "rtDW.hl5zrirewt.fqy4beoqau" ,
"rtDW.hl5zrirewt.mvk4qyxu0n" , "rtDW.gbv0nikqj2.ofjd3uadhp" ,
"rtDW.gbv0nikqj2.eya5d5vx55" , "rtDW.aa2j2wnloo2.fqy4beoqau" ,
"rtDW.aa2j2wnloo2.mvk4qyxu0n" , "rtDW.gpv2q2mna0v.ofjd3uadhp" ,
"rtDW.gpv2q2mna0v.eya5d5vx55" , } ; mxArray * rtdwData = mxCreateStructMatrix
( 1 , 1 , 69 , rtdwDataFieldNames ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData ,
0 , 0 , ( const void * ) & ( rtDW . naju1uwbkg ) , sizeof ( rtDW . naju1uwbkg
) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . iz4mjb3fpi ) , sizeof ( rtDW . iz4mjb3fpi ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW .
kanrys502u ) , sizeof ( rtDW . kanrys502u ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 3 , ( const void * ) & ( rtDW . il2g04n2zg ) , sizeof ( rtDW .
il2g04n2zg ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void
* ) & ( rtDW . lc4skbr0sd ) , sizeof ( rtDW . lc4skbr0sd ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW .
kmcobpcqvr ) , sizeof ( rtDW . kmcobpcqvr ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 6 , ( const void * ) & ( rtDW . dcvx0x0nhj ) , sizeof ( rtDW .
dcvx0x0nhj ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void
* ) & ( rtDW . jonetifjdl ) , sizeof ( rtDW . jonetifjdl ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & ( rtDW .
k5octspggf ) , sizeof ( rtDW . k5octspggf ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 9 , ( const void * ) & ( rtDW . kurtqaimb2 ) , sizeof ( rtDW .
kurtqaimb2 ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const
void * ) & ( rtDW . m3xa5qdlgu ) , sizeof ( rtDW . m3xa5qdlgu ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & ( rtDW .
g4a2feilda ) , sizeof ( rtDW . g4a2feilda ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 12 , ( const void * ) & ( rtDW . ati3zogtqu ) , sizeof ( rtDW
. ati3zogtqu ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const
void * ) & ( rtDW . n5yzxageiq ) , sizeof ( rtDW . n5yzxageiq ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & ( rtDW .
hxzxqy2ytd ) , sizeof ( rtDW . hxzxqy2ytd ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 15 , ( const void * ) & ( rtDW . lpdpgewspm ) , sizeof ( rtDW
. lpdpgewspm ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const
void * ) & ( rtDW . bwt1hrltpz ) , sizeof ( rtDW . bwt1hrltpz ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & ( rtDW .
o4yzgxidzo ) , sizeof ( rtDW . o4yzgxidzo ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 18 , ( const void * ) & ( rtDW . puptsnuvic ) , sizeof ( rtDW
. puptsnuvic ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const
void * ) & ( rtDW . do51saudm1 ) , sizeof ( rtDW . do51saudm1 ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & ( rtDW .
ejvm3rk4rw ) , sizeof ( rtDW . ejvm3rk4rw ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 21 , ( const void * ) & ( rtDW . hrtqjrd53x ) , sizeof ( rtDW
. hrtqjrd53x ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const
void * ) & ( rtDW . pvzxgas2b3 ) , sizeof ( rtDW . pvzxgas2b3 ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & ( rtDW .
edvu1xljbk ) , sizeof ( rtDW . edvu1xljbk ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 24 , ( const void * ) & ( rtDW . d3leen4kcy ) , sizeof ( rtDW
. d3leen4kcy ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const
void * ) & ( rtDW . jycqzsqlqh ) , sizeof ( rtDW . jycqzsqlqh ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & ( rtDW .
omzfzlvkmy ) , sizeof ( rtDW . omzfzlvkmy ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 27 , ( const void * ) & ( rtDW . hrjhnmw2gy ) , sizeof ( rtDW
. hrjhnmw2gy ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const
void * ) & ( rtDW . cbxygsrulg ) , sizeof ( rtDW . cbxygsrulg ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & ( rtDW .
oehqsdtju1 ) , sizeof ( rtDW . oehqsdtju1 ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 30 , ( const void * ) & ( rtDW . ebrnrfebzf ) , sizeof ( rtDW
. ebrnrfebzf ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const
void * ) & ( rtDW . mr1ke3zacb ) , sizeof ( rtDW . mr1ke3zacb ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & ( rtDW .
crtkqsbmaj ) , sizeof ( rtDW . crtkqsbmaj ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 33 , ( const void * ) & ( rtDW . kuxuhbis4w ) , sizeof ( rtDW
. kuxuhbis4w ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const
void * ) & ( rtDW . e3u5ld2y51 ) , sizeof ( rtDW . e3u5ld2y51 ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) & ( rtDW .
itw05pv4q1 ) , sizeof ( rtDW . itw05pv4q1 ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 36 , ( const void * ) & ( rtDW . oyd0zxlfez ) , sizeof ( rtDW
. oyd0zxlfez ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const
void * ) & ( rtDW . dg3sdnhfhz ) , sizeof ( rtDW . dg3sdnhfhz ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) & ( rtDW .
chgudtwki5 ) , sizeof ( rtDW . chgudtwki5 ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 39 , ( const void * ) & ( rtDW . cxei33jqmq ) , sizeof ( rtDW
. cxei33jqmq ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const
void * ) & ( rtDW . bisetz5iuz ) , sizeof ( rtDW . bisetz5iuz ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void * ) & ( rtDW .
lguevo5cl5 ) , sizeof ( rtDW . lguevo5cl5 ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 42 , ( const void * ) & ( rtDW . ee4ok4zlel ) , sizeof ( rtDW
. ee4ok4zlel ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const
void * ) & ( rtDW . mvk1crirkl ) , sizeof ( rtDW . mvk1crirkl ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void * ) & ( rtDW .
c2l3p2qtjf ) , sizeof ( rtDW . c2l3p2qtjf ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 45 , ( const void * ) & ( rtDW . kza5ow0kr4 ) , sizeof ( rtDW
. kza5ow0kr4 ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const
void * ) & ( rtDW . oxvhzb4uhf ) , sizeof ( rtDW . oxvhzb4uhf ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void * ) & ( rtDW .
aw1t1zwgas ) , sizeof ( rtDW . aw1t1zwgas ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 48 , ( const void * ) & ( rtDW . aisofpnorv ) , sizeof ( rtDW
. aisofpnorv ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const
void * ) & ( rtDW . hsca3knam3 ) , sizeof ( rtDW . hsca3knam3 ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void * ) & ( rtDW .
loledzy1qu ) , sizeof ( rtDW . loledzy1qu ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 51 , ( const void * ) & ( rtDW . oacr45potf ) , sizeof ( rtDW
. oacr45potf ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const
void * ) & ( rtDW . lp022slzwu ) , sizeof ( rtDW . lp022slzwu ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 53 , ( const void * ) & ( rtDW .
ls1rbfacqf ) , sizeof ( rtDW . ls1rbfacqf ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 54 , ( const void * ) & ( rtDW . navvsf1ufo ) , sizeof ( rtDW
. navvsf1ufo ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 55 , ( const
void * ) & ( rtDW . fbyhlicb5e ) , sizeof ( rtDW . fbyhlicb5e ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 56 , ( const void * ) & ( rtDW .
nf2gbckq3n ) , sizeof ( rtDW . nf2gbckq3n ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 57 , ( const void * ) & ( rtDW . o2b5vrjagl ) , sizeof ( rtDW
. o2b5vrjagl ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 58 , ( const
void * ) & ( rtDW . bv4jm4qenv ) , sizeof ( rtDW . bv4jm4qenv ) ) ;
mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 59 , ( const void * ) & ( rtDW .
fbzp2gawrm ) , sizeof ( rtDW . fbzp2gawrm ) ) ; mr_Sim6_cacheDataAsMxArray (
rtdwData , 0 , 60 , ( const void * ) & ( rtDW . ovo53pq3zf ) , sizeof ( rtDW
. ovo53pq3zf ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 61 , ( const
void * ) & ( rtDW . hl5zrirewt . fqy4beoqau ) , sizeof ( rtDW . hl5zrirewt .
fqy4beoqau ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 62 , ( const
void * ) & ( rtDW . hl5zrirewt . mvk4qyxu0n ) , sizeof ( rtDW . hl5zrirewt .
mvk4qyxu0n ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 63 , ( const
void * ) & ( rtDW . gbv0nikqj2 . ofjd3uadhp ) , sizeof ( rtDW . gbv0nikqj2 .
ofjd3uadhp ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 64 , ( const
void * ) & ( rtDW . gbv0nikqj2 . eya5d5vx55 ) , sizeof ( rtDW . gbv0nikqj2 .
eya5d5vx55 ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 65 , ( const
void * ) & ( rtDW . aa2j2wnloo2 . fqy4beoqau ) , sizeof ( rtDW . aa2j2wnloo2
. fqy4beoqau ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 66 , ( const
void * ) & ( rtDW . aa2j2wnloo2 . mvk4qyxu0n ) , sizeof ( rtDW . aa2j2wnloo2
. mvk4qyxu0n ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 67 , ( const
void * ) & ( rtDW . gpv2q2mna0v . ofjd3uadhp ) , sizeof ( rtDW . gpv2q2mna0v
. ofjd3uadhp ) ) ; mr_Sim6_cacheDataAsMxArray ( rtdwData , 0 , 68 , ( const
void * ) & ( rtDW . gpv2q2mna0v . eya5d5vx55 ) , sizeof ( rtDW . gpv2q2mna0v
. eya5d5vx55 ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; }
mr_Sim6_cacheDataAsMxArray ( ssDW , 0 , 2 , ( const void * ) & ( rtPrevZCX )
, sizeof ( rtPrevZCX ) ) ; return ssDW ; } void mr_Sim6_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_Sim6_restoreDataFromMxArray ( ( void *
) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_Sim6_restoreDataFromMxArray ( ( void
* ) & ( rtDW . naju1uwbkg ) , rtdwData , 0 , 0 , sizeof ( rtDW . naju1uwbkg )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . iz4mjb3fpi ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . iz4mjb3fpi ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . kanrys502u ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . kanrys502u ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . il2g04n2zg ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . il2g04n2zg ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . lc4skbr0sd ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . lc4skbr0sd ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . kmcobpcqvr ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . kmcobpcqvr ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . dcvx0x0nhj ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . dcvx0x0nhj ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . jonetifjdl ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . jonetifjdl ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . k5octspggf ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . k5octspggf ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . kurtqaimb2 ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . kurtqaimb2 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . m3xa5qdlgu ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . m3xa5qdlgu ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . g4a2feilda ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . g4a2feilda ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ati3zogtqu ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . ati3zogtqu ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . n5yzxageiq ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . n5yzxageiq ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . hxzxqy2ytd ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . hxzxqy2ytd ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . lpdpgewspm ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . lpdpgewspm ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . bwt1hrltpz ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . bwt1hrltpz ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . o4yzgxidzo ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . o4yzgxidzo ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . puptsnuvic ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . puptsnuvic ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . do51saudm1 ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . do51saudm1 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ejvm3rk4rw ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . ejvm3rk4rw ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . hrtqjrd53x ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . hrtqjrd53x ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . pvzxgas2b3 ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . pvzxgas2b3 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . edvu1xljbk ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . edvu1xljbk ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . d3leen4kcy ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . d3leen4kcy ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . jycqzsqlqh ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . jycqzsqlqh ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . omzfzlvkmy ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . omzfzlvkmy ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . hrjhnmw2gy ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . hrjhnmw2gy ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . cbxygsrulg ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . cbxygsrulg ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . oehqsdtju1 ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . oehqsdtju1 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ebrnrfebzf ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . ebrnrfebzf ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . mr1ke3zacb ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . mr1ke3zacb ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . crtkqsbmaj ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . crtkqsbmaj ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . kuxuhbis4w ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . kuxuhbis4w ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . e3u5ld2y51 ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . e3u5ld2y51 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . itw05pv4q1 ) ,
rtdwData , 0 , 35 , sizeof ( rtDW . itw05pv4q1 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . oyd0zxlfez ) ,
rtdwData , 0 , 36 , sizeof ( rtDW . oyd0zxlfez ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . dg3sdnhfhz ) ,
rtdwData , 0 , 37 , sizeof ( rtDW . dg3sdnhfhz ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . chgudtwki5 ) ,
rtdwData , 0 , 38 , sizeof ( rtDW . chgudtwki5 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . cxei33jqmq ) ,
rtdwData , 0 , 39 , sizeof ( rtDW . cxei33jqmq ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . bisetz5iuz ) ,
rtdwData , 0 , 40 , sizeof ( rtDW . bisetz5iuz ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . lguevo5cl5 ) ,
rtdwData , 0 , 41 , sizeof ( rtDW . lguevo5cl5 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ee4ok4zlel ) ,
rtdwData , 0 , 42 , sizeof ( rtDW . ee4ok4zlel ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . mvk1crirkl ) ,
rtdwData , 0 , 43 , sizeof ( rtDW . mvk1crirkl ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . c2l3p2qtjf ) ,
rtdwData , 0 , 44 , sizeof ( rtDW . c2l3p2qtjf ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . kza5ow0kr4 ) ,
rtdwData , 0 , 45 , sizeof ( rtDW . kza5ow0kr4 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . oxvhzb4uhf ) ,
rtdwData , 0 , 46 , sizeof ( rtDW . oxvhzb4uhf ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . aw1t1zwgas ) ,
rtdwData , 0 , 47 , sizeof ( rtDW . aw1t1zwgas ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . aisofpnorv ) ,
rtdwData , 0 , 48 , sizeof ( rtDW . aisofpnorv ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . hsca3knam3 ) ,
rtdwData , 0 , 49 , sizeof ( rtDW . hsca3knam3 ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . loledzy1qu ) ,
rtdwData , 0 , 50 , sizeof ( rtDW . loledzy1qu ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . oacr45potf ) ,
rtdwData , 0 , 51 , sizeof ( rtDW . oacr45potf ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . lp022slzwu ) ,
rtdwData , 0 , 52 , sizeof ( rtDW . lp022slzwu ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ls1rbfacqf ) ,
rtdwData , 0 , 53 , sizeof ( rtDW . ls1rbfacqf ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . navvsf1ufo ) ,
rtdwData , 0 , 54 , sizeof ( rtDW . navvsf1ufo ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . fbyhlicb5e ) ,
rtdwData , 0 , 55 , sizeof ( rtDW . fbyhlicb5e ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . nf2gbckq3n ) ,
rtdwData , 0 , 56 , sizeof ( rtDW . nf2gbckq3n ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . o2b5vrjagl ) ,
rtdwData , 0 , 57 , sizeof ( rtDW . o2b5vrjagl ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . bv4jm4qenv ) ,
rtdwData , 0 , 58 , sizeof ( rtDW . bv4jm4qenv ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . fbzp2gawrm ) ,
rtdwData , 0 , 59 , sizeof ( rtDW . fbzp2gawrm ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . ovo53pq3zf ) ,
rtdwData , 0 , 60 , sizeof ( rtDW . ovo53pq3zf ) ) ;
mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . hl5zrirewt .
fqy4beoqau ) , rtdwData , 0 , 61 , sizeof ( rtDW . hl5zrirewt . fqy4beoqau )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . hl5zrirewt .
mvk4qyxu0n ) , rtdwData , 0 , 62 , sizeof ( rtDW . hl5zrirewt . mvk4qyxu0n )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . gbv0nikqj2 .
ofjd3uadhp ) , rtdwData , 0 , 63 , sizeof ( rtDW . gbv0nikqj2 . ofjd3uadhp )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . gbv0nikqj2 .
eya5d5vx55 ) , rtdwData , 0 , 64 , sizeof ( rtDW . gbv0nikqj2 . eya5d5vx55 )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . aa2j2wnloo2 .
fqy4beoqau ) , rtdwData , 0 , 65 , sizeof ( rtDW . aa2j2wnloo2 . fqy4beoqau )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . aa2j2wnloo2 .
mvk4qyxu0n ) , rtdwData , 0 , 66 , sizeof ( rtDW . aa2j2wnloo2 . mvk4qyxu0n )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . gpv2q2mna0v .
ofjd3uadhp ) , rtdwData , 0 , 67 , sizeof ( rtDW . gpv2q2mna0v . ofjd3uadhp )
) ; mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtDW . gpv2q2mna0v .
eya5d5vx55 ) , rtdwData , 0 , 68 , sizeof ( rtDW . gpv2q2mna0v . eya5d5vx55 )
) ; } mr_Sim6_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW , 0
, 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_Sim6_GetSimStateDisallowedBlocks ( ) { mxArray * data = mxCreateCellMatrix
( 5 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const char * blockType [ 5
] = { "S-Function" , "Scope" , "Scope" , "Scope" , "S-Function" , } ; static
const char * blockPath [ 5 ] = { "Sim6/powergui/EquivalentModel2/State-Space"
, "Sim6/Control Scheme/Scope1" , "Sim6/Scope1" , "Sim6/Scope2" ,
"Sim6/powergui/EquivalentModel2/State-Space" , } ; static const int reason [
5 ] = { 0 , 0 , 0 , 0 , 2 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 5 ; ++ (
subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 ,
subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ]
] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 29 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 6 ) ; ssSetNumBlocks ( rtS , 313 ) ;
ssSetNumBlockIO ( rtS , 142 ) ; ssSetNumBlockParams ( rtS , 425 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 5.0E-7 ) ;
ssSetSampleTime ( rtS , 3 , 1.0E-6 ) ; ssSetSampleTime ( rtS , 4 , 5.0E-6 ) ;
ssSetSampleTime ( rtS , 5 , 2.5E-5 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; ssSetOffsetTime ( rtS , 4 , 0.0 ) ;
ssSetOffsetTime ( rtS , 5 , 1.25E-5 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1263269511U ) ; ssSetChecksumVal ( rtS , 1 ,
3066790768U ) ; ssSetChecksumVal ( rtS , 2 , 1316343474U ) ; ssSetChecksumVal
( rtS , 3 , 2761255352U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 26 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
Sim6_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS , true )
; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 )
; ssSetModelName ( rtS , "Sim6" ) ; ssSetPath ( rtS , "Sim6" ) ; ssSetTStart
( rtS , 0.0 ) ; ssSetTFinal ( rtS , 0.1 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 ,
2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 2 , 6 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ;
static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 2 , 6 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = {
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ; static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = {
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "Sim6/Control Scheme/PLL\n(3ph)/Model/Integrator" ,
"Sim6/Control Scheme/PLL\n(3ph)/Model/Continuous/Integrator" ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Variable Frequency\nMean value/Model/Variable\nTransport Delay"
,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Variable Frequency\nMean value/Model/integrator"
, "Sim6/Control Scheme/PLL\n(3ph)/Model/Continuous/Transfer Fcn" ,
"Sim6/Control Scheme/PLL\n(3ph)/Model/Second-Order\nFilter/Model/Integrator_x1"
,
"Sim6/Control Scheme/PLL\n(3ph)/Model/Second-Order\nFilter/Model/Integrator_x2"
, "Sim6/Control Scheme/PR Controllers/Transfer Fcn1" ,
"Sim6/Control Scheme/PR Controllers/Transfer Fcn2" ,
"Sim6/Control Scheme/PR Controllers/Transfer Fcn" ,
"Sim6/Control Scheme/Subsystem/Transfer Fcn" ,
"Sim6/Control Scheme/Subsystem/Transfer Fcn1" ,
"Sim6/Control Scheme/Subsystem/Transfer Fcn2" ,
"Sim6/Control Scheme/Subsystem1/Transfer Fcn" ,
"Sim6/Control Scheme/Subsystem1/Transfer Fcn1" ,
"Sim6/Control Scheme/Subsystem1/Transfer Fcn2" ,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)1/Model/Variable\nTransport Delay"
,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)1/Model/integrator"
,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)2/Model/Variable\nTransport Delay"
,
 "Sim6/Control Scheme/PLL\n(3ph)/Model/Automatic Gain\nControl/Positive-Sequence\n(PLL-Driven)/Mean\n(Variable Frequency)2/Model/integrator"
, "Sim6/powergui/EquivalentModel2/State-Space" ,
"Sim6/Universal Bridge/Model/Unit Delay" ,
"Sim6/Power Calculator/Power\nCalculator/1st order 5Hz/Delay11" ,
"Sim6/Control Scheme/PI controller-d/FF Int" ,
"Sim6/Power Calculator/Power\nCalculator/1st order 5Hz1/Delay11" ,
"Sim6/Control Scheme/PI controller-q/FF Int" ,
 "Sim6/Control Scheme/PWM Generator\n(2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle\nGenerator/Model/Unit Delay"
,
 "Sim6/Three-Phase\nProgrammable\nVoltage Source/Model/Signal generator/Discrete-Time\nIntegrator"
,
 "Sim6/Three-Phase\nProgrammable\nVoltage Source/Model/Signal generator/Variation\nSubSystem/Discrete-Time\nIntegrator1"
,
 "Sim6/Three-Phase\nProgrammable\nVoltage Source/Model/Signal generator/Variation\nSubSystem/Unit Delay"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" } ; static boolean_T rt_LoggedStateCrossMdlRef
[ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11
, 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 ,
9 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 30 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 30 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . iumu3kzzhr ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . iip1hksxhe ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . imjxbjnrao ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . hvdzss0qy0 ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . mgdsbp3tlu ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . mlt40cyrau ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . fb24y2esxb ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . jh55bpubqj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . jn4nrdhpx1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . fyyiprok3t [ 0 ] ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . bjpvgeyygb [ 0 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . jkhhrdnef2 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . ns23ofbiao [ 0 ] ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . fozte2xjae [ 0 ] ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . ggl1vuf0v0 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . eavqvzqdwf [ 0 ] ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . bpxu1bsrls ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . c2tj4z32zx ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . jbjlk4lmud ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . hcrv11zemx ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) rtDW . naju1uwbkg ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) rtDW . iz4mjb3fpi ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtDW . kanrys502u ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) & rtDW . il2g04n2zg ;
rt_LoggedStateSignalPtrs [ 24 ] = ( void * ) & rtDW . lc4skbr0sd ;
rt_LoggedStateSignalPtrs [ 25 ] = ( void * ) & rtDW . kmcobpcqvr ;
rt_LoggedStateSignalPtrs [ 26 ] = ( void * ) & rtDW . dcvx0x0nhj ;
rt_LoggedStateSignalPtrs [ 27 ] = ( void * ) & rtDW . jonetifjdl ;
rt_LoggedStateSignalPtrs [ 28 ] = ( void * ) & rtDW . k5octspggf ;
rt_LoggedStateSignalPtrs [ 29 ] = ( void * ) & rtDW . kurtqaimb2 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 29 ] ;
static real_T absTol [ 29 ] = { 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 ,
1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 ,
1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 ,
1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 , 1.0E-9 } ;
static uint8_T absTolControl [ 29 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U } ; static real_T contStateJacPerturbBoundMinVec
[ 29 ] ; static real_T contStateJacPerturbBoundMaxVec [ 29 ] ; static uint8_T
zcAttributes [ 20 ] = { ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , ( 0xc0 |
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ;
static ssNonContDerivSigInfo nonContDerivSigInfo [ 11 ] = { { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . mqhymewypv ) , ( NULL ) } , { 1 * sizeof (
boolean_T ) , ( char * ) ( & rtB . lbe40ygcva ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . exj242slie ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . ffvcceoghv [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . exoldmyxco ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . j2eixrpwyy ) , ( NULL ) } , { 3 *
sizeof ( real_T ) , ( char * ) ( & rtB . paaqohv05q [ 0 ] ) , ( NULL ) } , {
1 * sizeof ( real_T ) , ( char * ) ( & rtB . nred03mov5 ) , ( NULL ) } , { 1
* sizeof ( boolean_T ) , ( char * ) ( & rtB . bx3i1gippc ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . gfw00daf11 ) , ( NULL ) } , { 1 *
sizeof ( boolean_T ) , ( char * ) ( & rtB . kiunlxs5sx ) , ( NULL ) } } ; {
int i ; for ( i = 0 ; i < 29 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ]
= 0 ; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } }
ssSetSolverRelTol ( rtS , 1.0E-6 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 5.0E-7 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 11 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode23t" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 1 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 20 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 19 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . ff24yskbma = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal
( rtS , 0 , 1263269511U ) ; ssSetChecksumVal ( rtS , 1 , 3066790768U ) ;
ssSetChecksumVal ( rtS , 2 , 1316343474U ) ; ssSetChecksumVal ( rtS , 3 ,
2761255352U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 17 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . oxvhzb4uhf ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW . oxvhzb4uhf ;
systemRan [ 3 ] = ( sysRanDType * ) & rtDW . gpv2q2mna0v . ofjd3uadhp ;
systemRan [ 4 ] = ( sysRanDType * ) & rtDW . aa2j2wnloo2 . fqy4beoqau ;
systemRan [ 5 ] = ( sysRanDType * ) & rtDW . oxvhzb4uhf ; systemRan [ 6 ] = &
rtAlwaysEnabled ; systemRan [ 7 ] = ( sysRanDType * ) & rtDW . gbv0nikqj2 .
ofjd3uadhp ; systemRan [ 8 ] = ( sysRanDType * ) & rtDW . hl5zrirewt .
fqy4beoqau ; systemRan [ 9 ] = ( sysRanDType * ) & rtDW . kza5ow0kr4 ;
systemRan [ 10 ] = ( sysRanDType * ) & rtDW . c2l3p2qtjf ; systemRan [ 11 ] =
( sysRanDType * ) & rtDW . mvk1crirkl ; systemRan [ 12 ] = ( sysRanDType * )
& rtDW . ee4ok4zlel ; systemRan [ 13 ] = ( sysRanDType * ) & rtDW .
ee4ok4zlel ; systemRan [ 14 ] = ( sysRanDType * ) & rtDW . ee4ok4zlel ;
systemRan [ 15 ] = ( sysRanDType * ) & rtDW . ee4ok4zlel ; systemRan [ 16 ] =
( sysRanDType * ) & rtDW . ee4ok4zlel ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Sim6_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_Sim6_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS , mr_Sim6_SetDWork )
; rtP . Saturation_UpperSat = rtInf ; rtP . Saturation_UpperSat_lphrbvohc0 =
rtInf ; rtP . Integrator_UpperSat = rtInf ; rtP . Integrator_LowerSat =
rtMinusInf ; rtP . Integrator_UpperSat_pm1zhfhqin = rtInf ; rtP .
Saturation2_UpperSat = rtInf ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ;
if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 6 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID6 ( tid ) ; }
