/*
 * File: f_dynamics_QplyUGCb.c
 *
 * Code generated for Simulink model 'Digital_Twin'.
 *
 * Model version                  : 3.1
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Feb 11 19:18:49 2026
 */

#include "rtwtypes.h"
#include "f_dynamics_QplyUGCb.h"
#include <math.h>
#include "rt_atan2d_snf.h"
#include "get_mdot_Crp2OzBS.h"
#include "rt_nonfinite.h"

/* Function for MATLAB Function: '<Root>/Gate_EKF' */
void f_dynamics_QplyUGCb(const real_T x[7], real_T u, real_T Ts, real_T
  X_k_plus1[7])
{
  real_T x_dot[7];
  real_T C_val;
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
  real_T alpha_tmp_0;
  real_T alpha_tmp_1;
  real_T b_a;
  real_T b_a_tmp;
  real_T b_a_tmp_0;
  real_T b_a_tmp_1;
  real_T b_a_tmp_2;
  real_T dC_dtheta;
  real_T d_a_tmp;
  real_T f_a;
  real_T m_dot_ext;
  real_T m_dot_ret;
  real_T m_dot_tank;
  real_T s;
  real_T x_dot_tmp;
  int32_T i;
  boolean_T ext;
  boolean_T ret;
  s = sin(x[0] - 0.5191);
  alpha_tmp = sin(x[0]);
  alpha_tmp_0 = cos(x[0]);
  alpha_tmp_1 = 0.223 * alpha_tmp_0;
  alpha = rt_atan2d_snf(0.13996448246826462 - 0.223 * alpha_tmp, alpha_tmp_1 +
                        0.079971142591505173);
  R = 0.075714440000000008 - 0.0718952 * s;
  C_val = (0.1612 * s - 0.223) * 0.223 / R;
  dC_dtheta = cos(x[0] - 0.5191) * -0.00085352399745600009 / (R * R);
  R_val = sin(x[0] + alpha) * -0.223;
  R = sqrt(R);
  s = R_val * x[1];
  b_a_tmp = sin(alpha);
  b_a_tmp_0 = 0.0785 * C_val;
  b_a_tmp_1 = -0.223 * alpha_tmp;
  b_a_tmp_2 = b_a_tmp_0 * b_a_tmp;
  b_a = b_a_tmp_2 + b_a_tmp_1;
  alpha = cos(alpha);
  b_a_tmp_0 = b_a_tmp_0 * alpha + alpha_tmp_1;
  V_ext = 0.157 * C_val;
  d_a_tmp = V_ext * b_a_tmp;
  b_a_tmp_1 += d_a_tmp;
  alpha_tmp_1 += V_ext * alpha;
  V_ext = ((R - 0.2337) + 0.001) * 0.00020106192982974675 +
    2.4127431579569608E-6;
  V_ret = (0.1 - ((R - 0.2337) + 0.001)) * 0.0001727875959474386 +
    2.0734511513692632E-6;
  if (u == 0.0) {
    m_dot_ext = get_mdot_Crp2OzBS(x[2], x[3], 0.1056);
    m_dot_ret = -get_mdot_Crp2OzBS(x[4], 101325.0, 0.0591);
    m_dot_tank = m_dot_ext;
  } else if (u == 1.0) {
    m_dot_ext = -get_mdot_Crp2OzBS(x[3], 101325.0, 0.0729);
    m_dot_ret = get_mdot_Crp2OzBS(x[2], x[4], 0.1056);
    m_dot_tank = m_dot_ret;
  } else {
    m_dot_tank = 0.0;
    m_dot_ext = 0.0;
    m_dot_ret = 0.0;
  }

  ret = (u == 1.0);
  ext = (u == 0.0);
  F_static_tmp = C_val * C_val;
  F_static_tmp_0 = R_val * R_val;
  F_static = ((x[6] * (real_T)ret + x[5] * (real_T)ext) * F_static_tmp_0 +
              (F_static_tmp * 1.4434 + 1.0)) * ((real_T)ret * 1.482 + (real_T)
    ext * 2.028);
  F_c = 0.9178 * F_static;
  f_a = s / 0.005;
  if ((0.2337 - R <= 0.0) || rtIsNaN(0.2337 - R)) {
    R_underMin = 0.0;
  } else {
    R_underMin = 0.2337 - R;
  }

  if ((R - 0.33375 <= 0.0) || rtIsNaN(R - 0.33375)) {
    R = 0.0;
  } else {
    R -= 0.33375;
  }

  x_dot[0] = x[1];
  x_dot_tmp = F_static_tmp * -b_a_tmp + dC_dtheta * alpha;
  alpha_tmp = 0.223 * -alpha_tmp;
  alpha = F_static_tmp * alpha + dC_dtheta * b_a_tmp;
  alpha_tmp_0 *= -0.223;
  x_dot[1] = ((((((x[3] - 101325.0) * 0.00020106192982974675 - (x[4] - 101325.0)
                  * 0.0001727875959474386) * R_val - (((((alpha * 0.0785 +
    alpha_tmp_0) * (b_a * 2.0) + 0.0041081666666666662 * C_val * dC_dtheta) +
    (x_dot_tmp * 0.0785 + alpha_tmp) * (b_a_tmp_0 * 2.0)) * 0.02301 + 0.00228324
    * C_val * dC_dtheta) + ((x_dot_tmp * 0.157 + alpha_tmp) * alpha_tmp_1 +
    (alpha * 0.157 + alpha_tmp_0)) * b_a_tmp_1 * 0.04258) * 0.5 * (x[1] * x[1]))
                - (((-sin(x[0] - 0.036765969138185) * 0.071 *
                     -1.8851877000000001 + 0.0885 * C_val * -b_a_tmp * -0.938817)
                    + (b_a_tmp_2 + alpha_tmp) * -0.22572810000000001) + (d_a_tmp
    + alpha_tmp) * -0.2088549)) - (((F_static - F_c) * exp(-(f_a * f_a)) + F_c) *
    tanh(150.0 * x[1]) + 0.0087 * s * R_val)) + ((-1.0764E+6 * R - 9040.7 * s) *
    (real_T)(R > 0.0) + (1.0764E+6 * R_underMin - 9661.7 * s) * (real_T)
    (R_underMin > 0.0)) * R_val) * (1.0 / (((((F_static_tmp *
    0.0020540833333333331 + b_a * b_a) + b_a_tmp_0 * b_a_tmp_0) * 0.02301 +
    (F_static_tmp * 0.00114162 + 0.001333991)) + (b_a_tmp_1 * b_a_tmp_1 +
    alpha_tmp_1 * alpha_tmp_1) * 0.02129) + (15.7405 * (real_T)ext + 4.7308 *
    (real_T)ret) * (real_T)((R_underMin > 0.0) || (R > 0.0)) * F_static_tmp_0));
  x_dot[2] = -m_dot_tank * 287.0 * 1.2 * 294.0 / 0.024;
  x_dot[3] = m_dot_ext * 287.0 * 1.2 * 294.0 / V_ext - 0.00020106192982974675 *
    s * x[3] * 1.2 / V_ext;
  x_dot[4] = m_dot_ret * 287.0 * 1.2 * 294.0 / V_ret + 0.0001727875959474386 * s
    * x[4] * 1.2 / V_ret;
  x_dot[5] = 0.0;
  x_dot[6] = 0.0;
  for (i = 0; i < 7; i++) {
    X_k_plus1[i] = x_dot[i] * Ts + x[i];
  }

  X_k_plus1[1] = x_dot[1] * Ts + x[1];
  s = 0.0 * Ts;
  X_k_plus1[5] = s + x[5];
  X_k_plus1[6] = s + x[6];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
