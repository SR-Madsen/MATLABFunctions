#ifndef RTW_HEADER_Sim6_h_
#define RTW_HEADER_Sim6_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef Sim6_COMMON_INCLUDES_
#define Sim6_COMMON_INCLUDES_
#include <stdio.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Sim6_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME Sim6
#define NSAMPLE_TIMES (7) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (142) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (29)   
#elif NCSTATES != 29
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T j2nl0k3bjo ; real_T dxu5h4veqy ; } ez1qc1u4ss ;
typedef struct { int8_T ofjd3uadhp ; boolean_T eya5d5vx55 ; } etsotvigvh ;
typedef struct { real_T otn2ta4rye ; real_T ow32b43xgs ; } b000baele5 ;
typedef struct { int8_T fqy4beoqau ; boolean_T mvk4qyxu0n ; } htflfovccy ;
typedef struct { creal_T gap4mluorh ; real_T gktfzcs3fd ; real_T dbmx3g5hpc ;
real_T dm5evipofq ; real_T bpposa5psj [ 12 ] ; real_T a03vq2btj3 [ 6 ] ;
real_T bgjph5tzti [ 6 ] ; real_T kqg04a251b ; real_T djau2g1olc [ 3 ] ;
real_T paaqohv05q [ 3 ] ; real_T k2t2anegon ; real_T fo12qitrhm ; real_T
kkx3bsha4q ; real_T prxgf4reyt ; real_T dtyrdyfgxc ; real_T lhih2qrjjs ;
real_T j2eixrpwyy ; real_T m5uukj3ycd ; real_T kq0uqgcvcf ; real_T k5kueqchg5
; real_T m5bsg3jkvc ; real_T exoldmyxco ; real_T ffvcceoghv [ 3 ] ; real_T
dgq4jw1zua ; real_T k01onl4g5t ; real_T llqrd441m5 ; real_T exj242slie ;
real_T ckayt42vf3 ; real_T oijk30i103 ; real_T jkth2sfciv ; real_T psgxvcmjhn
; real_T mqhymewypv ; real_T hhnk2g0wfl ; real_T gphcjhvv1a ; real_T
jvo1ddk5yj ; real_T gbqdu1hcwl ; real_T k0pwj4jxiq ; real_T dijcpphi4p ;
real_T amr33vumq0 ; real_T gc2xht4yqo ; real_T iosedcm1tf ; real_T oll4rfkmhz
; real_T cnh4llzau0 ; real_T aebuj4jliw ; real_T f2yfeiz4wx ; real_T
mm4x5kerfj ; real_T ejg1ybzhgl ; real_T k1rxqwgc5o ; real_T n4ots5cknz ;
real_T brzgt5o0ly ; real_T fbrwvcuz2e ; real_T lrkvpii4gh ; real_T orccexijhq
; real_T erof3sa2ef ; real_T kyvouqb0no ; real_T gungbq04sb ; real_T
b4jfht23g2 ; real_T f0vgkk3bhk [ 3 ] ; real_T dvkqumepgk [ 3 ] ; real_T
fvbww5mjui [ 2 ] ; real_T gimxw5025n [ 2 ] ; real_T j2ygziwuza [ 3 ] ; real_T
i3co5cpqer [ 3 ] ; real_T pusmndwhp4 [ 3 ] ; real_T li0okspf41 ; real_T
eqrscq4msa ; real_T mv0i5cphjf ; real_T bt2aomm4y4 ; real_T bj5uxavhae ;
real_T a4ynar3r0p ; real_T kd4hozccoi ; real_T itzulpyuw2 ; real_T otuvlsx5ys
; real_T j0n1jzgntq ; real_T jmwusjiov1 ; real_T jb4fsta5my ; real_T
hm5ofsqtib ; real_T amhtuysrig ; real_T aylp23sizt ; real_T fdwocsfez5 ;
real_T cdgmcxdgxx [ 6 ] ; real_T it4rtc1qod ; real_T dsjsfniaum ; real_T
dcuhhc42lm ; real_T osecmroasz ; real_T gei3qlbkau ; real_T k2r2gd5thc ;
real_T hxgcychvxe ; real_T ojpmhqp3hb ; real_T dfsza0jb3r ; real_T aydt5pakqc
; real_T gahdo2523m ; real_T brq4reciat ; real_T mv2ve5xuao ; real_T
lzxedsxie0 ; real_T f2eidvmh01 ; real_T ermyprlyya ; real_T jqerscg1zt ;
real_T pqq2mzl5yy ; real_T emtuteg24p ; real_T gfw00daf11 ; real_T klqpdibj32
; real_T jdm55m0vau ; real_T hohn5tgzlv ; real_T asbptj5zaz ; real_T
nred03mov5 ; real_T onjteuktwt ; real_T jfashjspdq ; real_T hujgllbkhe ;
real_T pe3tnbqbgy ; real_T emd031udec ; real_T hs004dp4hy ; real_T lejcvssl30
; real_T omw4a1utb1 ; real_T aiseatx5p4 [ 3 ] ; real_T lsxposbkab [ 3 ] ;
real_T p52yfpva5l [ 2 ] ; real_T fdljtyo4lz ; real_T jwdiimvvl4 ; real_T
e3pcbwyj3i ; real_T aah0x3cxyl ; uint8_T ejjuk1fwje ; uint8_T bjycl5wbcz ;
uint8_T ogehm3eyx3 ; uint8_T oakfin4jis ; uint8_T eo33rm2kiy ; uint8_T
jr2eclq22h ; boolean_T hzmul4slgt ; boolean_T lbe40ygcva ; boolean_T
ejejjrbn43 [ 3 ] ; boolean_T g524d0rboe ; boolean_T k0zgmoo03i ; boolean_T
kiunlxs5sx ; boolean_T bx3i1gippc ; b000baele5 hl5zrirewt ; ez1qc1u4ss
gbv0nikqj2 ; b000baele5 aa2j2wnloo2 ; ez1qc1u4ss gpv2q2mna0v ; } B ; typedef
struct { real_T naju1uwbkg [ 2 ] ; real_T iz4mjb3fpi [ 6 ] ; real_T
kanrys502u ; real_T il2g04n2zg ; real_T lc4skbr0sd ; real_T kmcobpcqvr ;
real_T dcvx0x0nhj ; real_T jonetifjdl ; real_T k5octspggf ; real_T kurtqaimb2
; real_T m3xa5qdlgu ; real_T g4a2feilda ; real_T ati3zogtqu ; real_T
n5yzxageiq ; real_T hxzxqy2ytd ; real_T lpdpgewspm ; real_T bwt1hrltpz ;
real_T o4yzgxidzo ; real_T puptsnuvic ; real_T do51saudm1 ; real_T ejvm3rk4rw
; real_T hrtqjrd53x ; real_T pvzxgas2b3 ; real_T edvu1xljbk ; real_T
d3leen4kcy ; struct { real_T modelTStart ; } jycqzsqlqh ; struct { real_T
modelTStart ; } omzfzlvkmy ; struct { real_T modelTStart ; } hrjhnmw2gy ;
struct { void * AS ; void * BS ; void * CS ; void * DS ; void * DX_COL ; void
* BD_COL ; void * TMP1 ; void * TMP2 ; void * XTMP ; void * SWITCH_STATUS ;
void * SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ; void * USWLAST ;
void * XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ; void * IDX_SW_CHG
; void * Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW ; void *
SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } empra3chml ; struct { void *
LoggedData [ 2 ] ; } f4qjpvtvia ; struct { void * TUbufferPtrs [ 3 ] ; }
nr4hpz0s5b ; struct { void * LoggedData [ 2 ] ; } nowwneuenp ; struct { void
* LoggedData [ 2 ] ; } iske0ojumf ; struct { void * TUbufferPtrs [ 3 ] ; }
mlq3s0zii4 ; struct { void * TUbufferPtrs [ 3 ] ; } n2b5jg51yt ; int32_T
cbxygsrulg ; int32_T oehqsdtju1 ; int32_T ebrnrfebzf ; uint32_T mr1ke3zacb ;
int_T crtkqsbmaj [ 11 ] ; int_T kuxuhbis4w ; struct { int_T Tail ; int_T Head
; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; } e3u5ld2y51 ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } itw05pv4q1 ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } oyd0zxlfez ; int_T
dg3sdnhfhz ; int_T chgudtwki5 ; int_T cxei33jqmq ; int_T bisetz5iuz ; int_T
lguevo5cl5 ; int8_T ee4ok4zlel ; int8_T mvk1crirkl ; int8_T c2l3p2qtjf ;
int8_T kza5ow0kr4 ; int8_T oxvhzb4uhf ; uint8_T aw1t1zwgas ; uint8_T
aisofpnorv ; uint8_T hsca3knam3 ; uint8_T loledzy1qu ; boolean_T oacr45potf ;
boolean_T lp022slzwu ; boolean_T ls1rbfacqf [ 3 ] ; boolean_T navvsf1ufo ;
boolean_T fbyhlicb5e ; boolean_T nf2gbckq3n ; boolean_T o2b5vrjagl ;
boolean_T bv4jm4qenv ; boolean_T fbzp2gawrm ; boolean_T ovo53pq3zf ;
htflfovccy hl5zrirewt ; etsotvigvh gbv0nikqj2 ; htflfovccy aa2j2wnloo2 ;
etsotvigvh gpv2q2mna0v ; } DW ; typedef struct { real_T iumu3kzzhr ; real_T
iip1hksxhe ; real_T imjxbjnrao ; real_T hvdzss0qy0 ; real_T mgdsbp3tlu ;
real_T mlt40cyrau ; real_T fb24y2esxb ; real_T jh55bpubqj [ 2 ] ; real_T
jn4nrdhpx1 [ 2 ] ; real_T fyyiprok3t [ 2 ] ; real_T bjpvgeyygb [ 2 ] ; real_T
jkhhrdnef2 [ 2 ] ; real_T ns23ofbiao [ 2 ] ; real_T fozte2xjae [ 2 ] ; real_T
ggl1vuf0v0 [ 2 ] ; real_T eavqvzqdwf [ 2 ] ; real_T bpxu1bsrls ; real_T
c2tj4z32zx ; real_T jbjlk4lmud ; real_T hcrv11zemx ; } X ; typedef struct {
real_T iumu3kzzhr ; real_T iip1hksxhe ; real_T imjxbjnrao ; real_T hvdzss0qy0
; real_T mgdsbp3tlu ; real_T mlt40cyrau ; real_T fb24y2esxb ; real_T
jh55bpubqj [ 2 ] ; real_T jn4nrdhpx1 [ 2 ] ; real_T fyyiprok3t [ 2 ] ; real_T
bjpvgeyygb [ 2 ] ; real_T jkhhrdnef2 [ 2 ] ; real_T ns23ofbiao [ 2 ] ; real_T
fozte2xjae [ 2 ] ; real_T ggl1vuf0v0 [ 2 ] ; real_T eavqvzqdwf [ 2 ] ; real_T
bpxu1bsrls ; real_T c2tj4z32zx ; real_T jbjlk4lmud ; real_T hcrv11zemx ; }
XDot ; typedef struct { boolean_T iumu3kzzhr ; boolean_T iip1hksxhe ;
boolean_T imjxbjnrao ; boolean_T hvdzss0qy0 ; boolean_T mgdsbp3tlu ;
boolean_T mlt40cyrau ; boolean_T fb24y2esxb ; boolean_T jh55bpubqj [ 2 ] ;
boolean_T jn4nrdhpx1 [ 2 ] ; boolean_T fyyiprok3t [ 2 ] ; boolean_T
bjpvgeyygb [ 2 ] ; boolean_T jkhhrdnef2 [ 2 ] ; boolean_T ns23ofbiao [ 2 ] ;
boolean_T fozte2xjae [ 2 ] ; boolean_T ggl1vuf0v0 [ 2 ] ; boolean_T
eavqvzqdwf [ 2 ] ; boolean_T bpxu1bsrls ; boolean_T c2tj4z32zx ; boolean_T
jbjlk4lmud ; boolean_T hcrv11zemx ; } XDis ; typedef struct { real_T
iumu3kzzhr ; real_T iip1hksxhe ; real_T imjxbjnrao ; real_T hvdzss0qy0 ;
real_T mgdsbp3tlu ; real_T mlt40cyrau ; real_T fb24y2esxb ; real_T jh55bpubqj
[ 2 ] ; real_T jn4nrdhpx1 [ 2 ] ; real_T fyyiprok3t [ 2 ] ; real_T bjpvgeyygb
[ 2 ] ; real_T jkhhrdnef2 [ 2 ] ; real_T ns23ofbiao [ 2 ] ; real_T fozte2xjae
[ 2 ] ; real_T ggl1vuf0v0 [ 2 ] ; real_T eavqvzqdwf [ 2 ] ; real_T bpxu1bsrls
; real_T c2tj4z32zx ; real_T jbjlk4lmud ; real_T hcrv11zemx ; } CStateAbsTol
; typedef struct { real_T iumu3kzzhr ; real_T iip1hksxhe ; real_T imjxbjnrao
; real_T hvdzss0qy0 ; real_T mgdsbp3tlu ; real_T mlt40cyrau ; real_T
fb24y2esxb ; real_T jh55bpubqj [ 2 ] ; real_T jn4nrdhpx1 [ 2 ] ; real_T
fyyiprok3t [ 2 ] ; real_T bjpvgeyygb [ 2 ] ; real_T jkhhrdnef2 [ 2 ] ; real_T
ns23ofbiao [ 2 ] ; real_T fozte2xjae [ 2 ] ; real_T ggl1vuf0v0 [ 2 ] ; real_T
eavqvzqdwf [ 2 ] ; real_T bpxu1bsrls ; real_T c2tj4z32zx ; real_T jbjlk4lmud
; real_T hcrv11zemx ; } CXPtMin ; typedef struct { real_T iumu3kzzhr ; real_T
iip1hksxhe ; real_T imjxbjnrao ; real_T hvdzss0qy0 ; real_T mgdsbp3tlu ;
real_T mlt40cyrau ; real_T fb24y2esxb ; real_T jh55bpubqj [ 2 ] ; real_T
jn4nrdhpx1 [ 2 ] ; real_T fyyiprok3t [ 2 ] ; real_T bjpvgeyygb [ 2 ] ; real_T
jkhhrdnef2 [ 2 ] ; real_T ns23ofbiao [ 2 ] ; real_T fozte2xjae [ 2 ] ; real_T
ggl1vuf0v0 [ 2 ] ; real_T eavqvzqdwf [ 2 ] ; real_T bpxu1bsrls ; real_T
c2tj4z32zx ; real_T jbjlk4lmud ; real_T hcrv11zemx ; } CXPtMax ; typedef
struct { real_T dprhnx0hk5 ; real_T nmcpophsx3 ; real_T cyevdlgrse ; real_T
jgpeeoiue2 ; real_T iuxaqwhjjh ; real_T oqivsa4eyr ; real_T m1itfgxaol ;
real_T ix3q42sklm ; real_T jdi1rp00nt ; real_T d2qflxrvek ; real_T fipbq4kbkj
; real_T impstjptgt ; real_T nocih0nohz ; real_T m43iiyidnn [ 3 ] ; real_T
jd55xiah2i ; real_T kcppnfkfuz ; real_T kpi30mmi2d ; real_T flx3eb04bc ; }
ZCV ; typedef struct { ZCSigState ff24yskbma ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct lnfuzpqlv0_ { real_T
dq_Y0 [ 2 ] ; } ; struct anyxbustxf_ { real_T dq_Y0 [ 2 ] ; } ; struct P_ {
real_T KipP ; real_T KipQ ; real_T KppP ; real_T KppQ ; real_T ki ; real_T kp
; real_T AlphaBetaZerotodq0_Alignment ; real_T
AlphaBetaZerotodq0_Alignment_hohufqrubs ; real_T dq0toAlphaBetaZero_Alignment
; real_T Vdc_Amplitude ; real_T ThreePhaseSource_Frequency ; real_T
ThreePhaseProgrammableVoltageSource_HarmonicGeneration ; real_T
Continuous_Init ; real_T Continuous_Kd ; real_T Continuous_Ki ; real_T
Continuous_Kp ; real_T PWMGenerator2Level_MinMax [ 2 ] ; real_T
VariationSubSystem_Toff_Variation ; real_T VariationSubSystem_Ton_Variation ;
real_T ThreePhaseProgrammableVoltageSource_VariationEntity ; real_T
VariationSubSystem_VariationFreq ; real_T VariationSubSystem_VariationMag ;
real_T VariationSubSystem_VariationRate ; real_T
VariationSubSystem_VariationStep ; real_T
ThreePhaseProgrammableVoltageSource_VariationType ; real_T
CompareToConstant_const ; real_T CompareToConstant1_const ; real_T
CompareToConstant_const_c3zde2cbi4 ; real_T
CompareToConstant1_const_efjr5x0wsv ; real_T
CompareToConstant_const_gsz3trqyjp ; real_T
CompareToConstant1_const_hw4vovlkze ; real_T Gain_Y0 ; real_T
VariableTransportDelay_MaxDelay ; real_T VariableTransportDelay_InitOutput ;
real_T integrator_IC ; real_T Memory_InitialCondition ; real_T
VariableTransportDelay_MaxDelay_evwrynr4yh ; real_T
VariableTransportDelay_InitOutput_d5upbocuak ; real_T
integrator_IC_g14ialcirz ; real_T Memory_InitialCondition_bz4nohehtu ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
Toavoiddivisionbyzero_UpperSat ; real_T Toavoiddivisionbyzero_LowerSat ;
real_T Toavoiddivisionbyzero_UpperSat_amv5dob4gd ; real_T
Toavoiddivisionbyzero_LowerSat_dsvy2fn0ag ; real_T Gain3_Gain [ 9 ] ; real_T
Gain1_Gain ; real_T Constant_Value ; real_T Constant_Value_n0qkhh1fth ;
real_T alpha_beta_Y0 [ 2 ] ; real_T alpha_beta_Y0_pg4urrpzbu [ 2 ] ; real_T
Out1_Y0 ; real_T Out2_Y0 ; real_T timer_Y0 ; real_T magnitude_Y0 ; real_T
frequency_Y0 ; real_T phase_Y0 ; real_T DiscreteTimeIntegrator_gainval ;
real_T DiscreteTimeIntegrator_IC ; real_T Step1_Y0 ; real_T Step1_YFinal ;
real_T Step_Y0 ; real_T Step_YFinal ; real_T DiscreteTimeIntegrator1_gainval
; real_T DiscreteTimeIntegrator1_IC ; real_T UnitDelay_InitialCondition ;
real_T Switch2_Threshold ; real_T Gain2_Gain ; real_T Switch_Threshold ;
real_T Constant3_Value ; real_T Constant5_Value ; real_T
Constant_Value_dvamm1lycs ; real_T Constant1_Value ; real_T Constant2_Value ;
real_T Constant3_Value_jeehzqq2f5 ; real_T Constant4_Value ; real_T
Constant5_Value_bojg2v1nr1 ; real_T Gain1_Gain_onz34q5f5w ; real_T
SineWaveA_Amp ; real_T SineWaveA_Bias ; real_T SineWaveA_Hsin ; real_T
SineWaveA_HCos ; real_T SineWaveA_PSin ; real_T SineWaveA_PCos ; real_T
SineWaveB_Amp ; real_T SineWaveB_Bias ; real_T SineWaveB_Hsin ; real_T
SineWaveB_HCos ; real_T SineWaveB_PSin ; real_T SineWaveB_PCos ; real_T
SineWaveC_Amp ; real_T SineWaveC_Bias ; real_T SineWaveC_Hsin ; real_T
SineWaveC_HCos ; real_T SineWaveC_PSin ; real_T SineWaveC_PCos ; real_T
StateSpace_AS_param [ 4 ] ; real_T StateSpace_BS_param [ 20 ] ; real_T
StateSpace_CS_param [ 24 ] ; real_T StateSpace_DS_param [ 120 ] ; real_T
StateSpace_X0_param [ 2 ] ; real_T u4_Value ; real_T uRon_Gain ; real_T
Switch_Threshold_h0h0hrbrds ; real_T Saturation_UpperSat_lphrbvohc0 ; real_T
Saturation_LowerSat_gyzt3s021b ; real_T UnitDelay_InitialCondition_hnsfjn5hxn
; real_T P10kW_Time ; real_T P10kW_Y0 ; real_T P10kW_YFinal ; real_T
donotdeletethisgain_Gain ; real_T donotdeletethisgain_Gain_cjkn1fmmwf ;
real_T donotdeletethisgain_Gain_p4xdjo1x0c ; real_T Kv1_Gain ; real_T
donotdeletethisgain_Gain_f05p010jfj ; real_T
donotdeletethisgain_Gain_om0hzrwmvi ; real_T
donotdeletethisgain_Gain_pj4emxjkfc ; real_T Kv_Gain ; real_T s1_Gain ;
real_T Delay11_InitialCondition ; real_T a21_Gain ; real_T FFInt_gainval ;
real_T FFInt_IC ; real_T s1_Gain_hko4bmcnti ; real_T
Delay11_InitialCondition_dkcmnnrtrg ; real_T a21_Gain_igtn11js15 ; real_T
FFInt_gainval_ajjzcdjezz ; real_T FFInt_IC_dnt3xnjdp2 ; real_T
Gain1_Gain_mmba2zpssf ; real_T Initial_Value ; real_T Integrator_UpperSat ;
real_T Integrator_LowerSat ; real_T HitCrossing_Offset ; real_T
Memory_InitialCondition_cmy5m3zyx0 ; real_T Integrator_UpperSat_pm1zhfhqin ;
real_T Integrator_LowerSat_nkt4rnjn03 ; real_T
VariableTransportDelay_MaxDelay_gjh2uwsyu4 ; real_T
VariableTransportDelay_InitOutput_ly4stoovo0 ; real_T
integrator_IC_fa2zkozxvn ; real_T Memory_InitialCondition_mxilddonen ; real_T
TransferFcn_A ; real_T TransferFcn_C ; real_T TransferFcn_D ; real_T
Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T Gain10_Gain ;
real_T RateLimiter_RisingLim ; real_T RateLimiter_FallingLim ; real_T
Integrator_x1_IC ; real_T A11_Gain ; real_T Integrator_x2_IC ; real_T
A12_Gain ; real_T A21_Gain ; real_T A22_Gain ; real_T B11_Gain ; real_T
B21_Gain ; real_T C11_Gain ; real_T C12_Gain ; real_T Du_Gain ; real_T
Toavoiddivisionbyzero_UpperSat_ipy2dfjdyr ; real_T
Toavoiddivisionbyzero_LowerSat_ipo4dvmiva ; real_T Gain3_Gain_jp2ndmjqu5 [ 9
] ; real_T Gain1_Gain_nhidfscigt ; real_T Gain3_Gain_mvygasyxhr [ 9 ] ;
real_T TransferFcn1_A [ 2 ] ; real_T TransferFcn1_C [ 2 ] ; real_T
Gain2_Gain_asqeevkcou ; real_T TransferFcn2_A [ 2 ] ; real_T TransferFcn2_C [
2 ] ; real_T Gain3_Gain_gnz4vn3ehd ; real_T TransferFcn_A_dt3anvvvjk [ 2 ] ;
real_T TransferFcn_C_ebeqd4pm5a [ 2 ] ; real_T Constant3_Value_nxfd0r3vwv ;
real_T Constant4_Value_pzmijoxky1 ; real_T uib1_Gain ; real_T
uDLookupTable_tableData [ 3 ] ; real_T uDLookupTable_bp01Data [ 3 ] ; real_T
Constant2_Value_imsydp4sjx ; real_T TransferFcn_A_nzocbi1yil [ 2 ] ; real_T
TransferFcn_C_gvrgkkm0gy [ 2 ] ; real_T TransferFcn1_A_oq1eexzdia [ 2 ] ;
real_T TransferFcn1_C_kgy1sslmk0 [ 2 ] ; real_T Gain2_Gain_nzx0saocj4 ;
real_T TransferFcn2_A_ls5rzge3gu [ 2 ] ; real_T TransferFcn2_C_hvsgpr5esg [ 2
] ; real_T Gain3_Gain_hmwjolcezb ; real_T TransferFcn_A_ctlxcv4srh [ 2 ] ;
real_T TransferFcn_C_ieerxo0rjq [ 2 ] ; real_T TransferFcn1_A_dxdwz5zlll [ 2
] ; real_T TransferFcn1_C_lx3veeshxb [ 2 ] ; real_T Gain2_Gain_n2c2zc5fut ;
real_T TransferFcn2_A_pejgnp0mdw [ 2 ] ; real_T TransferFcn2_C_kjbo4vmtza [ 2
] ; real_T Gain3_Gain_gzq4wqubv2 ; real_T
UnitDelay_InitialCondition_kjuilmwono ; real_T Constant_Value_faygct0s2b ;
real_T Constant1_Value_bnn31ave1a ; real_T Constant2_Value_awyv320bt3 ;
real_T Constant_Value_amasrcypll ; real_T Gain1_Gain_bxyi0qtgnl ; real_T
Q_Value ; boolean_T selector_Y0 ; anyxbustxf hl5zrirewt ; lnfuzpqlv0
gbv0nikqj2 ; anyxbustxf aa2j2wnloo2 ; lnfuzpqlv0 gpv2q2mna0v ; } ; extern
const real_T Sim6_RGND ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern PrevZCX rtPrevZCX ;
extern P rtP ; extern mxArray * mr_Sim6_GetDWork ( ) ; extern void
mr_Sim6_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_Sim6_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Sim6_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
