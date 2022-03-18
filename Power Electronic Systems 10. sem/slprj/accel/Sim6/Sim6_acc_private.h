#ifndef RTW_HEADER_Sim6_acc_private_h_
#define RTW_HEADER_Sim6_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Sim6_acc.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
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
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T Sim6_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T *
tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * *
uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) ; real_T Sim6_acc_rt_VTDelayfindtDInterpolate ( real_T x ,
real_T * uBuf , int_T bufSz , int_T head , int_T tail , int_T * pLast ,
real_T t , real_T tStart , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput , real_T initOutput , real_T * appliedDelay )
; extern real_T look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) ; void
Sim6_Subsystempi2delay_Init ( SimStruct * S , B_Subsystempi2delay_Sim6_T *
localB , P_Subsystempi2delay_Sim6_T * localP ) ; void
Sim6_Subsystempi2delay_Disable ( SimStruct * S , DW_Subsystempi2delay_Sim6_T
* localDW ) ; void Sim6_Subsystempi2delay ( SimStruct * S , uint8_T
rtu_Enable , const real_T rtu_alpha_beta [ 2 ] , real_T rtu_wt ,
B_Subsystempi2delay_Sim6_T * localB , DW_Subsystempi2delay_Sim6_T * localDW )
; void Sim6_Subsystem1_Init ( SimStruct * S , B_Subsystem1_Sim6_T * localB ,
P_Subsystem1_Sim6_T * localP ) ; void Sim6_Subsystem1_Disable ( SimStruct * S
, DW_Subsystem1_Sim6_T * localDW ) ; void Sim6_Subsystem1 ( SimStruct * S ,
uint8_T rtu_Enable , const real_T rtu_alpha_beta [ 2 ] , real_T rtu_wt ,
B_Subsystem1_Sim6_T * localB , DW_Subsystem1_Sim6_T * localDW ) ; void
Sim6_Subsystempi2delay_Term ( SimStruct * const S ) ; void
Sim6_Subsystem1_Term ( SimStruct * const S ) ;
#endif
