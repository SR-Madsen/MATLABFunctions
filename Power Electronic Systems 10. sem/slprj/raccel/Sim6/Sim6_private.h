#ifndef RTW_HEADER_Sim6_private_h_
#define RTW_HEADER_Sim6_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Sim6.h"
#include <math.h>
#include <stdlib.h>
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
#ifndef CodeFormat
#define CodeFormat   S-Function
#else
#undef CodeFormat
#define CodeFormat   S-Function
#endif
#ifndef S_FUNCTION_NAME
#define S_FUNCTION_NAME   simulink_only_sfcn
#else
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME   simulink_only_sfcn
#endif
#ifndef S_FUNCTION_LEVEL
#define S_FUNCTION_LEVEL  2
#else
#undef S_FUNCTION_LEVEL
#define S_FUNCTION_LEVEL  2
#endif
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)        NULL
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif
#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES
#ifndef _RTW_COMMON_DEFINES_
#define _RTW_COMMON_DEFINES_
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) ;
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
; real_T rt_VTDelayfindtDInterpolate ( real_T x , real_T * uBuf , int_T bufSz
, int_T head , int_T tail , int_T * pLast , real_T t , real_T tStart ,
boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput , real_T
initOutput , real_T * appliedDelay ) ; extern real_T look1_pbinlxpw ( real_T
u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) ; void rt_TDelayFreeBuf ( void * buf ) ; extern void
lnng4k1xu3 ( ez1qc1u4ss * localB , lnfuzpqlv0 * localP ) ; extern void
eaxqlp5nrz ( SimStruct * rtS_p , etsotvigvh * localDW ) ; extern void
lxyv23omal ( etsotvigvh * localDW ) ; extern void gpv2q2mna0 ( SimStruct *
rtS_i , uint8_T oznahafnyb , const real_T io15qqqqo2 [ 2 ] , real_T
owa45pty5f , ez1qc1u4ss * localB , etsotvigvh * localDW ) ; extern void
doezucbrrq ( b000baele5 * localB , anyxbustxf * localP ) ; extern void
d3q41qgird ( SimStruct * rtS_i , htflfovccy * localDW ) ; extern void
dibibutkg4 ( htflfovccy * localDW ) ; extern void aa2j2wnloo ( SimStruct *
rtS_g , uint8_T lmolwjupgu , const real_T fwlcyrlim1 [ 2 ] , real_T
krnqok132n , b000baele5 * localB , htflfovccy * localDW ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
