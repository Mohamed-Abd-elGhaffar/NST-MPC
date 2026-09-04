/*
 * File: Simulation.c
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

#include "Simulation.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "Simulation_private.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block states (default storage) */
DW_Simulation_T Simulation_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Simulation_T Simulation_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Simulation_T Simulation_Y;

/* Real-time model */
static RT_MODEL_Simulation_T Simulation_M_;
RT_MODEL_Simulation_T *const Simulation_M = &Simulation_M_;

/* Forward declaration for local functions */
static real_T Simulation_get_mdot(real_T p_up, real_T p_down, real_T C_valve);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Simulation_M->Timing.TaskCounters.TID[1])++;
  if ((Simulation_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.001s, 0.0s] */
    Simulation_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/MATLAB Function2' */
static real_T Simulation_get_mdot(real_T p_up, real_T p_down, real_T C_valve)
{
  real_T r;
  int32_T direction;
  if (p_up > p_down) {
    r = p_down / p_up;
    direction = 1;
  } else {
    r = p_up / p_down;
    direction = -1;
    p_up = p_down;
  }

  r = fmax(0.0, fmin(r, 1.0));
  if (r > 0.528) {
    r = (r - 0.528) / 0.472;
    r = sqrt(1.0 - r * r);
  } else {
    r = 1.0;
  }

  return 9.8000000000000017E-9 * C_valve * p_up * 1.225 * r * (real_T)direction;
}

/* Model step function */
void Simulation_step(void)
{
  real_T tmp[16];
  real_T rtb_DiscreteTimeIntegrator[9];
  real_T rtb_x_dot_i[9];
  real_T rtb_DiscreteTimeIntegrator_i[7];
  real_T rtb_x_dot[7];
  real_T F_c;
  real_T F_static;
  real_T F_static_tmp;
  real_T F_static_tmp_0;
  real_T R;
  real_T R_underMin;
  real_T R_val;
  real_T V_ext;
  real_T V_ret;
  real_T alpha;
  real_T alpha_tmp;
  real_T b_a;
  real_T b_a_tmp;
  real_T b_a_tmp_0;
  real_T b_a_tmp_1;
  real_T dC_dtheta;
  real_T d_a_tmp;
  real_T f_a;
  real_T m_dot_ext;
  real_T m_dot_ret;
  real_T m_dot_tank;
  real_T rtb_td_dot;
  real_T rtb_x_dot_tmp;
  real_T rtb_y;
  real_T s;
  real_T td;
  real_T tmp_0;
  int32_T i;
  int32_T rtb_d_0;
  boolean_T ext;
  boolean_T ret;
  if (Simulation_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/Subsystem2' */
    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    memcpy(&rtb_DiscreteTimeIntegrator[0],
           &Simulation_DW.DiscreteTimeIntegrator_DSTATE[0], 9U * sizeof(real_T));

    /* MATLAB Function: '<S2>/MATLAB Function2' incorporates:
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     */
    if (Simulation_DW.DiscreteTimeIntegrator_DSTATE[0] > 0.001) {
      rtb_y = 0.1621;
    } else {
      rtb_y = 0.4009;
    }

    /* End of MATLAB Function: '<S2>/MATLAB Function2' */

    /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (!Simulation_DW.tk_prev_not_empty) {
      Simulation_DW.tk_prev = rtb_y;
      Simulation_DW.tk_prev_not_empty = true;
    }

    if (Simulation_DW.state == 0) {
      if (fabs(Simulation_DW.tk_prev - rtb_y) < 1.0E-6) {
        td = rtb_y;
      } else {
        Simulation_DW.state = 1;
        Simulation_DW.T_i = Simulation_DW.tk_prev;
        Simulation_DW.T_f = rtb_y;
        td = Simulation_DW.tk_prev;
      }

      rtb_td_dot = 0.0;
    } else {
      R = 1.0 / Simulation_DW.T_i - 1.0 / Simulation_DW.T_f;
      td = R * 0.001 * Simulation_DW.T_i + Simulation_DW.td_prev;
      if (fabs(Simulation_DW.T_i - td) > fabs(Simulation_DW.T_i -
           Simulation_DW.T_f)) {
        td = rtb_y;
        Simulation_DW.state = 0;
      }

      rtb_td_dot = R * Simulation_DW.T_i;
    }

    Simulation_DW.td_prev = td;
    s = rt_roundd_snf(td / 0.0002);
    if (s < 2.147483648E+9) {
      if (s >= -2.147483648E+9) {
        rtb_d_0 = (int32_T)s;
      } else {
        rtb_d_0 = MIN_int32_T;
      }
    } else {
      rtb_d_0 = MAX_int32_T;
    }

    Simulation_DW.tk_prev = rtb_y;

    /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    for (i = 0; i < 7; i++) {
      rtb_DiscreteTimeIntegrator_i[i] =
        Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[i];
    }

    /* Delay: '<S2>/Variable Integer Delay' incorporates:
     *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
     *  MATLAB Function: '<S2>/MATLAB Function1'
     */
    if (rtb_d_0 <= 0) {
      td = Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[0];
    } else {
      if (rtb_d_0 > 100) {
        rtb_d_0 = 100;
      }

      td = Simulation_DW.VariableIntegerDelay_DSTATE[100 - rtb_d_0];
    }

    /* End of Delay: '<S2>/Variable Integer Delay' */

    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     */
    memset(&rtb_x_dot_i[0], 0, 9U * sizeof(real_T));
    rtb_y = Simulation_DW.DiscreteTimeIntegrator_DSTATE[5] / (1.0 - rtb_td_dot);
    td = sin(fmax(td, 0.1701) - 0.1701) * 0.09;
    td = Simulation_DW.DiscreteTimeIntegrator_DSTATE[4] / 0.03 * fmax(0.03, td) *
      rt_powd_snf(fmin(0.03, td), 1.5);
    tmp[0] = -1.0 / rtb_y;
    tmp[4] = 0.0;
    tmp[8] = 0.0;
    tmp[12] = 0.0;
    tmp[1] = 1.0 - rtb_td_dot;
    tmp[5] = 0.0;
    tmp[9] = 0.0;
    tmp[13] = 0.0;
    s = Simulation_DW.DiscreteTimeIntegrator_DSTATE[7] *
      Simulation_DW.DiscreteTimeIntegrator_DSTATE[7];
    tmp[3] = s * Simulation_DW.DiscreteTimeIntegrator_DSTATE[6];
    tmp[7] = 0.0;
    tmp[11] = -s;
    tmp[15] = -2.0 * Simulation_DW.DiscreteTimeIntegrator_DSTATE[8] *
      Simulation_DW.DiscreteTimeIntegrator_DSTATE[7];
    tmp[2] = 0.0;
    tmp_0 = 0.0;
    tmp[6] = 0.0;
    dC_dtheta = 0.0;
    tmp[10] = 0.0;
    R_val = 0.0;
    tmp[14] = 1.0;
    R = 0.0;
    i = 0;
    for (rtb_d_0 = 0; rtb_d_0 < 4; rtb_d_0++) {
      s = Simulation_DW.DiscreteTimeIntegrator_DSTATE[rtb_d_0];
      tmp_0 += tmp[i] * s;
      dC_dtheta += tmp[i + 1] * s;
      R_val += tmp[i + 2] * s;
      R += tmp[i + 3] * s;
      i += 4;
    }

    rtb_x_dot_i[0] = 1.0 / rtb_y * td + tmp_0;
    td *= 0.0;
    rtb_x_dot_i[1] = td + dC_dtheta;
    rtb_x_dot_i[2] = td + R_val;
    rtb_x_dot_i[3] = td + R;
    for (i = 0; i < 5; i++) {
      rtb_x_dot_i[i + 4] = 0.0;
    }

    /* End of MATLAB Function: '<S2>/MATLAB Function' */

    /* MATLAB Function: '<S3>/MATLAB Function2' incorporates:
     *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
     *  Inport: '<Root>/valve input'
     */
    s = sin(Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[0] - 0.5191);
    rtb_td_dot = sin(Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[0]);
    rtb_y = cos(Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[0]);
    alpha_tmp = 0.223 * rtb_y;
    alpha = rt_atan2d_snf(0.13996448246826462 - 0.223 * rtb_td_dot, alpha_tmp +
                          0.079971142591505173);
    R = 0.075714440000000008 - 0.0718952 * s;
    td = (0.1612 * s - 0.223) * 0.223 / R;
    dC_dtheta = cos(Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[0] - 0.5191) *
      -0.00085352399745600009 / (R * R);
    R_val = sin(Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[0] + alpha) *
      -0.223;
    R = sqrt(R);
    s = R_val * Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[1];
    tmp_0 = sin(alpha);
    b_a_tmp = 0.0785 * td;
    b_a_tmp_0 = -0.223 * rtb_td_dot;
    b_a_tmp_1 = b_a_tmp * tmp_0;
    b_a = b_a_tmp_1 + b_a_tmp_0;
    alpha = cos(alpha);
    b_a_tmp = b_a_tmp * alpha + alpha_tmp;
    V_ext = 0.157 * td;
    d_a_tmp = V_ext * tmp_0;
    b_a_tmp_0 += d_a_tmp;
    alpha_tmp += V_ext * alpha;
    V_ext = ((R - 0.2337) + 0.001) * 0.00020106192982974675 +
      2.4127431579569608E-6;
    V_ret = (0.1 - ((R - 0.2337) + 0.001)) * 0.0001727875959474386 +
      2.0734511513692632E-6;
    if (Simulation_U.valveinput == 0.0) {
      m_dot_ext = Simulation_get_mdot
        (Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[2],
         Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[3], 0.1056);
      m_dot_ret = -Simulation_get_mdot
        (Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[4], 101325.0, 0.0591);
      m_dot_tank = m_dot_ext;
    } else if (Simulation_U.valveinput == 1.0) {
      m_dot_ext = -Simulation_get_mdot
        (Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[3], 101325.0, 0.0729);
      m_dot_ret = Simulation_get_mdot
        (Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[2],
         Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[4], 0.1056);
      m_dot_tank = m_dot_ret;
    } else {
      m_dot_tank = 0.0;
      m_dot_ext = 0.0;
      m_dot_ret = 0.0;
    }

    ret = (Simulation_U.valveinput == 1.0);
    ext = (Simulation_U.valveinput == 0.0);
    F_static_tmp = td * td;
    F_static_tmp_0 = R_val * R_val;
    F_static = ((Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[6] * (real_T)ret
                 + Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[5] * (real_T)
                 ext) * F_static_tmp_0 + (F_static_tmp * 1.4434 + 1.0)) *
      ((real_T)ret * 1.482 + (real_T)ext * 2.028);
    F_c = 0.9178 * F_static;
    f_a = s / 0.005;
    R_underMin = fmax(0.0, 0.2337 - R);
    R = fmax(0.0, R - 0.33375);
    rtb_x_dot[0] = Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[1];
    rtb_x_dot_tmp = F_static_tmp * -tmp_0 + dC_dtheta * alpha;
    rtb_td_dot = 0.223 * -rtb_td_dot;
    alpha = F_static_tmp * alpha + dC_dtheta * tmp_0;
    rtb_y *= -0.223;
    rtb_x_dot[1] = ((((((Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[3] -
                         101325.0) * 0.00020106192982974675 -
                        (Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[4] -
                         101325.0) * 0.0001727875959474386) * R_val - (((((alpha
      * 0.0785 + rtb_y) * (b_a * 2.0) + 0.0041081666666666662 * td * dC_dtheta)
      + (rtb_x_dot_tmp * 0.0785 + rtb_td_dot) * (b_a_tmp * 2.0)) * 0.02301 +
      0.00228324 * td * dC_dtheta) + ((rtb_x_dot_tmp * 0.157 + rtb_td_dot) *
      alpha_tmp + (alpha * 0.157 + rtb_y)) * b_a_tmp_0 * 0.04258) * 0.5 *
                       (Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[1] *
                        Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[1])) - (((
      -sin(Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[0] - 0.036765969138185)
      * 0.071 * -1.8851877000000001 + 0.0885 * td * -tmp_0 * -0.938817) +
      (b_a_tmp_1 + rtb_td_dot) * -0.22572810000000001) + (d_a_tmp + rtb_td_dot) *
      -0.2088549)) - (((F_static - F_c) * exp(-(f_a * f_a)) + F_c) * tanh(150.0 *
      Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[1]) + 0.0087 * s * R_val)) +
                    ((-1.0764E+6 * R - 9040.7 * s) * (real_T)(R > 0.0) +
                     (1.0764E+6 * R_underMin - 9661.7 * s) * (real_T)(R_underMin
      > 0.0)) * R_val) * (1.0 / (((((F_static_tmp * 0.0020540833333333331 + b_a *
      b_a) + b_a_tmp * b_a_tmp) * 0.02301 + (F_static_tmp * 0.00114162 +
      0.001333991)) + (b_a_tmp_0 * b_a_tmp_0 + alpha_tmp * alpha_tmp) * 0.02129)
      + (15.7405 * (real_T)ext + 4.7308 * (real_T)ret) * (real_T)((R_underMin >
      0.0) || (R > 0.0)) * F_static_tmp_0));
    rtb_x_dot[2] = -m_dot_tank * 287.0 * 1.2 * 294.0 / 0.024;
    rtb_x_dot[3] = m_dot_ext * 287.0 * 1.2 * 294.0 / V_ext -
      0.00020106192982974675 * s *
      Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[3] * 1.2 / V_ext;
    rtb_x_dot[4] = m_dot_ret * 287.0 * 1.2 * 294.0 / V_ret +
      0.0001727875959474386 * s * Simulation_DW.DiscreteTimeIntegrator_DSTATE_d
      [4] * 1.2 / V_ret;
    rtb_x_dot[5] = 0.0;
    rtb_x_dot[6] = 0.0;

    /* End of MATLAB Function: '<S3>/MATLAB Function2' */

    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    for (i = 0; i < 9; i++) {
      Simulation_DW.DiscreteTimeIntegrator_DSTATE[i] += 0.001 * rtb_x_dot_i[i];
    }

    /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    for (i = 0; i < 7; i++) {
      Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[i] += 0.001 * rtb_x_dot[i];
    }

    /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */

    /* Update for Delay: '<S2>/Variable Integer Delay' */
    for (rtb_d_0 = 0; rtb_d_0 < 99; rtb_d_0++) {
      Simulation_DW.VariableIntegerDelay_DSTATE[rtb_d_0] =
        Simulation_DW.VariableIntegerDelay_DSTATE[rtb_d_0 + 1];
    }

    Simulation_DW.VariableIntegerDelay_DSTATE[99] =
      rtb_DiscreteTimeIntegrator_i[0];

    /* End of Update for Delay: '<S2>/Variable Integer Delay' */
    /* End of Outputs for SubSystem: '<Root>/Subsystem2' */

    /* Outport: '<Root>/Out1' */
    Simulation_Y.Out1 = rtb_DiscreteTimeIntegrator[1];
  }

  rate_scheduler();
}

/* Model initialize function */
void Simulation_initialize(void)
{
  {
    int32_T i;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem2' */
    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    memcpy(&Simulation_DW.DiscreteTimeIntegrator_DSTATE[0],
           &Simulation_ConstP.DiscreteTimeIntegrator_IC[0], 9U * sizeof(real_T));

    /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    for (i = 0; i < 7; i++) {
      Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[i] =
        Simulation_ConstP.DiscreteTimeIntegrator_IC_o[i];
    }

    /* End of InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */

    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function1' */
    Simulation_DW.T_i = 1.0;
    Simulation_DW.T_f = 1.0;

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem2' */
  }
}

/* Model terminate function */
void Simulation_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
