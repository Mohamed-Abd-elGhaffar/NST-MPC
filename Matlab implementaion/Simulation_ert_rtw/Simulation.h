/*
 * File: Simulation.h
 *
 * Code generated for Simulink model 'Simulation'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Jan 28 10:45:51 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Simulation_h_
#define Simulation_h_
#ifndef Simulation_COMMON_INCLUDES_
#define Simulation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Simulation_COMMON_INCLUDES_ */

#include "Simulation_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[9];/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d[7];/* '<S3>/Discrete-Time Integrator' */
  real_T VariableIntegerDelay_DSTATE[100];/* '<S2>/Variable Integer Delay' */
  real_T tk_prev;                      /* '<S2>/MATLAB Function1' */
  real_T T_i;                          /* '<S2>/MATLAB Function1' */
  real_T T_f;                          /* '<S2>/MATLAB Function1' */
  real_T td_prev;                      /* '<S2>/MATLAB Function1' */
  int8_T state;                        /* '<S2>/MATLAB Function1' */
  boolean_T tk_prev_not_empty;         /* '<S2>/MATLAB Function1' */
} DW_Simulation_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0
     0
     0
     0
     183.5470
     0.0500
     0.2149
     56.3147
     0.4315]
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  real_T DiscreteTimeIntegrator_IC[9];

  /* Expression: [deg2rad(-0.51);0;9*101325;9*101325;101325;b2_ext;b2_ret]
   * Referenced by: '<S3>/Discrete-Time Integrator'
   */
  real_T DiscreteTimeIntegrator_IC_o[7];
} ConstP_Simulation_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T valveinput;                   /* '<Root>/valve input' */
} ExtU_Simulation_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_Simulation_T;

/* Real-time Model Data Structure */
struct tag_RTM_Simulation_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block states (default storage) */
extern DW_Simulation_T Simulation_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Simulation_T Simulation_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Simulation_T Simulation_Y;

/* Constant parameters (default storage) */
extern const ConstP_Simulation_T Simulation_ConstP;

/* Model entry point functions */
extern void Simulation_initialize(void);
extern void Simulation_step(void);
extern void Simulation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Simulation_T *const Simulation_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Zero-Order Hold' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Simulation'
 * '<S1>'   : 'Simulation/Subsystem2'
 * '<S2>'   : 'Simulation/Subsystem2/Subsystem'
 * '<S3>'   : 'Simulation/Subsystem2/Subsystem1'
 * '<S4>'   : 'Simulation/Subsystem2/Subsystem/MATLAB Function'
 * '<S5>'   : 'Simulation/Subsystem2/Subsystem/MATLAB Function1'
 * '<S6>'   : 'Simulation/Subsystem2/Subsystem/MATLAB Function2'
 * '<S7>'   : 'Simulation/Subsystem2/Subsystem1/MATLAB Function2'
 */
#endif                                 /* Simulation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
