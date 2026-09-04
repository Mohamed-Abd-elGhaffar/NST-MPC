#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "MIL_Testing_capi_host.h"
#define sizeof(...) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 22
#endif
#ifndef SS_INT64
#define SS_INT64 23
#endif
#else
#include "builtin_typeid_types.h"
#include "MIL_Testing.h"
#include "MIL_Testing_capi.h"
#include "MIL_Testing_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING ( "MIL_Testing/Data Gathering" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering" ) , TARGET_STRING ( "" ) , 1 , 0 , 1 , 0 , 0 } , { 2 , 1 , TARGET_STRING ( "MIL_Testing/Data Gathering" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 3 , 5 , TARGET_STRING ( "MIL_Testing/Data Gathering" ) , TARGET_STRING ( "" ) , 3 , 1 , 0 , 0 , 0 } , { 4 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering" ) , TARGET_STRING ( "" ) , 4 , 0 , 2 , 0 , 0 } , { 5 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering" ) , TARGET_STRING ( "" ) , 5 , 0 , 3 , 0 , 0 } , { 6 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering" ) , TARGET_STRING ( "" ) , 6 , 0 , 4 , 0 , 0 } , { 7 , 6 , TARGET_STRING ( "MIL_Testing/EKF_agg" ) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 8 , 6 , TARGET_STRING ( "MIL_Testing/EKF_agg" ) , TARGET_STRING ( "" ) , 1 , 0 , 4 , 0 , 1 } , { 9 , 9 , TARGET_STRING ( "MIL_Testing/EKF_gate" ) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 2 } , { 10 , 9 , TARGET_STRING ( "MIL_Testing/EKF_gate" ) , TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 2 } , { 11 , 9 , TARGET_STRING ( "MIL_Testing/EKF_gate" ) , TARGET_STRING ( "" ) , 2 , 0 , 3 , 0 , 2 } , { 12 , 13 , TARGET_STRING ( "MIL_Testing/MPC" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 13 , 0 , TARGET_STRING ( "MIL_Testing/RT" ) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 3 } , { 14 , 0 , TARGET_STRING ( "MIL_Testing/RT1" ) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 1 } , { 15 , 0 , TARGET_STRING ( "MIL_Testing/RT11" ) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 16 , 0 , TARGET_STRING ( "MIL_Testing/RT12" ) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 17 , 0 , TARGET_STRING ( "MIL_Testing/RT13" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 18 , 0 , TARGET_STRING ( "MIL_Testing/RT14" ) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 19 , 0 , TARGET_STRING ( "MIL_Testing/RT15" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 2 } , { 20 , 0 , TARGET_STRING ( "MIL_Testing/RT16" ) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 21 , 0 , TARGET_STRING ( "MIL_Testing/RT2" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 1 } , { 22 , 0 , TARGET_STRING ( "MIL_Testing/RT3" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 23 , 0 , TARGET_STRING ( "MIL_Testing/RT4" ) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 3 } , { 24 , 0 , TARGET_STRING ( "MIL_Testing/RT5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 25 , 0 , TARGET_STRING ( "MIL_Testing/RT6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 26 , 0 , TARGET_STRING ( "MIL_Testing/RT7" ) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING ( "MIL_Testing/RT8" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 28 , 0 , TARGET_STRING ( "MIL_Testing/RT9" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 29 , 1 , TARGET_STRING ( "MIL_Testing/Data Gathering/MATLAB System1" ) , TARGET_STRING ( "Omega" ) , 1 , 0 , 0 , 0 , 0 } , { 30 , 1 , TARGET_STRING ( "MIL_Testing/Data Gathering/MATLAB System1" ) , TARGET_STRING ( "Load" ) , 2 , 0 , 0 , 0 , 0 } , { 31 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering/MATLAB System2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 32 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering/MATLAB System2" ) , TARGET_STRING ( "" ) , 1 , 0 , 2 , 0 , 0 } , { 33 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering/MATLAB System2" ) , TARGET_STRING ( "" ) , 2 , 0 , 3 , 0 , 0 } , { 34 , 2 , TARGET_STRING ( "MIL_Testing/Data Gathering/MATLAB System2" ) , TARGET_STRING ( "" ) , 3 , 0 , 4 , 0 , 0 } , { 35 , 9 , TARGET_STRING ( "MIL_Testing/EKF_gate/Gate_EKF1" ) , TARGET_STRING ( "X_hat" ) , 0 , 0 , 6 , 0 , 2 } , { 36 , 9 , TARGET_STRING ( "MIL_Testing/EKF_gate/Gate_EKF1" ) , TARGET_STRING ( "" ) , 1 , 0 , 3 , 0 , 2 } , { 37 , 11 , TARGET_STRING ( "MIL_Testing/MPC/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 38 , 13 , TARGET_STRING ( "MIL_Testing/MPC/Unit Delay" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 39 , 5 , TARGET_STRING ( "MIL_Testing/Data Gathering/Detect Change/FixPt Relational Operator" ) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 40 , 6 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 1 } , { 41 , 6 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/MATLAB Function" ) , TARGET_STRING ( "" ) , 1 , 0 , 4 , 0 , 1 } , { 42 , 6 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/MATLAB Function" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 1 } , { 43 , 6 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/MATLAB Function" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 1 } , { 44 , 8 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Constant" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 45 , TARGET_STRING ( "MIL_Testing/RT" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING ( "MIL_Testing/RT1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING ( "MIL_Testing/RT11" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 48 , TARGET_STRING ( "MIL_Testing/RT12" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING ( "MIL_Testing/RT13" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING ( "MIL_Testing/RT14" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING ( "MIL_Testing/RT15" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING ( "MIL_Testing/RT16" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING ( "MIL_Testing/RT2" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING ( "MIL_Testing/RT3" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING ( "MIL_Testing/RT4" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING ( "MIL_Testing/RT5" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING ( "MIL_Testing/RT6" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING ( "MIL_Testing/RT7" ) , TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 59 , TARGET_STRING ( "MIL_Testing/RT8" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING ( "MIL_Testing/RT9" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING ( "MIL_Testing/Data Gathering/Detect Change" ) , TARGET_STRING ( "vinit" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING ( "MIL_Testing/Data Gathering/Pulse Generator" ) , TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING ( "MIL_Testing/Data Gathering/Pulse Generator" ) , TARGET_STRING ( "Period" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING ( "MIL_Testing/Data Gathering/Pulse Generator" ) , TARGET_STRING ( "PulseWidth" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING ( "MIL_Testing/Data Gathering/Pulse Generator" ) , TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0 } , { 66 , TARGET_STRING ( "MIL_Testing/EKF_agg/Detect Change1" ) , TARGET_STRING ( "vinit" ) , 1 , 0 , 0 } , { 67 , TARGET_STRING ( "MIL_Testing/EKF_gate/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 68 , TARGET_STRING ( "MIL_Testing/EKF_gate/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING ( "MIL_Testing/EKF_gate/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 70 , TARGET_STRING ( "MIL_Testing/EKF_gate/Constant5" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 71 , TARGET_STRING ( "MIL_Testing/EKF_gate/Step1" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING ( "MIL_Testing/EKF_gate/Step1" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING ( "MIL_Testing/EKF_gate/Step1" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING ( "MIL_Testing/MPC/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING ( "MIL_Testing/MPC/Unit Delay" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 77 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Step1" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Step1" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 79 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Step1" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Delay2" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Variable Integer Delay" ) , TARGET_STRING ( "DiagnosticForDelayLength" ) , 2 , 0 , 0 } , { 82 , TARGET_STRING ( "MIL_Testing/EKF_agg/Subsystem/Variable Integer Delay" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 83 , TARGET_STRING ( "MIL_Testing/MPC/Signal Editor/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) , 0 , 8 , 0 } , { 84 , TARGET_STRING ( "MIL_Testing/MPC/Signal Editor/fromWS_Signal 1" ) , TARGET_STRING ( "Data0" ) , 0 , 8 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 85 , TARGET_STRING ( "Q" ) , 0 , 4 , 0 } , { 86 , TARGET_STRING ( "T_S" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . hvbnpziw45 , & rtB . i5dfrly4pb [
0 ] , & rtB . j2ny3wc1th , & rtB . psxllogfzm , & rtB . hqfbb0iret [ 0 ] , &
rtB . etbnu02wn1 [ 0 ] , & rtB . erku2k0xec [ 0 ] , & rtB . lcdsgbjfwb [ 0 ]
, & rtB . fstyznqnc5 [ 0 ] , & rtB . ahdogngpdy [ 0 ] , & rtB . ahdogngpdy [
0 ] , & rtB . ddbaqxsz3c [ 0 ] , & rtB . g3dvnnpaww , & rtB . lqpivh20ue [ 0
] , & rtB . brgnx55w3z [ 0 ] , & rtB . pf1bcrl5dc [ 0 ] , & rtB . b3yhnwjth4
[ 0 ] , & rtB . cqzfaecv4m , & rtB . beqtta0fdy [ 0 ] , & rtB . h33i3u05hi [
0 ] , & rtB . patf3kg4ld [ 0 ] , & rtB . gadvm22wd1 [ 0 ] , & rtB .
a4mpu0tcou [ 0 ] , & rtB . etvej00kls [ 0 ] , & rtB . bvjoabbgen , & rtB .
fefh0hhvrv , & rtB . bxq1yx2osy , & rtB . if5diqfxfu [ 0 ] , & rtB .
pvqul3j2kd [ 0 ] , & rtB . hvbnpziw45 , & rtB . j2ny3wc1th , & rtB .
i5dfrly4pb [ 0 ] , & rtB . hqfbb0iret [ 0 ] , & rtB . etbnu02wn1 [ 0 ] , &
rtB . erku2k0xec [ 0 ] , & rtB . ahdogngpdy [ 0 ] , & rtB . ddbaqxsz3c [ 0 ]
, & rtB . bxo2fb1001 , & rtB . g3dvnnpaww , & rtB . psxllogfzm , & rtB .
lcdsgbjfwb [ 0 ] , & rtB . fstyznqnc5 [ 0 ] , & rtB . otgdt14a05 , & rtB .
ll4syrh021 , & rtB . euw0jex01r , & rtP . RT_InitialCondition , & rtP .
RT1_InitialCondition , & rtP . RT11_InitialCondition , & rtP .
RT12_InitialCondition , & rtP . RT13_InitialCondition , & rtP .
RT14_InitialCondition , & rtP . RT15_InitialCondition , & rtP .
RT16_InitialCondition , & rtP . RT2_InitialCondition , & rtP .
RT3_InitialCondition , & rtP . RT4_InitialCondition , & rtP .
RT5_InitialCondition , & rtP . RT6_InitialCondition , & rtP .
RT7_InitialCondition , & rtP . RT8_InitialCondition , & rtP .
RT9_InitialCondition , & rtP . DetectChange_vinit , & rtP .
PulseGenerator_Amp , & rtP . PulseGenerator_Period , & rtP .
PulseGenerator_Duty , & rtP . PulseGenerator_PhaseDelay , & rtP .
DetectChange1_vinit , & rtP . Constant_Value [ 0 ] , & rtP .
Constant1_Value_c2vf1mlipc , & rtP . Constant2_Value [ 0 ] , & rtP .
Constant5_Value , & rtP . Step1_Time_ostrpcewxx , & rtP . Step1_Y0_bf5ui0nx2l
, & rtP . Step1_YFinal_c35jqjcyg4 , & rtP . Constant_Value_mproqzully , & rtP
. UnitDelay_InitialCondition , & rtP . Constant1_Value , & rtP . Step1_Time ,
& rtP . Step1_Y0 , & rtP . Step1_YFinal , & rtP . Delay2_InitialCondition , &
rtP . VariableIntegerDelay_DiagnosticForDelayLength , & rtP .
VariableIntegerDelay_InitialCondition , & rtP . fromWS_Signal1_Time0 [ 0 ] ,
& rtP . fromWS_Signal1_Data0 [ 0 ] , & rtP . Q [ 0 ] , & rtP . T_S , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T ) SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 ,
0 } , { rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 4 , 2 , 0
} , { rtwCAPI_VECTOR , 2 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 6 , 1 , 9 , 1 , 6 , 6 , 9 , 9 , 1 , 6 , 7 , 1 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.002 , 0.0 , 0.001 , 0.0002 , 0.005 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 3 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 4 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 3 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , 4 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 45 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 40 , rtModelParameters , 2 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 928133372U , 2120093012U , 3764073844U , 3331302897U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo * MIL_Testing_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void MIL_Testing_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void MIL_Testing_host_InitializeDataMapInfo ( MIL_Testing_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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
