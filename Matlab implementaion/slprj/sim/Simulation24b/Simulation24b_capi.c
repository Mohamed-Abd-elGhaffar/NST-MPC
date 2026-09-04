#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Simulation24b_capi_host.h"
#define sizeof(...) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "Simulation24b.h"
#include "Simulation24b_capi.h"
#include "Simulation24b_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, TARGET_STRING ( "Simulation24b/Subsystem/Discrete-Time\nIntegrator" ) ,
TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 1 , - 1 ,
TARGET_STRING ( "Simulation24b/Subsystem/Variable Integer Delay" ) ,
TARGET_STRING ( "" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , { 2 , - 1 ,
TARGET_STRING ( "Simulation24b/Subsystem1/Discrete-Time\nIntegrator" ) ,
TARGET_STRING ( "" ) , "" , 0 , 0 , 2 , 0 , 0 , 0 , - 1 , 0 } , { 0 , - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 2 , 1 } ;
#ifndef HOST_CAPI_BUILD
static void Simulation24b_InitializeDataAddr ( void * dataAddr [ ] ,
eso4sc21a1 * localDW ) { dataAddr [ 0 ] = ( void * ) ( & localDW ->
gugr0g4zkp [ 0 ] ) ; dataAddr [ 1 ] = ( void * ) ( & localDW -> p000hohmy0 [
0 ] ) ; dataAddr [ 2 ] = ( void * ) ( & localDW -> ko42h1ub2o [ 0 ] ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Simulation24b_InitializeVarDimsAddr ( int32_T * vardimsAddr [ ] )
{ vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Simulation24b_InitializeLoggingFunctions ( RTWLoggingFcnPtr
loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ; loggingPtrs [ 1 ] = ( NULL
) ; loggingPtrs [ 2 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static uint_T rtDimensionArray [ ] = { 9 , 1
, 1000 , 1 , 7 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.001 ,
0.0 } ; static rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0 } } ; static int_T rtContextSystems [ 6 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 6 , rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL ) } , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockStates , 3 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 48487794U , 45155118U , 3868490166U , 3496114565U } , & mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo * Simulation24b_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void Simulation24b_InitializeSystemRan ( bbfkdjkyhg * const ljmhafjdje
, sysRanDType * systemRan [ ] , eso4sc21a1 * localDW , int_T systemTid [ ] ,
void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER ( ljmhafjdje ) ;
UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType * )
rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ] = ( NULL ) ;
systemRan [ 3 ] = ( NULL ) ; systemRan [ 4 ] = ( NULL ) ; systemRan [ 5 ] = ( NULL ) ; systemTid [ 1 ] = ljmhafjdje -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [ 2 ] = ljmhafjdje -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [ 3 ] = ljmhafjdje -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [ 4 ] = ljmhafjdje -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [ 5 ] = ljmhafjdje -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 0 ; rtContextSystems [ 3 ] = 0 ; rtContextSystems [ 4 ] = 0 ; rtContextSystems [ 5 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void Simulation24b_InitializeDataMapInfo ( bbfkdjkyhg * const ljmhafjdje ,
eso4sc21a1 * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( ljmhafjdje -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ljmhafjdje -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ljmhafjdje -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; Simulation24b_InitializeDataAddr ( ljmhafjdje ->
DataMapInfo . dataAddress , localDW ) ; rtwCAPI_SetDataAddressMap ( ljmhafjdje
-> DataMapInfo . mmi , ljmhafjdje -> DataMapInfo . dataAddress ) ;
Simulation24b_InitializeVarDimsAddr ( ljmhafjdje -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( ljmhafjdje -> DataMapInfo .
mmi , ljmhafjdje -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath ( ljmhafjdje -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath ( ljmhafjdje -> DataMapInfo . mmi , ( NULL ) ) ; Simulation24b_InitializeLoggingFunctions ( ljmhafjdje -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( ljmhafjdje -> DataMapInfo . mmi , ljmhafjdje -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetInstanceLoggingInfo ( ljmhafjdje -> DataMapInfo . mmi , & ljmhafjdje -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( ljmhafjdje -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ljmhafjdje -> DataMapInfo . mmi , 0 ) ; Simulation24b_InitializeSystemRan ( ljmhafjdje , ljmhafjdje -> DataMapInfo . systemRan , localDW , ljmhafjdje -> DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( ljmhafjdje -> DataMapInfo . mmi , ljmhafjdje -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid ( ljmhafjdje -> DataMapInfo . mmi , ljmhafjdje -> DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( ljmhafjdje -> DataMapInfo . mmi , & ljmhafjdje -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Simulation24b_host_InitializeDataMapInfo ( Simulation24b_host_DataMapInfo_T
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
