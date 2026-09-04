/*
 * File: get_mdot_Crp2OzBS.c
 *
 * Code generated for Simulink model 'Digital_Twin'.
 *
 * Model version                  : 3.1
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Feb 11 19:18:49 2026
 */

#include "rtwtypes.h"
#include "get_mdot_Crp2OzBS.h"
#include <math.h>

/* Function for MATLAB Function: '<Root>/Gate_EKF' */
real_T get_mdot_Crp2OzBS(real_T p_up, real_T p_down, real_T C_valve)
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

  if (!(r <= 1.0)) {
    r = 1.0;
  }

  if (r <= 0.0) {
    r = 0.0;
  }

  if (r > 0.528) {
    r = (r - 0.528) / 0.472;
    r = sqrt(1.0 - r * r);
  } else {
    r = 1.0;
  }

  return 9.8000000000000017E-9 * C_valve * p_up * 1.225 * r * (real_T)direction;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
