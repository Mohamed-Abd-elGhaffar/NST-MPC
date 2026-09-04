#ifndef Simulation24b_h_
#define Simulation24b_h_
#ifndef Simulation24b_COMMON_INCLUDES_
#define Simulation24b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "sfrtif/sfc_sdi.h"
#endif
#include "Simulation24b_types.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>
typedef struct { real_T ij0dh4z431 [ 7 ] ; real_T j1anepyxkx [ 7 ] ; real_T
affdqpybl5 [ 9 ] ; int32_T ivtdknr412 ; } mzroezuj5x ; typedef struct {
real_T gugr0g4zkp [ 9 ] ; real_T ko42h1ub2o [ 7 ] ; real_T p000hohmy0 [ 1000
] ; real_T dhqgitp3bq ; real_T gvmabsxbie ; real_T oht5yygimc ; real_T
mxgxnurtam ; int8_T gijldx5jwk ; boolean_T cgczmksjfr ; } eso4sc21a1 ; struct
kerzjtus1qo_ { real_T P_0 ; real_T P_1 [ 9 ] ; real_T P_2 ; real_T P_3 [ 7 ]
; real_T P_4 ; real_T P_5 ; uint8_T P_6 ; } ; struct ggpomsgmk4 { struct
SimStruct_tag * _mdlRefSfcnS ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; void * dataAddress [
3 ] ; int32_T * vardimsAddress [ 3 ] ; RTWLoggingFcnPtr loggingPtrs [ 3 ] ;
sysRanDType * systemRan [ 6 ] ; int_T systemTid [ 6 ] ; } DataMapInfo ;
struct { int_T mdlref_GlobalTID [ 3 ] ; } Timing ; } ; typedef struct {
mzroezuj5x rtb ; eso4sc21a1 rtdw ; bbfkdjkyhg rtm ; } ibfgmjp2q3s ; extern
void akqwlccdgw ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , int_T mdlref_TID2 , bbfkdjkyhg * const ljmhafjdje , mzroezuj5x
* localB , eso4sc21a1 * localDW , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_Simulation24b_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName
, int_T * retVal ) ; extern mxArray * mr_Simulation24b_GetDWork ( const
ibfgmjp2q3s * mdlrefDW ) ; extern void mr_Simulation24b_SetDWork ( ibfgmjp2q3s
* mdlrefDW , const mxArray * ssDW ) ; extern void
mr_Simulation24b_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray
* mr_Simulation24b_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Simulation24b_GetCAPIStaticMap ( void ) ;
extern void j2bgulz3mh ( eso4sc21a1 * localDW ) ; extern void eflzvbjf1g ( eso4sc21a1 * localDW ) ; extern void nn5qc4vcwnTID0 ( void ) ; extern void nn5qc4vcwnTID1 ( mzroezuj5x * localB , eso4sc21a1 * localDW ) ; extern void Simulation24bTID0 ( void ) ; extern void Simulation24bTID1 ( bbfkdjkyhg * const ljmhafjdje , const real_T * gdeq2b0pip , real_T * nwjomxhacf , real_T * bjug14zo0u , real_T * e2fplk3lsn , mzroezuj5x * localB , eso4sc21a1 * localDW ) ; extern void ldoflf1jdq ( bbfkdjkyhg * const ljmhafjdje ) ;
#endif
