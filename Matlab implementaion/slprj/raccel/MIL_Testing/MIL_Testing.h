#ifndef MIL_Testing_h_
#define MIL_Testing_h_
#ifndef MIL_Testing_COMMON_INCLUDES_
#define MIL_Testing_COMMON_INCLUDES_
#include <stdlib.h>
#include <stdio.h>
#include "rtwtypes.h"
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
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#include "blas.h"
#include "functions.h"
#include "serial_reader.hpp"
#include "csv_logger.hpp"
#include "gate.hpp"
#endif
#include "MIL_Testing_types.h"
#include "mwmathutil.h"
#include <stddef.h>
#include "rt_zcfcn.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "zero_crossing_types.h"
#define MODEL_NAME MIL_Testing
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (36) 
#define NUM_ZC_EVENTS (5) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
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
typedef struct { real_T cqzfaecv4m ; real_T bvjoabbgen ; real_T pvqul3j2kd [
6 ] ; real_T h33i3u05hi [ 36 ] ; real_T pf1bcrl5dc [ 6 ] ; real_T brgnx55w3z
[ 6 ] ; real_T gadvm22wd1 [ 36 ] ; real_T fefh0hhvrv ; real_T if5diqfxfu [ 9
] ; real_T patf3kg4ld [ 81 ] ; real_T b3yhnwjth4 [ 9 ] ; real_T a4mpu0tcou [
36 ] ; real_T beqtta0fdy [ 81 ] ; real_T lqpivh20ue [ 6 ] ; real_T etvej00kls
[ 9 ] ; real_T g3dvnnpaww ; real_T bxo2fb1001 ; real_T ahdogngpdy [ 6 ] ;
real_T ddbaqxsz3c [ 36 ] ; real_T euw0jex01r ; real_T lcdsgbjfwb [ 9 ] ;
real_T fstyznqnc5 [ 81 ] ; real_T otgdt14a05 ; real_T ll4syrh021 ; real_T
i5dfrly4pb [ 6 ] ; real_T hqfbb0iret [ 9 ] ; real_T etbnu02wn1 [ 36 ] ;
real_T erku2k0xec [ 81 ] ; real_T hvbnpziw45 ; real_T j2ny3wc1th ; boolean_T
bxq1yx2osy ; boolean_T psxllogfzm ; } B ; typedef struct { icoaoz3rgd
gocvwhon5y ; FILE * mznmhfvmea [ 20 ] ; mfrw1nqxwz mhyvkdo2ux ; iotyzgkdcn
mzifbxk1wn ; real_T lo3qyprm4b ; real_T beqcpe00sh [ 6 ] ; real_T fcyc3lekf3
[ 36 ] ; real_T a0i41tv53p ; real_T jw1guf4gc4 [ 500 ] ; real_T de4tsmwird [
9 ] ; real_T h3pyo5aafm [ 81 ] ; real_T iivzqnnafg ; real_T dfuabdacjg [ 3 ]
; real_T dtytunz3lh [ 3 ] ; real_T cfze1vz5si [ 18 ] ; real_T cmrxwx2p1q [
108 ] ; real_T h4yjnfwxyj [ 6 ] ; real_T bgcbhaqa0v [ 6 ] ; real_T mgieiokwlg
; real_T ew4umcwnpz [ 6 ] ; real_T ppuxszxz4r [ 6 ] ; real_T lgvzz3uvac ;
real_T dmeue2mdbu [ 36 ] ; real_T admijup4h5 [ 36 ] ; real_T lnkw33l3jm ;
real_T hvzeco2ore [ 3 ] ; real_T mvtpbffmvi [ 27 ] ; real_T fqe0q3cfrn [ 243
] ; real_T l2yr52gncr [ 9 ] ; real_T ezsyklwnq5 [ 9 ] ; real_T kaofucg0ce ;
real_T id31qo414u [ 36 ] ; real_T jyvxuxxqjf [ 36 ] ; real_T i4vu5e54ap ;
real_T ihu2yalc0n [ 81 ] ; real_T pil0xca4t5 [ 81 ] ; real_T iwm01ftkab ;
real_T kstza1wr21 [ 6 ] ; real_T b2kfls1nvu [ 6 ] ; real_T jpaa1akovd ;
real_T halwmwe2x0 [ 9 ] ; real_T c2dnexkmxf [ 9 ] ; real_T nlhsncexf0 ;
real_T oraym15yy4 ; real_T ivwglyseg3 ; real_T dw2aqddkbu ; real_T og10d1di0w
; real_T ptgnvnkaax ; real_T nl4qujfigc ; void * db0zscnkw5 ; void *
dnagvmiwyz ; void * l1qkwlxbe2 ; void * nx3phiwl4b ; void * bivy2tgpmo ; void
* ock4n01zv1 ; void * nscvg2w1jd ; struct { void * TimePtr ; void * DataPtr ;
void * RSimInfoPtr ; } hltsxhc0yl ; struct { void * LoggedData ; } cbz1zds3ha
; struct { void * LoggedData ; } plm1yijlcr ; int32_T cel4kex0vf ; int32_T
lnnkfakp5r ; int32_T dsacja1lso ; int32_T pob2ql2yji ; int32_T npbg2bjhaw ;
doah2ritxs abxfrplp1i ; struct { int_T PrevIndex ; } oeoydvlwgx ; boolean_T
npi2ladrba ; int8_T ieyig5nl2r ; int8_T f3pfkie500 ; int8_T eyofepozhc ;
int8_T d3gd2okwfo ; int8_T nfs34xvx3j ; int8_T id2fpjvnxd ; int8_T a3irhgkhqf
; int8_T laoagnfzfl ; int8_T enpaf0a13a ; int8_T k53yka44us ; int8_T
iz2nl50abi ; int8_T klxzw4td0l ; int8_T hcrq1cfyt5 ; int8_T lbjnlc1mss ;
int8_T eypykigfe0 ; int8_T h51utyovca ; volatile boolean_T elg2z4i5mu ;
boolean_T pfpu1lxyox ; boolean_T cwyperzqwf ; boolean_T pkugn2pznb ;
boolean_T l24bi33ydv ; boolean_T kc0j20jyvv ; boolean_T mghwgiy3zr ;
boolean_T mgqgi2ps1y ; boolean_T h3x4gkt34l ; boolean_T pbdxvs0spm ;
boolean_T n2anugr1ay ; boolean_T en0iu21xjh ; boolean_T ex1idzngre ;
boolean_T nsjaywhvfb ; boolean_T as24lkyvxh ; boolean_T nf2x5nb1ds ;
boolean_T bl11n31i34 ; boolean_T j5z0ymci3s ; boolean_T gciqwqedw2 ;
boolean_T kmhvvetfe2 ; boolean_T lvyyr1smre [ 20 ] ; boolean_T itimx2tbt5 ;
boolean_T hxoj3qbhn2 ; } DW ; typedef struct { ZCSigState cloejyaq4j ;
ZCSigState hw1y0usypt ; ZCSigState pnfmf2xzbv ; ZCSigState k1mcsspbdy ;
ZCSigState lvahitjqif ; } PrevZCX ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T Q [ 81 ] ; real_T T_S ; real_T
DetectChange_vinit ; boolean_T DetectChange1_vinit ; real_T
PulseGenerator_Amp ; real_T PulseGenerator_Period ; real_T
PulseGenerator_Duty ; real_T PulseGenerator_PhaseDelay ; real_T
Delay2_InitialCondition ; real_T VariableIntegerDelay_InitialCondition ;
real_T Constant1_Value ; real_T Step1_Time ; real_T Step1_Y0 ; real_T
Step1_YFinal ; real_T Constant_Value [ 36 ] ; real_T
Constant1_Value_c2vf1mlipc ; real_T Constant2_Value [ 6 ] ; real_T
Constant5_Value ; real_T Step1_Time_ostrpcewxx ; real_T Step1_Y0_bf5ui0nx2l ;
real_T Step1_YFinal_c35jqjcyg4 ; real_T Constant_Value_mproqzully ; real_T
fromWS_Signal1_Time0 [ 7 ] ; real_T fromWS_Signal1_Data0 [ 7 ] ; real_T
UnitDelay_InitialCondition ; real_T RT13_InitialCondition ; real_T
RT5_InitialCondition ; real_T RT9_InitialCondition ; real_T
RT15_InitialCondition ; real_T RT11_InitialCondition ; real_T
RT1_InitialCondition ; real_T RT2_InitialCondition ; real_T
RT6_InitialCondition ; real_T RT8_InitialCondition ; real_T
RT16_InitialCondition ; real_T RT12_InitialCondition ; real_T
RT3_InitialCondition ; real_T RT14_InitialCondition ; real_T
RT_InitialCondition ; real_T RT4_InitialCondition ; boolean_T
RT7_InitialCondition ; uint8_T VariableIntegerDelay_DiagnosticForDelayLength
; } ; extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ;
extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_MIL_Testing_GetDWork ( ) ; extern void mr_MIL_Testing_SetDWork ( const
mxArray * ssDW ) ; extern mxArray *
mr_MIL_Testing_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * MIL_Testing_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T
tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
