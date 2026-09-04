/*
 * File: rt_roundd.c
 *
 * Code generated for Simulink model 'MPC_Final'.
 *
 * Model version                  : 3.0
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Feb 11 19:36:53 2026
 */

#include "rtwtypes.h"
#include "rt_roundd.h"
#include <math.h>

real_T rt_roundd(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
