#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"struct_3rWjUg4qh0LaBgA7jvy4ZG" , 15 , 80 } , {
"struct_DQdQbIkMWeV34kyS80SufH" , 16 , 32 } , {
"struct_HoP8yLzcyPntsMzdhyBscD" , 17 , 24 } , {
"struct_oelS3oJRN3v85ZyO6rQa7G" , 18 , 112 } , {
"struct_uPZJGhhFlUv1dSuf4t0D9" , 19 , 192 } , {
"struct_FYX8Tyr7ukSNMnkMxyM9jF" , 20 , 1704 } , { "uint64_T" , 21 , 8 } , {
"int64_T" , 22 , 8 } , { "char_T" , 23 , 8 } , { "uchar_T" , 24 , 8 } , {
"time_T" , 25 , 8 } } ; static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T
) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof (
int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) ,
sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof (
pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T ) , sizeof (
int32_T ) , sizeof ( struct_3rWjUg4qh0LaBgA7jvy4ZG ) , sizeof (
struct_DQdQbIkMWeV34kyS80SufH ) , sizeof ( struct_HoP8yLzcyPntsMzdhyBscD ) ,
sizeof ( struct_oelS3oJRN3v85ZyO6rQa7G ) , sizeof (
struct_uPZJGhhFlUv1dSuf4t0D9 ) , sizeof ( struct_FYX8Tyr7ukSNMnkMxyM9jF ) ,
sizeof ( uint64_T ) , sizeof ( int64_T ) , sizeof ( char_T ) , sizeof (
uchar_T ) , sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] =
{ "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "physical_connection" ,
"struct_3rWjUg4qh0LaBgA7jvy4ZG" , "struct_DQdQbIkMWeV34kyS80SufH" ,
"struct_HoP8yLzcyPntsMzdhyBscD" , "struct_oelS3oJRN3v85ZyO6rQa7G" ,
"struct_uPZJGhhFlUv1dSuf4t0D9" , "struct_FYX8Tyr7ukSNMnkMxyM9jF" , "uint64_T"
, "int64_T" , "char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition
rtBTransitions [ ] = { { ( char_T * ) ( & rtB . gap4mluorh . re ) , 0 , 1 , 2
} , { ( char_T * ) ( & rtB . gktfzcs3fd ) , 0 , 0 , 169 } , { ( char_T * ) (
& rtB . ejjuk1fwje ) , 3 , 0 , 6 } , { ( char_T * ) ( & rtB . hzmul4slgt ) ,
8 , 0 , 9 } , { ( char_T * ) ( & rtB . hl5zrirewt . otn2ta4rye ) , 0 , 0 , 2
} , { ( char_T * ) ( & rtB . gbv0nikqj2 . j2nl0k3bjo ) , 0 , 0 , 2 } , { (
char_T * ) ( & rtB . aa2j2wnloo2 . otn2ta4rye ) , 0 , 0 , 2 } , { ( char_T *
) ( & rtB . gpv2q2mna0v . j2nl0k3bjo ) , 0 , 0 , 2 } , { ( char_T * ) ( &
rtDW . naju1uwbkg [ 0 ] ) , 0 , 0 , 34 } , { ( char_T * ) ( & rtDW .
empra3chml . AS ) , 11 , 0 , 16 } , { ( char_T * ) ( & rtDW . cbxygsrulg ) ,
6 , 0 , 3 } , { ( char_T * ) ( & rtDW . mr1ke3zacb ) , 7 , 0 , 1 } , { (
char_T * ) ( & rtDW . crtkqsbmaj [ 0 ] ) , 10 , 0 , 20 } , { ( char_T * ) ( &
rtDW . ee4ok4zlel ) , 2 , 0 , 5 } , { ( char_T * ) ( & rtDW . aw1t1zwgas ) ,
3 , 0 , 4 } , { ( char_T * ) ( & rtDW . oacr45potf ) , 8 , 0 , 12 } , { (
char_T * ) ( & rtDW . hl5zrirewt . fqy4beoqau ) , 2 , 0 , 1 } , { ( char_T *
) ( & rtDW . hl5zrirewt . mvk4qyxu0n ) , 8 , 0 , 1 } , { ( char_T * ) ( &
rtDW . gbv0nikqj2 . ofjd3uadhp ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
gbv0nikqj2 . eya5d5vx55 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
aa2j2wnloo2 . fqy4beoqau ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
aa2j2wnloo2 . mvk4qyxu0n ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
gpv2q2mna0v . ofjd3uadhp ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
gpv2q2mna0v . eya5d5vx55 ) , 8 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 24U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . KipP ) , 0 , 0 , 416 } , { (
char_T * ) ( & rtP . selector_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP .
hl5zrirewt . dq_Y0 [ 0 ] ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP .
gbv0nikqj2 . dq_Y0 [ 0 ] ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP .
aa2j2wnloo2 . dq_Y0 [ 0 ] ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP .
gpv2q2mna0v . dq_Y0 [ 0 ] ) , 0 , 0 , 2 } } ; static DataTypeTransitionTable
rtPTransTable = { 6U , rtPTransitions } ;
