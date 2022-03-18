#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Sim6_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#else
#include "builtin_typeid_types.h"
#include "Sim6.h"
#include "Sim6_capi.h"
#include "Sim6_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Q+" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 0 , TARGET_STRING ( "Sim6/Control Scheme/Gain1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 1 } , { 2 , 0 , TARGET_STRING ( "Sim6/Control Scheme/P*=10kW"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 3 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , {
4 , 0 , TARGET_STRING ( "Sim6/Control Scheme/Sum2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 2 } , { 5 , 0 , TARGET_STRING ( "Sim6/Control Scheme/Sum3" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Kv" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 1 } , { 7 , 0 , TARGET_STRING ( "Sim6/Three-Phase V-I Measurement1/Kv1" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PI controller-d/FF Int" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 4 } , { 9 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PI controller-d/Sum3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 5 } , { 10 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PI controller-q/FF Int" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PI controller-q/Sum3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 5 } , { 12 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 3 } , { 13 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 3 } , { 14 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 3 } , { 15 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 3 } , { 16 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PWM Generator (2-Level)/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 3 } , { 17 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 3 } , { 18 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 3 } , { 19 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 20 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 21 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 3 } , { 22 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 23 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 24 , 0 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 25 , 0 , TARGET_STRING (
"Sim6/Power Calculator/Clarke Transformation1/Clarke to Beta" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 26 , 0 , TARGET_STRING (
"Sim6/Power Calculator/Clarke Transformation1/Clarke to alpha" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 27 , 16 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator" ) ,
TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave A" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave B" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave C" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"Sim6/Universal Bridge/Model/Saturation" ) , TARGET_STRING ( "" ) , 0 , 0 , 2
, 0 , 1 } , { 32 , 0 , TARGET_STRING (
"Sim6/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "" ) , 0 , 0
, 3 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"Sim6/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "" ) , 1 , 0
, 2 , 0 , 1 } , { 34 , 5 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 35 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Gain10" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 3 } , { 36 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Initial" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 37 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Integrator" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 3 } , { 38 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Memory" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 2 } , { 39 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Divide" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 3 } , { 40 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Rate Limiter" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 3 } , { 41 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Relational Operator" ) , TARGET_STRING (
"" ) , 0 , 1 , 0 , 0 , 2 } , { 42 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Subtract" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 43 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PWM Generator (2-Level)/Cr_MinMax/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PWM Generator (2-Level)/Cr_MinMax/Add4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 45 , 0 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/Alpha-Beta-Zero to abc/Gain3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 46 , 9 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 47 , 9 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 48 , 10 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 49 , 10 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 50 , 0 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 3 } , { 51 , 0 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz/SumA21" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 52 , 0 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz/SumB21" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 53 , 0 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz1/SumA21" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz1/SumB21" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 55 , 16 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Discrete-Time Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 56 , 16 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Gain2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 57 , 16 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Relational Operator2"
) , TARGET_STRING ( "Frequency" ) , 0 , 1 , 0 , 0 , 0 } , { 58 , 5 ,
TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Math Function" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 59 , 5 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 60 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Kp4" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 61 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Kp5" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 62 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Kp6" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 63 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Integrator" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 64 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Saturation2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 65 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Sum6" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 3 } , { 66 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Transfer Fcn" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 67 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Modulator type/One Three Phase Bridge/Relational Operator2"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 2 } , { 68 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 69 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 70 , 9 , TARGET_STRING (
 "Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 71 , 9 , TARGET_STRING (
 "Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 72 , 10 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1/Fcn" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 73 , 10 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1/Fcn1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 74 , 16 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Discrete-Time Integrator1"
) , TARGET_STRING ( "Ramp" ) , 0 , 0 , 0 , 0 , 1 } , { 75 , 16 ,
TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 76 , 16 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 77 , 16 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 78 , 16 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 79 , 16 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 80 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Complex to Magnitude-Angle"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 81 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Real-Imag to Complex"
) , TARGET_STRING ( "" ) , 0 , 3 , 0 , 0 , 3 } , { 82 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/Integrator_x1"
) , TARGET_STRING ( "x1" ) , 0 , 0 , 0 , 0 , 3 } , { 83 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/Integrator_x2"
) , TARGET_STRING ( "x2" ) , 0 , 0 , 0 , 0 , 3 } , { 84 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x1+ B* u1" )
, TARGET_STRING ( "x'1" ) , 0 , 0 , 0 , 0 , 3 } , { 85 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x2+ B*u2" )
, TARGET_STRING ( "x'2" ) , 0 , 0 , 0 , 0 , 3 } , { 86 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/C*x + D*u" ) ,
TARGET_STRING ( "y" ) , 0 , 0 , 0 , 0 , 3 } , { 87 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Clock"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 88 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/period"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 89 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 90 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Memory"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 91 , 6 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Product"
) , TARGET_STRING ( "Mean value" ) , 0 , 0 , 0 , 0 , 3 } , { 92 , 0 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 93 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/To avoid division  by zero"
) , TARGET_STRING ( "Freq" ) , 0 , 0 , 0 , 0 , 3 } , { 94 , 6 , TARGET_STRING
(
"Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Sum7"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 95 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 96 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Variable Transport Delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 97 , 7 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 98 , 7 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 99 , 8 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 100 , 8 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 101 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 3 } , { 102 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/abc to Alpha-Beta-Zero/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 103 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/abc to Alpha-Beta-Zero/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 104 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A11" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 105 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A12" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 106 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A21" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 107 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A22" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 108 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/sum2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 109 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/sum3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 110 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/B*u/B11" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 111 , 0 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/B*u/B21" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 112 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 113 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 114 , 7 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 115 , 7 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 116 , 8 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 117 , 8 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 118 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Clock"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 119 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/period"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 120 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 121 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Memory"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 122 , 1 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Product"
) , TARGET_STRING ( "Mean value" ) , 0 , 0 , 0 , 0 , 3 } , { 123 , 5 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 124 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/To avoid division  by zero"
) , TARGET_STRING ( "Freq" ) , 0 , 0 , 0 , 0 , 3 } , { 125 , 1 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Sum7"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 126 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 127 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Variable Transport Delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 128 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Clock"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 129 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/period"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 130 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 131 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Memory"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 132 , 2 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Product"
) , TARGET_STRING ( "Mean value" ) , 0 , 0 , 0 , 0 , 3 } , { 133 , 5 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 134 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/To avoid division  by zero"
) , TARGET_STRING ( "Freq" ) , 0 , 0 , 0 , 0 , 3 } , { 135 , 2 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Sum7"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 136 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 137 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Variable Transport Delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 138 , 3 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 139 , 3 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 140 , 4 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 141 , 4 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 142 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 3 } , { 143 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/abc to Alpha-Beta-Zero/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 144 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/abc to Alpha-Beta-Zero/Gain3"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 3 } , { 145 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 146 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 147 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 148 , 0 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Unit Delay"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 6 } , { 149 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 150 , 5 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant1/Compare"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 151 , 3 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 152 , 3 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 153 , 4 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem1/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 154 , 4 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem1/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 155 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source" ) , TARGET_STRING (
"VariationEntity" ) , 0 , 0 , 0 } , { 156 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source" ) , TARGET_STRING (
"VariationType" ) , 0 , 0 , 0 } , { 157 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source" ) , TARGET_STRING (
"HarmonicGeneration" ) , 0 , 0 , 0 } , { 158 , TARGET_STRING (
"Sim6/Three-Phase Source" ) , TARGET_STRING ( "Frequency" ) , 0 , 0 , 0 } , {
159 , TARGET_STRING ( "Sim6/Vdc " ) , TARGET_STRING ( "Amplitude" ) , 0 , 0 ,
0 } , { 160 , TARGET_STRING ( "Sim6/Control Scheme/PWM Generator (2-Level)" )
, TARGET_STRING ( "MinMax" ) , 0 , 5 , 0 } , { 161 , TARGET_STRING (
"Sim6/Control Scheme/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 162 , TARGET_STRING ( "Sim6/Control Scheme/Q+" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 163 , TARGET_STRING ( "Sim6/Control Scheme/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
"Sim6/Control Scheme/P*=10kW" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , {
165 , TARGET_STRING ( "Sim6/Control Scheme/P*=10kW" ) , TARGET_STRING (
"Before" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"Sim6/Control Scheme/P*=10kW" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , {
167 , TARGET_STRING ( "Sim6/Three-Phase V-I Measurement1/Kv" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Kv1" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 169 , TARGET_STRING ( "Sim6/Control Scheme/PI controller-d/FF Int"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 170 , TARGET_STRING (
"Sim6/Control Scheme/PI controller-d/FF Int" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
"Sim6/Control Scheme/PI controller-q/FF Int" ) , TARGET_STRING ( "gainval" )
, 0 , 0 , 0 } , { 172 , TARGET_STRING (
"Sim6/Control Scheme/PI controller-q/FF Int" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 174 , TARGET_STRING ( "Sim6/Control Scheme/PR Controllers/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 175 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn" ) , TARGET_STRING ( "A" ) ,
0 , 4 , 0 } , { 176 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn" ) , TARGET_STRING ( "C" ) ,
0 , 5 , 0 } , { 177 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn1" ) , TARGET_STRING ( "A" )
, 0 , 4 , 0 } , { 178 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn1" ) , TARGET_STRING ( "C" )
, 0 , 5 , 0 } , { 179 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn2" ) , TARGET_STRING ( "A" )
, 0 , 4 , 0 } , { 180 , TARGET_STRING (
"Sim6/Control Scheme/PR Controllers/Transfer Fcn2" ) , TARGET_STRING ( "C" )
, 0 , 5 , 0 } , { 181 , TARGET_STRING ( "Sim6/Control Scheme/Subsystem/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Gain3" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 183 , TARGET_STRING ( "Sim6/Control Scheme/Subsystem/Transfer Fcn" )
, TARGET_STRING ( "A" ) , 0 , 4 , 0 } , { 184 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn" ) , TARGET_STRING ( "C" ) , 0 ,
5 , 0 } , { 185 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn1" ) , TARGET_STRING ( "A" ) , 0 ,
4 , 0 } , { 186 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn1" ) , TARGET_STRING ( "C" ) , 0 ,
5 , 0 } , { 187 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn2" ) , TARGET_STRING ( "A" ) , 0 ,
4 , 0 } , { 188 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem/Transfer Fcn2" ) , TARGET_STRING ( "C" ) , 0 ,
5 , 0 } , { 189 , TARGET_STRING ( "Sim6/Control Scheme/Subsystem1/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Gain3" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 191 , TARGET_STRING ( "Sim6/Control Scheme/Subsystem1/Transfer Fcn" )
, TARGET_STRING ( "A" ) , 0 , 4 , 0 } , { 192 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn" ) , TARGET_STRING ( "C" ) , 0 ,
5 , 0 } , { 193 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn1" ) , TARGET_STRING ( "A" ) , 0
, 4 , 0 } , { 194 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn1" ) , TARGET_STRING ( "C" ) , 0
, 5 , 0 } , { 195 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn2" ) , TARGET_STRING ( "A" ) , 0
, 4 , 0 } , { 196 , TARGET_STRING (
"Sim6/Control Scheme/Subsystem1/Transfer Fcn2" ) , TARGET_STRING ( "C" ) , 0
, 5 , 0 } , { 197 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero" ) , TARGET_STRING (
"Alignment" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave A" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 199 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave A" ) , TARGET_STRING ( "Bias" ) , 0
, 0 , 0 } , { 200 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave A" ) , TARGET_STRING ( "SinH" ) , 0
, 0 , 0 } , { 201 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave A" ) , TARGET_STRING ( "CosH" ) , 0
, 0 , 0 } , { 202 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave A" ) , TARGET_STRING ( "SinPhi" ) ,
0 , 0 , 0 } , { 203 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave A" ) , TARGET_STRING ( "CosPhi" ) ,
0 , 0 , 0 } , { 204 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave B" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 205 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave B" ) , TARGET_STRING ( "Bias" ) , 0
, 0 , 0 } , { 206 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave B" ) , TARGET_STRING ( "SinH" ) , 0
, 0 , 0 } , { 207 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave B" ) , TARGET_STRING ( "CosH" ) , 0
, 0 , 0 } , { 208 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave B" ) , TARGET_STRING ( "SinPhi" ) ,
0 , 0 , 0 } , { 209 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave B" ) , TARGET_STRING ( "CosPhi" ) ,
0 , 0 , 0 } , { 210 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave C" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 211 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave C" ) , TARGET_STRING ( "Bias" ) , 0
, 0 , 0 } , { 212 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave C" ) , TARGET_STRING ( "SinH" ) , 0
, 0 , 0 } , { 213 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave C" ) , TARGET_STRING ( "CosH" ) , 0
, 0 , 0 } , { 214 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave C" ) , TARGET_STRING ( "SinPhi" ) ,
0 , 0 , 0 } , { 215 , TARGET_STRING (
"Sim6/Three-Phase Source/Model/Sine Wave C" ) , TARGET_STRING ( "CosPhi" ) ,
0 , 0 , 0 } , { 216 , TARGET_STRING ( "Sim6/Universal Bridge/Model/0 4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 217 , TARGET_STRING (
"Sim6/Universal Bridge/Model/1//Ron" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 218 , TARGET_STRING ( "Sim6/Universal Bridge/Model/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 219 , TARGET_STRING (
"Sim6/Universal Bridge/Model/Saturation" ) , TARGET_STRING ( "LowerLimit" ) ,
0 , 0 , 0 } , { 220 , TARGET_STRING ( "Sim6/Universal Bridge/Model/Switch" )
, TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 221 , TARGET_STRING (
"Sim6/Universal Bridge/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 222 , TARGET_STRING (
"Sim6/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "AS_param" )
, 0 , 6 , 0 } , { 223 , TARGET_STRING (
"Sim6/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "BS_param" )
, 0 , 7 , 0 } , { 224 , TARGET_STRING (
"Sim6/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "CS_param" )
, 0 , 8 , 0 } , { 225 , TARGET_STRING (
"Sim6/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "DS_param" )
, 0 , 9 , 0 } , { 226 , TARGET_STRING (
"Sim6/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( "X0_param" )
, 0 , 4 , 0 } , { 227 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous" ) , TARGET_STRING ( "Kp" ) ,
0 , 0 , 0 } , { 228 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous" ) , TARGET_STRING ( "Ki" ) ,
0 , 0 , 0 } , { 229 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous" ) , TARGET_STRING ( "Kd" ) ,
0 , 0 , 0 } , { 230 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous" ) , TARGET_STRING ( "Init" )
, 0 , 0 , 0 } , { 231 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Constant1" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 232 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Constant2" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 233 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Gain10" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 234 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Hit  Crossing" ) , TARGET_STRING (
"HitCrossingOffset" ) , 0 , 0 , 0 } , { 235 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Initial" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 236 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Integrator" ) , TARGET_STRING (
"UpperSaturationLimit" ) , 0 , 0 , 0 } , { 237 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Integrator" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 238 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 239 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Rate Limiter" ) , TARGET_STRING (
"RisingSlewLimit" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Rate Limiter" ) , TARGET_STRING (
"FallingSlewLimit" ) , 0 , 0 , 0 } , { 241 , TARGET_STRING (
"Sim6/Control Scheme/PWM Generator (2-Level)/Cr_MinMax/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 242 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/Alpha-Beta-Zero to abc/Gain3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 10 , 0 } , { 243 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant" )
, TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 244 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 245 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz/a(2)(1)" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 246 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz/s(1)" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 247 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz/Delay11" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 248 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz1/a(2)(1)" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 249 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz1/s(1)" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 250 , TARGET_STRING (
"Sim6/Power Calculator/Power Calculator/1st order 5Hz1/Delay11" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 251 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Harmonic Generator/Out1"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 252 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Harmonic Generator/Out2"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 253 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/timer" )
, TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 254 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/selector"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 255 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/magnitude"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 256 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/frequency"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 257 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/phase" )
, TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 258 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem"
) , TARGET_STRING ( "VariationStep" ) , 0 , 0 , 0 } , { 259 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem"
) , TARGET_STRING ( "VariationRate" ) , 0 , 0 , 0 } , { 260 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem"
) , TARGET_STRING ( "VariationFreq" ) , 0 , 0 , 0 } , { 261 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem"
) , TARGET_STRING ( "VariationMag" ) , 0 , 0 , 0 } , { 262 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem"
) , TARGET_STRING ( "Ton_Variation" ) , 0 , 0 , 0 } , { 263 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem"
) , TARGET_STRING ( "Toff_Variation" ) , 0 , 0 , 0 } , { 264 , TARGET_STRING
(
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 265 , TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 266 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Discrete-Time Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 267 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Discrete-Time Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 268 ,
TARGET_STRING (
"Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Gain2" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 269 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Model/I A:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 270 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Model/I B:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 271 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Model/I C:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 272 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Model/U A:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 273 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Model/U B:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 274 , TARGET_STRING (
"Sim6/Three-Phase V-I Measurement1/Model/U C:/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 275 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Gain" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 276 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 277 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 278 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Integrator" ) , TARGET_STRING
( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 279 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Integrator" ) , TARGET_STRING
( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 280 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Saturation2" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 281 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Saturation2" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 282 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Transfer Fcn" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 283 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Transfer Fcn" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 284 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Continuous/Transfer Fcn" ) ,
TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 285 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0" ) ,
TARGET_STRING ( "Alignment" ) , 0 , 0 , 0 } , { 286 , TARGET_STRING (
 "Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay/alpha_beta"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 5 , 0 } , { 287 , TARGET_STRING (
"Sim6/Control Scheme/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1/alpha_beta"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 5 , 0 } , { 288 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 289 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 290 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 291 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 292 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 293 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 294 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Discrete-Time Integrator1"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 295 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Discrete-Time Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 296 ,
TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 297 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Step"
) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 298 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Step"
) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 299 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Step1"
) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 300 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Step1"
) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 301 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 302 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 303 , TARGET_STRING (
 "Sim6/Three-Phase Programmable Voltage Source/Model/Signal generator/Variation SubSystem/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 304 ,
TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/D*u" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 305 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/Integrator_x1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 306 ,
TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/Integrator_x2"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 307 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 308 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 309 ,
TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Memory"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 310 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/To avoid division  by zero"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 311 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/To avoid division  by zero"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 312 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Variable Transport Delay"
) , TARGET_STRING ( "MaximumDelay" ) , 0 , 0 , 0 } , { 313 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Variable Frequency Mean value/Model/Variable Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 314 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 315 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 316 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/abc to Alpha-Beta-Zero/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 317 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/abc to Alpha-Beta-Zero/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 10 , 0 } , { 318 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0"
) , TARGET_STRING ( "Alignment" ) , 0 , 0 , 0 } , { 319 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A11" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 320 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A12" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 321 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A21" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 322 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/A*x/A22" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 323 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/B*u/B11" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 324 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/B*u/B21" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 325 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/C*x/C11" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 326 , TARGET_STRING (
"Sim6/Control Scheme/PLL (3ph)/Model/Second-Order Filter/Model/C*x/C12" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 327 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/dq"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 5 , 0 } , { 328 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1/dq"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 5 , 0 } , { 329 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 330 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 331 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Memory"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 332 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/To avoid division  by zero"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 333 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/To avoid division  by zero"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 334 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Variable Transport Delay"
) , TARGET_STRING ( "MaximumDelay" ) , 0 , 0 , 0 } , { 335 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Variable Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 336 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 337 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 338 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Memory"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 339 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/To avoid division  by zero"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 340 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/To avoid division  by zero"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 341 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Variable Transport Delay"
) , TARGET_STRING ( "MaximumDelay" ) , 0 , 0 , 0 } , { 342 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Variable Transport Delay"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 343 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 344 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant1"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 345 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/abc to Alpha-Beta-Zero/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 346 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/abc to Alpha-Beta-Zero/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 10 , 0 } , { 347 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 348 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 349 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 350 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/1\\ib1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 351 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 352 , TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 11 , 0 } , { 353 ,
TARGET_STRING (
 "Sim6/Control Scheme/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 354 ,
TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay/dq"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 5 , 0 } , { 355 , TARGET_STRING (
 "Sim6/Control Scheme/PLL (3ph)/Model/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem1/dq"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 5 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 356 , TARGET_STRING (
"KipP" ) , 0 , 0 , 0 } , { 357 , TARGET_STRING ( "KipQ" ) , 0 , 0 , 0 } , {
358 , TARGET_STRING ( "KppP" ) , 0 , 0 , 0 } , { 359 , TARGET_STRING ( "KppQ"
) , 0 , 0 , 0 } , { 360 , TARGET_STRING ( "ki" ) , 0 , 0 , 0 } , { 361 ,
TARGET_STRING ( "kp" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . dcuhhc42lm , & rtB . ffvcceoghv [
0 ] , & rtB . kqg04a251b , & rtB . pusmndwhp4 [ 0 ] , & rtB . dtyrdyfgxc , &
rtB . k5kueqchg5 , & rtB . paaqohv05q [ 0 ] , & rtB . djau2g1olc [ 0 ] , &
rtB . lhih2qrjjs , & rtB . j2eixrpwyy , & rtB . m5bsg3jkvc , & rtB .
exoldmyxco , & rtB . bt2aomm4y4 , & rtB . mv0i5cphjf , & rtB . li0okspf41 , &
rtB . eqrscq4msa , & rtB . cdgmcxdgxx [ 0 ] , & rtB . jb4fsta5my , & rtB .
otuvlsx5ys , & rtB . j0n1jzgntq , & rtB . jmwusjiov1 , & rtB . fdwocsfez5 , &
rtB . hm5ofsqtib , & rtB . amhtuysrig , & rtB . aylp23sizt , & rtB .
fo12qitrhm , & rtB . k2t2anegon , & rtB . osecmroasz , & rtB . gktfzcs3fd , &
rtB . dbmx3g5hpc , & rtB . dm5evipofq , & rtB . bgjph5tzti [ 0 ] , & rtB .
bpposa5psj [ 0 ] , & rtB . a03vq2btj3 [ 0 ] , & rtB . pe3tnbqbgy , & rtB .
iosedcm1tf , & rtB . k01onl4g5t , & rtB . llqrd441m5 , & rtB . exj242slie , &
rtB . gphcjhvv1a , & rtB . oll4rfkmhz , & rtB . hzmul4slgt , & rtB .
dgq4jw1zua , & rtB . dsjsfniaum , & rtB . itzulpyuw2 , & rtB . i3co5cpqer [ 0
] , & rtB . mv2ve5xuao , & rtB . lzxedsxie0 , & rtB . gahdo2523m , & rtB .
brq4reciat , & rtB . gimxw5025n [ 0 ] , & rtB . kkx3bsha4q , & rtB .
prxgf4reyt , & rtB . m5uukj3ycd , & rtB . kq0uqgcvcf , & rtB . osecmroasz , &
rtB . hxgcychvxe , & rtB . g524d0rboe , & rtB . pe3tnbqbgy , & rtB .
hujgllbkhe , & rtB . jvo1ddk5yj , & rtB . gbqdu1hcwl , & rtB . k0pwj4jxiq , &
rtB . ckayt42vf3 , & rtB . gc2xht4yqo , & rtB . amr33vumq0 , & rtB .
dijcpphi4p , & rtB . ejejjrbn43 [ 0 ] , & rtB . ogehm3eyx3 , & rtB .
oakfin4jis , & rtB . mv2ve5xuao , & rtB . lzxedsxie0 , & rtB . gahdo2523m , &
rtB . brq4reciat , & rtB . gei3qlbkau , & rtB . dfsza0jb3r , & rtB .
k0zgmoo03i , & rtB . ojpmhqp3hb , & rtB . aydt5pakqc , & rtB . k2r2gd5thc , &
rtB . jfashjspdq , & rtB . gap4mluorh . re , & rtB . cnh4llzau0 , & rtB .
f2yfeiz4wx , & rtB . lrkvpii4gh , & rtB . erof3sa2ef , & rtB . kyvouqb0no , &
rtB . psgxvcmjhn , & rtB . b4jfht23g2 , & rtB . jkth2sfciv , & rtB .
mqhymewypv , & rtB . ermyprlyya , & rtB . lbe40ygcva , & rtB . gungbq04sb , &
rtB . f2eidvmh01 , & rtB . hhnk2g0wfl , & rtB . oijk30i103 , & rtB .
gbv0nikqj2 . j2nl0k3bjo , & rtB . gbv0nikqj2 . dxu5h4veqy , & rtB .
hl5zrirewt . otn2ta4rye , & rtB . hl5zrirewt . ow32b43xgs , & rtB .
fvbww5mjui [ 0 ] , & rtB . dvkqumepgk [ 0 ] , & rtB . f0vgkk3bhk [ 0 ] , &
rtB . aebuj4jliw , & rtB . mm4x5kerfj , & rtB . ejg1ybzhgl , & rtB .
k1rxqwgc5o , & rtB . n4ots5cknz , & rtB . brzgt5o0ly , & rtB . fbrwvcuz2e , &
rtB . orccexijhq , & rtB . ejjuk1fwje , & rtB . bjycl5wbcz , & rtB .
gbv0nikqj2 . j2nl0k3bjo , & rtB . gbv0nikqj2 . dxu5h4veqy , & rtB .
hl5zrirewt . otn2ta4rye , & rtB . hl5zrirewt . ow32b43xgs , & rtB .
emtuteg24p , & rtB . hs004dp4hy , & rtB . pqq2mzl5yy , & rtB . gfw00daf11 , &
rtB . aah0x3cxyl , & rtB . kiunlxs5sx , & rtB . emd031udec , & rtB .
e3pcbwyj3i , & rtB . klqpdibj32 , & rtB . jqerscg1zt , & rtB . asbptj5zaz , &
rtB . omw4a1utb1 , & rtB . hohn5tgzlv , & rtB . nred03mov5 , & rtB .
jwdiimvvl4 , & rtB . bx3i1gippc , & rtB . lejcvssl30 , & rtB . fdljtyo4lz , &
rtB . onjteuktwt , & rtB . jdm55m0vau , & rtB . gpv2q2mna0v . j2nl0k3bjo , &
rtB . gpv2q2mna0v . dxu5h4veqy , & rtB . aa2j2wnloo2 . otn2ta4rye , & rtB .
aa2j2wnloo2 . ow32b43xgs , & rtB . p52yfpva5l [ 0 ] , & rtB . lsxposbkab [ 0
] , & rtB . aiseatx5p4 [ 0 ] , & rtB . kd4hozccoi , & rtB . bj5uxavhae , &
rtB . a4ynar3r0p , & rtB . it4rtc1qod , & rtB . eo33rm2kiy , & rtB .
jr2eclq22h , & rtB . gpv2q2mna0v . j2nl0k3bjo , & rtB . gpv2q2mna0v .
dxu5h4veqy , & rtB . aa2j2wnloo2 . otn2ta4rye , & rtB . aa2j2wnloo2 .
ow32b43xgs , & rtP . ThreePhaseProgrammableVoltageSource_VariationEntity , &
rtP . ThreePhaseProgrammableVoltageSource_VariationType , & rtP .
ThreePhaseProgrammableVoltageSource_HarmonicGeneration , & rtP .
ThreePhaseSource_Frequency , & rtP . Vdc_Amplitude , & rtP .
PWMGenerator2Level_MinMax [ 0 ] , & rtP . Constant_Value_faygct0s2b , & rtP .
Q_Value , & rtP . Gain1_Gain_mmba2zpssf , & rtP . P10kW_Time , & rtP .
P10kW_Y0 , & rtP . P10kW_YFinal , & rtP . Kv_Gain , & rtP . Kv1_Gain , & rtP
. FFInt_gainval , & rtP . FFInt_IC , & rtP . FFInt_gainval_ajjzcdjezz , & rtP
. FFInt_IC_dnt3xnjdp2 , & rtP . Gain2_Gain_asqeevkcou , & rtP .
Gain3_Gain_gnz4vn3ehd , & rtP . TransferFcn_A_dt3anvvvjk [ 0 ] , & rtP .
TransferFcn_C_ebeqd4pm5a [ 0 ] , & rtP . TransferFcn1_A [ 0 ] , & rtP .
TransferFcn1_C [ 0 ] , & rtP . TransferFcn2_A [ 0 ] , & rtP . TransferFcn2_C
[ 0 ] , & rtP . Gain2_Gain_nzx0saocj4 , & rtP . Gain3_Gain_hmwjolcezb , & rtP
. TransferFcn_A_nzocbi1yil [ 0 ] , & rtP . TransferFcn_C_gvrgkkm0gy [ 0 ] , &
rtP . TransferFcn1_A_oq1eexzdia [ 0 ] , & rtP . TransferFcn1_C_kgy1sslmk0 [ 0
] , & rtP . TransferFcn2_A_ls5rzge3gu [ 0 ] , & rtP .
TransferFcn2_C_hvsgpr5esg [ 0 ] , & rtP . Gain2_Gain_n2c2zc5fut , & rtP .
Gain3_Gain_gzq4wqubv2 , & rtP . TransferFcn_A_ctlxcv4srh [ 0 ] , & rtP .
TransferFcn_C_ieerxo0rjq [ 0 ] , & rtP . TransferFcn1_A_dxdwz5zlll [ 0 ] , &
rtP . TransferFcn1_C_lx3veeshxb [ 0 ] , & rtP . TransferFcn2_A_pejgnp0mdw [ 0
] , & rtP . TransferFcn2_C_kjbo4vmtza [ 0 ] , & rtP .
dq0toAlphaBetaZero_Alignment , & rtP . SineWaveA_Amp , & rtP . SineWaveA_Bias
, & rtP . SineWaveA_Hsin , & rtP . SineWaveA_HCos , & rtP . SineWaveA_PSin ,
& rtP . SineWaveA_PCos , & rtP . SineWaveB_Amp , & rtP . SineWaveB_Bias , &
rtP . SineWaveB_Hsin , & rtP . SineWaveB_HCos , & rtP . SineWaveB_PSin , &
rtP . SineWaveB_PCos , & rtP . SineWaveC_Amp , & rtP . SineWaveC_Bias , & rtP
. SineWaveC_Hsin , & rtP . SineWaveC_HCos , & rtP . SineWaveC_PSin , & rtP .
SineWaveC_PCos , & rtP . u4_Value , & rtP . uRon_Gain , & rtP .
Saturation_UpperSat_lphrbvohc0 , & rtP . Saturation_LowerSat_gyzt3s021b , &
rtP . Switch_Threshold_h0h0hrbrds , & rtP .
UnitDelay_InitialCondition_hnsfjn5hxn , & rtP . StateSpace_AS_param [ 0 ] , &
rtP . StateSpace_BS_param [ 0 ] , & rtP . StateSpace_CS_param [ 0 ] , & rtP .
StateSpace_DS_param [ 0 ] , & rtP . StateSpace_X0_param [ 0 ] , & rtP .
Continuous_Kp , & rtP . Continuous_Ki , & rtP . Continuous_Kd , & rtP .
Continuous_Init , & rtP . Constant1_Value_bnn31ave1a , & rtP .
Constant2_Value_awyv320bt3 , & rtP . Gain10_Gain , & rtP . HitCrossing_Offset
, & rtP . Initial_Value , & rtP . Integrator_UpperSat , & rtP .
Integrator_LowerSat , & rtP . Memory_InitialCondition_cmy5m3zyx0 , & rtP .
RateLimiter_RisingLim , & rtP . RateLimiter_FallingLim , & rtP .
Gain1_Gain_bxyi0qtgnl , & rtP . Gain3_Gain_mvygasyxhr [ 0 ] , & rtP .
CompareToConstant_const_gsz3trqyjp , & rtP .
CompareToConstant1_const_hw4vovlkze , & rtP . a21_Gain , & rtP . s1_Gain , &
rtP . Delay11_InitialCondition , & rtP . a21_Gain_igtn11js15 , & rtP .
s1_Gain_hko4bmcnti , & rtP . Delay11_InitialCondition_dkcmnnrtrg , & rtP .
Out1_Y0 , & rtP . Out2_Y0 , & rtP . timer_Y0 , & rtP . selector_Y0 , & rtP .
magnitude_Y0 , & rtP . frequency_Y0 , & rtP . phase_Y0 , & rtP .
VariationSubSystem_VariationStep , & rtP . VariationSubSystem_VariationRate ,
& rtP . VariationSubSystem_VariationFreq , & rtP .
VariationSubSystem_VariationMag , & rtP . VariationSubSystem_Ton_Variation ,
& rtP . VariationSubSystem_Toff_Variation , & rtP . Constant3_Value , & rtP .
Constant5_Value , & rtP . DiscreteTimeIntegrator_gainval , & rtP .
DiscreteTimeIntegrator_IC , & rtP . Gain2_Gain , & rtP .
donotdeletethisgain_Gain_f05p010jfj , & rtP .
donotdeletethisgain_Gain_om0hzrwmvi , & rtP .
donotdeletethisgain_Gain_pj4emxjkfc , & rtP . donotdeletethisgain_Gain , &
rtP . donotdeletethisgain_Gain_cjkn1fmmwf , & rtP .
donotdeletethisgain_Gain_p4xdjo1x0c , & rtP . Gain_Y0 , & rtP .
Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
Integrator_UpperSat_pm1zhfhqin , & rtP . Integrator_LowerSat_nkt4rnjn03 , &
rtP . Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
TransferFcn_A , & rtP . TransferFcn_C , & rtP . TransferFcn_D , & rtP .
AlphaBetaZerotodq0_Alignment_hohufqrubs , & rtP . alpha_beta_Y0 [ 0 ] , & rtP
. alpha_beta_Y0_pg4urrpzbu [ 0 ] , & rtP . Constant_Value_dvamm1lycs , & rtP
. Constant1_Value , & rtP . Constant2_Value , & rtP .
Constant3_Value_jeehzqq2f5 , & rtP . Constant4_Value , & rtP .
Constant5_Value_bojg2v1nr1 , & rtP . DiscreteTimeIntegrator1_gainval , & rtP
. DiscreteTimeIntegrator1_IC , & rtP . Gain1_Gain_onz34q5f5w , & rtP .
Step_Y0 , & rtP . Step_YFinal , & rtP . Step1_Y0 , & rtP . Step1_YFinal , &
rtP . Switch_Threshold , & rtP . Switch2_Threshold , & rtP .
UnitDelay_InitialCondition , & rtP . Du_Gain , & rtP . Integrator_x1_IC , &
rtP . Integrator_x2_IC , & rtP . Constant_Value_amasrcypll , & rtP .
integrator_IC_fa2zkozxvn , & rtP . Memory_InitialCondition_mxilddonen , & rtP
. Toavoiddivisionbyzero_UpperSat_ipy2dfjdyr , & rtP .
Toavoiddivisionbyzero_LowerSat_ipo4dvmiva , & rtP .
VariableTransportDelay_MaxDelay_gjh2uwsyu4 , & rtP .
VariableTransportDelay_InitOutput_ly4stoovo0 , & rtP .
CompareToConstant_const_c3zde2cbi4 , & rtP .
CompareToConstant1_const_efjr5x0wsv , & rtP . Gain1_Gain_nhidfscigt , & rtP .
Gain3_Gain_jp2ndmjqu5 [ 0 ] , & rtP . AlphaBetaZerotodq0_Alignment , & rtP .
A11_Gain , & rtP . A12_Gain , & rtP . A21_Gain , & rtP . A22_Gain , & rtP .
B11_Gain , & rtP . B21_Gain , & rtP . C11_Gain , & rtP . C12_Gain , & rtP .
gbv0nikqj2 . dq_Y0 [ 0 ] , & rtP . hl5zrirewt . dq_Y0 [ 0 ] , & rtP .
Constant_Value , & rtP . integrator_IC , & rtP . Memory_InitialCondition , &
rtP . Toavoiddivisionbyzero_UpperSat , & rtP . Toavoiddivisionbyzero_LowerSat
, & rtP . VariableTransportDelay_MaxDelay , & rtP .
VariableTransportDelay_InitOutput , & rtP . Constant_Value_n0qkhh1fth , & rtP
. integrator_IC_g14ialcirz , & rtP . Memory_InitialCondition_bz4nohehtu , &
rtP . Toavoiddivisionbyzero_UpperSat_amv5dob4gd , & rtP .
Toavoiddivisionbyzero_LowerSat_dsvy2fn0ag , & rtP .
VariableTransportDelay_MaxDelay_evwrynr4yh , & rtP .
VariableTransportDelay_InitOutput_d5upbocuak , & rtP .
CompareToConstant_const , & rtP . CompareToConstant1_const , & rtP .
Gain1_Gain , & rtP . Gain3_Gain [ 0 ] , & rtP . Constant2_Value_imsydp4sjx ,
& rtP . Constant3_Value_nxfd0r3vwv , & rtP . Constant4_Value_pzmijoxky1 , &
rtP . uib1_Gain , & rtP . uDLookupTable_tableData [ 0 ] , & rtP .
uDLookupTable_bp01Data [ 0 ] , & rtP . UnitDelay_InitialCondition_kjuilmwono
, & rtP . gpv2q2mna0v . dq_Y0 [ 0 ] , & rtP . aa2j2wnloo2 . dq_Y0 [ 0 ] , &
rtP . KipP , & rtP . KipQ , & rtP . KppP , & rtP . KppQ , & rtP . ki , & rtP
. kp , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof (
uint8_T ) , ( uint8_T ) SS_UINT8 , 0 , 0 , 0 } , { "struct" , "creal_T" , 0 ,
0 , sizeof ( creal_T ) , ( uint8_T ) SS_DOUBLE , 1 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 18 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 20 , 2
, 0 } , { rtwCAPI_VECTOR , 22 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 3 , 1 , 6 , 1 , 12 , 1 , 2 , 1 , 1 , 2 , 2 ,
2 , 2 , 10 , 12 , 2 , 12 , 10 , 3 , 3 , 1 , 3 } ; static const real_T
rtcapiStoredFloats [ ] = { 1.0E-6 , 0.0 , 1.0 , 5.0E-7 , 5.0E-6 , 2.5E-5 ,
1.25E-5 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , 6 , 0 }
, { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 3 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 2 ] ,
( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1
] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T )
0 } , { ( const void * ) & rtcapiStoredFloats [ 3 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 2 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 4 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
( int8_T ) 4 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 5
] , ( const void * ) & rtcapiStoredFloats [ 6 ] , ( int8_T ) 5 , ( uint8_T )
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 155 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 201 ,
rtModelParameters , 6 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1263269511U , 3066790768U , 1316343474U , 2761255352U } , ( NULL ) , 0 ,
( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * Sim6_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Sim6_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Sim6_host_InitializeDataMapInfo ( Sim6_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
